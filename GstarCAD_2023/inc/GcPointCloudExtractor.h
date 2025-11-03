/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once 

#include "GcDbPointCloudEx.h"
#include "GcPointCloudExtractProfileCurve.h"

class DBPOINTCLOUDOBJ_PORT ExtractOption
{
public:
  enum ExtractionType
  {
    kOutLine,
    kAllLine,
  };

public:
  ExtractionType  m_extractionType;
  unsigned int    m_processPoints;
  double          m_fillGap;
  unsigned int    m_snapAngle;
  double          m_minSegLength;
  bool            m_useLineSegmentOnly;

  ExtractOption();
};

class DBPOINTCLOUDOBJ_PORT IPointCloudExtracProgressCallback
{
public:
  IPointCloudExtracProgressCallback(void) {}
  virtual ~IPointCloudExtracProgressCallback(void) {}

  virtual void updateProgress(int progress) = 0;
  virtual void updateCaption(const GcString& caption) = 0;
  virtual bool cancelled() const = 0;
  virtual void cancel() = 0;
  virtual void updateRemainTime(double remainTime) = 0;
  virtual void end() = 0;
};

class DBPOINTCLOUDOBJ_PORT GcPointCloudExtractor
{
public:
  static Gcad::ErrorStatus extract(GcDbPointCloudEx *pointCloud,
    const GcGeVector3d& planeZDirection,
    const GcGeVector3d& planeXDirection,
    GcGePoint3d pointPlane,
    const ExtractOption& extractOption,
    GcPointCloudExtractResult& outlineResult,
    IPointCloudExtracProgressCallback* progress = 0);
  static GcDbObjectIdArray appendLineProfile(const GcPointCloudExtractResult& profile,
    GcDbObjectId spaceId,
    GcString layer,
    GcCmColor color);
  static GcDbObjectIdArray appendPolylineProfile(const GcPointCloudExtractResult& profile,
    GcDbObjectId spaceId,
    GcString layer,
    GcCmColor color,
    double polylineWidth);
};