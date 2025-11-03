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


#ifndef OD_DBTABLESTYLE_H
#define OD_DBTABLESTYLE_H

#include "TD_PackPush.h"
#include "DbObject.h"
#include "DbColor.h"
#include "OdValue.h"
#include "StringArray.h"
//#include "DbTableTemplate.h"

class OdDbTableTemplate;

/** Description: 
  
    {group:TD_Namespaces}
*/
// namespace OdDb
// {
//   // OdDbTable and OdTbTableStyle specific enum
//   //
//   
//   enum CellType          
//   { 
//     kUnknownCell    = 0,
//     kTextCell       = 1,
//     kBlockCell      = 2,
//     kMultipleContentCell = 3
//   };

//   enum CellContentType   
//   { 
//     kCellContentTypeUnknown = 0x0,
//     kCellContentTypeValue   = 0x1,
//     kCellContentTypeField   = 0x2,
//     kCellContentTypeBlock   = 0x4
//   };

//   enum CellEdgeMask      
//   { 
//     kTopMask        = 0x1,
//     kRightMask      = 0x2,
//     kBottomMask     = 0x4,
//     kLeftMask       = 0x8 
//   };

//   enum SelectType
//   { 
//     kWindow         = 1,
//     kCrossing       = 2 
//   };
// 
//   enum FlowDirection
//   { 
//     kTtoB           = 0,
//     kBtoT           = 1 
//   };
// 
//   enum RotationAngle     
//   { 
//     kDegreesUnknown = -1,
//     kDegrees000     = 0,
//     kDegrees090     = 1,
//     kDegrees180     = 2,
//     kDegrees270     = 3 
//   };
// 
//   enum CellAlignment
//   { 
//     kTopLeft        = 1,
//     kTopCenter      = 2,
//     kTopRight       = 3,
//     kMiddleLeft     = 4,
//     kMiddleCenter   = 5,
//     kMiddleRight    = 6,
//     kBottomLeft     = 7,
//     kBottomCenter   = 8,
//     kBottomRight    = 9 
//   };
// 
//   enum GridLineType
//   { 
//     kInvalidGridLine= 0x00,
//     kHorzTop        = 0x01,
//     kHorzInside     = 0x02,
//     kHorzBottom     = 0x04,
//     kVertLeft       = 0x08,
//     kVertInside     = 0x10,
//     kVertRight      = 0x20,
//     kHorzGridLineTypes     = kHorzTop | kHorzBottom | kHorzInside,
//     kVertGridLineTypes     = kVertLeft | kVertRight | kVertInside,
//     kOuterGridLineTypes    = kHorzTop | kHorzBottom | kVertLeft | kVertRight,
//     kInnerGridLineTypes    = kHorzInside | kVertInside,
//     kAllGridLineTypes      = kOuterGridLineTypes | kInnerGridLineTypes
//   };
// 
// 
//   enum RowType
//   { 
//     kUnknownRow     = 0x0,
//     kDataRow        = 0x1,
//     kTitleRow       = 0x2,
//     kHeaderRow      = 0x4
//   };
// 
//   enum TableStyleFlags
//   { 
//     kHorzInsideLineFirst  = 0x1,
//     kHorzInsideLineSecond = 0x2,
//     kHorzInsideLineThird  = 0x4,
//     kTableStyleModified   = 0x8
//   };
// 
// 
//   enum RowTypes
//   { 
//     kAllRows = kDataRow | kTitleRow | kHeaderRow 
//   };
//     
//   enum GridLineTypes 
//   {   
//     kAllGridLines = kHorzTop | kHorzInside | kHorzBottom | kVertLeft | kVertInside | kVertRight 
//   };
// 
//   enum GridLineStyle  
//   { 
//     kGridLineStyleSingle = 1,
//     kGridLineStyleDouble = 2
//   };
// 
//   enum CellMargin        
//   { 
//     kCellMarginTop         = 0x01,
//     kCellMarginLeft        = 0x02,
//     kCellMarginBottom      = 0x04,
//     kCellMarginRight       = 0x08,
//     kCellMarginHorzSpacing = 0x10,
//     kCellMarginVertSpacing = 0x20 
//   };
// 
//   enum CellContentLayout
//   { 
//     kCellContentLayoutFlow              = 0x1,
//     kCellContentLayoutStackedHorizontal = 0x2,
//     kCellContentLayoutStackedVertical   = 0x4
//   };

