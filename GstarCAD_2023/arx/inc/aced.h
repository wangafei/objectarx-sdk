/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/gced.h"
#include "adesk.h"
#include "acadapidef.h"  
#include "rxevent.h"   
#include "ads.h"
#include "aced-xref.h"
#include "accmd.h"
#include "aced-hatch.h"

#define ACED_SERVICES GCED_SERVICES
#define ACED_EDITOR_OBJ GCED_EDITOR_OBJ
#define AcadContextMenuMode GcadContextMenuMode
#define AcEdCommandStruc GcEdCommandStruc
#define AcString GcString
#define AcRxVariable GcRxVariable
#define AcGiImageBGRA32 GcGiImageBGRA32
#define AcEdImpSysVarIterator GcEdImpSysVarIterator
#define acedCmdLookup2 gcedCmdLookup2
#define acedCmdLookup gcedCmdLookup
#define acedCmdUndefine gcedCmdUndefine
#define acedPopCommandDirectory gcedPopCommandDirectory
#define acedGetCommandForDocument gcedGetCommandForDocument
#define acedSetOLELock gcedSetOLELock
#define acedClearOLELock gcedClearOLELock
#define acedPostCommandPrompt gcedPostCommandPrompt
#define acedSyncFileOpen gcedSyncFileOpen
#define acedSetColorDialog gcedSetColorDialog
#define acedSetColorDialogTrueColor gcedSetColorDialogTrueColor
#define AcEdColorDialogCallbackFunction GcEdColorDialogCallbackFunction
#define acedSetColorDialogTrueColorWithCallback gcedSetColorDialogTrueColorWithCallback
#define acedSetColorPrompt gcedSetColorPrompt
#define acedIsMenuGroupLoaded gcedIsMenuGroupLoaded
#define acedLoadPartialMenu gcedLoadPartialMenu
#define acedUnloadPartialMenu gcedUnloadPartialMenu
#define acedReloadMenus gcedReloadMenus
#define acedSendModelessOperationStart gcedSendModelessOperationStart
#define acedSendModelessOperationEnded gcedSendModelessOperationEnded
#define acedUpdateDisplay gcedUpdateDisplay
#define acedUpdateDisplayPause gcedUpdateDisplayPause
#define acedIsUpdateDisplayPaused gcedIsUpdateDisplayPaused
#define acedInitDialog gcedInitDialog
#define acedInitCommandVersion gcedInitCommandVersion
#define acedGetCommandVersion gcedGetCommandVersion
#define acedDisableDefaultARXExceptionHandler gcedDisableDefaultGRXExceptionHandler
#define acedVportTableRecords2Vports gcedVportTableRecords2Vports
#define acedVports2VportTableRecords gcedVports2VportTableRecords
#define acedVPLayer gcedVPLayer
#define acedServices gcedServices
#define AcEdServices GcEdServices
#define AcEditorReactor GcEditorReactor
#define AcEditorReactor2 GcEditorReactor2
#define AcEditorReactor3 GcEditorReactor3
#define acedEditor gcedEditor
#define AcEditor GcEditor
#define AcEdUIContext GcEdUIContext
#define acedAddObjectContextMenu gcedAddObjectContextMenu
#define acedRemoveObjectContextMenu gcedRemoveObjectContextMenu
#define acedAddDefaultContextMenu gcedAddDefaultContextMenu
#define acedRemoveDefaultContextMenu gcedRemoveDefaultContextMenu
#define acedSetCMBaseAlias gcedSetCMBaseAlias
#define acedGetCMBaseAlias gcedGetCMBaseAlias
#define acedMspace gcedMspace
#define acedPspace gcedPspace
#define acedSetCurrentVPort gcedSetCurrentVPort
#define acedSetCurrentVPort gcedSetCurrentVPort
#define acedIsDragging gcedIsDragging
#define acedSetCurrentView gcedSetCurrentView
#define acedRestoreCurrentView gcedRestoreCurrentView
#define acedGetCurVportCircleSides gcedGetCurVportCircleSides
#define acedSetCurVportCircleSides gcedSetCurVportCircleSides
#define acedGetCurVportPixelToDisplay gcedGetCurVportPixelToDisplay
#define acedGetCurVportScreenToDisplay gcedGetCurVportScreenToDisplay
#define acedSetCurrentUCS gcedSetCurrentUCS
#define acedGetCurrentUCS gcedGetCurrentUCS
#define acedRestorePreviousUCS gcedRestorePreviousUCS
#define acedEditToleranceInteractive gcedEditToleranceInteractive
#define acedEditMTextInteractive gcedEditMTextInteractive
#define acedEditDimstyleInteractiveEx gcedEditDimstyleInteractiveEx
#define acedGetRGB gcedGetRGB
#define acedGetCurrentSelectionSet gcedGetCurrentSelectionSet
#define acedGetFullSubentPathsForCurrentSelection gcedGetFullSubentPathsForCurrentSelection
#define acedGetIDispatch gcedGetIDispatch
#define AcadGetIDispatch GcadGetIDispatch
#define acedActiveViewportId gcedActiveViewportId
#define acedViewportIdFromNumber gcedViewportIdFromNumber
#define acedNumberOfViewports gcedNumberOfViewports
#define acedGetCurViewportObjectId gcedGetCurViewportObjectId
#define acedConvertEntityToHatch gcedConvertEntityToHatch
#define acedManageHatchEditorReactor gcedManageHatchEditorReactor
#define AcEdDrawOrderCmdType GcEdDrawOrderCmdType
#define acedDrawOrderInherit gcedDrawOrderInherit
#define acedCreateViewportByView gcedCreateViewportByView
#define acedCreateEnhancedViewportOnDrop gcedCreateEnhancedViewportOnDrop
#define acedCreateEnhancedViewportOnDropDWG gcedCreateEnhancedViewportOnDropDWG
#define acedGetUnitsValueString gcedGetUnitsValueString
#define acedGetUnitsConversion gcedGetUnitsConversion
#define acdbCanonicalToSystemRange gcdbCanonicalToSystemRange
#define acdbSystemRangeToCanonical gcdbSystemRangeToCanonical
#define acedEnableUsrbrk gcedEnableUsrbrk
#define acedDisableUsrbrk gcedDisableUsrbrk
#define acedIsUsrbrkDisabled gcedIsUsrbrkDisabled
#define acedIsInBackgroundMode gcedIsInBackgroundMode
#define acedGetBlockEditMode gcedGetBlockEditMode
#define acedOpenDocWindowsMinimized gcedOpenDocWindowsMinimized
#define acedCompareToCurrentViewport gcedCompareToCurrentViewport
#define acedGetAnimationFrameId gcedGetAnimationFrameId
#define acedShowConstraintBar gcedShowConstraintBar
#define acedHideConstraintBar gcedHideConstraintBar
#define acedShowConstraintBarForAll gcedShowConstraintBarForAll
#define acedTraceBoundary gcedTraceBoundary
#define acedSetDrawComplexShape gcedSetDrawComplexShape
#define acedGetDrawComplexShape gcedGetDrawComplexShape
#define acedSetRecursingLinetypeVectorGeneration gcedSetRecursingLinetypeVectorGeneration
#define acedGetRecursingLinetypeVectorGeneration gcedGetRecursingLinetypeVectorGeneration
#define acedGetComplexLineTypeTransformPtr gcedGetComplexLineTypeTransformPtr
#define acedAudit gcedAudit
#define acedAddSupplementalCursorImage gcedAddSupplementalCursorImage
#define acedRemoveSupplementalCursorImage gcedRemoveSupplementalCursorImage
#define acedHasSupplementalCursorImage gcedHasSupplementalCursorImage
#define acedSetSupplementalCursorOffset gcedSetSupplementalCursorOffset
#define acedGetSupplementalCursorOffset gcedGetSupplementalCursorOffset
#define acedGetDpiScalingValue gcedGetDpiScalingValue
#define acedScaleImageWithGDIPlus gcedScaleImageWithGDIPlus
#define acedSetFieldUpdateEnabled gcedSetFieldUpdateEnabled
#define acedIsFieldUpdateEnabled gcedIsFieldUpdateEnabled
#define acedGetFullSubentPathArray gcedGetFullSubentPathArray
#define acedSetIgnoredEntAndDuplicatedBlkCount gcedSetIgnoredEntAndDuplicatedBlkCount
#define AcEdSysVarIterator GcEdSysVarIterator