/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef _ODEDCOMMANDSTACK_H_INCLUDED_
#define _ODEDCOMMANDSTACK_H_INCLUDED_



#define ODRX_COMMAND_DOCK      OD_T("ODRX_REGISTERED_COMMANDS")

class OdEdCommand;
class OdEdCommandContext;

#include "../RxObject.h"

class OdRxIterator;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxIterator object pointers. 
*/
typedef OdSmartPtr<OdRxIterator> OdRxIteratorPtr;

class OdRxDictionary;
class OdEdUIContext;

#include "../TD_PackPush.h"

class OdEdCommand;

class OdEdCommandIterator;

typedef void (*OdEdCommandFunction) (OdEdCommandContext* pCmdCtx);
typedef void (*GcRxFunctionPtr) ();

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdEdCommand object pointers. 
*/
typedef OdSmartPtr<OdEdCommand> OdEdCommandPtr;

struct OdEdCommandStruc 
{
  GcRxFunctionPtr fcnAddr;
  long            flags;
  void	          *app;
  HINSTANCE       hResHandle;
  OdEdCommand		*cmd;
};

/** Description:
    This class represents custom commands within a Teigha client application. 
    
    Remarks:
    A custom command is be created by deriving a class from OdEdCommand, and overriding
    the functions in that class. 
    
    The custom command is registered in the global command stack by calling 
    OdEdCommandStack::addCommand() on the global command stack, 
    which obtained via the odedRegCmds() external function.

    Library: TD_Root
    
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdCommand : public OdRxObject 
{
protected:
  OdEdCommand();
public:
  ~OdEdCommand();
  ODRX_DECLARE_MEMBERS(OdEdCommand);

  enum
  {
    kModal            = 0x00000000,
    kTransparent      = 0x00000001,
    kUsePickset       = 0x00000002,
    kRedraw           = 0x00000004,
    kNoPerspective    = 0x00000008, // NOT allowed in perspective views
    kNoMultiple       = 0x00000010,
    kNoTilemode       = 0x00000020, // NOT allowed with TILEMODE == 1
    kNoPaperspace     = 0x00000040, // NOT allowed in Paperspace
    kPlotOnly         = 0x00000080,
    kNoOEM            = 0x00000100,
    kUndefined        = 0x00000200,
    kInProgress       = 0x00000400,
    kDefun            = 0x00000800,
    kLispAsCmd        = 0x00001000, // For Internal use only
    kNoNewStack       = 0x00010000, // For internal use only
    kNoInternalLock   = 0x00020000,
    kDocReadLock      = 0x00080000, // not set = DOCWRITELOCK
    kDocExclusiveLock = 0x00100000, // not set = DOCSHAREDLOCK
    kSession          = 0x00200000, // Run cmd handler in the session fiber
    kInterruptible    = 0x00400000, // Supports OPM display of command properties
    kNoHistory        = 0x00800000, // Command does not become default
    kNoUndoMarker     = 0x01000000, // No Undo or Repeat presence.
    kNoBedit          = 0x02000000, // blocked during a bedit session
    kNoActionRecording= 0x04000000, // Disallow Action Recording
    kActionMacro      = 0x08000000, // Action Macro command
    KRelaxAssoc       = 0x10000000  /* Allow relaxed network evaluation
                                       during drag operation */
