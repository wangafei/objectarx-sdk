/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCTCUI_H__
#define __GCTCUI_H__

#include "gdui.h"
#include "GdGChar.h"
#include <afxtempl.h>

#ifdef  _GCTCUI_BUILD
#  define   GCTCUI_PORT  __declspec(dllexport)
#else
#  define   GCTCUI_PORT  
#endif

class CGcTcUiManager;
class CGcTcUiToolPaletteSet;
class CGcTcUiToolPalette;
class CGcTcUiCatalogView;
class GcTcCatalogItem;
class GcTcCatalog;
class GcTcStockTool;
class GcTcTool;

typedef CTypedPtrArray<CPtrArray, GcTcCatalogItem*> GcTcCatalogItemArray;
typedef CTypedPtrArray<CPtrArray, GcTcStockTool*>   GcTcStockToolArray;
typedef CTypedPtrArray<CPtrArray, GcTcCatalog*>     GcTcCatalogArray;
typedef CTypedPtrArray<CPtrArray, CGcTcUiToolPaletteSet*> GcTcUiToolPaletteSetArray;
typedef CTypedPtrArray<CPtrArray, CGcTcUiToolPalette*> GcTcUiToolPaletteArray;
typedef CTypedPtrArray<CPtrArray, CGcTcUiCatalogView*> GcTcUiCatalogViewArray;

#define GCTCUI_DRAGFORMAT_CUSTOM        (0x1 << 0)
#define GCTCUI_DRAGFORMAT_IDROP         (0x1 << 1)
#define GCTCUI_DRAGFORMAT_HDROP         (0x1 << 2)

#define GCTCUI_CNPS_NOCREATEWINDOW      (0x1 << 0)
#define GCTCUI_CNPS_NOADD               (0x1 << 1)
#define GCTCUI_CNPS_CREATEHIDDEN        (0x1 << 2)

#define CF_GCTC_CATALOG_ITEM_17_11          GCRX_T("CF_GCTC_CATALOG_ITEM_17_11")
#define CF_GCTCUI_CATALOG_ITEM_HEADER_17_11 GCRX_T("CF_GCTCUI_CATALOG_ITEM_HEADER_17_11")
#define CF_GCTC_CATALOG_ITEM_17_1           GCRX_T("CF_GCTC_CATALOG_ITEM_17_1")
#define CF_GCTCUI_CATALOG_ITEM_HEADER_17_1  GCRX_T("CF_GCTCUI_CATALOG_ITEM_HEADER_17_1")
#define CF_GCTC_CATALOG_ITEM_16_1           GCRX_T("CF_GCTC_CATALOG_ITEM_16_1")
#define CF_GCTCUI_CATALOG_ITEM_HEADER_16_1  GCRX_T("CF_GCTCUI_CATALOG_ITEM_HEADER_16_1")
#define CF_GCTCUI_CATALOG_ITEM              GCRX_T("CF_GCTC_CATALOG_ITEM")
#define CF_GCTCUI_CATALOG_ITEM_HEADER       GCRX_T("CF_GCTCUI_CATALOG_ITEM_HEADER")
#define CF_IDROP_GCTCUI_TOOL                GCRX_T("CF_IDROP.XML_GCTCUI_TOOL")
#define CF_IDROP_GCTCUI_PALETTE             GCRX_T("CF_IDROP.XML_GCTCUI_PALETTE")
#define CF_IDROP_GCTCUI_PACKAGE             GCRX_T("CF_IDROP.XML_GCTCUI_PACKAGE")
#define CF_IDROP_GCTCUI_CATEGORY            GCRX_T("CF_IDROP.XML_GCTCUI_CATEGORY")
#define CF_IDROP_GCTCUI_CATALOG             GCRX_T("CF_IDROP.XML_GCTCUI_CATALOG")
#define CF_IDROP_GCTCUI_STOCKTOOL           GCRX_T("CF_IDROP.XML_GCTCUI_STOCKTOOL")
#define CF_GCTCUI_TOOLBAR_ITEM              GCRX_T("CF_GCTCUI_TOOLBAR_ITEM")

#define GCTCUI_PI_SHOW_PROGRESS         (0x1 << 0)
#define GCTCUI_PI_USE_NEW_IDS           (0x1 << 1)
#define GCTCUI_PI_BREAK_SOURCE_LINK     (0x1 << 2)      
#define GCTCUI_PI_NOTIFY_TOOLS          (0x1 << 3)      

typedef struct GCTCUI_DRAG_HEADER
{
  DWORD               mdwDragFormat;
#ifdef _GSOFT_WINDOWS_
  CLIPFORMAT          mcfClipFormat;
#endif
  BOOL                mbGscadSource;
  DWORD               mdwSourceProcessId;
  GUID                mRootId;
  GUID                mParentId;
  BOOL                mbReadOnlySource;
  int                 mnCount;
  int                 mnStockTools;
  DWORD               mdwItemTypes;
} GCTCUI_DRAG_HEADER;

GCTCUI_PORT void GcTcUiInitialize();
GCTCUI_PORT CGcTcUiManager* GcTcUiGetManager(void);

#ifdef _GSOFT_WINDOWS_
GCTCUI_PORT BOOL        GcTcUiCopyItems(COleDataSource* pDataSource,
  const GcTcCatalogItemArray* pItems,
  BOOL bGscadSource);
GCTCUI_PORT BOOL        GcTcUiGetDragInfo(IDataObject* pDataObject,
  GCTCUI_DRAG_HEADER* pHeader);
GCTCUI_PORT BOOL        GcTcUiPasteItems(IDataObject* pDataObject,
  GcTcCatalogItemArray* pItems,
  GcTcCatalogItemArray* pStockTools,
  DWORD dwFlag = GCTCUI_PI_SHOW_PROGRESS);
GCTCUI_PORT CGcTcUiToolPaletteSet* GcTcUiGetToolPaletteWindow(void);
GCTCUI_PORT BOOL        GcTcUiFilterShapesDialog(GcTcCatalogItem* pPackage,
  GcTcCatalogItemArray* pActiveShapes,
  GcTcTool*& pCurrentShape,
  CWnd* pParentWnd);
#endif 
#endif 