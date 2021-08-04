//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CObject
{
protected:
   HWND hwnd;
   CObject *parent;
   bool created;

   const TCHAR *caption;
   DWORD style;
   int top;
   int left;
   int width;
   int height;
   bool visible;
   bool enable;

public:
   CObject();
   virtual ~CObject();

   void SetParent(CObject *Parent);
   void SetCaption(const TCHAR *Caption);
   void SetTop(int Top);
   void SetLeft(int Left);
   void SetWidth(int Width);
   void SetHeight(int Height);
   void SetVisible(bool Visible);
   void SetEnable(bool Enable);

   CObject *GetParent() const;
   int GetTop() const;
   int GetLeft() const;
   int GetWidth() const;
   int GetHeight() const;
   bool GetVisible() const;
   bool GetEnable() const;
};
//---------------------------------------------------------------------------
}
