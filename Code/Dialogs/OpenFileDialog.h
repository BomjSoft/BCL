//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
#include "../GUI/Form.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
class COpenFileDialog
{
private:
   OPENFILENAME file;
   std::vector<std::tstring> fileList;

public:
   COpenFileDialog();
   ~COpenFileDialog();

   void SetOwner(CForm *Owner);
   void SetFilter(const TCHAR *Filter);
   void SetMultiselect(bool UseMultiselect);

   bool Execute();

   size_t GetFileCount() const;
   const TCHAR *GetFileName(size_t Number) const;
};
//---------------------------------------------------------------------------
}
