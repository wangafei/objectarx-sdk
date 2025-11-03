

#ifndef _ZSUMMINFO_H_
#define _ZSUMMINFO_H_

#include "zrxobject.h"
#include "zAcString.h"


#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbDatabaseSummaryInfo : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDatabaseSummaryInfo);

	virtual Zcad::ErrorStatus getTitle(ZcString& title) const = 0;
    virtual Zcad::ErrorStatus setTitle(const ZTCHAR* title) = 0;

	virtual Zcad::ErrorStatus getSubject(ZcString& subject) const = 0;
    virtual Zcad::ErrorStatus setSubject(const ZTCHAR* subject) = 0;

	virtual Zcad::ErrorStatus getAuthor(ZcString& author) const = 0;
    virtual Zcad::ErrorStatus setAuthor(const ZTCHAR* author) = 0;

	virtual Zcad::ErrorStatus getKeywords(ZcString& keywordlist) const = 0;
    virtual Zcad::ErrorStatus setKeywords(const ZTCHAR* keywordlist) = 0;

	virtual Zcad::ErrorStatus getComments(ZcString& comments) const = 0;
    virtual Zcad::ErrorStatus setComments(const ZTCHAR* comments) = 0;

	virtual Zcad::ErrorStatus getLastSavedBy(ZcString& lastSavedBy) const = 0;
    virtual Zcad::ErrorStatus setLastSavedBy(const ZTCHAR* lastSavedBy) = 0;

	virtual Zcad::ErrorStatus getRevisionNumber(ZcString& revisionNumber) const = 0;
    virtual Zcad::ErrorStatus setRevisionNumber(const ZTCHAR* revisionNumber) = 0;

	virtual Zcad::ErrorStatus getHyperlinkBase(ZcString& HyperlinkBase) const = 0;
    virtual Zcad::ErrorStatus setHyperlinkBase(const ZTCHAR* HyperlinkBase) = 0;

    virtual int numCustomInfo() const = 0;

    virtual Zcad::ErrorStatus addCustomSummaryInfo(const ZTCHAR* key, const ZTCHAR* value ) = 0;

	virtual Zcad::ErrorStatus deleteCustomSummaryInfo(int index) = 0;
    virtual Zcad::ErrorStatus deleteCustomSummaryInfo(const ZTCHAR* key) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(int index, ZcString& key,
                               ZcString& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (int index, const ZTCHAR* key,
                               const ZTCHAR *value ) = 0;

    virtual Zcad::ErrorStatus getCustomSummaryInfo(const ZTCHAR *customInfoKey,
                               ZcString& value ) const = 0;

    virtual Zcad::ErrorStatus setCustomSummaryInfo (const ZTCHAR *customInfoKey,
                               const ZTCHAR *value ) = 0;

    virtual ZcDbDatabase* database() const = 0; 
    virtual void setDatabase(ZcDbDatabase *pDb) = 0;


	virtual Zcad::ErrorStatus getTitle(ZTCHAR*& title) const final;
	virtual Zcad::ErrorStatus getSubject(ZTCHAR*& subject) const final;
	virtual Zcad::ErrorStatus getAuthor(ZTCHAR*& author) const final;
	virtual Zcad::ErrorStatus getKeywords(ZTCHAR*& keywordlist) const final;
	virtual Zcad::ErrorStatus getComments(ZTCHAR*& comments) const final;
	virtual Zcad::ErrorStatus getLastSavedBy(ZTCHAR*& lastSavedBy) const final;
	virtual Zcad::ErrorStatus getRevisionNumber(ZTCHAR*& revisionNumber) const final;
	virtual Zcad::ErrorStatus getHyperlinkBase(ZTCHAR*& HyperlinkBase) const final;
	virtual Zcad::ErrorStatus getCustomSummaryInfo(const int index, ZTCHAR*& key,
			ZTCHAR *& value ) const final;
	virtual Zcad::ErrorStatus getCustomSummaryInfo(const ZTCHAR *customInfoKey,
			ZTCHAR *& value) const final;

    virtual ~ZcDbDatabaseSummaryInfo() {};
  protected:
    ZcDbDatabaseSummaryInfo();
  private:
    typedef Zcad::ErrorStatus (ZcDbDatabaseSummaryInfo::*GetPropZcString)(ZcString &) const;
    Zcad::ErrorStatus getACharString(GetPropZcString pMeth, ZTCHAR * & rpBuf) const;
};


Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbGetSummaryInfo(
                                 ZcDbDatabase* pDb, 
                                 ZcDbDatabaseSummaryInfo*& pInfo);

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo,
                                ZcDbDatabase *pDb);

ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbValidateCustomSummaryInfoKey(
                                const wchar_t* key, 
                                const ZcDbDatabaseSummaryInfo* pInfo = NULL);
inline Zcad::ErrorStatus zcdbPutSummaryInfo(
                                const ZcDbDatabaseSummaryInfo* pInfo)
{
    return ::zcdbPutSummaryInfo(pInfo, pInfo->database());
}

class ZSOFT_NO_VTABLE ZcDbSummaryInfoReactor {
public:
    virtual void summaryInfoHasChanged(
                     const ZcDbDatabase* , 
                     const ZcDbDatabaseSummaryInfo* ) {};
    virtual ~ZcDbSummaryInfoReactor() {};
};

#define ZCDB_SUMMINFO_INVALID_CHARACTERS   L"<>/\\\":;?*|,=`"
class ZSOFT_NO_VTABLE ZcDbSummaryInfoManager {
public:
    virtual void  addReactor(ZcDbSummaryInfoReactor* pReact) = 0;
    virtual void  removeReactor(ZcDbSummaryInfoReactor* pReact) = 0;
};


ZCDBCORE2D_PORT ZcDbSummaryInfoManager* zcdbSummaryInfoManager();


#pragma pack (pop)
#endif 


