

#ifndef _ZCPUBLISHREACTORS_H
#define _ZCPUBLISHREACTORS_H

#include "zrxobject.h"
#include "zacarray.h"
#include "zacpldsddata.h"
#include "zacpldsdentry.h"
#include "zacdmmutils.h"
#include "zacdmmeplotproperty.h"
#include "zacplploterrorhandler.h"
#include "zacplplotlogger.h"

class ZcPublishReactorManager;
class ZcPublishReactor;
class ZcPublishReactorInfo;

class ZcPublishBeginJobInfo;
class ZcPublishSheetInfo;

class ZcNameValuePair
{
public:
    ZcNameValuePair()
    {
        m_pName = NULL;
        m_pValue = NULL;
    };
    ~ZcNameValuePair()
    {
        if (NULL != m_pName)
            delete [] m_pName;
        if (NULL != m_pValue)
            delete [] m_pValue;
    };
    ZcNameValuePair(const ZTCHAR *name, const ZTCHAR *value)
    {
        if (NULL != name) {
            size_t nSize = ::wcslen(name) + 1;
            m_pName = new ZTCHAR[nSize];
            errno_t err = ::wcscpy_s(m_pName, nSize, name);
            assert(err == 0);
        } else
            m_pName = NULL;

        if (NULL != value) {
            size_t nSize = ::wcslen(value) + 1;
            m_pValue = new ZTCHAR[nSize];
            errno_t err = ::wcscpy_s(m_pValue, nSize, value);
            assert(err == 0);
        } else
            m_pValue = NULL;
    }
    ZcNameValuePair(const ZcNameValuePair &src)
    : m_pName(NULL),
      m_pValue(NULL)
    {
        *this = src;
    }
    const ZTCHAR * name() const {return m_pName;};
    const ZTCHAR * value() const {return m_pValue;};
    void setName(const ZTCHAR * name)
    {
        if (NULL != m_pName)
            delete [] m_pName;
        if (NULL != name) {
            size_t nSize = ::wcslen(name) + 1;
            m_pName = new ZTCHAR[nSize];
            errno_t err = ::wcscpy_s(m_pName, nSize, name);
            assert(err == 0);
        } else
            m_pName = NULL;
    }
    void setValue(const ZTCHAR * value)
    {
        if (NULL != m_pValue)
            delete [] m_pValue;
        if (NULL != value) {
            size_t nSize = ::wcslen(value) + 1;
            m_pValue = new ZTCHAR[nSize];
            errno_t err = ::wcscpy_s(m_pValue, nSize, value);
            assert(err == 0);
        } else
            m_pValue = NULL;
    }
    ZcNameValuePair & operator= (const ZcNameValuePair &src)
    {
        if (this == &src)
            return *this;

        setName(src.m_pName);
        setValue(src.m_pValue);
        return *this;
    }

private:
    ZTCHAR * m_pName;
    ZTCHAR * m_pValue;
};

typedef ZcArray<ZcNameValuePair> ZcNameValuePairVec;

class ZcPublishBeforeJobInfo
{
public:
    ZcPublishBeforeJobInfo() {};
    virtual ~ZcPublishBeforeJobInfo() {};
    virtual const ZcPlDSDData * GetDSDData() = 0;
    virtual const ZcNameValuePairVec
        GetPrivateData(const ZTCHAR * sectionName) = 0;
    virtual bool WritePrivateSection(const ZTCHAR * sectionName,
        const ZcNameValuePairVec nameValuePairVec) = 0;
    virtual bool JobWillPublishInBackground() = 0;
};

class ZcPublishBeginJobInfo
{
public:
    ZcPublishBeginJobInfo() {};
    virtual ~ZcPublishBeginJobInfo() {};
    virtual const ZcPlDSDData * GetDSDData() = 0;
    virtual const ZcNameValuePairVec
        GetPrivateData(const ZTCHAR * sectionName) = 0;
    virtual bool WritePrivateSection(const ZTCHAR * sectionName,
        const ZcNameValuePairVec nameValuePairVec) = 0;
    virtual bool JobWillPublishInBackground() = 0;
    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
};

class ZcPublishSheetInfo
{
public:
    ZcPublishSheetInfo() {};
    virtual ~ZcPublishSheetInfo() {};
    virtual const ZcPlDSDEntry * GetDSDEntry() = 0;
    virtual const ZTCHAR * GetUniqueId() = 0;
    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
};

class ZcPublishAggregationInfo
{
public:
    ZcPublishAggregationInfo() {};
    virtual ~ZcPublishAggregationInfo() {};
    virtual void AddGlobalProperties(ZcDMMEPlotPropertyVec props) = 0;
    virtual void AddGlobalResources(ZcDMMResourceVec resources) = 0;
    virtual ZcPlPlotLogger * GetPlotLogger() = 0;
    virtual const ZTCHAR* dwfFileName() = 0;
    virtual const ZTCHAR* dwfPassword() = 0;
};

class ZcPublishReactorInfo
{
public:
    ZcPublishReactorInfo() {};
    virtual ~ZcPublishReactorInfo() {};

    virtual const ZTCHAR* dwfFileName() = 0;
    virtual const ZTCHAR* tempDwfFileName() = 0;
    virtual const ZTCHAR* dwfPassword() = 0;

    virtual bool isMultiSheetDwf() = 0;
};

class ZcPublishReactor : public ZcRxObject
{
public:
    virtual void OnAboutToBeginBackgroundPublishing(ZcPublishBeforeJobInfo
        *pInfo);
    virtual void OnAboutToBeginPublishing(ZcPublishBeginJobInfo *pInfo);
    virtual void OnBeginPublishingSheet(ZcPublishSheetInfo *pInfo);
    virtual void OnBeginAggregation(ZcPublishAggregationInfo *pInfo);
    virtual void OnAboutToEndPublishing(ZcPublishReactorInfo *pInfo);
    virtual void OnAboutToMoveFile(ZcPublishReactorInfo *pInfo);
    virtual void OnEndPublish(ZcPublishReactorInfo *pInfo);
    virtual void OnCancelledOrFailedPublishing(ZcPublishReactorInfo *pInfo);

    virtual ~ZcPublishReactor() {};

protected:

    ZcPublishReactor() {};
};

inline void
    ZcPublishReactor::OnAboutToBeginBackgroundPublishing(ZcPublishBeforeJobInfo
    *pInfo) {};

inline void
    ZcPublishReactor::OnAboutToBeginPublishing(ZcPublishBeginJobInfo *pInfo) {};

inline void
    ZcPublishReactor::OnBeginPublishingSheet(ZcPublishSheetInfo *pInfo) {};

inline void
    ZcPublishReactor::OnBeginAggregation(ZcPublishAggregationInfo *pInfo) {};

inline void
    ZcPublishReactor::OnAboutToEndPublishing(ZcPublishReactorInfo *pInfo) {};

inline void
    ZcPublishReactor::OnAboutToMoveFile(ZcPublishReactorInfo *pInfo) {};

inline void
    ZcPublishReactor::OnEndPublish(ZcPublishReactorInfo *pInfo) {};

inline void
    ZcPublishReactor::OnCancelledOrFailedPublishing(ZcPublishReactorInfo
    *pInfo) {};

void ZcGlobAddPublishReactor(ZcPublishReactor *pReactor);

void ZcGlobRemovePublishReactor(ZcPublishReactor *pReactor);

typedef void (__cdecl * ZCGLOBADDPUBLISHREACTOR)(ZcPublishReactor * pReactor);
typedef void (__cdecl * ZCGLOBREMOVEPUBLISHREACTOR)(ZcPublishReactor * pReactor);

#endif

