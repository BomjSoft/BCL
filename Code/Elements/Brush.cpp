//---------------------------------------------------------------------------
#include "Brush.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CBrush::CBrush()
{
   hdc = 0;
   oldBrush = 0;
   brush = 0;
   style = bsSolid;
}
//---------------------------------------------------------------------------

CBrush::~CBrush()
{
   Close();
}
//---------------------------------------------------------------------------

void CBrush::Create(HDC Hdc)
{
   Close();
   hdc = Hdc;
}
//---------------------------------------------------------------------------

void CBrush::Close()
{
   if (brush != 0)
   {
      if (oldBrush != 0)
      {
         SelectObject(hdc, oldBrush);
         oldBrush = 0;
      }
      DeleteObject(brush);
      brush = 0;
   }
}
//---------------------------------------------------------------------------

void CBrush::SetColor(COLORREF Color)
{
   Close();
   color = Color;
   if (style == bsSolid)
   {
      brush = CreateSolidBrush(color);
   }
   else
   {
      brush = CreateHatchBrush(style, color);
   }
   oldBrush = SelectObject(hdc, brush);
}
//---------------------------------------------------------------------------

void CBrush::SetStyle(EBrushStyle Style)
{
   Close();
   style = Style;
   if (style == bsSolid)
   {
      brush = CreateSolidBrush(color);
   }
   else
   {
      brush = CreateHatchBrush(style, color);
   }
   oldBrush = SelectObject(hdc, brush);
}
//---------------------------------------------------------------------------
}
