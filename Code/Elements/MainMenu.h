//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
#define MENU_BASE_ID 0x8000
//---------------------------------------------------------------------------
class CSubMenu
{
private:
   static int position;
   static std::vector<CDelegate<void> > callBack;

protected:
   HMENU hmenu;

public:
   CSubMenu();
   ~CSubMenu();
   void Message(UINT Id, UINT Type);

   void AddItemSeparator();
   void AddItem(const TCHAR *String, CDelegate<void> CallBack);
   void AddItem(const TCHAR *String, const CSubMenu *SubMenu);
};
//---------------------------------------------------------------------------
class CMainMenu : public CSubMenu
{
public:
   CMainMenu();
   ~CMainMenu();
   void Create(HWND Hwnd);
};
//---------------------------------------------------------------------------
}
