/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __DBMLEADER_H__
#define __DBMLEADER_H__

#pragma once

#include "dbgrip.h"
#include "dbmleaderstyle.h"
#include "dbents.h"

const int MAX_LEADER_NUMBER = 5000;
const int MAX_LEADERLINE_NUMBER = 5000;

class GcDbMLeaderObjectContextData;

class GCDB_PORT GcDbMLeader : public GcDbEntity
{
public:
  enum MoveType {
    kMoveAllPoints = 0,
    kMoveAllExceptArrowHeaderPoints = 1,
    kMoveContentAndDoglegPoints = 2
  };

  enum gsMarkType {
    kNone = 0,
    kArrowMark = 1,
    kLeaderLineMark = kArrowMark + MAX_LEADERLINE_NUMBER,
    kDoglegMark = kLeaderLineMark + MAX_LEADERLINE_NUMBER,
    kMTextMark = kDoglegMark + MAX_LEADER_NUMBER,
    kMTextUnderLineMark = kMTextMark + 1,
    kToleranceMark = kMTextUnderLineMark + 1,
    kBlockMark = kToleranceMark + 1,
    kBlockAttribute = kBlockMark + 1
  };

  enum PropertyOverrideType {
    kLeaderLineType = 0,
    kLeaderLineColor = 1,
    kLeaderLineTypeId = 2,
    kLeaderLineWeight = 3,
    kEnableLanding = 4,
    kLandingGap = 5,
    kEnableDogleg = 6,
    kDoglegLength = 7,
    kArrowSymbolId = 8,
    kArrowSize = 9,
    kContentType = 10,
    kTextStyleId = 11,
    kTextLeftAttachmentType = 12,
    kTextAngleType = 13,
    kTextAlignmentType = 14,
    kTextColor = 15,
    kTextHeight = 16,
    kEnableFrameText = 17,
    kDefaultMText = 18,
    kBlockId = 19,
    kBlockColor = 20,
    kBlockScale = 21,
    kBlockRotation = 22,
    kBlockConnectionType = 23,
    kScale = 24,
    kTextRightAttachmentType = 25,
    kTextSwitchAlignmentType = 26,
    kTextAttachmentDirection = 27,
    kTextTopAttachmentType = 28,
    kTextBottomAttachmentType = 29,
    kExtendLeaderToText = 30,
    kSize = kExtendLeaderToText + 1
  };

  GcDbMLeader();
  ~GcDbMLeader();

  GCDB_DECLARE_MEMBERS(GcDbMLeader);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  Gcad::ErrorStatus subClose() override;
  Gcad::ErrorStatus subErase(Gsoft::Boolean erasing) override;
  void              objectClosed(const GcDbObjectId dbObjId) override;
  void              modified(const GcDbObject* dbObj) override;

  Gcad::ErrorStatus         setOverride(PropertyOverrideType propertyType, bool isOverride = true);
  bool                      isOverride(PropertyOverrideType propertyType) const;
  Gcad::ErrorStatus         setScale(double scale);
  double                    scale() const;
  Gcad::ErrorStatus         getBlockAttributeValue(const GcDbObjectId& attdefId, GcDbAttribute*& pAtt) const;
  Gcad::ErrorStatus         setBlockAttributeValue(const GcDbObjectId& attdefId, const GcDbAttribute* pAtt);
  Gcad::ErrorStatus         getBlockAttributeValue(const GcDbObjectId& attdefId, GCHAR*& value) const;
  Gcad::ErrorStatus         setBlockAttributeValue(const GcDbObjectId& attdefId, const GCHAR* value);

