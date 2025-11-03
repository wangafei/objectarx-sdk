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



#ifndef _ODGIDUMMYGEOM_INCLUDED_
#define _ODGIDUMMYGEOM_INCLUDED_

#include "Gi/Gi.h"
#include "Gi/GiBaseVectorizer.h"
#include "Gi/GiViewportGeometry.h"
#include "OdStack.h"
#include "StaticRxObject.h"
#include "DbBaseSubentId.h" 

#include "ModelerMarkers.h"

#include "TD_PackPush.h"


/** Description:
This class is a dummy template for OdGiGeometry.
Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiWrapperGeometry : public T
{
  OdGiGeometry        *m_Geom;
protected:
  void setGeom(OdGiGeometry &Geom) { m_Geom = &Geom; }
  OdGiGeometry &getGeom()const { return *m_Geom; }
public:
  virtual OdBool pline(const OdGiPolyline& p, OdUInt32 i, OdUInt32 n) const
  {
    return m_Geom->pline(p, i, n);
  }

  virtual OdBool pline(const OdDbPolyline& polyline, OdUInt32 fromIndex, OdUInt32 numSegs) const
  {
    return m_Geom->pline(polyline, fromIndex, numSegs);
  }

  virtual OdGeMatrix3d getModelToWorldTransform() const
  {
    return m_Geom->getModelToWorldTransform();
  }
  virtual OdGeMatrix3d getWorldToModelTransform() const
  {
    return m_Geom->getWorldToModelTransform();
  }

  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  virtual void getModelToWorldTransform(OdGeMatrix3d& unnamed) const
  {
    m_Geom->getModelToWorldTransform(unnamed);
  }
  virtual void getWorldToModelTransform(OdGeMatrix3d& unnamed) const
  {
    m_Geom->getWorldToModelTransform(unnamed);
  }

  virtual OdBool pushModelTransform(const OdGeVector3d& vNormal)
  {
    return m_Geom->pushModelTransform(vNormal);
  }
  virtual OdBool pushModelTransform(const OdGeMatrix3d& xMat)
  {
    return m_Geom->pushModelTransform(xMat);
  }
  virtual OdBool popModelTransform()
  {
    return m_Geom->popModelTransform();
  }

  // For drawing various primitives.
  //
  virtual OdBool circle(const OdGePoint3d& center, const double radius, const OdGeVector3d& normal) const
  {
    return m_Geom->circle(center, radius, normal);
  }

  virtual OdBool circle(const OdGePoint3d& p1, const OdGePoint3d& p2, const OdGePoint3d& p3) const
  {
    return m_Geom->circle(p1, p2, p3);
  }

  virtual OdBool circularArc(const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple) const
  {
    return m_Geom->circularArc(center, radius, normal, startVector, sweepAngle, arcType);
  }

  virtual OdBool circularArc(const OdGePoint3d& start,
    const OdGePoint3d& point,
    const OdGePoint3d& end,
    const OdGiArcType arcType = kOdGiArcSimple) const
  {
    return m_Geom->circularArc(start, point, end, arcType);
  }

  virtual OdBool polyline(const OdUInt32 nbPoints,
    const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = NULL,
    OdLongPtr lBaseSubEntMarker = -1) const
  {
    return m_Geom->polyline(nbPoints, pVertexList, pNormal, lBaseSubEntMarker);
  }

  virtual OdBool polygon(const OdUInt32 nbPoints, const OdGePoint3d* pVertexList) const
  {
    return m_Geom->polygon(nbPoints, pVertexList);
  }

  virtual OdBool polyPoints(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker) const
  {
    return m_Geom->polyPoints(numVertices , vertexList , baseSubEntMarker);
  }

  virtual OdBool lineSegs(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal,OdLongPtr baseSubEntMarker) const
  {
    return m_Geom->lineSegs(numSegs , vertexList , pNormal, baseSubEntMarker);
  }

  virtual OdBool dashLineSegs(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal, OdLongPtr baseSubEntMarker) const
  {
    return m_Geom->dashLineSegs(numSegs, dlList, pNormal, baseSubEntMarker);
  }

  virtual OdBool dashLineSegs(const OdGeMultiDashLine3d* pMDLine, const OdGeVector3d* pNormal, OdLongPtr baseSubEntMarker) const  
  {
    return m_Geom->dashLineSegs(pMDLine, pNormal, baseSubEntMarker);
  }

  virtual OdBool mesh(const OdUInt32 rows,
    const OdUInt32 columns,
    const OdGePoint3d* pVertexList,
    const OdGiEdgeData* pEdgeData = NULL,
    const OdGiFaceData* pFaceData = NULL,
    const OdGiVertexData* pVertexData = NULL,const bool bAutoGenerateNormals = true) const
  {
    return m_Geom->mesh(rows, columns, pVertexList,  pEdgeData, pFaceData, pVertexData);
  }

  virtual OdBool shell(const OdUInt32 nbVertex,
    const OdGePoint3d* pVertexList,
    const OdUInt32 faceListSize,
    const OdInt32* pFaceList,
    const OdGiEdgeData* pEdgeData = NULL,
    const OdGiFaceData* pFaceData = NULL,
    const OdGiVertexData* pVertexData = NULL,const struct resbuf* pResBuf = NULL,const bool bAutoGenerateNormals = true) const
  {
    return m_Geom->shell(nbVertex, pVertexList, faceListSize, pFaceList, pEdgeData, pFaceData, pVertexData);
  }

  virtual OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const double height, const double width, const double oblique, const OdChar* msg) const
  {
    return m_Geom->text(position, normal, direction, height, width, oblique, msg);
  }

  virtual OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const OdChar* msg, const OdInt32 length, const OdBool raw, const OdGiTextStyle& pTextStyle) const
  {
    return m_Geom->text(position, normal, direction, msg, length, raw, pTextStyle);
  }

  OdBool ray(const OdGePoint3d& first, const OdGePoint3d& second) const
  {
    return m_Geom->ray(first, second);
  }

  virtual OdBool nurbs(const OdGeNurbCurve3d& nurbs, const OdGeVector3d* pNormal = 0) const
  {
    return m_Geom->nurbs(nurbs, pNormal);
  }

  virtual OdBool xline(const OdGePoint3d& p1, const OdGePoint3d& p2) const
  {
    return m_Geom->xline(p1, p2);
  }

  virtual OdBool ellipArc(const OdGeEllipArc3d& arc,
    const OdGePoint3d* pEndPointsOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple) const
  {
    return m_Geom->ellipArc(arc, pEndPointsOverrides, arcType);
  }

  virtual OdBool draw(OdGiDrawable* pD) const
  {
    return m_Geom->draw(pD);
  }

  virtual OdBool pushClipBoundary(OdGiClipBoundary* pBoundary)
  {
    return m_Geom->pushClipBoundary(pBoundary);
  }
  virtual void popClipBoundary()
  {
    m_Geom->popClipBoundary();
  }

  virtual OdBool worldLine(const OdGePoint3d pnts[2])
  {
    return m_Geom->worldLine(pnts);
  }
  virtual OdBool polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors, const OdCmTransparency* pTransparency,
                         const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers, OdInt32 nPointSize)
  {
    return m_Geom->polypoint(numPoints, vertexList, pColors, pTransparency, pNormals, pSubEntMarkers, nPointSize);
  }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiWrapperWorldGeometry : public OdGiWrapperGeometry< T >
{
public:
  virtual void setExtents(OdGePoint3d *newExtents) const { ((OdGiWorldGeometry&)(OdGiWrapperGeometry< T >::getGeom())).setExtents(newExtents); }
  virtual void startAttributesSegment() { ((OdGiWorldGeometry&)(OdGiWrapperGeometry< T >::getGeom())).startAttributesSegment(); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiWrapperViewportGeometry : public OdGiWrapperGeometry< T >
{
public:
  virtual void polylineEye(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).polylineEye(numVertices, vertexList); }

  virtual void polygonEye(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).polygonEye(numVertices, vertexList); }

  virtual void polylineDc(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).polylineDc(numVertices, vertexList); }

  virtual void polygonDc(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).polygonDc(numVertices, vertexList); }

  virtual void rasterImageDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage, 
    const OdGePoint2d* uvBoundary, 
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).rasterImageDc(origin,u,v,pImage, uvBoundary, numBoundPts,transparency,brightness,contrast,fade); }

  virtual void  metafileDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).metafileDc(origin,u,v,pMetafile,dcAligned,allowClipping); }

  virtual void ownerDrawDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiSelfGdiDrawable* pDrawable,
    bool dcAligned = true,
    bool allowClipping = false) { ((OdGiViewportGeometry&)(OdGiWrapperGeometry< T >::getGeom())).ownerDrawDc(origin,u,v,pDrawable,dcAligned,allowClipping); }
};


/** \details

Corresponding C++ library: TD_Gi
<group OdGi_Classes>
*/
template <class TInterface, class TData>
class OdGiSubEntityTraitsToDataWrapper : public TInterface
{
  protected:
    TData *m_pTraits;
  public:
    OdGiSubEntityTraitsToDataWrapper() : m_pTraits(NULL) {}

