/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcValue.h"
#include "DbDataLink.h"

class GCDB_PORT GcDbLinkedData : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLinkedData);
  GcDbLinkedData(void);
  ~GcDbLinkedData(void);

  virtual Gcad::ErrorStatus clear(void);
  virtual bool isEmpty(void) const;

  virtual const GCHAR* name(void) const;
  virtual Gcad::ErrorStatus setName(const GCHAR* pszName);
  virtual const GCHAR* description(void) const;
  virtual Gcad::ErrorStatus setDescription(const GCHAR* pszDescription);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};

typedef GcArray<GcDbLinkedData*> GcDbDataArray;