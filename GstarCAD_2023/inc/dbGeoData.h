/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

class GcDbGeoDataReactor
{
public:
  virtual ~GcDbGeoDataReactor()
  {
  }
  virtual Gcad::ErrorStatus geoCoordinateSystemWillChange(GcDbDatabase*, const GcString&, const GcString&)
  {
    return Gcad::eOk;
  }
  virtual void geoCoordinateSystemChanged(GcDbDatabase*, const GcString&, const GcString&)
  {
  }
};

class GCDB_PORT GcDbGeoData : public GcDbObject
{
public:
  enum TypeOfCoordinates
  {
    kCoordTypUnknown = 0,
    kCoordTypLocal,
    kCoordTypGrid,
    kCoordTypGeographic
  };

  enum ScaleEstimationMethod {
    kScaleEstMethodUnity = 1,
    kScaleEstMethodUserDefined,
    kScaleEstMethodReferencePoint,
    kScaleEstMethodPrismoidal
  };

  GCDB_DECLARE_MEMBERS(GcDbGeoData);
  GcDbGeoData();
  ~GcDbGeoData();

  GcDbObjectId blockTableRecordId() const;
  Gcad::ErrorStatus setBlockTableRecordId(const GcDbObjectId& blockId);
  Gcad::ErrorStatus postToDb(GcDbObjectId& objId);
  Gcad::ErrorStatus eraseFromDb(void);
  TypeOfCoordinates coordinateType() const;
  Gcad::ErrorStatus setCoordinateType(TypeOfCoordinates designCoordinateType);
  GcGePoint3d designPoint() const;
  Gcad::ErrorStatus setDesignPoint(const GcGePoint3d& point);
  GcGePoint3d referencePoint() const;
  Gcad::ErrorStatus setReferencePoint(const GcGePoint3d& point);

  double horizontalUnitScale() const;
  GcDb::UnitsValue horizontalUnits() const;
  Gcad::ErrorStatus setHorizontalUnitScale(double horzUnitScale);
  Gcad::ErrorStatus setHorizontalUnits(GcDb::UnitsValue horizUnits);

  double verticalUnitScale() const;
  GcDb::UnitsValue verticalUnits() const;
  Gcad::ErrorStatus setVerticalUnitScale(double vertUnitScale);
  Gcad::ErrorStatus setVerticalUnits(GcDb::UnitsValue vertUnits);
  const GCHAR* coordinateSystem() const;
  Gcad::ErrorStatus setCoordinateSystem(const GCHAR* coordinateSystem);

  typedef bool(*GCDBGEODATA_VALIDATE_CS)(const GCHAR* coordinateSystem);

  static  Gcad::ErrorStatus setValidateCoordinateSystemCallback(GCDBGEODATA_VALIDATE_CS pFuncValidateCs);
  static  GCDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();

  GcGeVector3d upDirection() const;
  Gcad::ErrorStatus setUpDirection(const GcGeVector3d& vec);
  double northDirection() const;
  GcGeVector2d northDirectionVector() const;
  Gcad::ErrorStatus setNorthDirectionVector(const GcGeVector2d& north);
  ScaleEstimationMethod scaleEstimationMethod() const;
  Gcad::ErrorStatus setScaleEstimationMethod(ScaleEstimationMethod value);
  double scaleFactor() const;
  Gcad::ErrorStatus setScaleFactor(double value);
  bool doSeaLevelCorrection() const;
  Gcad::ErrorStatus setDoSeaLevelCorrection(bool seaLevelCorrectionOn);
  double seaLevelElevation() const;
  Gcad::ErrorStatus setSeaLevelElevation(double value);
  double coordinateProjectionRadius() const;
  Gcad::ErrorStatus setCoordinateProjectionRadius(double value);
  const GCHAR* geoRSSTag() const;
  Gcad::ErrorStatus setGeoRSSTag(const GCHAR* rssTag);
  const GCHAR* observationFrom() const;
  Gcad::ErrorStatus setObservationFrom(const GCHAR* from);
  const GCHAR* observationTo() const;
  Gcad::ErrorStatus setObservationTo(const GCHAR* to);
  const GCHAR* observationCoverage() const;
  Gcad::ErrorStatus setObservationCoverage(const GCHAR* coverage);

