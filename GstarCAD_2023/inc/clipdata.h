/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _CLIPDATA_H
#define _CLIPDATA_H

#pragma pack (push, 8)

#include "gccoredefs.h"
#include "GdGChar.h"

enum eClipInfoFlags {
  kbDragGeometry = 0x01,
};

enum eXrefType {
  kXrefTypeAttach = 1,
  kXrefTypeOverlay = 2
};

enum eExpandedClipDataTypes {
  kDcPlotStyles = 1,
  kDcXrefs = 2,
  kDcLayouts = 3,
  kDcBlocks = 4,
  kDcLayers = 5,
  kDcDrawings = 6,
  kDcLinetypes = 7,
  kDcTextStyles = 8,
  kDcDimStyles = 9,
  kDcBlocksWithAttdef = 10,
  kDcHatches = 11,
  kTpXrefs = 12,
  kTpImages = 13,
  kTpTable = 14,
  kDcTableStyles = 15,
  kDcMultileaderStyles = 16,
  kDcVisualStyles = 17,
  kDcSectionViewStyles = 18,
  kDcDetailViewStyles = 19,
};

const int nBlockFileSize = 260;
const int nSignatureSize = 4;

typedef struct tagClipboardInfo {
  GCHAR        szTempFile[nBlockFileSize];
  GCHAR        szSourceFile[nBlockFileSize];
  GCHAR        szSignature[nSignatureSize];
  int         nFlags;
  GcGePoint3d dptInsert;
  RECT        rectGDI;
  void*       mpView;
  DWORD       m_dwThreadId;
  int         nLen;
  int         nType;
  GCHAR        chData[1];
} ClipboardInfo;

#define szClipSignature GCRX_T("R15")

GCCORE_PORT const GCHAR* gcedClipFormatName();

#pragma pack (pop)

#endif