//---------------------------------------------------------------------------
#include "Application.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
CApplication::CApplication()
{
}
//---------------------------------------------------------------------------

CApplication::~CApplication()
{
}
//---------------------------------------------------------------------------

CApplication *CApplication::Instance()
{
   static CApplication app;
   return &app;
}
//---------------------------------------------------------------------------

void CApplication::Initialize()
{
   WNDCLASSEX wnd;
   wnd.cbSize = sizeof(WNDCLASSEX);
   wnd.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
   wnd.lpfnWndProc = StaticWndProc;
   wnd.cbClsExtra = 0;
   wnd.cbWndExtra = 0;
   wnd.hInstance = GetModuleHandle(nullptr);
   wnd.hIcon = NULL;
   wnd.hCursor = NULL;
   wnd.hbrBackground = HBRUSH(COLOR_BTNSHADOW);
   wnd.lpszMenuName = nullptr;
   wnd.lpszClassName = _T("BomjApplication");
   wnd.hIconSm = nullptr;
   if (!RegisterClassEx(&wnd))
   {
      throw std::runtime_error("Error class registration");
   }
}
//---------------------------------------------------------------------------

void CApplication::CreateForm(CForm *Form)
{
   forms.push_back(Form);
}
//---------------------------------------------------------------------------

void CApplication::Run()
{
   for (size_t i = 0; i < forms.size(); i++)
   {
      forms[i]->CreateForm(_T("BomjApplication"));
   }
   MSG message;
   BOOL ret;
   while ((ret = GetMessage(&message,nullptr,0,0)) != 0)
   {
      if (ret > 0)
      {
         TranslateMessage(&message);
         DispatchMessage(&message);
      }
      else
      {
         throw std::runtime_error("Runtime error in main loop");
      }
   }
}
//---------------------------------------------------------------------------

LRESULT CALLBACK CApplication::StaticWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   return CApplication::Instance()->WndProc(hwnd,msg,wParam,lParam);
}
//---------------------------------------------------------------------------

LRESULT CApplication::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   for (size_t i = 0; i < forms.size(); i++)
   {
      if (hwnd == forms[i]->hwnd)
      {
         return forms[i]->WndProc(hwnd,msg,wParam,lParam);
      }
   }
   for (size_t i = 0; i < forms.size(); i++)
   {
      if (forms[i]->hwnd == 0)
      {
         return forms[i]->WndProc(hwnd,msg,wParam,lParam);
      }
   }
   return DefWindowProc(hwnd,msg,wParam,lParam);
}
//---------------------------------------------------------------------------

int CApplication::ScreenWidth() const
{
   return GetSystemMetrics(SM_CXSCREEN);
}
//---------------------------------------------------------------------------

int CApplication::ScreenHeight() const
{
   return GetSystemMetrics(SM_CYSCREEN);
}
//---------------------------------------------------------------------------

int CApplication::CaptionHeight() const
{
   return GetSystemMetrics(SM_CYCAPTION);
}
//---------------------------------------------------------------------------

int CApplication::MenuHeight() const
{
   return GetSystemMetrics(SM_CYMENU);
}
//---------------------------------------------------------------------------
}
