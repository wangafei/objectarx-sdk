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




#ifndef __ODGIPOLYLINE_H__
#define __ODGIPOLYLINE_H__

class OdGeVector3d;
class OdGeLineSeg2d;
class OdGeLineSeg3d;
class OdGeCircArc2d;
class OdGeCircArc3d;

#include "../TD_PackPush.h"

#include "../Gi/GiExport.h"

/** Description:
    This class implements the OdGi equivalent of an OdDbPolyline or "lightweight" polyline.
    Remarks: 
    Instances of this class are used to pass lightweight polyline data through the 
    Teigha vectorization framework.

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiPolyline : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiPolyline);

  enum SegType
  {
    kLine,        // Straight segment with length greater than 0.
    kArc,         // Arc segment with length greater than 0.
    kCoincident,  // Segment with 0 length.
    kPoint,       // Polyline with a single vertex.
    kEmpty        // No vertices are present.
  };

  /** Description:
      Returns the number of vertices in the entity.
  */
  virtual unsigned int numVerts() const = 0;

  /** Description:
      Returns true if this polyline is closed, false otherwise. 
  */
  virtual OdBool isClosed() const = 0;

  /** Description:
      Returns the *normal* vector for this entity.
  */
  virtual OdGeVector3d getNormal() const = 0;

  /** Description:
      Returns the *thickness* for this entity.
  */
  virtual double thickness() const = 0;

  /** Description:
      Returns the constant width for this entity.  
  */
  virtual double getConstantWidth() const = 0;

  /** Description:
      Returns true if the vertices in this entity contain start and end width data, false otherwise.
  */
  virtual bool hasWidth() const = 0;

  /** Description:
      Returns the PLINEGEN flag for this entity. If PLINEGEN is true,
      linetype generation will be patterned across the entire polyline, rather than 
      being done for each segment individually.
  */
  virtual bool hasPlinegen() const = 0;

  /** Description:
      Returns the *elevation* for this entity.
  */
  virtual double elevation() const = 0;

  /** Description:
      Returns the segment type at the specified index.

      See Also:
      SegType
  */
  virtual SegType segType(unsigned int index) const = 0;
  
  /** Description:
  */
  virtual void getLineSegAt(unsigned int index, OdGeLineSeg2d& ln) const = 0;

  /** Description:
      Returns the line segment starting at the specified index.
  */
  virtual void getLineSegAt(unsigned int index, OdGeLineSeg3d& ln) const = 0;

  /** Description:
      Returns the arc segment starting at the specified index.
  */
  virtual void getArcSegAt(unsigned int index, OdGeCircArc2d& arc) const = 0;

  virtual void getArcSegAt(unsigned int index, OdGeCircArc3d& arc) const = 0;

  /** Description:
      Returns a specified point from this entity.
  */
  virtual void getPointAt(unsigned int index, OdGePoint2d& pt) const = 0;

  /** Description:
      Returns the bulge value for a specified point.
  */
  virtual double getBulgeAt(unsigned int index) const = 0;

  /** Description:
      Returns the start and end widths for a specified point.
  */
  virtual void getWidthsAt(unsigned int index, double& startWidth,  double& endWidth) const = 0;

  /** Description:
      Returns the original OdDbPolyline object from which this OdGiPolyline was 
      created.
  */
  virtual OdRxObjectPtr getDbPolyline() const = 0;

  virtual const OdGeVector3d* normal() const = 0;
  virtual bool hasBulges() const = 0;
  virtual void enableConstantWidth(bool bEnable) const = 0;
  virtual bool getThinLineSegPts(OdGePoint3dArray &, double) const = 0;
  virtual const OdGePoint2d* getRawPoints() const = 0;
  virtual const OdGeDoubleArray& getRawBulges() const = 0;
  virtual const OdGePoint3d* vertexList() const = 0;
  virtual unsigned int points() const = 0;
  virtual OdLongPtr baseSubEntMarker() const = 0;
};

typedef OdSmartPtr<OdGiPolyline> OdGiPolylinePtr;

#include "../TD_PackPop.h"

#endif  // __ODGIPOLYLINE_H__

