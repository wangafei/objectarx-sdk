/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __DBMLEADERSTYLE_H__
#define __DBMLEADERSTYLE_H__

#pragma once

#include "GcString.h"
#include "dbmain.h"

class GCDB_PORT GcDbMLeaderStyle : public GcDbObject
{
public:
  enum ContentType {
    kNoneContent = 0,
    kBlockContent = 1,
    kMTextContent = 2,
    kToleranceContent = 3,
  };

  enum DrawMLeaderOrderType {
    kDrawContentFirst = 0,
    kDrawLeaderFirst = 1
  };

  enum DrawLeaderOrderType {
    kDrawLeaderHeadFirst = 0,
    kDrawLeaderTailFirst = 1
  };

  enum LeaderType {
    kInVisibleLeader = 0,
    kStraightLeader = 1,
    kSplineLeader = 2
  };

  enum TextAttachmentDirection {
    kAttachmentHorizontal = 0,
    kAttachmentVertical = 1
  };

  enum TextAttachmentType {
    kAttachmentTopOfTop = 0,
    kAttachmentMiddleOfTop = 1,
    kAttachmentMiddle = 2,
    kAttachmentMiddleOfBottom = 3,
    kAttachmentBottomOfBottom = 4,
    kAttachmentBottomLine = 5,
    kAttachmentBottomOfTopLine = 6,
    kAttachmentBottomOfTop = 7,
    kAttachmentAllLine = 8,
    kAttachmentCenter = 9,
    kAttachmentLinedCenter = 10
  };

  enum TextAngleType {
    kInsertAngle = 0,
    kHorizontalAngle = 1,
    kAlwaysRightReadingAngle = 2
  };

  enum TextAlignmentType {
    kLeftAlignment = 0,
    kCenterAlignment = 1,
    kRightAlignment = 2
  };

  enum BlockConnectionType {
    kConnectExtents = 0,
    kConnectBase = 1
  };

  enum LeaderDirectionType {
    kUnknownLeader = 0,
    kLeftLeader = 1,
    kRightLeader = 2,
    kTopLeader = 3,
    kBottomLeader = 4
  };

  enum SegmentAngleType {
    kAny = 0,
    k15 = 1,
    k30 = 2,
    k45 = 3,
    k60 = 4,
    k90 = 6,
    kHorz = 12
  };

public:
  GcDbMLeaderStyle();
  ~GcDbMLeaderStyle();
  GCDB_DECLARE_MEMBERS(GcDbMLeaderStyle);

  virtual Gcad::ErrorStatus   getName(GcString & sName) const;
  virtual Gcad::ErrorStatus   getName(GCHAR*& pszName) const final;
  virtual Gcad::ErrorStatus   setName(const GCHAR * pszName);

  bool isRenamable() const;
  virtual const GCHAR*        description(void) const;
  virtual Gcad::ErrorStatus   setDescription(const GCHAR * pszDescription);
  virtual Gsoft::UInt32       bitFlags() const;
  virtual Gcad::ErrorStatus   setBitFlags(Gsoft::UInt32 flags);

  Gcad::ErrorStatus         setContentType(ContentType contentType);
  ContentType               contentType() const;

  Gcad::ErrorStatus         setDrawMLeaderOrderType(DrawMLeaderOrderType drawMLeaderOrderType);
  DrawMLeaderOrderType      drawMLeaderOrderType() const;

  Gcad::ErrorStatus         setDrawLeaderOrderType(DrawLeaderOrderType drawLeaderOrderType);
  DrawLeaderOrderType       drawLeaderOrderType() const;

  Gcad::ErrorStatus         setMaxLeaderSegmentsPoints(int maxLeaderSegmentsPoints);
  int                       maxLeaderSegmentsPoints() const;

  Gcad::ErrorStatus         setFirstSegmentAngleConstraint(SegmentAngleType angle);
  SegmentAngleType          firstSegmentAngleConstraint() const;

  Gcad::ErrorStatus         setSecondSegmentAngleConstraint(SegmentAngleType angle);
  SegmentAngleType          secondSegmentAngleConstraint() const;

  Gcad::ErrorStatus         setLeaderLineType(LeaderType leaderLineType);
  LeaderType                leaderLineType() const;

  Gcad::ErrorStatus         setLeaderLineColor(const GcCmColor& leaderLineColor);
  GcCmColor                 leaderLineColor() const;

  Gcad::ErrorStatus         setLeaderLineTypeId(GcDbObjectId leaderLineTypeId);
  GcDbObjectId              leaderLineTypeId() const;

