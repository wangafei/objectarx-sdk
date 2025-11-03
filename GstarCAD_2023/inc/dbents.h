/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBENTS_H
#define GD_DBENTS_H

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "dbmtext.h"
#include "dbBackground.h"
#include "dbdim.h"
#include "gept2dar.h"
#include "gedblar.h"
#include "dbsymtb.h"
#include "gemat3d.h"
#include "gcdbxref.h"
#include "gcgi.h"
#include "gcgiviewport.h"
#include "gcgivisualstyle.h"

#pragma pack(push, 8)

class GcDbAttribute;
class GcDbSequenceEnd;
class GcDb3dPolylineVertex;
class GcDb2dVertex;
class GcDbMText;
class GcDbAnnotationScale;

namespace Gtil
{
  class Image;
}

class GCDB_PORT GcDbText : public GcDbEntity
{
public:
  GcDbText();
  GcDbText(
    const GcGePoint3d&  position,
    const GCHAR*        text,
    GcDbObjectId        style = GcDbObjectId::kNull,
    double              height = 0,
    double              rotation = 0);
  ~GcDbText();
  GCDB_DECLARE_MEMBERS(GcDbText);

  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
  GcGePoint3d         alignmentPoint() const;
  Gcad::ErrorStatus   setAlignmentPoint(const GcGePoint3d&);
  Gsoft::Boolean      isDefaultAlignment() const;
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  Gsoft::Boolean      isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus   getPlane(GcGePlane&, GcDb::Planarity&) const override;
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  double              oblique() const;
  Gcad::ErrorStatus   setOblique(double);
  double              rotation() const;
  Gcad::ErrorStatus   setRotation(double);
  double              height() const;
  Gcad::ErrorStatus   setHeight(double);
  double              widthFactor() const;
  Gcad::ErrorStatus   setWidthFactor(double);
  Gcad::ErrorStatus   textString(GcString & sText) const;
  GCHAR*              textString() const;
  const GCHAR*        textStringConst() const;
  Gcad::ErrorStatus   setTextString(const GCHAR*);
  GcDbObjectId        textStyle() const;
  Gcad::ErrorStatus   setTextStyle(GcDbObjectId);
  Gsoft::Boolean      isMirroredInX() const;
  Gcad::ErrorStatus   mirrorInX(Gsoft::Boolean);
  Gsoft::Boolean      isMirroredInY() const;
  Gcad::ErrorStatus   mirrorInY(Gsoft::Boolean);
  GcDb::TextHorzMode  horizontalMode() const;
  Gcad::ErrorStatus   setHorizontalMode(GcDb::TextHorzMode);
  GcDb::TextVertMode  verticalMode() const;
  Gcad::ErrorStatus   setVerticalMode(GcDb::TextVertMode);
  int                 correctSpelling();
  virtual Gcad::ErrorStatus   adjustAlignment(const GcDbDatabase* pDb = nullptr);
  Gcad::ErrorStatus   setField(const GCHAR* pszPropName, GcDbField* pField, GcDbObjectId& fieldId) override;
  Gcad::ErrorStatus   removeField(GcDbObjectId fieldId) override;
  Gcad::ErrorStatus   removeField(const GCHAR* pszPropName, GcDbObjectId& returnId) override;
  Gcad::ErrorStatus   removeField(const GCHAR* pszPropName) override;
  Gcad::ErrorStatus   convertFieldToText();

  enum GcTextAlignment
  {
    kTextAlignmentLeft = 0,
    kTextAlignmentCenter = (kTextAlignmentLeft + 1),
    kTextAlignmentRight = (kTextAlignmentCenter + 1),
    kTextAlignmentAligned = (kTextAlignmentRight + 1),
    kTextAlignmentMiddle = (kTextAlignmentAligned + 1),
    kTextAlignmentFit = (kTextAlignmentMiddle + 1),
    kTextAlignmentTopLeft = (kTextAlignmentFit + 1),
    kTextAlignmentTopCenter = (kTextAlignmentTopLeft + 1),
    kTextAlignmentTopRight = (kTextAlignmentTopCenter + 1),
    kTextAlignmentMiddleLeft = (kTextAlignmentTopRight + 1),
    kTextAlignmentMiddleCenter = (kTextAlignmentMiddleLeft + 1),
    kTextAlignmentMiddleRight = (kTextAlignmentMiddleCenter + 1),
    kTextAlignmentBottomLeft = (kTextAlignmentMiddleRight + 1),
    kTextAlignmentBottomCenter = (kTextAlignmentBottomLeft + 1),
    kTextAlignmentBottomRight = (kTextAlignmentBottomCenter + 1)
  };

  GcTextAlignment              justification() const;
  Gcad::ErrorStatus            setJustification(GcTextAlignment);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline GCHAR * GcDbText::textString() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbText::textString);
}

class GCDB_PORT GcDbAttributeDefinition : public GcDbText
{
public:
  GcDbAttributeDefinition();
  GcDbAttributeDefinition(
    const GcGePoint3d& position,
    const GCHAR*       text,
    const GCHAR*       tag,
    const GCHAR*       prompt,
    GcDbObjectId       style = GcDbObjectId::kNull);
  ~GcDbAttributeDefinition();
  GCDB_DECLARE_MEMBERS(GcDbAttributeDefinition);

  Gcad::ErrorStatus   prompt(GcString & sTag) const;
  GCHAR*              prompt() const;
  const GCHAR*        promptConst() const;
  Gcad::ErrorStatus   setPrompt(const GCHAR*);
  Gcad::ErrorStatus   tag(GcString & sTag) const;
  GCHAR*              tag() const;
  const GCHAR*        tagConst() const;
  Gcad::ErrorStatus   setTag(const GCHAR*);
  Gsoft::Boolean      isInvisible() const;
  Gcad::ErrorStatus   setInvisible(Gsoft::Boolean);
  Gsoft::Boolean      isConstant() const;
  Gcad::ErrorStatus   setConstant(Gsoft::Boolean);
  Gsoft::Boolean      isVerifiable() const;
  Gcad::ErrorStatus   setVerifiable(Gsoft::Boolean);
  Gsoft::Boolean      isPreset() const;
  Gcad::ErrorStatus   setPreset(Gsoft::Boolean);
  Gsoft::UInt16       fieldLength() const;
  Gcad::ErrorStatus   setFieldLength(Gsoft::UInt16);
  Gcad::ErrorStatus   adjustAlignment(const GcDbDatabase* pDb = nullptr) override;

