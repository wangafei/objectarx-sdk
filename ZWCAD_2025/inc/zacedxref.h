

#ifndef   _ZCEDXREF_H
#define   _ZCEDXREF_H
#pragma pack (push, 8)

class ZcDbBlockTableRecord;
Zcad::ErrorStatus
zcedXrefAttach(const ZTCHAR*           XrefPathname,
               const ZTCHAR*           XrefBlockname,
                     ZcDbObjectId*   pXrefBTRid       = NULL,
                     ZcDbObjectId*   pXrefRefid       = NULL,
               const ZcGePoint3d*    pXrefInsertPt    = NULL,
               const ZcGeScale3d*    pXrefScale       = NULL,
               const double*         pXrefRotateAngle = NULL,
               const bool            bQuiet           = true,
                     ZcDbDatabase*   pHostDb          = NULL,
               const wchar_t*       wszPassword       = NULL);

Zcad::ErrorStatus
zcedXrefOverlay(const ZTCHAR*           XrefPathname,
                const ZTCHAR*           XrefBlockname,
                      ZcDbObjectId*   pXrefBTRid       = NULL,
                      ZcDbObjectId*   pXrefRefid       = NULL,
                const ZcGePoint3d*    pXrefInsertPt    = NULL,
                const ZcGeScale3d*    pXrefScale       = NULL,
                const double*         pXrefRotateAngle = NULL,
                const bool            bQuiet           = true,
                      ZcDbDatabase*   pHostDb          = NULL,
                const wchar_t*        wszPassword      = NULL);

Zcad::ErrorStatus
zcedXrefUnload(const ZTCHAR*         XrefBlockname,
               const bool            bQuiet        = true,
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefDetach(const ZTCHAR*         XrefBlockname,
               const bool            bQuiet        = true,
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefReload(const ZTCHAR*         XrefBlockname,
               const bool            bQuiet        = true, 
                     ZcDbDatabase*   pHostDb       = NULL);
Zcad::ErrorStatus
zcedXrefBind(const ZTCHAR*         XrefBlockname,
             const bool            bInsertBind     = false,
             const bool            bQuiet          = true,
                   ZcDbDatabase*   pHostDb         = NULL);

Zcad::ErrorStatus
zcedXrefCreateBlockname(const ZTCHAR*  XrefPathname,
                              ZTCHAR*& XrefBlockname);

Zcad::ErrorStatus
zcedXrefReload(const ZcDbObjectIdArray& XrefBTRids,
                     bool               bQuiet     = true,
                     ZcDbDatabase*      pHostDb    = NULL);

Zcad::ErrorStatus
zcedXrefXBind(const ZcDbObjectIdArray symbolIds,
              const bool              bQuiet       = true,
                    ZcDbDatabase*     pHostDb      = NULL);

Zcad::ErrorStatus
zcedXrefResolve(ZcDbDatabase* pHostDb, const bool bQuiet = true);

Zcad::ErrorStatus
zcedXrefNotifyCheckFileChanged(ZcDbObjectId btrId, bool& hasChanged);

Zcad::ErrorStatus
zcedSkipXrefNotification(ZcDbDatabase* pHostDb, const ZTCHAR* xrefName);

Zcad::ErrorStatus ZCDB_PORT
zcedSetXrefResolvedWithUpdateStatus(ZcDbBlockTableRecord* pBTR);

void
zcedMarkForDelayXRefRelativePathResolve(const ZcDbObjectId& xrefDefId);

void
zcedUnmarkForDelayXRefRelativePathResolve(const ZcDbObjectId& xrefDefId);

#pragma pack (pop)
#endif 