  Gcad::ErrorStatus         setLeaderLineWeight(GcDb::LineWeight leaderLineWeight);
  GcDb::LineWeight          leaderLineWeight() const;

  Gcad::ErrorStatus         setEnableLanding(bool enableLanding);
  bool                      enableLanding() const;

  Gcad::ErrorStatus         setLandingGap(double landingGap);
  double                    landingGap() const;

  Gcad::ErrorStatus         setEnableDogleg(bool enableDogleg);
  bool                      enableDogleg() const;

  Gcad::ErrorStatus         setDoglegLength(double doglegLength);
  double                    doglegLength() const;

  Gcad::ErrorStatus         setArrowSymbolId(const GCHAR* name);
  Gcad::ErrorStatus         setArrowSymbolId(GcDbObjectId arrowSymbolId);
  GcDbObjectId              arrowSymbolId() const;

  Gcad::ErrorStatus         setArrowSize(double arrowSize);
  double                    arrowSize() const;

  Gcad::ErrorStatus         setDefaultMText(const GcDbMText* defaultMText);
  GcDbMText*                defaultMText() const;

  Gcad::ErrorStatus         setTextStyleId(GcDbObjectId textStyleId);
  GcDbObjectId              textStyleId() const;

  Gcad::ErrorStatus         setTextAttachmentType(TextAttachmentType textAttachmentType, LeaderDirectionType leaderDirection);
  TextAttachmentType        textAttachmentType(LeaderDirectionType leaderDirection) const;

  Gcad::ErrorStatus         setTextAttachmentType(TextAttachmentType textAttachmentType);
  TextAttachmentType        textAttachmentType() const;

  Gcad::ErrorStatus         setTextAngleType(TextAngleType textAngleType);
  TextAngleType             textAngleType() const;

  Gcad::ErrorStatus         setTextAlignmentType(TextAlignmentType textAlignmentType);
  TextAlignmentType         textAlignmentType() const;

  Gcad::ErrorStatus         setTextAlignAlwaysLeft(bool bAlwaysLeft);
  bool                      textAlignAlwaysLeft() const;

  Gcad::ErrorStatus         setTextColor(const GcCmColor& textColor);
  GcCmColor                 textColor() const;

  Gcad::ErrorStatus         setTextHeight(double textHeight);
  double                    textHeight() const;

  Gcad::ErrorStatus         setEnableFrameText(bool enableFrameText);
  bool                      enableFrameText() const;

  Gcad::ErrorStatus         setAlignSpace(double alignSpace);
  double                    alignSpace() const;

  Gcad::ErrorStatus         setBlockId(const GCHAR* name);
  Gcad::ErrorStatus         setBlockId(GcDbObjectId blockId);
  GcDbObjectId              blockId() const;

  Gcad::ErrorStatus         setBlockColor(const GcCmColor& blockColor);
  GcCmColor                 blockColor() const;

  Gcad::ErrorStatus         setBlockScale(const GcGeScale3d& scale);
  GcGeScale3d               blockScale() const;

  Gcad::ErrorStatus         setEnableBlockScale(bool enableBlockScale);
  bool                      enableBlockScale() const;

  Gcad::ErrorStatus         setBlockRotation(double rotation);
  double                    blockRotation() const;

  Gcad::ErrorStatus         setEnableBlockRotation(bool enableBlockRotation);
  bool                      enableBlockRotation() const;

  Gcad::ErrorStatus         setBlockConnectionType(BlockConnectionType blockConnectionType);
  BlockConnectionType       blockConnectionType() const;

  Gcad::ErrorStatus         setScale(double scale);
  double                    scale() const;

  bool                      overwritePropChanged() const;
  Gcad::ErrorStatus         postMLeaderStyleToDb(GcDbDatabase* pDb, const GCHAR* styleName, GcDbObjectId & mleaderStyleId);

  Gcad::ErrorStatus         setAnnotative(bool isAnnotative);
  bool                      annotative() const;

  Gcad::ErrorStatus         setBreakSize(double size);
  double                    breakSize() const;

  Gcad::ErrorStatus         setTextAttachmentDirection(GcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);
  TextAttachmentDirection   textAttachmentDirection() const;

  Gcad::ErrorStatus setExtendLeaderToText(bool value);
  bool extendLeaderToText() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbMLeaderStyle::getName(GCHAR*& pName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbMLeaderStyle::getName, pName);
}

#endif 