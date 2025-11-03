/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCPUBLISHUIREACTORS_H
#define _GCPUBLISHUIREACTORS_H

#include "GdGChar.h"
#include "gcpublishreactors.h"
#include "rxobject.h"
#include "gcarray.h"
#include "GcPlDSDData.h"

#include "gcpublishreactors.h"

class GcPublishUIReactorInfo
{
public:
  GcPublishUIReactorInfo() {};
  virtual ~GcPublishUIReactorInfo() {};

  virtual const GcPlDSDData * GetDSDData() = 0;
  virtual const GcNameValuePairVec
    GetPrivateData(const GCHAR * sectionName) = 0;
  virtual bool WritePrivateSection(const GCHAR * sectionName,
    const GcNameValuePairVec nameValuePairVec) = 0;
  virtual bool JobWillPublishInBackground() = 0;
};

class GcPublishUIReactor : public GcRxObject
{
public:
  virtual void OnInitPublishOptionsDialog(IUnknown **pUnk,
    GcPublishUIReactorInfo *pInfo);
  virtual void OnInitExportOptionsDialog(IUnknown **pUnk,
    GcPublishUIReactorInfo *pInfo);

  virtual void PersistenceRegistryForExportOptionsDialog(const GCHAR* lpszRegRoot,
    bool bIsReadRegistry = true);
  virtual void OnInitAutoPublishSettingsDialog(IUnknown **pUnk,
    GcPublishUIReactorInfo *pInfo);
  virtual void PersistenceRegistryForAutoPublishDialog(const GCHAR* lpszRegRoot,
    bool bIsReadRegistry = true);

  ~GcPublishUIReactor() {};

protected:
  GcPublishUIReactor() {};
};

inline void
GcPublishUIReactor::OnInitPublishOptionsDialog(IUnknown **pUnk,
  GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::OnInitExportOptionsDialog(IUnknown **pUnk,
  GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::PersistenceRegistryForExportOptionsDialog(const GCHAR* lpszRegRoot,
  bool bIsReadRegistry)
{
}

inline void
GcPublishUIReactor::OnInitAutoPublishSettingsDialog(IUnknown **pUnk,
  GcPublishUIReactorInfo *pInfo)
{
}

inline void
GcPublishUIReactor::PersistenceRegistryForAutoPublishDialog(const GCHAR* lpszRegRoot,
  bool bIsReadRegistry)
{
}

class GcPublishUIReactor2 : public GcPublishUIReactor
{
public:
  virtual void PersistenceRegistryForPubishOptionsDialog(const GCHAR* lpszRegRoot,
    bool bIsReadRegistry = true) {}
  virtual ~GcPublishUIReactor2() {}

protected:
  GcPublishUIReactor2() {}
};

GCCORE_PORT void GcGlobAddPublishUIReactor(GcPublishUIReactor *pReactor);
GCCORE_PORT void GcGlobRemovePublishUIReactor(GcPublishUIReactor *pReactor);

typedef void(__cdecl * GCGLOBADDPUBLISHUIREACTOR)(GcPublishUIReactor * pReactor);
typedef void(__cdecl * GCGLOBREMOVEPUBLISHUIREACTOR)(GcPublishUIReactor * pReactor);

#endif
