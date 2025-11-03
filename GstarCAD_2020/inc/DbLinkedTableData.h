/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////



#ifndef OD_DBLINKEDTABLEDATA_H
#define OD_DBLINKEDTABLEDATA_H

#include "TD_PackPush.h"

#include "DbObject.h"
#include "DbTableStyle.h"
#include "DbLinkedData.h"
#include "DbDataLink.h"
#include "DbField.h"

class OdDbTableIterator;
/** Description:
    Work-in-progress. This class represents LinkedTableData objects in an OdDbDatabase instance.
    This enables linking to Excel data.

    Library:
    TD_Db

	{group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbLinkedTableData : public OdDbLinkedData
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLinkedTableData);

  OdDbLinkedTableData();
  virtual ~OdDbLinkedTableData();

  OdDbTableIterator* getIterator(void) const;
  OdDbTableIterator* getIterator(const OdCellRange* pRange, OdDb::TableIteratorOption nOption) const;

  virtual OdResult setSize(
                    int nRows, 
                    int nCols);

  virtual OdInt32 numColumns() const;

  virtual OdString getColumnName(
                    int nIndex) const;

  virtual OdResult setColumnName(
                int nIndex, 
                const OdChar *name);

  virtual OdInt32 appendColumn(
                    int nNumCols);

  virtual OdInt32 insertColumn(
                    int nIndex, 
                    int nNumCols);

  virtual OdResult deleteColumn(
                int nIndex, 
                int nNumColsToDelete);

  virtual OdInt32 numRows() const;

  virtual bool canInsert(
                int nIndex, 
                bool bRow) const;

  virtual int appendRow(
                int nNumRows);

  virtual int insertRow(
                int nIndex, 
                int nNumRows);

  virtual bool canDelete(
                int nIndex, 
                int nCount, 
                bool bRow) const;

  virtual OdResult deleteRow(
                    int nIndex, 
                    int nNumRowsToDelete);

  virtual bool isContentEditable(
                int nRow, 
                int nCol) const;

  virtual OdDb::CellState cellState(
                            int nRow, 
                            int nCol) const;

  virtual OdResult setCellState(
                    int nRow, 
                    int nCol, 
                    OdDb::CellState nCellState);

  virtual OdString getToolTip(
                    int nRow, 
                    int nCol) const;

  virtual OdResult setToolTip(
                    int nRow, 
                    int nCol, 
                    const OdString& sToolTip);

  virtual int getCustomData(
                    int nRow, 
                    int nCol) const;

  virtual OdResult setCustomData(
                    int nRow, 
                    int nCol, 
                    int nData);

  virtual OdResult getCustomData(
                    int nRow, 
                    int nCol, 
                    const OdString& sKey ,
                    OdValue *pValue) const;

  virtual OdResult setCustomData(
                    int nRow, 
                    int nCol, 
                    const OdString& sKey, 
                    const OdValue* pData);

  virtual int numContents(
                int nRow, 
                int nCol) const;

  virtual int createContent(
                int nRow, 
                int nCol, 
                int nIndex);
  
  virtual OdResult moveContent(
                    int nRow, 
                    int nCol, 
                    int nFromIndex, 
                    int nToIndex);

  virtual OdResult deleteContent(
    int nRow, 
    int nCol, 
    int nContent);

  virtual OdResult deleteContent(
    int nRow, 
    int nCol);

  virtual OdResult deleteContent(
    const OdCellRange& range);

  virtual OdDb::CellContentType contentType(
                                  int nRow, 
                                  int nCol) const;

  virtual OdDb::CellContentType contentType(
                                  int nRow, 
                                  int nCol, 
                                  int nContent) const;

  virtual OdResult getDataType(
                    int nRow, 
                    int nCol, 
                    OdValue::DataType& nDataType, 
                    OdValue::UnitType& nUnitType) const;

  virtual OdResult getDataType(
                    int nRow, 
                    int nCol, 
                    int nContent,
                    OdValue::DataType& nDataType, 
                    OdValue::UnitType& nUnitType) const;

  virtual OdResult setDataType(
                    int nRow, 
                    int nCol, 
                    OdValue::DataType nDataType, 
                    OdValue::UnitType nUnitType);

  virtual OdResult setDataType(
                    int nRow, 
                    int nCol, 
                    int nContent,
                    OdValue::DataType nDataType, 
                    OdValue::UnitType nUnitType);

  virtual OdString dataFormat(
                    int nRow, 
                    int nCol) const;

  virtual OdString dataFormat(
                    int nRow, 
                    int nCol,
                    int nContent) const;

  virtual OdResult setDataFormat(
                    int nRow, 
                    int nCol, 
                    const OdChar* sFormat);

  virtual OdResult setDataFormat(
                    int nRow, 
                    int nCol, 
                    int nContent,
                    const OdChar* sFormat);

  virtual OdResult getValue(
                    int nRow ,
                    int nCol ,
                    OdValue &value) const;

  virtual OdResult getValue(
                    int nRow ,
                    int nCol ,
                    int nContent ,
                    OdValue::FormatOption nOption ,
                    OdValue &value) const;

  virtual OdResult setValue(
                    int nRow, 
                    int nCol, 
                    const OdValue& value);

  virtual OdResult setValue(
                    int nRow, 
                    int nCol, 
                    int nContent, 
                    const OdValue& value);

  virtual OdResult setValue(
                    int nRow, 
                    int nCol, 
                    int nContent, 
                    const OdValue& value,
                    OdValue::ParseOption nOption);

  virtual OdString getText(
                    int nRow, 
                    int nCol) const;

  virtual OdString getText(
                    int nRow, 
                    int nCol, 
                    int nContent) const;

  virtual OdString getText(
                    int nRow, 
                    int nCol, 
                    int nContent, 
                    OdValue::FormatOption nOption) const;

  virtual OdResult setText(
                    int nRow, 
                    int nCol, 
                    const OdChar *sText);

  virtual OdResult setText(
                    int nRow, 
                    int nCol, 
                    int nContent, 
                    const OdChar *sText);

  virtual bool hasFormula(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent) const;

  virtual OdString getFormula(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent) const;

  virtual OdResult setFormula(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdString sFormula);

  virtual OdDbObjectId getFieldId(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdDbObjectId getFieldId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent) const;

  virtual OdResult setFieldId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idField);

  virtual OdResult setFieldId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdDbObjectId& idField);

  virtual OdDbFieldPtr getField(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent,
    OdDb::OpenMode mode) const;

  virtual OdResult getField(int nRow, 
    int nCol, 
    int nContent,
    OdDbField*& pField,
    OdDb::OpenMode mode) const;

  virtual OdDbObjectId getBlockTableRecordId(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdDbObjectId getBlockTableRecordId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent) const;

  virtual OdResult setBlockTableRecordId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idBTR);

  virtual OdResult setBlockTableRecordId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdDbObjectId& idBTR);
 
  virtual OdString getBlockAttributeValue(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idAttDef) const;
  
  virtual OdString getBlockAttributeValue(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdDbObjectId& idAttDef) const;
  
  virtual OdResult setBlockAttributeValue(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idAttDef, 
    const OdString sAttValue);

  virtual OdResult setBlockAttributeValue(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdDbObjectId& idAttDef, 
    const OdString sAttValue);

  virtual bool isLinked(
    OdInt32 nRow, 
    OdInt32 nCol) const;
  virtual OdDbObjectId getDataLink(
    OdInt32 nRow, 
    OdInt32 nCol) const;
  virtual OdDbDataLinkPtr getDataLink(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::OpenMode mode) const;
  virtual OdResult getDataLink(OdInt32 nRow, 
                                  OdInt32 nCol, 
                                  OdDbDataLink*& pDataLink, 
                                  OdDb::OpenMode mode) const;
  virtual OdInt32 getDataLink(
    const OdCellRange& pRange, 
    OdDbObjectIdArray& dataLinkIds) const;
  virtual OdResult setDataLink(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idDataLink,
    bool bUpdate);
  virtual OdResult setDataLink(
    const OdCellRange& range, 
    const OdDbObjectId& idDataLink,
    bool bUpdate);
  virtual OdCellRange getDataLinkRange(
    OdInt32 nRow, 
    OdInt32 nCol) const;
  virtual OdResult removeDataLink(
    OdInt32 nRow, 
    OdInt32 nCol);
  virtual OdResult removeDataLink();

  virtual OdResult updateDataLink(
    OdInt32 nRow,
    OdInt32 nCol, 
    OdDb::UpdateDirection nDir,
    OdDb::UpdateOption nOption);
  virtual OdResult updateDataLink(
    OdDb::UpdateDirection nDir, 
    OdDb::UpdateOption nOption);

  virtual OdResult clear();
  virtual OdResult copyFrom(
    const OdRxObject* pSource);
  virtual OdResult copyFrom(const OdDbLinkedTableData* pSrc,
    OdDb::TableCopyOption nOption);
  virtual OdResult copyFrom(const OdDbLinkedTableData* pSrc, 
    OdDb::TableCopyOption nOption, 
    const OdCellRange& srcRange, 
    const OdCellRange& targetRange,
    OdCellRange* pNewTargetRange);

  virtual OdResult evaluateFormula();

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
};

typedef OdSmartPtr<OdDbLinkedTableData> OdDbLinkedTableDataPtr;

#include "TD_PackPop.h"

#endif // OD_DBLINKEDTABLEDATA_H
