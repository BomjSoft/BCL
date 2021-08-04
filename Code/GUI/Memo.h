//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CMemo : public CComponent
{
private:
   bool readOnly;

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CMemo();
   virtual ~CMemo();

   std::tstring GetText();

   void SetText(const TCHAR *Text);
   void SetReadOnly(bool ReadOnly);

   CDelegate<void, CObject*> onClick;
};
//---------------------------------------------------------------------------
}
