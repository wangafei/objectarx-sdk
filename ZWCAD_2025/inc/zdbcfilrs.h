

#ifndef ZD_DBCFILERS_H
#define ZD_DBCFILERS_H 1

#include "zdbfiler.h"
#pragma pack (push, 8)

class ZcDbWblockCloneFiler;
class ZcDbImpDeepCloneFiler;

class ZCDB_PORT ZcDbDeepCloneFiler: public ZcDbDwgFiler
{
    friend class ZcDbSystemInternals;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDeepCloneFiler);
    ZcDbDeepCloneFiler();
    virtual ~ZcDbDeepCloneFiler();

    virtual Zcad::ErrorStatus filerStatus() const  override;
    virtual ZcDb::FilerType   filerType() const override;
    virtual void              setFilerStatus(Zcad::ErrorStatus) override;
    virtual void              resetFilerStatus() override;

    virtual Zcad::ErrorStatus readHardOwnershipId(ZcDbHardOwnershipId*) override;
    virtual Zcad::ErrorStatus writeHardOwnershipId(const ZcDbHardOwnershipId&) override;

    virtual Zcad::ErrorStatus readSoftOwnershipId(ZcDbSoftOwnershipId*) override;
    virtual Zcad::ErrorStatus writeSoftOwnershipId(const ZcDbSoftOwnershipId&) override;

    virtual Zcad::ErrorStatus readHardPointerId(ZcDbHardPointerId*) override;
    virtual Zcad::ErrorStatus writeHardPointerId(const ZcDbHardPointerId&) override;

    virtual Zcad::ErrorStatus readSoftPointerId(ZcDbSoftPointerId*) override;
    virtual Zcad::ErrorStatus writeSoftPointerId(const ZcDbSoftPointerId&) override;

	virtual Zcad::ErrorStatus readInt8(ZSoft::Int8 *) override;
	virtual Zcad::ErrorStatus writeInt8(ZSoft::Int8 ) override;

    virtual Zcad::ErrorStatus readString(ZTCHAR **) override;
    virtual Zcad::ErrorStatus writeString(const ZTCHAR *) override;

	virtual Zcad::ErrorStatus readString(ZcString &) override;
	virtual Zcad::ErrorStatus writeString(const ZcString &) override;

    virtual Zcad::ErrorStatus readBChunk(zds_binary*) override;
    virtual Zcad::ErrorStatus writeBChunk(const zds_binary&) override;

    virtual Zcad::ErrorStatus readZcDbHandle(ZcDbHandle*) override;
    virtual Zcad::ErrorStatus writeZcDbHandle(const ZcDbHandle&) override;

	virtual Zcad::ErrorStatus readInt64(ZSoft::Int64*) override;
	virtual Zcad::ErrorStatus writeInt64(ZSoft::Int64) override;

    virtual Zcad::ErrorStatus readInt32(ZSoft::Int32*) override;
    virtual Zcad::ErrorStatus writeInt32(ZSoft::Int32) override;

    virtual Zcad::ErrorStatus readInt16(ZSoft::Int16*) override;
    virtual Zcad::ErrorStatus writeInt16(ZSoft::Int16) override;

	virtual Zcad::ErrorStatus readUInt64(ZSoft::UInt64*) override;
	virtual Zcad::ErrorStatus writeUInt64(ZSoft::UInt64) override;

    virtual Zcad::ErrorStatus readUInt32(ZSoft::UInt32*) override;
    virtual Zcad::ErrorStatus writeUInt32(ZSoft::UInt32) override;

    virtual Zcad::ErrorStatus readUInt16(ZSoft::UInt16*) override;
    virtual Zcad::ErrorStatus writeUInt16(ZSoft::UInt16) override;

    virtual Zcad::ErrorStatus readUInt8(ZSoft::UInt8*) override;
    virtual Zcad::ErrorStatus writeUInt8(ZSoft::UInt8) override;

    virtual Zcad::ErrorStatus readBoolean(ZSoft::Boolean*) override;
    virtual Zcad::ErrorStatus writeBoolean(ZSoft::Boolean) override;

    virtual Zcad::ErrorStatus readBool(bool*) override;
    virtual Zcad::ErrorStatus writeBool(bool) override;

    virtual Zcad::ErrorStatus readDouble(double*) override;
    virtual Zcad::ErrorStatus writeDouble(double) override;

    virtual Zcad::ErrorStatus readPoint2d(ZcGePoint2d*) override;
    virtual Zcad::ErrorStatus writePoint2d(const ZcGePoint2d&) override;

    virtual Zcad::ErrorStatus readPoint3d(ZcGePoint3d*) override;
    virtual Zcad::ErrorStatus writePoint3d(const ZcGePoint3d&) override;

    virtual Zcad::ErrorStatus readVector2d(ZcGeVector2d*) override;
    virtual Zcad::ErrorStatus writeVector2d(const ZcGeVector2d&) override;

    virtual Zcad::ErrorStatus readVector3d(ZcGeVector3d*) override;
    virtual Zcad::ErrorStatus writeVector3d(const ZcGeVector3d&) override;

    virtual Zcad::ErrorStatus readScale3d(ZcGeScale3d*) override;
    virtual Zcad::ErrorStatus writeScale3d(const ZcGeScale3d&) override;

    virtual Zcad::ErrorStatus readBytes(void*, ZSoft::UIntPtr) override;
    virtual Zcad::ErrorStatus writeBytes(const void*, ZSoft::UIntPtr) override;

    virtual Zcad::ErrorStatus readAddress(void **) override;
    virtual Zcad::ErrorStatus writeAddress(const void *) override;

    virtual Zcad::ErrorStatus seek(ZSoft::Int64 offset, int method) override;
    virtual ZSoft::Int64      tell() const override;

    virtual Zcad::ErrorStatus addReferences(ZcDbIdRefQueue&) override;
    virtual              bool usesReferences() const override;
    virtual ZcDbFilerController& controller() const override;

    virtual bool              getNextOwnedObject(ZcDbObjectId& id);
    virtual bool              moreOwnedObjects() const;

protected:
    ZcDbDeepCloneFiler(ZcDbSystemInternals*);
private:
    ZcDbImpDeepCloneFiler*      mpImpFiler;
};

class ZCDB_PORT ZcDbWblockCloneFiler: public  ZcDbDeepCloneFiler
{
    friend class ZcDbSystemInternals;
public:
    ZCRX_DECLARE_MEMBERS(ZcDbWblockCloneFiler);

    ZcDbWblockCloneFiler();

    virtual Zcad::ErrorStatus addReferences(ZcDbIdRefQueue&) override;
    virtual              bool usesReferences() const override;

    virtual bool              getNextHardObject(ZcDbObjectId& id);
    virtual bool              moreHardObjects() const;

    virtual ZcDb::FilerType   filerType() const override;
};

#pragma pack (pop)
#endif
