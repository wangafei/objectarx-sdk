
#ifndef ZD_DBSYMTB_H
#define ZD_DBSYMTB_H
#include "zdbmain.h"
#include "zdbdict.h"
#include "zdbdate.h"
#include "zdbbackground.h"
#include "zgevec2d.h"
#include "zacgiviewport.h"
#include "zacgivisualstyle.h"
#include "zAcDbCore2dDefs.h"
#include "PAL/api/zcharset.h"
#include "PAL/api/zFontPitchAndFamily.h"
#pragma pack(push, 8)

#ifdef target
# undef target 
#endif

class ZcDbSortentsTable;
class ZcDbSymbolTableIterator;
class ZcDbSymbolTable;
class ZcDbAnnotationScale;
class ZcGsView;
class ZcString;

namespace Ztil 
{
	class Image; 
}

class ZCDB_PORT ZSOFT_NO_VTABLE ZcDbSymbolTableRecord: public  ZcDbObject
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbSymbolTableRecord);
	ZcDbSymbolTableRecord();
	virtual ~ZcDbSymbolTableRecord();

	typedef ZcDbSymbolTable TableType;

	Zcad::ErrorStatus getName(ZTCHAR*& pName) const;     
	Zcad::ErrorStatus getName(ZcString & sName) const;
	Zcad::ErrorStatus getName(const ZTCHAR*& pName) const;
	Zcad::ErrorStatus setName(const ZTCHAR* pName);

	bool isDependent() const;

	bool isResolved() const;

	bool isRenamable() const;
};

class ZcDbBlockTable;
class ZcDbBlockTableIterator;
class ZcDbBlockTableRecordIterator;
class ZcDbBlockReferenceIdIterator;