  GcGePlane         plane() const;
  void              setPlane(const GcGePlane& plane);
  GcGeVector3d      normal() const;
  Gcad::ErrorStatus moveMLeader(const GcGeVector3d& vector,
    MoveType moveType,
    bool bAutoSwitchDogleg = true);
  Gcad::ErrorStatus getContentGeomExtents(GcDbExtents& extents) const;
  int               numLeaders() const;
  Gcad::ErrorStatus getLeaderIndexes(GcArray<int>& leaderIndexes) const;
  Gcad::ErrorStatus addLeader(int& leaderIndex);
  Gcad::ErrorStatus removeLeader(int leaderIndex);
  int               numLeaderLines() const;
  Gcad::ErrorStatus getLeaderLineIndexes(GcArray<int>& leaderLineIndexes) const;
  Gcad::ErrorStatus addLeaderLine(int leaderIndex, int& leaderLineIndex);
  Gcad::ErrorStatus addLeaderLine(const GcGePoint3d& point, int& leaderLineIndex);
  Gcad::ErrorStatus removeLeaderLine(int leaderLineIndex);
  Gcad::ErrorStatus addFirstVertex(int leaderLineIndex, const GcGePoint3d& point);
  Gcad::ErrorStatus removeFirstVertex(int leaderLineIndex);
  Gcad::ErrorStatus getFirstVertex(int leaderLineIndex, GcGePoint3d& point) const;
  Gcad::ErrorStatus setFirstVertex(int leaderLineIndex, const GcGePoint3d& point);
  Gcad::ErrorStatus addLastVertex(int leaderLineIndex, const GcGePoint3d& point);
  Gcad::ErrorStatus removeLastVertex(int leaderLineIndex);
  Gcad::ErrorStatus getLastVertex(int leaderLineIndex, GcGePoint3d& point) const;
  Gcad::ErrorStatus setLastVertex(int leaderLineIndex, const GcGePoint3d& point);
  Gcad::ErrorStatus numVertices(int leaderLineIndex, int& num) const;
  Gcad::ErrorStatus setVertex(int leaderLineIndex, int index, const GcGePoint3d& point);
  Gcad::ErrorStatus getVertex(int leaderLineIndex, int index, GcGePoint3d& point) const;
  Gcad::ErrorStatus getLeaderIndex(int leaderLineIndex, int& leaderIndex) const;
  Gcad::ErrorStatus getLeaderLineIndexes(int leaderIndex, GcArray<int>& leaderLineIndexes) const;
  Gcad::ErrorStatus setDoglegDirection(int leaderIndex, const GcGeVector3d& vector);
  Gcad::ErrorStatus getDoglegDirection(int leaderIndex, GcGeVector3d& vector) const;

  Gcad::ErrorStatus                     setLeaderLineType(GcDbMLeaderStyle::LeaderType leaderLineType);
  GcDbMLeaderStyle::LeaderType          leaderLineType() const;

  Gcad::ErrorStatus setLeaderLineType(int leaderLineIndex, GcDbMLeaderStyle::LeaderType  leaderLineType);
  Gcad::ErrorStatus getLeaderLineType(int leaderLineIndex, GcDbMLeaderStyle::LeaderType& leaderLineType) const;

  Gcad::ErrorStatus                     setLeaderLineColor(const GcCmColor& leaderLineColor);
  GcCmColor                             leaderLineColor() const;

  Gcad::ErrorStatus setLeaderLineColor(int leaderLineIndex, const GcCmColor& leaderLineColor);
  Gcad::ErrorStatus getLeaderLineColor(int leaderLineIndex, GcCmColor& leaderLineColor) const;

  Gcad::ErrorStatus                     setLeaderLineTypeId(GcDbObjectId leaderLineTypeId);
  GcDbObjectId                          leaderLineTypeId() const;

  Gcad::ErrorStatus setLeaderLineTypeId(int leaderLineIndex, GcDbObjectId  leaderLineTypeId);
  Gcad::ErrorStatus getLeaderLineTypeId(int leaderLineIndex, GcDbObjectId& leaderLineTypeId) const;

  Gcad::ErrorStatus                     setLeaderLineWeight(GcDb::LineWeight leaderLineWeight);
  GcDb::LineWeight                      leaderLineWeight() const;

  Gcad::ErrorStatus setLeaderLineWeight(int leaderLineIndex, GcDb::LineWeight  leaderLineWeight);
  Gcad::ErrorStatus getLeaderLineWeight(int leaderLineIndex, GcDb::LineWeight& leaderLineWeight) const;

  Gcad::ErrorStatus                     setLandingGap(double landingGap);
  double                                landingGap() const;
  Gcad::ErrorStatus                     setEnableLanding(bool enableLanding);
  bool                                  enableLanding() const;
  Gcad::ErrorStatus                     setEnableDogleg(bool enableDogleg);
  bool                                  enableDogleg() const;
  Gcad::ErrorStatus                     setDoglegLength(int leaderIndex, double doglegLength);
  Gcad::ErrorStatus                     doglegLength(int leaderIndex, double& doglegLength) const;
  Gcad::ErrorStatus                     setDoglegLength(double doglegLength);
  double                                doglegLength() const;
  Gcad::ErrorStatus                     setArrowSymbolId(GcDbObjectId arrowSymbolId);
  GcDbObjectId                          arrowSymbolId() const;

  Gcad::ErrorStatus setArrowSymbolId(int leaderLineIndex, GcDbObjectId  arrowSymbolId);
  Gcad::ErrorStatus getArrowSymbolId(int leaderLineIndex, GcDbObjectId& arrowSymbolId) const;
  GcDbObjectId      arrowSymbolId(int leaderLineIndex) const;
  Gcad::ErrorStatus                     setArrowSize(double arrowSize);
  double                                arrowSize() const;
  Gcad::ErrorStatus setArrowSize(int leaderLineIndex, double  arrowSize);
  Gcad::ErrorStatus getArrowSize(int leaderLineIndex, double& arrowSize) const;

