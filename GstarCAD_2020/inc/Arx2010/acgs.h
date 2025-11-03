#pragma once
#include "adesk.h"
#include "stdlib.h"
#include "AdAChar.h"
#include "../grx/gcgs.h"

#define  acgsGetScreenShot    gcgsGetScreenShot

#define  acgsGetDisplayInfo   gcgsGetDisplayInfo
#define  acgsGetViewportInfo  gcgsGetViewportInfo
#define  acgsGetScreenShot    gcgsGetScreenShot

#define  acgsSetViewportRenderFlag    gcgsSetViewportRenderFlag
#define  acgsDisplayImage             gcgsDisplayImage
#define  acgsRemoveAnonymousGraphics  gcgsRemoveAnonymousGraphics
#define  acgsCustomUpdateMethod       gcgsCustomUpdateMethod
#define  acgsSetCustomUpdateMethod    gcgsSetCustomUpdateMethod
#define  acgsRedrawShortTermGraphics  gcgsRedrawShortTermGraphics

#define  AcGs  GcGs

#define  acgsSetHighlightColor        gcgsSetHighlightColor
#define  acgsGetHighlightColor        gcgsGetHighlightColor
#define  acgsSetHighlightLinePattern  gcgsSetHighlightLinePattern
#define  acgsGetHighlightLinePattern  gcgsGetHighlightLinePattern
#define  acgsSetHighlightLineWeight   gcgsSetHighlightLineWeight
#define  acgsGetHighlightLineWeight   gcgsGetHighlightLineWeight


#define  acgsSetViewParameters         gcgsSetViewParameters
#define  acgsGetViewParameters         gcgsGetViewParameters
#define  acgsSetLensLength             gcgsSetLensLength
#define  acgsGetLensLength             gcgsGetLensLength
#define  acgsWriteViewToUndoController  gcgsWriteViewToUndoController
#define  acgsSetView2D                  gcgsSetView2D

#define  acgsGetGsView  gcgsGetGsView
#define  acgsGetGsManager  gcgsGetGsManager

#define  acgsGetOrthoViewParameters  gcgsGetOrthoViewParameters

#define  AcGs2DViewLimitManager  GcGs2DViewLimitManager

#define  acgsCreate2DViewLimitManager  gcgsCreate2DViewLimitManager
#define  acgsDestroy2DViewLimitManager  gcgsDestroy2DViewLimitManager
#define  acgsDrawableModified           gcgsDrawableModified
#define  acgsDrawableErased             gcgsDrawableErased

#define AcGsScreenShot GcGsScreenShot
#define acgsSetLineWeightDisplay gcgsSetLineWeightDisplay