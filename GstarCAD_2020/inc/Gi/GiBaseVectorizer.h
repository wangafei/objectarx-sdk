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

// GiBaseVectorizer.h: interface for the OdGiBaseVectorizer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ODGIBASEVECTORIZER_INCLUDED_
#define _ODGIBASEVECTORIZER_INCLUDED_

#include "../Gi/GiDrawImpl.h"
#include "../Gs/Gs.h"
#include "../Ge/GeExtents3d.h"
#include "../Gi/GiViewport.h"
#include "../Gi/GiXform.h"
#include "../Gi/GiModelToViewProc.h"
#include "../Gi/GiConveyorEntryPoint.h"
#include "../Gi/GiConveyorConnector.h"
#include "../Gi/GiDeviation.h"
#include "../Ge/GePlane.h"
#include "../Gi/GiDgLinetype.h"
#include "../Gi/GiOrthoClipper.h"
#include "../Gi/GiExtAccum.h"
#include "../Gi/GiSubEntityTraitsData.h"
#include "../Gi/GiTextStyle.h"
#include "../Gi/GiLayerTraitsData.h"
#include "../Gi/GiMaterialTraitsData.h"
#include "../Gi/GiTraitsCache.h"
#include "../Gi/GiLocalDrawableDesc.h"

class OdGiVisualStyle;
class OdGiBaseVectorizer;
class OdDbStub;
typedef OdSmartPtr<OdGiContext> OdGiContextPtr;

#include "../TD_PackPush.h"

/** Description:
    This class provides an implementation of the OdGiWorldDraw::geometry() function.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiWorldDrawImpl : public OdGiWorldDraw_
                                                  , public OdGiSubEntityTraits
{
protected:
  ODRX_USING_HEAP_OPERATORS(OdGiWorldDraw_);

  OdGiSubEntityTraitsData m_entityTraitsData;
  OdGiContext*            m_pContext;

  OdGiWorldDrawImpl();
public:
  /** Description:
    Sets the OdGiContext instance associated with this object.

    Arguments:
    pUserContext (I) Pointer to the user *context*.
  */
  virtual void setContext(OdGiContext* pUserContext);
  static OdGiContext* dummyGiContext();
  static OdGiContextPtr defaultGiContext(bool bAssocDb = false);

  OdUInt16 color() const;
  OdCmEntityColor trueColor() const;
  OdDbStub* layer() const;
  OdDbStub* lineType() const;
  OdGiFillType fillType() const;
  OdDb::LineWeight lineWeight() const;
  double lineTypeScale() const;
  double thickness() const;
  OdDb::PlotStyleNameType plotStyleNameType() const;
  OdDbStub* plotStyleNameId() const;
  OdDbStub* material() const;
  const OdGiMapper* mapper() const;
  OdDbStub* visualStyle() const;
  OdCmTransparency transparency() const;
  OdUInt32 drawFlags() const;
  bool selectionGeom() const;
  ShadowFlags shadowFlags() const;
  bool sectionable() const;
  SelectionFlags selectionFlags() const;
  OdCmEntityColor secondaryTrueColor() const;
  const OdGiDgLinetypeModifiers* lineStyleModifiers() const;

  void setTrueColor(const OdCmEntityColor& color);
  void setPlotStyleName(OdDb::PlotStyleNameType plotStyleNameType, OdDbStub* pPlotStyleNameId = 0);
  void setColor(const OdUInt16 color);
  void setLayer(OdDbStub* layerId);
  void setLineType(OdDbStub* lineTypeId);
  void setFillType(const OdGiFillType fillType);
  void setLineWeight(const OdDb::LineWeight lineWeight);
  void setLineTypeScale(double lineTypeScale);
  void setThickness(double thickness);
  void setSelectionMarker(const OdGsMarker selectionMarker);
  void setMaterial(OdDbStub* pMaterialId);
  void setMapper(const OdGiMapper *pMapper);
  void setVisualStyle(const OdDbStub* visualStyleId);
  void setTransparency(const OdCmTransparency &transparency);
  void setDrawFlags(OdUInt32 drawFlags);
  void setSelectionGeom(bool bSelectionFlag);
  void setShadowFlags(ShadowFlags shadowFlags);
  void setSectionable(bool bSectionableFlag);
  void setSelectionFlags(SelectionFlags selectionFlags);
  void setSecondaryTrueColor(const OdCmEntityColor& color);
  void setLineStyleModifiers(const OdGiDgLinetypeModifiers* pLSMod);

  /////////////////////////////////////////////////////////////////////////////
  // OdGiCommonDraw Overrides

  OdGiContext* context();

  OdBool isDragging() const;

  OdGiSubEntityTraits& subEntityTraits() const;

  /*/DD2ARX - xi hui - 2008-06-24 - OdGiCommonDraw::rawGeometry
  OdGiGeometry& rawGeometry() const;
  /*/
  OdGiGeometry* rawGeometry() const;
  //*/

  OdUInt32 numberOfIsolines() const;
};