class ZCDBCORE2D_PORT ZcDbBlockTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbBlockTableRecord);

    ZcDbBlockTableRecord();
    virtual ~ZcDbBlockTableRecord();

    typedef ZcDbBlockTable TableType;
    typedef ZcArray<ZSoft::UInt8> PreviewIcon;

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;

    Zcad::ErrorStatus appendZcDbEntity(ZcDbEntity* pEntity)
    {
        ZcDbObjectId id;
        return this->appendZcDbEntity(id, pEntity);
    }

    Zcad::ErrorStatus appendZcDbEntity(ZcDbObjectId& pOutputId,
        ZcDbEntity* pEntity);

    Zcad::ErrorStatus newIterator(
        ZcDbBlockTableRecordIterator*& pIterator,
        bool atBeginning = true,
        bool skipDeleted = true) const;

    Zcad::ErrorStatus comments(ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(const ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(ZcString & sComments) const;
    Zcad::ErrorStatus setComments(const ZTCHAR* pString);

    Zcad::ErrorStatus pathName(ZTCHAR*& pPath) const;
    Zcad::ErrorStatus pathName(const ZTCHAR*& pPath) const;
    Zcad::ErrorStatus pathName(ZcString & sPath) const;
    Zcad::ErrorStatus setPathName(const ZTCHAR* pathStr);
 
    ZcGePoint3d       origin() const;
    Zcad::ErrorStatus setOrigin(const ZcGePoint3d& pt);

    Zcad::ErrorStatus openBlockBegin(ZcDbBlockBegin*& pBlockBegin,
                                     ZcDb::OpenMode   openMode = ZcDb::kForRead);
 
    Zcad::ErrorStatus openBlockEnd(ZcDbBlockEnd*& pBlockEnd,
                                   ZcDb::OpenMode openMode = ZcDb::kForRead);

    bool              hasAttributeDefinitions() const;

    bool              hasPreviewIcon() const;
    Zcad::ErrorStatus getPreviewIcon(PreviewIcon &previewIcon) const;
    Zcad::ErrorStatus setPreviewIcon(const PreviewIcon &previewIcon);

    bool              isAnonymous() const;

    bool              isFromExternalReference() const;

    bool              isFromOverlayReference() const;
    Zcad::ErrorStatus setIsFromOverlayReference(bool bIsOverlay);

    bool              isLayout() const;

    ZcDbObjectId      getLayoutId() const;
    Zcad::ErrorStatus setLayoutId(ZcDbObjectId);

    Zcad::ErrorStatus newBlockReferenceIdIterator(
        ZcDbBlockReferenceIdIterator*& pIter) const;

    Zcad::ErrorStatus getBlockReferenceIds(ZcDbObjectIdArray& ids,
                                           bool bDirectOnly = true,
                                           bool bForceValidity = false) const;

    Zcad::ErrorStatus getErasedBlockReferenceIds(ZcDbObjectIdArray&);

    Zcad::ErrorStatus
    getSortentsTable(ZcDbSortentsTable*& pSortents,
                     ZcDb::OpenMode openMode = ZcDb::kForRead,
                     bool createIfNecessary=false);

    ZcDbDatabase*     xrefDatabase(bool incUnres = false) const;

    bool              isUnloaded() const;
    Zcad::ErrorStatus setIsUnloaded(bool isUnloaded);

    ZcDb::XrefStatus  xrefStatus() const;

    ZcGiDrawable*     drawable() override;

    virtual Zcad::ErrorStatus decomposeForSave(ZcDb::ZcDbDwgVersion ver,
                                               ZcDbObject*& replaceObj,
                                               ZcDbObjectId& replaceId,
                                               ZSoft::Boolean& exchangeXData) override;

    virtual Zcad::ErrorStatus assumeOwnershipOf(const ZcDbObjectIdArray &entitiesToMove);

	enum BlockScaling {
		kAny,
		kUniform
	};

	ZcDbBlockTableRecord::BlockScaling blockScaling () const;
    Zcad::ErrorStatus  setBlockScaling (
                        ZcDbBlockTableRecord::BlockScaling blockScaling);

	Zcad::ErrorStatus setExplodable (bool bExplodable);
	bool              explodable () const;

	Zcad::ErrorStatus setBlockInsertUnits(ZcDb::UnitsValue insunits);
	ZcDb::UnitsValue blockInsertUnits() const;

    Zcad::ErrorStatus postProcessAnnotativeBTR(int& stripCnt,
                                               bool bqueryOnly = false, bool bScale = true);
    Zcad::ErrorStatus addAnnoScalestoBlkRefs(const bool bScale = false);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbLayerTable;

class ZCDBCORE2D_PORT ZcDbLayerTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerTableRecord);

    ZcDbLayerTableRecord();
    virtual ~ZcDbLayerTableRecord();

    typedef ZcDbLayerTable TableType;

    bool              isFrozen() const;
    Zcad::ErrorStatus setIsFrozen(bool frozen);

    bool              isOff() const;
    void              setIsOff(bool off);

    bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);

    bool              isLocked() const;
    void              setIsLocked(bool locked);

    ZcCmColor         color() const;
    void              setColor(const ZcCmColor &color);
    ZcCmEntityColor   entityColor(void) const;

    ZcCmTransparency  transparency(void) const;
    Zcad::ErrorStatus setTransparency(const ZcCmTransparency& trans);

    ZcDbObjectId      linetypeObjectId() const;
    Zcad::ErrorStatus setLinetypeObjectId(ZcDbObjectId id);

    ZcDbObjectId      materialId() const;
    Zcad::ErrorStatus setMaterialId(ZcDbObjectId id);

    enum { kDxfLayerPlotBit = ZcDb::kDxfBool };
    bool              isPlottable() const;
    Zcad::ErrorStatus setIsPlottable(bool plot);

    ZcDb::LineWeight  lineWeight() const;
    Zcad::ErrorStatus setLineWeight(ZcDb::LineWeight weight);

    ZTCHAR*            plotStyleName() const;
    Zcad::ErrorStatus plotStyleName(ZcString &) const;
    ZcDbObjectId      plotStyleNameId() const;
    Zcad::ErrorStatus setPlotStyleName(const ZTCHAR* newName);
    Zcad::ErrorStatus setPlotStyleName(const ZcDbObjectId& newId);

    ZcGiDrawable*     drawable() override;

    bool              isInUse() const;
    ZTCHAR*            description() const;
    Zcad::ErrorStatus description(ZcString &) const;
    Zcad::ErrorStatus setDescription(const ZTCHAR* description);

    bool              isHidden() const;
    Zcad::ErrorStatus setIsHidden(bool on);
    static bool isHidden(ZcDbObjectId);

    ZcCmColor         color(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setColor(const ZcCmColor& color, 
                               const ZcDbObjectId& viewportId);

    ZcDbObjectId      linetypeObjectId(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setLinetypeObjectId(const ZcDbObjectId& id, 
                                          const ZcDbObjectId& viewportId);

    ZcDb::LineWeight  lineWeight(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setLineWeight(ZcDb::LineWeight weight, 
                                    const ZcDbObjectId& viewportId);

    Zcad::ErrorStatus plotStyleName(const ZcDbObjectId& viewportId, 
		ZcString &sName, bool& isOverride) const;
    
    ZTCHAR*            plotStyleName(const ZcDbObjectId& viewportId, bool& isOverride) const;
    ZcDbObjectId      plotStyleNameId(const ZcDbObjectId& viewportId, bool& isOverride) const;
    Zcad::ErrorStatus setPlotStyleName(const ZTCHAR* newName,
                                       const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus setPlotStyleName(const ZcDbObjectId& newId, 
                                       const ZcDbObjectId& viewportId);

    ZcCmTransparency  transparency(const ZcDbObjectId& viewportId, bool& isOvr) const;
    Zcad::ErrorStatus setTransparency(const ZcCmTransparency& trans,
                               const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeColorOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeLinetypeOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeLineWeightOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removePlotStyleOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeTransparencyOverride(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeViewportOverrides(const ZcDbObjectId& viewportId);
    Zcad::ErrorStatus removeAllOverrides();

    bool              hasOverrides(const ZcDbObjectId& viewportId) const;
    bool              hasAnyOverrides() const;

    bool              isReconciled() const;
    Zcad::ErrorStatus setIsReconciled(bool bReconcile = true);
    static bool       isReconciled(const ZcDbObjectId& id);

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

Zcad::ErrorStatus applyCurDwgLayerTableChanges();

class ZcDbTextStyleTable;

class ZCDBCORE2D_PORT ZcDbTextStyleTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTextStyleTableRecord);

    ZcDbTextStyleTableRecord();
    virtual ~ZcDbTextStyleTableRecord();

    typedef ZcDbTextStyleTable TableType;

    ZcGiDrawable*     drawable() override;

    ZSoft::Boolean isShapeFile() const;
    void setIsShapeFile(ZSoft::Boolean shape);

    ZSoft::Boolean isVertical() const;
    void setIsVertical(ZSoft::Boolean vertical);

    double textSize() const;
    Zcad::ErrorStatus setTextSize(double size);

    double xScale() const;
    Zcad::ErrorStatus setXScale(double xScale);

    double obliquingAngle() const;
    Zcad::ErrorStatus setObliquingAngle(double obliquingAngle);

    ZSoft::UInt8 flagBits() const;
    void setFlagBits(ZSoft::UInt8 flagBits);

    double priorSize() const;
    Zcad::ErrorStatus setPriorSize(double priorSize);

    Zcad::ErrorStatus fileName(ZcString & sFileName) const;
    Zcad::ErrorStatus fileName(ZTCHAR*& fileName) const;
    Zcad::ErrorStatus fileName(const ZTCHAR*& fileName) const;
    Zcad::ErrorStatus setFileName(const ZTCHAR* fileName);

    Zcad::ErrorStatus bigFontFileName(ZcString & sFileName) const;
    Zcad::ErrorStatus bigFontFileName(ZTCHAR*& fileName) const;
    Zcad::ErrorStatus bigFontFileName(const ZTCHAR*& fileName) const;
    Zcad::ErrorStatus setBigFontFileName(const ZTCHAR* fileName);

    Zcad::ErrorStatus setFont(const ZTCHAR* pTypeface, ZSoft::Boolean bold,
        ZSoft::Boolean italic, Charset charset,
		ZwSoft::ZwCAD::PAL::FontUtils::FontPitch pitch,
		ZwSoft::ZwCAD::PAL::FontUtils::FontFamily family,
		bool bAllowMissingFont = false);
	Zcad::ErrorStatus font(ZcString& pTypeface, bool& bold, bool& italic, Charset& charset, 
		ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch, 
		ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const;
    Zcad::ErrorStatus font(ZTCHAR*& pTypeface, bool& bold, bool& italic, Charset& charset, 
		ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch, 
		ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const;
protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbLinetypeTable;

class ZCDBCORE2D_PORT ZcDbLinetypeTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinetypeTableRecord);

    ZcDbLinetypeTableRecord();
    virtual ~ZcDbLinetypeTableRecord();

    typedef ZcDbLinetypeTable TableType;

    Zcad::ErrorStatus comments(ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(const ZTCHAR*& pString) const;
    Zcad::ErrorStatus comments(ZcString & sComments) const;
    Zcad::ErrorStatus setComments(const ZTCHAR* pString);

    Zcad::ErrorStatus asciiDescription(ZTCHAR*& pString) const
                      { return comments(pString); }
    Zcad::ErrorStatus asciiDescription(const ZTCHAR*& pString) const
                      { return comments(pString); }
    Zcad::ErrorStatus setAsciiDescription(const ZTCHAR* pString)
                      { return setComments(pString); }

    double patternLength() const;
    Zcad::ErrorStatus setPatternLength(double patternLength);

    int    numDashes() const;
    Zcad::ErrorStatus setNumDashes(int count);

    double dashLengthAt(int index) const;
    Zcad::ErrorStatus setDashLengthAt(int index , double value);

    ZcDbObjectId shapeStyleAt(int index) const;
    Zcad::ErrorStatus setShapeStyleAt(int index, ZcDbObjectId id);

    int    shapeNumberAt(int index) const;
    Zcad::ErrorStatus setShapeNumberAt(int index, int shapeNumber);

    ZcGeVector2d shapeOffsetAt(int index) const;
    Zcad::ErrorStatus setShapeOffsetAt(int index, const ZcGeVector2d& offset);

    double shapeScaleAt(int index) const;
    Zcad::ErrorStatus setShapeScaleAt(int index, double scale);

    bool isScaledToFit() const;
    void           setIsScaledToFit(bool scaledToFit);

    bool shapeIsUcsOrientedAt(int index) const;
    Zcad::ErrorStatus setShapeIsUcsOrientedAt(int index, bool isUcsOriented);

    bool           shapeIsUprightAt(int index) const;
    Zcad::ErrorStatus setShapeIsUprightAt(int index, bool isUpright);

    double         shapeRotationAt(int index) const;
	Zcad::ErrorStatus setShapeRotationAt(int index, double rotation);

	Zcad::ErrorStatus textAt(int index, ZcString & sText) const;
    Zcad::ErrorStatus textAt(int index, ZTCHAR*& text) const;
    Zcad::ErrorStatus textAt(int index, const ZTCHAR*& text) const;
    Zcad::ErrorStatus setTextAt(int index, const ZTCHAR* text);

    ZcGiDrawable*     drawable() override;

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbAbstractViewTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbAbstractViewTableRecord);

    ZcDbAbstractViewTableRecord();
    virtual ~ZcDbAbstractViewTableRecord();

    ZcGePoint2d    centerPoint() const;
    void           setCenterPoint(const ZcGePoint2d&);

    double         height() const;
    void           setHeight(double height);

    double         width() const;
    void           setWidth(double width);

    ZcGePoint3d    target() const;
    void           setTarget(const ZcGePoint3d& target);

    ZcGeVector3d   viewDirection() const;
    void           setViewDirection(const ZcGeVector3d& viewDirection);

    double         viewTwist() const;
    void           setViewTwist(double angle);

    double         lensLength() const;
    void           setLensLength(double length);

    double         frontClipDistance() const;
    void           setFrontClipDistance(double distance);

    double         backClipDistance() const;
    void           setBackClipDistance(double distance);

    bool           perspectiveEnabled() const;
    void           setPerspectiveEnabled(bool enabled);

    bool           frontClipEnabled() const;
    void           setFrontClipEnabled(bool enabled);

    bool           backClipEnabled() const;
    void           setBackClipEnabled(bool enabled);

    bool           frontClipAtEye() const;
    void           setFrontClipAtEye(bool atEye);


    const ZcDbObjectId&  background() const;
    ZcDbObjectId&       background();
    Zcad::ErrorStatus   setBackground(const ZcDbObjectId& backgroundId);
    ZcDbObjectId visualStyle() const;
    Zcad::ErrorStatus   setVisualStyle(const ZcDbObjectId& visualStyleId);
    bool                isDefaultLightingOn() const;
    Zcad::ErrorStatus   setDefaultLightingOn(bool on);
    ZcGiViewportTraits::DefaultLightingType defaultLightingType() const;
    Zcad::ErrorStatus   setDefaultLightingType(ZcGiViewportTraits::DefaultLightingType typ);

    double              brightness() const;
    Zcad::ErrorStatus   setBrightness(double);

    double              contrast() const;
    Zcad::ErrorStatus   setContrast(double);

    ZcCmColor           ambientLightColor() const;
    Zcad::ErrorStatus   setAmbientLightColor(const ZcCmColor& clr);

    ZcDbObjectId        sunId() const;
    Zcad::ErrorStatus   setSun(ZcDbObjectId& retId, ZcDbObject* pSun);
    Zcad::ErrorStatus   setSun(ZcDbObjectId &retId, ZcDbObject *pSun, bool eraseOldSun);

    Zcad::ErrorStatus toneOperatorParameters(ZcGiToneOperatorParameters& params) const;
    Zcad::ErrorStatus setToneOperatorParameters(const ZcGiToneOperatorParameters& params);

    Zcad::ErrorStatus getUcs            ( ZcGePoint3d& origin,
                                          ZcGeVector3d& xAxis,
                                          ZcGeVector3d& yAxis ) const;
    bool              isUcsOrthographic ( ZcDb::OrthographicView& view ) const;
    ZcDbObjectId      ucsName           () const;
    double            elevation         () const;

    Zcad::ErrorStatus setUcs        ( const ZcGePoint3d& origin,
                                      const ZcGeVector3d& xAxis,
                                      const ZcGeVector3d& yAxis );
    Zcad::ErrorStatus setUcs        ( ZcDb::OrthographicView view );
    Zcad::ErrorStatus setUcs        ( const ZcDbObjectId& ucsId );
    Zcad::ErrorStatus setUcsToWorld ();
    Zcad::ErrorStatus setElevation  ( double elev );

    bool              isViewOrthographic ( ZcDb::OrthographicView& view ) const;
    Zcad::ErrorStatus setViewDirection   ( ZcDb::OrthographicView view );
};

typedef struct tagBITMAPINFO BITMAPINFO;

class ZcDbViewTable;

class ZCDBCORE2D_PORT ZcDbViewTableRecord: public  ZcDbAbstractViewTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewTableRecord);

    ZcDbViewTableRecord();
    virtual ~ZcDbViewTableRecord();

    typedef ZcDbViewTable TableType;

    Zcad::ErrorStatus setParametersFromViewport(ZcDbObjectId objId);

    bool isPaperspaceView() const;
    void setIsPaperspaceView(bool pspace);
    
    bool    isUcsAssociatedToView   () const;
    Zcad::ErrorStatus disassociateUcsFromView ();

    Zcad::ErrorStatus getCategoryName(ZcString & sCategoryName) const;
    Zcad::ErrorStatus getCategoryName(ZTCHAR *& categoryName) const;
    Zcad::ErrorStatus setCategoryName(const ZTCHAR * categoryName);

    Zcad::ErrorStatus getLayerState(ZcString & layerStateName) const;
    Zcad::ErrorStatus getLayerState(ZTCHAR*& layerStateName) const;
    Zcad::ErrorStatus setLayerState(const ZTCHAR *layerStateName);
 
    Zcad::ErrorStatus getLayout (ZcDbObjectId& layoutId) const;
    Zcad::ErrorStatus setLayout(ZcDbObjectId layoutId);

    bool              isViewAssociatedToViewport () const;
    Zcad::ErrorStatus setViewAssociatedToViewport (bool bVPflag);

    bool              isCameraPlottable () const;
    Zcad::ErrorStatus setIsCameraPlottable (bool plottable);

    ZcDbObjectId      liveSection() const;
    Zcad::ErrorStatus setLiveSection(const ZcDbObjectId& liveSectionId);

    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;

    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);

    Zcad::ErrorStatus getPreviewImage(Ztil::Image*& pPreviewImage) const;

    Zcad::ErrorStatus setPreviewImage (const Ztil::Image* pPreviewImage);

    ZcDbObjectId      camera          () const;
    Zcad::ErrorStatus setCamera(ZcDbObjectId cameraId);

    ZcDbAnnotationScale* annotationScale() const;
    Zcad::ErrorStatus setAnnotationScale(const ZcDbAnnotationScale* pScaleObj);

    ZcDbObjectId      sunId() const;
    Zcad::ErrorStatus setSun(ZcDbObjectId& retId, ZcDbObject* pSun);
    Zcad::ErrorStatus setSun(ZcDbObjectId &retId, ZcDbObject *pSun, bool eraseOldSun);

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbUCSTable;

class ZCDBCORE2D_PORT ZcDbUCSTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbUCSTableRecord);

    ZcDbUCSTableRecord();
    virtual ~ZcDbUCSTableRecord();

    typedef ZcDbUCSTable TableType;

    ZcGePoint3d  origin() const;
    void         setOrigin(const ZcGePoint3d& newOrigin);

    ZcGeVector3d xAxis() const;
    void         setXAxis(const ZcGeVector3d& xAxis);

    ZcGeVector3d yAxis() const;
    void         setYAxis(const ZcGeVector3d& yAxis);

    ZcGePoint3d       ucsBaseOrigin    ( ZcDb::OrthographicView view ) const;
    Zcad::ErrorStatus setUcsBaseOrigin ( const ZcGePoint3d& origin,
                                         ZcDb::OrthographicView view );

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbViewportTable;

class ZCDBCORE2D_PORT ZcDbViewportTableRecord: public  ZcDbAbstractViewTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbViewportTableRecord);

    ZcDbViewportTableRecord();
    virtual ~ZcDbViewportTableRecord();

    typedef ZcDbViewportTable TableType;

    ZSoft::Int16   number()  const;

    ZcGePoint2d    lowerLeftCorner() const;
    void           setLowerLeftCorner(const ZcGePoint2d& pt);

    ZcGePoint2d    upperRightCorner() const;
    void           setUpperRightCorner(const ZcGePoint2d& pt);

    bool           ucsFollowMode() const;
    void           setUcsFollowMode(bool enabled);

    ZSoft::UInt16  circleSides() const;
    void           setCircleSides(ZSoft::UInt16 circleSides);

	bool           fastZoomsEnabled() const { return true; }
	void           setFastZoomsEnabled(bool enabled) { enabled; }

    bool           iconEnabled() const;
    void           setIconEnabled(bool enabled);

    bool           iconAtOrigin() const;
    void           setIconAtOrigin(bool atOrigin);

    bool           gridEnabled() const;
    void           setGridEnabled(bool enabled);

    ZcGePoint2d    gridIncrements() const;
    void           setGridIncrements(const ZcGePoint2d& base);

    bool           snapEnabled() const;
    void           setSnapEnabled(bool enabled);

    bool           isometricSnapEnabled() const;
    void           setIsometricSnapEnabled(bool enabled);

    ZSoft::Int16   snapPair() const;
    void           setSnapPair(ZSoft::Int16 pairType);

    double         snapAngle() const;
    void           setSnapAngle(double angle);

    ZcGePoint2d    snapBase() const;
    void           setSnapBase(const ZcGePoint2d& base);

    ZcGePoint2d    snapIncrements() const;
    void           setSnapIncrements(const ZcGePoint2d& base);

    void           setGsView(ZcGsView* pView);
    ZcGsView*      gsView() const;

    bool           isUcsSavedWithViewport () const;
    void           setUcsPerViewport ( bool ucsvp );

    bool           isGridBoundToLimits() const;
    void           setGridBoundToLimits(bool enabled);

    bool           isGridAdaptive() const;
    void           setGridAdaptive(bool enabled);

    bool           isGridSubdivisionRestricted() const;
    void           setGridSubdivisionRestricted(bool enabled);

    bool           isGridFollow() const;
    void           setGridFollow(bool enabled);

    ZSoft::Int16   gridMajor() const;
    void           setGridMajor(ZSoft::Int16 value);

    Zcad::ErrorStatus   setBackground(const ZcDbObjectId& backgroundId);
    ZcDbObjectId        previousBackground(ZcGiDrawable::DrawableType type
                                           = ZcGiDrawable::kGeometry) const;
    Zcad::ErrorStatus   setPreviousBackground(ZcDbObjectId backgroundId,
                                              ZcGiDrawable::DrawableType type
                                              = ZcGiDrawable::kGeometry);
    Zcad::ErrorStatus   setPreviousBackground(ZcDbObjectId backgroundId,
                                              ZcGiDrawable::DrawableType type,
                                              bool bForcedSwitch);
    bool                previousBackgroundForcedSwitch (void) const;

    ZcGiDrawable*  drawable() override;
	
protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbRegAppTable;

class ZCDBCORE2D_PORT ZcDbRegAppTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbRegAppTableRecord);

    ZcDbRegAppTableRecord();
    virtual ~ZcDbRegAppTableRecord();

    typedef ZcDbRegAppTable TableType;

