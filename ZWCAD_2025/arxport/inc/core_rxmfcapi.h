

#ifndef _CORE_RXMFCAPI_H_H
#define _CORE_RXMFCAPI_H_H
#include "AcCoreDefs.h"
#include "AcHeapOpers.h"

#include "../../inc/zcore_rxmfcapi.h"

#ifndef AcColorSettings
#define AcColorSettings		ZcColorSettings
#endif //#ifndef AcColorSettings

#ifndef AcColorSettingsEx
#define AcColorSettingsEx		ZcColorSettingsEx
#endif //#ifndef AcColorSettingsEx


#ifndef acedGetCurrentColors
#define acedGetCurrentColors		zcedGetCurrentColors
#endif //#ifndef acedGetCurrentColors

#ifndef acedSetCurrentColors
#define acedSetCurrentColors		zcedSetCurrentColors
#endif //#ifndef acedGetCurrentColors

#ifndef acedDwgPoint
#define acedDwgPoint		zcedDwgPoint
#endif //#ifndef acedDwgPoint

#ifndef acedCoordFromPixelToWorld
#define acedCoordFromPixelToWorld		zcedCoordFromPixelToWorld
#endif //#ifndef acedCoordFromPixelToWorld

#ifndef acedCoordFromWorldToPixel
#define acedCoordFromWorldToPixel		zcedCoordFromWorldToPixel
#endif //#ifndef acedCoordFromWorldToPixel

#ifndef acedSetStatusBarProgressMeter
#define acedSetStatusBarProgressMeter		zcedSetStatusBarProgressMeter
#endif //#ifndef acedSetStatusBarProgressMeter

#ifndef acedSetStatusBarProgressMeterPos
#define acedSetStatusBarProgressMeterPos		zcedSetStatusBarProgressMeterPos
#endif //#ifndef acedSetStatusBarProgressMeterPos


#ifndef acedRestoreStatusBar
#define acedRestoreStatusBar		zcedRestoreStatusBar
#endif //#ifndef acedRestoreStatusBar


#ifndef AcedWatchWinMsgFn
#define AcedWatchWinMsgFn		ZcedWatchWinMsgFn
#endif //#ifndef AcedWatchWinMsgFn

#ifndef AcedFilterWinMsgFn
#define AcedFilterWinMsgFn		ZcedFilterWinMsgFn
#endif //#ifndef AcedFilterWinMsgFn

#ifndef AcedOnIdleMsgFn
#define AcedOnIdleMsgFn		ZcedOnIdleMsgFn
#endif //#ifndef AcedOnIdleMsgFn

#ifndef AcedOnModalFn
#define AcedOnModalFn	ZcedOnModalFn
#endif //AcedOnModalFn

#ifndef acedRegisterExtendedTab
#define acedRegisterExtendedTab		zcedRegisterExtendedTab
#endif //#ifndef acedRegisterExtendedTab

#ifndef acedRegisterFilterWinMsg
#define acedRegisterFilterWinMsg		zcedRegisterFilterWinMsg
#endif //#ifndef acedRegisterFilterWinMsg

#ifndef acedRegisterWatchWinMsg
#define acedRegisterWatchWinMsg		zcedRegisterWatchWinMsg
#endif //#ifndef acedRegisterWatchWinMsg

#ifndef acedRemoveFilterWinMsg
#define acedRemoveFilterWinMsg		zcedRemoveFilterWinMsg
#endif //#ifndef acedRemoveFilterWinMsg

#ifndef acedRemoveWatchWinMsg
#define acedRemoveWatchWinMsg		zcedRemoveWatchWinMsg
#endif //#ifndef acedRemoveWatchWinMsg


#ifndef acedSetCurrentColorsEx
#define acedSetCurrentColorsEx		zcedSetCurrentColorsEx
#endif //#ifndef acedSetCurrentColorsEx

#ifndef acedRemoveOnIdleWinMsg
#define acedRemoveOnIdleWinMsg		zcedRemoveOnIdleWinMsg
#endif //#ifndef acedRemoveOnIdleWinMsg

#ifndef acedRegisterOnIdleWinMsg
#define acedRegisterOnIdleWinMsg		zcedRegisterOnIdleWinMsg
#endif //#ifndef acedRegisterOnIdleWinMsg

#ifndef acedRegisterStatusBarMenuItem
#define acedRegisterStatusBarMenuItem		zcedRegisterStatusBarMenuItem
#endif //#ifndef acedRegisterStatusBarMenuItem

#ifndef acedGetSystemColors
#define acedGetSystemColors		zcedGetSystemColors
#endif //#ifndef acedGetSystemColors

#ifndef acedGetSystemColorsEx
#define acedGetSystemColorsEx		zcedGetSystemColorsEx
#endif //#ifndef acedGetSystemColorsEx

#ifndef acedGetChildFrameSettings
#define acedGetChildFrameSettings		zcedGetChildFrameSettings
#endif //#ifndef acedGetChildFrameSettings

#ifndef acedGetCurrentColorsEx
#define acedGetCurrentColorsEx		zcedGetCurrentColorsEx
#endif //#ifndef acedGetCurrentColorsEx

#ifndef acedGetWinNum
#define acedGetWinNum		zcedGetWinNum
#endif //#ifndef acedGetWinNum

#ifndef acedRegisterOnModal
#define acedRegisterOnModal	zcedRegisterOnModal
#endif //acedRegisterOnModal

