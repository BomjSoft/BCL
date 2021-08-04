//---------------------------------------------------------------------------
#include "Object.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CObject::CObject()
{
   hwnd = NULL;
   parent = nullptr;
   caption = _T("");
   created = false;
   visible = true;
   enable = true;
}
//---------------------------------------------------------------------------

CObject::~CObject()
{
}
//---------------------------------------------------------------------------

void CObject::SetParent(CObject *Parent)
{
   parent = Parent;
}
//---------------------------------------------------------------------------

void CObject::SetCaption(const TCHAR *Caption)
{
   caption = Caption;
   if (created)
   {
      SetWindowText(hwnd,caption);
   }
}
//---------------------------------------------------------------------------

void CObject::SetTop(int Top)
{
   top = Top;
   if (created)
   {
      MoveWindow(hwnd,left,top,width,height,TRUE);
   }
}
//---------------------------------------------------------------------------

void CObject::SetLeft(int Left)
{
   left = Left;
   if (created)
   {
      MoveWindow(hwnd,left,top,width,height,TRUE);
   }
}
//---------------------------------------------------------------------------

void CObject::SetWidth(int Width)
{
   width = Width;
   if (created)
   {
      MoveWindow(hwnd,left,top,width,height,TRUE);
   }
}
//---------------------------------------------------------------------------

void CObject::SetHeight(int Height)
{
   height = Height;
   if (created)
   {
      MoveWindow(hwnd,left,top,width,height,TRUE);
   }
}
//---------------------------------------------------------------------------

void CObject::SetVisible(bool Visible)
{
   visible = Visible;
   if (created)
   {
      ShowWindow(hwnd, visible?SW_NORMAL:SW_HIDE);
   }
}
//---------------------------------------------------------------------------

void CObject::SetEnable(bool Enable)
{
   enable = Enable;
   if (created)
   {
      EnableWindow(hwnd, enable);
   }
}
//---------------------------------------------------------------------------

CObject *CObject::GetParent() const
{
   return parent;
}
//---------------------------------------------------------------------------

int CObject::GetTop() const
{
   return top;
}
//---------------------------------------------------------------------------

int CObject::GetLeft() const
{
   return left;
}
//---------------------------------------------------------------------------

int CObject::GetWidth() const
{
   return width;
}
//---------------------------------------------------------------------------

int CObject::GetHeight() const
{
   return height;
}
//---------------------------------------------------------------------------

bool CObject::GetVisible() const
{
   return visible;
}
//---------------------------------------------------------------------------

bool CObject::GetEnable() const
{
   return enable;
}
//---------------------------------------------------------------------------
}
