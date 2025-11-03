#pragma once

#include "zrxobject.h"
#include "zAcString.h"

class ZcPointCloudViewFrustum;
class IPointCloudFilter;

class ZCDB_PORT ZcViewFrustum
{
public:
    ZcViewFrustum();
    ~ZcViewFrustum();

    void setNearUpperRight(double x, double y, double z);
    void setNearUpperLeft(double x, double y, double z);
    void setNearLowerLeft(double x, double y, double z);
    void setNearLowerRight(double x, double y, double z);

    void setFarUpperRight(double x, double y, double z);
    void setFarUpperLeft(double x, double y, double z);
    void setFarLowerLeft(double x, double y, double z);
    void setFarLowerRight(double x, double y, double z);

    void nearUpperRight(double& x, double& y, double& z) const;
    void nearUpperLeft(double& x, double& y, double& z) const;
    void nearLowerLeft(double& x, double& y, double& z) const;
    void nearLowerRight(double& x, double& y, double& z) const;

    void farUpperRight(double& x, double& y, double& z) const;
    void farUpperLeft(double& x, double& y, double& z) const;
    void farLowerLeft(double& x, double& y, double& z) const;
    void farLowerRight(double& x, double& y, double& z) const;

    void setNearClip(bool clip);
    bool nearClip() const;

    void setFarClip(bool clip);
    bool farClip() const;

    ZcPointCloudViewFrustum* asPointCloudFrustum() const;
private:
    void* m_pData;
};

class ZCDB_PORT ZcPcPointFloat {
public:

    float m_x, m_y, m_z;

    DWORD m_argb;
};

class ZCDB_PORT ZcPcPointDouble {
public:

    double m_x, m_y, m_z;

    DWORD m_argb;
};

class ZCDB_PORT ZcPcPointAttributes
{
public:

    float   m_intensity;

    float   m_nx, m_ny, m_nz;

    BYTE    m_classification;
};

class ZCDB_PORT IZcPcDataBuffer {
public:
    virtual ~IZcPcDataBuffer()              = 0 {};

    virtual bool nativeDbl()                = 0;

    virtual bool resize(DWORD size)         = 0;

    virtual bool shrink(DWORD size)         = 0;

    virtual DWORD size() const              = 0;

    virtual ZcPcPointFloat*  floatPoints () = 0;

    virtual ZcPcPointDouble* doublePoints() = 0;

    virtual ZcPcPointAttributes* pointAttributes() = 0;

    virtual bool floatPoint  (DWORD ptIx, ZcPcPointFloat&  pt) const    = 0;

    virtual bool doublePoint (DWORD ptIx, ZcPcPointDouble& pt) const    = 0;

    virtual bool setFloatPoint  (DWORD ptIx, ZcPcPointFloat&  pt)       = 0;

    virtual bool setDoublePoint (DWORD ptIx, ZcPcPointDouble& pt)       = 0;

    virtual bool offset   (double& x, double& y, double& z) const       = 0;

    virtual bool entityTransform(ZcGeMatrix3d& matrix) const            = 0;

    virtual void copyFrom(IZcPcDataBuffer const & from)                 = 0;
};

class ZCDB_PORT IZcPcPointFilter {
public:

    virtual void doFilter(
        const IZcPcDataBuffer& inBuffer,
        IZcPcDataBuffer&       outBuffer) = 0;
};

class ZCDB_PORT IZcPcPointProcessor {
public:

    virtual bool cancel()   = 0;

    virtual void abort()    = 0;

    virtual void finished() = 0;

    virtual bool processPoints() = 0;

    virtual IZcPcPointFilter*  filter() = 0;

    IZcPcDataBuffer* buffer();

    void setBuffer(IZcPcDataBuffer* buffer);

private:
    IZcPcDataBuffer* mpBuffer;
};

ZCDB_PORT Zcad::ErrorStatus zcdbCreatePointCloudEntity(
    ZcDbEntity*& newPointCloud,
    const ZcString& indexFile,
    const ZcString& sourceFile,
    ZcGePoint3d&    location,
    double          scale = 1.0,
    double          rotation = 0.0);

ZCDB_PORT Zcad::ErrorStatus zcdbAttachPointCloudExEntity(
    ZcDbObjectId&   newPointCloudExId,
    const ZcString& pointCloudFile,
    ZcGePoint3d&    location,
    double          scale = 1.0,
    double          rotation = 0.0,
    ZcDbDatabase* pDb = NULL);

ZCDB_PORT Zcad::ErrorStatus zcdbAttachPointCloudEntity(
    ZcDbObjectId& newPointCloudId,
    const ZcString& indexFile,
    const ZcString& sourceFile,
    ZcGePoint3d&    location,
    double          scale = 1.0,
    double          rotation = 0.0,
    ZcDbDatabase*   pDb = NULL);

ZCDB_PORT Zcad::ErrorStatus zcdbModifyPointCloudDataView(
    ZcDbEntity* pEnt,
    IZcPcPointFilter* pFilter
    );

ZCDB_PORT Zcad::ErrorStatus zcdbResetPointCloudDataView(
    ZcDbEntity* pEnt
    );

ZCDB_PORT Zcad::ErrorStatus zcdbProcessPointCloudData(
    ZcDbEntity* pEnt,
    const ZcDbExtents& ext,
    int levelOfDetail,
    IZcPcPointProcessor* pCallback);

ZCDB_PORT Zcad::ErrorStatus zcdbProcessPointCloudData(
    ZcDbEntity* pEnt,
    const ZcViewFrustum& frustum,
    int levelOfDetail,
    IZcPcPointProcessor* pCallback);

ZCDB_PORT Zcad::ErrorStatus zcdbSetPointCloudFilter(
    ZcDbEntity* pEnt,
    IPointCloudFilter* pFilter);
