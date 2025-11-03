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

#ifndef OD_GE_COMPOSITE_CURVE_2D_H
#define OD_GE_COMPOSITE_CURVE_2D_H /* {Secret} */

#include "../Ge/GeCurve2d.h"
#include "../Ge/GeCurve2dPtrArray.h"
#include "../Ge/GeIntArray.h"
#include "../Ge/GeIntervalArray.h"

#include "../TD_PackPush.h"
class OdGeCompositeCurve3dImpl;

/**
    Description:
    This class represents composite curves in 2D space.
    It is not implemented yet.

    Remarks:
    Composite curves consists of pointers to any number of subcurves that
    are joined end to end. Each subcurve must be bounded.

    The parameter at the start of the composite curve is 0.0. The parameter at any
    point along the composite curve is the approximate length of the
    composite curve up to that *point*.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCompositeCurve2d : public OdGeCurve2d
{
public:
  

  /**
    Arguments:
    curvelist (I) Array of pointers to subcurves comprising the composite *curve*.
    isOwnerOfCurves (I) Non-zero if and only if the corresponding subcurve
        is to be deleted when the composite curve is deleted.
    source (I) Object to be cloned.

    Remarks:
    If isOwnerOfCurves is not specified, the subcurves in the curvelist
    are copied, and the composite curve contains pointers to the copies.

    The default constructor creates a composite curve that consists 
    of a single subcurve: a line segment from (0,0) to (1,0). 

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCompositeCurve2d();
  OdGeCompositeCurve2d(const OdGeCompositeCurve2d& source);
  OdGeCompositeCurve2d(const OdGeVoidPointerArray& curveList);
  OdGeCompositeCurve2d(const OdGeVoidPointerArray& curveList,
                       const OdGeIntArray& isOwnerOfCurves);

  /**
    Description:
    Returns an array of pointers to subcurves comprising the composite *curve*.

    Arguments:
    curvelist (O) Receives an array of pointers to subcurves comprising the composite *curve*.

    Note:
    By default this function throws exception "not Implemented".
  */
  void getCurveList(OdGeVoidPointerArray& curveList) const;

  /**
    Description:
    Sets the curve list of the composite *curve*.

    Arguments:
    curvelist (I) Array of pointers to subcurves comprising the composite *curve*.
    isOwnerOfCurves (I) True if and only if the specified curve
    is to be deleted when the composite curve is deleted.

    Remarks:
    If OwnerOfCurves is not specified, the subcurves in the curvelist
    are copied, and the composite curve contains pointers to the copies.

    Note:
    By default this function throws exception "not Implemented".
  */
  OdGeCompositeCurve2d& setCurveList(const OdGeVoidPointerArray& curveList);

  OdGeCompositeCurve2d& setCurveList(const OdGeVoidPointerArray& curveList,
                                             const OdGeIntArray& isOwnerOfCurves);

  // useless after OdSharedPtr :
  //OdGeCompositeCurve2d& setCurveList(const OdGeCurve2dPtrArray& curveList,
  //                                           const OdGeIntArray& isOwnerOfCurves);
  // TD Special :
  //OdGeCompositeCurve2d& setCurveList(const OdGeCurve2d* subCurves, 
  //                                           OdUInt32 numSubCurves);

  /**
    Description:
    Returns the parameter on a subcurve, and the index of that subcurve,
    corresponding to the specified parameter on the composite *curve*.

    Arguments:
    param (I) Parameter value on composite *curve*.
    crvNum (O) Receives the *curve* number of the subcurve.

    Note:
    By default this function throws exception "not Implemented".
  */
  double globalToLocalParam(double param, 
                                    int& crvNum) const; 

  /**
  Description:
    Returns the parameter on the composite curve, corresponding
    corresponding to the specified parameter on the specifed subcurve *curve*.

    Arguments:
    param (I) Parameter value on the subcurve.
    crvNum (I) Curve number of the subcurve.


    Note:
    By default this function throws exception "not Implemented".
  */
  double localToGlobalParam(double param, 
                                    int crvNum) const; 

  /**
    Remarks:
    All of the subcurves of the input curve are copied.         
  */
  OdGeCompositeCurve2d& operator =(const OdGeCompositeCurve2d& compCurve);
  OdGeCompositeCurve2d(OdGeCompositeCurve3dImpl *);
};

#include "../TD_PackPop.h"

#endif // OD_GE_COMPOSITE_CURVE_2D_H

