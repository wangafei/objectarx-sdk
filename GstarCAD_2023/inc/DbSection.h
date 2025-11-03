/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "dbmain.h"
#include "dbhatch.h"
#include "GcString.h"

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <map>
#pragma pop_macro("_USE_ANSI_CPP")
typedef std::map<GcDbEntity*, Gsoft::UInt32> GcDbSectionGeometryMap;

class GcDbSectionSettings;

class GCDB_PORT GcDbSection : public GcDbEntity
{
public:
  enum State
  {
    kPlane = (0x1 << 0),
    kBoundary = (0x1 << 1),
    kVolume = (0x1 << 2),
  };

  enum SubItem
  {
    kNone = 0,
    kSectionLine = (0x1 << 0),
    kSectionLineTop = (0x1 << 1),
    kSectionLineBottom = (0x1 << 2),
    kBackLine = (0x1 << 3),
    kBackLineTop = (0x1 << 4),
    kBackLineBottom = (0x1 << 5),
    kVerticalLineTop = (0x1 << 6),
    kVerticalLineBottom = (0x1 << 7),
  };

  enum Height
  {
    kHeightAboveSectionLine = 0x1,
    kHeightBelowSectionLine = 0x2,
  };

public:
  GCDB_DECLARE_MEMBERS(GcDbSection);

  GcDbSection(void);
  GcDbSection(const GcGePoint3dArray& pts, const GcGeVector3d& verticalDir);
  GcDbSection(const GcGePoint3dArray& pts, const GcGeVector3d& verticalDir, const GcGeVector3d& vecViewingDir);
  ~GcDbSection(void);

  GcDbSection::State state(void) const;
  Gcad::ErrorStatus setState(GcDbSection::State nState);
  const GCHAR* getName(void) const;
  Gcad::ErrorStatus getName(GcString& sName) const;
  Gcad::ErrorStatus getName(GCHAR*& pszName) const;
  Gcad::ErrorStatus setName(const GCHAR* pszName);
  GcGeVector3d viewingDirection(void) const;
  Gcad::ErrorStatus setViewingDirection(const GcGeVector3d& dir);
  GcGeVector3d verticalDirection(void) const;
  Gcad::ErrorStatus setVerticalDirection(const GcGeVector3d& dir);
  GcGeVector3d normal(void) const;
  Gcad::ErrorStatus plane(GcGeVector3d& uAxis, GcGeVector3d& vAxis) const;

  int   indicatorTransparency(void) const;
  Gcad::ErrorStatus setIndicatorTransparency(int nTransparency);

  GcCmColor indicatorFillColor(void) const;
  Gcad::ErrorStatus setIndicatorFillColor(const GcCmColor& color);

  int numVertices(void) const;
  Gcad::ErrorStatus getVertex(int nIndex, GcGePoint3d& pt) const;
  Gcad::ErrorStatus setVertex(int nIndex, const GcGePoint3d& pt);
  Gcad::ErrorStatus addVertex(int nInsertAt, const GcGePoint3d& pt);
  Gcad::ErrorStatus removeVertex(int nIndex);
  Gcad::ErrorStatus getVertices(GcGePoint3dArray& pts) const;
  Gcad::ErrorStatus setVertices(const GcGePoint3dArray& pts);

  double height(GcDbSection::Height nHeightType) const;
  Gcad::ErrorStatus setHeight(GcDbSection::Height nHeightType, double fHeight);

  bool  hitTest(const GcGePoint3d& ptHit, int* pSegmentIndex,
    GcGePoint3d* ptOnSegment,
    GcDbSection::SubItem* pSubItem) const;
  Gcad::ErrorStatus createJog(const GcGePoint3d& ptOnSection);
  GcDbObjectId getSettings(void) const;
  Gcad::ErrorStatus getSettings(GcDbSectionSettings*& pSettings, GcDb::OpenMode mode) const;
  bool  isLiveSectionEnabled(void) const;
  Gcad::ErrorStatus enableLiveSection(bool bEnable);
  Gcad::ErrorStatus generateSectionGeometry(GcDbEntity *pEnt,
    GcArray<GcDbEntity*>& intBoundaryEnts,
    GcArray<GcDbEntity*>& intFillEnts,
    GcArray<GcDbEntity*>& backgroundEnts,
    GcArray<GcDbEntity*>& foregroundEnts,
    GcArray<GcDbEntity*>& curveTangencyEnts) const;

  double elevation() const;
  Gcad::ErrorStatus setElevation(double elev);
  double topPlane() const;
  Gcad::ErrorStatus setTopPlane(double);
  double bottomPlane() const;
  Gcad::ErrorStatus setBottomPlane(double);

public:
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus subClose() override;

