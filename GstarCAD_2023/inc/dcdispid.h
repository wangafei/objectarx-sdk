/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DCDISPID_H
#define DCDISPID_H

#define GCDC_MAKE_DISPID(ID)    (ID + 100)

#define DISPID_IGcDcContentBrowser_AddPaletteItem           GCDC_MAKE_DISPID(1)
#define DISPID_IGcDcContentBrowser_AddNavigatorNode         GCDC_MAKE_DISPID(2)
#define DISPID_IGcDcContentBrowser_GetDCFrameWindow         GCDC_MAKE_DISPID(3)
#define DISPID_IGcDcContentBrowser_SetItemDescription       GCDC_MAKE_DISPID(4)
#define DISPID_IGcDcContentBrowser_SetPaletteImageList      GCDC_MAKE_DISPID(5)
#define DISPID_IGcDcContentBrowser_SetNavigatorImageList    GCDC_MAKE_DISPID(6)
#define DISPID_IGcDcContentBrowser_SetPaletteMultiSelect    GCDC_MAKE_DISPID(7)
#define DISPID_IGcDcContentBrowser_InsertPaletteColumn      GCDC_MAKE_DISPID(8)
#define DISPID_IGcDcContentBrowser_DeleteAllPaletteItems    GCDC_MAKE_DISPID(9)
#define DISPID_IGcDcContentBrowser_GetSelectedNavNodeText   GCDC_MAKE_DISPID(10)
#define DISPID_IGcDcContentBrowser_GetCurrentViewMode       GCDC_MAKE_DISPID(11)
#define DISPID_IGcDcContentBrowser_SetPaletteSubItem        GCDC_MAKE_DISPID(12)
#define DISPID_IGcDcContentBrowser_SortPaletteItems         GCDC_MAKE_DISPID(13)
#define DISPID_IGcDcContentBrowser_RestorePaletteSelection  GCDC_MAKE_DISPID(14)
#define DISPID_IGcDcContentBrowser_GetDCStatusBar           GCDC_MAKE_DISPID(15)
#define DISPID_IGcDcContentBrowser_GetPaneInfo              GCDC_MAKE_DISPID(16)
#define DISPID_IGcDcContentBrowser_SetPaletteViewType       GCDC_MAKE_DISPID(17)
#define DISPID_IGcDcContentBrowser_NavigateTo               GCDC_MAKE_DISPID(18)

#define DISPID_IGcDcContentView_Initialize                  GCDC_MAKE_DISPID(101)
#define DISPID_IGcDcContentView_SetImageLists               GCDC_MAKE_DISPID(102)
#define DISPID_IGcDcContentView_Refresh                     GCDC_MAKE_DISPID(103)
#define DISPID_IGcDcContentView_NavigatorNodeExpanding      GCDC_MAKE_DISPID(104)
#define DISPID_IGcDcContentView_NavigatorNodeCollapsing     GCDC_MAKE_DISPID(105)
#define DISPID_IGcDcContentView_NavigatorNodeClick          GCDC_MAKE_DISPID(106)
#define DISPID_IGcDcContentView_NavigatorMouseUp            GCDC_MAKE_DISPID(107)
#define DISPID_IGcDcContentView_PaletteItemClick            GCDC_MAKE_DISPID(108)
#define DISPID_IGcDcContentView_PaletteItemDblClick         GCDC_MAKE_DISPID(109)
#define DISPID_IGcDcContentView_PaletteColumnClick          GCDC_MAKE_DISPID(110)
#define DISPID_IGcDcContentView_PaletteMouseUp              GCDC_MAKE_DISPID(111)
#define DISPID_IGcDcContentView_PaletteMouseDown            GCDC_MAKE_DISPID(112)
#define DISPID_IGcDcContentView_RenderPreviewWindow         GCDC_MAKE_DISPID(113)
#define DISPID_IGcDcContentView_PreviewMouseUp              GCDC_MAKE_DISPID(114)
#define DISPID_IGcDcContentView_PaletteBeginDrag            GCDC_MAKE_DISPID(115)
#define DISPID_IGcDcContentView_ReleaseBrowser              GCDC_MAKE_DISPID(116)
#define DISPID_IGcDcContentView_QueryContextMenu            GCDC_MAKE_DISPID(117)
#define DISPID_IGcDcContentView_InvokeCommand               GCDC_MAKE_DISPID(118)
#define DISPID_IGcDcContentView_IsExpandable                GCDC_MAKE_DISPID(119)
#define DISPID_IGcDcContentView_GetLargeIcon                GCDC_MAKE_DISPID(120)
#define DISPID_IGcDcContentView_GetSmallImageListForContent GCDC_MAKE_DISPID(121)
#define DISPID_IGcDcContentView_GetLargeImageListForContent GCDC_MAKE_DISPID(122)
#define DISPID_IGcDcContentView_GetCommandString            GCDC_MAKE_DISPID(123)
#define DISPID_IGcDcContentView_DeleteItemData              GCDC_MAKE_DISPID(124)

#endif 