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

#ifndef __ODGIGEOMETRYSIMPLIFIER_H__
#define __ODGIGEOMETRYSIMPLIFIER_H__

#include "../Gi/GiExport.h"
#include "../Gi/GiConveyorGeometry.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GePoint2dArray.h"
#include "../Ge/GePoint3dArray.h"
#include "../Gs/Gs.h"

class OdGiDeviation;
class OdGeLineSeg2d;
class OdGeCircArc3d;
class OdGeEllipArc3d;

#include "../TD_PackPush.h"

/** Description:
    This class provides tessellation functionality for the Teigha vectorization framework.
    
    Remarks:
    Tessellation consists of breaking complex entities into sets of simpler entities.  
    
    An instance of this class is used to simplify the geometry produced by the Teigha vectorization
    framework.

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiGeometrySimplifier : public OdGiConveyorGeometry
{
  // Old version do not override !!!
  // Overide shellFaceOut() or triangleOut() instead
  virtual int polygonWithHolesOut(OdUInt32, const OdGePoint3d*, OdUInt32 , OdUInt32*);
protected:
  /** Description:
    Draws an arc of the specified type.
    Arguments:
    arcType (I) Arc type.
    center (I) Center of arc.
    points (O) Receives an array of *points* comprising the arc.
    pNormal (I) Pointer to the normal to the arc.
    pExtrusion (I) Pointer to the extrusion direction of the arc.
  */
  void drawTypedArc(OdGiArcType arcType, const OdGePoint3d& center,
    OdGePoint3dArray& points, const OdGeVector3d* pNormal, const OdGeVector3d* pExtrusion);
private:
  virtual bool setFaceTraits(const OdGiFaceData* pFaceData, int faceIndex);
  virtual bool setEdgeTraits(const OdGiEdgeData* pEdgeData, int edgeIndex);

protected:
  OdGiConveyorContext*  m_pDrawCtx;
  OdGiSubEntityTraits*  m_pTraits;
  OdGsMarker            m_baseSubEntMarker;
protected:


  enum SimplifierFlags
  {
    kSimplProcessingText   = (1 << 0), // True if simplifier is inside TrueType text processing.
    kSimplFillModeDisabled = (1 << 1), // True if shell/mesh primitives must be filled during vectorization.
    kSimplEyeSpaceSilhs    = (1 << 2), // Enables silhouettes processing in ECS (Eye Space).
    kSimplLastFlag         = kSimplEyeSpaceSilhs
  };
  OdUInt32              m_simplFlags;

  OdGeLineSeg2d *m_pLineSeg2d;
  OdGeLineSeg2d &tmpLineSeg2d();
  OdGeCircArc3d *m_pCircArc3d;
  OdGeCircArc3d &tmpCircArc3d();
  OdGeEllipArc3d *m_pEllipArc3d;
  OdGeEllipArc3d &tmpEllipArc3d();

  OdInt32               m_nVertexCount;
  const OdGePoint3d*    m_pVertexList;
  const OdGiVertexData* m_pVertexData;
  OdGePoint2dArray      m_loopsPnts;
  OdGePoint3dArray      m_points3d;
  OdGePoint3dArray      m_thinLineSegPts;
protected:
  const OdGiDeviation*  m_pDeviation;
  OdGeDoubleArray       m_deviations;
  OdGsView::RenderMode  m_renderMode;

  /** Description:
    Returns the recommended maximum deviation of the current vectorization 
    for the specified *point* on the curve or surface being tesselated.
    Arguments:
    deviationType (I) Deviation type.
    pointOnCurve (I) Point on the curve.
  */
  double deviation(const OdGiDeviationType deviationType, const OdGePoint3d& pointOnCurve) const;

  /** Description:
    Returns the FillMode and DrawEdges for this Vectorizer object.
    Arguments:
    drawEdges (O) Receives the DrawEdges value.
    Note:
    As implemented, this function returns false if called without arguments:
  */
  bool fillMode();
  bool fillMode(bool& drawEdges);
  bool fillMode(bool& drawEdges, bool& secColor);
  bool circleArcFillMode();
  bool shmFillMode(bool& drawEdges);
  bool shmFillMode(bool& drawEdges, bool& secColor);
  /** Description:
    Returns true if and only if this Vectorizer object is processing text.
  */
  bool processingText() const { return GETBIT(m_simplFlags, kSimplProcessingText); }

  /** \details
    Returns true if silhouettes processing in ECS (Eye Coordinates Space) enabled.
  */
  bool silhouettesProcessingInEyeSpace() const { return GETBIT(m_simplFlags, kSimplEyeSpaceSilhs); }
  /** \details
    Enables processing silhouettes in ECS (Eye Coordinates Space).
  */
  void enableSilhouettesProcessingInEyeSpace(bool bEnable) { SETBIT(m_simplFlags, kSimplEyeSpaceSilhs, bEnable); }

  /** \details
    Returns the OdGiContext for this Vectorizer object.
  */
  OdGiContext& giCtx() const { return const_cast<OdGiContext&>(m_pDrawCtx->giContext()); }

