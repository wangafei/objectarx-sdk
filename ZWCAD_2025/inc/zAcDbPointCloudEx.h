

#pragma once
#include "zdbents.h"
#include "zAcPointCloudItem.h"

class PointCloudExImp;
class ZcDbPointCloudCrop;
class ZcDbPointCloudExLimitBox;
class PointCloudPerfMonitor;

class IZcDbPointCloudAttributeFilter;
class IZcDbPointCloudDataBuffer;
class IZcDbPointCloudPointProcessor;
class IZcDbPointCloudSpatialFilter;
class IZcDbPointCloudAttributeFilter;

class ZcPointCloudExtractedCylinder;

class ZcDbPointCloudCropStateManager;

class ZCDB_PORT ZcDbPointCloudEx : public ZcDbEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbPointCloudEx);
    ZcDbPointCloudEx();

    virtual ~ZcDbPointCloudEx();

public:
    virtual Zcad::ErrorStatus       subErase(ZSoft::Boolean erasing);

    virtual Zcad::ErrorStatus       dwgInFields(ZcDbDwgFiler* pFiler) ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       dwgOutFields(ZcDbDwgFiler* pFiler) const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       dxfInFields(ZcDbDxfFiler* pFiler) ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       dxfOutFields(ZcDbDxfFiler* pFiler) const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       subSwapIdWith(ZcDbObjectId otherId,
                                                ZSoft::Boolean swapXdata = false,
                                                ZSoft::Boolean swapExtDict = false) ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       copyFrom(const ZcRxObject* pObj);

public:

    virtual void                    getEcs(ZcGeMatrix3d& retVal) const ZSOFT_OVERRIDE;

    virtual void                    dragStatus(const ZcDb::DragStat status) ZSOFT_OVERRIDE;

protected:

    virtual void                    subList() const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       subGetClassID(CLSID* pClsid) const ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       subGetGeomExtents(ZcDbExtents& extents) const ZSOFT_OVERRIDE;

    virtual bool                    subIsContentSnappable() const ZSOFT_OVERRIDE;

    virtual ZSoft::Boolean          subWorldDraw(ZcGiWorldDraw* mode) ZSOFT_OVERRIDE;

    virtual void subViewportDraw(ZcGiViewportDraw* mode) ZSOFT_OVERRIDE;

    virtual Zcad::ErrorStatus       subTransformBy(const ZcGeMatrix3d& xform) ZSOFT_OVERRIDE;