protected:
   virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;  
};

class ZcDbDimStyleTable;

class ZCDBCORE2D_PORT ZcDbDimStyleTableRecord: public  ZcDbSymbolTableRecord
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDimStyleTableRecord);

    ZcDbDimStyleTableRecord();
    virtual ~ZcDbDimStyleTableRecord();

    typedef ZcDbDimStyleTable TableType;

    #undef ZDBDIMVAR_H         
    #include "zdbdimvar.h"

    ZcDbObjectId      arrowId(ZcDb::DimArrowFlags whichArrow) const;

    Zcad::ErrorStatus getDimpost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimapost(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk(ZcString & sOutput) const;
    Zcad::ErrorStatus getDimblk(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk1(ZcString & sOutput) const;
    Zcad::ErrorStatus getDimblk1(ZTCHAR*& pOutput) const;
    Zcad::ErrorStatus getDimblk2(ZcString & sOutput) const;
    Zcad::ErrorStatus getDimblk2(ZTCHAR*& pOutput) const;

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit(int fit);
    Zcad::ErrorStatus setDimunit(int unit);

    bool isModifiedForRecompute() const;    

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbSymbolTable: public ZcDbObject
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbSymbolTable);
	ZcDbSymbolTable();
	virtual ~ZcDbSymbolTable();

	typedef ZcDbSymbolTableRecord RecordType;
    typedef ZcDbSymbolTableIterator IteratorType;

    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbSymbolTableRecord*& pRec,
                             ZcDb::OpenMode openMode = ZcDb::kForRead,
                             bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }

    Zcad::ErrorStatus getIdAt(const ZTCHAR* entryName,
                                              ZcDbObjectId& recordId,
                                              bool getErasedRecord = false) const;
    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }

    bool has(const ZTCHAR* name) const
    {
        ZcDbObjectId id;
        this->assertReadEnabled();
        return this->getIdAt(name, id) == Zcad::eOk;
    }

	bool              has(ZcDbObjectId id) const;
	Zcad::ErrorStatus newIterator(ZcDbSymbolTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;

	Zcad::ErrorStatus add(ZcDbSymbolTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId& recordId, ZcDbSymbolTableRecord* pRecord);

  protected:
    template<class RecordType> Zcad::ErrorStatus openAt(const ZTCHAR* entryName,
                    RecordType * & pRec, ZcDb::OpenMode nMode, bool bOpenErased) const
    {
        pRec = nullptr;
        ZcDbObjectId id;
        Zcad::ErrorStatus es = this->getIdAt(entryName, id, bOpenErased);
        if (es == Zcad::eOk)
            es = ::zcdbOpenObject(pRec, id, nMode, bOpenErased);
        return es;
    }
};

