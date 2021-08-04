//---------------------------------------------------------------------------
#include "Component.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CComponent::CComponent() : CObject()
{
}
//---------------------------------------------------------------------------

CComponent::~CComponent()
{
}
//---------------------------------------------------------------------------

void CComponent::InitExtComponent(DWORD Component)
{
   INITCOMMONCONTROLSEX control;
   control.dwSize = sizeof(INITCOMMONCONTROLSEX);
   control.dwICC = Component;
   InitCommonControlsEx(&control);
}
//---------------------------------------------------------------------------
}
