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


#ifndef __OD_GI_PERSPECT_PREP__
#define __OD_GI_PERSPECT_PREP__

#include "../Gi/GiConveyorNode.h"
#include "../Gi/GiDeviation.h"

#include "../Ge/GeDoubleArray.h"

#include "../TD_PackPush.h"

/** Description:

    {group:OdGi_Classes}
    This class preprocesses geometry before xforming it by 
    perspective matrix.
    Remarks.
    Circles, arcs, ellipses, texts are tesselated, although for export tasks 
    it may be more useful to switch arcs to nurbs curves.
    
    Polylines, polygons, meshes, shells, xlines, rays, and NURBS curves are passed through.
    
    Images and metafiles are not passed.
*/
class ODGI_EXPORT OdGiPerspectivePreprocessor : public OdGiConveyorNode
{
public:
  ODRX_DECLARE_MEMBERS(OdGiPerspectivePreprocessor);

  /** Description:
    Sets max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGeDoubleArray& deviations) = 0;

  /** Description:
    Sets deviation object to obtain max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGiDeviation* pDeviation) = 0;

  /**  Description:
    Sets the draw context object (to access to traits, etc).
  */
  virtual void setDrawContext(OdGiConveyorContext* pDrawCtx) = 0;

  /** Description:
  */
  virtual void enable(bool enabled) = 0;

  /** Description:
  */
  virtual bool enabled() const = 0;
};

typedef OdSmartPtr<OdGiPerspectivePreprocessor> OdGiPerspectivePreprocessorPtr;

#include "../TD_PackPop.h"


#endif // __OD_GI_PERSPECT_PREP__