/** Description:
    This class is a base implementation of the OdGiWorldDraw and OdGiViewportDraw interfaces.
    Library: TD_Gi    
  
    Remarks:
    This class takes a drawable graphics and passes it into OdGiConveyorGeometry.
    
    It is the base class for specialized frameworks such as OdGiExtCalc.
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiBaseVectorizer : public OdGiWorldDrawImpl
                                     , public OdGiViewportDraw_
                                     , public OdGiConveyorContext
                                     , public OdGiDeviation 
{
protected:
  ODRX_HEAP_OPERATORS();

  mutable OdGiSubEntityTraitsData m_effectiveEntityTraitsData;
  mutable OdGiLayerTraitsTaker    m_effectiveLayerTraits;
  typedef OdGiTraitsCache<OdGiMaterialTraitsData, OdGiMaterialTraitsTaker, OdGiMaterialTraits::kByBlock | OdGiMaterialTraits::kByLayer> OdGiMaterialTraitsCache;
  mutable OdGiMaterialTraitsCache m_materialTraitsData;
  mutable OdGiMaterialTraitsCache m_effectiveMaterialTraitsData;
  mutable OdDbStub*               m_effectiveMaterialId;

  virtual OdDbStub*               switchLayer(OdDbStub* layerId) const;
  virtual const OdGiLayerTraitsData& effectiveLayerTraits() const;
  mutable OdDbStub*               m_effectiveLayerId;
  OdGsMarker                      m_nSelectionMarker;
  OdGsMarker                      m_nPrevSelectionMarker;
  OdCmEntityColor                 m_cmSecondaryColor;
  OdGiDgLinetypeModifiers         m_lsModifiers;
  OdGiDgLinetypeModifiers*        m_pCurLSModifiers;

  virtual bool layerVisible(OdDbStub* layerId) const;
  /** Description:
    Updates the *layer* traits for this Vectorizer object from the specified subentity traits.
    Arguments:
    subEntityTraits (I) Subentity traits.
  */
  void updateLayerTraits(OdGiSubEntityTraitsData& subEntityTraits) const;
  
public:
  enum ChangedTraits
  {
    kFirstChangedFlag      = 1,
    kColorChanged          = kFirstChangedFlag <<  0,
    kLayerChanged          = kFirstChangedFlag <<  1,
    kLineTypeChanged       = kFirstChangedFlag <<  2,
    kFillTypeChanged       = kFirstChangedFlag <<  3,
    kLineWeightChanged     = kFirstChangedFlag <<  4,
    kLineTypeScaleChanged  = kFirstChangedFlag <<  5,
    kThicknessChanged      = kFirstChangedFlag <<  6,
    kPlotStyleChanged      = kFirstChangedFlag <<  7,
    kMaterialChanged       = kFirstChangedFlag <<  8,
    kMapperChanged         = kFirstChangedFlag <<  9,
    kVisualStyleChanged    = kFirstChangedFlag << 10,
    kTransparencyChanged   = kFirstChangedFlag << 11,
    kDrawFlagsChanged      = kFirstChangedFlag << 12,
    kSelectionGeomChanged  = kFirstChangedFlag << 13,
    kShadowFlagsChanged    = kFirstChangedFlag << 14,
    kSectionableChanged    = kFirstChangedFlag << 15,
    kSelectionFlagsChanged = kFirstChangedFlag << 16,
    kSecColorChanged       = kFirstChangedFlag << 17,
    kAwareFlagChanged      = kFirstChangedFlag << 18,
    kGsMarkerChanged       = kFirstChangedFlag << 19,
	kLSModifiersChanged    = kFirstChangedFlag << 20,
    kAllChanged            = 0xFFFFF, // bin:0000 0000 0000 1111 1111 1111 1111 1111
    kSomeChanged           = kAllChanged
  };

  /** Description:
    Returns true if and only if the EntityTraitsData for this Vectorizer object have been changed.
  */
  bool isEntityTraitsDataChanged(int bit = kSomeChanged) const { return GETBIT(m_entityTraitsDataChanged, bit); }

  /** Description:
    Marks as changed the EntityTraitsData data for this Vectorizer object.
  */
  virtual void setEntityTraitsDataChanged() { m_entityTraitsDataChanged = kAllChanged; }
  /** Description:
    Marks as changed the EntityTraitsData data for this Vectorizer object.
  */
  virtual void setEntityTraitsDataChanged(int bit, bool value = true) { SETBIT(m_entityTraitsDataChanged, bit, value); }
  
  /** Description:
    Marks as unchanged the EntityTraitsData data for this Vectorizer object.
  */
  void clearEntityTraitsDataChanged() const { m_entityTraitsDataChanged = 0; }

