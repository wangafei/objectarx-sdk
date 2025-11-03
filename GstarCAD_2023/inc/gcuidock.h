/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiDock_h
#define _gcuiDock_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

class GCAD_PORT CGcUiDockFrame : public CGdUiDockFrame {
  DECLARE_DYNCREATE(CGcUiDockFrame);
public:
  CGcUiDockFrame();
  ~CGcUiDockFrame();

protected:
  afx_msg LRESULT OnGCADKeepFocus(WPARAM wParam, LPARAM lParam);
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiDockControlBar : public CGdUiDockControlBar {
  DECLARE_DYNCREATE(CGcUiDockControlBar);
public:
  CGcUiDockControlBar() {}

protected:
  bool CanFrameworkTakeFocus() override;
};

#ifndef NEW_PALETTE

class GCAD_PORT CGcUiPaletteSetDockFrame : public CGdUiPaletteSetDockFrame {
  DECLARE_DYNCREATE(CGcUiPaletteSetDockFrame);
public:
  CGcUiPaletteSetDockFrame();
  ~CGcUiPaletteSetDockFrame();

protected:
  afx_msg LRESULT OnGCADKeepFocus(WPARAM wParam, LPARAM lParam);
  afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);

  DECLARE_MESSAGE_MAP()
};
#endif 

#pragma pack (pop)
#endif