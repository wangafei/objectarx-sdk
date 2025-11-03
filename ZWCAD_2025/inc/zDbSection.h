
#pragma once

#include "zAdAChar.h"
#include "zdbmain.h"
#include "zdbhatch.h"
#include "zAcString.h"

#pragma push_macro("_USE_ANSI_CPP")
#define _USE_ANSI_CPP
#include <map>
#pragma pop_macro("_USE_ANSI_CPP")
typedef std::map<ZcDbEntity*, ZSoft::UInt32> ZcDbSectionGeometryMap;

class ZcDbSectionSettings;

class ZCDB_PORT ZcDbSection : public ZcDbEntity
{
public:
    enum State
    {
        kPlane              = (0x1 << 0),
        kBoundary           = (0x1 << 1),
        kVolume             = (0x1 << 2),
    };

    enum SubItem
    {
        kNone               = 0,
        kSectionLine        = (0x1 << 0),
        kSectionLineTop     = (0x1 << 1),
        kSectionLineBottom  = (0x1 << 2),
        kBackLine           = (0x1 << 3),
        kBackLineTop        = (0x1 << 4),
        kBackLineBottom     = (0x1 << 5),
        kVerticalLineTop    = (0x1 << 6),
        kVerticalLineBottom = (0x1 << 7),
    };

    enum Height
    {
        kHeightAboveSectionLine = 0x1,
        kHeightBelowSectionLine = 0x2,
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbSection);

    ZcDbSection(void);
    ZcDbSection(const ZcGePoint3dArray& pts,
        const ZcGeVector3d& verticalDir);
    ZcDbSection(const ZcGePoint3dArray& pts,
        const ZcGeVector3d& verticalDir, const ZcGeVector3d& vecViewingDir);
    ~ZcDbSection(void);

    ZcDbSection::State state      (void) const;
    Zcad::ErrorStatus setState    (ZcDbSection::State nState);

    const ZTCHAR* getName          (void) const;
    Zcad::ErrorStatus getName     (ZcString& sName) const;
    Zcad::ErrorStatus getName     (ZTCHAR*& pszName) const;
    Zcad::ErrorStatus setName     (const ZTCHAR* pszName);

    ZcGeVector3d viewingDirection (void) const;
    Zcad::ErrorStatus setViewingDirection(const ZcGeVector3d& dir);

    ZcGeVector3d verticalDirection(void) const;
    Zcad::ErrorStatus setVerticalDirection(const ZcGeVector3d& dir);

    ZcGeVector3d normal           (void) const;
    Zcad::ErrorStatus plane       (ZcGeVector3d& uAxis,
                                  ZcGeVector3d& vAxis) const;

    int   indicatorTransparency   (void) const;
    Zcad::ErrorStatus setIndicatorTransparency(int nTransparency);

    ZcCmColor indicatorFillColor  (void) const;
    Zcad::ErrorStatus setIndicatorFillColor(const ZcCmColor& color);

    int numVertices               (void) const;
    Zcad::ErrorStatus getVertex   (int nIndex,
                                  ZcGePoint3d& pt) const;
    Zcad::ErrorStatus setVertex   (int nIndex,
                                             const ZcGePoint3d& pt);
    Zcad::ErrorStatus addVertex   (int nInsertAt,
                                  const ZcGePoint3d& pt);
    Zcad::ErrorStatus removeVertex(int nIndex);
    Zcad::ErrorStatus getVertices (ZcGePoint3dArray& pts) const;
    Zcad::ErrorStatus setVertices (const ZcGePoint3dArray& pts);

    double height                 (ZcDbSection::Height nHeightType) const;
    Zcad::ErrorStatus setHeight   (ZcDbSection::Height nHeightType,
                        double fHeight);

    bool  hitTest                 (const ZcGePoint3d& ptHit,
                                             int* pSegmentIndex,
                                             ZcGePoint3d* ptOnSegment,
                                             ZcDbSection::SubItem* pSubItem) const;

	Zcad::ErrorStatus createJog(const ZcGePoint3d& ptOnSection);

	ZcDbObjectId getSettings(void) const;
	Zcad::ErrorStatus getSettings(ZcDbSectionSettings*& pSettings,
		ZcDb::OpenMode mode) const;