protected:
  /** Description:
    Returns true if and only if the *layer* of this Vectorizer object is effectively visible.
    
    Remarks:
    This function returns:
    
                    (GETBIT(m_flags, kDrawLayerOff   ) || !traits.isLayerOff()) &&
                    (GETBIT(m_flags, kDrawLayerFrozen) || !traits.isLayerFrozen())
  */
  bool effectivelyVisible() const
  {
	if ((m_pDrawableDesc) && (m_pDrawableDesc->persistId == NULL))
		return true;

    const OdGiSubEntityTraitsData& traits = effectiveTraits();
    return (
      (GETBIT(m_flags, kDrawLayerOff   ) || !traits.isLayerOff()) &&
      (GETBIT(m_flags, kDrawLayerFrozen) || !traits.isLayerFrozen())
    );
  }  

  /////////////////////////////////////////////////////////////////////////////
  // OdGiConveyorContext Overrides

  OdGiContext& giContext() const;
  const OdGiDrawableDesc* currentDrawableDesc() const;
  const OdGiDrawable* currentDrawable() const;
  const OdGiViewport* giViewport() const;
  const OdGsView* gsView() const;

  /////////////////////////////////////////////////////////////////////////////
  // Data Members
private:
  OdGiConveyorEntryPoint          m_dcEntryPoint;
  OdGiTextStyle                   m_textStyle;
  OdGePlane                       m_primitivePlane;
  OdGeVector3d                    m_extrusion;
  OdGiXformPtr                    m_pDcInputToOutput;

protected:
  OdRxObjectPtr                   m_pGiReserved;
  mutable OdUInt32                m_entityTraitsDataChanged;
  mutable OdUInt32                m_lastEntityTraitsDataChanged;
  OdGiConveyorConnector           m_eyeEntryPoint;

  /** Description:
    Returns an *extrusion* vector *normal* to the specified plane.
    
    Arguments:
    firstPoint (I) First point in the plane.
    secondPoint (I) Second point in the plane.
    thirdPoint (I) Third point in the plane.
    origin (I) Origin of the plane.
    u (I) U-vector in the plane.
    v (I) V-vector in the plane.
    normal (I) Normal to the plane.
    pNormal (I) Pointer to the *normal* to the plane.
    Remarks:
    The magnitude of the *extrusion* vector is effectiveTraits().thickness().
  */
  const OdGeVector3d* extrusion(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint, const OdGePoint3d& thirdPoint);
  const OdGeVector3d* extrusion(const OdGeVector3d& normal);
  const OdGeVector3d* extrusion(const OdGeVector3d* pNormal)
  {
    if(pNormal)
      return extrusion(*pNormal);
    return 0;
  }
  const OdGeVector3d* extrusion(const OdGePoint3d& origin, const OdGeVector3d& u, const OdGeVector3d& v);

  OdGiConveyorConnector           m_modelEntryPoint;
  OdGiConveyorConnector*          m_pActiveEntryPoint;

  OdGiModelToViewProcPtr          m_pModelToEyeProc;
  OdGiConveyorConnector           m_output;

public:
  OdGiDrawableDesc*               m_pDrawableDesc;
  mutable OdUInt32                m_nDrawableAttributes;
  const OdGiDrawableDesc *drawableDesc() const { return m_pDrawableDesc; }

