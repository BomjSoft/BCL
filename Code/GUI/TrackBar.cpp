//---------------------------------------------------------------------------
#include "TrackBar.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CTrackBar::CTrackBar() : CComponent()
{
   minValue = 0;
   maxValue = 100;
}
//---------------------------------------------------------------------------

CTrackBar::~CTrackBar()
{
}
//---------------------------------------------------------------------------

void CTrackBar::CreateObject(HWND Parent, DWORD Id)
{
   InitExtComponent(ICC_BAR_CLASSES);
   hwnd = CreateWindowEx(0, TRACKBAR_CLASS, caption, WS_CHILD | (visible?WS_VISIBLE:0) | TBS_LEFT | TBS_VERT, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   SendMessage(hwnd, TBM_SETRANGE, TRUE, MAKELPARAM(minValue, maxValue));
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CTrackBar::Message(UINT Type)
{
   switch (LOWORD(Type))
   {
      case TB_LINEUP:
      case TB_LINEDOWN:
      case TB_PAGEUP:
      case TB_PAGEDOWN:
      case TB_THUMBPOSITION:
      case TB_THUMBTRACK:
      case TB_TOP:
      case TB_BOTTOM:
         if (!onChange.IsVoid())
         {
            onChange(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------

void CTrackBar::SetRange(int Min, int Max)
{
   minValue = Min;
   maxValue = Max;
   if (created)
   {
      SendMessage(hwnd, TBM_SETRANGE, TRUE, MAKELPARAM(minValue, maxValue));
   }
}
//---------------------------------------------------------------------------

void CTrackBar::SetPosition(int Value)
{
   SendMessage(hwnd, TBM_SETPOS, TRUE, Value);
}
//---------------------------------------------------------------------------

int CTrackBar::GetPosition()
{
   return SendMessage(hwnd, TBM_GETPOS, 0, 0);
}
//---------------------------------------------------------------------------
}
