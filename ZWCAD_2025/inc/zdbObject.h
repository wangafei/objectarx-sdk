
#pragma once
#include "zadesk.h"
#include "zAcDbCore2dDefs.h"
#include "zdrawable.h"
#include "zAcHeapOpers.h"
#include "zrxobject.h"
#include "zacdb.h"
#include "zdbboiler.h"
#include "zdbptrar.h"
#include "zdbidar.h"

class ZcDbIdMapping;
class ZcDbAuditInfo;
class ZcDbDwgFiler;
class ZcDbDxfFiler;
struct resbuf;
class ZcDbObjectReactor;
class ZcDbImpObject;
class ZcDbField;
class ZcDbDictionary;
class ZcGeMatrix3d;
class ZcDbEntity;
class ZcDbObject;

struct _GUID;
typedef struct _GUID CLSID;

ZCDBCORE2D_PORT Zcad::ErrorStatus
zcdbOpenObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
    bool openErased, const ZcRxClass* pClass);

ZCDBCORE2D_PORT Zcad::ErrorStatus
zcdbOpenObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcRxClass* (*pfDesc)(),
    ZcDb::OpenMode mode, bool openErased);

inline Zcad::ErrorStatus
zcdbOpenZcDbObject(ZcDbObject*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode,
    bool openErasedObject = false);

template<class T_OBJECT> inline Zcad::ErrorStatus
zcdbOpenObject(
    T_OBJECT*& pObj, ZcDbObjectId id, ZcDb::OpenMode mode = ZcDb::kForRead,
    bool openErased = false)
{
    return ::zcdbOpenObject((ZcDbObject*&)pObj, id, &T_OBJECT::desc,
        mode, openErased);
}

