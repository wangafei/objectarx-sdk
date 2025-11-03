/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBSYMTB_H
#define GD_DBSYMTB_H

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbBackground.h"
#include "gevec2d.h"
#include "gcgiviewport.h"
#include "gcgivisualstyle.h"
#include "GcDbCore2dDefs.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"

#pragma pack(push, 8)

#ifdef target
# undef target 
#endif

class GcDbSortentsTable;
class GcDbSymbolTableIterator;
class GcDbSymbolTable;
class GcDbAnnotationScale;
class GcGsView;
class GcString;

namespace Gtil
{
  class Image;
}

class GSOFT_NO_VTABLE GCDB_PORT GcDbSymbolTableRecord : public  GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSymbolTableRecord);
  GcDbSymbolTableRecord();
  ~GcDbSymbolTableRecord();

  typedef GcDbSymbolTable TableType;

  Gcad::ErrorStatus getName(GCHAR*& pName) const;
  Gcad::ErrorStatus getName(GcString & sName) const;
  Gcad::ErrorStatus getName(const GCHAR*& pName) const;
  Gcad::ErrorStatus setName(const GCHAR* pName);

  bool isDependent() const;
  bool isResolved() const;
  bool isRenamable() const;
};

class GcDbBlockTable;
class GcDbBlockTableIterator;
class GcDbBlockTableRecordIterator;
class GcDbBlockReferenceIdIterator;

