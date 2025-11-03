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




#ifndef _OD_DB_POLYGON_MESH_
#define _OD_DB_POLYGON_MESH_

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbObjectIterator.h"
#include "DbPolygonMeshVertex.h"

class OdDbSequenceEnd;
typedef OdSmartPtr<OdDbPolygonMeshVertex> OdDbPolygonMeshVertexPtr;
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

/** Description: 
  
    {group:TD_Namespaces}
*/

/** Description:
    This class represents PolygonMesh entities in an OdDbDatabase instance.

    Library:
    TD_Db

    Remarks:
    A PolygonMesh entity consists of a list of PolygonMeshVertex (coordinate) vertices
    describing a M ?N array of vertices, defining a set of 3D faces.   
    
    M is the number vertices in a row, N is the number of vertices in a column.
    The first N vertices define the first column, the second N, the second column, etc.

    The mesh may be closed in the M and/or N directions. A closed mesh is connected from the last row
    or column to the first.

    Note:
    Never derive from ths class.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPolygonMesh : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPolygonMesh);

  OdDbPolygonMesh();
  
  OdDbPolygonMesh(OdDb::PolyMeshType pType,
				  OdInt16       mSize,
				  OdInt16       nSize,
				  const			OdGePoint3dArray& vertices,
				  OdBool		mClosed = kTrue,
				  OdBool		nClosed = kTrue);
  ~OdDbPolygonMesh();
	
  /** Description:
    Returns the mesh type of this PolygonMesh entity (DXF 75).
    
    Remarks:
    polyMeshType() returns one of the following:
      
    @table
    Name                       Value    Description
    OdDb::kSimpleMesh          0        Simple Mesh
    OdDb::kQuadSurfaceMesh     5        Quadratic B-spline fitting
    OdDb::kCubicSurfaceMesh    6        Cubic B-spline fitting
    OdDb::kBezierSurfaceMesh   8        Bezier Surface fitting
  */
  OdDb::PolyMeshType polyMeshType() const;

  /** Description:
    Sets the mesh type of this PolygonMesh entity (DXF 75).

    Arguments:
    polyMeshType (I) PolygonMesh type.
    
    Remarks:
    polyMeshType must be one of the following:
      
    @table
    Name                      Value    Description
    OdDb::kSimpleMesh          0        Simple Mesh
    OdDb::kQuadSurfaceMesh     5        Quadratic B-spline fitting
    OdDb::kCubicSurfaceMesh    6        Cubic B-spline fitting
    OdDb::kBezierSurfaceMesh   8        Bezier Surface fitting
  */
  OdResult setPolyMeshType(
    OdDb::PolyMeshType polyMeshType);

  /** Description:
    Uses surfaceFit() to convert mesh type of this PolygonMesh entity (DXF 75).

    Arguments:
    polyMeshType (I) PolygonMesh type.
    
    Remarks:
    polyMeshType must be one of the following:
      
    @table
    Name                      Value    Description
    OdDb::kSimpleMesh          0        Simple Mesh
    OdDb::kQuadSurfaceMesh     5        Quadratic B-spline fitting
    OdDb::kCubicSurfaceMesh    6        Cubic B-spline fitting
    OdDb::kBezierSurfaceMesh   8        Bezier Surface fitting
  */
  OdResult convertToPolyMeshType(
    OdDb::PolyMeshType polyMeshType);
  
  /** Description:
    Returns the number of vertices in the M direction for this PolygonMesh entity (DXF 71).
  */
  OdInt16 mSize() const;

  /** Description:
    Sets the number of vertices in the M direction for this PolygonMesh entity (DXF 71).
    Arguments:
    mSize (I) Number of vertices in M direction.  
  */
  OdResult setMSize(
    OdInt16 mSize);
  
  /** Description:
    Returns the number of vertices in the N direction for this PolygonMesh entity (DXF 72).
  */
  OdInt16 nSize() const;

  /** Description:
    Sets the number of vertices in the N direction for this PolygonMesh entity (DXF 72).
    Arguments:
    nSize (I) Number of vertices in N direction.  
  */
  OdResult setNSize(OdInt16 nSize);
  
  /** Description:
    Returns true if and only if this PolygonMesh entity is closed in the M direction (DXF 70, bit 0x01).
  */
  OdBool isMClosed() const;

  /** Description:
    Sets this PolygonMesh entity closed in the M direction (DXF 70, bit 0x01).
  */
  OdResult makeMClosed();

  /** Description:
    Sets this PolygonMesh entity opened in the M direction (DXF 70, bit 0x01).
  */
  OdResult makeMOpen();
  
  /** Description:
    Returns true if and only if this PolygonMesh entity is closed in the N direction (DXF 70, bit 0x20).
  */
  OdBool isNClosed() const;

  /** Description:
    Sets this PolygonMesh entity closed in the N direction (DXF 70, bit 0x20).
  */
  OdResult makeNClosed();

  /** Description:
    Sets this PolygonMesh entity opened in the N direction (DXF 70, bit 0x20).
  */
  OdResult makeNOpen();
  
  /** Description:
    Returns the M surface density for this PolygonMesh entity (DXF 73).
    
    Remarks:
    This is the number of vertices in the M direction after a surfaceFit.
     
    Used instead of M if polyMeshType() != OdDb::kSimpleMesh.
  */
  OdInt16 mSurfaceDensity() const;

  /** Description:
    Sets the M surface density for this PolygonMesh entity (DXF 73).
    Arguments:
    mSurfaceDensity (I) M surface density. 
      
    Remarks:
    This is the number of vertices in the M direction after a surfaceFit.
    
    Used instead of M if polyMeshType() != OdDb::kSimpleMesh.
  */
  OdResult setMSurfaceDensity(
    OdInt16 mSurfaceDensity);
  
  /** Description:
    Returns the N surface density for this PolygonMesh entity (DXF 74).
    
    Remarks:
    This is the number of vertices in the N direction after a surfaceFit. 
    
    Used instead of N if polyMeshType() != OdDb::kSimpleMesh.
  */
  OdInt16 nSurfaceDensity() const;

  /** Description:
    Sets the M surface density for this PolygonMesh entity (DXF 74).
    Arguments:
    nSurfaceDensity (I) N surface density. 
      
    Remarks:
    This is the number of vertices in the N direction after a surfaceFit.
    
    Used instead of N if polyMeshType() != OdDb::kSimpleMesh.
  */
  OdResult setNSurfaceDensity(
    OdInt16 nSurfaceDensity);
  
  /** Description:
    Removes all the surface fit vertices for this PolygonMesh entity.
  */
  OdResult straighten();

  /** Description:
    Surface fits a smooth surface to this PolygonMesh entity.
  */
  OdResult surfaceFit();

  /** Arguments:
    surfType (I) Surface type (overrides SURFTYPE system variable).
    surfU (I) M Surface density (overrides SURFU system variable).
    surfV (I) N Surface density (overrides SURFV system variable.
    Remarks:
    surfU and surfV will be in the range [2..200].

    Remarks:
    surfType must be one of the following:
      
    @table
    Name                       Value    Description
    OdDb::kQuadSurfaceMesh     5        Quadratic B-spline fitting
    OdDb::kCubicSurfaceMesh    6        Cubic B-spline fitting
    OdDb::kBezierSurfaceMesh   8        Bezier Surface fitting
  */
  OdResult surfaceFit(
    OdDb::PolyMeshType surfType, 
    OdInt16 surfU, 
    OdInt16 surfV);
  
   /** Description:
    Appends the specified vertex onto this PolygonMesh entity.

    Arguments:
    pVertex (I) Pointer to the vertex to append.
    vType (I) Vertex type.
    
    Remarks:
    Returns the Object ID of the appended vertex.
    
    vType must be one of the following:
    
    @table
    Name                     Value   DXF 70   Description
    OdDb::k3dSimpleVertex    0       0x40     Standard vertex.
    OdDb::k3dControlVertex   1       0x10     Spline-fit or curve-fit control point.
    OdDb::k3dFitVertex       2       0x08     Spline-fit or curve-fit generated vertex.
  */
  OdDbObjectId appendVertex(
	ODSYSDEF,
    OdDbPolygonMeshVertex* pVertex, 
    OdDb::Vertex3dType vType = OdDb::k3dSimpleVertex);
  // Gcad(Add)
