//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "Object.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CComponent : public CObject
{
friend class CForm;
protected:
   static void InitExtComponent(DWORD Component);

   virtual void CreateObject(HWND Parent, DWORD Id) = 0;
   virtual LRESULT Message(UINT Type) = 0;

public:
   CComponent();
   virtual ~CComponent();
};
//---------------------------------------------------------------------------
}