class GCDB_PORT GcDbBlockTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbBlockTableRecord);
  GcDbBlockTableRecord();
  ~GcDbBlockTableRecord();

  typedef GcDbBlockTable TableType;
  typedef GcArray<Gsoft::UInt8> PreviewIcon;

  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  Gcad::ErrorStatus appendGcDbEntity(GcDbEntity* pEntity)
  {
    GcDbObjectId id;
    return this->appendGcDbEntity(id, pEntity);
  }

  Gcad::ErrorStatus appendGcDbEntity(GcDbObjectId& pOutputId, GcDbEntity* pEntity);
  Gcad::ErrorStatus newIterator(
    GcDbBlockTableRecordIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;

  Gcad::ErrorStatus comments(GCHAR*& pString) const;
  Gcad::ErrorStatus comments(const GCHAR*& pString) const;
  Gcad::ErrorStatus comments(GcString & sComments) const;
  Gcad::ErrorStatus setComments(const GCHAR* pString);

  Gcad::ErrorStatus pathName(GCHAR*& pPath) const;
  Gcad::ErrorStatus pathName(const GCHAR*& pPath) const;
  Gcad::ErrorStatus pathName(GcString & sPath) const;
  Gcad::ErrorStatus setPathName(const GCHAR* pathStr);

  GcGePoint3d       origin() const;
  Gcad::ErrorStatus setOrigin(const GcGePoint3d& pt);

  Gcad::ErrorStatus openBlockBegin(GcDbBlockBegin*& pBlockBegin,
    GcDb::OpenMode   openMode = GcDb::kForRead);
  Gcad::ErrorStatus openBlockEnd(GcDbBlockEnd*& pBlockEnd,
    GcDb::OpenMode openMode = GcDb::kForRead);

  bool              hasAttributeDefinitions() const;
  bool              hasPreviewIcon() const;
  Gcad::ErrorStatus getPreviewIcon(PreviewIcon &previewIcon) const;
  Gcad::ErrorStatus setPreviewIcon(const PreviewIcon &previewIcon);
  bool              isAnonymous() const;
  bool              isFromExternalReference() const;
  bool              isFromOverlayReference() const;
  Gcad::ErrorStatus setIsFromOverlayReference(bool bIsOverlay);
  bool              isLayout() const;
  GcDbObjectId      getLayoutId() const;
  Gcad::ErrorStatus setLayoutId(GcDbObjectId);

  Gcad::ErrorStatus newBlockReferenceIdIterator(GcDbBlockReferenceIdIterator*& pIter) const;
  Gcad::ErrorStatus getBlockReferenceIds(GcDbObjectIdArray& ids,
    bool bDirectOnly = true,
    bool bForceValidity = false) const;
  Gcad::ErrorStatus getErasedBlockReferenceIds(GcDbObjectIdArray&);

  Gcad::ErrorStatus getSortentsTable(GcDbSortentsTable*& pSortents,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool createIfNecessary = false);

  GcDbDatabase*     xrefDatabase(bool incUnres = false) const;
  bool              isUnloaded() const;
  Gcad::ErrorStatus setIsUnloaded(bool isUnloaded);
  GcDb::XrefStatus  xrefStatus() const;
  GcGiDrawable*     drawable() override;
  Gcad::ErrorStatus decomposeForSave(GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj,
    GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData) override;

  virtual Gcad::ErrorStatus assumeOwnershipOf(const GcDbObjectIdArray &entitiesToMove);

  enum BlockScaling {
    kAny,
    kUniform
  };

  GcDbBlockTableRecord::BlockScaling blockScaling() const;
  Gcad::ErrorStatus  setBlockScaling(GcDbBlockTableRecord::BlockScaling blockScaling);

  Gcad::ErrorStatus setExplodable(bool bExplodable);
  bool              explodable() const;

  Gcad::ErrorStatus setBlockInsertUnits(GcDb::UnitsValue insunits);
  GcDb::UnitsValue  blockInsertUnits() const;
  Gcad::ErrorStatus postProcessAnnotativeBTR(int& stripCnt, bool bqueryOnly = false, bool bScale = true);
  Gcad::ErrorStatus addAnnoScalestoBlkRefs(bool bScale = false);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbLayerTable;

class GCDB_PORT GcDbLayerTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLayerTableRecord);
  GcDbLayerTableRecord();
  ~GcDbLayerTableRecord();

  typedef GcDbLayerTable TableType;

  bool              isFrozen() const;
  Gcad::ErrorStatus setIsFrozen(bool frozen);
  bool              isOff() const;
  void              setIsOff(bool off);
  bool              VPDFLT() const;
  void              setVPDFLT(bool frozen);
  bool              isLocked() const;
  void              setIsLocked(bool locked);
  GcCmColor         color() const;
  void              setColor(const GcCmColor &color);
  GcCmEntityColor   entityColor(void) const;
  GcCmTransparency  transparency(void) const;
  Gcad::ErrorStatus setTransparency(const GcCmTransparency& trans);
  GcDbObjectId      linetypeObjectId() const;
  Gcad::ErrorStatus setLinetypeObjectId(GcDbObjectId id);
  GcDbObjectId      materialId() const;
  Gcad::ErrorStatus setMaterialId(GcDbObjectId id);

  enum { kDxfLayerPlotBit = GcDb::kDxfBool };
  bool              isPlottable() const;
  Gcad::ErrorStatus setIsPlottable(bool plot);
  GcDb::LineWeight  lineWeight() const;
  Gcad::ErrorStatus setLineWeight(GcDb::LineWeight weight);
  GCHAR*            plotStyleName() const;
  Gcad::ErrorStatus plotStyleName(GcString &) const;
  GcDbObjectId      plotStyleNameId() const;
  Gcad::ErrorStatus setPlotStyleName(const GCHAR* newName);
  Gcad::ErrorStatus setPlotStyleName(const GcDbObjectId& newId);
  GcGiDrawable*     drawable() override;
  bool              isInUse() const;
  GCHAR*            description() const;
  Gcad::ErrorStatus description(GcString &) const;
  Gcad::ErrorStatus setDescription(const GCHAR* description);
  bool              isHidden() const;
  Gcad::ErrorStatus setIsHidden(bool on);
  static bool       isHidden(GcDbObjectId);

  GcCmColor         color(const GcDbObjectId& viewportId, bool& isOverride) const;
  Gcad::ErrorStatus setColor(const GcCmColor& color, const GcDbObjectId& viewportId);

  GcDbObjectId      linetypeObjectId(const GcDbObjectId& viewportId, bool& isOverride) const;
  Gcad::ErrorStatus setLinetypeObjectId(const GcDbObjectId& id, const GcDbObjectId& viewportId);

  GcDb::LineWeight  lineWeight(const GcDbObjectId& viewportId, bool& isOverride) const;
  Gcad::ErrorStatus setLineWeight(GcDb::LineWeight weight, const GcDbObjectId& viewportId);

  Gcad::ErrorStatus plotStyleName(const GcDbObjectId& viewportId, GcString &sName, bool& isOverride) const;
  GCHAR*            plotStyleName(const GcDbObjectId& viewportId, bool& isOverride) const;
  GcDbObjectId      plotStyleNameId(const GcDbObjectId& viewportId, bool& isOverride) const;
  Gcad::ErrorStatus setPlotStyleName(const GCHAR* newName, const GcDbObjectId& viewportId);
  Gcad::ErrorStatus setPlotStyleName(const GcDbObjectId& newId, const GcDbObjectId& viewportId);

  GcCmTransparency  transparency(const GcDbObjectId& viewportId, bool& isOvr) const;
  Gcad::ErrorStatus setTransparency(const GcCmTransparency& trans, const GcDbObjectId& viewportId);

  Gcad::ErrorStatus removeColorOverride(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removeLinetypeOverride(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removeLineWeightOverride(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removePlotStyleOverride(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removeTransparencyOverride(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removeViewportOverrides(const GcDbObjectId& viewportId);
  Gcad::ErrorStatus removeAllOverrides();

  bool              hasOverrides(const GcDbObjectId& viewportId) const;
  bool              hasAnyOverrides() const;
  bool              isReconciled() const;
  Gcad::ErrorStatus setIsReconciled(bool bReconcile = true);
  static bool       isReconciled(const GcDbObjectId& id);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

GCDB_PORT Gcad::ErrorStatus applyCurDwgLayerTableChanges();

class GcDbTextStyleTable;

class GCDB_PORT GcDbTextStyleTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTextStyleTableRecord);

  GcDbTextStyleTableRecord();
  ~GcDbTextStyleTableRecord();

  typedef GcDbTextStyleTable TableType;

  GcGiDrawable*     drawable() override;

  Gsoft::Boolean isShapeFile() const;
  void setIsShapeFile(Gsoft::Boolean shape);

  Gsoft::Boolean isVertical() const;
  void setIsVertical(Gsoft::Boolean vertical);

  double textSize() const;
  Gcad::ErrorStatus setTextSize(double size);

  double xScale() const;
  Gcad::ErrorStatus setXScale(double xScale);

  double obliquingAngle() const;
  Gcad::ErrorStatus setObliquingAngle(double obliquingAngle);

  Gsoft::UInt8 flagBits() const;
  void setFlagBits(Gsoft::UInt8 flagBits);

  double priorSize() const;
  Gcad::ErrorStatus setPriorSize(double priorSize);

  Gcad::ErrorStatus fileName(GcString & sFileName) const;
  Gcad::ErrorStatus fileName(GCHAR*& fileName) const;
  Gcad::ErrorStatus fileName(const GCHAR*& fileName) const;
  Gcad::ErrorStatus setFileName(const GCHAR* fileName);

  Gcad::ErrorStatus bigFontFileName(GcString & sFileName) const;
  Gcad::ErrorStatus bigFontFileName(GCHAR*& fileName) const;
  Gcad::ErrorStatus bigFontFileName(const GCHAR*& fileName) const;
  Gcad::ErrorStatus setBigFontFileName(const GCHAR* fileName);

  Gcad::ErrorStatus setFont(const GCHAR* pTypeface, Gsoft::Boolean bold,
    Gsoft::Boolean italic, Charset charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily family,
    bool bAllowMissingFont = false);
  Gcad::ErrorStatus font(GcString & sTypeface,
    bool & bold,
    bool & italic,
    Charset& charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const;
  Gcad::ErrorStatus font(GCHAR*& pTypeface,
    Gsoft::Boolean& bold,
    Gsoft::Boolean& italic,
    Charset& charset,
    Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
    Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const;
protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbLinetypeTable;

class GCDB_PORT GcDbLinetypeTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLinetypeTableRecord);

  GcDbLinetypeTableRecord();
  ~GcDbLinetypeTableRecord();

  typedef GcDbLinetypeTable TableType;

  Gcad::ErrorStatus comments(GCHAR*& pString) const;
  Gcad::ErrorStatus comments(const GCHAR*& pString) const;
  Gcad::ErrorStatus comments(GcString & sComments) const;
  Gcad::ErrorStatus setComments(const GCHAR* pString);

  Gcad::ErrorStatus asciiDescription(GCHAR*& pString) const
  {
    return comments(pString);
  }
  Gcad::ErrorStatus asciiDescription(const GCHAR*& pString) const
  {
    return comments(pString);
  }
  Gcad::ErrorStatus setAsciiDescription(const GCHAR* pString)
  {
    return setComments(pString);
  }

  double            patternLength() const;
  Gcad::ErrorStatus setPatternLength(double patternLength);

  int               numDashes() const;
  Gcad::ErrorStatus setNumDashes(int count);

  double            dashLengthAt(int index) const;
  Gcad::ErrorStatus setDashLengthAt(int index, double value);

  GcDbObjectId      shapeStyleAt(int index) const;
  Gcad::ErrorStatus setShapeStyleAt(int index, GcDbObjectId id);

  int               shapeNumberAt(int index) const;
  Gcad::ErrorStatus setShapeNumberAt(int index, int shapeNumber);

  GcGeVector2d      shapeOffsetAt(int index) const;
  Gcad::ErrorStatus setShapeOffsetAt(int index, const GcGeVector2d& offset);

  double            shapeScaleAt(int index) const;
  Gcad::ErrorStatus setShapeScaleAt(int index, double scale);

  bool              isScaledToFit() const;
  void              setIsScaledToFit(bool scaledToFit);

  bool              shapeIsUcsOrientedAt(int index) const;
  Gcad::ErrorStatus setShapeIsUcsOrientedAt(int index, bool isUcsOriented);

  bool              shapeIsUprightAt(int index) const;
  Gcad::ErrorStatus setShapeIsUprightAt(int index, bool isUpright);

  double            shapeRotationAt(int index) const;
  Gcad::ErrorStatus setShapeRotationAt(int index, double rotation);
  Gcad::ErrorStatus textAt(int index, GcString & sText) const;
  Gcad::ErrorStatus textAt(int index, GCHAR*& text) const;
  Gcad::ErrorStatus textAt(int index, const GCHAR*& text) const;
  Gcad::ErrorStatus setTextAt(int index, const GCHAR* text);

  GcGiDrawable*     drawable() override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbAbstractViewTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbAbstractViewTableRecord);

  GcDbAbstractViewTableRecord();
  ~GcDbAbstractViewTableRecord();

  GcGePoint2d    centerPoint() const;
  void           setCenterPoint(const GcGePoint2d&);

  double         height() const;
  void           setHeight(double height);

  double         width() const;
  void           setWidth(double width);

  GcGePoint3d    target() const;
  void           setTarget(const GcGePoint3d& target);

  GcGeVector3d   viewDirection() const;
  void           setViewDirection(const GcGeVector3d& viewDirection);

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

  const GcDbObjectId&  background() const;
  GcDbObjectId&       background();
  Gcad::ErrorStatus   setBackground(const GcDbObjectId& backgroundId);

  GcDbObjectId visualStyle() const;
  Gcad::ErrorStatus   setVisualStyle(const GcDbObjectId& visualStyleId);

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

  Gcad::ErrorStatus toneOperatorParameters(GcGiToneOperatorParameters& params) const;
  Gcad::ErrorStatus setToneOperatorParameters(const GcGiToneOperatorParameters& params);
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
};

typedef struct tagBITMAPINFO BITMAPINFO;

class GcDbViewTable;

class GCDB_PORT GcDbViewTableRecord : public  GcDbAbstractViewTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbViewTableRecord);

  GcDbViewTableRecord();
  ~GcDbViewTableRecord();

  typedef GcDbViewTable TableType;

  Gcad::ErrorStatus setParametersFromViewport(GcDbObjectId objId);

  bool isPaperspaceView() const;
  void setIsPaperspaceView(bool pspace);

  bool    isUcsAssociatedToView() const;
  Gcad::ErrorStatus disassociateUcsFromView();

  Gcad::ErrorStatus getCategoryName(GcString & sCategoryName) const;
  Gcad::ErrorStatus getCategoryName(GCHAR *& categoryName) const;
  Gcad::ErrorStatus setCategoryName(const GCHAR * categoryName);

  Gcad::ErrorStatus getLayerState(GcString & layerStateName) const;
  Gcad::ErrorStatus getLayerState(GCHAR*& layerStateName) const;
  Gcad::ErrorStatus setLayerState(const GCHAR *layerStateName);

  Gcad::ErrorStatus getLayout(GcDbObjectId& layoutId) const;
  Gcad::ErrorStatus setLayout(GcDbObjectId layoutId);

  bool              isViewAssociatedToViewport() const;
  Gcad::ErrorStatus setViewAssociatedToViewport(bool bVPflag);

  bool              isCameraPlottable() const;
  Gcad::ErrorStatus setIsCameraPlottable(bool plottable);

  GcDbObjectId      liveSection() const;
  Gcad::ErrorStatus setLiveSection(const GcDbObjectId& liveSectionId);

  Gcad::ErrorStatus getThumbnail(BITMAPINFO*& thumbnail) const;
  Gcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);

  Gcad::ErrorStatus getPreviewImage(Gtil::Image*& pPreviewImage) const;
  Gcad::ErrorStatus setPreviewImage(const Gtil::Image * pPreviewImage);

  GcDbObjectId      camera() const;
  Gcad::ErrorStatus setCamera(GcDbObjectId cameraId);

  GcDbAnnotationScale* annotationScale() const;
  Gcad::ErrorStatus setAnnotationScale(const GcDbAnnotationScale* pScaleObj);

  GcDbObjectId      sunId() const;
  Gcad::ErrorStatus setSun(GcDbObjectId &retId, GcDbObject *pSun);
  Gcad::ErrorStatus setSun(GcDbObjectId &retId, GcDbObject *pSun, bool eraseOldSun);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbUCSTable;

class GCDB_PORT GcDbUCSTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbUCSTableRecord);

  GcDbUCSTableRecord();
  ~GcDbUCSTableRecord();

  typedef GcDbUCSTable TableType;

  GcGePoint3d  origin() const;
  void         setOrigin(const GcGePoint3d& newOrigin);

  GcGeVector3d xAxis() const;
  void         setXAxis(const GcGeVector3d& xAxis);

  GcGeVector3d yAxis() const;
  void         setYAxis(const GcGeVector3d& yAxis);

  GcGePoint3d       ucsBaseOrigin(GcDb::OrthographicView view) const;
  Gcad::ErrorStatus setUcsBaseOrigin(const GcGePoint3d& origin, GcDb::OrthographicView view);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbViewportTable;

