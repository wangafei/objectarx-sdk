/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcTc.h"
#include "GcTcUI.h"

class CGcTcUiCatalogView;

#define GCTCUI_CVISTYLE_PUSHBUTTON      0x0
#define GCTCUI_CVISTYLE_SHOWTEXT        (0x1 << 1)
#define GCTCUI_CVISTYLE_RIGHTTEXT       (0x1 << 2)
#define GCTCUI_CVISTYLE_FLYOUT          (0x1 << 3)
#define GCTCUI_CVISTYLE_FULLROW         (0x1 << 4)
#define GCTCUI_CVISTYLE_HIDEIMAGE       (0x1 << 5)
#define GCTCUI_CVISTYLE_TEXT            (0x1 << 6)
#define GCTCUI_CVISTYLE_SEPARATOR       (0x1 << 7)

#define GCTCUI_CVISTATE_HIGHLIGHTED     (0x1 << 0)
#define GCTCUI_CVISTATE_SELECTED        (0x1 << 1)
#define GCTCUI_CVISTATE_HALO            (0x1 << 2)
#define GCTCUI_CVISTATE_FOCUSED         (0x1 << 3)

#define GCTCUI_CVIR_BOUNDS              (0x1 << 0)
#define GCTCUI_CVIR_IMAGE               (0x1 << 1)
#define GCTCUI_CVIR_LABEL               (0x1 << 2)
#define GCTCUI_CVIR_USEFULLLABEL        (0x1 << 3)
#define GCTCUI_CVIR_TRIGGER             (0x1 << 4)
#define GCTCUI_CVIR_WORLDRECT           (0x1 << 5)

class GCAD_PORT CGcTcUiCatalogViewItem : public CObject
{
  friend class CGcTcUiImpCatalogView;

public:
  ~CGcTcUiCatalogViewItem();

  BOOL                Render(BOOL bEraseBackground = FALSE);
  BOOL                Render(CDC* pDC,
    int x,
    int y);
  BOOL                GetRect(LPRECT lpRect,
    int nCode) const;
  GcTcCatalogItem *   GetCatalogItem(void) const;
  BOOL                SetCatalogItem(GcTcCatalogItem* pCatalogItem);
  DWORD               GetStyle(void) const;
  DWORD               GetState(void) const;
  BOOL                SetState(DWORD dwState);
  BOOL                GetPosition(LPPOINT lpPoint) const;
  DWORD               GetData(void) const;
  BOOL                SetData(DWORD dwData);
  BOOL                Highlight(BOOL bHighlight = TRUE);
  BOOL                Select(BOOL bSelect = TRUE);
  BOOL                Halo(BOOL bHalo = TRUE);

protected:
  CGcTcUiCatalogViewItem(CGcTcUiCatalogView* pCatalogView);
  CGcTcUiCatalogViewItem(CGcTcUiCatalogView* pCatalogView,
    GcTcCatalogItem* pCatalogItem, const CSize& sizeImage,
    DWORD dwStyle = GCTCUI_CVISTYLE_PUSHBUTTON);

protected:
  void            *   mpImpObj;
private:
  friend class GcTcUiSystemInternals;
};

typedef CTypedPtrArray<CPtrArray, CGcTcUiCatalogViewItem*> CGcTcUiCatalogViewItemArray;
