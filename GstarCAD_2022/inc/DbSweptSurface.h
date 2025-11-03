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


#ifndef _DbSweptSurface_h_Included_
#define _DbSweptSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"
#include "DbSweepOptions.h"

/** Description:
    This class implements a three-dimensional swept surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSweptSurface : public OdDbSurface
{
public:
  OdDbSweptSurface ();
  ODDB_DECLARE_MEMBERS(OdDbSweptSurface);

  virtual ~OdDbSweptSurface();
  // Create swept surface.

  virtual OdResult createSweptSurface ( OdDbEntity* pSweepEnt, OdDbEntity* pPathEnt, OdDbSweepOptions& sweepOptions, const OdStreamBuf *pSat = 0 );

  // Return defining data.

  OdDbEntityPtr getSweepEntity(ODSYSDEF) const;
  OdDbEntityPtr getPathEntity(ODSYSDEF) const;

  OdDbEntity* getSweepEntity() const;
  OdDbEntity* getPathEntity() const;

  OdDb3dProfile* sweepProfile() const;
  OdDb3dProfile* pathProfile() const;
  // Get/set the sweep options.

  void getSweepOptions ( OdDbSweepOptions& sweepOptions ) const;
  OdResult setSweepOptions ( const OdDbSweepOptions& sweepOptions );

  // Return length of path curve.
  OdResult getPathLength ( double& len ) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm );

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
};

typedef OdSmartPtr<OdDbSweptSurface> OdDbSweptSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbSweptSurface_h_Included_
