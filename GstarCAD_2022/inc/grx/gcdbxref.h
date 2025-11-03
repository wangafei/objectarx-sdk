#pragma once

#include "gcadstd.h"
#include "../DbXrefGraph.h"
#include "../XRefMan.h"

GCDB_DLL_DECL Gcad::ErrorStatus gcdbResolveCurrentXRefs(GcDbDatabase* pHostDb,
    bool useThreadEngine = true, bool doNewOnly = false);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbAttachXref(GcDbDatabase* pHostDb,
                                 const GCHAR * pFilename, 
                                 const GCHAR * pBlockName,
                                 OdDbObjectId& xrefBlkId);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbOverlayXref(GcDbDatabase* pHostDb,
                                  const GCHAR * pFilename,
                                  const GCHAR * pBlockName,
                                  OdDbObjectId& xrefBlkId);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbDetachXref(GcDbDatabase* pHostDb, 
                           const OdDbObjectId& xrefBlkId);



GCDB_DLL_DECL Gcad::ErrorStatus gcdbUnloadXrefs(GcDbDatabase*      pHostDb,
                            const OdDbObjectIdArray& xrefBlkIds,
                            const bool               bQuiet = true);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbReloadXrefs(GcDbDatabase*      pHostDb,
                            const OdDbObjectIdArray& xrefBlkIds,
                                  bool               bQuiet = true);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbBindXrefs(GcDbDatabase*      pHostDb,
                          const OdDbObjectIdArray& xrefBlkIds, 
                          const bool               bInsertBind,
                          const bool               bAllowUnresolved = false,
                          const bool               bQuiet = true);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbXBindXrefs(GcDbDatabase*     pHostDb,
                           const OdDbObjectIdArray xrefSymbolIds,
                           const bool              bInsertBind,
                           const bool              bQuiet = true);

GCDB_DLL_DECL void gcdbReleaseHostDwg(GcDbDatabase* pHostDb);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbGetHostDwgXrefGraph(GcDbDatabase* pHostDb, OdDbXrefGraph& graph,
    Hccad::Boolean includeGhosts = Hccad::kFalse);

class OdDbXrefObjectId;