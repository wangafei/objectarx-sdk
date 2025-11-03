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


#ifndef _DbLoftedSurface_h_Included_
#define _DbLoftedSurface_h_Included_

#include "TD_PackPush.h"
#include "DbSurface.h"
#include "DbLoftOptions.h"


/** Description:
    This class implements a three-dimensional lofted surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLoftedSurface : public OdDbSurface
{
public:
  OdDbLoftedSurface ();
  ODDB_DECLARE_MEMBERS(OdDbLoftedSurface);

  virtual ~OdDbLoftedSurface();
  // Create lofted surface.
  virtual OdResult createLoftedSurface(
    OdArray<OdDbEntity *>& crossSectionCurves,
    OdArray<OdDbEntity *>& guideCurves,
    OdDbEntity* pPathCurve, 
    OdDbLoftOptions& loftOptions, const OdStreamBuf *pSat = 0 );
  // Return defining data.

  virtual OdResult createBlendSurface(
    OdDbEntityPtrArray& blendedEdges,
    OdDbBlendOptions& loftOptions, const OdStreamBuf *pSat = 0);// , const bool byCoedges = false );

  int           numCrossSections () const;
  //Gcad(internal)
  OdDbEntityPtr getCrossSection (ODSYSDEF, int idx ) const;
  //Gcad(add)
  OdDbEntity* getCrossSection (int idx ) const;

  int           numGuideCurves () const;
  //Gcad(internal)
  OdDbEntityPtr getGuideCurve ( ODSYSDEF,int idx ) const;
  //Gcad(Add)
  OdDbEntity* getGuideCurve ( int idx ) const;
  //Gcad(internal)
  OdDbEntityPtr getPathEntity (ODSYSDEF) const;
  //Gcad(Add)
  OdDbEntity* getPathEntity () const;

  void          getLoftOptions ( OdDbLoftOptions& loftOptions ) const;

  // Set new loft options and recreate the surface.

  OdResult setLoftOptions ( const OdDbLoftOptions& loftOptions );

  OdDbLoftProfile*  crossSection(int idx) const;
  void              getCrossSections(OdArray<OdDbLoftProfile*>& crossSections) const;

  OdDbLoftProfile*  guide(int idx) const;
  void              getGuides(OdArray<OdDbLoftProfile*>& guides) const;

  OdDbLoftProfile*  path() const;

  int               startContinuity(bool isCrossSection = true) const;
  int               endContinuity(bool isCrossSection = true) const;

  double            startMagnitude(bool isCrossSection = true) const;
  double            endMagnitude(bool isCrossSection = true) const;

  OdResult          setStartContinuity(int val, bool isCrossSection = true);
  OdResult          setEndContinuity(int val, bool isCrossSection = true);

  OdResult          setStartMagnitude(double val, bool isCrossSection = true);
  OdResult          setEndMagnitude(double val, bool isCrossSection = true);

  enum LoftSurfaceType
  {
    kLoftSurf,
    kLoftBlendSurf,
    kLoftNetworkSurf
  };

  OdDbLoftedSurface::LoftSurfaceType  loftSurfaceType() const;

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

typedef OdSmartPtr<OdDbLoftedSurface> OdDbLoftedSurfacePtr;

#include "TD_PackPop.h"
#endif //_DbLoftedSurface_h_Included_
