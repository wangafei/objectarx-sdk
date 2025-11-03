/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GdExportDef.h"

class GdImpMenuBar;

typedef bool (CALLBACK *LPFNADMENUCALLBACK)(unsigned int nItemId);

class GCAD_PORT GdMenuBar
{
  friend class GdApplicationFrame;

public:
  virtual ~GdMenuBar();

  bool GetMenuItemHelpString(UINT nItemID, const wchar_t **wszHelpString);
  bool RemoveMenuItem(HMENU hMenu, UINT nMenuItemId);
  bool AddMenuItem(HMENU hMenu, UINT nPos, const MENUITEMINFO& menuItem,
    LPFNADMENUCALLBACK pfnCallback, const wchar_t *wszHelpString);
  bool SetMenuHandle(HMENU hMenu);
  void UpdateMenu();
  HMENU GetMenuHandle();
  bool TrackingPopup();
  void SetChildWindowMenuPopup(bool bShow);
  bool GetChildWindowMenuPopup(void);

private:
  GdMenuBar(GdImpMenuBar* pImpMenuBar);
  GdMenuBar();

  GdImpMenuBar *mpImpMenuBar;
};