/*
NOACTIONRECORDING  0x04000000 // Disallow Action Recording
ACTIONMACRO        0x08000000 // Action Macro command
RELAXASSOC         0x10000000 // Allow relaxed network evaluation during drag operation
CORE               0x20000000 // For internal use only 
NOINFERCONSTRAINT  0x40000000 // Disallow Inferring constraints 
TEMPSHOWDYNDIM     0x80000000 // Temporarily show dynamic dimensions for selected entities during this command
*/
  };

  static OdEdCommandPtr createObject(
    const OdString& sGroupName,
    const OdString& sGlobalName,
    const OdString& sLocalName,
    OdUInt32 commandFlags,
    OdEdCommandFunction pFunction,
    OdRxModule *pModule = 0,
	OdEdUIContext *pUIContext = NULL);

  static OdEdCommandPtr createObject(
	const OdString& sGroupName,
	const OdString& sGlobalName,
	const OdString& sLocalName,
	OdUInt32 flags,
	GcRxFunctionPtr pFunction,
	OdRxModule *pModule = 0,
	OdEdUIContext *pUIContext = NULL,
	HINSTANCE hResourceHandle = NULL);

  /** Description:
  This function is for internal use only. 

  Remarks:
  This function is for internal use only. 
  */
  virtual void* commandApp() const;

  /** Description:
    Returns the group *name* of this command object. 
    
    Remarks:
    This *name* is used to group sets of registered commands.
  */
  virtual const OdChar* groupName() const = 0;

  /** Description:
    Returns the global (untranslated) *name* of this command object.
    
    Remarks:
    This *name* must be unique within the groupName of this command object.
  */
  virtual const OdChar* globalName() const = 0;

  /** Description:
    Returns the local (translated) *name* of this command.
    
    Remarks:
    This *name* must be unique within the groupName of this command object.
  */  
  virtual const OdChar* localName() const;

  /** Description:
    Called to *execute* this command object.
    
    Remarks:
    The client's override of this function contains the body of the command.
    
    Arguments:
    pCommandContext (I) Pointer to the command *context*.
    
    Remarks:
    The specified command context object is used to interact with the 
    calling application as part of an interactive command.  
            
    See Also:
    OdEdCommandContext::userIO
  */
  virtual void execute(OdEdCommandContext* pCommandContext) = 0;

  virtual const OdRxModule* module() const;

  virtual const HINSTANCE resourceHandle() const;

  virtual void commandUndef(bool undefIt);

  virtual OdInt32 commandFlags() const;

  virtual OdEdUIContext*  UIContext() const {return NULL;}

  virtual GcRxFunctionPtr functionAddr() const;
  virtual void            functionAddr(GcRxFunctionPtr fhdl);  
  
  virtual int             functionCode() const;
  virtual void            functionCode(int fcode);
  
};


/** Description:
    This class is the base class for custom classes that receive notification
    of OdEdCommandStack events.
    
    Remarks:
    Events consist of the addition and deletion, starting and ending,
    cancellation and failure, and non-recognition of registered commands. 
    
    The command stack consists of groups which contain their respective commands.
    Adding a command adds it to its group. If the group does not exist,
    the group is first created and pushed onto the top of the stack.
    
    Note:
    The default implementations of all methods in this class do nothing but return.

    Library: TD_Root

    {group:OdEd_Classes}
*/
class FIRSTDLL_EXPORT OdEdCommandStackReactor : public OdRxObject 
{ 
public:
  ODRX_DECLARE_MEMBERS(OdEdCommandStackReactor);
  
  /** Description:
    Notification function called whenevever a command has been added to the global command stack.
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual void commandAdded(OdEdCommand* pCommand);
  
  /** Description:
    Notification function called whenevever a command will be removed from the global command stack
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual void commandWillBeRemoved(OdEdCommand* pCommand);
  
  /** Description:
    Notification function called whenevever the execution of a command will start.
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called before the operation.
  */
  virtual void commandWillStart(OdEdCommand* pCommand, OdEdCommandContext* pCmdCtx);
  
  /** Description:
    Notification function called whenevever the execution of a command has ended.
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual void commandEnded(OdEdCommand* pCommand, OdEdCommandContext* pCmdCtx);
  
  /** Description:
    Notification function called whenevever the execution of a command has been canceled.
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual void commandCancelled(OdEdCommand* pCommand, OdEdCommandContext* pCmdCtx);
  
  /** Description:
    Notification function called whenevever the execution of a command has failed.
    
    Arguments:
    pCommand (I) Pointer to the command object.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual void commandFailed(OdEdCommand* pCommand, OdEdCommandContext* pCmdCtx);
  
  /** Description:
    Notification function called whenevever the execution of an unknown command has been attempted.
    
    Arguments:
    commandName (I) *name* of unknown command.
    
	  Remarks:
	  This function is called after the operation.
  */
  virtual OdEdCommandPtr unknownCommand(const OdString& commandName, OdEdCommandContext* pCmdCtx);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdEdCommandStackReactor object pointers. 
*/
typedef OdSmartPtr<OdEdCommandStackReactor> OdEdCommandStackReactorPtr;

/** Description:
    This template class is a specialization of the OdArray class for OdEdCommandStackReactor object SmartPointers.
*/
typedef OdArray<OdEdCommandStackReactorPtr> OdEdCommandStackReactorArray;


/** Description:
    This class implements and manages the global command stack.

    Remarks:
    The command stack consists of groups which contain their respective commands.
    Adding a command adds it to its group. If the group does not exist,
    the group is first created and pushed onto the top of the stack.
    
    The lookupCommand and executeCommand functions search for command names
    in the group order on the stack.
     
    In the case of duplicate command names, the most recent one added to the stack
    is the command that is returned or executed.
     
    The group order may be changed with popGroupToTop function. 
         
    Library: TD_Root
    
    {group:OdEd_Classes}
*/
class FIRSTDLL_EXPORT OdEdCommandStack : public OdRxObject 
{ 
public:
  ODRX_DECLARE_MEMBERS(OdEdCommandStack);

