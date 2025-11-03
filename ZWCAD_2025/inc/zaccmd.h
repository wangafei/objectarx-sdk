

#ifndef   _ZCCMD_H
#define   _ZCCMD_H

#include "zadesk.h"
#include "zAdAChar.h"
#include "zaccmd-defs.h"
#include "zrxresource.h"
#include "zaccoredefs.h"


#define ZCRX_COMMAND_DOCK  	ZCRX_T("ZCAD_REGISTERED_COMMANDS")

typedef void (*ZcRxFunctionPtr) ();

#ifdef _ZSOFT_WINDOWS_
#include <wtypes.h>   
#endif

#pragma pack (push, 8)
class ZcEdCommand;

struct ZcEdCommandStruc {
    ZcRxFunctionPtr fcnAddr;
    long            flags;
    void	        *app;
	HINSTANCE     hResHandle; 
	ZcEdCommand		*cmd;
};
#pragma pack (pop)

#if defined(__cplusplus)

#include "zdbmain.h"
#include "zrxobject.h"

class ZcRxDictionary;
class ZcEdUIContext;
class ZcEdCommandReactor;

#pragma pack (push, 8)
class ZcEdCommand: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommand);

    virtual void            commandUndef(bool undefIt) = 0;
    virtual ZSoft::Int32    commandFlags() const = 0;
    virtual ZcRxFunctionPtr functionAddr() const = 0;
    virtual void            functionAddr(ZcRxFunctionPtr fhdl) = 0;
    virtual void            *commandApp() const = 0;
    virtual ZcEdUIContext   *UIContext() const = 0;
    virtual int             functionCode() const = 0;
    virtual void            functionCode(int fcode) = 0;

    virtual const ZTCHAR *   globalName() const = 0;
    virtual const ZTCHAR *   localName() const = 0;

    virtual const HINSTANCE resourceHandle() const = 0;
    virtual const ZcRxResourceInstance& resourceInstance() const = 0;
	
	ZCCORE_PORT void addReactor(ZcEdCommandReactor* pReator); 
	ZCCORE_PORT void removeReactor(ZcEdCommandReactor* pReactor);   

	ZCCORE_PORT ZSoft::UInt8 defaultCommandVersion() const; 

};





enum ZcEdCommandStatusFlags
{
    kCmdStatusNone   = 0x00000,
    kCmdStatusCancel = 0x00001,
    kCmdStatusFailed = 0x00002,
};

ZcEdCommandStatusFlags& operator|=(ZcEdCommandStatusFlags& f, int i);
ZcEdCommandStatusFlags& operator&=(ZcEdCommandStatusFlags& f, int i);

class ZcEdImpCommandEventArgs;
class ZcEdCommandEventArgs
{
public:
    const ZTCHAR* groupName() const;
    ZcEdCommandStatusFlags status() const;
    void setStatus(ZcEdCommandStatusFlags flags);

protected:
    friend class ZcEdImpCommandEventArgs;
    ZcEdImpCommandEventArgs* m_pImp;

    ZcEdCommandEventArgs(ZcEdImpCommandEventArgs* pImp);
    ZcEdCommandEventArgs(const ZcEdCommandEventArgs& other);
    ZcEdCommandEventArgs& operator=(const ZcEdCommandEventArgs& other);
};

class ZcEdCommandReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandReactor);
    ZCCORE_PORT virtual ~ZcEdCommandReactor();

    virtual void commandWillStart(ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
    virtual void commandEnded(ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
    virtual void goodbye(ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
};

class ZcEdCommandStackReactor: public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandStackReactor);
    ZCCORE_PORT virtual ~ZcEdCommandStackReactor();

    virtual void commandAdded(    ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
    virtual void commandRemoved(  ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
    virtual void commandWillStart( ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
    virtual void commandEnded( ZcEdCommand* pCmd, ZcEdCommandEventArgs* data);
};




class ZcEdCommandIterator: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandIterator);

    virtual bool               done() const = 0;
    virtual bool               next() = 0;
    virtual const ZcEdCommand* command() const = 0;
    virtual const ZTCHAR *      commandGroup() const = 0;
};

#define zcedRegCmds \
ZcEdCommandStack::cast(zcrxSysRegistry()->at(ZCRX_COMMAND_DOCK))

class ZcEdCommandStack: public ZcRxObject 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdCommandStack);

    virtual bool              atPut(const ZTCHAR * cmdGroupName,
                                    ZcRxDictionary*& cmdsGlobal,
                                    ZcRxDictionary*& cmdsLocal) = 0;

    virtual Zcad::ErrorStatus addCommand(const ZTCHAR * cmdGroupName,
                                         const ZTCHAR * cmdGlobalName,
                                         const ZTCHAR * cmdLocalName,
                                         ZSoft::Int32 commandFlags,
                                         ZcRxFunctionPtr FunctionAddr,
                                         ZcEdUIContext *UIContext /*= NULL*/,
                                         int fcode/* = -1*/,
                                         const ZcRxResourceInstance& resourceInstance/* = ZcRxResourceInstance::empty()*/, 
                                         ZcEdCommand** cmdPtrRet /*= NULL*/) = 0;

	virtual Zcad::ErrorStatus addCommand(const ZTCHAR * cmdGroupName,
                                     const ZTCHAR * cmdGlobalName,
                                         const ZTCHAR * cmdLocalName,
                                         ZSoft::Int32 commandFlags,
                                         ZcRxFunctionPtr FunctionAddr,
                                         ZcEdUIContext *UIContext = NULL,
                                         int fcode = -1,
                                         HINSTANCE hResourceHandle=NULL,
                                         ZcEdCommand** cmdPtrRet = NULL) = 0;

    virtual ZcEdCommandIterator* iterator() = 0;

    virtual ZcEdCommand* lookupGlobalCmd(const ZTCHAR * cmdName) = 0;
    virtual ZcEdCommand* lookupLocalCmd(const ZTCHAR * cmdName) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag) = 0;
    virtual ZcEdCommand* lookupCmd(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   bool skipUndefed) = 0;
    virtual ZcEdCommand* lookupCmd2(const ZTCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   int skipFlags,
                                   bool match = false) = 0;

    virtual Zcad::ErrorStatus popGroupToTop(const ZTCHAR * cmdGroupName) = 0;

    virtual Zcad::ErrorStatus removeCmd(const ZTCHAR * cmdGroupName,
                                        const ZTCHAR * cmdGlobalName) = 0;

    virtual Zcad::ErrorStatus removeGroup(const ZTCHAR * groupName) = 0;

	ZCCORE_PORT  void addReactor(ZcEdCommandStackReactor* pReactor);  
	ZCCORE_PORT  void removeReactor(ZcEdCommandStackReactor* pReactor);  
};

#pragma pack (pop)
#endif 
#endif
