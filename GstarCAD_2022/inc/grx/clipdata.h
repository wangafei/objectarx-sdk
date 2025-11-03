#ifndef _CLIPDATA_H
#define _CLIPDATA_H

#pragma pack (push, 8)

#include "gchar.h"

enum eClipInfoFlags 
{
    kbDragGeometry  = 0x01,
};

enum eXrefType 
{
    kXrefTypeAttach     = 1,
    kXrefTypeOverlay    = 2
};

enum eExpandedClipDataTypes 
{
    kDcPlotStyles       = 1,
    kDcXrefs            = 2,
    kDcLayouts          = 3,
    kDcBlocks           = 4,
    kDcLayers           = 5,
    kDcDrawings         = 6,
    kDcLinetypes        = 7,
    kDcTextStyles       = 8,
    kDcDimStyles        = 9,
    kDcBlocksWithAttdef = 10,
    kDcHatches          = 11,
    kTpXrefs            = 12,
    kTpImages           = 13,
    kTpTable            = 14,
    kDcTableStyles      = 15, 
    kDcMultileaderStyles = 16 
};

const int nBlockFileSize = 260;

typedef struct tagClipboardInfo 
{
    GCHAR        szTempFile[nBlockFileSize];     // block temp file name
    GCHAR        szSourceFile[nBlockFileSize];   // file name of drawing from which selection was made
    GCHAR        szSignature[4];                 // szClipSignature
    int         nFlags;                         // kbDragGeometry: dragging geometry from GCAD
    GcGePoint3d dptInsert;                      // original world coordinate of insertion point
    RECT        rectGDI;                        // GDI coord bounding rectangle of sset
    void*       mpView;                         // Used to verify that this object was created in this view (HWND*)
    DWORD       m_dwThreadId;                   // GCAD thread that created this DataObject
    int         nLen;                           // Length of next segment of data, if any, starting with chData
    int         nType;                          // Type of data, if any (eExpandedClipDataTypes)
    GCHAR        chData[1];                      // Start of data, if any.
} ClipboardInfo;

#define szClipSignature GCRX_T("R15")

// Clipboard format. The clipboard format is set to GCAD for all prodcuts. 
#define CF_AUTOCAD  GCRX_T("AutoCAD.r18")

#pragma pack (pop)

#endif