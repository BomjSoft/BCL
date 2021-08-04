//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CEdit : public CComponent
{
private:

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CEdit();
   virtual ~CEdit();

   std::tstring GetText();

   void SetText(const TCHAR *Text);

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
