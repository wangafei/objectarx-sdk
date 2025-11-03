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


#ifndef OD_DBTABLE_H
#define OD_DBTABLE_H

#include "TD_PackPush.h"
#include "DbBlockReference.h"
#include "DbTableStyle.h"
#include "DbDataLink.h"
#include "UInt32Array.h"

// typedef for OdSubentPathArray
//

class OdDbTableImpl;
class OdDbLinkedTableData;
class OdDbTableIterator;

typedef OdDbFullSubentPathArray OdSubentPathArray;

/** Description:
    This class represents Table entities in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes} 

*/
class TOOLKIT_EXPORT OdDbTable: public OdDbBlockReference
{
public:
  ODDB_DECLARE_MEMBERS(OdDbTable);

  enum TableStyleOverrides 
  {
    kTitleSuppressed             = 1,
    kHeaderSuppressed            = 2,
    kFlowDirection               = 3,         
    kHorzCellMargin              = 4,
    kVertCellMargin              = 5,
    kTitleRowColor               = 6,
    kHeaderRowColor              = 7,
    kDataRowColor                = 8,
    kTitleRowFillNone            = 9,
    kHeaderRowFillNone           = 10,
    kDataRowFillNone             = 11,
    kTitleRowFillColor           = 12,
    kHeaderRowFillColor          = 13,
    kDataRowFillColor            = 14,
    kTitleRowAlignment           = 15,
    kHeaderRowAlignment          = 16,
    kDataRowAlignment            = 17,
    kTitleRowTextStyle           = 18,
    kHeaderRowTextStyle          = 19,
    kDataRowTextStyle            = 20,
    kTitleRowTextHeight          = 21,
    kHeaderRowTextHeight         = 22,
    kDataRowTextHeight           = 23,
    kTitleRowDataType            = 24,
    kHeaderRowDataType           = 25,
    kDataRowDataType             = 26,
    kTitleHorzTopColor           = 40,
    kTitleHorzInsideColor        = 41,
    kTitleHorzBottomColor        = 42,
    kTitleVertLeftColor          = 43,
    kTitleVertInsideColor        = 44,
    kTitleVertRightColor         = 45,
    kHeaderHorzTopColor          = 46,
    kHeaderHorzInsideColor       = 47,
    kHeaderHorzBottomColor       = 48,
    kHeaderVertLeftColor         = 49,
    kHeaderVertInsideColor       = 50,
    kHeaderVertRightColor        = 51,
    kDataHorzTopColor            = 52,
    kDataHorzInsideColor         = 53,
    kDataHorzBottomColor         = 54,
    kDataVertLeftColor           = 55,
    kDataVertInsideColor         = 56,
    kDataVertRightColor          = 57,
    kTitleHorzTopLineWeight      = 70,
    kTitleHorzInsideLineWeight   = 71,
    kTitleHorzBottomLineWeight   = 72,
    kTitleVertLeftLineWeight     = 73,
    kTitleVertInsideLineWeight   = 74,
    kTitleVertRightLineWeight    = 75,
    kHeaderHorzTopLineWeight     = 76,
    kHeaderHorzInsideLineWeight  = 77,
    kHeaderHorzBottomLineWeight  = 78,
    kHeaderVertLeftLineWeight    = 79,
    kHeaderVertInsideLineWeight  = 80,
    kHeaderVertRightLineWeight   = 81,
    kDataHorzTopLineWeight       = 82,
    kDataHorzInsideLineWeight    = 83,
    kDataHorzBottomLineWeight    = 84,
    kDataVertLeftLineWeight      = 85,
    kDataVertInsideLineWeight    = 86,
    kDataVertRightLineWeight     = 87,

    kTitleHorzTopVisibility      = 100,
    kTitleHorzInsideVisibility   = 101,
    kTitleHorzBottomVisibility   = 102,
    kTitleVertLeftVisibility     = 103,
    kTitleVertInsideVisibility   = 104,
    kTitleVertRightVisibility    = 105,
    kHeaderHorzTopVisibility     = 106,
    kHeaderHorzInsideVisibility  = 107,
    kHeaderHorzBottomVisibility  = 108,
    kHeaderVertLeftVisibility    = 109,
    kHeaderVertInsideVisibility  = 110,
    kHeaderVertRightVisibility   = 111,
    kDataHorzTopVisibility       = 112,
    kDataHorzInsideVisibility    = 113,
    kDataHorzBottomVisibility    = 114,
    kDataVertLeftVisibility      = 115,
    kDataVertInsideVisibility    = 116,
    kDataVertRightVisibility     = 117,

    kCellAlignment               = 130,
    kCellBackgroundFillNone      = 131,
    kCellBackgroundColor         = 132,
    kCellContentColor            = 133,
    kCellTextStyle               = 134,
    kCellTextHeight              = 135,
    kCellTopGridColor            = 136,
    kCellRightGridColor          = 137,
    kCellBottomGridColor         = 138,
    kCellLeftGridColor           = 139,
    kCellTopGridLineWeight       = 140,
    kCellRightGridLineWeight     = 141,
    kCellBottomGridLineWeight    = 142,
    kCellLeftGridLineWeight      = 143,
    kCellTopVisibility           = 144,
    kCellRightVisibility         = 145,
    kCellBottomVisibility        = 146,
    kCellLeftVisibility          = 147,
    kCellDataType                = 148
  };

  OdDbTable();
  OdDbTable(const OdDbLinkedTableData* pTable, OdDb::TableCopyOption nCopyOption);
  virtual ~OdDbTable();

  
  /** Description:
    Returns the Object ID of the OdDbTableStyle used by this Table entity (DXF 342).
  */
  virtual OdDbObjectId tableStyle() const;

  /** Description:
    Sets the Object ID of the OdDbTableStyle for use by this Table entity (DXF 342).

    Arguments:
    tableStyleId (I) Object ID of the table style.

    Remarks:
    Returns eOk if successful, eInvalidInput otherwise.
  */
  virtual OdResult setTableStyle(
    const OdDbObjectId& tableStyleId);

  /** Description:
    Returns the unit X-axis for this Table entity in WCS coordinates (DXF 11,21,31).
  */
  virtual OdGeVector3d direction() const;
  
  /** Description:
    Sets the X-axis for this Table entity in WCS coordinates (DXF 11,21,31).
    
    Remarks:
    horizVector (I) Horizontal vector.
  */
  virtual OdResult setDirection(
    const OdGeVector3d& horizVector);

  /** Description:
    Returns the number of rows in this Table entity (DXF 91).
    
    Note:
    This includes title and header rows, if any. 
  */
  virtual OdUInt32 numRows() const;

  /** Description:
    Sets the number of rows for this Table entity (DXF 91).
    
    Arguments:
    numRows (I) Number of rows.
    
    Note:
    This includes title and header rows, if any.
    
    The number of rows must be greater than zero.
  */
  virtual OdResult setNumRows(
    OdUInt32 numRows);

