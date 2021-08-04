//---------------------------------------------------------------------------
#include "Canvas.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CCanvas::CCanvas()
{
   hwnd = 0;
   hdc = 0;
}
//---------------------------------------------------------------------------

CCanvas::~CCanvas()
{
   Close();
}
//---------------------------------------------------------------------------

void CCanvas::Create(HWND Hwnd)
{
   Close();
   hwnd = Hwnd;
   hdc = GetDC(hwnd);
   SetStretchBltMode(hdc, COLORONCOLOR);
   Brush.Create(hdc);
   Pen.Create(hdc);
}
//---------------------------------------------------------------------------

void CCanvas::Close()
{
   if (hdc != 0)
   {
      ReleaseDC(hwnd, hdc);
      hwnd = 0;
      hdc = 0;
   }
}
//---------------------------------------------------------------------------

void CCanvas::SetBackColor(COLORREF Color)
{
   SetBkColor(hdc, Color);
}
//---------------------------------------------------------------------------

void CCanvas::SetTextColor(COLORREF Color)
{
   ::SetTextColor(hdc, Color);
}
//---------------------------------------------------------------------------

void CCanvas::Draw(int X, int Y, const CBitmap *Bitmap)
{
   HDC temp = Bitmap->CreateHDC(hdc);
   BITMAP picture;
   GetObject(Bitmap->bitmap, sizeof(BITMAP), &picture);
   BitBlt(hdc, X, Y, picture.bmWidth, picture.bmHeight, temp, 0, 0, SRCCOPY);
   DeleteDC(temp);
}
//---------------------------------------------------------------------------

void CCanvas::StretchDraw(int X, int Y, int Width, int Height, const CBitmap *Bitmap)
{
   HDC temp = Bitmap->CreateHDC(hdc);
   BITMAP picture;
   GetObject(Bitmap->bitmap, sizeof(BITMAP), &picture);
   StretchBlt(hdc, X, Y, Width, Height, temp, 0, 0, picture.bmWidth, picture.bmHeight, SRCCOPY);
   DeleteDC(temp);
}
//---------------------------------------------------------------------------

void CCanvas::ProportionalStretchDraw(int X, int Y, int Width, int Height, const CBitmap *Bitmap)
{
   HDC temp = Bitmap->CreateHDC(hdc);
   BITMAP picture;
   GetObject(Bitmap->bitmap, sizeof(BITMAP), &picture);
   if ((picture.bmWidth > 0)&&(picture.bmHeight > 0))
   {
      int centerX = X + Width / 2;
      int centerY = Y + Height / 2;

      float scaleSizeX = float(Width) / float(picture.bmWidth);
      float scaleSizeY = float(Height) / float(picture.bmHeight);
      float scale = MIN(scaleSizeX, scaleSizeY);

      int realWidth = picture.bmWidth * scale;
      int realHeight = picture.bmHeight * scale;
      StretchBlt(hdc, centerX - realWidth / 2, centerY - realHeight / 2, realWidth, realHeight, temp, 0, 0, picture.bmWidth, picture.bmHeight, SRCCOPY);
   }
   DeleteDC(temp);
}
//---------------------------------------------------------------------------

void CCanvas::PrintText(int X, int Y, const TCHAR *Text)
{
   TextOut(hdc, X, Y, Text, lstrlen(Text));
}
//---------------------------------------------------------------------------

void CCanvas::SetPixel(int X, int Y, COLORREF Color)
{
   ::SetPixel(hdc, X, Y, Color);
}
//---------------------------------------------------------------------------

void CCanvas::Rectangle(int X, int Y, int Width, int Height)
{
   ::Rectangle(hdc, X, Y, X + Width, Y + Height);
}
//---------------------------------------------------------------------------

void CCanvas::Ellipse(int X, int Y, int Width, int Height)
{
   ::Ellipse(hdc, X, Y, X + Width, Y + Height);
}
//---------------------------------------------------------------------------

void CCanvas::MoveTo(int X, int Y)
{
   MoveToEx(hdc, X, Y, nullptr);
}
//---------------------------------------------------------------------------

void CCanvas::LineTo(int X, int Y)
{
   ::LineTo(hdc, X, Y);
}
//---------------------------------------------------------------------------

COLORREF CCanvas::GetPixel(int X, int Y)
{
   return ::GetPixel(hdc, X, Y);
}
//---------------------------------------------------------------------------
}
