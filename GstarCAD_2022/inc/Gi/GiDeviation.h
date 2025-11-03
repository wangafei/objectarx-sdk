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




#ifndef __ODGIDEVIATION_H__
#define __ODGIDEVIATION_H__


#include "../Gi/GiCommonDraw.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GePoint3d.h"

/** Description:
    This class implements an interface that returns the *deviation* values used for anisotropic space 
    (perspective view).

    Library: TD_Gi
    
    {group:OdGi_Classes} 
*/
class OdGiDeviation
{
public:

  /** Description:
    Returns the recommended maximum *deviation* of the current vectorization, for the specified *point* on the curve or surface being tesselated.
    See Also:
    OdGiGeometrySimplifier::setDeviation
    Arguments:
    deviationType (I) Deviation type.
    pointOnCurve (I) Point on the curve.
    Remarks:
    deviationType must be one of the following:
    
    @table
    Name                       Value
    kOdGiMaxDevForCircle       0      
    kOdGiMaxDevForCurve        1      
    kOdGiMaxDevForBoundary     2      
    kOdGiMaxDevForIsoline      3
    kOdGiMaxDevForFacet        4
  */
  virtual double deviation(const OdGiDeviationType deviationType, const OdGePoint3d& pointOnCurve) const = 0;
};
/** Description:
    Returns an array of the deviations for the specified Deviation object for the specified *point* on the curve.
    Arguments:
    deviationObj (I) Deviation object.
    pointOnCurve (I) Point on the curve.
  
    Remarks:
    Deviations are returned in the array in the following order:
    
    @table
    Name                       Index
    kOdGiMaxDevForCircle       0      
    kOdGiMaxDevForCurve        1      
    kOdGiMaxDevForBoundary     2      
    kOdGiMaxDevForIsoline      3
    kOdGiMaxDevForFacet        4
*/
inline OdGeDoubleArray odgiGetAllDeviations(const OdGiDeviation& deviationObj, const OdGePoint3d& pointOnCurve = OdGePoint3d::kOrigin)
{
  OdGeDoubleArray values(5);
  values.append(deviationObj.deviation(kOdGiMaxDevForCircle,   pointOnCurve));
  values.append(deviationObj.deviation(kOdGiMaxDevForCurve,    pointOnCurve));
  values.append(deviationObj.deviation(kOdGiMaxDevForBoundary, pointOnCurve));
  values.append(deviationObj.deviation(kOdGiMaxDevForIsoline,  pointOnCurve));
  values.append(deviationObj.deviation(kOdGiMaxDevForFacet,    pointOnCurve));
  return values;
}

#endif //#ifndef __ODGIDEVIATION_H__
