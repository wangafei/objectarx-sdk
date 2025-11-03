/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack (push, 8)

#ifndef GCSYNERGY_PORT
#define GCSYNERGY_PORT
#endif

class GcDbImpViewBorder;

class GCSYNERGY_PORT GcDbViewBorder : public GcDbEntity
{
  friend class GcDbAssocViewRepActionBody;
  friend class GcDbImpViewBorder;
  friend class GcDbImpViewSymbol;
public:
  GCRX_DECLARE_MEMBERS(GcDbViewBorder);
  GcDbViewBorder();
  ~GcDbViewBorder();

  enum ViewStyleType
  {
    kFromBase = 0,
    kWireframeVisibleEdges = 1,
    kWireframeHiddenEdges = 2,
    kShadedVisibleEdges = 3,
    kShadedHiddenEdges = 4
  };

  enum SourceType
  {
    kSourceNotDefined = 0,
    kInventorSource = 1,
    kFusionSource = 2,
    kModelSpaceSource = 3
  };

  GcGePoint3d                 insertionPoint() const;
  double                      height() const;
  double                      width() const;
  GcDbViewBorder::SourceType  sourceType() const;
  GcString                    inventorFileReference() const;
  bool                        isFirstAngleProjection() const;
  double                      rotationAngle() const;
  GcDbViewBorder::ViewStyleType viewStyleType() const;
  double                      scale() const;
  Gsoft::UInt32               shadedDPI() const;
  GcDbObjectId                viewportId() const;

