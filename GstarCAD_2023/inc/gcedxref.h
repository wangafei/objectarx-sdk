/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCEDXREF_H
#define   _GCEDXREF_H
#pragma pack (push, 8)

class GcDbBlockTableRecord;

GCCORE_PORT Gcad::ErrorStatus
gcedXrefAttach(const GCHAR*           XrefPathname,
  const GCHAR*           XrefBlockname,
  GcDbObjectId*   pXrefBTRid = NULL,
  GcDbObjectId*   pXrefRefid = NULL,
  const GcGePoint3d*    pXrefInsertPt = NULL,
  const GcGeScale3d*    pXrefScale = NULL,
  const double*         pXrefRotateAngle = NULL,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL,
  const wchar_t*       wszPassword = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefOverlay(const GCHAR*           XrefPathname,
  const GCHAR*           XrefBlockname,
  GcDbObjectId*   pXrefBTRid = NULL,
  GcDbObjectId*   pXrefRefid = NULL,
  const GcGePoint3d*    pXrefInsertPt = NULL,
  const GcGeScale3d*    pXrefScale = NULL,
  const double*         pXrefRotateAngle = NULL,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL,
  const wchar_t*        wszPassword = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefUnload(const GCHAR*           XrefBlockname,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL);
GCCORE_PORT Gcad::ErrorStatus
gcedXrefDetach(const GCHAR*           XrefBlockname,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL);
GCCORE_PORT Gcad::ErrorStatus
gcedXrefReload(const GCHAR*           XrefBlockname,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL);
GCCORE_PORT Gcad::ErrorStatus
gcedXrefBind(const GCHAR*           XrefBlockname,
  const bool            bInsertBind = false,
  const bool            bQuiet = true,
  GcDbDatabase*   pHostDb = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefCreateBlockname(const GCHAR*  XrefPathname,
  GCHAR*& XrefBlockname);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefReload(const GcDbObjectIdArray& XrefBTRids,
  bool               bQuiet = true,
  GcDbDatabase*      pHostDb = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefXBind(const GcDbObjectIdArray symbolIds,
  const bool              bQuiet = true,
  GcDbDatabase*     pHostDb = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefResolve(GcDbDatabase* pHostDb, const bool bQuiet = true);

GCCORE_PORT Gcad::ErrorStatus
gcedXrefNotifyCheckFileChanged(GcDbObjectId btrId, bool& hasChanged);

GCCORE_PORT Gcad::ErrorStatus
gcedSkipXrefNotification(GcDbDatabase* pHostDb, const GCHAR* xrefName);

Gcad::ErrorStatus GCCORE_PORT
gcedSetXrefResolvedWithUpdateStatus(GcDbBlockTableRecord* pBTR);

GCCORE_PORT void
gcedMarkForDelayXRefRelativePathResolve(const GcDbObjectId& xrefDefId);

GCCORE_PORT void
gcedUnmarkForDelayXRefRelativePathResolve(const GcDbObjectId& xrefDefId);

#pragma pack (pop)
#endif 