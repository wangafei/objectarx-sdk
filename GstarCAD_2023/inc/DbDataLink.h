/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcString.h"

class GcValue;
class GcDbLinkedData;
class GcDbDataLink;
class GcDbDataLinkManager;
class GcDbImpDataLinkManager;
class GcDbDataAdapter;
class GcTableSystemInternals;

#define GCDB_DATA_ADAPTER_EXCEL         GCRX_T("AcExcel")

class GCDB_PORT GcDbDataLink : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDataLink);

  GcDbDataLink(void);
  ~GcDbDataLink(void);

  GcString name(void) const;
  Gcad::ErrorStatus setName(const GCHAR* pszName);
  const GCHAR* description(void) const;
  Gcad::ErrorStatus setDescription(const GCHAR* pszDescription);
  GcString getToolTip(void) const;
  Gcad::ErrorStatus setToolTip(const GCHAR* pszToolTip);
  const GCHAR* dataAdapterId(void) const;
  Gcad::ErrorStatus setDataAdapterId(const GCHAR* pszAdapterId);
  const GCHAR* connectionString(void) const;
  Gcad::ErrorStatus setConnectionString(const GCHAR* pszConnectionString);
  GcDb::DataLinkOption option(void) const;
  Gcad::ErrorStatus setOption(GcDb::DataLinkOption nOption);
  int   updateOption(void) const;
  Gcad::ErrorStatus setUpdateOption(int nOption);
  Gcad::ErrorStatus update(GcDb::UpdateDirection nDir, GcDb::UpdateOption nOption);
  Gcad::ErrorStatus getUpdateStatus(GcDb::UpdateDirection* pDir,
    std::tm* pTime,
    GcString* pErrMessage) const;
  Gcad::ErrorStatus setUpdateStatus(const GCHAR* pszErrMessage);
  bool              isValid(void) const;
  int               getTargets(GcDbObjectIdArray& targetIds) const;
  Gcad::ErrorStatus getSourceFiles(GcDb::DataLinkGetSourceContext nContext, GcStringArray& files) const;
  Gcad::ErrorStatus repathSourceFiles(const wchar_t* pszBasePath, GcDb::PathOption nOption);
  Gcad::ErrorStatus getCustomData(const GCHAR* pszKey, GcValue* pData) const;
  Gcad::ErrorStatus setCustomData(const GCHAR* pszKey, const GcValue* pData);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;
};

typedef GcArray<GcDbDataLink*> GcDbDataLinkArray;

class GCDB_PORT GcDbDataLinkManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDataLinkManager);

  ~GcDbDataLinkManager(void);

  Gcad::ErrorStatus createDataLink(const GCHAR* pszAdapterId,
    const GCHAR* pszName,
    const GCHAR* pszDescription,
    const GCHAR* pszConnectionString,
    GcDbObjectId& idDataLink);
  Gcad::ErrorStatus getDataLink(const GCHAR* pszName, GcDbObjectId& idDataLink) const;
  Gcad::ErrorStatus getDataLink(const GCHAR* pszName,
    GcDbDataLink*& pDataLink,
    GcDb::OpenMode mode) const;
  int   dataLinkCount(void) const;
  int   getDataLink(GcDbObjectIdArray& dataLinks) const;
  Gcad::ErrorStatus addDataLink(GcDbDataLink* pDataLink);
  Gcad::ErrorStatus addDataLink(GcDbDataLink* pDataLink, GcDbObjectId& idDataLink);
  Gcad::ErrorStatus removeDataLink(const GCHAR* pszKey, GcDbObjectId& idDataLink);
  Gcad::ErrorStatus removeDataLink(const GcDbObjectId& idDataLink);

  Gcad::ErrorStatus update(const GcDbObjectIdArray& dataIds,
    GcDb::UpdateDirection nDir,
    GcDb::UpdateOption nOption);
  Gcad::ErrorStatus update(GcDb::UpdateDirection nDir, GcDb::UpdateOption nOption);

protected:
  GcDbDataLinkManager(void);

private:
  void*        mpImpObj;
  friend class GcTableSystemInternals;
  friend class GcDbImpDataLinkManager;
};