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




#ifndef __ODGICOMMONDRAW_H__
#define __ODGICOMMONDRAW_H__

#include "../TD_PackPush.h"

#include "../RxObject.h"
#include "../Gi/Gi.h"
#include "../DoubleArray.h"

class OdGiGeometry;
class OdGiContext;
class OdGiSubEntityTraits;
class OdDbStub;
typedef OdRxObject OdDbBaseDatabase;
class OdGePoint3d;
class OdGiDrawable;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiDrawable object pointers.
*/
typedef OdSmartPtr<OdGiDrawable> OdGiDrawablePtr;

/** Description:
    Viewport regeneration modes. 
*/
typedef enum
{
  eOdGiRegenTypeInvalid         = 0,
  kOdGiStandardDisplay          = 2,
  kOdGiHideOrShadeCommand       = 3,
  kOdGiRenderCommand            = 4,
  kOdGiShadedDisplay = kOdGiRenderCommand,
  kOdGiForExplode               = 5,
  kOdGiSaveWorldDrawForProxy    = 6,
  kOdGiForExtents               = 7
} OdGiRegenType;

/** Description: 
    Deviation types used for tessellation.
*/
typedef enum
{
  kOdGiMaxDevForCircle      = 0,
  kOdGiMaxDevForCurve       = 1,
  kOdGiMaxDevForBoundary    = 2,
  kOdGiMaxDevForIsoline     = 3,
  kOdGiMaxDevForFacet       = 4
} OdGiDeviationType;


class OdGiCommonDraw;
class OdGiTextStyle;
class OdPsPlotStyleData;
class OdGiConveyorGeometry;
class OdDbDatabase;

enum // Text vectorization flags
{
  kOdGiIncludeScores    = 2,
  kOdGiRawText          = 4,
  kOdGiIncludePenups    = 8,
  kOdGiDrawShape        = 16,
  kOdGiNotParseCIF      = 32,
  kOdGiNotParseMIF      = 64,
};

class OdGiSectionGeometryManager;
typedef OdSmartPtr<OdGiSectionGeometryManager> OdGiSectionGeometryManagerPtr;

