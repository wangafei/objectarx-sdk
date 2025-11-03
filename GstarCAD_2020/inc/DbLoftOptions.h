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


#ifndef _DbLoftOptions_h_Included_
#define _DbLoftOptions_h_Included_

#include "TD_PackPush.h"
#include "DbEntity.h"
#include "ModelerGeometryCreator.h"

class OdDbLoftOptionsImpl;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLoftOptions
{
public:
  OdDbLoftOptions();
  OdDbLoftOptions(const OdDbLoftOptions& src);
  ~OdDbLoftOptions();

  OdDbLoftOptions& operator = (const OdDbLoftOptions& rhs);

  enum NormalOption 
  {
    kNoNormal       = 0,
    kFirstNormal    = 1,
    kLastNormal     = 2,
    kEndsNormal     = 3,
    kAllNormal      = 4,
    kUseDraftAngles = 5
  };

  double draftStart() const;

  void setDraftStart(double angle);

  double draftEnd() const;

  void setDraftEnd(double angle);

  double draftStartMag() const;

  void setDraftStartMag(double startMag);

  double draftEndMag() const;

  void setDraftEndMag(double val);

  bool arcLengthParam() const;

  void setArcLengthParam(bool alParam);

  bool noTwist() const;

  void setNoTwist(bool noTwist);

  bool alignDirection() const;

  void setAlignDirection(bool alignDir);

  bool simplify() const;

  void setSimplify(bool simplify);

  bool closed() const;

  void setClosed(bool closed);

  bool ruled() const;

  void setRuled(bool ruled);

  bool virtualGuide() const;

  void setVirtualGuide(bool virtGuide);

  OdDbLoftOptions::NormalOption normal() const;

  void setNormal(OdDbLoftOptions::NormalOption option);

  OdResult setOptionsFromSysvars(const OdDbDatabase& pDb);
  OdResult setOptionsFromSysvars();

  OdResult setSysvarsFromOptions(OdDbDatabase& pDb);
  OdResult setSysvarsFromOptions();
  OdResult checkOptions(bool displayErrorMessages = false);

  OdResult checkLoftCurves(
    OdArray<OdDbEntity*>& crossSectionCurves,
    OdArray<OdDbEntity*>& guideCurves,
    OdDbEntity* pPathCurve,
    bool& allOpen, 
    bool& allClosed, 
    bool& allPlanar,
    bool displayErrorMessages = false);

  OdResult checkCrossSectionCurves(
     OdArray<OdDbEntity*>& crossSectionCurves,
    bool& allOpen, 
    bool& allClosed, 
    bool& allPlanar,
    bool displayErrorMessages = false);

  OdResult checkGuideCurves(OdArray<OdDbEntity*>& guideCurves,
    bool displayErrorMessages = false);


  OdResult checkPathCurve(OdDbEntity *pPathCurve,
    bool displayErrorMessages = false);


private:
  friend class OdDbLoftOptionsImpl;
  OdDbLoftOptionsImpl *m_pImpl;
};

#include "TD_PackPop.h"
#endif // _DbLoftOptions_h_Included_
