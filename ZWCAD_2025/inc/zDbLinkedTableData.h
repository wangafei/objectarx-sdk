

#pragma once

#include "zDbLinkedData.h"
#include "zDbTableIterator.h"
#include "zAcCell.h"

class ZCDB_PORT ZcDbLinkedTableData : public ZcDbLinkedData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinkedTableData);

    ZcDbLinkedTableData(void);
    virtual ~ZcDbLinkedTableData(void);

    virtual Zcad::ErrorStatus clear(void) override;
    virtual Zcad::ErrorStatus copyFrom(const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption);
    virtual Zcad::ErrorStatus copyFrom(const ZcDbLinkedTableData* pSrc, 
                                             ZcDb::TableCopyOption nOption, 
                                             const ZcCellRange& srcRange, 
                                             const ZcCellRange& targetRange,
                                             ZcCellRange* pNewTargetRange);
    ZcDbTableIterator* getIterator(void) const;
    ZcDbTableIterator* getIterator(const ZcCellRange* pRange, 
                                             ZcDb::TableIteratorOption nOption) const;

    virtual Zcad::ErrorStatus setSize(int nRows, int nCols);
    virtual int numColumns        (void) const;
    virtual const ZTCHAR* getColumnName(int nIndex) const;
    virtual Zcad::ErrorStatus setColumnName(int nIndex, 
                                             const ZTCHAR* pszName);
    virtual int appendColumn      (int nNumCols);
    virtual int insertColumn      (int nIndex, 
                                             int nNumCols);
    virtual Zcad::ErrorStatus deleteColumn(int nIndex, 
                                             int nNumColsToDelete);

    virtual int numRows           (void) const;
    virtual bool canInsert        (int nIndex, 
                                             bool bRow) const;
    virtual int appendRow         (int nNumRows);
    virtual int insertRow         (int nIndex, 
                                             int nNumRows);
    virtual bool canDelete        (int nIndex, 
                                             int nCount, 
                                             bool bRow) const;
    virtual Zcad::ErrorStatus deleteRow(int nIndex, 
                                             int nNumRowsToDelete);

    virtual bool isContentEditable(int nRow, 
                                             int nCol) const;
    virtual ZcDb::CellState cellState(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus setCellState(int nRow, 
                                             int nCol, 
                                             ZcDb::CellState nCellState);
    virtual ZcString getToolTip   (int nRow,
                                             int nCol) const;
    virtual Zcad::ErrorStatus setToolTip(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszToolTip);
    virtual int getCustomData     (int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus setCustomData(int nRow, 
                                             int nCol, 
                                             int nData);
    virtual Zcad::ErrorStatus getCustomData(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             ZcValue* pData) const;
    virtual Zcad::ErrorStatus setCustomData(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszKey, 
                                             const ZcValue* pData);
    virtual bool isLinked         (int nRow, 
                                             int nCol) const;
    virtual ZcDbObjectId getDataLink(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus getDataLink(int nRow, 
                                             int nCol, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    virtual int getDataLink       (const ZcCellRange* pRange, 
                                             ZcDbObjectIdArray& dataLinkIds) const;
    virtual Zcad::ErrorStatus setDataLink(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    virtual Zcad::ErrorStatus setDataLink(const ZcCellRange& range, 
                                             const ZcDbObjectId& idDataLink,
                                             bool bUpdate);
    virtual ZcCellRange getDataLinkRange(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus removeDataLink(int nRow, 
                                             int nCol);
    virtual Zcad::ErrorStatus removeDataLink(void);
    virtual Zcad::ErrorStatus updateDataLink(int nRow,
                                             int nCol, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    virtual Zcad::ErrorStatus updateDataLink(ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

    virtual int numContents       (int nRow, 
                                             int nCol) const;
    virtual int createContent     (int nRow, 
                                             int nCol, 
                                             int nIndex);
    virtual Zcad::ErrorStatus moveContent(int nRow, 
                                             int nCol, 
                                             int nFromIndex, 
                                             int nToIndex);
    virtual Zcad::ErrorStatus deleteContent(int nRow, 
                                             int nCol, 
                                             int nContent);
    virtual Zcad::ErrorStatus deleteContent(int nRow, 
                                             int nCol);
    virtual Zcad::ErrorStatus deleteContent(const ZcCellRange& range);

    virtual ZcDb::CellContentType contentType(int nRow, 
                                             int nCol) const;
    virtual ZcDb::CellContentType contentType(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    virtual Zcad::ErrorStatus getDataType(int nRow, 
                                             int nCol, 
                                             ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType) const;
    virtual Zcad::ErrorStatus getDataType(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcValue::DataType& nDataType,
                                             ZcValue::UnitType& nUnitType) const;
    virtual Zcad::ErrorStatus setDataType(int nRow, 
                                             int nCol, 
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    virtual Zcad::ErrorStatus setDataType(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcValue::DataType nDataType,
                                             ZcValue::UnitType nUnitType);
    virtual ZcString dataFormat   (int nRow,
                                             int nCol) const;
    virtual ZcString dataFormat   (int nRow,
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setDataFormat(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszFormat);
    virtual Zcad::ErrorStatus setDataFormat(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZTCHAR* pszFormat);
    virtual Zcad::ErrorStatus getValue(int nRow, 
                                             int nCol, 
                                             ZcValue& value) const;
    virtual Zcad::ErrorStatus getValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             ZcValue::FormatOption nOption,
                                             ZcValue& value) const;
    virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             const ZcValue& value);
    virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcValue& value);
    virtual Zcad::ErrorStatus setValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcValue& value,
                                             ZcValue::ParseOption nOption);
    virtual ZcString getText      (int nRow,
                                             int nCol) const;
    virtual ZcString getText      (int nRow,
                                             int nCol, 
                                             int nContent) const;
    virtual ZcString getText      (int nRow,
                                             int nCol, 
                                             int nContent, 
                                             ZcValue::FormatOption nOption) const;
    virtual Zcad::ErrorStatus setText(int nRow, 
                                             int nCol, 
                                             const ZTCHAR* pszText);
    virtual Zcad::ErrorStatus setText(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZTCHAR* pszText);
    virtual bool hasFormula       (int nRow, 
                                             int nCol, 
                                             int nContent) const;
    virtual ZcString getFormula   (int nRow,
                                             int nCol, 
                                             int nContent) const;
    virtual Zcad::ErrorStatus setFormula(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZTCHAR* pszFormula);
    virtual ZcDbObjectId getFieldId(int nRow, 
                                             int nCol) const;
    virtual ZcDbObjectId getFieldId(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idField);
    virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idField);
    virtual Zcad::ErrorStatus getField(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             ZcDbField*& pField,
                                             ZcDb::OpenMode mode) const;
    virtual ZcDbObjectId getBlockTableRecordId(int nRow, 
                                             int nCol) const;
    virtual ZcDbObjectId getBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    virtual Zcad::ErrorStatus setBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idBTR);
    virtual Zcad::ErrorStatus setBlockTableRecordId(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idBTR);
    virtual ZcString getBlockAttributeValue(int nRow,
                                             int nCol, 
                                             const ZcDbObjectId& idAttDef) const;
    virtual ZcString getBlockAttributeValue(int nRow,
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idAttDef) const;
    virtual Zcad::ErrorStatus setBlockAttributeValue(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idAttDef, 
                                             const ZTCHAR* pszAttValue);
    virtual Zcad::ErrorStatus setBlockAttributeValue(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             const ZcDbObjectId& idAttDef, 
                                             const ZTCHAR* pszAttValue);

    virtual Zcad::ErrorStatus evaluateFormula(void);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
};
