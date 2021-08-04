//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "Brush.h"
#include "Bitmap.h"
#include "Pen.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CCanvas
{
friend class CForm;
private:
   HWND hwnd;
   HDC hdc;

   void Create(HWND Hwnd);
   void Close();

public:
   CCanvas();
   ~CCanvas();

   CBrush Brush;
   CPen Pen;

   void SetBackColor(COLORREF Color);
   void SetTextColor(COLORREF Color);

   void Draw(int X, int Y, const CBitmap *Bitmap);
   void StretchDraw(int X, int Y, int Width, int Height, const CBitmap *Bitmap);
   void ProportionalStretchDraw(int X, int Y, int Width, int Height, const CBitmap *Bitmap);
   void PrintText(int X, int Y, const TCHAR *Text);
   void SetPixel(int X, int Y, COLORREF Color);
   void Rectangle(int X, int Y, int Width, int Height);
   void Ellipse(int X, int Y, int Width, int Height);

   void MoveTo(int X, int Y);
   void LineTo(int X, int Y);

   COLORREF GetPixel(int X, int Y);
};
//---------------------------------------------------------------------------
}
