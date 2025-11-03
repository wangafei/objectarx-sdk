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


#ifndef _ODGILAYERTRAITSDATA_INCLUDED_
#define _ODGILAYERTRAITSDATA_INCLUDED_


#include "../Gi/GiNonEntityTraits.h"
#include "../CmColor.h"
#include "GiDrawImpl.h"

class OdGiBaseVectorizer;


class OdDbStub;

#include "../TD_PackPush.h"

/** Description:
    This class provides an implementation of the OdGiLayerTraits::color() function.
    
    Library:
    TD_Gi
   
    {group:OdGi_Classes}
*/
class OdGiLayerTraits_ : public OdGiLayerTraits
{
  virtual OdCmEntityColor trueColor() const = 0;
protected:
  OdCmEntityColor color() const { return trueColor(); }
};

/** Description:
    This class provides an implementation of the OdGisubEntityTraits::color() function.
    
    Library:
    TD_Gi
   
    {group:OdGi_Classes}
*/
class OdGiSubEntityTraits_ : public OdGiSubEntityTraits
{
  virtual OdCmEntityColor trueColor() const = 0;
protected:
  OdUInt16 color() const { return trueColor().colorIndex(); }
};

/** Description:

    {group:Structs}
*/
struct OdGiLayerTraitsData
{
  OdGiLayerTraitsData()
    : m_flags(OdGiLayerTraits::kPlottable)
    , m_lineweight(OdDb::kLnWtByLwDefault)
    , m_plotStyleNameType(OdDb::kPlotStyleNameById)
    , m_color(OdCmEntityColor::kForeground)
    , m_linetypeId(0)
    , m_plotStyleNameId(0)
    , m_materialId(0)
    , m_cmTransparency(OdUInt8(0xFF))
    , m_layerId(0)
  {
  }

  void operator =(const OdGiLayerTraitsData& other)
  {
    m_flags             = other.m_flags;
    m_lineweight        = other.m_lineweight;
    m_plotStyleNameType = other.m_plotStyleNameType;
    m_color             = other.m_color;
    m_linetypeId        = other.m_linetypeId;
    m_plotStyleNameId   = other.m_plotStyleNameId;
    m_materialId        = other.m_materialId;
    m_cmTransparency    = other.m_cmTransparency;
    m_layerId           = other.m_layerId;
  }

  OdUInt32 flags() const { return m_flags; }
  OdDb::LineWeight lineweight() const { return m_lineweight; }
  OdDbStub* linetype() const { return m_linetypeId; }
  OdDb::PlotStyleNameType plotStyleNameType() const { return m_plotStyleNameType; }
  OdDbStub* plotStyleNameId() const { return m_plotStyleNameId; }
  const OdCmEntityColor& trueColor() const { return m_color; }
  OdDbStub* materialId() const { return m_materialId; }
  OdCmTransparency transparency() const { return m_cmTransparency; }

  void setTrueColor(const OdCmEntityColor& cl) { m_color = cl; }
  void setLineweight(OdDb::LineWeight lw) { m_lineweight = lw; }
  void setLinetype(OdDbStub* id) { m_linetypeId = id; }
  void setMaterial(OdDbStub* id) { m_materialId = id; }
  void setTransparency(const OdCmTransparency& transparency) { m_cmTransparency = transparency; }

  bool isOff() const { return GETBIT(m_flags, OdGiLayerTraits::kOff); }
  void setOff(bool bVal) { SETBIT(m_flags, OdGiLayerTraits::kOff, bVal); }

  bool isLocked() const { return GETBIT(m_flags, OdGiLayerTraits::kLocked); }
  void setLocked(bool bVal) { SETBIT(m_flags, OdGiLayerTraits::kLocked, bVal); }

  bool isPlottable() const { return GETBIT(m_flags, OdGiLayerTraits::kPlottable); }
  void setPlottable(bool bVal) { SETBIT(m_flags, OdGiLayerTraits::kPlottable, bVal); }

  OdUInt32                m_flags;
  OdDb::LineWeight        m_lineweight;
  OdDb::PlotStyleNameType m_plotStyleNameType;

  OdCmEntityColor         m_color;
  OdDbStub*               m_linetypeId;
  OdDbStub*               m_plotStyleNameId;

