//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "Includes.h"
#include "GUI/Form.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CApplication
{
   friend class CRadioGroup;
private:
   std::vector<CForm*> forms;

   static LRESULT CALLBACK StaticWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
   LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
   CApplication();
   ~CApplication();

public:
   static CApplication *Instance();

   void Initialize();
   void CreateForm(CForm *Form);
   void Run();

   int ScreenWidth() const;
   int ScreenHeight() const;
   int CaptionHeight() const;
   int MenuHeight() const;
};
//---------------------------------------------------------------------------
}
