/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDIM_H
#define GD_DBDIM_H

#include "dbmain.h"
#include "dbmtext.h"
#include "gcgi.h"

#define DYNAMIC_CONSTRAINT_LAYER_OLD    GCRX_T("LayerNameForDynamicConstraint")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN_OLD     GCRX_T("*LayerNameForDynamicConstraint")

#define DYNAMIC_CONSTRAINT_LAYER        GCRX_T("GSFT_CONSTRAINTS")
#define DYNAMIC_CONSTRAINT_LAYER_HIDDEN GCRX_T("*GSFT_CONSTRAINTS")

#pragma pack(push, 8)

namespace GcDmUtil
{
  GCDB_PORT int dimfit(int dimatfit, int dimtmove);
  GCDB_PORT int dimunit(int dimlunit, int dimfrac);
  GCDB_PORT int dimatfit(int dimfit);
  GCDB_PORT int dimtmove(int dimfit);
  GCDB_PORT int dimlunit(int dimunit);
  GCDB_PORT int dimfrac(int dimunit);

  GCDB_PORT const GCHAR * globalArrowName(const GCHAR * pName);
  GCDB_PORT const GCHAR * globalArrowName(GcDbObjectId blockId);
  GCDB_PORT const GCHAR * arrowName(const GCHAR * pName);
  GCDB_PORT const GCHAR * arrowName(GcDbObjectId blockId);

  GCDB_PORT bool isBuiltInArrow(const GCHAR * pName);
  GCDB_PORT bool isZeroLengthArrow(const GCHAR * pName);

  GCDB_PORT Gcad::ErrorStatus findArrowId(const GCHAR * pName,
    GcDbObjectId& blockId,
    GcDbDatabase* pDb = 0);
  GCDB_PORT Gcad::ErrorStatus getArrowId(const GCHAR * pName,
    GcDbObjectId& blockId,
    GcDbDatabase* pDb = 0);
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbDimension : public GcDbEntity
{
protected:
  GcDbDimension();

public:
  ~GcDbDimension();
  GCDB_DECLARE_MEMBERS(GcDbDimension);

  void      textDefinedSize(double &width, double &height) const;
  void      setTextDefinedSize(double width, double height);
  void      resetTextDefinedSize();

  GcGePoint3d         textPosition() const;
  Gcad::ErrorStatus   setTextPosition(const GcGePoint3d&);
  Gsoft::Boolean      isUsingDefaultTextPosition() const;
  Gcad::ErrorStatus   useSetTextPosition();
  Gcad::ErrorStatus   useDefaultTextPosition();
  Gcad::ErrorStatus   setUsingDefaultTextPosition(bool);
  GcGeVector3d        normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);
  Gsoft::Boolean      isPlanar() const  override { return true; }
  Gcad::ErrorStatus   getPlane(GcGePlane&, GcDb::Planarity&) const override;
  double              elevation() const;
  Gcad::ErrorStatus   setElevation(double);
  Gcad::ErrorStatus   dimensionText(GcString &sDimText) const;
  GCHAR *             dimensionText() const;
  Gcad::ErrorStatus   setDimensionText(const GCHAR *);
  double              textRotation() const;
  Gcad::ErrorStatus   setTextRotation(double);
  GcDbObjectId        dimensionStyle() const;
  Gcad::ErrorStatus   setDimensionStyle(GcDbObjectId);
  GcDbMText::AttachmentPoint textAttachment() const;
  Gcad::ErrorStatus   setTextAttachment(GcDbMText::AttachmentPoint eAtt);
  GcDb::LineSpacingStyle textLineSpacingStyle() const;
  Gcad::ErrorStatus   setTextLineSpacingStyle(GcDb::LineSpacingStyle eStyle);
  double              textLineSpacingFactor() const;
  Gcad::ErrorStatus   setTextLineSpacingFactor(double dFactor);
  Gcad::ErrorStatus   getDimstyleData(GcDbDimStyleTableRecord*& pRecord) const;
  Gcad::ErrorStatus   setDimstyleData(GcDbDimStyleTableRecord* pNewData);
  Gcad::ErrorStatus   setDimstyleData(GcDbObjectId newDataId);
  virtual void        erased(GcDbObject* dbObj, Gsoft::Boolean bErasing);
  void                objectClosed(const GcDbObjectId dbObj) override;
  void                dragStatus(const GcDb::DragStat status) override;
  double              horizontalRotation() const;
  Gcad::ErrorStatus   setHorizontalRotation(double newVal);
  GcDbObjectId        dimBlockId() const;
  Gcad::ErrorStatus   setDimBlockId(const GcDbObjectId&);
  GcGePoint3d         dimBlockPosition() const;
  Gcad::ErrorStatus   setDimBlockPosition(const GcGePoint3d&);
  Gcad::ErrorStatus   recomputeDimBlock(bool forceUpdate = true);
  Gcad::ErrorStatus   generateLayout();
  Gcad::ErrorStatus   measurement(double &val);
  Gcad::ErrorStatus   formatMeasurement(GcString & sMTextContent,
    double measurement,
    const GCHAR *dimensionText = nullptr);
  Gcad::ErrorStatus   formatMeasurement(GCHAR *MTextContentBuffer,
    size_t contentBufferLen,
    double measurement,
    GCHAR *dimensionText);
  bool                isDynamicDimension() const;
  Gcad::ErrorStatus   setDynamicDimension(bool newVal);
  Gcad::ErrorStatus   getOsnapPointsAtSubentPath(GcDb::OsnapMode osnapMode,
    const GcDbFullSubentPath& subentId,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds) const;

