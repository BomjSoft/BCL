//---------------------------------------------------------------------------
#include "Label.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CLabel::CLabel() : CComponent()
{
}
//---------------------------------------------------------------------------

CLabel::~CLabel()
{
}
//---------------------------------------------------------------------------

void CLabel::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("Static"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | SS_LEFT, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CLabel::Message(UINT Type)
{
   return 0;
}
//---------------------------------------------------------------------------

void CLabel::SetText(const TCHAR *Text)
{
   SetCaption(Text);
}
//---------------------------------------------------------------------------
}
