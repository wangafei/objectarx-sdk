#ifndef __ACGS_H__
#define __ACGS_H__

#include "adesk.h"
#include "stdlib.h"
#include "AdAChar.h"
#include "acgitransient.h"
#include "AcCoreDefs.h"
#include "acgidefs.h"
#include "acdb.h"

#include "../../inc/zacgs.h"

#ifndef acgsObtainZcGsView
#define acgsObtainZcGsView	zcgsObtainZcGsView
#endif //#ifndef acgsObtainZcGsView   

#ifndef AcGsDevice
#define AcGsDevice	ZcGsDevice
#endif //#ifndef AcGsDevice   

#ifndef AcGiDrawable
#define AcGiDrawable	ZcGiDrawable
#endif //#ifndef AcGiDrawable   

#ifndef AcGsModel
#define AcGsModel	ZcGsModel
#endif //#ifndef AcGsModel   

#ifndef acgsObtainAcGsView
#define acgsObtainAcGsView	zcgsObtainZcGsView
#endif //#ifndef acgsObtainAcGsView   

#ifndef acgsGetGsModel
#define acgsGetGsModel		zcgsGetGsModel
#endif //#ifndef acgsGetGsModel

#ifndef AcGiTransientDrawingMode
#define AcGiTransientDrawingMode		ZcGiTransientDrawingMode
#endif //#ifndef AcGiTransientDrawingMode

#ifndef acgsGetCurrentGsManager
#define acgsGetCurrentGsManager		zcgsGetCurrentGsManager
#endif //#ifndef acgsGetCurrentGsManager

#ifndef acgsDrawableModified
#define acgsDrawableModified		zcgsDrawableModified
#endif //#ifndef acgsDrawableModified

#ifndef acgsDrawableErased
#define acgsDrawableErased	zcgsDrawableErased
#endif //#ifndef acgsDrawableErased   

#ifndef acgsGetCurrentGsManager2
#define acgsGetCurrentGsManager2 zcgsGetCurrentGsManager2
#endif //#ifndef acgsGetCurrentGsManager2

#ifndef acgsDrawableCached
#define acgsDrawableCached		zcgsDrawableCached
#endif //#ifndef acgsDrawableCached

#ifndef acgsGetGsHighlightModel
#define acgsGetGsHighlightModel		zcgsGetGsHighlightModel
#endif //#ifndef acgsGetGsHighlightModel

#ifndef acgsGetActiveGraphicsKernels
#define acgsGetActiveGraphicsKernels zcgsGetActiveGraphicsKernels
#endif //#ifndef acgsGetActiveGraphicsKernels

#ifndef acgsGetActiveModels
#define acgsGetActiveModels zcgsGetActiveModels
#endif //#ifndef acgsGetActiveModels

#ifndef acgsSetGsModel
#define acgsSetGsModel		zcgsSetGsModel
#endif //#ifndef acgsSetGsModel

#ifndef acgsSetGsHighlightModel
#define acgsSetGsHighlightModel		zcgsSetGsHighlightModel
#endif //#ifndef acgsSetGsHighlightModel

#ifndef AcDb
#define AcDb		ZcDb
#endif //#ifndef AcDb

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcGs
#define AcGs		ZcGs
#endif //#ifndef AcGs

#ifndef AcGs2DViewLimitManager
#define AcGs2DViewLimitManager		ZcGs2DViewLimitManager
#endif //#ifndef AcGs2DViewLimitManager

#ifndef AcGsManager
#define AcGsManager		ZcGsManager
#endif //#ifndef AcGsManager

#ifndef AcGsScreenShot
#define AcGsScreenShot		ZcGsScreenShot
#endif //#ifndef AcGsScreenShot

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acgsCreate2DViewLimitManager
#define acgsCreate2DViewLimitManager		zcgsCreate2DViewLimitManager
#endif //#ifndef acgsCreate2DViewLimitManager

#ifndef acgsCustomUpdateMethod
#define acgsCustomUpdateMethod		zcgsCustomUpdateMethod
#endif //#ifndef acgsCustomUpdateMethod

#ifndef acgsDestroy2DViewLimitManager
#define acgsDestroy2DViewLimitManager		zcgsDestroy2DViewLimitManager
#endif //#ifndef acgsDestroy2DViewLimitManager

#ifndef acgsDisplayImage
#define acgsDisplayImage		zcgsDisplayImage
#endif //#ifndef acgsDisplayImage

#ifndef acgsGetDisplayInfo
#define acgsGetDisplayInfo		zcgsGetDisplayInfo
#endif //#ifndef acgsGetDisplayInfo

#ifndef acgsGetGsManager
#define acgsGetGsManager		zcgsGetGsManager
#endif //#ifndef acgsGetGsManager

