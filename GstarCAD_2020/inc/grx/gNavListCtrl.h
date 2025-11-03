#ifndef _GNavListCtrl_h
#define _GNavListCtrl_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class  CNavListCtrl;

class CNavDropSource : public COleDropSource
{
public:
    CNavDropSource();       

    CNavListCtrl* m_pListCtrl;

    SCODE GiveFeedback(DROPEFFECT dropEffect);
};


class GNAV_PORT CNavListCtrl : public CGdUiListCtrl {
public:
    CNavListCtrl ();

public:
    //{{AFX_VIRTUAL(CNavListCtrl)
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CNavListCtrl)
    afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
    //}}AFX_MSG
    afx_msg LONG OnHandleDrag(UINT pDataSource, LONG nSelectedItem);        
    DECLARE_MESSAGE_MAP()

    CImageList* m_pDragImage;
    CNavDropSource m_dropSource;

};

#endif