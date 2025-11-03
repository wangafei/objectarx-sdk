

#pragma once
#include "ZAdExportDef.h"

class ZdImpMenuBar;

typedef bool (CALLBACK *LPFNADMENUCALLBACK)(unsigned int nItemId);

class ZDAF_PORT ZdMenuBar
{
    friend class ZdApplicationFrame;

public:
    virtual ~ZdMenuBar();

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
    ZdMenuBar(ZdImpMenuBar* pImpMenuBar);
    ZdMenuBar();

    ZdImpMenuBar *mpImpMenuBar;
};