  bool lockPositionInBlock() const;
  Gcad::ErrorStatus setLockPositionInBlock(bool bValue);
  bool              isMTextAttributeDefinition() const;
  GcDbMText *       getMTextAttributeDefinition() const;
  const GcDbMText * getMTextAttributeDefinitionConst() const;
  Gcad::ErrorStatus setMTextAttributeDefinition(GcDbMText*);
  Gcad::ErrorStatus setMTextAttributeDefinitionConst(const GcDbMText*);
  Gcad::ErrorStatus convertIntoMTextAttributeDefinition(Gsoft::Boolean val = Gsoft::kTrue);
  Gcad::ErrorStatus updateMTextAttributeDefinition();

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline GCHAR * GcDbAttributeDefinition::prompt() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbAttributeDefinition::prompt);
}

inline GCHAR * GcDbAttributeDefinition::tag() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbAttributeDefinition::tag);
}

class GCDB_PORT GcDbAttribute : public GcDbText
{
public:
  GcDbAttribute();
  GcDbAttribute(
    const GcGePoint3d& position,
    const GCHAR*       text,
    const GCHAR*       tag,
    GcDbObjectId       style = GcDbObjectId::kNull);
  ~GcDbAttribute();
  GCDB_DECLARE_MEMBERS(GcDbAttribute);

  Gcad::ErrorStatus   tag(GcString & sTag) const;
  GCHAR*              tag() const;
  const GCHAR*        tagConst() const;
  Gcad::ErrorStatus   setTag(const GCHAR* newTag);
  Gsoft::Boolean      isInvisible() const;
  Gcad::ErrorStatus   setInvisible(Gsoft::Boolean);
  Gsoft::Boolean      isConstant() const;
  Gsoft::Boolean      isVerifiable() const;
  Gsoft::Boolean      isPreset() const;
  Gsoft::UInt16       fieldLength() const;
  Gcad::ErrorStatus   setFieldLength(Gsoft::UInt16);
  Gcad::ErrorStatus setAttributeFromBlock(const GcGeMatrix3d& blkXform);
  Gcad::ErrorStatus setAttributeFromBlock(
    const GcDbAttributeDefinition *pAttdef,
    const GcGeMatrix3d& blkXform);

  bool lockPositionInBlock() const;
  Gcad::ErrorStatus setLockPositionInBlock(bool bValue);
  bool              isMTextAttribute()                        const;
  GcDbMText *       getMTextAttribute()                        const;
  const GcDbMText * getMTextAttributeConst()                        const;
  Gcad::ErrorStatus setMTextAttribute(GcDbMText *);
  Gcad::ErrorStatus setMTextAttributeConst(const GcDbMText *);
  Gcad::ErrorStatus convertIntoMTextAttribute(Gsoft::Boolean val = Gsoft::kTrue);
  Gcad::ErrorStatus updateMTextAttribute();
  bool              isReallyLocked()                        const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline GCHAR * GcDbAttribute::tag() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbAttribute::tag);
}

class GCDB_PORT GcDbBlockReference : public GcDbEntity
{
public:
  GcDbBlockReference();
  GcDbBlockReference(const GcGePoint3d&  position,
    GcDbObjectId  blockTableRec);
  ~GcDbBlockReference();
  GCDB_DECLARE_MEMBERS(GcDbBlockReference);

