/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBFILER_H
#define GD_DBFILER_H

#include <stdarg.h>
#include "GdGChar.h"
#include "gcdb.h"
#include "rxobject.h"
#include "rxboiler.h"

#pragma pack (push, 8)

class GcDbAuditInfo;
class GcDbDatabase;
class GcDbFilerController;
class GcDbHandle;
class GcDbHardOwnershipId;
class GcDbSoftOwnershipId;
class GcDbHardPointerId;
class GcDbSoftPointerId;
class GcDbIdRefQueue;
class GcDbObjectId;
class GcGePoint2d;
class GcGePoint3d;
class GcGeScale3d;
class GcGeVector2d;
class GcGeVector3d;
class GcString;
struct resbuf;
struct gds_binary;

class GCDB_PORT GcDbDwgFiler : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDwgFiler);
protected:
  GcDbDwgFiler();
public:
  ~GcDbDwgFiler();

  virtual  Gcad::ErrorStatus filerStatus() const = 0;
  virtual  GcDb::FilerType   filerType() const = 0;
  virtual void               setFilerStatus(Gcad::ErrorStatus es) = 0;
  virtual void               resetFilerStatus() = 0;

  virtual  Gcad::ErrorStatus  dwgVersion(GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer) const;
  virtual  Gcad::ErrorStatus  extendedDwgMaintenanceReleaseVersion(
    GcDb::MaintenanceReleaseVersion& maintVer) const;

  virtual Gcad::ErrorStatus   readHardOwnershipId(GcDbHardOwnershipId* pVal) = 0;
  virtual Gcad::ErrorStatus   writeHardOwnershipId(const GcDbHardOwnershipId& val) = 0;

  virtual Gcad::ErrorStatus   readSoftOwnershipId(GcDbSoftOwnershipId* pVal) = 0;
  virtual Gcad::ErrorStatus   writeSoftOwnershipId(const GcDbSoftOwnershipId& val) = 0;

  virtual Gcad::ErrorStatus   readHardPointerId(GcDbHardPointerId* pVal) = 0;
  virtual Gcad::ErrorStatus   writeHardPointerId(const GcDbHardPointerId& val) = 0;

  virtual Gcad::ErrorStatus   readSoftPointerId(GcDbSoftPointerId* pVal) = 0;
  virtual Gcad::ErrorStatus   writeSoftPointerId(const GcDbSoftPointerId& val) = 0;

  virtual Gcad::ErrorStatus   readInt8(Gsoft::Int8* pVal) = 0;
  virtual Gcad::ErrorStatus   writeInt8(Gsoft::Int8 val) = 0;

  virtual Gcad::ErrorStatus   readString(GCHAR** pVal) = 0;
  virtual Gcad::ErrorStatus   writeString(const GCHAR* pVal) = 0;

  virtual Gcad::ErrorStatus   readString(GcString& val) = 0;
  virtual Gcad::ErrorStatus   writeString(const GcString& pVal) = 0;

  virtual Gcad::ErrorStatus   readBChunk(gds_binary* pVal) = 0;
  virtual Gcad::ErrorStatus   writeBChunk(const gds_binary&) = 0;

  virtual Gcad::ErrorStatus   readGcDbHandle(GcDbHandle* pVal) = 0;
  virtual Gcad::ErrorStatus   writeGcDbHandle(const GcDbHandle& val) = 0;

  virtual Gcad::ErrorStatus   readInt64(Gsoft::Int64* pVal) = 0;
  virtual Gcad::ErrorStatus   writeInt64(Gsoft::Int64 val) = 0;

  virtual Gcad::ErrorStatus   readInt32(Gsoft::Int32* pVal) = 0;
  virtual Gcad::ErrorStatus   writeInt32(Gsoft::Int32 val) = 0;

  virtual Gcad::ErrorStatus   readInt16(Gsoft::Int16* pVal) = 0;
  virtual Gcad::ErrorStatus   writeInt16(Gsoft::Int16 val) = 0;

  virtual Gcad::ErrorStatus   readUInt64(Gsoft::UInt64* pVal) = 0;
  virtual Gcad::ErrorStatus   writeUInt64(Gsoft::UInt64 val) = 0;

  virtual Gcad::ErrorStatus   readUInt32(Gsoft::UInt32* pVal) = 0;
  virtual Gcad::ErrorStatus   writeUInt32(Gsoft::UInt32 val) = 0;

  virtual Gcad::ErrorStatus   readUInt16(Gsoft::UInt16* pVal) = 0;
  virtual Gcad::ErrorStatus   writeUInt16(Gsoft::UInt16 val) = 0;

  virtual Gcad::ErrorStatus   readUInt8(Gsoft::UInt8* pVal) = 0;
  virtual Gcad::ErrorStatus   writeUInt8(Gsoft::UInt8 val) = 0;

  virtual Gcad::ErrorStatus   readBoolean(Gsoft::Boolean* pVal) = 0;
  virtual Gcad::ErrorStatus   writeBoolean(Gsoft::Boolean val) = 0;

  virtual Gcad::ErrorStatus   readBool(bool* pVal) = 0;
  virtual Gcad::ErrorStatus   writeBool(bool val) = 0;

  virtual Gcad::ErrorStatus   readDouble(double* pVal) = 0;
  virtual Gcad::ErrorStatus   writeDouble(double val) = 0;

  virtual Gcad::ErrorStatus   readPoint2d(GcGePoint2d* pVal) = 0;
  virtual Gcad::ErrorStatus   writePoint2d(const GcGePoint2d& val) = 0;

  virtual Gcad::ErrorStatus   readPoint3d(GcGePoint3d* pVal) = 0;
  virtual Gcad::ErrorStatus   writePoint3d(const GcGePoint3d& val) = 0;

  virtual Gcad::ErrorStatus   readVector2d(GcGeVector2d* pVal) = 0;
  virtual Gcad::ErrorStatus   writeVector2d(const GcGeVector2d& val) = 0;

  virtual Gcad::ErrorStatus   readVector3d(GcGeVector3d* pVal) = 0;
  virtual Gcad::ErrorStatus   writeVector3d(const GcGeVector3d& val) = 0;

  virtual Gcad::ErrorStatus   readScale3d(GcGeScale3d* pVal) = 0;
  virtual Gcad::ErrorStatus   writeScale3d(const GcGeScale3d& val) = 0;

  virtual Gcad::ErrorStatus   readBytes(void* pDest, Gsoft::UIntPtr nBytes) = 0;
  virtual Gcad::ErrorStatus   writeBytes(const void* pSrc, Gsoft::UIntPtr nBytes) = 0;

  virtual Gcad::ErrorStatus   readAddress(void ** pVal);
  virtual Gcad::ErrorStatus   writeAddress(const void * pVal);

  Gcad::ErrorStatus   readItem(GcDbHardOwnershipId* pId);
  Gcad::ErrorStatus   writeItem(const GcDbHardOwnershipId& id);

  Gcad::ErrorStatus   readItem(GcDbSoftOwnershipId* pId);
  Gcad::ErrorStatus   writeItem(const GcDbSoftOwnershipId& id);

  Gcad::ErrorStatus   readItem(GcDbHardPointerId* pId);
  Gcad::ErrorStatus   writeItem(const GcDbHardPointerId& id);

  Gcad::ErrorStatus   readItem(GcDbSoftPointerId* pId);
  Gcad::ErrorStatus   writeItem(const GcDbSoftPointerId& id);

  Gcad::ErrorStatus   readItem(GCHAR** pVal);
  Gcad::ErrorStatus   writeItem(const GCHAR* val);
  Gcad::ErrorStatus   writeItem(const GcString& val);
  Gcad::ErrorStatus   readItem(gds_binary* pVal);
  Gcad::ErrorStatus   writeItem(const gds_binary& val);

  Gcad::ErrorStatus   readItem(GcDbHandle* pVal);
  Gcad::ErrorStatus   writeItem(const GcDbHandle& val);

  Gcad::ErrorStatus   readItem(Gsoft::Int32* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::Int32 val);

  Gcad::ErrorStatus   readItem(Gsoft::Int16* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::Int16 val);

  Gcad::ErrorStatus   readItem(Gsoft::Int8* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::Int8 val);

  Gcad::ErrorStatus   readItem(Gsoft::UInt32* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::UInt32 val);

  Gcad::ErrorStatus   readItem(Gsoft::UInt16* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::UInt16 val);

  Gcad::ErrorStatus   readItem(Gsoft::UInt8* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::UInt8 val);

  Gcad::ErrorStatus   readItem(Gsoft::Boolean* pVal);
  Gcad::ErrorStatus   writeItem(Gsoft::Boolean val);