class ZCDBCORE2D_PORT ZcDbBlockTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbBlockTable);
	ZcDbBlockTable();
	virtual ~ZcDbBlockTable();

	typedef ZcDbBlockTableRecord RecordType;
    typedef ZcDbBlockTableIterator IteratorType;

    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbBlockTableRecord*& pRec,
                             ZcDb::OpenMode openMode = ZcDb::kForRead,
                             bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }

    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRec = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRec);
    }
	Zcad::ErrorStatus newIterator(ZcDbBlockTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbBlockTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId& recordId, ZcDbBlockTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbLayerTableRecord;
class ZcDbLayerTableIterator;

class ZCDBCORE2D_PORT ZcDbLayerTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbLayerTable);
	ZcDbLayerTable();
	virtual ~ZcDbLayerTable();

	typedef ZcDbLayerTableRecord RecordType;
    typedef ZcDbLayerTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbLayerTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }
	Zcad::ErrorStatus newIterator(ZcDbLayerTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbLayerTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId& recordId, ZcDbLayerTableRecord* pRecord);

	void generateUsageData();

	bool hasUnreconciledLayers() const;
	Zcad::ErrorStatus getUnreconciledLayers(ZcDbObjectIdArray& idArray) const;

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbTextStyleTableRecord;
class ZcDbTextStyleTableIterator;