  GcDbObjectId      blockTableRecord() const;
  virtual Gcad::ErrorStatus setBlockTableRecord(GcDbObjectId);
  virtual GcGePoint3d       position() const;
  virtual Gcad::ErrorStatus setPosition(const GcGePoint3d&);
  GcGeScale3d       scaleFactors() const;
  GcGeScale3d       nonAnnotationScaleFactors() const;
  virtual Gcad::ErrorStatus setScaleFactors(const GcGeScale3d& scale);
  double            rotation() const;
  virtual Gcad::ErrorStatus setRotation(double newVal);
  GcGeVector3d      normal() const;
  virtual Gcad::ErrorStatus setNormal(const GcGeVector3d& newVal);
  Gsoft::Boolean    isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus getPlane(GcGePlane&, GcDb::Planarity&) const override;
  GcGeMatrix3d      blockTransform() const;
  GcGeMatrix3d      nonAnnotationBlockTransform() const;
  virtual Gcad::ErrorStatus setBlockTransform(const GcGeMatrix3d&);
  Gcad::ErrorStatus appendAttribute(GcDbAttribute*);
  Gcad::ErrorStatus appendAttribute(GcDbObjectId&, GcDbAttribute*);
  Gcad::ErrorStatus openAttribute(GcDbAttribute*&, GcDbObjectId,
    GcDb::OpenMode,
    bool openErasedOne = false);
  Gcad::ErrorStatus openSequenceEnd(GcDbSequenceEnd*&, GcDb::OpenMode);
  GcDbObjectIterator*  attributeIterator() const;
  virtual Gsoft::Boolean    treatAsGcDbBlockRefForExplode() const;
  Gcad::ErrorStatus geomExtentsBestFit(
    GcDbExtents& extents,
    const GcGeMatrix3d& parentXform = GcGeMatrix3d::kIdentity) const;
  virtual Gcad::ErrorStatus explodeToOwnerSpace() const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbMInsertBlock : public GcDbBlockReference
{
public:
  GcDbMInsertBlock();
  GcDbMInsertBlock(
    const GcGePoint3d&  position,
    GcDbObjectId        blockTableRec,
    Gsoft::UInt16       columns,
    Gsoft::UInt16       rows,
    double              colSpacing,
    double              rowSpacing);
  ~GcDbMInsertBlock();
  GCDB_DECLARE_MEMBERS(GcDbMInsertBlock);

  Gsoft::UInt16      columns() const;
  Gcad::ErrorStatus  setColumns(Gsoft::UInt16);
  Gsoft::UInt16      rows() const;
  Gcad::ErrorStatus  setRows(Gsoft::UInt16);
  double             columnSpacing() const;
  Gcad::ErrorStatus  setColumnSpacing(double);
  double             rowSpacing() const;
  Gcad::ErrorStatus  setRowSpacing(double);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbBlockBegin : public GcDbEntity
{
public:
  GcDbBlockBegin();
  ~GcDbBlockBegin();
  GCDB_DECLARE_MEMBERS(GcDbBlockBegin);

};

class GCDB_PORT GcDbBlockEnd : public GcDbEntity
{
public:
  GcDbBlockEnd();
  ~GcDbBlockEnd();
  GCDB_DECLARE_MEMBERS(GcDbBlockEnd);
};

class GCDB_PORT GcDbSequenceEnd : public GcDbEntity
{
public:
  GcDbSequenceEnd();
  ~GcDbSequenceEnd();
  GCDB_DECLARE_MEMBERS(GcDbSequenceEnd);
};

class GCDB_PORT GcDbVertex : public GcDbEntity
{
public:
  GcDbVertex();
  ~GcDbVertex();
  GCDB_DECLARE_MEMBERS(GcDbVertex);
};

inline GcDbVertex::~GcDbVertex()
{
}

class GCDB_PORT GcDb2dVertex : public GcDbVertex
{
public:
  GcDb2dVertex();
  ~GcDb2dVertex();
  GCDB_DECLARE_MEMBERS(GcDb2dVertex);
  GcDb2dVertex(
    const GcGePoint3d&  position,
    double   bulge = 0,
    double   startWidth = 0,
    double   endWidth = 0,
    double   tangent = 0,
    Gsoft::Int32 vertexIdentifier = 0);

  GcDb::Vertex2dType  vertexType() const;
  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
  double              startWidth() const;
  Gcad::ErrorStatus   setStartWidth(double newVal);
  double              endWidth() const;
  Gcad::ErrorStatus   setEndWidth(double newVal);
  double              bulge() const;
  Gcad::ErrorStatus   setBulge(double newVal);
  Gsoft::Boolean      isTangentUsed() const;
  Gcad::ErrorStatus   useTangent();
  Gcad::ErrorStatus   ignoreTangent();
  Gcad::ErrorStatus   setTangentUsed(Gsoft::Boolean);
  double              tangent() const;
  Gcad::ErrorStatus   setTangent(double newVal);
  Gcad::ErrorStatus   setVertexIdentifier(Gsoft::Int32 suggestedValue);
  int                 vertexIdentifier() const;
};

class GCDB_PORT GcDb3dPolylineVertex : public GcDbVertex
{
public:
  GcDb3dPolylineVertex();
  ~GcDb3dPolylineVertex();
  GCDB_DECLARE_MEMBERS(GcDb3dPolylineVertex);
  GcDb3dPolylineVertex(const GcGePoint3d&);

  GcDb::Vertex3dType  vertexType() const;
  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
};

class GCDB_PORT GcDbPolygonMeshVertex : public GcDbVertex
{
public:
  GcDbPolygonMeshVertex();
  GcDbPolygonMeshVertex(const GcGePoint3d&  position);
  ~GcDbPolygonMeshVertex();
  GCDB_DECLARE_MEMBERS(GcDbPolygonMeshVertex);

  GcDb::Vertex3dType  vertexType() const;
  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
};

class GCDB_PORT GcDbPolyFaceMeshVertex : public GcDbVertex
{
public:
  GcDbPolyFaceMeshVertex();
  GcDbPolyFaceMeshVertex(const GcGePoint3d&  position);
  ~GcDbPolyFaceMeshVertex();
  GCDB_DECLARE_MEMBERS(GcDbPolyFaceMeshVertex);

  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
};

class GCDB_PORT GcDbFaceRecord : public GcDbVertex
{
public:
  GcDbFaceRecord();
  GcDbFaceRecord(Gsoft::Int16 vtx0, Gsoft::Int16 vtx1,
    Gsoft::Int16 vtx2, Gsoft::Int16 vtx3);
  ~GcDbFaceRecord();
  GCDB_DECLARE_MEMBERS(GcDbFaceRecord);

  Gcad::ErrorStatus getVertexAt(Gsoft::UInt16 faceIdx,
    Gsoft::Int16& vtxIdx) const;
  Gcad::ErrorStatus setVertexAt(Gsoft::UInt16 faceIdx,
    Gsoft::Int16  vtxIdx);
  Gcad::ErrorStatus isEdgeVisibleAt(Gsoft::UInt16 faceIndex,
    Gsoft::Boolean& visible) const;
  Gcad::ErrorStatus makeEdgeVisibleAt(Gsoft::UInt16 faceIndex);
  Gcad::ErrorStatus makeEdgeInvisibleAt(Gsoft::UInt16 faceIndex);
};

class GCDB_PORT GcDb2dPolyline : public GcDbCurve
{
public:
  GcDb2dPolyline();
  ~GcDb2dPolyline();
  GCDB_DECLARE_MEMBERS(GcDb2dPolyline);
  GcDb2dPolyline(
    GcDb::Poly2dType  type,
    GcGePoint3dArray& vertices,
    double            elevation = 0,
    Gsoft::Boolean    closed = Gsoft::kFalse,
    double            defStartWidth = 0,
    double            defEndWidth = 0,
    GcGeDoubleArray*  bulges = nullptr,
    GcArray<Gsoft::Int32>* vertexIdentifiers = nullptr
  );

  DBCURVE_METHODS

    GcDb::Poly2dType    polyType() const;
  Gcad::ErrorStatus   setPolyType(GcDb::Poly2dType);
  Gcad::ErrorStatus   convertToPolyType(GcDb::Poly2dType newVal);
  Gcad::ErrorStatus   makeClosed();
  Gcad::ErrorStatus   makeOpen();
  Gcad::ErrorStatus   setClosed(Gsoft::Boolean);
  Gcad::ErrorStatus   constantWidth(double&) const;
  Gcad::ErrorStatus   setConstantWidth(double);
  Gcad::ErrorStatus   length(double &) const;
  double              defaultStartWidth() const;
  Gcad::ErrorStatus   setDefaultStartWidth(double);
  double              defaultEndWidth() const;
  Gcad::ErrorStatus   setDefaultEndWidth(double);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  double              elevation() const;
  Gcad::ErrorStatus   setElevation(double);
  Gsoft::Boolean      isLinetypeGenerationOn() const;
  Gcad::ErrorStatus   setLinetypeGenerationOn();
  Gcad::ErrorStatus   setLinetypeGenerationOff();
  Gcad::ErrorStatus   setLinetypeGenerationOn(Gsoft::Boolean bOn);
  Gcad::ErrorStatus   straighten();
  Gcad::ErrorStatus   splineFit();
  Gcad::ErrorStatus   splineFit(GcDb::Poly2dType splineType,
    Gsoft::Int16   splineSegs);
  Gcad::ErrorStatus   curveFit();

  Gcad::ErrorStatus appendVertex(GcDb2dVertex*);
  Gcad::ErrorStatus appendVertex(GcDbObjectId& objId, GcDb2dVertex*);
  Gcad::ErrorStatus insertVertexAt(const GcDb2dVertex* pIndexVert,
    GcDb2dVertex* pNewVertex);
  Gcad::ErrorStatus insertVertexAt(GcDbObjectId& newVertId,
    const GcDbObjectId& indexVertId, GcDb2dVertex* pNewVertex);
  Gcad::ErrorStatus openVertex(GcDb2dVertex*&, GcDbObjectId    vertId,
    GcDb::OpenMode,
    bool openErasedOne = false) const;
  Gcad::ErrorStatus openSequenceEnd(GcDbSequenceEnd*&, GcDb::OpenMode);
  GcDbObjectIterator*  vertexIterator() const;
  GcGePoint3d       vertexPosition(const GcDb2dVertex& vert) const;
  Gcad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDb2dPolyline::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDb2dPolyline::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDb2dPolyline::getStartParam(double& param) const
{
  param = 0.0;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDb2dPolyline::extend(double param)
{
  param;
  return Gcad::eNotApplicable;
}

class GCDB_PORT GcDb3dPolyline : public GcDbCurve
{
public:
  GcDb3dPolyline();
  ~GcDb3dPolyline();
  GCDB_DECLARE_MEMBERS(GcDb3dPolyline);
  GcDb3dPolyline(GcDb::Poly3dType, GcGePoint3dArray& vertices,
    Gsoft::Boolean closed = Gsoft::kFalse);

  DBCURVE_METHODS

    Gcad::ErrorStatus     length(double &) const;
  Gcad::ErrorStatus     setClosed(Gsoft::Boolean);
  Gcad::ErrorStatus               makeClosed();
  Gcad::ErrorStatus               makeOpen();

  GcDb::Poly3dType    polyType() const;
  Gcad::ErrorStatus   setPolyType(GcDb::Poly3dType);
  Gcad::ErrorStatus   convertToPolyType(GcDb::Poly3dType newVal);
  Gcad::ErrorStatus   straighten();
  Gcad::ErrorStatus   splineFit();
  Gcad::ErrorStatus   splineFit(GcDb::Poly3dType splineType, Gsoft::Int16   splineSegs);

  Gcad::ErrorStatus appendVertex(GcDb3dPolylineVertex*);
  Gcad::ErrorStatus appendVertex(GcDbObjectId& objId, GcDb3dPolylineVertex*);
  Gcad::ErrorStatus insertVertexAt(const GcDb3dPolylineVertex* pIndexVert,
    GcDb3dPolylineVertex* pNewVertex);
  Gcad::ErrorStatus insertVertexAt(GcDbObjectId& newVertId,
    const GcDbObjectId& indexVertId, GcDb3dPolylineVertex* pNewVertex);
  Gcad::ErrorStatus openVertex(GcDb3dPolylineVertex*&, GcDbObjectId vertId,
    GcDb::OpenMode,
    bool openErasedOne = false);
  Gcad::ErrorStatus openSequenceEnd(GcDbSequenceEnd*&, GcDb::OpenMode);
  GcDbObjectIterator* vertexIterator() const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean    GcDb3dPolyline::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gcad::ErrorStatus GcDb3dPolyline::getStartParam(double& param) const
{
  param = 0.0;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDb3dPolyline::extend(double newparam)
{
  newparam;
  return Gcad::eNotApplicable;
}

class GCDB_PORT GcDbArc : public GcDbCurve
{
public:
  GcDbArc();
  GcDbArc(const GcGePoint3d& center, double radius,
    double startAngle, double endAngle);
  GcDbArc(const GcGePoint3d& center, const GcGeVector3d& normal,
    double radius, double startAngle, double endAngle);
  ~GcDbArc();
  GCDB_DECLARE_MEMBERS(GcDbArc);

  DBCURVE_METHODS

    GcGePoint3d         center() const;
  Gcad::ErrorStatus   setCenter(const GcGePoint3d&);
  double              radius() const;
  Gcad::ErrorStatus   setRadius(double);
  double              startAngle() const;
  Gcad::ErrorStatus   setStartAngle(double);
  double              endAngle() const;
  Gcad::ErrorStatus   setEndAngle(double);

  double    totalAngle() const;
  double    length() const;
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbArc::isClosed() const
{
  return Gsoft::kFalse;
}
inline Gsoft::Boolean GcDbArc::isPeriodic() const
{
  return Gsoft::kFalse;
}
inline Gsoft::Boolean GcDbArc::isPlanar() const
{
  return Gsoft::kTrue;
}

class GCDB_PORT GcDbCircle : public GcDbCurve
{
public:
  GcDbCircle();
  GcDbCircle(const GcGePoint3d& cntr, const GcGeVector3d& nrm, double radius);
  ~GcDbCircle();
  GCDB_DECLARE_MEMBERS(GcDbCircle);

  DBCURVE_METHODS

    GcGePoint3d         center() const;
  Gcad::ErrorStatus   setCenter(const GcGePoint3d&);
  double              radius() const;
  Gcad::ErrorStatus   setRadius(double);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  double              circumference() const;
  Gcad::ErrorStatus   setCircumference(double);
  double              diameter() const;
  Gcad::ErrorStatus   setDiameter(double);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbCircle::isClosed() const
{
  return Gsoft::kTrue;
}

inline Gsoft::Boolean GcDbCircle::isPeriodic() const
{
  return Gsoft::kTrue;
}

inline Gsoft::Boolean GcDbCircle::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbCircle::getStartParam(double& p) const
{
  p = 0.0;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcDbCircle::extend(double)
{
  return Gcad::eNotApplicable;
}

inline Gcad::ErrorStatus GcDbCircle::extend(Gsoft::Boolean, const GcGePoint3d&)
{
  return Gcad::eNotApplicable;
}

class GCDB_PORT GcDbLine : public GcDbCurve
{
public:
  GcDbLine();
  GcDbLine(const GcGePoint3d& start, const GcGePoint3d& end);
  ~GcDbLine();
  GCDB_DECLARE_MEMBERS(GcDbLine);

  DBCURVE_METHODS

    Gcad::ErrorStatus getOffsetCurvesGivenPlaneNormal(
      const GcGeVector3d& normal, double offsetDist,
      GcDbVoidPtrArray& offsetCurves) const override;

  GcGePoint3d         startPoint() const;
  Gcad::ErrorStatus   setStartPoint(const GcGePoint3d&);
  GcGePoint3d         endPoint() const;
  Gcad::ErrorStatus   setEndPoint(const GcGePoint3d&);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gsoft::Boolean GcDbLine::isClosed() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbLine::isPeriodic() const
{
  return Gsoft::kFalse;
}

inline Gsoft::Boolean GcDbLine::isPlanar() const
{
  return Gsoft::kTrue;
}

inline Gcad::ErrorStatus GcDbLine::getStartParam(double& v1) const
{
  v1 = 0.0;
  return Gcad::eOk;
}

class GCDB_PORT GcDbPoint : public GcDbEntity
{
public:
  GcDbPoint();
  GcDbPoint(const GcGePoint3d&   position);
  ~GcDbPoint();
  GCDB_DECLARE_MEMBERS(GcDbPoint);

  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  double              ecsRotation() const;
  Gcad::ErrorStatus   setEcsRotation(double);
  Gsoft::Boolean    isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus getPlane(GcGePlane&, GcDb::Planarity&) const override;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbFace : public GcDbEntity
{
public:
  GcDbFace();
  GcDbFace(const GcGePoint3d&   pt0,
    const GcGePoint3d&   pt1,
    const GcGePoint3d&   pt2,
    const GcGePoint3d&   pt3,
    Gsoft::Boolean e0vis = Gsoft::kTrue,
    Gsoft::Boolean e1vis = Gsoft::kTrue,
    Gsoft::Boolean e2vis = Gsoft::kTrue,
    Gsoft::Boolean e3vis = Gsoft::kTrue);
  GcDbFace(const GcGePoint3d&   pt0,
    const GcGePoint3d&   pt1,
    const GcGePoint3d&   pt2,
    Gsoft::Boolean e0vis = Gsoft::kTrue,
    Gsoft::Boolean e1vis = Gsoft::kTrue,
    Gsoft::Boolean e2vis = Gsoft::kTrue,
    Gsoft::Boolean e3vis = Gsoft::kTrue);
  ~GcDbFace();
  GCDB_DECLARE_MEMBERS(GcDbFace);

  Gcad::ErrorStatus getVertexAt(Gsoft::UInt16, GcGePoint3d&) const;
  Gcad::ErrorStatus setVertexAt(Gsoft::UInt16, const GcGePoint3d&);
  Gcad::ErrorStatus isEdgeVisibleAt(Gsoft::UInt16, Gsoft::Boolean&) const;
  Gcad::ErrorStatus makeEdgeVisibleAt(Gsoft::UInt16);
  Gcad::ErrorStatus makeEdgeInvisibleAt(Gsoft::UInt16);
  Gsoft::Boolean      isPlanar() const override;
  Gcad::ErrorStatus   getPlane(GcGePlane& plane, GcDb::Planarity& planarity) const override;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbPolyFaceMesh : public GcDbEntity
{
public:
  GcDbPolyFaceMesh();
  ~GcDbPolyFaceMesh();
  GCDB_DECLARE_MEMBERS(GcDbPolyFaceMesh);

  Gsoft::Int16 numVertices() const;
  Gsoft::Int16 numFaces() const;
  Gcad::ErrorStatus appendVertex(GcDbPolyFaceMeshVertex*);
  Gcad::ErrorStatus appendVertex(GcDbObjectId& objId, GcDbPolyFaceMeshVertex*);
  Gcad::ErrorStatus appendFaceRecord(GcDbFaceRecord*);
  Gcad::ErrorStatus appendFaceRecord(GcDbObjectId&, GcDbFaceRecord*);
  Gcad::ErrorStatus openVertex(GcDbVertex*&, GcDbObjectId subObjId, GcDb::OpenMode, bool openErasedOne = false);
  Gcad::ErrorStatus openSequenceEnd(GcDbSequenceEnd*&, GcDb::OpenMode);
  GcDbObjectIterator*  vertexIterator() const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbPolygonMesh : public GcDbEntity
{
public:
  GcDbPolygonMesh();
  GcDbPolygonMesh(GcDb::PolyMeshType pType,
    Gsoft::Int16       mSize,
    Gsoft::Int16       nSize,
    const GcGePoint3dArray& vertices,
    Gsoft::Boolean     mClosed = Gsoft::kTrue,
    Gsoft::Boolean     nClosed = Gsoft::kTrue);
  ~GcDbPolygonMesh();
  GCDB_DECLARE_MEMBERS(GcDbPolygonMesh);

  GcDb::PolyMeshType  polyMeshType() const;
  Gcad::ErrorStatus   setPolyMeshType(GcDb::PolyMeshType);
  Gcad::ErrorStatus   convertToPolyMeshType(GcDb::PolyMeshType newVal);
  Gsoft::Int16        mSize() const;
  Gcad::ErrorStatus   setMSize(Gsoft::Int16);
  Gsoft::Int16        nSize() const;
  Gcad::ErrorStatus   setNSize(Gsoft::Int16);
  Gsoft::Boolean      isMClosed() const;
  Gcad::ErrorStatus   makeMClosed();
  Gcad::ErrorStatus   makeMOpen();
  Gsoft::Boolean      isNClosed() const;
  Gcad::ErrorStatus   makeNClosed();
  Gcad::ErrorStatus   makeNOpen();
  Gsoft::Int16        mSurfaceDensity() const;
  Gcad::ErrorStatus   setMSurfaceDensity(Gsoft::Int16);
  Gsoft::Int16        nSurfaceDensity() const;
  Gcad::ErrorStatus   setNSurfaceDensity(Gsoft::Int16);
  Gcad::ErrorStatus   straighten();
  Gcad::ErrorStatus   surfaceFit();
  Gcad::ErrorStatus   surfaceFit(GcDb::PolyMeshType surfType, Gsoft::Int16 surfu, Gsoft::Int16 surfv);
  Gcad::ErrorStatus appendVertex(GcDbPolygonMeshVertex*);
  Gcad::ErrorStatus appendVertex(GcDbObjectId& objId, GcDbPolygonMeshVertex*);
  Gcad::ErrorStatus openVertex(GcDbPolygonMeshVertex*&, GcDbObjectId vertId,
    GcDb::OpenMode,
    bool openErasedOne = false);
  Gcad::ErrorStatus openSequenceEnd(GcDbSequenceEnd*&, GcDb::OpenMode);
  GcDbObjectIterator*  vertexIterator() const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbSolid : public GcDbEntity
{
public:
  GcDbSolid();
  GcDbSolid(const GcGePoint3d&    pt0,
    const GcGePoint3d&    pt1,
    const GcGePoint3d&    pt2,
    const GcGePoint3d&    pt3);
  GcDbSolid(const GcGePoint3d&    pt0,
    const GcGePoint3d&    pt1,
    const GcGePoint3d&    pt2);
  ~GcDbSolid();
  GCDB_DECLARE_MEMBERS(GcDbSolid);

  Gcad::ErrorStatus getPointAt(Gsoft::UInt16 idx, GcGePoint3d& pntRes) const;
  Gcad::ErrorStatus setPointAt(Gsoft::UInt16 idx, const GcGePoint3d&);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  double              elevation() const;
  void                setElevation(double);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbTrace : public GcDbEntity
{
public:
  GcDbTrace();
  GcDbTrace(const GcGePoint3d&    pt0,
    const GcGePoint3d&    pt1,
    const GcGePoint3d&    pt2,
    const GcGePoint3d&    pt3);
  ~GcDbTrace();
  GCDB_DECLARE_MEMBERS(GcDbTrace);

  Gcad::ErrorStatus   getPointAt(Gsoft::UInt16 idx, GcGePoint3d& PntRes) const;
  Gcad::ErrorStatus   setPointAt(Gsoft::UInt16 idx, const GcGePoint3d&);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  double              elevation() const;
  void                setElevation(double);
  Gsoft::Boolean      isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus   getPlane(GcGePlane&, GcDb::Planarity&) const override;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbShape : public GcDbEntity
{
public:
  GcDbShape();
  GcDbShape(const GcGePoint3d&  position,
    double        size,
    double        rotation = 0,
    double        widthFactor = 0);
  ~GcDbShape();
  GCDB_DECLARE_MEMBERS(GcDbShape);

  GcGePoint3d         position() const;
  Gcad::ErrorStatus   setPosition(const GcGePoint3d&);
  double              size() const;
  Gcad::ErrorStatus   setSize(double);
  Gcad::ErrorStatus   name(GcString &sName) const;
  GCHAR*              name() const;
  Gcad::ErrorStatus   setName(const GCHAR*);
  double              rotation() const;
  Gcad::ErrorStatus   setRotation(double);
  double              widthFactor() const;
  Gcad::ErrorStatus   setWidthFactor(double);
  double              oblique() const;
  Gcad::ErrorStatus   setOblique(double);
  double              thickness() const;
  Gcad::ErrorStatus   setThickness(double);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  Gsoft::Boolean      isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus   getPlane(GcGePlane&, GcDb::Planarity&) const override;
  Gsoft::Int16        shapeNumber() const;
  Gcad::ErrorStatus   setShapeNumber(Gsoft::Int16);
  GcDbObjectId        styleId() const;
  Gcad::ErrorStatus   setStyleId(GcDbObjectId id);
  GcDbObjectId        shapeIndex() const { return this->styleId(); }
  Gcad::ErrorStatus   setShapeIndex(GcDbObjectId id)
  {
    return this->setStyleId(id);
  }

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline GCHAR * GcDbShape::name() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbShape::name);
}

typedef struct tagBITMAPINFO BITMAPINFO;

class GCDB_PORT GcDbViewport : public GcDbEntity
{
public:
  GcDbViewport();
  ~GcDbViewport();
  GCDB_DECLARE_MEMBERS(GcDbViewport);

  Gcad::ErrorStatus setModelView(const GcDbXrefObjectId &xrefObjId);
  Gcad::ErrorStatus getModelView(GcDbXrefObjectId &xrefObjId) const;
  Gcad::ErrorStatus removeModelView(void);
  Gcad::ErrorStatus setSheetView(GcDbObjectId objId);
  Gcad::ErrorStatus getSheetView(GcDbObjectId &objId)const;
  Gcad::ErrorStatus removeSheetView(void);
  Gcad::ErrorStatus setLabelBlock(GcDbObjectId objId);
  Gcad::ErrorStatus getLabelBlock(GcDbObjectId &objId)const;
  Gcad::ErrorStatus removeLabelBlock(void);
  Gcad::ErrorStatus syncModelView(void);
  Gcad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
  Gcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
  Gcad::ErrorStatus getPreviewImage(Gtil::Image*& pPreviewImage) const;
  Gcad::ErrorStatus setPreviewImage(const Gtil::Image * pPreviewImage);
  double            height() const;
  Gcad::ErrorStatus setHeight(double);
  double            width() const;
  Gcad::ErrorStatus setWidth(double);
  GcGePoint3d       centerPoint() const;
  Gcad::ErrorStatus setCenterPoint(const GcGePoint3d&);
  Gsoft::Int16      number() const;
  bool              isOn() const;
  Gcad::ErrorStatus setOn();
  Gcad::ErrorStatus setOff();
  Gcad::ErrorStatus setIsOn(bool bOn);
  GcGePoint3d       viewTarget() const;
  Gcad::ErrorStatus setViewTarget(const GcGePoint3d&);
  GcGeVector3d      viewDirection() const;
  Gcad::ErrorStatus setViewDirection(const GcGeVector3d&);
  double            viewHeight() const;
  Gcad::ErrorStatus setViewHeight(double ht);
  GcGePoint2d       viewCenter() const;
  Gcad::ErrorStatus setViewCenter(const GcGePoint2d& pt);
  double            twistAngle() const;
  Gcad::ErrorStatus setTwistAngle(double);
  double            lensLength() const;
  Gcad::ErrorStatus setLensLength(double);
  bool              isFrontClipOn() const;
  Gcad::ErrorStatus setFrontClipOn();
  Gcad::ErrorStatus setFrontClipOff();
  Gcad::ErrorStatus setFrontClipOn(bool bOn);
  bool              isBackClipOn() const;
  Gcad::ErrorStatus setBackClipOn();
  Gcad::ErrorStatus setBackClipOff();
  Gcad::ErrorStatus setBackClipOn(bool bOn);
  bool              isFrontClipAtEyeOn() const;
  Gcad::ErrorStatus setFrontClipAtEyeOn();
  Gcad::ErrorStatus setFrontClipAtEyeOff();
  Gcad::ErrorStatus setFrontClipAtEyeOn(bool bOn);
  double            frontClipDistance() const;
  Gcad::ErrorStatus setFrontClipDistance(double newVal);
  double            backClipDistance() const;
  Gcad::ErrorStatus setBackClipDistance(double newVal);
  bool              isPerspectiveOn() const;
  Gcad::ErrorStatus setPerspectiveOn();
  Gcad::ErrorStatus setPerspectiveOff();
  Gcad::ErrorStatus setPerspectiveOn(bool bOn);
  bool              isUcsFollowModeOn() const;
  Gcad::ErrorStatus setUcsFollowModeOn();
  Gcad::ErrorStatus setUcsFollowModeOff();
  Gcad::ErrorStatus setUcsFollowModeOn(bool bOn);
  bool              isUcsIconVisible() const;
  Gcad::ErrorStatus setUcsIconVisible();
  Gcad::ErrorStatus setUcsIconInvisible();
  Gcad::ErrorStatus setUcsIconVisible(bool);
  bool              isUcsIconAtOrigin() const;
  Gcad::ErrorStatus setUcsIconAtOrigin();
  Gcad::ErrorStatus setUcsIconAtCorner();
  Gcad::ErrorStatus setUcsIconAtOrigin(bool);
  bool              isFastZoomOn() const { return true; }
  Gcad::ErrorStatus setFastZoomOn() { return Gcad::eOk; }
  Gcad::ErrorStatus setFastZoomOff() { return Gcad::eOk; }
  Gcad::ErrorStatus setFastZoomOn(bool);
  Gsoft::UInt16     circleSides() const;
  Gcad::ErrorStatus setCircleSides(Gsoft::UInt16);
  bool              isSnapOn() const;
  Gcad::ErrorStatus setSnapOn();
  Gcad::ErrorStatus setSnapOff();
  Gcad::ErrorStatus setSnapOn(bool);
  bool              isSnapIsometric() const;
  Gcad::ErrorStatus setSnapIsometric();
  Gcad::ErrorStatus setSnapStandard();
  Gcad::ErrorStatus setSnapIsometric(bool);
  double            snapAngle() const;
  Gcad::ErrorStatus setSnapAngle(double);
  GcGePoint2d       snapBasePoint() const;
  Gcad::ErrorStatus setSnapBasePoint(const GcGePoint2d&);
  GcGeVector2d      snapIncrement() const;
  Gcad::ErrorStatus setSnapIncrement(const GcGeVector2d&);
  Gsoft::UInt16     snapIsoPair() const;
  Gcad::ErrorStatus setSnapIsoPair(Gsoft::UInt16);
  bool              isGridOn() const;
  Gcad::ErrorStatus setGridOn();
  Gcad::ErrorStatus setGridOff();
  Gcad::ErrorStatus setGridOn(bool);
  bool              isGridBoundToLimits() const;
  Gcad::ErrorStatus setGridBoundToLimits(bool bNewVal);
  bool              isGridAdaptive() const;
  Gcad::ErrorStatus setGridAdaptive(bool bNewVal);
  bool              isGridSubdivisionRestricted() const;
  Gcad::ErrorStatus setGridSubdivisionRestricted(bool bNewVal);
  bool              isGridFollow() const;
  Gcad::ErrorStatus setGridFollow(bool bNewVal);
  Gsoft::UInt16     gridMajor() const;
  Gcad::ErrorStatus setGridMajor(Gsoft::UInt16);
  GcGeVector2d      gridIncrement() const;
  Gcad::ErrorStatus setGridIncrement(const GcGeVector2d&);
  bool              hiddenLinesRemoved() const;
  Gcad::ErrorStatus showHiddenLines();
  Gcad::ErrorStatus removeHiddenLines();
  Gcad::ErrorStatus removeHiddenLines(bool);
  Gcad::ErrorStatus freezeLayersInViewport(const GcDbObjectIdArray&);
  Gcad::ErrorStatus thawLayersInViewport(const GcDbObjectIdArray&);
  Gcad::ErrorStatus thawAllLayersInViewport();
  bool              isLayerFrozenInViewport(const GcDbObjectId& layerId) const;
  Gcad::ErrorStatus getFrozenLayerList(GcDbObjectIdArray& ids) const;
  Gcad::ErrorStatus updateDisplay() const;
  GcDbObjectId       background() const;
  Gcad::ErrorStatus  setBackground(GcDbObjectId backgroundId);
  GcDbObjectId       previousBackground(GcGiDrawable::DrawableType type = GcGiDrawable::kGeometry) const;
  Gcad::ErrorStatus  setPreviousBackground(GcDbObjectId backgroundId, GcGiDrawable::DrawableType type = GcGiDrawable::kGeometry);
  Gcad::ErrorStatus   setPreviousBackground(GcDbObjectId backgroundId, GcGiDrawable::DrawableType type, bool bForcedSwitch);
  bool                previousBackgroundForcedSwitch(void) const;
  GcDbObjectId        visualStyle() const;
  Gcad::ErrorStatus   setVisualStyle(const GcDbObjectId oidVisualStyle);
  bool                isDefaultLightingOn() const;
  Gcad::ErrorStatus   setDefaultLightingOn(bool on);
  GcGiViewportTraits::DefaultLightingType defaultLightingType() const;
  Gcad::ErrorStatus   setDefaultLightingType(GcGiViewportTraits::DefaultLightingType typ);
  double              brightness() const;
  Gcad::ErrorStatus   setBrightness(double);
  double              contrast() const;
  Gcad::ErrorStatus   setContrast(double);
  GcCmColor           ambientLightColor() const;
  Gcad::ErrorStatus   setAmbientLightColor(const GcCmColor& clr);
  GcDbObjectId        sunId() const;
  Gcad::ErrorStatus   setSun(GcDbObjectId &retId, GcDbObject *pSun);
  Gcad::ErrorStatus   setSun(GcDbObjectId &retId, GcDbObject *pSun, bool eraseOldSun);

  bool              isLocked() const;
  Gcad::ErrorStatus setLocked();
  Gcad::ErrorStatus setUnlocked();
  Gcad::ErrorStatus setLocked(bool);
  Gcad::ErrorStatus setAnnotationScale(const GcDbAnnotationScale *pScaleObj);
  GcDbAnnotationScale* annotationScale() const;
  bool              isTransparent() const;
  Gcad::ErrorStatus setTransparent();
  Gcad::ErrorStatus setOpaque();
  Gcad::ErrorStatus setTransparent(bool);

  enum StandardScaleType {
    kScaleToFit,
    kCustomScale,
    k1_1,
    k1_2,
    k1_4,
    k1_5,
    k1_8,
    k1_10,
    k1_16,
    k1_20,
    k1_30,
    k1_40,
    k1_50,
    k1_100,
    k2_1,
    k4_1,
    k8_1,
    k10_1,
    k100_1,
    k1_128in_1ft,
    k1_64in_1ft,
    k1_32in_1ft,
    k1_16in_1ft,
    k3_32in_1ft,
    k1_8in_1ft,
    k3_16in_1ft,
    k1_4in_1ft,
    k3_8in_1ft,
    k1_2in_1ft,
    k3_4in_1ft,
    k1in_1ft,
    k1and1_2in_1ft,
    k3in_1ft,
    k6in_1ft,
    k1ft_1ft
  };

  double            customScale() const;
  Gcad::ErrorStatus setCustomScale(double);
  StandardScaleType standardScale() const;
  Gcad::ErrorStatus setStandardScale(const StandardScaleType);
  Gcad::ErrorStatus plotStyleSheet(GcString &sName) const;
  Gcad::ErrorStatus plotStyleSheet(GCHAR *&) const;
  Gcad::ErrorStatus plotStyleSheet(const GCHAR *&) const;
  Gcad::ErrorStatus effectivePlotStyleSheet(const GCHAR *&);
  Gcad::ErrorStatus setPlotStyleSheet(const GCHAR *);
  bool              isNonRectClipOn() const;
  Gcad::ErrorStatus setNonRectClipOn();
  Gcad::ErrorStatus setNonRectClipOff();
  Gcad::ErrorStatus setNonRectClipOn(bool bOn);
  GcDbObjectId      nonRectClipEntityId() const;
  Gcad::ErrorStatus setNonRectClipEntityId(GcDbObjectId);
  void      erased(const GcDbObject*, Gsoft::Boolean) override;
  void      modified(const GcDbObject *) override;
  void      copied(const GcDbObject* pDbObj, const GcDbObject* pNewObj) override;
  void      subObjModified(const GcDbObject* pDbObj,
    const GcDbObject* pSubObj) override;
  Gcad::ErrorStatus getUcs(GcGePoint3d& origin,
    GcGeVector3d& xAxis,
    GcGeVector3d& yAxis) const;
  bool              isUcsOrthographic(GcDb::OrthographicView& view) const;
  GcDbObjectId      ucsName() const;
  double            elevation() const;
  Gcad::ErrorStatus setUcs(const GcGePoint3d& origin,
    const GcGeVector3d& xAxis,
    const GcGeVector3d& yAxis);
  Gcad::ErrorStatus setUcs(GcDb::OrthographicView view);
  Gcad::ErrorStatus setUcs(const GcDbObjectId& ucsId);
  Gcad::ErrorStatus setUcsToWorld();
  Gcad::ErrorStatus setElevation(double elev);
  bool              isViewOrthographic(GcDb::OrthographicView& view) const;
  Gcad::ErrorStatus setViewDirection(GcDb::OrthographicView view);
  bool           isUcsSavedWithViewport() const;
  void           setUcsPerViewport(bool ucsvp);

  enum ShadePlotType {
    kAsDisplayed = 0,
    kWireframe = 1,
    kHidden = 2,
    kRendered = 3,
    kVisualStyle = 4,
    kRenderPreset = 5
  };

  ShadePlotType     shadePlot() const;
  Gcad::ErrorStatus setShadePlot(const ShadePlotType);
  GcDbObjectId      shadePlotId() const;
  Gcad::ErrorStatus setShadePlot(const ShadePlotType type, const GcDbObjectId shadePlotId);
  bool              plotWireframe() const;
  bool              plotAsRaster()  const;
  Gcad::ErrorStatus toneOperatorParameters(GcGiToneOperatorParameters& params) const;
  Gcad::ErrorStatus setToneOperatorParameters(const GcGiToneOperatorParameters& params);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbViewport::plotStyleSheet(GCHAR *& pName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbViewport::plotStyleSheet, pName);
}

#pragma pack(pop)

#endif