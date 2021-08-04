//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CRadioButton : public CComponent
{
   friend class CRadioGroup;
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CRadioButton();
   virtual ~CRadioButton();

   void SetChecked(bool Checked);

   bool GetChecked();

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
