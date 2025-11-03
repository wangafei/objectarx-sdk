#if !defined(_ACHTMLAPI_H_INCLUDED_)
#define _ACHTMLAPI_H_INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif

class CZdUiPaletteSet;

int  zcedAddHTMLPalette(CZdUiPaletteSet* ps, const ZTCHAR* name, const ZTCHAR* uriOfHtmlPage );
bool zcedShowHTMLModalWindow(HWND owner, const ZTCHAR* uriOfHtmlPage, bool persistSizeAndPosition = true);
HWND zcedShowHTMLModelessWindow(HWND owner, const ZTCHAR* uriOfHtmlPage, bool persistSizeAndPosition = true);

struct HtmlWindowOptions {
    enum HtmlWindowFlags {
        eAllowResize             = 0x0001,
        eAllowMinimize           = 0x0002,
        eAllowMaximize           = 0x0004,
        eInitPosition            = 0x0008,
        eInitSize                = 0x0010,
        eMaxSize                 = 0x0020,
        eMinSize                 = 0x0040,
        ePersistSizeAndPosition  = 0x0080,
        eCenterWindow            = 0x0100,
        eDialogFrame             = 0x0200,
        eAutoHiDpiScale          = 0x0400,
        eTransparentHost         = 0x0800

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
    UINT dialogTemplateId;
    HWND ownerWindow;

    HtmlWindowOptions()
    {
        dialogTemplateId = 0;
        ownerWindow = NULL;
    }

};

bool zcedShowHTMLModalWindow(HWND owner, const ZTCHAR* uriOfHtmlPage, HtmlWindowOptions opts);

class ZcApDocWindow;
ZcApDocWindow* zcedAddHTMLDocWindow(const ZTCHAR* title, const ZTCHAR* uriOfHtmlPage);

#endif
