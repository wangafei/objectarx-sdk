
#ifndef __AD_APPFRAME_H__
#define __AD_APPFRAME_H__

#include "AdExportDef.h"
#include "../../inc/zAdApplicationFrame.h"

#ifndef AdImpApplicationFrame
#define AdImpApplicationFrame		ZdImpApplicationFrame
#endif //#ifndef AdImpApplicationFrame

#ifndef AdImpMenuBar
#define AdImpMenuBar		ZdImpMenuBar
#endif //#ifndef AdImpMenuBar

#ifndef AdVisualElementBase
#define AdVisualElementBase		ZdVisualElementBase
#endif //#ifndef AdVisualElementBase

#ifndef AdColorTheme
#define AdColorTheme		ZdColorTheme
#endif //#ifndef AdColorTheme

#ifndef AdApplicationFrameReactor
#define AdApplicationFrameReactor		ZdApplicationFrameReactor
#endif //#ifndef AdApplicationFrameReactor

#ifndef AdMenuBar
#define AdMenuBar		ZdMenuBar
#endif //#ifndef AdMenuBar

#ifndef ADAF_PORT
#define ADAF_PORT		ZDAF_PORT
#endif //#ifndef ADAF_PORT

#ifndef AdCallDataTooltipInfo
#define AdCallDataTooltipInfo		ZdCallDataTooltipInfo
#endif //#ifndef AdCallDataTooltipInfo

#ifndef AdApplicationFrame
#define AdApplicationFrame		ZdApplicationFrame
#endif //#ifndef AdApplicationFrame

#ifndef Ad_AppFrame_Const
#define Ad_AppFrame_Const		Zd_AppFrame_Const
#endif //#ifndef Ad_AppFrame_Const

#ifndef kAdApplicationStatusBarHeight_Min
#define kAdApplicationStatusBarHeight_Min		kZdApplicationStatusBarHeight_Min
#endif //#ifndef kAdApplicationStatusBarHeight_Min

#ifndef kAdDefaultDpi
#define kAdDefaultDpi		kZdDefaultDpi
#endif //#ifndef kAdDefaultDpi

#ifndef Ad_HostWindow_States
#define Ad_HostWindow_States		Zd_HostWindow_States
#endif //#ifndef Ad_HostWindow_States

#ifndef kAd_DocumentActivated
#define kAd_DocumentActivated		kZd_DocumentActivated
#endif //#ifndef kAd_DocumentActivated

#ifndef kAd_MenuSelect
#define kAd_MenuSelect		kZd_MenuSelect
#endif //#ifndef kAd_MenuSelect

#ifndef kAd_MDIStateChanged
#define kAd_MDIStateChanged		kZd_MDIStateChanged
#endif //#ifndef kAd_MDIStateChanged

#ifndef kAd_WindowPosChanged
#define kAd_WindowPosChanged		kZd_WindowPosChanged
#endif //#ifndef kAd_WindowPosChanged

#ifndef kAd_SessionInit
#define kAd_SessionInit		kZd_SessionInit
#endif //#ifndef kAd_SessionInit

#ifndef kAd_SessionDone
#define kAd_SessionDone		kZd_SessionDone
#endif //#ifndef kAd_SessionDone

#ifndef kAd_SettingChanged
#define kAd_SettingChanged		kZd_SettingChanged
#endif //#ifndef kAd_SettingChanged

#ifndef kAd_MDIMetricsChanged
#define kAd_MDIMetricsChanged		kZd_MDIMetricsChanged
#endif //#ifndef kAd_MDIMetricsChanged

#ifndef kAd_SetWindowText
#define kAd_SetWindowText		kZd_SetWindowText
#endif //#ifndef kAd_SetWindowText

#ifndef kAd_VisibilityChanged
#define kAd_VisibilityChanged		kZd_VisibilityChanged
#endif //#ifndef kAd_VisibilityChanged

#ifndef kAd_GetWindowText
#define kAd_GetWindowText		kZd_GetWindowText
#endif //#ifndef kAd_GetWindowText

#ifndef kAd_GetWindowTextLen
#define kAd_GetWindowTextLen		kZd_GetWindowTextLen
#endif //#ifndef kAd_GetWindowTextLen

#ifndef kAd_SysColorChanged
#define kAd_SysColorChanged		kZd_SysColorChanged
#endif //#ifndef kAd_SysColorChanged