//   enum CellState
//   { 
//     kCellStateNone                        = 0x00,
//     kCellStateContentLocked               = 0x01,
//     kCellStateContentReadOnly             = 0x02,
//     kCellStateLinked                      = 0x04,
//     kCellStateContentModifiedAfterUpdate  = 0x08,
//     kCellStateFormatLocked                = 0x10,
//     kCellStateFormatReadOnly              = 0x20,
//     kCellStateFormatModifiedAfterUpdate   = 0x40,
//     kAllCellStates  = (kCellStateContentLocked | kCellStateContentReadOnly |
//                        kCellStateLinked | kCellStateContentModifiedAfterUpdate | 
//                        kCellStateFormatLocked | kCellStateFormatReadOnly |
//                        kCellStateFormatModifiedAfterUpdate)
//   };
// 
//   enum GridProperty      
//   { 
//     kGridPropInvalid           = 0x00,
//     kGridPropLineStyle         = 0x01,
//     kGridPropLineWeight        = 0x02,
//     kGridPropLinetype          = 0x04,
//     kGridPropColor             = 0x08,
//     kGridPropVisibility        = 0x10,
//     kGridPropDoubleLineSpacing = 0x20,
//     kGridPropAll               = (kGridPropLineStyle | kGridPropLineWeight | kGridPropLinetype |
//                                   kGridPropColor | kGridPropVisibility | kGridPropDoubleLineSpacing)
//   };
// 
//   enum CellOption        
//   {
//     kCellOptionNone    = 0x0,
//     kInheritCellFormat = 0x1
//   };
// 
//   enum CellProperty      
//   { 
//     kCellPropInvalid               = 0x00000,
//     kCellPropDataType              = 0x00001,
//     kCellPropDataFormat            = 0x00002,
//     kCellPropRotation              = 0x00004,
//     kCellPropScale                 = 0x00008,
//     kCellPropAlignment             = 0x00010,
//     kCellPropContentColor          = 0x00020,
//     kCellPropTextStyle             = 0x00040,
//     kCellPropTextHeight            = 0x00080,
//     kCellPropAutoScale             = 0x00100,
//     kCellPropBackgroundColor       = 0x00200,
//     kCellPropMarginLeft            = 0x00400,
//     kCellPropMarginTop             = 0x00800,
//     kCellPropMarginRight           = 0x01000,
//     kCellPropMarginBottom          = 0x02000,
//     kCellPropContentLayout         = 0x04000,
//     kCellPropMergeAll              = 0x08000,
//     kCellPropFlowDirBtoT           = 0x10000,
//     kCellPropMarginHorzSpacing     = 0x20000,
//     kCellPropMarginVertSpacing     = 0x40000,
//     kCellPropDataTypeAndFormat     = (kCellPropDataType | kCellPropDataFormat),
//     kCellPropContent               = (kCellPropDataType | kCellPropDataFormat | kCellPropRotation |
//                                       kCellPropScale | kCellPropContentColor |  kCellPropTextStyle | 
//                                       kCellPropTextHeight | kCellPropAutoScale),
//     kCellPropBitProperties         = (kCellPropAutoScale | kCellPropMergeAll | kCellPropFlowDirBtoT),
//     kCellPropAll                   = (kCellPropDataType | kCellPropDataFormat | kCellPropRotation |
//                                       kCellPropScale | kCellPropAlignment | kCellPropContentColor | kCellPropBackgroundColor | 
//                                       kCellPropTextStyle | kCellPropTextHeight | kCellPropMarginLeft | kCellPropMarginTop |
//                                       kCellPropMarginRight | kCellPropMarginBottom | kCellPropMarginHorzSpacing | 
//                                       kCellPropMarginVertSpacing | kCellPropAutoScale | kCellPropMergeAll | 
//                                       kCellPropFlowDirBtoT | kCellPropContentLayout)
//   };
// }

  /** Description:
    This class represents the parameters of cells for OdDbTable entities..
    
    {group:Other_Classes}
  */
class OdCellRange
{
public:
  int     mnTopRow;
  int     mnLeftColumn;
  int     mnBottomRow;
  int     mnRightColumn;