public:
  OdGiGeometrySimplifier();
  ~OdGiGeometrySimplifier();

  /** Description:
      Specifies the maximum deviation allowed during the 
      tessellation process.  
      Remarks:
      This value sets the limit for the maximum difference 
      between the actual curve or surface, and the tessellated curve or surface.

      Arguments:
      deviations (I) Array of *deviation* values.
      Remarks:
      The *deviation* values (in isotropic world space) are  
      the *deviation* types defined by the OdGiDeviationType enum.

      Each OdGiDeviationType value is used as an index into this array.
  */
  void setDeviation(const OdGeDoubleArray& deviations);

  /** Arguments:
      pDeviation (I) Deviation to be used for anisotropic space (perspective view).
  */
  void setDeviation(const OdGiDeviation* pDeviation);

  /** Description
    Returns the render mode for this object.
       
    Remarks:
    renderMode() returns one of the following:
    
    @table
    Name                            Value      Description
    kBoundingBox                    -1         Bounding box. For internal use only.
    k2DOptimized                    0          Standard *display*. Optimized for 2D.
    kWireframe                      1          Standard *display*. Uses 3D pipeline.
    kHiddenLine                     2          Wireframe *display*. Hidden lines removed.
    kFlatShaded                     3          Faceted *display*. One *color* per face.
    kGouraudShaded                  4          Smooth shaded *display*. Colors interpolated between *vertices*.
    kFlatShadedWithWireframe        5          Faceted *display* with wireframe overlay.
    kGouraudShadedWithWireframe     6          Smooth shaded *display* with wireframe overlay.
  */
  OdGsView::RenderMode renderMode() { return m_renderMode; }

  /* Description:
     Sets the OdGiConveyorContext for this object.  
     Arguments:
     pDrawCtx (I) Pointer to the draw context.
     Note:
     The draw context must be set before 
     calling any of the tessellation functions.
  */
  void setDrawContext(OdGiConveyorContext* pDrawCtx);

  /** Description: 
    Returns the OdGiConveyorContext associated with this Vectorizer object.
  */
  OdGiConveyorContext* drawContext( ) { return m_pDrawCtx; }
  const OdGiConveyorContext* drawContext( ) const { return m_pDrawCtx; }

  /** Description:
    Passes *polyline* data to this Vectorizer object.
    Note:
    This function is called by the OdGiGeometrySimplifier class to 
    pass *polyline* data generated during tessellation, to a client application.

    Client applications have the option of overriding this function to process 
    the data themselves.  If the function is not overridden, 
    the default implementation of this function calls polylineOut with the vertex list.

    Arguments:
    numPoints (I) Number of points in the *polyline*.
    vertexList (I) Array of *vertices* that make up the *polyline*.
  */
  virtual void polylineOut(OdInt32 numPoints, const OdGePoint3d* vertexList);

  /** Description:
      Passes *polygon* data to this Vectorizer object.
      Note:
      This function is called by the OdGiGeometrySimplifier class to 
      pass *polygon* data generated during tessellation, to a client application.
      Clients should override this function.

      Arguments:
      numPoints (I) Number of points in the *polygon*.
      vertexList (I) Array of *vertices* that make up the *polygon*.
      pNormal (I) Normal vector for the *polygon*.
  */
  virtual void polygonOut(OdInt32 numPoints, 
    const OdGePoint3d* vertexList, 
    const OdGeVector3d* pNormal = 0);

  /** Description:
      Sets vertex data for tessilation of meshes and shells.
      Remarks:
      Called by the default implementations of meshProc and shellProc, to 
      set vertex data that will be used in the tessellation of these objects.

      Arguments:
      numVertices (I) Number of *vertices* in the *mesh* or *shell*.
      vertexList (I) Array of *vertices* that make up the *mesh* or *shell*.
      pVertexData (I) Pointer to additional vertex data. 
          
      See Also:
      OdGiVertexData, Vectorization Primatives
  */
  void setVertexData(OdInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGiVertexData* pVertexData = 0);

  /** Description:
      Returns the vertex count set in the most recent call to setVertexData.
  */
  OdInt32 vertexDataCount() const
  {
    return m_nVertexCount;
  }

  /** Description:
      Returns the vertex list set in the most recent call to setVertexData.
  */
  const OdGePoint3d* vertexDataList() const
  {
    return m_pVertexList;
  }

  /** Description:
      Returns the vertex attribute data set in the most recent call to setVertexData.
  */
  const OdGiVertexData* vertexData() const
  {
    return m_pVertexData;
  }

  /** Description:
      Returns base subentity selection marker for polylineOut().
  */
  OdGsMarker baseSubEntMarker() const
  {
    return m_baseSubEntMarker;
  }

  /** Note:
      Client applications have the option of overriding this function to process the *polyline*
      data themselves.  If the function is not overridden, the default implementation of 
      this function processes the *polyline*, taking into account the following:

        o The pXfm transformation (if any) that must be applied to the *polyline*.
        o Extrusion of the *polyline* (if it has a non-zero thickness).
        o Creating the closing segment if the *polyline* is closed.
        o Start and end widths for each segment, or constant width, if applicable.
        o Arc segments (if bulge values are present).

      In the default implementation of this function, line segments with a non-zero width 
      will be converted into calls to shellProc, and segments with no width will generate
      calls to polylineProc.  Arc segments with non-zero width will be converted into 
      calls to polygonProc, and arc segments with no width will generate calls to 
      polylineProc.      

      OdGiGeometrySimplifier::plineProc is only called for polylines with a continuous
      linetype. 
  */
  virtual void plineProc(const OdGiPolyline& polyline,
    const OdGeMatrix3d* pXfm = 0,
    OdUInt32 fromIndex = 0,
    OdUInt32 numSegs = 0);

  /** Note:
      Client applications have the option of overriding this function to process the *polyline*
      data themselves.  If the function is not overridden, the default implementation
      of this function processes the *polyline*, calling polylineOut if the data is not 
      extruded, or meshProc if an extrusion value is present.

      OdGiGeometrySimplifier::polylineProc is only called for polylines with a continuous
      linetype. 
  */
  virtual void polylineProc(OdUInt32 numPoints, 
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0, 
    const OdGeVector3d* pExtrusion = 0,
    OdLongPtr baseSubEntMarker = -1);

  /** Note:
      Client applications have the option of overriding this function to process the *polygon*
      data themselves.  If the function is not overridden, the default implementation
      of this function processes the *polygon*, calling polygonOut if the data is not 
      extruded, or shellProc if an extrusion value is present.
  */
  virtual void polygonProc(OdInt32 numPoints, 
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0, 
    const OdGeVector3d* pExtrusion = 0);

  virtual void polyPointsProc(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1);
  virtual void lineSegsProc(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1);
  virtual void dashLineSegsProc(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1);
  virtual void dashLineSegsProc(const OdGeMultiDashLine3d* dlList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1);

  /** Note:
     This function should not be overridden by clients. 
  */
  virtual void xlineProc(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint);

  /** Note:
      This function should not be overridden by clients. 
  */
  virtual void rayProc(const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint);

  /** Note:
      Client applications have the option of overriding this function to process the *mesh*
      data themselves.  If the function is not overridden, the default implementation
      of this function processes the *mesh* into a set of facets.  More specifically,
      the default meshProc function calls setVertexData, and the calls either
      generateMeshFaces for filled facets, or generateMeshWires for a wireframe.
  */
  virtual void meshProc(OdInt32 numRows,
    OdInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0);

  /** Description:
    Tessellates a wireframe *mesh*.
    Note:
    This function is called from the default implementation of meshProc
    to tessellate a wireframe *mesh*. Vertex data needed for this function
    can be obtained by calling vertexDataList and vertexData.

    Client applications have the option of overriding this function to process the *mesh*
    data themselves.  If the function is not overridden, the default implementation
    of this function processes the *mesh* into a set of facets.  More specifically,
    the default generateMeshWires function processes *mesh* attributes, and calls
    polylineOut with the tessellated *mesh* data.

    Arguments:
    numRows (I) Number of rows in the *mesh*.
    numColumns (I) Number of columns in the *mesh*.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.

    See Also:
    OdGiEdgeData, OdGiFaceData
  */
  virtual void generateMeshWires(OdInt32 numRows, 
    OdInt32 numColumns,
    const OdGiEdgeData* pEdgeData,
    const OdGiFaceData* pFaceData);

  /** Description:
    Tessellates a filled *mesh*.
    Note:
    This function is called from the default implementation of meshProc
    to tessellate a filled *mesh*. Vertex data needed for this function
    can be obtained by calling vertexDataList and vertexData.

    Client applications have the option of overriding this function to process the *mesh*
    data themselves.  If the function is not overridden, the default implementation
    of this function processes the *mesh* into a set of facets.  More specifically,
    the default generateMeshFaces function processes *mesh* attributes, and calls
    triangleOut function with the tessellated *mesh* data.

    Arguments:
      numRows (I) Number of rows in the *mesh*.
      numColumns (I) Number of columns in the *mesh*.
      pFaceData (I) Pointer to additional face data.

    See Also:
      OdGiEdgeData, OdGiFaceData
  */
  virtual void generateMeshFaces(OdInt32 numRows, OdInt32 numColumns,
                                 const OdGiFaceData* pFaceData);

  /** Description:
    Outputs a face of a tessilated *mesh*.
    Arguments:
    faceList (I) Array of numbers that define the face.
    pNormal (I) Pointer to the normal to the face.
    See Also:
    Vectorization Primitives
  */
  virtual void meshFaceOut(const OdInt32* faceList, const OdGeVector3d* pNormal);

  /** Note:
      Client applications have the option of overriding this function to process the *shell*
      data themselves.  If the function is not overridden, the default implementation
      of this function processes the *shell* into a set of facets.  More specifically,
      the default shellProc function calls setVertexData, and the calls either
      generateShellFaces for filled facets, or generateShellWires for a wireframe.
  */
  virtual void shellProc(OdInt32 numVertices,
                 const OdGePoint3d* vertexList,
                 OdInt32 faceListSize,
                 const OdInt32* faceList,
                 const OdGiEdgeData* pEdgeData = 0,
                 const OdGiFaceData* pFaceData = 0,
                 const OdGiVertexData* pVertexData = 0);

  /** Description:
    Tessellates a wireframe *shell*
    Note:
    This function is called from the default implementation of shellProc
    to tessellate a wireframe *shell*. Vertex data needed for this function
    can be obtained by calling vertexDataList and vertexData.

    Client applications have the option of overriding this function to process the *shell*
    data themselves.  If the function is not overridden, the default implementation
    of this function processes the *shell* into a set of facets.  More specifically,
    the default generateShellWires function processes *shell* attributes, and calls
    polylineOut with the tessellated *shell* data.

    Arguments:
    faceListSize (I) Number of entries in faceList.
    faceList (I) List of numbers that define the faces in the *shell*.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.

    See Also:
    OdGiEdgeData, OdGiFaceData, Vectorization Primitives
  */
   virtual void generateShellWires(OdInt32 faceListSize,
                                   const OdInt32* faceList,
                                   const OdGiEdgeData* pEdgeData = 0,
                                   const OdGiFaceData* pFaceData = 0);

   virtual void generateShellSilhouette(OdInt32 faceListSize,
                                  const OdInt32* faceList,
                                  const OdGiEdgeData* pEdgeData = 0,
                                  const OdGiFaceData* pFaceData = 0);
  /** Description:
    Tessellates a filled wireframe *shell*.
    Note:
    This function is called from the default implementation of shellProc
    to tessellate a filled wireframe *shell*. Vertex data needed for this function
    can be obtained by calling vertexDataList and vertexData.

    Client applications have the option of overriding this function to process the *shell*
    data themselves.  If the function is not overridden, the default implementation
    of this function processes the *shell* into a set of facets.  More specifically,
    the default generateShellFaces function processes *shell* attributes, and calls
    shellFaceOut with the tessellated *shell* data.

    Arguments:
    faceListSize (I) Number of entries in faceList.
    faceList (I) List of numbers that define the faces in the *shell*.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.

    See Also:
    OdGiEdgeData, OdGiFaceData, Vectorization Primitives
  */
  virtual void generateShellFaces(OdInt32 faceListSize,
                                  const OdInt32* faceList,
                                  const OdGiEdgeData* pEdgeData = 0,
                                  const OdGiFaceData* pFaceData = 0);

  /** Description:
    Outputs the face of a tessilated *shell*.

    Note:
    This function is called from the default implementation of generateShellFaces,
    to process a single face in a *shell* along with the holes in that face.
    Vertex data needed for this function can be obtained by calling 
    vertexDataList and vertexData.

    Client applications have the option of overriding this function to process the face
    data themselves.  If the function is not overridden, the default implementation
    of this function processes the face information calls
    triangleOut with the resulting triangle data.

    Arguments:
    faceListSize (I) Number of entries in faceList.
    faceList (I) List of numbers that define the face.
    pNormal (I) Normal vector for this face.    
    See Also:
    Vectorization Primitives
    */
    virtual void shellFaceOut(OdInt32 faceListSize,
                        const OdInt32* faceList,
                        const OdGeVector3d* pNormal);

  /** Description:
    Output a triangle.
    Note:
    This function is called from the default implementations of shellFaceOut
    and generateMeshFaces.  Vertex data needed for this function
    can be obtained by calling vertexDataList and vertexData.
    
    Client applications have the option of overriding this function to process 
    the triangle data themselves.  If the function is not overridden, 
    the default implementation of this function processes the color 
    attributes for the triangle, and calls polygonOut.

    Arguments:
    vertices (I) List of 3 numbers that define the *vertices* in the triangle.
    pNormal (I) Normal vector for this triangle.

  */
  virtual void triangleOut(const OdInt32* vertices,
                           const OdGeVector3d* pNormal);

  /** Description:
    Tessilates a *shell*.
    Note
    This auxiliary function that can be used to tessilate a *shell* up into a set of faces, 
    each with a maximum number of edges.
    
    Vertex data needed for this function is obtained by calling 
    vertexDataList and vertexData (so the caller of this function is responsible for 
    setting this data).  Face data is passed to the facetOut function, which 
    can be overridden by client applications to capture the tessellated data.

    Arguments:
    faceListSize (I) Number of entries in faceList.
    faceList (I) List of numbers that define the faces in the *shell*.
    pFaceData (I) Pointer to additional face data.
    maxFacetSize (I) Maximum number of edges in the tessellated faces produced
      by this function.

    See Also:
    OdGiFaceData, Vectorization Primitives
  */
  virtual void generateShellFacets(OdInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiFaceData* pFaceData = 0,
    OdInt32 maxFacetSize = 3);

  /** Description:
    Outputs a facet.
    Note:
    This function is called from the default implementations of generateShellFacets.  
    Vertex data needed for this function is obtained by calling 
    vertexDataList and vertexData.

    Client applications have the option of overriding this function to process 
    the face data themselves.  If the function is not overridden, 
    the default implementation of this function calls polygonOut with the face data.

    Arguments:
    faceList (I) List of numbers that define the *vertices* in the facet.  
    edgeIndices (I) Currently not used.
    pNormal (I) Pointer to the normal vector for this face.
    See Also:
    Vectorization Primitives
  */
  virtual void facetOut(const OdInt32* faceList,
        const OdInt32* edgeIndices,
        const OdGeVector3d* pNormal);

  /** Note:
    Client applications have the option of overriding these function to process the circle
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in circle using the current kOdGiMaxDevForCircle deviation,
    and calls polylineProc with the resulting data.
  */
  virtual void circleProc(const OdGePoint3d& center,
    double radius, 
    const OdGeVector3d& normal,
    const OdGeVector3d* pExtrusion = 0);

  virtual void circleProc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint,
    const OdGeVector3d* pExtrusion = 0);

  /** Note:
    Client applications have the option of overriding this function to process the circular arc
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in circular arc using the current kOdGiMaxDevForCircle deviation,
    and calls polylineProc with the resulting data (for kOdGiArcSimple type arcs).  For 
    kOdGiArcSector and kOdGiArcChord arc types, polygonOut is called.
  */
  virtual void circularArcProc(const OdGePoint3d& center,
    double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    double sweepAngle,
    OdGiArcType arcType = kOdGiArcSimple,
    const OdGeVector3d* pExtrusion = 0);

  virtual void circularArcProc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    OdGiArcType arcType = kOdGiArcSimple,
    const OdGeVector3d* pExtrusion = 0);

  /** Note:
    Client applications have the option of overriding this function to process the text
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in text string, by calling the textProc function
    on the associated OdGiContext object.  TrueType text will result in calls to 
    shellProc, and SHX text will get sent to polylineProc and polygonProc.
  */
  virtual void textProc(const OdGePoint3d& position,
    const OdGeVector3d& u, 
    const OdGeVector3d& v,
    const OdChar* msg, 
    OdInt32 length, 
    bool raw,
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0);

  virtual void textProc2(const OdGePoint3d& position,
    const OdGeVector3d& u, const OdGeVector3d& v,
    const OdChar* msg, OdInt32 length, bool raw, const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0, const OdGeExtents3d* extentsBox = 0);

  virtual void ttfTextProc(const OdGePoint3d& position,
    const OdGeVector3d& u, const OdGeVector3d& v,
    const OdChar* pText, OdInt32 nLen,
    double height, double allWidth,
    const OdArray<double>& charWidths,
    const void* pLOGFONT);

  /** Note:
    Client applications have the option of overriding this function to process the shape
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in shape, by calling the shapeProc function
    on the associated OdGiContext object.  The resulting geometry 
    will get sent to polylineProc and polygonProc.
  */
  virtual void shapeProc(const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0);

  /** Note:
    Client applications have the option of overriding this function to process the NURBS
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in NURBS curve using the current kOdGiMaxDevForCurve deviation,
    and calls polylineProc with the resulting data.
  */
  virtual void nurbsProc(const OdGeNurbCurve3d& nurbsCurve, const OdGeVector3d* pNormal = 0);

  /** Note:
    Client applications have the option of overriding this function to process the elliptical arc
    data themselves.  If the function is not overridden, the default implementation
    tessellates the passed in elliptical arc using the current kOdGiMaxDevForCurve deviation,
    and calls polylineProc with the resulting data.
  */
  virtual void ellipArcProc(
    const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple,
    const OdGeVector3d* pExtrusion = 0);

  /** Note:
      The default implementation of this function does nothing but return.
  */
  virtual void rasterImageProc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage, 
    const OdGePoint2d* uvBoundary, 
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0);

  /** Description:
    Initializes a texture map for this Vectorizer object.

    Arguments:
    origin (I) Lower-left corner. 
    u (I) Image width vector.
    v (I) Image height vector.
    pImage (I) Pointer to the RasterImage object.
    transparency (I) True if and only if *image* *transparency* is on.
    brightness (I) Image *brightness* [0.0 .. 100.0].
    contrast (I) Image *contrast* [0.0 .. 100.0].
    fade (I) Image *fade* value [0.0 .. 100.0].
  */
  virtual void initTexture(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage,
    bool transparency,
    double brightness,
    double contrast,
    double fade);

  /** Description:
    Releases a texture map for this Vectorizer object.
  */
  virtual void uninitTexture();

  /** Note:
      The default implementation of this function does nothing but return.
  */
  virtual void metafileProc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,        
    bool allowClipping = false); 

  /** \remarks
      Client applications have the option of overriding this function to process the polypoint
      data themselves. If the function is not overridden, the default implementation
      of this function processes the polypoint, calling polylineProc for each point.
  */
  virtual void polypointProc(OdInt32 numPoints,
    const OdGePoint3d* vertexList,
    const OdCmEntityColor* pColors,
    const OdCmTransparency* pTransparency = 0,
    const OdGeVector3d* pNormals = 0,
    const OdGeVector3d* pExtrusions = 0,
    const OdGsMarker* pSubEntMarkers = 0,
    OdInt32 nPointSize = 0);
   
  /** Note:
    This function is called by the OdGiGeometrySimplifier class to 
    pass *polyline* data generated during tessellation, to a client application.

    Client applications have the option of overriding this function to process 
    the data themselves.  If the function is not overridden, 
    the default implementation of this function calls polylineOut with the vertex list.

    Arguments:
    vertexIndexList (I) Array of vertex indices in vertexDataList().
  */
  virtual void polylineOut(OdInt32 numPoints, const OdInt32* vertexIndexList);

  /** Note:
      Utility function to be called from client implementation of meshProc()
      to unify mesh primitives processing. 
  */
  void convertMeshToShell(
    OdInt32 rows, OdInt32 columns,
    const OdGePoint3d* pVertexList,
    const OdGiEdgeData* pEdgeData,
    const OdGiFaceData* pFaceData,
    const OdGiVertexData* pVertexData);

  virtual int  selectState(){return 0;}
  virtual bool checkValidSelect(OdInt32,const OdGePoint3d*){return true;}
  virtual bool isSilhouettedisplay() const { return false; }
  virtual void beginSilhouettedisplay() {}
  virtual void endSilhouettedisplay() {}

  virtual int generateExtrusionData(const OdGeVector3d* pExtrusion);
};

