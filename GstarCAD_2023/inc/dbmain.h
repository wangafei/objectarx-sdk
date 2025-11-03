/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBMAIN_H
#define GD_DBMAIN_H

#include <stddef.h>
#include "gsoft.h"
#include "gcadapidef.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "GcHeapOpers.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbboiler.h"   
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "GcString.h"

class GcCmEntityColor;
class GcCmColor;
class GcDbBlockBegin;
class GcDbBlockEnd;
class GcDbDatabase;
class GcDbDatabaseIterator;
class GcDbDatabaseReactor;
class GcDbEntity;
class GcDbEntityReactor;
class GcDbImpDatabase;
class GcDbImpObject;
class GcDbObject;
class GcDbObjectReactor;
class GcDbSpaceIterator;
class GcDbSystemInternals;
class GcDbXObject;
class GcDbBlockReference;
class GcDbSymbolTable;
class GcDbBlockTable;
class GcDbBlockTableRecord;
class GcDbLayerTable;
class GcDbTextStyleTable;
class GcDbLinetypeTable;
class GcDbAbstractViewTable;
class GcDbViewTable;
class GcDbUCSTable;
class GcDbViewportTable;
class GcDbRegAppTable;
class GcDbDimStyleTable;
class GcDbDimStyleTableRecord;
class GcDbIdMapping;
class GcDbDictionary;
class GcDbDictionaryWithDefault;
class GcDbMline;
class GcDbMlineStyle;
class GcDbCurve;
class GcDbEllipse;
class GcDbSpline;
class GcDbRegion;
class GcDb3dSolid;
class GcDbBody;
class GcDbDate;
class GcDbExtents;
class GcDbAuditInfo;
class GcDbUndoController;
class GcDbTransactionManager;
class GcDbSpatialFilter;
class GcDbLayerFilter;
class GcGeMatrix2d;
class GcGeVector3d;
class GcGsNode;
class GcGsModel;
class GcGiContext;
class GcDbObjectIdGraph;
class GcDbLayerStateManager;
class GcDwgFileHandle;
class GcDbTableStyle;
class GcFdFieldValue;
class GcDbField;
class GcDbSectionManager;
class GcDbDataLinkManager;
class GcGiMapper;
class GcDbAnnotationScale;
class IGcReadStream;
class IGcWriteStream;

GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);

namespace Gtil
{
  class Image;
}

#include "gcdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "gds_db.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "gcgidefs.h"
#include "gcarray.h"
#pragma pack(push, 8)

class GcLocale;

struct _GUID;
typedef struct _GUID CLSID;

class GcDbGripData;
typedef GcArray<GcDbGripData*, GcArrayMemCopyReallocator<GcDbGripData*> > GcDbGripDataPtrArray;
typedef GcArray<GcDbFullSubentPath,
  GcArrayObjectCopyReallocator<GcDbFullSubentPath> > GcDbFullSubentPathArray;

extern GCDB_PORT_GLOBAL const GcDbFullSubentPath kNullSubent;

GcDb::DwgDataType gcdbGroupCodeToType(GcDb::DxfCode pCode);
GCCORE_PORT void  gcdbFreeResBufContents(resbuf* pField);

GCDB_PORT GcDbObjectId  gcdbPersistentReactorObjectId(const void *pSomething);
inline bool gcdbIsPersistentReactor(const void *pSomething)
{
  return !::gcdbPersistentReactorObjectId(pSomething).isNull();
}

GCCORE_PORT bool gcdbDisplayPreviewFromDwg(const GCHAR *pszDwgfilename,
  void* pPreviewWnd,
  const Gsoft::UInt32* pBgColor = nullptr);

GCCORE_PORT bool gcdbIsCustomObject(const GcDbObjectId& id);

GCDB_PORT Gcad::ErrorStatus
gcdbOpenObject(GcDbObject*& pObj, GcDbObjectId id, GcDb::OpenMode mode,
  bool openErased, const GcRxClass *pClass);

GCDB_PORT Gcad::ErrorStatus
gcdbOpenObject(GcDbObject*& pObj, GcDbObjectId id, GcRxClass * (*pfDesc)(),
  GcDb::OpenMode mode, bool openErased);

inline Gcad::ErrorStatus
gcdbOpenGcDbObject(GcDbObject*& pObj, GcDbObjectId id, GcDb::OpenMode mode,
  bool openErasedObject = false)
{
  return ::gcdbOpenObject(pObj, id, mode, openErasedObject, nullptr);
}

template<class T_OBJECT> inline Gcad::ErrorStatus
gcdbOpenObject(T_OBJECT *& pObj, GcDbObjectId id, GcDb::OpenMode mode = GcDb::kForRead, bool openErased = false)
{
  return ::gcdbOpenObject((GcDbObject * &)pObj, id, &T_OBJECT::desc,
    mode, openErased);
}

inline Gcad::ErrorStatus gcdbOpenObject(GcDbObject *& pObj, GcDbObjectId id,
  GcDb::OpenMode mode = GcDb::kForRead,
  bool openErased = false)
{
  return ::gcdbOpenObject(pObj, id, mode, openErased, nullptr);
}

GCDB_PORT Gcad::ErrorStatus gcdbOpenObject(GcDbEntity *& pEnt, GcDbObjectId id, GcDb::OpenMode mode = GcDb::kForRead, bool openErased = false);

inline Gcad::ErrorStatus
gcdbOpenGcDbEntity(GcDbEntity*& pEnt, GcDbObjectId id, GcDb::OpenMode mode,
  bool openErasedEntity = false)
{
  return ::gcdbOpenObject(pEnt, id, mode, openErasedEntity);
}

GCDB_PORT Gcad::ErrorStatus gcdbResurrectMeNow(const GcDbObjectId& id);
GCDB_PORT Gcad::ErrorStatus gcdbGetGdsName(gds_name&  objName, GcDbObjectId objId);
GCDB_PORT Gcad::ErrorStatus gcdbGetObjectId(GcDbObjectId& objId, const gds_name objName);

GCCORE_PORT Gcad::ErrorStatus gcdbValKey(const gds_name lname);

GCDB_PORT Gcad::ErrorStatus gcdbSetReferenced(GcDbObjectId objId);

GCDB_PORT const GcArray<GcDbDatabase *> & gcdbActiveDatabaseArray();

class GcDbViewTableRecord;
class GcDbViewport;
class GcDbObjectContextManager;

GCCORE_PORT Gcad::ErrorStatus gcdbLoadMlineStyleFile(const GCHAR *sname, const GCHAR *fname);
GCCORE_PORT Gcad::ErrorStatus gcdbLoadLineTypeFile(const GCHAR *ltname, const GCHAR *fname, GcDbDatabase *pDb);

GCCORE_PORT void* gcdbAlloc(size_t);
GCCORE_PORT void* gcdbRealloc(void *, size_t);
GCCORE_PORT void  gcdbFree(void*);

GCCORE_PORT void gcdbInitialize();
GCCORE_PORT void gcdbTerminate();

GCDB_PORT Gcad::ErrorStatus gcdbValidateSetup(const GcLocale& loc);
GCDB_PORT Gcad::ErrorStatus gcdbCleanUp();

GCCORE_PORT const GCHAR* gcdbOriginalXrefFullPathFor(const GcDbDatabase*);
GCCORE_PORT GcGiContext* gcdbSetDefaultGcGiContext(GcGiContext *);

GCDB_PORT Gcad::ErrorStatus gcdbGetThumbnailBitmapFromDxfFile(const GCHAR* filename, void*& pBitmap);