  Gcad::ErrorStatus generateSectionGeometry(const GcArray<GcDbEntity*>& entset,
    GcArray<GcDbEntity*>& intBoundaryEnts,
    GcArray<GcDbEntity*>& intFillEnts,
    GcArray<GcDbEntity*>& backgroundEnts,
    GcArray<GcDbEntity*>& foregroundEnts,
    GcArray<GcDbEntity*>& curveTangencyEnts) const;
  Gcad::ErrorStatus generateSectionGeometry(const GcDbVoidPtrArray& bodies,
    const GcDbIntArray& instanceCount,
    const GcArray<GcGeMatrix3d>& xforms,
    const GcArray<GcRxClass*>& providerClasses,
    GcArray<GcDbEntity*>& intBoundaryEnts,
    GcArray<GcDbEntity*>& intFillEnts,
    GcArray<GcDbEntity*>& backgroundEnts,
    GcArray<GcDbEntity*>& foregroundEnts,
    GcArray<GcDbEntity*>& curveTangencyEnts,
    GcDbSectionGeometryMap* = NULL) const;
protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
  bool                      isSlice() const;
  Gcad::ErrorStatus         setIsSlice(bool value);

  double                    thicknessDepth() const;
  Gcad::ErrorStatus         setThicknessDepth(double fThickness);

  bool                      hasJogs() const;

  double                    sectionPlaneOffset() const;
  Gcad::ErrorStatus         setSectionPlaneOffset(double offset);
};

class GCDB_PORT GcDbSectionSettings : public GcDbObject
{
public:
  enum SectionType
  {
    kLiveSection = (0x1 << 0),
    k2dSection = (0x1 << 1),
    k3dSection = (0x1 << 2),
  };

  enum Geometry
  {
    kIntersectionBoundary = (0x1 << 0),
    kIntersectionFill = (0x1 << 1),
    kBackgroundGeometry = (0x1 << 2),
    kForegroundGeometry = (0x1 << 3),
    kCurveTangencyLines = (0x1 << 4),
  };

  enum Generation
  {
    kSourceAllObjects = (0x1 << 0),
    kSourceSelectedObjects = (0x1 << 1),

    kDestinationNewBlock = (0x1 << 4),
    kDestinationReplaceBlock = (0x1 << 5),
    kDestinationFile = (0x1 << 6),
  };

public:
  GCDB_DECLARE_MEMBERS(GcDbSectionSettings);
  GcDbSectionSettings();
  ~GcDbSectionSettings();

  Gcad::ErrorStatus reset(void);
  Gcad::ErrorStatus reset(GcDbSectionSettings::SectionType nSecType);

  GcDbSectionSettings::SectionType currentSectionType(void) const;
  Gcad::ErrorStatus setCurrentSectionType(GcDbSectionSettings::SectionType nSecType);

  GcDbSectionSettings::Generation generationOptions(GcDbSectionSettings::SectionType nSecType) const;
  Gcad::ErrorStatus setGenerationOptions(GcDbSectionSettings::SectionType nSecType, GcDbSectionSettings::Generation nOptions);

  Gcad::ErrorStatus getSourceObjects(GcDbSectionSettings::SectionType nSecType, GcDbObjectIdArray& ids) const;
  Gcad::ErrorStatus setSourceObjects(GcDbSectionSettings::SectionType nSecType, const GcDbObjectIdArray& ids);

  GcDbObjectId destinationBlock(GcDbSectionSettings::SectionType nSecType) const;
  Gcad::ErrorStatus setDestinationBlock(GcDbSectionSettings::SectionType nSecType, const GcDbObjectId& id);

  const GCHAR* destinationFile(GcDbSectionSettings::SectionType nSecType) const;
  Gcad::ErrorStatus setDestinationFile(GcDbSectionSettings::SectionType nSecType, const GCHAR* pszFileName);

  bool  visibility(GcDbSectionSettings::SectionType nSecType, GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setVisibility(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    bool bVisible);
  GcCmColor color(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setColor(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    const GcCmColor& color);
  const GCHAR* layer(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setLayer(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    const GCHAR* pszLayer);
  const GCHAR* linetype(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setLinetype(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    const GCHAR* pszLinetype);
  double linetypeScale(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setLinetypeScale(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    double fScale);
  const GCHAR* plotStyleName(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setPlotStyleName(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    const GCHAR* pszPlotStyleName);
  GcDb::LineWeight lineWeight(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setLineWeight(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    GcDb::LineWeight nLineWeight);
  int   faceTransparency(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setFaceTransparency(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    int nTransparency);
  int   edgeTransparency(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setEdgeTransparency(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    int nTransparency);
  bool  hatchVisibility(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setHatchVisibility(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    bool bVisible);
  Gcad::ErrorStatus getHatchPattern(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    GcDbHatch::HatchPatternType& nPatternType,
    const GCHAR*& pszPatternName) const;
  Gcad::ErrorStatus setHatchPattern(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    GcDbHatch::HatchPatternType nPatternType,
    const GCHAR* pszPatternName);
  double hatchAngle(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setHatchAngle(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    double fAngle);
  double hatchSpacing(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setHatchSpacing(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    double fSpacing);
  double hatchScale(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setHatchScale(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    double fScale);
  bool  hiddenLine(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setHiddenLine(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    bool bHiddenLine);
  bool  divisionLines(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry) const;
  Gcad::ErrorStatus setDivisionLines(GcDbSectionSettings::SectionType nSecType,
    GcDbSectionSettings::Geometry nGeometry,
    bool bShow);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbSection::getName(GCHAR*& pszName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbSection::getName, pszName);
}