	bool  isLiveSectionEnabled(void) const;
	Zcad::ErrorStatus enableLiveSection(bool bEnable);

	Zcad::ErrorStatus generateSectionGeometry(ZcDbEntity *pEnt,
                                ZcArray<ZcDbEntity*>& intBoundaryEnts,
                                ZcArray<ZcDbEntity*>& intFillEnts,
                                ZcArray<ZcDbEntity*>& backgroundEnts,
                                ZcArray<ZcDbEntity*>& foregroundEnts,
                                ZcArray<ZcDbEntity*>& curveTangencyEnts) const;
	
	double elevation() const;

	Zcad::ErrorStatus setElevation(double elev);

	double topPlane() const;

	Zcad::ErrorStatus setTopPlane(double);

	double bottomPlane() const;

	Zcad::ErrorStatus setBottomPlane(double);
	
public:
	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
	virtual Zcad::ErrorStatus subClose() override;

    Zcad::ErrorStatus generateSectionGeometry (const ZcArray<ZcDbEntity*>& entset,
                                ZcArray<ZcDbEntity*>& intBoundaryEnts,
                                ZcArray<ZcDbEntity*>& intFillEnts,
                                ZcArray<ZcDbEntity*>& backgroundEnts,
                                ZcArray<ZcDbEntity*>& foregroundEnts,
                                ZcArray<ZcDbEntity*>& curveTangencyEnts) const;

	
	Zcad::ErrorStatus generateSectionGeometry(const ZcDbVoidPtrArray& bodies,
		const ZcDbIntArray& instanceCount,
		const ZcArray<ZcGeMatrix3d>& xforms,
		const ZcArray<ZcRxClass*>& providerClasses,
		ZcArray<ZcDbEntity*>& intBoundaryEnts,
		ZcArray<ZcDbEntity*>& intFillEnts,
		ZcArray<ZcDbEntity*>& backgroundEnts,
		ZcArray<ZcDbEntity*>& foregroundEnts,
		ZcArray<ZcDbEntity*>& curveTangencyEnts,
		ZcDbSectionGeometryMap* = NULL) const;
protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:

	bool                      isSlice() const;

	Zcad::ErrorStatus         setIsSlice(bool value);

	double                    thicknessDepth() const;

	Zcad::ErrorStatus         setThicknessDepth(double fThickness);

	bool                      hasJogs() const;

	double                    sectionPlaneOffset() const;

	Zcad::ErrorStatus         setSectionPlaneOffset(double offset);
	

};

class ZCDB_PORT ZcDbSectionSettings : public ZcDbObject
{
public:
    enum SectionType
    {

        kLiveSection                = (0x1 << 0),
        k2dSection                  = (0x1 << 1),
        k3dSection                  = (0x1 << 2),
    };

    enum Geometry
    {

        kIntersectionBoundary       = (0x1 << 0),
        kIntersectionFill           = (0x1 << 1),
        kBackgroundGeometry         = (0x1 << 2),
        kForegroundGeometry         = (0x1 << 3),
        kCurveTangencyLines         = (0x1 << 4),
    };

    enum Generation
    {

        kSourceAllObjects           = (0x1 << 0),
        kSourceSelectedObjects      = (0x1 << 1),
        kDestinationNewBlock        = (0x1 << 4),
        kDestinationReplaceBlock    = (0x1 << 5),
        kDestinationFile            = (0x1 << 6),
    };

public:
    ZCDB_DECLARE_MEMBERS(ZcDbSectionSettings);

    ZcDbSectionSettings();
    ~ZcDbSectionSettings();

    Zcad::ErrorStatus reset(void);
    Zcad::ErrorStatus reset(ZcDbSectionSettings::SectionType nSecType);

    ZcDbSectionSettings::SectionType currentSectionType(void) const;
    Zcad::ErrorStatus setCurrentSectionType(ZcDbSectionSettings::SectionType nSecType);

    ZcDbSectionSettings::Generation generationOptions(ZcDbSectionSettings::SectionType nSecType) const;
    Zcad::ErrorStatus setGenerationOptions(ZcDbSectionSettings::SectionType nSecType,
        ZcDbSectionSettings::Generation nOptions);

