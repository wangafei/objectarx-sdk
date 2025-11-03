/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCTCUIMANAGER_H__
#define __GCTCUIMANAGER_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "gepnt3d.h"
#include "GcTcUiToolPaletteSet.h"
#include "GcTcUI.h"

class GcTcUiSystemInternals;
#ifndef _GSOFT_MAC_
class GCAD_PORT CGcTcUiManager
{
public:
  CGcTcUiManager();
  virtual ~CGcTcUiManager();
  CGcTcUiToolPaletteSet* GetToolPaletteWindow(void);
  BOOL                Load(IUnknown* pUnknown);
  BOOL                Save(IUnknown* pUnknown);
  BOOL                SetApplicationWindow(HWND hWndApp);
  HWND                GetApplicationWindow(void);
  COleDropTarget*     GetDropTarget(void);
  CGcTcUiToolPalette* CreatePalette(LPCTSTR pszPalName = NULL,
    DWORD dwFlags = 0);
  BOOL                Export(LPCTSTR pszFile,
    const GcTcUiToolPaletteArray* palettes = NULL);
  BOOL                Import(LPCTSTR pszFile);
  BOOL                FindPalette(const GcTcCatalogItem* pItem,
    CGcTcUiToolPalette** ppToolPalette) const;
  BOOL                FindPalette(const GUID& itemId,
    CGcTcUiToolPalette** ppToolPalette) const;
  BOOL                ShowToolPaletteWindow(BOOL bShow = TRUE);
  BOOL                IsToolPaletteWindowVisible(void) const;
  int                 GetToolFilterCount(void) const;
  int                 AddToolFilter(LPCTSTR pszProductName,
    int nMajorVersion,
    int nMinorVersion,
    DWORD dwLocaleId);
  BOOL                GetToolFilter(int iIndex,
    LPTSTR pszProductName,
    int* pMajorVersion,
    int* pMinorVersion,
    DWORD* pLocaleId) const;
  BOOL                DeleteToolFilter(int iIndex);
  CGcTcUiScheme*      GetScheme(LPCTSTR pszName) const;
  CGcTcUiScheme*      GetScheme(int nIndex);
  int                 GetSchemeCount(void);
  int                 AddScheme(CGcTcUiScheme* pUiScheme);
  BOOL                RemoveScheme(CGcTcUiScheme* pUiScheme);
  void                NotifyDropPoint(const GcGePoint3d& point);
  BOOL                ExecuteTool(GDUI_DRAGDATA* pDragData);
  void                CreatePalette(GDUI_DRAGDATA* pDragData);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcUiSystemInternals;
};

#endif 
#endif 