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




#ifndef _OD_DB_FACERECORD_
#define _OD_DB_FACERECORD_

#include "TD_PackPush.h"

#include "DbVertex.h"

/** Description:
  This class represents OdDbPolyFaceMesh faces in an OdDbDatabase instance. 

  {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFaceRecord : public OdDbVertex
{
public:
  ODDB_DECLARE_MEMBERS(OdDbFaceRecord);

  OdDbFaceRecord();

  /** Gcad(Add):增加兼容接口
    注意: OdDbFaceRecord 是从 OdDbEntity 派生, 而 xxDbFaceRecord 则从 xxDbEntity 派生.
  */
  OdDbFaceRecord(
    OdInt16 vtx0, 
    OdInt16 vtx1,
    OdInt16 vtx2, 
    OdInt16 vtx3);

  /** Gcad(Add):增加兼容接口
  */
  ~OdDbFaceRecord();

  /** Description:
    Returns the index of the parent PolyFaceMesh vertex that defines the specified corner (DXF 71-74) of
    this FaceRecord entity.
    
    Arguments:
    cornerIndex (I) Corner index. [0 .. 3].

    Remarks:
    Vertex indices start at 1.  
    
    Negative indices indicate the following edge is invisible. 
    
    A zero value for cornerIndex == 3 indicates a triangular face.
  */
  OdInt16 getVertexAt(
    int cornerIndex) const;

  /** Gcad(Add):增加兼容接口	
  */
  OdResult getVertexAt(
    int cornerIndex,
    OdInt16& vertexIndex) const;

  /** Description:
    Sets the specified corner (DXF 71-74) of this FaceRecord entity to the specified index of 
    the parent PolyFaceMesh mesh vertex. 
    
    Arguments:
    cornerIndex (I) Corner index. [0 .. 3].
    vertexIndex (I) Vertex index.
    
    Remarks:
    Vertex indices start at 1.  
    
    Negative indices indicate the following edge is invisible.

    A zero value vertexIndex for cornerIndex == 3 defines a triangular face.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setVertexAt(
    int cornerIndex, 
    OdInt16 vertexIndex);
  
  /** Description:
    Returns true if and only if the specified edge of this FaceRecord entity is visible (sign of DXF 71-74)

    Arguments:
    edgeIndex (I) Edge index. [0 .. 3]
  */
  bool isEdgeVisibleAt(
    int edgeIndex) const;

  /** Gcad(Add):增加兼容接口	
  */
  OdResult isEdgeVisibleAt(
    int edgeIndex,
    OdBool& visible) const;
  
  /** Description:
    Sets visible the specified edge of this FaceRecord entity (sign of DXF 71-74)

    Arguments:
    edgeIndex (I) Edge index. [0 .. 3]

	Gcad(Modify):returns:void->OdResult
  */
  OdResult makeEdgeVisibleAt(
    int edgeIndex);

  /** Description:
    Sets invisible the specified edge of this FaceRecord entity (sign of DXF 71-74)

    Arguments:
    edgeIndex (I) Edge index. [0 .. 3]

	Gcad(Modify):returns:void->OdResult
  */
  OdResult makeEdgeInvisibleAt(
    int edgeIndex);

  /** Gcad(TODO): in & out
    returns: void->OdResult
  */
  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subErase(
    OdBool erasing);

  /**
    Note:
    Always returns eInvalidExtents.
  */
  virtual OdResult subGetGeomExtents( // Gcad(Modify)
    OdDbExtents& extents) const;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbFaceRecord object pointers.
*/
typedef OdSmartPtr<OdDbFaceRecord> OdDbFaceRecordPtr;

#include "TD_PackPop.h"

#endif
