//---------------------------------------------------------------------------
#include "CheckBox.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CCheckBox::CCheckBox() : CComponent()
{
}
//---------------------------------------------------------------------------

CCheckBox::~CCheckBox()
{
}
//---------------------------------------------------------------------------

void CCheckBox::CreateObject(HWND Parent, DWORD Id)
{
   hwnd = CreateWindowEx(0, _T("button"), caption, WS_CHILD | (visible?WS_VISIBLE:0) | BS_AUTOCHECKBOX, left, top, width, height, Parent, HMENU(Id), GetModuleHandle(nullptr), nullptr);
   created = true;
   if (!enable)
   {
      SetEnable(false);
   }
}
//---------------------------------------------------------------------------

LRESULT CCheckBox::Message(UINT Type)
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

void CCheckBox::SetChecked(bool Checked)
{
   SendMessage(hwnd, BM_SETSTATE, Checked, 0);
}
//---------------------------------------------------------------------------

bool CCheckBox::GetChecked()
{
   return SendMessage(hwnd, BM_GETCHECK, 0, 0);
}
//---------------------------------------------------------------------------
}
