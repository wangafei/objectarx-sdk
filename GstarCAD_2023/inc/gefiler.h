/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEFILER_H
#define GC_GEFILER_H   

#include "GdGChar.h"
#include "gegbl.h"
#include "gcdb.h"
#include "gcadstrc.h"
#pragma pack (push, 8)


class GcDbDwgFiler;
class GcGePoint2d;
class GcGePoint3d;
class GcGeVector2d;
class GcGeVector3d;
class GcString;

class
  GSOFT_NO_VTABLE
  GE_DLLDATAEXIMP
  GcGeFiler
{
protected:
  GcGeFiler();
public:
  virtual
    Gcad::ErrorStatus      readBoolean(Gsoft::Boolean*) = 0;
  virtual
    Gcad::ErrorStatus      writeBoolean(Gsoft::Boolean) = 0;

  virtual
    Gcad::ErrorStatus      readBool(bool*) = 0;
  virtual
    Gcad::ErrorStatus      writeBool(bool) = 0;

  virtual
    Gcad::ErrorStatus      readSignedByte(char *) = 0;
  virtual
    Gcad::ErrorStatus      writeSignedByte(char) = 0;

  virtual
    Gcad::ErrorStatus      readString(GcString &) = 0;
  virtual
    Gcad::ErrorStatus      writeString(const GcString &) = 0;

  virtual
    Gcad::ErrorStatus      readShort(short*) = 0;
  virtual
    Gcad::ErrorStatus      writeShort(short) = 0;

  virtual
    Gcad::ErrorStatus      readLong(Gsoft::Int32*) = 0;
  virtual
    Gcad::ErrorStatus      writeLong(Gsoft::Int32) = 0;

  virtual
    Gcad::ErrorStatus      readUChar(unsigned char*) = 0;
  virtual
    Gcad::ErrorStatus      writeUChar(unsigned char) = 0;

  virtual
    Gcad::ErrorStatus      readUShort(unsigned short*) = 0;
  virtual
    Gcad::ErrorStatus      writeUShort(unsigned short) = 0;

  virtual
    Gcad::ErrorStatus      readULong(Gsoft::UInt32*) = 0;
  virtual
    Gcad::ErrorStatus      writeULong(Gsoft::UInt32) = 0;

  virtual
    Gcad::ErrorStatus      readDouble(double*) = 0;
  virtual
    Gcad::ErrorStatus      writeDouble(double) = 0;

  virtual
    Gcad::ErrorStatus      readPoint2d(GcGePoint2d*) = 0;
  virtual
    Gcad::ErrorStatus      writePoint2d(const GcGePoint2d&) = 0;

  virtual
    Gcad::ErrorStatus      readPoint3d(GcGePoint3d*) = 0;
  virtual
    Gcad::ErrorStatus      writePoint3d(const GcGePoint3d&) = 0;

  virtual
    Gcad::ErrorStatus      readVector2d(GcGeVector2d*) = 0;
  virtual
    Gcad::ErrorStatus      writeVector2d(const GcGeVector2d&) = 0;

  virtual
    Gcad::ErrorStatus      readVector3d(GcGeVector3d*) = 0;
  virtual
    Gcad::ErrorStatus      writeVector3d(const GcGeVector3d&) = 0;

  virtual
    GcDbDwgFiler*          dwgFiler();

  virtual
    Gcad::ErrorStatus      readBytes(void*, Gsoft::UInt32) = 0;
  virtual
    Gcad::ErrorStatus      writeBytes(const void*, Gsoft::UInt32) = 0;
};

inline
GcDbDwgFiler* GcGeFiler::dwgFiler()
{
  return NULL;
}


#pragma pack (pop)
#endif