class GCDB_PORT GcDbViewportTableRecord : public  GcDbAbstractViewTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbViewportTableRecord);

  GcDbViewportTableRecord();
  ~GcDbViewportTableRecord();

  typedef GcDbViewportTable TableType;

  Gsoft::Int16   number()  const;

  GcGePoint2d    lowerLeftCorner() const;
  void           setLowerLeftCorner(const GcGePoint2d& pt);

  GcGePoint2d    upperRightCorner() const;
  void           setUpperRightCorner(const GcGePoint2d& pt);

  bool           ucsFollowMode() const;
  void           setUcsFollowMode(bool enabled);

  Gsoft::UInt16  circleSides() const;
  void           setCircleSides(Gsoft::UInt16 circleSides);

  bool           fastZoomsEnabled() const { return true; }
  void           setFastZoomsEnabled(bool enabled)
  {
    enabled;
  }

  bool           iconEnabled() const;
  void           setIconEnabled(bool enabled);

  bool           iconAtOrigin() const;
  void           setIconAtOrigin(bool atOrigin);

  bool           gridEnabled() const;
  void           setGridEnabled(bool enabled);

  GcGePoint2d    gridIncrements() const;
  void           setGridIncrements(const GcGePoint2d& base);

  bool           snapEnabled() const;
  void           setSnapEnabled(bool enabled);

  bool           isometricSnapEnabled() const;
  void           setIsometricSnapEnabled(bool enabled);

  Gsoft::Int16   snapPair() const;
  void           setSnapPair(Gsoft::Int16 pairType);

  double         snapAngle() const;
  void           setSnapAngle(double angle);

  GcGePoint2d    snapBase() const;
  void           setSnapBase(const GcGePoint2d& base);

  GcGePoint2d    snapIncrements() const;
  void           setSnapIncrements(const GcGePoint2d& base);

  void           setGsView(GcGsView* pView);
  GcGsView*      gsView() const;

  bool           isUcsSavedWithViewport() const;
  void           setUcsPerViewport(bool ucsvp);

  bool           isGridBoundToLimits() const;
  void           setGridBoundToLimits(bool enabled);

  bool           isGridAdaptive() const;
  void           setGridAdaptive(bool enabled);

  bool           isGridSubdivisionRestricted() const;
  void           setGridSubdivisionRestricted(bool enabled);

  bool           isGridFollow() const;
  void           setGridFollow(bool enabled);

  Gsoft::Int16   gridMajor() const;
  void           setGridMajor(Gsoft::Int16 value);

  Gcad::ErrorStatus   setBackground(const GcDbObjectId& backgroundId);
  GcDbObjectId        previousBackground(GcGiDrawable::DrawableType type = GcGiDrawable::kGeometry) const;
  Gcad::ErrorStatus   setPreviousBackground(GcDbObjectId backgroundId, GcGiDrawable::DrawableType type = GcGiDrawable::kGeometry);
  Gcad::ErrorStatus   setPreviousBackground(GcDbObjectId backgroundId, GcGiDrawable::DrawableType type, bool bForcedSwitch);
  bool                previousBackgroundForcedSwitch(void) const;
  GcGiDrawable*       drawable() override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbRegAppTable;

