/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/core_rxmfcapi.h"
#include "accoredefs.h"
#include "AcHeapOpers.h"

#define AcColorSettings GcColorSettings
#define acedGetCurrentColors gcedGetCurrentColors
#define acedSetCurrentColors gcedSetCurrentColors
#define acedGetSystemColors gcedGetSystemColors
#define AcColorSettingsEx GcColorSettingsEx
#define acedGetCurrentColorsEx gcedGetCurrentColorsEx
#define acedSetCurrentColorsEx gcedSetCurrentColorsEx
#define acedGetSystemColorsEx gcedGetSystemColorsEx
#define AcColorSettingsEx2 GcColorSettingsEx2
#define acedGetCurrentColorsEx2 gcedGetCurrentColorsEx2
#define acedSetCurrentColorsEx2 gcedSetCurrentColorsEx2
#define acedGetSystemColorsEx2 gcedGetSystemColorsEx2
#define AcColorSettingsEx3 GcColorSettingsEx3
#define acedGetCurrentColorsEx3 gcedGetCurrentColorsEx3
#define acedSetCurrentColorsEx3 gcedSetCurrentColorsEx3
#define acedGetSystemColorsEx3 gcedGetSystemColorsEx3
#define acedDwgPoint gcedDwgPoint
#define acedCoordFromPixelToWorld gcedCoordFromPixelToWorld
#define acedCoordFromWorldToPixel gcedCoordFromWorldToPixel
#define acedSetStatusBarProgressMeter gcedSetStatusBarProgressMeter
#define acedSetStatusBarProgressMeterPos gcedSetStatusBarProgressMeterPos
#define acedRestoreStatusBar gcedRestoreStatusBar
#define acedGetWinNum gcedGetWinNum
#define AcedWatchWinMsgFn GcedWatchWinMsgFn
#define AcedFilterWinMsgFn GcedFilterWinMsgFn
#define AcedOnIdleMsgFn GcedOnIdleMsgFn
#define AcedOnModalFn GcedOnModalFn
#define acedRegisterFilterWinMsg gcedRegisterFilterWinMsg
#define acedRemoveFilterWinMsg gcedRemoveFilterWinMsg
#define acedRegisterWatchWinMsg gcedRegisterWatchWinMsg
#define acedRemoveWatchWinMsg gcedRemoveWatchWinMsg
#define acedRegisterOnIdleWinMsg gcedRegisterOnIdleWinMsg
#define acedRemoveOnIdleWinMsg gcedRemoveOnIdleWinMsg
#define acedRegisterOnModal gcedRegisterOnModal
#define acedRemoveOnModal gcedRemoveOnModal
#define AcedRunLoopFn GcedRunLoopFn
#define acedExecuteOnMainThread gcedExecuteOnMainThread
#define IAcEdRunLoopTask IGcEdRunLoopTask
#define acedRemoveRunLoopTask gcedRemoveRunLoopTask
#define acedGetAcadResourceInstance gcedGetGcadResourceInstance
#define AcedCommandBitmapQueryFn GcedCommandBitmapQueryFn
#define acedRemoveCommandBitmapQuery gcedRemoveCommandBitmapQuery
#define acedRegisterCommandBitmapQuery gcedRegisterCommandBitmapQuery
#define acedGetBitmapForCommand gcedGetBitmapForCommand
#define acedGetCachedBitmapForCommand gcedGetCachedBitmapForCommand
#define acedGetToolTipInfoForCommand gcedGetToolTipInfoForCommand
#define acedGetApplicationStatusBar gcedGetApplicationStatusBar
#define acedDrawingStatusBarsVisible gcedDrawingStatusBarsVisible
#define acedIsInputPending gcedIsInputPending
#define AcCommandToolTipInfo GcCommandToolTipInfo