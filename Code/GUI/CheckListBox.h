//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CCheckListBox : public CComponent
{
private:
   HIMAGELIST imgList;
   bool addedItem;

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CCheckListBox();
   virtual ~CCheckListBox();

   CDelegate<void, CObject*> onChange;
   CDelegate<void, CObject*, int, bool> onCheck;

   void Clear();
   int AddColumn(const TCHAR *Caption);
   int AddString(const TCHAR *String, bool State = false);
   void SetString(int StringNubmer, int ParamNumber, const TCHAR *String);
   bool DeleteItem(int Number);
   int GetSelectItem();
   int GetItemCount();
};
//---------------------------------------------------------------------------
}
