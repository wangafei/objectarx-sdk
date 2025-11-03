#pragma once

#define acedCoordFromPixelToWorld         gcedCoordFromPixelToWorld
#define acedCoordFromWorldToPixel         gcedCoordFromWorldToPixel
#define acedGetWinNum                     gcedGetWinNum
#define AcedWatchWinMsgFn                 GcedWatchWinMsgFn
#define AcedFilterWinMsgFn                GcedFilterWinMsgFn
#define AcedOnIdleMsgFn                   GcedOnIdleMsgFn
#define AcedOnModalFn                     GcedOnModalFn
#define acedRegisterFilterWinMsg          gcedRegisterFilterWinMsg
#define acedRemoveFilterWinMsg            gcedRemoveFilterWinMsg
#define acedRegisterWatchWinMsg           gcedRegisterWatchWinMsg
#define acedRemoveWatchWinMsg             gcedRemoveWatchWinMsg
#define acedRegisterOnIdleWinMsg          gcedRegisterOnIdleWinMsg
#define acedRemoveOnIdleWinMsg            gcedRemoveOnIdleWinMsg
#define AcColorSettings                   GcColorSettings
#define acedGetCurrentColors              gcedGetCurrentColors
#define acedSetCurrentColors              gcedSetCurrentColors
#define acedGetSystemColors               gcedGetSystemColors 
#define AcColorSettingsEx                 GcColorSettingsEx
#define acedGetCurrentColorsEx            gcedGetCurrentColorsEx
#define acedSetCurrentColorsEx            gcedSetCurrentColorsEx
#define acedGetSystemColorsEx             gcedGetSystemColorsEx
#define acedGetAcadDoc                    gcedGetGcadDoc
#define acedGetAcadWinApp                 gcedGetGcadWinApp
#define acedGetAcadDwgView                gcedGetGcadDwgView
#define acedGetAcadFrame                  gcedGetGcadFrame
#define acedGetAcadDockCmdLine            gcedGetGcadDockCmdLine
#define acedGetAcadTextCmdLine            gcedGetGcadTextCmdLine
#define acedGetAcadResourceInstance       gcedGetGcadResourceInstance
#define acedRegisterOnModal               gcedRegisterOnModal
#define acedRemoveOnModal                 gcedRemoveOnModal
#define acedGetChildFrameSettings         gcedGetChildFrameSettings
#define acedSetChildFrameSettings         gcedSetChildFrameSettings
#define acedStartOverrideDropTarget       gcedStartOverrideDropTarget
#define acedRegisterCustomDropTarget      gcedRegisterCustomDropTarget
#define acedRevokeCustomDropTarget        gcedRevokeCustomDropTarget
#define acedEndOverrideDropTarget         gcedEndOverrideDropTarget
#define acedAddDropTarget                 gcedAddDropTarget
#define acedRemoveDropTarget              gcedRemoveDropTarget
#define acedGetRegistryCompany            gcedGetRegistryCompany
#define acedRegisterExtendedTab           gcedRegisterExtendedTab
#define acedGetMenu                       gcedGetMenu
#define acedIsInputPending                gcedIsInputPending
#define acedSetIUnknownForCurrentCommand  gcedSetIUnknownForCurrentCommand
#define acedGetIUnknownForCurrentCommand  gcedGetIUnknownForCurrentCommand
#define acedSetStatusBarProgressMeter     gcedSetStatusBarProgressMeter
#define acedSetStatusBarProgressMeterPos  gcedSetStatusBarProgressMeterPos
#define acedGetApplicationStatusBar       gcedGetApplicationStatusBar
#define acedRestoreStatusBar              gcedRestoreStatusBar
#define acedShowDrawingStatusBars         gcedShowDrawingStatusBars
#define acedUnregisterStatusBarMenuItem   gcedUnregisterStatusBarMenuItem
#define acedSetStatusBarPaneID            gcedSetStatusBarPaneID
#define acedSuppressFileMRU               gcedSuppressFileMRU
#define AcApGetDatabase                   GcApGetDatabase
#define acedDrawingStatusBarsVisible      gcedDrawingStatusBarsVisible
#define acedRegisterStatusBarMenuItem     gcedRegisterStatusBarMenuItem
#define acedGetApplicationFrame           gcedGetApplicationFrame
#define AcChildFrmSettings                GcChildFrmSettings
#define acedDwgPoint                      gcedDwgPoint

#include "AdAChar.h"
#include "AcStatusBar.h"
#include "afxole.h"
#include "../grx/rxmfcapi.h"