//---------------------------------------------------------------------------
#include "RadioButton.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CRadioButton::CRadioButton() : CComponent()
{
}
//---------------------------------------------------------------------------

CRadioButton::~CRadioButton()
{
}
//---------------------------------------------------------------------------

void CRadioButton::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("button"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | BS_AUTORADIOBUTTON, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CRadioButton::Message(UINT Type)
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

void CRadioButton::SetChecked(bool Checked)
{
   SendMessage(hwnd, BM_SETCHECK, Checked?TRUE:FALSE, 0);
}
//---------------------------------------------------------------------------

bool CRadioButton::GetChecked()
{
   return SendMessage(hwnd, BM_GETCHECK, 0, 0) != FALSE;
}
//---------------------------------------------------------------------------
}
