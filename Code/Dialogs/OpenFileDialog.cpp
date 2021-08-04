//---------------------------------------------------------------------------
#include "OpenFileDialog.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
COpenFileDialog::COpenFileDialog()
{
   memset(&file, 0, sizeof(file));
   file.lStructSize = sizeof(file);
   file.nFilterIndex = 1;
   file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;
}
//---------------------------------------------------------------------------

COpenFileDialog::~COpenFileDialog()
{
}
//---------------------------------------------------------------------------

void COpenFileDialog::SetOwner(CForm *Owner)
{
   file.hwndOwner = (Owner != nullptr)?Owner->hwnd:0;
}
//---------------------------------------------------------------------------

void COpenFileDialog::SetFilter(const TCHAR *Filter)
{
   file.lpstrFilter = Filter;
}
//---------------------------------------------------------------------------

void COpenFileDialog::SetMultiselect(bool UseMultiselect)
{
   if (UseMultiselect)
   {
      file.Flags |= OFN_ALLOWMULTISELECT;
   }
   else
   {
      file.Flags &= ~OFN_ALLOWMULTISELECT;
   }
}
//---------------------------------------------------------------------------

bool COpenFileDialog::Execute()
{
   fileList.clear();
   TCHAR *buffer;
   if (file.Flags & OFN_ALLOWMULTISELECT)
   {
      buffer = new TCHAR[0xFFFF];
      file.nMaxFile = 0xFFFF;
   }
   else
   {
      buffer = new TCHAR[MAX_PATH];
      file.nMaxFile = MAX_PATH;
   }
   buffer[0] = '\0';
   file.lpstrFile = buffer;
   if (GetOpenFileName(&file) == FALSE)
   {
      delete[] buffer;
      return false;
   }
   if (file.lpstrFile[file.nFileOffset - 1] == 0)
   {
      std::tstring path;
      path.append(file.lpstrFile);
      path.append(_T("\\"));
      std::tstring temp;
      TCHAR *ptr = file.lpstrFile + file.nFileOffset;
      while (*ptr)
      {
         temp.clear();
         temp.append(ptr);
         fileList.push_back(path + temp);
         ptr += _tcslen(ptr) + 1;
      }
   }
   else
   {
      std::tstring temp;
      temp.append(file.lpstrFile);
      fileList.push_back(temp);
   }
   delete[] buffer;
   return true;
}
//---------------------------------------------------------------------------

size_t COpenFileDialog::GetFileCount() const
{
   return fileList.size();
}
//---------------------------------------------------------------------------

const TCHAR *COpenFileDialog::GetFileName(size_t Number) const
{
   if (Number < fileList.size())
   {
      return fileList[Number].c_str();
   }
   return nullptr;
}
//---------------------------------------------------------------------------
}
