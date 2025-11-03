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




#ifndef OD_WIPEOUT_H
#define OD_WIPEOUT_H

#include "TD_PackPush.h"

#include "DbRasterImage.h"

/** Description:
  This class represents wipeout entities in an OdDbDatabase instance.
  Library: TD_Db
  {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbWipeout : public OdDbRasterImage
{
public:
  ODDB_DECLARE_MEMBERS(OdDbWipeout);

  OdDbWipeout();
  
  virtual OdRxObject* clone() const;

  virtual OdGeVector2d imageSize(OdBool bGetCachedValue = kFalse) const;
  
  OdGiSentScanLines* getScanLines(const OdGiRequestScanLines& req) const;
  
  OdBool isClipped() const;
  
  virtual void setDisplayOpt(ImageDisplayOpt option,OdBool bValue);
  
  virtual OdBool isSetDisplayOpt(ImageDisplayOpt option) const;
  
  virtual OdBool setBrightness(OdInt8 value);
  
  virtual OdInt8 brightness() const;
  
  virtual OdBool setContrast(OdInt8 value);
  
  virtual OdInt8 contrast() const;
  
  virtual OdBool setFade(OdInt8 value);
  
  virtual OdInt8 fade() const;
  
  virtual OdGeVector2d scale() const;
  
  
  
  
  /** Description:
      Sets orientation and boundary for this Wipeout entity (DXF 10, 11, 12, 71, 14, 24).
      Arguments:
      boundary (I) Array of planar WCS points.
  */
  void setBoundary(const OdGePoint3dArray& boundary);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;
#ifdef ODARXDEF
  OdResult append(OdDbObjectId& id);
#endif
  OdBool  frame() const;
  OdBool  setFrame(OdBool bFrame);

  static OdResult createImageDefinition();

  static OdResult fitPointsToImage(OdGePoint2dArray& pointArray, OdGePoint2d& minPoint, double& scale, OdBool bFlipY = kFalse);

};
 
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbWipeout object pointers.
*/
typedef OdSmartPtr<OdDbWipeout> OdDbWipeoutPtr;

#include "TD_PackPop.h"

#endif  // OD_WIPEOUT_H