#ifndef acedRemoveOnModal
#define acedRemoveOnModal	zcedRemoveOnModal
#endif //acedRemoveOnModal

#ifndef acedGetAcadResourceInstance
#define acedGetAcadResourceInstance	zcedGetZcadResourceInstance
#endif 

#ifndef acedSetCurrentColors
#define acedSetCurrentColors		zcedSetCurrentColors
#endif //#ifndef acedSetCurrentColors

#ifndef AcCommandToolTipInfo
#define AcCommandToolTipInfo		ZcCommandToolTipInfo
#endif //#ifndef AcCommandToolTipInfo

#ifndef ACCORE_PORT
#define ACCORE_PORT		ZCCORE_PORT
#endif //#ifndef ACCORE_PORT

#ifndef AcColorSettingsEx2
#define AcColorSettingsEx2		ZcColorSettingsEx2
#endif //#ifndef AcColorSettingsEx2

#ifndef acedGetCurrentColorsEx2
#define acedGetCurrentColorsEx2		zcedGetCurrentColorsEx2
#endif //#ifndef acedGetCurrentColorsEx

#ifndef acedSetCurrentColorsEx2
#define acedSetCurrentColorsEx2		zcedSetCurrentColorsEx2
#endif //#ifndef acedSetCurrentColorsEx2

#ifndef acedGetSystemColorsEx2
#define acedGetSystemColorsEx2		zcedGetSystemColorsEx2
#endif //#ifndef acedGetSystemColorsEx2

#ifndef AcColorSettingsEx3
#define AcColorSettingsEx3		ZcColorSettingsEx3
#endif //#ifndef AcColorSettingsEx3

#ifndef acedGetCurrentColorsEx3
#define acedGetCurrentColorsEx3		zcedGetCurrentColorsEx3
#endif //#ifndef acedGetCurrentColorsEx

#ifndef acedSetCurrentColorsEx3
#define acedSetCurrentColorsEx3		zcedSetCurrentColorsEx3
#endif //#ifndef acedSetCurrentColorsEx3

#ifndef acedGetSystemColorsEx3
#define acedGetSystemColorsEx3		zcedGetSystemColorsEx3
#endif //#ifndef acedGetSystemColorsEx3

#ifndef AcedRunLoopFn
#define AcedRunLoopFn		ZcedRunLoopFn
#endif //#ifndef AcedRunLoopFn

#ifndef acedExecuteOnMainThread
#define acedExecuteOnMainThread		zcedExecuteOnMainThread
#endif //#ifndef acedExecuteOnMainThread

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef IAcEdRunLoopTask
#define IAcEdRunLoopTask		IZcEdRunLoopTask
#endif //#ifndef IAcEdRunLoopTask

#ifndef IAcEdRunLoopTask
#define IAcEdRunLoopTask		IZcEdRunLoopTask
#endif //#ifndef IAcEdRunLoopTask

#ifndef acedRemoveRunLoopTask
#define acedRemoveRunLoopTask		zcedRemoveRunLoopTask
#endif //#ifndef acedRemoveRunLoopTask

#ifndef AcedCommandBitmapQueryFn
#define AcedCommandBitmapQueryFn		ZcedCommandBitmapQueryFn
#endif //#ifndef AcedCommandBitmapQueryFn

#ifndef acedRemoveCommandBitmapQuery
#define acedRemoveCommandBitmapQuery		zcedRemoveCommandBitmapQuery
#endif //#ifndef acedRemoveCommandBitmapQuery

#ifndef acedRegisterCommandBitmapQuery
#define acedRegisterCommandBitmapQuery		zcedRegisterCommandBitmapQuery
#endif //#ifndef acedRegisterCommandBitmapQuery

#ifndef acedGetBitmapForCommand
#define acedGetBitmapForCommand		zcedGetBitmapForCommand
#endif //#ifndef acedGetBitmapForCommand

#ifndef acedGetCachedBitmapForCommand
#define acedGetCachedBitmapForCommand		zcedGetCachedBitmapForCommand
#endif //#ifndef acedGetCzchedBitmapForCommand

#ifndef acedGetToolTipInfoForCommand
#define acedGetToolTipInfoForCommand		zcedGetToolTipInfoForCommand
#endif //#ifndef acedGetToolTipInfoForCommand

#ifndef AcCommandToolTipInfo
#define AcCommandToolTipInfo		ZcCommandToolTipInfo
#endif //#ifndef AcCommandToolTipInfo

#ifndef AcApStatusBar
#define AcApStatusBar		ZcApStatusBar
#endif //#ifndef AcApStatusBar

#ifndef acedGetApplicationStatusBar
#define acedGetApplicationStatusBar		zcedGetApplicationStatusBar
#endif //#ifndef acedGetApplicationStatusBar

#ifndef acedDrawingStatusBarsVisible
#define acedDrawingStatusBarsVisible		zcedDrawingStatusBarsVisible
#endif //#ifndef acedDrawingStatusBarsVisible

#ifndef acedIsInputPending
#define acedIsInputPending		zcedIsInputPending
#endif //#ifndef acedIsInputPending

#ifndef acedDrawingStatusBarsVisible
#define acedDrawingStatusBarsVisible		zcedDrawingStatusBarsVisible
#endif //#ifndef acedDrawingStatusBarsVisible

#endif //_CORE_RXMFCAPI_H_H