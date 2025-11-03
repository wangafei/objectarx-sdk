/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCDBSECTIONVIEWSTYLE_H__
#define __GCDBSECTIONVIEWSTYLE_H__

#pragma once
#include "dbModelDocViewStyle.h"

#pragma pack (push, 8)

class  GcDbSectionViewStyle : public GcDbModelDocViewStyle
{
public:
  enum IdentifierPosition {
    kEndCuttingPlane = 0,
    kAboveDirectionArrowLine = 1,
    kAboveDirectionArrowSymbol = 2,
    kStartDirectionArrow = 3,
    kEndDirectionArrow = 4,
  };

  enum ArrowDirection {
    kTowardsCuttingPlane = 0,
    kAwayFromCuttingPlane = 1,
  };

  GCDB_PORT GcDbSectionViewStyle();
  GCDB_PORT ~GcDbSectionViewStyle();
  GCDB_DECLARE_MEMBERS_EXPIMP(GcDbSectionViewStyle, GCDB_PORT);

  GCDB_PORT GcDbObjectId      identifierStyleId() const;
  GCDB_PORT Gcad::ErrorStatus setIdentifierStyleId(const GcDbObjectId &objId);

  GCDB_PORT GcCmColor         identifierColor() const;
  GCDB_PORT Gcad::ErrorStatus setIdentifierColor(const GcCmColor& color);

  GCDB_PORT double            identifierHeight() const;
  GCDB_PORT Gcad::ErrorStatus setIdentifierHeight(double height);

  GCDB_PORT const GCHAR *     identifierExcludeCharacters() const;
  GCDB_PORT Gcad::ErrorStatus setIdentifierExcludeCharacters(const GCHAR* str);

  GCDB_PORT GcDbObjectId      arrowStartSymbolId() const;
  GCDB_PORT Gcad::ErrorStatus setArrowStartSymbolId(const GcDbObjectId &arrowSymbolId);

  GCDB_PORT GcDbObjectId      arrowEndSymbolId() const;
  GCDB_PORT Gcad::ErrorStatus setArrowEndSymbolId(const GcDbObjectId &arrowSymbolId);

  GCDB_PORT GcCmColor         arrowSymbolColor() const;
  GCDB_PORT Gcad::ErrorStatus setArrowSymbolColor(const GcCmColor& color);

  GCDB_PORT double            arrowSymbolSize() const;
  GCDB_PORT Gcad::ErrorStatus setArrowSymbolSize(double size);

  GCDB_PORT double            arrowSymbolExtensionLength() const;
  GCDB_PORT Gcad::ErrorStatus setArrowSymbolExtensionLength(double length);

  GCDB_PORT GcDb::LineWeight  planeLineWeight() const;
  GCDB_PORT Gcad::ErrorStatus setPlaneLineWeight(GcDb::LineWeight lineweight);

  GCDB_PORT GcCmColor         planeLineColor() const;
  GCDB_PORT Gcad::ErrorStatus setPlaneLineColor(const GcCmColor& color);

  GCDB_PORT GcDbObjectId      planeLineTypeId() const;
  GCDB_PORT Gcad::ErrorStatus setPlaneLineTypeId(const GcDbObjectId &objId);

  GCDB_PORT GcCmColor         bendLineColor() const;
  GCDB_PORT Gcad::ErrorStatus setBendLineColor(const GcCmColor& color);

  GCDB_PORT GcDb::LineWeight  bendLineWeight() const;
  GCDB_PORT Gcad::ErrorStatus setBendLineWeight(GcDb::LineWeight lineweight);

  GCDB_PORT GcDbObjectId      bendLineTypeId() const;
  GCDB_PORT Gcad::ErrorStatus setBendLineTypeId(const GcDbObjectId &objId);

  GCDB_PORT double            bendLineLength() const;
  GCDB_PORT Gcad::ErrorStatus setBendLineLength(double length);

  GCDB_PORT double            endLineLength() const;
  GCDB_PORT Gcad::ErrorStatus setEndLineLength(double length);

  GCDB_PORT GcDbObjectId      viewLabelTextStyleId() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelTextStyleId(const GcDbObjectId &objId);

