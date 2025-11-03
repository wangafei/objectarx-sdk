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

#ifndef ODGSLTYPEREDIR_INC
#define ODGSLTYPEREDIR_INC

#include "../TD_PackPush.h"

#include "../Gi/GiLinetyper.h"
#include "../Gi/GiDgLinetyper.h"

#include "../Gs/GsExtAccum.h"

/** Description:
    Linetype redirection conveyor node.

    Library: TD_Gs

    {group:OdGs_Classes}
*/
class GS_TOOLKIT_EXPORT OdGsLinetyper : public OdGiDgLinetyper,
                                        public OdGsConveyorNodeBase
{
  OdGiLinetyperPtr m_pLinetyper;
  OdGiDgLinetyperPtr m_pDgLinetyper;
  OdGiLinetyper *m_pCurLinetyper;
public:
  enum Direction
  {
    kToStandard = 0,
    kToDg
  };
private:
  Direction m_curDirection;
  OdGiConveyorContext* m_pDrawCtx;
  OdGeDoubleArray m_devArray;
  const OdGiDeviation* m_pDeviation;
protected:
  OdGsLinetyper();
public:

  ODRX_DECLARE_MEMBERS(OdGsLinetyper);

  // OdGsConveyorNodeBase interface

  virtual OdGiConveyorGeometry* optionalGeometry();

  // OdGiConveyorNode interface

  virtual OdGiConveyorInput& input();
  virtual OdGiConveyorOutput& output();

  // conveyor sync interface
  void addSourceNode(OdGiConveyorOutput& sourceNode);
  void removeSourceNode(OdGiConveyorOutput& sourceNode);
  void setDestGeometry(OdGiConveyorGeometry& destGeometry);

  // OdGiLinetyper interface

  virtual void setDrawContext(OdGiConveyorContext* pDrawCtx);
  virtual void setDeviation(const OdGeDoubleArray& deviations);
  virtual void setDeviation(const OdGiDeviation* pDeviation);
  virtual OdUInt32 setLinetype(OdDbStub* id, double scale, double generationCriteria = 0.);
  virtual OdGiLinetypeTraits& linetypeTraits() const;
  virtual void enable();
  virtual bool enabled() const;
  virtual void disable();
  virtual void setAnalyticLinetypingCircles(bool bAnalytic);
  virtual bool isAnalyticLinetypingCircles() const;
  virtual void setAnalyticLinetypingComplexCurves(bool bAnalytic);
  virtual bool isAnalyticLinetypingComplexCurves() const;
  virtual OdGiConveyorGeometry* redirectionGeometry();
  virtual void enableCache();
  virtual void disableCache();
  virtual bool cacheEnabled() const;
  virtual void clearCache();

  // OdGiDgLinetyper interface

  virtual OdGiDgLinetypeTraits& dgLinetypeTraits() const;

  // OdGsLinetyper methods

  void switchTo(Direction dir);
  
  Direction currentRedir() const { return m_curDirection; }

  OdGiLinetyper *activeLinetyper() { return m_pCurLinetyper; }
  const OdGiLinetyper *activeLinetyper() const { return m_pCurLinetyper; }
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsLinetyper object pointers.
*/
typedef OdSmartPtr<OdGsLinetyper> OdGsLinetyperPtr;

#include "../TD_PackPop.h"

#endif // ODGSLTYPEREDIR_INC