class GCDB_PORT GcDbDatabase : public GcRxObject, public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDatabase);
  GcDbDatabase(bool buildDefaultDrawing = true, bool noDocument = false);
  ~GcDbDatabase();

  bool isBeingDestroyed() const;
  Gcad::ErrorStatus addGcDbObject(GcDbObjectId& id, GcDbObject* pObj);
  Gcad::ErrorStatus addGcDbObject(GcDbObject* pObj);

  static Gcad::ErrorStatus markObjectNonPersistent(GcDbObjectId id, bool value);
  static bool isObjectNonPersistent(GcDbObjectId id);

  Gcad::ErrorStatus getBlockTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getLayerTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getTextStyleTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getLinetypeTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getViewTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getUCSTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getViewportTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getRegAppTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getDimStyleTable(GcDbSymbolTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);

  Gcad::ErrorStatus getSymbolTable(GcDbBlockTable*&     pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbLayerTable*&     pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbTextStyleTable*& pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbLinetypeTable*&  pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbViewTable*&      pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbUCSTable*&       pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbViewportTable*&  pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbRegAppTable*&    pTable, GcDb::OpenMode       mode = GcDb::kForRead);
  Gcad::ErrorStatus getSymbolTable(GcDbDimStyleTable*&  pTable, GcDb::OpenMode       mode = GcDb::kForRead);

  Gcad::ErrorStatus getGroupDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getMLStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getLayoutDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getPlotStyleNameDictionary(GcDbDictionaryWithDefault*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getMaterialDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getVisualStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getColorDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getScaleListDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus getNamedObjectsDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);

  Gcad::ErrorStatus getBlockTable(GcDbBlockTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getLayerTable(GcDbLayerTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getTextStyleTable(GcDbTextStyleTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getLinetypeTable(GcDbLinetypeTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getViewTable(GcDbViewTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getUCSTable(GcDbUCSTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getViewportTable(GcDbViewportTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getRegAppTable(GcDbRegAppTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getDimStyleTable(GcDbDimStyleTable*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  Gcad::ErrorStatus getPlotSettingsDictionary(GcDbDictionary*& pTable, GcDb::OpenMode    mode = GcDb::kForRead);
  GcDbObjectId      getSectionManager(void) const;
  Gcad::ErrorStatus getSectionManager(GcDbSectionManager*& pMgr, GcDb::OpenMode mode = GcDb::kForRead) const;
  GcDbObjectId      dataLinkDictionaryId(void) const;
  Gcad::ErrorStatus getDataLinkDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbDataLinkManager*getDataLinkManager(void) const;
  Gcad::ErrorStatus updateDataLink(GcDb::UpdateDirection nDir, GcDb::UpdateOption nOption);

  GcDbObjectId  blockTableId() const;
  GcDbObjectId  layerTableId() const;
  GcDbObjectId  textStyleTableId() const;
  GcDbObjectId  linetypeTableId() const;
  GcDbObjectId  viewTableId() const;
  GcDbObjectId  UCSTableId() const;
  GcDbObjectId  viewportTableId() const;
  GcDbObjectId  regAppTableId() const;
  GcDbObjectId  dimStyleTableId() const;
  GcDbObjectId  mLStyleDictionaryId() const;
  GcDbObjectId  groupDictionaryId() const;
  GcDbObjectId  layoutDictionaryId() const;
  GcDbObjectId  plotStyleNameDictionaryId() const;
  GcDbObjectId  materialDictionaryId() const;
  GcDbObjectId  visualStyleDictionaryId() const;
  GcDbObjectId  colorDictionaryId() const;
  GcDbObjectId  scaleListDictionaryId() const;
  GcDbObjectId  namedObjectsDictionaryId() const;
  GcDbObjectId  plotSettingsDictionaryId() const;

  template <class TableType> GcDbObjectId getSymbolTableId() const;

  GcDbObjectId layerZero() const;
  GcDbObjectId continuousLinetype() const;
  GcDbObjectId byLayerLinetype() const;
  GcDbObjectId byBlockLinetype() const;
  GcDbObjectId globalMaterial() const;
  GcDbObjectId byLayerMaterial() const;
  GcDbObjectId byBlockMaterial() const;
  GcDbObjectId paperSpaceVportId() const;
  GcDbObjectId currentSpaceId() const;

  Gcad::ErrorStatus reclaimMemoryFromErasedObjects(const GcDbObjectIdArray& erasedObjects);
  Gcad::ErrorStatus purge(GcDbObjectIdArray& ids);
  Gcad::ErrorStatus purge(GcDbObjectIdGraph& idGraph);
  Gcad::ErrorStatus countHardReferences(const GcDbObjectIdArray& ids,
    Gsoft::UInt32* pCount);
  Gcad::ErrorStatus getGcDbObjectId(GcDbObjectId& retId,
    bool createIfNotFound,
    const GcDbHandle& objHandle,
    Gsoft::UInt32 xRefId = 0);
  const GCHAR* classDxfName(const GcRxClass* pClass);
  bool hasClass(const GcRxClass* pClass) const;

  enum OpenMode {
    kForReadAndReadShare = 1,
    kForReadAndWriteNoShare = 2,
    kForReadAndAllShare = 3,
    kTryForReadShare = 4
  };

  Gcad::ErrorStatus readDwgFile(const GCHAR* fileName,
    OpenMode shmode = kForReadAndReadShare,
    bool bAllowCPConversion = false,
    const wchar_t* wszPassword = nullptr);
  Gcad::ErrorStatus readDwgFile(GcDwgFileHandle *pDwgFile,
    bool bAllowCPConversion = false,
    const wchar_t* wszPassword = nullptr);

  bool needsRecovery() const;
  void setFullSaveRequired();

  inline Gcad::ErrorStatus saveAs(const GCHAR* fileName,
    const SecurityParams* pSecParams = 0)
  {
    return saveAs(fileName, true, GcDb::kDHL_CURRENT, pSecParams);
  }

  Gcad::ErrorStatus saveAs(const GCHAR* fileName,
    const bool bBakAndRename,
    const GcDb::GcDbDwgVersion dwgVer = GcDb::kDHL_CURRENT,
    const SecurityParams* pSecParams = 0);
  Gcad::ErrorStatus saveAs(GcDwgFileHandle * pOutputFiler,
    const SecurityParams* pSecParams = 0,
    bool crashing = false);
  Gcad::ErrorStatus save();
  Gcad::ErrorStatus dxfIn(const GCHAR* dxfFilename,
    const GCHAR* logFilename = nullptr);
  Gcad::ErrorStatus dxfIn(IGcReadStream* pInputStream,
    const GCHAR* logFilename = nullptr);
  Gcad::ErrorStatus dxfOut(const GCHAR* fileName,
    int precision = 16,
    GcDb::GcDbDwgVersion dwgVer = GcDb::kDHL_CURRENT,
    bool saveThumbnailImage = false);
  Gcad::ErrorStatus closeInput(bool bCloseFile);

  int approxNumObjects() const;
  Gsoft::Int32 numberOfSaves() const;
  const GCHAR * originalFileName() const;
  GcDb::GcDbDwgVersion lastSavedAsVersion() const;
  GcDb::GcDbDwgVersion originalFileVersion() const;
  GcDb::GcDbDwgVersion originalFileSavedByVersion() const;
  GcDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
  GcDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
  GcDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;

  GcDwgFileHandle * inputFiler() const;
#ifdef _GSOFT_MAC_
  GcDwgFileHandle * outputFiler() const;
#endif

  Gcad::ErrorStatus wblock(GcDbDatabase*& pOutputDb,
    const GcDbObjectIdArray& outObjIds,
    const GcGePoint3d& basePoint);
  Gcad::ErrorStatus wblock(GcDbDatabase* pOutputDb,
    const GcDbObjectIdArray& outObjIds,
    const GcGePoint3d& basePoint,
    GcDb::DuplicateRecordCloning drc);
  Gcad::ErrorStatus wblock(GcDbDatabase*& pOutputDb, GcDbObjectId blockId);
  Gcad::ErrorStatus wblock(GcDbDatabase*& pOutputDb);
  void              forceWblockDatabaseCopy();
  Gcad::ErrorStatus insert(GcDbObjectId& blockId, const GCHAR* pBlockName,
    GcDbDatabase* pDb,
    bool preserveSourceDatabase = true);
  Gcad::ErrorStatus insert(const GcGeMatrix3d& xform, GcDbDatabase* pDb,
    bool preserveSourceDatabase = true);
  Gcad::ErrorStatus insert(GcDbObjectId& blockId,
    const GCHAR* pSourceBlockName,
    const GCHAR* pDestinationBlockName,
    GcDbDatabase* pDb,
    bool preserveSourceDatabase = true);
  Gcad::ErrorStatus deepCloneObjects(const GcDbObjectIdArray& objectIds,
    const GcDbObjectId& owner, GcDbIdMapping& idMap,
    bool deferXlation = false);
  Gcad::ErrorStatus wblockCloneObjects(const GcDbObjectIdArray& objectIds,
    const GcDbObjectId& owner, GcDbIdMapping& idMap,
    GcDb::DuplicateRecordCloning drc,
    bool deferXlation = false);
  void              abortDeepClone(GcDbIdMapping& idMap);
  Gcad::ErrorStatus addReactor(GcDbDatabaseReactor* pReactor) const;
  Gcad::ErrorStatus removeReactor(GcDbDatabaseReactor* pReactor) const;
  Gcad::ErrorStatus auditXData(GcDbAuditInfo* pInfo);
  GcDbUndoController* undoController() const;
  void              disableUndoRecording(bool disable);
  bool              undoRecording() const;

  GcDbTransactionManager* transactionManager() const;
  GcDb::MaintenanceReleaseVersion maintenanceReleaseVersion() const
  {
    return GcDb::kMReleaseCurrent;
  }

  Gcad::ErrorStatus restoreOriginalXrefSymbols();
  Gcad::ErrorStatus restoreForwardingXrefSymbols();
  GcDbObjectId      xrefBlockId() const;
  void*             thumbnailBitmap() const;
  Gcad::ErrorStatus setThumbnailBitmap(void* pBmp);
  Gcad::ErrorStatus thumbnailImage(Gtil::Image*& pPreviewImage) const;
  Gcad::ErrorStatus setThumbnailImage(const Gtil::Image *pPreviewImage);
  bool              retainOriginalThumbnailBitmap() const;
  void              setRetainOriginalThumbnailBitmap(bool retain);

  bool                  setSecurityParams(const SecurityParams* pSecParams, bool bSetDbMod = true);
  const SecurityParams* cloneSecurityParams();
  static void           disposeSecurityParams(const SecurityParams* pSecParams);

  bool dimaso() const;
  Gcad::ErrorStatus setDimaso(bool aso);

  bool dimsho() const;
  Gcad::ErrorStatus setDimsho(bool sho);

  bool plinegen() const;
  Gcad::ErrorStatus setPlinegen(bool gen);

  bool orthomode() const;
  Gcad::ErrorStatus setOrthomode(bool mode);

  bool regenmode() const;
  Gcad::ErrorStatus setRegenmode(bool mode);

  bool fillmode() const;
  Gcad::ErrorStatus setFillmode(bool mode);

  bool qtextmode() const;
  Gcad::ErrorStatus setQtextmode(bool mode);

  bool psltscale() const;
  Gcad::ErrorStatus setPsltscale(bool scale);

  bool limcheck() const;
  Gcad::ErrorStatus setLimcheck(bool check);

  bool blipmode() const;
  Gcad::ErrorStatus setBlipmode(bool mode);

  Gsoft::Int16 saveproxygraphics() const;
  Gcad::ErrorStatus setSaveproxygraphics(Gsoft::Int16 saveimg);

  Gsoft::Int16 delUsedObj() const;
  Gcad::ErrorStatus setDelUsedObj(Gsoft::Int16 deleteObj);

  bool dispSilh() const;
  Gcad::ErrorStatus setDispSilh(bool silh);

  bool plineEllipse() const;
  Gcad::ErrorStatus setPlineEllipse(bool pline);

  bool usrtimer() const;
  Gcad::ErrorStatus setUsrtimer(bool timer);

  bool skpoly() const;
  Gcad::ErrorStatus setSkpoly(bool asPoly);

  bool angdir() const;
  Gcad::ErrorStatus setAngdir(bool dir);

  bool splframe() const;
  Gcad::ErrorStatus setSplframe(bool disp);

  Gsoft::UInt8 xclipFrame() const;
  Gcad::ErrorStatus setXclipFrame(Gsoft::UInt8 disp);

  bool attreq() const;
  Gcad::ErrorStatus setAttreq(bool req);

  bool attdia() const;
  Gcad::ErrorStatus setAttdia(bool dia);

  bool mirrtext() const;
  Gcad::ErrorStatus setMirrtext(bool mirror);

  bool worldview() const;
  Gcad::ErrorStatus setWorldview(bool view);

  bool tilemode() const;
  Gcad::ErrorStatus setTilemode(bool mode);

  bool plimcheck() const;
  Gcad::ErrorStatus setPlimcheck(bool check);

  bool visretain() const;
  Gcad::ErrorStatus setVisretain(bool retain);

  Gsoft::Int16 dragmode() const;
  Gcad::ErrorStatus setDragmode(Gsoft::Int16 mode);

  Gsoft::Int16 treedepth() const;
  Gcad::ErrorStatus setTreedepth(Gsoft::Int16 depth);

  Gsoft::Int16 lunits() const;
  Gcad::ErrorStatus setLunits(Gsoft::Int16 lunits);

  Gsoft::Int16 luprec() const;
  Gcad::ErrorStatus setLuprec(Gsoft::Int16 prec);

  Gsoft::Int16 aunits() const;
  Gcad::ErrorStatus setAunits(Gsoft::Int16 aunits);

  Gsoft::Int16 auprec() const;
  Gcad::ErrorStatus setAuprec(Gsoft::Int16 auprec);

  Gsoft::Int16 attmode() const;
  Gcad::ErrorStatus setAttmode(Gsoft::Int16 mode);

  Gsoft::Int16 coords() const;
  Gcad::ErrorStatus setCoords(Gsoft::Int16 coords);

  Gsoft::Int16 pdmode() const;
  Gcad::ErrorStatus setPdmode(Gsoft::Int16 mode);

  Gsoft::Int16 pickstyle() const;
  Gcad::ErrorStatus setPickstyle(Gsoft::Int16 style);

  Gsoft::Int16 useri1() const;
  Gcad::ErrorStatus setUseri1(Gsoft::Int16 val);

  Gsoft::Int16 useri2() const;
  Gcad::ErrorStatus setUseri2(Gsoft::Int16 val);

  Gsoft::Int16 useri3() const;
  Gcad::ErrorStatus setUseri3(Gsoft::Int16 val);

  Gsoft::Int16 useri4() const;
  Gcad::ErrorStatus setUseri4(Gsoft::Int16 val);

  Gsoft::Int16 useri5() const;
  Gcad::ErrorStatus setUseri5(Gsoft::Int16 val);

  Gsoft::Int16 splinesegs() const;
  Gcad::ErrorStatus setSplinesegs(Gsoft::Int16 segs);

  Gsoft::Int16 surfu() const;
  Gcad::ErrorStatus setSurfu(Gsoft::Int16 u);

  Gsoft::Int16 surfv() const;
  Gcad::ErrorStatus setSurfv(Gsoft::Int16 v);

  Gsoft::Int16 surftype() const;
  Gcad::ErrorStatus setSurftype(Gsoft::Int16 type);

  Gsoft::Int16 surftab1() const;
  Gcad::ErrorStatus setSurftab1(Gsoft::Int16 tab1);

  Gsoft::Int16 surftab2() const;
  Gcad::ErrorStatus setSurftab2(Gsoft::Int16 tab2);

  Gsoft::Int16 splinetype() const;
  Gcad::ErrorStatus setSplinetype(Gsoft::Int16 type);

  Gsoft::Int16 shadedge() const;
  Gcad::ErrorStatus setShadedge(Gsoft::Int16 mode);

  Gsoft::Int16 shadedif() const;
  Gcad::ErrorStatus setShadedif(Gsoft::Int16 dif);

  GcDb::MeasurementValue measurement() const;
  Gcad::ErrorStatus setMeasurement(GcDb::MeasurementValue type);

  Gsoft::Int16 unitmode() const;
  Gcad::ErrorStatus setUnitmode(Gsoft::Int16 mode);

  Gsoft::Int16 maxactvp() const;
  Gcad::ErrorStatus setMaxactvp(Gsoft::Int16 max);

  Gsoft::Int16 isolines() const;
  Gcad::ErrorStatus setIsolines(Gsoft::Int16 isolines);

  Gsoft::UInt8 dwfframe() const;
  Gcad::ErrorStatus setDwfframe(Gsoft::UInt8);

  Gsoft::UInt8 dgnframe() const;
  Gcad::ErrorStatus setDgnframe(Gsoft::UInt8);

  Gsoft::Int8 pdfframe() const;
  Gcad::ErrorStatus setPdfframe(Gsoft::Int8 val);

  double ltscale() const;
  Gcad::ErrorStatus setLtscale(double scale);

  double textsize() const;
  Gcad::ErrorStatus setTextsize(double size);

  double tracewid() const;
  Gcad::ErrorStatus setTracewid(double width);

  double sketchinc() const;
  Gcad::ErrorStatus setSketchinc(double inc);

  double filletrad() const;
  Gcad::ErrorStatus setFilletrad(double radius);

  double thickness() const;
  Gcad::ErrorStatus setThickness(double thickness);

  GcDb::LineWeight  celweight() const;
  Gcad::ErrorStatus setCelweight(GcDb::LineWeight weight);

  static bool       isValidLineWeight(int weight);
  static GcDb::LineWeight getNearestLineWeight(int weight);

  GcDb::EndCaps endCaps() const;
  Gcad::ErrorStatus setEndCaps(GcDb::EndCaps type);

  GcDb::JoinStyle joinStyle() const;
  Gcad::ErrorStatus setJoinStyle(GcDb::JoinStyle style);

  bool lineWeightDisplay() const;
  Gcad::ErrorStatus setLineWeightDisplay(bool display);

  bool xrefEditEnabled() const;
  Gcad::ErrorStatus setXrefEditEnabled(bool enable);

  bool oleStartUp() const;
  Gcad::ErrorStatus setOleStartUp(bool val);

  double angbase() const;
  Gcad::ErrorStatus setAngbase(double angle);

  double pdsize() const;
  Gcad::ErrorStatus setPdsize(double size);

  double plinewid() const;
  Gcad::ErrorStatus setPlinewid(double width);

  double userr1() const;
  Gcad::ErrorStatus setUserr1(double val);

  double userr2() const;
  Gcad::ErrorStatus setUserr2(double val);

  double userr3() const;
  Gcad::ErrorStatus setUserr3(double val);

  double userr4() const;
  Gcad::ErrorStatus setUserr4(double val);

  double userr5() const;
  Gcad::ErrorStatus setUserr5(double val);

  double chamfera() const;
  Gcad::ErrorStatus setChamfera(double val);

  double chamferb() const;
  Gcad::ErrorStatus setChamferb(double val);

  double chamferc() const;
  Gcad::ErrorStatus setChamferc(double val);

  double chamferd() const;
  Gcad::ErrorStatus setChamferd(double val);

  double facetres() const;
  Gcad::ErrorStatus setFacetres(double facetres);

  double get3dDwfPrec() const;
  Gcad::ErrorStatus set3dDwfPrec(double DwfPrec);

  Gcad::ErrorStatus getMenu(GcString & sMenuName) const;
  Gcad::ErrorStatus getMenu(GCHAR*& pOutput) const;

  bool hpInherit() const;
  Gcad::ErrorStatus setHpInherit(const bool inherit);

  GcGePoint2d hpOrigin() const;
  Gcad::ErrorStatus setHpOrigin(const GcGePoint2d& origin);

  const GcDbDate tdcreate() const;
  const GcDbDate tdupdate() const;
  const GcDbDate tducreate() const;
  const GcDbDate tduupdate() const;
  const GcDbDate tdindwg() const;
  const GcDbDate tdusrtimer() const;
  Gcad::ErrorStatus resetTimes();
  GcCmColor cecolor() const;
  Gcad::ErrorStatus setCecolor(const GcCmColor& color);
  GcCmTransparency cetransparency() const;
  Gcad::ErrorStatus setCetransparency(const GcCmTransparency& transparency);

  GcDbHandle handseed() const;
  Gcad::ErrorStatus setHandseed(const GcDbHandle& handle);

  GcDbObjectId clayer() const;
  Gcad::ErrorStatus setClayer(GcDbObjectId objId);

  GcDb::PlotStyleNameType getCePlotStyleNameId(GcDbObjectId& id) const;
  Gcad::ErrorStatus       setCePlotStyleName(GcDb::PlotStyleNameType, GcDbObjectId newId = GcDbObjectId::kNull);

  GcDbObjectId textstyle() const;
  Gcad::ErrorStatus setTextstyle(GcDbObjectId objId);

  GcDbObjectId celtype() const;
  Gcad::ErrorStatus setCeltype(GcDbObjectId objId);

  GcDbObjectId cmaterial() const;
  Gcad::ErrorStatus setCmaterial(GcDbObjectId objId);

  GcDbObjectId dimstyle() const;
  Gcad::ErrorStatus setDimstyle(GcDbObjectId styleId);

  Gcad::ErrorStatus getDimstyleData(GcDbDimStyleTableRecord*& pRec) const;
  Gcad::ErrorStatus getDimstyleChildData(const GcRxClass *pDimClass,
    GcDbDimStyleTableRecord*& pRec,
    GcDbObjectId &style) const;
  GcDbObjectId getDimstyleChildId(const GcRxClass *pDimClass, GcDbObjectId &parentStyle) const;
  GcDbObjectId getDimstyleParentId(GcDbObjectId &childStyle) const;

  Gcad::ErrorStatus setDimstyleData(GcDbDimStyleTableRecord* pRec);
  Gcad::ErrorStatus setDimstyleData(GcDbObjectId id);

  GcDbObjectId cmlstyleID() const;
  Gcad::ErrorStatus setCmlstyleID(GcDbObjectId objId);

  Gsoft::Int16 cmljust() const;
  Gcad::ErrorStatus setCmljust(Gsoft::Int16 just);

  double cmlscale() const;
  Gcad::ErrorStatus setCmlscale(double scale);

  double celtscale() const;
  Gcad::ErrorStatus setCeltscale(double scale);

  GcGePoint3d pinsbase() const;
  Gcad::ErrorStatus setPinsbase(const GcGePoint3d& base);

  GcGePoint3d pextmin() const;
  GcGePoint3d pextmax() const;

  Gcad::ErrorStatus setPextmin(const GcGePoint3d& min);
  Gcad::ErrorStatus setPextmax(const GcGePoint3d& max);

  GcGePoint2d plimmin() const;
  Gcad::ErrorStatus setPlimmin(const GcGePoint2d& min);

  GcGePoint2d plimmax() const;
  Gcad::ErrorStatus setPlimmax(const GcGePoint2d& max);

  double pelevation() const;
  Gcad::ErrorStatus setPelevation(double elev);

  GcGePoint3d pucsorg() const;
  GcGeVector3d pucsxdir() const;
  GcGeVector3d pucsydir() const;
  Gcad::ErrorStatus setPucs(const GcGePoint3d& ucsOrigin,
    const GcGeVector3d& ucsXDir,
    const GcGeVector3d& ucsYDir);
  GcDbObjectId pucsname() const;
  Gcad::ErrorStatus setPucsname(const GcDbObjectId& ucsRecId);
  GcDbObjectId pucsBase() const;
  Gcad::ErrorStatus setPucsBase(const GcDbObjectId &ucsid);

  GcGePoint3d worldPucsBaseOrigin(GcDb::OrthographicView orthoView) const;
  Gcad::ErrorStatus setWorldPucsBaseOrigin(const GcGePoint3d& origin, GcDb::OrthographicView orthoView);

  bool isPucsOrthographic(GcDb::OrthographicView& orthoView) const;
  double cameraHeight() const;
  Gcad::ErrorStatus setCameraHeight(const double cameraHeight);

  double lensLength() const;
  Gcad::ErrorStatus setLensLength(const double lensLength);

  bool cameraDisplay() const;
  Gcad::ErrorStatus setCameraDisplay(const bool cameraDisplay);

  double stepsPerSec() const;
  Gcad::ErrorStatus setStepsPerSec(double stepsPerSec);

  double stepSize() const;
  Gcad::ErrorStatus setStepSize(double stepSize);

  bool realWorldScale() const;
  Gcad::ErrorStatus setRealWorldScale(const bool realWorldScale);

  GcGePoint3d insbase() const;
  Gcad::ErrorStatus setInsbase(const GcGePoint3d& base);

  GcGePoint3d extmin() const;
  GcGePoint3d extmax() const;

  Gcad::ErrorStatus updateExt(bool doBestFit = false);
  Gcad::ErrorStatus setExtmin(const GcGePoint3d& min);
  Gcad::ErrorStatus setExtmax(const GcGePoint3d& max);

  GcGePoint2d limmin() const;
  Gcad::ErrorStatus setLimmin(const GcGePoint2d& min);

  GcGePoint2d limmax() const;
  Gcad::ErrorStatus setLimmax(const GcGePoint2d& max);

  double elevation() const;
  Gcad::ErrorStatus setElevation(double elev);

  GcGePoint3d ucsorg() const;

  GcGeVector3d ucsxdir() const;
  GcGeVector3d ucsydir() const;

  Gcad::ErrorStatus setUcs(const GcGePoint3d& ucsOrigin,
    const GcGeVector3d& ucsXDir,
    const GcGeVector3d& ucsYDir);

  GcDbObjectId ucsname() const;
  Gcad::ErrorStatus setUcsname(const GcDbObjectId& ucsRecId);

  GcDbObjectId ucsBase() const;
  Gcad::ErrorStatus setUcsBase(GcDbObjectId ucsid);

  GcGePoint3d worldUcsBaseOrigin(GcDb::OrthographicView orthoView) const;
  Gcad::ErrorStatus setWorldUcsBaseOrigin(const GcGePoint3d& origin,
    GcDb::OrthographicView orthoView);

  bool isUcsOrthographic(GcDb::OrthographicView& orthoView) const;
  bool isEMR() const;

#undef DBDIMVAR_H                   
#include "dbdimvar.h"

  Gcad::ErrorStatus getDimpost(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimapost(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk1(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk1(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk2(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk2(GCHAR*& pOutput) const;

  int dimfit() const;
  int dimunit() const;

  Gcad::ErrorStatus setDimfit(int fit);
  Gcad::ErrorStatus setDimunit(int unit);
  Gcad::ErrorStatus getDimRecentStyleList(GcDbObjectIdArray& objIds) const;
  Gcad::ErrorStatus loadLineTypeFile(const GCHAR *ltn, const GCHAR *filename);
  Gcad::ErrorStatus getProjectName(GcString & sProjectName) const;
  Gcad::ErrorStatus getProjectName(GCHAR*& pOutput) const;
  Gcad::ErrorStatus setProjectName(const GCHAR*);
  Gcad::ErrorStatus getHyperlinkBase(GcString & sHyperlinkBase) const;
  Gcad::ErrorStatus getHyperlinkBase(GCHAR*& pOutput) const;
  Gcad::ErrorStatus setHyperlinkBase(const GCHAR*);
  Gcad::ErrorStatus getStyleSheet(GcString & sStyleSheet) const;
  Gcad::ErrorStatus getStyleSheet(GCHAR*& pOutput) const;
  Gcad::ErrorStatus setStyleSheet(const GCHAR*);
  Gcad::ErrorStatus getFilename(const GCHAR* & pOutput) const;
  bool              isPartiallyOpened() const;
  Gcad::ErrorStatus applyPartialOpenFilters(
    const GcDbSpatialFilter* pSpatialFilter,
    const GcDbLayerFilter* pLayerFilter);
  void              disablePartialOpen();
  Gcad::ErrorStatus getFingerprintGuid(GcString & guidString) const;
  Gcad::ErrorStatus getFingerprintGuid(GCHAR*& guidString) const;
  Gcad::ErrorStatus setFingerprintGuid(const GCHAR *pNewGuid);
  Gcad::ErrorStatus getVersionGuid(GcString & guidString) const;
  Gcad::ErrorStatus getVersionGuid(GCHAR*& guidString) const;
  Gcad::ErrorStatus setVersionGuid(const GCHAR *pNewGuid);

  int tstackalign() const;
  Gcad::ErrorStatus setTStackAlign(int val);

  int tstacksize() const;
  Gcad::ErrorStatus setTStackSize(int val);

  GcDb::UnitsValue insunits() const;
  Gcad::ErrorStatus setInsunits(const GcDb::UnitsValue units);

  bool           plotStyleMode() const;
  double viewportScaleDefault() const;
  Gcad::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);

  bool           dwgFileWasSavedByGssoftSoftware() const;
  GcDbLayerStateManager *getLayerStateManager() const;
  GcDbObjectContextManager* objectContextManager() const;

  Gsoft::UInt8        sortEnts() const;
  Gcad::ErrorStatus   setSortEnts(Gsoft::UInt8 sortEnts);

  Gsoft::UInt8        drawOrderCtl() const;
  Gcad::ErrorStatus   setDrawOrderCtl(Gsoft::UInt8 val);

  Gsoft::UInt8        dimAssoc() const;
  Gcad::ErrorStatus setDimAssoc(Gsoft::UInt8 val);

  Gsoft::UInt8 hideText() const;
  Gcad::ErrorStatus setHideText(Gsoft::UInt8 val);

  Gsoft::UInt8  haloGap() const;
  Gcad::ErrorStatus setHaloGap(Gsoft::UInt8 val);

  Gsoft::UInt16 obscuredColor() const;
  Gcad::ErrorStatus setObscuredColor(Gsoft::UInt16 val);

  Gsoft::UInt8 obscuredLineType() const;
  Gcad::ErrorStatus setObscuredLineType(Gsoft::UInt8 val);

  Gsoft::UInt8  intersectDisplay() const;
  Gcad::ErrorStatus setIntersectDisplay(Gsoft::UInt8 val);

  Gsoft::UInt16 intersectColor() const;
  Gcad::ErrorStatus setIntersectColor(Gsoft::UInt16 val);
  Gcad::ErrorStatus getTableStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbObjectId tableStyleDictionaryId() const;
  GcDbObjectId tablestyle() const;
  Gcad::ErrorStatus setTablestyle(GcDbObjectId objId);
  Gcad::ErrorStatus getMLeaderStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbObjectId mleaderStyleDictionaryId() const;
  GcDbObjectId mleaderstyle() const;
  Gcad::ErrorStatus setMLeaderstyle(GcDbObjectId objId);
  Gcad::ErrorStatus getDetailViewStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbObjectId detailViewStyleDictionaryId() const;
  GcDbObjectId detailViewStyle() const;
  Gcad::ErrorStatus setDetailViewStyle(GcDbObjectId objId);
  Gcad::ErrorStatus getSectionViewStyleDictionary(GcDbDictionary*& pDict, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbObjectId sectionViewStyleDictionaryId() const;
  GcDbObjectId sectionViewStyle() const;
  Gcad::ErrorStatus setSectionViewStyle(GcDbObjectId objId);
  Gcad::ErrorStatus evaluateFields(int nContext,
    const GCHAR* pszPropName = nullptr,
    GcDbDatabase* pDb = nullptr,
    int* pNumFound = nullptr,
    int* pNumEvaluated = nullptr);
  Gcad::ErrorStatus getViewportArray(GcDbObjectIdArray& vportIds, bool bGetPaperspaceVports = true) const;
  Gcad::ErrorStatus getVisualStyleList(GcArray<const GCHAR*> & vstyleList);

  Gsoft::UInt8  solidHist() const;
  Gcad::ErrorStatus setSolidHist(Gsoft::UInt8 val);

  Gsoft::UInt8  showHist() const;
  Gcad::ErrorStatus setShowHist(Gsoft::UInt8 val);

  double psolWidth() const;
  Gcad::ErrorStatus setPsolWidth(double width);
  double psolHeight() const;
  Gcad::ErrorStatus setPsolHeight(double height);

  Gsoft::UInt16 loftParam() const;
  Gcad::ErrorStatus setLoftParam(Gsoft::UInt16 flags);
  Gsoft::UInt8 loftNormals() const;
  Gcad::ErrorStatus setLoftNormals(Gsoft::UInt8 value);
  double loftAng1() const;
  Gcad::ErrorStatus setLoftAng1(double ang1);
  double loftAng2() const;
  Gcad::ErrorStatus setLoftAng2(double ang2);
  double loftMag1() const;
  Gcad::ErrorStatus setLoftMag1(double mag1);
  double loftMag2() const;
  Gcad::ErrorStatus setLoftMag2(double mag2);

  double latitude() const;
  Gcad::ErrorStatus setLatitude(double lat);
  double longitude() const;
  Gcad::ErrorStatus setLongitude(double lng);
  double northDirection() const;
  Gcad::ErrorStatus setNorthDirection(double northdir);
  GcDb::TimeZone timeZone() const;
  Gcad::ErrorStatus setTimeZone(GcDb::TimeZone tz);
  Gcad::ErrorStatus getTimeZoneInfo(GcDb::TimeZone tz, double& offset, GcString& desc) const;
  Gcad::ErrorStatus setTimeZoneAsUtcOffset(double offset);
  bool geoMarkerVisibility() const;
  Gcad::ErrorStatus setGeoMarkerVisibility(bool value);
  GcString geoCoordinateSystemId() const;

  Gsoft::UInt8 lightGlyphDisplay() const;
  Gcad::ErrorStatus setLightGlyphDisplay(Gsoft::UInt8 val);
  Gsoft::UInt8 tileModeLightSynch() const;
  Gcad::ErrorStatus setTileModeLightSynch(Gsoft::UInt8 val);

  GcCmColor interfereColor() const;
  Gcad::ErrorStatus setInterfereColor(const GcCmColor& color);

  GcDbObjectId interfereObjVisStyle() const;
  Gcad::ErrorStatus setInterfereObjVisStyle(GcDbObjectId id);

  GcDbObjectId interfereVpVisStyle() const;
  Gcad::ErrorStatus setInterfereVpVisStyle(GcDbObjectId id);

  GcDbObjectId dragVisStyle() const;
  Gcad::ErrorStatus setDragVisStyle(GcDbObjectId id);

  Gsoft::UInt8 cshadow() const;
  Gcad::ErrorStatus setCshadow(Gsoft::UInt8 val);

  double shadowPlaneLocation() const;
  Gcad::ErrorStatus setShadowPlaneLocation(double val);

  GcDbAnnotationScale* cannoscale() const;
  Gcad::ErrorStatus setCannoscale(GcDbAnnotationScale*);

  bool annoAllVisible() const;
  Gcad::ErrorStatus setAnnoAllVisible(bool allvis);

  bool annotativeDwg() const;
  Gcad::ErrorStatus setAnnotativeDwg(bool anno);

  bool msltscale() const;
  Gcad::ErrorStatus setMsltscale(bool val);

  Gsoft::UInt8 lightingUnits() const;
  Gcad::ErrorStatus setLightingUnits(Gsoft::UInt8 val);

  bool lightsInBlocks() const;
  Gcad::ErrorStatus setLightsInBlocks(bool val);

  Gsoft::Int16 dxeVal() const;
  Gcad::ErrorStatus setDxeVal(Gsoft::Int16 val);

  double mleaderscale() const;
  Gcad::ErrorStatus setMLeaderscale(double scale);

  Gsoft::Int16 cDynDisplayMode() const;
  Gcad::ErrorStatus setCDynDisplayMode(Gsoft::Int16 val);

  Gsoft::Int16 previewType() const;
  Gcad::ErrorStatus setPreviewType(Gsoft::Int16 val);

  Gsoft::UInt8 indexctl() const;
  Gcad::ErrorStatus setIndexctl(Gsoft::UInt8 val);

  Gsoft::UInt8 layerEval() const;
  Gcad::ErrorStatus setLayerEval(Gsoft::UInt8 val);

  Gsoft::Int16 layerNotify() const;
  Gcad::ErrorStatus setLayerNotify(Gsoft::Int16 val);

  double msOleScale() const;
  Gcad::ErrorStatus setMsOleScale(double val);

  Gsoft::UInt8 updateThumbnail() const;
  Gcad::ErrorStatus setUpdateThumbnail(Gsoft::UInt8 val);

  enum EraseMask {
    kZeroLengthCurve = 0x01,
    kEmptyText = 0x02,
    kAllEmptyObj = 0xFFFFFFFF
  };
  Gsoft::UInt32 eraseEmptyObjects(const Gsoft::UInt32 flags);
  Gsoft::UInt32 countEmptyObjects(const Gsoft::UInt32 flags);

private:
  friend class GcDbSystemInternals;
  GcDbImpDatabase* mpImpDb = nullptr;
  GcDbDatabase(const GcDbDatabase &) = delete;
  GcDbDatabase & operator = (const GcDbDatabase &) = delete;
};

template <class ObjType> inline Gcad::ErrorStatus gcutGetGcStringConvertToGChar(
  const ObjType *pObj,
  Gcad::ErrorStatus(ObjType::*pFunc)(GcString &) const,
  GCHAR*& pOutput)
{
  GcString sOutput;
  const Gcad::ErrorStatus es = (pObj->*pFunc)(sOutput);
  if (es != Gcad::eOk) {
    pOutput = nullptr;
    return es;
  }
  return ::gcutNewString(sOutput.kwszPtr(), pOutput);
}

template <class ObjType> inline GCHAR * gcutGetGcStringConvertToGChar(
  const ObjType *pObj,
  Gcad::ErrorStatus(ObjType::*pFunc)(GcString &) const)
{
  GcString sOutput;
  const Gcad::ErrorStatus es = (pObj->*pFunc)(sOutput);
  GCHAR *pRet = nullptr;
  if (es == Gcad::eOk)
    ::gcutNewString(sOutput.kwszPtr(), pRet);
  return pRet;
}

inline GCHAR * gcutGcStringToGChar(const GcString &s, Gcad::ErrorStatus es)
{
  GCHAR *pBuf = nullptr;
  if (es == Gcad::eOk)
    ::gcutNewString(s.kwszPtr(), pBuf);
  return pBuf;
}
inline Gcad::ErrorStatus gcutGcStringToGChar(const GcString &s, GCHAR * & pBuf,
  Gcad::ErrorStatus es)
{
  pBuf = nullptr;
  if (es != Gcad::eOk)
    return es;
  return ::gcutNewString(s.kwszPtr(), pBuf);
}

inline Gcad::ErrorStatus GcDbDatabase::getDimpost(GCHAR*& pOutput) const
{
  return ::gcutNewString(this->dimpost(), pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getDimapost(GCHAR*& pOutput) const
{
  return ::gcutNewString(this->dimapost(), pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getDimblk(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getDimblk, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getDimblk1(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getDimblk1, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getDimblk2(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getDimblk2, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getMenu(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getMenu, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getProjectName(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getProjectName, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getHyperlinkBase(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getHyperlinkBase, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getStyleSheet(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getStyleSheet, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getFingerprintGuid(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getFingerprintGuid, pOutput);
}
inline Gcad::ErrorStatus GcDbDatabase::getVersionGuid(GCHAR*& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDatabase::getVersionGuid, pOutput);
}

inline Gcad::ErrorStatus gcdbSaveAs2004(GcDbDatabase* pDb,
  const GCHAR* fileName)
{
  return pDb->saveAs(fileName, false, GcDb::kDHL_1800);
}

inline Gcad::ErrorStatus gcdbSaveAs2000(GcDbDatabase* pDb,
  const GCHAR* fileName)
{
  return pDb->saveAs(fileName, false, GcDb::kDHL_1015);
}

inline Gcad::ErrorStatus gcdbSaveAsR14(GcDbDatabase* pDb,
  const GCHAR* fileName)
{
  return pDb->saveAs(fileName, false, GcDb::kDHL_1014);
}

inline Gcad::ErrorStatus gcdbDxfOutAs2004(GcDbDatabase* pDb,
  const GCHAR* fileName,
  const int precision = 16)
{
  return pDb->dxfOut(fileName, precision, GcDb::kDHL_1800);
}

inline Gcad::ErrorStatus gcdbDxfOutAs2000(GcDbDatabase* pDb,
  const GCHAR* fileName,
  const int precision = 16)
{
  return pDb->dxfOut(fileName, precision, GcDb::kDHL_1015);
}

inline Gcad::ErrorStatus gcdbDxfOutAsR12(GcDbDatabase* pDb,
  const GCHAR* fileName,
  const int precision = 16)
{
  return pDb->dxfOut(fileName, precision, GcDb::kDHL_1009);
}

class GCDB_PORT GcDbObjectIterator : public GcRxObject, public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectIterator);
  ~GcDbObjectIterator();

  bool           done() const;
  void           step(bool backwards = false, bool skipDeleted = true);
  void           setPosition(GcDbEntity*  pEnt);
  void           setPosition(GcDbObjectId  pObj);
  void           start(bool atEnd = false);
  GcDbEntity*    entity();
  GcDbObjectId   objectId();

private:
  friend class GcDbSystemInternals;
  GcDbObjectIterator();
  GcDbSpaceIterator* mpImpIterator = nullptr;
};

class GCDB_PORT GSOFT_NO_VTABLE GcDbObject : public GcGiDrawable, public GcHeapOperators
{
public:
  GCDB_DECLARE_MEMBERS(GcDbObject);

  ~GcDbObject();

  GcDbObjectId      objectId() const;
  GcDbObjectId      ownerId() const;
  virtual Gcad::ErrorStatus setOwnerId(GcDbObjectId objId);
  void              getGcDbHandle(GcDbHandle& handle) const;
  GcDbDatabase*     database() const;
  GcDbDatabase*     databaseToUse() const;
  GcDbDatabase*     intendedDatabase() const;
  Gcad::ErrorStatus setIntendedDatabase(GcDbDatabase* pDb);
  Gcad::ErrorStatus createExtensionDictionary();
  GcDbObjectId      extensionDictionary() const;
  Gcad::ErrorStatus releaseExtensionDictionary();
  Gcad::ErrorStatus upgradeOpen();
  Gcad::ErrorStatus upgradeFromNotify(Gsoft::Boolean& wasWritable);
  Gcad::ErrorStatus downgradeOpen();
  Gcad::ErrorStatus downgradeToNotify(Gsoft::Boolean wasWritable);
  virtual Gcad::ErrorStatus subOpen(GcDb::OpenMode mode);
  Gcad::ErrorStatus cancel();
  virtual Gcad::ErrorStatus subCancel();
  Gcad::ErrorStatus close();
  Gcad::ErrorStatus closeAndPage(Gsoft::Boolean onlyWhenClean = true);
  virtual Gcad::ErrorStatus subClose();
  Gcad::ErrorStatus erase(Gsoft::Boolean erasing = true);
  virtual Gcad::ErrorStatus subErase(Gsoft::Boolean erasing);
  Gcad::ErrorStatus handOverTo(GcDbObject* newObject,
    Gsoft::Boolean keepXData = true,
    Gsoft::Boolean keepExtDict = true);
  virtual Gcad::ErrorStatus subHandOverTo(GcDbObject* newObject);
  Gcad::ErrorStatus swapIdWith(GcDbObjectId otherId,
    Gsoft::Boolean swapXdata = false,
    Gsoft::Boolean swapExtDict = false);
  virtual Gcad::ErrorStatus subSwapIdWith(GcDbObjectId otherId,
    Gsoft::Boolean swapXdata = false,
    Gsoft::Boolean swapExtDict = false);
  virtual Gcad::ErrorStatus swapReferences(const GcDbIdMapping& idMap);
  virtual Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo);
  Gcad::ErrorStatus         dwgIn(GcDbDwgFiler* pFiler);
  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus         dwgOut(GcDbDwgFiler* pFiler) const;
  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus         dxfIn(GcDbDxfFiler* pFiler);
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);
  Gcad::ErrorStatus         dxfOut(GcDbDxfFiler* pFiler,
    bool bAllXdata,
    const GcDbObjectIdArray *pRegAppIds) const;
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;
  virtual GcDb::DuplicateRecordCloning mergeStyle() const;
  virtual resbuf*           xData(const GCHAR* regappName = nullptr) const;
  virtual Gcad::ErrorStatus setXData(const resbuf* xdata);
  Gcad::ErrorStatus         xDataTransformBy(const GcGeMatrix3d& xform);
  Gcad::ErrorStatus         setBinaryData(const GCHAR * key,
    Gsoft::Int32 size,
    const char * data);
  Gcad::ErrorStatus         getBinaryData(const GCHAR * key,
    Gsoft::Int32 & size,
    char *&      data) const;

  Gsoft::Boolean isEraseStatusToggled() const;
  Gsoft::Boolean isErased() const;
  Gsoft::Boolean isReadEnabled() const;
  Gsoft::Boolean isWriteEnabled() const;
  Gsoft::Boolean isNotifyEnabled() const;
  Gsoft::Boolean isModified() const;
  Gsoft::Boolean isModifiedXData() const;
  Gsoft::Boolean isModifiedGraphics() const;
  Gsoft::Boolean isNewObject() const;
  Gsoft::Boolean isNotifying() const;
  Gsoft::Boolean isUndoing() const;
  Gsoft::Boolean isCancelling() const;
  Gsoft::Boolean isReallyClosing() const;
  Gsoft::Boolean isTransactionResident() const;
  Gsoft::Boolean isAProxy() const;

  void assertReadEnabled() const;
  void assertWriteEnabled(Gsoft::Boolean autoUndo = true, Gsoft::Boolean recordModified = true);
  void assertNotifyEnabled() const;

  bool                      isUndoRecordingDisabled() const;
  void                      disableUndoRecording(Gsoft::Boolean disable);
  GcDbDwgFiler*             undoFiler();
  virtual Gcad::ErrorStatus applyPartialUndo(GcDbDwgFiler* undoFiler, GcRxClass*    classObj);

  Gcad::ErrorStatus addReactor(GcDbObjectReactor * pReactor) const;
  Gcad::ErrorStatus removeReactor(GcDbObjectReactor * pReactor) const;
  Gcad::ErrorStatus addPersistentReactor(GcDbObjectId objId);
  Gcad::ErrorStatus removePersistentReactor(GcDbObjectId objId);

  bool hasReactor(const GcDbObjectReactor *pReactor) const;
  bool hasPersistentReactor(GcDbObjectId objId) const;

  const GcDbVoidPtrArray * reactors() const;

  virtual void              recvPropagateModify(const GcDbObject* subObj);
  virtual void              xmitPropagateModify() const;

  GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus deepClone(GcDbObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true) const GSOFT_SEALED;
  GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus wblockClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true) const GSOFT_SEALED;

  void              setGcDbObjectIdsInFlux();
  Gsoft::Boolean    isGcDbObjectIdsInFlux() const;

  virtual void cancelled(const GcDbObject* dbObj);
  virtual void copied(const GcDbObject* dbObj, const GcDbObject* newObj);
  virtual void erased(const GcDbObject* dbObj, Gsoft::Boolean bErasing);
  virtual void goodbye(const GcDbObject* dbObj);
  virtual void openedForModify(const GcDbObject* dbObj);
  virtual void modified(const GcDbObject* dbObj);
  virtual void subObjModified(const GcDbObject* dbObj, const GcDbObject* subObj);
  virtual void modifyUndone(const GcDbObject* dbObj);
  virtual void modifiedXData(const GcDbObject* dbObj);
  virtual void unappended(const GcDbObject* dbObj);
  virtual void reappended(const GcDbObject* dbObj);
  virtual void objectClosed(const GcDbObjectId objId);
  virtual void modifiedGraphics(const GcDbEntity* dbEnt);

  GcRxObject*        clone() const override;
  Gcad::ErrorStatus  copyFrom(const GcRxObject* pSrc) override;

  bool       hasSaveVersionOverride();
  void       setHasSaveVersionOverride(bool bSetIt);

  virtual Gcad::ErrorStatus getObjectSaveVersion(const GcDbDwgFiler* pFiler,
    GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer);
  virtual Gcad::ErrorStatus getObjectSaveVersion(const GcDbDxfFiler* pFiler,
    GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer);
  Gcad::ErrorStatus         getObjectBirthVersion(
    GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer);
  virtual Gcad::ErrorStatus   decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj,
    GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData);
  virtual GcGiDrawable*       drawable();

  Gsoft::Boolean      isPersistent() const override;
  GcDbObjectId        id() const override;

  GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   getClassID(CLSID* pClsid) const GSOFT_SEALED;

  bool              hasFields(void) const;
  Gcad::ErrorStatus getField(const GCHAR* pszPropName, GcDbObjectId& fieldId) const;
  Gcad::ErrorStatus getField(const GCHAR* pszPropName, GcDbField*& pField, GcDb::OpenMode mode = GcDb::kForRead) const;
  virtual Gcad::ErrorStatus setField(const GCHAR* pszPropName, GcDbField* pField, GcDbObjectId& fieldId);
  virtual Gcad::ErrorStatus removeField(GcDbObjectId fieldId);
  virtual Gcad::ErrorStatus removeField(const GCHAR* pszPropName, GcDbObjectId& returnId);
  virtual Gcad::ErrorStatus removeField(const GCHAR* pszPropName);
  GcDbObjectId      getFieldDictionary(void) const;
  Gcad::ErrorStatus getFieldDictionary(GcDbDictionary*& pFieldDict, GcDb::OpenMode mode = GcDb::kForRead) const;
protected:
  GcDbObject();

  virtual GcRxObject* subQueryX(const GcRxClass* protocolClass) const;
  Gsoft::UInt32       subSetAttributes(GcGiDrawableTraits* pTraits) override;
  Gsoft::Boolean      subWorldDraw(GcGiWorldDraw* pWd) override;
  void                subViewportDraw(GcGiViewportDraw* pVd) override;
  virtual Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const;
  virtual Gcad::ErrorStatus subDeepClone(GcDbObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true) const;
  virtual Gcad::ErrorStatus subWblockClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary = true) const;

private:
  friend class GcDbPropertiesOverrule;
  friend class GcDbObjectOverrule;
  GcDbImpObject*            mpImpObject = nullptr;

  GcDbObject(const GcDbObject &) = delete;
  GcDbObject & operator = (const GcDbObject &) = delete;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbXObject : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbXObject);

  virtual Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo);
  Gcad::ErrorStatus dwgIn(GcDbDwgFiler* pFiler);
  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus dwgOut(GcDbDwgFiler* pFiler) const;
  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus dxfIn(GcDbDxfFiler* pFiler);
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);
  Gcad::ErrorStatus dxfOut(GcDbDxfFiler* pFiler) const;
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;

protected:
  GcDbXObject();
};

class GCDB_PORT GcCmComplexColor : public  GcDbXObject
{
public:
  GCRX_DECLARE_MEMBERS(GcCmComplexColor);

  virtual GcCmComplexColor* incReference();
  virtual void              decReference();
  virtual Gcad::ErrorStatus getDescription(GcString & desc) const;
  virtual Gcad::ErrorStatus getDescription(GCHAR*& desc) const final;
  virtual Gcad::ErrorStatus getExplanation(GcString & expl) const;
  virtual Gcad::ErrorStatus getExplanation(GCHAR*& expl) const final;
  virtual GcCmEntityColor::ColorMethod  colorMethod() const;
  virtual Gcad::ErrorStatus setColorMethod(GcCmEntityColor::ColorMethod eColorMethod);
  virtual bool              isByColor() const;
  virtual bool              isByLayer() const;
  virtual bool              isByBlock() const;
  virtual bool              isByACI()   const;
  virtual bool              isByPen()  const;
  virtual bool              isForeground()   const;
  virtual Gsoft::UInt32     color() const;
  virtual Gcad::ErrorStatus setColor(Gsoft::UInt32 color);
  virtual Gcad::ErrorStatus setRGB(Gsoft::UInt8 red,
    Gsoft::UInt8 green,
    Gsoft::UInt8 blue);
  virtual Gcad::ErrorStatus setRed(Gsoft::UInt8 red);
  virtual Gcad::ErrorStatus setGreen(Gsoft::UInt8 green);
  virtual Gcad::ErrorStatus setBlue(Gsoft::UInt8 blue);
  virtual Gsoft::UInt8      red() const;
  virtual Gsoft::UInt8      green() const;
  virtual Gsoft::UInt8      blue() const;
  virtual Gsoft::UInt16     colorIndex() const;
  virtual Gcad::ErrorStatus setColorIndex(Gsoft::UInt16 colorIndex);
  virtual Gsoft::UInt16     penIndex() const;
  virtual Gcad::ErrorStatus setPenIndex(Gsoft::UInt16 penIndex);

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo) override;

private:
  Gsoft::UInt16 refCount = 0;
  GcCmEntityColor mColor;
};

inline Gcad::ErrorStatus GcCmComplexColor::getDescription(GCHAR*& desc) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcCmComplexColor::getDescription, desc);
}

inline Gcad::ErrorStatus GcCmComplexColor::getExplanation(GCHAR*& expl) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcCmComplexColor::getExplanation, expl);
}

class GCBASE_PORT GcCmColor : public GcCmColorBase
{
public:
  GcCmColor();
  GcCmColor(const GcCmColor&);
  GcCmColor(const GcCmColorBase&);
  GcCmColor& operator=(const GcCmColor& inputColor);
  GcCmColor& operator=(const GcCmColorBase& inputColor);
  ~GcCmColor();

  bool operator ==(const GcCmColor& color) const;
  bool operator !=(const GcCmColor& color) const;
  bool operator ==(const GcCmColorBase& color) const;
  bool operator !=(const GcCmColorBase& color) const;

  Gcad::ErrorStatus getDescription(GcString & desc) const;
  Gcad::ErrorStatus getDescription(GCHAR*& desc) const;
  Gcad::ErrorStatus getExplanation(GcString & expl) const;
  Gcad::ErrorStatus getExplanation(GCHAR*& expl) const;

  GcCmEntityColor::ColorMethod  colorMethod() const override;
  Gcad::ErrorStatus setColorMethod(GcCmEntityColor::ColorMethod eColorMethod) override;

  bool    isByColor() const override;
  bool    isByLayer() const override;
  bool    isByBlock() const override;
  bool    isByACI()   const override;
  bool    isByPen() const override;
  bool    isForeground()   const override;

  bool              isNone() const;
  Gsoft::UInt32     color() const override;
  Gcad::ErrorStatus setColor(Gsoft::UInt32 color) override;
  Gcad::ErrorStatus setRGB(Gsoft::UInt8 red,
    Gsoft::UInt8 green,
    Gsoft::UInt8 blue) override;
  Gcad::ErrorStatus setRed(Gsoft::UInt8 red) override;
  Gcad::ErrorStatus setGreen(Gsoft::UInt8 green) override;
  Gcad::ErrorStatus setBlue(Gsoft::UInt8 blue) override;
  Gsoft::UInt8      red() const override;
  Gsoft::UInt8      green() const override;
  Gsoft::UInt8      blue() const override;
  Gsoft::UInt16     colorIndex() const override;
  Gcad::ErrorStatus setColorIndex(Gsoft::UInt16 colorIndex) override;
  Gsoft::UInt16     penIndex() const override;
  Gcad::ErrorStatus setPenIndex(Gsoft::UInt16 penIndex) override;
  Gcad::ErrorStatus setNames(const GCHAR *colorName, const GCHAR *bookName = nullptr) override;
  const GCHAR *     colorName(void) const override;
  const GCHAR *     bookName(void) const override;
  const GCHAR *     colorNameForDisplay(void) override;
  bool              hasColorName(void) const override;
  bool              hasBookName(void) const override;

  GcCmEntityColor         entityColor(void) const;
  int                     dictionaryKeyLength(void) const;
  Gcad::ErrorStatus       getDictionaryKey(GcString & sKey) const;
  Gcad::ErrorStatus       getDictionaryKey(GCHAR *pKey, size_t nLen) const;
  Gcad::ErrorStatus       setNamesFromDictionaryKey(const GCHAR *pKey);

  Gcad::ErrorStatus dwgIn(GcDbDwgFiler* pInputFiler);
  Gcad::ErrorStatus dwgOut(GcDbDwgFiler *pOutputFiler) const;
  Gcad::ErrorStatus dxfIn(GcDbDxfFiler* pFiler, int groupCodeOffset = 0);
  Gcad::ErrorStatus dxfOut(GcDbDxfFiler* pFiler, int groupCodeOffset = 0) const;

  Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo);
  Gcad::ErrorStatus serializeOut(void *pBuff, int *pBuflen,
    GcDb::GcDbDwgVersion ver = GcDb::kDHL_CURRENT) const;
  Gcad::ErrorStatus serializeIn(const void *pBuff, int *pBuflen);

  static const Gsoft::UInt16 MaxColorIndex;

  Gcad::ErrorStatus dwgInAsTrueColor(GcDbDwgFiler* pInputFiler);
  Gcad::ErrorStatus dwgOutAsTrueColor(GcDbDwgFiler *pOutputFiler) const;

private:

  enum NameFlags {
    kNoNames = 0x00,
    kHasColorName = 0x01,
    kHasBookName = 0x02
  };

  static const Gsoft::UInt16 ComplexColorFlag;

  GcCmEntityColor::RGBM   mRGBM;
  GcString                msColorName;
  GcString                msBookName;
  Gsoft::UInt8            mNameFlags = 0;
};

inline Gcad::ErrorStatus GcCmColor::getDescription(GCHAR*& desc) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcCmColor::getDescription, desc);
}

inline Gcad::ErrorStatus GcCmColor::getExplanation(GCHAR*& expl) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcCmColor::getExplanation, expl);
}

class GCBASE_PORT GcCmHSB
{
public:
  GcCmHSB();
  GcCmHSB(Gsoft::UInt16 hue, Gsoft::UInt8 saturation, Gsoft::UInt8 brightness);
  GcCmHSB(const GcCmHSB&);
  GcCmHSB& operator=(const GcCmHSB& inputColor);
  virtual ~GcCmHSB();

  bool operator ==(const GcCmHSB& color) const;
  bool operator !=(const GcCmHSB& color) const;

  virtual Gsoft::UInt32     value() const;
  virtual Gcad::ErrorStatus rgbToHSB(Gsoft::UInt8 r, Gsoft::UInt8 g, Gsoft::UInt8 b);
  virtual Gcad::ErrorStatus hsbToRGB(Gsoft::UInt8 *r, Gsoft::UInt8 *g, Gsoft::UInt8 *b);
  virtual Gcad::ErrorStatus setHSB(Gsoft::UInt32 value);
  virtual Gcad::ErrorStatus setHSB(Gsoft::UInt16 hue,
    Gsoft::UInt8 saturation,
    Gsoft::UInt8 brightness);
  virtual Gcad::ErrorStatus setHSB(double hue, double saturation, double brightness);
  virtual Gcad::ErrorStatus setHue(Gsoft::UInt16 hue);
  virtual Gcad::ErrorStatus setHue(double hue);
  virtual Gcad::ErrorStatus setSaturation(Gsoft::UInt8 saturation);
  virtual Gcad::ErrorStatus setSaturation(double saturation);
  virtual Gcad::ErrorStatus setBrightness(Gsoft::UInt8 brightness);
  virtual Gcad::ErrorStatus setBrightness(double brightness);
  virtual Gsoft::UInt16     hue() const;
  virtual Gsoft::UInt8      saturation() const;
  virtual Gsoft::UInt8      brightness() const;

private:
  Gsoft::UInt32           mHSB = 0;
};

GCCORE_PORT Gcad::ErrorStatus gccmGetColorFromACIName(GcCmColor& clr, const GCHAR *pInput);
GCCORE_PORT Gcad::ErrorStatus gccmGetColorFromRGBName(GcCmColor& clr, const GCHAR *pInput);
GCCORE_PORT Gcad::ErrorStatus gccmGetFromHSBName(GcCmHSB& hsb, const GCHAR *pInput);
GCAD_PORT Gcad::ErrorStatus gccmGetColorFromColorBookName(GcCmColor& clr, const GCHAR *pBookName, const GCHAR *pColorName);
GCCORE_PORT void gccmGetLocalizedColorNames(const GCHAR* colors[9]);

class GCDB_PORT GcDbColor : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbColor);
  GcDbColor();
  ~GcDbColor();

  void getColor(GcCmColor& color) const;
  void setColor(const GcCmColor& color);
  const GcCmEntityColor& entityColor(void) const;
  Gcad::ErrorStatus   decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj,
    GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData) override;

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;

