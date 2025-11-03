
#if !defined(_ADUITOOLBARCTRL_H__)
#define _ADUITOOLBARCTRL_H__

#if _MSC_VER > 1000
#pragma once
#endif

#define ZDUI_TBSTYLE_AUTOSTRETCH 0x00080000

class ZDUI_PORT CZdUiToolBarCtrl : public CToolBarCtrl
{
    DECLARE_DYNAMIC(CZdUiToolBarCtrl)
public:

    CZdUiToolBarCtrl();

    virtual ~CZdUiToolBarCtrl();

    int AddBitmap(int nNumButtons, UINT nBitmapID);

    int AddBitmap(int nNumButtons, CBitmap* pBitmap);

protected:

    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);

    DECLARE_MESSAGE_MAP()

private:
    CBitmap *m_pBmp;
    void UpdateBitmap(const CBitmap& bmp);
};

#endif

