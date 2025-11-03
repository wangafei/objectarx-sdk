/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcTcUiCatalogView.h"

#ifndef _GSOFT_MAC_
class GCAD_PORT CGcTcUiPaletteView : public CGcTcUiCatalogView
{
public:
  CGcTcUiPaletteView();
  ~CGcTcUiPaletteView();

protected:
  DROPEFFECT  DragEnter(GDUI_DRAGDATA* pDragData) override;
  DROPEFFECT  DragOver(GDUI_DRAGDATA* pDragData) override;
  void        DragLeave(GDUI_DRAGDATA* pDragData) override;
  DROPEFFECT  Drop(GDUI_DRAGDATA* pDragData) override;
  DROPEFFECT  DropEx(GDUI_DRAGDATA* pDragData) override;

protected:
  CGcTcUiPaletteView(GcTcUiSystemInternals*);

protected:
  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnInvokeCommand(UINT nID);
  afx_msg void OnPaletteRemove();
  afx_msg void OnCatalogItemSpecifyImage();
  afx_msg void OnCatalogItemRemoveImage();
  afx_msg void OnCatalogItemUpdateImage();
  DECLARE_MESSAGE_MAP()
};
#endif 