    void setTraits(TData &pTraits) { m_pTraits = &pTraits; }
    TData &getTraits() const { return *m_pTraits; }

    void setColor(const OdUInt16 n) { m_pTraits->setColor(n); }
    void setTrueColor(const OdCmEntityColor& n) { m_pTraits->setTrueColor(n); }
    void setLayer(OdDbStub* n) { m_pTraits->setLayer(n); }
    void setLineType(OdDbStub* n) { m_pTraits->setLineType(n); }
    void setSelectionMarker(const OdGsMarker /*n*/) { } // Stub
    void setFillType(const OdGiFillType n) { m_pTraits->setFillType(n); }
    void setFillPlane(const OdGeVector3d* /*n*/ = 0) { } // Stub
    void setLineWeight(const OdDb::LineWeight n) { m_pTraits->setLineWeight(n); }
    void setLineTypeScale(double n = 1.0) { m_pTraits->setLineTypeScale(n); }
    void setThickness(double n) { m_pTraits->setThickness(n); }
    void setPlotStyleName(OdDb::PlotStyleNameType n, OdDbStub* m = 0) { m_pTraits->setPlotStyleName(n, m); }
    void setMaterial(OdDbStub* n) { m_pTraits->setMaterial(n); }
    void setMapper(const OdGiMapper * n) { m_pTraits->setMapper(n); }
    void setVisualStyle(const OdDbStub* n) { m_pTraits->setVisualStyle(const_cast<OdDbStub*>(n)); }
    void setTransparency(const OdCmTransparency& transparency) { m_pTraits->setTransparency(transparency); }
    void setDrawFlags(OdUInt32 drawFlags) { m_pTraits->setDrawFlags(drawFlags); }
    void setSelectionGeom(bool bSelectionFlag) { m_pTraits->setSelectionGeom(bSelectionFlag); }
    void setShadowFlags(OdGiSubEntityTraits::ShadowFlags shadowFlags) { m_pTraits->setShadowFlags(shadowFlags); }
    void setSectionable(bool bSectionableFlag) { m_pTraits->setSectionable(bSectionableFlag); }
    void setSelectionFlags(OdGiSubEntityTraits::SelectionFlags selectionFlags) { m_pTraits->setSelectionFlags(selectionFlags); }
    void setSecondaryTrueColor(const OdCmEntityColor& n) { m_pTraits->setSecondaryTrueColor(n); }
    void setLineStyleModifiers(const OdGiDgLinetypeModifiers* pLSMod) { m_pTraits->setLineStyleModifiers(pLSMod); }
    //void setFill(const OdGiFill* pFill) { m_pTraits->setFill(pFill); }