#ifndef AcGsKernelDescriptor
#define AcGsKernelDescriptor		ZcGsKernelDescriptor
#endif //#ifndef AcGsKernelDescriptor
 
#ifndef acgsGetCurrentAcGsView
#define acgsGetCurrentAcGsView		zcgsGetCurrentZcGsView
#endif //#ifndef acgsGetCurrentAcGsView

#ifndef acgsGetCurrent3dAcGsView
#define acgsGetCurrent3dAcGsView		zcgsGetCurrent3dZcGsView
#endif //#ifndef acgsGetCurrent3dAcGsView

#ifndef acgsGetHighlightColor
#define acgsGetHighlightColor		zcgsGetHighlightColor
#endif //#ifndef acgsGetHighlightColor

#ifndef acgsGetHighlightLinePattern
#define acgsGetHighlightLinePattern		zcgsGetHighlightLinePattern
#endif //#ifndef acgsGetHighlightLinePattern

#ifndef acgsGetHighlightLineWeight
#define acgsGetHighlightLineWeight		zcgsGetHighlightLineWeight
#endif //#ifndef acgsGetHighlightLineWeight

#ifndef acgsGetLensLength
#define acgsGetLensLength		zcgsGetLensLength
#endif //#ifndef acgsGetLensLength

#ifndef acgsGetOrthoViewParameters
#define acgsGetOrthoViewParameters		zcgsGetOrthoViewParameters
#endif //#ifndef acgsGetOrthoViewParameters

#ifndef acgsGetScreenShot
#define acgsGetScreenShot		zcgsGetScreenShot
#endif //#ifndef acgsGetScreenShot

#ifndef acgsGetViewParameters
#define acgsGetViewParameters		zcgsGetViewParameters
#endif //#ifndef acgsGetViewParameters

#ifndef acgsGetViewportInfo
#define acgsGetViewportInfo		zcgsGetViewportInfo
#endif //#ifndef acgsGetViewportInfo

#ifndef acgsRedrawShortTermGraphics
#define acgsRedrawShortTermGraphics		zcgsRedrawShortTermGraphics
#endif //#ifndef acgsRedrawShortTermGraphics

#ifndef acgsRemoveAnonymousGraphics
#define acgsRemoveAnonymousGraphics		zcgsRemoveAnonymousGraphics
#endif //#ifndef acgsRemoveAnonymousGraphics

#ifndef acgsSetCustomUpdateMethod
#define acgsSetCustomUpdateMethod		zcgsSetCustomUpdateMethod
#endif //#ifndef acgsSetCustomUpdateMethod

#ifndef acgsSetHighlightColor
#define acgsSetHighlightColor		zcgsSetHighlightColor
#endif //#ifndef acgsSetHighlightColor

#ifndef acgsSetHighlightLinePattern
#define acgsSetHighlightLinePattern		zcgsSetHighlightLinePattern
#endif //#ifndef acgsSetHighlightLinePattern

#ifndef acgsSetHighlightLineWeight
#define acgsSetHighlightLineWeight		zcgsSetHighlightLineWeight
#endif //#ifndef acgsSetHighlightLineWeight

#ifndef acgsSetLensLength
#define acgsSetLensLength		zcgsSetLensLength
#endif //#ifndef acgsSetLensLength

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase
#ifndef acgsSetHighlightStyle
#define acgsSetHighlightStyle		zcgsSetHighlightStyle
#endif //#ifndef acgsSetHighlightStyle
#ifndef acgsGetHighlightStyle
#define acgsGetHighlightStyle		zcgsGetHighlightStyle
#endif //#ifndef acgsGetHighlightStyle

#ifndef AcGiHighlightStyle
#define AcGiHighlightStyle		ZcGiHighlightStyle
#endif //#ifndef AcGiHighlightStyle

#ifndef ACCORE_PORT
#define ACCORE_PORT		ZCCORE_PORT
#endif //#ifndef ACCORE_PORT

#ifndef acgsSetView2D
#define acgsSetView2D		zcgsSetView2D
#endif //#ifndef acgsSetView2D

#ifndef acgsSetViewParameters
#define acgsSetViewParameters		zcgsSetViewParameters
#endif //#ifndef acgsSetViewParameters

#ifndef acgsSetViewportRenderFlag
#define acgsSetViewportRenderFlag		zcgsSetViewportRenderFlag
#endif //#ifndef acgsSetViewportRenderFlag

#ifndef acgsWriteViewToUndoController
#define acgsWriteViewToUndoController		zcgsWriteViewToUndoController
#endif //#ifndef acgsWriteViewToUndoController

#ifndef acgsSetLineWeightDisplay
#define acgsSetLineWeightDisplay		zcgsSetLineWeightDisplay
#endif //#ifndef acgsSetLineWeightDisplay

#endif //#ifndef __ACGS_H__
