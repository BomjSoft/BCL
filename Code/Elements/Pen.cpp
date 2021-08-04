//---------------------------------------------------------------------------
#include "Pen.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CPen::CPen()
{
   hdc = 0;
   oldPen = 0;
   pen = 0;
   style = psSolid;
   width = 1;
}
//---------------------------------------------------------------------------

CPen::~CPen()
{
   Close();
}
//---------------------------------------------------------------------------

void CPen::Create(HDC Hdc)
{
   Close();
   hdc = Hdc;
}
//---------------------------------------------------------------------------

void CPen::Close()
{
   if (pen != 0)
   {
      if (oldPen != 0)
      {
         SelectObject(hdc, oldPen);
         oldPen = 0;
      }
      DeleteObject(pen);
      pen = 0;
   }
}
//---------------------------------------------------------------------------

void CPen::SetColor(COLORREF Color)
{
   Close();
   color = Color;
   pen = CreatePen(style, width, color);
   oldPen = SelectObject(hdc, pen);
}
//---------------------------------------------------------------------------

void CPen::SetStyle(EPenStyle Style)
{
   Close();
   style = Style;
   pen = CreatePen(style, width, color);
   oldPen = SelectObject(hdc, pen);
}
//---------------------------------------------------------------------------

void CPen::SetWidth(int Width)
{
   Close();
   width = Width;
   pen = CreatePen(style, width, color);
   oldPen = SelectObject(hdc, pen);
}
//---------------------------------------------------------------------------
}
