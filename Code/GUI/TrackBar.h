//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CTrackBar : public CComponent
{
private:
   int minValue;
   int maxValue;

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CTrackBar();
   virtual ~CTrackBar();

   void SetRange(int Min, int Max);
   void SetPosition(int Value);

   int GetPosition();

   CDelegate<void, CObject*> onChange;
};
//---------------------------------------------------------------------------
}
