//
//////////////////////////////////////////////////////////////////////////////
// 
// Name:            DbTableTemplate.h
//
// Description:     Contains the following classes: 
//                      OdDbTableTemplate
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "DbTableContent.h"

class OdDbTable;

//*************************************************************************
// OdDbTableTemplate
//*************************************************************************

class TOOLKIT_EXPORT OdDbTableTemplate : public OdDbTableContent
{
public:
  ODDB_DECLARE_MEMBERS(OdDbTableTemplate);

  OdDbTableTemplate(void);
  OdDbTableTemplate(const OdDbTable* pTable, OdDb::TableCopyOption nCopyOption);
  virtual ~OdDbTableTemplate(void);

  virtual OdResult capture       (const OdDbTable* pTable, OdDb::TableCopyOption nCopyOption);
  virtual OdResult createTable   (OdDbTable*& pTable, OdDb::TableCopyOption nCopyOption);

  virtual OdResult dwgInFields   (OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields  (OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields   (OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields  (OdDbDxfFiler* pFiler) const;
};
