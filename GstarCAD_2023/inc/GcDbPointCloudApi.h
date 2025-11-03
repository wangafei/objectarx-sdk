/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gepnt3d.h"
#include "gevec3d.h"

class __declspec(novtable) IGcDbPointCloudDataBuffer
{
public:
  enum DataType
  {
    kIntensity = 0x00000001,
    kClassification = 0x00000002,
    kColor = 0x00000004,
    kNormal = 0x00000008,
  };

  typedef Gsoft::UInt8  RGBA[4];

  virtual ~IGcDbPointCloudDataBuffer() = 0 {};

  virtual Gsoft::UInt64 numPoints() const = 0;
  virtual const GcGePoint3d* points() const = 0;
  virtual const GcGeVector3d* normals() const = 0;
  virtual const RGBA* colors() const = 0;
  virtual const Gsoft::UInt8* intensity()  const = 0;
  virtual const Gsoft::UInt8* classifications() const = 0;
  virtual const GcGeMatrix3d& transform() const = 0;
  virtual void freeObject() = 0;
  virtual void* getBuffer() const = 0;
};

class __declspec(novtable) IGcDbPointCloudSpatialFilter
{
public:
  enum FilterResult { FILTER_INSIDE = 0, FILTER_OUTSIDE, FILTER_INTERSECTS };

  virtual ~IGcDbPointCloudSpatialFilter() = 0 {};

  virtual FilterResult testCell(const GcGePoint3d& min, const GcGePoint3d& max) const = 0;
  virtual FilterResult testPoint(const GcGePoint3d& point) const = 0;
  virtual IGcDbPointCloudSpatialFilter* transformFilter(const GcGeMatrix3d& mat) const = 0;
  virtual IGcDbPointCloudSpatialFilter* clone() const = 0;
  virtual void freeObject() = 0;
};

class __declspec(novtable) IGcDbPointCloudAttributeFilter
{
public:
  virtual ~IGcDbPointCloudAttributeFilter() = 0 {};

  virtual bool testPoint(const Gsoft::UInt8 rgba[4], Gsoft::UInt8 intensity, const float normal[3], Gsoft::UInt8 classification) const = 0;
  virtual IGcDbPointCloudAttributeFilter* clone() const = 0;
  virtual IGcDbPointCloudAttributeFilter* transformFilter(const GcGeMatrix3d& mat) const = 0;
  virtual void freeObject() = 0;
};

class __declspec(novtable) IGcDbPointCloudPointProcessor
{
public:
  enum ProcessSate
  {
    Abort,
    Continue
  };
  virtual ~IGcDbPointCloudPointProcessor() = 0 {};
  virtual ProcessSate process(const IGcDbPointCloudDataBuffer* buffer) = 0;
};