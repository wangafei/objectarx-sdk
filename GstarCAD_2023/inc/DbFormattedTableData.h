/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "DbLinkedTableData.h"
#include "DbTableIterator.h"

struct GcGridProperty
{
  GcDb::GridProperty  mnPropMask;
  GcDb::GridLineStyle mnLineStyle;
  GcDb::LineWeight    mnLineWeight;
  GcDbHardPointerId   mLinetype;
  GcCmColor           mColor;
  GcDb::Visibility    mnVisibility;
  double              mfDoubleLineSpacing;
};

class GCDB_PORT GcDbFormattedTableData : public GcDbLinkedTableData
{
public:
  GCDB_DECLARE_MEMBERS(GcDbFormattedTableData);
  GcDbFormattedTableData(void);
  ~GcDbFormattedTableData(void);

  virtual int insertRowAndInherit(int nIndex, int nInheritFrom, int nNumRows);
  virtual int insertColumnAndInherit(int nIndex, int nInheritFrom, int nNumCols);

  virtual Gcad::ErrorStatus setFieldId(int nRow, int nCol, const GcDbObjectId& idField, GcDb::CellOption nFlag);
  virtual Gcad::ErrorStatus setFieldId(int nRow, int nCol, int nIndex, const GcDbObjectId& idField, GcDb::CellOption nFlag);
  virtual Gcad::ErrorStatus merge(const GcCellRange& range);
  virtual Gcad::ErrorStatus unmerge(const GcCellRange& range);
  virtual bool isMerged(int nRow, int nCol) const;
  virtual GcCellRange getMergeRange(int nRow, int nCol) const;

  virtual bool isFormatEditable(int nRow, int nCol) const;
  virtual double rotation(int nRow, int nCol) const;
  virtual double rotation(int nRow, int nCol, int nIndex) const;
  virtual Gcad::ErrorStatus setRotation(int nRow, int nCol, double fRotation);
  virtual Gcad::ErrorStatus setRotation(int nRow, int nCol, int nContent, double fRotation);
  virtual double scale(int nRow, int nCol) const;
  virtual double scale(int nRow, int nCol, int nContent) const;
  virtual Gcad::ErrorStatus setScale(int nRow, int nCol, double fScale);
  virtual Gcad::ErrorStatus setScale(int nRow, int nCol, int nIndex, double fScale);
  virtual bool isAutoScale(int nRow, int nCol) const;
  virtual bool isAutoScale(int nRow, int nCol, int nContent) const;
  virtual Gcad::ErrorStatus setAutoScale(int nRow, int nCol, bool bAutoScale);
  virtual Gcad::ErrorStatus setAutoScale(int nRow, int nCol, int nContent, bool bAutoScale);
  virtual GcDb::CellAlignment alignment(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setAlignment(int nRow, int nCol, GcDb::CellAlignment nAlignment);
  virtual GcCmColor contentColor(int nRow, int nCol) const;
  virtual GcCmColor contentColor(int nRow, int nCol, int nContent) const;
  virtual Gcad::ErrorStatus setContentColor(int nRow, int nCol, const GcCmColor& color);
  virtual Gcad::ErrorStatus setContentColor(int nRow, int nCol, int nContent, const GcCmColor& color);
  virtual GcDbObjectId textStyle(int nRow, int nCol) const;
  virtual GcDbObjectId textStyle(int nRow, int nCol, int nContent) const;
  virtual Gcad::ErrorStatus setTextStyle(int nRow, int nCol, const GcDbObjectId& idTextStyle);
  virtual Gcad::ErrorStatus setTextStyle(int nRow, int nCol, int nContent, const GcDbObjectId& idTextStyle);
  virtual double textHeight(int nRow, int nCol) const;
  virtual double textHeight(int nRow, int nCol, int nContent) const;
  virtual Gcad::ErrorStatus setTextHeight(int nRow, int nCol, double fTextHeight);
  virtual Gcad::ErrorStatus setTextHeight(int nRow, int nCol, int nContent, double fTextHeight);
  virtual GcCmColor backgroundColor(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setBackgroundColor(int nRow, int nCol, const GcCmColor& color);
  virtual GcDb::CellContentLayout contentLayout(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setContentLayout(int nRow, int nCol, GcDb::CellContentLayout nLayout);

  virtual GcDb::FlowDirection flowDirection(void) const;
  virtual Gcad::ErrorStatus setFlowDirection(GcDb::FlowDirection nDir);
  virtual double margin(int nRow, int nCol, GcDb::CellMargin nMargin) const;
  virtual Gcad::ErrorStatus setMargin(int nRow, int nCol, GcDb::CellMargin nMargins, double fMargin);
  virtual bool isMergeAllEnabled(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus enableMergeAll(int nRow, int nCol, bool bEnable);

  virtual GcDb::GridLineStyle gridLineStyle(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridLineStyle(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, GcDb::GridLineStyle nLineStyle);
  virtual GcDb::LineWeight gridLineWeight(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridLineWeight(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, GcDb::LineWeight nLineWeight);
  virtual GcDbObjectId gridLinetype(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridLinetype(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, const GcDbObjectId& idLinetype);
  virtual GcCmColor gridColor(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridColor(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, const GcCmColor& color);
  virtual GcDb::Visibility gridVisibility(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridVisibility(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, GcDb::Visibility nVisibility);
  virtual double gridDoubleLineSpacing(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setGridDoubleLineSpacing(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, double fSpacing);
  virtual Gcad::ErrorStatus getGridProperty(int nRow, int nCol, GcDb::GridLineType nGridLineType, GcGridProperty& gridProp) const;
  virtual Gcad::ErrorStatus setGridProperty(int nRow, int nCol, GcDb::GridLineType nGridLineTypes, const GcGridProperty& gridProp);
  virtual Gcad::ErrorStatus setGridProperty(const GcCellRange& range, GcDb::GridLineType nGridLineTypes, const GcGridProperty& gridProp);

  virtual GcDb::CellProperty getOverride(int nRow, int nCol, int nContent) const;
  virtual GcDb::GridProperty getOverride(int nRow, int nCol, GcDb::GridLineType nGridLineType) const;
  virtual Gcad::ErrorStatus setOverride(int nRow, int nCol, int nContent, GcDb::CellProperty nOverride);
  virtual Gcad::ErrorStatus setOverride(int nRow, int nCol, GcDb::GridLineType nGridLineType, GcDb::GridProperty nOverride);
  virtual Gcad::ErrorStatus removeAllOverrides(int nRow, int nCol);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};