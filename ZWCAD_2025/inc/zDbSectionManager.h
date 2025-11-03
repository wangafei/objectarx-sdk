
#pragma once

#include "zAdAChar.h"
#include "zDbSection.h"

class ZcDbSection;
class ZcDbSectionManagerIterator;
class ZcDbImpSectionManager;

class ZCDB_PORT ZcDbSectionManager : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbSectionManager);

    Zcad::ErrorStatus getSection  (const ZTCHAR* pszName,
                                             ZcDbObjectId& id) const;
    Zcad::ErrorStatus getSection  (const ZTCHAR* pszName,
                                             ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode mode) const;
    Zcad::ErrorStatus getLiveSection(ZcDbObjectId& id) const;
    Zcad::ErrorStatus getLiveSection(ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode mode) const;
    int   numSections             (void) const;
    Zcad::ErrorStatus newIterator (ZcDbSectionManagerIterator*& pIterator) const;
	Zcad::ErrorStatus getUniqueSectionName(const ZTCHAR* pszBaseName,
											ZcString& pszUniqueName) const;
    Zcad::ErrorStatus getUniqueSectionName(const ZTCHAR* pszBaseName,
                                             ZTCHAR*& pszUniqueName) const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

public:

    ZcDbSectionManager(void);
    ~ZcDbSectionManager(void);
protected:
    virtual Zcad::ErrorStatus subGetClassID  (CLSID* pClsid) const override;
};
class ZCDB_PORT ZcDbSectionManagerIterator
{
public:
    virtual ~ZcDbSectionManagerIterator(void);

    void  start                   (void);
    void  step                    (void);
    bool  done                    (void) const;

    ZcDbObjectId      getSection  (void) const;
    Zcad::ErrorStatus getSection  (ZcDbSection*& pSecPlane,
                                             ZcDb::OpenMode openMode) const;

protected:
    ZcDbSectionManagerIterator(ZcDbSectionManager* pMgr);

protected:
    void            *   mpImpObj = nullptr;

    friend class ZcDbImpSectionManager;
};
