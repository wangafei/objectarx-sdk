/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/gxtempl.h"
#include "adesk.h"
#include "axobjref.h"
#include "axboiler.h"
#include "oleaprot.h"

#ifdef _ADESK_WINDOWS_
#include "opmext.h"
#include "opmimp.h"
#endif

#include "dbobjptr.h"

#ifdef _ADESK_WINDOWS_
#include "rxregsvc.h"
#include "PAL/api/AcLocale.h"
#endif

#define ACAX_VARIANT_TRUE GCAX_VARIANT_TRUE
#define ACAX_VARIANT_FALSE GCAX_VARIANT_FALSE
#define CProxy_AcadObjectEvents CProxy_GcadObjectEvents
#define IAcadBaseObjectImpl IGcadBaseObjectImpl
#define IAcadBaseObject IGcadBaseObject
#define IAcadBaseObject2Impl IGcadBaseObject2Impl
#define IAcadBaseObject2 IGcadBaseObject2
#define IAcadEntityDispatchImpl IGcadEntityDispatchImpl
#define IAcadObjectDispatchImpl IGcadObjectDispatchImpl
#define IAcadBaseDatabase IGcadBaseDatabase
#define IAcadBaseSubEntityImpl IGcadBaseSubEntityImpl
#define IAcadBaseSubEntity IGcadBaseSubEntity
#define IAcadShadowDisplayImpl IGcadShadowDisplayImpl
#define IAcadSurfaceDispatchImpl IGcadSurfaceDispatchImpl
#define IAcadBaseDatabaseImpl IGcadBaseDatabaseImpl