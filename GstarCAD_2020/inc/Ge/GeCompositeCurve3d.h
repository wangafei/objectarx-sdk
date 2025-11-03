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

#ifndef OD_GECOMP3D_H
#define OD_GECOMP3D_H /* {Secret} */

#include "../Ge/GeCurve3d.h"
#include "../Ge/GeIntervalArray.h"
#include "../Ge/GeCurve3dPtrArray.h"
#include "../Ge/GeVoidPointerArray.h"
#include "../Ge/GeIntArray.h"
#include "../OdPlatform.h"

#include "../TD_PackPush.h"

class OdGeCompositeCurve3dImpl;

/**
Description:
    This class represents composite curves in 3D space.

    Remarks:
    Composite curves consists of pointers to any number of subcurves that
    are joined end to end. Each subcurve must be bounded.

    The parameter at the start of the composite curve is 0.0. The parameter at any
    point along the composite curve is the approximate length of the
    composite curve up to that *point*.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeCompositeCurve3d : public OdGeCurve3d
{
public:
  /**
    Arguments:
    curvelist (I) Array of pointers to subcurves comprising the composite *curve*.
    subCurves (I) Array of the subcurves comprising the composite *curve* 
    numSubCurves (I) Number of subcurves.
    source (I) Object to be cloned.

    Remarks:
    The default constructor creates a composite curve that consists 
    of a single subcurve: a line segment from (0,0,0) to (1,0,0). 
  */
  OdGeCompositeCurve3d();
  OdGeCompositeCurve3d(OdGeCompositeCurve3dImpl* impl);
  OdGeCompositeCurve3d (const OdGeVoidPointerArray& curveList);
  OdGeCompositeCurve3d(const OdGeCompositeCurve3d& source);
  OdGeCompositeCurve3d(const OdGeVoidPointerArray& curveList, 
    const OdGeIntArray& isOwnerOfCurves);

  /**
  Description:
  Returns an array of pointers to subcurves comprising the composite *curve*.

  Arguments:
  curvelist (O) Receives an array of pointers to subcurves comprising the composite *curve*.
  */
  void getCurveList (OdGeVoidPointerArray& curveList) const;

  /**
  Description:
  Sets the curve list of the composite *curve*.

  Arguments:
  curveList (I) Array of pointers to subcurves comprising the composite *curve*.
  subCurves (I) Array of the subcurves comprising the composite *curve*. 
  numSubCurves (I) Number of subcurves.
  */
  OdGeCompositeCurve3d& setCurveList (const OdGeVoidPointerArray& curveList);
  OdGeCompositeCurve3d& setCurveList (const OdGeVoidPointerArray& curveList,const OdGeIntArray& isOwnerOfCurves);

  /**
    Description:
    Returns the parameter on a subcurve, and the index of that subcurve,
    corresponding to the specified parameter on the composite *curve*.

    Arguments:
    param (I) Parameter value on composite *curve*.
    crvNum (O) Receives the *curve* number of the subcurve.
  */
   double globalToLocalParam(double param, int& crvNum) const; 

  /**
    Description:
    Returns the parameter on the composite curve, corresponding
    to the specified parameter on the specifed subcurve.

    Arguments:
    param (I) Parameter value on the subcurve.
    crvNum (I) Curve number of the subcurve.
  */
   double localToGlobalParam(double param, int crvNum) const; 

  /**
    Remarks:
    All of the subcurves of the input curve are copied.         
  */
  OdGeCompositeCurve3d& operator =(const OdGeCompositeCurve3d& compCurve);
};


#include "../TD_PackPop.h"

#endif