protected:
  enum Flags
  {
    kFirstFlag            = 1,

    kSuppressViewportDraw = kFirstFlag << 0,
    kDrawInvisibleEnts    = kFirstFlag << 1,
    kDrawLayerOff         = kFirstFlag << 2,
    kDrawLayerFrozen      = kFirstFlag << 3,
    kIgnoreFillPlane      = kFirstFlag << 4,
    kSelectionMode        = kFirstFlag << 5,
    kAttributesSegment    = kFirstFlag << 6,

    kLastFlag             = kAttributesSegment
  };
  mutable OdUInt32                m_flags;
  OdUInt32                        m_drawContextFlags;

  OdGiSubEntityTraitsData*        m_pByBlock;

  /** Description:
    Sets the specfied EntityTraitsData data from the specified EntityTraitsData.
    
    Arguments:
    pSource (I) Pointer to the source SubEntityTraitsData.
    destination (O) Receives the SubEntityTraitsData.
    
    Remarks:
    If pSource is NULL, default SubEntityTraitsData is used.
    
  */
  virtual void affectTraits(const OdGiSubEntityTraitsData* pSource, OdGiSubEntityTraitsData& destination) const;

  /** Description:
    Returns the *dash* length below which linetypes are not generated by this Vectorizer object.
  */
  virtual double linetypeGenerationCriteria() const;

  /////////////////////////////////////////////////////////////////////////////
  // OdGiConveyorContext Override

  /** Description:
    Returns the EntityTraitsData in effect for this Vectorization object.
  */
  virtual const OdGiSubEntityTraitsData& effectiveTraits() const;
  virtual void getEffectiveTraits(OdGiSubEntityTraitsData& eTraits) const;

  virtual void setEffectiveTraits(const OdGiSubEntityTraitsData& traits,
                                  const OdGeVector3d* fillNormal = NULL);

  /////////////////////////////////////////////////////////////////////////////
  static OdRxClass* g_pDesc;

