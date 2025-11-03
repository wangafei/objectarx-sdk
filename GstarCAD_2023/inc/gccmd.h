/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCCMD_H
#define   _GCCMD_H

#include "gsoft.h"
#include "GdGChar.h"
#include "gccmd-defs.h"
#include "rxresource.h"

#define GCRX_COMMAND_DOCK  	GCRX_T("ACRX_REGISTERED_COMMANDS") 

typedef void(*GcRxFunctionPtr) ();

#pragma pack (push, 8)
class GcEdCommand;

struct GcEdCommandStruc {
  GcRxFunctionPtr fcnAddr;
  long            flags;
  void	          *app;
  GcEdCommand	    *cmd;
};
#pragma pack (pop)

#if defined(__cplusplus)

#include "dbmain.h"
#include "rxobject.h"

class GcRxDictionary;
class GcEdUIContext;
class GcEdCommandReactor;

#pragma pack (push, 8)

class GCBASE_PORT GcEdCommand : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdCommand);

  virtual void            commandUndef(bool undefIt) = 0;
  virtual Gsoft::Int32    commandFlags() const = 0;
  virtual GcRxFunctionPtr functionAddr() const = 0;
  virtual void            functionAddr(GcRxFunctionPtr fhdl) = 0;
  virtual void            *commandApp() const = 0;
  virtual GcEdUIContext   *UIContext() const = 0;
  virtual int             functionCode() const = 0;
  virtual void            functionCode(int fcode) = 0;
  virtual const GCHAR *   globalName() const = 0;
  virtual const GCHAR *   localName() const = 0;

  virtual const GcRxResourceInstance& resourceInstance() const = 0;

  void addReactor(GcEdCommandReactor* pReactor);
  void removeReactor(GcEdCommandReactor* pReactor);

  Gsoft::UInt8 defaultCommandVersion() const;
};

enum GcEdCommandStatusFlags
{
  kCmdStatusNone   = 0x00000,
  kCmdStatusCancel = 0x00001,
  kCmdStatusFailed = 0x00002,
};

GCBASE_PORT GcEdCommandStatusFlags& operator|=(GcEdCommandStatusFlags& f, int i);
GCBASE_PORT GcEdCommandStatusFlags& operator&=(GcEdCommandStatusFlags& f, int i);

class GcEdImpCommandEventArgs;
class GcEdCommandEventArgs
{
public:
  const GCHAR*           groupName() const;
  GcEdCommandStatusFlags status() const;
  void                   setStatus(GcEdCommandStatusFlags flags);

protected:
  friend class GcEdImpCommandEventArgs;
  GcEdImpCommandEventArgs* m_pImp;

  GcEdCommandEventArgs(GcEdImpCommandEventArgs* pImp);
  GcEdCommandEventArgs(const GcEdCommandEventArgs& other);
  GcEdCommandEventArgs& operator=(const GcEdCommandEventArgs& other);
};

class GCBASE_PORT GcEdCommandReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdCommandReactor);

  virtual void commandWillStart(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
  virtual void     commandEnded(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
  virtual void          goodbye(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
};

class GCBASE_PORT GcEdCommandStackReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdCommandStackReactor);

  virtual void commandAdded(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
  virtual void commandRemoved(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
  virtual void commandWillStart(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
  virtual void commandEnded(GcEdCommand* pCmd, GcEdCommandEventArgs* data);
};

class GCBASE_PORT GcEdCommandIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdCommandIterator);

  virtual bool               done() const = 0;
  virtual bool               next() = 0;
  virtual const GcEdCommand* command() const = 0;
  virtual const GCHAR *      commandGroup() const = 0;
};

#define gcedRegCmds \
GcEdCommandStack::cast(gcrxSysRegistry()->at(GCRX_COMMAND_DOCK))

class GCBASE_PORT GcEdCommandStack : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdCommandStack);

  virtual bool              atPut(const GCHAR * cmdGroupName,
                                  GcRxDictionary*& cmdsGlobal,
                                  GcRxDictionary*& cmdsLocal) = 0;

  virtual Gcad::ErrorStatus addCommand(const GCHAR * cmdGroupName,
                                       const GCHAR * cmdGlobalName,
                                       const GCHAR * cmdLocalName,
                                       Gsoft::Int32 commandFlags,
                                       GcRxFunctionPtr FunctionAddr,
                                       GcEdUIContext *UIContext=NULL,
                                       int fcode=-1,
                                       const GcRxResourceInstance& resourceInstance = GcRxResourceInstance::empty(),
                                       GcEdCommand** cmdPtrRet=NULL) = 0;

  virtual GcEdCommandIterator* iterator() = 0;

  virtual GcEdCommand* lookupGlobalCmd(const GCHAR * cmdName) = 0;
  virtual GcEdCommand* lookupLocalCmd(const GCHAR * cmdName) = 0;
  virtual GcEdCommand* lookupCmd(const GCHAR * cmdName,
                                 bool globalFlag) = 0;
  virtual GcEdCommand* lookupCmd(const GCHAR * cmdName,
                                 bool globalFlag,
                                 bool allGroupsFlag) = 0;
  virtual GcEdCommand* lookupCmd(const GCHAR * cmdName,
                                 bool globalFlag,
                                 bool allGroupsFlag,
                                 bool skipUndefed) = 0;
  virtual GcEdCommand* lookupCmd2(const GCHAR * cmdName,
                                  bool globalFlag,
                                  bool allGroupsFlag,
                                  int skipFlags,
                                  bool match = false) = 0;

  virtual Gcad::ErrorStatus popGroupToTop(const GCHAR * cmdGroupName) = 0;

  virtual Gcad::ErrorStatus removeCmd(const GCHAR * cmdGroupName,
                                      const GCHAR * cmdGlobalName) = 0;

  virtual Gcad::ErrorStatus removeGroup(const GCHAR * groupName) = 0;

  void addReactor(GcEdCommandStackReactor* pReactor);
  void removeReactor(GcEdCommandStackReactor* pReactor);
};

#pragma pack (pop)
#endif 
#endif