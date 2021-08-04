//---------------------------------------------------------------------------
#include "Form.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
std::vector<CComponent*> CForm::object;
//---------------------------------------------------------------------------
CForm::CForm() : CObject()
{
   caption = _T("Form");
   style = WS_OVERLAPPEDWINDOW;
   top = CW_USEDEFAULT;
   left = CW_USEDEFAULT;
   width = CW_USEDEFAULT;
   height = CW_USEDEFAULT;
}
//---------------------------------------------------------------------------

CForm::~CForm()
{
}
//---------------------------------------------------------------------------

void CForm::CreateForm(const TCHAR *ClassName)
{
   hwnd = CreateWindowEx(0, ClassName, caption, style, left, top, width, height, HWND_DESKTOP, NULL, GetModuleHandle(nullptr), nullptr);
   if (hwnd == NULL)
   {
      throw std::runtime_error("Error window created");
   }
   Canvas.Create(hwnd);
   ShowWindow(hwnd,SW_SHOW);
   UpdateWindow(hwnd);
   DrawMenuBar(hwnd);
}
//---------------------------------------------------------------------------

void CForm::Redraw()
{
   InvalidateRect(hwnd, nullptr, TRUE);
   UpdateWindow(hwnd);
}
//---------------------------------------------------------------------------

LRESULT CForm::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
   switch (msg)
   {
      case WM_CREATE:
         created = true;
         MainMenu.Create(hwnd);
         DrawMenuBar(hwnd);
         for (size_t i = 0; i < object.size(); i++)
         {
            if ((object[i] != nullptr)&&(object[i]->GetParent() == this))
            {
               object[i]->CreateObject(hwnd, i + 1);
            }
         }
         if (!onCreate.IsVoid())
         {
            onCreate(this);
         }
         return 0;

      case WM_DESTROY:
         created = false;
         PostQuitMessage(0);
         return 0;

      case WM_MOVE:
         left = LOWORD(lParam);
         top = HIWORD(lParam);
         return 0;

      case WM_SIZE:
         width = LOWORD(lParam);
         height = HIWORD(lParam);
         if (!onResize.IsVoid())
         {
            onResize(this);
         }
         return 0;

      case WM_ACTIVATE:
         if (!onActivate.IsVoid())
         {
            onActivate(this);
         }
         break;

      case WM_PAINT:
         {
            PAINTSTRUCT paint;
            BeginPaint(hwnd, &paint);
            if (!onPaint.IsVoid())
            {
               onPaint(this);
            }
            EndPaint(hwnd, &paint);
         }
         return 0;

      case WM_NOTIFY:
         if (LOWORD(wParam) != 0)
         {
            if (LOWORD(wParam) <= object.size())
            {
               object[LOWORD(wParam) - 1]->Message(lParam);
            }
         }
         return 0;

      case WM_COMMAND:
         if (LOWORD(wParam) != 0)
         {
            if (LOWORD(wParam) <= object.size())
            {
               object[LOWORD(wParam) - 1]->Message(HIWORD(wParam));
            }
            else
            {
               MainMenu.Message(LOWORD(wParam), HIWORD(wParam));
            }
         }
         return 0;

      case WM_HSCROLL:
      case WM_VSCROLL:
         for (size_t i = 0; i < object.size(); i++)
         {
            if (HWND(lParam) == object[i]->hwnd)
            {
               return object[i]->Message(wParam);
            }
         }
         break;

      case WM_LBUTTONDOWN:
         if (!onMouseDown.IsVoid())
         {
            onMouseDown(this, mbLeft, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_LBUTTONUP:
         if (!onMouseUp.IsVoid())
         {
            onMouseUp(this, mbLeft, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_LBUTTONDBLCLK:
         if (!onMouseDoubleClick.IsVoid())
         {
            onMouseDoubleClick(this, mbLeft, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_RBUTTONDOWN:
         if (!onMouseDown.IsVoid())
         {
            onMouseDown(this, mbRight, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_RBUTTONUP:
         if (!onMouseUp.IsVoid())
         {
            onMouseUp(this, mbRight, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_RBUTTONDBLCLK:
         if (!onMouseDoubleClick.IsVoid())
         {
            onMouseDoubleClick(this, mbRight, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_MBUTTONDOWN:
         if (!onMouseDown.IsVoid())
         {
            onMouseDown(this, mbMiddle, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_MBUTTONUP:
         if (!onMouseUp.IsVoid())
         {
            onMouseUp(this, mbMiddle, LOWORD(lParam), HIWORD(lParam));
         }
         break;

      case WM_MBUTTONDBLCLK:
         if (!onMouseDoubleClick.IsVoid())
         {
            onMouseDoubleClick(this, mbMiddle, LOWORD(lParam), HIWORD(lParam));
         }
         break;
   }
   return DefWindowProc(hwnd,msg,wParam,lParam);
}
//---------------------------------------------------------------------------

void CForm::AddObject(CComponent *Object)
{
   object.push_back(Object);
   Object->SetParent(this);
}
//---------------------------------------------------------------------------

int CForm::GetClientWidth() const
{
   RECT rect;
   GetClientRect(hwnd,&rect);
   return rect.right - rect.left;
}
//---------------------------------------------------------------------------

int CForm::GetClientHeight() const
{
   RECT rect;
   GetClientRect(hwnd,&rect);
   return rect.bottom - rect.top;
}
//---------------------------------------------------------------------------
}
