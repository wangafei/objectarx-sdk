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


#ifndef _OD_MODELERGEOMETRYCREATOR_INCLUDED_
#define _OD_MODELERGEOMETRYCREATOR_INCLUDED_

#include "RxObject.h"
#include "ModelerGeometry.h"
#include "OdArray.h"

class OdStreamBuf;

#include "TD_PackPush.h"

/** Description:
    This utility class loads and saves SAT/SAB files, and performs other
    miscellaneous other ACIS-related operations.
    
    Remarks:
    The functions in this class can do the following: 
    
    o Create OdModelerGeometry instances from a specified input stream.
    o Save SAT/SAB data from an OdModelerGeometry instance.
    o Create region entities from sets of curves.

    Library: ModelerGeometry
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdModelerGeometryCreator : public OdRxObject
{
protected:
  OdModelerGeometryCreator() {}
public:  
  ODRX_DECLARE_MEMBERS(OdModelerGeometryCreator);

  /** Description: 
      Creates one or more instances of OdModelerGeometry from the specified SAT/SAB file.
      
      Arguments:
      models (O) Receives an array of OdModelerGeometry SmartPointers.
      pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.   
      standardSaveFlag (I) Controls the saving and restoring of use count data *in* the save file.

      Remarks:
      Since OdModelerGeometry does not support multi-body SAT files, such files 
      are divided into a set of single body OdModelerGeometry objects

      Empty streamBuf generates single element array with empty OdModelerGeometry.

      Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult createModeler(OdArray<OdModelerGeometryPtr> &models, 
    OdStreamBuf* pStreamBuf, 
    bool standardSaveFlag = true) = 0;

  /** Description: 
    Creates a single SAT/SAB file from the specified array of objects.

    Arguments:
    models (I) Array of SmartPointers to the OdDbModelerGeometry objects to be written.
    pStreamBuf (I) Pointer to the StreamBuf object to which the data are to be written.   
    typeVer(I) Type and version of ACIS data to write.
    standardSaveFlag (I) Controls the saving and restoring of use count data *in* the save file.
  */
  virtual OdResult createSat(const OdArray<OdModelerGeometryPtr> &models, 
    OdStreamBuf* pStreamBuf, 
    AfTypeVer typeVer, 
    bool standardSaveFlag = true) = 0;

  /** 
    Arguments:
    entities (I) Array of SmartPointers to the OdDbEntity objects to be written.
    Remarks:
    Color attributes are also added to the SAT/SAB file from the specified OdDbEntity objects.

    Returns eOk if successful, or an appropriate error code if not.
    Note:
    Only the following OdDbEntity types are valid: OdDb3dSolid, OdDbBody, and OdDbRegion/
  */
  virtual OdResult createSat(const OdDbEntityPtrArray &entities, 
    OdStreamBuf* pStreamBuf, 
    AfTypeVer typeVer, 
    bool standardSaveFlag = true) = 0;

  /** Description: 
    Creates OdDbRegion entities from the closed loops defined by the specified curve segments.

    Arguments:
    curveSegments (I) Array of curve segments.
    pRegions (O) Receives an array of pointers to the *regions*.

    Remarks:
    Each curve segment must be one of the following

    @untitled table
    OdDb3dPolyline
    OdDbArc
    OdDbCircle
    OdDbEllipse
    OdDbLine
    OdDbPolyline
    OdDbSpline

    The newly created *regions* are non- *database* -resident. It is up to the caller to either add them
    to an OdDbDatabase or to delete them.

    Returns eOk if successful, or an appropriate error code if not. 
    
    Note:
    o  All *curves* must be in the same plane.
    o  The endpoint of each curve must be equal to the start point of the next curve
    o  The endpoint of the last curve must be equal to the start point of the first curve.
    
  */
  virtual OdResult createRegionFromCurves(const OdRxObjectPtrArray& curveSegments, 
    OdArray<OdModelerGeometryPtr> &pRegions) = 0;

  virtual OdResult createRegionFromCurves(const OdRxObjectPtrArray& curveSegments, 
    OdModelerGeometryPtr &pRegions, bool split = true) = 0;

  virtual OdResult getProfile(const OdRxObjectPtrArray &allSolids, const OdGePoint3d &eyePos, const OdGePoint3d &target,
    const OdGePoint3d &viewCenter, const OdGeVector3d &viewDir, OdDbVoidPtrArray &visibleEnts, OdDbVoidPtrArray &hideEnts, 
    bool isProjected = true, bool isTangent = true, bool isShowHideLines = true ) = 0;

  virtual OdResult getFlatShot(const OdRxObjectPtrArray& acisEnts, const OdGePoint3d &eyePos, const OdGePoint3d &target,
    const OdGePoint3d &viewCenter, const OdGeVector3d &viewDir, OdDbVoidPtrArray &visibleEnts, OdDbVoidPtrArray &hideEnts, 
    bool isTangent = true, bool isShowHideLines = true ) = 0;

  virtual OdResult getHide(const OdRxObjectPtrArray &allSolids, const OdGePoint3d &eyePos, const OdGePoint3d &target,
    const OdGeVector3d &viewDir, OdDbVoidPtrArray &visibleEnts) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdModelerGeometryCreator object pointers.
*/
typedef OdSmartPtr<OdModelerGeometryCreator> OdModelerGeometryCreatorPtr;

#include "TD_PackPop.h"

#endif // _OD_MODELERGEOMETRYCREATOR_INCLUDED_
