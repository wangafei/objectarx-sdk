#pragma once
#include <afxpriv.h>                    
#include "gchar.h"
#include "gduiDock.h"
#include "gduiTheme.h"
#include "gdui.h"

class CGdUiThemeModifiedReactor;
class CGdUiDockControlBar;
class CGdUiTheme;
class CGdUiDockControlBar;

class CGdUiDockControlBarThemeModReactor : public CGdUiThemeModifiedReactor
{
public:
  CGdUiDockControlBarThemeModReactor(CGdUiDockControlBar* pDockControlBar) {};
  virtual void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element);
  void SetDockControlBar(CGdUiDockControlBar* pDockControlBar);

private:
  CGdUiDockControlBar * m_pDockControlBar;
};

class GDUI_PORT CGdUiPaletteSetDockFrame : public CMiniDockFrameWnd
{
  friend class CGdUiImpPaletteSet;
  friend class CGdUiDockDragContext;
  friend class CGdUiDockBarMutator;
  friend class CGdUiAnchorBar;

  DECLARE_DYNCREATE(CGdUiPaletteSetDockFrame)

public:
  CGdUiPaletteSetDockFrame();
  virtual ~CGdUiPaletteSetDockFrame();

  virtual BOOL Create(CWnd* pParent, DWORD dwBarStyle);
  static bool HidePalettes();
  static bool ShowPalettes();

public:
  enum ContainedBarType { Unknown, Standard, AdskBar };

  enum ContainedBarType GetContainedBarType();

  void SetAutoRollup(BOOL bSet);

  virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType = adjustBorder);

  typedef enum
  {
    kLeft = 0,
    kRight
  } GdUiTitleBarLocation;

  CGdUiPaletteSetDockFrame::GdUiTitleBarLocation TitleBarLocation();
  void SetTitleBarLocation(CGdUiPaletteSetDockFrame::GdUiTitleBarLocation);

private:
  enum GdUiSkBtnItems
  {
    kBtnUnknown = -1,
    kBtnPushPin = 0,
    kBtnOptionMenu = 1,
    kBtnClose = 2,
    kBtnIcon = 3,
  };

  enum GdUiSkIds
  {
    kRollupTimerId = 0x3011,
    kRolloutTimerId = 0x3012,
    kCursorCheckTimerId = 0x3013
  };

  enum AdUiSkUiFlags
  {
    kImgListUnpinnedLeft = 0,
    kImgListUnpinnedRight = 1,
    kImgListPinnedLeft = 2,
    kImgListPinnedRight = 3,
    kImgListOptionMenuLeft = 4,
    kImgListOptionMenuRight = 5,
    kImgListClose = 6,
    kImgList_Count = 7,
  };

};

void GDUI_PORT GdUiSaveDockingToolPositions();
void GDUI_PORT GdUiShowDockControlBars(bool bShow);
bool GDUI_PORT GdUiRegisterDockingTool(LPCTSTR lpszToolName, LPCTSTR lpszCommand, UINT nToolbarID);

void GDUI_PORT GdUiEnableDocking(CFrameWnd *pFrame, DWORD dwDockStyle, GDUI_LOADFN* pLoadFcn, GDUI_SAVEFN* pSaveFcn);

bool GDUI_PORT CanStealFocusFromDockedWindow();
void GDUI_PORT GetSystemVirtualScreen(RECT &rect);
void GDUI_PORT GdUiEnableDockControlBars(BOOL bEnable, CStringArray* pToolIds = NULL);



