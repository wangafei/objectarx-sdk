/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#if !defined(_GDUITHEMEDSTATIC_H__)
#define _GDUITHEMEDSTATIC_H__

#if _MSC_VER > 1000
#pragma once
#endif 

class GCAD_PORT CGdUiThemedStatic : public CStatic
{
  DECLARE_DYNAMIC(CGdUiThemedStatic)
public:
  CGdUiThemedStatic();
  CGdUiThemedStatic(const CString & themeName);
  ~CGdUiThemedStatic();

  CString GetThemeName() const;
  bool SetThemeName(const CString & themeName);

  HBITMAP SetBitmap(HBITMAP hBitmap);
  HICON SetIcon(HICON hIcon);
  void PreSubclassWindow() override;

protected:
  void Initialize();

  afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
  DECLARE_MESSAGE_MAP()

private:
  CString mThemeName;
  CBrush mBackgroundBrush;
};


#endif 