    OdUInt16 color() const { return m_pTraits->color(); }
    OdCmEntityColor trueColor() const { return m_pTraits->trueColor(); }
    OdDbStub* layer() const { return m_pTraits->layer(); }
    OdDbStub* lineType() const { return m_pTraits->lineType(); }
    OdGiFillType fillType() const { return m_pTraits->fillType(); }
    bool fillPlane(OdGeVector3d& /*n*/) { return false; } // Stub
    OdDb::LineWeight lineWeight() const { return m_pTraits->lineWeight(); }
    double lineTypeScale() const { return m_pTraits->lineTypeScale(); }
    double thickness() const { return m_pTraits->thickness(); }
    OdDb::PlotStyleNameType plotStyleNameType() const { return m_pTraits->plotStyleNameType(); }
    OdDbStub* plotStyleNameId() const { return  m_pTraits->plotStyleNameId(); }
    OdDbStub* material() const { return m_pTraits->material(); }
    const OdGiMapper* mapper() const { return m_pTraits->mapper(); }
    OdDbStub* visualStyle() const { return m_pTraits->visualStyle(); }
    OdCmTransparency transparency() const { return m_pTraits->transparency(); }
    OdUInt32 drawFlags() const { return m_pTraits->drawFlags(); }
    bool selectionGeom() const { return m_pTraits->selectionGeom(); }
    OdGiSubEntityTraits::ShadowFlags shadowFlags() const { return m_pTraits->shadowFlags(); }
    bool sectionable() const { return m_pTraits->sectionable(); }
    OdGiSubEntityTraits::SelectionFlags selectionFlags() const { return m_pTraits->selectionFlags(); }
    OdCmEntityColor secondaryTrueColor() const { return m_pTraits->secondaryTrueColor(); }
    const OdGiDgLinetypeModifiers* lineStyleModifiers() const { return m_pTraits->lineStyleModifiers(); }
    //const OdGiFill* fill() const { return m_pTraits->fill(); }
};

/** \details

Corresponding C++ library: TD_Gi
<group OdGi_Classes>
*/
class OdGiSubEntityTraitsToData : public OdGiSubEntityTraitsToDataWrapper<OdStaticRxObject<OdGiSubEntityTraits>, OdGiSubEntityTraitsData>
{
  public:
    OdGiSubEntityTraitsToData() {}
    OdGiSubEntityTraitsToData(OdGiSubEntityTraitsData &pData) { setTraits(pData); }

