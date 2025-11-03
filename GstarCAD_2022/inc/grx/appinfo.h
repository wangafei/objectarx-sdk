#ifndef GCADAPPINFO_INCLUDED
#define GCADAPPINFO_INCLUDED

#include "gcadstd.h"
#include "gcdb.h"
#include "rxdlinkr.h"

class GcadAppInfoImp;


#pragma pack (push, 8)

class GcadAppInfo: public GcRxObject
{
public:
    GCRX_DECLARE_MEMBERS(GcadAppInfo);

    enum CmdStatus {
        kNoAction    = 0,
        kRetry       = 1,
        kShowMsg     = 2,
        kNoModule    = 3
    };
    typedef GcadAppInfo::CmdStatus (*LoaderFunPtr)(void *);

    GcadAppInfo();
    virtual ~GcadAppInfo();

    const GCHAR *appName() const;
    void setAppName(const GCHAR *);

    const GCHAR *moduleName() const;
    void setModuleName(const GCHAR *);

    const GCHAR *appDesc() const;
    void setAppDesc(const GCHAR *);

    bool appImplements(const GCHAR *) const;
    bool managed() const
    {
      throw OdError(eNotImplemented);
      return false;
    }
    void setManaged(bool bManaged)
    {
      throw OdError(eNotImplemented);
    }

    GcadApp::ErrorStatus writeToRegistry(bool bObjDbx = false, bool skipHKLM = false);

    GcadApp::ErrorStatus readFromRegistry();
    GcadApp::ErrorStatus delFromRegistry(bool bObjDbx = false);

    GcadAppInfo::CmdStatus runAppLoader();
    void setAppLoader(LoaderFunPtr);

    GcadApp::LoadReasons loadReason();
    void setLoadReason(GcadApp::LoadReasons);
    GcadApp::ErrorStatus status() const;

    GcadApp::ErrorStatus writeGroupNameToRegistry(const GCHAR* group);

    GcadApp::ErrorStatus writeCommandNameToRegistry(const GCHAR* globalCmdName,
													const GCHAR* localCmdName);

    virtual void addRef() {}
    virtual void release(){}

private:
    GcadAppInfoImp * mpImp;
};

#pragma pack (pop)

#endif //GCADAPPINFO_INCLUDED