class GCDB_PORT GcDbRegAppTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbRegAppTableRecord);

  GcDbRegAppTableRecord();
  ~GcDbRegAppTableRecord();

  typedef GcDbRegAppTable TableType;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbDimStyleTable;

class GCDB_PORT GcDbDimStyleTableRecord : public  GcDbSymbolTableRecord
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDimStyleTableRecord);

  GcDbDimStyleTableRecord();
  ~GcDbDimStyleTableRecord();

  typedef GcDbDimStyleTable TableType;

#undef DBDIMVAR_H         
#include "dbdimvar.h"

  GcDbObjectId      arrowId(GcDb::DimArrowFlags whichArrow) const;
  Gcad::ErrorStatus getDimpost(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimapost(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk1(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk1(GCHAR*& pOutput) const;
  Gcad::ErrorStatus getDimblk2(GcString & sOutput) const;
  Gcad::ErrorStatus getDimblk2(GCHAR*& pOutput) const;

  int dimfit() const;
  int dimunit() const;

  Gcad::ErrorStatus setDimfit(int fit);
  Gcad::ErrorStatus setDimunit(int unit);
  bool isModifiedForRecompute() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbSymbolTable : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSymbolTable);
  GcDbSymbolTable();
  ~GcDbSymbolTable();

  typedef GcDbSymbolTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbSymbolTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }

  Gcad::ErrorStatus getIdAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRecord = false) const;
  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }

  bool has(const GCHAR* name) const
  {
    GcDbObjectId id;
    this->assertReadEnabled();
    return this->getIdAt(name, id) == Gcad::eOk;
  }

  bool      has(GcDbObjectId id) const;
  Gcad::ErrorStatus newIterator(GcDbSymbolTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbSymbolTableRecord* pRecord);
  Gcad::ErrorStatus add(GcDbObjectId& recordId, GcDbSymbolTableRecord* pRecord);

