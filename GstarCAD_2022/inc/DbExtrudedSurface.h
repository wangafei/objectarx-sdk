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


#ifndef _DbExtrudedSurface_h_Included_
#define _DbExtrudedSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"
#include "DbSweepOptions.h"

/** Description:
    This class implements a three-dimensional extruded surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbExtrudedSurface : public OdDbSurface
{
public:
  OdDbExtrudedSurface ();
  ODDB_DECLARE_MEMBERS(OdDbExtrudedSurface);

  /*/Gcad(Add):增加兼容接口	
  /*/
  virtual ~OdDbExtrudedSurface();
  //*/

  // Create extruded surface by sweeping input entity.
  virtual OdResult createExtrudedSurface (OdDbEntity* pSweepEnt,
    const OdGeVector3d& directionVec, OdDbSweepOptions& sweepOptions, const OdStreamBuf *pSat = 0);

  // Return defining data.
  /*/Gcad(internal)
  OdDbEntityPtr getSweepEntity () const;
  /*/
  OdDbEntityPtr getSweepEntity (ODSYSDEF) const;
  OdDbEntity* getSweepEntity () const;
  //*/

  OdDb3dProfile* sweepProfile() const;

  // Get/set the extrusion vector.
  OdGeVector3d getSweepVec() const;
  OdResult setSweepVec(const OdGeVector3d& sweepVec);//Gcad(Modify):void->OdResult

  // Get/set the extrusion height.
  double getHeight() const;
  OdResult setHeight(double height);//Gcad(Modify):void->OdResult

  // Get/set the sweep options.
  void getSweepOptions (OdDbSweepOptions& sweepOptions) const;
  OdResult setSweepOptions (const OdDbSweepOptions& sweepOptions);//Gcad(Modify):void->OdResult

  // Set all defining data.
  OdResult setExtrude(const OdGeVector3d& sweepVec,
    const OdDbSweepOptions& sweepOptions);

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

typedef OdSmartPtr<OdDbExtrudedSurface> OdDbExtrudedSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbExtrudedSurface_h_Included_
