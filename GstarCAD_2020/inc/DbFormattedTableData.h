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



#ifndef OD_DBFORMATTEDTABLEDATA_H
#define OD_DBFORMATTEDTABLEDATA_H

#include "DbObject.h"
#include "DbLinkedTableData.h"

#include "TD_PackPush.h"

	/** Description:
    Work-in-progress. This class represents FormattedTableData objects in an OdDbDatabase instance.

    Library:
    TD_Db

	{group:OdDb_Classes}
	*/
class TOOLKIT_EXPORT OdDbFormattedTableData : public OdDbLinkedTableData
{
public:
  ODDB_DECLARE_MEMBERS(OdDbFormattedTableData);

  OdDbFormattedTableData();
  ~OdDbFormattedTableData();

  virtual OdInt32 insertRowAndInherit(
    OdInt32 nIndex, 
    OdInt32 nInheritFrom,
    OdInt32 nNumRows);

  virtual OdInt32 insertColumnAndInherit(
    OdInt32 nIndex, 
    OdInt32 nInheritFrom,
    OdInt32 nNumCols);

  virtual OdResult setFieldId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdDbObjectId& idField, 
    OdDb::CellOption nFlag);

  virtual OdResult setFieldId(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent, 
    const OdDbObjectId& idField, 
    OdDb::CellOption nFlag);

  virtual OdResult merge(
    const OdCellRange &range);

  virtual OdResult unmerge(
    const OdCellRange &range);

  virtual bool isMerged(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdCellRange getMergeRange(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual bool isMergeAllEnabled(
                OdInt32 nRow, 
                OdInt32 nCol) const;
  
  virtual OdResult enableMergeAll(
                    OdInt32 nRow, 
                    OdInt32 nCol,
                    bool bEnable);

  virtual bool isFormatEditable(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual double rotation(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual double rotation(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setRotation(
    OdInt32 nRow, 
    OdInt32 nCol, 
    double fRotation);

  virtual OdResult setRotation(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent,
    double fRotation);

  virtual double scale(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual double scale(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setScale(
    OdInt32 nRow, 
    OdInt32 nCol, 
    double fScale);

  virtual OdResult setScale(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent,
    double fScale);

  virtual bool isAutoScale(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual bool isAutoScale(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setAutoScale(
    OdInt32 nRow, 
    OdInt32 nCol, 
    bool bAutoScale);

  virtual OdResult setAutoScale(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent,
    bool bAutoScale);

  virtual OdDb::CellAlignment alignment(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdResult setAlignment(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::CellAlignment nAlignment);

  virtual OdCmColor contentColor(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdCmColor contentColor(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setContentColor(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdCmColor& color);

  virtual OdResult setContentColor(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdUInt32 nContent,
    const OdCmColor& color);

  virtual OdDbObjectId textStyle(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdDbObjectId textStyle(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setTextStyle(
                    OdInt32 nRow, 
                    OdInt32 nCol, 
                    const OdDbObjectId& idTextStyle);

  virtual OdResult setTextStyle(
                    OdInt32 nRow, 
                    OdInt32 nCol, 
                    OdUInt32 nContent,
                    const OdDbObjectId& idTextStyle);

  virtual double textHeight(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual double textHeight(
    OdInt32 nRow, 
    OdInt32 nCol,
    OdUInt32 nContent) const;

  virtual OdResult setTextHeight(
                    OdInt32 nRow, 
                    OdInt32 nCol, 
                    double fTextHeight);

  virtual OdResult setTextHeight(
                    OdInt32 nRow, 
                    OdInt32 nCol,
                    OdUInt32 nContent,
                    double fTextHeight);

  virtual OdCmColor backgroundColor(OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdResult setBackgroundColor(
    OdInt32 nRow, 
    OdInt32 nCol, 
    const OdCmColor& color);

  virtual OdDb::CellContentLayout contentLayout(
    OdInt32 nRow, 
    OdInt32 nCol) const;

  virtual OdResult setContentLayout(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::CellContentLayout nLayout);

  virtual OdDb::FlowDirection flowDirection() const;
  
  virtual OdResult setFlowDirection(
    OdDb::FlowDirection nDir);

  virtual double margin(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::CellMargin nMargin) const;

  virtual OdResult setMargin(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::CellMargin nMargins, 
    double fMargin);

  virtual OdDb::GridLineStyle gridLineStyle(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridLineStyle(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes,
    OdDb::GridLineStyle nLineStyle);

  virtual OdDb::LineWeight gridLineWeight(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridLineWeight(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    OdDb::LineWeight nLineWeight);

  virtual OdDbObjectId gridLinetype(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridLinetype(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    const OdDbObjectId& idLinetype);

  virtual OdCmColor gridColor(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridColor(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    const OdCmColor& color);

  virtual OdDb::Visibility gridVisibility(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridVisibility(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    OdDb::Visibility nVisibility);

  virtual double gridDoubleLineSpacing(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setGridDoubleLineSpacing(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    double fSpacing);

  virtual OdResult getGridProperty(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType, 
    OdGridProperty& gridProp) const;

  virtual OdResult setGridProperty(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineTypes, 
    const OdGridProperty& gridProp);

  virtual OdResult setGridProperty(
    const OdCellRange& range,
    OdDb::GridLineType nGridLineTypes, 
    const OdGridProperty& gridProp);

  virtual OdDb::CellProperty getOverride(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdInt32 nContent) const;

  virtual OdDb::GridProperty getOverride(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType) const;

  virtual OdResult setOverride(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdInt32 nContent, 
    OdDb::CellProperty nOverride);
  
  virtual OdResult setOverride(
    OdInt32 nRow, 
    OdInt32 nCol, 
    OdDb::GridLineType nGridLineType, 
    OdDb::GridProperty nOverride);

  virtual OdResult removeAllOverrides(
    OdInt32 nRow, 
    OdInt32 nCol);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
};

typedef OdSmartPtr<OdDbFormattedTableData> OdDbFormattedTableDataPtr;

#include "TD_PackPop.h"

#endif // OD_DBFORMATTEDTABLEDATA_H
