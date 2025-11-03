#pragma once

#include "AdAChar.h"
#include "dbmain.h"
#include "rxobject.h"
#include <wtypes.h> 
#include "../Ed/EdCommandStack.h"

#define acedRegCmds  gcedRegCmds
#define	gcedRegCmds  odedRegCmds().get()

#define	AcEdCommand 	GcEdCommand
#define	GcEdCommand 	OdEdCommand

#define	AcEdCommandIterator 	GcEdCommandIterator
#define	GcEdCommandIterator 	OdEdCommandIterator

#define	AcEdCommandStack 	GcEdCommandStack
#define	GcEdCommandStack 	OdEdCommandStack

#define	ACRX_CMD_MODAL 	              OdEdCommand::kModal
#define	ACRX_CMD_TRANSPARENT        	OdEdCommand::kTransparent
#define	ACRX_CMD_USEPICKSET 	        OdEdCommand::kUsePickset
#define	ACRX_CMD_REDRAW 	            OdEdCommand::kRedraw
#define	ACRX_CMD_NOPERSPECTIVE 	      OdEdCommand::kNoPerspective

#define	ACRX_CMD_NOMULTIPLE 	        OdEdCommand::kNoMultiple
#define	ACRX_CMD_NOTILEMODE 	        OdEdCommand::kNoTilemode
#define	ACRX_CMD_NOPAPERSPACE 	      OdEdCommand::kNoPaperspace
//#define	ACRX_CMD_PLOTONLY 	        OdEdCommand::kPlotOnly
#define	ACRX_CMD_NOOEM 	              OdEdCommand::kNoOEM
#define	ACRX_CMD_UNDEFINED 	          OdEdCommand::kUndefined
#define	ACRX_CMD_INPROGRESS 	        OdEdCommand::kInProgress
#define	ACRX_CMD_DEFUN 	              OdEdCommand::kDefun
#define ACRX_CMD_LISPASCMD            OdEdCommand::kLispAsCmd
#define	ACRX_CMD_NONEWSTACK 	        OdEdCommand::kNoNewStack
#define	ACRX_CMD_NOINTERNALLOCK 	    OdEdCommand::kNoInternalLock
#define	ACRX_CMD_DOCREADLOCK        	OdEdCommand::kDocReadLock
#define	ACRX_CMD_DOCEXCLUSIVELOCK   	OdEdCommand::kDocExclusiveLock
#define	ACRX_CMD_SESSION 	            OdEdCommand::kSession

#define	ACRX_CMD_INTERRUPTIBLE 	      OdEdCommand::kInterruptible

#define	ACRX_CMD_NOHISTORY          	OdEdCommand::kNoHistory
#define	ACRX_CMD_NO_UNDO_MARKER 	    OdEdCommand::kNoUndoMarker
#define	ACRX_CMD_NOBEDIT 	            OdEdCommand::kNoBedit
#define ACRX_CMD_NOACTIONRECORDING    OdEdCommand::kNoActionRecording
#define ACRX_CMD_ACTIONMACRO          OdEdCommand::kActionMacro
#define ACRX_CMD_RELAXASSOC           OdEdCommand::KRelaxAssoc

#define ACRX_MAX_CMDNAME_LEN  	64

#define ACRX_COMMAND_DOCK  	GCRX_T("ACAD_REGISTERED_COMMANDS")

#define	AcRxFunctionPtr 	GcRxFunctionPtr

#define	AcEdCommandStruc 	GcEdCommandStruc
#define	GcEdCommandStruc 	OdEdCommandStruc
