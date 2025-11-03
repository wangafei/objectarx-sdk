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




#ifndef OD_DBMLINE_H
#define OD_DBMLINE_H

#include "TD_PackPush.h"

#include "DbEntity.h"
//#include "Ge/GeVoidPointerArray.h"

/** Description:
  This struct contains enumerated types and data used by OdDbMline.
  
  {group:Structs}
*/
struct Mline
{
  typedef OdInt8 MlineJustification;
  enum
  {
    kTop = 0,
    kZero,
    kBottom
  };
  enum
  {
    kOpen = 0,
    kClosed,
    kMerged
  };
};

class OdGePlane;

/** Description:
  Library: TD_Db
  {group:Structs}
*/      
struct OdMLSegment
{
  OdGeDoubleArray m_AreaFillParams;
  OdGeDoubleArray m_SegParams;
};

typedef OdArray<OdMLSegment> OdMLSegmentArray;

/** Description:
    This class represents multi-line (MLine) entities in an OdDbDatabase instance.
    
    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbMline : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMline);

  OdDbMline();
  virtual ~OdDbMline();

  /** Description:
    Sets the Object ID of the MLine Style of this MLine entity (DXF 340).
    Arguments:
    styleId (I) Object ID of the MLine Style
  */
  OdResult setStyle(
    const OdDbObjectId &styleId);

  /** Description:
    Returns the Object ID of the MLine Style of this MLine entity (DXF 340).
  */
  OdDbObjectId style() const;

  /** Description:
    Sets the *justification* of this MLine entity (DXF 70).
    Arguments:
    justification (I) Justification.
  */
  OdResult setJustification(Mline::MlineJustification justification);

  /** Description:
    Returns the *justification* of this MLine entity (DXF 70).
  */
  Mline::MlineJustification justification() const;

  /** Description:
    Sets the *scale* of this entity (DXF 40).
  */
  OdResult setScale(
    double scale);

  /** Description:
    Returns the *scale* of this entity (DXF 40).
  */
  double scale() const;

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  /** Description:
    Appends a vertex onto the end of this MLine entity.

    Arguments:
    newVertex (I) Vertex to append.
    
    Remarks:
    newVertex is projected onto the plane of this MLine entity, and this projected vertex
    appended to it.     
  */
  OdResult appendSeg(
    const OdGePoint3d& newVertex);

  /** Description:
    Returns and removes the last vertex from this MLine entity.

    Arguments:
    lastVertex (O) Receives the last vertex.
  */
  OdResult removeLastSeg
    (OdGePoint3d& lastVertex);

  /** Description:
    Moves the specified vertex of this MLine entity.

    Arguments:
    vertexIndex (I) Vertex index.
    newPosition (I) New WCS position for specified vertex.

    Remarks:
    newPosition is projected onto the plane of this MLine entity, and this projected vertex
    replaces the specified vertex.     
  */
  OdResult moveVertexAt(
    int vertexIndex, 
    const OdGePoint3d& newPosition);

  /** Description:
    Controls the closed status of this MLine entity (DXF 71, bit 0x02).
    
    Arguments:
    closedMline (I) Sets this MLine closed if true, open if false.
  */
  OdResult setClosedMline(
    bool closedMline);

  /** Description:
    Returns the closed status of this MLine entity(DXF 71, bit 0x02).
    Remarks:
    Returns true if and only if this MLine entity is closed.
  */
  bool closedMline() const;

  /** Description:
    Sets the "Suppress Start Caps" status of this MLine entity (DXF 71, bit 0x04).

    Arguments:
    suppressIt (I) Suppresses start caps if true, enables start caps if false.
  */
  void setSupressStartCaps(
    bool supressIt);

  /** Description:
    Returns the "Suppress Start Caps" status of this MLine entity (DXF 71, bit 0x04).

    Remarks:
    Returns true if and only if start caps are suppressed.
  */
  bool supressStartCaps() const;

  /** Description:
    Sets the "Suppress End Caps" status of this MLine entity (DXF 71, bit 0x04).

    Arguments:
    suppressIt (I) Suppresses end caps if true, enables end caps if false.
  */
  void setSupressEndCaps(
    bool supressIt);

  /** Description:
    Returns the "Suppress End Caps" status of this MLine entity (DXF 71, bit 0x04).

    Remarks:
    Returns true if and only if end caps are suppressed.
  */
  bool supressEndCaps() const;

  /** Description:
    Returns the number of vertices in this MLine entity (DXF 72).
  */
  int numVertices() const;

  /** Description:
    Returns the specified vertex of this MLine entity (DXF 10 or 11).
    Arguments:
    vertexIndex (I) Vertex index.
  */
  OdGePoint3d vertexAt(
    int vertexIndex) const;

  /** Description:
    Returns the *direction* vector of the segment starting at the specified vertex (DXF 12).
    Arguments:
    vertexIndex (I) Vertex index.
  */
  OdGeVector3d axisAt(
    int vertexIndex) const;

  /** Description:
    Returns the *direction* vector of the miter starting at the specified vertex (DXF 13).
    Arguments:
    vertexIndex (I) Vertex index.
  */
  OdGeVector3d miterAt(
    int vertexIndex) const;

  /** Description:
    Returns the element and area fill parameters at the specified vertex (DXF 41 and 42).
    Arguments:
    vertexIndex (I) Vertex index.
    params (O) Receives the element and area fill parameters.
  */
  OdResult getParametersAt(int index, OdMLSegmentArray& params) const;
  
  OdResult getParametersAt(int index, OdGeVoidPointerArray& params) const;

  /** Description:
    Sets the element and area fill parameters at the specified vertex (DXF 41 and 42).
    Arguments:
    vertexIndex (I) Vertex index.
    params (I) Element and area fill parameters.
  */
  OdResult setParametersAt(
    int vertexIndex, 
    const OdMLSegmentArray& params);

  OdResult setParametersAt(
    int index,
    OdGeVoidPointerArray& params);

  /** Description:
    Attempts to find which element of the Mline object contains the point.
    Arguments:
    pt (I) Point to find intersection with Mline elements.
    Remarks:
    If an element is not found that directly contains the point and the Mline object is not closed,
    then the ends of the MLine object are virtually extended to see if point lies in the path of any
    element. 
    If successful, the index number of the element that contains point is returned.
    If not successful, then -1 is returned.
  */
  int element(const OdGePoint3d &pt) const;

  /** Description:
    Finds closest point to this Mline object.
    Arguments:
    pt (I) Input point.
    ptOut (O) Output point.
    bExtend (I) Virtually extends Mline geometry.
    bExcludeCaps (I) Excludes Mline start/end caps and joints.
  */
  OdResult getClosestPointTo(const OdGePoint3d &pt, OdGePoint3d& ptOut, bool bExtend, bool bExcludeCaps = false) const;

  /** Description:
    Finds closest point to this Mline object projected on specified plane.
    Arguments:
    pt (I) Input point.
    norm (I) Plane normal.
    ptOut (O) Output point.
    bExtend (I) Virtually extends Mline geometry.
    bExcludeCaps (I) Excludes Mline start/end caps and joints.
  */
  OdResult getClosestPointTo(const OdGePoint3d &pt, const OdGeVector3d &norm, OdGePoint3d& ptOut, bool bExtend, bool bExcludeCaps = false) const;

  void getPlane(OdGePlane &plane) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const; /* Replace OdRxObjectPtrArray */

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult subClose();

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMline object pointers.
*/
typedef OdSmartPtr<OdDbMline> OdDbMlinePtr;

#include "TD_PackPop.h"

#endif

