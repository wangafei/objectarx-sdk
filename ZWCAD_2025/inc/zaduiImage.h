
#ifndef _zaduiImage_h
#define _zaduiImage_h

#if _MSC_VER >= 1000
#pragma once
#endif

#ifndef _WINDOWS_
#include <afxwin.h>
#include <afxext.h>
#endif

#pragma push_macro("new")
#undef new
#include <minmax.h>
#include <gdiplus.h>
#undef min
#undef max
#pragma pop_macro("new")

#include <WinDef.h>
#include "zaduitheme.h"

#define ICON_16     16
#define ICON_32     32

class ZDUI_PORT CZdUiImage
{
public:

    CZdUiImage(bool bIsThemed = false);

    CZdUiImage(LPCWSTR pFile, bool bIsThemed = false);

    CZdUiImage(HBITMAP hbmp, Gdiplus::PixelFormat format);

    virtual ~CZdUiImage();

    virtual void Empty();

    virtual bool Reload();

    bool Load(LPCWSTR pFile);

    bool IsThemed()                     { return m_bIsThemed; }

    void SetIsThemed(bool bIsThemed)    { m_bIsThemed = bIsThemed; }

    void SetTheme(const CZdUiTheme * theme);

    unsigned int GetWidth() const;

    unsigned int GetHeight() const;

    Gdiplus::Bitmap* GetBitmap() const   { return m_pBitmap; }

    void SetBitmap(Gdiplus::Bitmap* pBitmap);

    bool DrawImage(CDC* pDC, int x, int y, bool isDisabled = false);

    bool DrawImage(CDC* pDC, int x, int y, int width, int height, bool isDisabled = false);

    bool DrawImage(CDC* pDC, int x, int y, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled = false);

    bool DrawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled = false);

    static CString GetThemedFileName(LPCTSTR pName, const CZdUiTheme * pTheme = NULL);

protected:
    Gdiplus::Bitmap* m_pBitmap;
    bool m_bIsThemed;
    const CZdUiTheme* m_pTheme;
    CString m_name;

    bool CZdUiImage::IsThemeDark() const;

    static bool IsCurrentPaletteThemeDark();

private:
    void commonCtr(bool bIsThemed);
    void clear();
    void drawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled);

    static unsigned int         g_instanceCount;
    static Gdiplus::GdiplusStartupInput  g_gdiplusStartupInput;
    static ULONG_PTR            g_gdiplusToken;

    CZdUiImage(const CZdUiImage & image);
    CZdUiImage& operator=(const CZdUiImage & image);
};

class ZDUI_PORT CZdUiImageResource : public CZdUiImage
{
protected:
    HGLOBAL m_hBuffer;
    UINT m_lightId;
    UINT m_darkId;
    LPCTSTR m_pType;
    CString m_strType;
    HMODULE m_hInst;

public:

    CZdUiImageResource();

    CZdUiImageResource(bool bIsThemed);

    CZdUiImageResource(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL, bool bIsThemed = false);

    CZdUiImageResource(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);

    CZdUiImageResource(UINT id, UINT type, HMODULE hInst = NULL);

    CZdUiImageResource(UINT lightId, UINT darkId, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);

    CZdUiImageResource(UINT lightId, UINT darkId, UINT type, HMODULE hInst = NULL);

    virtual ~CZdUiImageResource();

    virtual void Empty() override;

    virtual bool Reload() override;

    bool Load(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);

    bool Load(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);

    bool Load(UINT id, UINT type, HMODULE hInst = NULL);

    bool Load(UINT lightId, UINT darkId, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);

    bool Load(UINT lightId, UINT darkId, UINT type, HMODULE hInst = NULL);

    static CString GetThemedResourceName(LPCTSTR pName, const CZdUiTheme * pTheme = NULL);

private:
    bool loadIcon(LPCTSTR pName, HMODULE hInst = NULL);
    bool loadResource(LPCTSTR pName, LPCTSTR pType, HMODULE hInst);
    bool isPredefinedResourceType(LPCTSTR pType);
    bool isValidPredefinedResourceType(LPCTSTR pType);
    void saveType(LPCTSTR pType);

private:

    void clear();

    CZdUiImageResource(const CZdUiImageResource & image);
    CZdUiImageResource& operator=(const CZdUiImageResource & image);
};

#endif
