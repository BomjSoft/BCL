//---------------------------------------------------------------------------
#include "ListBox.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CListBox::CListBox() : CComponent()
{
}
//---------------------------------------------------------------------------

CListBox::~CListBox()
{
}
//---------------------------------------------------------------------------

void CListBox::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("listbox"), caption, WS_CHILD | WS_VSCROLL | (visible?WS_VISIBLE:0) | LBS_NOINTEGRALHEIGHT | LBS_WANTKEYBOARDINPUT | LBS_NOTIFY, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CListBox::Message(UINT Type)
{
   switch (Type)
   {
      case LBN_SELCHANGE:
         if (!onChange.IsVoid())
         {
            onChange(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------

void CListBox::Clear()
{
   SendMessage(hwnd, LB_RESETCONTENT, 0, 0);
}
//---------------------------------------------------------------------------

int CListBox::AddString(const TCHAR *String)
{
   return SendMessage(hwnd, LB_ADDSTRING, 0, (LPARAM)String);
}
//---------------------------------------------------------------------------

int CListBox::InsertString(const TCHAR *String, int Position)
{
   return SendMessage(hwnd, LB_INSERTSTRING, Position, (LPARAM)String);
}
//---------------------------------------------------------------------------

std::tstring CListBox::GetString(int Number)
{
   int lineLength = SendMessage(hwnd, LB_GETTEXTLEN, Number, 0);
   TCHAR buffer[lineLength + 1];
   SendMessage(hwnd, LB_GETTEXT, Number, LPARAM(buffer));
   std::tstring str;
   str.append(buffer);
   return str;
}
//---------------------------------------------------------------------------

int CListBox::DeleteItem(int Number)
{
   return SendMessage(hwnd, LB_DELETESTRING, Number, 0);
}
//---------------------------------------------------------------------------

int CListBox::GetSelectItem()
{
   return SendMessage(hwnd, LB_GETCURSEL, 0, 0);
}
//---------------------------------------------------------------------------

int CListBox::GetItemCount()
{
   return SendMessage(hwnd, LB_GETCOUNT, 0, 0);
}
//---------------------------------------------------------------------------

void CListBox::ShowItem(int Number)
{
   SendMessage(hwnd, LB_SETTOPINDEX, Number, 0);
}
//---------------------------------------------------------------------------

int CListBox::SearchString(const TCHAR *String)
{
   return SendMessage(hwnd, LB_FINDSTRINGEXACT, 0, (LPARAM)String);
}
//---------------------------------------------------------------------------
}
