//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../GUI/Form.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class CSaveFileDialog
{
private:
   OPENFILENAME file;
   TCHAR nameBuffer[MAX_PATH];

public:
   CSaveFileDialog();
   ~CSaveFileDialog();

   void SetOwner(CForm *Owner);
   void SetFilter(const TCHAR *Filter);
   void SetDefaultExtension(const TCHAR *DefExt);

   bool Execute();

   const TCHAR *GetFileName() const;
   const TCHAR *GetFileExtension() const;
};
//---------------------------------------------------------------------------
}