    static void copyTraits(OdGiSubEntityTraits &pFrom, OdGiSubEntityTraits &pTo, OdUInt32 nFlags = OdGiBaseVectorizer::kAllChanged)
    {
      if (GETBIT(nFlags, OdGiBaseVectorizer::kColorChanged)) pTo.setTrueColor(pFrom.trueColor());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kLayerChanged)) pTo.setLayer(pFrom.layer());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kLineTypeChanged)) pTo.setLineType(pFrom.lineType());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kFillTypeChanged)) pTo.setFillType(pFrom.fillType());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kLineWeightChanged)) pTo.setLineWeight(pFrom.lineWeight());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kLineTypeScaleChanged)) pTo.setLineTypeScale(pFrom.lineTypeScale());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kThicknessChanged)) pTo.setThickness(pFrom.thickness());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kPlotStyleChanged)) pTo.setPlotStyleName(pFrom.plotStyleNameType(), pFrom.plotStyleNameId());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kMaterialChanged)) pTo.setMaterial(pFrom.material());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kMapperChanged)) pTo.setMapper(pFrom.mapper());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kVisualStyleChanged)) pTo.setVisualStyle(pFrom.visualStyle());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kTransparencyChanged)) pTo.setTransparency(pFrom.transparency());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kDrawFlagsChanged)) pTo.setDrawFlags(pFrom.drawFlags());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kSelectionGeomChanged)) pTo.setSelectionGeom(pFrom.selectionGeom());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kShadowFlagsChanged)) pTo.setShadowFlags(pFrom.shadowFlags());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kSectionableChanged)) pTo.setSectionable(pFrom.sectionable());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kSelectionFlagsChanged)) pTo.setSelectionFlags(pFrom.selectionFlags());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kSecColorChanged)) pTo.setSecondaryTrueColor(pFrom.secondaryTrueColor());
      if (GETBIT(nFlags, OdGiBaseVectorizer::kLSModifiersChanged)) pTo.setLineStyleModifiers(pFrom.lineStyleModifiers());
      //if (GETBIT(nFlags, OdGiBaseVectorizer::kFillChanged)) pTo.setFill(pFrom.fill());
    }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T> class OdGiSubEntityTraitsWrapper : public T
{
  OdGiSubEntityTraits *m_pTraits;
protected:
  void setTraits(OdGiSubEntityTraits &pTraits) { m_pTraits = &pTraits; }
  OdGiSubEntityTraits &getTraits() { return *m_pTraits; }
public:
  OdGiSubEntityTraitsWrapper() : m_pTraits(0) { }

  // no refcounting
  void addRef() { m_pTraits->addRef(); }
  // no refcounting
  void release() { m_pTraits->release(); }

  void setColor(const OdUInt16 n) { m_pTraits->setColor(n); }
  void setTrueColor(const OdCmEntityColor& n) { m_pTraits->setTrueColor(n); }
  void setLayer(OdDbStub* n) { m_pTraits->setLayer(n); }
  void setLineType(OdDbStub* n) { m_pTraits->setLineType(n); }
  void setSelectionMarker(const OdGsMarker n) { m_pTraits->setSelectionMarker(n); }
  void setFillType(const OdGiFillType n) { m_pTraits->setFillType(n); }
  void setFillPlane(const OdGeVector3d* n= 0) { m_pTraits->setFillPlane(n); }
  void setLineWeight(const OdDb::LineWeight n) { m_pTraits->setLineWeight(n); }
  void setLineTypeScale(double n = 1.0) { m_pTraits->setLineTypeScale(n); }
  void setLineTypeScaleToFit(bool n) { m_pTraits->setLineTypeScaleToFit(n); }
  void setThickness(double n) { m_pTraits->setThickness(n); }
  void setPlotStyleName(OdDb::PlotStyleNameType n, OdDbStub* m= 0) { m_pTraits->setPlotStyleName(n,m); }
  void setMaterial(OdDbStub* n) { m_pTraits->setMaterial(n); }
  void setMapper(const OdGiMapper * n) { m_pTraits->setMapper(n); }
  void setVisualStyle(const OdDbStub* n) { m_pTraits->setVisualStyle(n); }
  void setTransparency(const OdCmTransparency& transparency) { m_pTraits->setTransparency(transparency); }
  void setDrawFlags(OdUInt32 drawFlags) { m_pTraits->setDrawFlags(drawFlags); }
  void setSelectionGeom(bool bSelectionFlag) { m_pTraits->setSelectionGeom(bSelectionFlag); }
  void setShadowFlags(OdGiSubEntityTraits::ShadowFlags shadowFlags) { m_pTraits->setShadowFlags(shadowFlags); }
  void setSectionable(bool bSectionableFlag) { m_pTraits->setSectionable(bSectionableFlag); }
  void setSelectionFlags(OdGiSubEntityTraits::SelectionFlags selectionFlags) { m_pTraits->setSelectionFlags(selectionFlags); }
  void setSecondaryTrueColor(const OdCmEntityColor& n) { m_pTraits->setSecondaryTrueColor(n); }

  OdUInt16 color() const  { return  m_pTraits->color(); }
  OdCmEntityColor trueColor() const  { return  m_pTraits->trueColor(); }
  OdDbStub* layer() const  { return  m_pTraits->layer(); }
  OdDbStub* lineType() const  { return  m_pTraits->lineType(); }
  OdGiFillType fillType() const  { return  m_pTraits->fillType(); }
  bool fillPlane(OdGeVector3d& n) { return  m_pTraits->fillPlane(n); }
  OdDb::LineWeight lineWeight() const  { return  m_pTraits->lineWeight(); }
  double lineTypeScale() const  { return  m_pTraits->lineTypeScale(); }
  double thickness() const  { return m_pTraits->thickness(); }
  OdDb::PlotStyleNameType plotStyleNameType() const  { return m_pTraits->plotStyleNameType(); }
  OdDbStub* plotStyleNameId() const  { return  m_pTraits->plotStyleNameId(); }
  OdDbStub* material() const  { return  m_pTraits->material(); }
  const OdGiMapper* mapper() const  { return  m_pTraits->mapper(); }
  OdDbStub* visualStyle() const  { return  m_pTraits->visualStyle(); }
  OdCmTransparency transparency() const  {  return m_pTraits->transparency(); }
  OdUInt32 drawFlags() const  {  return m_pTraits->drawFlags(); }
  bool selectionGeom() const  { return m_pTraits->selectionGeom(); }
  OdGiSubEntityTraits::ShadowFlags shadowFlags() const  { return m_pTraits->shadowFlags(); }
  bool sectionable() const  { return m_pTraits->sectionable(); }
  OdGiSubEntityTraits::SelectionFlags selectionFlags() const  { return m_pTraits->selectionFlags(); }
  OdCmEntityColor secondaryTrueColor() const  { return m_pTraits->secondaryTrueColor(); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T> class OdGiWrapperCommonDraw : public T
{
  OdGiCommonDraw *m_pD;
protected:
  void setDraw(OdGiCommonDraw &pD) { m_pD = &pD; }
  OdGiCommonDraw *getDraw() const { return m_pD; }
public:
  OdGiWrapperCommonDraw() : m_pD(0) {}
  virtual OdGiGeometry* rawGeometry() const            { return m_pD->rawGeometry(); }
  virtual OdGiRegenType regenType() const              { return m_pD->regenType(); }
  virtual OdBool regenAbort() const                    { return m_pD->regenAbort(); }
  virtual OdGiSubEntityTraits& subEntityTraits() const { return m_pD->subEntityTraits(); }
  virtual OdBool isDragging() const                    { return m_pD->isDragging(); }
  virtual OdGiContext* context()                       { return m_pD->context(); }
  virtual OdUInt32 numberOfIsolines() const            { return m_pD->numberOfIsolines(); }
  virtual double deviation(const OdGiDeviationType t, const OdGePoint3d& p) const { return m_pD->deviation(t, p); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T> class OdGiWrapperViewportDraw : public OdGiWrapperCommonDraw< T >
{
public:
  virtual OdGiViewport& viewport() const { return ((OdGiViewportDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->viewport(); }
  virtual OdGiViewportGeometry& geometry() const  { return ((OdGiViewportDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->geometry(); }
  virtual OdUInt32 sequenceNumber() const  { return ((OdGiViewportDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->sequenceNumber(); }
  virtual bool isValidId(const OdUInt32 viewportId) const { return ((OdGiViewportDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->isValidId(viewportId); }
  virtual OdDbStub* viewportObjectId() const { return ((OdGiViewportDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->viewportObjectId(); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T> class OdGiWrapperWorldDraw : public OdGiWrapperCommonDraw< T >
{
public:
  virtual OdGiWorldGeometry& geometry() const  { return ((OdGiWorldDraw*)(OdGiWrapperCommonDraw< T >::getDraw()))->geometry(); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
class OdGiViewportDraw_Stub : public OdGiWrapperViewportDraw<OdGiViewportDraw>
                            , public OdGiWrapperViewportGeometry<OdGiViewportGeometry>
                            , public OdGiSubEntityTraitsWrapper<OdGiSubEntityTraits>
{
public:
  ODRX_USING_HEAP_OPERATORS( OdGiWrapperViewportDraw<OdGiViewportDraw> );

  OdGiViewportDraw_Stub(OdGiViewportDraw &pVD, OdGiViewportGeometry &pVG, OdGiSubEntityTraits &pST)
  {
    setDraw(pVD);
    setGeom(pVG);
    setTraits(pST);
  }

  virtual OdGiGeometry* rawGeometry() const   { return static_cast<OdGiGeometry*>(const_cast<OdGiViewportDraw_Stub*>(this)); }
  virtual OdGiSubEntityTraits& subEntityTraits() const { return *static_cast<OdGiSubEntityTraits*>(const_cast<OdGiViewportDraw_Stub*>(this)); }
  virtual OdGiViewportGeometry& geometry() const  { return *static_cast<OdGiViewportGeometry*>(const_cast<OdGiViewportDraw_Stub*>(this)); }

  void addRef() { }
  void release() { }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
class OdGiWorldDraw_Stub : public OdGiWrapperWorldDraw<OdGiWorldDraw>
                         , public OdGiWrapperWorldGeometry<OdGiWorldGeometry>
                         , public OdGiSubEntityTraitsWrapper<OdGiSubEntityTraits>
{
public:
  ODRX_USING_HEAP_OPERATORS( OdGiWrapperWorldDraw<OdGiWorldDraw> );

  OdGiWorldDraw_Stub(OdGiWorldDraw &pVD, OdGiWorldGeometry &pVG, OdGiSubEntityTraits &pST)
  {
    setDraw(pVD);
    setGeom(pVG);
    setTraits(pST);
  }

  virtual OdGiGeometry* rawGeometry() const   { return static_cast<OdGiGeometry*>(const_cast<OdGiWorldDraw_Stub*>(this)); }
  virtual OdGiSubEntityTraits& subEntityTraits() const { return *static_cast<OdGiSubEntityTraits*>(const_cast<OdGiWorldDraw_Stub*>(this)); }
  virtual OdGiWorldGeometry& geometry() const  { return *static_cast<OdGiWorldGeometry*>(const_cast<OdGiWorldDraw_Stub*>(this)); }

  void addRef() { }
  void release() { }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyGeometry : public T
{
public:
  OdBool circle(const OdGePoint3d& /*center*/, const double /*radius*/, const OdGeVector3d& /*normal*/) const {return ::kFalse;}

  OdBool circle(const OdGePoint3d& /*firstPoint*/, const OdGePoint3d& /*secondPoint*/, const OdGePoint3d& /*thirdPoint*/) const {return ::kFalse;}

  OdBool circularArc(const OdGePoint3d& /*center*/,
    const double /*radius*/,
    const OdGeVector3d& /*normal*/,
    const OdGeVector3d& /*startVector*/,
    const double /*sweepAngle*/,
    const OdGiArcType /*arcType*/ = kOdGiArcSimple) const {return ::kFalse;}

  OdBool circularArc(const OdGePoint3d& /*firstPoint*/,
    const OdGePoint3d& /*secondPoint*/,
    const OdGePoint3d& /*thirdPoint*/,
    const OdGiArcType /*arcType */= kOdGiArcSimple) const {return ::kFalse;}

  OdBool polyline(const OdUInt32 /*numVertices*/,
    const OdGePoint3d* /*vertexList*/,
    const OdGeVector3d* /*pNormal */= 0,
     OdLongPtr /*baseSubEntMarker */= -1) const {return ::kFalse;}

  OdBool polygon(const OdUInt32 /*numVertices*/, const OdGePoint3d* /*vertexList*/) const {return ::kFalse;}
  OdBool polyPoints(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1) const {return kFalse;}
  OdBool lineSegs(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const {return kFalse;}
  OdBool dashLineSegs(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1) const{return kFalse;}
  OdBool dashLineSegs(const OdGeMultiDashLine3d* dlList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const{return kFalse;}

  OdBool pline(const OdGiPolyline& /*polylPine*/, OdUInt32 /*fromIndex */= 0, OdUInt32 /*numSegs */= 0) const {return ::kFalse;}

  OdBool pline(const OdDbPolyline&, OdUInt32, OdUInt32) const { return ::kFalse; }

  OdBool shape(const OdGePoint3d& /*position*/,
    const OdGeVector3d& /*normal*/, const OdGeVector3d& /*direction*/,
    int /*shapeNumber*/, const OdGiTextStyle* /*pTextStyle*/) {return ::kFalse;}

  OdBool text(const OdGePoint3d& /*position*/,
    const OdGeVector3d& /*normal*/, const OdGeVector3d& /*direction*/,
    const double /*height*/, const double /*width*/, const double /*oblique*/, const OdChar* /*msg*/) const {return ::kFalse;}

  OdBool text(const OdGePoint3d& /*position*/,
    const OdGeVector3d& /*normal*/, const OdGeVector3d& /*direction*/,
    const OdChar* /*msg*/, const OdInt32 /*length*/, const OdBool /*raw*/, const OdGiTextStyle& /*pTextStyle*/) const {return ::kFalse;}

  OdBool xline(const OdGePoint3d& /*firstPoint*/, const OdGePoint3d& /*secondPoint*/) const {return ::kFalse;}

  OdBool ray(const OdGePoint3d& /*basePoint*/, const OdGePoint3d& /*throughPoint */) const {return ::kFalse;}

  OdBool nurbs(const OdGeNurbCurve3d& /*nurbsCurve*/,const OdGeVector3d*) const {return ::kFalse;}

  OdBool ellipArc(const OdGeEllipArc3d& /*ellipArc*/,
    const OdGePoint3d* /*endPointsOverrides */= 0,
    OdGiArcType /*arcType */= kOdGiArcSimple) const {return ::kFalse;}

  OdBool mesh(const OdUInt32 /*numRows*/,
    const OdUInt32 /*numColumns*/,
    const OdGePoint3d* /*vertexList*/,
    const OdGiEdgeData* /*pEdgeData */= 0,
    const OdGiFaceData* /*pFaceData */= 0,
    const OdGiVertexData* /*pVertexData */= 0,
    const bool = true) const {return ::kFalse;}

  OdBool shell(const OdUInt32 /*numVertices*/,
    const OdGePoint3d* /*vertexList*/,
    const OdUInt32 /*faceListSize*/,
    const OdInt32* /*faceList*/,
    const OdGiEdgeData* /*pEdgeData */= 0,
    const OdGiFaceData* /*pFaceData */= 0,
    const OdGiVertexData* /*pVertexData */= 0,
    const struct resbuf* = NULL,
    const bool = true) const {return ::kFalse;}

  OdBool worldLine(const OdGePoint3d /*points*/[2]) {return ::kFalse;}

  OdBool polypoint(OdInt32 /*numPoints*/, const OdGePoint3d* /*vertexList*/, const OdCmEntityColor* /*pColors*/, const OdCmTransparency* /*pTransparency*/,
                 const OdGeVector3d* /*pNormals*/, const OdGsMarker* /*pSubEntMarkers*/, OdInt32 /*nPointSize*/) {return ::kFalse;}

  void setExtents(OdGePoint3d * /*newExtents*/) const {}

  OdBool pushClipBoundary(OdGiClipBoundary* /*pBoundary*/) {return ::kFalse;}
  void popClipBoundary() {}
  OdBool draw(OdGiDrawable* /*pDrawable*/) const {return ::kFalse;}

  OdBool pushModelTransform(const OdGeMatrix3d& /*xMat*/) { return ::kFalse;}

  OdBool pushModelTransform(const OdGeVector3d& /*normal*/) {return ::kFalse; }

  OdBool popModelTransform() {return ::kFalse; }

  OdGeMatrix3d getModelToWorldTransform() const { return OdGeMatrix3d::kIdentity; }

  OdGeMatrix3d getWorldToModelTransform() const { return OdGeMatrix3d::kIdentity; }

  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  void getModelToWorldTransform(OdGeMatrix3d& mat) const { mat = OdGeMatrix3d::kIdentity; }
  void getWorldToModelTransform(OdGeMatrix3d& mat) const { mat = OdGeMatrix3d::kIdentity; }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyWorldGeometry : public OdGiDummyGeometry< T >
{
public:
  virtual void setExtents(
    const OdGePoint3d * /*newExtents*/) { }

  virtual void startAttributesSegment() {}
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyViewportGeometry : public OdGiDummyGeometry< T >
{
public:
  virtual void polylineEye(
    OdUInt32 , 
    const OdGePoint3d* ) { }

  virtual void polygonEye(
    OdUInt32 , 
    const OdGePoint3d* ) {  }

  virtual void polylineDc(
    OdUInt32 , 
    const OdGePoint3d* ) {  }

  virtual void polygonDc(
    OdUInt32 , 
    const OdGePoint3d* ) {  }

  virtual void rasterImageDc(
    const OdGePoint3d& ,
    const OdGeVector3d& ,
    const OdGeVector3d& ,
    const OdGiRasterImage* , 
    const OdGePoint2d* , 
    OdUInt32 ,
    bool  = false,
    double  = 50.0,
    double  = 50.0,
    double  = 0.0) {  }

  virtual void  metafileDc(
    const OdGePoint3d& ,
    const OdGeVector3d& ,
    const OdGeVector3d& ,
    const OdGiMetafile* ,
    bool  = true,
    bool  = false) {  }

  virtual void ownerDrawDc(
    const OdGePoint3d& ,
    const OdGeVector3d& ,
    const OdGeVector3d& ,
    const OdGiSelfGdiDrawable* ,
    bool  = true,
    bool  = false) {  }
};

// OdGiSubEntityTraits dummy template

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummySubEntityTraits : public T
{
public:
  void setColor(const OdUInt16 ) { }
  void setTrueColor(const OdCmEntityColor& ) { }
  void setLayer(OdDbStub* ) { }
  void setLineType(OdDbStub* ) { }
  void setSelectionMarker(const OdGsMarker ) { }
  void setFillType(const OdGiFillType ) { }
  void setFillPlane(const OdGeVector3d* = 0) {}
  void setLineWeight(const OdDb::LineWeight ) { }
  void setLineTypeScale(double  = 1.0) { }
  void setLineTypeScaleToFit(bool ) { }
  void setThickness(double ) { }
  void setPlotStyleName(OdDb::PlotStyleNameType, OdDbStub* = 0) { }
  void setMaterial(OdDbStub* ) { }
  void setMapper(const OdGiMapper * /*pMapper*/) { }
  void setVisualStyle(const OdDbStub* /*visualStyleId*/) { }
  void setTransparency(const OdCmTransparency& /*transparency*/) { }
  void setDrawFlags(OdUInt32 /*drawFlags*/) { }
  void setSelectionGeom(bool /*bSelectionFlag*/) { }
  void setShadowFlags(OdGiSubEntityTraits::ShadowFlags /*shadowFlags*/) { }
  void setSectionable(bool /*bSectionableFlag*/) { }
  void setSelectionFlags(OdGiSubEntityTraits::SelectionFlags /*selectionFlags*/) { }

  OdUInt16 color() const { return 0; }
  OdCmEntityColor trueColor() const { return OdCmEntityColor(); }
  OdDbStub* layer() const { return NULL; }
  OdDbStub* lineType() const { return NULL; }
  OdGiFillType fillType() const { return kOdGiFillNever; }
  bool fillPlane(OdGeVector3d& /*normal*/) { return false; }
  OdDb::LineWeight lineWeight() const { return OdDb::kLnWt000; }
  double lineTypeScale() const { return 0.0; }
  double thickness() const { return 0.0; }
  OdDb::PlotStyleNameType plotStyleNameType() const { return OdDb::kPlotStyleNameByBlock; }
  OdDbStub* plotStyleNameId() const { return NULL; }
  OdDbStub* material() const { return NULL; }
  const OdGiMapper* mapper() const { return NULL; }
  void addLight(const OdDbStub* /*lightId*/) { }
  OdCmTransparency transparency() const { return OdCmTransparency(); }
  OdUInt32 drawFlags() const { return 0; }
  bool selectionGeom() const { return false; }
  OdGiSubEntityTraits::ShadowFlags shadowFlags() const { return OdGiSubEntityTraits::kShadowsCastAndReceive; }
  bool sectionable() const { return false; }
  OdGiSubEntityTraits::SelectionFlags selectionFlags() const { return OdGiSubEntityTraits::kNoSelectionFlags; }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T> class OdGiDummyCommonDraw : public T
{
public:
  virtual OdGiRegenType regenType() const              { return kOdGiStandardDisplay; } // dont change from kOdGiStandardDisplay
  virtual OdBool regenAbort() const                    { return kFalse; }
  virtual OdBool isDragging() const                    { return kFalse; }
  virtual OdUInt32 numberOfIsolines() const { return 4; }
  virtual double deviation(const OdGiDeviationType t, const OdGePoint3d& p) const { return 0.; }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyViewportDraw : public OdGiDummyCommonDraw< T >
{
public:
  virtual OdUInt32 sequenceNumber() const  { return 0; }
  virtual bool isValidId(const OdUInt32 viewportId) const { return false; }
  virtual OdDbStub* viewportObjectId() const { return (OdDbStub*)1; } // something non NULL
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyWorldDraw : public OdGiDummyCommonDraw< T >
{
public:
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyContext : public T
{
public:
  virtual OdDbDatabase* database() const { return 0;}
  virtual OdGiDrawablePtr openDrawable(OdDbStub* ) { return OdGiDrawablePtr(); }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template <class T> class OdGiDummyViewport : public T
{
public:
  virtual OdGeMatrix3d getModelToEyeTransform() const { return OdGeMatrix3d::kIdentity; }
  virtual OdGeMatrix3d getEyeToModelTransform() const { return OdGeMatrix3d::kIdentity; }
  virtual OdGeMatrix3d getWorldToEyeTransform() const { return OdGeMatrix3d::kIdentity; }
  virtual OdGeMatrix3d getEyeToWorldTransform() const { return OdGeMatrix3d::kIdentity; }
  virtual bool isPerspective() const { return false; }
  virtual bool doPerspective(OdGePoint3d& p) const { return false; }
  virtual bool doInversePerspective(OdGePoint3d&) const  { return false; }
  virtual void getNumPixelsInUnitSquare(const OdGePoint3d& givenWorldpt, OdGePoint2d& pixelArea) const {  }
  virtual OdGePoint3d getCameraLocation() const { return OdGePoint3d::kOrigin; }
  virtual OdGePoint3d getCameraTarget() const { return OdGePoint3d(0.,0.,1.); }
  virtual OdGeVector3d getCameraUpVector() const { return OdGeVector3d::kYAxis; }
  virtual OdGeVector3d viewDir() const { return getCameraTarget() - getCameraLocation();  }
  virtual OdUInt32 viewportId() const { return 0; }
  virtual OdInt16  acadWindowId() const { return 0; }
  virtual void getViewportDcCorners(OdGePoint2d& lower_left, OdGePoint2d& upper_right) const { lower_left.set(0,0); upper_right.set(100,100); }
  virtual bool getFrontAndBackClipValues(bool& clip_front, bool& clip_back, double& front, double& back) const { clip_front = clip_back = false; return false; }
  virtual double linetypeScaleMultiplier() const { return 1.; }
  virtual double linetypeGenerationCriteria() const { return 1.; }
  virtual bool layerVisible(OdDbStub* idLayer) const { return true; }
  //DD2ARX - xi hui - 08-07-09 - OdGiViewport::ModifyInterface
  virtual void getModelToEyeTransform(OdGeMatrix3d& trans) const { trans = OdGeMatrix3d::kIdentity; }
  virtual void getEyeToModelTransform(OdGeMatrix3d& trans) const { trans = OdGeMatrix3d::kIdentity; }
  virtual void getWorldToEyeTransform(OdGeMatrix3d& trans) const { trans = OdGeMatrix3d::kIdentity; }
  virtual void getEyeToWorldTransform(OdGeMatrix3d& trans) const { trans = OdGeMatrix3d::kIdentity; }
  virtual void getCameraLocation(OdGePoint3d& unnamed) const { unnamed = OdGePoint3d::kOrigin; }
  virtual void getCameraTarget(OdGePoint3d& unnamed) const { unnamed = OdGePoint3d::kOrigin + OdGeVector3d::kZAxis; }
  virtual void getCameraUpVector(OdGeVector3d& unnamed) const { unnamed = OdGeVector3d::kYAxis; }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
class OdGiViewportDraw_Dummy : public OdGiDummySubEntityTraits< OdGiSubEntityTraits >
                             , public OdGiDummyViewportDraw< OdGiViewportDraw >
                             , public OdGiDummyViewportGeometry< OdGiViewportGeometry >
                             , public OdGiDummyContext< OdGiContext >
                             , public OdGiDummyViewport< OdGiViewport >
{
  OdDbDatabase *m_pDb;
public:
  ODRX_USING_HEAP_OPERATORS( OdGiDummySubEntityTraits< OdGiSubEntityTraits > );

  OdGiViewportDraw_Dummy(OdDbDatabase *pDb = 0) : m_pDb(pDb) { }
  virtual OdDbDatabase* database() const { return m_pDb; }

  virtual OdGiGeometry* rawGeometry() const   { return static_cast<OdGiGeometry*>(const_cast<OdGiViewportDraw_Dummy*>(this)); }
  virtual OdGiSubEntityTraits& subEntityTraits() const { return *static_cast<OdGiSubEntityTraits*>(const_cast<OdGiViewportDraw_Dummy*>(this)); }
  virtual OdGiViewport& viewport() const { return *static_cast<OdGiViewport*>(const_cast<OdGiViewportDraw_Dummy*>(this)); }
  virtual OdGiViewportGeometry& geometry() const  { return *static_cast<OdGiViewportGeometry*>(const_cast<OdGiViewportDraw_Dummy*>(this)); }
  virtual OdGiContext* context() const            { return static_cast<OdGiContext*>(const_cast<OdGiViewportDraw_Dummy*>(this)); }

  void addRef() { }
  void release() { }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
class OdGiWorldDraw_Dummy : public OdGiDummySubEntityTraits< OdGiSubEntityTraits >
  , public OdGiDummyWorldDraw< OdGiWorldDraw >
  , public OdGiDummyWorldGeometry< OdGiWorldGeometry >
  , public OdGiDummyContext< OdGiContext >
{
  OdDbDatabase *m_pDb;
public:
  ODRX_USING_HEAP_OPERATORS( OdGiDummySubEntityTraits< OdGiSubEntityTraits > );

  OdGiWorldDraw_Dummy(OdDbDatabase *pDb = 0) : m_pDb(pDb) { }
  virtual OdDbDatabase* database() const { return m_pDb; }

  virtual OdGiGeometry* rawGeometry() const   { return static_cast<OdGiGeometry*>(const_cast<OdGiWorldDraw_Dummy*>(this)); }
  virtual OdGiSubEntityTraits& subEntityTraits() const { return *static_cast<OdGiSubEntityTraits*>(const_cast<OdGiWorldDraw_Dummy*>(this)); }
  virtual OdGiWorldGeometry& geometry() const  { return *static_cast<OdGiWorldGeometry*>(const_cast<OdGiWorldDraw_Dummy*>(this)); }
  virtual OdGiContext* context() const            { return static_cast<OdGiContext*>(const_cast<OdGiWorldDraw_Dummy*>(this)); }

  void addRef() { }
  void release() { }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T, class DRAW, class WR, class WRA> class OdGeomGrabber : public T
{
  OdGsMarker m_curSelMarker;
  WRA &wires;

  OdGeomGrabber();
public:

  OdGeomGrabber(WRA &pW, DRAW &pVd)
    : T(pVd, pVd.geometry(), pVd.subEntityTraits())
    , m_curSelMarker(0)
    , wires(pW)
  { }

  virtual void setSelectionMarker(const OdGsMarker n) { m_curSelMarker = n; T::setSelectionMarker(n); }

  virtual WR *appendWire() const
  {
    WR *pWire = wires.append();
    pWire->selMarker = -getFaceIndex(m_curSelMarker);
    pWire->color = T::subEntityTraits().trueColor();
    return pWire;
  }

  virtual OdBool circle(const OdGePoint3d& center, const double radius, const OdGeVector3d& normal) const
  {
    appendWire()->circle(center, radius, normal);
    return T::circle(center, radius, normal);
  }

  virtual OdBool circle(const OdGePoint3d& p1, const OdGePoint3d& p2, const OdGePoint3d& p3) const
  {
    appendWire()->circle(p1, p2, p3);
    return T::circle(p1, p2, p3);
  }

  virtual OdBool circularArc(const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple)const
  {
    appendWire()->circularArc(center, radius, normal, startVector, sweepAngle);
    return T::circularArc(center, radius, normal, startVector, sweepAngle, arcType);
  }

  virtual OdBool circularArc(const OdGePoint3d& start,
    const OdGePoint3d& point,
    const OdGePoint3d& end,
    const OdGiArcType arcType = kOdGiArcSimple) const
  {
    appendWire()->circularArc(start, point, end);
    return T::circularArc(start, point, end, arcType);
  }

  virtual OdBool polyline(const OdUInt32 nbPoints,
    const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = NULL,
    OdLongPtr lBaseSubEntMarker = -1) const
  {
    appendWire()->polyline(nbPoints, pVertexList);
    return T::polyline(nbPoints, pVertexList, pNormal, lBaseSubEntMarker);
  }
};

/** Description:

Library: TD_Gi
{group:OdGi_Classes}
*/
template<class T, class DRAW, class WR, class WRA> class OdShellGrabber : public T
{
  OdGsMarker m_curSelMarker;
  WRA &wires;

  OdShellGrabber();
public:

  OdShellGrabber(WRA &pW, DRAW &pVd) : T(pVd, pVd.geometry(), pVd.subEntityTraits())
    , m_curSelMarker(0)
    , wires(pW)
  { }

  virtual OdGiRegenType regenType() const              { return kOdGiHideOrShadeCommand; }

  virtual void setSelectionMarker(OdGsMarker n) { m_curSelMarker = n; T::setSelectionMarker(n); }

  virtual void shell(
    const OdInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) const 
  {
    WR *pWire = wires.append();
    pWire->selMarker = m_curSelMarker;
    pWire->color = T::subEntityTraits().trueColor();
    pWire->shell(
      numVertices,
      vertexList,
      faceListSize,
      faceList,
      pEdgeData,
      pFaceData,
      pVertexData);

    T::shell(
      numVertices,
      vertexList,
      faceListSize,
      faceList,
      pEdgeData,
      pFaceData,
      pVertexData);
  }
};

typedef  OdStaticRxObject< OdGiDummySubEntityTraits< OdGiSubEntityTraits > > OdGiSubEntityTraits_Stub;

#include "TD_PackPop.h"

#endif // #ifndef _ODGIDUMMYGEOM_INCLUDED_
