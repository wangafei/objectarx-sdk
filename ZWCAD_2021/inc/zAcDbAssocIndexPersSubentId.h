#pragma once
#include "zdbsubeid.h"
#include "zAcDbAssocPersSubentId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocIndexPersSubentId : public ZcDbAssocPersSubentId
{
#ifdef __GNUC__
    typedef ZcDbAssocPersSubentId __super;
    static_assert((std::is_same<__super, ZcDbAssocPersSubentId>::value), "Incorrect __super class");
#endif

public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocIndexPersSubentId);

    explicit ZcDbAssocIndexPersSubentId(ZcDb::SubentType subentType = ZcDb::kNullSubentType, unsigned int index = 0);

    bool operator ==(const ZcDbAssocIndexPersSubentId& other) const
    {
        return mSubentType == other.mSubentType && mIndex == other.mIndex;
    }

    bool operator <(const ZcDbAssocIndexPersSubentId& other) const
    {
        return mSubentType != other.mSubentType ? mSubentType < other.mSubentType : mIndex < other.mIndex;
    }

    virtual ZcDb::SubentType subentType(const ZcDbEntity*, ZcDbDatabase*) const override { return mSubentType; }

    virtual bool isNull() const override { return mSubentType == ZcDb::kNullSubentType; }

    virtual Zcad::ErrorStatus dwgOutFieldsData(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus dxfOutFieldsData(ZcDbDxfFiler* pFiler) const;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;

    unsigned int index() const { return mIndex; }

    void setSubentType(ZcDb::SubentType subentType) { mSubentType = subentType; }
    void setIndex     (unsigned int newIndex)       { mIndex      = newIndex;   }

private:

    int encodeActualClassInSubentType() const;

    static const int kRoundTripOffset = 1000000;
    virtual int roundTripOffset() const { return kRoundTripOffset; }

    friend void roundTripReadViaZcDbAssocSimplePersSubentId(ZcDbAssocPersSubentId*&);

protected:
    ZcDb::SubentType mSubentType;
    unsigned int     mIndex;

};

class ZCDBCORE2D_PORT ZcDbAssocExternalIndexPersSubentId : public ZcDbAssocIndexPersSubentId
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocExternalIndexPersSubentId);

    explicit ZcDbAssocExternalIndexPersSubentId(ZcDb::SubentType subentType = ZcDb::kNullSubentType, unsigned int index = 0)
      : ZcDbAssocIndexPersSubentId(subentType, index) {}

private:

    static const int kRoundTripOffset = 2000000;
    virtual int roundTripOffset() const override { return kRoundTripOffset; }

    friend void roundTripReadViaZcDbAssocSimplePersSubentId(ZcDbAssocPersSubentId*&);

};

class ZCDBCORE2D_PORT ZcDbAssocObjectAndIndexPersSubentId : public ZcDbAssocIndexPersSubentId
{
#ifdef __GNUC__
    typedef ZcDbAssocIndexPersSubentId __super;
    static_assert((std::is_same<__super, ZcDbAssocIndexPersSubentId>::value), "Incorrect __super class");
#endif

public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocObjectAndIndexPersSubentId);

    ZcDbAssocObjectAndIndexPersSubentId() {}
    ZcDbAssocObjectAndIndexPersSubentId(const ZcDbObjectId& objId, ZcDb::SubentType subentType, unsigned int index);

    bool operator ==(const ZcDbAssocObjectAndIndexPersSubentId& other) const;
    bool operator  <(const ZcDbAssocObjectAndIndexPersSubentId& other) const;

    ZcDbObjectId objectId() const { return mObjectId; }

    void setObjectId(const ZcDbObjectId& objId) { mObjectId = objId; }

    virtual Zcad::ErrorStatus dwgOutFieldsData(ZcDbDwgFiler*) const ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus dxfOutFieldsData(ZcDbDxfFiler*) const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* ) ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const ZSOFT_OVERRIDE;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* ) ZSOFT_OVERRIDE;

private:
    ZcDbObjectId mObjectId;

};

#pragma pack (pop)
