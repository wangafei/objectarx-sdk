

#pragma once

#include "zDbLinkedTableData.h"
#include "zDbTableIterator.h"

struct ZcGridProperty
{
    ZcDb::GridProperty  mnPropMask;
    ZcDb::GridLineStyle mnLineStyle;
    ZcDb::LineWeight    mnLineWeight;
    ZcDbHardPointerId   mLinetype;
    ZcCmColor           mColor;
    ZcDb::Visibility    mnVisibility;
    double              mfDoubleLineSpacing;
};

class ZCDB_PORT ZcDbFormattedTableData : public ZcDbLinkedTableData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFormattedTableData);

    ZcDbFormattedTableData(void);
    ~ZcDbFormattedTableData(void);

    virtual int insertRowAndInherit(int nIndex, 
                                             int nInheritFrom,
                                             int nNumRows);
    virtual int insertColumnAndInherit(int nIndex, 
                                             int nInheritFrom,
                                             int nNumCols);

    virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idField, 
                                             ZcDb::CellOption nFlag);
    virtual Zcad::ErrorStatus setFieldId(int nRow, 
                                             int nCol, 
                                             int nIndex, 
                                             const ZcDbObjectId& idField, 
                                             ZcDb::CellOption nFlag);

    virtual Zcad::ErrorStatus merge(const ZcCellRange& range);
    virtual Zcad::ErrorStatus unmerge(const ZcCellRange& range);
    virtual bool isMerged         (int nRow, 
                                             int nCol) const;
    virtual ZcCellRange getMergeRange(int nRow, 
                                             int nCol) const;

    virtual bool isFormatEditable (int nRow, 
                                             int nCol) const;
    virtual double rotation       (int nRow, 
                                             int nCol) const;
    virtual double rotation       (int nRow, 
                                             int nCol,
                                             int nIndex) const;
    virtual Zcad::ErrorStatus setRotation(int nRow, 
                                             int nCol, 
                                             double fRotation);
    virtual Zcad::ErrorStatus setRotation(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             double fRotation);
    virtual double scale          (int nRow, 
                                             int nCol) const;
    virtual double scale          (int nRow, 
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setScale(int nRow, 
                                             int nCol, 
                                             double fScale);
    virtual Zcad::ErrorStatus setScale(int nRow, 
                                             int nCol, 
                                             int nIndex,
                                             double fScale);
    virtual bool isAutoScale      (int nRow, 
                                             int nCol) const;
    virtual bool isAutoScale      (int nRow, 
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setAutoScale(int nRow, 
                                             int nCol, 
                                             bool bAutoScale);
    virtual Zcad::ErrorStatus setAutoScale(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             bool bAutoScale);
    virtual ZcDb::CellAlignment alignment(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus setAlignment(int nRow, 
                                             int nCol, 
                                             ZcDb::CellAlignment nAlignment);
    virtual ZcCmColor contentColor(int nRow, 
                                             int nCol) const;
    virtual ZcCmColor contentColor(int nRow, 
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setContentColor(int nRow, 
                                             int nCol, 
                                             const ZcCmColor& color);
    virtual Zcad::ErrorStatus setContentColor(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZcCmColor& color);
    virtual ZcDbObjectId textStyle(int nRow, 
                                             int nCol) const;
    virtual ZcDbObjectId textStyle(int nRow, 
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setTextStyle(int nRow, 
                                             int nCol, 
                                             const ZcDbObjectId& idTextStyle);
    virtual Zcad::ErrorStatus setTextStyle(int nRow, 
                                             int nCol, 
                                             int nContent,
                                             const ZcDbObjectId& idTextStyle);
    virtual double textHeight     (int nRow, 
                                             int nCol) const;
    virtual double textHeight     (int nRow, 
                                             int nCol,
                                             int nContent) const;
    virtual Zcad::ErrorStatus setTextHeight(int nRow, 
                                             int nCol, 
                                             double fTextHeight);
    virtual Zcad::ErrorStatus setTextHeight(int nRow, 
                                             int nCol,
                                             int nContent,
                                             double fTextHeight);
    virtual ZcCmColor backgroundColor(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus setBackgroundColor(int nRow, 
                                             int nCol, 
                                             const ZcCmColor& color);
    virtual ZcDb::CellContentLayout contentLayout(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus setContentLayout(int nRow, 
                                             int nCol, 
                                             ZcDb::CellContentLayout nLayout);

    virtual ZcDb::FlowDirection flowDirection(void) const;
    virtual Zcad::ErrorStatus setFlowDirection(ZcDb::FlowDirection nDir);
    virtual double margin         (int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargin) const;
    virtual Zcad::ErrorStatus setMargin(int nRow, 
                                             int nCol, 
                                             ZcDb::CellMargin nMargins, 
                                             double fMargin);
    virtual bool isMergeAllEnabled(int nRow, 
                                             int nCol) const;
    virtual Zcad::ErrorStatus enableMergeAll(int nRow, 
                                             int nCol,
                                             bool bEnable);

    virtual ZcDb::GridLineStyle gridLineStyle(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridLineStyle(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes,
                                             ZcDb::GridLineStyle nLineStyle);
    virtual ZcDb::LineWeight gridLineWeight(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridLineWeight(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::LineWeight nLineWeight);
    virtual ZcDbObjectId gridLinetype(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridLinetype(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcDbObjectId& idLinetype);
    virtual ZcCmColor gridColor   (int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridColor(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcCmColor& color);
    virtual ZcDb::Visibility gridVisibility(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridVisibility(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             ZcDb::Visibility nVisibility);
    virtual double gridDoubleLineSpacing(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setGridDoubleLineSpacing(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             double fSpacing);
    virtual Zcad::ErrorStatus getGridProperty(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcGridProperty& gridProp) const;
    virtual Zcad::ErrorStatus setGridProperty(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);
    virtual Zcad::ErrorStatus setGridProperty(const ZcCellRange& range,
                                             ZcDb::GridLineType nGridLineTypes, 
                                             const ZcGridProperty& gridProp);

    virtual ZcDb::CellProperty getOverride(int nRow, 
                                             int nCol, 
                                             int nContent) const;
    virtual ZcDb::GridProperty getOverride(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType) const;
    virtual Zcad::ErrorStatus setOverride(int nRow, 
                                             int nCol, 
                                             int nContent, 
                                             ZcDb::CellProperty nOverride);
    virtual Zcad::ErrorStatus setOverride(int nRow, 
                                             int nCol, 
                                             ZcDb::GridLineType nGridLineType, 
                                             ZcDb::GridProperty nOverride);
    virtual Zcad::ErrorStatus removeAllOverrides(int nRow, 
                                             int nCol);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
};
