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


#ifndef _DbRevolvedSurface_h_Included_
#define _DbRevolvedSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"
#include "DbRevolveOptions.h"

/** Description:
    This class implements a three-dimensional revolved surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRevolvedSurface: public OdDbSurface
{
public:
  OdDbRevolvedSurface ();
  ODDB_DECLARE_MEMBERS(OdDbRevolvedSurface);

  virtual ~OdDbRevolvedSurface();
  // Create revolved surface.

  virtual OdResult createRevolvedSurface ( OdDbEntity* pRevEnt,
    const OdGePoint3d& axisPnt, const OdGeVector3d& axisDir,
    double revAngle, double startAngle,
    OdDbRevolveOptions& revolveOptions, const OdStreamBuf *pSat = 0 );

  // Return the revolve entity.

  OdDbEntity*   getRevolveEntity () const;

  OdDb3dProfile* revolveProfile() const;

  // Get/set the axis of revolution.

  OdGePoint3d getAxisPnt () const;
  OdResult setAxisPnt( const OdGePoint3d& pnt );
  OdGeVector3d getAxisVec () const;
  OdResult setAxisVec( const OdGeVector3d& vec );

  // Get/set angle of revolution.

  double getRevolveAngle () const;
  OdResult setRevolveAngle ( double ang );
  double getStartAngle () const;
  void setStartAngle (double startAng);

  // Get/set revolve options for the surface.

  void getRevolveOptions ( OdDbRevolveOptions& revolveOptions ) const;
  OdResult setRevolveOptions ( const OdDbRevolveOptions& revolveOptions );

  // Set all defining data.

  OdResult setRevolve ( const OdGePoint3d& axisPnt, const OdGeVector3d& axisVec,
    double revAngle, const OdDbRevolveOptions& revolveOptions );

  OdResult subTransformBy(
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

typedef OdSmartPtr<OdDbRevolvedSurface> OdDbRevolvedSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbRevolvedSurface_h_Included_
