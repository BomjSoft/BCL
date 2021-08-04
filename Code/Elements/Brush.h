//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
enum EBrushStyle {bsSolid,
                  bsClear,
                  bsHorizontal = HS_HORIZONTAL,
                  bsVertical = HS_VERTICAL,
                  bsFDiagonal = HS_FDIAGONAL,
                  bsBDiagonal = HS_BDIAGONAL,
                  bsCross = HS_CROSS,
                  bsDiagCross = HS_DIAGCROSS};
//---------------------------------------------------------------------------
class CBrush
{
friend class CCanvas;
private:
   HDC hdc;
   HGDIOBJ oldBrush;
   HBRUSH brush;

   COLORREF color;
   EBrushStyle style;

   void Create(HDC Hdc);
   void Close();

public:
   CBrush();
   ~CBrush();

   void SetColor(COLORREF Color);
   void SetStyle(EBrushStyle Style);
};
//---------------------------------------------------------------------------
}