    Zcad::ErrorStatus getSourceObjects(ZcDbSectionSettings::SectionType nSecType,
        ZcDbObjectIdArray& ids) const;
    Zcad::ErrorStatus setSourceObjects(ZcDbSectionSettings::SectionType nSecType,
        const ZcDbObjectIdArray& ids);

    ZcDbObjectId destinationBlock(ZcDbSectionSettings::SectionType nSecType) const;
    Zcad::ErrorStatus setDestinationBlock(ZcDbSectionSettings::SectionType nSecType,
        const ZcDbObjectId& id);

    const ZTCHAR* destinationFile(ZcDbSectionSettings::SectionType nSecType) const;
    Zcad::ErrorStatus setDestinationFile(ZcDbSectionSettings::SectionType nSecType,
        const ZTCHAR* pszFileName);

    bool  visibility              (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    Zcad::ErrorStatus setVisibility(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             bool bVisible);
    ZcCmColor color               (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    Zcad::ErrorStatus setColor    (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZcCmColor& color);
    const ZTCHAR* layer            (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    Zcad::ErrorStatus setLayer    (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZTCHAR* pszLayer);
    const ZTCHAR* linetype         (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    Zcad::ErrorStatus setLinetype (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             const ZTCHAR* pszLinetype);
    double linetypeScale          (ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry) const;
    Zcad::ErrorStatus setLinetypeScale(ZcDbSectionSettings::SectionType nSecType,
                                             ZcDbSectionSettings::Geometry nGeometry,
                                             double fScale);
	const ZTCHAR* plotStyleName(ZcDbSectionSettings::SectionType nSecType,
								ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setPlotStyleName(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									const ZTCHAR* pszPlotStyleName);
	ZcDb::LineWeight lineWeight(ZcDbSectionSettings::SectionType nSecType,
								ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setLineWeight(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									ZcDb::LineWeight nLineWeight);
	int   faceTransparency(ZcDbSectionSettings::SectionType nSecType,
						   ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setFaceTransparency(ZcDbSectionSettings::SectionType nSecType,
										  ZcDbSectionSettings::Geometry nGeometry,
										  int nTransparency);
	int   edgeTransparency(ZcDbSectionSettings::SectionType nSecType,
							ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setEdgeTransparency(ZcDbSectionSettings::SectionType nSecType,
                                          ZcDbSectionSettings::Geometry nGeometry,
                                             int nTransparency);

	bool  hatchVisibility(ZcDbSectionSettings::SectionType nSecType,
						  ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setHatchVisibility(ZcDbSectionSettings::SectionType nSecType,
										ZcDbSectionSettings::Geometry nGeometry,
										bool bVisible);
	Zcad::ErrorStatus getHatchPattern(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									ZcDbHatch::HatchPatternType& nPatternType,
									const ZTCHAR*& pszPatternName) const;
	Zcad::ErrorStatus setHatchPattern(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									ZcDbHatch::HatchPatternType nPatternType,
									const ZTCHAR* pszPatternName);
	double hatchAngle(ZcDbSectionSettings::SectionType nSecType,
					ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setHatchAngle(ZcDbSectionSettings::SectionType nSecType,
								ZcDbSectionSettings::Geometry nGeometry,
								double fAngle);
	double hatchSpacing(ZcDbSectionSettings::SectionType nSecType,
					ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setHatchSpacing(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									double fSpacing);
	double hatchScale(ZcDbSectionSettings::SectionType nSecType,
					ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setHatchScale(ZcDbSectionSettings::SectionType nSecType,
									ZcDbSectionSettings::Geometry nGeometry,
									double fScale);
	bool  hiddenLine(ZcDbSectionSettings::SectionType nSecType,
					ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setHiddenLine(ZcDbSectionSettings::SectionType nSecType,
								ZcDbSectionSettings::Geometry nGeometry,
								bool bHiddenLine);
	bool  divisionLines(ZcDbSectionSettings::SectionType nSecType,
						ZcDbSectionSettings::Geometry nGeometry) const;
	Zcad::ErrorStatus setDivisionLines(ZcDbSectionSettings::SectionType nSecType,
                                     ZcDbSectionSettings::Geometry nGeometry,
                                             bool bShow);
protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