/** Description:

    Library:
    TD_Gi 
    {group:OdGi_Classes} 
*/
struct ODGI_EXPORT OdGiFillData
{
  OdGiFillData(OdGiConveyorContext* pDrawCtx, OdGiSubEntityTraits* pTraits,
    OdDb::LineWeight lweight = OdDb::kLnWt000,
    OdGiFillType fillType = kOdGiFillNever);
  void set(OdDb::LineWeight lweight, OdGiFillType fillType, const OdGeVector3d* fillNormal);
  ~OdGiFillData();

  OdDb::LineWeight m_lweight;
  OdGiFillType m_fillType;
  OdGeVector3d m_fillNormal;
  OdGeVector3d* m_pFillNormal;
  OdGiSubEntityTraits* m_pTraits;
  OdGiConveyorContext* m_pDrawCtx;
};

/** Description:

    Library:
    TD_Gi 
    {group:OdGi_Classes} 
*/
class OdGiConveyorContextWrapper : public OdGiConveyorContext
{
protected:
  OdGiConveyorContext *m_pCtx;
public:
  OdGiConveyorContext *getOriginalContext() const { return m_pCtx; }
  void setOriginalContext(OdGiConveyorContext *pCtx) { m_pCtx = pCtx; }
  explicit OdGiConveyorContextWrapper(OdGiConveyorContext *pCtx = NULL) : m_pCtx(pCtx) { }

