//---------------------------------------------------------------------------
#include "ProgressBar.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CProgressBar::CProgressBar() : CComponent()
{
   minValue = 0;
   maxValue = 100;
}
//---------------------------------------------------------------------------

CProgressBar::~CProgressBar()
{
}
//---------------------------------------------------------------------------

void CProgressBar::CreateObject(HWND Parent, DWORD Id)
{
   InitExtComponent(ICC_PROGRESS_CLASS);
   hwnd = CreateWindowEx(0, PROGRESS_CLASS, caption, WS_CHILD | (visible?WS_VISIBLE:0) | PBS_SMOOTH, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   SendMessage(hwnd, PBM_SETRANGE, TRUE, MAKELPARAM(minValue, maxValue));
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CProgressBar::Message(UINT Type)
{
   return 0;
}
//---------------------------------------------------------------------------

void CProgressBar::SetRange(int Min, int Max)
{
   minValue = Min;
   maxValue = Max;
   if (created)
   {
      SendMessage(hwnd, PBM_SETRANGE, TRUE, MAKELPARAM(minValue, maxValue));
   }
}
//---------------------------------------------------------------------------

void CProgressBar::SetPosition(int Value)
{
   SendMessage(hwnd, PBM_SETPOS, Value, 0);
}
//---------------------------------------------------------------------------

void CProgressBar::SetStep(int Value)
{
   SendMessage(hwnd, PBM_SETSTEP, Value, 0);
}
//---------------------------------------------------------------------------

void CProgressBar::Update(int StepCount)
{
   SendMessage(hwnd, PBM_DELTAPOS, StepCount, 0);
}
//---------------------------------------------------------------------------

void CProgressBar::Update()
{
   SendMessage(hwnd, PBM_STEPIT, 0, 0);
}
//---------------------------------------------------------------------------
}
