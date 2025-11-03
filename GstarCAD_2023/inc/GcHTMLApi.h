/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#if !defined(_GCHTMLAPI_H_INCLUDED_)
#define _GCHTMLAPI_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class CGdUiPaletteSet;

GCCORE_PORT int  gcedAddHTMLPalette(CGdUiPaletteSet* ps, const GCHAR* name, const GCHAR* uriOfHtmlPage);
GCCORE_PORT bool gcedShowHTMLModalWindow(HWND owner, const GCHAR* uriOfHtmlPage, bool persistSizeAndPosition = true);
GCCORE_PORT HWND gcedShowHTMLModelessWindow(HWND owner, const GCHAR* uriOfHtmlPage, bool persistSizeAndPosition = true);

struct HtmlWindowOptions {
  enum HtmlWindowFlags {
    eAllowResize = 0x0001,
    eAllowMinimize = 0x0002,
    eAllowMaximize = 0x0004,
    eInitPosition = 0x0008,
    eInitSize = 0x0010,
    eMaxSize = 0x0020,
    eMinSize = 0x0040,
    ePersistSizeAndPosition = 0x0080,
  };
  UINT flags;
  UINT x;
  UINT y;
  UINT width;
  UINT height;
  UINT maxWidth;
  UINT maxHeight;
  UINT minWidth;
  UINT minHeight;
};

GCCORE_PORT bool gcedShowHTMLModalWindow(HWND owner, const GCHAR* uriOfHtmlPage, HtmlWindowOptions opts);

class GcApDocWindow;
GCCORE_PORT GcApDocWindow* gcedAddHTMLDocWindow(const GCHAR* title, const GCHAR* uriOfHtmlPage);
extern "C" GCCORE_PORT void gcedLoadJSScript(const GCHAR* pUriOfJSFile);
#endif 