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



#ifndef _ODDBGPIPPOINTS_INCLUDED_
#define _ODDBGPIPPOINTS_INCLUDED_

#include "RxObject.h"
#include "RxModule.h"
#include "IntArray.h"
#include "DbEntity.h"
#include "Gi/GiDrawable.h"

class OdDbCommandContext;
/** Description:
    This class is the Grip Points Protocol Extension class.
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbGripPointsPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbGripPointsPE);
  
  /** Description:
    Returns all grip points of the specified entity.

    Arguments:
    pEntity (I) Pointer to the entity.
    gripPoints (I/O) Receives an array of WCS grip points.

    Remarks:
    Grip points are appended to the specified array.
    
    Returns eOk if successful, or an appropriate error code if not.
    The default implementation of this function returns eNotImplemented.
  */
  virtual OdResult getGripPoints(
    const OdDbEntity* pEntity,
    OdGePoint3dArray& gripPoints ) const;

  /**
    Description:
    Moves the specified grip points of the specified entity.
    
    Arguments:
    pEntity (I) Pointer to the entity.
    indices (I) Array of indicies.
    offset(I) The direction and magnitude of the grip points offset (WCS).
    
    Remarks:
    Each element in gripPoints has a corresponding entry in indices, which specifies the index of 
    the grip point as returned by getGripPoints.
    
    Returns eOk if successful, or an appropriate error code if not.
    The default implementation of this function returns eNotImplemented.
  */  
  virtual OdResult moveGripPointsAt(
    OdDbEntity* pEntity,
    const OdIntArray& indices,
    const OdGeVector3d& offset );

  /** Description:
    Returns OdDbGripData objects for grip points of this entity.

    Arguments:
    pEntity (I) Pointer to the entity.
    grips (I/O) Receives an array of OdDbGripData objects.

    Remarks:
    Grip points are appended to the specified array.
    When eNotImplemented is returned, the application should call the other overload of the getGripPoints() method.
    The default implementation of this function returns eNotImplemented.
  */
  virtual OdResult getGripPoints(
    const OdDbEntity* pEntity,
    OdDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const OdGeVector3d& curViewDir,
    const int bitFlags ) const;

  /**
    Description:
    Moves the specified grip points of this entity.
    
    Arguments:
    pEntity (I) Pointer to the entity.
    grips (I) Array of OdDbGripData identifiers.
    offset(I) The direction and magnitude of the grip points offset (WCS).

    Remarks:
    The default implementation of this function returns eNotImplemented. 
  */  
  virtual OdResult moveGripPointsAt(
    OdDbEntity* pEntity,
    const OdDbVoidPtrArray& grips,
    const OdGeVector3d& offset,
    const int bitFlags );

  /** Description:
    Returns all stretch points of the specified entity.

    Arguments:
    pEntity (I) Pointer to the entity.
    stretchPoints (I/O) Receives an array of WCS stretch points.

    Remarks:
    Stretch points are appended to the specified array.
    
    Returns eOk if successful, or an appropriate error code if not.
    The default implementation of this function returns eNotImplemented.
  */
  virtual OdResult getStretchPoints(
    const OdDbEntity* pEntity,
    OdGePoint3dArray& stretchPoints ) const;
  /**
    Description:
    Moves the specified stretch points of this entity.
    
    Arguments:
    pEntity (I) Pointer to the entity.
    indices (I) Array of indicies.
    offset(I) The direction and magnitude of the stretch points offset (WCS).
    
    Remarks:
    Each element in stretchPoints has a corresponding entry in indices, which specifies the index of 
    the stretch point as returned by getStretchPoints.
    
    Returns eOk if successful, or an appropriate error code if not.
    The default implementation of this function returns eNotImplemented.
  */  
  virtual OdResult moveStretchPointsAt(
    OdDbEntity* pEntity,
    const OdIntArray& indices,
    const OdGeVector3d& offset );

  /** Description:
    Returns all appropriate object snap points of the specified entity.
    
    Arguments:
    pEntity (I) Pointer to the entity.
    osnapMode (I) The object snap mode being queried.
    gsSelectionMark (I) The GS marker of the subentity being queried.
    pickPoint (I) The WCS point being queried.
    lastPoint (I) The WCS point picked before pickPoint.
    viewXform (I) The WCS->DCS transformation matrix.
    ucs (I) The WCS->UCS transformation matrix.
    snapPoints (I/O) Receives an array of UCS object snap points.
    
    Remarks:
    Object snap points are appended to the specified array.
    
    osnapMode must be one of the following:
    
    @table
    Name                      Value   Description 
    OdDb::kOsModeEnd          1       Endpoint
    OdDb::kOsModeMid          2       Midpoint
    OdDb::kOsModeCen          3       Center
    OdDb::kOsModeNode         4       Node
    OdDb::kOsModeQuad         5       Quadrant
    OdDb::kOsModeIntersec     6       Intersection
    OdDb::kOsModeIns          7       Insertion point
    OdDb::kOsModePerp         8       Perpendicular
    OdDb::kOsModeTan          9       Tangent
    OdDb::kOsModeNear         10      Nearest
    OdDb::kOsModeApint        11      Apparent intersection
    OdDb::kOsModePar          12      Parallel
    OdDb::kOsModeStart        13      Unknown 
   
    The default implementation of this function returns eNotImplemented.
  */  
  virtual OdResult getOsnapPoints( 
    const OdDbEntity* pEntity, 
    OdDb::OsnapMode osnapMode, 
    OdGsMarker gsSelectionMark, 
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint, 
    const OdGeMatrix3d& xWorldToEye, 
    OdGePoint3dArray& snapPoints ) const;

  /** Description:
  Returns all appropriate object snap points of the specified entity.

  Arguments:
  pEntity (I) Pointer to the entity.
  osnapMode (I) The object snap mode being queried.
  gsSelectionMark (I) The GS marker of the subentity being queried.
  pickPoint (I) The WCS point being queried.
  lastPoint (I) The WCS point picked before pickPoint.
  viewXform (I) The WCS->DCS transformation matrix.
  ucs (I) The WCS->UCS transformation matrix.
  snapPoints (I/O) Receives an array of UCS object snap points.
  insert (I) Current insertion matrix

  Remarks:
  Object snap points are appended to the specified array.

  osnapMode must be one of the following:

  @table
  Name                      Value   Description 
  OdDb::kOsModeEnd          1       Endpoint
  OdDb::kOsModeMid          2       Midpoint
  OdDb::kOsModeCen          3       Center
  OdDb::kOsModeNode         4       Node
  OdDb::kOsModeQuad         5       Quadrant
  OdDb::kOsModeIntersec     6       Intersection
  OdDb::kOsModeIns          7       Insertion point
  OdDb::kOsModePerp         8       Perpendicular
  OdDb::kOsModeTan          9       Tangent
  OdDb::kOsModeNear         10      Nearest
  OdDb::kOsModeApint        11      Apparent intersection
  OdDb::kOsModePar          12      Parallel
  OdDb::kOsModeStart        13      Unknown 

  The default implementation of this function returns eNotImplemented.
  */  
  virtual OdResult getOsnapPoints( 
    const OdDbEntity* pEntity, 
    OdDb::OsnapMode osnapMode, 
    OdGsMarker gsSelectionMark, 
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint, 
    const OdGeMatrix3d& xWorldToEye, 
    OdGePoint3dArray& snapPoints,
    const OdGeMatrix3d& insert) const;

  enum GsMarkerType
  {
    kUnknownMT = 0,
    kYesMT     = 1,
    kNoMT      = 2
  };
  virtual int supportGsMarker() const;
	
  virtual bool getEntityExtents(const OdDbEntity* pEntity,OdGeExtents3d& ext) const;
  /** Description:
	Gets the grip points and supporting information about the grips for a subentity.

	Arguments:
  pEntity (I) Pointer to the entity.
	path (I) The OdDbFullSubentPath to the subentity.
	grips (I/O) Receives an array of pointers of OdDbGripData objects, one object for each grip point in the subentity.
	curViewUnitSize (I) The size (in pixels) of one drawing unit in the current viewport.
	gripSize (I) The current grip size (in pixels).
	curViewDir (I) The view direction in the current viewport.
	bitflags (I) The bitmap of one or more flags specified by the GetGripPointsFlags enumeration.
  */

  virtual OdResult getGripPointsAtSubentPath(   const OdDbEntity* pEntity,
                        const OdDbFullSubentPath& path, OdDbGripDataPtrArray& grips,
											  const double curViewUnitSize, const int gripSize,
											  const OdGeVector3d& curViewDir, const OdUInt32 bitflags) const;

  /** Description:
	Applies a vector offset to one or more grip points exposed by subentities on the object.

	Arguments:
  pEntity (I) Pointer to the entity.
	paths (I) The array of OdDbFullSubentPath objects.
	gripAppData (I) The array of pointers of OdDbGripData objects.
	offset (I) The vector (in WCS coordinates) indicating the direction and magnitude of the translation.
	bitflags (I) The bitmap of one or more flags specified by the GetGripPointsFlags enumeration.
  */

  virtual OdResult moveGripPointsAtSubentPaths(   const OdDbEntity* pEntity,
                        const OdDbFullSubentPathArray& paths, const OdDbVoidPtrArray& gripAppData,
												const OdGeVector3d& offset, const OdUInt32 bitflags);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbGripPointsPE object pointers.
*/
typedef OdSmartPtr<OdDbGripPointsPE> OdDbGripPointsPEPtr;

#endif //_ODDBGPIPPOINTS_INCLUDED_