private:
  GcCmColor           m_color;
  GcCmEntityColor     m_ecol;

protected:
  Gcad::ErrorStatus subWblockClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap,
    Gsoft::Boolean isPrimary
    = true) const override;
};

class GCDB_PORT GSOFT_NO_VTABLE GcDbEntity : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbEntity);
  ~GcDbEntity();

  GcDbObjectId                blockId() const;
  GcCmColor                   color() const;
  virtual Gcad::ErrorStatus   setColor(const GcCmColor& color, bool doSubents, GcDbDatabase *pDb);
  virtual Gcad::ErrorStatus   setColor(const GcCmColor& color, bool doSubents = true) final;
  Gsoft::UInt16               colorIndex() const;
  virtual Gcad::ErrorStatus   setColorIndex(Gsoft::UInt16 color, Gsoft::Boolean doSubents = true);
  GcCmEntityColor             entityColor() const;
  GcCmTransparency            transparency() const;
  virtual Gcad::ErrorStatus   setTransparency(const GcCmTransparency& trans, Gsoft::Boolean doSubents = true);

  Gcad::ErrorStatus           plotStyleName(GcString &sName) const;
  GCHAR*                      plotStyleName() const;
  GcDb::PlotStyleNameType     getPlotStyleNameId(GcDbObjectId& id) const;
  virtual Gcad::ErrorStatus   setPlotStyleName(const GCHAR* newName, Gsoft::Boolean doSubents = true);
  virtual Gcad::ErrorStatus   setPlotStyleName(GcDb::PlotStyleNameType,
                                               GcDbObjectId newId = GcDbObjectId::kNull,
                                               Gsoft::Boolean doSubents = true);

  Gcad::ErrorStatus           layer(GcString &sName) const;
  GCHAR*                      layer() const;
  GcDbObjectId                layerId() const;
  virtual Gcad::ErrorStatus   setLayer(const GCHAR* newVal,
                                       Gsoft::Boolean doSubents = true,
                                       bool allowHiddenLayer = false);
  virtual Gcad::ErrorStatus   setLayer(GcDbObjectId newVal,
                                       Gsoft::Boolean doSubents = true,
                                       bool allowHiddenLayer = false);
  Gcad::ErrorStatus           linetype(GcString &sName) const;
  GCHAR*                      linetype() const;
  GcDbObjectId                linetypeId() const;
  virtual Gcad::ErrorStatus   setLinetype(const GCHAR* newVal,
                                          Gsoft::Boolean doSubents = true);
  virtual Gcad::ErrorStatus   setLinetype(GcDbObjectId newVal,
                                          Gsoft::Boolean doSubents = true);
  Gcad::ErrorStatus material(GcString &sName) const;
  GCHAR*                      material() const;
  GcDbObjectId                materialId() const;
  virtual Gcad::ErrorStatus   setMaterial(const GCHAR* newVal, Gsoft::Boolean doSubents = true);
  virtual Gcad::ErrorStatus   setMaterial(GcDbObjectId newVal, Gsoft::Boolean doSubents = true);

  enum VisualStyleType {
    kFullVisualStyle,
    kFaceVisualStyle,
    kEdgeVisualStyle
  };

  virtual Gcad::ErrorStatus   setVisualStyle(GcDbObjectId visualStyleId,
                                             VisualStyleType vsType = kFullVisualStyle,
                                             Gsoft::Boolean doSubents = true);
  GcDbObjectId                visualStyleId(VisualStyleType vsType = kFullVisualStyle) const;
  virtual Gcad::ErrorStatus   getMaterialMapper(GcGiMapper& mapper) const;
  virtual Gcad::ErrorStatus   setMaterialMapper(const GcGiMapper& mapper, Gsoft::Boolean doSubents = true);
  double                      linetypeScale() const;
  virtual Gcad::ErrorStatus   setLinetypeScale(double newval,
                                               Gsoft::Boolean doSubents = true);
  GcDb::Visibility            visibility() const;
  GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   setVisibility(GcDb::Visibility newVal,
                                                         Gsoft::Boolean doSubents = true) GSOFT_SEALED;
  GcDb::LineWeight            lineWeight() const;
  virtual Gcad::ErrorStatus   setLineWeight(GcDb::LineWeight newVal,
                                            Gsoft::Boolean doSubents = true);
  virtual GcDb::CollisionType collisionType() const;
  virtual bool                castShadows() const;
  virtual void                setCastShadows(bool newVal);
  virtual bool                receiveShadows() const;
  virtual void                setReceiveShadows(bool newVal);
  Gcad::ErrorStatus           setPropertiesFrom(const GcDbEntity* pEntity,
                                                Gsoft::Boolean doSubents = true);
  virtual Gsoft::Boolean      isPlanar() const { return false; }
  virtual Gcad::ErrorStatus   getPlane(GcGePlane&, GcDb::Planarity&) const
                                    {
 return Gcad::eNotApplicable;
}
virtual void                getEcs(GcGeMatrix3d& retVal) const;

GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getGeomExtents(GcDbExtents& extents) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus addSubentPaths(
  const GcDbFullSubentPathArray& newPaths) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus deleteSubentPaths(
  const GcDbFullSubentPathArray& paths) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL   Gcad::ErrorStatus getSubentClassId(
  const GcDbFullSubentPath& path,
  CLSID*                    clsId) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus transformSubentPathsBy(
  const GcDbFullSubentPathArray& paths,
  const GcGeMatrix3d&            xform) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getGripPointsAtSubentPath(
  const GcDbFullSubentPath&      path,
  GcDbGripDataPtrArray&          grips,
  const double                   curViewUnitSize,
  const int                      gripSize,
  const GcGeVector3d&            curViewDir,
  const int                      bitflags) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus moveGripPointsAtSubentPaths(
  const GcDbFullSubentPathArray& paths,
  const GcDbVoidPtrArray&        gripAppData,
  const GcGeVector3d&            offset,
  const int                      bitflags) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getSubentPathGeomExtents(
  const GcDbFullSubentPath&      path,
  GcDbExtents&                   extents) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getSubentPathsAtGsMarker(
  GcDb::SubentType       type,
  Gsoft::GsMarker        gsMark,
  const GcGePoint3d&     pickPoint,
  const GcGeMatrix3d&    viewXform,
  int&                   numPaths,
  GcDbFullSubentPath*&   subentPaths,
  int                    numInserts = 0,
  GcDbObjectId*          entAndInsertStack
  = nullptr) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getGsMarkersAtSubentPath(
  const GcDbFullSubentPath& subPath,
  GcArray<Gsoft::GsMarker>& gsMarkers) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus highlight(const GcDbFullSubentPath& subId
  = kNullSubent, const Gsoft::Boolean highlightAll
  = false) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus unhighlight(const GcDbFullSubentPath& subId
  = kNullSubent, const Gsoft::Boolean highlightAll
  = false) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL GcDbEntity*       subentPtr(const GcDbFullSubentPath& id) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getOsnapPoints(
  GcDb::OsnapMode     osnapMode,
  Gsoft::GsMarker     gsSelectionMark,
  const GcGePoint3d&  pickPoint,
  const GcGePoint3d&  lastPoint,
  const GcGeMatrix3d& viewXform,
  GcGePoint3dArray&   snapPoints,
  GcDbIntArray &   geomIds) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getOsnapPoints(
  GcDb::OsnapMode     osnapMode,
  Gsoft::GsMarker     gsSelectionMark,
  const GcGePoint3d&  pickPoint,
  const GcGePoint3d&  lastPoint,
  const GcGeMatrix3d& viewXform,
  GcGePoint3dArray&   snapPoints,
  GcDbIntArray &   geomIds,
  const GcGeMatrix3d& insertionMat) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL bool isContentSnappable() const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   getGripPoints(
  GcGePoint3dArray&  gripPoints,
  GcDbIntArray &     osnapModes,
  GcDbIntArray &  geomIds) const GSOFT_SEALED;

GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus moveGripPointsAt(const GcDbIntArray & indices,
  const GcGeVector3d& offset) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   getGripPoints(GcDbGripDataPtrArray& grips,
  const double curViewUnitSize, const int gripSize,
  const GcGeVector3d& curViewDir, const int bitflags) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus moveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
  const GcGeVector3d& offset, const int bitflags) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getStretchPoints(
  GcGePoint3dArray& stretchPoints) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus moveStretchPointsAt(const GcDbIntArray & indices,
  const GcGeVector3d& offset) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus intersectWith(const GcDbEntity* pEnt,
  GcDb::Intersect intType,
  GcGePoint3dArray& points,
  Gsoft::GsMarker thisGsMarker = 0,
  Gsoft::GsMarker otherGsMarker = 0) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus intersectWith(const GcDbEntity* pEnt,
  GcDb::Intersect intType,
  const GcGePlane& projPlane,
  GcGePoint3dArray& points,
  Gsoft::GsMarker thisGsMarker = 0,
  Gsoft::GsMarker otherGsMarker = 0) const GSOFT_SEALED;
Gcad::ErrorStatus          boundingBoxIntersectWith(
  const GcDbEntity*   pEnt,
  GcDb::Intersect     intType,
  GcGePoint3dArray&   points,
  Gsoft::GsMarker     thisGsMarker,
  Gsoft::GsMarker     otherGsMarker) const;