#if !defined(Gsoft_Boolean_is_bool) 
#error "Unexpected Gsoft::Boolean is not bool"
  Gcad::ErrorStatus   readItem(bool* pVal);
  Gcad::ErrorStatus   writeItem(bool val);
#endif

  Gcad::ErrorStatus   readItem(double* pVal);
  Gcad::ErrorStatus   writeItem(double val);

  Gcad::ErrorStatus   readItem(GcGePoint2d* pVal);
  Gcad::ErrorStatus   writeItem(const GcGePoint2d& val);

  Gcad::ErrorStatus   readItem(GcGePoint3d* pVal);
  Gcad::ErrorStatus   writeItem(const GcGePoint3d& val);

  Gcad::ErrorStatus   readItem(GcGeVector2d* pVal);
  Gcad::ErrorStatus   writeItem(const GcGeVector2d& val);

  Gcad::ErrorStatus   readItem(GcGeVector3d* pVal);
  Gcad::ErrorStatus   writeItem(const GcGeVector3d& val);

  Gcad::ErrorStatus   readItem(GcGeScale3d* pVal);
  Gcad::ErrorStatus   writeItem(const GcGeScale3d& val);

  Gcad::ErrorStatus   readItem(void* pDest, Gsoft::UIntPtr nBytes);
  Gcad::ErrorStatus   writeItem(const void* pSrc, Gsoft::UIntPtr nBytes);

  Gcad::ErrorStatus   readItem(void** pp);
  Gcad::ErrorStatus   writeItem(const void* p);

  virtual Gcad::ErrorStatus   seek(Gsoft::Int64 nOffset, int nMethod) = 0;
  virtual Gsoft::Int64        tell() const = 0;
  virtual Gcad::ErrorStatus   addReferences(GcDbIdRefQueue&);
  virtual              bool   usesReferences() const;
  virtual GcDbAuditInfo *     getAuditInfo() const;
  virtual GcDbFilerController& controller() const;

