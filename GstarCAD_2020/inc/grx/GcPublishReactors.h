#pragma once
#include "rxobject.h"
#include "gcarray.h"
#include "GcPlDSDData.h"
#include "GcPlDSDEntry.h"
#include "gcdmmutils.h"
#include "gcdmmeplotproperty.h"
#include "GcPlPlotErrorHandler.h"
#include "GcPlPlotLogger.h"

class GcNameValuePair
{
public:
  GcNameValuePair()
  {
    m_pName = NULL;
    m_pValue = NULL;
  };

  ~GcNameValuePair()
  {
    if (NULL != m_pName)
      delete[] m_pName;
    if (NULL != m_pValue)
      delete[] m_pValue;
  };

  GcNameValuePair(const GCHAR *name, const GCHAR *value)
  {
    if (NULL != name) {
      size_t nSize = ::wcslen(name) + 1;
      m_pName = new GCHAR[nSize];
      errno_t err = ::wcscpy_s(m_pName, nSize, name);
      assert(err == 0);
    }
    else
      m_pName = NULL;

    if (NULL != value) {
      size_t nSize = ::wcslen(value) + 1;
      m_pValue = new GCHAR[nSize];
      errno_t err = ::wcscpy_s(m_pValue, nSize, value);
      assert(err == 0);
    }
    else
      m_pValue = NULL;
  }

  GcNameValuePair(const GcNameValuePair &src)
    : m_pName(NULL),
    m_pValue(NULL)
  {
    *this = src;
  }

  const GCHAR * name() const { return m_pName; };

  const GCHAR * value() const { return m_pValue; };

  void setName(const GCHAR * name)
  {
    if (NULL != m_pName)
      delete[] m_pName;
    if (NULL != name) {
      size_t nSize = ::wcslen(name) + 1;
      m_pName = new GCHAR[nSize];
      errno_t err = ::wcscpy_s(m_pName, nSize, name);
      assert(err == 0);
    }
    else
      m_pName = NULL;
  }

  void setValue(const GCHAR * value)
  {
    if (NULL != m_pValue)
      delete[] m_pValue;
    if (NULL != value) {
      size_t nSize = ::wcslen(value) + 1;
      m_pValue = new GCHAR[nSize];
      errno_t err = ::wcscpy_s(m_pValue, nSize, value);
      assert(err == 0);
    }
    else
      m_pValue = NULL;
  }

  GcNameValuePair & operator= (const GcNameValuePair &src)
  {
    if (this == &src)
      return *this;

    setName(src.m_pName);
    setValue(src.m_pValue);
    return *this;
  }

private:
  GCHAR * m_pName;
  GCHAR * m_pValue;
};

typedef GcArray<GcNameValuePair> GcNameValuePairVec;

class GcPublishBeforeJobInfo
{
public:

  GcPublishBeforeJobInfo() {};

  virtual ~GcPublishBeforeJobInfo() {};

  virtual const GcPlDSDData * GetDSDData() = 0;

  virtual const GcNameValuePair GetPrivateData(const GCHAR * sectionName) = 0;

  virtual bool WritePrivateSection(const GCHAR * sectionName, const GcNameValuePair nameValuePairVec) = 0;

  virtual bool JobWillPublishInBackground() = 0;
};

class GcPublishBeginJobInfo
{
public:
  GcPublishBeginJobInfo() {};

  virtual ~GcPublishBeginJobInfo() {};

  virtual const GcPlDSDData * GetDSDData() = 0;

  virtual const GcNameValuePair GetPrivateData(const GCHAR * sectionName) = 0;

  virtual bool WritePrivateSection(const GCHAR * sectionName, const GcNameValuePair nameValuePairVec) = 0;

  virtual bool JobWillPublishInBackground() = 0;

  virtual GcPlPlotLogger * GetPlotLogger() = 0;
};

class GcPublishSheetInfo
{
public:
  GcPublishSheetInfo() {};

  virtual ~GcPublishSheetInfo() {};

  virtual const GcPlDSDEntry * GetDSDEntry() = 0;

  virtual const GCHAR * GetUniqueId() = 0;

  virtual GcPlPlotLogger * GetPlotLogger() = 0;
};

class GcPublishAggregationInfo
{
public:
  GcPublishAggregationInfo() {};

  virtual ~GcPublishAggregationInfo() {};

  virtual void AddGlobalProperties(GcDMMEPlotPropertyVec props) = 0;

  virtual void AddGlobalResources(GcDMMResourceVec resources) = 0;

  virtual GcPlPlotLogger * GetPlotLogger() = 0;

  virtual const GCHAR* dwfFileName() = 0;

  virtual const GCHAR* dwfPassword() = 0;
};

class GcPublishReactorInfo
{
public:
  GcPublishReactorInfo() {};

  virtual ~GcPublishReactorInfo() {};

  virtual const GCHAR* dwfFileName() = 0;

  virtual const GCHAR* tempDwfFileName() = 0;

  virtual const GCHAR* dwfPassword() = 0;

  virtual bool isMultiSheetDwf() = 0;
};

class GcPublishReactor : public OdRxObject
{
public:
  virtual void OnAboutToBeginBackgroundPublishing(GcPublishBeforeJobInfo * pInfo);

  virtual void OnAboutToBeginPublishing(GcPublishBeginJobInfo *pInfo);

  virtual void OnBeginPublishingSheet(GcPublishSheetInfo *pInfo);

  virtual void OnBeginAggregation(GcPublishAggregationInfo *pInfo);

  virtual void OnAboutToEndPublishing(GcPublishReactorInfo *pInfo);

  virtual void OnAboutToMoveFile(GcPublishReactorInfo *pInfo);

  virtual void OnEndPublish(GcPublishReactorInfo *pInfo);

  virtual void OnCancelledOrFailedPublishing(GcPublishReactorInfo *pInfo);

  virtual ~GcPublishReactor() {};
protected:
  GcPublishReactor() {};
};

inline void
GcPublishReactor::OnAboutToBeginBackgroundPublishing(GcPublishBeforeJobInfo * pInfo) {};

inline void
GcPublishReactor::OnAboutToBeginPublishing(GcPublishBeginJobInfo *pInfo) {};

inline void
GcPublishReactor::OnBeginPublishingSheet(GcPublishSheetInfo *pInfo) {};

inline void
GcPublishReactor::OnBeginAggregation(GcPublishAggregationInfo *pInfo) {};

inline void
GcPublishReactor::OnAboutToEndPublishing(GcPublishReactorInfo *pInfo) {};

inline void
GcPublishReactor::OnAboutToMoveFile(GcPublishReactorInfo *pInfo) {};

inline void
GcPublishReactor::OnEndPublish(GcPublishReactorInfo *pInfo) {};

inline void
GcPublishReactor::OnCancelledOrFailedPublishing(GcPublishReactorInfo * pInfo) {};

GCPL_PORT void    GcGlobAddPublishReactor(GcPublishReactor *pReactor);

GCPL_PORT void    GcGlobRemovePublishReactor(GcPublishReactor *pReactor);

typedef void(__cdecl * GCGLOBADDPUBLISHREACTOR)(GcPublishReactor * pReactor);
typedef void(__cdecl * GCGLOBREMOVEPUBLISHREACTOR)(GcPublishReactor * pReactor);



