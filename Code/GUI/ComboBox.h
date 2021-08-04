//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CComboBox : public CComponent
{
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CComboBox();
   virtual ~CComboBox();
   void Clear();

   int AddString(const TCHAR *String);
   int DeleteItem(int Number);
   int GetItemCount();
   int GetSelectItem();
   void SelectItem(int Number);

   CDelegate<void, CObject*> onChange;
};
//---------------------------------------------------------------------------
}
