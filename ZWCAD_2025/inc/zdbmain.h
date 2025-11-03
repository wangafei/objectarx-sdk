
#ifndef ZD_DBMAIN_H
#define ZD_DBMAIN_H

#include <stddef.h>
#include "zadesk.h"	
#include "zgepnt2d.h"
#include "zgepnt3d.h"
#include "zAcHeapOpers.h"
#include "zrxobject.h"
#include "zrxdlinkr.h"
#include "zrxiter.h"
#include "zrxditer.h"
#include "zrxsrvice.h"
#include "zdbboiler.h"
#include "zdbptrar.h"
#include "zdbcolor.h"
#include "zdbidar.h"
#include "zdrawable.h"
#include "zdbsecurity.h"
#include "zAcString.h"
#include "zdbObject.h"
#include "zacutAcString.h"
#include "zAcCmColor.h"

class ZcCmEntityColor;
class ZcDbBlockBegin;
class ZcDbBlockEnd;
class ZcDbDatabase;
class ZcDbDatabaseIterator;
class ZcDbDatabaseReactor;
class ZcDbEntity;
class ZcDbEntityReactor;
class ZcDbImpDatabase;
class ZcDbImpObject;
class ZcDbObjectReactor;
class ZcDbSpaceIterator;
class ZcDbSystemInternals;
class ZcDbXObject;
class ZcDbBlockReference;
class ZcDbSymbolTable;
class ZcDbBlockTable;
class ZcDbBlockTableRecord;    
class ZcDbLayerTable;
class ZcDbTextStyleTable;
class ZcDbLinetypeTable;
class ZcDbAbstractViewTable;
class ZcDbViewTable;
class ZcDbUCSTable;
class ZcDbViewportTable;
class ZcDbRegAppTable;
class ZcDbDimStyleTable;
class ZcDbDimStyleTableRecord;
class ZcDbIdMapping;
class ZcDbDictionary;
class ZcDbDictionaryWithDefault;
class ZcDbMline;
class ZcDbMlineStyle;
class ZcDbCurve;
class ZcDbEllipse;
class ZcDbSpline;
class ZcDbRegion;
class ZcDb3dSolid;
class ZcDbBody;
class ZcDbDate;
class ZcDbExtents;
class ZcDbAuditInfo;
class ZcDbUndoController;
class ZcDbTransactionManager;
class ZcDbSpatialFilter;
class ZcDbLayerFilter;
class ZcGeMatrix2d;
class ZcGeVector3d;
class ZcGsNode;
class ZcGsModel;
class ZcGiContext;
class ZcDbObjectIdGraph;
class ZcDbLayerStateManager;
class ZcDwgFileHandle;
class ZcFileDependencyManager;
class ZcDbTableStyle;
class ZcFdFieldValue;
class ZcDbField;
class ZcDbSectionManager;
class ZcDbDataLinkManager;
class ZcGiMapper;
class ZcDbAnnotationScale;
class IZcReadStream;
class IZcWriteStream;

enum class code_page_id : int;

namespace Ztil 
{
	class Image; 
}

#include "zacdb.h"
#include "zdbhandle.h"
#include "zdbfiler.h"
#include "zads_db.h"
#include "zgept3dar.h"
#include "zdbintar.h"
#include "zdbsubeid.h"
#include "zdbaudita.h"
#include "zacgidefs.h"
#include "zAcArray.h"
#include "ZRXExports.h"

#pragma pack(push, 8)

class ZcLocale;

struct _GUID;
typedef struct _GUID CLSID;

class ZcDbGripData;
typedef ZcArray<ZcDbGripData*, ZcArrayMemCopyReallocator<ZcDbGripData*>> ZcDbGripDataPtrArray;
typedef ZcArray<ZcDbFullSubentPath,
        ZcArrayObjectCopyReallocator<ZcDbFullSubentPath> > ZcDbFullSubentPathArray;

ZRX_DB_EXPORT_GLOBAL extern const ZcDbFullSubentPath kNullSubent;

ZcDb::DwgDataType zcdbGroupCodeToType(ZcDb::DxfCode pCode);

void              zcdbFreeResBufContents(resbuf* pField);

ZCDBCORE2D_PORT ZcDbObjectId  zcdbPersistentReactorObjectId(const void *pSomething);	
ZCDBCORE2D_PORT bool              zcdbIsPersistentReactor(const void *pSomething);


ZCDB_PORT bool   zcdbDisplayPreviewFromDwg(const ZTCHAR *pszDwgfilename,
                                 void* pPreviewWnd,
                                 const ZSoft::UInt32* pBgColor = nullptr);

bool zcdbIsCustomObject(const ZcDbObjectId& id);

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbOpenObject(ZcDbEntity *& pEnt,
	ZcDbObjectId id, ZcDb::OpenMode mode = ZcDb::kForRead, bool openErased = false);

Zcad::ErrorStatus ZSOFT_STDCALL
	zcdbOpenZcDbObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
	const ZcRxClass *pClass, bool openErasedObject = false);

inline Zcad::ErrorStatus
zcdbOpenZcDbEntity(ZcDbEntity*& pEnt, ZcDbObjectId id, ZcDb::OpenMode mode,
	bool openErasedEntity = false)
{
	return ::zcdbOpenObject(pEnt, id, mode, openErasedEntity);
}


Zcad::ErrorStatus zcdbResurrectMeNow(const ZcDbObjectId& id);

Zcad::ErrorStatus zcdbGetZdsName(zds_name&  objName, ZcDbObjectId objId);
Zcad::ErrorStatus zcdbGetObjectId(ZcDbObjectId& objId,
                                         const zds_name objName);

Zcad::ErrorStatus zcdbValKey(const zds_name name);
Zcad::ErrorStatus zcdbSetReferenced(ZcDbObjectId objId);

ZCDBCORE2D_PORT const ZcArray<ZcDbDatabase *> & zcdbActiveDatabaseArray();

class ZcDbViewTableRecord;
class ZcDbViewport;
class ZcDbObjectContextManager;

Zcad::ErrorStatus zcdbLoadMlineStyleFile(
                const ZTCHAR *sname, const ZTCHAR *fname);

Zcad::ErrorStatus zcdbLoadLineTypeFile(const ZTCHAR *ltname,
                                       const ZTCHAR *fname,
                                       ZcDbDatabase *pDb);

void* zcdbAlloc(size_t);
void* zcdbRealloc(void *, size_t);
void  zcdbFree(void*);

ZCDB_PORT void zcdbInitialize();
ZCDB_PORT void zcdbTerminate();


ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbValidateSetup(const ZcLocale& loc); 
	

Zcad::ErrorStatus zcdbCleanUp();

const ZTCHAR* zcdbOriginalXrefFullPathFor(const ZcDbDatabase*);

ZcGiContext * zcdbSetDefaultZcGiContext(ZcGiContext *);

int zcdbSetDbmod(ZcDbDatabase* pDatabase, int iNewVal);

Zcad::ErrorStatus zcdbGetThumbnailBitmapFromDxfFile(const ZTCHAR* filename, void*& pBitmap);

