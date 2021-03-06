//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include "../Includes.h"
//---------------------------------------------------------------------------
namespace bcl {
//---------------------------------------------------------------------------
bool SelectDirectory(HWND Owner, const TCHAR *Description, std::tstring &Result);
bool MoveToTrash(const TCHAR *FileName);
bool RemoteOpenFile(const TCHAR *FileName);
//---------------------------------------------------------------------------
}
