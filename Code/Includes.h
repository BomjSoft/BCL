//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
//---------------------------------------------------------------------------
#ifdef DEBUG
#define printlog(Args...) printf(Args)
#else
#define printlog(Args...)
#endif
//---------------------------------------------------------------------------
#include <stdexcept>
#include <vector>
#include <string>
#include <tchar.h>
#include <windows.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <winuser.h>
#include <windowsx.h>
#include <commctrl.h>
//---------------------------------------------------------------------------
#ifdef UNICODE
#define tstring      wstring
#define to_tstring   to_wstring
#else
#define tstring      string
#define to_tstring   to_string
#endif
//---------------------------------------------------------------------------
#define MIN(A,B)  (((A) < (B))?(A):(B))
#define MAX(A,B)  (((A) > (B))?(A):(B))
//---------------------------------------------------------------------------
#include "Delegate.h"
//---------------------------------------------------------------------------
enum EMouseButton {mbLeft, mbRight, mbMiddle};
//---------------------------------------------------------------------------