Gcad::ErrorStatus          boundingBoxIntersectWith(
  const GcDbEntity*   pEnt,
  GcDb::Intersect     intType,
  const GcGePlane&    projPlane,
  GcGePoint3dArray&   points,
  Gsoft::GsMarker     thisGsMarker,
  Gsoft::GsMarker     otherGsMarker) const;

GSOFT_SEALED_VIRTUAL void  list() const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   transformBy(const GcGeMatrix3d& xform) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   getTransformedCopy(const GcGeMatrix3d& xform,
  GcDbEntity*& pEnt) const GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   explode(GcDbVoidPtrArray& entitySet) const GSOFT_SEALED;

void                        recordGraphicsModified(
  Gsoft::Boolean setModified = true);
Gcad::ErrorStatus           draw();
virtual void                saveAs(GcGiWorldDraw* mode, GcDb::SaveType st);

GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus   getCompoundObjectTransform(GcGeMatrix3d & xMat) const GSOFT_SEALED;

void                        setDatabaseDefaults();
void                        setDatabaseDefaults(GcDbDatabase* pDb);
virtual void                subSetDatabaseDefaults(GcDbDatabase* pDb);
Gcad::ErrorStatus   applyPartialUndo(GcDbDwgFiler* undoFiler,
  GcRxClass*    classObj) override;