#ifndef Ad_AppFrame_ToolTipId
#define Ad_AppFrame_ToolTipId		Zd_AppFrame_ToolTipId
#endif //#ifndef Ad_AppFrame_ToolTipId

#ifndef kAd_ToolId_ApplicationButton
#define kAd_ToolId_ApplicationButton		kZd_ToolId_ApplicationButton
#endif //#ifndef kAd_ToolId_ApplicationButton

#ifndef Ad_Callback_Index
#define Ad_Callback_Index		Zd_Callback_Index
#endif //#ifndef Ad_Callback_Index

#ifndef kAd_ApplicationButton_IsOpen
#define kAd_ApplicationButton_IsOpen		kZd_ApplicationButton_IsOpen
#endif //#ifndef kAd_ApplicationButton_IsOpen

#ifndef kAd_ApplicationButton_ShowSmallButton
#define kAd_ApplicationButton_ShowSmallButton		kZd_ApplicationButton_ShowSmallButton
#endif //#ifndef kAd_ApplicationButton_ShowSmallButton

#ifndef kAd_ToolTip_Close
#define kAd_ToolTip_Close		kZd_ToolTip_Close
#endif //#ifndef kAd_ToolTip_Close

#ifndef kAd_ToolTip_Show
#define kAd_ToolTip_Show		kZd_ToolTip_Show
#endif //#ifndef kAd_ToolTip_Show

#ifndef kAd_MenuBar_Show
#define kAd_MenuBar_Show		kZd_MenuBar_Show
#endif //#ifndef kAd_MenuBar_Show

#ifndef kAd_MenuBar_ExecuteMenuItem
#define kAd_MenuBar_ExecuteMenuItem		kZd_MenuBar_ExecuteMenuItem
#endif //#ifndef kAd_MenuBar_ExecuteMenuItem

#ifndef kAd_WorkSpaceInfo
#define kAd_WorkSpaceInfo		kZd_WorkSpaceInfo
#endif //#ifndef kAd_WorkSpaceInfo

#ifndef kAd_GetProductName
#define kAd_GetProductName		kZd_GetProductName
#endif //#ifndef kAd_GetProductName

#ifndef kAd_Ribbon_IsDockedTop
#define kAd_Ribbon_IsDockedTop		kZd_Ribbon_IsDockedTop
#endif //#ifndef kAd_Ribbon_IsDockedTop

#ifndef kAd_Ribbon_IsDockedTop
#define kAd_Ribbon_IsDockedTop		kZd_Ribbon_IsDockedTop
#endif //#ifndef kAd_Ribbon_IsDockedTop

#ifndef kAd_ACAD_InPlotPreview
#define kAd_ACAD_InPlotPreview		kZd_ZCAD_InPlotPreview
#endif //#ifndef kAd_ACAD_InPlotPreview

#ifndef kAd_ACAD_GetDataSource
#define kAd_ACAD_GetDataSource		kZd_ZCAD_GetDataSource
#endif //#ifndef kAd_ACAD_GetDataSource

#ifndef kAd_RecalcLayout
#define kAd_RecalcLayout		kZd_RecalcLayout
#endif //#ifndef kAd_RecalcLayout

#ifndef kAd_StayActive
#define kAd_StayActive		kZd_StayActive
#endif //#ifndef kAd_StayActive

#ifndef kAd_GetMDIClient
#define kAd_GetMDIClient		kZd_GetMDIClient
#endif //#ifndef kAd_GetMDIClient

#ifndef kAd_MDIGetActive
#define kAd_MDIGetActive		kZd_MDIGetActive
#endif //#ifndef kAd_MDIGetActive

#ifndef kAd_SkipStandardBackgroundDraw
#define kAd_SkipStandardBackgroundDraw		kZd_SkipStandardBackgroundDraw
#endif //#ifndef kAd_SkipStandardBackgroundDraw

#ifndef kAd_SkipProductNameUpdate
#define kAd_SkipProductNameUpdate		kZd_SkipProductNameUpdate
#endif //#ifndef kAd_SkipProductNameUpdate

#ifndef Ad_Product_Character_Set
#define Ad_Product_Character_Set		Zd_Product_Character_Set
#endif //#ifndef Ad_Product_Character_Set

#ifndef kAd_Unicode
#define kAd_Unicode		kZd_Unicode
#endif //#ifndef kAd_Unicode

#ifndef kAd_MBCS
#define kAd_MBCS		kZd_MBCS
#endif //#ifndef kAd_MBCS

#endif
