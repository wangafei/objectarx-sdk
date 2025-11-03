/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcTcUiToolPalette.h"

class CGcTcUiImpToolPaletteGroup;
class CGcTcUiImpToolPaletteSet;

class GCAD_PORT CGcTcUiToolPaletteGroup : public CObject
{
  DECLARE_DYNAMIC(CGcTcUiToolPaletteGroup);

public:
  CGcTcUiToolPaletteGroup();
  ~CGcTcUiToolPaletteGroup();

  BOOL            Reset(void);
  CString         GetName(void) const;
  BOOL            SetName(LPCTSTR pszName);
  CString         GetDescription(void) const;
  BOOL            SetDescription(LPCTSTR pszDesc);
  BOOL            IsItemPalette(int iIndex) const;
  int             AddItem(CGcTcUiToolPalette* pPalette);
  int             AddItem(CGcTcUiToolPaletteGroup* pGroup);
  int             InsertItem(int iIndex,
    CGcTcUiToolPalette* pPalette);
  int             InsertItem(int iIndex,
    CGcTcUiToolPaletteGroup* pGroup);
  int             GetItemCount(void) const;
  BOOL            GetItem(int iIndex,
    CGcTcUiToolPalette*& pPalette) const;
  BOOL            GetItem(int iIndex,
    CGcTcUiToolPaletteGroup*& pGroup) const;
  BOOL            DeleteItem(CGcTcUiToolPalette* pPalette,
    BOOL bRecursive = FALSE);
  BOOL            DeleteItem(CGcTcUiToolPaletteGroup* pGroup);
  BOOL            RemoveItem(CGcTcUiToolPalette* pPalette,
    BOOL bRecursive = FALSE);
  BOOL            RemoveItem(CGcTcUiToolPaletteGroup* pGroup);
  BOOL            DeleteAllPalettes(void);
  BOOL            DeleteAllItems(void);
  int             GetActivePalette(void) const;
  BOOL            SetActivePalette(int nIndex);
  BOOL            GetCustomData(IUnknown** ppUnknown);
  virtual BOOL    Load(IUnknown* pUnk);
  virtual BOOL    Save(IUnknown* pUnk);
  virtual BOOL    Clone(CGcTcUiToolPaletteGroup*& pClone);
  CGcTcUiToolPaletteGroup* FindGroup(LPCTSTR pszGroup,
    BOOL bRecursive = TRUE);
  CGcTcUiToolPalette* FindPalette(LPCTSTR pszPalName,
    CGcTcUiToolPaletteGroup** ppGroup,
    BOOL bRecursive = TRUE) const;

protected:
  void            *   mpImpObj;

private:
  friend class GcTcUiSystemInternals;
};