  Gcad::ErrorStatus                     setContentType(GcDbMLeaderStyle::ContentType contentType);
  GcDbMLeaderStyle::ContentType         contentType() const;

  Gcad::ErrorStatus                     setTextStyleId(GcDbObjectId textStyleId);
  GcDbObjectId                          textStyleId() const;

  Gcad::ErrorStatus                     setTextAttachmentType(GcDbMLeaderStyle::TextAttachmentType textAttachmentType,
    GcDbMLeaderStyle::LeaderDirectionType leaderDirection);
  GcDbMLeaderStyle::TextAttachmentType  textAttachmentType(GcDbMLeaderStyle::LeaderDirectionType leaderDirection) const;

  Gcad::ErrorStatus                     setTextAttachmentType(GcDbMLeaderStyle::TextAttachmentType textAttachmentType);
  GcDbMLeaderStyle::TextAttachmentType  textAttachmentType() const;

  Gcad::ErrorStatus                     setTextAngleType(GcDbMLeaderStyle::TextAngleType textAngleType);
  GcDbMLeaderStyle::TextAngleType       textAngleType() const;

  Gcad::ErrorStatus                     setTextAlignmentType(GcDbMLeaderStyle::TextAlignmentType textAlignmentType);
  GcDbMLeaderStyle::TextAlignmentType   textAlignmentType() const;

  Gcad::ErrorStatus                     setTextColor(const GcCmColor& textColor);
  GcCmColor                             textColor() const;

  Gcad::ErrorStatus                     setTextHeight(double textHeight);
  double                                textHeight() const;

  Gcad::ErrorStatus                     setEnableFrameText(bool enableFrameText);
  bool                                  enableFrameText() const;

  Gcad::ErrorStatus                     setMText(const GcDbMText* pMText);
  GcDbMText*                            mtext() const;

  Gcad::ErrorStatus                     setBlockContentId(GcDbObjectId blockId);
  GcDbObjectId                          blockContentId() const;

  Gcad::ErrorStatus                     setBlockColor(const GcCmColor& blockColor);
  GcCmColor                             blockColor() const;

  Gcad::ErrorStatus                     setBlockScale(const GcGeScale3d& scale);
  GcGeScale3d                           blockScale() const;

  Gcad::ErrorStatus                     setBlockRotation(double rotation);
  double                                blockRotation() const;

  Gcad::ErrorStatus                     setBlockConnectionType(GcDbMLeaderStyle::BlockConnectionType blockConnectionType);
  GcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;

  Gcad::ErrorStatus                     setEnableAnnotationScale(bool enableAnnotationScale);
  bool                                  enableAnnotationScale() const;

  Gcad::ErrorStatus                     setMLeaderStyle(GcDbObjectId newStyleId);
  GcDbObjectId                          MLeaderStyle();

  Gcad::ErrorStatus                     getOverridedMLeaderStyle(GcDbMLeaderStyle& mleaderStyle);
  Gcad::ErrorStatus                     setContextDataManager(void* pContextDataManager);
  void*                                 getContextDataManager() const;
  Gcad::ErrorStatus                     setBlockPosition(const GcGePoint3d& position);
  Gcad::ErrorStatus                     getBlockPosition(GcGePoint3d& position) const;
  Gcad::ErrorStatus                     setTextLocation(const GcGePoint3d& location);
  Gcad::ErrorStatus                     getTextLocation(GcGePoint3d& location) const;
  Gcad::ErrorStatus                     setToleranceLocation(const GcGePoint3d& location);
  Gcad::ErrorStatus                     getToleranceLocation(GcGePoint3d& location) const;
  bool                                  hasContent() const;
  Gcad::ErrorStatus                     connectionPoint(const GcGeVector3d& vect, GcGePoint3d& point) const;
  Gcad::ErrorStatus                     connectionPoint(const GcGeVector3d& vect,
    GcGePoint3d& point,
    GcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection) const;
  Gcad::ErrorStatus                     recomputeBreakPoints();
  Gcad::ErrorStatus                     postMLeaderToDb(GcDbDatabase* pDb);
  Gcad::ErrorStatus                     updateLeaderLinePosition();
  Gcad::ErrorStatus                     removeLeaderLineRefAssoc(int leaderLineIndex) const;
  Gcad::ErrorStatus                     updateContentScale(GcDbMLeaderObjectContextData* pContext);
  Gcad::ErrorStatus                     setTextAttachmentDirection(GcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection);

  GcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
  Gcad::ErrorStatus setExtendLeaderToText(bool value);
  bool extendLeaderToText() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#endif 