
#ifndef ZD_DBDICT_H
#define ZD_DBDICT_H

#include "zdbmain.h"

#pragma pack(push, 8)

class ZcDbImpDictionary;
class ZcString;

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbDictionaryIterator: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDictionaryIterator);
	ZcDbDictionaryIterator(const ZcDbDictionaryIterator &) = delete;
	ZcDbDictionaryIterator & operator = (const ZcDbDictionaryIterator &) = delete;

    virtual ~ZcDbDictionaryIterator() {}

	virtual const ZTCHAR*      name       () const = 0;
    virtual bool				       name       (ZcString &sName) const = 0;		

	template<class ObjType> Zcad::ErrorStatus getObject(ObjType *& pObject,
		ZcDb::OpenMode mode = ZcDb::kForRead)
	{
		const ZcDbObjectId id = this->objectId();
		return ::zcdbOpenObject(pObject, id, mode, false);
	}

	Zcad::ErrorStatus getObject  (ZcDbObject*&   pObject,
	                                      ZcDb::OpenMode mode = ZcDb::kForRead)
	{
		return this->getObject<ZcDbObject>(pObject, mode);
	}
    virtual ZcDbObjectId      objectId   () const = 0;

    virtual bool              done       () const = 0;
    virtual bool              next       () = 0;
    virtual bool              setPosition(ZcDbObjectId objId) = 0;

protected:
    ZcDbDictionaryIterator() {}
};

class ZCDBCORE2D_PORT ZcDbDictionary: public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDictionary);
    ZcDbDictionary();
    virtual ~ZcDbDictionary();

	
	ZcDbDictionary(const ZcDbDictionary &) = delete;
	ZcDbDictionary & operator = (const ZcDbDictionary &) = delete;

	template<class ObjType> Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
		ObjType *& entryObj,
		ZcDb::OpenMode mode = ZcDb::kForRead) const
	{
		entryObj = nullptr;
		ZcDbObjectId id;
		Zcad::ErrorStatus es = this->getAt(entryName, id);
		if (es == Zcad::eOk)
			es = ::zcdbOpenObject(entryObj, id, mode, false);
		return es;
	}
	
    Zcad::ErrorStatus getAt(const ZTCHAR*   entryName,
        ZcDbObject*&   entryObj,
        ZcDb::OpenMode mode = ZcDb::kForRead)
    {
        return this->getAt<ZcDbObject>(entryName, entryObj, mode);
    }
	
    Zcad::ErrorStatus getAt(const ZTCHAR*   entryName,
                            ZcDbObjectId&  entryObj) const;
    Zcad::ErrorStatus nameAt(ZcDbObjectId objId,
                             ZTCHAR*&      name) const;

	Zcad::ErrorStatus nameAt(ZcDbObjectId objId, ZcString &   name) const;	

    bool              has       (const ZTCHAR*  entryName) const;
    bool              has       (ZcDbObjectId objId) const;
    ZSoft::UInt32     numEntries() const;

    Zcad::ErrorStatus remove(const ZTCHAR *  key);
    Zcad::ErrorStatus remove(const ZTCHAR *  key,
                             ZcDbObjectId& returnId);
    Zcad::ErrorStatus remove(ZcDbObjectId  objId);

    bool              setName(const ZTCHAR*   oldName,
                              const ZTCHAR*   newName);
    Zcad::ErrorStatus setAt  (const ZTCHAR*   srchKey,
                              ZcDbObject*   newValue,
                              ZcDbObjectId& retObjId);

    bool              isTreatElementsAsHard () const;
    void              setTreatElementsAsHard(bool doIt);
	
    virtual void  setMergeStyle(ZcDb::DuplicateRecordCloning style);

	ZcDbDictionaryIterator* newIterator() const;

    virtual Zcad::ErrorStatus subErase     (ZSoft::Boolean pErasing
                                                = ZSoft::kTrue) override;
    virtual Zcad::ErrorStatus dwgInFields  (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields  (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields (ZcDbDxfFiler* pFiler) const override;

    virtual ZcDb::DuplicateRecordCloning mergeStyle() const override;

    virtual void goodbye(const ZcDbObject* pObject) override;
    virtual void erased (const ZcDbObject* pObject, bool bErasing) override;	

    virtual Zcad::ErrorStatus decomposeForSave(
                                  ZcDb::ZcDbDwgVersion ver,
                                  ZcDbObject*&         replaceObj,
                                  ZcDbObjectId&        replaceId,
                                  ZSoft::Boolean&      exchangeXData) override;
protected:

    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Zcad::ErrorStatus ZcDbDictionary::nameAt(ZcDbObjectId objId, ZTCHAR*& pName) const
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, pName, this->nameAt(objId, sName));
}

inline bool ZcDbDictionary::has(const ZTCHAR*  entryName) const
{
    ZcDbObjectId id;
    return this->getAt(entryName, id) == Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbDictionary::remove(const ZTCHAR*  entryName)
{
    ZcDbObjectId id;
    return this->remove(entryName, id);
}

#pragma pack(pop)

#endif
