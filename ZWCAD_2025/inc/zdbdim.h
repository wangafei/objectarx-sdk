

#ifndef ZD_DBDIM_H
#define ZD_DBDIM_H

#include "zdbmain.h"
#include "zdbmtext.h"
#include "zacgi.h"

#define DYNAMIC_CONSTRAINT_LAYER_OLD    ZCRX_T("LayerNameForDynamicConstraint")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN_OLD     ZCRX_T("*LayerNameForDynamicConstraint")


#define DYNAMIC_CONSTRAINT_LAYER        ZCRX_T("ADSK_CONSTRAINTS")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN ZCRX_T("*ADSK_CONSTRAINTS")

#pragma pack(push, 8)

namespace ZcDmUtil
{

    int dimfit  (int dimatfit, int dimtmove);
    int dimunit (int dimlunit, int dimfrac );

    int dimatfit(int dimfit);
    int dimtmove(int dimfit);
    int dimlunit(int dimunit);
    int dimfrac (int dimunit);

    const ZTCHAR * globalArrowName(const ZTCHAR * pName);
    const ZTCHAR * globalArrowName(ZcDbObjectId blockId);

    const ZTCHAR * arrowName(const ZTCHAR * pName);
    const ZTCHAR * arrowName(ZcDbObjectId blockId);

    bool isBuiltInArrow(const ZTCHAR * pName);

    bool isZeroLengthArrow(const ZTCHAR * pName);

    Zcad::ErrorStatus findArrowId(const ZTCHAR * pName,
                                        ZcDbObjectId& blockId, 
                                        ZcDbDatabase* pDb = 0);