#ifdef ODARXDEF
   OdResult appendVertex(OdDbPolygonMeshVertex*);
   OdResult appendVertex(OdDbObjectId& objId, OdDbPolygonMeshVertex*);
#endif
  /** Description:
    Opens a vertex owned by this PolygonMesh entity.

    Arguments:
    vertId (I) Object ID of vertex to be opened.
    mode (I) Mode in which to open the vertex.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns a SmartPointer to the opened object if successful, otherwise a null SmartPointer.
  */
  OdDbPolygonMeshVertexPtr openVertex(
    OdDbObjectId vertId, 
    OdDb::OpenMode mode, 
    bool openErasedOne = false);
  // GreatStr(Add)
   OdResult openVertex(OdDbPolygonMeshVertex*&, OdDbObjectId vertId,
                                 OdDb::OpenMode,
                                 bool openErasedOne = false);
  /** Description:
    Opens the OdDbSequenceEnd entity for this PolygonMesh entity.

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
    Returns an Iterator that can be used to traverse the vertices owned 
    by this PolygonMesh entity.
  */
  // Gcad(Internal)
  OdDbObjectIteratorPtr vertexIterator(ODSYSDEF) const;
  // Gcad(Add)
#ifdef ODARXDEF
  OdDbObjectIterator*  vertexIterator() const;
#endif

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

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdBool isPlanar() const;
  
  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

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

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;
  private:
  OdResult checkMarker(OdUInt32 index, OdDb::SubentType type) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbPolygonMesh object pointers.
*/
typedef OdSmartPtr<OdDbPolygonMesh> OdDbPolygonMeshPtr;

#include "TD_PackPop.h"

#endif
