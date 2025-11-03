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




#ifndef _OD_DB_POLYFACE_MESH_
#define _OD_DB_POLYFACE_MESH_

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbObjectIterator.h"

class OdDbPolyFaceMeshVertex;
class OdDbSequenceEnd;
class OdDbFaceRecord;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPolyFaceMeshVertex object pointers.
*/
typedef OdSmartPtr<OdDbPolyFaceMeshVertex> OdDbPolyFaceMeshVertexPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSequenceEnd object pointers.
*/
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

/** Description:
    This class represents PolyFaceMesh entities in an OdDbDatabase instance.
  
    Library:
    TD_Db

    Remarks:
    A PolyFaceMesh entity consists of a list of PolyFaceMeshVertex (coordinate) vertices 
    and a list of OdDbFaceRecord face records.
    Together they define a set of 3D faces.
    
    Note:
    Never derive from this class.

    {group:OdDb_Classes}
*/
//Gcad(Add)
class OdDbVertex;

class TOOLKIT_EXPORT OdDbPolyFaceMesh : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPolyFaceMesh);

  OdDbPolyFaceMesh();
  
  ~OdDbPolyFaceMesh();
	
  /** Description:
    Returns the number of vertices in this PolyFaceMesh entity (DXF 71).
  */
  OdInt16 numVertices() const;

  /** Description:
    Returns the number of faces in this PolyFaceMesh entity (DXF 72).
  */
  OdInt16 numFaces() const;
  
  /** Description:
    Appends the specified face vertex onto this PolyFaceMesh entity.

    Arguments:
    pVertex (I) Pointer to the vertex to append.

    Remarks:
    Returns the Object ID of the appended face vertex.
  */
  OdDbObjectId appendVertex(
	ODSYSDEF,
    OdDbPolyFaceMeshVertex* pVertex);
  // Gcad(Add)
#ifdef ODARXDEF
  OdResult appendVertex(OdDbPolyFaceMeshVertex*);
  OdResult appendVertex(OdDbObjectId& objId, OdDbPolyFaceMeshVertex*);
#endif
  /** Description:
    Appends the specified face record onto this PolyFaceMesh entity.

    Arguments:
    pFaceRecord (I) Pointer to the face record to append.

    Remarks:
    Returns the Object ID of the newly appended face record.
  */
  OdDbObjectId appendFaceRecord(
	ODSYSDEF,
    OdDbFaceRecord* pFaceRecord);
  // Gcad(Add)
#ifdef ODARXDEF
  OdResult appendFaceRecord(OdDbFaceRecord*);
  OdResult appendFaceRecord(OdDbObjectId&, OdDbFaceRecord*);
#endif  
  /** Description:
    Opens the specified vertex or face record owned by this PolyFaceMesh entity.

    Arguments:
    subObjId (I) Object ID of vertex or face record to be opened.
    mode (I) Mode in which the object is being opened.
    openErasedOne (I) If and only if true, *erased* objects will be opened.
    Remarks:
    Returns a SmartPointer to the opened object if successful, otherwise a null SmartPointer.
  */
  OdDbPolyFaceMeshVertexPtr openVertex(
    OdDbObjectId subObjId, 
    OdDb::OpenMode mode, 
    bool openErasedOne = false);
  // Gcad(Add)
  OdResult openVertex(OdDbVertex*&, OdDbObjectId subObjId,
                     OdDb::OpenMode,
                     bool openErasedOne = false);
  /** Description:
    Opens the OdDbSequenceEnd entity for this PolyfaceMesh entity.

    Arguments:
    mode (I) Mode in which to open the OdDbSequenceEnd entity.

    Remarks:
    Returns a SmartPointer to the newly opened OdDbSequenceEnd, or a null SmartPointer.

    Note:
    This method is provided solely for applications that store XData on
    OdDbSequenceEnd entities; this is not recommended. 
  */
  OdDbSequenceEndPtr openSequenceEnd(
    OdDb::OpenMode mode);
  // Gcad(Add)
  OdResult openSequenceEnd(OdDbSequenceEnd*&, OdDb::OpenMode);
  /** Description:
    Returns a SmartPointer to an iterator that can be used to traverse the vertices and face records owned 
    by this PolyFaceMesh entity.
  */
  // Gcad(Internal)
  OdDbObjectIteratorPtr vertexIterator(ODSYSDEF) const;
  // Gcad(Add)
#ifdef ODARXDEF
  OdDbObjectIterator*  vertexIterator() const;
#endif

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  
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

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  virtual OdBool isPlanar() const;
  
  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

  /** Remarks:
    Creates and returns a set of OdDbFace entities.
  */
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  /** Remarks:
    Creates and returns a set of OdDbFace entities.
  */
  virtual OdResult explodeGeometry(OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  private:
  OdResult checkMark(OdUInt32 index, OdDb::SubentType type, OdDbObjectIteratorPtr pVi) const;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPolyFaceMesh object pointers.
*/
typedef OdSmartPtr<OdDbPolyFaceMesh> OdDbPolyFaceMeshPtr;

#include "TD_PackPop.h"

#endif
