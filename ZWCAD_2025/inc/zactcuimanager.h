

#ifndef __ZCTCUIMANAGER_H__
#define __ZCTCUIMANAGER_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zgepnt3d.h"
#include "zAcTcUiToolPaletteSet.h"
#include "zAcTcUi.h"

class ZcTcUiSystemInternals;

#ifndef _ZSOFT_MAC_   
class ZCTCUI_PORT CZcTcUiManager  
{
public:
    CZcTcUiManager();
	virtual ~CZcTcUiManager();
    CZcTcUiToolPaletteSet* GetToolPaletteWindow(void);
    BOOL                Load                (IUnknown* pUnknown);
    BOOL                Save                (IUnknown* pUnknown);
    BOOL                SetApplicationWindow(HWND hWndApp);
    HWND                GetApplicationWindow(void);
    COleDropTarget*     GetDropTarget       (void);
    CZcTcUiToolPalette* CreatePalette       (LPCTSTR pszPalName = NULL,
                                             DWORD dwFlags = 0);
    BOOL                Export              (LPCTSTR pszFile,
                                            const ZcTcUiToolPaletteArray* palettes = NULL);
    BOOL                Import              (LPCTSTR pszFile);
    BOOL                FindPalette         (const ZcTcCatalogItem* pItem,
                                             CZcTcUiToolPalette** ppToolPalette) const;
    BOOL                FindPalette         (const GUID& itemId,
                                             CZcTcUiToolPalette** ppToolPalette) const;
    BOOL                ShowToolPaletteWindow(BOOL bShow = TRUE);
    BOOL                IsToolPaletteWindowVisible(void) const;
    int                 GetToolFilterCount  (void) const;
    int                 AddToolFilter       (LPCTSTR pszProductName,
                                             int nMajorVersion,
                                             int nMinorVersion,
                                             DWORD dwLocaleId);
    BOOL                GetToolFilter       (int iIndex, 
                                             LPTSTR pszProductName,
                                             int* pMajorVersion,
                                             int* pMinorVersion,
                                             DWORD* pLocaleId) const;
    BOOL                DeleteToolFilter    (int iIndex);
    CZcTcUiScheme*      GetScheme           (LPCTSTR pszName) const;
    CZcTcUiScheme*      GetScheme           (int nIndex);
    int                 GetSchemeCount      (void);
    int                 AddScheme           (CZcTcUiScheme* pUiScheme);
    BOOL                RemoveScheme        (CZcTcUiScheme* pUiScheme);
    void                NotifyDropPoint     (const ZcGePoint3d& point);	
   
    BOOL                ExecuteTool         (ZDUI_DRAGDATA* pDragData);	
   
    void                CreatePalette       (ZDUI_DRAGDATA* pDragData);	

protected:
    void            *   mpImpObj;

private:
    friend class ZcTcUiSystemInternals;
};
#endif

#endif 
