/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCDBDETAILVIEWSTYLE_H__
#define __GCDBDETAILVIEWSTYLE_H__

#pragma once
#include "dbModelDocViewStyle.h"

class GCDB_PORT GcDbDetailViewStyle : public GcDbModelDocViewStyle
{
public:
  enum IdentifierPlacement {
    kOutsideBoundary = 0,
    kOutsideBoundaryWithLeader,
    kOnBoundary,
    kOnBoundaryWithLeader,
  };

  enum ModelEdge {
    kSmooth = 0,
    kSmoothWithBorder,
    kSmoothWithConnectionLine,
    kJagged,
  };

  GcDbDetailViewStyle();
  ~GcDbDetailViewStyle();
  GCDB_DECLARE_MEMBERS(GcDbDetailViewStyle);

  GcDbObjectId      identifierStyleId() const;
  Gcad::ErrorStatus setIdentifierStyleId(const GcDbObjectId &objId);
  GcCmColor         identifierColor() const;
  Gcad::ErrorStatus setIdentifierColor(const GcCmColor& color);
  double            identifierHeight() const;
  Gcad::ErrorStatus setIdentifierHeight(double height);
  double            identifierOffset() const;
  Gcad::ErrorStatus setIdentifierOffset(double offset);
  GcDbDetailViewStyle::IdentifierPlacement identifierPlacement() const;
  Gcad::ErrorStatus setIdentifierPlacement(GcDbDetailViewStyle::IdentifierPlacement placement);
  GcDbObjectId      arrowSymbolId() const;
  Gcad::ErrorStatus setArrowSymbolId(const GcDbObjectId &arrowSymbolId);
  GcCmColor         arrowSymbolColor() const;
  Gcad::ErrorStatus setArrowSymbolColor(const GcCmColor& color);
  double            arrowSymbolSize() const;
  Gcad::ErrorStatus setArrowSymbolSize(double size);
  bool              showArrows() const;
  Gcad::ErrorStatus setShowArrows(bool bValue);
  GcDb::LineWeight  boundaryLineWeight() const;
  Gcad::ErrorStatus setBoundaryLineWeight(GcDb::LineWeight lineweight);
  GcCmColor         boundaryLineColor() const;
  Gcad::ErrorStatus setBoundaryLineColor(const GcCmColor& color);
  GcDbObjectId      boundaryLineTypeId() const;
  Gcad::ErrorStatus setBoundaryLineTypeId(const GcDbObjectId &objId);
  GcDb::LineWeight  connectionLineWeight() const;
  Gcad::ErrorStatus setConnectionLineWeight(GcDb::LineWeight lineweight);
  GcCmColor         connectionLineColor() const;
  Gcad::ErrorStatus setConnectionLineColor(const GcCmColor& color);
  GcDbObjectId      connectionLineTypeId() const;
  Gcad::ErrorStatus setConnectionLineTypeId(const GcDbObjectId &objId);
  GcDbObjectId      viewLabelTextStyleId() const;
  Gcad::ErrorStatus setViewLabelTextStyleId(const GcDbObjectId &objId);
  GcCmColor         viewLabelTextColor() const;
  Gcad::ErrorStatus setViewLabelTextColor(const GcCmColor& color);
  double            viewLabelTextHeight() const;
  Gcad::ErrorStatus setViewLabelTextHeight(double height);
  double            viewLabelOffset() const;
  Gcad::ErrorStatus setViewLabelOffset(double offset);
  GcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment() const;
  Gcad::ErrorStatus setViewLabelAttachment(GcDbModelDocViewStyle::AttachmentPoint attachment);
  GcDbModelDocViewStyle::TextAlignment viewLabelAlignment() const;
  Gcad::ErrorStatus setViewLabelAlignment(GcDbModelDocViewStyle::TextAlignment alignment);
  const GCHAR *     viewLabelPattern() const;
  Gcad::ErrorStatus getViewLabelPattern(GcString &pattern, GcDbField *pField = NULL) const;
  Gcad::ErrorStatus setViewLabelPattern(const GCHAR* pattern, const GcDbField *pField = NULL);
  bool              showViewLabel() const;
  Gcad::ErrorStatus setShowViewLabel(bool bValue);
  GcDbDetailViewStyle::ModelEdge modelEdge() const;
  Gcad::ErrorStatus setModelEdge(GcDbDetailViewStyle::ModelEdge placement);
  GcDb::LineWeight  borderLineWeight() const;
  Gcad::ErrorStatus setBorderLineWeight(GcDb::LineWeight lineweight);
  GcCmColor         borderLineColor() const;
  Gcad::ErrorStatus setBorderLineColor(const GcCmColor& color);
  GcDbObjectId      borderLineTypeId() const;
  Gcad::ErrorStatus setBorderLineTypeId(const GcDbObjectId &objId);

protected:
  Gcad::ErrorStatus subDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
  Gcad::ErrorStatus subWblockClone(GcRxObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
};

#endif 