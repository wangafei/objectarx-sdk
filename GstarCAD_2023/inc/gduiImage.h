/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiImage_h
#define _gduiImage_h

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
#include "gduiTheme.h"

#define ICON_16     16
#define ICON_32     32

class GCAD_PORT CGdUiImage
{
public:
  CGdUiImage(bool bIsThemed = false);
  CGdUiImage(LPCWSTR pFile, bool bIsThemed = false);
  CGdUiImage(HBITMAP hbmp, Gdiplus::PixelFormat format);
  virtual ~CGdUiImage();

  virtual void Empty();
  virtual bool Reload();
  bool Load(LPCWSTR pFile);

  bool IsThemed() { return m_bIsThemed; }
  void SetIsThemed(bool bIsThemed) { m_bIsThemed = bIsThemed; }
  void SetTheme(const CGdUiTheme * theme);

  unsigned int GetWidth() const;
  unsigned int GetHeight() const;

  Gdiplus::Bitmap* GetBitmap() const { return m_pBitmap; }
  void SetBitmap(Gdiplus::Bitmap* pBitmap);

  bool DrawImage(CDC* pDC, int x, int y, bool isDisabled = false);
  bool DrawImage(CDC* pDC, int x, int y, int width, int height, bool isDisabled = false);
  bool DrawImage(CDC* pDC, int x, int y, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled = false);
  bool DrawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled = false);

  static CString GetThemedFileName(LPCTSTR pName, const CGdUiTheme * pTheme = NULL);

protected:
  Gdiplus::Bitmap* m_pBitmap;
  bool m_bIsThemed;
  const CGdUiTheme* m_pTheme;
  CString m_name;

  bool CGdUiImage::IsThemeDark() const;

  static bool IsCurrentPaletteThemeDark();

private:
  void commonCtr(bool bIsThemed);
  void clear();
  void drawImage(CDC* pDC, int x, int y, int width, int height, int srcx, int srcy, int srcwidth, int srcheight, bool isDisabled);

  static unsigned int         g_instanceCount;
  static Gdiplus::GdiplusStartupInput  g_gdiplusStartupInput;
  static ULONG_PTR            g_gdiplusToken;

  CGdUiImage(const CGdUiImage & image);
  CGdUiImage& operator=(const CGdUiImage & image);
};

class GCAD_PORT CGdUiImageResource : public CGdUiImage
{
protected:
  HGLOBAL m_hBuffer;
  UINT m_lightId;
  UINT m_darkId;
  LPCTSTR m_pType;
  CString m_strType;
  HMODULE m_hInst;

public:
  CGdUiImageResource();
  CGdUiImageResource(bool bIsThemed);
  CGdUiImageResource(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL, bool bIsThemed = false);
  CGdUiImageResource(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);
  CGdUiImageResource(UINT id, UINT type, HMODULE hInst = NULL);
  CGdUiImageResource(UINT lightId, UINT darkId, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);
  CGdUiImageResource(UINT lightId, UINT darkId, UINT type, HMODULE hInst = NULL);
  ~CGdUiImageResource();

  void Empty() override;
  bool Reload() override;
  bool Load(LPCTSTR pName, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);
  bool Load(UINT id, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);
  bool Load(UINT id, UINT type, HMODULE hInst = NULL);
  bool Load(UINT lightId, UINT darkId, LPCTSTR pType = RT_RCDATA, HMODULE hInst = NULL);
  bool Load(UINT lightId, UINT darkId, UINT type, HMODULE hInst = NULL);

  static CString GetThemedResourceName(LPCTSTR pName, const CGdUiTheme * pTheme = NULL);

private:
  bool loadIcon(LPCTSTR pName, HMODULE hInst = NULL);
  bool loadResource(LPCTSTR pName, LPCTSTR pType, HMODULE hInst);
  bool isPredefinedResourceType(LPCTSTR pType);
  bool isValidPredefinedResourceType(LPCTSTR pType);
  void saveType(LPCTSTR pType);

private:
  void clear();

  CGdUiImageResource(const CGdUiImageResource & image);
  CGdUiImageResource& operator=(const CGdUiImageResource & image);
};

#endif  