    Zcad::ErrorStatus getArrowId(const ZTCHAR * pName,
                                        ZcDbObjectId& blockId, 
                                        ZcDbDatabase* pDb = 0);
};

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbDimension: public ZcDbEntity
{
protected:
    ZcDbDimension();
public:
    ~ZcDbDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbDimension);

	
	void      textDefinedSize(double &width, double &height) const;

	void      setTextDefinedSize(double width, double height);

	void      resetTextDefinedSize();
	

    ZcGePoint3d         textPosition() const;
    Zcad::ErrorStatus   setTextPosition(const ZcGePoint3d&);

    ZSoft::Boolean      isUsingDefaultTextPosition() const;
    Zcad::ErrorStatus   useSetTextPosition();
    Zcad::ErrorStatus   useDefaultTextPosition();
	Zcad::ErrorStatus   setUsingDefaultTextPosition(bool);	


    ZcGeVector3d        normal() const;
    Zcad::ErrorStatus   setNormal(const ZcGeVector3d&);

    virtual ZSoft::Boolean    isPlanar() const override{ return true; }
    virtual Zcad::ErrorStatus getPlane(ZcGePlane&, ZcDb::Planarity&) const override;

    double              elevation() const;
    Zcad::ErrorStatus   setElevation(double);
	

	Zcad::ErrorStatus   dimensionText(ZcString &sDimText) const;	
    ZTCHAR *             dimensionText() const;
    Zcad::ErrorStatus   setDimensionText(const ZTCHAR *);

    double              textRotation() const;
    Zcad::ErrorStatus   setTextRotation(double);

    ZcDbObjectId        dimensionStyle() const;
    Zcad::ErrorStatus   setDimensionStyle(ZcDbObjectId);

    ZcDbMText::AttachmentPoint textAttachment() const;
    Zcad::ErrorStatus   setTextAttachment(ZcDbMText::AttachmentPoint eAtt);

    ZcDb::LineSpacingStyle textLineSpacingStyle() const;
    Zcad::ErrorStatus   setTextLineSpacingStyle(ZcDb::LineSpacingStyle eStyle);

    double              textLineSpacingFactor() const;
    Zcad::ErrorStatus   setTextLineSpacingFactor(double dFactor);

    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);

    virtual void        erased(ZcDbObject* dbObj, ZSoft::Boolean bErasing);
    virtual void        objectClosed(const ZcDbObjectId dbObj) override;
	virtual void        dragStatus(const ZcDb::DragStat status) override;

    double              horizontalRotation() const;
    Zcad::ErrorStatus   setHorizontalRotation(double newVal);

    ZcDbObjectId        dimBlockId() const;
    Zcad::ErrorStatus   setDimBlockId(const ZcDbObjectId&);
    ZcGePoint3d         dimBlockPosition() const;
    Zcad::ErrorStatus   setDimBlockPosition(const ZcGePoint3d&);
    Zcad::ErrorStatus   recomputeDimBlock(bool forceUpdate = true);
    Zcad::ErrorStatus   generateLayout();
    Zcad::ErrorStatus   measurement(double &val);


	Zcad::ErrorStatus   formatMeasurement(ZcString & sMTextContent,
									double measurement,
									const ZTCHAR *dimensionText = nullptr);	

	Zcad::ErrorStatus	formatMeasurement(ZTCHAR *MTextContentBuffer,
										  size_t contentBufferLen,
										  double measurement,
                                          ZTCHAR *dimensionText);

    bool                isDynamicDimension() const;
    Zcad::ErrorStatus   setDynamicDimension(bool newVal);
    Zcad::ErrorStatus getOsnapPointsAtSubentPath(ZcDb::OsnapMode osnapMode,
                                     const ZcDbFullSubentPath& subentId,
                                     const ZcGePoint3d&  pickPoint,
                                     const ZcGePoint3d&  lastPoint,
                                     const ZcGeMatrix3d& viewXform,
                                     ZcGePoint3dArray&   snapPoints,
                                     ZcDbIntArray&   geomIds) const;


    ZcDbObjectId dimLineLinetype() const;
    Zcad::ErrorStatus setDimLineLinetype(const ZcDbObjectId linetype);
    ZcDbObjectId dimExt1Linetype() const;
    Zcad::ErrorStatus setDimExt1Linetype(const ZcDbObjectId linetype);
    ZcDbObjectId dimExt2Linetype() const;
    Zcad::ErrorStatus setDimExt2Linetype(const ZcDbObjectId linetype);

    Zcad::ErrorStatus   removeTextField();
    Zcad::ErrorStatus   fieldToMText(ZcDbMText* pDimMText);
    Zcad::ErrorStatus   fieldFromMText(ZcDbMText* pDimMText);

    #undef ZDBDIMVAR_H                   
    #include "zdbdimvar.h"

    int dimfit() const;
    int dimunit() const;

    Zcad::ErrorStatus setDimfit (int );
    Zcad::ErrorStatus setDimunit(int );
    bool                isHorizontalRefTextRotation() const;
    Zcad::ErrorStatus   setHorizontalRefTextRotation(bool newVal);
    bool getArrowFirstIsFlipped() const;
    bool getArrowSecondIsFlipped() const;
    Zcad::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
    Zcad::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);

    ZcGeMatrix3d blockTransform() const;
	enum DimInspect {
		kShapeRemove  = 0,     
		kShapeRound   = 1,     
		kShapeAngular = 2,     
		kShapeNone    = 4,     
		kShapeLabel   = 0x10,  
		kShapeRate    = 0x20,  
	};

	bool 				inspection() const;
	Zcad::ErrorStatus 	setInspection(bool val);

	int 				inspectionFrame() const;
	Zcad::ErrorStatus 	setInspectionFrame(int frame);

	const ZTCHAR* 		inspectionLabel() const;
	Zcad::ErrorStatus 	setInspectionLabel(const ZTCHAR* label);

	const ZTCHAR* 		inspectionRate() const;
	Zcad::ErrorStatus 	setInspectionRate(const ZTCHAR* label);

	
	bool  isConstraintObject() const;
	bool  isConstraintObject(bool &hasExpression,
		bool &isReferenceConstraint) const;
	bool  isConstraintDynamic(void) const;
	Zcad::ErrorStatus  setConstraintDynamic(bool bDynamic);

	bool  shouldParticipateInOPM(void) const;
	void  setShouldParticipateInOPM(bool bShouldParticipate);
	double                centerMarkSize() const;
	Zcad::ErrorStatus     prefix(ZcString& sPrefix) const;
	Zcad::ErrorStatus     setPrefix(const ZcString&);
	Zcad::ErrorStatus     suffix(ZcString&) const;
	Zcad::ErrorStatus     setSuffix(const ZcString&);

	Zcad::ErrorStatus     alternateSuffix(ZcString&) const;
	Zcad::ErrorStatus     setAlternateSuffix(const ZcString&);
	Zcad::ErrorStatus     alternatePrefix(ZcString&) const;
	Zcad::ErrorStatus     setAlternatePrefix(const ZcString&);

	bool                  suppressAngularLeadingZeros() const;
	Zcad::ErrorStatus     setSuppressAngularLeadingZeros(bool);

	bool                  suppressAngularTrailingZeros() const;
	Zcad::ErrorStatus     setSuppressAngularTrailingZeros(bool);

	bool                  altSuppressZeroInches() const;
	Zcad::ErrorStatus     setAltSuppressZeroInches(bool);
	bool                  altSuppressZeroFeet() const;
	Zcad::ErrorStatus     setAltSuppressZeroFeet(bool);
	bool                  altSuppressTrailingZeros() const;
	Zcad::ErrorStatus     setAltSuppressTrailingZeros(bool);

	bool                  altToleranceSuppressLeadingZeros() const;
	Zcad::ErrorStatus     setAltToleranceSuppressLeadingZeros(bool);
	bool                  altToleranceSuppressZeroInches() const;
	Zcad::ErrorStatus     setAltToleranceSuppressZeroInches(bool);

	bool                  altToleranceSuppressZeroFeet() const;
	Zcad::ErrorStatus     setAltToleranceSuppressZeroFeet(bool);
	bool                  altToleranceSuppressTrailingZeros() const;
	Zcad::ErrorStatus     setAltToleranceSuppressTrailingZeros(bool);

	bool                  suppressZeroFeet() const;
	Zcad::ErrorStatus     setSuppressZeroFeet(bool);
	bool                  suppressTrailingZeros() const;
	Zcad::ErrorStatus     setSuppressTrailingZeros(bool);

	bool                  suppressLeadingZeros() const;
	Zcad::ErrorStatus     setSuppressLeadingZeros(bool);
	bool                  suppressZeroInches() const;
	Zcad::ErrorStatus     setSuppressZeroInches(bool);

	bool                  altSuppressLeadingZeros() const;
	Zcad::ErrorStatus     setAltSuppressLeadingZeros(bool);
	bool                  toleranceSuppressZeroFeet() const;
	Zcad::ErrorStatus     setToleranceSuppressZeroFeet(bool);

	bool                  toleranceSuppressTrailingZeros() const;
	Zcad::ErrorStatus     setToleranceSuppressTrailingZeros(bool);
	bool                  toleranceSuppressLeadingZeros() const;
	Zcad::ErrorStatus     setToleranceSuppressLeadingZeros(bool);

	bool                  toleranceSuppressZeroInches() const;
	Zcad::ErrorStatus     setToleranceSuppressZeroInches(bool);

	enum CenterMarkType   { kMark       = 0,
		kLine       = 1,
		kNone       = 2 };

	ZcDbDimension::CenterMarkType centerMarkType() const;
