

#pragma once

#include "zDbFormattedTableData.h"

class ZCDB_PORT ZcDbTableContent : public ZcDbFormattedTableData
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableContent);

    ZcDbTableContent(void);
    virtual ~ZcDbTableContent(void);

    virtual ZcDbObjectId tableStyleId(void) const;
    virtual Zcad::ErrorStatus setTableStyleId(const ZcDbObjectId& idTableStyle);
    virtual const ZTCHAR* cellStyle(int nRow, 
                                   int nCol) const;
    virtual Zcad::ErrorStatus setCellStyle(int nRow, 
                                   int nCol, 
                                   const ZTCHAR* pszCellStyle);
    virtual double rowHeight      (int nRow) const;
    virtual Zcad::ErrorStatus setRowHeight(int nRow, 
                                   double fWidth);
    virtual double columnWidth    (int nCol) const;
    virtual Zcad::ErrorStatus setColumnWidth(int nCol, 
                                             double fWidth);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
};
