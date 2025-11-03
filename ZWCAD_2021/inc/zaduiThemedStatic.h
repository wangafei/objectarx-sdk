

#if !defined(_ZADUITHEMEDSTATIC_H__)
#define _ZADUITHEMEDSTATIC_H__

#if _MSC_VER > 1000
#pragma once
#endif 


class ZDUI_PORT CZdUiThemedStatic : public CStatic
{
    DECLARE_DYNAMIC(CZdUiThemedStatic)
public:
    CZdUiThemedStatic();
    CZdUiThemedStatic(const CString & themeName);
    virtual ~CZdUiThemedStatic();
    CString GetThemeName() const;
    bool SetThemeName(const CString & themeName);
    HBITMAP SetBitmap(HBITMAP hBitmap);
    HICON SetIcon(HICON hIcon);
    virtual void PreSubclassWindow();

protected:
    
    void Initialize();
    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
    
    DECLARE_MESSAGE_MAP()

private:
    CString mThemeName;             
    CBrush mBackgroundBrush;
};

#endif 

