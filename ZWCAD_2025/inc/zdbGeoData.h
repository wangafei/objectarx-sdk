

#pragma once

#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)


class ZcDbGeoDataReactor
{
public:
    virtual ~ZcDbGeoDataReactor()
    {
    }

    virtual Zcad::ErrorStatus geoCoordinateSystemWillChange(ZcDbDatabase* /*pDb*/, const ZcString& /*oldId*/, const ZcString& /*newId*/)
    {
        return Zcad::eOk;
    }

    virtual void geoCoordinateSystemChanged(ZcDbDatabase* /*pDb*/, const ZcString& /*oldId*/, const ZcString& /*newId*/)
    {
    }
};

class ZcDbGeoData : public ZcDbObject
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

    ZCDBCORE2D_DECLARE_MEMBERS(ZcDbGeoData);

    ZCDBCORE2D_PORT ZcDbGeoData();
    ZCDBCORE2D_PORT virtual ~ZcDbGeoData();

    ZCDBCORE2D_PORT ZcDbObjectId blockTableRecordId() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setBlockTableRecordId(const ZcDbObjectId& blockId);

    ZCDBCORE2D_PORT Zcad::ErrorStatus postToDb(ZcDbObjectId& objId);
    ZCDBCORE2D_PORT Zcad::ErrorStatus eraseFromDb(void);

    ZCDBCORE2D_PORT TypeOfCoordinates coordinateType() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setCoordinateType(TypeOfCoordinates designCoordinateType);

    ZCDBCORE2D_PORT ZcGePoint3d designPoint() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setDesignPoint(const ZcGePoint3d& point);

    ZCDBCORE2D_PORT ZcGePoint3d referencePoint() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setReferencePoint(const ZcGePoint3d& point);

    ZCDBCORE2D_PORT double horizontalUnitScale() const;
    ZCDBCORE2D_PORT ZcDb::UnitsValue horizontalUnits () const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setHorizontalUnitScale(double horzUnitScale);
    ZCDBCORE2D_PORT Zcad::ErrorStatus setHorizontalUnits (ZcDb::UnitsValue horizUnits);

    ZCDBCORE2D_PORT double verticalUnitScale() const;
    ZCDBCORE2D_PORT ZcDb::UnitsValue verticalUnits () const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setVerticalUnitScale(double vertUnitScale);
    ZCDBCORE2D_PORT Zcad::ErrorStatus setVerticalUnits(ZcDb::UnitsValue vertUnits);

    ZCDBCORE2D_PORT const ZTCHAR* coordinateSystem() const;

    ZCDBCORE2D_PORT Zcad::ErrorStatus setCoordinateSystem(const ZTCHAR* coordinateSystem);

    typedef bool (*ZCDBGEODATA_VALIDATE_CS)(const ZTCHAR* coordinateSystem);

    static ZCDBCORE2D_PORT Zcad::ErrorStatus setValidateCoordinateSystemCallback(ZCDBGEODATA_VALIDATE_CS pFuncValidateCs);
    static ZCDBCORE2D_PORT ZCDBGEODATA_VALIDATE_CS getValidateCoordinateSystemCallback();

    ZCDBCORE2D_PORT ZcGeVector3d upDirection() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setUpDirection(const ZcGeVector3d& vec);

    ZCDBCORE2D_PORT double northDirection() const;            
    ZCDBCORE2D_PORT ZcGeVector2d northDirectionVector() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setNorthDirectionVector(const ZcGeVector2d& north);

    ZCDBCORE2D_PORT ScaleEstimationMethod scaleEstimationMethod() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setScaleEstimationMethod(ScaleEstimationMethod value);

    ZCDBCORE2D_PORT double scaleFactor() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setScaleFactor(double value);

    ZCDBCORE2D_PORT bool doSeaLevelCorrection() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setDoSeaLevelCorrection(bool seaLevelCorrectionOn);

    ZCDBCORE2D_PORT double seaLevelElevation() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setSeaLevelElevation(double value);

    ZCDBCORE2D_PORT double coordinateProjectionRadius() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setCoordinateProjectionRadius(double value);

    ZCDBCORE2D_PORT const ZTCHAR* geoRSSTag() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setGeoRSSTag(const ZTCHAR* rssTag);

    ZCDBCORE2D_PORT const ZTCHAR* observationFrom() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setObservationFrom(const ZTCHAR* from);

    
    ZCDBCORE2D_PORT const ZTCHAR* observationTo() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setObservationTo(const ZTCHAR* to);

    
    ZCDBCORE2D_PORT const ZTCHAR* observationCoverage() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus setObservationCoverage(const ZTCHAR* coverage);

    ZCDBCORE2D_PORT int numMeshPoints() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus getMeshPointMap(int index, ZcGePoint2d& sourcePt, ZcGePoint2d& destPt) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus getMeshPointMaps(ZcGePoint2dArray& sourcePts, ZcGePoint2dArray& destPts) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus addMeshPointMap(int index, const ZcGePoint2d& sourcePt, const ZcGePoint2d& destPt);
    ZCDBCORE2D_PORT Zcad::ErrorStatus setMeshPointMaps(const ZcGePoint2dArray& sourcePts, const ZcGePoint2dArray& destPts);
    ZCDBCORE2D_PORT Zcad::ErrorStatus resetMeshPointMaps();

    ZCDBCORE2D_PORT int numMeshFaces() const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus getMeshFace(int faceIndex, int& p0, int& p1, int& p2) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus addMeshFace(int faceIndex, int p0, int p1,int p2);

    ZCDBCORE2D_PORT Zcad::ErrorStatus updateTransformationMatrix();

    ZCDBCORE2D_PORT Zcad::ErrorStatus transformToLonLatAlt(const ZcGePoint3d& dwgPt,
                                                     ZcGePoint3d& geoPt) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus transformToLonLatAlt(double x,
                                                     double y,
                                                     double z,
                                                     double& lon,
                                                     double& lat,
                                                     double& alt) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus transformFromLonLatAlt(const ZcGePoint3d& geoPt,
                                                       ZcGePoint3d& dwgPt) const;
    ZCDBCORE2D_PORT Zcad::ErrorStatus transformFromLonLatAlt(double lon,
                                                       double lat,
                                                       double alt,
                                                       double& x,
                                                       double& y,
                                                       double& z) const;

    typedef Zcad::ErrorStatus (*ZCDBGEODATA_GEOGRAPHICTODWG)(const ZcDbGeoData* pGeoData,
                                                             const double& dblLongitude,
                                                             const double& dblLatitude,
                                                             const double& dblAltitude,
                                                             double& dblDwgX,
                                                             double& dblDwgY,
                                                             double& dblDwgZ );
    typedef Zcad::ErrorStatus (*ZCDBGEODATA_DWGTOGEOGRAPHIC)(const ZcDbGeoData* pGeoData, 
                                                             const double& dblDwgX,
                                                             const double& dblDwgY,
                                                             const double& dblDwgZ,
                                                             double& dblLongitude,
                                                             double& dblLatitude,
                                                             double& dblAltitude );

    static ZCDBCORE2D_PORT Zcad::ErrorStatus setTransformCallbacks(const ZTCHAR* zoneDescription,
                                                             ZCDBGEODATA_GEOGRAPHICTODWG pFuncGeoToDwg,
                                                             ZCDBGEODATA_DWGTOGEOGRAPHIC pFuncDwgToGeo);
    static ZCDBCORE2D_PORT const ZTCHAR* getTransformCallbacks(ZCDBGEODATA_GEOGRAPHICTODWG& pFuncGeoToDwg,
                                                        ZCDBGEODATA_DWGTOGEOGRAPHIC& pFuncDwgToGeo);

    ZCDBCORE2D_PORT virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler*) override;
    ZCDBCORE2D_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const override;

    ZCDBCORE2D_PORT virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler*) override;
    ZCDBCORE2D_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const override;
};


ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbGetGeoDataObjId(ZcDbDatabase *pDb, ZcDbObjectId& objId);


ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbGetGeoDataTransform(ZcDbDatabase*   pDbSource,
                                                    ZcDbDatabase*   pDbTarget,
                                                    ZcGePoint3d&    insertionPt,
                                                    double&         rotation,
                                                    double&         scale);

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbRegisterGeoDataReactor(ZcDbGeoDataReactor *reactor);


ZCDBCORE2D_PORT void zcdbRemoveGeoDataReactor(ZcDbGeoDataReactor *reactor);

#pragma pack (pop)