class ZCDBCORE2D_PORT ZcDbTextStyleTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbTextStyleTable);
	ZcDbTextStyleTable();
	virtual ~ZcDbTextStyleTable();

	typedef ZcDbTextStyleTableRecord RecordType;
    typedef ZcDbTextStyleTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbTextStyleTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt (const ZTCHAR* entryName,
                             ZcDbObjectId& recordId,
                             bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }
	Zcad::ErrorStatus newIterator(ZcDbTextStyleTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbTextStyleTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId&  recordId,
		ZcDbTextStyleTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbLinetypeTableRecord;
class ZcDbLinetypeTableIterator;

class ZCDBCORE2D_PORT ZcDbLinetypeTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbLinetypeTable);
	ZcDbLinetypeTable();
	virtual ~ZcDbLinetypeTable();

	typedef ZcDbLinetypeTableRecord RecordType;
    typedef ZcDbLinetypeTableIterator IteratorType;

	Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
		ZcDbLinetypeTableRecord*& pRec,
		ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
	Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
		ZcDbObjectId& recordId,
                            bool getErasedRec = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRec);
    }
	Zcad::ErrorStatus newIterator(ZcDbLinetypeTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbLinetypeTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId& recordId,
		ZcDbLinetypeTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbAbstractViewTableRecord;
class ZcDbAbstractViewTableIterator;

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbAbstractViewTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbAbstractViewTable);
	ZcDbAbstractViewTable();
	virtual ~ZcDbAbstractViewTable();
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbAbstractViewTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }
	Zcad::ErrorStatus newIterator(ZcDbAbstractViewTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbAbstractViewTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId&  recordId,
		ZcDbAbstractViewTableRecord* pRecord);
};

