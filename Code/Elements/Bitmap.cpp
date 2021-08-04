//---------------------------------------------------------------------------
#include "Bitmap.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CBitmap::CBitmap()
{
   bitmap = nullptr;
}
//---------------------------------------------------------------------------

CBitmap::~CBitmap()
{
   Clear();
}
//---------------------------------------------------------------------------

void CBitmap::Clear()
{
   if (bitmap != nullptr)
   {
      DeleteObject(bitmap);
      bitmap = nullptr;
   }
}
//---------------------------------------------------------------------------

HDC CBitmap::CreateHDC(HDC Hdc) const
{
   HDC answer = CreateCompatibleDC(Hdc);
   SelectObject(answer, bitmap);
   return answer;
}
//---------------------------------------------------------------------------

DWORD CBitmap::GetData(void *Buffer, DWORD Size) const
{
   return GetBitmapBits(bitmap, Size, Buffer);
}
//---------------------------------------------------------------------------

bool CBitmap::Create(int Width, int Height, int Channels, int BytePerPixel, const void *Data)
{
   Clear();
   DWORD *temp = new DWORD[Width * Height];
   BYTE *t = (BYTE*)Data;
   if (Channels == 1)
   {
      for (int i = 0; i < Height; i++)
      {
         for (int o = 0; o < Width; o++)
         {
            temp[i * Width + o] = ((*t) << 16) | ((*t) << 8) | (*t);
            t++;
         }
      }
   }
   else if ((Channels == 3)||(Channels == 4))
   {
      for (int i = 0; i < Height; i++)
      {
         for (int o = 0; o < Width; o++)
         {
            DWORD color = *((DWORD*)t) & 0xFFFFFF;
            temp[i * Width + o] = (color >> 16) | ((color & 0xFF) << 16) | (color & 0xFF00);
            t += Channels;
         }
      }
   }
   else
   {
      delete[] temp;
      return false;
   }
   bitmap = CreateBitmap(Width, Height, 1, 32, temp);
   delete[] temp;
   return bitmap != nullptr;
}
//---------------------------------------------------------------------------

bool CBitmap::Load(TCHAR *ImageName)
{
   Clear();
   bitmap = (HBITMAP)LoadImage(nullptr, ImageName, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
   return bitmap != nullptr;
}
//---------------------------------------------------------------------------
}