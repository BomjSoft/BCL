//---------------------------------------------------------------------------
#include "Edit.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CEdit::CEdit() : CComponent()
{
}
//---------------------------------------------------------------------------

CEdit::~CEdit()
{
}
//---------------------------------------------------------------------------

void CEdit::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("edit"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | WS_BORDER | ES_AUTOHSCROLL, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CEdit::Message(UINT Type)
{
   return 0;
}
//---------------------------------------------------------------------------

std::tstring CEdit::GetText()
{
   int lineLength = SendMessage(hwnd, EM_GETLIMITTEXT, 0, 0);
   TCHAR buffer[lineLength + 1];
   SendMessage(hwnd, WM_GETTEXT, lineLength, LPARAM(buffer));
   std::tstring str;
   str.append(buffer);
   return str;
}
//---------------------------------------------------------------------------

void CEdit::SetText(const TCHAR *Text)
{
   SendMessage(hwnd, WM_SETTEXT, lstrlen(Text), LPARAM(Text));
}
//---------------------------------------------------------------------------
}