  OdCellRange() : mnTopRow(-1)
    , mnLeftColumn(-1)
    , mnBottomRow(-1)
    , mnRightColumn(-1) {}

  OdCellRange(OdInt32 topRow, OdInt32 leftColumn, OdInt32 bottomRow, OdInt32 rightColumn)
    : mnTopRow(topRow)
    , mnLeftColumn(leftColumn)
    , mnBottomRow(bottomRow)
    , mnRightColumn(rightColumn)
  {}

  bool operator ==(
    const OdCellRange& range) const
  {
    return ( mnTopRow == range.mnTopRow &&
              mnLeftColumn == range.mnLeftColumn &&
              mnBottomRow == range.mnBottomRow &&
              mnRightColumn == range.mnRightColumn );
  }
  bool operator !=(
    const OdCellRange& range) const
  {
    return !( *this == range);
  }
};

typedef OdArray<OdCellRange> OdCellRangeArray;

 /** Description:
    This class represents a grid for OdDbTable entities.
    
    {group:Other_Classes}
  */
class OdGridProperty
{
public:

  OdDb::GridProperty  m_propMask;
  OdDb::GridLineStyle m_lineStyle;
  OdDb::LineWeight    m_lineWeight;
  OdDbHardPointerId   m_linetype;
  OdCmColor           m_color;
  OdDb::Visibility    m_visibility;
  double              m_doubleLineSpacing;

  OdGridProperty() : m_propMask(OdDb::kGridPropInvalid)
    , m_lineStyle(OdDb::kGridLineStyleSingle)
    , m_lineWeight(OdDb::kLnWtByBlock)
    , m_visibility(OdDb::kVisible)
    , m_doubleLineSpacing(0.0) {}

};

