/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/grxEntryPoint.h"
#include "accmd.h"
#include "ads.h"
#include "dbxEntryPoint.h"
#ifdef __ATLCOM_H__
#include "dynpropmgr.h"
#endif

#define _ARXCOMMAND_ENTRY _GRXCOMMAND_ENTRY
#define _ADSSYMBOL_ENTRY  _GDSSYMBOL_ENTRY
#define AcRxArxApp GcRxGrxApp

#define ACED_ARXCOMMAND_ENTRY_AUTO   GCED_GRXCOMMAND_ENTRY_AUTO
#define ACED_ARXCOMMAND_ENTRYBYID_AUTO   GCED_GRXCOMMAND_ENTRYBYID_AUTO
#define ACED_ADSCOMMAND_ENTRY_AUTO  GCED_GDSCOMMAND_ENTRY_AUTO

#define ACED_ADSSYMBOL_ENTRY_AUTO  GCED_GDSSYMBOL_ENTRY_AUTO
#define ACED_ADSSYMBOL_ENTRYBYID_AUTO GCED_GDSSYMBOL_ENTRYBYID_AUTO