public:

    void                            setPointCloudDefExId(const ZcDbObjectId& defExId);

    ZcDbObjectId                    pointCloudDefExId() const;

    void                            setReactorId(const ZcDbObjectId& reactorId);

    ZcDbObjectId                    reactorId() const;

    bool                            locked()const;

    void                            setLocked(bool locked);

    double                          scale() const;

    Zcad::ErrorStatus               setScale(double val);

    double                          rotation() const;

    Zcad::ErrorStatus               setRotation(double val);

    ZcGePoint3d                     location() const;

	

    Zcad::ErrorStatus               setLocation(const ZcGePoint3d& pt);

    void                            getNativeCloudExtent(ZcDbExtents& extents) const;

    unsigned int                    getVisiblePointCount() const;

    unsigned int                    getLoadedVisiblePointCount() const;

    unsigned int                    getDisplayedVisiblePointCount() const;

    PointCloudPerfMonitor*          getPointCloudPerfMonitor();

    bool                            setActiveFileName(const wchar_t* strActiveFileName);

    bool                            getActiveFileName(ZcString& strActiveFileName) const;

    ZcString                        getPointCloudName() const;

    Zcad::ErrorStatus               setPointCloudName(const ZcString& name);

    int                             getCroppingCount() const;

    ZcDbPointCloudCrop*             getPointCloudCropping(int index);

    const ZcDbPointCloudCrop*       getPointCloudCroppingConst(int index) const;

    void                            addCroppingBoundary(const ZcDbPointCloudCrop& cropping);

    Zcad::ErrorStatus               clearCropping();

    Zcad::ErrorStatus               removeLastCropping();

    bool                            getCroppingInvert() const;

    Zcad::ErrorStatus               setCroppingInvert(bool invert);

    void                            setInCreatingCroppingMode(bool  bCreating);

    bool                            showCropped() const;

    Zcad::ErrorStatus               setShowCropped(bool bShowCropped);

    enum StylizationType
    {

        kTrueColor      = 1,

        kSingleColor,

        kNormalRamp,

        kHeightRamp,

        kIntensityRamp,

        kClassificationRamp
    };

    Zcad::ErrorStatus               setStylizationType(StylizationType type);

    StylizationType                 stylizationType() const;

    ZcString                        getCurrentColorScheme() const;

    Zcad::ErrorStatus               setCurrentColorScheme(const ZcString& guid);

    ZcString                        getColorSchemeForStylization(StylizationType type) const;

    Zcad::ErrorStatus               setColorSchemeForStylization(const ZcString& guid, StylizationType type);

    enum DispOptionOutOfRange
    {

        kUseMinMaxColors = 0,

        kUseRGBScanColors,

        kHidePoints
    };

    bool                            showIntensityAsGradient() const;

    void                            setShowIntensityAsGradient(bool b);

    ZSoft::Int32                    minIntensity() const;

    ZSoft::Int32                    maxIntensity() const;

    Zcad::ErrorStatus               setMinMaxIntensity(int min, int max);

    DispOptionOutOfRange            intensityOutOfRangeBehavior() const;

    void                            setIntensityOutOfRangeBehavior(DispOptionOutOfRange dispOp);

    bool                            showElevationAsGradient() const;

    void                            setShowElevationAsGradient(bool b);

    double                          minElevation() const;

    double                          maxElevation() const;

    Zcad::ErrorStatus               setMinMaxElevation(double min, double max);

    bool                            elevationApplyToFixedRange() const;

    void                            setElevationApplyToFixedRange(bool val);

    DispOptionOutOfRange            elevationOutOfRangeBehavior() const;

    void                            setElevationOutOfRangeBehavior(DispOptionOutOfRange dispOp);

    void                            getLimitBox(ZcDbPointCloudExLimitBox& limitBox) const;

    Zcad::ErrorStatus               setLimitBox(const ZcDbPointCloudExLimitBox& limitBox);

    void                            resetLimitBox();

    void                            setHighlightLimitboxBoundary(bool val);

    const ZcPointCloudItemArray*    getPointCloudDataList() const;

    ZcPointCloudItem*               findScanItem(const ZcString& scanGuid);

    ZcPointCloudItem*               findRegionItem(int regionId);

    void                            setScanVisibility(const ZcString& scanGuid, bool bVisible);

    void                            setAllScansVisibility(bool bVisible);

    void                            setRegionVisibility(int regionId, bool bVisible);

    void                            setAllRegionsVisibility(bool bVisible, bool includeUnassigned = false);

    void                            setAllScansVisibilityByRegion(int regionId, bool bVisible);

    bool                            getScanViewInfo(const ZcString& scanGuid, ZcGePoint3d& origin, ZcDbExtents& extent) const;

    void                            resetScanRegionVisibility();

    void                            setAllScanHighlight(bool bHighlight);

    void                            setAllRegionHighlight(bool bHighlight, bool bIncludeUnassignedPoints = false);

    void                            applyGeoLocation(bool useDrawingGeo = false, const ZcString& geoCS = _T(""));

    void                            updateGeoLocation();

    void                            clearGeoLocation();

    bool                            geolocate() const;

    enum PointCloudOSnapMode
    {
        kOsModePNod     = 0,
        kOsModePNea     = 1,
        kOsModePPer     = 2,
        kOsModePEdgeNea = 3,
        kOsModePEdgePer = 4,
        kOsModePInt     = 5,
        kOsModePCL      = 6,
        kOsModePCorner  = 7
    };

    Zcad::ErrorStatus               getCustomOsnapInfo(PointCloudOSnapMode snapMode,
                                                    const ZcGePoint3d& pickPoint,
                                                    const ZcGePoint3d& lastPoint,
                                                    const ZcGeMatrix3d& viewXform,
                                                    ZcArray<ZcGePoint3d>& snapPoints);

    Zcad::ErrorStatus getPointDataByPointCount(IZcDbPointCloudDataBuffer*& pointData, ZSoft::UInt32 pointCount,
         IZcDbPointCloudSpatialFilter* pSpatialFilter, IZcDbPointCloudAttributeFilter* pAttributeFilter, ZSoft::UInt32 dataTypes, ZSoft::UInt32 maxPointLimitation) const;

    Zcad::ErrorStatus traverseAllPointData(IZcDbPointCloudPointProcessor* processor,IZcDbPointCloudSpatialFilter* pSpatialFilter, ZSoft::UInt32 dataTypes, int LODLevel) const;

    Zcad::ErrorStatus  addSpatialFilter(IZcDbPointCloudSpatialFilter* pFilter);

    Zcad::ErrorStatus  removeSpatialFilter(IZcDbPointCloudSpatialFilter* pFilter);

    void  clearSpatialFilters();

    Zcad::ErrorStatus  addAttributeFilter(IZcDbPointCloudAttributeFilter* pFilter);
	

    Zcad::ErrorStatus  removeAttributeFilter(IZcDbPointCloudAttributeFilter* pFilter);

    void  clearAttributeFilters();

    bool  getPlaneOrPointAt(const ZcGeMatrix3d & viewXform, const ZcGePoint3d & pickPt, ZcArray<ZcGePoint3d> & points);

    bool  getPlaneBoundaryAt(const ZcGeMatrix3d& viewXform, const ZcGePoint3d& pickPt, ZcGePoint3dArray& arrPlaneVertices);

    void * getQuery();

    void objectToWorldMatrix(ZcGeMatrix3d& mat) const;

    Zcad::ErrorStatus getCandidatePlane(const class CPoint& pt, ZcGePlane &result, double &distToEdge, double &objWidth, double &objHeight, void*& context) const;

    Zcad::ErrorStatus  getCylinderAt(const ZcGeMatrix3d& viewXform, const ZcGePoint3d& pickPt, ZcGePoint3d& origin, ZcGeVector3d& axis, double& height, double& radius);

    const ZcDbPointCloudCropStateManager* cropStatesManagerConst() const;

    ZcDbPointCloudCropStateManager* cropStatesManager();

    Zcad::ErrorStatus getMinDistPrecision(double& minDistPrecision) const;

    Zcad::ErrorStatus getPointDataByPrecision(IZcDbPointCloudDataBuffer*& pointData, double distPrecision, IZcDbPointCloudSpatialFilter* pSpatialFilter = NULL,
        IZcDbPointCloudAttributeFilter* pAttributeFilter = NULL, ZSoft::UInt32 dataTypes = 0, ZSoft::UInt32 maxPointLimitation = 1000000uLL) const;

    Zcad::ErrorStatus getEstimatedPointCountByPrecision(unsigned long long &pointCount, double distPrecision, IZcDbPointCloudSpatialFilter* pSpatialFilter = NULL, IZcDbPointCloudAttributeFilter* pAttributeFilter = NULL) const;

    Zcad::ErrorStatus  decomposeForSave(ZcDb::ZcDbDwgVersion ver, ZcDbObject*& replaceObj, ZcDbObjectId& replaceId,ZSoft::Boolean& exchangeXData) override;

    Zcad::ErrorStatus getCylinderAt(const ZcGeMatrix3d& viewXform, const ZcGePoint3d& pickPt, ZcPointCloudExtractedCylinder& extractedCylinder);

    Zcad::ErrorStatus  detectPointBelonger(const ZcGePoint3d& ptInWCS, ZcString& scanGuid, ZSoft::UInt16& segmentIndex) const;

    Zcad::ErrorStatus  getPointDataBySegment(IZcDbPointCloudDataBuffer*& pointData, const ZcString& scanGuid, ZSoft::UInt16 nSegmentIndex, ZSoft::UInt32 nExpectedCount) const;

    Zcad::ErrorStatus  getPointDataByPointCount(IZcDbPointCloudDataBuffer*& pointData, ZSoft::UInt32 pointCount, const ZcArray<ZcString>& arrScanGuids, IZcDbPointCloudSpatialFilter* pSpatialFilter,
                         IZcDbPointCloudAttributeFilter* pAttributeFilter, ZSoft::UInt32 dataTypes, ZSoft::UInt32 maxPointLimitation) const;

    Zcad::ErrorStatus  traverseAllPointData(IZcDbPointCloudPointProcessor* processor, IZcDbPointCloudSpatialFilter* pSpatialFilter, ZSoft::UInt32 dataTypes, int LODLevel, const ZcArray<ZcString>& arrScanGuids) const;

private:
    PointCloudExImp*        m_pImp;

    friend class ZcDbPointCloudCropStateManagerImp;
};
