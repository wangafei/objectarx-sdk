

#pragma once

#include "zAcString.h"

class ZcValue;
class ZcDbLinkedData;
class ZcDbDataLink;
class ZcDbDataLinkManager;
class ZcDbImpDataLinkManager;
class ZcDbDataAdapter;
class ZcTableSystemInternals;


#define ZCDB_DATA_ADAPTER_EXCEL         ZCRX_T("AcExcel")  

class ZCDB_PORT ZcDbDataLink : public ZcDbObject
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbDataLink);

    ZcDbDataLink(void);
    virtual ~ZcDbDataLink(void);

    ZcString name                 (void) const;
    Zcad::ErrorStatus setName     (const ZTCHAR* pszName);
    const ZTCHAR* description      (void) const;
    Zcad::ErrorStatus setDescription(const ZTCHAR* pszDescription);
    ZcString getToolTip           (void) const;
    Zcad::ErrorStatus setToolTip  (const ZTCHAR* pszToolTip);
    const ZTCHAR* dataAdapterId    (void) const;
    Zcad::ErrorStatus setDataAdapterId(const ZTCHAR* pszAdapterId);
    const ZTCHAR* connectionString (void) const;
    Zcad::ErrorStatus setConnectionString(const ZTCHAR* pszConnectionString);
    ZcDb::DataLinkOption option   (void) const;
    Zcad::ErrorStatus setOption   (ZcDb::DataLinkOption nOption);
    int   updateOption            (void) const;
    Zcad::ErrorStatus setUpdateOption(int nOption);
    Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);
    Zcad::ErrorStatus getUpdateStatus(ZcDb::UpdateDirection* pDir, 
                                             std::tm* pTime,	 
                                             ZcString* pErrMessage) const;
    Zcad::ErrorStatus setUpdateStatus(const ZTCHAR* pszErrMessage);
    bool  isValid                 (void) const;
    int   getTargets              (ZcDbObjectIdArray& targetIds) const;
    Zcad::ErrorStatus getSourceFiles(ZcDb::DataLinkGetSourceContext nContext, 
                                             ZcStringArray& files) const;
    Zcad::ErrorStatus repathSourceFiles(/*LPCTSTR*/const wchar_t* pszBasePath,		
                                             ZcDb::PathOption nOption);
    Zcad::ErrorStatus getCustomData(const ZTCHAR* pszKey, 
                                             ZcValue* pData) const;
    Zcad::ErrorStatus setCustomData(const ZTCHAR* pszKey, 
                                             const ZcValue* pData);

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;
};

typedef ZcArray<ZcDbDataLink*> ZcDbDataLinkArray;

class ZCDB_PORT ZcDbDataLinkManager : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDataLinkManager);

    virtual ~ZcDbDataLinkManager(void);

    Zcad::ErrorStatus createDataLink(const ZTCHAR* pszAdapterId, 
                                             const ZTCHAR* pszName, 
                                             const ZTCHAR* pszDescription, 
                                             const ZTCHAR* pszConnectionString, 
                                             ZcDbObjectId& idDataLink);
    Zcad::ErrorStatus getDataLink (const ZTCHAR* pszName, 
                                             ZcDbObjectId& idDataLink) const;
    Zcad::ErrorStatus getDataLink (const ZTCHAR* pszName, 
                                             ZcDbDataLink*& pDataLink, 
                                             ZcDb::OpenMode mode) const;
    int   dataLinkCount           (void) const;
    int   getDataLink             (ZcDbObjectIdArray& dataLinks) const;
    Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink);
    Zcad::ErrorStatus addDataLink (ZcDbDataLink* pDataLink, 
                                             ZcDbObjectId& idDataLink);
    Zcad::ErrorStatus removeDataLink        (const ZTCHAR* pszKey, 
                                             ZcDbObjectId& idDataLink);
    Zcad::ErrorStatus removeDataLink(const ZcDbObjectId& idDataLink);

    Zcad::ErrorStatus update      (const ZcDbObjectIdArray& dataIds, 
                                             ZcDb::UpdateDirection nDir,
                                             ZcDb::UpdateOption nOption);
    Zcad::ErrorStatus update      (ZcDb::UpdateDirection nDir, 
                                             ZcDb::UpdateOption nOption);

protected:
    ZcDbDataLinkManager(void);

private:
    void        *   mpImpObj;
    friend class ZcTableSystemInternals;
    friend class ZcDbImpDataLinkManager;
};
