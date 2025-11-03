/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "xgraph.h"

GCCORE_PORT Gcad::ErrorStatus gcdbResolveCurrentXRefs(GcDbDatabase* pHostDb,
  bool useThreadEngine = true, bool doNewOnly = false);

GCCORE_PORT Gcad::ErrorStatus gcdbAttachXref(GcDbDatabase* pHostDb,
  const GCHAR * pFilename,
  const GCHAR * pBlockName,
  GcDbObjectId& xrefBlkId);

GCCORE_PORT Gcad::ErrorStatus gcdbOverlayXref(GcDbDatabase* pHostDb,
  const GCHAR * pFilename,
  const GCHAR * pBlockName,
  GcDbObjectId& xrefBlkId);

GCCORE_PORT Gcad::ErrorStatus gcdbDetachXref(GcDbDatabase* pHostDb,
  const GcDbObjectId& xrefBlkId);

GCCORE_PORT Gcad::ErrorStatus gcdbUnloadXrefs(GcDbDatabase*      pHostDb,
  const GcDbObjectIdArray& xrefBlkIds,
  const bool               bQuiet = true);

GCCORE_PORT Gcad::ErrorStatus gcdbReloadXrefs(GcDbDatabase*      pHostDb,
  const GcDbObjectIdArray& xrefBlkIds,
  bool               bQuiet = true);

GCCORE_PORT Gcad::ErrorStatus gcdbBindXrefs(GcDbDatabase*      pHostDb,
  const GcDbObjectIdArray& xrefBlkIds,
  const bool               bInsertBind,
  const bool               bAllowUnresolved = false,
  const bool               bQuiet = true);

GCCORE_PORT Gcad::ErrorStatus gcdbXBindXrefs(GcDbDatabase*     pHostDb,
  const GcDbObjectIdArray xrefSymbolIds,
  const bool              bInsertBind,
  const bool              bQuiet = true);

GCCORE_PORT void gcdbReleaseHostDwg(GcDbDatabase* pHostDb);

GCCORE_PORT Gcad::ErrorStatus
gcdbGetHostDwgXrefGraph(GcDbDatabase* pHostDb, GcDbXrefGraph& graph,
  Gsoft::Boolean includeGhosts = Gsoft::kFalse);

class GCDB_PORT GcDbXrefObjectId {
public:
  GcDbXrefObjectId();
  GcDbXrefObjectId(const GcDbXrefObjectId& other);

  GcDbXrefObjectId& operator= (const GcDbXrefObjectId& other);
  bool operator== (const GcDbXrefObjectId& other) const;
  bool operator!= (const GcDbXrefObjectId& other) const;

  bool isValid(void) const;
  bool isXref(void) const { return !m_handle.isNull(); }
  bool isNull(void) const { return m_localId.isNull(); }

  Gcad::ErrorStatus setNull(void);

  Gcad::ErrorStatus setXrefId(GcDbObjectId xrefBlkId, const GcDbHandle & hObject);
  Gcad::ErrorStatus getXrefId(GcDbObjectId& xrefBlkId, GcDbHandle& hObject) const;

  Gcad::ErrorStatus setLocalId(GcDbObjectId objId);
  Gcad::ErrorStatus getLocalId(GcDbObjectId& objId) const;

  Gcad::ErrorStatus resolveObjectId(GcDbObjectId& id) const;

  Gcad::ErrorStatus serializeToResbuf(resbuf*& pResBuf, resbuf*& pEndOfChain) const;
  Gcad::ErrorStatus serializeFromResbuf(const resbuf* pResBuf, resbuf*& pNextInChain);

private:
  GcDbObjectId        m_localId;
  GcDbHandle          m_handle;
};
