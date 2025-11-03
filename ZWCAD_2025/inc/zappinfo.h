
#pragma  once
#ifndef _zappinfo_h
#define _zappinfo_h 1

#include "zrxobject.h"
#include "zAdAChar.h"
#include "zrxdlinkr.h"	


#pragma pack (push, 8)

class ZcadAppInfoImp;

class ZCBASE_PORT ZcadAppInfo: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcadAppInfo);

    enum CmdStatus {
        kNoAction    = 0,
        kRetry       = 1,
        kShowMsg     = 2,
        kNoModule    = 3
    };
	enum MgdType {
		kUnManaged   = 0,
		kManaged     = 1,
		kJavaScript  = 2
	};
	enum ReadFlags
	{
		kNone = 0, 
		kSkipFindFileForModuleName = 1 
	};

    typedef ZcadAppInfo::CmdStatus (*LoaderFunPtr)(void *);

    ZcadAppInfo();
    virtual ~ZcadAppInfo();

    const ZTCHAR *appName() const;
    void setAppName(const ZTCHAR *);

    const ZTCHAR *moduleName() const;
    void setModuleName(const ZTCHAR *);

    const ZTCHAR *appDesc() const;
    void setAppDesc(const ZTCHAR *);

    bool appImplements(const ZTCHAR *) const;
    
    ZcadAppInfo::MgdType managed() const;
    void setManaged(ZcadAppInfo::MgdType mgdType);

	ZcadApp::ErrorStatus writeToRegistry();		

	ZcadApp::ErrorStatus readFromRegistry();
    
	ZcadApp::ErrorStatus readFromRegistry(ReadFlags flags);	
	
	ZcadApp::ErrorStatus delFromRegistry();	

    ZcadAppInfo::CmdStatus runAppLoader();
    void setAppLoader(LoaderFunPtr);

    ZcadApp::LoadReasons loadReason() const ;	
    void setLoadReason(ZcadApp::LoadReasons);
    ZcadApp::ErrorStatus status() const;

    ZcadApp::ErrorStatus writeGroupNameToRegistry(const ZTCHAR* group);

    ZcadApp::ErrorStatus writeCommandNameToRegistry(const ZTCHAR* globalCmdName,
                                                    const ZTCHAR* localCmdName);
    
protected:
    ZcadAppInfoImp * mpImp;
};

#pragma pack (pop)

#endif 

