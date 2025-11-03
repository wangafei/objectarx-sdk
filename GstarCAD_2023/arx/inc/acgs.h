/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/gcgs.h"
#include "adesk.h"
#include "acdb.h"
#include "stdlib.h"
#include "AdAChar.h"
#include "acgitransient.h"
#include "accoredefs.h"
#include "acgidefs.h"


#define acgsGetDisplayInfo gcgsGetDisplayInfo
#define acgsGetViewportInfo gcgsGetViewportInfo
#define AcGsScreenShot GcGsScreenShot
#define acgsGetScreenShot gcgsGetScreenShot
#define acgsSetViewportRenderFlag gcgsSetViewportRenderFlag
#define acgsDisplayImage gcgsDisplayImage
#define acgsRemoveAnonymousGraphics gcgsRemoveAnonymousGraphics
#define acgsCustomUpdateMethod gcgsCustomUpdateMethod
#define acgsSetCustomUpdateMethod gcgsSetCustomUpdateMethod
#define acgsRedrawShortTermGraphics gcgsRedrawShortTermGraphics
#define AcGs GcGs
#define acgsSetHighlightColor gcgsSetHighlightColor
#define acgsGetHighlightColor gcgsGetHighlightColor
#define acgsSetHighlightLinePattern gcgsSetHighlightLinePattern
#define acgsGetHighlightLinePattern gcgsGetHighlightLinePattern
#define acgsSetHighlightLineWeight gcgsSetHighlightLineWeight
#define acgsGetHighlightLineWeight gcgsGetHighlightLineWeight
#define acgsSetHighlightStyle gcgsSetHighlightStyle
#define acgsGetHighlightStyle gcgsGetHighlightStyle
#define acgsSetViewParameters gcgsSetViewParameters
#define acgsGetViewParameters gcgsGetViewParameters
#define acgsSetLensLength gcgsSetLensLength
#define acgsGetLensLength gcgsGetLensLength
#define acgsWriteViewToUndoController gcgsWriteViewToUndoController
#define acgsSetView2D gcgsSetView2D
#define acgsGetCurrentGcGsView gcgsGetCurrentGcGsView
#define acgsGetCurrent3dGcGsView gcgsGetCurrent3dGcGsView
#define acgsObtainGcGsView gcgsObtainGcGsView
#define acgsGetGsModel gcgsGetGsModel
#define acgsGetGsManager gcgsGetGsManager
#define acgsGetCurrentGsManager gcgsGetCurrentGsManager
#define acgsGetOrthoViewParameters gcgsGetOrthoViewParameters
#define AcGs2DViewLimitManager GcGs2DViewLimitManager
#define acgsCreate2DViewLimitManager gcgsCreate2DViewLimitManager
#define acgsDestroy2DViewLimitManager gcgsDestroy2DViewLimitManager
#define acgsDrawableModified gcgsDrawableModified
#define acgsDrawableErased gcgsDrawableErased
#define acgsDrawableCached gcgsDrawableCached
#define acgsGetGsHighlightModel gcgsGetGsHighlightModel
#define acgsSetGsModel gcgsSetGsModel
#define acgsSetGsHighlightModel gcgsSetGsHighlightModel
#define acgsGetCurrent3dAcGsView gcgsGetCurrent3dGcGsView
#define acgsGetCurrentAcGsView   gcgsGetCurrentGcGsView
#define acgsObtainAcGsView       gcgsObtainGcGsView