  Gsoft::Boolean      subWorldDraw(GcGiWorldDraw* pWd) override;
  Gcad::ErrorStatus   subErase(Gsoft::Boolean erasing) override;
  Gcad::ErrorStatus   subDeepClone(GcDbObject* pOwnerObject, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
  Gcad::ErrorStatus   subWblockClone(GcRxObject* pOwnerObject, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;

  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   audit(GcDbAuditInfo* pAuditInfo) override;

  Gcad::ErrorStatus   subGetStretchPoints(GcGePoint3dArray& stretchPoints) const override;
  Gcad::ErrorStatus   subMoveStretchPointsAt(const GcDbIntArray & indices,
    const GcGeVector3d& offset) override;
  Gcad::ErrorStatus   subGetGripPoints(GcDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const GcGeVector3d& curViewDir,
    const int bitflags) const override;
  Gcad::ErrorStatus   subGetGripPoints(GcGePoint3dArray& gripPoints,
    GcDbIntArray & osnapModes,
    GcDbIntArray & geomIds) const override;
  Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset,
    const int bitflags) override;
  Gcad::ErrorStatus   subMoveGripPointsAt(const GcDbIntArray & indices,
    const GcGeVector3d& offset) override;
  void                subGripStatus(const GcDb::GripStat status) override;
  Gcad::ErrorStatus   subGetOsnapPoints(GcDb::OsnapMode osnapMode,
    Gsoft::GsMarker gsSelectionMark,
    const GcGePoint3d& pickPoint,
    const GcGePoint3d& lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray& snapPoints,
    GcDbIntArray & geomIds) const override;
  Gcad::ErrorStatus   subGetOsnapPoints(GcDb::OsnapMode osnapMode,
    Gsoft::GsMarker gsSelectionMark,
    const GcGePoint3d& pickPoint,
    const GcGePoint3d& lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray& snapPoints,
    GcDbIntArray & geomIds,
    const GcGeMatrix3d& insertionMat) const override;
  Gcad::ErrorStatus   subIntersectWith(const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    const GcGePlane& projPlane,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker = 0,
    Gsoft::GsMarker otherGsMarker = 0) const override;
  Gcad::ErrorStatus   subIntersectWith(const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker = 0,
    Gsoft::GsMarker otherGsMarker = 0) const override;
  Gcad::ErrorStatus   subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
  void                subList() const override;
  Gcad::ErrorStatus   subHighlight(const GcDbFullSubentPath& subId = kNullSubent,
    const Gsoft::Boolean highlightAll = false) const override;
  Gcad::ErrorStatus   subUnhighlight(const GcDbFullSubentPath& subId = kNullSubent,
    const Gsoft::Boolean highlightAll = false) const override;
  Gcad::ErrorStatus  subGetSubentPathsAtGsMarker(GcDb::SubentType       type,
    Gsoft::GsMarker        gsMark,
    const GcGePoint3d&     pickPoint,
    const GcGeMatrix3d&    viewXform,
    int&                   numPaths,
    GcDbFullSubentPath*&   subentPaths,
    int                    numInserts = 0,
    GcDbObjectId*          entAndInsertStack
    = NULL) const override;
  Gcad::ErrorStatus  subGetGsMarkersAtSubentPath(const GcDbFullSubentPath& subPath,
    GcArray<Gsoft::GsMarker>& gsMarkers) const override;
  Gcad::ErrorStatus  subGetSubentClassId(const GcDbFullSubentPath& path, CLSID* clsId) const override;

  void                saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;
  Gcad::ErrorStatus   setLayer(const GCHAR* newVal,
    Gsoft::Boolean doSubents = true,
    bool allowHiddenLayer = false) override;
  Gcad::ErrorStatus   setLayer(GcDbObjectId newVal,
    Gsoft::Boolean doSubents = true,
    bool allowHiddenLayer = false) override;
  Gcad::ErrorStatus           setViewportId(const GcDbObjectId& viewportId);
  GcGePoint2d                 centerPoint(bool exludeSketchEnts = true) const;
  GcGePoint3d                 centerPoint3d(bool exludeSketchEnts = true) const;
  Gcad::ErrorStatus           getSize(GcGePoint3d& minPt, GcGePoint3d& maxPt) const;
  Gcad::ErrorStatus           setSize(const GcGePoint3d& minPt, const GcGePoint3d& maxPt);
  void                        setScale(double newScale);
  Gcad::ErrorStatus           recalculateBorder();
  void                        setTransientEnts(const GcArray<GcDbEntity*>& traientEnts);
  void                        setDisableUnHighlight(bool bIsDisable);
  bool                        hitTest(const GcGePoint3d& inputPt) const;

  Gcad::ErrorStatus getSubentColor(const GcDbSubentId& subentId, GcCmColor& color) const;
  Gcad::ErrorStatus setSubentColor(const GcDbSubentId& subentId, const GcCmColor& color);

  Gcad::ErrorStatus getSubentLayerId(const GcDbSubentId& subentId, GcDbObjectId& layerId) const;
  Gcad::ErrorStatus setSubentLayer(const GcDbSubentId& subentId, GcDbObjectId newVal);

  Gcad::ErrorStatus getSubentLinetypeId(const GcDbSubentId& subentId, GcDbObjectId& linetypeId) const;
  Gcad::ErrorStatus setSubentLinetype(const GcDbSubentId& subentId, GcDbObjectId newVal);

  Gcad::ErrorStatus getSubentLinetypeScale(const GcDbSubentId& subentId, double& linetypeScale) const;
  Gcad::ErrorStatus setSubentLinetypeScale(const GcDbSubentId& subentId, double newVal);

  GCHAR*            getSubentPlotStyleName(const GcDbSubentId& subentId) const;
  Gcad::ErrorStatus setSubentPlotStyleName(const GcDbSubentId& subentId, const GCHAR* newName);

  Gcad::ErrorStatus getSubentLineWeight(const GcDbSubentId& subentId, GcDb::LineWeight& lineweight) const;
  Gcad::ErrorStatus setSubentLineWeight(const GcDbSubentId& subentId, GcDb::LineWeight newVal);

  Gcad::ErrorStatus getSubentVisibility(const GcDbSubentId& subentId, GcDb::Visibility& visVal) const;
  Gcad::ErrorStatus setSubentVisibility(const GcDbSubentId& subentId, GcDb::Visibility newVal);

  Gcad::ErrorStatus subentIdToNestedEnts(const GcDbSubentId& subentId, GcDbFullSubentPathArray &nestedEnts) const;

private:
  GcGeMatrix3d            transientXform() const;

private:
  GcDbImpViewBorder*          mpGcDbImpViewBorder;
  static  double              sViewBoderOffset;
};

#pragma pack (pop)