protected:

	ZcDbObjectId        subDimensionStyle() const;

	Zcad::ErrorStatus   subSetDimensionStyle(ZcDbObjectId dimStyleId);

	Zcad::ErrorStatus   subGetDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;

	Zcad::ErrorStatus   subSetDimstyleData(ZcDbDimStyleTableRecord* pNewData);

	Zcad::ErrorStatus   subSetDimstyleData(ZcDbObjectId newDataId);

	friend class ZcDbDimensionStyleOverrule;

	
};

class ZCDBCORE2D_PORT ZcDbOrdinateDimension: public ZcDbDimension
{
public:
    ZcDbOrdinateDimension();
    ZcDbOrdinateDimension(
        ZSoft::Boolean     useXAxis,
        const ZcGePoint3d& definingPoint,
        const ZcGePoint3d& leaderEndPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle  = ZcDbObjectId::kNull);
    ~ZcDbOrdinateDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbOrdinateDimension);

    ZSoft::Boolean      isUsingXAxis() const;
    ZSoft::Boolean      isUsingYAxis() const;
    Zcad::ErrorStatus   useXAxis();
    Zcad::ErrorStatus   useYAxis();
	
	
	Zcad::ErrorStatus   setUsingXAxis(bool value);
	Zcad::ErrorStatus   setUsingYAxis(bool value);
	

    ZcGePoint3d         origin() const;
    Zcad::ErrorStatus   setOrigin(const ZcGePoint3d&);

    ZcGePoint3d         definingPoint() const;
    Zcad::ErrorStatus   setDefiningPoint(const ZcGePoint3d&);

    ZcGePoint3d         leaderEndPoint() const;
    Zcad::ErrorStatus   setLeaderEndPoint(const ZcGePoint3d&);
