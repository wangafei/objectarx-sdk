#pragma once
#include "zAcDbCore2dDefs.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbCompoundObjectId : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbCompoundObjectId);

    ZcDbCompoundObjectId();

    ZcDbCompoundObjectId(const ZcDbObjectId& id, ZcDbDatabase* pHostDatabase = NULL);

    ZcDbCompoundObjectId(const ZcDbCompoundObjectId&);

    ZcDbCompoundObjectId(const ZcDbObjectId& id, const ZcDbObjectIdArray& path, ZcDbDatabase* pHostDatabase = NULL);

    virtual ~ZcDbCompoundObjectId();

    ZcDbCompoundObjectId& operator =(const ZcDbObjectId&);
    ZcDbCompoundObjectId& operator =(const ZcDbCompoundObjectId&);

    bool operator ==(const ZcDbCompoundObjectId&) const;
    bool operator !=(const ZcDbCompoundObjectId& other) const { return !(*this == other); }

    ZcDbObjectId topId() const;

    ZcDbObjectId leafId() const;

    Zcad::ErrorStatus getFullPath(ZcDbObjectIdArray& fullPath) const;

    Zcad::ErrorStatus getPath(ZcDbObjectIdArray& path) const;

    void setEmpty();

    Zcad::ErrorStatus set(const ZcDbObjectId&, ZcDbDatabase* pHostDatabase = NULL);

    Zcad::ErrorStatus set(const ZcDbCompoundObjectId&, ZcDbDatabase* pHostDatabase = NULL);

    Zcad::ErrorStatus set(const ZcDbObjectId& id, const ZcDbObjectIdArray& path, ZcDbDatabase* pHostDatabase = NULL);

    Zcad::ErrorStatus setFullPath(const ZcDbObjectIdArray& fullPath, ZcDbDatabase* pHostDatabase = NULL);

    bool isEmpty() const;

    bool isValid(int validityCheckingLevel = 1) const;

    bool isExternal() const;

    bool isSimpleObjectId() const;

    enum Status
    {
        kValid                      = 0,
        kWasLoadedNowUnloaded       = 1,
        kCouldNotResolveNonTerminal = 2,
        kCouldNotResolveTerminal    = 3,
        kCouldNotResolveTooEarly    = 4,
        kIncompatibleIdType         = 1000,
    };

    Status status() const;

    Zcad::ErrorStatus getTransform(ZcGeMatrix3d& trans) const;

    bool remap(const ZcDbIdMapping& idMap);

    Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler, ZcDbDatabase* pHostDatabase) const;

    Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler, int ownerVersion);

    Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler, ZcDbDatabase* pHostDatabase) const;

    Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler, ZcDbDatabase* pHostDatabase, int ownerVersion);

    static const ZcDbCompoundObjectId& nullId();

private:
    class ZcDbImpCompoundObjectId* mpImp;
};

class ZCDBCORE2D_PORT ZcDbParentTransformOfChildPE : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbParentTransformOfChildPE);

    virtual Zcad::ErrorStatus getParentTransformOfChild(const ZcDbObject* pThisParent, const ZcDbObjectId& childId, ZcGeMatrix3d&) = 0;
};

#pragma pack (pop)
