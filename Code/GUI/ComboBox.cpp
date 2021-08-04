//---------------------------------------------------------------------------
#include "ComboBox.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CComboBox::CComboBox() : CComponent()
{
}
//---------------------------------------------------------------------------

CComboBox::~CComboBox()
{
}
//---------------------------------------------------------------------------

void CComboBox::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("combobox"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | CBS_DISABLENOSCROLL | CBS_AUTOHSCROLL | CBS_DROPDOWNLIST, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CComboBox::Message(UINT Type)
{
   switch (Type)
   {
      case CBN_SELCHANGE:
         if (!onChange.IsVoid())
         {
            onChange(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------

void CComboBox::Clear()
{
   SendMessage(hwnd, CB_RESETCONTENT, 0, 0);
}
//---------------------------------------------------------------------------

int CComboBox::AddString(const TCHAR *String)
{
   return SendMessage(hwnd, CB_ADDSTRING, 0, (LPARAM)String);
}
//---------------------------------------------------------------------------

int CComboBox::DeleteItem(int Number)
{
   return SendMessage(hwnd, CB_DELETESTRING, Number, 0);
}
//---------------------------------------------------------------------------

int CComboBox::GetItemCount()
{
   return SendMessage(hwnd, CB_GETCOUNT, 0, 0);
}
//---------------------------------------------------------------------------

int CComboBox::GetSelectItem()
{
   return SendMessage(hwnd, CB_GETCURSEL, 0, 0);
}
//---------------------------------------------------------------------------

void CComboBox::SelectItem(int Number)
{
   SendMessage(hwnd, CB_SETCURSEL, Number, 0);
}
//---------------------------------------------------------------------------
}
