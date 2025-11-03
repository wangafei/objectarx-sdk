#pragma once
#include "gchar.h"
#include "GcPublishReactors.h"
#include "rxobject.h"
#include "GcPlDSDData.h"

class GcPublishUIReactorInfo
{
public:
  GcPublishUIReactorInfo() {}

  virtual ~GcPublishUIReactorInfo() {}

  virtual const GcPlDSDData * GetDSDData() = 0;

  virtual const GcNameValuePairVec GetPrivateData(const OdChar * sectionName) = 0;

  virtual bool WritePrivateSection(const OdChar * sectionName, const GcNameValuePairVec nameValuePairVec) = 0;

  virtual bool JobWillPublishInBackground() = 0;
};

struct  IUnknown;
class GcPublishUIReactor : public GcRxObject
{
public:
  virtual void OnInitPublishOptionsDialog(IUnknown **pUnk, GcPublishUIReactorInfo *pInfo);

  virtual void OnInitExportOptionsDialog(IUnknown **pUnk, GcPublishUIReactorInfo *pInfo);

  virtual void PersistenceRegistryForExportOptionsDialog(const OdChar* lpszRegRoot, bool bIsReadRegistry = true);

  virtual void OnInitAutoPublishSettingsDialog(IUnknown **pUnk, GcPublishUIReactorInfo *pInfo);

  virtual void PersistenceRegistryForAutoPublishDialog(const OdChar* lpszRegRoot, bool bIsReadRegistry = true);

	virtual ~GcPublishUIReactor() {}

protected:
	GcPublishUIReactor() {}
};

inline void
GcPublishUIReactor::OnInitPublishOptionsDialog(IUnknown **pUnk,GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::OnInitExportOptionsDialog(IUnknown **pUnk,GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::PersistenceRegistryForExportOptionsDialog(const OdChar* lpszRegRoot,bool bIsReadRegistry)
{
}

inline void
GcPublishUIReactor::OnInitAutoPublishSettingsDialog(IUnknown **pUnk,GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::PersistenceRegistryForAutoPublishDialog(const OdChar* lpszRegRoot,bool bIsReadRegistry)
{
}

GCPL_PORT void GcGlobAddPublishUIReactor(GcPublishUIReactor *pReactor);

GCPL_PORT void GcGlobRemovePublishUIReactor(GcPublishUIReactor *pReactor);

typedef void(__cdecl * GCGLOBADDPUBLISHUIREACTOR)(GcPublishUIReactor * pReactor);
typedef void(__cdecl * GCGLOBREMOVEPUBLISHUIREACTOR)(GcPublishUIReactor * pReactor);
