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


#ifndef __OD_GI_EXTACCUM__
#define __OD_GI_EXTACCUM__

#include "../Ge/GeExtents3d.h"
#include "../Gi/GiConveyorNode.h"
#include "../Gi/GiDeviation.h"

#include "../TD_PackPush.h"

/** Description:
    This class is the base class for custom classes that compute the extents of OdGiConveyorGeometry objects.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiExtAccum : public OdGiConveyorNode
{
public:
  ODRX_DECLARE_MEMBERS(OdGiExtAccum);

  /** Description:
    Sets the draw context associated with this object.
    Arguments:
    pDrawContext (I) Pointer to the draw context.
  */
  virtual void setDrawContext(OdGiConveyorContext* pDrawContext) = 0;

  /** Description:
    Sets max deviation for curve tessellation.
  */
  virtual void setDeviation(const OdGeDoubleArray& deviations) = 0;

  /** Description:
    Sets deviation object to obtain max deviation for curve tessellation.
  */
  virtual void setDeviation(const OdGiDeviation* pDeviation) = 0;

  /** Description:
    Returns the OdGiConveyorGeometry object associated with this object.  
    
    Remarks:
    This instance contains the functions that can be used by an entity to
    vectorize itself.
  */
  virtual OdGiConveyorGeometry& geometry() = 0;

  /** Description:
    Returns the accumulated *extents* for the OdGiConveyorGeometry object associated with this object.
    Arguments:
    extents (O) Receives the *extents*.
  */
  virtual bool getExtents(OdGeExtents3d& extents) const = 0;

  /** Description:
    Resets the accumulated *extents* for the OdGiConveyorGeometry object associated with this object.
    Arguments:
    newExtents (O) New *extents*.
  */
  virtual void resetExtents(const OdGeExtents3d& newExtents = OdGeExtents3d()) = 0;


  /** Description:
    Adds the specified *extents* to the the accumulated *extents* for the OdGiConveyorGeometry object associated with this object.
    Arguments:
    extents (O) Extents to be added.
  */
  virtual void addExtents(const OdGeExtents3d& extents) = 0;

  static void textExtents(OdGiConveyorContext* pDrawContext, const OdGiTextStyle& textStyle,
                          const OdChar* pStr, int nLength, OdUInt32 raw, OdGePoint3d& minExt,
                          OdGePoint3d& maxExt, OdGePoint3d* pEndPos = NULL);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiExtAccum object pointers.
*/
typedef OdSmartPtr<OdGiExtAccum> OdGiExtAccumPtr;

#include "../TD_PackPop.h"

#endif // __OD_GI_EXTACCUM__
