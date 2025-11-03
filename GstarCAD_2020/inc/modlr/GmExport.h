#ifndef _GmModeler_EXPORT_DEFINED_
#define _GmModeler_EXPORT_DEFINED_

#include "../OdPlatformSettings.h"

#ifdef MODLR_DLL_EXPORTS
#define MODLR_EXPORT          OD_TOOLKIT_EXPORT
#define MODLR_EXPORT_STATIC   OD_STATIC_EXPORT
#else
#define MODLR_EXPORT          OD_TOOLKIT_IMPORT
#define MODLR_EXPORT_STATIC   OD_STATIC_IMPORT
#endif

#endif