private:
  GcDbDwgFiler & operator = (const GcDbDwgFiler &);
  GcDbFilerController& mController;
};

class GCDB_PORT GcDbDxfFiler : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDxfFiler);

  virtual int               rewindFiler() = 0;
  virtual Gcad::ErrorStatus filerStatus() const = 0;
  virtual void              resetFilerStatus() = 0;
  virtual Gcad::ErrorStatus setError(Gcad::ErrorStatus es, const GCHAR* errMsg, ...);
  virtual Gcad::ErrorStatus setError(const GCHAR* errMsg, ...);
  virtual const GCHAR*      errorMessage() const;
  virtual  GcDb::FilerType  filerType() const = 0;
  virtual  GcDbDatabase*    database() const = 0;

  virtual  Gcad::ErrorStatus  dwgVersion(GcDb::GcDbDwgVersion& ver,
    GcDb::MaintenanceReleaseVersion& maintVer) const;
  virtual  Gcad::ErrorStatus  extendedDwgMaintenanceReleaseVersion(
    GcDb::MaintenanceReleaseVersion& maintVer) const;
  virtual int                 precision() const;
  virtual void                setPrecision(int prec);

  enum { kDfltPrec = -1, kMaxPrec = 16 };

  virtual Gcad::ErrorStatus readResBuf(resbuf* pRb);
  virtual Gcad::ErrorStatus writeResBuf(const resbuf& rb);
  virtual Gcad::ErrorStatus writeObjectId(GcDb::DxfCode code, const GcDbObjectId& id) = 0;
  virtual Gcad::ErrorStatus writeInt8(GcDb::DxfCode code, Gsoft::Int8) = 0;
  virtual Gcad::ErrorStatus writeString(GcDb::DxfCode code, const GCHAR* pVal) = 0;
  virtual Gcad::ErrorStatus writeString(GcDb::DxfCode code, const GcString& pVal) = 0;
  virtual Gcad::ErrorStatus writeBChunk(GcDb::DxfCode code, const gds_binary& val) = 0;
  virtual Gcad::ErrorStatus writeGcDbHandle(GcDb::DxfCode code, const GcDbHandle& val) = 0;
  virtual Gcad::ErrorStatus writeInt64(GcDb::DxfCode code, Gsoft::Int64 val) = 0;
  virtual Gcad::ErrorStatus writeInt32(GcDb::DxfCode code, Gsoft::Int32 val) = 0;
  virtual Gcad::ErrorStatus writeInt16(GcDb::DxfCode code, Gsoft::Int16 val) = 0;
  virtual Gcad::ErrorStatus writeUInt64(GcDb::DxfCode code, Gsoft::UInt64 val) = 0;
  virtual Gcad::ErrorStatus writeUInt32(GcDb::DxfCode code, Gsoft::UInt32 val) = 0;
  virtual Gcad::ErrorStatus writeUInt16(GcDb::DxfCode code, Gsoft::UInt16 val) = 0;
  virtual Gcad::ErrorStatus writeUInt8(GcDb::DxfCode code, Gsoft::UInt8 val) = 0;
  virtual Gcad::ErrorStatus writeBoolean(GcDb::DxfCode code, Gsoft::Boolean val) = 0;
  virtual Gcad::ErrorStatus writeBool(GcDb::DxfCode code, bool val) = 0;
  virtual Gcad::ErrorStatus writeDouble(GcDb::DxfCode code, double val, int prec = kDfltPrec) = 0;
  virtual Gcad::ErrorStatus writePoint2d(GcDb::DxfCode code, const GcGePoint2d& val, int prec = kDfltPrec) = 0;
  virtual Gcad::ErrorStatus writePoint3d(GcDb::DxfCode code, const GcGePoint3d& val, int prec = kDfltPrec) = 0;
  virtual Gcad::ErrorStatus writeVector2d(GcDb::DxfCode code, const GcGeVector2d& val, int prec = kDfltPrec) = 0;
  virtual Gcad::ErrorStatus writeVector3d(GcDb::DxfCode code, const GcGeVector3d& val, int prec = kDfltPrec) = 0;
  virtual Gcad::ErrorStatus writeScale3d(GcDb::DxfCode code, const GcGeScale3d& val, int prec = kDfltPrec) = 0;

  Gcad::ErrorStatus readItem(resbuf* pItem);
  Gcad::ErrorStatus writeItem(const resbuf& pItem);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcDbObjectId& id);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GCHAR* val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcString& val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const gds_binary& val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcDbHandle& val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::Int32 val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::Int16 val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::Int8 val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::UInt32 val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::UInt16 val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::UInt8 val);

