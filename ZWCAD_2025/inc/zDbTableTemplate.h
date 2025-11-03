

#pragma once

#include "zDbTableContent.h"

class ZcDbTable;
class ZCDBCORE2D_PORT ZcDbTableTemplate : public ZcDbTableContent
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbTableTemplate);

    ZcDbTableTemplate(void);
    ZcDbTableTemplate(const ZcDbTable* pTable, ZcDb::TableCopyOption nCopyOption);
    virtual ~ZcDbTableTemplate(void);

    virtual Zcad::ErrorStatus capture       (const ZcDbTable* pTable, ZcDb::TableCopyOption nCopyOption);
    virtual Zcad::ErrorStatus createTable   (ZcDbTable*& pTable, ZcDb::TableCopyOption nCopyOption);

    virtual Zcad::ErrorStatus dwgInFields   (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields  (ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields   (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields  (ZcDbDxfFiler* pFiler) const override;
};
