/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCRX_EVENT_H__
#define   _GCRX_EVENT_H__

#include "gcarray.h"
#include "rxobject.h"
#include "GdGChar.h"
#include "dbid.h"
#pragma pack (push, 8)

#define GCRX_EVENT_OBJ GCRX_T("GcRxEvent")

class GcDbDatabase;
class GcGeMatrix3d;
class GcDbIdMapping;
class GcGePoint3d;

enum GcXrefSubCommand
{
  kAttach  = 0,
  kBind    = 1,
  kDetach  = 2,
  kOverlay = 3,
  kPath    = 4,
  kReload  = 5,
  kResolve = 6,
  kUnload  = 7,
  kXBind   = 8
};

class GCDB_PORT GcRxEventReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxEventReactor);

  GSOFT_DEPRECATED virtual void dwgFileOpened(GcDbDatabase*, GCHAR *) final {};
  virtual void dwgFileOpened(GcDbDatabase*, const GCHAR *) {};
  virtual void initialDwgFileOpenComplete(GcDbDatabase*);
  virtual void databaseConstructed(GcDbDatabase*);
  virtual void databaseToBeDestroyed(GcDbDatabase*);

  virtual void beginSave(GcDbDatabase*, const GCHAR * pIntendedName);
  virtual void saveComplete(GcDbDatabase*, const GCHAR * pActualName);
  virtual void abortSave(GcDbDatabase*);

  virtual void beginDxfIn(GcDbDatabase*);
  virtual void abortDxfIn(GcDbDatabase*);
  virtual void dxfInComplete(GcDbDatabase*);
  virtual void beginDxfOut(GcDbDatabase*);
  virtual void abortDxfOut(GcDbDatabase*);
  virtual void dxfOutComplete(GcDbDatabase*);

  virtual void beginInsert(GcDbDatabase* pTo, const GCHAR * pBlockName, GcDbDatabase* pFrom);
  virtual void beginInsert(GcDbDatabase* pTo, const GcGeMatrix3d& xform, GcDbDatabase* pFrom);
  virtual void otherInsert(GcDbDatabase* pTo, GcDbIdMapping& idMap, GcDbDatabase* pFrom);
  virtual void abortInsert(GcDbDatabase* pTo);
  virtual void endInsert(GcDbDatabase* pTo);

  virtual void wblockNotice(GcDbDatabase* pDb);
  virtual void beginWblock(GcDbDatabase* pTo, GcDbDatabase* pFrom, const GcGePoint3d*& insertionPoint);
  virtual void beginWblock(GcDbDatabase* pTo, GcDbDatabase* pFrom, GcDbObjectId blockId);
  virtual void beginWblock(GcDbDatabase* pTo, GcDbDatabase* pFrom);
  virtual void otherWblock(GcDbDatabase* pTo, GcDbIdMapping&, GcDbDatabase* pFrom);
  virtual void abortWblock(GcDbDatabase* pTo);
  virtual void endWblock(GcDbDatabase* pTo);
  virtual void beginWblockObjects(GcDbDatabase*, GcDbIdMapping&);

  virtual void beginDeepClone(GcDbDatabase* pTo, GcDbIdMapping&);
  virtual void beginDeepCloneXlation(GcDbIdMapping&, Gcad::ErrorStatus*);
  virtual void abortDeepClone(GcDbIdMapping&);
  virtual void endDeepClone(GcDbIdMapping&);

  virtual void partialOpenNotice(GcDbDatabase* pDb);

  virtual void beginAttach(GcDbDatabase* pTo, const GCHAR *, GcDbDatabase* pFrom);
  virtual void otherAttach(GcDbDatabase* pTo, GcDbDatabase* pFrom);
  virtual void abortAttach(GcDbDatabase* pFrom);
  virtual void endAttach(GcDbDatabase* pTo);
  virtual void redirected(GcDbObjectId  newId, GcDbObjectId oldId);
  virtual void comandeered(GcDbDatabase* pTo, GcDbObjectId id, GcDbDatabase* pFrom);
  virtual void beginRestore(GcDbDatabase* pTo, const GCHAR *, GcDbDatabase* pFrom);
  virtual void abortRestore(GcDbDatabase* pTo);
  virtual void endRestore(GcDbDatabase* pTo);

  virtual void xrefSubcommandBindItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId);
  virtual void xrefSubcommandAttachItem(GcDbDatabase* pHost, int activity, const GCHAR* pPath);
  virtual void xrefSubcommandOverlayItem(GcDbDatabase* pHost, int activity, const GCHAR* pPath);
  virtual void xrefSubcommandDetachItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId);
  virtual void xrefSubcommandPathItem(int activity, GcDbObjectId blockId, const GCHAR* pNewPath);
  virtual void xrefSubcommandReloadItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId);
  virtual void xrefSubcommandUnloadItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId);
  virtual void xrefSubCommandStart(GcDbDatabase* pHostDb,
                                   GcXrefSubCommand op,
                                   const GcArray<GcDbObjectId>& ids,
                                   const GCHAR* const* btrNames,
                                   const GCHAR* const* paths,
                                   bool& vetoOp);
  virtual void xrefSubCommandAborted(GcDbDatabase* pHostDb,
                                     GcXrefSubCommand op,
                                     const GcArray<GcDbObjectId>& ids,
                                     const GCHAR* const* btrNames,
                                     const GCHAR* const* paths);
  virtual void xrefSubCommandEnd(GcDbDatabase* pHostDb,
                                 GcXrefSubCommand op,
                                 const GcArray<GcDbObjectId>& ids,
                                 const GCHAR* const* btrNames,
                                 const GCHAR* const* paths);

  virtual void preXrefLockFile(GcDbDatabase* pDb, GcDbObjectId btrId);
};

#define gcrxEvent GcRxEvent::cast(gcrxSysRegistry()->at(GCRX_EVENT_OBJ))

class GCDB_PORT GcRxEvent : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxEvent);
  virtual void addReactor(GcRxEventReactor * newObj) = 0;
  virtual void removeReactor(GcRxEventReactor * delObj) = 0;
};

#pragma pack (pop)
#endif
