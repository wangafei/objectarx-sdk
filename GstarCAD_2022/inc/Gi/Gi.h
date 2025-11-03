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




#ifndef _OD_GI_H_
#define _OD_GI_H_

#include "../RxObject.h"
#include "../Ge/GePoint2d.h"
#include "../Ge/GeMatrix2d.h"

class OdDbStub;
class OdDbObjectId;
class OdCmEntityColor;
class OdGeVector3d;
class OdGiMapper;
class OdCmTransparency;
struct OdGiDgLinetypeModifiers;

typedef enum
{
  kOdGiBitonal,
  kOdGiPalette,
  kOdGiGray,
  kOdGiRGBA,
  kOdGiBGRA,
  kOdGiARGB,
  kOdGiABGR,
  kOdGiBGR,
  kOdGiRGB
} OdGiImageOrg;

typedef enum
{
  kOdGiXLeftToRightTopFirst,
  kOdGiXLeftToRightBottomFirst,
  kOdGiXRightToLeftTopFirst,
  kOdGiXRightToLeftBottomFirst,
  kOdGiYTopToBottomLeftFirst,
  kOdGiYTopToBottomRightFirst,
  kOdGiYBottomToTopLeftFirst,
  kOdGiYBottomToTopRightFirst
} OdGiImageOrient;

typedef enum 
{
  kDefaultScaleFilter,
  kNearestScaleFilter,
  kBellScaleFilter,
  kMitchellScaleFilter,
  kTriangleScaleFilter,
  kCubicScaleFilter,
  kBsplineScaleFilter,
  kLanczos3ScaleFilter
} OdGiScaleFilterType;

typedef enum 
{
  kDefaultRotationFilter,
  kInterpolatedRotationFilter,
  kNearestRotationFilter,
} OdGiRotationFilterType;

typedef enum 
{
  kDefaultScale,
  kRelativeScale,
  kUnTransformedScale
} OdGiScaleType;

enum OdGiEdgeStyleMaskValues 
{
  kOdGiNoEdgeStyleMask = 0,
  kOdGiJitterMask      = 1,
  kOdGiOverhangMask    = 2,
  kOdGiEdgeColorMask   = 4
};

class OdGiSentScanLines 
{
public:
  enum IsmRequestStatus 
  {
     eOk,
     eInvalidInput,
     eInvalidColorDepth,
     eInvalidPixelRequest,
     eInvalidDeliveryMethod,
     eNoValidCompressors,
     eInsufficientMemory    
   };
   
    OdInt8 *   mpPixelBuffer;
    OdInt32    mRowBytes;
    void *     mpImageId;
    OdInt16    mIsCancelled;
    OdInt16    mHasFailed;
    OdUInt32   mBytes;
    IsmRequestStatus mRequestStatus;
};

class OdGiRequestScanLines 
{
public:
  enum IEDitherMethod 
  {
    kIEAnyPalette,
    kCustomDithering,
    kCustomDitheringMethod
  };

  enum IEColorSystem
  {
    kBitonal,
    kCMY,
    kCMYK,
    kRGB
  };

  enum ImagePaletteType
  {
    kFromDevice,
    kFromIeWholeImage
  };

  OdGiRequestScanLines()
    : mPixelMinX          (0)
    , mPixelMinY          (0)
    , mPixelMaxX          (0)
    , mPixelMaxY          (0)
    , mpImageId           (0)
    , mImageOrg           (kOdGiBitonal)
    , mImageOrient        (kOdGiXLeftToRightTopFirst)
    , mWindowId           (0)
    , mColorDepth         (8)
    , mPaletteIncarnation (0)
    , mpPalette           (0)
    , mIsDisplay          (0)
    , mRasterRatio        (1.0)
    , mPaletteType        (kFromDevice)
    , mpDataBuffer        (0)
    , mRowWidth           (0)
    , mpBoundaryPoints    (0)
    , mnContours          (0)
    , mpCounts            (0)
    , mScalingType        (kDefaultScale)
    , mScaleFilterType    (kDefaultScaleFilter)
    , mRotationFilterType (kDefaultRotationFilter)
    , mnTotalChunks       (0)
    , mnThisChunk         (0)
    {
    }

