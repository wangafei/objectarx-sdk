/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "dbents.h"
#include "GcField.h"
#include "DbLinkedTableData.h"
#include "DbFormattedTableData.h"

#pragma pack(push, 8)

class GcDbTableIterator;
class GcDbTableTemplate;

typedef GcDbFullSubentPathArray GcSubentPathArray;

class GCDB_PORT GcDbTable : public GcDbBlockReference
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTable);

  enum TableStyleOverrides {
    kTitleSuppressed = 1,
    kHeaderSuppressed = 2,
    kFlowDirection = 3,
    kHorzCellMargin = 4,
    kVertCellMargin = 5,
    kTitleRowColor = 6,
    kHeaderRowColor = 7,
    kDataRowColor = 8,
    kTitleRowFillNone = 9,
    kHeaderRowFillNone = 10,
    kDataRowFillNone = 11,
    kTitleRowFillColor = 12,
    kHeaderRowFillColor = 13,
    kDataRowFillColor = 14,
    kTitleRowAlignment = 15,
    kHeaderRowAlignment = 16,
    kDataRowAlignment = 17,
    kTitleRowTextStyle = 18,
    kHeaderRowTextStyle = 19,
    kDataRowTextStyle = 20,
    kTitleRowTextHeight = 21,
    kHeaderRowTextHeight = 22,
    kDataRowTextHeight = 23,
    kTitleRowDataType = 24,
    kHeaderRowDataType = 25,
    kDataRowDataType = 26,

    kTitleHorzTopColor = 40,
    kTitleHorzInsideColor = 41,
    kTitleHorzBottomColor = 42,
    kTitleVertLeftColor = 43,
    kTitleVertInsideColor = 44,
    kTitleVertRightColor = 45,

    kHeaderHorzTopColor = 46,
    kHeaderHorzInsideColor = 47,
    kHeaderHorzBottomColor = 48,
    kHeaderVertLeftColor = 49,
    kHeaderVertInsideColor = 50,
    kHeaderVertRightColor = 51,

    kDataHorzTopColor = 52,
    kDataHorzInsideColor = 53,
    kDataHorzBottomColor = 54,
    kDataVertLeftColor = 55,
    kDataVertInsideColor = 56,
    kDataVertRightColor = 57,

    kTitleHorzTopLineWeight = 70,
    kTitleHorzInsideLineWeight = 71,
    kTitleHorzBottomLineWeight = 72,
    kTitleVertLeftLineWeight = 73,
    kTitleVertInsideLineWeight = 74,
    kTitleVertRightLineWeight = 75,

    kHeaderHorzTopLineWeight = 76,
    kHeaderHorzInsideLineWeight = 77,
    kHeaderHorzBottomLineWeight = 78,
    kHeaderVertLeftLineWeight = 79,
    kHeaderVertInsideLineWeight = 80,
    kHeaderVertRightLineWeight = 81,

    kDataHorzTopLineWeight = 82,
    kDataHorzInsideLineWeight = 83,
    kDataHorzBottomLineWeight = 84,
    kDataVertLeftLineWeight = 85,
    kDataVertInsideLineWeight = 86,
    kDataVertRightLineWeight = 87,

    kTitleHorzTopVisibility = 100,
    kTitleHorzInsideVisibility = 101,
    kTitleHorzBottomVisibility = 102,
    kTitleVertLeftVisibility = 103,
    kTitleVertInsideVisibility = 104,
    kTitleVertRightVisibility = 105,

    kHeaderHorzTopVisibility = 106,
    kHeaderHorzInsideVisibility = 107,
    kHeaderHorzBottomVisibility = 108,
    kHeaderVertLeftVisibility = 109,
    kHeaderVertInsideVisibility = 110,
    kHeaderVertRightVisibility = 111,

    kDataHorzTopVisibility = 112,
    kDataHorzInsideVisibility = 113,
    kDataHorzBottomVisibility = 114,
    kDataVertLeftVisibility = 115,
    kDataVertInsideVisibility = 116,
    kDataVertRightVisibility = 117,

    kCellAlignment = 130,
    kCellBackgroundFillNone = 131,
    kCellBackgroundColor = 132,
    kCellContentColor = 133,
    kCellTextStyle = 134,
    kCellTextHeight = 135,
    kCellTopGridColor = 136,
    kCellRightGridColor = 137,
    kCellBottomGridColor = 138,
    kCellLeftGridColor = 139,
    kCellTopGridLineWeight = 140,
    kCellRightGridLineWeight = 141,
    kCellBottomGridLineWeight = 142,
    kCellLeftGridLineWeight = 143,
    kCellTopVisibility = 144,
    kCellRightVisibility = 145,
    kCellBottomVisibility = 146,
    kCellLeftVisibility = 147,
    kCellDataType = 148,
  };

  GcDbTable();
  GcDbTable(const GcDbLinkedTableData* pTable, GcDb::TableCopyOption nCopyOption);
  ~GcDbTable();

  virtual GcDbObjectId        tableStyle() const;
  virtual Gcad::ErrorStatus   setTableStyle(const GcDbObjectId& id);

  virtual GcGeVector3d        direction() const;
  virtual Gcad::ErrorStatus   setDirection(const GcGeVector3d& horzVec);

  virtual Gsoft::UInt32       numRows() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setNumRows(int nRows);

  virtual Gsoft::UInt32       numColumns() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setNumColumns(int nCols);

  virtual double              width() const;
  virtual Gcad::ErrorStatus   setWidth(double width);

  virtual double              columnWidth(int col) const;
  virtual Gcad::ErrorStatus   setColumnWidth(int col, double width);
  virtual Gcad::ErrorStatus   setColumnWidth(double width);

  virtual double              height() const;
  virtual Gcad::ErrorStatus   setHeight(double height);

  virtual double              rowHeight(int row) const;
  virtual Gcad::ErrorStatus   setRowHeight(int row, double height);
  virtual Gcad::ErrorStatus   setRowHeight(double height);
  virtual double              minimumColumnWidth(int col) const;
  virtual double              minimumRowHeight(int row) const;
  virtual double              minimumTableWidth() const;
  virtual double              minimumTableHeight() const;

  GSOFT_DEPRECATED virtual double horzCellMargin() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setHorzCellMargin(double gap);

  GSOFT_DEPRECATED virtual double vertCellMargin() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setVertCellMargin(double gap);

  virtual GcDb::FlowDirection flowDirection() const;
  virtual Gcad::ErrorStatus   setFlowDirection(GcDb::FlowDirection flow);

  GSOFT_DEPRECATED virtual bool isTitleSuppressed() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus suppressTitleRow(bool value);

  GSOFT_DEPRECATED virtual bool isHeaderSuppressed() const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus suppressHeaderRow(bool value);

  GSOFT_DEPRECATED virtual GcDb::CellAlignment alignment(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setAlignment(GcDb::CellAlignment align, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual bool isBackgroundColorNone(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setBackgroundColorNone(bool value, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual GcCmColor backgroundColor(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setBackgroundColor(const GcCmColor& color, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual GcCmColor contentColor(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setContentColor(const GcCmColor& color, int nRowType = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual Gcad::ErrorStatus getDataType(GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType,
    GcDb::RowType type) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setDataType(GcValue::DataType nDataType, GcValue::UnitType nUnitType);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setDataType(GcValue::DataType nDataType, GcValue::UnitType nUnitType, int nRowTypes);

  GSOFT_DEPRECATED virtual const GCHAR* format(GcDb::RowType type);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setFormat(const GCHAR* pszFormat);
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setFormat(const GCHAR* pszFormat, int nRowTypes);

  GSOFT_DEPRECATED virtual GcDbObjectId  textStyle(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setTextStyle(const GcDbObjectId& id, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual double textHeight(GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setTextHeight(double height, int rowTypes = GcDb::kAllRows);

  GSOFT_DEPRECATED virtual GcDb::LineWeight gridLineWeight(GcDb::GridLineType gridlineType, GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setGridLineWeight(GcDb::LineWeight lwt, int nBorders, int nRows);

  GSOFT_DEPRECATED virtual GcCmColor gridColor(GcDb::GridLineType gridlineType, GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setGridColor(const GcCmColor& color, int nBorders, int nRows);

  GSOFT_DEPRECATED virtual GcDb::Visibility gridVisibility(GcDb::GridLineType gridlineType, GcDb::RowType type = GcDb::kDataRow) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setGridVisibility(GcDb::Visibility visible, int nBorders, int nRows);

  GSOFT_DEPRECATED virtual bool tableStyleOverrides(GcDbIntArray& overrides) const;
  GSOFT_DEPRECATED virtual void clearTableStyleOverrides(int options = 0);

  virtual GcDb::CellType      cellType(int row, int col) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   setCellType(int row, int col, GcDb::CellType type);

  virtual Gcad::ErrorStatus   getCellExtents(int row,
    int col,
    bool isOuterCell,
    GcGePoint3dArray& pts) const;
  virtual GcGePoint3d         attachmentPoint(int row, int col) const;
  virtual GcDb::CellAlignment alignment(int row, int col) const;
  virtual Gcad::ErrorStatus   setAlignment(int row, int col, GcDb::CellAlignment align);
  virtual bool                isBackgroundColorNone(int row, int col) const;
  virtual Gcad::ErrorStatus   setBackgroundColorNone(int row, int col, bool value);
  virtual GcCmColor           backgroundColor(int row, int col) const;
  virtual Gcad::ErrorStatus   setBackgroundColor(int row, int col, const GcCmColor& color);
  virtual GcCmColor           contentColor(int row, int col) const;
  virtual Gcad::ErrorStatus   setContentColor(int row, int col, const GcCmColor& color);
  virtual bool                cellStyleOverrides(int row, int col, GcDbIntArray& overrides) const;
  void                        clearCellOverrides(int row, int column);

  GSOFT_DEPRECATED virtual Gcad::ErrorStatus   deleteCellContent(int row, int col);
  GSOFT_DEPRECATED virtual GcDb::RowType   rowType(int row) const;

  Gcad::ErrorStatus       getDataType(int row, int col,
    GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType) const;
  Gcad::ErrorStatus       setDataType(int row, int col,
    GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  GcValue                 value(int row, int col) const;
  Gcad::ErrorStatus       setValue(int row, int col, const GcValue& val);
  Gcad::ErrorStatus       setValue(int row, int col,
    const wchar_t* pszText,
    GcValue::ParseOption nOption);
  Gcad::ErrorStatus       resetValue(int row, int col);
  const GCHAR* format(int row, int col) const;
  GSOFT_DEPRECATED Gcad::ErrorStatus setFormat(int row, int col, const GCHAR* pszFormat);
  virtual const GCHAR*         textStringConst(int row, int col) const;
  virtual GCHAR*               textString(int row, int col) const;
  virtual Gcad::ErrorStatus    textString(int row, int col,
    GcValue::FormatOption nOption,
    GcString& sText) const;
  virtual Gcad::ErrorStatus    setTextString(int row,
    int col,
    const GCHAR* text);

  virtual GcDbObjectId        fieldId(int row, int col) const;
  virtual Gcad::ErrorStatus   setFieldId(int row, int col, const GcDbObjectId& fieldId);
  virtual Gcad::ErrorStatus   setFieldId(int row, int col, const GcDbObjectId& fieldId, GcDb::CellOption nFlag);
  virtual GcDbObjectId        textStyle(int row, int col) const;
  virtual Gcad::ErrorStatus   setTextStyle(int row,
    int col,
    const GcDbObjectId& id);
  virtual double              textHeight(int row, int col) const;
  virtual Gcad::ErrorStatus   setTextHeight(int row, int col, double height);

  GSOFT_DEPRECATED virtual GcDb::RotationAngle textRotation(int row, int col) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus  setTextRotation(int row, int col, GcDb::RotationAngle rot);

  GSOFT_DEPRECATED virtual bool isAutoScale(int row, int col) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setAutoScale(int row, int col, bool autoFit);

  virtual GcDbObjectId        blockTableRecordId(int row, int col) const;
  virtual Gcad::ErrorStatus   setBlockTableRecordId(int row,
    int col,
    const GcDbObjectId& blkId,
    bool autoFit = false);
  GSOFT_DEPRECATED virtual double blockScale(int row, int col) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setBlockScale(int row, int col, double scale);

  GSOFT_DEPRECATED virtual double blockRotation(int row, int col) const;
  GSOFT_DEPRECATED virtual Gcad::ErrorStatus setBlockRotation(int row, int col, double rotAng);

  virtual Gcad::ErrorStatus   getBlockAttributeValue(int row,
    int col,
    const GcDbObjectId& attdefId,
    GCHAR*& value) const;
  virtual Gcad::ErrorStatus   setBlockAttributeValue(int row,
    int col,
    const GcDbObjectId& attdefId,
    const GCHAR* value);

  virtual GcCmColor           gridColor(int row, int col, GcDb::CellEdgeMask iEdge) const;
  virtual Gcad::ErrorStatus   setGridColor(int row,
    int col,
    short nEdges,
    const GcCmColor& color);

  virtual GcDb::Visibility    gridVisibility(int row,
    int col,
    GcDb::CellEdgeMask iEdge) const;
  virtual Gcad::ErrorStatus   setGridVisibility(int row,
    int col,
    short nEdges,
    GcDb::Visibility value);

  virtual GcDb::LineWeight    gridLineWeight(int row,
    int col,
    GcDb::CellEdgeMask iEdge) const;
  virtual Gcad::ErrorStatus   setGridLineWeight(int row,
    int col,
    short nEdges,
    GcDb::LineWeight value);

  virtual Gcad::ErrorStatus insertColumns(int col, double width, int nCols = 1);
  virtual Gcad::ErrorStatus deleteColumns(int col, int nCols = 1);
  virtual Gcad::ErrorStatus insertRows(int row, double height, int nRows = 1);
  virtual Gcad::ErrorStatus deleteRows(int row, int nRows = 1);
  virtual Gcad::ErrorStatus mergeCells(int minRow, int maxRow, int minCol, int maxCol);
  virtual Gcad::ErrorStatus unmergeCells(int minRow, int maxRow, int minCol, int maxCol);
  virtual bool              isMergedCell(int row, int col,
    int* minRow = NULL,
    int* maxRow = NULL,
    int* minCol = NULL,
    int* maxCol = NULL) const;
  virtual Gcad::ErrorStatus generateLayout();
  virtual Gcad::ErrorStatus recomputeTableBlock(bool forceUpdate = true);
  virtual bool              hitTest(const GcGePoint3d& wpt,
    const GcGeVector3d& wviewVec,
    double wxaper,
    double wyaper,
    int& resultRowIndex,
    int& resultColumnIndex);
  bool                      hitTest(const GcGePoint3d& wpt,
    const GcGeVector3d& wviewVec,
    double wxaper,
    double wyaper,
    int& resultRowIndex,
    int& resultColumnIndex,
    int& contentIndex,
    GcDb::TableHitItem& nItem);
  virtual Gcad::ErrorStatus select(const GcGePoint3d& wpt,
    const GcGeVector3d& wvwVec,
    const GcGeVector3d& wvwxVec,
    double wxaper,
    double wyaper,
    bool allowOutside,
    bool bInPickFirst,
    int& resultRowIndex,
    int& resultColumnIndex,
    GcDbFullSubentPathArray* pPaths = NULL) const;
  virtual Gcad::ErrorStatus selectSubRegion(const GcGePoint3d& wpt1,
    const GcGePoint3d& wpt2,
    const GcGeVector3d& wvwVec,
    const GcGeVector3d& wvwxVec,
    double wxaper,
    double wyaper,
    GcDb::SelectType seltype,
    bool bIncludeCurrentSelection,
    bool bInPickFirst,
    int& rowMin,
    int& rowMax,
    int& colMin,
    int& colMax,
    GcDbFullSubentPathArray* pPaths = NULL) const;

  virtual bool reselectSubRegion(GcDbFullSubentPathArray& paths) const;
  virtual Gcad::ErrorStatus getSubSelection(int& rowMin, int& rowMax, int& colMin, int& colMax) const;
  GcCellRange     getSubSelection(void) const;
  virtual Gcad::ErrorStatus setSubSelection(int rowMin, int rowMax, int colMin, int colMax);
  Gcad::ErrorStatus setSubSelection(const GcCellRange& range);
  virtual void      clearSubSelection();
  virtual bool      hasSubSelection() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;

  Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo) override;
  Gcad::ErrorStatus subClose() override;
  void              objectClosed(const GcDbObjectId objId) override;
  void              erased(const GcDbObject* dbObj, Gsoft::Boolean pErasing = true) override;
  Gcad::ErrorStatus setPosition(const GcGePoint3d&) override;
  Gcad::ErrorStatus setNormal(const GcGeVector3d& newVal) override;

  virtual Gcad::ErrorStatus select_next_cell(int dir,
    int& resultRowIndex,
    int& resultColumnIndex,
    GcDbFullSubentPathArray* pPaths = NULL,
    bool bSupportTextCellOnly = true) const;

  virtual void              setRegen();
  virtual void              suppressInvisibleGrid(bool value);
  virtual Gcad::ErrorStatus getCellExtents(int row,
    int col,
    double& cellWidth,
    double& cellHeight,
    bool bAdjustForMargins) const;
  bool isRegenerateTableSuppressed() const;
  void suppressRegenerateTable(bool bSuppress);
  void setRecomputeTableBlock(bool newVal);

  Gcad::ErrorStatus  setSize(int nRows, int nCols);
  bool               canInsert(int nIndex, bool bRow) const;
  Gcad::ErrorStatus  insertRowsAndInherit(int nIndex, int nInheritFrom, int nNumRows);
  Gcad::ErrorStatus  insertColumnsAndInherit(int col, int nInheritFrom, int nNumCols);
  bool               canDelete(int nIndex, int nCount, bool bRow) const;
  bool               isEmpty(int nRow, int nCol) const;
  GcCellRange        getMergeRange(int nRow, int nCol) const;
  GcDbTableIterator* getIterator(void) const;
  GcDbTableIterator* getIterator(const GcCellRange* pRange, GcDb::TableIteratorOption nOption) const;
  bool               isContentEditable(int nRow, int nCol) const;
  bool               isFormatEditable(int nRow, int nCol) const;
  GcDb::CellState    cellState(int nRow, int nCol) const;
  Gcad::ErrorStatus  setCellState(int nRow, int nCol, GcDb::CellState nLock);
  int                numContents(int nRow, int nCol) const;
  int                createContent(int nRow, int nCol, int nIndex);
  Gcad::ErrorStatus  moveContent(int nRow,
    int nCol,
    int nFromIndex,
    int nToIndex);
  Gcad::ErrorStatus  deleteContent(int nRow, int nCol);
  Gcad::ErrorStatus  deleteContent(int nRow, int nCol, int nIndex);
  Gcad::ErrorStatus  deleteContent(const GcCellRange& range);

  GcDb::CellContentType contentType(int nRow, int nCol) const;
  GcDb::CellContentType contentType(int nRow, int nCol, int nIndex) const;

  GcValue value(int row, int col, int nContent) const;
  GcValue value(int row,
    int col,
    int nContent,
    GcValue::FormatOption nOption) const;
  Gcad::ErrorStatus setValue(int row,
    int col,
    int nContent,
    const GcValue& val);
  Gcad::ErrorStatus setValue(int row,
    int col,
    int nContent,
    const GcValue& val,
    GcValue::ParseOption nOption);
  Gcad::ErrorStatus setValue(int row,
    int col,
    int nContent,
    const wchar_t* pszText,
    GcValue::ParseOption nOption);
  GcString        dataFormat(int row, int col) const;
  GcString        dataFormat(int row,
    int col,
    int nContent) const;
  Gcad::ErrorStatus setDataFormat(int row,
    int col,
    const GCHAR* pszFormat);
  Gcad::ErrorStatus setDataFormat(int row,
    int col,
    int nContent,
    const GCHAR* pszFormat);
  GcString          textString(int row, int col, int nContent) const;
  Gcad::ErrorStatus textString(int row,
    int col,
    int nContent,
    GcValue::FormatOption nOption,
    GcString& sText) const;
  Gcad::ErrorStatus setTextString(int row,
    int col,
    int nContent,
    const GCHAR* text);
  bool            hasFormula(int nRow, int nCol, int nContent) const;
  GcString        getFormula(int nRow, int nCol, int nContent) const;
  Gcad::ErrorStatus setFormula(int nRow,
    int nCol,
    int nContent,
    const GCHAR* pszFormula);
  GcDbObjectId    fieldId(int row, int col, int nContent) const;
  Gcad::ErrorStatus setFieldId(int row,
    int col,
    int nContent,
    const GcDbObjectId& fieldId,
    GcDb::CellOption nFlag);
  GcDbObjectId    blockTableRecordId(int row, int col, int nContent) const;
  Gcad::ErrorStatus setBlockTableRecordId(int row,
    int col,
    int nContent,
    const GcDbObjectId& blkId,
    bool autoFit);
  Gcad::ErrorStatus getBlockAttributeValue(int row,
    int col,
    int nContent,
    const GcDbObjectId& attdefId,
    GCHAR*& value) const;
  Gcad::ErrorStatus setBlockAttributeValue(int row,
    int col,
    int nContent,
    const GcDbObjectId& attdefId,
    const GCHAR* value);
  int             getCustomData(int nRow, int nCol) const;
  Gcad::ErrorStatus setCustomData(int nRow, int nCol, int nData);
  Gcad::ErrorStatus getCustomData(int nRow,
    int nCol,
    const GCHAR* pszKey,
    GcValue* pData) const;
  Gcad::ErrorStatus setCustomData(int nRow,
    int nCol,
    const GCHAR* pszKey,
    const GcValue* pData);
  const GCHAR *   cellStyle(int nRow, int nCol) const;
  Gcad::ErrorStatus setCellStyle(int nRow, int nCol, const GCHAR* pszCellStyle);
  double          margin(int nRow, int nCol, GcDb::CellMargin nMargin) const;
  Gcad::ErrorStatus setMargin(int nRow,
    int nCol,
    GcDb::CellMargin nMargins,
    double fMargin);
  GcGePoint3d     attachmentPoint(int row,
    int col,
    int content) const;
  GcCmColor       contentColor(int row,
    int col,
    int nContent) const;
  Gcad::ErrorStatus setContentColor(int row,
    int col,
    int nContent,
    const GcCmColor& color);
  Gcad::ErrorStatus getDataType(int row,
    int col,
    int nContent,
    GcValue::DataType& nDataType,
    GcValue::UnitType& nUnitType) const;
  Gcad::ErrorStatus setDataType(int row,
    int col,
    int nContent,
    GcValue::DataType nDataType,
    GcValue::UnitType nUnitType);
  GcDbObjectId    textStyle(int row,
    int col,
    int nContent) const;
  Gcad::ErrorStatus setTextStyle(int row,
    int col,
    int nContent,
    const GcDbObjectId& id);
  double          textHeight(int row,
    int col,
    int nContent) const;
  Gcad::ErrorStatus setTextHeight(int row,
    int col,
    int nContent,
    double height);
  double          rotation(void) const;
  double          rotation(int row, int col, int nContent) const;
  Gcad::ErrorStatus setRotation(double fAngle) override;
  Gcad::ErrorStatus setRotation(int row,
    int col,
    int nContent,
    double fAngle);
  bool              isAutoScale(int row, int col, int nContent) const;
  Gcad::ErrorStatus setAutoScale(int row,
    int col,
    int nContent,
    bool autoFit);
  double            scale(int row, int col, int nContent) const;
  Gcad::ErrorStatus setScale(int row,
    int col,
    int nContent,
    double scale);
  GcDb::CellContentLayout contentLayout(int row, int col) const;
  Gcad::ErrorStatus setContentLayout(int row, int col, GcDb::CellContentLayout nLayout);
  bool            isMergeAllEnabled(int nRow, int nCol) const;
  Gcad::ErrorStatus enableMergeAll(int nRow, int nCol, bool bEnable);
  GcDb::CellProperty getOverride(int nRow, int nCol, int nContent) const;
  GcDb::GridProperty getOverride(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setOverride(int nRow,
    int nCol,
    int nContent,
    GcDb::CellProperty nOverride);
  Gcad::ErrorStatus setOverride(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType,
    GcDb::GridProperty nOverride);
  Gcad::ErrorStatus removeAllOverrides(int nRow, int nCol);
  GcDb::GridLineStyle gridLineStyle(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridLineStyle(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    GcDb::GridLineStyle nLineStyle);
  GcDb::LineWeight  gridLineWeight(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridLineWeight(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    GcDb::LineWeight nLineWeight);
  GcDbObjectId      gridLinetype(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridLinetype(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    const GcDbObjectId& idLinetype);
  GcCmColor         gridColor(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridColor(int nRow,
    int nCol,
    GcDb::GridLineType nGridlineTypes,
    const GcCmColor& color);
  GcDb::Visibility  gridVisibility(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridVisibility(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    GcDb::Visibility nVisibility);
  double            gridDoubleLineSpacing(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType) const;
  Gcad::ErrorStatus setGridDoubleLineSpacing(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    double fSpacing);
  Gcad::ErrorStatus getGridProperty(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineType,
    GcGridProperty& gridProp) const;
  Gcad::ErrorStatus setGridProperty(int nRow,
    int nCol,
    GcDb::GridLineType nGridLineTypes,
    const GcGridProperty& gridProp);
  Gcad::ErrorStatus setGridProperty(const GcCellRange& rangeIn,
    GcDb::GridLineType nGridLineTypes,
    const GcGridProperty& gridProp);

  bool              isLinked(int nRow, int nCol) const;
  GcDbObjectId      getDataLink(int nRow, int nCol) const;
  Gcad::ErrorStatus getDataLink(int nRow,
    int nCol,
    GcDbDataLink*& pDataLink,
    GcDb::OpenMode mode) const;
  int               getDataLink(const GcCellRange* pRange, GcDbObjectIdArray& dataLinkIds) const;
  Gcad::ErrorStatus setDataLink(int nRow,
    int nCol,
    const GcDbObjectId& idDataLink,
    bool bUpdate);
  Gcad::ErrorStatus setDataLink(const GcCellRange& range, const GcDbObjectId& idDataLink, bool bUpdate);
  GcCellRange       getDataLinkRange(int nRow, int nCol) const;
  Gcad::ErrorStatus removeDataLink(int nRow, int nCol);
  Gcad::ErrorStatus removeDataLink(void);
  Gcad::ErrorStatus updateDataLink(int nRow,
    int nCol,
    GcDb::UpdateDirection nDir,
    GcDb::UpdateOption nOption);
  Gcad::ErrorStatus updateDataLink(GcDb::UpdateDirection nDir, GcDb::UpdateOption nOption);

  bool              isBreakEnabled(void) const;
  Gcad::ErrorStatus enableBreak(bool bEnable);
  GcDb::TableBreakFlowDirection breakFlowDirection(void) const;
  Gcad::ErrorStatus setBreakFlowDirection(GcDb::TableBreakFlowDirection nDir);
  double            breakHeight(int nIndex) const;
  Gcad::ErrorStatus setBreakHeight(int nIndex, double fHeight);
  GcGeVector3d      breakOffset(int nIndex) const;
  Gcad::ErrorStatus setBreakOffset(int nIndex, const GcGeVector3d& vec);
  GcDb::TableBreakOption breakOption(void) const;
  Gcad::ErrorStatus setBreakOption(GcDb::TableBreakOption nOption);
  double            breakSpacing(void) const;
  Gcad::ErrorStatus setBreakSpacing(double fSpacing);
  Gcad::ErrorStatus copyFrom(const GcDbLinkedTableData* pSrc, GcDb::TableCopyOption nOption);
  Gcad::ErrorStatus copyFrom(const GcDbLinkedTableData* pSrc,
    GcDb::TableCopyOption nOption,
    const GcCellRange& srcRange,
    const GcCellRange& targetRange,
    GcCellRange* pNewTargetRangeOut);
  Gcad::ErrorStatus copyFrom(const GcDbTable* pSrc,
    GcDb::TableCopyOption nOption,
    const GcCellRange& srcRange,
    const GcCellRange& targetRange,
    GcCellRange* pNewTargetRangeOut);
  Gcad::ErrorStatus fill(const GcCellRange& fillRange, const GcCellRange& srcRange, GcDb::TableFillOption nOption);
  const GCHAR *     getColumnName(int nIndex) const;
  Gcad::ErrorStatus setColumnName(int nIndex, const GCHAR* pszName);
  GcString          getToolTip(int nRow, int nCol) const;
  Gcad::ErrorStatus setToolTip(int nRow, int nCol, const GCHAR* pszToolTip);
  Gcad::ErrorStatus createTemplate(GcDbTableTemplate*& pTemplate, GcDb::TableCopyOption nCopyOption);
  Gcad::ErrorStatus getIndicatorSize(double& fWidth, double& fHeight) const;
  GcCellRange       cellRange() const;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)