Gcad::ErrorStatus   audit(GcDbAuditInfo* pAuditInfo) override;

Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;

GcGiDrawable*       drawable() override;
bool                bounds(GcDbExtents& bounds) const override;

GSOFT_SEALED_VIRTUAL Gsoft::Boolean  cloneMeForDragging() GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL bool            hideMeForDragging() const GSOFT_SEALED;
virtual void                dragStatus(const GcDb::DragStat status);
GSOFT_SEALED_VIRTUAL void gripStatus(const GcDb::GripStat status) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL void  subentGripStatus(
  const GcDb::GripStat      status,
  const GcDbFullSubentPath& subentity) GSOFT_SEALED;
GSOFT_SEALED_VIRTUAL Gcad::ErrorStatus getGripEntityUCS(const void* pGripAppData,
  GcGeVector3d& normalVec, GcGePoint3d& origin, GcGeVector3d& xAxis) const GSOFT_SEALED;

protected:
  GcDbEntity();

  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
  virtual void                subList() const;
  virtual Gcad::ErrorStatus   subGetOsnapPoints(
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds) const;
  virtual Gcad::ErrorStatus   subGetOsnapPoints(
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds,
    const GcGeMatrix3d& insertionMat) const;
  virtual bool                subIsContentSnappable() const;
  virtual Gcad::ErrorStatus   subTransformBy(const GcGeMatrix3d& xform);
  virtual Gcad::ErrorStatus   subGetTransformedCopy(const GcGeMatrix3d& xform,
    GcDbEntity*& pEnt) const;
  virtual Gcad::ErrorStatus   subExplode(GcDbVoidPtrArray& entitySet) const;
  virtual Gsoft::Boolean      subCloneMeForDragging();
  virtual bool                subHideMeForDragging() const;
  virtual Gcad::ErrorStatus   subGetGripPoints(
    GcGePoint3dArray&  gripPoints,
    GcDbIntArray &     osnapModes,
    GcDbIntArray &  geomIds) const;
  virtual Gcad::ErrorStatus   subGetGripPoints(GcDbGripDataPtrArray& grips,
    const double curViewUnitSize, const int gripSize,
    const GcGeVector3d& curViewDir, const int bitflags) const;
  virtual Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbIntArray & indices,
    const GcGeVector3d& offset);
  virtual Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset, const int bitflags);
  virtual Gcad::ErrorStatus   subGetStretchPoints(
    GcGePoint3dArray& stretchPoints) const;
  virtual Gcad::ErrorStatus   subMoveStretchPointsAt(const GcDbIntArray & indices,
    const GcGeVector3d& offset);
  virtual Gcad::ErrorStatus   subGetGeomExtents(GcDbExtents& extents) const;
  virtual Gcad::ErrorStatus subGetSubentClassId(
    const GcDbFullSubentPath& path,
    CLSID*                    clsId) const;
  virtual  Gcad::ErrorStatus subAddSubentPaths(
    const GcDbFullSubentPathArray& newPaths);
  virtual  Gcad::ErrorStatus subDeleteSubentPaths(
    const GcDbFullSubentPathArray& paths);
  virtual  Gcad::ErrorStatus subTransformSubentPathsBy(
    const GcDbFullSubentPathArray& paths,
    const GcGeMatrix3d&            xform);
  virtual  Gcad::ErrorStatus subGetGripPointsAtSubentPath(
    const GcDbFullSubentPath&      path,
    GcDbGripDataPtrArray&          grips,
    const double                   curViewUnitSize,
    const int                      gripSize,
    const GcGeVector3d&            curViewDir,
    const int                      bitflags) const;
  virtual  Gcad::ErrorStatus subMoveGripPointsAtSubentPaths(
    const GcDbFullSubentPathArray& paths,
    const GcDbVoidPtrArray&        gripAppData,
    const GcGeVector3d&            offset,
    const int                      bitflags);
  virtual  Gcad::ErrorStatus subGetSubentPathGeomExtents(
    const GcDbFullSubentPath&      path,
    GcDbExtents&                   extents) const;
  virtual  Gcad::ErrorStatus subGetSubentPathsAtGsMarker(
    GcDb::SubentType       type,
    Gsoft::GsMarker        gsMark,
    const GcGePoint3d&     pickPoint,
    const GcGeMatrix3d&    viewXform,
    int&                   numPaths,
    GcDbFullSubentPath*&   subentPaths,
    int                    numInserts = 0,
    GcDbObjectId*          entAndInsertStack
    = nullptr) const;
  virtual  Gcad::ErrorStatus subGetGsMarkersAtSubentPath(
    const GcDbFullSubentPath& subPath,
    GcArray<Gsoft::GsMarker>& gsMarkers) const;
  virtual GcDbEntity*        subSubentPtr(const GcDbFullSubentPath& id) const;
  virtual void subGripStatus(const GcDb::GripStat status);
  virtual void               subSubentGripStatus(
    const GcDb::GripStat      status,
    const GcDbFullSubentPath& subentity);
  virtual Gcad::ErrorStatus subHighlight(const GcDbFullSubentPath& subId
    = kNullSubent, const Gsoft::Boolean highlightAll
    = false) const;
  virtual Gcad::ErrorStatus subUnhighlight(const GcDbFullSubentPath& subId
    = kNullSubent, const Gsoft::Boolean highlightAll
    = false) const;
  virtual GcDb::Visibility  subVisibility() const;
  virtual Gcad::ErrorStatus subSetVisibility(GcDb::Visibility newVal,
    Gsoft::Boolean doSubents = true);
  virtual Gcad::ErrorStatus subIntersectWith(const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker = 0,
    Gsoft::GsMarker otherGsMarker = 0) const;
  virtual Gcad::ErrorStatus subIntersectWith(const GcDbEntity* pEnt,
                                             GcDb::Intersect intType,
                                             const GcGePlane& projPlane,
                                             GcGePoint3dArray& points,
                                             Gsoft::GsMarker thisGsMarker = 0,
                                             Gsoft::GsMarker otherGsMarker = 0) const;
  virtual Gcad::ErrorStatus subGetGripEntityUCS(const void* pGripAppData,
                                                GcGeVector3d& normalVec, GcGePoint3d& origin, GcGeVector3d& xAxis) const;
  virtual Gcad::ErrorStatus subGetCompoundObjectTransform(GcGeMatrix3d & xMat) const;

  friend class GcDbPropertiesOverrule;
  friend class GcDbOsnapOverrule;
  friend class GcDbTransformOverrule;
  friend class GcDbGripOverrule;
  friend class GcDbSubentityOverrule;
  friend class GcDbHighlightOverrule;
  friend class GcDbHighlightStateOverrule;
  friend class GcDbVisibilityOverrule;
  friend class GcDbGeometryOverrule;
  friend class GcDbGripEntityOverrule;

