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


#ifndef _DbPlaneSurface_h_Included_
#define _DbPlaneSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"

class OdDbRegion;

/** Description:
    This class implements a three-dimensional planar surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPlaneSurface : public OdDbSurface
{
public:
  OdDbPlaneSurface ();
  ODDB_DECLARE_MEMBERS(OdDbPlaneSurface);

  virtual ~OdDbPlaneSurface();
  // Create plane surface from region.

  virtual OdResult createFromRegion( OdDbRegion *pRegion );

  // OdDbObject methods

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual bool isDependent() const { return false; }

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;
};

typedef OdSmartPtr<OdDbPlaneSurface> OdDbPlaneSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbPlaneSurface_h_Included_