protected:
  template<class RecordType> Gcad::ErrorStatus openAt(const GCHAR* entryName,
    RecordType * & pRec, GcDb::OpenMode nMode, bool bOpenErased) const
  {
    pRec = nullptr;
    GcDbObjectId id;
    Gcad::ErrorStatus es = this->getIdAt(entryName, id, bOpenErased);
    if (es == Gcad::eOk)
      es = ::gcdbOpenObject(pRec, id, nMode, bOpenErased);
    return es;
  }
};

class GCDB_PORT GcDbBlockTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbBlockTable);
  GcDbBlockTable();
  ~GcDbBlockTable();

  typedef GcDbBlockTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbBlockTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRec = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRec);
  }
  Gcad::ErrorStatus newIterator(GcDbBlockTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbBlockTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }

  Gcad::ErrorStatus add(GcDbObjectId& recordId, GcDbBlockTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbLayerTableRecord;
class GcDbLayerTableIterator;

class GCDB_PORT GcDbLayerTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLayerTable);
  GcDbLayerTable();
  ~GcDbLayerTable();

  typedef GcDbLayerTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbLayerTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }
  Gcad::ErrorStatus newIterator(GcDbLayerTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbLayerTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId& recordId, GcDbLayerTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

  void generateUsageData();
  bool hasUnreconciledLayers() const;
  Gcad::ErrorStatus getUnreconciledLayers(GcDbObjectIdArray& idArray) const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbTextStyleTableRecord;
class GcDbTextStyleTableIterator;

class GCDB_PORT GcDbTextStyleTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTextStyleTable);
  GcDbTextStyleTable();
  ~GcDbTextStyleTable();

  typedef GcDbTextStyleTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbTextStyleTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }
  Gcad::ErrorStatus newIterator(GcDbTextStyleTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbTextStyleTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId&  recordId,
    GcDbTextStyleTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbLinetypeTableRecord;
class GcDbLinetypeTableIterator;

class GCDB_PORT GcDbLinetypeTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLinetypeTable);
  GcDbLinetypeTable();
  ~GcDbLinetypeTable();

  typedef GcDbLinetypeTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbLinetypeTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbObjectId& recordId,
    bool getErasedRec = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRec);
  }
  Gcad::ErrorStatus newIterator(GcDbLinetypeTableIterator*& pIterator,
    bool atBeginning = true,
    bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbLinetypeTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId& recordId,
    GcDbLinetypeTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbAbstractViewTableRecord;
class GcDbAbstractViewTableIterator;

class GSOFT_NO_VTABLE GCDB_PORT GcDbAbstractViewTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbAbstractViewTable);
  GcDbAbstractViewTable();
  ~GcDbAbstractViewTable();
  Gcad::ErrorStatus getAt(const GCHAR* entryName,
                          GcDbAbstractViewTableRecord*& pRec,
                          GcDb::OpenMode openMode = GcDb::kForRead,
                          bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }
  Gcad::ErrorStatus newIterator(GcDbAbstractViewTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbAbstractViewTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId&  recordId, GcDbAbstractViewTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }
};

