#ifndef _GD_MENUBAR_INC_
#define _GD_MENUBAR_INC_

class GdImpMenuBar;

typedef bool (CALLBACK *LPFNADMENUCALLBACK)(unsigned int nItemId);

class GCAD_DLL_DECL GdMenuBar
{
  friend class GdApplicationFrame;

public:
  virtual ~GdMenuBar();

  bool GetMenuItemHelpString(UINT nItemID, const wchar_t **wszHelpString);
  bool RemoveMenuItem(HMENU hMenu, UINT nMenuItemId);
  bool AddMenuItem(HMENU hMenu, UINT nPos, const MENUITEMINFO& menuItem, LPFNADMENUCALLBACK pfnCallback, const wchar_t *wszHelpString);
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

#endif//_GD_MENUBAR_INC_