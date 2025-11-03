/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef _appinfo_h
#define _appinfo_h 1

#include "rxobject.h"
#include "GdGChar.h"
#include "rxdlinkr.h"

#pragma pack (push, 8)

class GcadAppInfoImp;

class GCCORE_PORT GcadAppInfo : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcadAppInfo);

  enum CmdStatus {
    kNoAction = 0,
    kRetry = 1,
    kShowMsg = 2,
    kNoModule = 3
  };
  enum MgdType {
    kUnManaged = 0,
    kManaged = 1,
    kJavaScript = 2
  };
  enum ReadFlags
  {
    kNone = 0,
    kSkipFindFileForModuleName = 1
  };
  typedef GcadAppInfo::CmdStatus(*LoaderFunPtr)(void *);

  GcadAppInfo();
  ~GcadAppInfo();

  const GCHAR *appName() const;
  void setAppName(const GCHAR *);

  const GCHAR *moduleName() const;
  void setModuleName(const GCHAR *);

  const GCHAR *appDesc() const;
  void setAppDesc(const GCHAR *);

  bool appImplements(const GCHAR *) const;

  GcadAppInfo::MgdType managed() const;
  void setManaged(GcadAppInfo::MgdType mgdType);

  GcadApp::ErrorStatus writeToRegistry();

  GcadApp::ErrorStatus readFromRegistry();
  GcadApp::ErrorStatus readFromRegistry(ReadFlags flags);
  GcadApp::ErrorStatus delFromRegistry();

  GcadAppInfo::CmdStatus runAppLoader();
  void setAppLoader(LoaderFunPtr);

  GcadApp::LoadReasons loadReason() const;
  void setLoadReason(GcadApp::LoadReasons);
  GcadApp::ErrorStatus status() const;

  GcadApp::ErrorStatus writeGroupNameToRegistry(const GCHAR* group);
  GcadApp::ErrorStatus writeCommandNameToRegistry(const GCHAR* globalCmdName, const GCHAR* localCmdName);
protected:
  GcadAppInfoImp * mpImp;
};

#pragma pack (pop)
#endif 