  //This function is for internal system use only.
  virtual bool atPut(const OdChar * cmdGroupName,OdRxDictionary*& cmdsGlobal, OdRxDictionary*& cmdsLocal) = 0;

   /** Description:
    Adds the specified *reactor* to this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void addReactor(OdEdCommandStackReactor* pReactor) = 0;

  /** Description:
    Removes the specified transient *reactor* from this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  virtual void removeReactor(OdEdCommandStackReactor* pReactor) = 0;

  /** Description:
    Returns this object's transient reactors.
  */
  virtual OdEdCommandStackReactorArray getCommandStackReactors() const = 0;

  /** Description:
    Adds the specified command object to this Stack object.

    Arguments:
    pCommand (I) Pointer to the command object.
    
    Remarks:
    If the group associated with the command does not exist, 
    the group is first created and pushed onto the top of the stack.
    
    The globalName and localName must be unique within the groupName of this command object.
  */
  virtual void addCommand(OdEdCommand* pCommand) = 0;

  /** Description:
    Adds the specified command object to this Stack object.

    Arguments:
    pCommand (I) Pointer to the command object.
    
    Remarks:
    If the group associated with the command does not exist, 
    the group is first created and pushed onto the top of the stack.
    
    The globalName and localName must be unique within the groupName of this command object.
  */
  virtual OdEdCommand* addCommand(
    const OdString& sGroupName,
    const OdString& sGlobalName,
    const OdString& sLocalName,
    OdUInt32 commandFlags,
    OdEdCommandFunction pFunction,
    OdRxModule *pModule = 0,
		OdEdUIContext *pUIContext = NULL);
  
  virtual OdEdCommand* addCommand(
    const OdString& sGroupName,
    const OdString& sGlobalName,
    const OdString& sLocalName,
    OdUInt32 commandFlags,
    GcRxFunctionPtr pFunction,
    OdRxModule *pModule = 0,
		OdEdUIContext *pUIContext = NULL,
		HINSTANCE hResourceHandle = NULL);

  OdResult addCommand(const OdChar* cmdGroupName,const OdChar* cmdGlobalName,const OdChar* cmdLocalName,OdUInt32 commandFlags,
		GcRxFunctionPtr FunctionAddr,OdEdUIContext* UIContext = NULL,int fcode = -1,HINSTANCE hResourceHandle = NULL,OdEdCommand** cmdPtrRet = NULL);

  /** Description:
    Returns an Iterator object that can be 
    used to traverse the OdEdCommand objects in this Stack object.
    
    
    Remarks:
    The traversal is by global name in group order.

  */
  virtual OdRxIteratorPtr newIterator() = 0;

  /** 
    Arguments:
    groupName (I) Group *name*.

    Remarks:
    If groupName is specified, only OdEdCommand objects in the specified
    group will be traversed.
  */
  virtual OdRxIteratorPtr newIterator(const OdString& groupName) = 0;


	virtual OdEdCommandIterator* iterator() = 0;

  /** Description:
    Returns an Iterator object that can be used to traverse the 
    group objects in this Stack object.

    Remarks:
    Each group is an OdRxDictionary object.
  */
  virtual OdRxIteratorPtr newGroupIterator() = 0;
  
  enum LookupFlags
  {
    kGlobal       = 0x01, // Search global (untranslated) names.
    kLocal        = 0x02, // Search local (translated) names.
    kSpecifedGroup= 0x04, // Search in specified group only.
    kUndefed      = 0x08, // Do not fire unknownCommand() event.
	kUndefined    = 0x10  // Search undefined command.
  };
  /** Description:
    Returns the OdEdCommand object with the specified name in this Stack object. 

    Arguments:
    commandName (I) Name of the command to find.
    lookupFlags (I) Specified where command lookup is to look.
    groupName (I) Group *name*.
    
    Remarks:
    Returns a SmartPointer to the OdEdCommand object if successful, otherwise a null SmartPointer.

    This function searches for command names in the group order on the stack.
    
    If groupName is specified, only that group will be searched.

    lookupFlags must be a combination of one or more of the following:
    
    @table
    Name              Value     Description
    kGlobal           0x01      Search global (untranslated) names.
    kLocal            0x02      Search local (translated) names.
    kSpecifedGroup    0x04      Search in specified group only.
    kUndefed          0x08      Indicats whether or not to return commands that are currently marked as undefined.
    kUndefined        0x10      Search undefined command.
  */
  virtual OdEdCommandPtr lookupCmd(const OdChar * commandName,int lookupFlags = kGlobal|kLocal,const OdString& groupName = OdString::kEmpty) = 0;

