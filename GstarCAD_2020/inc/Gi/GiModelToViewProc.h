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

#ifndef __ODGIMODELTOVIEWPROC_H__
#define __ODGIMODELTOVIEWPROC_H__

#include "../Gi/GiConveyorNode.h"
#include "../Ge/GeDoubleArray.h"

class OdGeMatrix3d;
class OdGiDeviation;
class OdGiXform;
class OdGiAbstractClipBoundary;

/** Description:

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiModelToViewProc : public OdRxObject
{
protected:
  OdGiModelToViewProc();
public:
  ODRX_DECLARE_MEMBERS(OdGiModelToViewProc);

  virtual void setDrawContext( OdGiConveyorContext* pDrawCtx ) = 0;

  virtual OdGiConveyorInput& modelInput() = 0;
  virtual OdGiConveyorInput& eyeInput() = 0;

  virtual OdGiConveyorOutput& output() = 0;

  virtual void setEyeToOutputTransform(const OdGeMatrix3d& xMat) = 0;
  virtual const OdGeMatrix3d& eyeToOutputTransform() const = 0;

  virtual void setView(
    const OdGePoint3d& target,
    const OdGeVector3d& xVector,
    const OdGeVector3d& upVector,
    const OdGeVector3d& eyeVector) = 0;
  virtual void setWorldToEyeTransform(const OdGeMatrix3d& xMat) = 0;

  virtual const OdGeMatrix3d& worldToEyeTransform() const = 0;
  virtual const OdGeMatrix3d& eyeToWorldTransform() const = 0;

  virtual const OdGeMatrix3d& modelToEyeTransform() const = 0;
  virtual const OdGeMatrix3d& eyeToModelTransform() const = 0;
  
  virtual void pushModelTransform(const OdGeMatrix3d& xMat) = 0;
  virtual void popModelTransform() = 0;
  virtual const OdGeMatrix3d& modelToWorldTransform() const = 0;
  virtual const OdGeMatrix3d& worldToModelTransform() const = 0;

  virtual OdGiXform *getModelToEyeXform() = 0;
  virtual const OdGiXform *getModelToEyeXform() const = 0;
  virtual OdGiXform *getEyeToModelXform() = 0;
  virtual const OdGiXform *getEyeToModelXform() const = 0;

  virtual void pushClipBoundary(OdGiClipBoundary* pBoundary) = 0;
  virtual void pushClipBoundary(OdGiClipBoundary* pBoundary, OdGiAbstractClipBoundary* pClipInfo) = 0;
  virtual void popClipBoundary() = 0;

  virtual bool isClipping() const = 0;
  virtual bool isEmptyClipSet() const = 0;

  virtual void setWorldDeviation(const OdGiDeviation& worldDev) = 0;
  virtual void setWorldDeviation(const OdGeDoubleArray& deviations) = 0;

  virtual const OdGiDeviation& worldDeviation() const = 0;
  virtual const OdGiDeviation& modelDeviation() const = 0;
  virtual const OdGiDeviation& eyeDeviation() const = 0;
};


typedef OdSmartPtr<OdGiModelToViewProc> OdGiModelToViewProcPtr;

#endif //#ifndef __ODGIMODELTOVIEWPROC_H__
