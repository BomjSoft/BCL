//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CProgressBar : public CComponent
{
private:
   int minValue;
   int maxValue;

protected:
   virtual void CreateObject(HWND Parent, DWORD Id);
   virtual LRESULT Message(UINT Type);

public:
   CProgressBar();
   virtual ~CProgressBar();

   void SetRange(int Min, int Max);
   void SetPosition(int Value);
   void SetStep(int Value);
   void Update(int StepCount);
   void Update();
};
//---------------------------------------------------------------------------
}
