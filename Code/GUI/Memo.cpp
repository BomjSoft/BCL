//---------------------------------------------------------------------------
#include "Memo.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CMemo::CMemo() : CComponent()
{
   readOnly = false;
}
//---------------------------------------------------------------------------

CMemo::~CMemo()
{
}
//---------------------------------------------------------------------------

void CMemo::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("edit"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | WS_HSCROLL | WS_VSCROLL | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
   if (readOnly)
   {
      SendMessage(hwnd, EM_SETREADONLY, TRUE, 0);
   }
}
//---------------------------------------------------------------------------

LRESULT CMemo::Message(UINT Type)
{
   return 0;
}
//---------------------------------------------------------------------------

std::tstring CMemo::GetText()
{
   int lineLength = SendMessage(hwnd, EM_GETLIMITTEXT, 0, 0);
   TCHAR buffer[lineLength];
   SendMessage(hwnd, WM_GETTEXT, lineLength, LPARAM(buffer));
   return buffer;
}
//---------------------------------------------------------------------------

void CMemo::SetText(const TCHAR *Text)
{
   SendMessage(hwnd, WM_SETTEXT, lstrlen(Text), LPARAM(Text));
}
//---------------------------------------------------------------------------

void CMemo::SetReadOnly(bool ReadOnly)
{
   readOnly = ReadOnly;
   if (created)
   {
      SendMessage(hwnd, EM_SETREADONLY, readOnly?TRUE:FALSE, 0);
   }
}
//---------------------------------------------------------------------------
}