/** Description:
    This class defines common operations and properties that are used in the
    Teigha vectorization process.
    
    Remarks:
    An instance of an OdGiContext subclass is normally created as a preliminary step in the vectorization process, to be
    used throughout the vectorization.

    Most of the virtual functions in this class (the ones that are not pure virtual) are no-ops, serving only to define an interface.

    Library: TD_Gi
    
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiContext : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiContext);

  /** Description:
    Returns the *database* that is currently being vectorized.
  */
  virtual OdDbDatabase* database() const = 0;

  /** Description:
    Opens for read the specified drawable object belonging to the *database* associated with this Context object.
    
    Arguments:
    drawableId (I) Object ID of the drawable to be opened.
    
    Remarks: 
    Returns a SmartPointer to the drawable object.
  */
  virtual OdGiDrawablePtr openDrawable(
    OdDbStub* drawableId);

  /** Description:
      Returns the default lineweight associated with this Context object.
  */
  virtual OdDb::LineWeight defaultLineWeight() const;

  /** Description:
    Returns the common LinetypeScale for this Context object.
  */
  virtual double commonLinetypeScale() const;

  /** Description:
    Returns the default TextStyle associated with this Context object.
    
    Arguments:
    textStyle (O) Receives the TextStyle object.
  */
  virtual void getDefaultTextStyle(
    OdGiTextStyle& textStyle);

  /** Description:
    Vectorizes the specified shape into the specified interface object.

    Arguments:
    pDraw (I) Pointer to the CommonDraw object.
    position (I) Position of the shape.
    shapeNumber (I) Shape number.
    pTextStyle (I) Pointer to the TextStyle for the shape.
  */
  virtual void drawShape(
    OdGiCommonDraw* pDraw, 
    OdGePoint3d& position, 
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle);

  /** Arguments:
      pDest (I) Pointer to the Conveyor object.
      direction (I) Baseline *direction* for the text.
      upVector (I) Up vector for the text.
      pExtrusion (I) Pointer to the Extrusion vector for the text.
  */
  virtual void drawShape(
    OdGiConveyorGeometry* pDest,
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion);

  /** Description:
    Vectorizes the specified text string into the supplied CommonDraw object.

    Arguments:
    pDraw (I) Pointer to the CommonDraw object.
    position (I) Position of the text.
    msg (I) Text string.
    numBytes (I) Number of *bytes* in msg (not including the optional null byte).
    pTextStyle (I) Pointer to the TextStyle for msg.
    flags (I) Vectorization *flags*.
    
    Remarks:
    msg must be null terminated if numBytes is not supplied.
  */
  virtual void drawText(
    OdGiCommonDraw* pDraw, 
    OdGePoint3d& position,
    const OdChar* msg, 
    OdInt32 numBytes,
    const OdGiTextStyle* pTextStyle, 
    OdUInt32 flags = 0);

  /** Arguments:
    height (I) Height of the text.
    width (I) Width of the text.
    oblique (I) Oblique angle of the text.
      
    Note:
    All angles are expressed in radians.
    
    As currently implemented, this function ignores width and oblique.
    They will be fully implemented in a future *release*.
  */
  virtual void drawText(
    OdGiCommonDraw* pDraw, 
    OdGePoint3d& position,
    double height, 
    double width, 
    double oblique, 
    const OdString& msg);

  /** Arguments:
      pDest (I) Pointer to the Conveyor object.
      direction (I) Baseline *direction* for the text.
      upVector (I) Up vector for the text.
      pExtrusion (I) Pointer to the extrusion vector for the text.
      raw (I) If and only if true, escape sequences, such as %%P, will not be converted to special characters.
  */
  virtual void drawText(
    OdGiConveyorGeometry* pDest,
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 numBytes, 
    bool raw,
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion);


  /** Description:
    Returns the extents box for the specified text.
       
    Arguments:
    msg (I) Text string.
    numBytes (I) Number of *bytes* in msg (not including the optional null byte).
    textStyle (I) TextStyle for msg.
    flags (I) Vectorization *flags*.
    min (O) Receives the lower-left corner of the extents box.
    max (O) Receives the upper-right corner of the extents box.
    pEndPos (O) If non-NULL, receives the end position of the text string.

  */
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

  /** Description:
    Returns the extents box for the specified shape.
    
    Arguments:
    textStyle (I) TextStyle for the shape.
    shapeNumber (I) Shape number.
    min (O) Receives the lower-left corner of the extents box.
    max (O) Receives the upper-right corner of the extents box.
  */
  virtual void shapeExtentsBox(
    const OdGiTextStyle& textStyle, 
    int shapeNumber, 
    OdGePoint3d& min, 
    OdGePoint3d& max);

  /** Description:
    Returns the *circle* *zoom* percent for this vectorization process.
    
    Arguments:
    viewportId (I) Pointer to the Object ID of the Viewport object to be queried.
    
    Remarks:
    Returns a value in the range [1,20000]. 100 is the default.
  */
  virtual unsigned int circleZoomPercent(
    OdDbStub* viewportId) const;

  /** Description:
    Returns true if and only if this vectorization is intended for hard copy output.
  */
  virtual OdBool isPlotGeneration() const;
  /** Description:
    Returns palette background color.
  */
  virtual ODCOLORREF paletteBackground() const;

  /** Description:
    Returns true if and only if TrueType text should be filled during this vectorization.
  */
  virtual bool fillTtf() const;

  /** Description:
    Returns the number of isolines to be drawn on surfaces during this vectorization.
  */
  virtual OdUInt32 numberOfIsolines() const;

  /** Description:
    Returns true if and only if quick text mode enabled for this vectorization process.
  */
  virtual bool quickTextMode() const;

  /** Description:
    Returns the text quality percent for this vectorization process.

    Remarks:
    Returns a value in the range [0,100]. 50 is the default.
  */
  virtual OdUInt32 textQuality() const;

  enum ImageQuality
  {
    kImageQualityDraft = 0,
    kImageQualityHigh  = 1
  };

  /** Description:
    Returns the image quality for this vectorization process.
  */
  virtual ImageQuality imageQuality() const;

  /** Description:
    Fading intensity percentage.
  */
  virtual OdUInt32 fadingIntensityPercentage() const;

  enum LineWeightStyle
  {
    kPointLineWeight = 0,
    kLineCapStyle    = 1,
    kLineJoinStyle   = 2
  };
  /** Description:
    Returns line weight display style configuration.

    Arguments:
    styleEntry (I) Line weight style entry for which current setting will be returned.

    Remarks:
    For kPointLineWeight style entry 0 will be returned if point line weight is disabled or 1 if enabled.
    For kLineCapStyle style entry will be returned member of OdPs::LineEndStyle enumeration.
    For kLineJoinStyle style entry will be returned member of OdPs::LineJoinStyle enumeration.
  */
  virtual OdUInt32 lineWeightConfiguration(LineWeightStyle styleEntry) const;
  
  /** Description:
  Enables smooth contours information output for TrueType fonts.
  */
  virtual bool ttfPolyDraw() const;

  /** Description:
    Returns true and only if this vectorization process should be aborted.
  */
  virtual bool regenAbort() const;

  // new ARX
  virtual void disableFastMoveDrag() const;
  virtual bool isBoundaryClipping() const;
  virtual bool isNesting() const;

  // for gcad use
  virtual OdUInt32 hostFlags() const;

  enum PStyleType
  {
    kPsNone       = 0,
    kPsByColor    = 1,
    kPsByName     = 2
  };
  
  /** Description:
    Returns the plot style type of this Context object.
    
    Remarks:
    plotStyleType() returns one of the following:
    
    @table
    Name          Value
    kPsNone       0
    kPsByColor    1
    kPsByName     2
  */
  virtual PStyleType plotStyleType() const;
  
  /** Description:
    Returns the PaperSpace PlotStyle data for this vectorization.
    Arguments:
    
    penNumber (I) Pen number.
    plotStyleData (O) Receives the PlotStyle data.
    objectId (I) Object ID of plot style.
    
  */
  virtual void plotStyle(
    int penNumber, 
    OdPsPlotStyleData& plotStyleData) const;

  virtual void plotStyle(
    OdDbStub* objectId, 
    OdPsPlotStyleData& plotStyleData) const;

  virtual OdDbStub* getStubByID( OdUInt64 objectId ) const;

  virtual OdDbBaseDatabase* baseDatabase() const;
  /** \details
    Silhouette types.
  */
  enum SilhouetteType
  {
    kNoSilhouettes      = 0,        // Disables all types of silhouettes.
    kMeshSilhouettes    = (1 << 0), // Generates silhouettes for shell primitives on Gi side.
    kModelerSilhouettes = (1 << 1), // Generates silhouettes for Brep's on modeler geometry side.
    kAllSilhouettes     = kMeshSilhouettes | kModelerSilhouettes // Enables all types of silhouettes.
  };

  /** \details
    Controls the display of silhouettes.
  */
  virtual OdUInt32 displaySilhouettes() const;
  /** \details
    Returns true if generation of silhouettes is enabled for shell primitives on Gi side.
  */
  inline bool displayMeshSilhouettes() const    { return GETBIT(displaySilhouettes(), kMeshSilhouettes); }
  /** \details
    Returns true if generation of silhouettes is enabled for modeler geometry.
  */
  inline bool displayModelerSilhouettes() const { return GETBIT(displaySilhouettes(), kModelerSilhouettes); }

  /** \details
    Returns an interface for access section geometry functionality.
  */
  virtual OdGiSectionGeometryManagerPtr getSectionGeometryManager();

};


