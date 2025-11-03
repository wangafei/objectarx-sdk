#pragma once

#define AcDbHostApplicationProgressMeter   GcDbHostApplicationProgressMeter
#define GcDbHostApplicationProgressMeter   OdDbHostApplicationProgressMeter

#define acdbHostAppMinorVersion            gcdbHostAppMinorVersion

#define acdbSetHostApplicationServices     gcdbSetHostApplicationServices

#define AcDbHostApplicationServices        GcDbHostApplicationServices
#define GcDbHostApplicationServices        OdDbHostAppServices

#define AcSDIValues                        GcSDIValues
#define GcSDIValues                        OdSDIValues

#define AcPwdCache                         GcPwdCache
#define GcPwdCache                         OdPwdCache

#define AcDbAbstractClipBoundaryDefinition GcDbAbstractClipBoundaryDefinition
#define GcDbAbstractClipBoundaryDefinition OdDbAbstractClipBoundaryDefinition

#define AcadInternalServices               GcadInternalServices

#define AcDbGlobals                        GcDbGlobals
#define GcDbGlobals                        OdDbGlobals

#define AcDbPasswordedFile                 GcDbPasswordedFile
#define GcDbPasswordedFile                 OdDbPasswordedFile

#define kProd_AcDb  kProd_GcDb
#define kProd_GcDb  kProd_OdDb

#define acdbHostApplicationServices        gcdbHostApplicationServices
#define gcdbHostApplicationServices        oddbHostApplicationServices

#define acdbSendInitialDwgFileOpenComplete gcdbSendInitialDwgFileOpenComplete
#define gcdbSendInitialDwgFileOpenComplete oddbSendInitialDwgFileOpenComplete

#define acdbTriggerAcadOctTreeReclassification gcdbTriggerGcadOctTreeReclassification
#define gcdbTriggerGcadOctTreeReclassification oddbTriggerGcadOctTreeReclassification

#define acdbSetBreak3dQueueForRegen            gcdbSetBreak3dQueueForRegen
#define gcdbSetBreak3dQueueForRegen            oddbSetBreak3dQueueForRegen

#define acadInternalServices               gcadInternalServices

#include "adesk.h"
#include "acdb.h"
#include "acarray.h"
#include "codepgid.h"
#include "acdlflagbits.h"
#include "inetstrc.h"
#include "rxdlinkr.h"

#include "../grx/dbapserv.h" 
#include "../DbHostAppProgressMeter.h"
#include "../DbHostAppPasswordFile.h"
