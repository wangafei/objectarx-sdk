/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCTCUITOOLPALETTESET_H__
#define __GCTCUITOOLPALETTESET_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "GcTcUI.h"
#include "gduiPaletteSet.h"
#include "GcTcUiToolPalette.h"
#include "GcTcUiToolPaletteGroup.h"


class CGcTcUiImpToolPaletteSet;
class CGcTcUiScheme;
#ifndef _GSOFT_MAC_
class GCAD_PORT CGcTcUiToolPaletteSet : public CGdUiPaletteSet
{
    friend CGcTcUiImpToolPaletteSet;

    DECLARE_DYNCREATE(CGcTcUiToolPaletteSet);

public:
    ~CGcTcUiToolPaletteSet();

    BOOL                Load                (IUnknown* pUnk) override;
    BOOL                Save                (IUnknown* pUnk) override;
    virtual BOOL        Import              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        Export              (IUnknown* pUnk, LPCTSTR pszRefPath);
    virtual BOOL        HitTest             (CPoint pt, UINT& nFlag, 
                                             DWORD& dwData);
    int                 AddPalette          (CGdUiPalette* pPalette);
    int                 InsertPalette       (int iIndex, CGdUiPalette* pPalette);
    BOOL                RemovePalette       (CGdUiPalette* pPalette);
    BOOL                RemovePalette       (int iIndex);
#ifndef NEW_PALETTE
    void        TitleBarLocationUpdated(GdUiTitleBarLocation newLoc) override;
#endif  
    CGcTcUiToolPaletteGroup* GetToolPaletteGroup(BOOL bCreate = FALSE);
    CGcTcUiToolPaletteGroup* GetAllPalettesGroup(void);
    CGcTcUiToolPaletteGroup* GetActivePaletteGroup(void);
    BOOL                GetActivePaletteGroup(LPTSTR pszGroup, 
                                              int cbSize) const;
    BOOL                SetActivePaletteGroup(CGcTcUiToolPaletteGroup* pGroup);
    BOOL                SetActivePaletteGroup(LPCTSTR pszGroup);
    CGcTcUiScheme*      GetScheme           (void) const;
    BOOL                Show                (void);
    BOOL                Show                (BOOL bShow);
    BOOL                SetActivePalette    (CGdUiPalette* pPalette);
    BOOL                SetActivePalette    (int nPaletteIndex);
    BOOL                SetActivePalette    (LPCTSTR pszPalName,
                                             BOOL bSearchOnlyCurrentGroup) const;
    CGcTcUiToolPalette* FindPalette         (LPCTSTR pszPalName,
                                             CGcTcUiToolPaletteGroup** ppGroup,
                                             BOOL bSearchOnlyCurrentGroup) const;

protected:
    CGcTcUiToolPaletteSet();

protected:
    BOOL AddContextMenuItems (
        CMenu *pMenu, 
        int nHitFlag,
        int nRightClkTab = 0) override;

    void        ThemeModified       (GdUiThemeElement element) override;
    void        OnTabDrag           (CPtrArray & arrayPalettes) override;
    virtual BOOL        OnBeginDrag         (COleDataSource* pDataSource,
                                             CPtrArray & arrayPalettes);
    virtual void        OnEndDrag           (DROPEFFECT dropEffect);
    virtual BOOL        OnBeginMove         (COleDataSource* pDataSource,
                                             CPtrArray & arrayPalettes);
    virtual void        OnEndMove           (DROPEFFECT dropEffect);
    virtual BOOL        OnRenderData        (LPFORMATETC lpFormatEtc,
                                             LPSTGMEDIUM lpStgMedium);
    virtual void        OnTearOff           (CGdUiPaletteSet* pSet);
    virtual void        DestroyStackedPaletteSet(void);

protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
    afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
    afx_msg void OnRemovePaletteSet();
    afx_msg void OnRemoveActivePalette();
    afx_msg void OnRemovePalette();
    afx_msg void OnViewOptions();
    afx_msg void OnSelectPaletteGroup( UINT nID );
    afx_msg void OnShowCustomizeDialog();
    afx_msg void OnShowCustomizeDialogCUI();
    afx_msg void OnNewPalette();
    afx_msg void OnPaste();
    afx_msg void OnPaletteProperties();
    afx_msg void OnRefreshPaletteSet();
    afx_msg void OnRefreshActivePalette();
    afx_msg void OnClose();
    afx_msg void OnMoveUp();
    afx_msg void OnMoveDown();
    afx_msg void OnInvokeCommand(UINT nID);
    afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
    afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
    afx_msg LRESULT OnRenderData(WPARAM wParam, LPARAM lParam);
    DECLARE_MESSAGE_MAP()

protected:
    void            *   mpImpObj;           

private:
    friend class GcTcUiSystemInternals;

};

#endif 
#endif 