#pragma once
#include "adesk.h"
#include "dbid.h"
#include "dblayout.h"
#include "dblaymgrrctr.h"
#include "../grx/GcDbLMgr.h"

#define	AcDbLayoutManager 	GcDbLayoutManager
#define	GcDbLayoutManager 	OdDbLayoutManager

#define acdbDoSetupForLayouts  gcdbDoSetupForLayouts
#define acdbClearSetupForLayouts  gcdbClearSetupForLayouts
#define acdbDeleteLayout  gcdbDeleteLayout
#define acdbRenameLayout  gcdbRenameLayout
#define acdbCopyLayout  gcdbCopyLayout