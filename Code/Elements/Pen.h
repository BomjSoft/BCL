//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
enum EPenStyle {psSolid = PS_SOLID,
                psDash = PS_DASH,
                psDot = PS_DOT,
                psDashDot = PS_DASHDOT,
                psDashDotDot = PS_DASHDOTDOT,
                psClear = PS_NULL,
                psInsideFrame = PS_INSIDEFRAME};
//---------------------------------------------------------------------------
class CPen
{
friend class CCanvas;
private:
   HDC hdc;
   HGDIOBJ oldPen;
   HPEN pen;

   COLORREF color;
   EPenStyle style;
   int width;

   void Create(HDC Hdc);
   void Close();

public:
   CPen();
   ~CPen();

   void SetColor(COLORREF Color);
   void SetStyle(EPenStyle Style);
   void SetWidth(int Width);
};
//---------------------------------------------------------------------------
}