  OdDbStub*               m_materialId;
  OdCmTransparency        m_cmTransparency;

  OdDbStub*               m_layerId;
};

/** Description:
    This class implements OdGiLayerTraits, OdGiWorldDraw, and OdGIViewportDraw together 
	as a single class that uses the OdDbLayerTableRecord::subSetAttributes(), 
	OdDbLayerTableRecord::subWorldDraw(), and OdDbLayerTableRecord::subViewportDraw() functions to return 
	layer trait values and store them temporarily.
    
    Library:
    TD_Gi
   
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiLayerTraitsTaker : public OdGiLayerTraits_
                                       , public OdGiWorldDraw_
                                       , public OdGiViewportDraw_
                                       , public OdGiSubEntityTraits_
                                       , public OdGiLayerTraitsData
{
  ODRX_USING_HEAP_OPERATORS(OdGiWorldDraw_);

  const OdGiBaseVectorizer* m_pUnderlayingView;

public:
  OdGiLayerTraitsTaker();
  OdGiLayerTraitsTaker(const OdGiBaseVectorizer* pRefView);

  void addRef();
  void release();

  void setRefView(const OdGiBaseVectorizer* pRefView);
  void reset() { static_cast<OdGiLayerTraitsData&>(*this) = OdGiLayerTraitsData(); }

  OdDb::LineWeight lineweight() const;
  OdDbStub* linetype() const;
  OdDb::PlotStyleNameType plotStyleNameType() const;
  OdDbStub* plotStyleNameId() const;
  OdDbStub* materialId() const;
  void setColor(const OdCmEntityColor& color);
  void setLineweight(OdDb::LineWeight lineweight);
  void setLinetype(OdDbStub* pLinetypeId);
  void setPlotStyleName(OdDb::PlotStyleNameType plotStyleNameType, OdDbStub* pPlotStyleNameId= 0);

  bool isOff() const { return GETBIT(m_flags, kOff); }
  void setOff(bool bVal) { SETBIT(m_flags, kOff, bVal); }

  bool isPlottable() const { return GETBIT(m_flags, kPlottable); }
  void setPlottable(bool bVal) { SETBIT(m_flags, kPlottable, bVal); }

  OdCmEntityColor trueColor() const;
  OdDbStub* layer() const;
  OdDbStub* lineType() const;
  OdGiFillType fillType() const;
  OdDb::LineWeight lineWeight() const;
  double lineTypeScale() const;
  double thickness() const;
  OdDbStub* material() const;
  const OdGiMapper* mapper() const;
  OdDbStub* visualStyle() const;
  OdCmTransparency transparency() const;
  OdUInt32 drawFlags() const;
  bool selectionGeom() const;
  ShadowFlags shadowFlags() const;
  bool sectionable() const;
  SelectionFlags selectionFlags() const;

  void setTrueColor(const OdCmEntityColor& color);
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

  OdCmEntityColor secondaryTrueColor() const;
  void setSecondaryTrueColor(const OdCmEntityColor& color);
  const OdGiDgLinetypeModifiers* lineStyleModifiers() const;
  void setLineStyleModifiers(const OdGiDgLinetypeModifiers* pLSMod);

  OdGiRegenType regenType() const;
  OdBool regenAbort() const;
  OdGiSubEntityTraits& subEntityTraits() const;
  /*/DD2ARX - xi hui - 2008-06-24 - OdGiCommonDraw::rawGeometry
  OdGiGeometry& rawGeometry() const;
  /*/
  OdGiGeometry* rawGeometry() const;
  //*/
  OdBool isDragging() const;
  double deviation(const OdGiDeviationType deviationType, 
    const OdGePoint3d& pointOnCurve) const;
  OdUInt32 numberOfIsolines() const;
  OdGiContext* context();

  OdGiViewport& viewport() const;
  OdUInt32 sequenceNumber() const;
  bool isValidId(const OdUInt32 viewportId) const;
  OdDbStub* viewportObjectId() const;

  OdBool pline(const OdGiPolyline& , OdUInt32 , OdUInt32 ) const;
  OdBool pline(const OdDbPolyline& , OdUInt32 , OdUInt32 ) const;
  OdGeMatrix3d getModelToWorldTransform() const;
  OdGeMatrix3d getWorldToModelTransform() const;
  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  void getModelToWorldTransform(OdGeMatrix3d& unnamed) const;
  void getWorldToModelTransform(OdGeMatrix3d& unnamed) const;
  OdBool pushModelTransform(const OdGeVector3d& vNormal);
  OdBool pushModelTransform(const OdGeMatrix3d& xMat);
  OdBool popModelTransform();
  OdBool circle(const OdGePoint3d& center, const double radius, const OdGeVector3d& normal) const;
  OdBool circle(const OdGePoint3d& p1, const OdGePoint3d& p2, const OdGePoint3d& p3)const;
  OdBool circularArc(const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple) const;
  OdBool circularArc(const OdGePoint3d& start,
    const OdGePoint3d& point,
    const OdGePoint3d& end,
    const OdGiArcType arcType = kOdGiArcSimple) const;
  OdBool polyline(const OdUInt32 nbPoints,
    const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = NULL,
    OdLongPtr lBaseSubEntMarker = -1) const;
  OdBool polygon(const OdUInt32 nbPoints, const OdGePoint3d* pVertexList) const;
  OdBool polyPoints(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1) const;
  OdBool lineSegs(const OdUInt32 numSegs , const OdGePoint3d * vertexList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdGeMultiDashLine3d* dlList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;

  OdBool mesh(const OdUInt32 rows,
    const OdUInt32 columns,
    const OdGePoint3d* pVertexList,
    const OdGiEdgeData* pEdgeData = NULL,
    const OdGiFaceData* pFaceData = NULL,
    const OdGiVertexData* pVertexData = NULL,const bool bAutoGenerateNormals = true) const;
  OdBool shell(const OdUInt32 nbVertex,
    const OdGePoint3d* pVertexList,
    const OdUInt32 faceListSize,
    const OdInt32* pFaceList,
    const OdGiEdgeData* pEdgeData = NULL,
    const OdGiFaceData* pFaceData = NULL,
    const OdGiVertexData* pVertexData = NULL,const struct resbuf* pResBuf = NULL,const bool bAutoGenerateNormals = true) const;
  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const double height, const double width, const double oblique, const OdChar* msg) const;
  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const OdChar* msg,const OdInt32 length, const OdBool raw, const OdGiTextStyle& pTextStyle) const;
  OdBool ray(const OdGePoint3d& first, const OdGePoint3d& second) const;
  OdBool nurbs(const OdGeNurbCurve3d& nurbs,const OdGeVector3d* pNormal = 0) const;
  OdBool xline(const OdGePoint3d& p1, const OdGePoint3d& p2) const;
  OdBool ellipArc(const OdGeEllipArc3d& arc,
    const OdGePoint3d* pEndPointsOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple) const;
  OdBool draw(OdGiDrawable* pD) const;
  OdBool pushClipBoundary(OdGiClipBoundary* pBoundary);
  void popClipBoundary();
  OdBool worldLine(const OdGePoint3d pnts[2]);
  void setExtents(OdGePoint3d *newExtents) const;

  void polylineEye(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void polygonEye(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void polylineDc(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void polygonDc(OdUInt32 numVertices, const OdGePoint3d* vertexList);
  void rasterImageDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage, 
    const OdGePoint2d* uvBoundary, 
    OdUInt32 numBoundPts,
    bool transparency,
    double brightness,
    double contrast,
    double fade);
  void  metafileDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false);
  void ownerDrawDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiSelfGdiDrawable* pDrawable,
    bool dcAligned = true,
    bool allowClipping = false);
};

inline void
OdGiLayerTraitsTaker::setRefView(const OdGiBaseVectorizer* pRefView)
{
  m_pUnderlayingView = pRefView;
}

inline
OdGiLayerTraitsTaker::OdGiLayerTraitsTaker()
  : m_pUnderlayingView(0)
{
}

inline
OdGiLayerTraitsTaker::OdGiLayerTraitsTaker(const OdGiBaseVectorizer* pRefView)
  : m_pUnderlayingView(pRefView)
{
}

#include "../TD_PackPop.h"

#endif // #ifndef _ODGILAYERTRAITSDATA_INCLUDED_
