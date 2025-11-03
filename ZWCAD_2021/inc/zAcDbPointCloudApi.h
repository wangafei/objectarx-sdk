

#pragma once

#include "zgepnt3d.h"
#include "zgevec3d.h"

class __declspec(novtable) IZcDbPointCloudDataBuffer
{
public:
    enum DataType
    {
        kIntensity      = 0x00000001,
        kClassification = 0x00000002,
        kColor          = 0x00000004,
        kNormal         = 0x00000008,
    };

    typedef ZSoft::UInt8  RGBA[4];

    virtual ~IZcDbPointCloudDataBuffer() = 0 {};

    virtual ZSoft::UInt64 numPoints() const = 0;

    virtual const ZcGePoint3d* points() const = 0;

    virtual const ZcGeVector3d* normals() const = 0;

    virtual const RGBA* colors() const  = 0;

    virtual const ZSoft::UInt8* intensity()  const = 0;

    virtual const ZSoft::UInt8* classifications() const = 0;

    virtual const ZcGeMatrix3d& transform() const = 0;

    virtual void freeObject() = 0;

    virtual void* getBuffer() const = 0;
};

class __declspec(novtable) IZcDbPointCloudSpatialFilter
{
public:

    enum FilterResult { FILTER_INSIDE = 0, FILTER_OUTSIDE, FILTER_INTERSECTS };

    virtual ~IZcDbPointCloudSpatialFilter() = 0 {};

    virtual FilterResult testCell(const ZcGePoint3d& min, const ZcGePoint3d& max) const = 0;

    virtual FilterResult testPoint(const ZcGePoint3d& point) const = 0;

    virtual IZcDbPointCloudSpatialFilter* transformFilter(const ZcGeMatrix3d& mat) const = 0;

    virtual IZcDbPointCloudSpatialFilter* clone() const = 0;

    virtual void freeObject() = 0;

};

class __declspec(novtable) IZcDbPointCloudAttributeFilter
{
public:
    virtual ~IZcDbPointCloudAttributeFilter() = 0 {};

    virtual bool testPoint(const ZSoft::UInt8 rgba[4], ZSoft::UInt8 intensity, const float normal[3], ZSoft::UInt8 classification) const = 0;

    virtual IZcDbPointCloudAttributeFilter* clone() const = 0;

    virtual IZcDbPointCloudAttributeFilter* transformFilter(const ZcGeMatrix3d& mat) const = 0;

    virtual void freeObject() = 0;
};

class __declspec(novtable) IZcDbPointCloudPointProcessor
{
public:
    enum ProcessSate
    {
        Abort,
        Continue
    };
    virtual ~IZcDbPointCloudPointProcessor() = 0 {};

    virtual ProcessSate process(const IZcDbPointCloudDataBuffer* buffer) = 0;
};