/** Description:
    This class represents TableStyles for OdDbTable entities in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbTableStyle : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbTableStyle);

  OdDbTableStyle();
  virtual ~OdDbTableStyle();

  // General Properties
  //
  
  /** Description:
    Returns the *name* of this TableStyle object.

    Arguments
    name (O) Receives the *name*.
    
    Note:
    Returns eOk if successful, or an appropriate error code if not.
  */
  OdString getName() const;

  virtual OdResult   getName(OdChar*& pszName) const;
  
  /** Description:
    Sets the *name* of this TableStyle object.

    Arguments
    name (I) Name.
  */
  virtual OdResult   setName(const OdChar* pszName);

  /** Description:
    Returns the *description* of this TableStyle object.
  */
  virtual const OdChar* description() const;

  /** Description:
    Sets the *description* of this TableStyle object.
    
    Arguments:
    description (I) Description.
  */
  virtual OdResult setDescription(
    const OdChar* pszDescription);

  /** Description:
    Returns the bit flags for this TableStyle object (DXF 71). 
      
    Remarks:  
    bitFlags() returns a combination of zero or more of the following:
    
    @table
    Name                      Value
    kHorzInsideLineFirst      1
    kHorzInsideLineSecond     2
    kHorzInsideLineThird      4
    kTableStyleModified       8 
  */
  virtual OdUInt32 bitFlags() const;

  /** Description:
    Sets the bit flags for this TableStyle object (DXF 71). 
    
    Arguments:
    bitFlags (I) Bit flags.
    
    Remarks:
    bitFlags must be a combination of one or more of the following:
    
    @table
    Name                      Value
    kHorzInsideLineFirst      1
    kHorzInsideLineSecond     2
    kHorzInsideLineThird      4
    kTableStyleModified       8 
  */
  virtual OdResult setBitFlags(
    OdUInt32 bitFlags);

  /** Description:
    Returns the *direction* this TableStyle object flows from its first *row* to its last (DXF 70).

    Remarks:
    flowDirection() returns one of the following:
    
    @table
    Name          Value   Description
    OdDb::kTtoB   0       Top to Bottom
    OdDb::kBtoT   1       Bottom to Top
  */
  virtual OdDb::FlowDirection flowDirection() const; 

  /** Description:
    Sets the *direction* this TableStyle objectflows from its first *row* to its last. (DXF 70).

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
    Returns the horizontal cell margin for this TableStyle object (DXF 40). 
    Remarks:
    The horizontal cell margin is the horizontal space between the cell text and the cell border.
  */
  virtual double horzCellMargin() const;

  /** Description:
    Sets the horizontal cell margin for this TableStyle object (DXF 40).
    
    Arguments:
    cellMargin (I) Cell margin.
    
    Remarks:
    The horizontal cell margin is the horizontal space between the cell text and the cell border.
  */
  virtual OdResult setHorzCellMargin(
    double cellMargin);


  /** Description:
    Returns the vertical cell margin for this TableStyle object (DXF 41). 

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
      Returns true if and only if the title *row* is suppressed for this TableStyle object (DXF 280).
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
    Returns true if and only if the header *row* is suppressed for this TableStyle object (DXF 281). 
  */
  virtual bool isHeaderSuppressed() const;

  /** Description:
      Controls the suppression of the header *row* for this TableStyle object (DXF 280).
      Arguments:
      enable (I) Controls suppression.
  */
  virtual OdResult suppressHeaderRow(
    bool suppress);


  /** Description:
    Returns the Object ID of the text style for the specified *row* type in this TableStyle object (DXF 7).

    Arguments:
    rowType (I) Row type.
    
    Remarks: 
    rowType must be one of the following:
    
    @table
    Name              Value
    kTitleRow         1
    kHeaderRow        2
    kDataRow          4
  */
  virtual OdDbObjectId textStyle(
    OdDb::RowType rowType = OdDb::kDataRow) const;

  /** Description:
    Sets the Object ID of the text style for the specified *row* types for this TableStyle object (DXF 7).
    
    Arguments:
    rowTypes (I) Row types.
    textStyleId (I) Text style Object ID.

    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name              Value
    kTitleRow         1
    kHeaderRow        2
    kDataRow          4
  */
  virtual OdResult setTextStyle(
    const OdDbObjectId textStyleId, 
    int rowTypes = OdDb::kAllRows);

  /** Description:
    Returns the text *height* for the specified *row* type in this TableStyle object (DXF 140).

    Arguments:
    rowType (I) Row type
    
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

  /** Description:
    Sets the text *height* for the specified *row* types in this TableStyle object (DXF 140).

    Arguments:
    rowTypes (I) Row types.
    height (I) Text *height*.

    Remarks:
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name              Value
    kTitleRow         1
    kHeaderRow        2
    kDataRow          4
  */
  virtual OdResult setTextHeight(
    double height, 
    int rowTypes = OdDb::kAllRows);

  /** Description:
    Returns the cell *alignment* for the specified *row* type in this TableStyle object (DXF 170).

    Arguments:
    rowType (I) Row type
    
    Remarks:
    rowType() returns one of the following:
    
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


  /** Description:
    Sets the cell *alignment* for the specified *row* types in this TableStyle object (DXF 170).
    
    Arguments:
    rowTypes (I) Row types.
    alignment (I) Alignment.

    Remarks: 
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
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
    int rowTypes = OdDb::kAllRows);

  /** Description:
    Returns the text *color* for the specified *row* type in this TableStyle object (DXF 62).

    Arguments:
    rowTypes (I) Row types.

    Remarks:
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdCmColor color(
    OdDb::RowType rowType = OdDb::kDataRow) const;
    

  /** Description:
    Sets the text *color* for the specified *row* types in this TableStyle object (DXF 62).

    Arguments:
    rowTypes (I) Row types.
    color (I) Color.

    Remarks:
    rowTypes must be a combination of one or more of the following:
    
    @table
    Name                    Value
    OdDb::kTitleRow         1
    OdDb::kHeaderRow        2
    OdDb::kDataRow          4
  */
  virtual OdResult setColor(
    const OdCmColor& color,
    int rowTypes = OdDb::kAllRows);

  /** Description:
    Returns the background *color* for the specified *row* type in this TableStyle object (DXF 63).

    Arguments:
    rowType (I) Row type.

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

  /** Description:
    Sets the background *color* for the specified *row* type in this TableStyle object (DXF 63). 

    Arguments:
    rowTypes (I) Row types.
    color (I) Background *color*.
    
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
    int rowTypes = OdDb::kAllRows);

  /** Description:
    Returns true if and only if the background *color* for the specified *row* 
    type is disabled for this TableStyle object (DXF 283).

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

  /** Description:
    Controls the background *color* setting for the specified *row* types or cell in this TableStyle object (DXF 283). 

    Arguments:
    disable (I) Disables the background *color* if true, enables if false.
    rowTypes (I) Row types.

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
    int rowTypes = OdDb::kAllRows);

  //Gridline properties
  //
  
  /** Description:
    Returns the grid lineweight for the specified gridline type and *row* type in this TableStyle object (DXF 274-279).
      
    Arguments:      
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
    
  */
  virtual OdDb::LineWeight gridLineWeight(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 
  
  /** Description:
    Sets the grid lineweight for the specified gridline types and *row* types,
    or the specified cell and edges in this Table entity (DXF 274-279).
      
    Arguments:
    lineWeight (I) Lineweight.      
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
  */
  virtual OdResult setGridLineWeight(
    OdDb::LineWeight lineWeight, 
    int gridlineTypes = OdDb::kAllGridLines, 
    int rowTypes = OdDb::kAllRows);


  /** Description:
    Returns the grid *color* for the specified gridline type and *row* type
    in this TableStyle object (DXF 63,64,65,66,68,69).
      
    Arguments:      
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
  */
  virtual OdCmColor gridColor(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 

  /** Description:
    Returns the grid *color* for the specified gridline types and *row* type
    in this TableStyle object (DXF 63,64,65,66,68,69).
      
    Arguments:      
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
  */
  virtual OdResult setGridColor(
    const OdCmColor color, 
    int gridlineTypes = OdDb::kAllGridLines, 
    int rowTypes = OdDb::kAllRows);


  /** Description:
    Returns the grid visibility for the specified gridline type and *row* type,
    in this TableStyle object (DXF 284-289).
      
    Arguments:      
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
    
  */
  virtual OdDb::Visibility gridVisibility(
    OdDb::GridLineType gridlineType,
    OdDb::RowType rowType = OdDb::kDataRow) const; 


/** Description:
    Sets the grid visibility for the specified gridline types and *row* types,
    in this TableStyle object (DXF 284-289).
      
    Arguments:
    gridVisibility (I) Grid visibility.      
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
    
  */
  virtual OdResult setGridVisibility(
    OdDb::Visibility gridVisiblity, 
    int gridlineTypes = OdDb::kAllGridLines, 
    int rowTypes = OdDb::kAllRows);


  // NEW 2007

  virtual OdResult getDataType(
    OdValue::DataType& nDataType,
    OdValue::UnitType& nUnitType) const;
	
  virtual OdResult getDataType(
    OdValue::DataType& nDataType,
    OdValue::UnitType& nUnitType,
    OdDb::RowType rowType) const;

  virtual OdResult setDataType(
    OdValue::DataType nDataType, 
    OdValue::UnitType nUnitType);

  virtual OdResult setDataType(
    OdValue::DataType nDataType, 
    OdValue::UnitType nUnitType,
    int rowTypes);

  virtual const OdChar* format () const;
  virtual const OdChar* format (
    OdDb::RowType rowType) const;

  virtual OdResult setFormat(
    const OdChar* pszFormat);
  virtual OdResult setFormat(
    const OdChar* pszFormat,
    int rowTypes);


  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult audit(OdDbAuditInfo* pAuditInfo);

  // Utility functions
  //

  /** Description:
    Applies the default properties of the specified *database* to this TableStyle object.
    
    Arguments:
    pDb (I) Pointer to the *database* whose default values are to be used.
     
    Remarks:
    If pDb is null, the *database* containing this object is used
  */
  void setDatabaseDefaults(OdDbDatabase* pDb = 0);

  /** Description:
    Adds this TableStyle object to the specified *database*.
  
    Arguments:
    pDb (I) Pointer to the *database* in which to post.
    styleName (I) Name for the table style. 
    tableStyleId (O) Receives 

    Remarks:
    Returns the Object ID of the posted table style.
  */
  OdDbObjectId postTableStyleToDb(OdDbDatabase* pDb, const OdString& styleName);

  virtual OdResult postTableStyleToDb(OdDbDatabase* pDb, const OdChar* pStyleName, OdDbObjectId& tableStyleId);

  const OdString  createCellStyle(void);

  OdResult createCellStyle(const OdString& cellStyle);

  OdResult createCellStyle(const OdString& cellStyle, const OdString& fromCellStyle);

  OdResult renameCellStyle(const OdString& oldName, const OdString& newName);

  OdResult deleteCellStyle(const OdString& cellStyle);

  OdResult copyCellStyle(const OdString& srcCellStyle, const OdString& targetCellStyle);
  OdResult copyCellStyle(const OdDbTableStyle* pSrc, const OdString& srcCellStyle, const OdString &targetCellStyle);

  OdResult getUniqueCellStyleName(const OdString& baseName, OdString& sUniqueName) const;
  bool isCellStyleInUse(const OdString& cellStyle) const;

  OdInt32 numCellStyles(void) const;

  OdInt32 getCellStyles(OdStringArray& cellstyles) const;

  OdInt32 cellStyleId(const OdString& cellStyle) const;
  OdString cellStyleName(OdInt32 cellStyle) const;

  OdDbObjectId textStyle(const OdString& cellStyle) const;
  OdResult setTextStyle (const OdDbObjectId& id, const OdString& cellStyle);

  double textHeight(const OdString& cellStyle) const;
  OdResult setTextHeight(double dHeight, const OdString& cellStyle);

  OdDb::CellAlignment alignment(const OdString& cellStyle) const;
  OdResult setAlignment(OdDb::CellAlignment alignment, const OdString& cellStyle);

  OdCmColor color(const OdString& cellStyle) const;
  OdResult setColor(const OdCmColor& color, const OdString& cellStyle);

  OdCmColor backgroundColor(const OdString& cellStyle) const;
  OdResult setBackgroundColor(const OdCmColor& color, const OdString& cellStyle);

  OdResult getDataType(OdValue::DataType& nDataType, OdValue::UnitType& nUnitType, const OdString& cellStyle) const;
  OdResult setDataType(OdValue::DataType nDataType, OdValue::UnitType nUnitType, const OdString& cellStyle);

  const OdString format(const OdString& cellStyle) const;
  OdResult setFormat(const OdString& format, const OdString& cellStyle);

  OdInt32 cellClass(const OdString& cellStyle) const;
  OdResult setCellClass(OdInt32 nClass, const OdString& cellStyle);

  double rotation(const OdString& cellStyle) const;
  OdResult setRotation(double rotation, const OdString& cellStyle);

  bool isMergeAllEnabled(const OdString& cellStyle) const;
  OdResult enableMergeAll(bool bEnable, const OdString& cellStyle);

  double margin(OdDb::CellMargin nMargin, const OdString& cellStyle) const;
  OdResult setMargin(OdDb::CellMargin nMargins, double fMargin, const OdString& cellStyle);

  //Gridline properties
  //
  OdDb::LineWeight gridLineWeight(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridLineWeight(OdDb::LineWeight lineWeight, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  OdCmColor gridColor(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridColor(const OdCmColor color, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  OdDb::Visibility gridVisibility(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridVisibility(OdDb::Visibility visible, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  double gridDoubleLineSpacing(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridDoubleLineSpacing(double fSpacing, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  OdDb::GridLineStyle gridLineStyle(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridLineStyle(OdDb::GridLineStyle nLineStyle, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  OdDbObjectId gridLinetype(OdDb::GridLineType gridLineType, const OdString& cellStyle) const;
  OdResult setGridLinetype(const OdDbObjectId& id, OdDb::GridLineType gridLineTypes, const OdString& cellStyle);

  OdResult getGridProperty(OdGridProperty& gridProp, OdDb::GridLineType nGridLineTypes, const OdString& cellStyle) const;
  OdResult setGridProperty (const OdGridProperty& gridProp, OdDb::GridLineType nGridLineTypes, const OdString& cellStyle);

  virtual OdResult subGetClassID(CLSID* pClsid) const;

  OdDbObjectId getTemplate(void) const;

  OdResult getTemplate(OdDbTableTemplate *&pTemplate , OdDb::OpenMode mode);

  OdResult setTemplate(const OdDbObjectId& templateId, OdDb::MergeCellStyleOption nOption);

  OdResult setTemplate(
            OdDbTableTemplate *pTemplate ,
            OdDb::MergeCellStyleOption nOption ,
            OdDbObjectId& templateId);

  OdDbObjectId removeTemplate(void);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbTableStyle object pointers.
*/
typedef OdSmartPtr<OdDbTableStyle> OdDbTableStylePtr;
typedef OdSmartPtr<OdDbTableTemplate> OdDbTableTemplatePtr;

#include "TD_PackPop.h"

#endif // OD_DBTABLESTYLE_H
