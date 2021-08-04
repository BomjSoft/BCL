//---------------------------------------------------------------------------
#include "FileOperations.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------

bool SelectDirectory(HWND Owner, const TCHAR *Description, std::tstring &Result)
{
   BROWSEINFO info;
   memset(&info, 0, sizeof(info));
   info.hwndOwner = Owner;
   info.lpszTitle = Description;
   info.ulFlags = BIF_RETURNONLYFSDIRS;

   PIDLIST_ABSOLUTE id = SHBrowseForFolder(&info);
   if (id != 0)
   {
      TCHAR buffer[MAX_PATH + 1];
      SHGetPathFromIDList(id, buffer);
      GlobalFreePtr(id);

      int len = _tcslen(buffer);
      if (buffer[len - 1] != '\\')
      {
         buffer[len] = '\\';
         len++;
      }
      buffer[len] = '\0';
      Result = buffer;
      return true;
   }
   return false;
}
//---------------------------------------------------------------------------

bool MoveToTrash(const TCHAR *FileName)
{
   int len = _tcslen(FileName);
   TCHAR *buffer = new TCHAR[len + 2];
   if (buffer != nullptr)
   {
      _tcscpy(buffer, FileName);
      buffer[len + 0] = 0;
      buffer[len + 1] = 0;
      SHFILEOPSTRUCT fileop;
      memset(&fileop, 0, sizeof(fileop));
      fileop.wFunc = FO_DELETE;
      fileop.pFrom = buffer;
      fileop.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_SILENT;
      bool result = (SHFileOperation(&fileop) == 0);
      delete[] buffer;
      return result;
   }
   return false;
}
//---------------------------------------------------------------------------

bool RemoteOpenFile(const TCHAR *FileName)
{
   return (INT_PTR(ShellExecute(0, _T("Open"), FileName, nullptr, nullptr, SW_SHOWNORMAL)) > 32);
}
//---------------------------------------------------------------------------
}
