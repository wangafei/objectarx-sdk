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


#ifndef _DbSweepOptions_h_Included_
#define _DbSweepOptions_h_Included_

#include "TD_PackPush.h"
#include "DbEntity.h"


class OdDbSweepOptionsImpl;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSweepOptions
{
public:
  OdDbSweepOptions ();
  ~OdDbSweepOptions ();
  OdDbSweepOptions ( const OdDbSweepOptions& src );
  OdDbSweepOptions& operator = ( const OdDbSweepOptions& src );

  enum AlignOption 
  {
    kNoAlignment                = 0,
    kAlignSweepEntityToPath     = 1,
    kTranslateSweepEntityToPath = 2,
    kTranslatePathToSweepEntity = 3
  };

  enum MiterOption 
  {
    kDefaultMiter = 0,
    kOldMiter     = 1,
    kNewMiter     = 2,
    kCrimpMiter   = 3,
    kBendMiter    = 4
  };

  /** Description:
      Returns the draft angle.
  */
  double  draftAngle () const;

  /** Description:
      Sets the draft angle.
  */
  void  setDraftAngle ( double ang );

  /** Description:
      Returns the start draft distance.
  */
  double  startDraftDist () const;

  /** Description:
      Sets the start draft distance.
  */
  void  setStartDraftDist ( double val );

  /** Description:
      Returns the end draft distance.
  */
  double  endDraftDist () const;

  /** Description:
      Sets the start draft distance.
  */
  void  setEndDraftDist ( double val );

  /** Description:
      Returns the twist angle.
  */
  double  twistAngle () const;

  /** Description:
      Sets the twist angle.
  */
  void  setTwistAngle ( double ang );

  /** Description:
      Returns the scale factor.
  */
  double  scaleFactor () const;

  /** Description:
      Sets the scale factor.
  */
  void  setScaleFactor ( double val );

  /** Description:
      Returns the align angle.
  */
  double  alignAngle () const;

  /** Description:
      Sets the align angle.
  */
  void  setAlignAngle ( double ang );

  /** Description:
      Returns the align option.
  */
  OdDbSweepOptions::AlignOption  align () const;

  /** Description:
      Sets the align option.
  */
  void  setAlign ( OdDbSweepOptions::AlignOption val );

  /** Description:
      Returns the miter option.
  */
  OdDbSweepOptions::MiterOption  miterOption () const;

  /** Description:
      Sets the miter option.
  */
  void  setMiterOption ( OdDbSweepOptions::MiterOption val );

  /** Description:
      Returns the align start.
  */
  bool  alignStart () const;

  /** Description:
      Sets the align start.
  */
  void  setAlignStart ( bool val );

  /** Description:
      Returns the base point for alignment.
  */
  OdGePoint3d  basePoint () const;

  /** Description:
      Sets the base point for alignment.
  */
  void  setBasePoint ( const OdGePoint3d& pnt );

  /** Description:
      Returns the bank flag.
  */
  bool  bank () const;

  /** Description:
      Sets the bank flag.
  */
  void  setBank ( bool val );

  /** Description:
      Returns the check self-intersections flag.

      Remarks:
      If this flag is disabled, a self-intersecting surface may be created.
  */
  bool  checkIntersections () const;

  /** Description:
      Sets the check self-intersections flag.

      Remarks:
      If this flag is disabled, a self-intersecting surface may be created.
  */
  void  setCheckIntersections ( bool val );

  /** Description:
      Returns the twist vector.
  */
  OdGeVector3d  twistRefVec () const;

  /** Description:
      Sets the twist vector.
  */
  void  setTwistRefVec ( const OdGeVector3d& vec );

  /** Description:
      Returns the transformation associated with this entity.
  */
  bool  getSweepEntityTransform ( OdGeMatrix3d& mat )const;

  /** Description:
      Sets the transformation associated with this entity.
  */
  void  setSweepEntityTransform ( const OdGeMatrix3d& mat ); 
  OdResult setSweepEntityTransform ( OdArray<OdDbEntity*>& sweepEntities,bool displayErrorMessages = false );
  /** Description:
      Returns the transformation associated with the start and end of the path curve.
  */
  bool  getPathEntityTransform ( OdGeMatrix3d& mat )const;

  /** Description:
      Sets the transformation associated with the start and end of the path curve.
  */
  void  setPathEntityTransform ( const OdGeMatrix3d& mat ); 

  /** Description:
      Sets the transformation associated with the start and end of the path curve.

      Remarks:
      setSweepEntityTranform should be called prior to calling this function.
  */
  OdResult  setPathEntityTransform ( OdDbEntity *pPathEnt,  bool displayErrorMessages = false );

  /** Description:
      Determines if the specified sweep entity is valid, and returns the planarity of the sweep entity.
      
      Remarks:
      If kPlanar is returned, then "pnt" and "vec" will specify the normal plane
      of the entity.  If kLinear is returned, then "pnt" and "vec" will specify
      a defining point and direction of the sweep entity.
  */
  OdResult  checkSweepCurve ( OdDbEntity *pSweepEnt,
    OdDb::Planarity& planarity, OdGePoint3d& pnt, OdGeVector3d& vec,
    bool& closed, double& approxArcLen, bool displayErrorMessages = false );

  /** Description:
      Determines if the passed in path curve is valid.
  */
  OdResult  checkPathCurve ( OdDbEntity *pPathEnt,    bool displayErrorMessages = false );

private:
  friend class OdDbSweepOptionsImpl;
  OdDbSweepOptionsImpl *m_pImpl;
};

#include "TD_PackPop.h"
#endif //_DbSweepOptions_h_Included_
