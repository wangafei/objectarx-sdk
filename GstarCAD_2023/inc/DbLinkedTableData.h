/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "DbLinkedData.h"
#include "DbTableIterator.h"
#include "GcCell.h"

class GCDB_PORT GcDbLinkedTableData : public GcDbLinkedData
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLinkedTableData);
  GcDbLinkedTableData(void);
  ~GcDbLinkedTableData(void);

  Gcad::ErrorStatus clear(void) override;
  virtual Gcad::ErrorStatus copyFrom(const GcDbLinkedTableData* pSrc, GcDb::TableCopyOption nOption);
  virtual Gcad::ErrorStatus copyFrom(const GcDbLinkedTableData* pSrc,
    GcDb::TableCopyOption nOption,
    const GcCellRange& srcRange,
    const GcCellRange& targetRange,
    GcCellRange* pNewTargetRange);
  GcDbTableIterator* getIterator(void) const;
  GcDbTableIterator* getIterator(const GcCellRange* pRange, GcDb::TableIteratorOption nOption) const;

  virtual Gcad::ErrorStatus setSize(int nRows, int nCols);
  virtual int numColumns(void) const;
  virtual const GCHAR* getColumnName(int nIndex) const;
  virtual Gcad::ErrorStatus setColumnName(int nIndex, const GCHAR* pszName);
  virtual int appendColumn(int nNumCols);
  virtual int insertColumn(int nIndex, int nNumCols);
  virtual Gcad::ErrorStatus deleteColumn(int nIndex, int nNumColsToDelete);

  virtual int numRows(void) const;
  virtual bool canInsert(int nIndex, bool bRow) const;
  virtual int appendRow(int nNumRows);
  virtual int insertRow(int nIndex, int nNumRows);
  virtual bool canDelete(int nIndex,
    int nCount,
    bool bRow) const;
  virtual Gcad::ErrorStatus deleteRow(int nIndex, int nNumRowsToDelete);
  virtual bool isContentEditable(int nRow, int nCol) const;
  virtual GcDb::CellState cellState(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setCellState(int nRow,
    int nCol,
    GcDb::CellState nCellState);
  virtual GcString getToolTip(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setToolTip(int nRow,
    int nCol,
    const GCHAR* pszToolTip);
  virtual int getCustomData(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setCustomData(int nRow,
    int nCol,
    int nData);
  virtual Gcad::ErrorStatus getCustomData(int nRow,
    int nCol,
    const GCHAR* pszKey,
    GcValue* pData) const;
  virtual Gcad::ErrorStatus setCustomData(int nRow,
    int nCol,
    const GCHAR* pszKey,
    const GcValue* pData);
  virtual bool isLinked(int nRow, int nCol) const;
  virtual GcDbObjectId getDataLink(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus getDataLink(int nRow,
    int nCol,
    GcDbDataLink*& pDataLink,
    GcDb::OpenMode mode) const;
  virtual int getDataLink(const GcCellRange* pRange, GcDbObjectIdArray& dataLinkIds) const;
  virtual Gcad::ErrorStatus setDataLink(int nRow,
    int nCol,
    const GcDbObjectId& idDataLink,
    bool bUpdate);
  virtual Gcad::ErrorStatus setDataLink(const GcCellRange& range,
    const GcDbObjectId& idDataLink,
    bool bUpdate);
  virtual GcCellRange getDataLinkRange(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus removeDataLink(int nRow, int nCol);
  virtual Gcad::ErrorStatus removeDataLink(void);
  virtual Gcad::ErrorStatus updateDataLink(int nRow,
    int nCol,
    GcDb::UpdateDirection nDir,
    GcDb::UpdateOption nOption);
  virtual Gcad::ErrorStatus updateDataLink(GcDb::UpdateDirection nDir, GcDb::UpdateOption nOption);

  virtual int numContents(int nRow, int nCol) const;
  virtual int createContent(int nRow,
    int nCol,
    int nIndex);
  virtual Gcad::ErrorStatus moveContent(int nRow,
    int nCol,
    int nFromIndex,
    int nToIndex);
  virtual Gcad::ErrorStatus deleteContent(int nRow,
    int nCol,
    int nContent);
  virtual Gcad::ErrorStatus deleteContent(int nRow, int nCol);
  virtual Gcad::ErrorStatus deleteContent(const GcCellRange& range);

  virtual GcDb::CellContentType contentType(int nRow, int nCol) const;
  virtual GcDb::CellContentType contentType(int nRow,
    int nCol,
    int nContent) const;
  virtual Gcad::ErrorStatus getDataType(int nRow,
    int nCol,
    GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType) const;
  virtual Gcad::ErrorStatus getDataType(int nRow,
    int nCol,
    int nContent,
    GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType) const;
  virtual Gcad::ErrorStatus setDataType(int nRow,
    int nCol,
    GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  virtual Gcad::ErrorStatus setDataType(int nRow,
    int nCol,
    int nContent,
    GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  virtual GcString dataFormat(int nRow, int nCol) const;
  virtual GcString dataFormat(int nRow,
    int nCol,
    int nContent) const;
  virtual Gcad::ErrorStatus setDataFormat(int nRow,
    int nCol,
    const GCHAR* pszFormat);
  virtual Gcad::ErrorStatus setDataFormat(int nRow,
    int nCol,
    int nContent,
    const GCHAR* pszFormat);
  virtual Gcad::ErrorStatus getValue(int nRow,
    int nCol,
    GcValue& value) const;
  virtual Gcad::ErrorStatus getValue(int nRow,
    int nCol,
    int nContent,
    GcValue::FormatOption nOption,
    GcValue& value) const;
  virtual Gcad::ErrorStatus setValue(int nRow,
    int nCol,
    const GcValue& value);
  virtual Gcad::ErrorStatus setValue(int nRow,
    int nCol,
    int nContent,
    const GcValue& value);
  virtual Gcad::ErrorStatus setValue(int nRow,
    int nCol,
    int nContent,
    const GcValue& value,
    GcValue::ParseOption nOption);
  virtual GcString getText(int nRow, int nCol) const;
  virtual GcString getText(int nRow,
    int nCol,
    int nContent) const;
  virtual GcString getText(int nRow,
    int nCol,
    int nContent,
    GcValue::FormatOption nOption) const;
  virtual Gcad::ErrorStatus setText(int nRow,
    int nCol,
    const GCHAR* pszText);
  virtual Gcad::ErrorStatus setText(int nRow,
    int nCol,
    int nContent,
    const GCHAR* pszText);
  virtual bool hasFormula(int nRow,
    int nCol,
    int nContent) const;
  virtual GcString getFormula(int nRow,
    int nCol,
    int nContent) const;
  virtual Gcad::ErrorStatus setFormula(int nRow,
    int nCol,
    int nContent,
    const GCHAR* pszFormula);
  virtual GcDbObjectId getFieldId(int nRow, int nCol) const;
  virtual GcDbObjectId getFieldId(int nRow,
    int nCol,
    int nContent) const;
  virtual Gcad::ErrorStatus setFieldId(int nRow,
    int nCol,
    const GcDbObjectId& idField);
  virtual Gcad::ErrorStatus setFieldId(int nRow,
    int nCol,
    int nContent,
    const GcDbObjectId& idField);
  virtual Gcad::ErrorStatus getField(int nRow,
    int nCol,
    int nContent,
    GcDbField*& pField,
    GcDb::OpenMode mode) const;
  virtual GcDbObjectId getBlockTableRecordId(int nRow, int nCol) const;
  virtual GcDbObjectId getBlockTableRecordId(int nRow,
    int nCol,
    int nContent) const;
  virtual Gcad::ErrorStatus setBlockTableRecordId(int nRow,
    int nCol,
    const GcDbObjectId& idBTR);
  virtual Gcad::ErrorStatus setBlockTableRecordId(int nRow,
    int nCol,
    int nContent,
    const GcDbObjectId& idBTR);
  virtual GcString getBlockAttributeValue(int nRow,
    int nCol,
    const GcDbObjectId& idAttDef) const;
  virtual GcString getBlockAttributeValue(int nRow,
    int nCol,
    int nContent,
    const GcDbObjectId& idAttDef) const;
  virtual Gcad::ErrorStatus setBlockAttributeValue(int nRow,
    int nCol,
    const GcDbObjectId& idAttDef,
    const GCHAR* pszAttValue);
  virtual Gcad::ErrorStatus setBlockAttributeValue(int nRow,
    int nCol,
    int nContent,
    const GcDbObjectId& idAttDef,
    const GCHAR* pszAttValue);
  virtual Gcad::ErrorStatus evaluateFormula(void);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};