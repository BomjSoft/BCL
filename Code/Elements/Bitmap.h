//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CBitmap
{
friend class CCanvas;
private:
   HBITMAP bitmap;

   HDC CreateHDC(HDC Hdc) const;

public:
   CBitmap();
   ~CBitmap();
   void Clear();

   DWORD GetData(void *Buffer, DWORD Size) const;

   bool Create(int Width, int Height, int Channels, int BytePerPixel, const void *Data);
   bool Load(TCHAR *ImageName);
};
//---------------------------------------------------------------------------
}
