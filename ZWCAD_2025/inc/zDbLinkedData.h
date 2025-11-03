

#pragma once

#include "zAcValue.h"
#include "zDbDataLink.h"

class ZCDB_PORT ZcDbLinkedData : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLinkedData);

    ZcDbLinkedData(void);
    virtual ~ZcDbLinkedData(void);

    virtual Zcad::ErrorStatus clear(void);
    virtual bool isEmpty          (void) const;

    virtual const ZTCHAR* name     (void) const;
    virtual Zcad::ErrorStatus setName(const ZTCHAR* pszName);
    virtual const ZTCHAR* description(void) const;
    virtual Zcad::ErrorStatus setDescription(const ZTCHAR* pszDescription);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
};

typedef ZcArray<ZcDbLinkedData*> ZcDbDataArray;
