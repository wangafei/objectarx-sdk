#pragma once

#include "../OdaCommon.h"
#include "../Ge/GeExport.h"

#include "../TD_PackPush.h"

class OdDbDwgFiler;
class OdGePoint2d;
class OdGePoint3d;
class OdGeVector2d;
class OdGeVector3d;

class GE_TOOLKIT_EXPORT OdGeFiler
{
public:
  // Read/write functions.
  //
  virtual
    OdResult      readBoolean(OdBool*) = 0;
  virtual
    OdResult      writeBoolean(OdBool) = 0;

  virtual
    OdResult      readBool(bool*) = 0;
  virtual
    OdResult      writeBool(bool) = 0;

  virtual
    OdResult      readSignedByte(char *) = 0;
  virtual
    OdResult      writeSignedByte(char) = 0;

  virtual
    OdResult      readString(OdString &) = 0;
  virtual
    OdResult      writeString(const OdString &) = 0;

  virtual
    OdResult      readShort(short*) = 0;
  virtual
    OdResult      writeShort(short) = 0;

  virtual
    OdResult      readLong(long*) = 0;
  virtual
    OdResult      writeLong(long) = 0;

  // Unicode: this is assumed to be a binary value, not a text character!
  virtual
    OdResult      readUChar(unsigned char*) = 0;
  virtual
    OdResult      writeUChar(unsigned char) = 0;
  virtual
    OdResult      readUShort(unsigned short*) = 0;
  virtual
    OdResult      writeUShort(unsigned short) = 0;

  virtual
    OdResult      readULong(unsigned long*) = 0;
  virtual
    OdResult      writeULong(unsigned long) = 0;

  virtual
    OdResult      readDouble(double*) = 0;
  virtual
    OdResult      writeDouble(double) = 0;

  virtual
    OdResult      readPoint2d(OdGePoint2d*) = 0;
  virtual
    OdResult      writePoint2d(const OdGePoint2d&) = 0;

  virtual
    OdResult      readPoint3d(OdGePoint3d*) = 0;
  virtual
    OdResult      writePoint3d(const OdGePoint3d&) = 0;

  virtual
    OdResult      readVector2d(OdGeVector2d*) = 0;
  virtual
    OdResult      writeVector2d(const OdGeVector2d&) = 0;

  virtual
    OdResult      readVector3d(OdGeVector3d*) = 0;
  virtual
    OdResult      writeVector3d(const OdGeVector3d&) = 0;

  // This method must be implemented in order to read/write 
  // external curves and surfaces (and nurb surfaces). 
  virtual
    OdDbDwgFiler*          dwgFiler();

  virtual
    OdResult      readBytes(void*, unsigned long) = 0;
  virtual
    OdResult      writeBytes(const void*, unsigned long) = 0;
};

__forceinline
OdDbDwgFiler* OdGeFiler::dwgFiler()
{
  return NULL;
}

#include "../TD_PackPop.h"