public:
  OdGiBaseVectorizer();
  virtual ~OdGiBaseVectorizer();

  static void rxInit();
  static void rxUninit();

  /** Description:
    Returns the a pointer to the OdRxClass object that contains a description
    of this object type, for objects of known class type.

    Note:
    This function is for use only when the class type of this object is known.
    If the class type of this object is unknown, use instead isA().
  */
  static OdRxClass* desc();

  /** Description:
    Called when selection marker is being to be changed.
  */
  virtual void selectionMarkerOnChange(bool bChange = false);


  /** Description:
    Returns the a pointer to the OdRxClass object that contains a description
    of this object type, for objects of unknown class type.
    
    Note:
    This function may be used only when the class type of this object is unknown. 
    If the class type of this object is known, use instead desc().
  */
  OdRxClass* isA() const;

  /** Description:
     Returns the Protocol Extension object for this object.
     Remarks:
     Returns NULL if no protocol extension class exists.
  */                   
  OdRxObject* queryX(const OdRxClass* pProtocolClass) const;

  /** Description:
    Returns a reference to the *output* of this Vectorizer object.
  */
  virtual OdGiConveyorOutput& output();

  /** Description:
    Sets the Eye to Output transformation matrix for this Vectorizer object.
    Arguments:
    xfm (I) Transformation matrix.
  */
  void setEyeToOutputTransform(const OdGeMatrix3d& xfm);

  /** Description:
    Returns the Eye to Output transformation matrix for this Vectorizer object.
    Arguments:
    xfm (I) Receives the transformation matrix.
  */
  const OdGeMatrix3d& eyeToOutputTransform() const;
  void eyeToOutputTransform(OdGeMatrix3d& xfm) const;

  /** Description:
    Returns the OdGiConveyorContext associated with this object.

    Remarks:
    Since OdGiConveyorContext is a parent class, this function always returns "this".
  */
  OdGiConveyorContext* drawContext() { return this; }

  const OdGiConveyorContext* drawContext() const { return this; }

  /** Description:
    Begins the ViewVectorization process for this Vectorizer object.
  */
  virtual void beginViewVectorization();

  /** Description:
    Ends the ViewVectorization process for this Vectorizer object.
  */
  virtual void endViewVectorization();

  /////////////////////////////////////////////////////////////////////////////
  // OdGiSubEntityTraits Overrides

  void setTrueColor(const OdCmEntityColor& trueColor);
  /** Description
    Sets the Plot Style Name Type for this Vectorizer object.
    Arguments:
    plotStyleNameType (I) Plot Style Name Type.
    
    Remarks:
    plotStyleNameType must be one of the following:
    
    @table
    Name                                 Value                         
    OdDb::kPlotStyleNameByLayer          0
    OdDb::kPlotStyleNameByBlock          1
    OdDb::kPlotStyleNameIsDictDefault    2
    OdDb::kPlotStyleNameById             3
  */
  void setPlotStyleNameType(OdDb::PlotStyleNameType plotStyleNameType);
  /** Description:
    Sets the PlotStyleName for this Vectorizer object.
    Arguments:
    plotStyleNameId (I) Pointer to the Object ID of the plot style name.
  */
  void setPlotStyleNameId(OdDbStub* plotStyleNameId);
  void setColor(const OdUInt16 color);
  void setLayer(OdDbStub* layerId);
  void setLineType(OdDbStub* lineTypeId);
  void setFillType(const OdGiFillType fillType);
  void setLineWeight(const OdDb::LineWeight lineWeight);
  void setLineTypeScale(double lineTypeScale);
  void setThickness(double thickness);

  void setPlotStyleName(OdDb::PlotStyleNameType plotStyleNameType, OdDbStub* pPlotStyleNameId= 0);
  void setSelectionMarker(const OdGsMarker selectionMarker);
  void setSelectionMarkerAuto(const OdGsMarker selectionMarker);
  void setMaterial(OdDbStub* pMaterialId);
  void setMapper(const OdGiMapper *pMapper);
  void setVisualStyle(const OdDbStub* pVisualStyleId);
  void setTransparency(const OdCmTransparency& transparency);
  void setDrawFlags(OdUInt32 drawFlags);
  void setSelectionGeom(bool bSelectionFlag);
  void setShadowFlags(ShadowFlags shadowFlags);
  void setSectionable(bool bSectionableFlag);
  void setSelectionFlags(SelectionFlags selectionFlags);

  void setSecondaryTrueColor(const OdCmEntityColor& color);
  OdCmEntityColor secondaryTrueColor() const;
  void setLineStyleModifiers(const OdGiDgLinetypeModifiers* pLSMod);

  virtual void setVisualStyle(const OdGiVisualStyle &visualStyle);
  virtual bool visualStyle(OdGiVisualStyle &visualStyle) const;
  virtual OdDbStub* visualStyle() const;

  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // OdGiCommonDraw Overrides
  virtual OdGiContext* context();
  OdBool regenAbort() const;
  OdGiSubEntityTraits& subEntityTraits() const;
  double deviation(const OdGiDeviationType deviationType, const OdGePoint3d& pointOnCurve) const;
  OdGiRegenType regenType() const;
  OdUInt32 numberOfIsolines() const;
  /*/DD2ARX - xi hui - 2008-06-24 - OdGiCommonDraw::rawGeometry
  OdGiGeometry& rawGeometry() const;
  /*/
  using OdGiCommonDraw::rawGeometry;
  OdGiGeometry* rawGeometry() const;
  //*/
  OdBool isDragging() const;

  /////////////////////////////////////////////////////////////////////////////

  OdUInt32 drawContextFlags() const;
  void setDrawContextFlags(OdUInt32 flags, bool bFlag);

  /////////////////////////////////////////////////////////////////////////////
  // OdGiViewportDraw Override
  //

  /** Note:
      The default implementation of this function always returns 0.
  */
  OdUInt32  sequenceNumber() const;

  /** Note:
      The default implementation of this function always returns false.
  */
  bool isValidId(const OdUInt32 viewportId) const;

  /** Note:
      The default implementation of this function always returns 0.
  */
  OdDbStub* viewportObjectId() const;

  OdGiViewport& viewport() const;

  /////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // OdGiGeometry Overrides

  OdBool circle(const OdGePoint3d& center, const double radius, const OdGeVector3d& normal) const;

  OdBool circle(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint, const OdGePoint3d& thirdPoint) const;

  OdBool circularArc(const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool circularArc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    const OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool polyline(const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const;

  OdBool polygon(const OdUInt32 numVertices, const OdGePoint3d* vertexList) const;
  OdBool polyPoints(const OdUInt32 numVertices, const OdGePoint3d* vertexList ,OdLongPtr baseSubEntMarker = -1) const;
  OdBool lineSegs(const OdUInt32 numSegs , const OdGePoint3d * vertexList ,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdGeMultiDashLine3d* pMDLine,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;  

  OdBool pline(const OdGiPolyline& polyline, OdUInt32 fromIndex = 0, OdUInt32 numSegs = 0) const;

  OdBool pline(const OdDbPolyline& polyline, OdUInt32 fromIndex = 0, OdUInt32 numSegs = 0) const;

  /** Description:
    Introduces a *shape* into this vectorization *context*.
    
    Arguments:
    position (I) Position of the shape.
    shapeNumber (I) Shape number.
    pTextStyle (I) Pointer to the TextStyle for the shape.
    direction (I) Baseline *direction* for the *shape*.
    normal (I) Normal vector.
  */
  void shape(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    int shapeNumber, const OdGiTextStyle* pTextStyle);

  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const double height, const double width, const double oblique, const OdChar* msg) const;

  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const OdChar* msg, const OdInt32 length, const OdBool raw, const OdGiTextStyle& pTextStyle) const;

  OdBool xline(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint) const;

  OdBool ray(const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint ) const;

  OdBool nurbs(const OdGeNurbCurve3d& nurbsCurve, const OdGeVector3d* pNormal = 0) const;

  OdBool ellipArc(const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointsOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool mesh(const OdUInt32 numRows,
    const OdUInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0, 
    const bool bAutoGenerateNormals = true) const;

  OdBool shell(const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdUInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0,
    const struct resbuf* pResbuf = NULL,
    const bool bAutoGenerateNormals = true) const;

  OdBool worldLine(const OdGePoint3d points[2]);

  OdBool polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors, const OdCmTransparency* pTransparency,
                 const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers, OdInt32 nPointSize);

  OdBool image(const OdGiImageBGRA32& imageSource, const OdGePoint3d& position,
    const OdGeVector3d& u, const OdGeVector3d& v, TransparencyMode transparencyMode) const;

  OdBool pushClipBoundary(OdGiClipBoundary* pBoundary);
  OdBool pushClipBoundary(OdGiClipBoundary* pBoundary, OdGiAbstractClipBoundary* pClipInfo);
  void drawClipBoundary(OdGiClipBoundary* pBoundary, OdGiAbstractClipBoundary* pClipInfo);
  void popClipBoundary();
  bool isClipping() const;

  OdBool pushModelTransform(const OdGeMatrix3d& xfm);
  OdBool pushModelTransform(const OdGeVector3d& normal);
  OdBool popModelTransform();

  OdGeMatrix3d getModelToWorldTransform() const;
  OdGeMatrix3d getWorldToModelTransform() const;
  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  void getModelToWorldTransform(OdGeMatrix3d& unnamed) const;
  void getWorldToModelTransform(OdGeMatrix3d& unnamed) const;

  OdBool draw(OdGiDrawable* pDrawable) const;

  const OdGiPathNode* currentGiPath() const;

  /////////////////////////////////////////////////////////////////////////////

  /** Description:
    Sets the default drawable traits for this Vectorizer object,
    and sets the drawable flags for the specified OdGiDrawable object.
    
    Arguments:
    pDrawable (I) Pointer to the Drawable object.
  */
  virtual OdUInt32 setAttributes(const OdGiDrawable* pDrawable);

  /** Description:
    Returns the  drawable flags of the last vectorized OdGiDrawable object.
  */
  OdUInt32 drawableAttributes() const { return m_nDrawableAttributes; }

  /** Description:
    Returnes true if and only the Drawable object associated with
    this Vectorizer is visible.
    Arguments:
    drawableFlags (I) Drawable flags.
    Remarks:
    Called by draw().
  */
  bool needDraw(OdUInt32 drawableFlags);

  /** Description:
    Vectorizes the specified OdGiDrawable object.
    Arguments:
    drawableFlags (I) Drawable flags.
    pDrawable (I) Pointer to the Drawable object.
    
    Remarks:
    Called by draw() after subSetAttributes().
    
    Returns pDrawable->subWorldDraw(this). If pDrawable->subWorldDraw returns false, 
    and kSuppressViewportDraw is not set, this function evokes pDrawable->subViewportDraw(this).
  */
  virtual bool doDraw(OdUInt32 drawableFlags, const OdGiDrawable* pDrawable);

  virtual bool beginDrawable(const OdGiDrawableDesc* ) const { return true; }
  virtual void endDrawable(const OdGiDrawableDesc* ) const   { }

  /////////////////////////////////////////////////////////////////////////////
  // OdGiWorldGeometry Override

  void setExtents(OdGePoint3d *newExtents) const;
  void startAttributesSegment();
  bool isAttributesSegmentEnabled();

  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // OdGiViewportGeometry

  void rasterImageDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage,
    const OdGePoint2d* uvBoundary,
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0);

  void metafileDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool bDcAligned = true,
    bool bAllowClipping = false);

  void polylineEye(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void polygonEye(OdUInt32 numVertices, const OdGePoint3d* vertexList);

  void polylineDc(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void polygonDc(OdUInt32 numVertices, const OdGePoint3d* vertexList);


  /////////////////////////////////////////////////////////////////////////////
  // OdGiConveyorContext Overrides

  virtual void onTraitsModified();

  /////////////////////////////////////////////////////////////////////////////

  /** Description:
    Returns the maximum ModelSpace (UCS) *deviation* for this VectorizeView object.
  */
  const OdGiDeviation& modelDeviation() const;
  /** Description:
    Returns the maximum world (WCS) *deviation* for this VectorizeView object.
  */
  const OdGiDeviation& worldDeviation() const;
  /** Description:
    Returns the maximum EyeSpace (ECS) *deviation* for this VectorizeView object.
  */
  const OdGiDeviation& eyeDeviation() const;

  // materials
  const OdGiMaterialTraitsData &activeMaterialTraitsData() const;
  void activeMaterialTraitsData(OdGiMaterialTraitsData &data) const;
  void setActiveMaterialTraitsData(const OdGiMaterialTraitsData &data);
  // effective materials
  const OdGiMaterialTraitsData &effectiveMaterialTraitsData() const;
  void effectiveMaterialTraitsData(OdGiMaterialTraitsData &data) const;
  void setEffectiveMaterialTraitsData(const OdGiMaterialTraitsData &data);

  /** Description:
    Returns current selection marker state.
  */
  OdGsMarker selectionMarker() const;

  OdGiSubEntityTraitsData *byBlockTraits() const { return m_pByBlock; }
  void setByBlockTraits(OdGiSubEntityTraitsData *pByBlock) { m_pByBlock = pByBlock; }
  OdRxObjectPtr saveByBlockTraits();

  virtual OdBool polylineEx(
    const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1,
    int flags = 0) const;

  virtual OdBool drawOperator(OdUInt32 op, void *pData) const;
  
  virtual OdUInt32 testDrawableFlags(const OdGiDrawable* pDrawable, void* pReserve = NULL) const{return 0;}
  virtual OdGiRegenType regenOdType() const{return regenType();}
};

/** Description:
    This class is an implementation of the subWorldDraw() framework to calculate the WCS *extents* of an OdGiDrawable object.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiExtCalc : public OdGiBaseVectorizer
{
protected:
  bool            m_BBoxSet;
  OdGiExtAccumPtr m_pExtAccum;

public:

  OdGiExtCalc();
  virtual ~OdGiExtCalc();

  OdGiRegenType regenType() const;
  OdBool regenAbort() const;
  OdBool draw(OdGiDrawable* pDrawable) const;
  void setExtents(OdGePoint3d *newExtents) const;
  /** Description:
    Resets the accumulated *extents* for the OdGiDrawable object associated with this Vectorization object.
  */
  void resetExtents();

  /** Description:
    Returns the accumulated *extents* for the OdGiDrawable object associated with this Vectorization object.
    Arguments:
    extents (O) Receives the *extents*.
  */
  void getExtents(OdGeExtents3d& extents) const;

  void setContext(OdGiContext* pUserContext);

  // optimization
  
  const OdGiSubEntityTraitsData& effectiveTraits() const;
  void affectTraits(const OdGiSubEntityTraitsData* pSource, OdGiSubEntityTraitsData& destination) const;
};

ODGI_EXPORT void odgiCalculateTextBasis(OdGeVector3d& u, OdGeVector3d& v,
                                        const OdGeVector3d& normal,
                                        const OdGeVector3d& direction,
                                        double height,
                                        double width,
                                        double oblique,
                                        bool bMirrorX = false,
                                        bool bMirrorY = false);
ODGI_EXPORT const OdGiTextStyle* odgiPrepareTextStyle(const OdGiTextStyle* pStyle, OdGiTextStyle& res);

ODGI_EXPORT OdGiRegenType odgiRegenOdType(OdGiCommonDraw* pCD);

#include "../TD_PackPop.h"

#endif // #ifndef _ODGIBASEVECTORIZER_INCLUDED_
