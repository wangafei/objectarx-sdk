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




#ifndef _OD_DB_FACE_
#define _OD_DB_FACE_

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class represents 3D face entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbFace : public OdDbEntity
{
public:                
  ODDB_DECLARE_MEMBERS(OdDbFace);

  OdDbFace();

  /** Gcad(Add):增加兼容接口	
  */
  OdDbFace(const OdGePoint3d&   pt0,
		   const OdGePoint3d&   pt1,
		   const OdGePoint3d&   pt2,
		   const OdGePoint3d&   pt3,
				 OdBool e0vis = kTrue,
				 OdBool e1vis = kTrue,
				 OdBool e2vis = kTrue,
				 OdBool e3vis = kTrue);

  /** Gcad(Add):增加兼容接口	
  */
  OdDbFace(const OdGePoint3d&   pt0,
		   const OdGePoint3d&   pt1,
		   const OdGePoint3d&   pt2,
				 OdBool e0vis = kTrue,
				 OdBool e1vis = kTrue,
				 OdBool e2vis = kTrue,
				 OdBool e3vis = kTrue);

  /** Gcad(Add):增加兼容接口	
  */
  ~OdDbFace();

  /** Description:
    Returns the WCS value of the specified *vertex* (DXF 10-13).

    Arguments:
    vertexIndex (I) Vertex *index*. [0 .. 3].
    vertex (O) Receives the WCS value of the specified *vertex*.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult getVertexAt(
    OdUInt16 vertexIndex, 
    OdGePoint3d& vertex) const;

  /** Description:
  Sets the WCS value of the specified *vertex* (DXF 10-13).

  Arguments:
    vertexIndex (I) Vertex *index*. [0 .. 3].
    vertex (I) The WCS value for the specified *vertex*.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setVertexAt(
    OdUInt16 vertexIndex, 
    const OdGePoint3d& vertex);

  /** Description:
    Returns true if and only if the specified edge is visible (DXF 70).

    Arguments:
    edgeIndex (I) Edge *index*. [0 .. 3].
  */
  bool isEdgeVisibleAt(
    OdUInt16 edgeIndex) const;

  /** Gcad(Add):增加兼容接口	
  */
  OdResult isEdgeVisibleAt(
    OdUInt16 edgeIndex, 
    OdBool& visible) const;

  /** Description:
    Turns on the *visibility* for the specified edge (DXF 70).

    Arguments:
    edgeIndex (I) Edge *index*. [0 .. 3].

	Gcad(Modify):returns:void->OdResult
  */
  OdResult makeEdgeVisibleAt(
    OdUInt16 edgeIndex);

  /** Description:
    Turns off the *visibility* for the specified edge (DXF 70).

    Arguments:
    edgeIndex (I) Edge *index*. [0 .. 3].

	Gcad(Modify):returns:void->OdResult
  */
  OdResult makeEdgeInvisibleAt(
    OdUInt16 edgeIndex);

  /** Gcad(TODO): in & out
    returns: void->OdResult
  */
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm);

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual OdBool     isPlanar() const;
  virtual OdResult   getPlane(OdGePlane& plane, OdDb::Planarity& planarity) const;
  /*
  OdDbFace(const OdGePoint3d& pt0, const OdGePoint3d& pt1, const OdGePoint3d& pt2,
  const OdGePoint3d& pt3, bool e0vis = true, bool e1vis = true,
  bool e2vis = true, bool e3vis = true);
  OdDbFace(const OdGePoint3d& pt0, const OdGePoint3d& pt1, const OdGePoint3d& pt2,
  bool e0vis = true, bool e1vis = true, bool e2vis = true, bool e3vis = true);
  */

};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbFace object pointers.
*/
typedef OdSmartPtr<OdDbFace> OdDbFacePtr;

#include "TD_PackPop.h"

#endif