  OdGiContext& giContext() const { return m_pCtx->giContext(); }
  OdGiSubEntityTraits& subEntityTraits() const { return m_pCtx->subEntityTraits(); }
  const OdGiSubEntityTraitsData& effectiveTraits() const { return m_pCtx->effectiveTraits(); }
  void getEffectiveTraits(OdGiSubEntityTraitsData& eTraits) const { m_pCtx->getEffectiveTraits(eTraits); }
  void setEffectiveTraits(const OdGiSubEntityTraitsData& traits,
                          const OdGeVector3d* fillNormal = NULL) { m_pCtx->setEffectiveTraits(traits, fillNormal); }
  const OdGiDrawableDesc* currentDrawableDesc() const { return m_pCtx->currentDrawableDesc(); }
  const OdGiDrawable* currentDrawable() const { return m_pCtx->currentDrawable(); }
  const OdGiViewport* giViewport() const { return m_pCtx->giViewport(); }
  const OdGsView* gsView() const { return m_pCtx->gsView(); }
  void onTraitsModified() { m_pCtx->onTraitsModified(); }
  OdBool regenAbort() const { return m_pCtx->regenAbort(); }
  const OdGiPathNode* currentGiPath() const { return m_pCtx->currentGiPath(); }
  const OdGiDeviation& worldDeviation() const { return m_pCtx->worldDeviation(); }
  const OdGiDeviation& modelDeviation() const { return m_pCtx->modelDeviation(); }
  const OdGiDeviation& eyeDeviation() const { return m_pCtx->eyeDeviation(); }
  OdUInt32 drawContextFlags() const { return m_pCtx->drawContextFlags(); }
};

#include "../TD_PackPop.h"

#endif //#ifndef __ODGIGEOMETRYSIMPLIFIER_H__