    OdUInt32         mPixelMinX;
    OdUInt32         mPixelMinY;
    OdUInt32         mPixelMaxX;
    OdUInt32         mPixelMaxY;
    OdGePoint2d      mLowerLeft;
    OdGePoint2d      mUpperRight;
    void *           mpImageId;
    OdGiImageOrg     mImageOrg;
    OdGiImageOrient  mImageOrient;
    OdInt16          mWindowId;
    OdInt16          mColorDepth;

    union 
    {
      OdInt16 mBackgroundIndex;
      OdInt8  mBackgroundRGB[3];
    } mBackgroundColor;

    union 
    {
      OdInt16 mTransparentIndex;
      OdInt8  mTransparentRGB[3];
    } mTransparentColor;

    union 
    {
      OdInt16 mEntityIndex;
      OdInt8  mEntityRGB[3];
    } mEntityColor;

    OdInt32        mPaletteIncarnation;
    OdInt8 *       mpPalette;
    OdInt16        mIsDisplay;
    double              mRasterRatio;
    OdGeMatrix2d        mPixelToDc;
    ImagePaletteType    mPaletteType;
    void *              mpDataBuffer;
    OdInt32       mRowWidth;
    OdInt32       mNumRows;
    OdInt32 const *mpBoundaryPoints;
    OdInt32       mnContours;
    OdInt32 const *mpCounts;
    OdGiScaleType          mScalingType;
    OdGiScaleFilterType    mScaleFilterType;
    OdGiRotationFilterType mRotationFilterType;
    short                  mnTotalChunks;
    short                  mnThisChunk;
};

class OwnerDraw3d
{
public:
    virtual ~OwnerDraw3d(void) {};
};

typedef enum OdGiColorIntensity 
{
    kOdGiMinColorIntensity = 0x0,
    kOdGiColorIntensity1   = 0x1,
    kOdGiColorIntensity2   = 0x2,
    kOdGiColorIntensity3   = 0x3,
    kOdGiColorIntensity4   = 0x4,
    kOdGiColorIntensity5   = 0x5,
    kOdGiColorIntensity6   = 0x6,
    kOdGiMaxColorIntensity = 0x7 
};

class OdGiColorRGBA
{
public:
  OdGiColorRGBA (void)
    : red   (0.0)
    , green (0.0)
    , blue  (0.0)
    , alpha (1.0)
  { }
  
  OdGiColorRGBA (double r, double g, double b, double a) 
    : red   (r)
    , green (g)
    , blue  (b)
    , alpha (a)
  { }
  
  double red;
  double green;
  double blue;
  double alpha;
};

typedef enum
{
  kOdGiFillAlways = 1,  // Always fill closed graphic primitives.
  kOdGiFillNever  = 2   // Never fill closed graphic primitives.
} OdGiFillType;

typedef enum
{
  kOdGiInvisible      = 0, // Invisible
  kOdGiVisible        = 1, // Visible
  kOdGiSilhouette     = 2  // Silhouette edge
} OdGiVisibility;

#include "../TD_PackPush.h"

