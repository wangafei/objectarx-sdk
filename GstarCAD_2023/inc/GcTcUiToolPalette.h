/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCTCUITOOLPALETTE_H__
#define __GCTCUITOOLPALETTE_H__


#if _MSC_VER > 1000
#pragma once
#endif 

#include "GcTcUI.h"
#include "gduiPalette.h"
#include "GcTcUiPaletteView.h"

class CGcTcUiImpToolPalette;
class GcTcUiSystemInternals;
class CGcTcUiScheme;
#ifndef _GSOFT_MAC_
class GCAD_PORT CGcTcUiToolPalette : public CGdUiPalette
{
  friend CGcTcUiImpToolPalette;
  DECLARE_DYNCREATE(CGcTcUiToolPalette);

public:
  CGcTcUiToolPalette();
  ~CGcTcUiToolPalette();
  CGcTcUiPaletteView* GetView(void);

public:
  BOOL                Create(CGdUiPaletteSet* pParent) override;
  BOOL                Create(DWORD dwStyle,
    LPCTSTR pszName,
    CGdUiPaletteSet* pParent,
    DWORD dwPaletteStyle = 0);
  BOOL                Load(IUnknown* pUnk) override;
  bool                CanFrameworkTakeFocus() override;
  BOOL                Save(IUnknown* pUnk) override;
  virtual BOOL        Import(IUnknown* pUnk, LPCTSTR pszRefPath);
  virtual BOOL        Export(IUnknown* pUnk, LPCTSTR pszRefPath);
  BOOL                OnKillActive(void) override;
  BOOL                GetMinimumSize(CSize& size) override;
  void                OnSetActive(void) override;
  BOOL                NameEditValidation(CEdit* pEdit) override;
  virtual BOOL        Paste(IDataObject* pDataObject,
    int iIndex = -1,
    GcTcCatalogItemArray* pNewTools = NULL);
  virtual BOOL        CanPaste(IDataObject* pDataObject);
  BOOL                SetView(CGcTcUiPaletteView* pView);
  CGcTcUiScheme*      GetScheme(void) const;

protected:
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg LRESULT OnDragEnter(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnDragOver(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnDragLeave(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnDrop(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnDropEx(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnUpdate(WPARAM wParam, LPARAM lParam);
  afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);
  DECLARE_MESSAGE_MAP()

protected:
  void            *   mpImpObj;
private:
  friend class GcTcUiSystemInternals;
};

#endif 
#endif 