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




#ifndef OD_DBHATCH_H
#define OD_DBHATCH_H

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "Ge/GePoint2dArray.h"
#include "IntArray.h"
#include "Ge/GeVoidPointerArray.h"
#include "CmColorArray.h"
#include "HatchPattern.h"
#include "DbRegion.h"

#define HATCH_PATTERN_NAME_LENGTH 32


/** Description:
    This template class is a specialization of the OdArray class for OdGeCurve2d object pointers.
*/
typedef OdArray<OdGeCurve2d*> EdgeArray;


/** Description:
    This class represents Hatch entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    Note:
    
    Loops must be closed, simple, and continuous. 
    They must be self-intersecting itself only at their endpoints.
    Their start points and end points must coincide. 
    The outer loops must be appended before all of their inner loops.
    
    Teigha provides limited validation of the hatch boundary in order to maintain API efficiency
    and performance.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbHatch : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbHatch);

  OdDbHatch();
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual ~OdDbHatch();

  enum HatchLoopType
  {
    kDefault             = 0,        // Not yet specified.
    kExternal            = 1,        // Defined by external entities.
    kPolyline            = 2,        // Defined by OdGe polyline.
    kDerived             = 4,        // Derived from a picked point.
    kTextbox             = 8,        // Defined by text.
    kOutermost           = 0x10,     // Outermost loop.
    kNotClosed           = 0x20,     // Open loop.
    kSelfIntersecting    = 0x40,     // Self-intersecting loop.
    kTextIsland          = 0x80,     // Text loop surrounded by an even number of loops.
    kDuplicate           = 0x100,    // Duplicate loop.
    kIsAnnotative        = 0x200,    // The bounding area is an annotative block.
    kDoesNotSupportScale = 0x400,    // The bounding type does not support scaling
    kForceAnnoAllVisible = 0x800,    // Forces all annotatives to be visible
    kOrientToPaper       = 0x1000,   // Orients hatch loop to paper
    kIsAnnotativeBlock   = 0x2000    // Describes if the hatch is an annotative block.
  };

  enum HatchEdgeType
  {
    kLine     = 1,  // Linear.         
    kCirArc   = 2,  // Circular arc.
    kEllArc   = 3,  // Elliptical arc.
    kSpline   = 4   // Spline curve.
  };

  enum HatchPatternType
  {
    kUserDefined     = 0, // User-defined hatch.
    kPreDefined      = 1, // Defined in acad.pat and acadiso.pat. 
    kCustomDefined   = 2  // In its own PAT file.
  };

  enum HatchStyle
  {
    kNormal   = 0, // Hatch toggles on each boundary.
    kOuter    = 1, // Hatch turns off after first inner loop.
    kIgnore   = 2  // Hatch ignores inner loop
  };

  enum HatchObjectType 
  {
    kHatchObject      = 0, // Classic hatch
    kGradientObject   = 1  // Color gradient
  };

  enum GradientPatternType 
  {
    kPreDefinedGradient    = 0, // Predefined gradient pattern.
    kUserDefinedGradient   = 1  // User-defined gradient pattern.
  };

  /** Description:
    Returns the *elevation* of this entity in the OCS (DXF 30).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  double elevation() const;

  /** Description:
    Sets the *elevation* of this entity in the OCS (DXF 30).

    Arguments:
    elevation (I) Elevation.    

    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setElevation(
    double elevation);

   /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setNormal(
    const OdGeVector3d& normal);

  virtual OdBool isPlanar() const { return ::kTrue; }

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  /** Description:
    Returns the number of loops in this hatch (DXF 91).
  */
  int numLoops() const;

  /** Description:
    Returns the type of loop at the specified index (DXF 92). 
    
    Arguments:
    loopIndex (I) Loop index. 
    
    Remarks:
    The loop type consists of a combination of bits from the HatchLoopType enumeration.
  */
  OdInt32 loopTypeAt(
    int loopIndex) const;

   /** Description:
    Returns the specified loop from this Hatch entity.

    Arguments:
    loopIndex (I) Loop index.
    edgePtrs (O) Receives a set of OdGeCurve2d pointers to the edges that comprise this loop.
    vertices (O) Receives the *vertices* that comprise this loop.
    bulges (O) Receives a set of *bulges* corresponding to the *vertices* array.
    
    Remarks:
    Should be called with edgePtrs if the loop is not a polyline loop, and with
    *vertices* and *bulges* if it is.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getLoopAt(
    int loopIndex, 
    EdgeArray& edgePtrs) const;
  
  // Gcad(Modify):returns:void->OdResult
  OdResult getLoopAt(
    int loopIndex, 
    OdGePoint2dArray& vertices, 
    OdGeDoubleArray& bulges) const;

  // Gcad(Add):TODO
  OdResult getLoopAt(int loopIndex,
    OdInt32& loopType,
	OdGeVoidPointerArray& edgePtrs,
    OdIntArray&  edgeTypes) const;

  // Gcad(Add):
  OdResult getLoopAt(int loopIndex,
	OdInt32& loopType,
	OdGePoint2dArray& vertices,
	OdGeDoubleArray& bulges) const;
  
  
  /** Description:
    Appends a loop onto this Hatch entity.

    Arguments:
    loopType (I) Type of loop being appended.
    edgePtrs (I) Array OdGeCurve pointers to the edges that comprise this loop.
    vertices (I) The *vertices* that comprise this loop.
    bulges (I) The *bulges* corresponding to the *vertices* array.
    dbObjIds (I) Array of OdDbEntity Object IDs that comprise the loop.
    
    Remarks:
    
    loopType is one of the following:
    
    @table
    Name                Value     Description
    kDefault            0         Not yet specified.
    kExternal           1         Defined by external entities.
    kPolyline           2         Defined by OdGe polyline.
    kDerived            4         Derived from a picked point.
    kTextbox            8         Defined by text.
    kOutermost          0x10      Outermost loop.
    kNotClosed          0x20      Open loop.
    kSelfIntersecting   0x40      Self-intersecting loop.
    kTextIsland         0x80      Text loop surrounded by an even number of loops.
    kDuplicate          0x100     Duplicate loop.
    
    Note:
    edgePtrs may contain pointers to only the following objects:
    
    o  OdGeLineSeg2d
    o  OdGeCircArc2d
    o  OdGeEllipArc2d
    o  OdGeNurbCurve2d
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult appendLoop(
    OdInt32 loopType,
    const EdgeArray& edgePtrs);

  // Gcad(Modify):returns:void->OdResult
  OdResult appendLoop(
    OdInt32 loopType,
    const OdGePoint2dArray& vertices,
    const OdGeDoubleArray& bulges);

  // Gcad(Modify):returns:void->OdResult
  OdResult appendLoop(
    OdInt32 loopType, 
    const OdDbObjectIdArray& dbObjIds);

  // Gcad(Add)://TODO
   OdResult appendLoop(OdInt32 loopType,
     const OdGeVoidPointerArray& edgePtrs,
     const OdIntArray&  edgeTypes);

  /** Description:
    Inserts a loop into this Hatch entity.

    Arguments:
    loopIndex (I) Loop index.
    loopType (I) Type of loop being appended.
    edgePtrs (I) Array OdGeCurve pointers to the edges that comprise this loop.
    vertices (I) The *vertices* that comprise this loop.
    bulges (I) The *bulges* corresponding to the *vertices* array.
    dbObjIds (I) Array of OdDbEntity Object IDs that comprise the loop.

    Remarks:
    loopType is one of the following:
    
    @table
    Name                Value     Description.
    kDefault            0         Not yet specified.
    kExternal           1         Defined by external entities.
    kPolyline           2         Defined by OdGe polyline.
    kDerived            4         Derived from a picked point.
    kTextbox            8         Defined by text.
    kOutermost          0x10      Outermost loop.
    kNotClosed          0x20      Open loop.
    kSelfIntersecting   0x40      Self-intersecting loop.
    kTextIsland         0x80      Text loop surrounded by an even number of loops.
    kDuplicate          0x100     Duplicate loop.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult insertLoopAt(
    int loopIndex, 
    OdInt32 loopType,
    const EdgeArray& edgePtrs);

  // Gcad(Modify):returns:void->OdResult
  OdResult insertLoopAt(
    int loopIndex, 
    OdInt32 loopType,
    const OdGePoint2dArray& vertices,
    const OdGeDoubleArray& bulges);

  // Gcad(Modify):returns:void->OdResult
  OdResult insertLoopAt(
    int loopIndex, OdInt32 loopType,
    const OdDbObjectIdArray& dbObjIds);

   // Gcad(Add)://TODO
   OdResult insertLoopAt(int loopIndex,
      OdInt32 loopType,
      const OdGeVoidPointerArray& edgePtrs,
      const OdIntArray&  edgeTypes);

  /** Description:
    Removes the specified loop from this Hatch entity.

    Arguments:
    loopIndex (I) Loop index.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult removeLoopAt(
    int loopIndex);

  /** Description:
    Returns true if and only if this hatch is *associative* (DXF 71).
    Remarks:
    Associative hatch is automatically recalculated 
    when its boundaries are *modified*.
  */
  bool associative() const;

  /** Description:
    Controls the *associative* flag for this hatch (DXF 71).
    Arguments:    
    isAssociative (I) Controls the *associative* flag.

    Remarks:
    Associative hatch is automatically recalculated 
    when its boundaries are *modified*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setAssociative(
    bool isAssociative);

  /** Description:
    Returns the Object IDs comprising the specified *associative* loop in this Hatch entity.

    Arguments:
    loopIndex (I) Loop index.
    dbObjIds (O) Receives the boundary Object IDs.
    
    Remarks:
    Returns nothing if this Hatch entity is not *associative*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getAssocObjIdsAt(
    int loopIndex, 
    OdDbObjectIdArray& dbObjIds) const;

  /** Description:
    Returns the Object IDs comprising all the *associative* boundaries in this Hatch entity.

    Arguments:
    dbObjIds (O) Receives the boundary Object IDs.

    Remarks:
    Returns nothing if this Hatch entity is not *associative*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getAssocObjIds(
    OdDbObjectIdArray& dbObjIds) const;

  /** Description:
    Sets the Object IDs comprising the specified *associative* loop in this Hatch entity.

    Arguments:
    loopIndex (I) Loop *index*.
    dbObjIds (I) The set of boundary Object ID's that make up the specified loop.

    Remarks:
    Adds the Object ID of this hatch to the reactors of the boundary objects.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setAssocObjIdsAt(
    int loopIndex, 
    const OdDbObjectIdArray& dbObjIds);

  /** Description:
    Removes all Object IDs that are associated with this Hatch entity.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult removeAssocObjIds();

  /** Description:
    Returns the hatch pattern type for this Hatch entity (DXF 76).
    Remarks:
    
    patternType() returns one of the following:
    
    @table
    Name              Value
    kUserDefined      0
    kPreDefined       1
    kCustomDefined    2 
  */
  OdDbHatch::HatchPatternType patternType() const;

  /** Description:
    Returns true if and only if this hatch is solid fill (DXF 70).
  */
  bool isSolidFill() const;

  
  /** Description:
      Returns the name of the pattern for this Hatch entity (DXF 2).
  */
  // Gcad(Modify)
  const OdChar * patternName() const;

  /** Description:
    Sets the pattern data for this Hatch entity.
    
    Arguments:
    patType (I) Pattern type.
    patName (I) Pattern name.
    angle (I) Pattern *angle*.
    scale (I) Pattern *scale*.
    pat (I) Pattern definition (as in PAT file)
    basePt (I) Base point.
    
    Remarks:
    patType must be one of the following:
    
    @table
    Name              Value
    kUserDefined      0
    kPreDefined       1
    kCustomDefined    2
     
    patName is ignored for patType == kUserDefined; appearance is defined by setPatternAngle(),
    setPatternSpace() and setPatternDouble(). 
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPattern(
    OdDbHatch::HatchPatternType patType, 
    const OdChar* patName);

  // Gcad(Modify):returns:void->OdResult
  OdResult setPattern(
    OdDbHatch::HatchPatternType patType, 
    const OdString& patName,
    double angle, 
    double scale,
    const OdHatchPattern& pat,
    OdGePoint2d basePt = OdGePoint2d());

  /** Description:
    Returns the pattern *angle* for this Hatch entity (DXF 52).
    
    Note:
    All angles are expressed in radians.
  */
  double patternAngle() const;

  /** Description:
    Sets the pattern *angle* for this Hatch entity (DXF 52).

    Note:
    All angles are expressed in radians.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPatternAngle(
    double angle);

  /** Description:
    Returns the pattern spacing for this Hatch entity (DXF 41).
    
    Note:
    Pattern spacing is the distance between parallel lines for kUserDefined hatch.
  */
  double patternSpace() const;

  /** Description:
    Sets the pattern spacing for this Hatch entity (DXF 41).

    Arguments:
    space (I) Pattern spacing.
    
    Note:
    Pattern spacing is the distance between parallel lines for kUserDefined hatch.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPatternSpace(
    double space);

  /** Description:
    Returns the pattern scale for this Hatch entity (DXF 41).
  */
  double patternScale() const;

  /** Description:
    Sets the pattern scale for this Hatch entity (DXF 41).
    
    Arguments:
    scale (I) Pattern *scale*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPatternScale(
    double scale);

  /** Description:
    Returns the pattern double flag for this Hatch entity (DXF 77).
      
    Note:
    Setting the pattern double flag causes a second set of lines, at 90?to the first, for kUserDefined hatch.
  */
  bool patternDouble() const;

  /** Description:
    Sets the pattern double flag for this Hatch entity (DXF 77).

    Arguments:
    isDouble (I) Sets the pattern double flag if true, clears it otherwise.
    
    Note:
    Setting the pattern double flag causes a second set of lines, at 90?to the first, for kUserDefined hatch.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPatternDouble(
    bool isDouble);

 /** Description:
    Returns the number of pattern definition lines for this Hatch entity (DXF 78).
  */
  int numPatternDefinitions() const;

  /** Description:
    Returns the specified pattern definition line for this Hatch entity.

    Arguments:
    lineIndex (I) Line index.
    lineAngle (O) Receives the line *angle* (DXF 53).
    baseX (O) Receives the line base point X (DXF 43).
    baseY (O) Receives the line base point Y (DXF 44).
    offsetX (O) Receives the line offset X (DXF 45).
    offsetY (O) Receives the line offset Y (DXF 46).
    dashes (O) Receives the line dash lengths (DXF 79, 49).
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getPatternDefinitionAt(
    int lineIndex, 
    double& lineAngle, 
    double& baseX,
    double& baseY, 
    double& offsetX, 
    double& offsetY,
    OdGeDoubleArray& dashes) const;

  /** Description:
    Returns the hatch style of this hatch entity (DXF 75).
      
    Remarks:
    hatchStyle is one of the following:
    
    @table
    Name          Value
    kNormal       0
    kOuter        1
    kIgnore       2
  */
  OdDbHatch::HatchStyle hatchStyle() const;

  /** Description:
    Sets the hatch style of this Hatch entity (DXF 75).
    
    Arguments:
    hatchStyle (I) Hatch style.
    
    Remarks:
    hatchStyle is one of the following:
    
    @table
    Name          Value
    kNormal       0
    kOuter        1
    kIgnore       2
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setHatchStyle(
    OdDbHatch::HatchStyle hatchStyle);

  /** Description:
    Returns the number of seed points for this Hatch entity (DXF 98).
  */
  int numSeedPoints() const;

  /** Description:
    Returns the specified seed *point* from this Hatch entity (DXF 10).
    Arguments:
    seedIndex (I) Seed *point* index.
  */
  const OdGePoint2d& getSeedPointAt(
    unsigned seedIndex) const;

  /** Description:
    Sets the specified seed *point* for this Hatch entity (DXF 10).

    Arguments:
    seedIndex (I) Seed *point* index.
    point (I) Seed *point*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setSeedPointAt(
    unsigned seedIndex, 
    const OdGePoint2d& point);

  OdResult insertSeedPointAt(
    unsigned seedIndex, 
    const OdGePoint2d& point);

  OdResult getSeepPointIndex(
    const int loopIndex,
    unsigned& seedIndex)const;

  /** Description:
    Appends a seed *point* to this hatch.
    
    Arguments:
    Appends the specified seed *point* to this Hatch entity (DXF 10).
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult appendSeedPoint(const OdGePoint2d& point);

  /** Description:
  Remove a specified seed *point* from this Hatch entity.

  Arguments:
  seedIndex (I) Seed *point* index.
  */
  void removeSeedPointAt(int seedPointIndex);

  /** Description:
    Returns the pixel size for intersection and ray casting.
  */
  double pixelSize() const;

  /** Description:
    Sets the pixel size for intersection and ray casting.
    Arguments:
    pixelSize (I) Pixel size.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setPixelSize(
    double pixelSize);

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

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subViewportDraw(
    OdGiViewportDraw* pWd);

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntity*& pCopy) const ODRX_OVERRIDE;

  /*/Gcad(Modify)
  OdDbObjectPtr decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObjectId& replaceId,
    bool& exchangeXData);
  /*/
  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);
  //*/
  /** Description:
    Evaluates the hatch for this Hatch entity.
    Arguments:
    bUnderestimateNumLines (I) Underestimates the hatch count before aborting.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  OdResult evaluateHatch(
    bool bUnderestimateNumLines = false);

  bool lineGenerationEnabled() const;
  bool setLineGenerationEnabled(bool bEnable);

  /** Description:
    Returns the number of hatch lines in this Hatch entity.
    
    Remarks 
    Returns zero if the hatch pattern is SOLID. 
  */
  int numHatchLines() const;
  
  /** Description:
    Returns the hatch line data for the specified hatch line in this Hatch entity.
      
    Arguments:
    lineIndex (I) Line index.
    startPoint (O) Receives the start *point*.
    endPoint (O) Receives the end *point*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getHatchLineDataAt(
    int lineIndex, 
    OdGePoint2d& startPoint, 
    OdGePoint2d& endPoint) const;
  
	//
  /** Description:
    Returns all the hatch line data for this Hatch entity.
    
    Arguments:
    startPoints (O) Receives the start points.
    endPoints (O) Receives the end points.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getHatchLinesData(
    OdGePoint2dArray& startPoints, 
    OdGePoint2dArray& endPoints) const;
  
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  /** Gcad(Modify): OdDbEntity
  */
  virtual void modifiedGraphics(
    const OdDbEntity* pEntity/*const OdDbObject* pObject*/);

  /** Gcad(Add)
  */
  virtual OdResult subSwapIdWith(OdDbObjectId otherId, OdBool swapXdata = false, OdBool swapExtDict = false);
  virtual OdResult swapReferences(const OdDbIdMapping& idMap);


  /** Description:
    Returns the hatch object type of this Hatch entity.
    
    Remarks:
    hatchObjectType is one of the following:
    
    @table
    Name                Value     Description
    kHatchObject        0         Classic hatch
    kGradientObject     1         Color gradient
  */
  OdDbHatch::HatchObjectType hatchObjectType() const;

  /** Description:
    Sets the hatch object type of this Hatch entity.
    
    Arguments:
    hatchObjectType (I) Hatch object type.
    
    Remarks:
    hatchObjectType is one of the following:
    
    @table
    Name                Value     Description
    kHatchObject        0         Classic hatch
    kGradientObject     1         Color gradient
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setHatchObjectType(
    OdDbHatch::HatchObjectType hatchObjectType);
  
  /** Description:
    Returns true if and only if this Hatch entity is a *color* gradient.
  */
  virtual OdBool isGradient() const;

  /** Description:
    Returns true if and only if this Hatch entity is of type kHatchObject.
  */
  virtual OdBool isHatch() const;
  
  /** Description:
    Returns the gradient type of this Hatch entity.
    
    Remarks:
    gradientType is one of the following:
    
    @table
    Name                    Value
    kPreDefinedGradient     0
    kUserDefinedGradient    1
  */
  OdDbHatch::GradientPatternType gradientType() const;
  
  /** Description:
      Returns the name of the gradient of this Hatch entity.
  */
  // Gcad(Modify)
  const OdChar * gradientName() const;
  
  /** Description:
    Sets the gradient type and name for this Hatch entity.
    Arguments:
    gradientType (I) Gradient type.
    gradientName (I) Gradient name: SPHERICAL, HEMISPHERICAL, CURVED,
    LINEAR, CYLINDER, INVSPHERICAL, INVHEMISPHERICAL, INVCURVED, INVLINEAR,
    or INVCYLINDER.
    
    Remarks:
    gradientType is one of the following:
    
    @table
    Name                    Value
    kPreDefinedGradient     0
    kUserDefinedGradient    1
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setGradient(
    OdDbHatch::GradientPatternType gradientType, 
    const OdChar * gradientName);
  
  /** Description:
    Returns the *angle* of the gradient for this Hatch entity.
      
    Remarks:
    All angles are expressed in radians.  
  */
  double gradientAngle() const;

  /** Description:
    Returns the *angle* of the gradient for this Hatch entity.

    Arguments:
    angle (I) Gradient *angle*.
          
    Remarks:
    All angles are expressed in radians.  
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setGradientAngle(double angle);
  
  /** Description:
    Returns the *colors* and interpolation *values* describing the gradient fill for this Hatch entity.
    
    Arguments:
    colors (O) Array of *colors* defining the gradient.
    values (O) Array of interpolation *values* for the gradient.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult getGradientColors(
    OdCmColorArray& colors, 
    OdGeFloatArray& values) const;
  
  //Gcad(Add):[NOTICE]:arx这里为float
  OdResult getGradientColors(
	unsigned int& count, 
    OdCmColor*& colors,
    float*& values );

  /** Description:
    Returns the *colors* and interpolation values describing the gradient fill for this Hatch entity.
    
    Arguments:
    colors (I) Array of colors defining the gradient.
    values (I) Array of interpolation values for the gradient.

    Note:
    count must be two for the current implementation.
    
    Throws:
    @table
    Exception             Cause
    eInvalidInput         count < 2 || values[0] != 0. || values[count-1] != 1.
    eNotImplementedYet    count > 2
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setGradientColors(
    OdUInt32 count, 
    const OdCmColor* colors, 
    const float* values);
  
  /** Description:
    Returns the *oneColorMode* for this Hatch entity.
  */
  OdBool getGradientOneColorMode() const;

  /** Description:
    Controls the *oneColorMode* for this Hatch entity.
    Arguments:
    oneColorMode (I) Controls the *oneColorMode*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setGradientOneColorMode(
    OdBool oneColorMode);
  
  /** Description:
    Returns the *luminance* *value* for this Hatch entity.
    
    Remarks:
    Returns a *value* in the range. [0.0 .. 1.0].
    
    If the gradient is using *oneColorMode*, this function returns 
    the *luminance* *value* applied to the first *color*.
  */
  double getShadeTintValue() const;
  
  /** Description:
    Sets the *luminance* *value* for this Hatch entity.
    
    Arguments:
    luminance (I) Luminace *value*. [0.0 .. 1.0]
    
    If the gradient is using *oneColorMode*, this function sets 
    the *luminance* *value* applied to the first color.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setShadeTintValue(
    double luminance);

  OdResult setShadeTintValueAndColor2(
    float value);
  
  /** Description:
    Returns the interpolation *value* between the 
    default and shifted values of the gradient's definition. 
    
    Remarks:
    A gradientShift of 0 indicates a fully unshifted gradient.
    A gradientShift of 1 indicates a fully shifted gradient.
  */
  double gradientShift() const;
  
  /** Description:
      Sets the interpolation *value* between the 
      default and shifted values of the gradient's definition. 

      Arguments:
      gradientShift (I) Shift *value*.      
      Remarks:
      A gradientShift of 0 indicates a fully unshifted gradient.
      A gradientShift of 1 indicates a fully shifted gradient.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setGradientShift(double gradientShift);
  
  /** Description:
    Returns the interpolated *color* of the gradient definition.
    Arguments:
    value (I) Interpolation *value*.
    color (O) Receives the interpolated *color*.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult evaluateGradientColorAt(
    double value, 
    OdCmColor& color);

  void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  /** Description:
    Sets the pattern data for this Hatch entity directly, bypassing OdHatchPatternManager (DXF 76 and DXF 2).
    
    Arguments:
    patType (I) Pattern type.
    patName (I) Pattern name.
    angle (I) Pattern *angle*.
    scale (I) Pattern *scale*.
    pat (I) Pattern definition (already scaled and rotated)
    
    Remarks:
    patType must be one of the following:
    
    @table
    Name              Value
    kUserDefined      0
    kPreDefined       1
    kCustomDefined    2
     
    patName is ignored for patType == kUserDefined; appearance is defined by setPatternAngle(),
    setPatternSpace() and setPatternDouble().
    
    Note:
    angle and scale are not applied to the pattern.
  */
  // Gcad(Modify):returns:void->OdResult
  OdResult setRawPattern(
    OdDbHatch::HatchPatternType patType, 
    const OdString& patName,
    double angle, 
    double scale,
    const OdHatchPattern& pat);


  /** Description:
    Returns the hatch pattern definition for this Hatch entity as it appears in the PAT file.
  */
  OdHatchPattern getPattern() const;


  /** Description:
    Returns the hatch pattern definition for this Hatch entity as it appears in the DWG/DXF file.
  */
  OdHatchPattern getRawPattern() const;

  // Gcad(Modify):returns:void->OdResult
  OdResult setOriginPoint(const OdGePoint2d& pt);
  OdGePoint2d originPoint() const;

  virtual OdResult explodeGeometry(OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subDeepClone(OdDbObject* pOwnerObject,OdDbObject*& pClonedObject,OdDbIdMapping& idMap, OdBool isPrimary = true) const;
  
  /** 
  Gcad(Add):增加兼容接口	
  //arx 2008
  */
  virtual OdResult getArea(double& area) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  /**
    Description:
      Returns the hatch background color.
  */
  OdCmColor backgroundColor() const;
  /**
    Description:
      Sets the hatch background color.
  */
  void setBackgroundColor(const OdCmColor& color);

  /**
    Description:
    This function creates a region representing the hatch area from the boundary loops of the hatch. 
    Returns null if the hatch entity does not have a closed boundary, or if the region cannot be created for any other reason.
  */
  OdDbRegion* getRegionArea() const;

  void removeHatchLines();

  virtual void getEcs(OdGeMatrix3d& retVal) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbHatch object pointers.
*/
typedef OdSmartPtr<OdDbHatch> OdDbHatchPtr;

TOOLKIT_EXPORT EdgeArray oddbCreateEdgesFromEntity(const OdDbEntity* pEnt, const OdGePlane& hatchPlane, bool bUseExtend = true);

#include "TD_PackPop.h"

#endif /* OD_DBHATCH_H */
