/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "DbFormattedTableData.h"

class GCDB_PORT GcDbTableContent : public GcDbFormattedTableData
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTableContent);

  GcDbTableContent(void);
  ~GcDbTableContent(void);

  virtual GcDbObjectId tableStyleId(void) const;
  virtual Gcad::ErrorStatus setTableStyleId(const GcDbObjectId& idTableStyle);

  virtual const GCHAR* cellStyle(int nRow, int nCol) const;
  virtual Gcad::ErrorStatus setCellStyle(int nRow, int nCol, const GCHAR* pszCellStyle);

  virtual double rowHeight(int nRow) const;
  virtual Gcad::ErrorStatus setRowHeight(int nRow, double fWidth);

  virtual double columnWidth(int nCol) const;
  virtual Gcad::ErrorStatus setColumnWidth(int nCol, double fWidth);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};