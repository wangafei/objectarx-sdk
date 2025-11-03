#pragma  once

#include "adesk.h"
#include "rxnames.h"
#include "rxevent.h"
#include "accmd.h"

#include "../grx/gced.h"
#include "../grx/gcedTodo.h"


#define AcHatchNotifier  GcHatchNotifier

#define AcHatchEdReact GcHatchEdReact

#define acedEditor    gcedEditor
#define gcedEditor    odedEditor()

#define AcEdDrawOrderCmdType  GcEdDrawOrderCmdType

#define AcadContextMenuMode GcadContextMenuMode

#define acedCmdLookup gcedCmdLookup

#define acedCmdLookup2 gcedCmdLookup2

#define acedCmdUndefine gcedCmdUndefine

#define acedPopCommandDirectory gcedPopCommandDirectory

#define acedGetCommandForDocument gcedGetCommandForDocument

#define	acedPostCommand 	gcedPostCommand

#define	acedPostCommandPrompt 	gcedPostCommandPrompt

#define acedSetOLELock  gcedSetOLELock

#define acedClearOLELock gcedClearOLELock

#define	acedSyncFileOpen 	gcedSyncFileOpen

#define	acedSetColorDialog 	gcedSetColorDialog

#define	acedSetColorDialogTrueColor 	gcedSetColorDialogTrueColor

#define acedSetColorDialogTrueColorWithCallback  gcedSetColorDialogTrueColorWithCallback

#define acedSetColorPrompt gcedSetColorPrompt

#define	acedIsMenuGroupLoaded 	gcedIsMenuGroupLoaded

#define acedSendModelessOperationStart gcedSendModelessOperationStart

#define acedSendModelessOperationEnded gcedSendModelessOperationEnded

#define	acedUpdateDisplay 	gcedUpdateDisplay

#define acedUpdateDisplayPause gcedUpdateDisplayPause

#define acedInitDialog gcedInitDialog

#define acedInitCommandVersion gcedInitCommandVersion

#define acedGetCommandVersion gcedGetCommandVersion

#define	acedVportTableRecords2Vports 	gcedVportTableRecords2Vports

#define	acedVports2VportTableRecords 	gcedVports2VportTableRecords

#define acedVPLayer  gcedVPLayer


#define	acedAddObjectContextMenu 	gcedAddObjectContextMenu

#define	acedRemoveObjectContextMenu 	gcedRemoveObjectContextMenu

#define	acedAddDefaultContextMenu 	gcedAddDefaultContextMenu

#define	acedRemoveDefaultContextMenu 	gcedRemoveDefaultContextMenu

#define acedSetCMBaseAlias  gcedSetCMBaseAlias

#define acedGetCMBaseAlias  gcedGetCMBaseAlias

#define acedMspace gcedMspace

#define acedPspace gcedPspace

#define	acedSetCurrentVPort 	gcedSetCurrentVPort

#define acedIsDragging	gcedIsDragging

#define	acedSetCurrentView 	gcedSetCurrentView

#define acedRestoreCurrentView  gcedRestoreCurrentView

#define acedGetCurVportPixelToDisplay  gcedGetCurVportPixelToDisplay

#define acedGetCurVportScreenToDisplay  gcedGetCurVportScreenToDisplay

#define	acedSetCurrentUCS 	gcedSetCurrentUCS

#define	acedGetCurrentUCS 	gcedGetCurrentUCS

#define	acedRestorePreviousUCS 	gcedRestorePreviousUCS

#define acedEditToleranceInteractive  gcedEditToleranceInteractive

#define acedEditMTextInteractive gcedEditMTextInteractive

#define acedEditDimstyleInteractiveEx gcedEditDimstyleInteractiveEx

#define	acedGetRGB 	gcedGetRGB

#define	acedGetCurrentSelectionSet 	gcedGetCurrentSelectionSet

#define acedGetFullSubentPathsForCurrentSelection gcedGetFullSubentPathsForCurrentSelection

#define	acedGetIDispatch 	gcedGetIDispatch

#define acedActiveViewportId gcedActiveViewportId

#define acedNumberOfViewports  gcedNumberOfViewports

#define	acedGetCurViewportObjectId 	gcedGetCurViewportObjectId

#define acedConvertEntityToHatch  gcedConvertEntityToHatch

#define acedManageHatchEditorReactor  gcedManageHatchEditorReactor

#define acedDrawOrderInherit  gcedDrawOrderInherit

#define acedCreateViewportByView  gcedCreateViewportByView

#define acedCreateEnhancedViewportOnDrop  gcedCreateEnhancedViewportOnDrop

#define acedCreateEnhancedViewportOnDropDWG gcedCreateEnhancedViewportOnDropDWG

#define acedGetUnitsConversion gcedGetUnitsConversion

#define acdbCanonicalToSystemRange  gcdbCanonicalToSystemRange

#define acdbSystemRangeToCanonical gcdbSystemRangeToCanonical

#define acedEnableUsrbrk gcedEnableUsrbrk

#define acedDisableUsrbrk  gcedDisableUsrbrk

#define  acedIsUsrbrkDisabled  gcedIsUsrbrkDisabled

#define acedIsInBackgroundMode  gcedIsInBackgroundMode

#define acedGetBlockEditMode  gcedGetBlockEditMode

#define acedOpenDocWindowsMinimized gcedOpenDocWindowsMinimized

#define acedCompareToCurrentViewport  gcedCompareToCurrentViewport

#define acedGetAnimationFrameId  gcedGetAnimationFrameId

#define acedShowConstraintBar  gcedShowConstraintBar

#define acedGetUnitsValueString gcedGetUnitsValueString
#define acedGetCurVportCircleSides gcedGetCurVportCircleSides 
#define	AcEdUIContext 	GcEdUIContext
#define	GcEdUIContext 	OdEdUIContext

#define acedDisableDefaultARXExceptionHandler  gcedDisableDefaultARXExceptionHandler

#define	AcEdServices 	GcEdServices
#define	GcEdServices 	OdEdServices

#define	AcEditorReactor 	GcEditorReactor
#define	GcEditorReactor 	OdEditorReactor

#define	AcEditorReactor2 	GcEditorReactor2
#define	GcEditorReactor2 	OdEditorReactor2

#define	AcEditorReactor3 	GcEditorReactor3
#define	GcEditorReactor3 	OdEditorReactor3

#define	AcEditor 	GcEditor
#define	GcEditor 	OdEditor

#define acedLinetypeDialog   gcedLinetypeDialog
#define acedLineWeightDialog gcedLineWeightDialog
#define acedViewportIdFromNumber  gcedViewportIdFromNumber
#define acedIsUpdateDisplayPaused gcedIsUpdateDisplayPaused
#define acedHatchPalletteDialog   gcedHatchPalletteDialog
#define acedRegenLayers gcedRegenLayers

class CGdUiPathname;


#include "dbjig.h"