  /** Description:
    Returns the number of columns in this Table entity (DXF 92). 
  */
  virtual OdUInt32 numColumns() const;

  /** Description:
    Sets the number of columns for this Table entity (DXF 92). 
    
    Arguments:
    numColumns (I) Number of columns.
    
    Remarks:
    The number of columns must be greater than zero.    
  */
  virtual OdResult setNumColumns(OdUInt32 numColumns);

  /** Description:
    Returns the overall *width* of this Table entity.
  */
  virtual double width() const;

  /** Description:
    Sets the overall *width* for this Table entity. 
    
    Arguments:
    width (I) Overall *width*.
    
    Remarks:
    Column widths may be adjusted proportionally.
    
    See also:
    columWidth
  */
  virtual OdResult setWidth(double width);

  /** Description:
    Returns the *width* of the specified *column* in this Table entity (DXF 142).
    
    Arguments:
    column (I) Column index. 
  */
  virtual double columnWidth(OdUInt32 column) const;
  
  /** Description:
    Sets the *width* of all columns or the specified *column* in this Table entity (DXF 142).

    Arguments:
    column (I) Column index. 
    width (I) Column *width*.
  */
  virtual OdResult setColumnWidth(
    OdUInt32 column, 
    double width);
  virtual OdResult setColumnWidth(
    double width);

  /** Description:
    Returns the overall *height* of this Table entity.
  */
  virtual double height() const;

  /** Description:
    Sets the overall *height* of this Table entity.
    
    Arguments:
    height (I) Overall *height*.
      
    Remarks:
    Row heights may be adjusted proportionally.
  */
  virtual OdResult setHeight(
    double height);

  /** Description:
    Returns the *height* of the specified *row* in this Table entity (DXF 141).
    
    Arguments:
    row (I) Row index.
  */
  virtual double rowHeight(
    OdUInt32 row) const;
  
  /** Description:
    Sets the *height* of all rows or the specified *row* in this Table entity (DXF 141).
    Arguments:
    row (I) Row index.
    height (I) Row *height*.
  */
  virtual OdResult setRowHeight(
    OdUInt32 row, 
    double height);

  virtual OdResult setRowHeight(
    double height);
  
  /** Description:
    Returns the minimum *column* *width* for the specified *column* in this Table entity.
    Arguments:
    column (I) Column index. 
  */
  virtual double minimumColumnWidth(
    OdUInt32 column) const;

  /** Description:
    Returns the minimum *row* *height* for the specified *row* in this Table entity.
    Arguments:
    row (I) Row index.
  */
  virtual double minimumRowHeight(
    OdUInt32 row) const;    

  /** Description:
    Returns the minimum overall *width* for this Table entity.
  */
  virtual double minimumTableWidth() const;
  
  /** Description:
    Returns the minimum overall *height* for this Table entity.
  */
  virtual double minimumTableHeight() const;        

  //********************************************************************
  // Get and set methods for table style overrides
  //********************************************************************
  //
  
  /** Description:
    Returns the horizontal cell margin for this Table entity (DXF 40). 
    Remarks:
    The horizontal cell margin is the horizontal space between the cell text and the cell border.
  */
  virtual double horzCellMargin() const;

  /** Description:
    Sets the horizontal cell margin for this Table entity (DXF 40).
    
    Arguments:
    cellMargin (I) Cell margin.
    
    Remarks:
    The horizontal cell margin is the horizontal space between the cell text and the cell border.
  */
  virtual OdResult setHorzCellMargin(
    double cellMargin);

  /** Description:
    Returns the vertical cell margin for this Table entity (DXF 41). 

    Remarks:
    The vertical cell margin is the vertical space between the cell text and the cell border.
  */
  virtual double vertCellMargin() const;

  /** Description:
    Sets the vertical cell margin for this Table entity (DXF 41).
    
    Arguments:
    cellMargin (I) Cell margin.
    
    Remarks:
    The vertical cell margin is the vertical space between the cell text and the cell border.
  */
  virtual OdResult setVertCellMargin(
    double cellMargin);

  /** Description:
    Returns the *direction* this Table entity flows from its first *row* to its last (DXF 70).

    Remarks:
    flowDirection() returns one of the following:
    
    @table
    Name          Value   Description
    OdDb::kTtoB   0       Top to Bottom
    OdDb::kBtoT   1       Bottom to Top
  */
  virtual OdDb::FlowDirection flowDirection() const; 

  /** Description:
    Sets the *direction* this Table entity flows from its first *row* to its last. (DXF 70).

    Arguments:
    flowDirection (I) Flow *direction*.
    
    Remarks:
    flowDirection must be one of the following: 
         
    @table
    Name          Value   Description
    OdDb::kTtoB   0       Top to Bottom
    OdDb::kBtoT   1       Bottom to Top
  */
  virtual OdResult setFlowDirection(
    OdDb::FlowDirection flowDirection);

  /** Description:
      Returns true if and only if the title *row* is suppressed for this Table entity (DXF 280).
  */
  virtual bool isTitleSuppressed() const;

  /** Description:
    Controls the suppression of the title *row* (DXF 280).
    Arguments:
    suppress (I) Controls suppression.
  */
  virtual OdResult suppressTitleRow(
    bool suppress);

  /** Description:
    Returns true if and only if the header *row* is suppressed for this Table entity (DXF 281). 
  */
  virtual bool isHeaderSuppressed() const;

  /** Description:
      Controls the suppression of the header *row* for this Table entity (DXF 280).
      Arguments:
      enable (I) Controls suppression.
  */
  virtual OdResult suppressHeaderRow(
    bool suppress);

