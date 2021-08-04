//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
#include "../Application.h"
#include "RadioButton.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CRadioGroup : public CComponent
{
private:
   std::vector<CRadioButton> itemList;

   DWORD id;

   static WNDPROC oldGroupBoxProc;
   static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

   void CreateItem(size_t Number);
   void RepositionItem();

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CRadioGroup();
   virtual ~CRadioGroup();

   void AddItem(const TCHAR *Name);
   void SetTop(int Top);
   void SetLeft(int Left);
   void SetWidth(int Width);
   void SetHeight(int Height);
   void SetEnable(bool Enable);

   int GetSelectItem();
   void SelectItem(int Number);

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