#ifndef Gsoft_Boolean_is_bool
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, Gsoft::Boolean val);
#endif

  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, bool val);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, double val, int = kDfltPrec);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcGePoint2d& val, int prec = kDfltPrec);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcGePoint3d& val, int prec = kDfltPrec);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcGeVector2d& val, int prec = kDfltPrec);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcGeVector3d& val, int prec = kDfltPrec);
  Gcad::ErrorStatus writeItem(GcDb::DxfCode dc, const GcGeScale3d& val, int prec = kDfltPrec);
  virtual Gcad::ErrorStatus writeXDataStart();
  virtual bool              includesDefaultValues() const = 0;
  virtual Gcad::ErrorStatus pushBackItem();
  virtual bool              atEOF();
  virtual bool              atSubclassData(const GCHAR* subClassName);
  virtual bool              atExtendedData();
  virtual bool              atEndOfObject();
  virtual void              haltAtClassBoundaries(bool halt);
  virtual Gcad::ErrorStatus writeEmbeddedObjectStart();
  virtual bool              atEmbeddedObjectStart();

  virtual double elevation() const;
  virtual double thickness() const;

  virtual bool              isModifyingExistingObject() const;

  GcDbDxfFiler();
  ~GcDbDxfFiler();
  GcDbFilerController& controller() const;

