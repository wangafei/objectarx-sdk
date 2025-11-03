/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "DbTableContent.h"

class GcDbTable;

class GCDB_PORT GcDbTableTemplate : public GcDbTableContent
{
public:
  GCDB_DECLARE_MEMBERS(GcDbTableTemplate);

  GcDbTableTemplate(void);
  GcDbTableTemplate(const GcDbTable* pTable, GcDb::TableCopyOption nCopyOption);
  ~GcDbTableTemplate(void);

  virtual Gcad::ErrorStatus capture(const GcDbTable* pTable, GcDb::TableCopyOption nCopyOption);
  virtual Gcad::ErrorStatus createTable(GcDbTable*& pTable, GcDb::TableCopyOption nCopyOption);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};