protected:
    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbAlignedDimension: public ZcDbDimension
{
public:
    ZcDbAlignedDimension();
    ZcDbAlignedDimension(
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& dimLinePoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbAlignedDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbAlignedDimension);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         dimLinePoint() const;
    Zcad::ErrorStatus   setDimLinePoint(const ZcGePoint3d&);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);
	bool 				jogSymbolOn() const;
	Zcad::ErrorStatus 	setJogSymbolOn(bool value);

	ZcGePoint3d 		jogSymbolPosition() const;
	Zcad::ErrorStatus 	setJogSymbolPosition(const ZcGePoint3d& pt);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbRotatedDimension: public ZcDbDimension
{
public:
    ZcDbRotatedDimension();
    ZcDbRotatedDimension(
        double             rotation,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& dimLinePoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbRotatedDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbRotatedDimension);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         dimLinePoint() const;
    Zcad::ErrorStatus   setDimLinePoint(const ZcGePoint3d&);

    double              oblique() const;
    Zcad::ErrorStatus   setOblique(double);

    double              rotation() const;
    Zcad::ErrorStatus   setRotation(double);
	bool 				jogSymbolOn() const;
	Zcad::ErrorStatus 	setJogSymbolOn(bool value);

	ZcGePoint3d 		jogSymbolPosition() const;
	Zcad::ErrorStatus 	setJogSymbolPosition(const ZcGePoint3d& pt);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDb3PointAngularDimension: public ZcDbDimension
{
public:
    ZcDb3PointAngularDimension();
    ZcDb3PointAngularDimension(
        const ZcGePoint3d& centerPoint,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDb3PointAngularDimension();
    ZCDB_DECLARE_MEMBERS(ZcDb3PointAngularDimension);

    ZcGePoint3d         arcPoint() const;
    Zcad::ErrorStatus   setArcPoint(const ZcGePoint3d&);

    ZcGePoint3d         xLine1Point() const;
    Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Point() const;
    Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d&);

    ZcGePoint3d         centerPoint() const;
    Zcad::ErrorStatus   setCenterPoint(const ZcGePoint3d&);
	bool 				extArcOn() const;
	Zcad::ErrorStatus 	setExtArcOn(bool value);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDb2LineAngularDimension: public ZcDbDimension
{
public:
    ZcDb2LineAngularDimension();
    ZcDb2LineAngularDimension(
        const ZcGePoint3d& xLine1Start,
        const ZcGePoint3d& xLine1End,
        const ZcGePoint3d& xLine2Start,
        const ZcGePoint3d& xLine2End,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDb2LineAngularDimension();
    ZCDB_DECLARE_MEMBERS(ZcDb2LineAngularDimension);

    ZcGePoint3d         arcPoint() const;
    Zcad::ErrorStatus   setArcPoint(const ZcGePoint3d&);

    ZcGePoint3d         xLine1Start() const;
    Zcad::ErrorStatus   setXLine1Start(const ZcGePoint3d&);

    ZcGePoint3d         xLine1End() const;
    Zcad::ErrorStatus   setXLine1End(const ZcGePoint3d&);

    ZcGePoint3d         xLine2Start() const;
    Zcad::ErrorStatus   setXLine2Start(const ZcGePoint3d&);

    ZcGePoint3d         xLine2End() const;
    Zcad::ErrorStatus   setXLine2End(const ZcGePoint3d&);
	bool 				extArcOn() const;
	Zcad::ErrorStatus 	setExtArcOn(bool value);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbRadialDimension: public ZcDbDimension
{
public:
    ZcDbRadialDimension();
    ZcDbRadialDimension(
        const ZcGePoint3d& center,
        const ZcGePoint3d& chordPoint,
        double             leaderLength,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbRadialDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbRadialDimension);

    double              leaderLength() const;
    Zcad::ErrorStatus   setLeaderLength(double);

    ZcGePoint3d         center() const;
    Zcad::ErrorStatus   setCenter(const ZcGePoint3d&);

    ZcGePoint3d         chordPoint() const;
    Zcad::ErrorStatus   setChordPoint(const ZcGePoint3d&);
    double extArcStartAngle() const;
    Zcad::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    Zcad::ErrorStatus setExtArcEndAngle(double newAngle);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbDiametricDimension: public ZcDbDimension
{
public:
    ZcDbDiametricDimension();
    ZcDbDiametricDimension(
        const ZcGePoint3d& chordPoint,
        const ZcGePoint3d& farChordPoint,
        double             leaderLength,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);
    ~ZcDbDiametricDimension();
    ZCDB_DECLARE_MEMBERS(ZcDbDiametricDimension);

    double              leaderLength() const;
    Zcad::ErrorStatus   setLeaderLength(double);

    ZcGePoint3d         chordPoint() const;
    Zcad::ErrorStatus   setChordPoint(const ZcGePoint3d&);

    ZcGePoint3d         farChordPoint() const;
    Zcad::ErrorStatus   setFarChordPoint(const ZcGePoint3d&);
	double 				extArcStartAngle() const;
	Zcad::ErrorStatus 	setExtArcStartAngle(double newAngle);

	double 				extArcEndAngle() const;
	Zcad::ErrorStatus 	setExtArcEndAngle(double newAngle);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbArcDimension: public ZcDbDimension
{
public:
    ZcDbArcDimension();

    ZcDbArcDimension(
        const ZcGePoint3d& centerPoint,
        const ZcGePoint3d& xLine1Point,
        const ZcGePoint3d& xLine2Point,
        const ZcGePoint3d& arcPoint,
        const ZTCHAR * dimText = NULL,
        ZcDbObjectId dimStyle = ZcDbObjectId::kNull);

	~ZcDbArcDimension();
	ZCDB_DECLARE_MEMBERS(ZcDbArcDimension);

	ZcGePoint3d         arcPoint() const;
	Zcad::ErrorStatus	setArcPoint(const ZcGePoint3d & arcPt);

	ZcGePoint3d         xLine1Point() const;
	Zcad::ErrorStatus   setXLine1Point(const ZcGePoint3d & xLine1Pt);

	ZcGePoint3d         xLine2Point() const;
	Zcad::ErrorStatus   setXLine2Point(const ZcGePoint3d & xLine2Pt);

	ZcGePoint3d         centerPoint() const;
	Zcad::ErrorStatus   setCenterPoint(const ZcGePoint3d & ctrPt);

	bool                isPartial() const;
	Zcad::ErrorStatus   setIsPartial(const bool & partial);

	double              arcStartParam() const;
	Zcad::ErrorStatus   setArcStartParam(const double & arcParam);

	double              arcEndParam() const;
	Zcad::ErrorStatus   setArcEndParam(const double & arcParam);

	bool                hasLeader() const;
	Zcad::ErrorStatus   setHasLeader(const bool & leaderVal);

	ZcGePoint3d         leader1Point() const;       
	Zcad::ErrorStatus   setLeader1Point(const ZcGePoint3d & ldr1Pt);

	ZcGePoint3d         leader2Point() const;   
	Zcad::ErrorStatus   setLeader2Point(const ZcGePoint3d & ldr2Pt);

	int					arcSymbolType() const;
	Zcad::ErrorStatus	setArcSymbolType(const int symbol);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbRadialDimensionLarge: public ZcDbDimension
{
public:

	ZcDbRadialDimensionLarge();

    ZcDbRadialDimensionLarge(
        const ZcGePoint3d& center,
        const ZcGePoint3d& chordPoint,
        const ZcGePoint3d& overrideCenter,
        const ZcGePoint3d& jogPoint,
        double             jogAngle,
        const ZTCHAR *      dimText = NULL,
        ZcDbObjectId       dimStyle = ZcDbObjectId::kNull);

	~ZcDbRadialDimensionLarge();
	ZCDB_DECLARE_MEMBERS(ZcDbRadialDimensionLarge);

	ZcGePoint3d         center() const;
	Zcad::ErrorStatus	setCenter(const ZcGePoint3d & centerPoint);

	ZcGePoint3d         chordPoint() const;
	Zcad::ErrorStatus	setChordPoint(const ZcGePoint3d & chordPoint);

	ZcGePoint3d         overrideCenter() const;
	Zcad::ErrorStatus	setOverrideCenter(const ZcGePoint3d & overrideCenterPoint);

	ZcGePoint3d         jogPoint() const;
	Zcad::ErrorStatus	setJogPoint(const ZcGePoint3d & jogPoint);

	double              jogAngle() const;
	Zcad::ErrorStatus	setJogAngle(double jogAngle);
    Zcad::ErrorStatus   setOverrideCenterPP(const ZcGePoint3d & overrideCenterPointPP);
    Zcad::ErrorStatus   setJogPointPP(const ZcGePoint3d & jogPointPP);
    Zcad::ErrorStatus   setTextPositionPP(const ZcGePoint3d & textPointPP);
	double				extArcStartAngle() const;
    Zcad::ErrorStatus setExtArcStartAngle(double newAngle);

	double				extArcEndAngle() const;
    Zcad::ErrorStatus setExtArcEndAngle(double newAngle);
protected:
	virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class ZCDBCORE2D_PORT ZcDbDimensionStyleOverrule : public ZcRxOverrule
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbDimensionStyleOverrule);

	ZcDbDimensionStyleOverrule();

	virtual ZcDbObjectId   dimensionStyle  (const ZcDbDimension* pSubject);

	virtual Zcad::ErrorStatus   setDimensionStyle (ZcDbDimension* pSubject,
		ZcDbObjectId dimStyleId);

	virtual Zcad::ErrorStatus   getDimstyleData   (const ZcDbDimension* pSubject,
		ZcDbDimStyleTableRecord*& pRecord);

	virtual Zcad::ErrorStatus   setDimstyleData   (ZcDbDimension* pSubject,
		ZcDbDimStyleTableRecord* pRecord);

	virtual Zcad::ErrorStatus   setDimstyleData   (ZcDbDimension* pSubject,
		ZcDbObjectId dimstyleId);
};


#pragma pack(pop)

#endif
