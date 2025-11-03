
#pragma once

#include "zadui_port.h"

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

    virtual void PreSubclassWindow() override;

protected:

    void Initialize();

    afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

    DECLARE_MESSAGE_MAP()

private:
    CString mThemeName;
    CBrush mBackgroundBrush;
};

