//---------------------------------------------------------------------------
#include "CheckListBox.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CCheckListBox::CCheckListBox() : CComponent()
{
   imgList = 0;
   addedItem = false;
}
//---------------------------------------------------------------------------

CCheckListBox::~CCheckListBox()
{
}
//---------------------------------------------------------------------------

void CCheckListBox::CreateObject(HWND Parent, DWORD Id)
{
   InitExtComponent(ICC_LISTVIEW_CLASSES);
   hwnd = CreateWindowEx(0, WC_LISTVIEW, caption, WS_CHILD | WS_VSCROLL | (visible?WS_VISIBLE:0) | LVS_REPORT | LVS_SINGLESEL, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   ListView_SetExtendedListViewStyle(hwnd, LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT);

   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CCheckListBox::Message(UINT Type)
{
   LPNMHDR message = (LPNMHDR)Type;
   switch (message->code)
   {
      case LVN_ITEMCHANGING:
         if ((!onCheck.IsVoid())&&(!addedItem))
         {
            LPNMLISTVIEW info = (LPNMLISTVIEW)Type;
            if (info->uNewState & 0x2000)
            {
               onCheck(this, info->iItem, true);
            }
            else if (info->uNewState & 0x1000)
            {
               onCheck(this, info->iItem, false);
            }
         }
         break;

      case LVN_ITEMCHANGED:
         if (!onChange.IsVoid())
         {
            onChange(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------

void CCheckListBox::Clear()
{
   SendMessage(hwnd, LVM_DELETEALLITEMS, 0, 0);
}
//---------------------------------------------------------------------------

int CCheckListBox::AddColumn(const TCHAR *Caption)
{
   static int columnNumber = 0;
   LV_COLUMN col;
   col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
   col.fmt = LVCFMT_LEFT;
   col.cx =  _tcslen(Caption) * 20;
   col.pszText = (TCHAR*)Caption;
   col.iSubItem = columnNumber;
   int answer = ListView_InsertColumn(hwnd, columnNumber, &col);
   columnNumber++;
   return answer;
}
//---------------------------------------------------------------------------

int CCheckListBox::AddString(const TCHAR *String, bool State)
{
   LV_ITEM item;
   item.iItem = GetItemCount();
   item.mask = LVIF_TEXT;
   item.pszText = (TCHAR*)String;
   item.cchTextMax = _tcslen(String) + 1;
   item.lParam = 0;
   item.iSubItem = 0;
   addedItem = true;
   int answer = ListView_InsertItem(hwnd, &item);
   ListView_SetItemState(hwnd, answer, INDEXTOSTATEIMAGEMASK(State?2:1), LVIS_STATEIMAGEMASK);
   addedItem = false;
   return answer;
}
//---------------------------------------------------------------------------

void CCheckListBox::SetString(int StringNubmer, int ParamNumber, const TCHAR *String)
{
   LV_ITEM item;
   item.iItem = StringNubmer;
   item.mask = LVIF_TEXT;
   item.pszText = (TCHAR*)String;
   item.cchTextMax = _tcslen(String) + 1;
   item.lParam = 0;
   item.iSubItem = ParamNumber;
   ListView_SetItem(hwnd, &item);
}
//---------------------------------------------------------------------------

bool CCheckListBox::DeleteItem(int Number)
{
   return ListView_DeleteItem(hwnd, Number);
}
//---------------------------------------------------------------------------

int CCheckListBox::GetSelectItem()
{
   return ListView_GetNextItem(hwnd, -1, LVNI_ALL | LVNI_SELECTED);
}
//---------------------------------------------------------------------------

int CCheckListBox::GetItemCount()
{
   return ListView_GetItemCount(hwnd);
}
//---------------------------------------------------------------------------
}
