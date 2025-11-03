/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbents.h"
#include "GcPointCloudItem.h"

class PointCloudExImp;
class GcDbPointCloudCrop;
class GcDbPointCloudExLimitBox;
class PointCloudPerfMonitor;

class IGcDbPointCloudAttributeFilter;
class IGcDbPointCloudDataBuffer;
class IGcDbPointCloudPointProcessor;
class IGcDbPointCloudSpatialFilter;
class IGcDbPointCloudAttributeFilter;

class GcPointCloudExtractedCylinder;

class GcDbPointCloudCropStateManager;
class DBPOINTCLOUDOBJ_PORT GcDbPointCloudEx : public GcDbEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPointCloudEx);
  GcDbPointCloudEx();
  ~GcDbPointCloudEx();

public:
  Gcad::ErrorStatus       subErase(Gsoft::Boolean erasing) override;

  Gcad::ErrorStatus       dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus       dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus       dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus       dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus       subSwapIdWith(GcDbObjectId otherId,
    Gsoft::Boolean swapXdata = false,
    Gsoft::Boolean swapExtDict = false) override;

  Gcad::ErrorStatus       copyFrom(const GcRxObject* pObj) override;

public:
  void                    getEcs(GcGeMatrix3d& retVal) const override;
  void                    dragStatus(const GcDb::DragStat status) override;

protected:
  void                    subList() const override;
  Gcad::ErrorStatus       subGetClassID(CLSID* pClsid) const override;
  Gcad::ErrorStatus       subGetGeomExtents(GcDbExtents& extents) const override;
  bool                    subIsContentSnappable() const override;
  Gsoft::Boolean          subWorldDraw(GcGiWorldDraw* mode) override;
  Gcad::ErrorStatus       subTransformBy(const GcGeMatrix3d& xform) override;