class ZcDbViewTableRecord;
class ZcDbViewTableIterator;

class ZCDBCORE2D_PORT ZcDbViewTable: public ZcDbAbstractViewTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbViewTable);
	ZcDbViewTable();
	virtual ~ZcDbViewTable();

	typedef ZcDbViewTableRecord RecordType;
    typedef ZcDbViewTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbViewTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRec = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRec);
    }
    Zcad::ErrorStatus newIterator(ZcDbViewTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbViewTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId&  recordId,
		ZcDbViewTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbUCSTableRecord;
class ZcDbUCSTableIterator;

class ZCDBCORE2D_PORT ZcDbUCSTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbUCSTable);
	ZcDbUCSTable();
	virtual ~ZcDbUCSTable();

	typedef ZcDbUCSTableRecord RecordType;
    typedef ZcDbUCSTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbUCSTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }
	Zcad::ErrorStatus newIterator(ZcDbUCSTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbUCSTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId&  recordId,
		ZcDbUCSTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbViewportTableRecord;
class ZcDbViewportTableIterator;

class ZCDBCORE2D_PORT ZcDbViewportTable: public ZcDbAbstractViewTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbViewportTable);
	ZcDbViewportTable();
	virtual ~ZcDbViewportTable();

	typedef ZcDbViewportTableRecord RecordType;
    typedef ZcDbViewportTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbViewportTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRecord = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRecord);
    }
	Zcad::ErrorStatus newIterator(ZcDbViewportTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus add(ZcDbViewportTableRecord* pRecord);
	Zcad::ErrorStatus add(ZcDbObjectId& recordId,
		ZcDbViewportTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbRegAppTableRecord;
class ZcDbRegAppTableIterator;

class ZCDBCORE2D_PORT ZcDbRegAppTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbRegAppTable);
	ZcDbRegAppTable();
	virtual ~ZcDbRegAppTable();

	typedef ZcDbRegAppTableRecord RecordType;
    typedef ZcDbRegAppTableIterator IteratorType;

    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbRegAppTableRecord*& pRec,
                            ZcDb::OpenMode openMode = ZcDb::kForRead,
                            bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus getAt(const ZTCHAR* entryName,
                            ZcDbObjectId& recordId,
                            bool getErasedRec = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRec);
    }
	Zcad::ErrorStatus newIterator(ZcDbRegAppTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus   add(ZcDbRegAppTableRecord* pRecord);
	Zcad::ErrorStatus   add(ZcDbObjectId&  recordId,
		ZcDbRegAppTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZcDbDimStyleTableRecord;
class ZcDbDimStyleTableIterator;

class ZCDBCORE2D_PORT ZcDbDimStyleTable: public ZcDbSymbolTable
{
public:
	ZCDB_DECLARE_MEMBERS(ZcDbDimStyleTable);
	ZcDbDimStyleTable();
	virtual ~ZcDbDimStyleTable();

	typedef ZcDbDimStyleTableRecord RecordType;
    typedef ZcDbDimStyleTableIterator IteratorType;

    Zcad::ErrorStatus   getAt   (const ZTCHAR* entryName,
                                 ZcDbDimStyleTableRecord*& pRec,
                                 ZcDb::OpenMode openMode = ZcDb::kForRead,
                                 bool openErasedRec = false) const
    {
        return this->openAt(entryName, pRec, openMode, openErasedRec);
    }
    Zcad::ErrorStatus   getAt   (const ZTCHAR* entryName,
                                 ZcDbObjectId& recordId,
                                 bool getErasedRec = false) const
    {
        return this->getIdAt(entryName, recordId, getErasedRec);
    }
	Zcad::ErrorStatus   newIterator(ZcDbDimStyleTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	Zcad::ErrorStatus   add(ZcDbDimStyleTableRecord* pRecord);
	Zcad::ErrorStatus   add(ZcDbObjectId&  recordId,
		ZcDbDimStyleTableRecord* pRecord);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbSymbolTableIterator
{
public:
	virtual ~ZcDbSymbolTableIterator();

	void                start   (bool atBeginning = true,
		bool skipDeleted = true);

	bool                done    () const;

	Zcad::ErrorStatus   getRecordId(ZcDbObjectId& id) const;

    Zcad::ErrorStatus   getRecord(ZcDbSymbolTableRecord*& pRecord,
                                 ZcDb::OpenMode openMode = ZcDb::kForRead,
                                 bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

	void                step    (bool forward = true,
		bool skipDeleted = true);

	Zcad::ErrorStatus   seek    (ZcDbObjectId id);

	Zcad::ErrorStatus   seek    (const ZcDbSymbolTableRecord* pRecord);
protected:
    template<class RecordType> Zcad::ErrorStatus openRecord(RecordType * & pRec,
                                 ZcDb::OpenMode nMode, bool bOpenErased) const
    {
        pRec = nullptr;
        ZcDbObjectId id;
        Zcad::ErrorStatus es = this->getRecordId(id);
        if (es == Zcad::eOk)
            es = ::zcdbOpenObject(pRec, id, nMode, bOpenErased);
        return es;
    }
                                                
    class ZcDbSymbolTableIteratorImp * mpImp;
	ZcDbSymbolTableIterator();
	friend class ZcDbSymbolTable;
};

class ZCDBCORE2D_PORT ZcDbBlockTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbBlockTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbBlockTableIterator();
	friend class ZcDbBlockTable;
};

class ZCDBCORE2D_PORT ZcDbLayerTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbLayerTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }
	bool getSkipHidden() const;
	void setSkipHidden(bool value);
	bool getSkipReconciled() const;
	void setSkipReconciled(bool value);
protected:
	ZcDbLayerTableIterator();
	friend class ZcDbLayerTable;
};

class ZCDBCORE2D_PORT ZcDbTextStyleTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbTextStyleTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbTextStyleTableIterator();
	friend class ZcDbTextStyleTable;
};

class ZCDBCORE2D_PORT ZcDbLinetypeTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbLinetypeTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbLinetypeTableIterator();
	friend class ZcDbLinetypeTable;
};