private:
  GcDbDxfFiler & operator = (const GcDbDxfFiler &);
  GcDbFilerController& mController;
  virtual Gcad::ErrorStatus setVAError(Gcad::ErrorStatus, const GCHAR *, va_list);
};

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcDbHardOwnershipId* pId)
{
  return readHardOwnershipId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcDbHardOwnershipId& pId)
{
  return writeHardOwnershipId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcDbSoftOwnershipId* pId)
{
  return readSoftOwnershipId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcDbSoftOwnershipId& pId)
{
  return writeSoftOwnershipId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcDbHardPointerId* pId)
{
  return readHardPointerId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcDbHardPointerId& pId)
{
  return writeHardPointerId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcDbSoftPointerId* pId)
{
  return readSoftPointerId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcDbSoftPointerId& pId)
{
  return writeSoftPointerId(pId);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GCHAR ** pVal)
{
  return readString(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GCHAR * val)
{
  return writeString(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(gds_binary* pVal)
{
  return readBChunk(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const gds_binary& val)
{
  return writeBChunk(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcDbHandle* pVal)
{
  return readGcDbHandle(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcDbHandle& val)
{
  return writeGcDbHandle(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::Int32* pVal)
{
  return readInt32(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::Int32 val)
{
  return writeInt32(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::Int16* pVal)
{
  return readInt16(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::Int16 val)
{
  return writeInt16(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::Int8 * pVal)
{
  return this->readInt8(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::Int8 val)
{
  return this->writeInt8(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::UInt32* pVal)
{
  return readUInt32(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::UInt32 val)
{
  return writeUInt32(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::UInt16* pVal)
{
  return readUInt16(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::UInt16 val)
{
  return writeUInt16(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::UInt8* pVal)
{
  return readUInt8(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::UInt8 val)
{
  return writeUInt8(val);
}

#if !defined(Gsoft_Boolean_is_bool)
inline Gcad::ErrorStatus GcDbDwgFiler::readItem(Gsoft::Boolean* pVal)
{
  return readBoolean(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(Gsoft::Boolean val)
{
  return writeBoolean(val);
}
#endif

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(bool* pVal)
{
  return readBool(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(bool val)
{
  return writeBool(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(double* pVal)
{
  return readDouble(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(double val)
{
  return writeDouble(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcGePoint2d* pVal)
{
  return readPoint2d(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcGePoint2d& val)
{
  return writePoint2d(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcGePoint3d* pVal)
{
  return readPoint3d(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcGePoint3d& val)
{
  return writePoint3d(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcGeVector2d* pVal)
{
  return readVector2d(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcGeVector2d& val)
{
  return writeVector2d(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcGeVector3d* pVal)
{
  return readVector3d(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcGeVector3d& val)
{
  return writeVector3d(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(GcGeScale3d* pVal)
{
  return readScale3d(pVal);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcGeScale3d& val)
{
  return writeScale3d(val);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(void *buf, Gsoft::UIntPtr cnt)
{
  return readBytes(buf, cnt);
}

inline Gcad::ErrorStatus
GcDbDwgFiler::writeItem(const void *buf, Gsoft::UIntPtr cnt)
{
  return writeBytes(buf, cnt);
}

inline Gcad::ErrorStatus GcDbDwgFiler::readItem(void **pp)
{
  return readAddress(pp);
}

inline Gcad::ErrorStatus
GcDbDwgFiler::writeItem(const void *p)
{
  return writeAddress(p);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::readItem(resbuf* pVal)
{
  return readResBuf(pVal);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(const resbuf& val)
{
  return writeResBuf(val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcDbObjectId& id)
{
  return writeObjectId(dc, id);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GCHAR * val)
{
  return writeString(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const gds_binary& val)
{
  return writeBChunk(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcDbHandle& val)
{
  return writeGcDbHandle(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::Int32 val)
{
  return writeInt32(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::Int16 val)
{
  return writeInt16(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::Int8 val)
{
  return this->writeInt8(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::UInt32 val)
{
  return writeUInt32(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::UInt16 val)
{
  return writeUInt16(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::UInt8 val)
{
  return writeUInt8(dc, val);
}

#if !defined(Gsoft_Boolean_is_bool) 
inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, Gsoft::Boolean val)
{
  return writeBoolean(dc, val);
}
#endif

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, bool val)
{
  return writeBool(dc, val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, double val, int prec)
{
  return writeDouble(dc, val, prec);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcGePoint2d& val, int prec)
{
  return writePoint2d(dc, val, prec);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcGePoint3d& val, int prec)
{
  return writePoint3d(dc, val, prec);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcGeVector2d& val, int prec)
{
  return writeVector2d(dc, val, prec);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcGeVector3d& val, int prec)
{
  return writeVector3d(dc, val, prec);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcGeScale3d& val, int prec)
{
  return writeScale3d(dc, val, prec);
}

inline Gcad::ErrorStatus GcDbDwgFiler::writeItem(const GcString & val)
{
  return writeString(val);
}

inline Gcad::ErrorStatus
GcDbDxfFiler::writeItem(GcDb::DxfCode dc, const GcString & val)
{
  return writeString(dc, val);
}

#pragma pack (pop)

#endif