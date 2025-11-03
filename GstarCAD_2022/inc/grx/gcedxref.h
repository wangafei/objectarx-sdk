#ifndef   _GCEDXREF_H
#define   _GCEDXREF_H

#include "gcadstd.h"

#pragma pack (push, 8)

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefAttach(const GCHAR*           XrefPathname,
               const GCHAR*           XrefBlockname,
                     OdDbObjectId*   pXrefBTRid       = NULL,
                     OdDbObjectId*   pXrefRefid       = NULL,
               const OdGePoint3d*    pXrefInsertPt    = NULL,
               const OdGeScale3d*    pXrefScale       = NULL,
               const double*         pXrefRotateAngle = NULL,
               const bool            bQuiet           = true,
                     OdDbDatabase*   pHostDb          = NULL,
               const wchar_t*       wszPassword       = NULL);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefOverlay(const GCHAR*           XrefPathname,
                const GCHAR*           XrefBlockname,
                      OdDbObjectId*   pXrefBTRid       = NULL,
                      OdDbObjectId*   pXrefRefid       = NULL,
                const OdGePoint3d*    pXrefInsertPt    = NULL,
                const OdGeScale3d*    pXrefScale       = NULL,
                const double*         pXrefRotateAngle = NULL,
                const bool            bQuiet           = true,
                      OdDbDatabase*   pHostDb          = NULL,
                const wchar_t*        wszPassword      = NULL);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefUnload(const GCHAR*           XrefBlockname,
               const bool            bQuiet        = true,
                     OdDbDatabase*   pHostDb       = NULL);
GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefDetach(const GCHAR*           XrefBlockname,
               const bool            bQuiet        = true,
                     OdDbDatabase*   pHostDb       = NULL);
GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefReload(const GCHAR*           XrefBlockname,
               const bool            bQuiet        = true, 
                     OdDbDatabase*   pHostDb       = NULL);
GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefBind(const GCHAR*           XrefBlockname,
             const bool            bInsertBind     = false,
             const bool            bQuiet          = true,
                   OdDbDatabase*   pHostDb         = NULL);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefCreateBlockname(const GCHAR*  XrefPathname,
                              GCHAR*& XrefBlockname);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefReload(const OdDbObjectIdArray& XrefBTRids,
                     bool               bQuiet     = true,
                     OdDbDatabase*      pHostDb    = NULL);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefXBind(const OdDbObjectIdArray symbolIds,
              const bool              bQuiet       = true,
                    OdDbDatabase*     pHostDb      = NULL);

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefResolve(OdDbDatabase* pHostDb, const bool bQuiet = true);

#pragma pack (pop)

#endif /* _ICEDXREF_H */