class ZCDBCORE2D_PORT ZcDbAbstractViewTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbAbstractViewTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbAbstractViewTableIterator();
	friend class ZcDbAbstractViewTable;
};

class ZCDBCORE2D_PORT ZcDbViewTableIterator : public ZcDbAbstractViewTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbViewTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbViewTableIterator();
	friend class ZcDbViewTable;
};

class ZCDBCORE2D_PORT ZcDbUCSTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbUCSTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbUCSTableIterator();
	friend class ZcDbUCSTable;
};

class ZCDBCORE2D_PORT ZcDbViewportTableIterator : public ZcDbAbstractViewTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbViewportTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbViewportTableIterator();
	friend class ZcDbViewportTable;
};

class ZCDBCORE2D_PORT ZcDbRegAppTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbRegAppTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbRegAppTableIterator();
	friend class ZcDbRegAppTable;
};

class ZCDBCORE2D_PORT ZcDbDimStyleTableIterator : public ZcDbSymbolTableIterator
{
public:
    Zcad::ErrorStatus getRecord(ZcDbDimStyleTableRecord*& pRecord,
        ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedRec = false) const
    {
        return this->openRecord(pRecord, openMode, openErasedRec);
    }

protected:
	ZcDbDimStyleTableIterator();
	friend class ZcDbDimStyleTable;
};

class ZCDBCORE2D_PORT ZcDbBlockTableRecordIterator
{
public:
	virtual ~ZcDbBlockTableRecordIterator();