  GCDB_PORT GcCmColor         viewLabelTextColor() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelTextColor(const GcCmColor& color);

  GCDB_PORT double            viewLabelTextHeight() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelTextHeight(double height);

  GCDB_PORT double            viewLabelOffset() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelOffset(double offset);

  GCDB_PORT GcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelAttachment(GcDbModelDocViewStyle::AttachmentPoint attachment);

  GCDB_PORT GcDbModelDocViewStyle::TextAlignment viewLabelAlignment() const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelAlignment(GcDbModelDocViewStyle::TextAlignment alignment);

  GCDB_PORT const GCHAR *     viewLabelPattern() const;
  GCDB_PORT Gcad::ErrorStatus getViewLabelPattern(GcString &pattern,
    GcDbField *pField = NULL) const;
  GCDB_PORT Gcad::ErrorStatus setViewLabelPattern(const GCHAR* pattern,
    const GcDbField *pField = NULL);

  GCDB_PORT const GCHAR *     hatchPattern() const;
  GCDB_PORT Gcad::ErrorStatus setHatchPattern(const GCHAR* pattern);

  GCDB_PORT GcCmColor         hatchColor() const;
  GCDB_PORT Gcad::ErrorStatus setHatchColor(const GcCmColor& color);

  GCDB_PORT GcCmColor         hatchBackgroundColor() const;
  GCDB_PORT Gcad::ErrorStatus setHatchBackgroundColor(const GcCmColor& color);

  GCDB_PORT double            hatchScale() const;
  GCDB_PORT Gcad::ErrorStatus setHatchScale(double scale);

  GCDB_PORT const GcArray<double>& hatchAngles() const;
  GCDB_PORT Gcad::ErrorStatus setHatchAngles(const GcArray<double>& angleArray);

  GCDB_PORT Gcad::ErrorStatus setHatchTransparency(const GcCmTransparency& transparency);
  GCDB_PORT GcCmTransparency  hatchTransparency() const;

  GCDB_PORT bool              isContinuousLabeling() const;
  GCDB_PORT Gcad::ErrorStatus setContinuousLabeling(bool bValue);

  GCDB_PORT bool              showArrowheads() const;
  GCDB_PORT Gcad::ErrorStatus setShowArrowheads(bool bValue);

  GCDB_PORT bool              showViewLabel() const;
  GCDB_PORT Gcad::ErrorStatus setShowViewLabel(bool bValue);

  GCDB_PORT bool              showAllPlaneLines() const;
  GCDB_PORT Gcad::ErrorStatus setShowAllPlaneLines(bool bValue);

  GCDB_PORT bool              showAllBendIndentifiers() const;
  GCDB_PORT Gcad::ErrorStatus setShowAllBendIndentifiers(bool bValue);

  GCDB_PORT bool              showEndAndBendLines() const;
  GCDB_PORT Gcad::ErrorStatus setShowEndAndBendLines(bool bValue);

  GCDB_PORT bool              showHatching() const;
  GCDB_PORT Gcad::ErrorStatus setShowHatching(bool bValue);

  GCDB_PORT static bool       validateIdentifierExcludeCharacters(const GCHAR* str);

  GCDB_PORT GcDbSectionViewStyle::IdentifierPosition viewIdentifierPosition() const;
  GCDB_PORT Gcad::ErrorStatus setViewIdentifierPosition(GcDbSectionViewStyle::IdentifierPosition type);

  GCDB_PORT double viewIdentifierOffset() const;
  GCDB_PORT Gcad::ErrorStatus setViewIdentifierOffset(double offset);

  GCDB_PORT GcDbSectionViewStyle::ArrowDirection arrowPosition() const;
  GCDB_PORT Gcad::ErrorStatus setArrowPosition(GcDbSectionViewStyle::ArrowDirection type);

  GCDB_PORT double            endLineOvershoot() const;
  GCDB_PORT Gcad::ErrorStatus setEndLineOvershoot(double length);

protected:
  GCDB_PORT Gcad::ErrorStatus subDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
  GCDB_PORT Gcad::ErrorStatus subWblockClone(GcRxObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
};

#pragma pack (pop)

#endif 