inline Zcad::ErrorStatus zcdbOpenObject(ZcDbObject*& pObj, ZcDbObjectId id,
    ZcDb::OpenMode mode = ZcDb::kForRead,
    bool openErased = false)
{
    return ::zcdbOpenObject(pObj, id, mode, openErased, nullptr);
}

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbObject: public ZcGiDrawable, public ZcHeapOperators
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbObject);

    virtual ~ZcDbObject();

    ZcDbObjectId      objectId() const;
    ZcDbObjectId      ownerId() const;
    virtual Zcad::ErrorStatus setOwnerId(ZcDbObjectId objId);
    void              getZcDbHandle(ZcDbHandle& handle) const;
    ZcDbDatabase*     database() const;
 
    ZcDbDatabase* databaseToUse() const;
    ZcDbDatabase* intendedDatabase() const;
    Zcad::ErrorStatus setIntendedDatabase(ZcDbDatabase* pDb);

    Zcad::ErrorStatus createExtensionDictionary();
    ZcDbObjectId      extensionDictionary() const;
    Zcad::ErrorStatus releaseExtensionDictionary();

    Zcad::ErrorStatus upgradeOpen();
    Zcad::ErrorStatus upgradeFromNotify(ZSoft::Boolean& wasWritable);
    Zcad::ErrorStatus downgradeOpen();
    Zcad::ErrorStatus downgradeToNotify(ZSoft::Boolean wasWritable);
    virtual Zcad::ErrorStatus subOpen(ZcDb::OpenMode mode);

    Zcad::ErrorStatus cancel();
    virtual Zcad::ErrorStatus subCancel();

    Zcad::ErrorStatus close();
    Zcad::ErrorStatus closeAndPage(ZSoft::Boolean onlyWhenClean = true);
    virtual Zcad::ErrorStatus subClose();

    Zcad::ErrorStatus erase(ZSoft::Boolean erasing = true);
    virtual Zcad::ErrorStatus subErase(ZSoft::Boolean erasing);

    Zcad::ErrorStatus handOverTo(ZcDbObject* newObject,
                                 ZSoft::Boolean keepXData = true,
                                 ZSoft::Boolean keepExtDict = true);
    virtual Zcad::ErrorStatus subHandOverTo(ZcDbObject* newObject);

    Zcad::ErrorStatus swapIdWith(ZcDbObjectId otherId, 
                                 ZSoft::Boolean swapXdata = false,
                                 ZSoft::Boolean swapExtDict = false);
    virtual Zcad::ErrorStatus subSwapIdWith(ZcDbObjectId otherId,
                                 ZSoft::Boolean swapXdata = false,
                                 ZSoft::Boolean swapExtDict = false);

    virtual Zcad::ErrorStatus swapReferences (const ZcDbIdMapping& idMap);

    virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus         dwgIn       (ZcDbDwgFiler* pFiler);
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler);
    Zcad::ErrorStatus         dwgOut      (ZcDbDwgFiler* pFiler) const;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

    Zcad::ErrorStatus         dxfIn       (ZcDbDxfFiler* pFiler);
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler);

	 
    Zcad::ErrorStatus         dxfOut      (ZcDbDxfFiler* pFiler,
                                           bool bAllXdata,
                                          const ZcDbObjectIdArray * pRegAppIds) const;	
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    virtual ZcDb::DuplicateRecordCloning mergeStyle () const;

    virtual resbuf*           xData   (const ZTCHAR* regappName = nullptr) const;
    virtual Zcad::ErrorStatus setXData(const resbuf* xdata);
            Zcad::ErrorStatus xDataTransformBy(const ZcGeMatrix3d& xform);

    Zcad::ErrorStatus         setBinaryData(const ZTCHAR * key,
                                            ZSoft::Int32         size,
                                            const char * data);
    Zcad::ErrorStatus         getBinaryData(const ZTCHAR * key,
                                            ZSoft::Int32 &       size,
                                            char *&      data) const;

    ZSoft::Boolean isEraseStatusToggled() const;
    ZSoft::Boolean isErased() const;
    ZSoft::Boolean isReadEnabled() const;
    ZSoft::Boolean isWriteEnabled() const;
    ZSoft::Boolean isNotifyEnabled() const;
    ZSoft::Boolean isModified() const;
    ZSoft::Boolean isModifiedXData() const;
    ZSoft::Boolean isModifiedGraphics() const;
    ZSoft::Boolean isNewObject() const;
    ZSoft::Boolean isNotifying() const;
    ZSoft::Boolean isUndoing() const;
    ZSoft::Boolean isCancelling() const;
    ZSoft::Boolean isReallyClosing() const;
    ZSoft::Boolean isTransactionResident() const;

    ZSoft::Boolean isAProxy() const;

    void assertReadEnabled() const;
    void assertWriteEnabled(ZSoft::Boolean autoUndo = true,
                            ZSoft::Boolean recordModified = true);
    void assertNotifyEnabled() const;

	bool                      isUndoRecordingDisabled() const;		

    void                      disableUndoRecording(ZSoft::Boolean disable);
    ZcDbDwgFiler*             undoFiler();
    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* undoFiler,
                                               ZcRxClass*    classObj);

	Zcad::ErrorStatus addReactor(ZcDbObjectReactor * pReactor) const;	

	Zcad::ErrorStatus removeReactor(ZcDbObjectReactor * pReactor) const;	

    Zcad::ErrorStatus              addPersistentReactor(ZcDbObjectId objId); 

    Zcad::ErrorStatus removePersistentReactor(ZcDbObjectId objId); 
	
	bool hasReactor(const ZcDbObjectReactor *pReactor) const;  
    bool                      hasPersistentReactor(ZcDbObjectId objId) const;

    const ZcDbVoidPtrArray*   reactors() const;

    virtual void              recvPropagateModify(const ZcDbObject* subObj);
    virtual void              xmitPropagateModify() const;

    virtual Zcad::ErrorStatus deepClone(ZcDbObject* pOwnerObject,
                                        ZcDbObject*& pClonedObject,
                                        ZcDbIdMapping& idMap,
                                        bool isPrimary = true) const final;	

    template<typename CloneType> Zcad::ErrorStatus deepClone(ZcDbObject* pOwner,
        CloneType*& pClone,
        ZcDbIdMapping& idMap,
        bool isPrimary = true) const
    {
        ZcDbObject* pNewObj = nullptr;
        Zcad::ErrorStatus es = this->deepClone(pOwner, pNewObj, idMap, isPrimary);
        if (pNewObj == nullptr || es != Zcad::eOk)
            pClone = nullptr;
        else {
            pClone = CloneType::cast(pNewObj);
            if (pClone == nullptr) {
                es = Zcad::eWrongObjectType;
                pNewObj->erase();
                pNewObj->close();
            }
        }
        return es;
    }

	virtual  Zcad::ErrorStatus wblockClone(ZcRxObject* pOwnerObject,
                                          ZcDbObject*& pClonedObject,
                                          ZcDbIdMapping& idMap,
                                          bool isPrimary = true) const final;	

    template<typename CloneType> Zcad::ErrorStatus wblockClone(ZcRxObject* pOwner,
        CloneType*& pClone,
        ZcDbIdMapping& idMap,
        bool isPrimary = true) const
    {
        ZcDbObject* pNewObj = nullptr;
        Zcad::ErrorStatus es = this->wblockClone(pOwner, pNewObj, idMap, isPrimary);
        if (pNewObj == nullptr || es != Zcad::eOk)
            pClone = nullptr;
        else {
            pClone = CloneType::cast(pNewObj);
            if (pClone == nullptr) {
                es = Zcad::eWrongObjectType;
                pNewObj->erase();
                pNewObj->close();
            }
        }
        return es;
    }
    void              setZcDbObjectIdsInFlux();
    ZSoft::Boolean    isZcDbObjectIdsInFlux() const;

    virtual void cancelled       (const ZcDbObject* dbObj);
    virtual void copied          (const ZcDbObject* dbObj,
                                  const ZcDbObject* newObj);
    virtual void erased          (const ZcDbObject* dbObj,
                                  ZSoft::Boolean bErasing);	
    virtual void goodbye         (const ZcDbObject* dbObj);
    virtual void openedForModify (const ZcDbObject* dbObj);
    virtual void modified        (const ZcDbObject* dbObj);
    virtual void subObjModified  (const ZcDbObject* dbObj,
                                  const ZcDbObject* subObj);
    virtual void modifyUndone    (const ZcDbObject* dbObj);
    virtual void modifiedXData   (const ZcDbObject* dbObj);
    virtual void unappended      (const ZcDbObject* dbObj);
    virtual void reappended      (const ZcDbObject* dbObj);
    virtual void objectClosed    (const ZcDbObjectId objId);
    virtual void modifiedGraphics(const ZcDbEntity* dbEnt);

    virtual ZcRxObject*        clone() const override;
    virtual Zcad::ErrorStatus  copyFrom(const ZcRxObject* pSrc) override;

    bool       hasSaveVersionOverride();
    void       setHasSaveVersionOverride(bool bSetIt);

    virtual Zcad::ErrorStatus getObjectSaveVersion(const ZcDbDwgFiler* pFiler, 
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);
    virtual Zcad::ErrorStatus getObjectSaveVersion(const ZcDbDxfFiler* pFiler, 
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);
            Zcad::ErrorStatus getObjectBirthVersion(
                                 ZcDb::ZcDbDwgVersion& ver,
                                 ZcDb::MaintenanceReleaseVersion& maintVer);

    virtual Zcad::ErrorStatus   decomposeForSave(
                                ZcDb::ZcDbDwgVersion ver,
                                ZcDbObject*& replaceObj,
                                ZcDbObjectId& replaceId,
                                ZSoft::Boolean& exchangeXData);

    virtual ZcGiDrawable*       drawable();
	
    virtual ZSoft::Boolean      isPersistent() const override;
    virtual ZcDbObjectId        id() const override;

   virtual void                setGsNode(ZcGsNode* pNode);
   virtual ZcGsNode*           gsNode() const;


    virtual Zcad::ErrorStatus   getClassID(CLSID* pClsid) const final;

    bool              hasFields(void) const;
    Zcad::ErrorStatus getField(const ZTCHAR* pszPropName,
                               ZcDbObjectId& fieldId) const;
    Zcad::ErrorStatus getField(const ZTCHAR* pszPropName, ZcDbField*& pField,
                               ZcDb::OpenMode mode = ZcDb::kForRead) const;

    virtual Zcad::ErrorStatus setField(const ZTCHAR* pszPropName, ZcDbField* pField,
                               ZcDbObjectId& fieldId);

    virtual Zcad::ErrorStatus removeField(ZcDbObjectId fieldId);
    virtual Zcad::ErrorStatus removeField(const ZTCHAR* pszPropName, ZcDbObjectId& returnId);
    virtual Zcad::ErrorStatus removeField(const ZTCHAR* pszPropName);
    ZcDbObjectId      getFieldDictionary(void) const;
    Zcad::ErrorStatus getFieldDictionary(ZcDbDictionary*& pFieldDict, 
                             ZcDb::OpenMode mode = ZcDb::kForRead) const;
protected:
    ZcDbObject();

	
	virtual ZSoft::UInt32       subSetAttributes(ZcGiDrawableTraits* pTraits) override;
	virtual ZSoft::Boolean      subWorldDraw(ZcGiWorldDraw* pWd) override;
	virtual void                subViewportDraw(ZcGiViewportDraw* pVd) override;

	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const;

	virtual Zcad::ErrorStatus subDeepClone(ZcDbObject* pOwnerObject,
		ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,
		ZSoft::Boolean isPrimary = true) const;

	virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwnerObject,
		ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,
		ZSoft::Boolean isPrimary = true) const;
	
private:
	friend class ZcDbPropertiesOverrule;
	friend class ZcDbObjectOverrule;
    ZcDbImpObject*            mpImpObject = nullptr;

	ZcDbObject (const ZcDbObject & ) = delete;
	ZcDbObject & operator = (const ZcDbObject & ) = delete;
};
