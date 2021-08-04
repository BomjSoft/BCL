//---------------------------------------------------------------------------
#include "MainMenu.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
int CSubMenu::position = 0;
std::vector<CDelegate<void> > CSubMenu::callBack;
//---------------------------------------------------------------------------
CSubMenu::CSubMenu()
{
   hmenu = CreatePopupMenu();
}
//---------------------------------------------------------------------------

CSubMenu::~CSubMenu()
{
}
//---------------------------------------------------------------------------

CMainMenu::CMainMenu()
{
   hmenu = nullptr;
}
//---------------------------------------------------------------------------

CMainMenu::~CMainMenu()
{

}
//---------------------------------------------------------------------------

void CSubMenu::Message(UINT Id, UINT Type)
{
   Id -= MENU_BASE_ID;
   if (Id >= callBack.size())
   {
      return;
   }
   callBack[Id]();
}
//---------------------------------------------------------------------------

void CMainMenu::Create(HWND Hwnd)
{
   if (hmenu == nullptr)
   {
      hmenu = CreateMenu();
   }
   SetMenu(Hwnd, hmenu);
   DrawMenuBar(Hwnd);
}
//---------------------------------------------------------------------------

void CSubMenu::AddItemSeparator()
{
   MENUITEMINFO item;
   item.cbSize = sizeof(MENUITEMINFO);
   item.fMask = MIIM_STATE | MIIM_TYPE;
   item.fType = MFT_SEPARATOR;
   item.fState = MFS_ENABLED;
   item.wID = 0;
   item.hSubMenu = nullptr;
   item.hbmpChecked = nullptr;
   item.hbmpUnchecked = nullptr;
   item.dwItemData = 0;
   item.dwTypeData = nullptr;
   item.cch = 0;
   InsertMenuItem(hmenu, position++, FALSE, &item);
}
//---------------------------------------------------------------------------

void CSubMenu::AddItem(const TCHAR *String, CDelegate<void> CallBack)
{
   MENUITEMINFO item;
   item.cbSize = sizeof(MENUITEMINFO);
   item.fMask = MIIM_STATE | MIIM_TYPE | MIIM_ID;
   item.fType = MFT_STRING;
   item.fState = MFS_ENABLED;
   if (CallBack.IsVoid())
   {
      item.wID = 0;
   }
   else
   {
      item.wID = callBack.size() + MENU_BASE_ID;
      callBack.push_back(CallBack);
   }
   item.hSubMenu = nullptr;
   item.hbmpChecked = nullptr;
   item.hbmpUnchecked = nullptr;
   item.dwItemData = 0;
   item.dwTypeData = (TCHAR *)String;
   item.cch = sizeof(String);
   InsertMenuItem(hmenu, position++, FALSE, &item);
}
//---------------------------------------------------------------------------

void CSubMenu::AddItem(const TCHAR *String, const CSubMenu *SubMenu)
{
   MENUITEMINFO item;
   item.cbSize = sizeof(MENUITEMINFO);
   item.fMask = MIIM_STATE | MIIM_TYPE | MIIM_SUBMENU;
   item.fType = MFT_STRING;
   item.fState = MFS_ENABLED;
   item.wID = 0;
   item.hSubMenu = SubMenu->hmenu;
   item.hbmpChecked = nullptr;
   item.hbmpUnchecked = nullptr;
   item.dwItemData = 0;
   item.dwTypeData = (TCHAR *)String;
   item.cch = sizeof(String);
   InsertMenuItem(hmenu, position++, FALSE, &item);
}
//---------------------------------------------------------------------------
}