  GcDbObjectId dimLineLinetype() const;
  Gcad::ErrorStatus setDimLineLinetype(const GcDbObjectId linetype);
  GcDbObjectId dimExt1Linetype() const;
  Gcad::ErrorStatus setDimExt1Linetype(const GcDbObjectId linetype);
  GcDbObjectId dimExt2Linetype() const;
  Gcad::ErrorStatus setDimExt2Linetype(const GcDbObjectId linetype);
  Gcad::ErrorStatus   removeTextField();
  Gcad::ErrorStatus   fieldToMText(GcDbMText* pDimMText);
  Gcad::ErrorStatus   fieldFromMText(GcDbMText* pDimMText);

#undef DBDIMVAR_H                   
#include "dbdimvar.h"
  int dimfit() const;
  int dimunit() const;

  Gcad::ErrorStatus setDimfit(int);
  Gcad::ErrorStatus setDimunit(int);
  bool                isHorizontalRefTextRotation() const;
  Gcad::ErrorStatus   setHorizontalRefTextRotation(bool newVal);
  bool getArrowFirstIsFlipped() const;
  bool getArrowSecondIsFlipped() const;
  Gcad::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
  Gcad::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);
  GcGeMatrix3d blockTransform() const;

  enum DimInspect {
    kShapeRemove = 0,
    kShapeRound = 1,
    kShapeAngular = 2,
    kShapeNone = 4,
    kShapeLabel = 0x10,
    kShapeRate = 0x20,
  };
  bool inspection() const;
  Gcad::ErrorStatus setInspection(bool val);
  int inspectionFrame() const;
  Gcad::ErrorStatus setInspectionFrame(int frame);
  const GCHAR* inspectionLabel() const;
  Gcad::ErrorStatus setInspectionLabel(const GCHAR* label);
  const GCHAR* inspectionRate() const;
  Gcad::ErrorStatus setInspectionRate(const GCHAR* label);
  bool  isConstraintObject() const;
  bool  isConstraintObject(bool &hasExpression, bool &isReferenceConstraint) const;
  bool  isConstraintDynamic(void) const;
  Gcad::ErrorStatus  setConstraintDynamic(bool bDynamic);
  bool  shouldParticipateInOPM(void) const;
  void  setShouldParticipateInOPM(bool bShouldParticipate);
  double                centerMarkSize() const;
  Gcad::ErrorStatus     prefix(GcString& sPrefix) const;
  Gcad::ErrorStatus     setPrefix(const GcString&);
  Gcad::ErrorStatus     suffix(GcString&) const;
  Gcad::ErrorStatus     setSuffix(const GcString&);
  Gcad::ErrorStatus     alternateSuffix(GcString&) const;
  Gcad::ErrorStatus     setAlternateSuffix(const GcString&);
  Gcad::ErrorStatus     alternatePrefix(GcString&) const;
  Gcad::ErrorStatus     setAlternatePrefix(const GcString&);
  bool                  suppressAngularLeadingZeros() const;
  Gcad::ErrorStatus     setSuppressAngularLeadingZeros(bool);
  bool                  suppressAngularTrailingZeros() const;
  Gcad::ErrorStatus     setSuppressAngularTrailingZeros(bool);
  bool                  altSuppressZeroInches() const;
  Gcad::ErrorStatus     setAltSuppressZeroInches(bool);
  bool                  altSuppressZeroFeet() const;
  Gcad::ErrorStatus     setAltSuppressZeroFeet(bool);
  bool                  altSuppressTrailingZeros() const;
  Gcad::ErrorStatus     setAltSuppressTrailingZeros(bool);
  bool                  altToleranceSuppressLeadingZeros() const;
  Gcad::ErrorStatus     setAltToleranceSuppressLeadingZeros(bool);
  bool                  altToleranceSuppressZeroInches() const;
  Gcad::ErrorStatus     setAltToleranceSuppressZeroInches(bool);
  bool                  altToleranceSuppressZeroFeet() const;
  Gcad::ErrorStatus     setAltToleranceSuppressZeroFeet(bool);
  bool                  altToleranceSuppressTrailingZeros() const;
  Gcad::ErrorStatus     setAltToleranceSuppressTrailingZeros(bool);
  bool                  suppressZeroFeet() const;
  Gcad::ErrorStatus     setSuppressZeroFeet(bool);
  bool                  suppressTrailingZeros() const;
  Gcad::ErrorStatus     setSuppressTrailingZeros(bool);
  bool                  suppressLeadingZeros() const;
  Gcad::ErrorStatus     setSuppressLeadingZeros(bool);
  bool                  suppressZeroInches() const;
  Gcad::ErrorStatus     setSuppressZeroInches(bool);
  bool                  altSuppressLeadingZeros() const;
  Gcad::ErrorStatus     setAltSuppressLeadingZeros(bool);
  bool                  toleranceSuppressZeroFeet() const;
  Gcad::ErrorStatus     setToleranceSuppressZeroFeet(bool);
  bool                  toleranceSuppressTrailingZeros() const;
  Gcad::ErrorStatus     setToleranceSuppressTrailingZeros(bool);
  bool                  toleranceSuppressLeadingZeros() const;
  Gcad::ErrorStatus     setToleranceSuppressLeadingZeros(bool);
  bool                  toleranceSuppressZeroInches() const;
  Gcad::ErrorStatus     setToleranceSuppressZeroInches(bool);

  enum CenterMarkType {
    kMark = 0,
    kLine = 1,
    kNone = 2
  };

  GcDbDimension::CenterMarkType centerMarkType() const;
