/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBUNDERLAYREF_H
#define GCDB_DBUNDERLAYREF_H

#pragma once

#include "dbmain.h"
#include "GcString.h"

#pragma pack (push, 8)

class GcUnderlayLayer;

class GSOFT_NO_VTABLE GCDB_PORT GcDbUnderlayReference : public GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbUnderlayReference);
  ~GcDbUnderlayReference() = 0;
  GcGePoint3d       position() const;
  Gcad::ErrorStatus setPosition(const GcGePoint3d& position);
  GcGeScale3d       scaleFactors() const;
  Gcad::ErrorStatus setScaleFactors(const GcGeScale3d& scale);
  double            rotation() const;
  Gcad::ErrorStatus setRotation(double rotation);
  GcGeVector3d      normal() const;
  Gcad::ErrorStatus setNormal(const GcGeVector3d& normal);
  GcGeMatrix3d transform() const;
  Gcad::ErrorStatus setTransform(const GcGeMatrix3d& transform);
  GcDbObjectId      definitionId() const;
  Gcad::ErrorStatus setDefinitionId(GcDbObjectId id);
  Gcad::ErrorStatus  setWidth(double width);
  Gcad::ErrorStatus  width(double& width) const;
  Gcad::ErrorStatus  setHeight(double width);
  Gcad::ErrorStatus  height(double& width) const;
  const GcGePoint2dArray&  clipBoundary() const;
  Gcad::ErrorStatus        setClipBoundary(const GcGePoint2dArray& clipBoundary);
  bool                     isClipped() const;
  Gcad::ErrorStatus        setIsClipped(bool value);
  Gsoft::UInt8      contrast() const;
  Gcad::ErrorStatus setContrast(Gsoft::UInt8 value);
  Gsoft::UInt8      fade() const;
  Gcad::ErrorStatus setFade(Gsoft::UInt8 value);
  bool              isOn() const;
  Gcad::ErrorStatus setIsOn(bool value);
  bool              isMonochrome() const;
  Gcad::ErrorStatus setIsMonochrome(bool value);
  bool              isAdjustedForBackground() const;
  Gcad::ErrorStatus setIsAdjustedForBackground(bool value);
  virtual bool isFrameVisible() const;
  virtual bool isFramePlottable() const;
  Gsoft::UInt32 underlayLayerCount() const;
  Gcad::ErrorStatus getUnderlayLayer(int index, GcUnderlayLayer& layer) const;
  Gcad::ErrorStatus setUnderlayLayer(int index, const GcUnderlayLayer& layer);
  static Gsoft::UInt8 contrastLowerLimit();
  static Gsoft::UInt8 contrastUpperLimit();
  static Gsoft::UInt8 contrastDefault();
  static Gsoft::UInt8 fadeLowerLimit();
  static Gsoft::UInt8 fadeUpperLimit();
  static Gsoft::UInt8 fadeDefault();
  bool isClipInverted() const;
  Gcad::ErrorStatus setClipInverted(bool value);
  Gcad::ErrorStatus generateClipBoundaryFromPline(GcDbObjectId polyId);
};

class GCDB_PORT GcDbDwfReference : public GcDbUnderlayReference
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDwfReference);
  GcDbDwfReference();
  ~GcDbDwfReference();

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbDgnReference : public GcDbUnderlayReference
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDgnReference);
  GcDbDgnReference();
  ~GcDbDgnReference();

  void setXrefDepth(int depth);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbPdfReference : public GcDbUnderlayReference
{
public:
  GCDB_DECLARE_MEMBERS(GcDbPdfReference);
  GcDbPdfReference();
  ~GcDbPdfReference();
protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
public:
  static Gsoft::UInt8 contrastDefault();
  static Gsoft::UInt8 fadeDefault();
};

#pragma pack (pop)

#endif