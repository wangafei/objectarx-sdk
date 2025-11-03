
#pragma once

#include "zadui_port.h"

class ZDUI_PORT CZdUiCheckListBox : public CCheckListBox
{
    DECLARE_DYNAMIC(CZdUiCheckListBox)
public:
    CZdUiCheckListBox();
    virtual ~CZdUiCheckListBox();

public:

    void EnableItemToolTip();

    enum HorizontalStyle
    {

        kHorizontalClip,

        kHorizontalEndEllipsis,

        kHorizontalPathEllipsis,

        kHorizontalWordEllipsis,

        kHorizontalScroll,
    };

    HorizontalStyle GetHorizontalStyle() const
    {
        return _horizontalStyle;
    }

    void SetHorizontalStyle(HorizontalStyle style);

public:

    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;

    virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

protected:

    virtual int CalcHorizontalExtent(int index, LPCTSTR text);

    virtual void CalcItemParts(int index, const CRect& item, CRect* checkBox, CRect* text);

    virtual int CalcMinimumItemHeight();

    virtual void DrawCheckBox(LPDRAWITEMSTRUCT lpDrawItemStruct);

    virtual void DrawFocus(LPDRAWITEMSTRUCT lpDrawItemStruct);

    virtual bool OnItemToolTip(int index, const CRect& item, const CPoint& mouse, CPoint& tipPosition, CString& tipText);

    int CheckFromPoint(CPoint point, BOOL& checkBox);
    void InvalidateCheck(int index);
    void PreDrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

public:
    virtual void DeleteItem(LPDELETEITEMSTRUCT lpDeleteItemStruct) override;
    virtual void PreSubclassWindow() override;
protected:
    virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;
    virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult) override;
    DECLARE_MESSAGE_MAP()
    afx_msg void OnDestroy();
    afx_msg LRESULT OnLBAddString(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnLBInsertString(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnLBResetContent(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnLBSetItemHeight(WPARAM wParam, LPARAM lParam);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnSetFont(CFont* pFont, BOOL bRedraw);
private:
    BOOL OnLButtonDown(int index, BOOL checkBox);
    bool ToolTip();
private:
    bool _deleteItem;
    HorizontalStyle _horizontalStyle;
    CToolTipCtrl* _toolTipCtrl;
};
