//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../ServiceComponents/Component.h"
#include "../Elements/Canvas.h"
#include "../Elements/MainMenu.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CForm : public CObject
{
   friend class CApplication;
   friend class COpenFileDialog;
   friend class CSaveFileDialog;
private:
   static std::vector<CComponent*> object;

   void CreateForm(const TCHAR *ClassName);
   LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

protected:
   void AddObject(CComponent *Object);

public:
   CForm();
   virtual ~CForm();

   void Redraw();

   int GetClientWidth() const;
   int GetClientHeight() const;

   CCanvas Canvas;
   CMainMenu MainMenu;

   CDelegate<void, CObject*> onCreate;
   CDelegate<void, CObject*> onActivate;
   CDelegate<void, CObject*> onResize;
   CDelegate<void, CObject*> onPaint;
   CDelegate<void, CObject*, EMouseButton, int, int> onMouseDown;
   CDelegate<void, CObject*, EMouseButton, int, int> onMouseUp;
   CDelegate<void, CObject*, EMouseButton, int, int> onMouseDoubleClick;
};
//---------------------------------------------------------------------------
}
