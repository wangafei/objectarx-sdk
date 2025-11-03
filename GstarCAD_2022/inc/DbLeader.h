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




#ifndef OD_DBLEOD_H
#define OD_DBLEOD_H 1

#include "TD_PackPush.h"

#include "DbCurve.h"
#include "DbDimStyleTableRecord.h"

/** Description:
    This class represents Leader entities in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLeader : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLeader);

  OdDbLeader();
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbLeader();

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  virtual OdGeVector3d normal() const;
  
  /** Description:
    Returns the number of vertices in this Leader entity (DXF 76).
 */
  virtual int numVertices() const;

  /** Description:
    Appends the specified WCS *vertex* to this Leader entity.
     
    Arguments:
    vertex (I) Vertex to append.
       
    Remarks:
    Returns true if and only if the *vertex* was appended.

    The specified *vertex* is projected onto the plane of this Leader, parallel to its *normal*.

    Note:
    If the specified *vertex* is inside a 2e-10 cube surrounding the
    previous *vertex*, it will not be appended.
  */
  virtual OdBool appendVertex(
    const OdGePoint3d& vertex);

  /** Description:
    Removes the last *vertex* of this Leader entity.
  */
  virtual void removeLastVertex();

  /** Description:
    Returns the WCS first *vertex* of this Leader entity.
  */
  virtual OdGePoint3d firstVertex() const;

  /** Description:
    Returns the WCS last *vertex* of this Leader entity.
  */
  virtual OdGePoint3d lastVertex() const;

  /** Description:
    Returns the specified WCS *vertex* of this Leader entity.
    Arguments:
    vertexIndex (I) Vertex *index*.
  */
  virtual OdGePoint3d vertexAt(
    int vertexIndex) const;

  /** Description:
    Sets the specified WCS *vertex* of this Leader entity.

    Arguments:
    vertexIndex (I) Vertex *index*.
    vertex (I) WCS value for the *vertex*.

    Remarks:
    Returns true if and only if the *vertex* was set.
  */
  virtual OdBool setVertexAt(
    int vertexIndex, 
    const OdGePoint3d& vertex);
  
  /** Description:
    Returns true if and only if this Leader entity has an arrowhead (DXF 71).
  */
  bool isArrowHeadEnabled() const;

  /** Description:
  Returns true if arrowhead is currently enabled for this leader:
  1. Arrow head is enabled (isArrowHeadEnabled() returns true).
  2. DIMASZ (arrow size) is non-zero
  3. First leader's segment length is greater or equal to (DIMASZ * DIMSCALE * 2).
  */
  virtual OdBool hasArrowHead() const;

  /** Description:
    Enables the arrowhead for this Leader entity (DXF 71).
  */
  virtual void enableArrowHead();

  /** Description:
    Disables the arrowhead for this Leader entity (DXF 71).
  */
  virtual void disableArrowHead();

  /** Description:
    Returns true if and only if this Leader entity has a hookline (DXF 75).
  */
  virtual OdBool hasHookLine() const;

  /** Description:
    Returns true if the hookline is codirectional with the
    OCS X-axis of this Leader entity, or false if it is antidirectional with it.
  */
  virtual bool isHookLineOnXDir() const;

  /** Description:
    Sets this Leader entity to use a spline-fit leader line (DXF 72).
  */
  virtual void setToSplineLeader();

  /** Description:
    Sets this Leader to use a straight line segments (DXF 72).
  */
  virtual void setToStraightLeader();

  /** Description:
    Returns true if and only if this Leader entity uses a spline-fit leader line (DXF 72).
  */
  virtual OdBool isSplined() const;
  
  /** Description:
    Returns the dimension style (OdDbDimStyleTableRecord) used by this Leader entity (DXF 3).
  */
  virtual OdDbHardPointerId dimensionStyle() const;

  /** Description:
    Sets the dimension style (OdDbDimStyleTableRecord) to used by this Leader entity (DXF 3).
    
    Arguments:
    dimStyleId (I) Object ID of the dimension style.
  */
  virtual void setDimensionStyle(
    const OdDbHardPointerId& dimStyleId);
    
  /** Description:
    Sets the annotation entity of this Leader entity (DXF 340).
      
    Arguments:
    annoId (I) The Object ID of the annotation entity.
    xDir (I) WCS X-axis of the annotation entity.
    annotationWidth (I) Annotation entity width.
    annotationHeight (I) Annotation entity height.
    hookLineOnXDir (I) True to set hookline codirectional with the
                       OCS X-axis of this annotation entity, or false to set it antidirectional with it.
    
    Remarks:
    This Leader entity is appended to the persistent reactor list of the annotation entity.
    
    The annotation entity must be one of, or a subclass of one of, the following
    
    @table
    Name        Entity type          Description
    kMText      OdDbMText            MText 
    kFcf        OdDbFcf              Feature control frame (Tolerance)  
    kBlockRef   OdDbBlockReference   Block reference

    Other than annoId, the parameters are usually set with evaluateLeader().    

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult attachAnnotation(
    const OdDbObjectId& annoId);

  virtual OdResult attachAnnotation(
    OdDbObjectId annoId,
    OdGeVector3d xDir,
    double annotationWidth,
    double annotationHeight,
    bool hookLineOnXDir);

  /** Description:
    Removes this Leader entity from the persistent reactor list of its annotation entity,
    and sets the annotation Object ID to NULL.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult detachAnnotation();

  /** Description:
     Returns the annotation Object ID of the annotation entity associated with this Leader entity (DXF 340).
  */
  virtual OdDbObjectId annotationObjId() const;

  /** Description:
    Returns the OCS X-axis of the annotation entity associated with this Leader entity (DXF 211).
  */
  virtual OdGeVector3d annotationXDir() const;

  /** Description:
    Returns the annotation *offset* of this Leader entity (DXF 213).
    
    Remarks:
    The annotation *offset* determines the final leader endpoint of this Leader entity
    
    @table
    annoType()     Final Leader Endpoint
    kMText         annotationOffset() + OdDbMText::location() ?OdGeVector3d(dimgap(), 0, 0) 
    kFcf           annotationOffset() + OdDbFcf::location()   ?OdGeVector3d(dimgap(), 0, 0)
    kBlockRef      annotationOffset() + OdDbBlockReference::position()
    kNoAnno        lastVertex() 
    
    Note:
    dimgap() is subtracted if the annotation is to the right of the Leader entity (isHookLikeOnXDir() == true)
    and added if it is to the left.
  */
  virtual OdGeVector3d annotationOffset() const;

  /** Description:
    Sets the annotation *offset* of this leader (DXF 213).
    
    Arguments:
    offset (I) Annotation offset.

    Remarks:
    The annotation *offset* determines the final leader endpoint of this Leader entity
    
    @table
    annoType()     Final Leader Endpoint
    kMText         annotationOffset() + OdGeVector3d(?dimgap(), 0, 0) + OdDbMText::location()
    kFcf           annotationOffset() + OdGeVector3d(?dimgap(), 0, 0) + OdDbFcf::location()
    kBlockRef      annotationOffset() + OdDbBlockReference::position()
    kNoAnno        lastVertex() 
    
    Note:
    dimgap() is added if isHookLikeOnXDir() is true, subtracted if it is false.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setAnnotationOffset(
    const OdGeVector3d& offset);
  
  /** Description:
    The type of annotation used by a Leader entity. 
  */
  
  enum AnnoType
  { 
    kMText      = 0,   // OdDbMText
    kFcf        = 1,   // OdDbFcf
    kBlockRef   = 2,   // OdDbBlockReference.
    kNoAnno     = 3    // No annotation.
  };

  /** Description:
    Returns the annotation type associated with this Leader entity (DXF 73).

    Remarks:   
    annoType() returns one of the following:
    
    @table
    Name        Value    Entity type          Description
    kMText      0        OdDbMText            MText 
    kFcf        1        OdDbFcf              Feature control frame (Tolerance)  
    kBlockRef   2        OdDbBlockReference   Block reference
    kNoAnno     3        --                   No annotation
  */
  AnnoType annoType() const;

  /** Description:
      Returns the height of the annotation entity associated with this Leader entity (DXF 40).
  */
  double annoHeight() const;

  /** Description:
      Returns the width of the annotation entity associated with this Leader entity (DXF 41).
  */
  double annoWidth() const;
  
  /** Description: Returns the DIMASZ value of this object.  
    Remarks: 
    DIMASZ specifies the arrowhead size for dimensions. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual double dimasz() const;

  /** Description: Returns the DIMCLRD value of this object.  
    Remarks: 
    DIMCLRD specifies the *color* of dimension lines, leader lines, and arrowheads. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual OdCmColor dimclrd() const;

  /** Description: Returns the DIMGAP value of this object.  
    Remarks: 
    DIMGAP specifies the gap between dimension text and dimension lines.

    A negative value for DIMGAP draws a reference box round the dimension text.

    Text is placed inside a dimension line only if there will be two line segments
    each as long as abs(DIMGAP). 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual double dimgap() const;

  /** Description: Returns the DIMLWD value of this object.  
    Remarks: 
    DIMLWD specifies the lineweight for dimension lines. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual OdDb::LineWeight dimlwd() const;

  /** Description: Returns the DIMLDRBLK value of this object.  
    Remarks: 
    DIMLDRBLK specifies the arrowhead block at the ends of leader lines.

    A null value specifies the default arrowhead is to be used. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual OdDbObjectId dimldrblk() const;

  /** Description: Returns the DIMSAH value of this object.  
    Remarks: 
    DIMSAH controls the generation of separate arrowheads for dimension lines.

    @table
    Value    Arrowhead Blocks
    false    DIMBLK
    true     DIMBLK1 and DIMBLK2 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */
  virtual bool dimsah() const;

  /** Description: Returns the DIMSCALE value of this object.  
    Remarks: 
    DIMSCALE is an scale factor applied to all dimension variables that
    regulate sizes, offsets, and distances.

    DIMSCALE serves as an overall "volume control" for dimensions
    and leaders.

    @table
    Value        Description
    0.0          A "reasonable" value is computed for model space viewports.
    > 0.0        If set to the inverse of the plot scale, plotted dimensions will be at the sizes specified by the other dimension variables. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual double dimscale() const;

  /** Description: Returns the DIMTAD value of this object.  
    Remarks: 
    DIMTAD specifies the dimension text vertical position.

    @table
    Value        Description
    0            Centered about the dimension line.
    1            Above the dimension line, unless DIMTIH==1 and the dimension line is not horizontal.
    2            Side of the dimension line farthest from the defining points.
    3            JIS standard. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual int dimtad() const;

  /** Description: Returns the DIMTXSTY value of this object.  
    Remarks: 
    DIMTXSTY specifies the text style of the dimension text. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual OdDbObjectId dimtxsty() const;

  /** Description: Returns the DIMTXT value of this object.  
    Remarks: 
    DIMTXT specifies the size of the dimension text. 
    
    Remarks: 
    The value from the dimension style of this object will be returned unless 
    that value has been overridden, in which case, the override value will be returned. 
    
  */ 
  virtual double dimtxt() const;
  
  /** Description: Sets the DIMASZ override for this object. 
    Arguments: val (I) New value for DIMASZ.   
    Remarks: 
    DIMASZ specifies the arrowhead size for dimensions. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimasz(
    double val);

  /** Description: Sets the DIMCLRD override for this object. 
    Arguments: val (I) New value for DIMCLRD.   
    Remarks: 
    DIMCLRD specifies the *color* of dimension lines, leader lines, and arrowheads. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimclrd(
    OdCmColor& val);

  /** Description: Sets the DIMGAP override for this object. 
    Arguments: val (I) New value for DIMGAP.   
    Remarks: 
    DIMGAP specifies the gap between dimension text and dimension lines.

    A negative value for DIMGAP draws a reference box round the dimension text.

    Text is placed inside a dimension line only if there will be two line segments
    each as long as abs(DIMGAP). 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimgap(
    double val);

  /** Description: Sets the DIMLDRBLK override for this object. 
    Arguments: val (I) New value for DIMLDRBLK.   
    Remarks: 
    DIMLDRBLK specifies the arrowhead block at the ends of leader lines.

    A null value specifies the default arrowhead is to be used. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimldrblk(
    OdDbObjectId val);
  virtual OdResult setDimldrblk(
    const OdChar * val);

  /** Description: Sets the DIMLWD override for this object. 
    Arguments: val (I) New value for DIMLWD.   
    Remarks: 
    DIMLWD specifies the lineweight for dimension lines. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimlwd(
    OdDb::LineWeight val); 

  /** Description: Sets the DIMSAH override for this object. 
    Arguments: val (I) New value for DIMSAH.   
    Remarks: 
    DIMSAH controls the generation of separate arrowheads for dimension lines.

    @table
    Value    Arrowhead Blocks
    false    DIMBLK
    true     DIMBLK1 and DIMBLK2 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimsah(
    bool val);

  /** Description: Sets the DIMSCALE override for this object. 
    Arguments: val (I) New value for DIMSCALE.   
    Remarks: 
    DIMSCALE is an scale factor applied to all dimension variables that
    regulate sizes, offsets, and distances.

    DIMSCALE serves as an overall "volume control" for dimensions
    and leaders.

    @table
    Value        Description
    0.0          A "reasonable" value is computed for model space viewports.
    > 0.0        If set to the inverse of the plot scale, plotted dimensions will be at the sizes specified by the other dimension variables. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimscale(
    double val);

  /** Description: Sets the DIMTAD override for this object. 
    Arguments: val (I) New value for DIMTAD.  [0..3] 
    Remarks: 
    DIMTAD specifies the dimension text vertical position.

    @table
    Value        Description
    0            Centered about the dimension line.
    1            Above the dimension line, unless DIMTIH==1 and the dimension line is not horizontal.
    2            Side of the dimension line farthest from the defining points.
    3            JIS standard. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimtad(
    int val);

  /** Description: Sets the DIMTXSTY override for this object. 
    Arguments: val (I) New value for DIMTXSTY.   
    Remarks: 
    DIMTXSTY specifies the text style of the dimension text. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimtxsty(
    OdDbObjectId val);

  /** Description: Sets the DIMTXT override for this object. 
    Arguments: val (I) New value for DIMTXT.   
    Remarks: 
    DIMTXT specifies size of the dimension text. 

	Gcad(Modify):returns:void->OdResult
  */ 
  virtual OdResult setDimtxt(
    double val);
    
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
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

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd) ODRX_OVERRIDE;

  ODRX_SEALED_VIRTUAL void subViewportDraw(
    OdGiViewportDraw* pVd) ODRX_OVERRIDE;

  virtual OdResult subExplode(
  OdDbVoidPtrArray& entitySet) const ODRX_OVERRIDE; 

  virtual OdResult subClose() ODRX_OVERRIDE;

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits) ODRX_OVERRIDE;
 
  virtual OdBool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual OdBool isClosed() const;

  virtual OdBool isPeriodic() const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam (
  double& endParam) const;

  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const ODRX_OVERRIDE;

  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const ODRX_OVERRIDE;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdBool subCloneMeForDragging();

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xform,
    OdDbEntity*& pEnt) const ODRX_OVERRIDE;

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  virtual OdResult getArea(
    double& area) const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPnt, 
    OdGePoint3d& pointOnCurve, 
    OdBool extend = kFalse
    ) const;

  /** Note:
     This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
     the dimension style of this entity to the current style for the specified *database*.
  */
  void subSetDatabaseDefaults(OdDbDatabase *pDb);
  
  /** Description:
    Updates this the geometry of this leader per its relationship to its
    annotation entity.
  */
  virtual OdResult evaluateLeader();

  
  /** Note:
    Support for persistent reactor to annotation entity.

    Gcad(Modify): OdDbEntity
  */
  virtual void modifiedGraphics(
    const OdDbEntity* pEntity/*const OdDbObject* pObject*/);
  
  //Gcad(Add)
  virtual void modified (const OdDbObject*);

  virtual void erased(
    const OdDbObject* pObject, 
    OdBool erasing = kTrue);

  /** Description:
    Copies the dimension style settings, including overrides, of this entity into the specified
    dimension style table record.
    
    Arguments:
    pRecord (O) Receives the effective dimension style data associated with entity.
    
    Remarks:
    The *copied* data includes the dimension style data with all applicable overrides. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult getDimstyleData(
    OdDbDimStyleTableRecord *pRecord) const;

  /** Description:
    Copies the dimension style settings, including overrides, from the specified
    dimension style table record to this entity.
    
    Arguments:
    pDimstyle (I) Pointer to a non- *database* -resident dimension style record.
    dimstyleID (I) Database-resident dimension style record.

    Remarks:
    The *copied* data includes the dimension style with all applicable overrides.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimstyleData(
    const OdDbDimStyleTableRecord* pDimstyle);
  OdResult setDimstyleData(
    OdDbObjectId dimstyleID);

  /** Description:
      Sets the plane to contain this Leader entity.

      Arguments:
      leaderPlane (I) Leader plane.
      
      Note: 
      Any associativity of this Leader entity will be broken.
  */
  virtual void setPlane(
    const OdGePlane& leaderPlane);

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

    enum gsMarkType {
    kArrowMark          = 3,
    kLeaderLineMark     = kArrowMark  + 1,
    kMTextUnderLineMark = 5000
  };

  /**
  Gcad(Add)
  */  
   virtual void goodbye(const OdDbObject*);
  /**
  Gcad(Add)
  */
   virtual void copied(const OdDbObject*, const OdDbObject*);
  
  /** Gcad(Add) 
  */
  virtual OdResult subIntersectWith(const OdDbEntity* pEnt,
							OdDb::Intersect intType, OdGePoint3dArray& points,
							OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
							const OdGePlane& projPlane, OdGePoint3dArray& points,
							OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  OdResult getOrthoProjectedCurve(const OdGePlane&, OdDbCurve*&) const;
  OdResult getProjectedCurve(const OdGePlane&, const OdGeVector3d& projDir, OdDbCurve*& projCrv) const;
  OdResult getOffsetCurves(double offsetDist, OdDbVoidPtrArray& offsetCurves) const;
  OdResult getSecondDeriv(const OdGePoint3d&, OdGeVector3d& secDeriv) const;
  OdResult getSplitCurves(const OdGeDoubleArray& params, OdDbVoidPtrArray& curveSegments) const;
  OdResult getSplitCurves(const OdGePoint3dArray& points, OdDbVoidPtrArray& curveSegments) const;
  OdResult extend(double);
  OdResult extend(OdBool, const OdGePoint3d&);

   // DEPRECATED METHODS!
   // These are supported but will be removed in future releases:
   //
   virtual void     setDimVars();

   // Returns the result of calling OdDbEntity::setColorIndex() for the object.
   virtual OdResult setColorIndex(OdUInt16, OdBool doSubents = true);
   //
   // end DEPRECATED METHODS!
};


inline OdResult OdDbLeader::getOrthoProjectedCurve(const OdGePlane&, OdDbCurve*&) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::getProjectedCurve(const OdGePlane&, const OdGeVector3d& projDir, OdDbCurve*& projCrv) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::getOffsetCurves(double offsetDist, OdDbVoidPtrArray& offsetCurves) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::getSecondDeriv(const OdGePoint3d&, OdGeVector3d& secDeriv) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::getSplitCurves(const OdGeDoubleArray& params, OdDbVoidPtrArray& curveSegments) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::getSplitCurves(const OdGePoint3dArray& points, OdDbVoidPtrArray& curveSegments) const
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::extend(double)
{
  return eNotApplicable;
}

inline OdResult OdDbLeader::extend(OdBool, const OdGePoint3d&)
{
  return eNotApplicable;
}

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLeader object pointers.
*/
typedef OdSmartPtr<OdDbLeader> OdDbLeaderPtr;

#include "TD_PackPop.h"

#endif

