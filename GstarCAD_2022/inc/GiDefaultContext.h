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


#ifndef _ODGI_DEFAULTCONTEXT_INCLUDED_
#define _ODGI_DEFAULTCONTEXT_INCLUDED_

#include "Gi/GiCommonDraw.h"
#include "DbRootExport.h"
#include "Ge/GeMatrix3d.h"
#include "OdFont.h"

#include "TD_PackPush.h"


/** Description:
    This class defines the default context that is used in the Teigha vectorization of OdDbDatabase instances.

    Library: TD_DbRoot
    
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdGiDefaultContext : public OdGiContext
{
public:
  ODRX_DECLARE_MEMBERS(OdGiDefaultContext);

  OdGiDefaultContext();
  ~OdGiDefaultContext();

  virtual void getDefaultTextStyle(OdGiTextStyle& textStyle);

  virtual void drawText(
    OdGiCommonDraw* pDraw,
    OdGePoint3d& position,
    const OdChar* msg,
    OdInt32 numBytes,
    const OdGiTextStyle* pTextStyle,
    OdUInt32 flags = 0);

  virtual void drawText(
    OdGiCommonDraw* pDraw,
    OdGePoint3d& position,
    double height,
    double width,
    double oblique,
    const OdString& msg);

  virtual void drawText(
    OdGiConveyorGeometry* pDest,
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg,
    OdInt32 nLength,
    bool raw,
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion);

  virtual void drawShape(
    OdGiCommonDraw* pDraw, 
    OdGePoint3d& position, 
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle);

  void drawShape(
    OdGiConveyorGeometry* pDest,
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber,
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion);

  virtual void textExtentsBox(
    const OdGiTextStyle& textStyle, 
    const OdChar* msg, 
    int nLength,
    OdUInt32 flags, 
    OdGePoint3d& min, 
    OdGePoint3d& max, 
    OdGePoint3d* pEndPos = 0);

  virtual void textExtentsBox(
    const OdGiTextStyle& textStyle, 
    const OdChar* msg, 
    int nLength,
    OdUInt32 flags, 
    OdGePoint3d& min, 
    OdGePoint3d& max, 
    OdGePoint3d* pEndPos,
    OdDoubleArray* pCharWidths);

  virtual void shapeExtentsBox(
    const OdGiTextStyle& textStyle, 
    int shapeNumber, 
    OdGePoint3d& min, 
    OdGePoint3d& max);
  
  virtual void setPlotGeneration(
    bool plotGeneration) = 0;
  
  virtual ODCOLORREF paletteBackground() const = 0;
  virtual void setPaletteBackground(
    ODCOLORREF paletteBackground) = 0;

  virtual bool isZeroTextNormals() const { return false; }

  virtual void initTextProc(const OdGePoint3d& /*position*/,
    const OdGeVector3d& /*u*/, const OdGeVector3d& /*v*/,
    const OdChar* /*msg*/, OdInt32 /*nLength*/, 
    double /*aspect*/, const void* /*pLogFont*/) {}

  virtual void saveTTFCharData(OdChar /*ch*/, 
    const OdGePoint2d& /*advance*/, const OdGeMatrix3d& /*mat*/) { }
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiDefaultContext object pointers.
*/
typedef OdSmartPtr<OdGiDefaultContext> OdGiDefaultContextPtr;


#include "TD_PackPop.h"

#endif //_ODGI_DEFAULTCONTEXT_INCLUDED_