  int numMeshPoints() const;
  Gcad::ErrorStatus getMeshPointMap(int index, GcGePoint2d& sourcePt, GcGePoint2d& destPt) const;
  Gcad::ErrorStatus getMeshPointMaps(GcGePoint2dArray& sourcePts, GcGePoint2dArray& destPts) const;
  Gcad::ErrorStatus addMeshPointMap(int index, const GcGePoint2d& sourcePt, const GcGePoint2d& destPt);
  Gcad::ErrorStatus setMeshPointMaps(const GcGePoint2dArray& sourcePts, const GcGePoint2dArray& destPts);
  Gcad::ErrorStatus resetMeshPointMaps();
  int numMeshFaces() const;
  Gcad::ErrorStatus getMeshFace(int faceIndex, int& p0, int& p1, int& p2) const;
  Gcad::ErrorStatus addMeshFace(int faceIndex, int p0, int p1, int p2);
  Gcad::ErrorStatus updateTransformationMatrix();
  Gcad::ErrorStatus transformToLonLatAlt(const GcGePoint3d& dwgPt,
    GcGePoint3d& geoPt) const;
  Gcad::ErrorStatus transformToLonLatAlt(double x,
    double y,
    double z,
    double& lon,
    double& lat,
    double& alt) const;
  Gcad::ErrorStatus transformFromLonLatAlt(const GcGePoint3d& geoPt,
    GcGePoint3d& dwgPt) const;
  Gcad::ErrorStatus transformFromLonLatAlt(double lon,
    double lat,
    double alt,
    double& x,
    double& y,
    double& z) const;

  typedef Gcad::ErrorStatus(*GCDBGEODATA_GEOGRAPHICTODWG)(const GcDbGeoData* pGeoData,
    const double& dblLongitude,
    const double& dblLatitude,
    const double& dblAltitude,
    double& dblDwgX,
    double& dblDwgY,
    double& dblDwgZ);
  typedef Gcad::ErrorStatus(*GCDBGEODATA_DWGTOGEOGRAPHIC)(const GcDbGeoData* pGeoData,
    const double& dblDwgX,
    const double& dblDwgY,
    const double& dblDwgZ,
    double& dblLongitude,
    double& dblLatitude,
    double& dblAltitude);

  static  Gcad::ErrorStatus setTransformCallbacks(const GCHAR* zoneDescription,
    GCDBGEODATA_GEOGRAPHICTODWG pFuncGeoToDwg,
    GCDBGEODATA_DWGTOGEOGRAPHIC pFuncDwgToGeo);
  static  const GCHAR* getTransformCallbacks(GCDBGEODATA_GEOGRAPHICTODWG& pFuncGeoToDwg,
    GCDBGEODATA_DWGTOGEOGRAPHIC& pFuncDwgToGeo);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;
};

GCDB_PORT Gcad::ErrorStatus gcdbGetGeoDataObjId(GcDbDatabase *pDb, GcDbObjectId& objId);
GCDB_PORT Gcad::ErrorStatus gcdbGetGeoDataTransform(GcDbDatabase*   pDbSource,
  GcDbDatabase*   pDbTarget,
  GcGePoint3d&    insertionPt,
  double&         rotation,
  double&         scale);

GCDB_PORT Gcad::ErrorStatus gcdbRegisterGeoDataReactor(GcDbGeoDataReactor *reactor);
GCDB_PORT void gcdbRemoveGeoDataReactor(GcDbGeoDataReactor *reactor);

#pragma pack (pop)