public:
  Gcad::ErrorStatus  pushHighlight(const GcDbFullSubentPath& subId,
                                   GcGiHighlightStyle        highlightStyle);
  Gcad::ErrorStatus  popHighlight(const GcDbFullSubentPath& subId);
  GcGiHighlightStyle highlightState(const GcDbFullSubentPath& subId);

protected:
  virtual Gcad::ErrorStatus  subPushHighlight(const GcDbFullSubentPath& subId,
                                              GcGiHighlightStyle        highlightStyle);
  virtual Gcad::ErrorStatus  subPopHighlight(const GcDbFullSubentPath& subId);
  virtual GcGiHighlightStyle subHighlightState(const GcDbFullSubentPath& subId);

  GcDbEntity(const GcDbEntity &) = delete;
  GcDbEntity & operator = (const GcDbEntity &) = delete;
};

inline GcDbEntity::~GcDbEntity()
{
}

inline GCHAR * GcDbEntity::plotStyleName() const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->plotStyleName(sName));
}

inline GCHAR * GcDbEntity::layer() const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->layer(sName));
}

inline GCHAR * GcDbEntity::linetype() const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->linetype(sName));
}

inline GCHAR * GcDbEntity::material() const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->material(sName));
}

class GSOFT_NO_VTABLE GCDB_PORT GcDbObjectReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectReactor);

  virtual void cancelled(const GcDbObject* dbObj);
  virtual void copied(const GcDbObject* dbObj,
                      const GcDbObject* newObj);
  virtual void erased(const GcDbObject* dbObj,
                      Gsoft::Boolean bErasing);
  virtual void goodbye(const GcDbObject* dbObj);
  virtual void openedForModify(const GcDbObject* dbObj);
  virtual void modified(const GcDbObject* dbObj);
  virtual void subObjModified(const GcDbObject* dbObj,
                              const GcDbObject* subObj);
  virtual void modifyUndone(const GcDbObject* dbObj);
  virtual void modifiedXData(const GcDbObject* dbObj);
  virtual void unappended(const GcDbObject* dbObj);
  virtual void reappended(const GcDbObject* dbObj);
  virtual void objectClosed(const GcDbObjectId objId);

protected:
  GcDbObjectReactor();
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbEntityReactor : public GcDbObjectReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcDbEntityReactor);
  virtual void modifiedGraphics(const GcDbEntity* dbObj);
  virtual void dragCloneToBeDeleted(const GcDbEntity* pOriginalObj,
                                    const GcDbEntity* pClone);
protected:
  GcDbEntityReactor();
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbDatabaseReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDatabaseReactor);

  virtual void objectAppended(const GcDbDatabase* dwg, const GcDbObject* dbObj);
  virtual void objectUnAppended(const GcDbDatabase* dwg, const GcDbObject* dbObj);
  virtual void objectReAppended(const GcDbDatabase* dwg, const GcDbObject* dbObj);
  virtual void objectOpenedForModify(const GcDbDatabase* dwg, const GcDbObject* dbObj);
  virtual void objectModified(const GcDbDatabase* dwg, const GcDbObject* dbObj);
  virtual void objectErased(const GcDbDatabase* dwg, const GcDbObject* dbObj,
                            Gsoft::Boolean bErased);
  virtual void headerSysVarWillChange(const GcDbDatabase* dwg, const GCHAR* name);
  virtual void headerSysVarChanged(const GcDbDatabase* dwg, const GCHAR* name,
                                   Gsoft::Boolean bSuccess);
  virtual void proxyResurrectionCompleted(const GcDbDatabase* dwg,
                                          const GCHAR* appname,
                                          GcDbObjectIdArray& objects);
  virtual void goodbye(const GcDbDatabase* dwg);
};

class GCDB_PORT GcDbExtents2d : public GcHeapOperators
{
public:
  GcDbExtents2d();
  GcDbExtents2d(const GcDbExtents2d& src);
  GcDbExtents2d(const GcGePoint2d& min, const GcGePoint2d& max);

  GcGePoint2d       minPoint() const { return mMinPoint; }
  GcGePoint2d       maxPoint() const { return mMaxPoint; }
  Gcad::ErrorStatus set(const GcGePoint2d& min, const GcGePoint2d& max);
  void              addPoint(const GcGePoint2d& pt);
  void              addExt(const GcDbExtents2d& src);
  void              expandBy(const GcGeVector2d& vec);
  void              transformBy(const GcGeMatrix2d& mat);
  bool              operator==(const GcDbExtents2d& other);

private:
  GcGePoint2d    mMinPoint;
  GcGePoint2d    mMaxPoint;
};

class GCDB_PORT GcDbExtents : public GcHeapOperators
{
public:
  GcDbExtents();
  GcDbExtents(const GcDbExtents& src);
  GcDbExtents(const GcGePoint3d& min, const GcGePoint3d& max);

  GcGePoint3d       minPoint() const { return mMinPoint; }
  GcGePoint3d       maxPoint() const { return mMaxPoint; }
  Gcad::ErrorStatus set(const GcGePoint3d& min, const GcGePoint3d& max);
  void              addPoint(const GcGePoint3d& pt);
  void              addExt(const GcDbExtents& src);
  Gcad::ErrorStatus addBlockExt(GcDbBlockTableRecord* pBTR);
  void              expandBy(const GcGeVector3d& vec);
  void              transformBy(const GcGeMatrix3d& mat);
  bool              operator==(const GcDbExtents& other);

private:
  GcGePoint3d    mMinPoint;
  GcGePoint3d    mMaxPoint;
};

template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbBlockTable>() const
{
  return this->blockTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbLayerTable>() const
{
  return this->layerTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbTextStyleTable>() const
{
  return this->textStyleTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbLinetypeTable>() const
{
  return this->linetypeTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbViewTable>() const
{
  return this->viewTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbUCSTable>() const
{
  return this->UCSTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbViewportTable>() const
{
  return this->viewportTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbRegAppTable>() const
{
  return this->regAppTableId();
}
template <> inline GcDbObjectId GcDbDatabase::getSymbolTableId<GcDbDimStyleTable>() const
{
  return this->dimStyleTableId();
}

inline Gcad::ErrorStatus
GcDbDatabase::getBlockTable(
  GcDbBlockTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getLayerTable(
  GcDbLayerTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getTextStyleTable(
  GcDbTextStyleTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getLinetypeTable(
  GcDbLinetypeTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getViewTable(
  GcDbViewTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getUCSTable(
  GcDbUCSTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getViewportTable(
  GcDbViewportTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getRegAppTable(
  GcDbRegAppTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

inline Gcad::ErrorStatus
GcDbDatabase::getDimStyleTable(
  GcDbDimStyleTable*& pTable,
  GcDb::OpenMode mode)
{
  return getSymbolTable(pTable, mode);
}

#define GC_SRCH_BLOCK         0x01
#define GC_SRCH_DIM_TEXT      0x02
#define GC_SRCH_TEXT          0x04
#define GC_SRCH_LINK_DESC     0x08
#define GC_SRCH_LINK_URL      0x10
#define GC_SRCH_MATCH_CASE    0x20
#define GC_SRCH_WHOLE_WORD    0x40

#define GC_SRCH_DEFAULT       0x1F

GCCORE_PORT bool gcdbTextFind(GcDbDatabase* pDatabase,
  GcDbObjectIdArray& resultSet,
  const GCHAR* findString,
  const GCHAR* replaceString = nullptr,
  Gsoft::UInt8 searchOptions = GC_SRCH_DEFAULT,
  const GcDbObjectIdArray& selSet = 0);

#pragma pack(pop)

#endif