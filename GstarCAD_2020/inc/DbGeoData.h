/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef _ODDB_GEODATA_INCLUDED_
#define _ODDB_GEODATA_INCLUDED_

#include "TD_PackPush.h"

#include "DbObject.h"


/** Description:
    This class represents GeoData objects in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGeoData: public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbGeoData);

  OdDbGeoData();

  enum TypeOfCoordinates
  {
    kCoordTypUnknown = 0,
    kCoordTypLocal,
    kCoordTypGrid,
    kCoordTypGeographic
  };

  enum ScaleEstimationMethod
  {
    kScaleEstMethodUnity = 1,
    kScaleEstMethodUserDefined,
    kScaleEstMethodReferencePoint,
    kScaleEstMethodPrismoidal
  };

  OdDbObjectId blockTableRecordId() const;
  void setBlockTableRecordId(const OdDbObjectId& blockId);

  TypeOfCoordinates coordinateType() const;
  void setCoordinateType(TypeOfCoordinates designCoordinateType);

  OdGePoint3d designPoint() const;
  void setDesignPoint(const OdGePoint3d& point);

  OdGePoint3d referencePoint() const;
  void setReferencePoint(const OdGePoint3d& point);

  double horizontalUnitScale() const;
  OdDb::UnitsValue horizontalUnits () const;
  void setHorizontalUnitScale(double horzUnitScale);
  void setHorizontalUnits (OdDb::UnitsValue horizUnits);

  double verticalUnitScale() const;
  OdDb::UnitsValue verticalUnits () const;
  void setVerticalUnitScale(double vertUnitScale);
  void setVerticalUnits(OdDb::UnitsValue vertUnits);

  OdGeVector3d upDirection() const;
  void setUpDirection(const OdGeVector3d& vec);

  double northDirection() const;
  OdGeVector2d northDirectionVector() const;
  void setNorthDirectionVector(const OdGeVector2d& north);

  ScaleEstimationMethod scaleEstimationMethod() const;
  void setScaleEstimationMethod(ScaleEstimationMethod value);

  double scaleFactor() const;
  void setScaleFactor(double value);

  bool doSeaLevelCorrection() const;
  void setDoSeaLevelCorrection(bool seaLevelCorrectionOn);

  double seaLevelElevation() const;
  void setSeaLevelElevation(double value);

  double coordinateProjectionRadius() const;
  void setCoordinateProjectionRadius(double value);

  OdString coordinateSystem() const;
  void setCoordinateSystem(const OdString& coordSystem);

  OdString geoRSSTag() const;
  void setGeoRSSTag(const OdString& rssTag);

  OdString observationFrom() const;
  void setObservationFrom(const OdString& from);

  OdString observationTo() const;
  void setObservationTo(const OdString& to);

  OdString observationCoverage() const;
  void setObservationCoverage(const OdString& coverage);

  int numMeshPoints() const;
  void getMeshPointMap(int index, OdGePoint2d& srcPt, OdGePoint2d& dstPt) const;
  void getMeshPointMaps(OdGePoint2dArray& srcPts, OdGePoint2dArray& dstPts) const;
  void addMeshPointMap(int index, const OdGePoint2d& srcPt, const OdGePoint2d& dstPt);
  void setMeshPointMaps(const OdGePoint2dArray& srcPts, const OdGePoint2dArray& dstPts);
  void resetMeshPointMaps();

  int numMeshFaces() const;
  void getMeshFace(int faceIndex, int& p0, int& p1, int& p2) const;
  void addMeshFace(int faceIndex, int p0, int p1,int p2);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbGeoData object pointers.
*/
typedef OdSmartPtr<OdDbGeoData> OdDbGeoDataPtr;

//=============================================================================
//  Global API functions 
//=============================================================================
//
TOOLKIT_EXPORT OdResult oddbGetGeoDataObjId(OdDbDatabase *pDb, OdDbObjectId& objId);

TOOLKIT_EXPORT OdResult oddbGetGeoDataTransform(OdDbDatabase*   pDbSource,
                                                OdDbDatabase*   pDbTarget,
                                                OdGePoint3d&    insertionPt,
                                                double&         rotation,
                                                double&         scale);

#include "TD_PackPop.h"

#endif //_ODDB_GEODATA_INCLUDED_
