/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _SUMMINFO_H_
#define _SUMMINFO_H_

#include "rxobject.h"
#include "GcString.h"

#pragma pack (push, 8)

class GSOFT_NO_VTABLE GCDB_PORT GcDbDatabaseSummaryInfo : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDatabaseSummaryInfo);

  virtual Gcad::ErrorStatus getTitle(GcString & title) const = 0;
  virtual Gcad::ErrorStatus setTitle(const GCHAR* title) = 0;

  virtual Gcad::ErrorStatus getSubject(GcString & subject) const = 0;
  virtual Gcad::ErrorStatus setSubject(const GCHAR* subject) = 0;

  virtual Gcad::ErrorStatus getAuthor(GcString & author) const = 0;
  virtual Gcad::ErrorStatus setAuthor(const GCHAR* author) = 0;

  virtual Gcad::ErrorStatus getKeywords(GcString & keywordlist) const = 0;
  virtual Gcad::ErrorStatus setKeywords(const GCHAR* keywordlist) = 0;

  virtual Gcad::ErrorStatus getComments(GcString & comments) const = 0;
  virtual Gcad::ErrorStatus setComments(const GCHAR* comments) = 0;

  virtual Gcad::ErrorStatus getLastSavedBy(GcString & lastSavedBy) const = 0;
  virtual Gcad::ErrorStatus setLastSavedBy(const GCHAR* lastSavedBy) = 0;

  virtual Gcad::ErrorStatus getRevisionNumber(GcString & revisionNumber) const = 0;
  virtual Gcad::ErrorStatus setRevisionNumber(const GCHAR* revisionNumber) = 0;

  virtual Gcad::ErrorStatus getHyperlinkBase(GcString & HyperlinkBase) const = 0;
  virtual Gcad::ErrorStatus setHyperlinkBase(const GCHAR* HyperlinkBase) = 0;

  virtual int numCustomInfo() const = 0;

  virtual Gcad::ErrorStatus addCustomSummaryInfo(const GCHAR* key, const GCHAR* value) = 0;
  virtual Gcad::ErrorStatus deleteCustomSummaryInfo(int index) = 0;
  virtual Gcad::ErrorStatus deleteCustomSummaryInfo(const GCHAR* key) = 0;

  virtual Gcad::ErrorStatus getCustomSummaryInfo(int index, GcString & key, GcString & value) const = 0;
  virtual Gcad::ErrorStatus setCustomSummaryInfo(int index, const GCHAR* key, const GCHAR *value) = 0;
  virtual Gcad::ErrorStatus getCustomSummaryInfo(const GCHAR *customInfoKey, GcString & value) const = 0;
  virtual Gcad::ErrorStatus setCustomSummaryInfo(const GCHAR *customInfoKey, const GCHAR *value) = 0;

  virtual GcDbDatabase* database() const = 0;

  virtual Gcad::ErrorStatus getTitle(GCHAR*& title) const final;
  virtual Gcad::ErrorStatus getSubject(GCHAR*& subject) const final;
  virtual Gcad::ErrorStatus getAuthor(GCHAR*& author) const final;
  virtual Gcad::ErrorStatus getKeywords(GCHAR*& keywordlist) const final;
  virtual Gcad::ErrorStatus getComments(GCHAR*& comments) const final;
  virtual Gcad::ErrorStatus getLastSavedBy(GCHAR*& lastSavedBy) const final;
  virtual Gcad::ErrorStatus getRevisionNumber(GCHAR*& revisionNumber) const final;
  virtual Gcad::ErrorStatus getHyperlinkBase(GCHAR*& HyperlinkBase) const final;
  virtual Gcad::ErrorStatus getCustomSummaryInfo(int index, GCHAR*& key, GCHAR *& value) const final;
  virtual Gcad::ErrorStatus getCustomSummaryInfo(const GCHAR *customInfoKey, GCHAR *& value) const final;

  ~GcDbDatabaseSummaryInfo() {};
protected:
  GcDbDatabaseSummaryInfo();
private:
  typedef Gcad::ErrorStatus(GcDbDatabaseSummaryInfo::*GetPropGcString)(GcString &) const;
  Gcad::ErrorStatus getGCharString(GetPropGcString pMeth, GCHAR * & rpBuf) const;
};

GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getGCharString(GetPropGcString pMeth, GCHAR * & rpBuf) const
{
  rpBuf = nullptr;
  GcString sTemp;
  const Gcad::ErrorStatus es = (this->*pMeth)(sTemp);
  if (es == Gcad::eOk)
    ::gcutNewString(sTemp.constPtr(), rpBuf);
  return es;
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getTitle(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getTitle, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getSubject(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getSubject, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getAuthor(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getAuthor, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getKeywords(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getKeywords, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getComments(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getComments, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getLastSavedBy(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getLastSavedBy, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getRevisionNumber(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getRevisionNumber, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getHyperlinkBase(GCHAR*& title) const
{
  return this->getGCharString(&GcDbDatabaseSummaryInfo::getHyperlinkBase, title);
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getCustomSummaryInfo(int index, GCHAR*& key, GCHAR *& value) const
{
  GcString sKey, sValue;
  const Gcad::ErrorStatus es = this->getCustomSummaryInfo(index, sKey, sValue);
  if (es == Gcad::eOk)
  {
    ::gcutNewString(sKey.constPtr(), key);
    ::gcutNewString(sValue.constPtr(), value);
  }
  else
    key = value = nullptr;
  return es;
}

inline Gcad::ErrorStatus GcDbDatabaseSummaryInfo::getCustomSummaryInfo(const GCHAR *customInfoKey, GCHAR *& value) const
{
  GcString sValue;
  const Gcad::ErrorStatus es = this->getCustomSummaryInfo(customInfoKey, sValue);
  if (es == Gcad::eOk)
    ::gcutNewString(sValue.constPtr(), value);
  else
    value = nullptr;
  return es;
}

GCDB_PORT Gcad::ErrorStatus gcdbGetSummaryInfo(GcDbDatabase* pDb, GcDbDatabaseSummaryInfo*& pInfo);
GCDB_PORT Gcad::ErrorStatus gcdbPutSummaryInfo(const GcDbDatabaseSummaryInfo* pInfo, GcDbDatabase *pDb);
GCDB_PORT Gcad::ErrorStatus gcdbValidateCustomSummaryInfoKey(const wchar_t* key, const GcDbDatabaseSummaryInfo* pInfo = NULL);

inline Gcad::ErrorStatus gcdbPutSummaryInfo(const GcDbDatabaseSummaryInfo* pInfo)
{
  return ::gcdbPutSummaryInfo(pInfo, pInfo->database());
}

class GSOFT_NO_VTABLE GCDB_PORT GcDbSummaryInfoReactor
{
public:
  virtual void summaryInfoHasChanged(const GcDbDatabase*, const GcDbDatabaseSummaryInfo*)
  {
  };
  virtual ~GcDbSummaryInfoReactor() {};
};

#define GCDB_SUMMINFO_INVALID_CHARACTERS   L"<>/\\\":;?*|,=`"

class GSOFT_NO_VTABLE GcDbSummaryInfoManager
{
public:
  virtual void  addReactor(GcDbSummaryInfoReactor* pReact) = 0;
  virtual void  removeReactor(GcDbSummaryInfoReactor* pReact) = 0;
};

GCDB_PORT GcDbSummaryInfoManager* gcdbSummaryInfoManager();

#pragma pack (pop)
#endif
