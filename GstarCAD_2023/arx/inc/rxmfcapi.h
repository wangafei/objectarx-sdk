/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/rxmfcapi.h"
//#include "gsoft.h"
#include "AdAChar.h"
#include "AcStatusBar.h"
#include "core_rxmfcapi.h"

#define AcColorSettings                   GcColorSettings
#define AcChildFrmSettings                GcChildFrmSettings
#define	AcDbDatabase 	GcDbDatabase
#define AcStatusBarMenuItem                GcStatusBarMenuItem
#define AcStatusBarType                    GcStatusBarType
#define AcPane                             GcPane
#define AdApplicationFrame GdApplicationFrame


#define AcApGetDatabase                   GcApGetDatabase
#define acedGetAcadWinApp  gcedGetGcadWinApp
#define acedGetAcadDoc                    gcedGetGcadDoc
#define acedGetAcadDwgView                gcedGetGcadDwgView
#define acedGetAcadFrame                  gcedGetGcadFrame
#define acedGetAcadDockCmdLine            gcedGetGcadDockCmdLine
#define acedGetAcadTextCmdLine            gcedGetGcadTextCmdLine
#define acedGetAcadBrandingResourceInstance gcedGetGcadBrandingResourceInstance
#define acedGetChildFrameSettings         gcedGetChildFrameSettings
#define acedSetChildFrameSettings         gcedSetChildFrameSettings
#define acedRegisterCustomDropTarget gcedRegisterCustomDropTarget
#define acedStartOverrideDropTarget     gcedStartOverrideDropTarget
#define acedRevokeCustomDropTarget  gcedRevokeCustomDropTarget
#define acedEndOverrideDropTarget      gcedEndOverrideDropTarget
#define acedAddDropTarget                   gcedAddDropTarget
#define acedRemoveDropTarget             gcedRemoveDropTarget

#define acedGetRegistryCompany            gcedGetRegistryCompany
#define acedRegisterExtendedTab           gcedRegisterExtendedTab
#define acedGetMenu                       gcedGetMenu
#define acedSetIUnknownForCurrentCommand  gcedSetIUnknownForCurrentCommand
#define acedGetIUnknownForCurrentCommand  gcedGetIUnknownForCurrentCommand
#define acedShowDrawingStatusBars         gcedShowDrawingStatusBars
#define acedRegisterStatusBarMenuItem     gcedRegisterStatusBarMenuItem
#define acedUnregisterStatusBarMenuItem   gcedUnregisterStatusBarMenuItem
#define acedSetStatusBarPaneID            gcedSetStatusBarPaneID
#define acedSuppressFileMRU gcedSuppressFileMRU
#define acedGetApplicationFrame gcedGetApplicationFrame
#define AcedPreTranslateMsgFn GcedPreTranslateMsgFn
#define acedRegisterMainFramePreTranslateObserver gcedRegisterMainFramePreTranslateObserver
#define acedRemoveMainFramePreTranslateObserver gcedRemoveMainFramePreTranslateObserver