public:
  void                            setPointCloudDefExId(const GcDbObjectId& defExId);
  GcDbObjectId                    pointCloudDefExId() const;

  void                            setReactorId(const GcDbObjectId& reactorId);
  GcDbObjectId                    reactorId() const;

  bool                            locked()const;
  void                            setLocked(bool locked);

  double                          scale() const;
  Gcad::ErrorStatus               setScale(double val);

  double                          rotation() const;
  Gcad::ErrorStatus               setRotation(double val);

  GcGePoint3d                     location() const;
  Gcad::ErrorStatus               setLocation(const GcGePoint3d& pt);

  void                            getNativeCloudExtent(GcDbExtents& extents) const;
  unsigned int                    getVisiblePointCount() const;

  unsigned int                    getLoadedVisiblePointCount() const;
  unsigned int                    getDisplayedVisiblePointCount() const;

  PointCloudPerfMonitor*          getPointCloudPerfMonitor();

  bool                            setActiveFileName(const wchar_t* strActiveFileName);
  bool                            getActiveFileName(GcString& strActiveFileName) const;

  GcString                        getPointCloudName() const;
  Gcad::ErrorStatus               setPointCloudName(const GcString& name);

  int                             getCroppingCount() const;
  GcDbPointCloudCrop*             getPointCloudCropping(int index);
  const GcDbPointCloudCrop*       getPointCloudCroppingConst(int index) const;
  void                            addCroppingBoundary(const GcDbPointCloudCrop& cropping);
  Gcad::ErrorStatus               clearCropping();
  Gcad::ErrorStatus               removeLastCropping();
  bool                            getCroppingInvert() const;
  Gcad::ErrorStatus               setCroppingInvert(bool invert);
  void                            setInCreatingCroppingMode(bool  bCreating);

  bool                            showCropped() const;
  Gcad::ErrorStatus               setShowCropped(bool bShowCropped);

  enum StylizationType
  {
    kTrueColor = 1,
    kSingleColor,
    kNormalRamp,
    kHeightRamp,
    kIntensityRamp,
    kClassificationRamp
  };

  Gcad::ErrorStatus               setStylizationType(StylizationType type);
  StylizationType                 stylizationType() const;

  GcString                        getCurrentColorScheme() const;
  Gcad::ErrorStatus               setCurrentColorScheme(const GcString& guid);

  GcString                        getColorSchemeForStylization(StylizationType type) const;
  Gcad::ErrorStatus               setColorSchemeForStylization(const GcString& guid, StylizationType type);

  enum DispOptionOutOfRange
  {
    kUseMinMaxColors = 0,
    kUseRGBScanColors,
    kHidePoints
  };

  bool                            showIntensityAsGradient() const;
  void                            setShowIntensityAsGradient(bool b);

  Gsoft::Int32                    minIntensity() const;
  Gsoft::Int32                    maxIntensity() const;

  Gcad::ErrorStatus               setMinMaxIntensity(int min, int max);

  DispOptionOutOfRange            intensityOutOfRangeBehavior() const;
  void                            setIntensityOutOfRangeBehavior(DispOptionOutOfRange dispOp);

  bool                            showElevationAsGradient() const;
  void                            setShowElevationAsGradient(bool b);

  double                          minElevation() const;
  double                          maxElevation() const;
  Gcad::ErrorStatus               setMinMaxElevation(double min, double max);

  bool                            elevationApplyToFixedRange() const;
  void                            setElevationApplyToFixedRange(bool val);

  DispOptionOutOfRange            elevationOutOfRangeBehavior() const;
  void                            setElevationOutOfRangeBehavior(DispOptionOutOfRange dispOp);

  void                            getLimitBox(GcDbPointCloudExLimitBox& limitBox) const;
  Gcad::ErrorStatus               setLimitBox(const GcDbPointCloudExLimitBox& limitBox);
  void                            resetLimitBox();

  void                            setHighlightLimitboxBoundary(bool val);

  const GcPointCloudItemArray*    getPointCloudDataList() const;

  GcPointCloudItem*               findScanItem(const GcString& scanGuid);
  GcPointCloudItem*               findRegionItem(int regionId);

  void                            setScanVisibility(const GcString& scanGuid, bool bVisible);
  void                            setAllScansVisibility(bool bVisible);
  void                            setRegionVisibility(int regionId, bool bVisible);
  void                            setAllRegionsVisibility(bool bVisible, bool includeUnassigned = false);
  void                            setAllScansVisibilityByRegion(int regionId, bool bVisible);

  bool                            getScanViewInfo(const GcString& scanGuid, GcGePoint3d& origin, GcDbExtents& extent) const;

  void                            resetScanRegionVisibility();

  void                            setAllScanHighlight(bool bHighlight);
  void                            setAllRegionHighlight(bool bHighlight, bool bIncludeUnassignedPoints = false);

  void                            applyGeoLocation(bool useDrawingGeo = false, const GcString& geoCS = GCRX_T(""));
  void                            updateGeoLocation();
  void                            clearGeoLocation();

  bool                            geolocate() const;

  enum PointCloudOSnapMode
  {
    kOsModePNod = 0,
    kOsModePNea = 1,
    kOsModePPer = 2,
    kOsModePEdgeNea = 3,
    kOsModePEdgePer = 4,
    kOsModePInt = 5,
    kOsModePCL = 6,
    kOsModePCorner = 7
  };

  Gcad::ErrorStatus               getCustomOsnapInfo(PointCloudOSnapMode snapMode,
    const GcGePoint3d& pickPoint,
    const GcGePoint3d& lastPoint,
    const GcGeMatrix3d& viewXform,
    GcArray<GcGePoint3d>& snapPoints);

  Gcad::ErrorStatus getPointDataByPointCount(IGcDbPointCloudDataBuffer*& pointData, Gsoft::UInt32 pointCount,
    IGcDbPointCloudSpatialFilter* pSpatialFilter, IGcDbPointCloudAttributeFilter* pAttributeFilter, Gsoft::UInt32 dataTypes, Gsoft::UInt32 maxPointLimitation) const;

  Gcad::ErrorStatus traverseAllPointData(IGcDbPointCloudPointProcessor* processor, IGcDbPointCloudSpatialFilter* pSpatialFilter, Gsoft::UInt32 dataTypes, int LODLevel) const;

  Gcad::ErrorStatus  addSpatialFilter(IGcDbPointCloudSpatialFilter* pFilter);
  Gcad::ErrorStatus  removeSpatialFilter(IGcDbPointCloudSpatialFilter* pFilter);
  void  clearSpatialFilters();

  Gcad::ErrorStatus  addAttributeFilter(IGcDbPointCloudAttributeFilter* pFilter);
  Gcad::ErrorStatus  removeAttributeFilter(IGcDbPointCloudAttributeFilter* pFilter);
  void  clearAttributeFilters();

  bool  getPlaneOrPointAt(const GcGeMatrix3d & viewXform, const GcGePoint3d & pickPt, GcArray<GcGePoint3d> & points);
  bool  getPlaneBoundaryAt(const GcGeMatrix3d& viewXform, const GcGePoint3d& pickPt, GcGePoint3dArray& arrPlaneVertices);
  void * getQuery();
  void objectToWorldMatrix(GcGeMatrix3d& mat) const;
  Gcad::ErrorStatus getCandidatePlane(const class CPoint& pt, GcGePlane &result, double &distToEdge, double &objWidth, double &objHeight, void*& context) const;
  Gcad::ErrorStatus  getCylinderAt(const GcGeMatrix3d& viewXform, const GcGePoint3d& pickPt, GcGePoint3d& origin, GcGeVector3d& axis, double& height, double& radius);

  const GcDbPointCloudCropStateManager* cropStatesManagerConst() const;
  GcDbPointCloudCropStateManager* cropStatesManager();

  Gcad::ErrorStatus getMinDistPrecision(double& minDistPrecision) const;
  Gcad::ErrorStatus getPointDataByPrecision(IGcDbPointCloudDataBuffer*& pointData, double distPrecision, IGcDbPointCloudSpatialFilter* pSpatialFilter = NULL,
    IGcDbPointCloudAttributeFilter* pAttributeFilter = NULL, Gsoft::UInt32 dataTypes = 0, Gsoft::UInt32 maxPointLimitation = 1000000uLL) const;

  Gcad::ErrorStatus getEstimatedPointCountByPrecision(unsigned long long &pointCount, double distPrecision, IGcDbPointCloudSpatialFilter* pSpatialFilter = NULL, IGcDbPointCloudAttributeFilter* pAttributeFilter = NULL) const;
  Gcad::ErrorStatus  decomposeForSave(GcDb::GcDbDwgVersion ver, GcDbObject*& replaceObj, GcDbObjectId& replaceId, Gsoft::Boolean& exchangeXData);
  Gcad::ErrorStatus getCylinderAt(const GcGeMatrix3d& viewXform, const GcGePoint3d& pickPt, GcPointCloudExtractedCylinder& extractedCylinder);
  Gcad::ErrorStatus  detectPointBelonger(const GcGePoint3d& ptInWCS, GcString& scanGuid, Gsoft::UInt16& segmentIndex) const;
  Gcad::ErrorStatus  getPointDataBySegment(IGcDbPointCloudDataBuffer*& pointData, const GcString& scanGuid, Gsoft::UInt16 nSegmentIndex, Gsoft::UInt32 nExpectedCount) const;
  Gcad::ErrorStatus  getPointDataByPointCount(IGcDbPointCloudDataBuffer*& pointData, Gsoft::UInt32 pointCount, const GcArray<GcString>& arrScanGuids, IGcDbPointCloudSpatialFilter* pSpatialFilter,
    IGcDbPointCloudAttributeFilter* pAttributeFilter, Gsoft::UInt32 dataTypes, Gsoft::UInt32 maxPointLimitation) const;
  Gcad::ErrorStatus  traverseAllPointData(IGcDbPointCloudPointProcessor* processor, IGcDbPointCloudSpatialFilter* pSpatialFilter, Gsoft::UInt32 dataTypes, int LODLevel, const GcArray<GcString>& arrScanGuids) const;

private:
  PointCloudExImp*        m_pImp;
  friend class GcDbPointCloudCropStateManagerImp;
};