/** Description:
    This class is the base class for entity-level vectorization within Teigha.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiCommonDraw : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiCommonDraw);

  /** Description:
    Returns the regeneration type of the current vectorization process.

    Remarks:
    regenType() returns one of the following:
    
    @table
    Name                            Value 
    eOdGiRegenTypeInvalid           0
    kOdGiStandardDisplay            2
    kOdGiHideOrShadeCommand         3
    kOdGiRenderCommand              4
    kOdGiForExplode                 5
    kOdGiSaveWorldDrawForProxy      6
    kOdGiForExtents                 7

  */
  virtual OdGiRegenType regenType() const = 0;

  /** Description:
    Returns true and only if this vectorization process should be aborted.
  */
  virtual OdBool regenAbort() const = 0;

  /** Description:
    Provides access to this object's the subentity traits.

    Remarks:
    This allows the modification of the vectorization attributes such as *color*, linetype, etc.
  */
  virtual OdGiSubEntityTraits& subEntityTraits() const = 0;

  /** Description:
    Provides access to this object's "drawing interface".
    
    Remarks:
    The "drawing interface" is a set of *geometry* functions used during the vectorization process.
  */
  /*/DD2ARX - xi hui - 2008-06-24 - OdGiCommonDraw::rawGeometry
  virtual OdGiGeometry& rawGeometry() const = 0;
  /*/
  OdGiGeometry& rawGeometry(ODSYSDEF) const
  {
	  return *rawGeometry();
  }
  virtual OdGiGeometry* rawGeometry() const = 0;
  //*/

  /** Description:
    Returns true and only if this vectorization process is the result of a "drag" operation.
    
    Remarks:
  */
  virtual OdBool isDragging() const = 0;
  
  /** Description:
    Returns the recommended maximum *deviation* of the
    current vectorization for the specified *point* on the curve.

    Arguments:
    deviationType (I) Deviation type.
    pointOnCurve (I) Point on the curve.
        
    Remarks:
    This function returns the recommended maximum difference (with respect to the current active *viewport*) between the actual curve or surface, 
    and the tessellated curve or surface. 
    
    deviationType must be one of the following:
    
    @table
    Name                       Value
    kOdGiMaxDevForCircle       0      
    kOdGiMaxDevForCurve        1      
    kOdGiMaxDevForBoundary     2      
    kOdGiMaxDevForIsoline      3
    kOdGiMaxDevForFacet        4

    Note: 
    This function uses *circle* *zoom* percent or FacetRes as appropriate.
  */
  virtual double deviation(
    const OdGiDeviationType deviationType, 
    const OdGePoint3d& pointOnCurve) const = 0;

  /** Description:
    Returns the number of isolines to be drawn on surfaces during this vectorization.
  */
  virtual OdUInt32 numberOfIsolines() const = 0;

  /** Description:
      Returns the OdGiContext instance associated with this object.
  */
  virtual OdGiContext* context() = 0;

  virtual bool secondaryCall() const;
  
  /** \details
    Returns whether silhouette curves should be generated (basically should return OdDbDatabase::getDISPSILH,
    but the behavior could be specialized).
  */
  virtual bool displayModelerSilhouettes() const
  {
    OdGiContext* pContext = const_cast<OdGiCommonDraw*>(this)->context();
    if (pContext)
      return pContext->displayModelerSilhouettes();
    return false;
  }

  virtual bool displayMeshSilhouettes() const
  {
    OdGiContext* pContext = const_cast<OdGiCommonDraw*>(this)->context();
    if (pContext)
      return pContext->displayMeshSilhouettes();
    return false;
  }
  

  virtual int getRenderMode() const { return 0; }
};

class FIRSTDLL_EXPORT OdGiDrawFlagsHelper
{
protected:
  OdGiSubEntityTraits *m_pTraits;
  OdUInt32 m_prevFlags;
public:
  OdGiDrawFlagsHelper(OdGiSubEntityTraits &pTraits, OdUInt32 addFlags, OdUInt32 delFlags = 0)
    : m_pTraits(NULL)
  {
    if (addFlags || delFlags)
    {
      m_prevFlags = pTraits.drawFlags();
      OdUInt32 newFlags = (m_prevFlags & ~delFlags) | addFlags;
      if (m_prevFlags != newFlags)
      {
        pTraits.setDrawFlags(newFlags);
        m_pTraits = &pTraits;
      }
    }
  }
  ~OdGiDrawFlagsHelper()
  {
    if (m_pTraits)
      m_pTraits->setDrawFlags(m_prevFlags);
  }
};
#include "../TD_PackPop.h"

#endif

