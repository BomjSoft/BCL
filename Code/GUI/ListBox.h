//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CListBox : public CComponent
{
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CListBox();
   virtual ~CListBox();

   void Clear();
   int AddString(const TCHAR *String);
   int InsertString(const TCHAR *String, int Position);
   std::tstring GetString(int Number);
   int DeleteItem(int Number);
   int GetSelectItem();
   int GetItemCount();
   void ShowItem(int Number);
   int SearchString(const TCHAR *String);

   CDelegate<void, CObject*> onChange;
};
//---------------------------------------------------------------------------
}
