/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCTCUISCHEME_H__
#define __GCTCUISCHEME_H__

#if _MSC_VER > 1000
#pragma once
#endif 

#include "GcTcUiToolPaletteSet.h"
#include "GcTcUI.h"

class GcTcUiSystemInternals;

class GCAD_PORT CGcTcUiScheme : public CObject
{
public:
  enum RefreshScope {
    kAllPalettes = (0x1 << 0),
    kRefreshEnabledPalettes = (0x1 << 1),
    kAutoRefreshEnabledPalettes = (0x1 << 2),
  };

  enum ShowOption {
    kShow = (0x1 << 0),
    kHide = (0x1 << 1),
    kSaveState = (0x1 << 2),
    kRestoreState = (0x1 << 3),
  };

  CGcTcUiScheme(GcTcScheme* pScheme);
  ~CGcTcUiScheme();

  BOOL                Load(IUnknown* pUnknown);
  BOOL                Save(IUnknown* pUnknown);
  BOOL                Unload(void);
  CGcTcUiToolPaletteSet* CreatePaletteSet(LPCTSTR pszPalSetName);
  CGcTcUiToolPaletteSet* GetPaletteSet(void);
  BOOL                FindPalette(const GcTcCatalogItem* pItem,
    CGcTcUiToolPalette** ppToolPalette) const;
  BOOL                FindPalette(const GcTcCatalogItem* pItem,
    CGcTcUiToolPalette** ppToolPalette,
    CGcTcUiToolPaletteSet** ppToolPaletteSet) const;
  BOOL                FindPalette(const GUID& itemId,
    CGcTcUiToolPalette** ppToolPalette) const;
  BOOL                FindPalette(const GUID& itemId,
    CGcTcUiToolPalette** ppToolPalette,
    CGcTcUiToolPaletteSet** ppToolPaletteSet) const;
  BOOL                Export(LPCTSTR pszFile);
  BOOL                Export(LPCTSTR pszFile,
    const GcTcUiToolPaletteArray* palettes);
  BOOL                Import(LPCTSTR pszFile);
  BOOL                Refresh(RefreshScope nScope);
  BOOL                Refresh(RefreshScope nScope,
    DWORD dwRefreshFlag);
  BOOL                Show(ShowOption nOption,
    LONG_PTR lKey);

protected:
  void            *   mpImpObj;

private:
  friend class GcTcUiSystemInternals;
};

#endif 