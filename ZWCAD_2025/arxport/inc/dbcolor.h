
#ifndef __DBCOLOR_H__
#define __DBCOLOR_H__

#include "adesk.h"
#include "acadstrc.h"
#include <assert.h>

#include "../../inc/zdbcolor.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcCm
#define AcCm		ZcCm
#endif //#ifndef AcCm

#ifndef AcCmColorBase
#define AcCmColorBase		ZcCmColorBase
#endif //#ifndef AcCmColorBase

#ifndef AcCmDialogColor
#define AcCmDialogColor		ZcCmDialogColor
#endif //#ifndef AcCmDialogColor

#ifndef AcCmEntityColor
#define AcCmEntityColor		ZcCmEntityColor
#endif //#ifndef AcCmEntityColor

#ifndef AcCmTransparency
#define AcCmTransparency		ZcCmTransparency
#endif //#ifndef AcCmTransparency

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcCmEntityColor
#define AcCmEntityColor		ZcCmEntityColor
#endif //#ifndef AcCmEntityColor

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef ADESK_ACCMENTITYCOLOR_DEFINED
#define ADESK_ACCMENTITYCOLOR_DEFINED		ZSOFT_ZCCMENTITYCOLOR_DEFINED
#endif //#ifndef ADESK_ACCMENTITYCOLOR_DEFINED

#ifndef accmResolveEffectiveColorToRGB
#define accmResolveEffectiveColorToRGB zccmResolveEffectiveColorToRGB
#endif

#ifndef accmAttenuateRGB
#define accmAttenuateRGB zccmAttenuateRGB
#endif

#endif //#ifndef __DBCOLOR_H__