	void              start (bool atBeginning = true,
		bool skipDeleted = true);

	bool              done  () const;

	Zcad::ErrorStatus getEntityId (ZcDbObjectId& entityId) const;

	Zcad::ErrorStatus getEntity(ZcDbEntity*& pEntity, ZcDb::OpenMode openMode = ZcDb::kForRead,
		bool openErasedEntity = false) const;

	ZcDbBlockTableRecord* blockTableRecord() const;

	void              step (bool forward = true,
		bool skipDeleted = true);

	Zcad::ErrorStatus seek (ZcDbObjectId id);

	Zcad::ErrorStatus seek (const ZcDbEntity* pEntity);

protected:
	class ZcDbImpBlockTableRecordIterator * mpImp;
private:
	ZcDbBlockTableRecordIterator();
	friend class ZcDbImpBlockTableRecord;
};

class ZCDBCORE2D_PORT ZcDbBlockReferenceIdIterator
{
public:
	~ZcDbBlockReferenceIdIterator();

	void              start () { mPos = 0; }

	bool              done  () const { return mPos >= mAry.length(); }

	Zcad::ErrorStatus getBlockReferenceId (ZcDbObjectId& id) const;

	Zcad::ErrorStatus getDatabase (ZcDbDatabase*& pDb) const;

	Zcad::ErrorStatus getBlockReference(ZcDbBlockReference*& pBlkRef,
		ZcDb::OpenMode openMode = ZcDb::kForRead, bool openErasedEntity = false) const;

	void              step () { mPos++; }

	Zcad::ErrorStatus seek (ZcDbObjectId id);

private:
	ZcDbBlockReferenceIdIterator();
	friend class ZcDbBlockTableRecord;

	int               mPos;
	ZcDbObjectIdArray mAry;
};

#pragma pack(pop)

inline Zcad::ErrorStatus ZcDbSymbolTableRecord::getName(ZTCHAR*& pName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbSymbolTableRecord::getName, pName);
}
inline Zcad::ErrorStatus ZcDbBlockTableRecord::comments(ZTCHAR*& pComments) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbBlockTableRecord::comments, pComments);
}
inline Zcad::ErrorStatus ZcDbBlockTableRecord::pathName(ZTCHAR*& pPath) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbBlockTableRecord::pathName, pPath);
}
inline ZTCHAR * ZcDbLayerTableRecord::plotStyleName() const
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, this->plotStyleName(sName));
}
inline ZTCHAR * ZcDbLayerTableRecord::plotStyleName(const ZcDbObjectId& viewportId,
                                                   bool& isOverride) const
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, this->plotStyleName(viewportId, sName, isOverride));
}
inline ZTCHAR * ZcDbLayerTableRecord::description() const
{
    ZcString sDescription;
    return ::zcutZcStringToZTChar(sDescription, this->description(sDescription));
}
inline Zcad::ErrorStatus ZcDbTextStyleTableRecord::fileName(ZTCHAR*& fileName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbTextStyleTableRecord::fileName, fileName);
}
inline Zcad::ErrorStatus ZcDbTextStyleTableRecord::bigFontFileName(ZTCHAR*& fileName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbTextStyleTableRecord::bigFontFileName, fileName);
}
inline Zcad::ErrorStatus ZcDbTextStyleTableRecord::font(ZTCHAR*& pTypeface,
                                        bool & bold,
                                        bool & italic,
                                        Charset& charset,
                                        ZwSoft::ZwCAD::PAL::FontUtils::FontPitch& pitch,
                                        ZwSoft::ZwCAD::PAL::FontUtils::FontFamily& family) const
{
    pTypeface = nullptr;
    ZcString sTypeface;
    const Zcad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
    if (es == Zcad::eOk)
        ::zcutNewString(sTypeface.kwszPtr(), pTypeface);
    return es;
}
inline Zcad::ErrorStatus ZcDbLinetypeTableRecord::comments(ZTCHAR*& pComments) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbLinetypeTableRecord::comments, pComments);
}
inline Zcad::ErrorStatus ZcDbLinetypeTableRecord::textAt(int nIndex, ZTCHAR*& pText) const
{
    ZcString sText;
    return ::zcutZcStringToZTChar(sText, pText, this->textAt(nIndex, sText));
}

inline Zcad::ErrorStatus ZcDbViewTableRecord::getCategoryName(ZTCHAR*& pCategoryName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbViewTableRecord::getCategoryName, pCategoryName);
}
inline Zcad::ErrorStatus ZcDbViewTableRecord::getLayerState(ZTCHAR*& pLayerStateName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbViewTableRecord::getLayerState, pLayerStateName);
}
inline Zcad::ErrorStatus ZcDbDimStyleTableRecord::getDimpost(ZTCHAR *& pOutput) const
{
    return ::zcutNewString(this->dimpost(), pOutput);
}

inline Zcad::ErrorStatus ZcDbDimStyleTableRecord::getDimapost(ZTCHAR *& pOutput) const
{
    return ::zcutNewString(this->dimapost(), pOutput);
}
inline Zcad::ErrorStatus ZcDbDimStyleTableRecord::getDimblk(ZTCHAR *& pOutput) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbDimStyleTableRecord::getDimblk, pOutput);
}
inline Zcad::ErrorStatus ZcDbDimStyleTableRecord::getDimblk1(ZTCHAR *& pOutput) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbDimStyleTableRecord::getDimblk1, pOutput);
}
inline Zcad::ErrorStatus ZcDbDimStyleTableRecord::getDimblk2(ZTCHAR *& pOutput) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbDimStyleTableRecord::getDimblk2, pOutput);
}

#endif