   /** Description:
    Returns the OdEdCommand object with the specified name in this Stack object. 

    Arguments:
    cmdName       (I) Name of the command to find.
    globalFlag    (I) Input Boolean flag which specifies if the command lookup is to be performed on global and untranslated or local and translated command names 
    allGroupsFlag (I) Input Boolean flag indicating whether to search only the command group at the top of the CommandStack, or all command groups 
    skipUndefed   (I) Input Boolean flag indicating whether or not to skip past commands that are currently marked as undefined 

    Remarks:
    Returns a SmartPointer to the OdEdCommand object if successful, otherwise a null SmartPointer.
  */
  virtual OdEdCommand* lookupGlobalCmd(const OdChar * cmdName) = 0;
  virtual OdEdCommand* lookupLocalCmd(const OdChar * cmdName) = 0;
  virtual OdEdCommand* lookupCmd(const OdChar * cmdName,bool globalFlag) = 0;
  virtual OdEdCommand* lookupCmd(const OdChar * cmdName,bool globalFlag,bool allGroupsFlag) = 0;
  virtual OdEdCommand* lookupCmd(const OdChar * cmdName,bool globalFlag,bool allGroupsFlag,bool skipUndefed) = 0;

  //This function is for internal system use only.
  virtual OdEdCommand* lookupCmd2(const OdChar * cmdName,bool globalFlag,bool allGroupsFlag,int skipFlags,bool match = false) = 0;


  /** Description:
    Executes the specified command in this Stack object. 
    
    Remarks:
    OdEdCommandStackReactor objects in the reactor list of this Stack object will be notified.

    Arguments:
    pCommand (I) Pointer to the command object to *execute*.
    pCmdCtx (I) Pointer to the command *context*.

    Remarks:
    The specified command context object is used to interact with the 
    calling application as part of an interactive command.  

    This function searches for both global and local command names in the group order on the stack.

    See also:
    OdEdCommand::execute.
  */
  virtual void executeCommand(OdEdCommand* pCmd, OdEdCommandContext* pCmdCtx) = 0;

  virtual void executeCommand(const OdString& cmdName,
                              OdEdCommandContext* pCmdCtx,
                              int lookupFlags = kGlobal|kLocal,
                              const OdString& groupName = OdString::kEmpty) = 0;

  /** Description:
    Removes the command with the specified group and global names from this Stack object.

    Arguments:
    groupName (I) Group *name*.
    globalName (I) Global (untranslated) name.
    
    Remarks:
    If a group is emptied, it is removed from this Stack object.
    
    If the specified command is not found, this function does nothing but return.
  */
  virtual OdResult removeCmd(const OdChar* groupName, const OdChar* globalName) = 0;

  virtual OdResult removeCmd(const OdEdCommand* pCommand) = 0;

  /** Description:
    Removes the specified group and its commands from this Stack object.

    Arguments:
    groupName (I) Group *name*.

    Remarks:
    If the specified group is not found, this function does nothing but return.
  */
  virtual OdResult removeGroup(const OdChar* groupName) = 0;

  /** Description:
    pops the cmdGroupName command group to the top of the CommandStack making 
    it the first group to be searched when resolving application defined command names.

    Arguments:
    Input pointer to NULL-terminated string that is the name of the command group to pop to the top of the CommandStack

    Remarks:
    This function returns eOk if successful.
    If no command group with the name cmdGroupName is found in the CommandStack, then eKeyNotFound is returned.
  */
  virtual OdResult popGroupToTop(const OdChar* cmdGroupName) = 0;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdEdCommandStack object pointers. 
*/
typedef OdSmartPtr<OdEdCommandStack> OdEdCommandStackPtr;

/** Description:
    Returns the global command stack.
*/
FIRSTDLL_EXPORT OdEdCommandStackPtr odedRegCmds();

class FIRSTDLL_EXPORT OdEdCommandIterator : public OdRxObject
{
public:
	ODRX_DECLARE_MEMBERS(OdEdCommandIterator);

	virtual bool               done() const = 0;
	virtual bool               next() = 0;
	virtual const OdEdCommand* command() const = 0;
	virtual const OdChar*      commandGroup() const = 0;
};

#include "../TD_PackPop.h"

#endif //#ifndef _ODEDCOMMANDSTACK_H_INCLUDED_
