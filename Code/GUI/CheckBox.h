//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CCheckBox : public CComponent
{
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CCheckBox();
   virtual ~CCheckBox();

   void SetChecked(bool Checked);

   bool GetChecked();

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
