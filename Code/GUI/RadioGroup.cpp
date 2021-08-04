//---------------------------------------------------------------------------
#include "RadioGroup.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
WNDPROC CRadioGroup::oldGroupBoxProc = nullptr;
//---------------------------------------------------------------------------
CRadioGroup::CRadioGroup() : CComponent()
{
}
//---------------------------------------------------------------------------

CRadioGroup::~CRadioGroup()
{
}
//---------------------------------------------------------------------------

void CRadioGroup::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("button"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | BS_GROUPBOX, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   id = Id;
   for (size_t i = 0; i < itemList.size(); i++)
   {
      CreateItem(i);
   }
   RepositionItem();

   if (oldGroupBoxProc == nullptr)
   {
      oldGroupBoxProc = (WNDPROC)GetWindowLongPtr(hwnd, GWLP_WNDPROC);
   }
   SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG)StaticWndProc);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CALLBACK CRadioGroup::StaticWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   if (msg == WM_COMMAND)
   {
      CallWindowProc(CApplication::StaticWndProc, ::GetParent(hwnd), msg, wParam, lParam);
   }
   return CallWindowProc(oldGroupBoxProc, hwnd, msg, wParam, lParam);
}
//---------------------------------------------------------------------------

void CRadioGroup::CreateItem(size_t Number)
{
   itemList[Number].CreateObject(hwnd, id);
}
//---------------------------------------------------------------------------

void CRadioGroup::RepositionItem()
{
   if (itemList.size() != 0)
   {
      int delta = height / (itemList.size() + 1);
      for (size_t i = 0; i < itemList.size(); i++)
      {
         itemList[i].SetTop(delta * (i + 1));
         itemList[i].SetLeft(10);
         itemList[i].SetWidth(width - 20);
         itemList[i].SetHeight(20);
      }
   }
}
//---------------------------------------------------------------------------

LRESULT CRadioGroup::Message(UINT Type)
{
   switch (Type)
   {
      case BN_CLICKED:
         if (!onClick.IsVoid())
         {
            onClick(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------

void CRadioGroup::AddItem(const TCHAR *Name)
{
   CRadioButton temp;
   itemList.push_back(temp);
   itemList.back().SetCaption(Name);
   itemList.back().SetParent(this);
   if (created)
   {
      CreateItem(itemList.size() - 1);
      RepositionItem();
   }
}
//---------------------------------------------------------------------------

void CRadioGroup::SetTop(int Top)
{
   CObject::SetTop(Top);
   RepositionItem();
}
//---------------------------------------------------------------------------

void CRadioGroup::SetLeft(int Left)
{
   CObject::SetLeft(Left);
   RepositionItem();
}
//---------------------------------------------------------------------------

void CRadioGroup::SetWidth(int Width)
{
   CObject::SetWidth(Width);
   RepositionItem();
}
//---------------------------------------------------------------------------

void CRadioGroup::SetHeight(int Height)
{
   CObject::SetHeight(Height);
   RepositionItem();
}
//---------------------------------------------------------------------------

void CRadioGroup::SetEnable(bool Enable)
{
   for (size_t i = 0; i < itemList.size(); i++)
   {
      itemList[i].SetEnable(Enable);
   }
}
//---------------------------------------------------------------------------

int CRadioGroup::GetSelectItem()
{
   for (size_t i = 0; i < itemList.size(); i++)
   {
      if (itemList[i].GetChecked())
      {
         return i;
      }
   }
   return -1;
}
//---------------------------------------------------------------------------

void CRadioGroup::SelectItem(int Number)
{
   if ((Number >= 0)&&(size_t(Number) < itemList.size()))
   {
      itemList[Number].SetChecked(true);
   }
   else
   {
      for (size_t i = 0; i < itemList.size(); i++)
      {
         itemList[i].SetChecked(false);
      }
   }
}
//---------------------------------------------------------------------------
}
