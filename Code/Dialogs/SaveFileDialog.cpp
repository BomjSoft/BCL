//---------------------------------------------------------------------------
#include "SaveFileDialog.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CSaveFileDialog::CSaveFileDialog()
{
   memset(&file, 0, sizeof(file));
   file.lStructSize = sizeof(file);
   nameBuffer[0] = '\0';
   file.lpstrFile = nameBuffer;
   file.nMaxFile = sizeof(nameBuffer) / sizeof(TCHAR);
   file.nFilterIndex = 1;
   file.lpstrDefExt = _T("");
   file.Flags = OFN_EXTENSIONDIFFERENT | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
}
//---------------------------------------------------------------------------

CSaveFileDialog::~CSaveFileDialog()
{
}
//---------------------------------------------------------------------------

void CSaveFileDialog::SetOwner(CForm *Owner)
{
   file.hwndOwner = (Owner != nullptr)?Owner->hwnd:0;
}
//---------------------------------------------------------------------------

void CSaveFileDialog::SetFilter(const TCHAR *Filter)
{
   file.lpstrFilter = Filter;
}
//---------------------------------------------------------------------------

void CSaveFileDialog::SetDefaultExtension(const TCHAR *DefExt)
{
   file.lpstrDefExt = DefExt;
}
//---------------------------------------------------------------------------

bool CSaveFileDialog::Execute()
{
   return GetSaveFileName(&file) == TRUE;
}
//---------------------------------------------------------------------------

const TCHAR *CSaveFileDialog::GetFileName() const
{
   return nameBuffer;
}
//---------------------------------------------------------------------------

const TCHAR *CSaveFileDialog::GetFileExtension() const
{
   return &nameBuffer[file.nFileExtension];
}
//---------------------------------------------------------------------------
}