class GcDbViewTableRecord;
class GcDbViewTableIterator;

class GCDB_PORT GcDbViewTable : public GcDbAbstractViewTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbViewTable);
  GcDbViewTable();
  ~GcDbViewTable();

  typedef GcDbViewTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbViewTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRec = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRec);
  }
  Gcad::ErrorStatus newIterator(GcDbViewTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbViewTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId&  recordId, GcDbViewTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbUCSTableRecord;
class GcDbUCSTableIterator;

class GCDB_PORT GcDbUCSTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbUCSTable);
  GcDbUCSTable();
  ~GcDbUCSTable();

  typedef GcDbUCSTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbUCSTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }
  Gcad::ErrorStatus newIterator(GcDbUCSTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbUCSTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId&  recordId, GcDbUCSTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbViewportTableRecord;
class GcDbViewportTableIterator;

class GCDB_PORT GcDbViewportTable : public GcDbAbstractViewTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbViewportTable);
  GcDbViewportTable();
  ~GcDbViewportTable();

  typedef GcDbViewportTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbViewportTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRecord = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRecord);
  }
  Gcad::ErrorStatus newIterator(GcDbViewportTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus add(GcDbViewportTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus add(GcDbObjectId& recordId, GcDbViewportTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbRegAppTableRecord;
class GcDbRegAppTableIterator;

class GCDB_PORT GcDbRegAppTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbRegAppTable);
  GcDbRegAppTable();
  ~GcDbRegAppTable();

  typedef GcDbRegAppTableRecord RecordType;

  Gcad::ErrorStatus getAt(const GCHAR* entryName,
    GcDbRegAppTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRec = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRec);
  }
  Gcad::ErrorStatus newIterator(GcDbRegAppTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus   add(GcDbRegAppTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus   add(GcDbObjectId&  recordId, GcDbRegAppTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GcDbDimStyleTableRecord;
class GcDbDimStyleTableIterator;

class GCDB_PORT GcDbDimStyleTable : public GcDbSymbolTable
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDimStyleTable);
  GcDbDimStyleTable();
  ~GcDbDimStyleTable();

  typedef GcDbDimStyleTableRecord RecordType;

  Gcad::ErrorStatus   getAt(const GCHAR* entryName,
    GcDbDimStyleTableRecord*& pRec,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openAt(entryName, pRec, openMode, openErasedRec);
  }
  Gcad::ErrorStatus   getAt(const GCHAR* entryName, GcDbObjectId& recordId, bool getErasedRec = false) const
  {
    return this->getIdAt(entryName, recordId, getErasedRec);
  }
  Gcad::ErrorStatus   newIterator(GcDbDimStyleTableIterator*& pIterator, bool atBeginning = true, bool skipDeleted = true) const;
  Gcad::ErrorStatus   add(GcDbDimStyleTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(pRecord);
  }
  Gcad::ErrorStatus   add(GcDbObjectId&  recordId, GcDbDimStyleTableRecord* pRecord)
  {
    return this->GcDbSymbolTable::add(recordId, pRecord);
  }

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbSymbolTableIterator
{
public:
  virtual ~GcDbSymbolTableIterator();

  void                start(bool atBeginning = true, bool skipDeleted = true);
  bool                done() const;
  Gcad::ErrorStatus   getRecordId(GcDbObjectId& id) const;
  Gcad::ErrorStatus   getRecord(GcDbSymbolTableRecord*& pRecord,
    GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

  void                step(bool forward = true, bool skipDeleted = true);
  Gcad::ErrorStatus   seek(GcDbObjectId id);
  Gcad::ErrorStatus   seek(const GcDbSymbolTableRecord* pRecord);
protected:
  template<class RecordType> Gcad::ErrorStatus openRecord(RecordType * & pRec,
    GcDb::OpenMode nMode, bool bOpenErased) const
  {
    pRec = nullptr;
    GcDbObjectId id;
    Gcad::ErrorStatus es = this->getRecordId(id);
    if (es == Gcad::eOk)
      es = ::gcdbOpenObject(pRec, id, nMode, bOpenErased);
    return es;
  }

  class GcDbImpSymbolTableIterator * mpImp;
  GcDbSymbolTableIterator();
  friend class GcDbSymbolTable;
};

class GCDB_PORT GcDbBlockTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbBlockTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbBlockTableIterator();
  friend class GcDbBlockTable;
};

class GCDB_PORT GcDbLayerTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbLayerTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }
  bool getSkipHidden() const;
  void setSkipHidden(bool value);
  bool getSkipReconciled() const;
  void setSkipReconciled(bool value);
protected:
  GcDbLayerTableIterator();
  friend class GcDbLayerTable;
};

class GCDB_PORT GcDbTextStyleTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbTextStyleTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbTextStyleTableIterator();
  friend class GcDbTextStyleTable;
};

