/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __DBTABLESTYLE_H__
#define __DBTABLESTYLE_H__

#pragma once

#include "dbmain.h"
#include "GdGChar.h"
#include "GcValue.h"
#include "GcString.h"
#include "DbFormattedTableData.h"
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

class GcDbTableTemplate;
class GCDB_PORT GcDbTableStyle : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTableStyle);
  GcDbTableStyle();
  ~GcDbTableStyle();

  virtual Gcad::ErrorStatus   getName(GcString & sName) const;
  virtual Gcad::ErrorStatus   getName(GCHAR*& pszName) const final;
  virtual Gcad::ErrorStatus   setName(const GCHAR * pszName);
  bool                        isRenamable() const;

  virtual const GCHAR*        description(void) const;
  virtual Gcad::ErrorStatus   setDescription(const GCHAR * pszDescription);

  virtual Gsoft::UInt32       bitFlags() const;
  virtual Gcad::ErrorStatus   setBitFlags(Gsoft::UInt32 flags);

  virtual GcDb::FlowDirection flowDirection(void) const;
  virtual Gcad::ErrorStatus   setFlowDirection(GcDb::FlowDirection flow);

  GSOFT_DEPRECATED virtual double horzCellMargin(void) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setHorzCellMargin(double dCellMargin);

  GSOFT_DEPRECATED virtual double vertCellMargin(void) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setVertCellMargin(double dCellMargin);

  GSOFT_DEPRECATED virtual bool isTitleSuppressed(void) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus suppressTitleRow(bool bValue);

  GSOFT_DEPRECATED virtual bool isHeaderSuppressed(void) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus suppressHeaderRow(bool bValue);

  virtual GcDbObjectId        textStyle(GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setTextStyle(const GcDbObjectId id, int rowTypes = GcDb::kAllRows);

  virtual double              textHeight(GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setTextHeight(double dHeight, int rowTypes = GcDb::kAllRows);

  virtual GcDb::CellAlignment alignment(GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setAlignment(GcDb::CellAlignment alignment, int rowTypes = GcDb::kAllRows);

  virtual GcCmColor           color(GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setColor(const GcCmColor& color, int rowTypes = GcDb::kAllRows);

  virtual GcCmColor           backgroundColor(GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setBackgroundColor(const GcCmColor& color, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual bool isBackgroundColorNone(GcDb::RowType rowType = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setBackgroundColorNone(bool bValue, int rowTypes = GcDb::kAllRows);
  virtual Gcad::ErrorStatus   getDataType(GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   getDataType(GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType,
    GcDb::RowType rowType) const;
  virtual Gcad::ErrorStatus   setDataType(GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setDataType(GcValue::DataType nDataType,
    GcValue::UnitType nUnitType,
    int rowTypes);

  GSOFT_DEPRECATED virtual const GCHAR* format(void) const;
  GSOFT_DEPRECATED virtual const GCHAR* format(GcDb::RowType rowType) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setFormat(const GCHAR* pszFormat);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setFormat(const GCHAR* pszFormat, int rowTypes);

  virtual GcDb::LineWeight    gridLineWeight(GcDb::GridLineType gridLineType,
    GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setGridLineWeight(GcDb::LineWeight lineWeight,
    int gridLineTypes = GcDb::kAllGridLines,
    int rowTypes = GcDb::kAllRows);
  virtual GcCmColor           gridColor(GcDb::GridLineType gridLineType,
    GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setGridColor(const GcCmColor color,
    int gridLineTypes = GcDb::kAllGridLines,
    int rowTypes = GcDb::kAllRows);
  virtual GcDb::Visibility    gridVisibility(GcDb::GridLineType gridLineType,
    GcDb::RowType rowType = GcDb::kDataRow) const;
  virtual Gcad::ErrorStatus   setGridVisibility(GcDb::Visibility visible,
    int gridLineTypes = GcDb::kAllGridLines,
    int rowTypes = GcDb::kAllRows);

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;
  Gcad::ErrorStatus   audit(GcDbAuditInfo* pAuditInfo) override;

  virtual Gcad::ErrorStatus   postTableStyleToDb(GcDbDatabase* pDb, const GCHAR* styleName, GcDbObjectId& tableStyleId);

  const GCHAR *     createCellStyle(void);
  Gcad::ErrorStatus createCellStyle(const GCHAR* pszCellStyle);
  Gcad::ErrorStatus createCellStyle(const GCHAR* pszCellStyle, const GCHAR* pszFromCellStyle);
  Gcad::ErrorStatus renameCellStyle(const GCHAR* pszOldName, const GCHAR* pszNewName);
  Gcad::ErrorStatus deleteCellStyle(const GCHAR* pszCellStyle);
  Gcad::ErrorStatus copyCellStyle(const GCHAR* pszSrcCellStyle, const GCHAR* pszTargetCellStyle);
  Gcad::ErrorStatus copyCellStyle(const GcDbTableStyle* pSrc, const GCHAR* pszSrcCellStyle, const GCHAR* pszTargetCellStyle);
  Gcad::ErrorStatus getUniqueCellStyleName(const GCHAR* pszBaseName, GcString& sUniqueName) const;
  bool              isCellStyleInUse(const GCHAR* pszCellStyle) const;
  int               numCellStyles(void) const;
  int               getCellStyles(GcStringArray& cellstyles) const;

  GcDbObjectId      textStyle(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setTextStyle(const GcDbObjectId& id, const GCHAR* pszCellStyle);

  double            textHeight(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setTextHeight(double dHeight, const GCHAR* pszCellStyle);

  GcDb::CellAlignment alignment(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setAlignment(GcDb::CellAlignment alignment, const GCHAR* pszCellStyle);

  GcCmColor         color(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setColor(const GcCmColor& color, const GCHAR* pszCellStyle);

  GcCmColor         backgroundColor(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setBackgroundColor(const GcCmColor& color, const GCHAR* pszCellStyle);

  Gcad::ErrorStatus getDataType(GcValue::DataType& nDataType, GcValue::UnitType& nUnitType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setDataType(GcValue::DataType nDataType, GcValue::UnitType nUnitType, const GCHAR* pszCellStyle);

  const GCHAR *     format(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setFormat(const GCHAR* pszFormat, const GCHAR* pszCellStyle);

  int               cellClass(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setCellClass(int nClass, const GCHAR* pszCellStyle);

  double            rotation(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setRotation(double fRotation, const GCHAR* pszCellStyle);

  bool              isMergeAllEnabled(const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus enableMergeAll(bool bEnable, const GCHAR* pszCellStyle);

  double            margin(GcDb::CellMargin nMargin, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setMargin(GcDb::CellMargin nMargins, double fMargin, const GCHAR* pszCellStyle);

  GcDb::LineWeight  gridLineWeight(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridLineWeight(GcDb::LineWeight lineWeight, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  GcCmColor         gridColor(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridColor(const GcCmColor color, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  GcDb::Visibility  gridVisibility(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridVisibility(GcDb::Visibility visible, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  double            gridDoubleLineSpacing(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridDoubleLineSpacing(double fSpacing, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  GcDb::GridLineStyle gridLineStyle(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridLineStyle(GcDb::GridLineStyle nLineStyle, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  GcDbObjectId      gridLinetype(GcDb::GridLineType gridLineType, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridLinetype(const GcDbObjectId& id, GcDb::GridLineType gridLineTypes, const GCHAR* pszCellStyle);
  Gcad::ErrorStatus getGridProperty(GcGridProperty& gridProp, GcDb::GridLineType nGridLineTypes, const GCHAR* pszCellStyle) const;
  Gcad::ErrorStatus setGridProperty(const GcGridProperty& gridProp, GcDb::GridLineType nGridLineTypes, const GCHAR* pszCellStyle);

  GcDbObjectId      getTemplate(void) const;
  Gcad::ErrorStatus getTemplate(GcDbTableTemplate*& pTemplate, GcDb::OpenMode mode);
  Gcad::ErrorStatus setTemplate(const GcDbObjectId& templateId, GcDb::MergeCellStyleOption nOption);
  Gcad::ErrorStatus setTemplate(GcDbTableTemplate* pTemplate, GcDb::MergeCellStyleOption nOption, GcDbObjectId& templateId);
  GcDbObjectId      removeTemplate(void);

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)

inline Gcad::ErrorStatus GcDbTableStyle::getName(GCHAR*& pName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbTableStyle::getName, pName);
}
#endif 