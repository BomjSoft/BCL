//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CButton : public CComponent
{
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CButton();
   virtual ~CButton();

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
