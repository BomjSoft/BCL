//---------------------------------------------------------------------------
#include "Button.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CButton::CButton() : CComponent()
{
}
//---------------------------------------------------------------------------

CButton::~CButton()
{
}
//---------------------------------------------------------------------------

void CButton::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("button"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | BS_DEFPUSHBUTTON, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CButton::Message(UINT Type)
{
   switch (Type)
   {
      case BN_CLICKED:
         if (!onClick.IsVoid())
         {
            onClick(this);
         }
         break;
   }
   return 0;
}
//---------------------------------------------------------------------------
}
