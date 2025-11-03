/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxobject.h"
#include "GcString.h"

class GcPointCloudViewFrustum;
class IPointCloudFilter;

class DBPOINTCLOUDOBJ_PORT GcViewFrustum
{
public:
  GcViewFrustum();
  ~GcViewFrustum();

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

  GcPointCloudViewFrustum* asPointCloudFrustum() const;
private:
  void* m_pData;
};

class DBPOINTCLOUDOBJ_PORT GcPcPointFloat {
public:
  float m_x, m_y, m_z;
  DWORD m_argb;
};

class DBPOINTCLOUDOBJ_PORT GcPcPointDouble {
public:
  double m_x, m_y, m_z;
  DWORD m_argb;
};

class DBPOINTCLOUDOBJ_PORT GcPcPointAttributes
{
public:
  float   m_intensity;
  float   m_nx, m_ny, m_nz;
  BYTE    m_classification;
};

class DBPOINTCLOUDOBJ_PORT IGcPcDataBuffer {
public:
#if !defined(WIN32) && !defined(_WIN64)
    virtual ~IGcPcDataBuffer() = 0;
#else
    virtual ~IGcPcDataBuffer() = 0 {};
#endif
  virtual bool nativeDbl() = 0;
  virtual bool resize(DWORD size) = 0;
  virtual bool shrink(DWORD size) = 0;
  virtual DWORD size() const = 0;

  virtual GcPcPointFloat*  floatPoints() = 0;
  virtual GcPcPointDouble* doublePoints() = 0;

  virtual GcPcPointAttributes* pointAttributes() = 0;

  virtual bool floatPoint(DWORD ptIx, GcPcPointFloat&  pt) const = 0;
  virtual bool doublePoint(DWORD ptIx, GcPcPointDouble& pt) const = 0;

  virtual bool setFloatPoint(DWORD ptIx, GcPcPointFloat&  pt) = 0;
  virtual bool setDoublePoint(DWORD ptIx, GcPcPointDouble& pt) = 0;

  virtual bool offset(double& x, double& y, double& z) const = 0;
  virtual bool entityTransform(GcGeMatrix3d& matrix) const = 0;

  virtual void copyFrom(IGcPcDataBuffer const & from) = 0;
};


class DBPOINTCLOUDOBJ_PORT IGcPcPointFilter {
public:
  virtual void doFilter(
    const IGcPcDataBuffer& inBuffer,
    IGcPcDataBuffer&       outBuffer) = 0;
};

class DBPOINTCLOUDOBJ_PORT IGcPcPointProcessor {
public:
  virtual bool cancel() = 0;
  virtual void abort() = 0;
  virtual void finished() = 0;
  virtual bool processPoints() = 0;
  virtual IGcPcPointFilter*  filter() = 0;
  IGcPcDataBuffer* buffer();
  void setBuffer(IGcPcDataBuffer* buffer);

private:
  IGcPcDataBuffer* mpBuffer;
};

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbCreatePointCloudEntity(
  GcDbEntity*& newPointCloud,
  const GcString& indexFile,
  const GcString& sourceFile,
  GcGePoint3d&    location,
  double          scale = 1.0,
  double          rotation = 0.0);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbAttachPointCloudExEntity(
  GcDbObjectId&   newPointCloudExId,
  const GcString& pointCloudFile,
  GcGePoint3d&    location,
  double          scale = 1.0,
  double          rotation = 0.0,
  GcDbDatabase* pDb = NULL);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbAttachPointCloudEntity(
  GcDbObjectId& newPointCloudId,
  const GcString& indexFile,
  const GcString& sourceFile,
  GcGePoint3d&    location,
  double          scale = 1.0,
  double          rotation = 0.0,
  GcDbDatabase*   pDb = NULL);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbModifyPointCloudDataView(
  GcDbEntity* pEnt,
  IGcPcPointFilter* pFilter
);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbResetPointCloudDataView(
  GcDbEntity* pEnt
);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbProcessPointCloudData(
  GcDbEntity* pEnt,
  const GcDbExtents& ext,
  int levelOfDetail,
  IGcPcPointProcessor* pCallback);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbProcessPointCloudData(
  GcDbEntity* pEnt,
  const GcViewFrustum& frustum,
  int levelOfDetail,
  IGcPcPointProcessor* pCallback);

DBPOINTCLOUDOBJ_PORT Gcad::ErrorStatus gcdbSetPointCloudFilter(
  GcDbEntity* pEnt,
  IPointCloudFilter* pFilter);