/** Description:
    This class provides an interface to the graphical attributes of graphic
    primitives.
  
    Remarks:
    OdGiDrawableTraits is a superset of OdGiSubEntityTraits, and exposes
    additional traits that are consistant for the entire OdGiDrawable.
    
    An OdGiDrawableTraits instance is available during calls to subSetAttributes.
    Graphical attribute settings are used for all graphical primitives until they are changed.
    
    Library:
    TD_Gi
    
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiDrawableTraits : public OdRxObject
{ 
public:
  ODRX_DECLARE_MEMBERS(OdGiDrawableTraits);
public:
  virtual void setTrueColor(const OdCmEntityColor& color);
  virtual void setLayer(OdDbStub* layerId);
  virtual void setLineType(OdDbStub* lineTypeId);
  virtual void setLineWeight(const OdDb::LineWeight lineWeight);
  virtual void setLineTypeScale(double lineTypeScale = 1.0);
  virtual void setThickness(double thickness);
  virtual void setPlotStyleName(OdDb::PlotStyleNameType plotStyleNameType, 
    OdDbStub* plotStyleNameId = 0);
};

/** Description:
    This class provides an interface to the graphical attributes of graphic
    primitives.
  
    Remarks:
    An OdGiSubEntityTraits instance is available during calls to subWorldDraw and subViewportDraw,
    so that drawable classes can control attributes during the vectorization process. 
    Graphical attribute settings are used for all graphical primitives until they are changed.
    
    The functions in this class are implemented by the OdGiAbstractVectorizer
    class.

    Library:
    TD_Gi
    
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiSubEntityTraits : public OdGiDrawableTraits
{
public:
  enum DrawFlags
  {
    kNoDrawFlags        = 0x0000,   // Default value. No DrawFlags specified.
    kDrawBackfaces      = 0x0001,   // Forces backfaces vectorization.
    kDrawHatchGroup     = 0x0002,   // Next shells and meshes should draw hatches.
    kDrawFrontfacesOnly = 0x0004,   // Forces discard backfaces mode.
    kDrawGradientFill   = 0x0008,   // Draws with gradient fill.
    kDrawSolidFill      = 0x0010,   // Draws with solid fill.
    kDrawNoLineWeight   = 0x0020,   // Disables lineweight.
    kDrawNoPlotstyle    = 0x0080,   // Disables plotstyles.
    // the range before 0x8000 is reserved.
    kDrawContourFill            = 0x08000, // Teigha(R) for .dgn files specific.
    kDisableLayoutCache         = 0x10000, // Disable metafile caching for layout switching.
    kDrawBoundaryForClipping    = 0x20000, // Draw (rough) boundary of object to be checked
                                           // when clipping is performed, set by vectorizer.
    kDrawBoundaryForClippingDrw = 0x40000, // Draw (rough) boundary of object to be checked
                                           // when clipping is performed, set by a drawable.
    kClipSetIsEmpty             = 0x80000,
    kInternalDrawFlags          = kDisableLayoutCache | kClipSetIsEmpty,
    // @@@TODO: rename kTextProcessing to something more reasonable. kDrawPolygonFill for example.
    kDrawPolygonFill            = 0x100000, // Fill in all modes if FillAlways mode enabled.
    kExcludeFromViewExt         = 0x200000, // Don't use extents of the entity when calculating total extents.
    kDrawDgLsPolyWithoutBreaks  = 0x400000, // Draw polylines/polygons with Dgn Line Style without segmentation.
    kPolygonProcessing          = 0x800000, // Polygon filling logic must be applied for shell primitive.
    kDisableAutoGenerateNormals = 0x1000000, // Avoid automatic generation of normals for mesh/shell primitives.
    kDisableFillModeCheck       = 0x2000000, // Avoid checking of OdGiContext::fillMode during filling of geometry primitives.
    kDrawUnderlayReference      = 0x4000000, // Draw underlay reference object.
    
    // Flags which can be inherited by nested drawables.
    kInheritableDrawFlags       = kDrawNoLineWeight | kDrawNoPlotstyle | kDrawBoundaryForClipping | kDrawBoundaryForClippingDrw |
                                  kInternalDrawFlags | kExcludeFromViewExt
  };

  enum ShadowFlags
  {
    kShadowsCastAndReceive = 0,   // Geometry could cast and receive shadows.
    kShadowsDoesNotCast    = 1,   // Geometry doesn't cast shadows.
    kShadowsDoesNotReceive = 2,   // Geometry doesn't receive shadows.
    kShadowsIgnore         = kShadowsDoesNotCast | kShadowsDoesNotReceive
  };

  enum SelectionFlags
  {
    kNoSelectionFlags = 0,   // No selection flags set.
    kSelectionIgnore  = 1    // Avoid geometry selection.
  };

  enum SubEntityHints
  {
    kHint2DAttributes  = 1,  // Setup attributes only available in 2DWireframe mode (plotStyles and etc.)
    kHint3DAttributes  = 2,  // Setup attributes only available in shaded modes (materials and etc.)
    kHintAllAttributes = kHint2DAttributes | kHint3DAttributes,
    kHintDefaultState  = kHintAllAttributes
  };
public:
  ODRX_DECLARE_MEMBERS(OdGiSubEntityTraits);

  /** Description:
    Sets the current *color* index (ACI).

    Arguments:
    color (I) *Color* index.
    
    Remarks:
    color must be one of the following:
    
    @table
    Name              Value   Description
    kACIbyBlock       0       ByBlock.
    kACIforeground    7       Foreground *color*.
    kACIbyLayer       256     ByLayer. 
    kACIRed           1       Red. 
    kACIYellow        2       Yellow. 
    kACIGreen         3       Green. 
    kACICyan          4       Cyan. 
    kACIBlue          5       Blue. 
    kACIMagenta       6       Magenta. 
    ..                8-255   Defined by AcadPalette.h
  */
  virtual void setColor(
	  const OdUInt16 color);

 /** Description:
    Sets the current *color* from an OdCmEntityColor instance.
    
    Arguments:
    color (I) OdCmEntityColor object.
  */
  virtual void setTrueColor(
	  const OdCmEntityColor& color);

  /** Description:
    Sets the current *layer*.
    Arguments:
    layerId (I) Object ID of the LayerTableRecord.  
  */
  virtual void setLayer(
	  OdDbStub* layerId);

  /** Description:
    Sets the current linetype.
    Arguments:
    lineTypeId (I) Object ID of the LinetypeTableRecord.  
  */
  virtual void setLineType(
	  OdDbStub* lineTypeId);

  /** Description:
    Sets the current selection marker.
    Arguments:
    marker (I) Selection marker.
  */
  virtual void setSelectionMarker(
    const OdGsMarker selectionMarker);

  virtual void setSelectionMarkerAuto(
    const OdGsMarker selectionMarker);

  /** Description:
    Sets the current fill type.
    Arguments:
    fillType (I) Fill type.
    
    Remarks:
    fillType must be one of the following:
    
    @table
    Name              Value   Description
    kOdGiFillAlways   1       Fill closed graphic primitives.
    kOdGiFillNever    2       Don't fill closed graphic primitives.
       
    Closed graphic primitives consist of the following:
    
    o  arcs with (OdGiArcType == kOdGiArcSector) || (OdGiArcType == kOdGiArcChord) 
    o  circles 
    o  meshes 
    o  polygons 
    o  shells 

  */
  virtual void setFillType(
	  const OdGiFillType fillType);

  /** Description:
    Sets the current fill plane.
    
    Arguments:
    pNormal (I) Pointer to the *normal* to the plane.
    
    Note:
    As implemented, this function does nothing but return.
    It will be fully implemented in a future *release*.
  */
  virtual void setFillPlane(
    const OdGeVector3d* pNormal = 0);

  virtual bool useFillPlane() const;

  /** Description:
    Sets the current lineweight.

    Arguments:
    lineWeight (I) Lineweight.
  */
  virtual void setLineWeight(
	  const OdDb::LineWeight lineWeight);

  /** Description:
    Sets the current linetype scale.
    Arguments:
    lineTypeScale (I) Linetype scale factor.
  */
  virtual void setLineTypeScale(
	  double lineTypeScale = 1.0);

  /** Description:
    Sets the current linetype ScaleToFit property.
    
    Arguments:
    enable (I) Controls ScaleToFit.
    
    Note:
    As implemented, this function does nothing but return.
    It will be fully implemented in a future *release*.
  */
  virtual void setLineTypeScaleToFit(
    bool enable) /*= 0*/;

  /** Description:
    Sets the current *thickness*.
    Arguments:
    thickness (I) Thickness.
  */
  virtual void setThickness(
	  double thickness);

  /** Description:
    Sets the current PlotStyleName.

    Arguments:
    plotStyleNameType (I) Plot Style Name Type.
    plotStyleNameId (I) Object ID of the Plot Style Name.
    
    Remarks:
    plotStyleNameId is used only when plotStyleNameType == kPlotStyleNameById.
    
    plotStyleNameType must be one of the following:
    
    @table
    Name                           Value                         
    kPlotStyleNameByLayer          0
    kPlotStyleNameByBlock          1
    kPlotStyleNameIsDictDefault    2
    kPlotStyleNameById             3
  */
  virtual void setPlotStyleName(
    OdDb::PlotStyleNameType plotStyleNameType, 
    OdDbStub* plotStyleNameId = 0);

  /** Description:
    Sets the current *material*.
    Arguments:
    materialId (I) Object ID of the *material*.
  */
  virtual void setMaterial(
	  OdDbStub* materialId);

  /** Description:
    Sets the current material mapper.
    Arguments:
    pMapper (I) Pointer to the GI mapper object.
  */
  virtual void setMapper(
	  const OdGiMapper *pMapper);

  /** Description:
    Sets the current visual style.
    Arguments:
    visualStyleId (I) Object ID of the visual style.
  */
  virtual void setVisualStyle(
    const OdDbStub* visualStyleId);

 /** Description:
    Sets the current transparency.
    
    Arguments:
    transparency (I) OdCmTransparency object.
  */
  virtual void setTransparency(
    const OdCmTransparency &transparency);

 /** Description:
    Sets the drawing flags.
    
    Arguments:
    drawFlags (I) Input bitmask with DrawFlags.
  */
  virtual void setDrawFlags(
    OdUInt32 drawFlags);

 /** Description:
    Sets selection geometry flag.
    
    Arguments:
    bSelectionFlag (I) New selection geometry flag.
  */
  virtual void setSelectionGeom(
    bool bSelectionFlag);

 /** Description:
    Sets the shadow flags.
    
    Arguments:
    shadowFlags (I) Input ShadowFlags.
  */
  virtual void setShadowFlags(
    ShadowFlags shadowFlags);

 /** Description:
    Sets sectionable flag.
    
    Arguments:
    bSectionableFlag (I) New sectionable flag.
  */
  virtual void setSectionable(
    bool bSectionableFlag);

 /** Description:
    Sets the selection flags.
    
    Arguments:
    selectionFlags (I) Input SelectionFlags.
  */
  virtual void setSelectionFlags(
    SelectionFlags selectionFlags);

  /** Description:
    Returns the current *color* index (ACI).

    Remarks:
    color() returns one of the following:
    
    @table
    Name              Value   Description
    kACIbyBlock       0       ByBlock.
    kACIforeground    7       Foreground *color*.
    kACIbyLayer       256     ByLayer. 
    kACIRed           1       Red. 
    kACIYellow        2       Yellow. 
    kACIGreen         3       Green. 
    kACICyan          4       Cyan. 
    kACIBlue          5       Blue. 
    kACIMagenta       6       Magenta. 
    ..                8-255   Defined by AcadPalette.h
  */
  virtual OdUInt16 color() const;

  /** Description:
    Returns the current *color* as an OdCmEntityColor instance.
  */
  virtual OdCmEntityColor trueColor() const;

  /** Description:
      Returns the current *layer*.
  */
  virtual OdDbStub* layer() const;
  OdDbStub* layerId() const;

  /** Description:
      Returns the current linetype.
  */
  virtual OdDbStub* lineType() const;
  OdDbStub* lineTypeId() const;

  /** Description:
    Returns the current fill type.
      
    Remarks:
    fillType() returns one of the following:
    
    @table
    Name              Value   Description
    kOdGiFillAlways   1       Fill closed graphic primitives.
    kOdGiFillNever    2       Don't fill closed graphic primitives.
       
    Closed graphic primitives consist of the following:
    
    o  arcs with (OdGiArcType == kOdGiArcSector) || (OdGiArcType == kOdGiArcChord) 
    o  circles 
    o  meshes 
    o  polygons 
    o  shells 
 */
  virtual OdGiFillType fillType() const;

  /** Description:
    Returns the *normal* to the current fill plane.
    
    Arguments:
    normal (O) Receives the *normal*.
    
    Note:
    As implemented, this function does nothing but return false.
    It will be fully implemented in a future *release*.
  */
  virtual bool fillPlane(
    OdGeVector3d& normal);

  /** Description:
    Returns the current lineweight.
  */
  virtual OdDb::LineWeight lineWeight() const;

  /** Description:
    Returns the current linetype scale.
  */
  virtual double lineTypeScale() const;

  /** Description:
    Returns the current *thickness*.
  */
  virtual double thickness() const;

  /** Description:
    Returns the current PlotStyleName type.
    
    Remarks:
    plotStyleNameType() returns one of the following:
    
    @table
    Name                           Value                         
    kPlotStyleNameByLayer          0
    kPlotStyleNameByBlock          1
    kPlotStyleNameIsDictDefault    2
    kPlotStyleNameById             3
  */
  virtual OdDb::PlotStyleNameType plotStyleNameType() const;

  /** Description:
    Returns object ID of the the plot style name.
  */
  virtual OdDbStub* plotStyleNameId() const;

  OdDb::PlotStyleNameType getPlotStyleNameId(  OdDbObjectId& id ) const;

  /** Description:
    Returns the Object ID of the *material*.
  */
  virtual OdDbStub* material() const;
  OdDbStub* materialId() const;

  /** Description:
    Returns pointer to the current *material* *mapper*.
  */
  virtual const OdGiMapper* mapper() const;

  /** Description:
    Returns the Object ID of the visual style.
  */
  virtual OdDbStub* visualStyle() const;

  /** Description:
    Returns the current transparency.
  */
  virtual OdCmTransparency transparency() const;

  /** Description:
    Return the current DrawFlags bitmask.
  */
  virtual OdUInt32 drawFlags() const;

  /** Description:
    Return the current selection geometry flag.
  */
  virtual bool selectionGeom() const;

  /** Description:
    Return the current ShadowFlags.
  */
  virtual ShadowFlags shadowFlags() const;

  /** Description:
    Return the current sectionable flag.
  */
  virtual bool sectionable() const;

  /** Description:
    Return the current SelectionFlags.
  */
  virtual SelectionFlags selectionFlags() const;

  // Teigha(R) for .dgn files specific

  /** Description:
    Sets the current secondary color from an OdCmEntityColor instance.
    
    Arguments:
    color (I) OdCmEntityColor object.
  */
  virtual void setSecondaryTrueColor(
    const OdCmEntityColor& color);

  /** Description:
    Returns the current secondary color as an OdCmEntityColor instance.
  */
  virtual OdCmEntityColor secondaryTrueColor() const;
 
 /** Description:
    Sets Dgn Line Style modifiers.

    Arguments:
    pLSMod (I) Pointer to structure with Dgn Line Style modifiers.
  */
  virtual void setLineStyleModifiers(
    const OdGiDgLinetypeModifiers* pLSMod);

  /** Description:
    Return pointer to the current Dgn Line Style modifiers structure.
  */
  virtual const OdGiDgLinetypeModifiers* lineStyleModifiers() const;

  // eof Teigha(R) for .dgn files specific section
  /** Description:
    Adds a light object to the model.

    Arguments:
    lightId (I) Object ID of the light.

    Remarks:
    Through this interface, drawables that emit light can add light objects to the model. 
  */
  virtual void addLight(
    const OdDbStub* lightId);

  virtual void setHighlightFlags(bool bEnable, OdInt32 nPattern); // internal use
  virtual bool highlightFlags(OdInt32* pPattern = NULL) const; // internal use
};

typedef OdSmartPtr<OdGiSubEntityTraits> OdGiSubEntityTraitsPtr;

#include "../TD_PackPop.h"

#endif //_OD_GI_H_