protected:
  GcDbObjectId        subDimensionStyle() const;
  Gcad::ErrorStatus   subSetDimensionStyle(GcDbObjectId dimStyleId);
  Gcad::ErrorStatus   subGetDimstyleData(GcDbDimStyleTableRecord*& pRecord) const;
  Gcad::ErrorStatus   subSetDimstyleData(GcDbDimStyleTableRecord* pNewData);
  Gcad::ErrorStatus   subSetDimstyleData(GcDbObjectId newDataId);

  friend class GcDbDimensionStyleOverrule;
};

class GCDB_PORT GcDbOrdinateDimension : public GcDbDimension
{
public:
  GcDbOrdinateDimension();
  GcDbOrdinateDimension(
    Gsoft::Boolean     useXAxis,
    const GcGePoint3d& definingPoint,
    const GcGePoint3d& leaderEndPoint,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbOrdinateDimension();
  GCDB_DECLARE_MEMBERS(GcDbOrdinateDimension);

  Gsoft::Boolean      isUsingXAxis() const;
  Gsoft::Boolean      isUsingYAxis() const;
  Gcad::ErrorStatus   useXAxis();
  Gcad::ErrorStatus   useYAxis();
  Gcad::ErrorStatus   setUsingXAxis(bool value);
  Gcad::ErrorStatus   setUsingYAxis(bool value);
  GcGePoint3d         origin() const;
  Gcad::ErrorStatus   setOrigin(const GcGePoint3d&);
  GcGePoint3d         definingPoint() const;
  Gcad::ErrorStatus   setDefiningPoint(const GcGePoint3d&);
  GcGePoint3d         leaderEndPoint() const;
  Gcad::ErrorStatus   setLeaderEndPoint(const GcGePoint3d&);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbAlignedDimension : public GcDbDimension
{
public:
  GcDbAlignedDimension();
  GcDbAlignedDimension(
    const GcGePoint3d& xLine1Point,
    const GcGePoint3d& xLine2Point,
    const GcGePoint3d& dimLinePoint,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbAlignedDimension();
  GCDB_DECLARE_MEMBERS(GcDbAlignedDimension);

  GcGePoint3d         xLine1Point() const;
  Gcad::ErrorStatus   setXLine1Point(const GcGePoint3d&);
  GcGePoint3d         xLine2Point() const;
  Gcad::ErrorStatus   setXLine2Point(const GcGePoint3d&);
  GcGePoint3d         dimLinePoint() const;
  Gcad::ErrorStatus   setDimLinePoint(const GcGePoint3d&);
  double              oblique() const;
  Gcad::ErrorStatus   setOblique(double);

  bool jogSymbolOn() const;
  Gcad::ErrorStatus setJogSymbolOn(bool value);
  GcGePoint3d jogSymbolPosition() const;
  Gcad::ErrorStatus setJogSymbolPosition(const GcGePoint3d& pt);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbRotatedDimension : public GcDbDimension
{
public:
  GcDbRotatedDimension();
  GcDbRotatedDimension(
    double             rotation,
    const GcGePoint3d& xLine1Point,
    const GcGePoint3d& xLine2Point,
    const GcGePoint3d& dimLinePoint,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbRotatedDimension();
  GCDB_DECLARE_MEMBERS(GcDbRotatedDimension);

  GcGePoint3d         xLine1Point() const;
  Gcad::ErrorStatus   setXLine1Point(const GcGePoint3d&);
  GcGePoint3d         xLine2Point() const;
  Gcad::ErrorStatus   setXLine2Point(const GcGePoint3d&);
  GcGePoint3d         dimLinePoint() const;
  Gcad::ErrorStatus   setDimLinePoint(const GcGePoint3d&);
  double              oblique() const;
  Gcad::ErrorStatus   setOblique(double);
  double              rotation() const;
  Gcad::ErrorStatus   setRotation(double);

  bool jogSymbolOn() const;
  Gcad::ErrorStatus setJogSymbolOn(bool value);
  GcGePoint3d jogSymbolPosition() const;
  Gcad::ErrorStatus setJogSymbolPosition(const GcGePoint3d& pt);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDb3PointAngularDimension : public GcDbDimension
{
public:
  GcDb3PointAngularDimension();
  GcDb3PointAngularDimension(
    const GcGePoint3d& centerPoint,
    const GcGePoint3d& xLine1Point,
    const GcGePoint3d& xLine2Point,
    const GcGePoint3d& arcPoint,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDb3PointAngularDimension();
  GCDB_DECLARE_MEMBERS(GcDb3PointAngularDimension);

  GcGePoint3d         arcPoint() const;
  Gcad::ErrorStatus   setArcPoint(const GcGePoint3d&);
  GcGePoint3d         xLine1Point() const;
  Gcad::ErrorStatus   setXLine1Point(const GcGePoint3d&);
  GcGePoint3d         xLine2Point() const;
  Gcad::ErrorStatus   setXLine2Point(const GcGePoint3d&);
  GcGePoint3d         centerPoint() const;
  Gcad::ErrorStatus   setCenterPoint(const GcGePoint3d&);
  bool extArcOn() const;
  Gcad::ErrorStatus setExtArcOn(bool value);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDb2LineAngularDimension : public GcDbDimension
{
public:
  GcDb2LineAngularDimension();
  GcDb2LineAngularDimension(
    const GcGePoint3d& xLine1Start,
    const GcGePoint3d& xLine1End,
    const GcGePoint3d& xLine2Start,
    const GcGePoint3d& xLine2End,
    const GcGePoint3d& arcPoint,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDb2LineAngularDimension();
  GCDB_DECLARE_MEMBERS(GcDb2LineAngularDimension);

  GcGePoint3d         arcPoint() const;
  Gcad::ErrorStatus   setArcPoint(const GcGePoint3d&);
  GcGePoint3d         xLine1Start() const;
  Gcad::ErrorStatus   setXLine1Start(const GcGePoint3d&);
  GcGePoint3d         xLine1End() const;
  Gcad::ErrorStatus   setXLine1End(const GcGePoint3d&);
  GcGePoint3d         xLine2Start() const;
  Gcad::ErrorStatus   setXLine2Start(const GcGePoint3d&);
  GcGePoint3d         xLine2End() const;
  Gcad::ErrorStatus   setXLine2End(const GcGePoint3d&);
  bool extArcOn() const;
  Gcad::ErrorStatus setExtArcOn(bool value);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbRadialDimension : public GcDbDimension
{
public:
  GcDbRadialDimension();
  GcDbRadialDimension(
    const GcGePoint3d& center,
    const GcGePoint3d& chordPoint,
    double             leaderLength,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbRadialDimension();
  GCDB_DECLARE_MEMBERS(GcDbRadialDimension);

  double              leaderLength() const;
  Gcad::ErrorStatus   setLeaderLength(double);
  GcGePoint3d         center() const;
  Gcad::ErrorStatus   setCenter(const GcGePoint3d&);
  GcGePoint3d         chordPoint() const;
  Gcad::ErrorStatus   setChordPoint(const GcGePoint3d&);

  double extArcStartAngle() const;
  Gcad::ErrorStatus setExtArcStartAngle(double newAngle);
  double extArcEndAngle() const;
  Gcad::ErrorStatus setExtArcEndAngle(double newAngle);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbDiametricDimension : public GcDbDimension
{
public:
  GcDbDiametricDimension();
  GcDbDiametricDimension(
    const GcGePoint3d& chordPoint,
    const GcGePoint3d& farChordPoint,
    double             leaderLength,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbDiametricDimension();
  GCDB_DECLARE_MEMBERS(GcDbDiametricDimension);

  double              leaderLength() const;
  Gcad::ErrorStatus   setLeaderLength(double);
  GcGePoint3d         chordPoint() const;
  Gcad::ErrorStatus   setChordPoint(const GcGePoint3d&);
  GcGePoint3d         farChordPoint() const;
  Gcad::ErrorStatus   setFarChordPoint(const GcGePoint3d&);

  double extArcStartAngle() const;
  Gcad::ErrorStatus setExtArcStartAngle(double newAngle);
  double extArcEndAngle() const;
  Gcad::ErrorStatus setExtArcEndAngle(double newAngle);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbArcDimension : public GcDbDimension
{
public:
  GcDbArcDimension();
  GcDbArcDimension(
    const GcGePoint3d& centerPoint,
    const GcGePoint3d& xLine1Point,
    const GcGePoint3d& xLine2Point,
    const GcGePoint3d& arcPoint,
    const GCHAR * dimText = NULL,
    GcDbObjectId dimStyle = GcDbObjectId::kNull);
  ~GcDbArcDimension();
  GCDB_DECLARE_MEMBERS(GcDbArcDimension);

  GcGePoint3d         arcPoint() const;
  Gcad::ErrorStatus   setArcPoint(const GcGePoint3d & arcPt);
  GcGePoint3d         xLine1Point() const;
  Gcad::ErrorStatus   setXLine1Point(const GcGePoint3d & xLine1Pt);
  GcGePoint3d         xLine2Point() const;
  Gcad::ErrorStatus   setXLine2Point(const GcGePoint3d & xLine2Pt);
  GcGePoint3d         centerPoint() const;
  Gcad::ErrorStatus   setCenterPoint(const GcGePoint3d & ctrPt);
  bool                isPartial() const;
  Gcad::ErrorStatus   setIsPartial(const bool & partial);
  double              arcStartParam() const;
  Gcad::ErrorStatus   setArcStartParam(const double & arcParam);
  double              arcEndParam() const;
  Gcad::ErrorStatus   setArcEndParam(const double & arcParam);
  bool                hasLeader() const;
  Gcad::ErrorStatus   setHasLeader(const bool & leaderVal);
  GcGePoint3d         leader1Point() const;
  Gcad::ErrorStatus   setLeader1Point(const GcGePoint3d & ldr1Pt);
  GcGePoint3d         leader2Point() const;
  Gcad::ErrorStatus   setLeader2Point(const GcGePoint3d & ldr2Pt);
  int arcSymbolType() const;
  Gcad::ErrorStatus setArcSymbolType(const int symbol);

protected:
  Gcad::ErrorStatus  subGetClassID(CLSID* pClsid) const override;
};

class GCDB_PORT GcDbRadialDimensionLarge : public GcDbDimension
{
public:
  GcDbRadialDimensionLarge();
  GcDbRadialDimensionLarge(
    const GcGePoint3d& center,
    const GcGePoint3d& chordPoint,
    const GcGePoint3d& overrideCenter,
    const GcGePoint3d& jogPoint,
    double             jogAngle,
    const GCHAR *      dimText = NULL,
    GcDbObjectId       dimStyle = GcDbObjectId::kNull);
  ~GcDbRadialDimensionLarge();
  GCDB_DECLARE_MEMBERS(GcDbRadialDimensionLarge);

  GcGePoint3d         center() const;
  Gcad::ErrorStatus   setCenter(const GcGePoint3d & centerPoint);
  GcGePoint3d         chordPoint() const;
  Gcad::ErrorStatus   setChordPoint(const GcGePoint3d & chordPoint);
  GcGePoint3d         overrideCenter() const;
  Gcad::ErrorStatus   setOverrideCenter(const GcGePoint3d & overrideCenterPoint);
  GcGePoint3d         jogPoint() const;
  Gcad::ErrorStatus   setJogPoint(const GcGePoint3d & jogPoint);
  double              jogAngle() const;
  Gcad::ErrorStatus   setJogAngle(double jogAngle);
  Gcad::ErrorStatus   setOverrideCenterPP(const GcGePoint3d & overrideCenterPointPP);
  Gcad::ErrorStatus   setJogPointPP(const GcGePoint3d & jogPointPP);
  Gcad::ErrorStatus   setTextPositionPP(const GcGePoint3d & textPointPP);

  double extArcStartAngle() const;
  Gcad::ErrorStatus setExtArcStartAngle(double newAngle);
  double extArcEndAngle() const;
  Gcad::ErrorStatus setExtArcEndAngle(double newAngle);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID * pClsid) const override;
};

class GcDbDimensionStyleOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDimensionStyleOverrule);
  GCDB_PORT GcDbDimensionStyleOverrule();

  GCDB_PORT virtual GcDbObjectId   dimensionStyle(const GcDbDimension* pSubject);
  GCDB_PORT virtual Gcad::ErrorStatus   setDimensionStyle(GcDbDimension* pSubject, GcDbObjectId dimStyleId);
  GCDB_PORT virtual Gcad::ErrorStatus   getDimstyleData(const GcDbDimension* pSubject, GcDbDimStyleTableRecord*& pRecord);
  GCDB_PORT virtual Gcad::ErrorStatus   setDimstyleData(GcDbDimension* pSubject, GcDbDimStyleTableRecord* pRecord);
  GCDB_PORT virtual Gcad::ErrorStatus   setDimstyleData(GcDbDimension* pSubject, GcDbObjectId dimstyleId);
};

#pragma pack(pop)

#endif