class GCDB_PORT GcDbLinetypeTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbLinetypeTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbLinetypeTableIterator();
  friend class GcDbLinetypeTable;
};

class GCDB_PORT GcDbAbstractViewTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbAbstractViewTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbAbstractViewTableIterator();
  friend class GcDbAbstractViewTable;
};

class GCDB_PORT GcDbViewTableIterator : public GcDbAbstractViewTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbViewTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbViewTableIterator();
  friend class GcDbViewTable;
};

class GCDB_PORT GcDbUCSTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbUCSTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbUCSTableIterator();
  friend class GcDbUCSTable;
};

class GCDB_PORT GcDbViewportTableIterator : public GcDbAbstractViewTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbViewportTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbViewportTableIterator();
  friend class GcDbViewportTable;
};

class GCDB_PORT GcDbRegAppTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbRegAppTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbRegAppTableIterator();
  friend class GcDbRegAppTable;
};

class GCDB_PORT GcDbDimStyleTableIterator : public GcDbSymbolTableIterator
{
public:
  Gcad::ErrorStatus getRecord(GcDbDimStyleTableRecord*& pRecord, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedRec = false) const
  {
    return this->openRecord(pRecord, openMode, openErasedRec);
  }

protected:
  GcDbDimStyleTableIterator();
  friend class GcDbDimStyleTable;
};

class GCDB_PORT GcDbBlockTableRecordIterator
{
public:
  virtual ~GcDbBlockTableRecordIterator();

  void              start(bool atBeginning = true, bool skipDeleted = true);
  bool              done() const;
  Gcad::ErrorStatus getEntityId(GcDbObjectId& entityId) const;
  Gcad::ErrorStatus getEntity(GcDbEntity*& pEntity, GcDb::OpenMode openMode = GcDb::kForRead,
    bool openErasedEntity = false) const;