class ZCDBCORE2D_PORT ZcDbDatabase: public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabase);

    ZcDbDatabase(bool buildDefaultDrawing = true,
                 bool noDocument = false);
    virtual ~ZcDbDatabase();
	bool isBeingDestroyed() const;	

    Zcad::ErrorStatus addZcDbObject(ZcDbObjectId&  objId,ZcDbObject*    pObj);
	Zcad::ErrorStatus addZcDbObject(ZcDbObject*    pObj);

    static Zcad::ErrorStatus markObjectNonPersistent(ZcDbObjectId id, bool value);
    static bool isObjectNonPersistent(ZcDbObjectId id);

    Zcad::ErrorStatus getBlockTable     (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getLayerTable     (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getTextStyleTable (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getLinetypeTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getViewTable      (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getUCSTable       (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getViewportTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getRegAppTable    (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getDimStyleTable  (ZcDbSymbolTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);

    Zcad::ErrorStatus getSymbolTable    (ZcDbBlockTable*&     pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbLayerTable*&     pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbTextStyleTable*& pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbLinetypeTable*&  pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbViewTable*&      pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbUCSTable*&       pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbViewportTable*&  pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbRegAppTable*&    pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);
    Zcad::ErrorStatus getSymbolTable    (ZcDbDimStyleTable*&  pTable,
                                         ZcDb::OpenMode       mode = ZcDb::kForRead);

    Zcad::ErrorStatus getGroupDictionary   (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getMLStyleDictionary (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getLayoutDictionary  (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getPlotStyleNameDictionary(
                                            ZcDbDictionaryWithDefault*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getMaterialDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getVisualStyleDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    Zcad::ErrorStatus getColorDictionary   (ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
	
	Zcad::ErrorStatus getScaleListDictionary(ZcDbDictionary*& pDict,
											ZcDb::OpenMode mode = ZcDb::kForRead);
	
    Zcad::ErrorStatus getNamedObjectsDictionary(
                                            ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);

    Zcad::ErrorStatus getBlockTable     (ZcDbBlockTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getLayerTable     (ZcDbLayerTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getTextStyleTable (ZcDbTextStyleTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getLinetypeTable  (ZcDbLinetypeTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getViewTable      (ZcDbViewTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getUCSTable       (ZcDbUCSTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getViewportTable  (ZcDbViewportTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getRegAppTable    (ZcDbRegAppTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getDimStyleTable  (ZcDbDimStyleTable*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    Zcad::ErrorStatus getPlotSettingsDictionary(ZcDbDictionary*& pTable,
                                         ZcDb::OpenMode    mode = ZcDb::kForRead);
    ZcDbObjectId      getSectionManager (void) const;
    Zcad::ErrorStatus getSectionManager (ZcDbSectionManager*& pMgr,
                                         ZcDb::OpenMode mode = ZcDb::kForRead) const;
    ZcDbObjectId    dataLinkDictionaryId(void) const;
    Zcad::ErrorStatus getDataLinkDictionary(ZcDbDictionary*& pDict,
                                            ZcDb::OpenMode mode = ZcDb::kForRead);
    ZcDbDataLinkManager*getDataLinkManager(void) const;
    Zcad::ErrorStatus updateDataLink    (ZcDb::UpdateDirection nDir,
                                         ZcDb::UpdateOption nOption);
    ZcDbObjectId  blockTableId() const;
    ZcDbObjectId  layerTableId() const;
    ZcDbObjectId  textStyleTableId() const;
    ZcDbObjectId  linetypeTableId() const;
    ZcDbObjectId  viewTableId() const;
    ZcDbObjectId  UCSTableId() const;
    ZcDbObjectId  viewportTableId() const;
    ZcDbObjectId  regAppTableId() const;
    ZcDbObjectId  dimStyleTableId() const;
    ZcDbObjectId  mLStyleDictionaryId() const;
    ZcDbObjectId  groupDictionaryId() const;
    ZcDbObjectId  layoutDictionaryId() const;
    ZcDbObjectId  plotStyleNameDictionaryId() const;
    ZcDbObjectId  materialDictionaryId() const;
    ZcDbObjectId  visualStyleDictionaryId() const;
    ZcDbObjectId  colorDictionaryId() const;
    ZcDbObjectId  scaleListDictionaryId() const;
    ZcDbObjectId  namedObjectsDictionaryId() const;
    ZcDbObjectId  plotSettingsDictionaryId() const;

	template <class TableType> ZcDbObjectId getSymbolTableId() const;	

    ZcDbObjectId layerZero() const;
    ZcDbObjectId continuousLinetype() const;
    ZcDbObjectId byLayerLinetype() const;
    ZcDbObjectId byBlockLinetype() const;

    ZcDbObjectId globalMaterial() const;
    ZcDbObjectId byLayerMaterial() const;
    ZcDbObjectId byBlockMaterial() const;

    ZcDbObjectId paperSpaceVportId() const;
    ZcDbObjectId currentSpaceId() const;

	Zcad::ErrorStatus reclaimMemoryFromErasedObjects(const ZcDbObjectIdArray& erasedObjects); 

    Zcad::ErrorStatus purge(ZcDbObjectIdArray& ids);
    Zcad::ErrorStatus purge(ZcDbObjectIdGraph& idGraph);
    Zcad::ErrorStatus countHardReferences(const ZcDbObjectIdArray& ids,
                                          ZSoft::UInt32* pCount);

    Zcad::ErrorStatus getZcDbObjectId(ZcDbObjectId& retId,
                                      bool createIfNotFound,
                                      const ZcDbHandle& objHandle,
                                      ZSoft::UInt32 xRefId = 0);

    const ZTCHAR* classDxfName(const ZcRxClass* pClass);

	bool hasClass(const ZcRxClass* pClass) const;	

	enum OpenMode {
		kForReadAndReadShare =    1, 
		kForReadAndWriteNoShare = 2, 
		kForReadAndAllShare =     3, 
		kTryForReadShare =        4 
	};
	Zcad::ErrorStatus readDwgFile(const ZTCHAR* fileName,
		OpenMode openmode = kForReadAndReadShare,
		bool bAllowCPConversion = false,
		const wchar_t* wszPassword = nullptr);
    Zcad::ErrorStatus readDwgFile(const ZTCHAR* fileName,
                                  const int shmode/* = _SH_DENYWR*/,	
                                  bool bAllowCPConversion = false,
                                  const wchar_t* wszPassword = nullptr);		 
    Zcad::ErrorStatus readDwgFile(ZcDwgFileHandle *pDwgFile,
                                  bool bAllowCPConversion = false,
                                  const wchar_t* wszPassword = nullptr);

	bool needsRecovery() const;		
    void           setFullSaveRequired();
	inline Zcad::ErrorStatus saveAs(const ZTCHAR* fileName,
									const SecurityParams* pSecParams = 0)
	{
		return saveAs(fileName, true, ZcDb::kDHL_CURRENT, pSecParams);
	}

	Zcad::ErrorStatus saveAs(const ZTCHAR* fileName,
							 const bool bBakAndRename,
							 const ZcDb::ZcDbDwgVersion dwgVer = ZcDb::kDHL_CURRENT,
							 const SecurityParams* pSecParams = 0);
	Zcad::ErrorStatus saveAs(ZcDwgFileHandle * pOutputFiler,
		const SecurityParams* pSecParams = 0,
		bool crashing = false);	

    Zcad::ErrorStatus save();
    Zcad::ErrorStatus dxfIn(const ZTCHAR* dxfFilename,
                            const ZTCHAR* logFilename=nullptr);
	Zcad::ErrorStatus dxfIn(IZcReadStream* pInputStream,
		const ZTCHAR* logFilename=nullptr);	

	Zcad::ErrorStatus dxfOut(const ZTCHAR* fileName,
							int precision = 16,
							ZcDb::ZcDbDwgVersion dwgVer = ZcDb::kDHL_CURRENT,
							bool saveThumbnailImage = false);

	Zcad::ErrorStatus dxfOutEx(const ZTCHAR* fileName,
		int precision = 16,
		ZcDb::ZcDbDwgVersion dwgVer = ZcDb::kDHL_CURRENT,
		int nFlags = 0,
		code_page_id nCodePage = static_cast<code_page_id>(0));


	Zcad::ErrorStatus closeInput(bool bCloseFile = false);

    int approxNumObjects() const;
    ZSoft::Int32 numberOfSaves() const;
    const ZTCHAR * originalFileName() const;
    ZcDb::ZcDbDwgVersion lastSavedAsVersion() const;
    ZcDb::ZcDbDwgVersion originalFileVersion() const;
    ZcDb::ZcDbDwgVersion originalFileSavedByVersion() const;
    ZcDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
    ZcDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
    ZcDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;

    ZcDwgFileHandle * inputFiler() const;
	
#ifdef _ZSOFT_MAC_		
	ZcDwgFileHandle * outputFiler() const;
#endif
	

    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb,
                             const ZcDbObjectIdArray& outObjIds,
                             const ZcGePoint3d& basePoint);

    Zcad::ErrorStatus wblock(ZcDbDatabase* pOutputDb,  
                             const ZcDbObjectIdArray& outObjIds,
                             const ZcGePoint3d& basePoint,
                             ZcDb::DuplicateRecordCloning drc);  

    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb, ZcDbObjectId blockId);
    Zcad::ErrorStatus wblock(ZcDbDatabase*& pOutputDb);

    void              forceWblockDatabaseCopy();

    Zcad::ErrorStatus insert(ZcDbObjectId& blockId, const ZTCHAR* pBlockName,
        ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus insert(const ZcGeMatrix3d& xform, ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus insert(ZcDbObjectId& blockId, 
        const ZTCHAR* pSourceBlockName,
        const ZTCHAR* pDestinationBlockName,
        ZcDbDatabase* pDb,
        bool preserveSourceDatabase = true);

    Zcad::ErrorStatus deepCloneObjects(const ZcDbObjectIdArray& objectIds,
        const ZcDbObjectId& owner, ZcDbIdMapping& idMap,
        bool deferXlation = false);		
       
    Zcad::ErrorStatus wblockCloneObjects(const ZcDbObjectIdArray& objectIds,
        const ZcDbObjectId& owner, ZcDbIdMapping& idMap,
        ZcDb::DuplicateRecordCloning drc,
        bool deferXlation = false);		

    void              abortDeepClone(ZcDbIdMapping& idMap);

   Zcad::ErrorStatus              addReactor(ZcDbDatabaseReactor* pReactor) const;	

   Zcad::ErrorStatus              removeReactor(ZcDbDatabaseReactor* pReactor) const;	

   Zcad::ErrorStatus registerApp(const wchar_t *pszAppName);

   bool isAppRegistered(const wchar_t *pszAppName) const;

    Zcad::ErrorStatus auditXData(ZcDbAuditInfo* pInfo);

    ZcDbUndoController* undoController() const;
    void              disableUndoRecording(bool disable);
    bool              undoRecording() const ;

    ZcDbTransactionManager* transactionManager() const;

    ZcFileDependencyManager* fileDependencyManager() const;	

    ZcDb::MaintenanceReleaseVersion      maintenanceReleaseVersion() const	
	{
		return ZcDb::kMReleaseCurrent;	
	}

    Zcad::ErrorStatus restoreOriginalXrefSymbols();
    Zcad::ErrorStatus restoreForwardingXrefSymbols();

    ZcDbObjectId      xrefBlockId() const;
	
    void*             thumbnailBitmap() const;
    Zcad::ErrorStatus setThumbnailBitmap(void* pBmp);
	Zcad::ErrorStatus thumbnailImage(Ztil::Image*& pPreviewImage) const;	

	Zcad::ErrorStatus setThumbnailImage(const Ztil::Image *pPreviewImage);	

    bool              retainOriginalThumbnailBitmap() const;
    void              setRetainOriginalThumbnailBitmap(bool retain);

    bool                  setSecurityParams(const SecurityParams* pSecParams,
                                            bool bSetDbMod = true);
    const SecurityParams* cloneSecurityParams();
    static void           disposeSecurityParams(const SecurityParams* pSecParams);

    bool dimaso() const;
    Zcad::ErrorStatus setDimaso(bool aso);

    bool dimsho() const;
    Zcad::ErrorStatus setDimsho(bool sho);

    bool plinegen() const;
    Zcad::ErrorStatus setPlinegen(bool gen);

    bool orthomode() const;
    Zcad::ErrorStatus setOrthomode(bool mode);

    bool regenmode() const;
    Zcad::ErrorStatus setRegenmode(bool mode);

    bool fillmode() const;
    Zcad::ErrorStatus setFillmode(bool mode);

    bool qtextmode() const;
    Zcad::ErrorStatus setQtextmode(bool mode);

    bool psltscale() const;
    Zcad::ErrorStatus setPsltscale(bool scale);

    bool limcheck() const;
    Zcad::ErrorStatus setLimcheck(bool check);

    bool blipmode() const;
    Zcad::ErrorStatus setBlipmode(bool mode);

    ZSoft::Int16 saveproxygraphics() const;
    Zcad::ErrorStatus setSaveproxygraphics(ZSoft::Int16 saveimg);

    ZSoft::Int16 delUsedObj() const;
    Zcad::ErrorStatus setDelUsedObj(ZSoft::Int16 deleteObj);

    bool dispSilh() const;
    Zcad::ErrorStatus setDispSilh(bool silh);

    bool plineEllipse() const;
    Zcad::ErrorStatus setPlineEllipse(bool pline);

    bool usrtimer() const;
    Zcad::ErrorStatus setUsrtimer(bool timer);

    bool skpoly() const;
    Zcad::ErrorStatus setSkpoly(bool asPoly);

    bool angdir() const;
    Zcad::ErrorStatus setAngdir(bool dir);

    bool splframe() const;
    Zcad::ErrorStatus setSplframe(bool disp);

    ZSoft::UInt8 xclipFrame() const;
    Zcad::ErrorStatus setXclipFrame(ZSoft::UInt8 disp);

    bool attreq() const;
    Zcad::ErrorStatus setAttreq(bool req);

    bool attdia() const;
    Zcad::ErrorStatus setAttdia(bool dia);

    bool mirrtext() const;
    Zcad::ErrorStatus setMirrtext(bool mirror);

    bool worldview() const;
    Zcad::ErrorStatus setWorldview(bool view);

    bool tilemode() const;
    Zcad::ErrorStatus setTilemode(bool mode);

    bool plimcheck() const;
    Zcad::ErrorStatus setPlimcheck(bool check);

    bool visretain() const;
    Zcad::ErrorStatus setVisretain(bool retain);

    ZSoft::Int16 dragmode() const;
    Zcad::ErrorStatus setDragmode(ZSoft::Int16 mode);

    ZSoft::Int16 treedepth() const;
    Zcad::ErrorStatus setTreedepth(ZSoft::Int16 depth);

    ZSoft::Int16 lunits() const;
    Zcad::ErrorStatus setLunits(ZSoft::Int16 lunits);

    ZSoft::Int16 luprec() const;
    Zcad::ErrorStatus setLuprec(ZSoft::Int16 prec);

    ZSoft::Int16 aunits() const;
    Zcad::ErrorStatus setAunits(ZSoft::Int16 aunits);

    ZSoft::Int16 auprec() const;
    Zcad::ErrorStatus setAuprec(ZSoft::Int16 auprec);

    ZSoft::Int16 attmode() const;
    Zcad::ErrorStatus setAttmode(ZSoft::Int16 mode);

    ZSoft::Int16 coords() const;
    Zcad::ErrorStatus setCoords(ZSoft::Int16 coords);

    ZSoft::Int16 pdmode() const;
    Zcad::ErrorStatus setPdmode(ZSoft::Int16 mode);

    ZSoft::Int16 pickstyle() const;
    Zcad::ErrorStatus setPickstyle(ZSoft::Int16 style);

    ZSoft::Int16 useri1() const;
    Zcad::ErrorStatus setUseri1(ZSoft::Int16 val);

    ZSoft::Int16 useri2() const;
    Zcad::ErrorStatus setUseri2(ZSoft::Int16 val);

    ZSoft::Int16 useri3() const;
    Zcad::ErrorStatus setUseri3(ZSoft::Int16 val);

    ZSoft::Int16 useri4() const;
    Zcad::ErrorStatus setUseri4(ZSoft::Int16 val);

    ZSoft::Int16 useri5() const;
    Zcad::ErrorStatus setUseri5(ZSoft::Int16 val);

    ZSoft::Int16 splinesegs() const;
    Zcad::ErrorStatus setSplinesegs(ZSoft::Int16 segs);

    ZSoft::Int16 surfu() const;
    Zcad::ErrorStatus setSurfu(ZSoft::Int16 u);

    ZSoft::Int16 surfv() const;
    Zcad::ErrorStatus setSurfv(ZSoft::Int16 v);

    ZSoft::Int16 surftype() const;
    Zcad::ErrorStatus setSurftype(ZSoft::Int16 type);

    ZSoft::Int16 surftab1() const;
    Zcad::ErrorStatus setSurftab1(ZSoft::Int16 tab1);

    ZSoft::Int16 surftab2() const;
    Zcad::ErrorStatus setSurftab2(ZSoft::Int16 tab2);

    ZSoft::Int16 splinetype() const;
    Zcad::ErrorStatus setSplinetype(ZSoft::Int16 type);

    ZSoft::Int16 shadedge() const;
    Zcad::ErrorStatus setShadedge(ZSoft::Int16 mode);

    ZSoft::Int16 shadedif() const;
    Zcad::ErrorStatus setShadedif(ZSoft::Int16 dif);

    ZcDb::MeasurementValue measurement() const;
    Zcad::ErrorStatus setMeasurement(ZcDb::MeasurementValue type);

    ZSoft::Int16 unitmode() const;
    Zcad::ErrorStatus setUnitmode(ZSoft::Int16 mode);

    ZSoft::Int16 maxactvp() const;
    Zcad::ErrorStatus setMaxactvp(ZSoft::Int16 max);

    ZSoft::Int16 isolines() const;
    Zcad::ErrorStatus setIsolines(ZSoft::Int16 isolines);

    ZSoft::UInt8 dwfframe() const;
    Zcad::ErrorStatus setDwfframe(ZSoft::UInt8);

    ZSoft::UInt8 dgnframe() const;
    Zcad::ErrorStatus setDgnframe(ZSoft::UInt8);

	ZSoft::Int8 pdfframe() const;
	Zcad::ErrorStatus setPdfframe(ZSoft::Int8 val);

    double ltscale() const;
    Zcad::ErrorStatus setLtscale(double scale);

    double textsize() const;
    Zcad::ErrorStatus setTextsize(double size);

    double tracewid() const;
    Zcad::ErrorStatus setTracewid(double width);

    double sketchinc() const;
    Zcad::ErrorStatus setSketchinc(double inc);

    double filletrad() const;
    Zcad::ErrorStatus setFilletrad(double radius);

    double thickness() const;
    Zcad::ErrorStatus setThickness(double thickness);

    ZcDb::LineWeight  celweight() const;
    Zcad::ErrorStatus setCelweight(ZcDb::LineWeight weight);

    static bool       isValidLineWeight(int weight);
    static ZcDb::LineWeight getNearestLineWeight(int weight);

    ZcDb::EndCaps endCaps() const;
    Zcad::ErrorStatus setEndCaps(ZcDb::EndCaps type);

    ZcDb::JoinStyle joinStyle() const;
    Zcad::ErrorStatus setJoinStyle(ZcDb::JoinStyle style);

    bool lineWeightDisplay() const;
    Zcad::ErrorStatus setLineWeightDisplay(bool display);

    bool xrefEditEnabled() const;
    Zcad::ErrorStatus setXrefEditEnabled(bool enable);

    bool oleStartUp() const;
    Zcad::ErrorStatus setOleStartUp(bool val);

    double angbase() const;
    Zcad::ErrorStatus setAngbase(double angle);

    double pdsize() const;
    Zcad::ErrorStatus setPdsize(double size);

    double plinewid() const;
    Zcad::ErrorStatus setPlinewid(double width);

    double userr1() const;
    Zcad::ErrorStatus setUserr1(double val);

    double userr2() const;
    Zcad::ErrorStatus setUserr2(double val);

    double userr3() const;
    Zcad::ErrorStatus setUserr3(double val);

    double userr4() const;
    Zcad::ErrorStatus setUserr4(double val);

    double userr5() const;
    Zcad::ErrorStatus setUserr5(double val);

    double chamfera() const;
    Zcad::ErrorStatus setChamfera(double val);

    double chamferb() const;
    Zcad::ErrorStatus setChamferb(double val);

    double chamferc() const;
    Zcad::ErrorStatus setChamferc(double val);

    double chamferd() const;
    Zcad::ErrorStatus setChamferd(double val);

    double facetres() const;
    Zcad::ErrorStatus setFacetres(double facetres);
    double get3dDwfPrec() const;
    Zcad::ErrorStatus set3dDwfPrec(double DwfPrec);

	Zcad::ErrorStatus getMenu(ZcString & sMenuName) const;	
    Zcad::ErrorStatus getMenu(ZTCHAR*& pOutput) const;

    bool hpInherit() const;
    Zcad::ErrorStatus setHpInherit(const bool inherit);

    ZcGePoint2d hpOrigin() const;
    Zcad::ErrorStatus setHpOrigin(const ZcGePoint2d& origin);

    const ZcDbDate tdcreate() const;     
    const ZcDbDate tdupdate() const;

    const ZcDbDate tducreate() const;    
    const ZcDbDate tduupdate() const;

    const ZcDbDate tdindwg() const;      
    const ZcDbDate tdusrtimer() const;

	Zcad::ErrorStatus resetTimes();	

    ZcCmColor cecolor() const;
    Zcad::ErrorStatus setCecolor(const ZcCmColor& color);

	ZcCmTransparency cetransparency() const;	
	Zcad::ErrorStatus setCetransparency(const ZcCmTransparency& transparency);	

    ZcDbHandle handseed() const;
    Zcad::ErrorStatus setHandseed(const ZcDbHandle& handle);

    ZcDbObjectId clayer() const;
    Zcad::ErrorStatus setClayer(ZcDbObjectId objId);

    ZcDb::PlotStyleNameType getCePlotStyleNameId(ZcDbObjectId& id) const;
    Zcad::ErrorStatus       setCePlotStyleName(ZcDb::PlotStyleNameType,
                            ZcDbObjectId newId = ZcDbObjectId::kNull);
    
    ZcDbObjectId textstyle() const;
    Zcad::ErrorStatus setTextstyle(ZcDbObjectId objId);

    ZcDbObjectId celtype() const;
    Zcad::ErrorStatus setCeltype(ZcDbObjectId objId);

    ZcDbObjectId cmaterial() const;
    Zcad::ErrorStatus setCmaterial(ZcDbObjectId objId);

    ZcDbObjectId dimstyle() const;
    Zcad::ErrorStatus setDimstyle(ZcDbObjectId styleId);

    Zcad::ErrorStatus getDimstyleData(ZcDbDimStyleTableRecord*& pRec) const;
    Zcad::ErrorStatus getDimstyleChildData(const ZcRxClass *pDimClass,
                                           ZcDbDimStyleTableRecord*& pRec,
                                           ZcDbObjectId &style) const;
    ZcDbObjectId getDimstyleChildId(const ZcRxClass *pDimClass,
                                    ZcDbObjectId &parentStyle) const;

    ZcDbObjectId getDimstyleParentId(ZcDbObjectId &childStyle) const;
                                           
    Zcad::ErrorStatus setDimstyleData(ZcDbDimStyleTableRecord* pRec);
    Zcad::ErrorStatus setDimstyleData(ZcDbObjectId id);

    ZcDbObjectId cmlstyleID() const;
    Zcad::ErrorStatus setCmlstyleID(ZcDbObjectId objId);

    ZSoft::Int16 cmljust() const;
    Zcad::ErrorStatus setCmljust(ZSoft::Int16 just);

    double cmlscale() const;
    Zcad::ErrorStatus setCmlscale(double scale);

    double celtscale() const;
    Zcad::ErrorStatus setCeltscale(double scale);

    ZcGePoint3d pinsbase() const;
    Zcad::ErrorStatus setPinsbase(const ZcGePoint3d& base);

    ZcGePoint3d pextmin() const;

    ZcGePoint3d pextmax() const;

    Zcad::ErrorStatus setPextmin(const ZcGePoint3d& min);
    Zcad::ErrorStatus setPextmax(const ZcGePoint3d& max);

    ZcGePoint2d plimmin() const;
    Zcad::ErrorStatus setPlimmin(const ZcGePoint2d& min);

    ZcGePoint2d plimmax() const;
    Zcad::ErrorStatus setPlimmax(const ZcGePoint2d& max);

    double pelevation() const;
    Zcad::ErrorStatus setPelevation(double elev);

    ZcGePoint3d pucsorg() const;

    ZcGeVector3d pucsxdir() const;

	ZcGeVector3d pucsydir() const;

	Zcad::ErrorStatus setPucs(const ZcGePoint3d& ucsOrigin,
		const ZcGeVector3d& ucsXDir,
		const ZcGeVector3d& ucsYDir);		

    ZcDbObjectId pucsname() const;

	Zcad::ErrorStatus setPucsname(const ZcDbObjectId& ucsRecId);	

    ZcDbObjectId pucsBase() const;
    Zcad::ErrorStatus setPucsBase(const ZcDbObjectId &ucsid);

    ZcGePoint3d worldPucsBaseOrigin(ZcDb::OrthographicView orthoView) const;
    Zcad::ErrorStatus setWorldPucsBaseOrigin(const ZcGePoint3d& origin,
                                             ZcDb::OrthographicView orthoView);

    bool isPucsOrthographic(ZcDb::OrthographicView& orthoView) const;

    double cameraHeight() const;
    Zcad::ErrorStatus setCameraHeight(const double cameraHeight);

    double lensLength() const;
    Zcad::ErrorStatus setLensLength(const double lensLength);

    bool cameraDisplay() const;
    Zcad::ErrorStatus setCameraDisplay(const bool cameraDisplay);

    double stepsPerSec() const;
    Zcad::ErrorStatus setStepsPerSec(double stepsPerSec);

    double stepSize() const;
    Zcad::ErrorStatus setStepSize(double stepSize);

    bool realWorldScale() const;
    Zcad::ErrorStatus setRealWorldScale(const bool realWorldScale);
    ZcGePoint3d insbase() const;
    Zcad::ErrorStatus setInsbase(const ZcGePoint3d& base);

    ZcGePoint3d extmin() const;

    ZcGePoint3d extmax() const;

    Zcad::ErrorStatus updateExt(bool doBestFit = false);

    Zcad::ErrorStatus setExtmin(const ZcGePoint3d& min);
    Zcad::ErrorStatus setExtmax(const ZcGePoint3d& max);

    ZcGePoint2d limmin() const;
    Zcad::ErrorStatus setLimmin(const ZcGePoint2d& min);

    ZcGePoint2d limmax() const;
    Zcad::ErrorStatus setLimmax(const ZcGePoint2d& max);

    double elevation() const;
    Zcad::ErrorStatus setElevation(double elev);

    ZcGePoint3d ucsorg() const;

    ZcGeVector3d ucsxdir() const;

    ZcGeVector3d ucsydir() const;

	Zcad::ErrorStatus setUcs(const ZcGePoint3d& ucsOrigin,
		const ZcGeVector3d& ucsXDir,
		const ZcGeVector3d& ucsYDir);		

    ZcDbObjectId ucsname() const;

	Zcad::ErrorStatus setUcsname(const ZcDbObjectId& ucsRecId);		

    ZcDbObjectId ucsBase() const;
    Zcad::ErrorStatus setUcsBase(ZcDbObjectId ucsid);

    ZcGePoint3d worldUcsBaseOrigin(ZcDb::OrthographicView orthoView) const;
    Zcad::ErrorStatus setWorldUcsBaseOrigin(const ZcGePoint3d& origin,
                                            ZcDb::OrthographicView orthoView);

    bool isUcsOrthographic(ZcDb::OrthographicView& orthoView) const;

	bool isEMR() const;

    #undef ZDBDIMVAR_H                   
    #include "zdbdimvar.h"

    Zcad::ErrorStatus getDimpost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimapost(ZTCHAR*& pOutput) const;
	Zcad::ErrorStatus getDimblk(ZcString & sOutput) const;	

    Zcad::ErrorStatus getDimblk(ZTCHAR*& pOutput) const;
	
	Zcad::ErrorStatus getDimblk1(ZcString & sOutput) const;	
	Zcad::ErrorStatus getDimblk1(ZTCHAR*& pOutput) const;
	
	Zcad::ErrorStatus getDimblk2(ZcString & sOutput) const;	
    Zcad::ErrorStatus getDimblk2(ZTCHAR*& pOutput) const;

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit(int fit);
    Zcad::ErrorStatus setDimunit(int unit);

    Zcad::ErrorStatus getDimRecentStyleList(ZcDbObjectIdArray& objIds) const;

    Zcad::ErrorStatus loadLineTypeFile(const ZTCHAR *ltn, const ZTCHAR *filename);
	
	Zcad::ErrorStatus getProjectName(ZcString & sProjectName) const;		
    Zcad::ErrorStatus getProjectName(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setProjectName(const ZTCHAR*);
	
	Zcad::ErrorStatus getHyperlinkBase(ZcString & sHyperlinkBase) const;		
    Zcad::ErrorStatus getHyperlinkBase(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setHyperlinkBase(const ZTCHAR*);
	
	Zcad::ErrorStatus getStyleSheet(ZcString & sStyleSheet) const;	
    Zcad::ErrorStatus getStyleSheet(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus setStyleSheet(const ZTCHAR*);
    Zcad::ErrorStatus getFilename(const ZTCHAR* & pOutput) const;

    bool              isPartiallyOpened() const;
    Zcad::ErrorStatus applyPartialOpenFilters(
        const ZcDbSpatialFilter* pSpatialFilter,
        const ZcDbLayerFilter* pLayerFilter);

    void              disablePartialOpen();

	Zcad::ErrorStatus getFingerprintGuid(ZcString & guidString) const;	
    Zcad::ErrorStatus getFingerprintGuid(ZTCHAR*& guidString) const;
    Zcad::ErrorStatus setFingerprintGuid(const ZTCHAR *pNewGuid);

	Zcad::ErrorStatus getVersionGuid(ZcString & guidString) const;		
    Zcad::ErrorStatus getVersionGuid(ZTCHAR*& guidString) const;
    Zcad::ErrorStatus setVersionGuid(const ZTCHAR *pNewGuid);

    int tstackalign() const;
    Zcad::ErrorStatus setTStackAlign(int val);

    int tstacksize() const;
    Zcad::ErrorStatus setTStackSize(int val);

    ZcDb::UnitsValue insunits() const;
    Zcad::ErrorStatus setInsunits(const ZcDb::UnitsValue units);

	
    void                setGsModel(ZcGsModel*);
    ZcGsModel*          gsModel() const;

    //void                setGsHighlightModel(ZcGsModel*);
    //ZcGsModel*          gsHighlightModel() const;
	
    bool           plotStyleMode() const;

    double viewportScaleDefault() const;
    Zcad::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);

    bool           dwgFileWasSavedByZwSoftSoftware() const;

    ZcDbLayerStateManager *getLayerStateManager() const;
    ZcDbObjectContextManager* objectContextManager() const;
    ZSoft::UInt8        sortEnts() const;
    Zcad::ErrorStatus   setSortEnts(ZSoft::UInt8 sortEnts);

    ZSoft::UInt8        drawOrderCtl() const;
    Zcad::ErrorStatus   setDrawOrderCtl(ZSoft::UInt8 val);
    
    ZSoft::UInt8        dimAssoc() const;
    Zcad::ErrorStatus setDimAssoc(ZSoft::UInt8 val);

    ZSoft::UInt8 hideText() const;
    Zcad::ErrorStatus setHideText(ZSoft::UInt8 val);

    ZSoft::UInt8  haloGap() const;
    Zcad::ErrorStatus setHaloGap(ZSoft::UInt8 val);

    ZSoft::UInt16 obscuredColor() const;
    Zcad::ErrorStatus setObscuredColor(ZSoft::UInt16 val);

    ZSoft::UInt8 obscuredLineType() const;
    Zcad::ErrorStatus setObscuredLineType(ZSoft::UInt8 val);

    ZSoft::UInt8  intersectDisplay() const;
    Zcad::ErrorStatus setIntersectDisplay(ZSoft::UInt8 val);

    ZSoft::UInt16 intersectColor() const;
    Zcad::ErrorStatus setIntersectColor(ZSoft::UInt16 val);

    Zcad::ErrorStatus getTableStyleDictionary(ZcDbDictionary*& pDict,
                                              ZcDb::OpenMode mode = ZcDb::kForRead);
    ZcDbObjectId  tableStyleDictionaryId() const;

    ZcDbObjectId tablestyle() const;
    Zcad::ErrorStatus setTablestyle(ZcDbObjectId objId);
    Zcad::ErrorStatus getMLeaderStyleDictionary(ZcDbDictionary*& pDict,
                                              ZcDb::OpenMode mode = ZcDb::kForRead);
    ZcDbObjectId  mleaderStyleDictionaryId() const;
    ZcDbObjectId mleaderstyle() const;
    Zcad::ErrorStatus setMLeaderstyle(ZcDbObjectId objId);

	
	Zcad::ErrorStatus getDetailViewStyleDictionary(ZcDbDictionary*& pDict,
		ZcDb::OpenMode mode = ZcDb::kForRead);
	ZcDbObjectId detailViewStyleDictionaryId() const;
	ZcDbObjectId detailViewStyle() const;

	Zcad::ErrorStatus setDetailViewStyle(ZcDbObjectId objId);

	Zcad::ErrorStatus getSectionViewStyleDictionary(ZcDbDictionary*& pDict,
		ZcDb::OpenMode mode = ZcDb::kForRead);
	ZcDbObjectId sectionViewStyleDictionaryId() const;
	ZcDbObjectId sectionViewStyle() const;


	Zcad::ErrorStatus setSectionViewStyle(ZcDbObjectId objId);
	

    Zcad::ErrorStatus evaluateFields(int nContext,
                                     const ZTCHAR* pszPropName= nullptr,
                                     ZcDbDatabase* pDb      = nullptr,
                                     int* pNumFound         = nullptr,
                                     int* pNumEvaluated     = nullptr);
    Zcad::ErrorStatus getViewportArray(ZcDbObjectIdArray& vportIds,
                                       bool bGetPaperspaceVports = true) const;
    Zcad::ErrorStatus getVisualStyleList(ZcArray<const ZTCHAR*> & vstyleList);

    ZSoft::UInt8  solidHist() const;
    Zcad::ErrorStatus setSolidHist(ZSoft::UInt8 val);

    ZSoft::UInt8  showHist() const;
    Zcad::ErrorStatus setShowHist(ZSoft::UInt8 val);

    double psolWidth() const;
    Zcad::ErrorStatus setPsolWidth(double width);
    double psolHeight() const;
    Zcad::ErrorStatus setPsolHeight(double height);

    ZSoft::UInt16 loftParam() const;
    Zcad::ErrorStatus setLoftParam(ZSoft::UInt16 flags);
    ZSoft::UInt8 loftNormals() const;
    Zcad::ErrorStatus setLoftNormals(ZSoft::UInt8 value);
    double loftAng1() const;
    Zcad::ErrorStatus setLoftAng1(double ang1);
    double loftAng2() const;
    Zcad::ErrorStatus setLoftAng2(double ang2);
    double loftMag1() const;
    Zcad::ErrorStatus setLoftMag1(double mag1);
    double loftMag2() const;
    Zcad::ErrorStatus setLoftMag2(double mag2);
    double latitude() const;
    Zcad::ErrorStatus setLatitude(double lat);
    double longitude() const;
    Zcad::ErrorStatus setLongitude(double lng);
    double northDirection() const;
    Zcad::ErrorStatus setNorthDirection(double northdir);
    ZcDb::TimeZone timeZone() const;
    Zcad::ErrorStatus setTimeZone(ZcDb::TimeZone tz);

    Zcad::ErrorStatus getTimeZoneInfo(ZcDb::TimeZone tz, double& offset, ZcString& desc) const;
    Zcad::ErrorStatus setTimeZoneAsUtcOffset(double offset);

	
	bool geoMarkerVisibility() const;
	Zcad::ErrorStatus setGeoMarkerVisibility(bool value);
	ZcString geoCoordinateSystemId() const;
	


    ZSoft::UInt8 lightGlyphDisplay() const;
    Zcad::ErrorStatus setLightGlyphDisplay(ZSoft::UInt8 val);
    ZSoft::UInt8 tileModeLightSynch() const;
    Zcad::ErrorStatus setTileModeLightSynch(ZSoft::UInt8 val);

    ZcCmColor interfereColor() const;
    Zcad::ErrorStatus setInterfereColor(const ZcCmColor& color);

    ZcDbObjectId interfereObjVisStyle() const;
    Zcad::ErrorStatus setInterfereObjVisStyle(ZcDbObjectId id);

    ZcDbObjectId interfereVpVisStyle() const;
    Zcad::ErrorStatus setInterfereVpVisStyle(ZcDbObjectId id);

    ZcDbObjectId dragVisStyle() const;
    Zcad::ErrorStatus setDragVisStyle(ZcDbObjectId id);

    ZSoft::UInt8 cshadow() const;
    Zcad::ErrorStatus setCshadow(ZSoft::UInt8 val);

    double shadowPlaneLocation() const;
    Zcad::ErrorStatus setShadowPlaneLocation(double val);

    ZcDbAnnotationScale* cannoscale() const;
    Zcad::ErrorStatus setCannoscale(ZcDbAnnotationScale*);

    bool annoAllVisible() const;
    Zcad::ErrorStatus setAnnoAllVisible(bool allvis);

    bool annotativeDwg() const;
    Zcad::ErrorStatus setAnnotativeDwg(bool ao);

    bool msltscale() const;
    Zcad::ErrorStatus setMsltscale(bool val);

    ZSoft::UInt8 lightingUnits() const;
    Zcad::ErrorStatus setLightingUnits(ZSoft::UInt8 val);

    bool lightsInBlocks() const;
    Zcad::ErrorStatus setLightsInBlocks(bool val);

    ZSoft::Int16 dxeVal() const;
    Zcad::ErrorStatus setDxeVal(ZSoft::Int16 val);

	
	double mleaderscale() const;
	Zcad::ErrorStatus setMLeaderscale(double scale);

	ZSoft::Int16 cDynDisplayMode() const;
	Zcad::ErrorStatus setCDynDisplayMode(ZSoft::Int16 val);

	ZSoft::Int16 previewType() const;
	Zcad::ErrorStatus setPreviewType(ZSoft::Int16 val);

	ZSoft::UInt8 indexctl() const;
	Zcad::ErrorStatus setIndexctl(ZSoft::UInt8 val);

	ZSoft::UInt8 layerEval() const;
	Zcad::ErrorStatus setLayerEval(ZSoft::UInt8 val);

	ZSoft::Int16 layerNotify() const;
	Zcad::ErrorStatus setLayerNotify(ZSoft::Int16 val);

	double msOleScale() const;
	Zcad::ErrorStatus setMsOleScale(double val);

	ZSoft::UInt8 updateThumbnail() const;
	Zcad::ErrorStatus setUpdateThumbnail(ZSoft::UInt8 val);

	enum EraseMask {
		kZeroLengthCurve = 0x01,  
		kEmptyText       = 0x02,  
		kAllEmptyObj     = 0xFFFFFFFF
	};
	ZSoft::UInt32 eraseEmptyObjects(const ZSoft::UInt32 flags);
	ZSoft::UInt32 countEmptyObjects(const ZSoft::UInt32 flags);
	

private:
    friend class ZcDbSystemInternals;
    ZcDbImpDatabase* mpImpDb = nullptr;

	
	ZcDbDatabase (const ZcDbDatabase & ) = delete;	
	ZcDbDatabase & operator = (const ZcDbDatabase & ) = delete;	

};


inline Zcad::ErrorStatus zcdbSaveAs2004(ZcDbDatabase* pDb,
	const ZTCHAR* fileName)
{
	return pDb->saveAs(fileName, false, ZcDb::kDHL_1800);
}

inline Zcad::ErrorStatus zcdbSaveAs2000(ZcDbDatabase* pDb,
	const ZTCHAR* fileName)
{
	return pDb->saveAs(fileName, false, ZcDb::kDHL_1015);
}

inline Zcad::ErrorStatus zcdbSaveAsR14(ZcDbDatabase* pDb,
	const ZTCHAR* fileName)
{
	return pDb->saveAs(fileName, false, ZcDb::kDHL_1014);
}

inline Zcad::ErrorStatus zcdbDxfOutAs2004(ZcDbDatabase* pDb,
	const ZTCHAR* fileName,
	const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, ZcDb::kDHL_1800);
}

inline Zcad::ErrorStatus zcdbDxfOutAs2000(ZcDbDatabase* pDb,
	const ZTCHAR* fileName,
	const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, ZcDb::kDHL_1015);
}

inline Zcad::ErrorStatus zcdbDxfOutAsR12(ZcDbDatabase* pDb,
	const ZTCHAR* fileName,
	const int precision = 16)
{
	return pDb->dxfOut(fileName, precision, ZcDb::kDHL_1009);
}

class ZCDBCORE2D_PORT ZcDbObjectIterator: public ZcRxObject, public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectIterator);
    virtual ~ZcDbObjectIterator();

    bool           done() const;
    void           step(bool backwards = false, bool skipDeleted = true);
    void           setPosition(ZcDbEntity*  pEnt);
    void           setPosition(ZcDbObjectId  pObj);
    void           start(bool atEnd = false);
    ZcDbEntity*    entity();
    ZcDbObjectId   objectId();

private:
    friend class ZcDbSystemInternals;
    ZcDbObjectIterator();
    ZcDbSpaceIterator* mpImpIterator;
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbXObject: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbXObject);

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus dwgIn(ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    Zcad::ErrorStatus dxfIn(ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
    Zcad::ErrorStatus dxfOut(ZcDbDxfFiler* pFiler) const;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    protected:
    ZcDbXObject();
};

class ZCDBCORE2D_PORT ZcCmComplexColor: public  ZcDbXObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcCmComplexColor); 

    virtual ZcCmComplexColor* incReference();
    virtual void              decReference();

	virtual Zcad::ErrorStatus getDescription(ZcString & desc) const;		
    virtual Zcad::ErrorStatus getDescription(ZTCHAR*& desc) const final;
	virtual Zcad::ErrorStatus getExplanation(ZcString & expl) const;		
    virtual Zcad::ErrorStatus getExplanation(ZTCHAR*& expl) const final;

    virtual ZcCmEntityColor::ColorMethod  colorMethod() const;

    virtual bool              isByColor() const;
    virtual bool              isByLayer() const;
    virtual bool              isByBlock() const;
    virtual bool              isByACI()   const;
    virtual bool              isByPen ()  const;
    virtual bool              isForeground()   const;

    virtual Zcad::ErrorStatus setRGB  (ZSoft::UInt8 red, 
                                       ZSoft::UInt8 green, 
                                       ZSoft::UInt8 blue);

    virtual ZSoft::UInt8      red  () const;
    virtual ZSoft::UInt8      green() const;
    virtual ZSoft::UInt8      blue () const;

	Zcad::ErrorStatus   setRGB(ZSoft::UInt32 rgbValue);
	ZSoft::UInt32       getRGB() const;

	Zcad::ErrorStatus   setRGBM(ZSoft::UInt32 rgbmValue);
	ZSoft::UInt32       getRGBM() const;

    virtual ZSoft::UInt16     colorIndex() const;
    virtual Zcad::ErrorStatus setColorIndex(ZSoft::UInt16 colorIndex);
    virtual ZSoft::UInt16     penIndex() const;   
    virtual Zcad::ErrorStatus setPenIndex (ZSoft::UInt16 penIndex);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo) override;

private:
    ZSoft::UInt16 refCount = 0;
    ZcCmEntityColor mColor;
#ifdef ZcCmColor_DEPRECATED_METHODS
public:
	[[deprecated("Prefer specific setMethod() calls to this generic call")]] virtual Zcad::ErrorStatus setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod);
	[[deprecated("Use getRGBM() or getRGB()")]]virtual ZSoft::UInt32     color() const;
	[[deprecated("Use setRGBM() or setRGB()")]]virtual Zcad::ErrorStatus setColor(ZSoft::UInt32 color);
	[[deprecated("Use setRGB()")]]virtual Zcad::ErrorStatus setRed(ZSoft::UInt8 red);
	[[deprecated("Use setRGB()")]]virtual Zcad::ErrorStatus setGreen(ZSoft::UInt8 green);
	[[deprecated("Use setRGB()")]]virtual Zcad::ErrorStatus setBlue(ZSoft::UInt8 blue);
#endif
};

inline Zcad::ErrorStatus ZcCmComplexColor::getDescription(ZTCHAR*& desc) const
{
	return ::zcutGetZcStringConvertToZTChar(this, &ZcCmComplexColor::getDescription, desc); 
}

inline Zcad::ErrorStatus ZcCmComplexColor::getExplanation(ZTCHAR*& expl) const
{
	return ::zcutGetZcStringConvertToZTChar(this, &ZcCmComplexColor::getExplanation, expl); 
}


class ZCDBCORE2D_PORT ZcCmHSB   
{

public:
	ZcCmHSB();
	ZcCmHSB(ZSoft::UInt16 hue, ZSoft::UInt8 saturation, ZSoft::UInt8 brightness);
	ZcCmHSB(const ZcCmHSB&);
	ZcCmHSB& operator=(const ZcCmHSB& inputColor);
	virtual ~ZcCmHSB();

	bool operator ==(const ZcCmHSB& color) const;
	bool operator !=(const ZcCmHSB& color) const;

	virtual ZSoft::UInt32     value() const;

	virtual Zcad::ErrorStatus rgbToHSB(ZSoft::UInt8 r, ZSoft::UInt8 g, ZSoft::UInt8 b);
	virtual Zcad::ErrorStatus hsbToRGB(ZSoft::UInt8 *r, ZSoft::UInt8 *g, ZSoft::UInt8 *b);

	virtual Zcad::ErrorStatus setHSB(ZSoft::UInt32 value);
	virtual Zcad::ErrorStatus setHSB  (ZSoft::UInt16 hue, 
		ZSoft::UInt8 saturation, 
		ZSoft::UInt8 brightness);
	virtual Zcad::ErrorStatus setHSB(double hue, double saturation, double brightness);
	virtual Zcad::ErrorStatus setHue  (ZSoft::UInt16 hue);
	virtual Zcad::ErrorStatus setHue  (double hue);
	virtual Zcad::ErrorStatus setSaturation (ZSoft::UInt8 saturation);
	virtual Zcad::ErrorStatus setSaturation (double saturation);
	virtual Zcad::ErrorStatus setBrightness (ZSoft::UInt8 brightness);
	virtual Zcad::ErrorStatus setBrightness (double brightness);
	virtual ZSoft::UInt16     hue  () const;
	virtual ZSoft::UInt8      saturation() const;
	virtual ZSoft::UInt8      brightness () const;

private:

	ZSoft::UInt32           mHSB = 0;
};


Zcad::ErrorStatus zccmGetColorFromACIName(ZcCmColor& clr, const ZTCHAR *pInput);
Zcad::ErrorStatus zccmGetColorFromRGBName(ZcCmColor& clr, const ZTCHAR *pInput);
Zcad::ErrorStatus ZCDBCORE2D_PORT zccmGetFromHSBName(ZcCmHSB& hsb, const ZTCHAR *pInput);	
Zcad::ErrorStatus zccmGetColorFromColorBookName(ZcCmColor& clr, const ZTCHAR *pBookName, const ZTCHAR *pColorName);

void zccmGetLocalizedColorNames( const ZTCHAR* colors[9] );

class ZCDBCORE2D_PORT ZcDbColor: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbColor);

    ZcDbColor();
    virtual ~ZcDbColor();

    void getColor(ZcCmColor& color) const;
    void setColor(const ZcCmColor& color);
    const ZcCmEntityColor& entityColor(void) const;

    virtual Zcad::ErrorStatus   decomposeForSave(
                                ZcDb::ZcDbDwgVersion ver,
                                ZcDbObject*& replaceObj,
                                ZcDbObjectId& replaceId,
                                ZSoft::Boolean& exchangeXData) override;

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const override;


private:
    ZcCmColor           m_color;    
    ZcCmEntityColor     m_ecol;
protected:

	virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwnerObject,
		ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,
		ZSoft::Boolean isPrimary
		= true) const override;	 
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbEntity: public ZcDbObject
 {
public:
    ZCDB_DECLARE_MEMBERS(ZcDbEntity);

    virtual ~ZcDbEntity();

    ZcDbObjectId                blockId() const;

    ZcCmColor                   color() const;
	
	virtual Zcad::ErrorStatus   setColor(const ZcCmColor& color, bool doSubents, ZcDbDatabase *pDb);	
    virtual Zcad::ErrorStatus   setColor(const ZcCmColor& color, bool doSubents = true) final; 
    ZSoft::UInt16               colorIndex() const;
    virtual Zcad::ErrorStatus   setColorIndex(ZSoft::UInt16 color,
                                  ZSoft::Boolean doSubents = true);
    ZcCmEntityColor             entityColor() const;

    ZcCmTransparency            transparency() const;
    virtual Zcad::ErrorStatus   setTransparency(const ZcCmTransparency& trans,
                                  ZSoft::Boolean doSubents = true);
	Zcad::ErrorStatus plotStyleName(ZcString &sName) const;	
    ZTCHAR*                       plotStyleName() const;
    ZcDb::PlotStyleNameType     getPlotStyleNameId(ZcDbObjectId& id) const;
    virtual Zcad::ErrorStatus   setPlotStyleName(const ZTCHAR* newName,
                                  ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setPlotStyleName(ZcDb::PlotStyleNameType,
                                ZcDbObjectId newId = ZcDbObjectId::kNull,
                                ZSoft::Boolean doSubents = true);
	Zcad::ErrorStatus layer(ZcString &sName) const;	
    ZTCHAR*                       layer() const;
    ZcDbObjectId                layerId() const;
    virtual Zcad::ErrorStatus   setLayer(const ZTCHAR* newVal,
                                  ZSoft::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);
    virtual Zcad::ErrorStatus   setLayer(ZcDbObjectId newVal,
                                  ZSoft::Boolean doSubents = true,
                                  bool allowHiddenLayer = false);
	Zcad::ErrorStatus linetype(ZcString &sName) const;		
    ZTCHAR*                       linetype() const;
    ZcDbObjectId                linetypeId() const;
    virtual Zcad::ErrorStatus   setLinetype(const ZTCHAR* newVal,
                                  ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setLinetype(ZcDbObjectId newVal,
                                  ZSoft::Boolean doSubents = true);
	Zcad::ErrorStatus material(ZcString &sName) const;		
    ZTCHAR*                        material() const;
    ZcDbObjectId                materialId() const;
    virtual Zcad::ErrorStatus   setMaterial(const ZTCHAR* newVal, ZSoft::Boolean doSubents = true);
    virtual Zcad::ErrorStatus   setMaterial(ZcDbObjectId newVal, ZSoft::Boolean doSubents = true);

	enum VisualStyleType 
	{
		kFullVisualStyle,
		kFaceVisualStyle,
		kEdgeVisualStyle
	};
	virtual Zcad::ErrorStatus   setVisualStyle  (ZcDbObjectId visualStyleId,
								VisualStyleType vsType = kFullVisualStyle,
								ZSoft::Boolean doSubents = true);
	ZcDbObjectId                visualStyleId   (VisualStyleType vsType = kFullVisualStyle) const;

    virtual Zcad::ErrorStatus getMaterialMapper(ZcGiMapper& mapper) const;
    virtual Zcad::ErrorStatus setMaterialMapper(const ZcGiMapper& mapper, ZSoft::Boolean doSubents = true);

    double                      linetypeScale() const;
    virtual Zcad::ErrorStatus   setLinetypeScale(double newval,
                                  ZSoft::Boolean doSubents = true);

    ZcDb::Visibility            visibility() const;
    ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus   setVisibility(ZcDb::Visibility newVal,
                                  ZSoft::Boolean doSubents = true) ZSOFT_SEALED;	

    ZcDb::LineWeight            lineWeight() const;
    virtual Zcad::ErrorStatus   setLineWeight(ZcDb::LineWeight newVal,
                                  ZSoft::Boolean doSubents = true);

    virtual ZcDb::CollisionType collisionType() const;

    virtual bool                castShadows() const;
    virtual void                setCastShadows(bool newVal);
    virtual bool                receiveShadows() const;
    virtual void                setReceiveShadows(bool newVal);

    Zcad::ErrorStatus           setPropertiesFrom(const ZcDbEntity* pEntity,
                                  ZSoft::Boolean doSubents = true);

    virtual ZSoft::Boolean      isPlanar() const { return false; }
    virtual Zcad::ErrorStatus   getPlane(ZcGePlane&, ZcDb::Planarity&) const
                                    { return Zcad::eNotApplicable; }

    virtual void                getEcs(ZcGeMatrix3d& retVal) const;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getGeomExtents(ZcDbExtents& extents) const ZSOFT_SEALED; 
     
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus addSubentPaths(
                    const ZcDbFullSubentPathArray& newPaths) ZSOFT_SEALED;
     
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus deleteSubentPaths(
                    const ZcDbFullSubentPathArray& paths) ZSOFT_SEALED;
     
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus getSubentClassId(
                    const ZcDbFullSubentPath& path,
                    CLSID*                    clsId) const ZSOFT_SEALED;
     
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus transformSubentPathsBy(
                    const ZcDbFullSubentPathArray& paths,
                    const ZcGeMatrix3d&            xform) ZSOFT_SEALED;
     
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus getGripPointsAtSubentPath(
                                  const ZcDbFullSubentPath&      path,
                                  ZcDbGripDataPtrArray&          grips,
                                  const double                   curViewUnitSize,
                                  const int                      gripSize,
                                  const ZcGeVector3d&            curViewDir,
                                  const int                      bitflags) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus moveGripPointsAtSubentPaths(
                                  const ZcDbFullSubentPathArray& paths,
                                  const ZcDbVoidPtrArray&        gripAppData,
                                  const ZcGeVector3d&            offset,
                                  const int                      bitflags) ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus getSubentPathGeomExtents(
                                  const ZcDbFullSubentPath&      path,
                                  ZcDbExtents&                   extents) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                  ZcDb::SubentType       type,
                                  ZSoft::GsMarker        gsMark,
                                  const ZcGePoint3d&     pickPoint,
                                  const ZcGeMatrix3d&    viewXform, 
                                  int&                   numPaths,
                                  ZcDbFullSubentPath*&   subentPaths, 
                                  int                    numInserts = 0,
                                  ZcDbObjectId*          entAndInsertStack
                                                           = nullptr) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                               const ZcDbFullSubentPath& subPath, 
                               ZcArray<ZSoft::GsMarker>& gsMarkers) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus highlight(const ZcDbFullSubentPath& subId 
                                        = kNullSubent, const ZSoft::Boolean highlightAll 
                        = false) const ZSOFT_SEALED;
      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus unhighlight(const ZcDbFullSubentPath& subId 
                                        = kNullSubent, const ZSoft::Boolean highlightAll  
                        = false) const ZSOFT_SEALED;
      ZSOFT_SEALED_VIRTUAL ZcDbEntity*       subentPtr(const ZcDbFullSubentPath& id) const ZSOFT_SEALED;
 
      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray &      geomIds) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getOsnapPoints(
                                 ZcDb::OsnapMode     osnapMode,
                                 ZSoft::GsMarker     gsSelectionMark,
                                 const ZcGePoint3d&  pickPoint,
                                 const ZcGePoint3d&  lastPoint,
                                 const ZcGeMatrix3d& viewXform,
                                 ZcGePoint3dArray&   snapPoints,
                                 ZcDbIntArray&       geomIds,
                                 const ZcGeMatrix3d& insertionMat) const ZSOFT_SEALED;

	  ZSOFT_SEALED_VIRTUAL bool isContentSnappable() const ZSOFT_SEALED;	

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getGripPoints(
                                   ZcGePoint3dArray&  gripPoints,
                                   ZcDbIntArray&  osnapModes,
                                   ZcDbIntArray&  geomIds) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus moveGripPointsAt(const ZcDbIntArray& indices,
        const ZcGeVector3d& offset) ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getGripPoints(ZcDbGripDataPtrArray& grips,
        const double curViewUnitSize, const int gripSize, 
        const ZcGeVector3d& curViewDir, const int bitflags) const ZSOFT_SEALED;


      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus moveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
        const ZcGeVector3d& offset, const int bitflags) ZSOFT_SEALED;
    
      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus getStretchPoints(
        ZcGePoint3dArray& stretchPoints) const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus moveStretchPointsAt(const ZcDbIntArray& indices,
        const ZcGeVector3d& offset) ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus intersectWith(const ZcDbEntity* pEnt,
                                    ZcDb::Intersect intType, 
                                    ZcGePoint3dArray& points,
                                    ZSoft::GsMarker thisGsMarker = 0,
                                    ZSoft::GsMarker otherGsMarker = 0) const ZSOFT_SEALED;
 
      ZSOFT_SEALED_VIRTUAL  Zcad::ErrorStatus intersectWith(const ZcDbEntity* pEnt,
                                             ZcDb::Intersect intType, 
                                             const ZcGePlane& projPlane,
                                             ZcGePoint3dArray& points, 
                                             ZSoft::GsMarker thisGsMarker = 0,
                                             ZSoft::GsMarker otherGsMarker = 0) const ZSOFT_SEALED;

    Zcad::ErrorStatus          boundingBoxIntersectWith(
                                             const ZcDbEntity*   pEnt,
                                             ZcDb::Intersect     intType,
                                             ZcGePoint3dArray&   points,
                                             ZSoft::GsMarker     thisGsMarker,
                                             ZSoft::GsMarker     otherGsMarker) const;

    Zcad::ErrorStatus          boundingBoxIntersectWith(
                                             const ZcDbEntity*   pEnt,
                                             ZcDb::Intersect     intType,
                                             const ZcGePlane&    projPlane,
                                             ZcGePoint3dArray&   points,
                                             ZSoft::GsMarker     thisGsMarker,
                                             ZSoft::GsMarker     otherGsMarker) const;

      ZSOFT_SEALED_VIRTUAL void            list() const ZSOFT_SEALED;

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   transformBy(const ZcGeMatrix3d& xform) ZSOFT_SEALED;
      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getTransformedCopy(const ZcGeMatrix3d& xform,
                                                   ZcDbEntity*& pEnt) const ZSOFT_SEALED;
      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   explode(ZcDbVoidPtrArray& entitySet) const ZSOFT_SEALED;

    void                        recordGraphicsModified(
                                    ZSoft::Boolean setModified = true);

    Zcad::ErrorStatus           draw();
    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st);

      ZSOFT_SEALED_VIRTUAL Zcad::ErrorStatus   getCompoundObjectTransform(ZcGeMatrix3d & xMat) const ZSOFT_SEALED;

    void                        setDatabaseDefaults();
    void                        setDatabaseDefaults(ZcDbDatabase* pDb);
    virtual void                subSetDatabaseDefaults(ZcDbDatabase* pDb);

    virtual Zcad::ErrorStatus   applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                                 ZcRxClass*    classObj) override;

    virtual Zcad::ErrorStatus   audit(ZcDbAuditInfo* pAuditInfo) override;

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual ZcGiDrawable*       drawable() override;

    virtual void                setGsNode(ZcGsNode* pNode); 
    virtual ZcGsNode*           gsNode() const; 
	virtual bool                bounds(ZcDbExtents& bounds) const override;

	virtual ZSoft::Boolean      cloneMeForDragging() final;
	virtual bool                hideMeForDragging() const final;

    virtual void                dragStatus(const ZcDb::DragStat status);
    virtual void                gripStatus(const ZcDb::GripStat status) final;
    virtual void                subentGripStatus(
                                    const ZcDb::GripStat      status,
                                    const ZcDbFullSubentPath& subentity) final;

    virtual Zcad::ErrorStatus getGripEntityUCS(const void* pGripAppData,
        ZcGeVector3d& normalVec, ZcGePoint3d& origin, ZcGeVector3d& xAxis) const final;
protected:
    
    ZcDbEntity();
	
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
	virtual void                subList() const;


	virtual Zcad::ErrorStatus   subGetOsnapPoints(
		ZcDb::OsnapMode     osnapMode,
		ZSoft::GsMarker     gsSelectionMark,
		const ZcGePoint3d&  pickPoint,
		const ZcGePoint3d&  lastPoint,
		const ZcGeMatrix3d& viewXform,
		ZcGePoint3dArray&   snapPoints,
		ZcDbIntArray &   geomIds) const;
	virtual Zcad::ErrorStatus   subGetOsnapPoints(
		ZcDb::OsnapMode     osnapMode,
		ZSoft::GsMarker     gsSelectionMark,
		const ZcGePoint3d&  pickPoint,
		const ZcGePoint3d&  lastPoint,
		const ZcGeMatrix3d& viewXform,
		ZcGePoint3dArray&   snapPoints,
		ZcDbIntArray &   geomIds,
		const ZcGeMatrix3d& insertionMat) const;

	virtual bool                subIsContentSnappable() const;


	virtual Zcad::ErrorStatus   subTransformBy(const ZcGeMatrix3d& xform);
	virtual Zcad::ErrorStatus   subGetTransformedCopy(const ZcGeMatrix3d& xform,
		ZcDbEntity*& pEnt) const;
	virtual Zcad::ErrorStatus   subExplode(ZcDbVoidPtrArray& entitySet) const;
	virtual ZSoft::Boolean      subCloneMeForDragging();
	virtual bool                subHideMeForDragging() const;


	virtual Zcad::ErrorStatus   subGetGripPoints(
		ZcGePoint3dArray&  gripPoints,
		ZcDbIntArray &     osnapModes,
		ZcDbIntArray &  geomIds) const;

	virtual Zcad::ErrorStatus   subGetGripPoints(ZcDbGripDataPtrArray& grips,
		const double curViewUnitSize, const int gripSize, 
		const ZcGeVector3d& curViewDir, const int bitflags) const;

	virtual Zcad::ErrorStatus   subMoveGripPointsAt(const ZcDbIntArray & indices,
		const ZcGeVector3d& offset);

	virtual Zcad::ErrorStatus   subMoveGripPointsAt(const ZcDbVoidPtrArray& gripAppData,
		const ZcGeVector3d& offset, const int bitflags);

	virtual Zcad::ErrorStatus   subGetStretchPoints(
		ZcGePoint3dArray& stretchPoints) const;

	virtual Zcad::ErrorStatus   subMoveStretchPointsAt(const ZcDbIntArray & indices,
		const ZcGeVector3d& offset);

	virtual Zcad::ErrorStatus   subGetGeomExtents(ZcDbExtents& extents) const;


	virtual Zcad::ErrorStatus subGetSubentClassId(
		const ZcDbFullSubentPath& path,
		CLSID*                    clsId) const;

	virtual  Zcad::ErrorStatus subAddSubentPaths(
		const ZcDbFullSubentPathArray& newPaths);

	virtual  Zcad::ErrorStatus subDeleteSubentPaths(
		const ZcDbFullSubentPathArray& paths);

	virtual  Zcad::ErrorStatus subTransformSubentPathsBy(
		const ZcDbFullSubentPathArray& paths,
		const ZcGeMatrix3d&            xform);

	virtual  Zcad::ErrorStatus subGetGripPointsAtSubentPath(
		const ZcDbFullSubentPath&      path,
		ZcDbGripDataPtrArray&          grips,
		const double                   curViewUnitSize,
		const int                      gripSize,
		const ZcGeVector3d&            curViewDir,
		const int                      bitflags) const;

	virtual  Zcad::ErrorStatus subMoveGripPointsAtSubentPaths(
		const ZcDbFullSubentPathArray& paths,
		const ZcDbVoidPtrArray&        gripAppData,
		const ZcGeVector3d&            offset,
		const int                      bitflags);

	virtual  Zcad::ErrorStatus subGetSubentPathGeomExtents(
		const ZcDbFullSubentPath&      path, 
		ZcDbExtents&                   extents) const;   

	virtual  Zcad::ErrorStatus subGetSubentPathsAtGsMarker(
		ZcDb::SubentType       type,
		ZSoft::GsMarker        gsMark, 
		const ZcGePoint3d&     pickPoint,
		const ZcGeMatrix3d&    viewXform, 
		int&                   numPaths,
		ZcDbFullSubentPath*&   subentPaths, 
		int                    numInserts = 0,
		ZcDbObjectId*          entAndInsertStack
		= nullptr) const;

	virtual  Zcad::ErrorStatus subGetGsMarkersAtSubentPath(
		const ZcDbFullSubentPath& subPath, 
		ZcArray<ZSoft::GsMarker>& gsMarkers) const;

	virtual ZcDbEntity*        subSubentPtr(const ZcDbFullSubentPath& id) const;

	virtual void subGripStatus(const ZcDb::GripStat status);
	virtual void               subSubentGripStatus(
		const ZcDb::GripStat      status,
		const ZcDbFullSubentPath& subentity);


	virtual Zcad::ErrorStatus subHighlight(const ZcDbFullSubentPath& subId 
		= kNullSubent, const ZSoft::Boolean highlightAll 
		= false) const;
	virtual Zcad::ErrorStatus subUnhighlight(const ZcDbFullSubentPath& subId 
		= kNullSubent, const ZSoft::Boolean highlightAll  
		= false) const;


	virtual ZcDb::Visibility  subVisibility() const;
	virtual Zcad::ErrorStatus subSetVisibility(ZcDb::Visibility newVal,
		ZSoft::Boolean doSubents = true);


	virtual  Zcad::ErrorStatus subIntersectWith(const ZcDbEntity* pEnt,
		ZcDb::Intersect intType, 
		ZcGePoint3dArray& points,
		ZSoft::GsMarker thisGsMarker = 0, 
		ZSoft::GsMarker otherGsMarker = 0) const;

	virtual  Zcad::ErrorStatus subIntersectWith(const ZcDbEntity* pEnt,
		ZcDb::Intersect intType, 
		const ZcGePlane& projPlane,
		ZcGePoint3dArray& points, 
		ZSoft::GsMarker thisGsMarker = 0,
		ZSoft::GsMarker otherGsMarker = 0) const;

	virtual Zcad::ErrorStatus subGetGripEntityUCS(const void* pGripAppData, 
		ZcGeVector3d& normalVec, ZcGePoint3d& origin, ZcGeVector3d& xAxis) const;

	virtual Zcad::ErrorStatus   subGetCompoundObjectTransform(ZcGeMatrix3d & xMat) const;

	friend class ZcDbPropertiesOverrule;
	friend class ZcDbOsnapOverrule;
	friend class ZcDbTransformOverrule;
	friend class ZcDbGripOverrule;
	friend class ZcDbSubentityOverrule;
	friend class ZcDbHighlightOverrule;
	friend class ZcDbHighlightStateOverrule;
	friend class ZcDbVisibilityOverrule;
	friend class ZcDbGeometryOverrule;
	friend class ZcDbGripEntityOverrule;
	
public:
	
	Zcad::ErrorStatus  pushHighlight     (const ZcDbFullSubentPath& subId,
		ZcGiHighlightStyle        highlightStyle);
	Zcad::ErrorStatus  popHighlight      (const ZcDbFullSubentPath& subId);
	ZcGiHighlightStyle highlightState    (const ZcDbFullSubentPath& subId);
	
private:
	virtual Zcad::ErrorStatus  subPushHighlight  (const ZcDbFullSubentPath& subId,
		ZcGiHighlightStyle        highlightStyle);
	virtual Zcad::ErrorStatus  subPopHighlight   (const ZcDbFullSubentPath& subId);
	virtual ZcGiHighlightStyle subHighlightState (const ZcDbFullSubentPath& subId);

	ZcDbEntity (const ZcDbEntity& ) = delete;
	ZcDbEntity & operator = (const ZcDbEntity& ) = delete;
};

inline ZcDbEntity::~ZcDbEntity()
{
    
}

inline ZTCHAR* ZcDbEntity::plotStyleName() const
{
	ZcString sName;
	return ::zcutZcStringToZTChar(sName, this->plotStyleName(sName));
}

inline ZTCHAR* ZcDbEntity::layer() const
{
	ZcString sName;
	return ::zcutZcStringToZTChar(sName, this->layer(sName));
}

inline ZTCHAR* ZcDbEntity::linetype() const
{
	ZcString sName;
	return ::zcutZcStringToZTChar(sName, this->linetype(sName));
}

inline ZTCHAR* ZcDbEntity::material() const
{
	ZcString sName;
	return ::zcutZcStringToZTChar(sName, this->material(sName));
}

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbObjectReactor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbObjectReactor);
	virtual ~ZcDbObjectReactor();

	virtual void cancelled(const ZcDbObject* dbObj) {}
	virtual void copied(const ZcDbObject* dbObj,
		const ZcDbObject* newObj) {}
	virtual void erased(const ZcDbObject* dbObj,
		ZSoft::Boolean bErasing) {}
	virtual void goodbye(const ZcDbObject* dbObj) {}
	virtual void openedForModify(const ZcDbObject* dbObj) {}
	virtual void modified(const ZcDbObject* dbObj) {}
	virtual void subObjModified(const ZcDbObject* dbObj,
		const ZcDbObject* subObj) {}
	virtual void modifyUndone(const ZcDbObject* dbObj) {}
	virtual void modifiedXData(const ZcDbObject* dbObj) {}
	virtual void unappended(const ZcDbObject* dbObj) {}
	virtual void reappended(const ZcDbObject* dbObj) {}
	virtual void objectClosed(const ZcDbObjectId objId) {}

protected:
    ZcDbObjectReactor();
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbEntityReactor: public ZcDbObjectReactor
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbEntityReactor);
	~ZcDbEntityReactor();
	virtual void modifiedGraphics(const ZcDbEntity* dbObj) {}
	virtual void dragCloneToBeDeleted(const ZcDbEntity* pOriginalObj,
		const ZcDbEntity* pClone) {}
protected:
    ZcDbEntityReactor();
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbDatabaseReactor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabaseReactor);
	virtual ~ZcDbDatabaseReactor();

	virtual void objectAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj) {}
	virtual void objectUnAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj) {}
	virtual void objectReAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj) {}
	virtual void objectOpenedForModify(const ZcDbDatabase* dwg, const ZcDbObject* dbObj) {}
	virtual void objectModified(const ZcDbDatabase* dwg, const ZcDbObject* dbObj) {}
	virtual void objectErased(const ZcDbDatabase* dwg, const ZcDbObject* dbObj,
		ZSoft::Boolean bErased) {}
	virtual void headerSysVarWillChange(const ZcDbDatabase* dwg, const ZTCHAR* name) {}
	virtual void headerSysVarChanged(const ZcDbDatabase* dwg, const ZTCHAR* name,
		ZSoft::Boolean bSuccess) {}
	virtual void proxyResurrectionCompleted(const ZcDbDatabase* dwg,
		const ZTCHAR* appname,
		ZcDbObjectIdArray& objects) {}
	virtual void goodbye(const ZcDbDatabase* dwg) {}
};

class ZCDBCORE2D_PORT ZcDbExtents2d : public ZcHeapOperators
{
public:
	ZcDbExtents2d();                                      
	ZcDbExtents2d(const ZcDbExtents2d& src);           
	ZcDbExtents2d(const ZcGePoint2d& min, const ZcGePoint2d& max);  

	ZcGePoint2d       minPoint() const { return mMinPoint; }
	ZcGePoint2d       maxPoint() const { return mMaxPoint; }
	Zcad::ErrorStatus set(const ZcGePoint2d& min, const ZcGePoint2d& max);

	
	void              addPoint (const ZcGePoint2d& pt);
	void              addExt   (const ZcDbExtents2d& src);

	void              expandBy(const ZcGeVector2d& vec);
	void              transformBy(const ZcGeMatrix2d& mat);
	

	bool              operator==(const ZcDbExtents2d& other);

private:
	ZcGePoint2d    mMinPoint;
	ZcGePoint2d    mMaxPoint;
};

class ZCDBCORE2D_PORT ZcDbExtents : public ZcHeapOperators
{
public:
    ZcDbExtents();                                      
    ZcDbExtents(const ZcDbExtents& src);           
    ZcDbExtents(const ZcGePoint3d& min, const ZcGePoint3d& max);  
 
    ZcGePoint3d       minPoint() const { return mMinPoint; }
    ZcGePoint3d       maxPoint() const { return mMaxPoint; }
    Zcad::ErrorStatus set(const ZcGePoint3d& min, const ZcGePoint3d& max);

    void              addPoint (const ZcGePoint3d& pt);
    void              addExt   (const ZcDbExtents& src);
    Zcad::ErrorStatus addBlockExt(ZcDbBlockTableRecord* pBTR);

    void expandBy(const ZcGeVector3d& vec);
    void transformBy(const ZcGeMatrix3d& mat);

	bool              operator==(const ZcDbExtents& other);
private:
    ZcGePoint3d    mMinPoint;
    ZcGePoint3d    mMaxPoint;
};

template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbBlockTable>() const
{
	return this->blockTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbLayerTable>() const
{
	return this->layerTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbTextStyleTable>() const
{
	return this->textStyleTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbLinetypeTable>() const
{
	return this->linetypeTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbViewTable>() const
{
	return this->viewTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbUCSTable>() const
{
	return this->UCSTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbViewportTable>() const
{
	return this->viewportTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbRegAppTable>() const
{
	return this->regAppTableId();
}
template <> inline ZcDbObjectId ZcDbDatabase::getSymbolTableId<ZcDbDimStyleTable>() const
{
	return this->dimStyleTableId();
}

inline Zcad::ErrorStatus
ZcDbDatabase::getBlockTable(
    ZcDbBlockTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getLayerTable(
    ZcDbLayerTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getTextStyleTable(
    ZcDbTextStyleTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getLinetypeTable(
    ZcDbLinetypeTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getViewTable(
    ZcDbViewTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getUCSTable(
    ZcDbUCSTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getViewportTable(
    ZcDbViewportTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getRegAppTable(
    ZcDbRegAppTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

inline Zcad::ErrorStatus
ZcDbDatabase::getDimStyleTable(
    ZcDbDimStyleTable*& pTable,
    ZcDb::OpenMode mode)
{
    return getSymbolTable(pTable, mode);
}

#define ZC_SRCH_BLOCK         0x01
#define ZC_SRCH_DIM_TEXT      0x02
#define ZC_SRCH_TEXT          0x04
#define ZC_SRCH_LINK_DESC     0x08
#define ZC_SRCH_LINK_URL      0x10
#define ZC_SRCH_MATCH_CASE    0x20
#define ZC_SRCH_WHOLE_WORD    0x40

#define ZC_SRCH_DEFAULT       0x1F

bool zcdbTextFind(ZcDbDatabase* pDatabase,
                  ZcDbObjectIdArray& resultSet,
                  const ZTCHAR* findString,
                  const ZTCHAR* replaceString = nullptr,
                  ZSoft::UInt8 searchOptions = ZC_SRCH_DEFAULT,
                  const ZcDbObjectIdArray& selSet = ZcDbObjectIdArray());

ZCDBCORE2D_PORT bool zcdbIsGsWorkerThread();

#pragma pack(pop)

#endif
