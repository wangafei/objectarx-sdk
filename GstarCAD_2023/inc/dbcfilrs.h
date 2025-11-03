/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBCFILERS_H
#define GD_DBCFILERS_H 1

#include "dbfiler.h"
#pragma pack (push, 8)

class GcDbWblockCloneFiler;
class GcDbImpDeepCloneFiler;

class GCDB_PORT GcDbDeepCloneFiler : public GcDbDwgFiler
{
  friend class GcDbSystemInternals;
public:
  GCRX_DECLARE_MEMBERS(GcDbDeepCloneFiler);
  GcDbDeepCloneFiler();
  ~GcDbDeepCloneFiler();

  Gcad::ErrorStatus filerStatus() const override;
  GcDb::FilerType   filerType() const override;
  void              setFilerStatus(Gcad::ErrorStatus) override;
  void              resetFilerStatus() override;

  Gcad::ErrorStatus readHardOwnershipId(GcDbHardOwnershipId*) override;
  Gcad::ErrorStatus writeHardOwnershipId(const GcDbHardOwnershipId&) override;

  Gcad::ErrorStatus readSoftOwnershipId(GcDbSoftOwnershipId*) override;
  Gcad::ErrorStatus writeSoftOwnershipId(const GcDbSoftOwnershipId&) override;

  Gcad::ErrorStatus readHardPointerId(GcDbHardPointerId*) override;
  Gcad::ErrorStatus writeHardPointerId(const GcDbHardPointerId&) override;

  Gcad::ErrorStatus readSoftPointerId(GcDbSoftPointerId*) override;
  Gcad::ErrorStatus writeSoftPointerId(const GcDbSoftPointerId&) override;

  Gcad::ErrorStatus readInt8(Gsoft::Int8 *) override;
  Gcad::ErrorStatus writeInt8(Gsoft::Int8) override;

  Gcad::ErrorStatus readString(GCHAR **) override;
  Gcad::ErrorStatus writeString(const GCHAR *) override;

  Gcad::ErrorStatus readString(GcString &) override;
  Gcad::ErrorStatus writeString(const GcString &) override;

  Gcad::ErrorStatus readBChunk(gds_binary*) override;
  Gcad::ErrorStatus writeBChunk(const gds_binary&) override;

  Gcad::ErrorStatus readGcDbHandle(GcDbHandle*) override;
  Gcad::ErrorStatus writeGcDbHandle(const GcDbHandle&) override;

  Gcad::ErrorStatus readInt64(Gsoft::Int64*) override;
  Gcad::ErrorStatus writeInt64(Gsoft::Int64) override;

  Gcad::ErrorStatus readInt32(Gsoft::Int32*) override;
  Gcad::ErrorStatus writeInt32(Gsoft::Int32) override;

  Gcad::ErrorStatus readInt16(Gsoft::Int16*) override;
  Gcad::ErrorStatus writeInt16(Gsoft::Int16) override;

  Gcad::ErrorStatus readUInt64(Gsoft::UInt64*) override;
  Gcad::ErrorStatus writeUInt64(Gsoft::UInt64) override;

  Gcad::ErrorStatus readUInt32(Gsoft::UInt32*) override;
  Gcad::ErrorStatus writeUInt32(Gsoft::UInt32) override;

  Gcad::ErrorStatus readUInt16(Gsoft::UInt16*) override;
  Gcad::ErrorStatus writeUInt16(Gsoft::UInt16) override;

  Gcad::ErrorStatus readUInt8(Gsoft::UInt8*) override;
  Gcad::ErrorStatus writeUInt8(Gsoft::UInt8) override;

  Gcad::ErrorStatus readBoolean(Gsoft::Boolean*) override;
  Gcad::ErrorStatus writeBoolean(Gsoft::Boolean) override;

  Gcad::ErrorStatus readBool(bool*) override;
  Gcad::ErrorStatus writeBool(bool) override;

  Gcad::ErrorStatus readDouble(double*) override;
  Gcad::ErrorStatus writeDouble(double) override;

  Gcad::ErrorStatus readPoint2d(GcGePoint2d*) override;
  Gcad::ErrorStatus writePoint2d(const GcGePoint2d&) override;

  Gcad::ErrorStatus readPoint3d(GcGePoint3d*) override;
  Gcad::ErrorStatus writePoint3d(const GcGePoint3d&) override;

  Gcad::ErrorStatus readVector2d(GcGeVector2d*) override;
  Gcad::ErrorStatus writeVector2d(const GcGeVector2d&) override;

  Gcad::ErrorStatus readVector3d(GcGeVector3d*) override;
  Gcad::ErrorStatus writeVector3d(const GcGeVector3d&) override;

  Gcad::ErrorStatus readScale3d(GcGeScale3d*) override;
  Gcad::ErrorStatus writeScale3d(const GcGeScale3d&) override;

  Gcad::ErrorStatus readBytes(void*, Gsoft::UIntPtr) override;
  Gcad::ErrorStatus writeBytes(const void*, Gsoft::UIntPtr) override;

  Gcad::ErrorStatus readAddress(void **) override;
  Gcad::ErrorStatus writeAddress(const void *) override;

  Gcad::ErrorStatus seek(Gsoft::Int64 nOffset, int nMethod) override;
  Gsoft::Int64      tell() const override;

  Gcad::ErrorStatus addReferences(GcDbIdRefQueue&) override;
  bool usesReferences() const override;
  GcDbFilerController& controller() const override;

  virtual bool getNextOwnedObject(GcDbObjectId& id);
  virtual bool moreOwnedObjects() const;

protected:
  GcDbDeepCloneFiler(GcDbSystemInternals*);
private:
  GcDbImpDeepCloneFiler* mpImpFiler;
};

class GCDB_PORT GcDbWblockCloneFiler : public GcDbDeepCloneFiler
{
  friend class GcDbSystemInternals;
public:
  GCRX_DECLARE_MEMBERS(GcDbWblockCloneFiler);

  GcDbWblockCloneFiler();

  virtual Gcad::ErrorStatus addReferences(GcDbIdRefQueue&) override;
  virtual              bool usesReferences() const override;

  virtual bool              getNextHardObject(GcDbObjectId& id);
  virtual bool              moreHardObjects() const;

  GcDb::FilerType   filerType() const override;
};

#pragma pack (pop)
#endif