  GcDbBlockTableRecord* blockTableRecord() const;
  void              step(bool forward = true, bool skipDeleted = true);
  Gcad::ErrorStatus seek(GcDbObjectId id);
  Gcad::ErrorStatus seek(const GcDbEntity* pEntity);

protected:
  class GcDbImpBlockTableRecordIterator* mpImp;
private:
  GcDbBlockTableRecordIterator();
  friend class GcDbImpBlockTableRecord;
};

class GCDB_PORT GcDbBlockReferenceIdIterator
{
public:
  ~GcDbBlockReferenceIdIterator();

  void              start() { mPos = 0; }
  bool              done() const { return mPos >= mAry.length(); }
  Gcad::ErrorStatus getBlockReferenceId(GcDbObjectId& id) const;
  Gcad::ErrorStatus getDatabase(GcDbDatabase*& pDb) const;
  Gcad::ErrorStatus getBlockReference(GcDbBlockReference*& pBlkRef, GcDb::OpenMode openMode = GcDb::kForRead, bool openErasedEntity = false) const;
  void              step() { mPos++; }
  Gcad::ErrorStatus seek(GcDbObjectId id);

private:
  GcDbBlockReferenceIdIterator();
  friend class GcDbBlockTableRecord;
  int               mPos;
  GcDbObjectIdArray mAry;
};

#pragma pack(pop)

inline Gcad::ErrorStatus GcDbSymbolTableRecord::getName(GCHAR*& pName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbSymbolTableRecord::getName, pName);
}
inline Gcad::ErrorStatus GcDbBlockTableRecord::comments(GCHAR*& pComments) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbBlockTableRecord::comments, pComments);
}
inline Gcad::ErrorStatus GcDbBlockTableRecord::pathName(GCHAR*& pPath) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbBlockTableRecord::pathName, pPath);
}
inline GCHAR * GcDbLayerTableRecord::plotStyleName() const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->plotStyleName(sName));
}
inline GCHAR * GcDbLayerTableRecord::plotStyleName(const GcDbObjectId& viewportId,
  bool& isOverride) const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, this->plotStyleName(viewportId, sName, isOverride));
}
inline GCHAR * GcDbLayerTableRecord::description() const
{
  GcString sDescription;
  return ::gcutGcStringToGChar(sDescription, this->description(sDescription));
}
inline Gcad::ErrorStatus GcDbTextStyleTableRecord::fileName(GCHAR*& fileName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbTextStyleTableRecord::fileName, fileName);
}
inline Gcad::ErrorStatus GcDbTextStyleTableRecord::bigFontFileName(GCHAR*& fileName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbTextStyleTableRecord::bigFontFileName, fileName);
}
inline Gcad::ErrorStatus GcDbTextStyleTableRecord::font(GCHAR*& pTypeface,
  bool & bold,
  bool & italic,
  Charset& charset,
  Gssoft::Gscad::PAL::FontUtils::FontPitch& pitch,
  Gssoft::Gscad::PAL::FontUtils::FontFamily& family) const
{
  pTypeface = nullptr;
  GcString sTypeface;
  const Gcad::ErrorStatus es = this->font(sTypeface, bold, italic, charset, pitch, family);
  if (es == Gcad::eOk)
    ::gcutNewString(sTypeface.kwszPtr(), pTypeface);
  return es;
}
inline Gcad::ErrorStatus GcDbLinetypeTableRecord::comments(GCHAR*& pComments) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbLinetypeTableRecord::comments, pComments);
}
inline Gcad::ErrorStatus GcDbLinetypeTableRecord::textAt(int nIndex, GCHAR*& pText) const
{
  GcString sText;
  return ::gcutGcStringToGChar(sText, pText, this->textAt(nIndex, sText));
}

inline Gcad::ErrorStatus GcDbViewTableRecord::getCategoryName(GCHAR*& pCategoryName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbViewTableRecord::getCategoryName, pCategoryName);
}
inline Gcad::ErrorStatus GcDbViewTableRecord::getLayerState(GCHAR*& pLayerStateName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbViewTableRecord::getLayerState, pLayerStateName);
}
inline Gcad::ErrorStatus GcDbDimStyleTableRecord::getDimpost(GCHAR *& pOutput) const
{
  return ::gcutNewString(this->dimpost(), pOutput);
}

inline Gcad::ErrorStatus GcDbDimStyleTableRecord::getDimapost(GCHAR *& pOutput) const
{
  return ::gcutNewString(this->dimapost(), pOutput);
}
inline Gcad::ErrorStatus GcDbDimStyleTableRecord::getDimblk(GCHAR *& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDimStyleTableRecord::getDimblk, pOutput);
}
inline Gcad::ErrorStatus GcDbDimStyleTableRecord::getDimblk1(GCHAR *& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDimStyleTableRecord::getDimblk1, pOutput);
}
inline Gcad::ErrorStatus GcDbDimStyleTableRecord::getDimblk2(GCHAR *& pOutput) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbDimStyleTableRecord::getDimblk2, pOutput);
}

#endif