  /** Description:
    Returns the cell *alignment* for the specified *row* type or cell in this Table entity (DXF 170).

    Arguments:
    rowType (I) Row type.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    
    Remarks:
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    alignment() returns one of the following:
    
    @table                  
    Name                    Value
    OdDb::kTopLeft          1
    OdDb::kTopCenter        2 
    OdDb::kTopRight         3
    OdDb::kMiddleLeft       4
    OdDb::kMiddleCenter     5
    OdDb::kMiddleRight      6
    OdDb::kBottomLeft       7 
    OdDb::kBottomCenter     8
    OdDb::kBottomRight      9
  */
  virtual OdDb::CellAlignment alignment(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual OdDb::CellAlignment alignment(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the cell *alignment* for the specified *row* types or cell in this Table entity (DXF 170).
    
    Arguments:
    rowTypes (I) Row types.
    alignment (I) Alignment.
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kHeaderRow        2
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    alignment must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTopLeft          1
    OdDb::kTopCenter        2 
    OdDb::kTopRight         3
    OdDb::kMiddleLeft       4
    OdDb::kMiddleCenter     5
    OdDb::kMiddleRight      6
    OdDb::kBottomLeft       7 
    OdDb::kBottomCenter     8
    OdDb::kBottomRight      9

  */
  virtual OdResult setAlignment(
    OdDb::CellAlignment alignment, 
    OdUInt32 rowTypes = OdDb::kAllRows);
  virtual OdResult setAlignment(
    OdUInt32 row, 
    OdUInt32 column, 
    OdDb::CellAlignment alignment);

  /** Description:
    Returns true if and only if the background *color* for the specified *row* 
    type or cell is disabled for this Table entity (DXF 283).

    Arguments:
    rowType (I) Row type
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks:
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual bool isBackgroundColorNone(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual bool isBackgroundColorNone(
    OdUInt32 row, 
    OdUInt32 column) const;


  /** Description:
    Controls the background *color* setting for the specified *row* types or cell in this Table entity (DXF 283). 

    Arguments:
    disable (I) Disables the background *color* if true, enables if false.
    rowTypes (I) Row types.
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setBackgroundColorNone(
    bool disable, 
    OdUInt32 rowTypes = OdDb::kAllRows);
  virtual OdResult setBackgroundColorNone(
    OdUInt32 row, 
    OdUInt32 column, 
    bool disable);
    
  /** Description:
    Returns the background *color* for the specified *row* type or cell in this Table entity (DXF 63).

    Arguments:
    rowType (I) Row type.
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks: 
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdCmColor backgroundColor(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual OdCmColor backgroundColor(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the background *color* for the specified *row* types or cell in this Table entity (DXF 63). 

    Arguments:
    rowTypes (I) Row types.
    color (I) Background *color*.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    
    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setBackgroundColor(
    const OdCmColor& color, 
    OdUInt32 rowTypes = OdDb::kAllRows);
  virtual OdResult setBackgroundColor(
    OdUInt32 row, 
    OdUInt32 column,
    const OdCmColor& color);

  /** Description:
    Returns the content *color* for the specified *row* type or cell in this Table entity (DXF 64).

    Arguments:
    rowType (I) Row type.
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks: 
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdCmColor contentColor(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual OdCmColor contentColor(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the content *color* for the specified *row* types or cell in this Table entity (DXF 64). 

    Arguments:
    rowTypes (I) Row types.
    color (I) Content *color*.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
   
    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setContentColor(
    const OdCmColor& color, 
    OdUInt32 nRowType = OdDb::kAllRows);
  virtual OdResult setContentColor(
    OdUInt32 row, 
    OdUInt32 column,
    const OdCmColor& color);

  /** Description:
    Returns the Object ID of the text style for the specified *row* type or cell in this Table entity (DXF 7).

    Arguments:
    rowType (I) Row type.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    
    Remarks: 
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdDbObjectId textStyle(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual OdDbObjectId textStyle(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the Object ID of the text style for the specified *row* types or cell in this Table entity (DXF 7).
    
    Arguments:
    rowTypes (I) Row types.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    textStyleId (I) Text style Object ID.

    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setTextStyle(
    const OdDbObjectId& textStyleId, 
    OdUInt32 rowTypes = OdDb::kAllRows);
  virtual OdResult setTextStyle(
    OdUInt32 row, 
    OdUInt32 column, 
    const OdDbObjectId& textStyleId);
    
  /** Description:
    Returns the text *height* for the specified *row* type or cell in this Table entity (DXF 140).

    Arguments:
    rowType (I) Row type
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    
    Remarks:
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual double textHeight(
    OdDb::RowType rowType = OdDb::kDataRow) const;
  virtual double textHeight(
    OdUInt32 row, 
    OdUInt32 column) const;


  /** Description:
    Sets the text *height* for the specified *row* types or cell in this Table entity (DXF 140).

    Arguments:
    rowTypes (I) Row types.
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    height (I) Text *height*.

    Remarks:
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setTextHeight(
    double height, 
    OdUInt32 rowTypes = OdDb::kAllRows);
  virtual OdResult setTextHeight(
    OdUInt32 row, 
    OdUInt32 column, 
    double height);


  /** Description:
    Returns the grid lineweight for the specified gridline type and *row* type,
    or the specified cell and edge in this Table entity (DXF 274-279).
      
    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeType (I) Edge type.
    gridlineType (I) Gridline type.
    rowType (I) Row type.

    Remarks:    
    gridlineType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    OdDb::kVertLeft         8
    OdDb::kVertInside       0x10
    OdDb::kVertRight        0x20
    
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeType must be one of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdDb::LineWeight gridLineWeight(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 
  virtual OdDb::LineWeight gridLineWeight(
    OdUInt32 row, 
    OdUInt32 column,
    OdDb::CellEdgeMask edgeType) const;

  /** Description:
    Sets the grid lineweight for the specified gridline types and *row* types,
    or the specified cell and edges in this Table entity (DXF 274-279).
      
    Arguments:
    lineWeight (I) Lineweight.      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeTypes (I) Edge types.
    gridlineTypes (I) Gridline types.
    rowTypes (I) Row types.

    Remarks:    
    gridlineTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    OdDb::kVertLeft         8
    OdDb::kVertInside       0x10
    OdDb::kVertRight        0x20
    
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeTypes must be a combination of one or more of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdResult setGridLineWeight(
    OdDb::LineWeight lineWeight, 
    OdUInt32 gridlineTypes, 
    OdUInt32 rowTypes);
  virtual OdResult setGridLineWeight(
    OdUInt32 row, 
    OdUInt32 column, 
    OdInt16 edgeTypes,
    OdDb::LineWeight lineWeight);

  /** Description:
    Returns the grid *color* for the specified gridline type and *row* type,
    or the specified cell and edge in this Table entity (DXF 63,64,65,66,68,69).
      
    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeType (I) Edge type.
    gridlineType (I) Gridline type.
    rowType (I) Row type.

    Remarks:    
    gridlineType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeType must be one of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdCmColor gridColor(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 
  virtual OdCmColor gridColor(
    OdUInt32 row, 
    OdUInt32 column,
    OdDb::CellEdgeMask edgeType) const;


  /** Description:
    Returns the grid *visibility* for the specified gridline type and *row* type,
    or the specified cell and edge in this Table entity (DXF 284-289).
      
    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeType (I) Edge type.
    gridlineType (I) Gridline type.
    rowType (I) Row type.

    Remarks:    
    gridVisibility() returns one of the following:
    
    @table
    Name                    Value
    OdDb::kInvisible        1
    OdDb::kVisible          0 
        
    gridlineType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    OdDb::kVertLeft         8
    OdDb::kVertInside       0x10
    OdDb::kVertRight        0x20
    
    rowType must be one of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeType must be one of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdDb::Visibility gridVisibility(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 
  virtual OdDb::Visibility gridVisibility(
    OdUInt32 row, 
    OdUInt32 column,
    OdDb::CellEdgeMask edgeType) const;

/** Description:
    Sets the grid *visibility* for the specified gridline types and *row* types,
    or the specified cell and edges in this Table entity (DXF 284-289).
      
    Arguments:
    gridVisibility (I) Grid *visibility*.      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeTypes (I) Edge types.
    gridlineTypes (I) Gridline types.
    rowTypes (I) Row types.

    Remarks:
    gridVisibility must be one of the following:
    
    @table
    Name                    Value
    OdDb::kInvisible        1
    OdDb::kVisible          0 
        
    gridlineTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    OdDb::kVertLeft         8
    OdDb::kVertInside       0x10
    OdDb::kVertRight        0x20
    
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeTypes must be a combination of one or more of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdResult setGridVisibility(
    OdDb::Visibility gridVisiblity, 
    OdUInt32 gridlineTypes, 
    OdUInt32 rowTypes);
  virtual OdResult setGridVisibility(
    OdUInt32 row, 
    OdUInt32 column, 
    OdInt16 edgeTypes,
    OdDb::Visibility gridVisibility);

  /** Description:
    Returns the table style *overrides* for this Table entity. 

    Arguments:
    overrides (O) Receives an array of table style *overrides* for this Table entity.         
    
    Remarks:
    Returns true and only if successful.
  */
  virtual bool tableStyleOverrides( 
    OdDbIntArray& overrides) const;

  /** Description:
    Clears the table style *overrides* for this Table entity and/or its cells. 

    Arguments:
    option (I) Option.
        
    Remarks:
    option can be one of the following:
    
    @table
    Value   Description
    0       Clears all overrides.         
    1       Clears all table overrides.   
    2       Clears all cell overrides.    
  */
  virtual void clearTableStyleOverrides(
    int option = 0);
  
  /** Description:
    Returns the cell type of the specified cell in this Table entity.

    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks:
    cellType() returns one of the following:
    
    @table
    Name               Value
    OdDb::kTextCell    1
    OdDb::kBlockCell   2
  */
  virtual OdDb::CellType cellType(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the cell type for the specified cell in this Table entity.

    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    cellType (I) Cell type.
    
    Remarks:
    cellType must be one of the following:
    
    @table
    Name               Value
    OdDb::kTextCell    1
    OdDb::kBlockCell   2
  */
  virtual OdResult setCellType(
    OdUInt32 row, 
    OdUInt32 column, 
    OdDb::CellType cellType);

  /** Description:
    Returns the cell extents for the specified cell in this Table entity.

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    isOuterCell (I) If and only if true, ignores margins.
    pts (O) Receives the cell extents information.
    
    Remarks:
    If isOuterCell is true, this function returns the *extents* of the cell without regard to margins.
    
    If isOuterCell is false, this function returns the *extents( of cell reduced
    by the horizontal and vertical cell margins.
  */
  virtual OdResult getCellExtents(
    OdUInt32 row, 
    OdUInt32 column,
    bool isOuterCell, 
    OdGePoint3dArray& pts) const;

  /** Description:
    Returns the attachment point of the specified cell in this Table entity.
    
    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual OdGePoint3d attachmentPoint(
    int row, 
    int column) const; 

 
  /** Description:
    Returns the cell style *overrides* for the specified cell in this Table entity.
      
    Arguments:      
    row (I) Row index of the 
    column (I) Column index of the cell.
    overrides (O) Receives the *overrides*.   
  */
  virtual bool cellStyleOverrides(
    OdUInt32 row, 
    OdUInt32 column,
    OdDbIntArray& overrides) const;

  /** Description:
    Clears the cell *overrides* for the specified cell in this Table entity. 

    Arguments:      
    row (I) Row index of the 
    column (I) Column index of the cell.
  */
  void clearCellOverrides(
    OdUInt32 row, 
    OdUInt32 column);

  /** Description:
    Deletes the content of the specified cell in this Table entity.

    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual OdResult deleteCellContent(
    OdUInt32 row, 
    OdUInt32 column);

  /** Description:
    Returns the type of the specified *row* in this Table entity.
    
    Arguments:
    row (I) Row index.
  
    Remarks:
    rowType() returns one of the following:

    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdDb::RowType rowType(
    OdUInt32 row) const;

  /** Description:
    Returns the text string in the specified cell in this Table entity.

    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  OdString textString(
	ODSYSDEF,
    OdUInt32 row, 
    OdUInt32 column) const;

//   const OdString& textStringInternal(
//     OdUInt32 row, 
//     OdUInt32 column) const;

  virtual const OdChar* textStringConst(
    OdUInt32 row, 
    OdUInt32 column) const;

  virtual OdChar* textString(
    OdUInt32 row, 
    OdUInt32 column) const;
  /** Description:
    Sets the text string in the for the specified cell in this Table entity.

    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    textString (I) Text string.
  */
  virtual OdResult setTextString(
    OdUInt32 row, 
    OdUInt32 column, 
    const OdChar * textString);
    
  /** Description:
    Returns the Object ID of the OdDbField in the specified cell in this Table entity. 
      
    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual OdDbObjectId fieldId(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the Object ID for OdDbField in the specified cell in this Table entity.

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    fieldId (I) Object ID of the AdDbField.
  */
  virtual OdResult setFieldId(
    OdUInt32 row, 
    OdUInt32 column, 
    const OdDbObjectId& fieldId);

  virtual OdResult setFieldId(
    OdUInt32 row, 
    OdUInt32 col, 
    const OdDbObjectId& fieldId, 
    OdDb::CellOption nFlag);

  virtual OdResult setFieldId (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdDbObjectId& fieldId, 
    OdDb::CellOption nFlag);


  /** Description:
    Returns the text *rotation* angle for the specified cell in this Table entity. 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.

    Remarks:
    textRotation() returns one of the following:
    
    @table
    Name                    Value     Description
    OdDb::kDegrees000       0         0?
    OdDb::kDegrees090       1         90?CCW
    OdDb::kDegrees180       2         180?
    OdDb::kDegrees270       3         90?CW
  */
  virtual OdDb::RotationAngle textRotation(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the text *rotation* angle of the text in the specified cell in this Table entity. 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    textRotation (I) Text *rotation* angle.
    
    Remarks:
    textRotation must be one of the following:
    
    @table
    Name                    Value     Description
    OdDb::kDegrees000       0         0?
    OdDb::kDegrees090       1         90?CCW
    OdDb::kDegrees180       2         180?
    OdDb::kDegrees270       3         90?CW
  */
  virtual OdResult setTextRotation(
    OdUInt32 row, 
    OdUInt32 column, 
    OdDb::RotationAngle textRotation);
  

  /** Description:
    Returns true if and only if the block in the specified cell in this Table entity is
    automatically scaled and positioned to fit into the cell.
     
    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual bool isAutoScale(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Determines if the  block in the specified cell in this Table entity is to be
    automatically scaled and positioned to fit into the cell.

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    autoScale (I) True to autoscale the block to the cell.
  */
  virtual OdResult setAutoScale(
    OdUInt32 row, 
    OdUInt32 column, 
    bool autoScale);
 
  /** Description:
    Returns the Object ID of the block table record in the specified cell in this Table entity. 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual OdDbObjectId blockTableRecordId(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the Object ID of the block table record in the specified cell in this Table entity 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    blockId (I) Object ID of the block.
    autoScale (I) If true, autoscales the block to the cell.
  */
  virtual OdResult setBlockTableRecordId(
    OdUInt32 row, 
    OdUInt32 column,
    const OdDbObjectId& blockId, 
    bool autoScale = false);

  /** Description:
    Returns the scale factor of the block reference in the specified cell in this Table entity 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual double blockScale(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the *scale* factor of the block reference in the specified cell in this Table entity 

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    blockScale (I) Uniform *scale* factor.
    
    Note:
    blockScale cannot be zero.
  */
  virtual OdResult setBlockScale(
    OdUInt32 row, 
    OdUInt32 column, 
    double blockScale);

  /** Description:
    Returns the *rotation* angle of the block reference in the specified cell in this Table entity

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
  */
  virtual double blockRotation(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Sets the *rotation* angle of the block reference in the specified cell in this Table entity

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    blockRotation (I) Rotation angle.
  */
  virtual OdResult setBlockRotation(
    OdUInt32 row, 
    OdUInt32 column, 
    double blockRotation);

  /** Description:
    Gets the attribute *value* for the specified Object ID OdDb::key for the specified cell in this Table entity

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    attdefId (I) Object ID of the OdDbAttributeDefinition.
    attValue (O) Receives the attribute *value*.
  */
  OdResult getBlockAttributeValue(
    OdUInt32 row, 
    OdUInt32 column, 
    const OdDbObjectId& attdefId, 
    OdString& attValue) const;

  virtual OdResult getBlockAttributeValue(
    OdUInt32 row, 
    OdUInt32 column, 
    const OdDbObjectId& attdefId, 
    OdChar*& value) const;

  /** Description:
    Sets the attribute *value* for the specified Object ID OdDb::key for the specified cell in this Table entity

    Arguments:
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    attdefId (I) Object ID of the OdDbAttributeDefinition.
    attValue (O) Sets the attribute *value*.
  */
  void setBlockAttributeValue(
    OdUInt32 row, 
    OdUInt32 column,
    const OdDbObjectId& attdefId, 
    const OdString& attValue);
  virtual OdResult setBlockAttributeValue(
    OdUInt32 row, 
    OdUInt32 column,
    const OdDbObjectId& attdefId, 
    const OdChar* attValue);

  /** Description:
    Returns the grid *color* for the specified gridline types and *row* type,
    or the specified cell and edges in this Table entity (DXF 63,64,65,66,68,69).
      
    Arguments:      
    row (I) Row index of the cell.
    column (I) Column index of the cell.
    edgeTypes (I) Edge types.
    gridlineTypes (I) Gridline types.
    rowTypes (I) Row types.

    Remarks:    
    gridlineTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kHorzTop          1
    OdDb::kHorzInside       2
    OdDb::kHorzBottom       4
    
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
    
    edgeTypes must be a combination of one or more of the following:

    @table
    Name                    Value
    OdDb::kTopMask          1
    OdDb::kRightMask        2
    OdDb::kBottomMask       4
    OdDb::kLeftMask         8
  */
  virtual OdResult setGridColor(
    const OdCmColor& color, 
    OdUInt32 gridlineTypes, 
    OdUInt32 rowTypes);
  virtual OdResult setGridColor(
    OdUInt32 row, 
    OdUInt32 column, 
    OdInt16 edgeTypes,
    const OdCmColor& color);

  
  /** Description:
    Inserts the specified number of columns into this Table entity at the specified *column* index.
    Arguments:
    column (I) Column index.
    width (I) Width of the inserted columns.
    numColumns (I) Number of columns to insert.
  */
  virtual OdResult insertColumns(
    OdUInt32 column, 
    double width, 
    OdUInt32 numColumns = 1);

  /** Description:
    Deletes the specified number of columns from this Table entity.

    Arguments:      
    column (I) Index of first *column* to delete.
    numColumns (I) Number of columns to delete. 
  */
  virtual OdResult deleteColumns(
                    int column, 
                    int numColumns = 1);

  /** Description:
    Inserts the specified number of rows into this Table entity at the specified *row* index.
    Arguments:
    row (I) Row index.
    height (I) Height of the inserted rows.
    numRows (I) Number of rows to insert.
  */  
  virtual OdResult insertRows(
    OdUInt32 row, 
    double height, 
    OdUInt32 numRows = 1);
  
  /** Description:
    Deletes the specified number of rows from this Table entity.

    Arguments:      
    row (I) Index of first *row* to delete.
    numRows (I) Number of rows to delete. 
      
  */
  virtual OdResult deleteRows(
    OdUInt32 row, 
    OdUInt32 numRows = 1);

 
  /** Description:
    Merges a rectangular region of cells in this Table entity.
      
    Arguments:
    minRow (I) Minimum *row* index of the merged cells.
    maxRow (I) Maximum *row* index of the merged cells. 
    minColumn (I) Minimum *column* index of the merged cells.
    maxColumn (I) Maximum *column* index of the merged cells. 
  */  
  virtual OdResult mergeCells(
    OdUInt32 minRow, 
    OdUInt32 maxRow,
    OdUInt32 minColumn, 
    OdUInt32 maxColumn);

  /** Description:
    Unmerges a rectangular region of cells in this Table entity.
      
    Arguments:
    minRow (I) Minimum *row* index of the merged cells.
    maxRow (I) Maximum *row* index of the merged cells. 
    minColumn (I) Minimum *column* index of the merged cells.
    maxColumn (I) Maximum *column* index of the merged cells. 
  */  
  virtual OdResult unmergeCells(
    OdUInt32 minRow, 
    OdUInt32 maxRow,
    OdUInt32 minColumn, 
    OdUInt32 maxColumn);
    
  /** Description:
    Returns true if and only if the specified cell has been merged, and 
    the range of the merged cells in this Table entity.
    
    Arguments:
    row (I) Row index.
    column (I) Column index.
    minRow (O) Receives the minimum *row* index of the merged cells.
    maxRow (O) Receives the maximum *row* index of the merged cells. 
    minColumn (O) Receives the minimum *column* index of the merged cells.
    maxColumn (O) Receives the maximum *column* index of the merged cells. 
        
  */
  virtual bool isMergedCell(
                int row, 
                int column, 
                int *minRow = NULL, 
                int *maxRow = NULL,
                int *minColumn = NULL, 
                int *maxColumn = NULL) const;

  /** Description:
    Returns cell property "merged height". The first cell may have value > 1. Next cells has value equal 1.

    Arguments:
    row (I) Row index.
    column (I) Column index.
  */
  OdUInt32 mergedHeight(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Returns cell property "merged width". The first cell may have value > 1. Next cells has value equal 1.

    Arguments:
    row (I) Row index.
    column (I) Column index.
  */
  OdUInt32 mergedWidth(
    OdUInt32 row, 
    OdUInt32 column) const;

  /** Description:
    Returns cell property "merged flag". The first cell has value equal false. Next cells has value equal true.

    Arguments:
    row (I) Row index.
    column (I) Column index.
  */
  bool mergedFlag(
    OdUInt32 row, 
    OdUInt32 column) const;
  
  /**
    Description:
    Updates this Table entity according to its current table style.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult generateLayout();

  /** Description:
    Updates the block table record referenced by this Table entity.
    
    Arguments:
    forceUpdate (I) Force an update of block table record.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    If forceUpdate is false, the block table record is updated
    if and only if this table entity has been changed since the
    block table record was last updated.
    
    If forceUpdate is true, the block table will be unconditionally
    updated.
  */
  virtual OdResult recomputeTableBlock(
    bool forceUpdate = true);
  
  //********************************************************************
  // Methods for sub-selection  
  //********************************************************************
  //
  virtual bool  hitTest(const OdGePoint3d& wpt, 
                                    const OdGeVector3d& wviewVec,
                                    double wxaper,
                                    double wyaper,
                                    int& resultRowIndex, 
                                    int& resultColumnIndex) const;

  virtual bool  hitTest(const OdGePoint3d& wpt, 
                                    const OdGeVector3d& wviewVec,
                                    double wxaper,
                                    double wyaper,
                                    int& resultRowIndex, 
                                    int& resultColumnIndex,
                                    int& contentIndex,
                                    OdDb::TableHitItem& nItem) const;

  virtual OdResult select(const OdGePoint3d& wpt, 
                                   const OdGeVector3d& wvwVec, 
                                   const OdGeVector3d& wvwxVec, 
                                   double wxaper,
                                   double wyaper,
                                   bool allowOutside,
                                   bool bInPickFirst, 
                                   int& resultRowIndex, 
                                   int& resultColumnIndex,
                                   OdDbFullSubentPathArray* pPaths = 0) const;

  virtual OdResult selectSubRegion(const OdGePoint3d& wpt1, 
                                   const OdGePoint3d& wpt2,
                                   const OdGeVector3d& wvwVec, 
                                   const OdGeVector3d& wvwxVec,
                                   double wxaper,
                                   double wyaper,                             
                                   OdDb::SelectType seltype,
                                   bool bIncludeCurrentSelection,
                                   bool bInPickFirst,                             
                                   int& rowMin,
                                   int& rowMax,
                                   int& colMin,
                                   int& colMax,
                                   OdDbFullSubentPathArray* pPaths = 0) const;

  virtual bool reselectSubRegion(OdDbFullSubentPathArray& paths) const;
          
  virtual OdResult getSubSelection(int& rowMin,
                                    int& rowMax,
                                    int& colMin,
                                    int& colMax) const;

  OdCellRange  getSubSelection (void) const;

  virtual OdResult setSubSelection  (const OdCellRange& range);

  virtual OdResult setSubSelection(int rowMin,
                                    int rowMax,
                                    int colMin,
                                    int colMax);

  virtual void clearSubSelection();

  virtual bool hasSubSelection() const;
  
  virtual OdResult select_next_cell(int dir,
                                    int& resultRowIndex, 
                                    int& resultColumnIndex,
                                    OdDbFullSubentPathArray* pPaths = NULL,
                                    bool bSupportTextCellOnly = true) const;

  virtual void setRegen();
  virtual void suppressInvisibleGrid(bool value);
  virtual OdResult getCellExtents(int row, 
                                   int column,
                                   double& cellWidth,
                                   double& cellHeight,
                                   bool bAdjustForMargins) const;

  //********************************************************************
  // Overridden methods from OdDbObject
  //********************************************************************
  //

  virtual OdResult dwgInFields (
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields (
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult audit(OdDbAuditInfo* pAuditInfo);

  virtual void erased(const OdDbObject* dbObj,
    OdBool pErasing = kTrue);

  OdResult subClose();
  /** Note:
     This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
     the dimension style of this entity to the current style for the specified *database*.
  */
  void subSetDatabaseDefaults(
    OdDbDatabase *pDb,
    bool doSubents);

  virtual void objectClosed(const OdDbObjectId objId);
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  //********************************************************************
  // Overridden methods from OdDbEntity
  //********************************************************************
  //
  /*
  virtual void              list() const;
  */

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  /*
  virtual OdResult getGripPoints(OdGePoint3dArray&, 
                                          OdDbIntArray&,
                                          OdDbIntArray&) const;

  virtual OdResult moveGripPointsAt(const OdDbIntArray&,
                                             const OdGeVector3d&);

  virtual OdResult getStretchPoints(OdGePoint3dArray& stretchPoints)
                                             const;

  virtual OdResult moveStretchPointsAt(const OdDbIntArray& 
                                               indices,
                                               const OdGeVector3d& offset);

  virtual OdResult getOsnapPoints(OdDb::OsnapMode osnapMode,
                                           OdGsMarker   gsSelectionMark,
                                           const OdGePoint3d&  pickPoint,
                                           const OdGePoint3d&  lastPoint,
                                           const OdGeMatrix3d& viewXform,
                                           OdGePoint3dArray&      snapPoints,
                                           OdDbIntArray&   geomIds)
                                           const;
  */

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm,
    OdDbEntity*& pCopy) const;

  /*
  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;

  virtual OdResult explode(OdDbVoidPtrArray& entitySet) const;
  */

  //********************************************************************
  // Overridden methods from OdDbBlockReference required for OdDbTable
  //********************************************************************
  //
  //OdGePoint3d            position() const;
  virtual OdResult setPosition(const OdGePoint3d&);

  //OdGeVector3d           normal() const;
  virtual OdResult setNormal(const OdGeVector3d& newVal);

  //********************************************************************
  // Methods for internal use only
  //********************************************************************
  //
  // TODO: Temporary method for navigating after editing cells
  /*
  virtual OdResult select_next_cell(int dir,
                                   int& resultRowIndex, 
                                   int& resultColumnIndex,
                                   OdDbFullSubentPathArray* pPaths = 0,
                                   bool bSupportTextCellOnly = true) const;

  virtual void              setRegen();
  virtual void              suppressInvisibleGrid(bool value);
  virtual OdResult getCellExtents(int row, 
                                       int column,
                                       double& cellWidth,
                                       double& cellHeight,
                                       bool bAdjustForMargins) const;
  */
  
  // NEW 2007
  
  virtual OdResult getDataType(OdValue::DataType& nDataType,
    OdValue::UnitType& nUnitType,
    OdDb::RowType type) const;

  virtual OdResult setDataType(OdValue::DataType nDataType,
    OdValue::UnitType nUnitType);

  virtual OdResult setDataType(OdValue::DataType nDataType, 
    OdValue::UnitType nUnitType, 
    int nRowTypes);

  OdString format(ODSYSDEF, OdDb::RowType type) const;
  virtual const OdChar* format(OdDb::RowType type) const;

  virtual OdResult setFormat(const OdString& pszFormat);

  virtual OdResult setFormat(const OdString& pszFormat, 
    int nRowTypes);


  OdResult getDataType(int row, int col,
    OdValue::DataType& nDataType,
    OdValue::UnitType& nUnitType) const;

  OdResult setDataType(
            int row ,
            int col ,
            OdValue::DataType nDataType ,
            OdValue::UnitType nUnitType);

  OdValue value(OdUInt32 row, OdUInt32 col) const;

  OdResult resetValue(OdUInt32 row, OdUInt32 col);

  const OdChar * format(OdUInt32 row, OdUInt32 col) const;

  OdResult setFormat(OdUInt32 row, OdUInt32 col, 
    const OdChar * pszFormat);


  bool isBreakEnabled(void) const;
  OdResult enableBreak (bool bEnable);
  OdDb::TableBreakFlowDirection breakFlowDirection(void) const;
  OdResult setBreakFlowDirection (OdDb::TableBreakFlowDirection flowDir);
  double breakHeight (OdUInt32 index) const;
  OdResult setBreakHeight (OdUInt32 index, 
    double height);
  OdGeVector3d breakOffset (OdUInt32 index) const;
  OdResult setBreakOffset (OdUInt32 index, 
    const OdGeVector3d& vec);
  OdDb::TableBreakOption breakOption (void) const;
  OdResult  setBreakOption (OdDb::TableBreakOption option);
  double breakSpacing (void) const;
  OdResult setBreakSpacing (double spacing);

  //********************************************************************
  // New Methods
  //********************************************************************

  OdResult setSize ( 
            OdUInt32 rows, 
            OdUInt32 cols);

  bool canInsert (
    int nIndex, 
    bool bRow) const;

  OdResult insertRowsAndInherit  (
            OdUInt32 nIndex, 
            OdUInt32 nInheritFrom, 
            OdUInt32 nNumRows);

  OdResult insertColumnsAndInherit(
            OdUInt32 col, 
            OdUInt32 nInheritFrom, 
            OdUInt32 nNumCols);

  bool canDelete (
        int nIndex, 
        int nCount, 
        bool bRow) const;

  bool isEmpty (
    OdUInt32 row, 
    OdUInt32 col) const;

  OdCellRange getMergeRange (
                OdUInt32 row, 
                OdUInt32 col) const;

  OdDbTableIterator* getIterator(void) const;
  OdDbTableIterator* getIterator(const OdCellRange* pRange, OdDb::TableIteratorOption nOption) const;

  bool isContentEditable (
        OdUInt32 row, 
        OdUInt32 col) const;

  bool isFormatEditable (
        OdUInt32 row, 
        OdUInt32 col) const;

  OdDb::CellState cellState (
                    int row, 
                    int col) const;

  OdResult setCellState (
            int row, 
            int col, 
            OdDb::CellState nLock);

  int numContents (
        int row, 
        int col) const;

  int createContent (
    int row, 
    int col, 
    int nIndex);

  OdResult moveContent (
            int row, 
            int col, 
            int nFromIndex, 
            int nToIndex);

  OdResult  deleteContent (
              int row, 
              int col);

  OdResult  deleteContent (
              int row, 
              int col, 
              int nIndex);

  OdResult  deleteContent (
              const OdCellRange& range);

  OdDb::CellContentType contentType (
                          int row, 
                          int col) const;

  OdDb::CellContentType contentType (
                          int row, 
                          int col, 
                          int nIndex) const;

  OdValue value (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdValue value (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    OdValue::FormatOption nOption) const;

  OdResult setValue (
          int row , 
          int col , 
          int nContent , 
          const OdValue &val);

  OdResult setValue(
            int row ,
            int col ,
            const OdValue& val);

  OdResult setValue (
            int row ,
            int col ,
            int nContent ,
            const OdValue &val ,
            OdValue::ParseOption nOption);

  OdResult setValue (
            int row ,
            int col ,
            int nContent ,
            const OdChar *pszText ,
            OdValue::ParseOption nOption);

  OdResult setValue(
            int row ,
            int col,
            const OdChar *pszText ,
            OdValue::ParseOption nOption);

  OdString dataFormat (
            int row,
            int col) const;

  OdString dataFormat (
            int row, 
            int col, 
            int nContent) const;

  OdResult  setDataFormat (
              int row, 
              int col, 
              const OdChar* sFormat);

  OdResult  setDataFormat (
              int row, 
              int col, 
              int nContent, 
              const OdChar*  sFormat);

  OdString textString (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdString textString (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    OdValue::FormatOption nOption) const;

  OdString textString (
    OdUInt32 row, 
    OdUInt32 col, 
    OdValue::FormatOption nOption ) const;

  OdResult textString (
    OdUInt32 row, 
    OdUInt32 col, 
    OdValue::FormatOption nOption,
    OdString& sText) const;

  OdResult  setTextString (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdChar * text);

  bool  hasFormula (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdString getFormula (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdResult  setFormula (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdString& pszFormula);

  OdDbObjectId  fieldId (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdDbObjectId  blockTableRecordId (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;

  OdResult  setBlockTableRecordId (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdDbObjectId& blkId, 
    bool autoFit);

  OdString  getBlockAttributeValue (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdDbObjectId& attdefId) const;

   OdResult getBlockAttributeValue (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdDbObjectId& attdefId,
	OdString& value) const;
   OdResult setBlockAttributeValue (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdDbObjectId& attdefId, 
    const OdString& atrValue);

  int  getCustomData (
        int row, 
        int col) const;

  OdResult  setCustomData (
              int row, 
              int col, 
              int nData);

  OdResult getCustomData (
            int row, 
            int col, 
            const OdString &sKey,
            OdValue *pValue) const;

  OdResult setCustomData (
            int row, 
            int col, 
            const OdString& sKey, 
            const OdValue* pData);

  OdString cellStyle (
    int row, 
    int col) const;
  OdResult  setCellStyle (
    OdUInt32 row, 
    OdUInt32 col, 
    const OdString& sCellStyle);
  double margin (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::CellMargin nMargin) const;
  void  setMargin (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::CellMargin nMargins, 
    double fMargin);
  OdGePoint3d  attachmentPoint (
     int row, 
     int col, 
     int content) const;
  OdCmColor  contentColor (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult setContentColor (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    const OdCmColor& color);

  OdResult getDataType (
            int row, 
            int col, 
            int nContent, 
            OdValue::DataType& nDataType, 
            OdValue::UnitType& nUnitType) const;

  OdResult setDataType (
            int row, 
            int col, 
            int nContent, 
            OdValue::DataType nDataType, 
            OdValue::UnitType nUnitType);

  OdDbObjectId  textStyle (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult  setTextStyle (
              OdUInt32 row, 
              OdUInt32 col, 
              OdUInt32 nContent, 
              const OdDbObjectId& id);
  double textHeight (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult setTextHeight (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    double height);
  double rotation () const;
  double rotation (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult  setRotation (double fAngle);
  OdResult  setRotation (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    double fAngle);
  bool  isAutoScale (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult  setAutoScale (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    bool autoFit);
  double scale (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent) const;
  OdResult  setScale (
    OdUInt32 row, 
    OdUInt32 col, 
    OdUInt32 nContent, 
    double scale);
  OdDb::CellContentLayout contentLayout (
    OdUInt32 row, 
    OdUInt32 col) const;
  OdResult  setContentLayout (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::CellContentLayout nLayout);
   bool  isMergeAllEnabled (
     OdUInt32 row, 
     OdUInt32 col) const;

   OdResult enableMergeAll (
             OdUInt32 row, 
             OdUInt32 col, 
             bool bEnable);

   OdDb::CellProperty getOverride (
     OdUInt32 row, 
     OdUInt32 col, 
     OdUInt32 nContent) const;
   OdDb::GridProperty getOverride (
     OdUInt32 row, 
     OdUInt32 col, 
     OdDb::GridLineType nGridLineType) const;
   OdResult  setOverride (
     OdUInt32 row, 
     OdUInt32 col, 
     OdUInt32 nContent, 
     OdDb::CellProperty nOverride);
   OdResult  setOverride (
     OdUInt32 row, 
     OdUInt32 col, 
     OdDb::GridLineType nGridLineType, 
     OdDb::GridProperty nOverride);
   OdResult  removeAllOverrides (
     OdUInt32 row, 
     OdUInt32 col);
  OdDb::GridLineStyle gridLineStyle (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridLineStyle (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineTypes, 
    OdDb::GridLineStyle nLineStyle);
  OdDb::LineWeight gridLineWeight (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridLineWeight (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineTypes, 
    OdDb::LineWeight nLineWeight);
  OdDbObjectId    gridLinetype (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridLinetype (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineTypes, 
    const OdDbObjectId& idLinetype);
  OdCmColor gridColor (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridColor (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridlineTypes, 
    const OdCmColor& color);
  OdDb::Visibility gridVisibility (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridVisibility (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineTypes, 
    OdDb::Visibility nVisibility);
  double gridDoubleLineSpacing (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType) const;
  OdResult  setGridDoubleLineSpacing(
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType 
    nGridLineTypes, 
    double fSpacing);
  OdResult  getGridProperty (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineType, 
    OdGridProperty& gridProp) const;
  OdResult  setGridProperty (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::GridLineType nGridLineTypes, 
    const OdGridProperty& gridProp);
  OdResult  setGridProperty  (
    const OdCellRange& rangeIn, 
    OdDb::GridLineType nGridLineTypes, 
    const OdGridProperty& gridProp);

  bool isLinked (
    OdUInt32 row, 
    OdUInt32 col) const;

  /** Description:
      Returns the data link (OdDbDataLink) for specified row and column.
  */
  OdDbObjectId getDataLink (
    OdUInt32 row, 
    OdUInt32 col) const;
  /** Description:
      Opens and returns the data link (OdDbDataLink) for specified row and column.
  */
  OdDbDataLinkPtr getDataLink (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::OpenMode mode) const;

  OdResult getDataLink (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDbDataLink*& pDataLink,
    OdDb::OpenMode mode) const;
  /** Description:
      Returns all data links (OdDbDataLink) for specified cell range.
  */
  OdUInt32 getDataLink (
    const OdCellRange& pRange, 
    OdDbObjectIdArray& dataLinkIds) const;
  /** Description:
      Sets the data link (OdDbDataLink) for specified row and column.
  */
  OdResult setDataLink (
    OdUInt32 row, 
    OdUInt32 col, 
    const OdDbObjectId& idDataLink, 
    bool bUpdate);
  /** Description:
      Sets the data link (OdDbDataLink) for specified cell range.
  */
  OdResult setDataLink 
    (const OdCellRange& range, 
    const OdDbObjectId& idDataLink, 
    bool bUpdate);
  /** Description:
      Returns the data link cell range that includes the specified row and column.
  */
  OdCellRange getDataLinkRange (
    OdUInt32 row, 
    OdUInt32 col) const;
  /** Description:
      Removes the data link at the specified row and column.
  */
  OdResult  removeDataLink (
    OdUInt32 row, 
    OdUInt32 col);
  /** Description:
     Removes all data links.
  */
  OdResult  removeDataLink (void);
  
  OdResult  updateDataLink (
    OdUInt32 row, 
    OdUInt32 col, 
    OdDb::UpdateDirection nDir, 
    OdDb::UpdateOption nOption);
  OdResult  updateDataLink (
    OdDb::UpdateDirection nDir, 
    OdDb::UpdateOption nOption);

  OdString getColumnName (
    int nIndex) const;
  OdResult setColumnName (
    int nIndex, 
    const OdChar *sName);

  OdString getToolTip (
            int row, 
            int col) const;

  OdResult setToolTip (
            int row, 
            int col, 
            const OdString &sToolTip);

  OdResult createTemplate(OdDbTableTemplate *&pTemplate , OdDb::TableCopyOption nCopyOption);
  OdResult  getIndicatorSize (double& fWidth, double& fHeight) const;

  virtual OdResult copyFrom(
    const OdRxObject* pSource);
  OdResult copyFrom (
    const OdDbLinkedTableData* pSrc, 
    OdDb::TableCopyOption nOption);
  OdResult copyFrom (const OdDbLinkedTableData* pSrc, 
    OdDb::TableCopyOption nOption, 
    const OdCellRange& srcRange, 
    const OdCellRange& targetRange,
    OdCellRange* pNewTargetRangeOut);
  OdResult copyFrom  (const OdDbTable* pSrc, 
    OdDb::TableCopyOption nOption, 
    const OdCellRange& srcRange, 
    const OdCellRange& targetRange,
    OdCellRange* pNewTargetRangeOut);

  OdResult fill(const OdCellRange& fillRange, const OdCellRange& srcRange, OdDb::TableFillOption nOption);

 void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);
	
  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, OdGePoint3dArray &points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  /** Description:
      Returns true if regeneration of the table block is disabled. Otherwise, returns false.
  */
  bool isRegenerateTableSuppressed() const;
  void suppressRegenerateTable(bool bSuppress);
  
  void modified(const OdDbObject* pObj);

  /** Description:
      This method allows the user to disable the regeneration of the table block during property changes. 

      Arguments:
      bSuppress (I)  Input boolean value to suppress or enable the regeneration of a table object.
  */
//   void suppressRegenerateTable(bool bSuppress);

//   virtual OdResult subExplode(OdRxObjectPtrArray& entitySet) const ODRX_OVERRIDE;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbTable object pointers.
*/
typedef OdSmartPtr<OdDbTable> OdDbTablePtr;

#include "TD_PackPop.h"

#endif
