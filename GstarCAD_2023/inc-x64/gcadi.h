

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Drawing\Extensions\win\gcax\gcadi.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __gcadi_h__
#define __gcadi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IGcadPlaneSurface_FWD_DEFINED__
#define __IGcadPlaneSurface_FWD_DEFINED__
typedef interface IGcadPlaneSurface IGcadPlaneSurface;

#endif 	/* __IGcadPlaneSurface_FWD_DEFINED__ */


#ifndef __IGcadExtrudedSurface_FWD_DEFINED__
#define __IGcadExtrudedSurface_FWD_DEFINED__
typedef interface IGcadExtrudedSurface IGcadExtrudedSurface;

#endif 	/* __IGcadExtrudedSurface_FWD_DEFINED__ */


#ifndef __IGcadRevolvedSurface_FWD_DEFINED__
#define __IGcadRevolvedSurface_FWD_DEFINED__
typedef interface IGcadRevolvedSurface IGcadRevolvedSurface;

#endif 	/* __IGcadRevolvedSurface_FWD_DEFINED__ */


#ifndef __IGcadSweptSurface_FWD_DEFINED__
#define __IGcadSweptSurface_FWD_DEFINED__
typedef interface IGcadSweptSurface IGcadSweptSurface;

#endif 	/* __IGcadSweptSurface_FWD_DEFINED__ */


#ifndef __IGcadLoftedSurface_FWD_DEFINED__
#define __IGcadLoftedSurface_FWD_DEFINED__
typedef interface IGcadLoftedSurface IGcadLoftedSurface;

#endif 	/* __IGcadLoftedSurface_FWD_DEFINED__ */


#ifndef __IGcadNurbSurface_FWD_DEFINED__
#define __IGcadNurbSurface_FWD_DEFINED__
typedef interface IGcadNurbSurface IGcadNurbSurface;

#endif 	/* __IGcadNurbSurface_FWD_DEFINED__ */


#ifndef __IGcadPointCloudEx_FWD_DEFINED__
#define __IGcadPointCloudEx_FWD_DEFINED__
typedef interface IGcadPointCloudEx IGcadPointCloudEx;

#endif 	/* __IGcadPointCloudEx_FWD_DEFINED__ */


#ifndef __IGcadApplication_FWD_DEFINED__
#define __IGcadApplication_FWD_DEFINED__
typedef interface IGcadApplication IGcadApplication;

#endif 	/* __IGcadApplication_FWD_DEFINED__ */


#ifndef __IGcadMenuGroups_FWD_DEFINED__
#define __IGcadMenuGroups_FWD_DEFINED__
typedef interface IGcadMenuGroups IGcadMenuGroups;

#endif 	/* __IGcadMenuGroups_FWD_DEFINED__ */


#ifndef __IGcadDocuments_FWD_DEFINED__
#define __IGcadDocuments_FWD_DEFINED__
typedef interface IGcadDocuments IGcadDocuments;

#endif 	/* __IGcadDocuments_FWD_DEFINED__ */


#ifndef __IGcadState_FWD_DEFINED__
#define __IGcadState_FWD_DEFINED__
typedef interface IGcadState IGcadState;

#endif 	/* __IGcadState_FWD_DEFINED__ */


#ifndef __IGcadPlot_FWD_DEFINED__
#define __IGcadPlot_FWD_DEFINED__
typedef interface IGcadPlot IGcadPlot;

#endif 	/* __IGcadPlot_FWD_DEFINED__ */


#ifndef __IGcadSelectionSets_FWD_DEFINED__
#define __IGcadSelectionSets_FWD_DEFINED__
typedef interface IGcadSelectionSets IGcadSelectionSets;

#endif 	/* __IGcadSelectionSets_FWD_DEFINED__ */


#ifndef __IGcadSelectionSet_FWD_DEFINED__
#define __IGcadSelectionSet_FWD_DEFINED__
typedef interface IGcadSelectionSet IGcadSelectionSet;

#endif 	/* __IGcadSelectionSet_FWD_DEFINED__ */


#ifndef __IGcadUtility_FWD_DEFINED__
#define __IGcadUtility_FWD_DEFINED__
typedef interface IGcadUtility IGcadUtility;

#endif 	/* __IGcadUtility_FWD_DEFINED__ */


#ifndef __IGcadDocument_FWD_DEFINED__
#define __IGcadDocument_FWD_DEFINED__
typedef interface IGcadDocument IGcadDocument;

#endif 	/* __IGcadDocument_FWD_DEFINED__ */


#ifndef __IGcadDynamicBlockReferenceProperty_FWD_DEFINED__
#define __IGcadDynamicBlockReferenceProperty_FWD_DEFINED__
typedef interface IGcadDynamicBlockReferenceProperty IGcadDynamicBlockReferenceProperty;

#endif 	/* __IGcadDynamicBlockReferenceProperty_FWD_DEFINED__ */


#ifndef __IGcadSortentsTable_FWD_DEFINED__
#define __IGcadSortentsTable_FWD_DEFINED__
typedef interface IGcadSortentsTable IGcadSortentsTable;

#endif 	/* __IGcadSortentsTable_FWD_DEFINED__ */


#ifndef __IGcadIdPair_FWD_DEFINED__
#define __IGcadIdPair_FWD_DEFINED__
typedef interface IGcadIdPair IGcadIdPair;

#endif 	/* __IGcadIdPair_FWD_DEFINED__ */


#ifndef __IGcadTableStyle_FWD_DEFINED__
#define __IGcadTableStyle_FWD_DEFINED__
typedef interface IGcadTableStyle IGcadTableStyle;

#endif 	/* __IGcadTableStyle_FWD_DEFINED__ */


#ifndef __IGcadShadowDisplay_FWD_DEFINED__
#define __IGcadShadowDisplay_FWD_DEFINED__
typedef interface IGcadShadowDisplay IGcadShadowDisplay;

#endif 	/* __IGcadShadowDisplay_FWD_DEFINED__ */


#ifndef __IGcadPreferencesProfiles_FWD_DEFINED__
#define __IGcadPreferencesProfiles_FWD_DEFINED__
typedef interface IGcadPreferencesProfiles IGcadPreferencesProfiles;

#endif 	/* __IGcadPreferencesProfiles_FWD_DEFINED__ */


#ifndef __IGcadPreferences_FWD_DEFINED__
#define __IGcadPreferences_FWD_DEFINED__
typedef interface IGcadPreferences IGcadPreferences;

#endif 	/* __IGcadPreferences_FWD_DEFINED__ */


#ifndef __IGcadPreferencesDrafting_FWD_DEFINED__
#define __IGcadPreferencesDrafting_FWD_DEFINED__
typedef interface IGcadPreferencesDrafting IGcadPreferencesDrafting;

#endif 	/* __IGcadPreferencesDrafting_FWD_DEFINED__ */


#ifndef __IGcadPreferencesDisplay_FWD_DEFINED__
#define __IGcadPreferencesDisplay_FWD_DEFINED__
typedef interface IGcadPreferencesDisplay IGcadPreferencesDisplay;

#endif 	/* __IGcadPreferencesDisplay_FWD_DEFINED__ */


#ifndef __IGcadPreferencesFiles_FWD_DEFINED__
#define __IGcadPreferencesFiles_FWD_DEFINED__
typedef interface IGcadPreferencesFiles IGcadPreferencesFiles;

#endif 	/* __IGcadPreferencesFiles_FWD_DEFINED__ */


#ifndef __IGcadPreferencesOpenSave_FWD_DEFINED__
#define __IGcadPreferencesOpenSave_FWD_DEFINED__
typedef interface IGcadPreferencesOpenSave IGcadPreferencesOpenSave;

#endif 	/* __IGcadPreferencesOpenSave_FWD_DEFINED__ */


#ifndef __IGcadPreferencesOutput_FWD_DEFINED__
#define __IGcadPreferencesOutput_FWD_DEFINED__
typedef interface IGcadPreferencesOutput IGcadPreferencesOutput;

#endif 	/* __IGcadPreferencesOutput_FWD_DEFINED__ */


#ifndef __IGcadPreferencesSystem_FWD_DEFINED__
#define __IGcadPreferencesSystem_FWD_DEFINED__
typedef interface IGcadPreferencesSystem IGcadPreferencesSystem;

#endif 	/* __IGcadPreferencesSystem_FWD_DEFINED__ */


#ifndef __IGcadPreferencesUser_FWD_DEFINED__
#define __IGcadPreferencesUser_FWD_DEFINED__
typedef interface IGcadPreferencesUser IGcadPreferencesUser;

#endif 	/* __IGcadPreferencesUser_FWD_DEFINED__ */


#ifndef __IGcadPreferencesSelection_FWD_DEFINED__
#define __IGcadPreferencesSelection_FWD_DEFINED__
typedef interface IGcadPreferencesSelection IGcadPreferencesSelection;

#endif 	/* __IGcadPreferencesSelection_FWD_DEFINED__ */


#ifndef __IGcadMenuGroup_FWD_DEFINED__
#define __IGcadMenuGroup_FWD_DEFINED__
typedef interface IGcadMenuGroup IGcadMenuGroup;

#endif 	/* __IGcadMenuGroup_FWD_DEFINED__ */


#ifndef __IGcadPopupMenus_FWD_DEFINED__
#define __IGcadPopupMenus_FWD_DEFINED__
typedef interface IGcadPopupMenus IGcadPopupMenus;

#endif 	/* __IGcadPopupMenus_FWD_DEFINED__ */


#ifndef __IGcadPopupMenu_FWD_DEFINED__
#define __IGcadPopupMenu_FWD_DEFINED__
typedef interface IGcadPopupMenu IGcadPopupMenu;

#endif 	/* __IGcadPopupMenu_FWD_DEFINED__ */


#ifndef __IGcadPopupMenuItem_FWD_DEFINED__
#define __IGcadPopupMenuItem_FWD_DEFINED__
typedef interface IGcadPopupMenuItem IGcadPopupMenuItem;

#endif 	/* __IGcadPopupMenuItem_FWD_DEFINED__ */


#ifndef __IGcadToolbars_FWD_DEFINED__
#define __IGcadToolbars_FWD_DEFINED__
typedef interface IGcadToolbars IGcadToolbars;

#endif 	/* __IGcadToolbars_FWD_DEFINED__ */


#ifndef __IGcadToolbar_FWD_DEFINED__
#define __IGcadToolbar_FWD_DEFINED__
typedef interface IGcadToolbar IGcadToolbar;

#endif 	/* __IGcadToolbar_FWD_DEFINED__ */


#ifndef __IGcadToolbarItem_FWD_DEFINED__
#define __IGcadToolbarItem_FWD_DEFINED__
typedef interface IGcadToolbarItem IGcadToolbarItem;

#endif 	/* __IGcadToolbarItem_FWD_DEFINED__ */


#ifndef __IGcadMenuBar_FWD_DEFINED__
#define __IGcadMenuBar_FWD_DEFINED__
typedef interface IGcadMenuBar IGcadMenuBar;

#endif 	/* __IGcadMenuBar_FWD_DEFINED__ */


#ifndef __IGcadSecurityParams_FWD_DEFINED__
#define __IGcadSecurityParams_FWD_DEFINED__
typedef interface IGcadSecurityParams IGcadSecurityParams;

#endif 	/* __IGcadSecurityParams_FWD_DEFINED__ */


#ifndef __IGcadScriptJet_FWD_DEFINED__
#define __IGcadScriptJet_FWD_DEFINED__
typedef interface IGcadScriptJet IGcadScriptJet;

#endif 	/* __IGcadScriptJet_FWD_DEFINED__ */


#ifndef __IGcadLayerStateManager_FWD_DEFINED__
#define __IGcadLayerStateManager_FWD_DEFINED__
typedef interface IGcadLayerStateManager IGcadLayerStateManager;

#endif 	/* __IGcadLayerStateManager_FWD_DEFINED__ */


#ifndef ___DGcadApplicationEvents_FWD_DEFINED__
#define ___DGcadApplicationEvents_FWD_DEFINED__
typedef interface _DGcadApplicationEvents _DGcadApplicationEvents;

#endif 	/* ___DGcadApplicationEvents_FWD_DEFINED__ */


#ifndef __GcadApplication_FWD_DEFINED__
#define __GcadApplication_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadApplication GcadApplication;
#else
typedef struct GcadApplication GcadApplication;
#endif /* __cplusplus */

#endif 	/* __GcadApplication_FWD_DEFINED__ */


#ifndef __GcadMenuGroups_FWD_DEFINED__
#define __GcadMenuGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMenuGroups GcadMenuGroups;
#else
typedef struct GcadMenuGroups GcadMenuGroups;
#endif /* __cplusplus */

#endif 	/* __GcadMenuGroups_FWD_DEFINED__ */


#ifndef __GcadMenuBar_FWD_DEFINED__
#define __GcadMenuBar_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMenuBar GcadMenuBar;
#else
typedef struct GcadMenuBar GcadMenuBar;
#endif /* __cplusplus */

#endif 	/* __GcadMenuBar_FWD_DEFINED__ */


#ifndef __GcadDocuments_FWD_DEFINED__
#define __GcadDocuments_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDocuments GcadDocuments;
#else
typedef struct GcadDocuments GcadDocuments;
#endif /* __cplusplus */

#endif 	/* __GcadDocuments_FWD_DEFINED__ */


#ifndef __GcadDatabase_FWD_DEFINED__
#define __GcadDatabase_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDatabase GcadDatabase;
#else
typedef struct GcadDatabase GcadDatabase;
#endif /* __cplusplus */

#endif 	/* __GcadDatabase_FWD_DEFINED__ */


#ifndef __GcadModelSpace_FWD_DEFINED__
#define __GcadModelSpace_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadModelSpace GcadModelSpace;
#else
typedef struct GcadModelSpace GcadModelSpace;
#endif /* __cplusplus */

#endif 	/* __GcadModelSpace_FWD_DEFINED__ */


#ifndef __GcadPaperSpace_FWD_DEFINED__
#define __GcadPaperSpace_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPaperSpace GcadPaperSpace;
#else
typedef struct GcadPaperSpace GcadPaperSpace;
#endif /* __cplusplus */

#endif 	/* __GcadPaperSpace_FWD_DEFINED__ */


#ifndef __GcadBlocks_FWD_DEFINED__
#define __GcadBlocks_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadBlocks GcadBlocks;
#else
typedef struct GcadBlocks GcadBlocks;
#endif /* __cplusplus */

#endif 	/* __GcadBlocks_FWD_DEFINED__ */


#ifndef __GcadGroups_FWD_DEFINED__
#define __GcadGroups_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadGroups GcadGroups;
#else
typedef struct GcadGroups GcadGroups;
#endif /* __cplusplus */

#endif 	/* __GcadGroups_FWD_DEFINED__ */


#ifndef __GcadDimStyles_FWD_DEFINED__
#define __GcadDimStyles_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimStyles GcadDimStyles;
#else
typedef struct GcadDimStyles GcadDimStyles;
#endif /* __cplusplus */

#endif 	/* __GcadDimStyles_FWD_DEFINED__ */


#ifndef __GcadLayers_FWD_DEFINED__
#define __GcadLayers_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLayers GcadLayers;
#else
typedef struct GcadLayers GcadLayers;
#endif /* __cplusplus */

#endif 	/* __GcadLayers_FWD_DEFINED__ */


#ifndef __GcadLineTypes_FWD_DEFINED__
#define __GcadLineTypes_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLineTypes GcadLineTypes;
#else
typedef struct GcadLineTypes GcadLineTypes;
#endif /* __cplusplus */

#endif 	/* __GcadLineTypes_FWD_DEFINED__ */


#ifndef __GcadDictionaries_FWD_DEFINED__
#define __GcadDictionaries_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDictionaries GcadDictionaries;
#else
typedef struct GcadDictionaries GcadDictionaries;
#endif /* __cplusplus */

#endif 	/* __GcadDictionaries_FWD_DEFINED__ */


#ifndef __GcadRegisteredApplication_FWD_DEFINED__
#define __GcadRegisteredApplication_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRegisteredApplication GcadRegisteredApplication;
#else
typedef struct GcadRegisteredApplication GcadRegisteredApplication;
#endif /* __cplusplus */

#endif 	/* __GcadRegisteredApplication_FWD_DEFINED__ */


#ifndef __GcadRegisteredApplications_FWD_DEFINED__
#define __GcadRegisteredApplications_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRegisteredApplications GcadRegisteredApplications;
#else
typedef struct GcadRegisteredApplications GcadRegisteredApplications;
#endif /* __cplusplus */

#endif 	/* __GcadRegisteredApplications_FWD_DEFINED__ */


#ifndef __GcadTextStyles_FWD_DEFINED__
#define __GcadTextStyles_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTextStyles GcadTextStyles;
#else
typedef struct GcadTextStyles GcadTextStyles;
#endif /* __cplusplus */

#endif 	/* __GcadTextStyles_FWD_DEFINED__ */


#ifndef __GcadUCSs_FWD_DEFINED__
#define __GcadUCSs_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadUCSs GcadUCSs;
#else
typedef struct GcadUCSs GcadUCSs;
#endif /* __cplusplus */

#endif 	/* __GcadUCSs_FWD_DEFINED__ */


#ifndef __GcadViews_FWD_DEFINED__
#define __GcadViews_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadViews GcadViews;
#else
typedef struct GcadViews GcadViews;
#endif /* __cplusplus */

#endif 	/* __GcadViews_FWD_DEFINED__ */


#ifndef __GcadViewports_FWD_DEFINED__
#define __GcadViewports_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadViewports GcadViewports;
#else
typedef struct GcadViewports GcadViewports;
#endif /* __cplusplus */

#endif 	/* __GcadViewports_FWD_DEFINED__ */


#ifndef __GcadLayouts_FWD_DEFINED__
#define __GcadLayouts_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLayouts GcadLayouts;
#else
typedef struct GcadLayouts GcadLayouts;
#endif /* __cplusplus */

#endif 	/* __GcadLayouts_FWD_DEFINED__ */


#ifndef __GcadPlotConfigurations_FWD_DEFINED__
#define __GcadPlotConfigurations_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPlotConfigurations GcadPlotConfigurations;
#else
typedef struct GcadPlotConfigurations GcadPlotConfigurations;
#endif /* __cplusplus */

#endif 	/* __GcadPlotConfigurations_FWD_DEFINED__ */


#ifndef __GcadDatabasePreferences_FWD_DEFINED__
#define __GcadDatabasePreferences_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDatabasePreferences GcadDatabasePreferences;
#else
typedef struct GcadDatabasePreferences GcadDatabasePreferences;
#endif /* __cplusplus */

#endif 	/* __GcadDatabasePreferences_FWD_DEFINED__ */


#ifndef __GcadFileDependencies_FWD_DEFINED__
#define __GcadFileDependencies_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadFileDependencies GcadFileDependencies;
#else
typedef struct GcadFileDependencies GcadFileDependencies;
#endif /* __cplusplus */

#endif 	/* __GcadFileDependencies_FWD_DEFINED__ */


#ifndef __GcadSummaryInfo_FWD_DEFINED__
#define __GcadSummaryInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSummaryInfo GcadSummaryInfo;
#else
typedef struct GcadSummaryInfo GcadSummaryInfo;
#endif /* __cplusplus */

#endif 	/* __GcadSummaryInfo_FWD_DEFINED__ */


#ifndef __GcadSectionManager_FWD_DEFINED__
#define __GcadSectionManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSectionManager GcadSectionManager;
#else
typedef struct GcadSectionManager GcadSectionManager;
#endif /* __cplusplus */

#endif 	/* __GcadSectionManager_FWD_DEFINED__ */


#ifndef __GcadMaterials_FWD_DEFINED__
#define __GcadMaterials_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMaterials GcadMaterials;
#else
typedef struct GcadMaterials GcadMaterials;
#endif /* __cplusplus */

#endif 	/* __GcadMaterials_FWD_DEFINED__ */


#ifndef __GcadGroup_FWD_DEFINED__
#define __GcadGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadGroup GcadGroup;
#else
typedef struct GcadGroup GcadGroup;
#endif /* __cplusplus */

#endif 	/* __GcadGroup_FWD_DEFINED__ */


#ifndef __GcadPlot_FWD_DEFINED__
#define __GcadPlot_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPlot GcadPlot;
#else
typedef struct GcadPlot GcadPlot;
#endif /* __cplusplus */

#endif 	/* __GcadPlot_FWD_DEFINED__ */


#ifndef __GcadLayer_FWD_DEFINED__
#define __GcadLayer_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLayer GcadLayer;
#else
typedef struct GcadLayer GcadLayer;
#endif /* __cplusplus */

#endif 	/* __GcadLayer_FWD_DEFINED__ */


#ifndef __GcadLineType_FWD_DEFINED__
#define __GcadLineType_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLineType GcadLineType;
#else
typedef struct GcadLineType GcadLineType;
#endif /* __cplusplus */

#endif 	/* __GcadLineType_FWD_DEFINED__ */


#ifndef __GcadDimStyle_FWD_DEFINED__
#define __GcadDimStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimStyle GcadDimStyle;
#else
typedef struct GcadDimStyle GcadDimStyle;
#endif /* __cplusplus */

#endif 	/* __GcadDimStyle_FWD_DEFINED__ */


#ifndef __GcadMLeaderStyle_FWD_DEFINED__
#define __GcadMLeaderStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMLeaderStyle GcadMLeaderStyle;
#else
typedef struct GcadMLeaderStyle GcadMLeaderStyle;
#endif /* __cplusplus */

#endif 	/* __GcadMLeaderStyle_FWD_DEFINED__ */


#ifndef __GcadTextStyle_FWD_DEFINED__
#define __GcadTextStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTextStyle GcadTextStyle;
#else
typedef struct GcadTextStyle GcadTextStyle;
#endif /* __cplusplus */

#endif 	/* __GcadTextStyle_FWD_DEFINED__ */


#ifndef __GcadUCS_FWD_DEFINED__
#define __GcadUCS_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadUCS GcadUCS;
#else
typedef struct GcadUCS GcadUCS;
#endif /* __cplusplus */

#endif 	/* __GcadUCS_FWD_DEFINED__ */


#ifndef __GcadViewport_FWD_DEFINED__
#define __GcadViewport_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadViewport GcadViewport;
#else
typedef struct GcadViewport GcadViewport;
#endif /* __cplusplus */

#endif 	/* __GcadViewport_FWD_DEFINED__ */


#ifndef __GcadPViewport_FWD_DEFINED__
#define __GcadPViewport_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPViewport GcadPViewport;
#else
typedef struct GcadPViewport GcadPViewport;
#endif /* __cplusplus */

#endif 	/* __GcadPViewport_FWD_DEFINED__ */


#ifndef __GcadUtility_FWD_DEFINED__
#define __GcadUtility_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadUtility GcadUtility;
#else
typedef struct GcadUtility GcadUtility;
#endif /* __cplusplus */

#endif 	/* __GcadUtility_FWD_DEFINED__ */


#ifndef __GcadMaterial_FWD_DEFINED__
#define __GcadMaterial_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMaterial GcadMaterial;
#else
typedef struct GcadMaterial GcadMaterial;
#endif /* __cplusplus */

#endif 	/* __GcadMaterial_FWD_DEFINED__ */


#ifndef __GcadLayout_FWD_DEFINED__
#define __GcadLayout_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLayout GcadLayout;
#else
typedef struct GcadLayout GcadLayout;
#endif /* __cplusplus */

#endif 	/* __GcadLayout_FWD_DEFINED__ */


#ifndef ___DGcadDocumentEvents_FWD_DEFINED__
#define ___DGcadDocumentEvents_FWD_DEFINED__
typedef interface _DGcadDocumentEvents _DGcadDocumentEvents;

#endif 	/* ___DGcadDocumentEvents_FWD_DEFINED__ */


#ifndef __GcadDocument_FWD_DEFINED__
#define __GcadDocument_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDocument GcadDocument;
#else
typedef struct GcadDocument GcadDocument;
#endif /* __cplusplus */

#endif 	/* __GcadDocument_FWD_DEFINED__ */


#ifndef __GcadObject_FWD_DEFINED__
#define __GcadObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadObject GcadObject;
#else
typedef struct GcadObject GcadObject;
#endif /* __cplusplus */

#endif 	/* __GcadObject_FWD_DEFINED__ */


#ifndef __GcadEntity_FWD_DEFINED__
#define __GcadEntity_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadEntity GcadEntity;
#else
typedef struct GcadEntity GcadEntity;
#endif /* __cplusplus */

#endif 	/* __GcadEntity_FWD_DEFINED__ */


#ifndef __GcadAcCmColor_FWD_DEFINED__
#define __GcadAcCmColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAcCmColor GcadAcCmColor;
#else
typedef struct GcadAcCmColor GcadAcCmColor;
#endif /* __cplusplus */

#endif 	/* __GcadAcCmColor_FWD_DEFINED__ */


#ifndef __GcadHyperlinks_FWD_DEFINED__
#define __GcadHyperlinks_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadHyperlinks GcadHyperlinks;
#else
typedef struct GcadHyperlinks GcadHyperlinks;
#endif /* __cplusplus */

#endif 	/* __GcadHyperlinks_FWD_DEFINED__ */


#ifndef __GcadLine_FWD_DEFINED__
#define __GcadLine_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLine GcadLine;
#else
typedef struct GcadLine GcadLine;
#endif /* __cplusplus */

#endif 	/* __GcadLine_FWD_DEFINED__ */


#ifndef __GcadPlotConfiguration_FWD_DEFINED__
#define __GcadPlotConfiguration_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPlotConfiguration GcadPlotConfiguration;
#else
typedef struct GcadPlotConfiguration GcadPlotConfiguration;
#endif /* __cplusplus */

#endif 	/* __GcadPlotConfiguration_FWD_DEFINED__ */


#ifndef __GcadBlock_FWD_DEFINED__
#define __GcadBlock_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadBlock GcadBlock;
#else
typedef struct GcadBlock GcadBlock;
#endif /* __cplusplus */

#endif 	/* __GcadBlock_FWD_DEFINED__ */


#ifndef __GcadState_FWD_DEFINED__
#define __GcadState_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadState GcadState;
#else
typedef struct GcadState GcadState;
#endif /* __cplusplus */

#endif 	/* __GcadState_FWD_DEFINED__ */


#ifndef __GcadSelectionSet_FWD_DEFINED__
#define __GcadSelectionSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSelectionSet GcadSelectionSet;
#else
typedef struct GcadSelectionSet GcadSelectionSet;
#endif /* __cplusplus */

#endif 	/* __GcadSelectionSet_FWD_DEFINED__ */


#ifndef __GcadSelectionSets_FWD_DEFINED__
#define __GcadSelectionSets_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSelectionSets GcadSelectionSets;
#else
typedef struct GcadSelectionSets GcadSelectionSets;
#endif /* __cplusplus */

#endif 	/* __GcadSelectionSets_FWD_DEFINED__ */


#ifndef __GcadPreferences_FWD_DEFINED__
#define __GcadPreferences_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferences GcadPreferences;
#else
typedef struct GcadPreferences GcadPreferences;
#endif /* __cplusplus */

#endif 	/* __GcadPreferences_FWD_DEFINED__ */


#ifndef __GcadPreferencesDrafting_FWD_DEFINED__
#define __GcadPreferencesDrafting_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesDrafting GcadPreferencesDrafting;
#else
typedef struct GcadPreferencesDrafting GcadPreferencesDrafting;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesDrafting_FWD_DEFINED__ */


#ifndef __GcadPreferencesDisplay_FWD_DEFINED__
#define __GcadPreferencesDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesDisplay GcadPreferencesDisplay;
#else
typedef struct GcadPreferencesDisplay GcadPreferencesDisplay;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesDisplay_FWD_DEFINED__ */


#ifndef __GcadPreferencesFiles_FWD_DEFINED__
#define __GcadPreferencesFiles_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesFiles GcadPreferencesFiles;
#else
typedef struct GcadPreferencesFiles GcadPreferencesFiles;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesFiles_FWD_DEFINED__ */


#ifndef __GcadPreferencesOpenSave_FWD_DEFINED__
#define __GcadPreferencesOpenSave_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesOpenSave GcadPreferencesOpenSave;
#else
typedef struct GcadPreferencesOpenSave GcadPreferencesOpenSave;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesOpenSave_FWD_DEFINED__ */


#ifndef __GcadPreferencesOutput_FWD_DEFINED__
#define __GcadPreferencesOutput_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesOutput GcadPreferencesOutput;
#else
typedef struct GcadPreferencesOutput GcadPreferencesOutput;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesOutput_FWD_DEFINED__ */


#ifndef __GcadPreferencesProfiles_FWD_DEFINED__
#define __GcadPreferencesProfiles_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesProfiles GcadPreferencesProfiles;
#else
typedef struct GcadPreferencesProfiles GcadPreferencesProfiles;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesProfiles_FWD_DEFINED__ */


#ifndef __GcadPreferencesSelection_FWD_DEFINED__
#define __GcadPreferencesSelection_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesSelection GcadPreferencesSelection;
#else
typedef struct GcadPreferencesSelection GcadPreferencesSelection;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesSelection_FWD_DEFINED__ */


#ifndef __GcadPreferencesSystem_FWD_DEFINED__
#define __GcadPreferencesSystem_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesSystem GcadPreferencesSystem;
#else
typedef struct GcadPreferencesSystem GcadPreferencesSystem;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesSystem_FWD_DEFINED__ */


#ifndef __GcadPreferencesUser_FWD_DEFINED__
#define __GcadPreferencesUser_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPreferencesUser GcadPreferencesUser;
#else
typedef struct GcadPreferencesUser GcadPreferencesUser;
#endif /* __cplusplus */

#endif 	/* __GcadPreferencesUser_FWD_DEFINED__ */


#ifndef __GcadMenuGroup_FWD_DEFINED__
#define __GcadMenuGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMenuGroup GcadMenuGroup;
#else
typedef struct GcadMenuGroup GcadMenuGroup;
#endif /* __cplusplus */

#endif 	/* __GcadMenuGroup_FWD_DEFINED__ */


#ifndef __GcadPopupMenus_FWD_DEFINED__
#define __GcadPopupMenus_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPopupMenus GcadPopupMenus;
#else
typedef struct GcadPopupMenus GcadPopupMenus;
#endif /* __cplusplus */

#endif 	/* __GcadPopupMenus_FWD_DEFINED__ */


#ifndef __GcadPopupMenu_FWD_DEFINED__
#define __GcadPopupMenu_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPopupMenu GcadPopupMenu;
#else
typedef struct GcadPopupMenu GcadPopupMenu;
#endif /* __cplusplus */

#endif 	/* __GcadPopupMenu_FWD_DEFINED__ */


#ifndef __GcadPopupMenuItem_FWD_DEFINED__
#define __GcadPopupMenuItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPopupMenuItem GcadPopupMenuItem;
#else
typedef struct GcadPopupMenuItem GcadPopupMenuItem;
#endif /* __cplusplus */

#endif 	/* __GcadPopupMenuItem_FWD_DEFINED__ */


#ifndef __GcadMText_FWD_DEFINED__
#define __GcadMText_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMText GcadMText;
#else
typedef struct GcadMText GcadMText;
#endif /* __cplusplus */

#endif 	/* __GcadMText_FWD_DEFINED__ */


#ifndef __GcadBlockReference_FWD_DEFINED__
#define __GcadBlockReference_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadBlockReference GcadBlockReference;
#else
typedef struct GcadBlockReference GcadBlockReference;
#endif /* __cplusplus */

#endif 	/* __GcadBlockReference_FWD_DEFINED__ */


#ifndef __GcadCircle_FWD_DEFINED__
#define __GcadCircle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadCircle GcadCircle;
#else
typedef struct GcadCircle GcadCircle;
#endif /* __cplusplus */

#endif 	/* __GcadCircle_FWD_DEFINED__ */


#ifndef __GcadShadowDisplay_FWD_DEFINED__
#define __GcadShadowDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadShadowDisplay GcadShadowDisplay;
#else
typedef struct GcadShadowDisplay GcadShadowDisplay;
#endif /* __cplusplus */

#endif 	/* __GcadShadowDisplay_FWD_DEFINED__ */


#ifndef __GcadHyperlink_FWD_DEFINED__
#define __GcadHyperlink_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadHyperlink GcadHyperlink;
#else
typedef struct GcadHyperlink GcadHyperlink;
#endif /* __cplusplus */

#endif 	/* __GcadHyperlink_FWD_DEFINED__ */


#ifndef __GcadDynamicBlockReferenceProperty_FWD_DEFINED__
#define __GcadDynamicBlockReferenceProperty_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDynamicBlockReferenceProperty GcadDynamicBlockReferenceProperty;
#else
typedef struct GcadDynamicBlockReferenceProperty GcadDynamicBlockReferenceProperty;
#endif /* __cplusplus */

#endif 	/* __GcadDynamicBlockReferenceProperty_FWD_DEFINED__ */


#ifndef __GcadXRecord_FWD_DEFINED__
#define __GcadXRecord_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadXRecord GcadXRecord;
#else
typedef struct GcadXRecord GcadXRecord;
#endif /* __cplusplus */

#endif 	/* __GcadXRecord_FWD_DEFINED__ */


#ifndef __GcadSectionSettings_FWD_DEFINED__
#define __GcadSectionSettings_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSectionSettings GcadSectionSettings;
#else
typedef struct GcadSectionSettings GcadSectionSettings;
#endif /* __cplusplus */

#endif 	/* __GcadSectionSettings_FWD_DEFINED__ */


#ifndef __GcadRasterImage_FWD_DEFINED__
#define __GcadRasterImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRasterImage GcadRasterImage;
#else
typedef struct GcadRasterImage GcadRasterImage;
#endif /* __cplusplus */

#endif 	/* __GcadRasterImage_FWD_DEFINED__ */


#ifndef __Gcad3DFace_FWD_DEFINED__
#define __Gcad3DFace_FWD_DEFINED__

#ifdef __cplusplus
typedef class Gcad3DFace Gcad3DFace;
#else
typedef struct Gcad3DFace Gcad3DFace;
#endif /* __cplusplus */

#endif 	/* __Gcad3DFace_FWD_DEFINED__ */


#ifndef __Gcad3DPolyline_FWD_DEFINED__
#define __Gcad3DPolyline_FWD_DEFINED__

#ifdef __cplusplus
typedef class Gcad3DPolyline Gcad3DPolyline;
#else
typedef struct Gcad3DPolyline Gcad3DPolyline;
#endif /* __cplusplus */

#endif 	/* __Gcad3DPolyline_FWD_DEFINED__ */


#ifndef __GcadRegion_FWD_DEFINED__
#define __GcadRegion_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRegion GcadRegion;
#else
typedef struct GcadRegion GcadRegion;
#endif /* __cplusplus */

#endif 	/* __GcadRegion_FWD_DEFINED__ */


#ifndef __Gcad3DSolid_FWD_DEFINED__
#define __Gcad3DSolid_FWD_DEFINED__

#ifdef __cplusplus
typedef class Gcad3DSolid Gcad3DSolid;
#else
typedef struct Gcad3DSolid Gcad3DSolid;
#endif /* __cplusplus */

#endif 	/* __Gcad3DSolid_FWD_DEFINED__ */


#ifndef __GcadArc_FWD_DEFINED__
#define __GcadArc_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadArc GcadArc;
#else
typedef struct GcadArc GcadArc;
#endif /* __cplusplus */

#endif 	/* __GcadArc_FWD_DEFINED__ */


#ifndef __GcadAttribute_FWD_DEFINED__
#define __GcadAttribute_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAttribute GcadAttribute;
#else
typedef struct GcadAttribute GcadAttribute;
#endif /* __cplusplus */

#endif 	/* __GcadAttribute_FWD_DEFINED__ */


#ifndef __GcadAttributeReference_FWD_DEFINED__
#define __GcadAttributeReference_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAttributeReference GcadAttributeReference;
#else
typedef struct GcadAttributeReference GcadAttributeReference;
#endif /* __cplusplus */

#endif 	/* __GcadAttributeReference_FWD_DEFINED__ */


#ifndef __GcadEllipse_FWD_DEFINED__
#define __GcadEllipse_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadEllipse GcadEllipse;
#else
typedef struct GcadEllipse GcadEllipse;
#endif /* __cplusplus */

#endif 	/* __GcadEllipse_FWD_DEFINED__ */


#ifndef __GcadHatch_FWD_DEFINED__
#define __GcadHatch_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadHatch GcadHatch;
#else
typedef struct GcadHatch GcadHatch;
#endif /* __cplusplus */

#endif 	/* __GcadHatch_FWD_DEFINED__ */


#ifndef __GcadLeader_FWD_DEFINED__
#define __GcadLeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLeader GcadLeader;
#else
typedef struct GcadLeader GcadLeader;
#endif /* __cplusplus */

#endif 	/* __GcadLeader_FWD_DEFINED__ */


#ifndef __GcadLWPolyline_FWD_DEFINED__
#define __GcadLWPolyline_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLWPolyline GcadLWPolyline;
#else
typedef struct GcadLWPolyline GcadLWPolyline;
#endif /* __cplusplus */

#endif 	/* __GcadLWPolyline_FWD_DEFINED__ */


#ifndef __GcadPoint_FWD_DEFINED__
#define __GcadPoint_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPoint GcadPoint;
#else
typedef struct GcadPoint GcadPoint;
#endif /* __cplusplus */

#endif 	/* __GcadPoint_FWD_DEFINED__ */


#ifndef __GcadPolyline_FWD_DEFINED__
#define __GcadPolyline_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPolyline GcadPolyline;
#else
typedef struct GcadPolyline GcadPolyline;
#endif /* __cplusplus */

#endif 	/* __GcadPolyline_FWD_DEFINED__ */


#ifndef __GcadPolygonMesh_FWD_DEFINED__
#define __GcadPolygonMesh_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPolygonMesh GcadPolygonMesh;
#else
typedef struct GcadPolygonMesh GcadPolygonMesh;
#endif /* __cplusplus */

#endif 	/* __GcadPolygonMesh_FWD_DEFINED__ */


#ifndef __GcadRay_FWD_DEFINED__
#define __GcadRay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRay GcadRay;
#else
typedef struct GcadRay GcadRay;
#endif /* __cplusplus */

#endif 	/* __GcadRay_FWD_DEFINED__ */


#ifndef __GcadShape_FWD_DEFINED__
#define __GcadShape_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadShape GcadShape;
#else
typedef struct GcadShape GcadShape;
#endif /* __cplusplus */

#endif 	/* __GcadShape_FWD_DEFINED__ */


#ifndef __GcadSolid_FWD_DEFINED__
#define __GcadSolid_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSolid GcadSolid;
#else
typedef struct GcadSolid GcadSolid;
#endif /* __cplusplus */

#endif 	/* __GcadSolid_FWD_DEFINED__ */


#ifndef __GcadSpline_FWD_DEFINED__
#define __GcadSpline_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSpline GcadSpline;
#else
typedef struct GcadSpline GcadSpline;
#endif /* __cplusplus */

#endif 	/* __GcadSpline_FWD_DEFINED__ */


#ifndef __GcadText_FWD_DEFINED__
#define __GcadText_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadText GcadText;
#else
typedef struct GcadText GcadText;
#endif /* __cplusplus */

#endif 	/* __GcadText_FWD_DEFINED__ */


#ifndef __GcadTolerance_FWD_DEFINED__
#define __GcadTolerance_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTolerance GcadTolerance;
#else
typedef struct GcadTolerance GcadTolerance;
#endif /* __cplusplus */

#endif 	/* __GcadTolerance_FWD_DEFINED__ */


#ifndef __GcadTrace_FWD_DEFINED__
#define __GcadTrace_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTrace GcadTrace;
#else
typedef struct GcadTrace GcadTrace;
#endif /* __cplusplus */

#endif 	/* __GcadTrace_FWD_DEFINED__ */


#ifndef __GcadXline_FWD_DEFINED__
#define __GcadXline_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadXline GcadXline;
#else
typedef struct GcadXline GcadXline;
#endif /* __cplusplus */

#endif 	/* __GcadXline_FWD_DEFINED__ */


#ifndef __GcadMInsertBlock_FWD_DEFINED__
#define __GcadMInsertBlock_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMInsertBlock GcadMInsertBlock;
#else
typedef struct GcadMInsertBlock GcadMInsertBlock;
#endif /* __cplusplus */

#endif 	/* __GcadMInsertBlock_FWD_DEFINED__ */


#ifndef __GcadPolyfaceMesh_FWD_DEFINED__
#define __GcadPolyfaceMesh_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPolyfaceMesh GcadPolyfaceMesh;
#else
typedef struct GcadPolyfaceMesh GcadPolyfaceMesh;
#endif /* __cplusplus */

#endif 	/* __GcadPolyfaceMesh_FWD_DEFINED__ */


#ifndef __GcadMLine_FWD_DEFINED__
#define __GcadMLine_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMLine GcadMLine;
#else
typedef struct GcadMLine GcadMLine;
#endif /* __cplusplus */

#endif 	/* __GcadMLine_FWD_DEFINED__ */


#ifndef __GcadAssocArrayPath_FWD_DEFINED__
#define __GcadAssocArrayPath_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAssocArrayPath GcadAssocArrayPath;
#else
typedef struct GcadAssocArrayPath GcadAssocArrayPath;
#endif /* __cplusplus */

#endif 	/* __GcadAssocArrayPath_FWD_DEFINED__ */


#ifndef __GcadAssocArrayPolar_FWD_DEFINED__
#define __GcadAssocArrayPolar_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAssocArrayPolar GcadAssocArrayPolar;
#else
typedef struct GcadAssocArrayPolar GcadAssocArrayPolar;
#endif /* __cplusplus */

#endif 	/* __GcadAssocArrayPolar_FWD_DEFINED__ */


#ifndef __GcadAssocArrayRectangular_FWD_DEFINED__
#define __GcadAssocArrayRectangular_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadAssocArrayRectangular GcadAssocArrayRectangular;
#else
typedef struct GcadAssocArrayRectangular GcadAssocArrayRectangular;
#endif /* __cplusplus */

#endif 	/* __GcadAssocArrayRectangular_FWD_DEFINED__ */


#ifndef __GcadExternalReference_FWD_DEFINED__
#define __GcadExternalReference_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadExternalReference GcadExternalReference;
#else
typedef struct GcadExternalReference GcadExternalReference;
#endif /* __cplusplus */

#endif 	/* __GcadExternalReference_FWD_DEFINED__ */


#ifndef __GcadTable_FWD_DEFINED__
#define __GcadTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTable GcadTable;
#else
typedef struct GcadTable GcadTable;
#endif /* __cplusplus */

#endif 	/* __GcadTable_FWD_DEFINED__ */


#ifndef __GcadTableCell_FWD_DEFINED__
#define __GcadTableCell_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTableCell GcadTableCell;
#else
typedef struct GcadTableCell GcadTableCell;
#endif /* __cplusplus */

#endif 	/* __GcadTableCell_FWD_DEFINED__ */


#ifndef __GcadDimension_FWD_DEFINED__
#define __GcadDimension_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimension GcadDimension;
#else
typedef struct GcadDimension GcadDimension;
#endif /* __cplusplus */

#endif 	/* __GcadDimension_FWD_DEFINED__ */


#ifndef __GcadDimAligned_FWD_DEFINED__
#define __GcadDimAligned_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimAligned GcadDimAligned;
#else
typedef struct GcadDimAligned GcadDimAligned;
#endif /* __cplusplus */

#endif 	/* __GcadDimAligned_FWD_DEFINED__ */


#ifndef __GcadDimAngular_FWD_DEFINED__
#define __GcadDimAngular_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimAngular GcadDimAngular;
#else
typedef struct GcadDimAngular GcadDimAngular;
#endif /* __cplusplus */

#endif 	/* __GcadDimAngular_FWD_DEFINED__ */


#ifndef __GcadDimDiametric_FWD_DEFINED__
#define __GcadDimDiametric_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimDiametric GcadDimDiametric;
#else
typedef struct GcadDimDiametric GcadDimDiametric;
#endif /* __cplusplus */

#endif 	/* __GcadDimDiametric_FWD_DEFINED__ */


#ifndef __GcadDimOrdinate_FWD_DEFINED__
#define __GcadDimOrdinate_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimOrdinate GcadDimOrdinate;
#else
typedef struct GcadDimOrdinate GcadDimOrdinate;
#endif /* __cplusplus */

#endif 	/* __GcadDimOrdinate_FWD_DEFINED__ */


#ifndef __GcadDimRadial_FWD_DEFINED__
#define __GcadDimRadial_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimRadial GcadDimRadial;
#else
typedef struct GcadDimRadial GcadDimRadial;
#endif /* __cplusplus */

#endif 	/* __GcadDimRadial_FWD_DEFINED__ */


#ifndef __GcadDimRotated_FWD_DEFINED__
#define __GcadDimRotated_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimRotated GcadDimRotated;
#else
typedef struct GcadDimRotated GcadDimRotated;
#endif /* __cplusplus */

#endif 	/* __GcadDimRotated_FWD_DEFINED__ */


#ifndef __GcadDim3PointAngular_FWD_DEFINED__
#define __GcadDim3PointAngular_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDim3PointAngular GcadDim3PointAngular;
#else
typedef struct GcadDim3PointAngular GcadDim3PointAngular;
#endif /* __cplusplus */

#endif 	/* __GcadDim3PointAngular_FWD_DEFINED__ */


#ifndef __GcadDimArcLength_FWD_DEFINED__
#define __GcadDimArcLength_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimArcLength GcadDimArcLength;
#else
typedef struct GcadDimArcLength GcadDimArcLength;
#endif /* __cplusplus */

#endif 	/* __GcadDimArcLength_FWD_DEFINED__ */


#ifndef __GcadDimRadialLarge_FWD_DEFINED__
#define __GcadDimRadialLarge_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDimRadialLarge GcadDimRadialLarge;
#else
typedef struct GcadDimRadialLarge GcadDimRadialLarge;
#endif /* __cplusplus */

#endif 	/* __GcadDimRadialLarge_FWD_DEFINED__ */


#ifndef __GcadDictionary_FWD_DEFINED__
#define __GcadDictionary_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDictionary GcadDictionary;
#else
typedef struct GcadDictionary GcadDictionary;
#endif /* __cplusplus */

#endif 	/* __GcadDictionary_FWD_DEFINED__ */


#ifndef __GcadView_FWD_DEFINED__
#define __GcadView_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadView GcadView;
#else
typedef struct GcadView GcadView;
#endif /* __cplusplus */

#endif 	/* __GcadView_FWD_DEFINED__ */


#ifndef __GcadToolbars_FWD_DEFINED__
#define __GcadToolbars_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadToolbars GcadToolbars;
#else
typedef struct GcadToolbars GcadToolbars;
#endif /* __cplusplus */

#endif 	/* __GcadToolbars_FWD_DEFINED__ */


#ifndef __GcadToolbar_FWD_DEFINED__
#define __GcadToolbar_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadToolbar GcadToolbar;
#else
typedef struct GcadToolbar GcadToolbar;
#endif /* __cplusplus */

#endif 	/* __GcadToolbar_FWD_DEFINED__ */


#ifndef __GcadToolbarItem_FWD_DEFINED__
#define __GcadToolbarItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadToolbarItem GcadToolbarItem;
#else
typedef struct GcadToolbarItem GcadToolbarItem;
#endif /* __cplusplus */

#endif 	/* __GcadToolbarItem_FWD_DEFINED__ */


#ifndef __GcadSecurityParams_FWD_DEFINED__
#define __GcadSecurityParams_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSecurityParams GcadSecurityParams;
#else
typedef struct GcadSecurityParams GcadSecurityParams;
#endif /* __cplusplus */

#endif 	/* __GcadSecurityParams_FWD_DEFINED__ */


#ifndef ___IGcadScriptJetEvents_FWD_DEFINED__
#define ___IGcadScriptJetEvents_FWD_DEFINED__
typedef interface _IGcadScriptJetEvents _IGcadScriptJetEvents;

#endif 	/* ___IGcadScriptJetEvents_FWD_DEFINED__ */


#ifndef __GcadScriptJet_FWD_DEFINED__
#define __GcadScriptJet_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadScriptJet GcadScriptJet;
#else
typedef struct GcadScriptJet GcadScriptJet;
#endif /* __cplusplus */

#endif 	/* __GcadScriptJet_FWD_DEFINED__ */


#ifndef __GcadFileDependency_FWD_DEFINED__
#define __GcadFileDependency_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadFileDependency GcadFileDependency;
#else
typedef struct GcadFileDependency GcadFileDependency;
#endif /* __cplusplus */

#endif 	/* __GcadFileDependency_FWD_DEFINED__ */


#ifndef __GcadMLeader_FWD_DEFINED__
#define __GcadMLeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadMLeader GcadMLeader;
#else
typedef struct GcadMLeader GcadMLeader;
#endif /* __cplusplus */

#endif 	/* __GcadMLeader_FWD_DEFINED__ */


#ifndef __GcadOle_FWD_DEFINED__
#define __GcadOle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadOle GcadOle;
#else
typedef struct GcadOle GcadOle;
#endif /* __cplusplus */

#endif 	/* __GcadOle_FWD_DEFINED__ */


#ifndef __GcadSubDMesh_FWD_DEFINED__
#define __GcadSubDMesh_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSubDMesh GcadSubDMesh;
#else
typedef struct GcadSubDMesh GcadSubDMesh;
#endif /* __cplusplus */

#endif 	/* __GcadSubDMesh_FWD_DEFINED__ */


#ifndef __GcadHelix_FWD_DEFINED__
#define __GcadHelix_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadHelix GcadHelix;
#else
typedef struct GcadHelix GcadHelix;
#endif /* __cplusplus */

#endif 	/* __GcadHelix_FWD_DEFINED__ */


#ifndef __GcadSection_FWD_DEFINED__
#define __GcadSection_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSection GcadSection;
#else
typedef struct GcadSection GcadSection;
#endif /* __cplusplus */

#endif 	/* __GcadSection_FWD_DEFINED__ */


#ifndef __GcadDgnUnderlay_FWD_DEFINED__
#define __GcadDgnUnderlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDgnUnderlay GcadDgnUnderlay;
#else
typedef struct GcadDgnUnderlay GcadDgnUnderlay;
#endif /* __cplusplus */

#endif 	/* __GcadDgnUnderlay_FWD_DEFINED__ */


#ifndef __GcadPdfUnderlay_FWD_DEFINED__
#define __GcadPdfUnderlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPdfUnderlay GcadPdfUnderlay;
#else
typedef struct GcadPdfUnderlay GcadPdfUnderlay;
#endif /* __cplusplus */

#endif 	/* __GcadPdfUnderlay_FWD_DEFINED__ */


#ifndef __GcadDwfUnderlay_FWD_DEFINED__
#define __GcadDwfUnderlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadDwfUnderlay GcadDwfUnderlay;
#else
typedef struct GcadDwfUnderlay GcadDwfUnderlay;
#endif /* __cplusplus */

#endif 	/* __GcadDwfUnderlay_FWD_DEFINED__ */


#ifndef __GcadSurface_FWD_DEFINED__
#define __GcadSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSurface GcadSurface;
#else
typedef struct GcadSurface GcadSurface;
#endif /* __cplusplus */

#endif 	/* __GcadSurface_FWD_DEFINED__ */


#ifndef __GcadExtrudedSurface_FWD_DEFINED__
#define __GcadExtrudedSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadExtrudedSurface GcadExtrudedSurface;
#else
typedef struct GcadExtrudedSurface GcadExtrudedSurface;
#endif /* __cplusplus */

#endif 	/* __GcadExtrudedSurface_FWD_DEFINED__ */


#ifndef __GcadLoftedSurface_FWD_DEFINED__
#define __GcadLoftedSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLoftedSurface GcadLoftedSurface;
#else
typedef struct GcadLoftedSurface GcadLoftedSurface;
#endif /* __cplusplus */

#endif 	/* __GcadLoftedSurface_FWD_DEFINED__ */


#ifndef __GcadPlaneSurface_FWD_DEFINED__
#define __GcadPlaneSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPlaneSurface GcadPlaneSurface;
#else
typedef struct GcadPlaneSurface GcadPlaneSurface;
#endif /* __cplusplus */

#endif 	/* __GcadPlaneSurface_FWD_DEFINED__ */


#ifndef __GcadRevolvedSurface_FWD_DEFINED__
#define __GcadRevolvedSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadRevolvedSurface GcadRevolvedSurface;
#else
typedef struct GcadRevolvedSurface GcadRevolvedSurface;
#endif /* __cplusplus */

#endif 	/* __GcadRevolvedSurface_FWD_DEFINED__ */


#ifndef __GcadSweptSurface_FWD_DEFINED__
#define __GcadSweptSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSweptSurface GcadSweptSurface;
#else
typedef struct GcadSweptSurface GcadSweptSurface;
#endif /* __cplusplus */

#endif 	/* __GcadSweptSurface_FWD_DEFINED__ */


#ifndef __GcadCamera_FWD_DEFINED__
#define __GcadCamera_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadCamera GcadCamera;
#else
typedef struct GcadCamera GcadCamera;
#endif /* __cplusplus */

#endif 	/* __GcadCamera_FWD_DEFINED__ */


#ifndef __GcadLight_FWD_DEFINED__
#define __GcadLight_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLight GcadLight;
#else
typedef struct GcadLight GcadLight;
#endif /* __cplusplus */

#endif 	/* __GcadLight_FWD_DEFINED__ */


#ifndef __GcadIdPair_FWD_DEFINED__
#define __GcadIdPair_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadIdPair GcadIdPair;
#else
typedef struct GcadIdPair GcadIdPair;
#endif /* __cplusplus */

#endif 	/* __GcadIdPair_FWD_DEFINED__ */


#ifndef __GcadLayerStateManager_FWD_DEFINED__
#define __GcadLayerStateManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadLayerStateManager GcadLayerStateManager;
#else
typedef struct GcadLayerStateManager GcadLayerStateManager;
#endif /* __cplusplus */

#endif 	/* __GcadLayerStateManager_FWD_DEFINED__ */


#ifndef __GcadSortentsTable_FWD_DEFINED__
#define __GcadSortentsTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadSortentsTable GcadSortentsTable;
#else
typedef struct GcadSortentsTable GcadSortentsTable;
#endif /* __cplusplus */

#endif 	/* __GcadSortentsTable_FWD_DEFINED__ */


#ifndef __GcadTableStyle_FWD_DEFINED__
#define __GcadTableStyle_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadTableStyle GcadTableStyle;
#else
typedef struct GcadTableStyle GcadTableStyle;
#endif /* __cplusplus */

#endif 	/* __GcadTableStyle_FWD_DEFINED__ */


#ifndef __GcadArcAlignedText_FWD_DEFINED__
#define __GcadArcAlignedText_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadArcAlignedText GcadArcAlignedText;
#else
typedef struct GcadArcAlignedText GcadArcAlignedText;
#endif /* __cplusplus */

#endif 	/* __GcadArcAlignedText_FWD_DEFINED__ */


#ifndef __GcadNurbSurface_FWD_DEFINED__
#define __GcadNurbSurface_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadNurbSurface GcadNurbSurface;
#else
typedef struct GcadNurbSurface GcadNurbSurface;
#endif /* __cplusplus */

#endif 	/* __GcadNurbSurface_FWD_DEFINED__ */


#ifndef __GcadPointCloudEx_FWD_DEFINED__
#define __GcadPointCloudEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcadPointCloudEx GcadPointCloudEx;
#else
typedef struct GcadPointCloudEx GcadPointCloudEx;
#endif /* __cplusplus */

#endif 	/* __GcadPointCloudEx_FWD_DEFINED__ */


#ifndef __GcPePropertyEditorColor_FWD_DEFINED__
#define __GcPePropertyEditorColor_FWD_DEFINED__

#ifdef __cplusplus
typedef class GcPePropertyEditorColor GcPePropertyEditorColor;
#else
typedef struct GcPePropertyEditorColor GcPePropertyEditorColor;
#endif /* __cplusplus */

#endif 	/* __GcPePropertyEditorColor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "gcdb.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_gcadi_0000_0000 */
/* [local] */ 











extern RPC_IF_HANDLE __MIDL_itf_gcadi_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_gcadi_0000_0000_v0_0_s_ifspec;

#ifndef __IGcadPlaneSurface_INTERFACE_DEFINED__
#define __IGcadPlaneSurface_INTERFACE_DEFINED__

/* interface IGcadPlaneSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadPlaneSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D3A1F3D5-4942-4904-928D-910183FAD5B3")
    IGcadPlaneSurface : public IGcadSurface
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPlaneSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPlaneSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPlaneSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPlaneSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPlaneSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPlaneSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPlaneSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPlaneSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadPlaneSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadPlaneSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadPlaneSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadPlaneSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadPlaneSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadPlaneSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadPlaneSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadPlaneSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadPlaneSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadPlaneSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadPlaneSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadPlaneSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadPlaneSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        END_INTERFACE
    } IGcadPlaneSurfaceVtbl;

    interface IGcadPlaneSurface
    {
        CONST_VTBL struct IGcadPlaneSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPlaneSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPlaneSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPlaneSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPlaneSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPlaneSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPlaneSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPlaneSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPlaneSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadPlaneSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadPlaneSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadPlaneSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadPlaneSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadPlaneSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadPlaneSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadPlaneSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadPlaneSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadPlaneSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadPlaneSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadPlaneSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadPlaneSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadPlaneSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadPlaneSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadPlaneSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadPlaneSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadPlaneSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadPlaneSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadPlaneSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadPlaneSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadPlaneSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadPlaneSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadPlaneSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadPlaneSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadPlaneSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadPlaneSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadPlaneSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadPlaneSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadPlaneSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadPlaneSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadPlaneSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadPlaneSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadPlaneSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadPlaneSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadPlaneSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadPlaneSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadPlaneSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadPlaneSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadPlaneSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadPlaneSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadPlaneSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadPlaneSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadPlaneSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadPlaneSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadPlaneSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadPlaneSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadPlaneSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadPlaneSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadPlaneSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadPlaneSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadPlaneSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadPlaneSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadPlaneSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadPlaneSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadPlaneSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPlaneSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadExtrudedSurface_INTERFACE_DEFINED__
#define __IGcadExtrudedSurface_INTERFACE_DEFINED__

/* interface IGcadExtrudedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadExtrudedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB90B93B-E0A9-43E8-A5F9-B79015C81B0E")
    IGcadExtrudedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ double *Height) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ double Height) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TaperAngle( 
            /* [retval][out] */ GCAD_ANGLE *TaperAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TaperAngle( 
            /* [in] */ GCAD_ANGLE TaperAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Direction( 
            /* [retval][out] */ VARIANT *Direction) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadExtrudedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadExtrudedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadExtrudedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadExtrudedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadExtrudedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadExtrudedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadExtrudedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadExtrudedSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadExtrudedSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadExtrudedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadExtrudedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadExtrudedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadExtrudedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadExtrudedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ double *Height);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IGcadExtrudedSurface * This,
            /* [in] */ double Height);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TaperAngle )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *TaperAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TaperAngle )( 
            IGcadExtrudedSurface * This,
            /* [in] */ GCAD_ANGLE TaperAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Direction )( 
            IGcadExtrudedSurface * This,
            /* [retval][out] */ VARIANT *Direction);
        
        END_INTERFACE
    } IGcadExtrudedSurfaceVtbl;

    interface IGcadExtrudedSurface
    {
        CONST_VTBL struct IGcadExtrudedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadExtrudedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadExtrudedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadExtrudedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadExtrudedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadExtrudedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadExtrudedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadExtrudedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadExtrudedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadExtrudedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadExtrudedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadExtrudedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadExtrudedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadExtrudedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadExtrudedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadExtrudedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadExtrudedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadExtrudedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadExtrudedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadExtrudedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadExtrudedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadExtrudedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadExtrudedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadExtrudedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadExtrudedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadExtrudedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadExtrudedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadExtrudedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadExtrudedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadExtrudedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadExtrudedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadExtrudedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadExtrudedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadExtrudedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadExtrudedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadExtrudedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadExtrudedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadExtrudedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadExtrudedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadExtrudedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadExtrudedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadExtrudedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadExtrudedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadExtrudedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadExtrudedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadExtrudedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadExtrudedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadExtrudedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadExtrudedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadExtrudedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadExtrudedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadExtrudedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadExtrudedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadExtrudedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadExtrudedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadExtrudedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadExtrudedSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadExtrudedSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadExtrudedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadExtrudedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadExtrudedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadExtrudedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadExtrudedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadExtrudedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadExtrudedSurface_get_Height(This,Height)	\
    ( (This)->lpVtbl -> get_Height(This,Height) ) 

#define IGcadExtrudedSurface_put_Height(This,Height)	\
    ( (This)->lpVtbl -> put_Height(This,Height) ) 

#define IGcadExtrudedSurface_get_TaperAngle(This,TaperAngle)	\
    ( (This)->lpVtbl -> get_TaperAngle(This,TaperAngle) ) 

#define IGcadExtrudedSurface_put_TaperAngle(This,TaperAngle)	\
    ( (This)->lpVtbl -> put_TaperAngle(This,TaperAngle) ) 

#define IGcadExtrudedSurface_get_Direction(This,Direction)	\
    ( (This)->lpVtbl -> get_Direction(This,Direction) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadExtrudedSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadRevolvedSurface_INTERFACE_DEFINED__
#define __IGcadRevolvedSurface_INTERFACE_DEFINED__

/* interface IGcadRevolvedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadRevolvedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC4B31D4-9595-43C1-8BC9-AC5F8003F179")
    IGcadRevolvedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RevolutionAngle( 
            /* [retval][out] */ GCAD_ANGLE *revAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_RevolutionAngle( 
            /* [in] */ GCAD_ANGLE revAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AxisPosition( 
            /* [retval][out] */ VARIANT *AxisPosition) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AxisPosition( 
            /* [in] */ VARIANT AxisPosition) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AxisDirection( 
            /* [retval][out] */ VARIANT *AxisDirection) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadRevolvedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadRevolvedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadRevolvedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadRevolvedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadRevolvedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadRevolvedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadRevolvedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadRevolvedSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadRevolvedSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadRevolvedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadRevolvedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadRevolvedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadRevolvedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RevolutionAngle )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *revAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_RevolutionAngle )( 
            IGcadRevolvedSurface * This,
            /* [in] */ GCAD_ANGLE revAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AxisPosition )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT *AxisPosition);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AxisPosition )( 
            IGcadRevolvedSurface * This,
            /* [in] */ VARIANT AxisPosition);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AxisDirection )( 
            IGcadRevolvedSurface * This,
            /* [retval][out] */ VARIANT *AxisDirection);
        
        END_INTERFACE
    } IGcadRevolvedSurfaceVtbl;

    interface IGcadRevolvedSurface
    {
        CONST_VTBL struct IGcadRevolvedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadRevolvedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadRevolvedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadRevolvedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadRevolvedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadRevolvedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadRevolvedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadRevolvedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadRevolvedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadRevolvedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadRevolvedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadRevolvedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadRevolvedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadRevolvedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadRevolvedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadRevolvedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadRevolvedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadRevolvedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadRevolvedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadRevolvedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadRevolvedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadRevolvedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadRevolvedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadRevolvedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadRevolvedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadRevolvedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadRevolvedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadRevolvedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadRevolvedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadRevolvedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadRevolvedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadRevolvedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadRevolvedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadRevolvedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadRevolvedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadRevolvedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadRevolvedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadRevolvedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadRevolvedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadRevolvedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadRevolvedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadRevolvedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadRevolvedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadRevolvedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadRevolvedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadRevolvedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadRevolvedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadRevolvedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadRevolvedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadRevolvedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadRevolvedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadRevolvedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadRevolvedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadRevolvedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadRevolvedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadRevolvedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadRevolvedSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadRevolvedSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadRevolvedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadRevolvedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadRevolvedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadRevolvedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadRevolvedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadRevolvedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadRevolvedSurface_get_RevolutionAngle(This,revAngle)	\
    ( (This)->lpVtbl -> get_RevolutionAngle(This,revAngle) ) 

#define IGcadRevolvedSurface_put_RevolutionAngle(This,revAngle)	\
    ( (This)->lpVtbl -> put_RevolutionAngle(This,revAngle) ) 

#define IGcadRevolvedSurface_get_AxisPosition(This,AxisPosition)	\
    ( (This)->lpVtbl -> get_AxisPosition(This,AxisPosition) ) 

#define IGcadRevolvedSurface_put_AxisPosition(This,AxisPosition)	\
    ( (This)->lpVtbl -> put_AxisPosition(This,AxisPosition) ) 

#define IGcadRevolvedSurface_get_AxisDirection(This,AxisDirection)	\
    ( (This)->lpVtbl -> get_AxisDirection(This,AxisDirection) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadRevolvedSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadSweptSurface_INTERFACE_DEFINED__
#define __IGcadSweptSurface_INTERFACE_DEFINED__

/* interface IGcadSweptSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadSweptSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0EA16B8C-632D-4AC3-8B6F-FECEB9558A7D")
    IGcadSweptSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProfileRotation( 
            /* [retval][out] */ GCAD_ANGLE *profileRotationAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProfileRotation( 
            /* [in] */ GCAD_ANGLE profileRotationAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Bank( 
            /* [retval][out] */ VARIANT_BOOL *bBank) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Bank( 
            /* [in] */ VARIANT_BOOL bBank) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Twist( 
            /* [retval][out] */ GCAD_ANGLE *TwistAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Twist( 
            /* [in] */ GCAD_ANGLE TwistAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_scale( 
            /* [retval][out] */ double *scale) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_scale( 
            /* [in] */ double scale) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ double *Length) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSweptSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSweptSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSweptSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSweptSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSweptSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSweptSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSweptSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSweptSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadSweptSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadSweptSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadSweptSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadSweptSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadSweptSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadSweptSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadSweptSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadSweptSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadSweptSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadSweptSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProfileRotation )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_ANGLE *profileRotationAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProfileRotation )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_ANGLE profileRotationAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Bank )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bBank);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Bank )( 
            IGcadSweptSurface * This,
            /* [in] */ VARIANT_BOOL bBank);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Twist )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ GCAD_ANGLE *TwistAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Twist )( 
            IGcadSweptSurface * This,
            /* [in] */ GCAD_ANGLE TwistAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_scale )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ double *scale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_scale )( 
            IGcadSweptSurface * This,
            /* [in] */ double scale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IGcadSweptSurface * This,
            /* [retval][out] */ double *Length);
        
        END_INTERFACE
    } IGcadSweptSurfaceVtbl;

    interface IGcadSweptSurface
    {
        CONST_VTBL struct IGcadSweptSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSweptSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSweptSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSweptSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSweptSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSweptSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSweptSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSweptSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSweptSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadSweptSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadSweptSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadSweptSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadSweptSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadSweptSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadSweptSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadSweptSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadSweptSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadSweptSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadSweptSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadSweptSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadSweptSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadSweptSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadSweptSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadSweptSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadSweptSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadSweptSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadSweptSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadSweptSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadSweptSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadSweptSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadSweptSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadSweptSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadSweptSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadSweptSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadSweptSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadSweptSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadSweptSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadSweptSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadSweptSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadSweptSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadSweptSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadSweptSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadSweptSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadSweptSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadSweptSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadSweptSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadSweptSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadSweptSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadSweptSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadSweptSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadSweptSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadSweptSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadSweptSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadSweptSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadSweptSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadSweptSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadSweptSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadSweptSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadSweptSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadSweptSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadSweptSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadSweptSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadSweptSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadSweptSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadSweptSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadSweptSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadSweptSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadSweptSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadSweptSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadSweptSurface_get_ProfileRotation(This,profileRotationAngle)	\
    ( (This)->lpVtbl -> get_ProfileRotation(This,profileRotationAngle) ) 

#define IGcadSweptSurface_put_ProfileRotation(This,profileRotationAngle)	\
    ( (This)->lpVtbl -> put_ProfileRotation(This,profileRotationAngle) ) 

#define IGcadSweptSurface_get_Bank(This,bBank)	\
    ( (This)->lpVtbl -> get_Bank(This,bBank) ) 

#define IGcadSweptSurface_put_Bank(This,bBank)	\
    ( (This)->lpVtbl -> put_Bank(This,bBank) ) 

#define IGcadSweptSurface_get_Twist(This,TwistAngle)	\
    ( (This)->lpVtbl -> get_Twist(This,TwistAngle) ) 

#define IGcadSweptSurface_put_Twist(This,TwistAngle)	\
    ( (This)->lpVtbl -> put_Twist(This,TwistAngle) ) 

#define IGcadSweptSurface_get_scale(This,scale)	\
    ( (This)->lpVtbl -> get_scale(This,scale) ) 

#define IGcadSweptSurface_put_scale(This,scale)	\
    ( (This)->lpVtbl -> put_scale(This,scale) ) 

#define IGcadSweptSurface_get_Length(This,Length)	\
    ( (This)->lpVtbl -> get_Length(This,Length) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSweptSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadLoftedSurface_INTERFACE_DEFINED__
#define __IGcadLoftedSurface_INTERFACE_DEFINED__

/* interface IGcadLoftedSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadLoftedSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83049727-9881-4D4D-8E57-63C83CB0CC6E")
    IGcadLoftedSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumCrossSections( 
            /* [retval][out] */ long *NumCrossSections) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumGuidePaths( 
            /* [retval][out] */ long *NumGuidePaths) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SurfaceNormals( 
            /* [retval][out] */ GcLoftedSurfaceNormalType *surfaceNormal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SurfaceNormals( 
            /* [in] */ GcLoftedSurfaceNormalType surfaceNormal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StartDraftAngle( 
            /* [retval][out] */ GCAD_ANGLE *StartDraftAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StartDraftAngle( 
            /* [in] */ GCAD_ANGLE StartDraftAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StartDraftMagnitude( 
            /* [retval][out] */ double *startDraftMag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StartDraftMagnitude( 
            /* [in] */ double startDraftMag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndDraftAngle( 
            /* [retval][out] */ GCAD_ANGLE *EndDraftAngle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndDraftAngle( 
            /* [in] */ GCAD_ANGLE EndDraftAngle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndDraftMagnitude( 
            /* [retval][out] */ double *endDraftMag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndDraftMagnitude( 
            /* [in] */ double endDraftMag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Closed( 
            /* [retval][out] */ VARIANT_BOOL *bClosed) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Closed( 
            /* [in] */ VARIANT_BOOL bClosed) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadLoftedSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadLoftedSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadLoftedSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadLoftedSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadLoftedSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadLoftedSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadLoftedSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadLoftedSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadLoftedSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadLoftedSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadLoftedSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadLoftedSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadLoftedSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadLoftedSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadLoftedSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadLoftedSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadLoftedSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadLoftedSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumCrossSections )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *NumCrossSections);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumGuidePaths )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ long *NumGuidePaths);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceNormals )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GcLoftedSurfaceNormalType *surfaceNormal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SurfaceNormals )( 
            IGcadLoftedSurface * This,
            /* [in] */ GcLoftedSurfaceNormalType surfaceNormal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *StartDraftAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StartDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_ANGLE StartDraftAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ double *startDraftMag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StartDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [in] */ double startDraftMag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ GCAD_ANGLE *EndDraftAngle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndDraftAngle )( 
            IGcadLoftedSurface * This,
            /* [in] */ GCAD_ANGLE EndDraftAngle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ double *endDraftMag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndDraftMagnitude )( 
            IGcadLoftedSurface * This,
            /* [in] */ double endDraftMag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Closed )( 
            IGcadLoftedSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bClosed);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Closed )( 
            IGcadLoftedSurface * This,
            /* [in] */ VARIANT_BOOL bClosed);
        
        END_INTERFACE
    } IGcadLoftedSurfaceVtbl;

    interface IGcadLoftedSurface
    {
        CONST_VTBL struct IGcadLoftedSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadLoftedSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadLoftedSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadLoftedSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadLoftedSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadLoftedSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadLoftedSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadLoftedSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadLoftedSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadLoftedSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadLoftedSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadLoftedSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadLoftedSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadLoftedSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadLoftedSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadLoftedSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadLoftedSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadLoftedSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadLoftedSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadLoftedSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadLoftedSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadLoftedSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadLoftedSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadLoftedSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadLoftedSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadLoftedSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadLoftedSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadLoftedSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadLoftedSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadLoftedSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadLoftedSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadLoftedSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadLoftedSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadLoftedSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadLoftedSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadLoftedSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadLoftedSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadLoftedSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadLoftedSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadLoftedSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadLoftedSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadLoftedSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadLoftedSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadLoftedSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadLoftedSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadLoftedSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadLoftedSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadLoftedSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadLoftedSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadLoftedSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadLoftedSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadLoftedSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadLoftedSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadLoftedSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadLoftedSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadLoftedSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadLoftedSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadLoftedSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadLoftedSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadLoftedSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadLoftedSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadLoftedSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadLoftedSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadLoftedSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadLoftedSurface_get_NumCrossSections(This,NumCrossSections)	\
    ( (This)->lpVtbl -> get_NumCrossSections(This,NumCrossSections) ) 

#define IGcadLoftedSurface_get_NumGuidePaths(This,NumGuidePaths)	\
    ( (This)->lpVtbl -> get_NumGuidePaths(This,NumGuidePaths) ) 

#define IGcadLoftedSurface_get_SurfaceNormals(This,surfaceNormal)	\
    ( (This)->lpVtbl -> get_SurfaceNormals(This,surfaceNormal) ) 

#define IGcadLoftedSurface_put_SurfaceNormals(This,surfaceNormal)	\
    ( (This)->lpVtbl -> put_SurfaceNormals(This,surfaceNormal) ) 

#define IGcadLoftedSurface_get_StartDraftAngle(This,StartDraftAngle)	\
    ( (This)->lpVtbl -> get_StartDraftAngle(This,StartDraftAngle) ) 

#define IGcadLoftedSurface_put_StartDraftAngle(This,StartDraftAngle)	\
    ( (This)->lpVtbl -> put_StartDraftAngle(This,StartDraftAngle) ) 

#define IGcadLoftedSurface_get_StartDraftMagnitude(This,startDraftMag)	\
    ( (This)->lpVtbl -> get_StartDraftMagnitude(This,startDraftMag) ) 

#define IGcadLoftedSurface_put_StartDraftMagnitude(This,startDraftMag)	\
    ( (This)->lpVtbl -> put_StartDraftMagnitude(This,startDraftMag) ) 

#define IGcadLoftedSurface_get_EndDraftAngle(This,EndDraftAngle)	\
    ( (This)->lpVtbl -> get_EndDraftAngle(This,EndDraftAngle) ) 

#define IGcadLoftedSurface_put_EndDraftAngle(This,EndDraftAngle)	\
    ( (This)->lpVtbl -> put_EndDraftAngle(This,EndDraftAngle) ) 

#define IGcadLoftedSurface_get_EndDraftMagnitude(This,endDraftMag)	\
    ( (This)->lpVtbl -> get_EndDraftMagnitude(This,endDraftMag) ) 

#define IGcadLoftedSurface_put_EndDraftMagnitude(This,endDraftMag)	\
    ( (This)->lpVtbl -> put_EndDraftMagnitude(This,endDraftMag) ) 

#define IGcadLoftedSurface_get_Closed(This,bClosed)	\
    ( (This)->lpVtbl -> get_Closed(This,bClosed) ) 

#define IGcadLoftedSurface_put_Closed(This,bClosed)	\
    ( (This)->lpVtbl -> put_Closed(This,bClosed) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadLoftedSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadNurbSurface_INTERFACE_DEFINED__
#define __IGcadNurbSurface_INTERFACE_DEFINED__

/* interface IGcadNurbSurface */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadNurbSurface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B4087378-9A1B-4996-B1C0-D3EAD492FA7A")
    IGcadNurbSurface : public IGcadSurface
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CvHullDisplay( 
            /* [retval][out] */ VARIANT_BOOL *Display) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CvHullDisplay( 
            /* [in] */ VARIANT_BOOL Display) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadNurbSurfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadNurbSurface * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadNurbSurface * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadNurbSurface * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadNurbSurface * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadNurbSurface * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadNurbSurface * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadNurbSurface * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadNurbSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadNurbSurface * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadNurbSurface * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadNurbSurface * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadNurbSurface * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadNurbSurface * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadNurbSurface * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadNurbSurface * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadNurbSurface * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadNurbSurface * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadNurbSurface * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadNurbSurface * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SurfaceType )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ BSTR *SurfaceType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UIsolineDensity )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UIsolineDensity )( 
            IGcadNurbSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VIsolineDensity )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ long *density);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VIsolineDensity )( 
            IGcadNurbSurface * This,
            /* [in] */ long density);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WireframeType )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ GcWireframeType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WireframeType )( 
            IGcadNurbSurface * This,
            /* [in] */ GcWireframeType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaintainAssociativity )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ int *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaintainAssociativity )( 
            IGcadNurbSurface * This,
            /* [in] */ int rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowAssociativity )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ VARIANT_BOOL *rhs);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowAssociativity )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT_BOOL rhs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CvHullDisplay )( 
            IGcadNurbSurface * This,
            /* [retval][out] */ VARIANT_BOOL *Display);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CvHullDisplay )( 
            IGcadNurbSurface * This,
            /* [in] */ VARIANT_BOOL Display);
        
        END_INTERFACE
    } IGcadNurbSurfaceVtbl;

    interface IGcadNurbSurface
    {
        CONST_VTBL struct IGcadNurbSurfaceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadNurbSurface_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadNurbSurface_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadNurbSurface_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadNurbSurface_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadNurbSurface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadNurbSurface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadNurbSurface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadNurbSurface_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadNurbSurface_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadNurbSurface_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadNurbSurface_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadNurbSurface_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadNurbSurface_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadNurbSurface_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadNurbSurface_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadNurbSurface_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadNurbSurface_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadNurbSurface_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadNurbSurface_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadNurbSurface_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadNurbSurface_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadNurbSurface_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadNurbSurface_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadNurbSurface_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadNurbSurface_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadNurbSurface_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadNurbSurface_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadNurbSurface_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadNurbSurface_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadNurbSurface_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadNurbSurface_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadNurbSurface_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadNurbSurface_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadNurbSurface_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadNurbSurface_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadNurbSurface_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadNurbSurface_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadNurbSurface_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadNurbSurface_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadNurbSurface_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadNurbSurface_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadNurbSurface_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadNurbSurface_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadNurbSurface_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadNurbSurface_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadNurbSurface_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadNurbSurface_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadNurbSurface_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadNurbSurface_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadNurbSurface_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadNurbSurface_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadNurbSurface_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadNurbSurface_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadNurbSurface_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadNurbSurface_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadNurbSurface_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadNurbSurface_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadNurbSurface_get_SurfaceType(This,SurfaceType)	\
    ( (This)->lpVtbl -> get_SurfaceType(This,SurfaceType) ) 

#define IGcadNurbSurface_get_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_UIsolineDensity(This,density) ) 

#define IGcadNurbSurface_put_UIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_UIsolineDensity(This,density) ) 

#define IGcadNurbSurface_get_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> get_VIsolineDensity(This,density) ) 

#define IGcadNurbSurface_put_VIsolineDensity(This,density)	\
    ( (This)->lpVtbl -> put_VIsolineDensity(This,density) ) 

#define IGcadNurbSurface_get_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> get_WireframeType(This,Type) ) 

#define IGcadNurbSurface_put_WireframeType(This,Type)	\
    ( (This)->lpVtbl -> put_WireframeType(This,Type) ) 

#define IGcadNurbSurface_get_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_MaintainAssociativity(This,rhs) ) 

#define IGcadNurbSurface_put_MaintainAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_MaintainAssociativity(This,rhs) ) 

#define IGcadNurbSurface_get_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> get_ShowAssociativity(This,rhs) ) 

#define IGcadNurbSurface_put_ShowAssociativity(This,rhs)	\
    ( (This)->lpVtbl -> put_ShowAssociativity(This,rhs) ) 


#define IGcadNurbSurface_get_CvHullDisplay(This,Display)	\
    ( (This)->lpVtbl -> get_CvHullDisplay(This,Display) ) 

#define IGcadNurbSurface_put_CvHullDisplay(This,Display)	\
    ( (This)->lpVtbl -> put_CvHullDisplay(This,Display) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadNurbSurface_INTERFACE_DEFINED__ */


#ifndef __IGcadPointCloudEx_INTERFACE_DEFINED__
#define __IGcadPointCloudEx_INTERFACE_DEFINED__

/* interface IGcadPointCloudEx */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadPointCloudEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43DC153E-7BF6-43A8-96AC-C6788C702C9D")
    IGcadPointCloudEx : public IGcadEntity
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Stylization( 
            /* [retval][out] */ GcPointCloudExStylizationType *Type) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Stylization( 
            /* [in] */ GcPointCloudExStylizationType Type) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ColorScheme( 
            /* [retval][out] */ BSTR *Type) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ColorScheme( 
            /* [in] */ BSTR Type) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_InsertionPoint( 
            /* [retval][out] */ VARIANT *EndPoint) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_InsertionPoint( 
            /* [in] */ VARIANT EndPoint) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Rotation( 
            /* [retval][out] */ GCAD_ANGLE *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Rotation( 
            /* [in] */ GCAD_ANGLE val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Scale( 
            /* [retval][out] */ GCAD_NOUNITS *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Scale( 
            /* [in] */ GCAD_NOUNITS val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowCropped( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowCropped( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Locked( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Locked( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Geolocate( 
            /* [retval][out] */ VARIANT_BOOL *val) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Geolocate( 
            /* [in] */ VARIANT_BOOL val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Unit( 
            /* [retval][out] */ BSTR *val) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UnitFactor( 
            /* [retval][out] */ double *val) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPointCloudExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPointCloudEx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPointCloudEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPointCloudEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPointCloudEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPointCloudEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPointCloudEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPointCloudEx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColor )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColor )( 
            IGcadPointCloudEx * This,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layer )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Layer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Layer )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Layer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetype )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Linetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Linetype )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Linetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LinetypeScale )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_NOUNITS *ltScale);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LinetypeScale )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_NOUNITS ltScale);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *bVisible);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL bVisible);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayPolar )( 
            IGcadPointCloudEx * This,
            /* [in] */ int NumberOfObjects,
            /* [in] */ double AngleToFill,
            /* [in] */ VARIANT CenterPoint,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArrayRectangular )( 
            IGcadPointCloudEx * This,
            /* [in] */ int NumberOfRows,
            /* [in] */ int NumberOfColumns,
            /* [in] */ int NumberOfLevels,
            /* [in] */ double DistBetweenRows,
            /* [in] */ double DistBetweenCols,
            /* [in] */ double DistBetweenLevels,
            /* [retval][out] */ VARIANT *pArrayObjs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL HighlightFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IDispatch **pCopyObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT FromPoint,
            /* [in] */ VARIANT ToPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate3D )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ double RotationAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror3D )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT Point1,
            /* [in] */ VARIANT Point2,
            /* [in] */ VARIANT point3,
            /* [retval][out] */ IDispatch **pMirrorObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ScaleEntity )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT BasePoint,
            /* [in] */ double ScaleFactor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransformBy )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT TransformationMatrix);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadPointCloudEx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBoundingBox )( 
            IGcadPointCloudEx * This,
            /* [out] */ VARIANT *MinPoint,
            /* [out] */ VARIANT *MaxPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IntersectWith )( 
            IGcadPointCloudEx * This,
            /* [in] */ IDispatch *IntersectObject,
            /* [in] */ GcExtendOption option,
            /* [retval][out] */ VARIANT *intPoints);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotStyleName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *plotStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotStyleName )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR plotStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Lineweight )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Lineweight )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityTransparency )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *transparency);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EntityTransparency )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR transparency);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Hyperlinks )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ IGcadHyperlinks **Hyperlinks);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Material )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Material);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Material )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Material);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityName )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *EntityName);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EntityType )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ long *entType);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Color )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_COLOR *color);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Color )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Stylization )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GcPointCloudExStylizationType *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Stylization )( 
            IGcadPointCloudEx * This,
            /* [in] */ GcPointCloudExStylizationType Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ColorScheme )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *Type);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ColorScheme )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR Type);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_InsertionPoint )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT *EndPoint);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_InsertionPoint )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT EndPoint);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Rotation )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_ANGLE *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Rotation )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_ANGLE val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Scale )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ GCAD_NOUNITS *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Scale )( 
            IGcadPointCloudEx * This,
            /* [in] */ GCAD_NOUNITS val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadPointCloudEx * This,
            /* [in] */ BSTR val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowCropped )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowCropped )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Locked )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Locked )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Geolocate )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ VARIANT_BOOL *val);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Geolocate )( 
            IGcadPointCloudEx * This,
            /* [in] */ VARIANT_BOOL val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Unit )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ BSTR *val);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnitFactor )( 
            IGcadPointCloudEx * This,
            /* [retval][out] */ double *val);
        
        END_INTERFACE
    } IGcadPointCloudExVtbl;

    interface IGcadPointCloudEx
    {
        CONST_VTBL struct IGcadPointCloudExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPointCloudEx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPointCloudEx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPointCloudEx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPointCloudEx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPointCloudEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPointCloudEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPointCloudEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPointCloudEx_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadPointCloudEx_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadPointCloudEx_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadPointCloudEx_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadPointCloudEx_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadPointCloudEx_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadPointCloudEx_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadPointCloudEx_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadPointCloudEx_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadPointCloudEx_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadPointCloudEx_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadPointCloudEx_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadPointCloudEx_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadPointCloudEx_get_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> get_TrueColor(This,pColor) ) 

#define IGcadPointCloudEx_put_TrueColor(This,pColor)	\
    ( (This)->lpVtbl -> put_TrueColor(This,pColor) ) 

#define IGcadPointCloudEx_get_Layer(This,Layer)	\
    ( (This)->lpVtbl -> get_Layer(This,Layer) ) 

#define IGcadPointCloudEx_put_Layer(This,Layer)	\
    ( (This)->lpVtbl -> put_Layer(This,Layer) ) 

#define IGcadPointCloudEx_get_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> get_Linetype(This,Linetype) ) 

#define IGcadPointCloudEx_put_Linetype(This,Linetype)	\
    ( (This)->lpVtbl -> put_Linetype(This,Linetype) ) 

#define IGcadPointCloudEx_get_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> get_LinetypeScale(This,ltScale) ) 

#define IGcadPointCloudEx_put_LinetypeScale(This,ltScale)	\
    ( (This)->lpVtbl -> put_LinetypeScale(This,ltScale) ) 

#define IGcadPointCloudEx_get_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> get_Visible(This,bVisible) ) 

#define IGcadPointCloudEx_put_Visible(This,bVisible)	\
    ( (This)->lpVtbl -> put_Visible(This,bVisible) ) 

#define IGcadPointCloudEx_ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayPolar(This,NumberOfObjects,AngleToFill,CenterPoint,pArrayObjs) ) 

#define IGcadPointCloudEx_ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs)	\
    ( (This)->lpVtbl -> ArrayRectangular(This,NumberOfRows,NumberOfColumns,NumberOfLevels,DistBetweenRows,DistBetweenCols,DistBetweenLevels,pArrayObjs) ) 

#define IGcadPointCloudEx_Highlight(This,HighlightFlag)	\
    ( (This)->lpVtbl -> Highlight(This,HighlightFlag) ) 

#define IGcadPointCloudEx_Copy(This,pCopyObj)	\
    ( (This)->lpVtbl -> Copy(This,pCopyObj) ) 

#define IGcadPointCloudEx_Move(This,FromPoint,ToPoint)	\
    ( (This)->lpVtbl -> Move(This,FromPoint,ToPoint) ) 

#define IGcadPointCloudEx_Rotate(This,BasePoint,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate(This,BasePoint,RotationAngle) ) 

#define IGcadPointCloudEx_Rotate3D(This,Point1,Point2,RotationAngle)	\
    ( (This)->lpVtbl -> Rotate3D(This,Point1,Point2,RotationAngle) ) 

#define IGcadPointCloudEx_Mirror(This,Point1,Point2,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror(This,Point1,Point2,pMirrorObj) ) 

#define IGcadPointCloudEx_Mirror3D(This,Point1,Point2,point3,pMirrorObj)	\
    ( (This)->lpVtbl -> Mirror3D(This,Point1,Point2,point3,pMirrorObj) ) 

#define IGcadPointCloudEx_ScaleEntity(This,BasePoint,ScaleFactor)	\
    ( (This)->lpVtbl -> ScaleEntity(This,BasePoint,ScaleFactor) ) 

#define IGcadPointCloudEx_TransformBy(This,TransformationMatrix)	\
    ( (This)->lpVtbl -> TransformBy(This,TransformationMatrix) ) 

#define IGcadPointCloudEx_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadPointCloudEx_GetBoundingBox(This,MinPoint,MaxPoint)	\
    ( (This)->lpVtbl -> GetBoundingBox(This,MinPoint,MaxPoint) ) 

#define IGcadPointCloudEx_IntersectWith(This,IntersectObject,option,intPoints)	\
    ( (This)->lpVtbl -> IntersectWith(This,IntersectObject,option,intPoints) ) 

#define IGcadPointCloudEx_get_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> get_PlotStyleName(This,plotStyle) ) 

#define IGcadPointCloudEx_put_PlotStyleName(This,plotStyle)	\
    ( (This)->lpVtbl -> put_PlotStyleName(This,plotStyle) ) 

#define IGcadPointCloudEx_get_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> get_Lineweight(This,Lineweight) ) 

#define IGcadPointCloudEx_put_Lineweight(This,Lineweight)	\
    ( (This)->lpVtbl -> put_Lineweight(This,Lineweight) ) 

#define IGcadPointCloudEx_get_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> get_EntityTransparency(This,transparency) ) 

#define IGcadPointCloudEx_put_EntityTransparency(This,transparency)	\
    ( (This)->lpVtbl -> put_EntityTransparency(This,transparency) ) 

#define IGcadPointCloudEx_get_Hyperlinks(This,Hyperlinks)	\
    ( (This)->lpVtbl -> get_Hyperlinks(This,Hyperlinks) ) 

#define IGcadPointCloudEx_get_Material(This,Material)	\
    ( (This)->lpVtbl -> get_Material(This,Material) ) 

#define IGcadPointCloudEx_put_Material(This,Material)	\
    ( (This)->lpVtbl -> put_Material(This,Material) ) 

#define IGcadPointCloudEx_get_EntityName(This,EntityName)	\
    ( (This)->lpVtbl -> get_EntityName(This,EntityName) ) 

#define IGcadPointCloudEx_get_EntityType(This,entType)	\
    ( (This)->lpVtbl -> get_EntityType(This,entType) ) 

#define IGcadPointCloudEx_get_Color(This,color)	\
    ( (This)->lpVtbl -> get_Color(This,color) ) 

#define IGcadPointCloudEx_put_Color(This,color)	\
    ( (This)->lpVtbl -> put_Color(This,color) ) 


#define IGcadPointCloudEx_get_Stylization(This,Type)	\
    ( (This)->lpVtbl -> get_Stylization(This,Type) ) 

#define IGcadPointCloudEx_put_Stylization(This,Type)	\
    ( (This)->lpVtbl -> put_Stylization(This,Type) ) 

#define IGcadPointCloudEx_get_ColorScheme(This,Type)	\
    ( (This)->lpVtbl -> get_ColorScheme(This,Type) ) 

#define IGcadPointCloudEx_put_ColorScheme(This,Type)	\
    ( (This)->lpVtbl -> put_ColorScheme(This,Type) ) 

#define IGcadPointCloudEx_get_InsertionPoint(This,EndPoint)	\
    ( (This)->lpVtbl -> get_InsertionPoint(This,EndPoint) ) 

#define IGcadPointCloudEx_put_InsertionPoint(This,EndPoint)	\
    ( (This)->lpVtbl -> put_InsertionPoint(This,EndPoint) ) 

#define IGcadPointCloudEx_get_Rotation(This,val)	\
    ( (This)->lpVtbl -> get_Rotation(This,val) ) 

#define IGcadPointCloudEx_put_Rotation(This,val)	\
    ( (This)->lpVtbl -> put_Rotation(This,val) ) 

#define IGcadPointCloudEx_get_Scale(This,val)	\
    ( (This)->lpVtbl -> get_Scale(This,val) ) 

#define IGcadPointCloudEx_put_Scale(This,val)	\
    ( (This)->lpVtbl -> put_Scale(This,val) ) 

#define IGcadPointCloudEx_get_Name(This,val)	\
    ( (This)->lpVtbl -> get_Name(This,val) ) 

#define IGcadPointCloudEx_put_Name(This,val)	\
    ( (This)->lpVtbl -> put_Name(This,val) ) 

#define IGcadPointCloudEx_get_Path(This,val)	\
    ( (This)->lpVtbl -> get_Path(This,val) ) 

#define IGcadPointCloudEx_get_ShowCropped(This,val)	\
    ( (This)->lpVtbl -> get_ShowCropped(This,val) ) 

#define IGcadPointCloudEx_put_ShowCropped(This,val)	\
    ( (This)->lpVtbl -> put_ShowCropped(This,val) ) 

#define IGcadPointCloudEx_get_Locked(This,val)	\
    ( (This)->lpVtbl -> get_Locked(This,val) ) 

#define IGcadPointCloudEx_put_Locked(This,val)	\
    ( (This)->lpVtbl -> put_Locked(This,val) ) 

#define IGcadPointCloudEx_get_Geolocate(This,val)	\
    ( (This)->lpVtbl -> get_Geolocate(This,val) ) 

#define IGcadPointCloudEx_put_Geolocate(This,val)	\
    ( (This)->lpVtbl -> put_Geolocate(This,val) ) 

#define IGcadPointCloudEx_get_Unit(This,val)	\
    ( (This)->lpVtbl -> get_Unit(This,val) ) 

#define IGcadPointCloudEx_get_UnitFactor(This,val)	\
    ( (This)->lpVtbl -> get_UnitFactor(This,val) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPointCloudEx_INTERFACE_DEFINED__ */


#ifndef __IGcadApplication_INTERFACE_DEFINED__
#define __IGcadApplication_INTERFACE_DEFINED__

/* interface IGcadApplication */
/* [unique][helpstring][dual][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_IGcadApplication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1872638-6D18-482F-90BA-38086D17625F")
    IGcadApplication : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *Visible) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL Visible) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pAppName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *bstrCaption) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveDocument( 
            /* [retval][out] */ IGcadDocument **pActiveDoc) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveDocument( 
            /* [in] */ IGcadDocument *pActiveDoc) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullName( 
            /* [retval][out] */ BSTR *FullName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *Height) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ int Height) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowLeft( 
            /* [retval][out] */ int *left) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowLeft( 
            /* [in] */ int left) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *bstrPath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LocaleId( 
            /* [retval][out] */ long *lcid) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowTop( 
            /* [retval][out] */ int *top) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowTop( 
            /* [in] */ int top) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *bstrVer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *Width) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ int Width) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Preferences( 
            /* [retval][out] */ IGcadPreferences **pPreferences) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StatusId( 
            /* [in] */ IDispatch *VportObj,
            /* [retval][out] */ VARIANT_BOOL *bStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ListGrx( 
            /* [retval][out] */ VARIANT *pVarListArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadGrx( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInterfaceObject( 
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IDispatch **pObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnloadGrx( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Quit( void) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE Zoom( 
            /* [in] */ int Type,
            /* [in] */ VARIANT *vParams) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_VBE( 
            /* [retval][out] */ IDispatch **pDispVBE) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuGroups( 
            /* [retval][out] */ IGcadMenuGroups **pMenuGroups) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuBar( 
            /* [retval][out] */ IGcadMenuBar **pMenuBar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadVBI( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnloadVBI( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Documents( 
            /* [retval][out] */ IGcadDocuments **pDocuments) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [in] */ BSTR Expression) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowState( 
            /* [retval][out] */ GcWindowState *eWinState) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowState( 
            /* [in] */ GcWindowState eWinState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunMacro( 
            /* [in] */ BSTR MacroPath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomExtents( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomCenter( 
            /* [in] */ VARIANT Center,
            /* [in] */ double Magnify) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomScaled( 
            /* [in] */ double scale,
            /* [in] */ GcZoomScaleType ScaleType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomWindow( 
            /* [in] */ VARIANT LowerLeft,
            /* [in] */ VARIANT UpperRight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomPickWindow( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAcadState( 
            /* [retval][out] */ IGcadState **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ZoomPrevious( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *HWND) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE InitApp( 
            /* [in] */ DWORD *pApp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDVB( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnloadDVB( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND32( 
            /* [retval][out] */ long *HWND) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadApplicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadApplication * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadApplication * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadApplication * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadApplication * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadApplication * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadApplication * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadApplication * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadApplication * This,
            /* [retval][out] */ VARIANT_BOOL *Visible);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadApplication * This,
            /* [in] */ VARIANT_BOOL Visible);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadApplication * This,
            /* [retval][out] */ BSTR *pAppName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IGcadApplication * This,
            /* [retval][out] */ BSTR *bstrCaption);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDocument )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadDocument **pActiveDoc);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveDocument )( 
            IGcadApplication * This,
            /* [in] */ IGcadDocument *pActiveDoc);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullName )( 
            IGcadApplication * This,
            /* [retval][out] */ BSTR *FullName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IGcadApplication * This,
            /* [retval][out] */ int *Height);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IGcadApplication * This,
            /* [in] */ int Height);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowLeft )( 
            IGcadApplication * This,
            /* [retval][out] */ int *left);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowLeft )( 
            IGcadApplication * This,
            /* [in] */ int left);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IGcadApplication * This,
            /* [retval][out] */ BSTR *bstrPath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LocaleId )( 
            IGcadApplication * This,
            /* [retval][out] */ long *lcid);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowTop )( 
            IGcadApplication * This,
            /* [retval][out] */ int *top);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowTop )( 
            IGcadApplication * This,
            /* [in] */ int top);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IGcadApplication * This,
            /* [retval][out] */ BSTR *bstrVer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IGcadApplication * This,
            /* [retval][out] */ int *Width);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IGcadApplication * This,
            /* [in] */ int Width);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Preferences )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadPreferences **pPreferences);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StatusId )( 
            IGcadApplication * This,
            /* [in] */ IDispatch *VportObj,
            /* [retval][out] */ VARIANT_BOOL *bStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ListGrx )( 
            IGcadApplication * This,
            /* [retval][out] */ VARIANT *pVarListArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadGrx )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInterfaceObject )( 
            IGcadApplication * This,
            /* [in] */ BSTR ProgID,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnloadGrx )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Quit )( 
            IGcadApplication * This);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Zoom )( 
            IGcadApplication * This,
            /* [in] */ int Type,
            /* [in] */ VARIANT *vParams);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VBE )( 
            IGcadApplication * This,
            /* [retval][out] */ IDispatch **pDispVBE);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuGroups )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadMenuGroups **pMenuGroups);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuBar )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadMenuBar **pMenuBar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadVBI )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnloadVBI )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Documents )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadDocuments **pDocuments);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Eval )( 
            IGcadApplication * This,
            /* [in] */ BSTR Expression);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowState )( 
            IGcadApplication * This,
            /* [retval][out] */ GcWindowState *eWinState);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowState )( 
            IGcadApplication * This,
            /* [in] */ GcWindowState eWinState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunMacro )( 
            IGcadApplication * This,
            /* [in] */ BSTR MacroPath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomExtents )( 
            IGcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomAll )( 
            IGcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomCenter )( 
            IGcadApplication * This,
            /* [in] */ VARIANT Center,
            /* [in] */ double Magnify);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomScaled )( 
            IGcadApplication * This,
            /* [in] */ double scale,
            /* [in] */ GcZoomScaleType ScaleType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomWindow )( 
            IGcadApplication * This,
            /* [in] */ VARIANT LowerLeft,
            /* [in] */ VARIANT UpperRight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomPickWindow )( 
            IGcadApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAcadState )( 
            IGcadApplication * This,
            /* [retval][out] */ IGcadState **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ZoomPrevious )( 
            IGcadApplication * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IGcadApplication * This,
            /* [retval][out] */ LONG_PTR *HWND);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *InitApp )( 
            IGcadApplication * This,
            /* [in] */ DWORD *pApp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadDVB )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnloadDVB )( 
            IGcadApplication * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND32 )( 
            IGcadApplication * This,
            /* [retval][out] */ long *HWND);
        
        END_INTERFACE
    } IGcadApplicationVtbl;

    interface IGcadApplication
    {
        CONST_VTBL struct IGcadApplicationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadApplication_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadApplication_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadApplication_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadApplication_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadApplication_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadApplication_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadApplication_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadApplication_get_Visible(This,Visible)	\
    ( (This)->lpVtbl -> get_Visible(This,Visible) ) 

#define IGcadApplication_put_Visible(This,Visible)	\
    ( (This)->lpVtbl -> put_Visible(This,Visible) ) 

#define IGcadApplication_get_Name(This,pAppName)	\
    ( (This)->lpVtbl -> get_Name(This,pAppName) ) 

#define IGcadApplication_get_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> get_Caption(This,bstrCaption) ) 

#define IGcadApplication_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadApplication_get_ActiveDocument(This,pActiveDoc)	\
    ( (This)->lpVtbl -> get_ActiveDocument(This,pActiveDoc) ) 

#define IGcadApplication_put_ActiveDocument(This,pActiveDoc)	\
    ( (This)->lpVtbl -> put_ActiveDocument(This,pActiveDoc) ) 

#define IGcadApplication_get_FullName(This,FullName)	\
    ( (This)->lpVtbl -> get_FullName(This,FullName) ) 

#define IGcadApplication_get_Height(This,Height)	\
    ( (This)->lpVtbl -> get_Height(This,Height) ) 

#define IGcadApplication_put_Height(This,Height)	\
    ( (This)->lpVtbl -> put_Height(This,Height) ) 

#define IGcadApplication_get_WindowLeft(This,left)	\
    ( (This)->lpVtbl -> get_WindowLeft(This,left) ) 

#define IGcadApplication_put_WindowLeft(This,left)	\
    ( (This)->lpVtbl -> put_WindowLeft(This,left) ) 

#define IGcadApplication_get_Path(This,bstrPath)	\
    ( (This)->lpVtbl -> get_Path(This,bstrPath) ) 

#define IGcadApplication_get_LocaleId(This,lcid)	\
    ( (This)->lpVtbl -> get_LocaleId(This,lcid) ) 

#define IGcadApplication_get_WindowTop(This,top)	\
    ( (This)->lpVtbl -> get_WindowTop(This,top) ) 

#define IGcadApplication_put_WindowTop(This,top)	\
    ( (This)->lpVtbl -> put_WindowTop(This,top) ) 

#define IGcadApplication_get_Version(This,bstrVer)	\
    ( (This)->lpVtbl -> get_Version(This,bstrVer) ) 

#define IGcadApplication_get_Width(This,Width)	\
    ( (This)->lpVtbl -> get_Width(This,Width) ) 

#define IGcadApplication_put_Width(This,Width)	\
    ( (This)->lpVtbl -> put_Width(This,Width) ) 

#define IGcadApplication_get_Preferences(This,pPreferences)	\
    ( (This)->lpVtbl -> get_Preferences(This,pPreferences) ) 

#define IGcadApplication_get_StatusId(This,VportObj,bStatus)	\
    ( (This)->lpVtbl -> get_StatusId(This,VportObj,bStatus) ) 

#define IGcadApplication_ListGrx(This,pVarListArray)	\
    ( (This)->lpVtbl -> ListGrx(This,pVarListArray) ) 

#define IGcadApplication_LoadGrx(This,Name)	\
    ( (This)->lpVtbl -> LoadGrx(This,Name) ) 

#define IGcadApplication_GetInterfaceObject(This,ProgID,pObj)	\
    ( (This)->lpVtbl -> GetInterfaceObject(This,ProgID,pObj) ) 

#define IGcadApplication_UnloadGrx(This,Name)	\
    ( (This)->lpVtbl -> UnloadGrx(This,Name) ) 

#define IGcadApplication_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadApplication_Quit(This)	\
    ( (This)->lpVtbl -> Quit(This) ) 

#define IGcadApplication_Zoom(This,Type,vParams)	\
    ( (This)->lpVtbl -> Zoom(This,Type,vParams) ) 

#define IGcadApplication_get_VBE(This,pDispVBE)	\
    ( (This)->lpVtbl -> get_VBE(This,pDispVBE) ) 

#define IGcadApplication_get_MenuGroups(This,pMenuGroups)	\
    ( (This)->lpVtbl -> get_MenuGroups(This,pMenuGroups) ) 

#define IGcadApplication_get_MenuBar(This,pMenuBar)	\
    ( (This)->lpVtbl -> get_MenuBar(This,pMenuBar) ) 

#define IGcadApplication_LoadVBI(This,Name)	\
    ( (This)->lpVtbl -> LoadVBI(This,Name) ) 

#define IGcadApplication_UnloadVBI(This,Name)	\
    ( (This)->lpVtbl -> UnloadVBI(This,Name) ) 

#define IGcadApplication_get_Documents(This,pDocuments)	\
    ( (This)->lpVtbl -> get_Documents(This,pDocuments) ) 

#define IGcadApplication_Eval(This,Expression)	\
    ( (This)->lpVtbl -> Eval(This,Expression) ) 

#define IGcadApplication_get_WindowState(This,eWinState)	\
    ( (This)->lpVtbl -> get_WindowState(This,eWinState) ) 

#define IGcadApplication_put_WindowState(This,eWinState)	\
    ( (This)->lpVtbl -> put_WindowState(This,eWinState) ) 

#define IGcadApplication_RunMacro(This,MacroPath)	\
    ( (This)->lpVtbl -> RunMacro(This,MacroPath) ) 

#define IGcadApplication_ZoomExtents(This)	\
    ( (This)->lpVtbl -> ZoomExtents(This) ) 

#define IGcadApplication_ZoomAll(This)	\
    ( (This)->lpVtbl -> ZoomAll(This) ) 

#define IGcadApplication_ZoomCenter(This,Center,Magnify)	\
    ( (This)->lpVtbl -> ZoomCenter(This,Center,Magnify) ) 

#define IGcadApplication_ZoomScaled(This,scale,ScaleType)	\
    ( (This)->lpVtbl -> ZoomScaled(This,scale,ScaleType) ) 

#define IGcadApplication_ZoomWindow(This,LowerLeft,UpperRight)	\
    ( (This)->lpVtbl -> ZoomWindow(This,LowerLeft,UpperRight) ) 

#define IGcadApplication_ZoomPickWindow(This)	\
    ( (This)->lpVtbl -> ZoomPickWindow(This) ) 

#define IGcadApplication_GetAcadState(This,pVal)	\
    ( (This)->lpVtbl -> GetAcadState(This,pVal) ) 

#define IGcadApplication_ZoomPrevious(This)	\
    ( (This)->lpVtbl -> ZoomPrevious(This) ) 

#define IGcadApplication_get_HWND(This,HWND)	\
    ( (This)->lpVtbl -> get_HWND(This,HWND) ) 

#define IGcadApplication_InitApp(This,pApp)	\
    ( (This)->lpVtbl -> InitApp(This,pApp) ) 

#define IGcadApplication_LoadDVB(This,Name)	\
    ( (This)->lpVtbl -> LoadDVB(This,Name) ) 

#define IGcadApplication_UnloadDVB(This,Name)	\
    ( (This)->lpVtbl -> UnloadDVB(This,Name) ) 

#define IGcadApplication_get_HWND32(This,HWND)	\
    ( (This)->lpVtbl -> get_HWND32(This,HWND) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadApplication_INTERFACE_DEFINED__ */


#ifndef __IGcadMenuGroups_INTERFACE_DEFINED__
#define __IGcadMenuGroups_INTERFACE_DEFINED__

/* interface IGcadMenuGroups */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadMenuGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1CB4149C-D49B-45BE-AEBC-D27A5B666A0B")
    IGcadMenuGroups : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadMenuGroup **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadApplication **pParent) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR MenuFileName,
            /* [optional][in] */ VARIANT BaseMenu,
            /* [retval][out] */ IGcadMenuGroup **pMenuGroup) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadMenuGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadMenuGroups * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadMenuGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadMenuGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadMenuGroups * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadMenuGroups * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadMenuGroups * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadMenuGroups * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadMenuGroups * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadMenuGroup **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadMenuGroups * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadMenuGroups * This,
            /* [retval][out] */ long *Count);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadMenuGroups * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadMenuGroups * This,
            /* [retval][out] */ IGcadApplication **pParent);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IGcadMenuGroups * This,
            /* [in] */ BSTR MenuFileName,
            /* [optional][in] */ VARIANT BaseMenu,
            /* [retval][out] */ IGcadMenuGroup **pMenuGroup);
        
        END_INTERFACE
    } IGcadMenuGroupsVtbl;

    interface IGcadMenuGroups
    {
        CONST_VTBL struct IGcadMenuGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadMenuGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadMenuGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadMenuGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadMenuGroups_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadMenuGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadMenuGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadMenuGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadMenuGroups_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadMenuGroups_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadMenuGroups_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadMenuGroups_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadMenuGroups_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadMenuGroups_Load(This,MenuFileName,BaseMenu,pMenuGroup)	\
    ( (This)->lpVtbl -> Load(This,MenuFileName,BaseMenu,pMenuGroup) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadMenuGroups_INTERFACE_DEFINED__ */


#ifndef __IGcadDocuments_INTERFACE_DEFINED__
#define __IGcadDocuments_INTERFACE_DEFINED__

/* interface IGcadDocuments */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadDocuments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31010F88-E412-4A4B-B482-B71D45D1A28A")
    IGcadDocuments : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadDocument **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [optional][in] */ VARIANT TemplateName,
            /* [retval][out] */ IGcadDocument **pDispDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT ReadOnly,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IGcadDocument **pDispDoc) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadDocumentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadDocuments * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadDocuments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadDocuments * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadDocuments * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadDocuments * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadDocuments * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadDocuments * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadDocuments * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadDocument **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadDocuments * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadDocuments * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadDocuments * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IGcadDocuments * This,
            /* [optional][in] */ VARIANT TemplateName,
            /* [retval][out] */ IGcadDocument **pDispDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IGcadDocuments * This,
            /* [in] */ BSTR Name,
            /* [optional][in] */ VARIANT ReadOnly,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IGcadDocument **pDispDoc);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IGcadDocuments * This);
        
        END_INTERFACE
    } IGcadDocumentsVtbl;

    interface IGcadDocuments
    {
        CONST_VTBL struct IGcadDocumentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadDocuments_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadDocuments_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadDocuments_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadDocuments_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadDocuments_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadDocuments_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadDocuments_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadDocuments_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadDocuments_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadDocuments_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadDocuments_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadDocuments_Add(This,TemplateName,pDispDoc)	\
    ( (This)->lpVtbl -> Add(This,TemplateName,pDispDoc) ) 

#define IGcadDocuments_Open(This,Name,ReadOnly,Password,pDispDoc)	\
    ( (This)->lpVtbl -> Open(This,Name,ReadOnly,Password,pDispDoc) ) 

#define IGcadDocuments_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadDocuments_INTERFACE_DEFINED__ */


#ifndef __IGcadState_INTERFACE_DEFINED__
#define __IGcadState_INTERFACE_DEFINED__

/* interface IGcadState */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31E08BF4-3D9F-45DC-B456-D2A2CA16E126")
    IGcadState : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsQuiescent( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadState * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadState * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadState * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadState * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadState * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadState * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsQuiescent )( 
            IGcadState * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IGcadStateVtbl;

    interface IGcadState
    {
        CONST_VTBL struct IGcadStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadState_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadState_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadState_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadState_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadState_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadState_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadState_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadState_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadState_get_IsQuiescent(This,pVal)	\
    ( (This)->lpVtbl -> get_IsQuiescent(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadState_INTERFACE_DEFINED__ */


#ifndef __IGcadPlot_INTERFACE_DEFINED__
#define __IGcadPlot_INTERFACE_DEFINED__

/* interface IGcadPlot */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadPlot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E93528F4-F504-4E58-8560-C473AD8445A2")
    IGcadPlot : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_QuietErrorMode( 
            /* [retval][out] */ VARIANT_BOOL *bErrorMode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_QuietErrorMode( 
            /* [in] */ VARIANT_BOOL bErrorMode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfCopies( 
            /* [retval][out] */ long *numCopies) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_NumberOfCopies( 
            /* [in] */ long numCopies) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BatchPlotProgress( 
            /* [retval][out] */ VARIANT_BOOL *bProgressStatus) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BatchPlotProgress( 
            /* [in] */ VARIANT_BOOL bProgressStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisplayPlotPreview( 
            /* [in] */ GcPreviewMode Preview) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlotToFile( 
            /* [in] */ BSTR plotFile,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *success) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PlotToDevice( 
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *success) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLayoutsToPlot( 
            /* [in] */ VARIANT layoutList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartBatchMode( 
            /* [in] */ long entryCount) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPlotVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPlot * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPlot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPlot * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPlot * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPlot * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPlot * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPlot * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPlot * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_QuietErrorMode )( 
            IGcadPlot * This,
            /* [retval][out] */ VARIANT_BOOL *bErrorMode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_QuietErrorMode )( 
            IGcadPlot * This,
            /* [in] */ VARIANT_BOOL bErrorMode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfCopies )( 
            IGcadPlot * This,
            /* [retval][out] */ long *numCopies);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_NumberOfCopies )( 
            IGcadPlot * This,
            /* [in] */ long numCopies);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BatchPlotProgress )( 
            IGcadPlot * This,
            /* [retval][out] */ VARIANT_BOOL *bProgressStatus);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BatchPlotProgress )( 
            IGcadPlot * This,
            /* [in] */ VARIANT_BOOL bProgressStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisplayPlotPreview )( 
            IGcadPlot * This,
            /* [in] */ GcPreviewMode Preview);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlotToFile )( 
            IGcadPlot * This,
            /* [in] */ BSTR plotFile,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *success);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PlotToDevice )( 
            IGcadPlot * This,
            /* [optional][in] */ VARIANT plotConfig,
            /* [retval][out] */ VARIANT_BOOL *success);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLayoutsToPlot )( 
            IGcadPlot * This,
            /* [in] */ VARIANT layoutList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartBatchMode )( 
            IGcadPlot * This,
            /* [in] */ long entryCount);
        
        END_INTERFACE
    } IGcadPlotVtbl;

    interface IGcadPlot
    {
        CONST_VTBL struct IGcadPlotVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPlot_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPlot_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPlot_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPlot_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPlot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPlot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPlot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPlot_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPlot_get_QuietErrorMode(This,bErrorMode)	\
    ( (This)->lpVtbl -> get_QuietErrorMode(This,bErrorMode) ) 

#define IGcadPlot_put_QuietErrorMode(This,bErrorMode)	\
    ( (This)->lpVtbl -> put_QuietErrorMode(This,bErrorMode) ) 

#define IGcadPlot_get_NumberOfCopies(This,numCopies)	\
    ( (This)->lpVtbl -> get_NumberOfCopies(This,numCopies) ) 

#define IGcadPlot_put_NumberOfCopies(This,numCopies)	\
    ( (This)->lpVtbl -> put_NumberOfCopies(This,numCopies) ) 

#define IGcadPlot_get_BatchPlotProgress(This,bProgressStatus)	\
    ( (This)->lpVtbl -> get_BatchPlotProgress(This,bProgressStatus) ) 

#define IGcadPlot_put_BatchPlotProgress(This,bProgressStatus)	\
    ( (This)->lpVtbl -> put_BatchPlotProgress(This,bProgressStatus) ) 

#define IGcadPlot_DisplayPlotPreview(This,Preview)	\
    ( (This)->lpVtbl -> DisplayPlotPreview(This,Preview) ) 

#define IGcadPlot_PlotToFile(This,plotFile,plotConfig,success)	\
    ( (This)->lpVtbl -> PlotToFile(This,plotFile,plotConfig,success) ) 

#define IGcadPlot_PlotToDevice(This,plotConfig,success)	\
    ( (This)->lpVtbl -> PlotToDevice(This,plotConfig,success) ) 

#define IGcadPlot_SetLayoutsToPlot(This,layoutList)	\
    ( (This)->lpVtbl -> SetLayoutsToPlot(This,layoutList) ) 

#define IGcadPlot_StartBatchMode(This,entryCount)	\
    ( (This)->lpVtbl -> StartBatchMode(This,entryCount) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPlot_INTERFACE_DEFINED__ */


#ifndef __IGcadSelectionSets_INTERFACE_DEFINED__
#define __IGcadSelectionSets_INTERFACE_DEFINED__

/* interface IGcadSelectionSets */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadSelectionSets;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA391ABB-844F-42A0-8F57-31EE00D0583A")
    IGcadSelectionSets : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadSelectionSet **pItem) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IGcadSelectionSet **pSet) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE GetActiveSelectionSet( 
            /* [retval][out] */ IGcadSelectionSet **pSet) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSelectionSetsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSelectionSets * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSelectionSets * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSelectionSets * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSelectionSets * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSelectionSets * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSelectionSets * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSelectionSets * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadSelectionSets * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadSelectionSet **pItem);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadSelectionSets * This,
            /* [retval][out] */ long *pVal);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadSelectionSets * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadSelectionSets * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IGcadSelectionSets * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IGcadSelectionSet **pSet);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetActiveSelectionSet )( 
            IGcadSelectionSets * This,
            /* [retval][out] */ IGcadSelectionSet **pSet);
        
        END_INTERFACE
    } IGcadSelectionSetsVtbl;

    interface IGcadSelectionSets
    {
        CONST_VTBL struct IGcadSelectionSetsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSelectionSets_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSelectionSets_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSelectionSets_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSelectionSets_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSelectionSets_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSelectionSets_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSelectionSets_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSelectionSets_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadSelectionSets_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IGcadSelectionSets_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IGcadSelectionSets_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadSelectionSets_Add(This,Name,pSet)	\
    ( (This)->lpVtbl -> Add(This,Name,pSet) ) 

#define IGcadSelectionSets_GetActiveSelectionSet(This,pSet)	\
    ( (This)->lpVtbl -> GetActiveSelectionSet(This,pSet) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSelectionSets_INTERFACE_DEFINED__ */


#ifndef __IGcadSelectionSet_INTERFACE_DEFINED__
#define __IGcadSelectionSet_INTERFACE_DEFINED__

/* interface IGcadSelectionSet */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadSelectionSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7DEA163-B4F1-4DDF-A408-2A3989603B09")
    IGcadSelectionSet : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadEntity **pEntity) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Highlight( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Erase( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Update( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddItems( 
            /* [in] */ VARIANT pSelSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItems( 
            /* [in] */ VARIANT Objects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Select( 
            /* [in] */ GcSelect Mode,
            /* [optional][in] */ VARIANT Point1,
            /* [optional][in] */ VARIANT Point2,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectAtPoint( 
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectByPolygon( 
            /* [in] */ GcSelect Mode,
            /* [in] */ VARIANT PointsList,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectOnScreen( 
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSelectionSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSelectionSet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSelectionSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSelectionSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSelectionSet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSelectionSet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSelectionSet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSelectionSet * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadSelectionSet * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadEntity **pEntity);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadSelectionSet * This,
            /* [retval][out] */ long *pVal);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadSelectionSet * This,
            /* [retval][out] */ IUnknown **pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadSelectionSet * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Highlight )( 
            IGcadSelectionSet * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadSelectionSet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Update )( 
            IGcadSelectionSet * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadSelectionSet * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddItems )( 
            IGcadSelectionSet * This,
            /* [in] */ VARIANT pSelSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItems )( 
            IGcadSelectionSet * This,
            /* [in] */ VARIANT Objects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IGcadSelectionSet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Select )( 
            IGcadSelectionSet * This,
            /* [in] */ GcSelect Mode,
            /* [optional][in] */ VARIANT Point1,
            /* [optional][in] */ VARIANT Point2,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectAtPoint )( 
            IGcadSelectionSet * This,
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectByPolygon )( 
            IGcadSelectionSet * This,
            /* [in] */ GcSelect Mode,
            /* [in] */ VARIANT PointsList,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectOnScreen )( 
            IGcadSelectionSet * This,
            /* [optional][in] */ VARIANT FilterType,
            /* [optional][in] */ VARIANT FilterData);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadSelectionSet * This);
        
        END_INTERFACE
    } IGcadSelectionSetVtbl;

    interface IGcadSelectionSet
    {
        CONST_VTBL struct IGcadSelectionSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSelectionSet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSelectionSet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSelectionSet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSelectionSet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSelectionSet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSelectionSet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSelectionSet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSelectionSet_Item(This,Index,pEntity)	\
    ( (This)->lpVtbl -> Item(This,Index,pEntity) ) 

#define IGcadSelectionSet_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IGcadSelectionSet_get__NewEnum(This,pVal)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pVal) ) 

#define IGcadSelectionSet_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IGcadSelectionSet_Highlight(This,bFlag)	\
    ( (This)->lpVtbl -> Highlight(This,bFlag) ) 

#define IGcadSelectionSet_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 

#define IGcadSelectionSet_Update(This)	\
    ( (This)->lpVtbl -> Update(This) ) 

#define IGcadSelectionSet_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadSelectionSet_AddItems(This,pSelSet)	\
    ( (This)->lpVtbl -> AddItems(This,pSelSet) ) 

#define IGcadSelectionSet_RemoveItems(This,Objects)	\
    ( (This)->lpVtbl -> RemoveItems(This,Objects) ) 

#define IGcadSelectionSet_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IGcadSelectionSet_Select(This,Mode,Point1,Point2,FilterType,FilterData)	\
    ( (This)->lpVtbl -> Select(This,Mode,Point1,Point2,FilterType,FilterData) ) 

#define IGcadSelectionSet_SelectAtPoint(This,Point,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectAtPoint(This,Point,FilterType,FilterData) ) 

#define IGcadSelectionSet_SelectByPolygon(This,Mode,PointsList,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectByPolygon(This,Mode,PointsList,FilterType,FilterData) ) 

#define IGcadSelectionSet_SelectOnScreen(This,FilterType,FilterData)	\
    ( (This)->lpVtbl -> SelectOnScreen(This,FilterType,FilterData) ) 

#define IGcadSelectionSet_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSelectionSet_INTERFACE_DEFINED__ */


#ifndef __IGcadUtility_INTERFACE_DEFINED__
#define __IGcadUtility_INTERFACE_DEFINED__

/* interface IGcadUtility */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadUtility;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE85BBED-B6CD-446F-B3F6-052465802DB6")
    IGcadUtility : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleToReal( 
            /* [in] */ BSTR Angle,
            /* [in] */ GcAngleUnits Unit,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleToString( 
            /* [in] */ double Angle,
            /* [in] */ GcAngleUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DistanceToReal( 
            /* [in] */ BSTR Distance,
            /* [in] */ GcUnits Unit,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RealToString( 
            /* [in] */ double Value,
            /* [in] */ GcUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TranslateCoordinates( 
            /* [in] */ VARIANT Point,
            /* [in] */ GcCoordinateSystem FromCoordSystem,
            /* [in] */ GcCoordinateSystem ToCoordSystem,
            /* [in] */ int Displacement,
            /* [optional][in] */ VARIANT OCSNormal,
            /* [retval][out] */ VARIANT *transPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializeUserInput( 
            /* [in] */ int Bits,
            /* [optional][in] */ VARIANT KeyWordList) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInteger( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ int *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReal( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInput( 
            /* [retval][out] */ BSTR *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetKeyword( 
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrKeyword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetString( 
            /* [in] */ int HasSpaces,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngle( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AngleFromXAxis( 
            /* [in] */ VARIANT StartPoint,
            /* [in] */ VARIANT EndPoint,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCorner( 
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *corner) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistance( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *dist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOrientation( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPoint( 
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *inputPoint) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PolarPoint( 
            /* [in] */ VARIANT Point,
            /* [in] */ double Angle,
            /* [in] */ double Distance,
            /* [retval][out] */ VARIANT *inputPoint) = 0;
        
        virtual /* [helpstring][vararg][id] */ HRESULT STDMETHODCALLTYPE CreateTypedArray( 
            /* [out] */ VARIANT *varArr,
            /* [in] */ int Type,
            /* [in] */ SAFEARRAY * inArgs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEntity( 
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [optional][in] */ VARIANT Prompt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Prompt( 
            /* [in] */ BSTR Message) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSubEntity( 
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsURL( 
            /* [in] */ BSTR URL,
            /* [retval][out] */ VARIANT_BOOL *IsValidURL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRemoteFile( 
            /* [in] */ BSTR URL,
            /* [out] */ BSTR *LocalFile,
            /* [in] */ VARIANT_BOOL IgnoreCache) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutRemoteFile( 
            /* [in] */ BSTR URL,
            /* [in] */ BSTR LocalFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsRemoteFile( 
            /* [in] */ BSTR LocalFile,
            /* [out] */ BSTR *URL,
            /* [retval][out] */ VARIANT_BOOL *IsDownloadedFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchBrowserDialog( 
            /* [out] */ BSTR *SelectedURL,
            /* [in] */ BSTR DialogTitle,
            /* [in] */ BSTR OpenButtonCaption,
            /* [in] */ BSTR StartPageURL,
            /* [in] */ BSTR RegistryRootKey,
            /* [in] */ VARIANT_BOOL OpenButtonAlwaysEnabled,
            /* [retval][out] */ VARIANT_BOOL *success) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendModelessOperationStart( 
            BSTR Context) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendModelessOperationEnded( 
            BSTR Context) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSubEntity32( 
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ObjectId32ToObjectIdString( 
            /* [in] */ long ObjectID32,
            /* [retval][out] */ BSTR *ObjectIdString) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetObjectIdString( 
            /* [in] */ IDispatch *Object,
            /* [in] */ VARIANT_BOOL bHex,
            /* [retval][out] */ BSTR *ObjectIdString) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadUtilityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadUtility * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadUtility * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadUtility * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadUtility * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadUtility * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadUtility * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadUtility * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleToReal )( 
            IGcadUtility * This,
            /* [in] */ BSTR Angle,
            /* [in] */ GcAngleUnits Unit,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleToString )( 
            IGcadUtility * This,
            /* [in] */ double Angle,
            /* [in] */ GcAngleUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DistanceToReal )( 
            IGcadUtility * This,
            /* [in] */ BSTR Distance,
            /* [in] */ GcUnits Unit,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RealToString )( 
            IGcadUtility * This,
            /* [in] */ double Value,
            /* [in] */ GcUnits Unit,
            /* [in] */ int precision,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TranslateCoordinates )( 
            IGcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [in] */ GcCoordinateSystem FromCoordSystem,
            /* [in] */ GcCoordinateSystem ToCoordSystem,
            /* [in] */ int Displacement,
            /* [optional][in] */ VARIANT OCSNormal,
            /* [retval][out] */ VARIANT *transPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitializeUserInput )( 
            IGcadUtility * This,
            /* [in] */ int Bits,
            /* [optional][in] */ VARIANT KeyWordList);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInteger )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ int *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetReal )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInput )( 
            IGcadUtility * This,
            /* [retval][out] */ BSTR *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetKeyword )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrKeyword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IGcadUtility * This,
            /* [in] */ int HasSpaces,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngle )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AngleFromXAxis )( 
            IGcadUtility * This,
            /* [in] */ VARIANT StartPoint,
            /* [in] */ VARIANT EndPoint,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCorner )( 
            IGcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *corner);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistance )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *dist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOrientation )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ double *Angle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPoint )( 
            IGcadUtility * This,
            /* [optional][in] */ VARIANT Point,
            /* [optional][in] */ VARIANT Prompt,
            /* [retval][out] */ VARIANT *inputPoint);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PolarPoint )( 
            IGcadUtility * This,
            /* [in] */ VARIANT Point,
            /* [in] */ double Angle,
            /* [in] */ double Distance,
            /* [retval][out] */ VARIANT *inputPoint);
        
        /* [helpstring][vararg][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTypedArray )( 
            IGcadUtility * This,
            /* [out] */ VARIANT *varArr,
            /* [in] */ int Type,
            /* [in] */ SAFEARRAY * inArgs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            IGcadUtility * This,
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [optional][in] */ VARIANT Prompt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Prompt )( 
            IGcadUtility * This,
            /* [in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSubEntity )( 
            IGcadUtility * This,
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsURL )( 
            IGcadUtility * This,
            /* [in] */ BSTR URL,
            /* [retval][out] */ VARIANT_BOOL *IsValidURL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRemoteFile )( 
            IGcadUtility * This,
            /* [in] */ BSTR URL,
            /* [out] */ BSTR *LocalFile,
            /* [in] */ VARIANT_BOOL IgnoreCache);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutRemoteFile )( 
            IGcadUtility * This,
            /* [in] */ BSTR URL,
            /* [in] */ BSTR LocalFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsRemoteFile )( 
            IGcadUtility * This,
            /* [in] */ BSTR LocalFile,
            /* [out] */ BSTR *URL,
            /* [retval][out] */ VARIANT_BOOL *IsDownloadedFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LaunchBrowserDialog )( 
            IGcadUtility * This,
            /* [out] */ BSTR *SelectedURL,
            /* [in] */ BSTR DialogTitle,
            /* [in] */ BSTR OpenButtonCaption,
            /* [in] */ BSTR StartPageURL,
            /* [in] */ BSTR RegistryRootKey,
            /* [in] */ VARIANT_BOOL OpenButtonAlwaysEnabled,
            /* [retval][out] */ VARIANT_BOOL *success);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendModelessOperationStart )( 
            IGcadUtility * This,
            BSTR Context);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendModelessOperationEnded )( 
            IGcadUtility * This,
            BSTR Context);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSubEntity32 )( 
            IGcadUtility * This,
            /* [out] */ IDispatch **Object,
            /* [out] */ VARIANT *PickedPoint,
            /* [out] */ VARIANT *transMatrix,
            /* [out] */ VARIANT *ContextData,
            /* [optional][in] */ VARIANT Prompt);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObjectId32ToObjectIdString )( 
            IGcadUtility * This,
            /* [in] */ long ObjectID32,
            /* [retval][out] */ BSTR *ObjectIdString);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetObjectIdString )( 
            IGcadUtility * This,
            /* [in] */ IDispatch *Object,
            /* [in] */ VARIANT_BOOL bHex,
            /* [retval][out] */ BSTR *ObjectIdString);
        
        END_INTERFACE
    } IGcadUtilityVtbl;

    interface IGcadUtility
    {
        CONST_VTBL struct IGcadUtilityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadUtility_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadUtility_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadUtility_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadUtility_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadUtility_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadUtility_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadUtility_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadUtility_AngleToReal(This,Angle,Unit,Value)	\
    ( (This)->lpVtbl -> AngleToReal(This,Angle,Unit,Value) ) 

#define IGcadUtility_AngleToString(This,Angle,Unit,precision,bstrValue)	\
    ( (This)->lpVtbl -> AngleToString(This,Angle,Unit,precision,bstrValue) ) 

#define IGcadUtility_DistanceToReal(This,Distance,Unit,Value)	\
    ( (This)->lpVtbl -> DistanceToReal(This,Distance,Unit,Value) ) 

#define IGcadUtility_RealToString(This,Value,Unit,precision,bstrValue)	\
    ( (This)->lpVtbl -> RealToString(This,Value,Unit,precision,bstrValue) ) 

#define IGcadUtility_TranslateCoordinates(This,Point,FromCoordSystem,ToCoordSystem,Displacement,OCSNormal,transPt)	\
    ( (This)->lpVtbl -> TranslateCoordinates(This,Point,FromCoordSystem,ToCoordSystem,Displacement,OCSNormal,transPt) ) 

#define IGcadUtility_InitializeUserInput(This,Bits,KeyWordList)	\
    ( (This)->lpVtbl -> InitializeUserInput(This,Bits,KeyWordList) ) 

#define IGcadUtility_GetInteger(This,Prompt,Value)	\
    ( (This)->lpVtbl -> GetInteger(This,Prompt,Value) ) 

#define IGcadUtility_GetReal(This,Prompt,Value)	\
    ( (This)->lpVtbl -> GetReal(This,Prompt,Value) ) 

#define IGcadUtility_GetInput(This,Value)	\
    ( (This)->lpVtbl -> GetInput(This,Value) ) 

#define IGcadUtility_GetKeyword(This,Prompt,bstrKeyword)	\
    ( (This)->lpVtbl -> GetKeyword(This,Prompt,bstrKeyword) ) 

#define IGcadUtility_GetString(This,HasSpaces,Prompt,bstrValue)	\
    ( (This)->lpVtbl -> GetString(This,HasSpaces,Prompt,bstrValue) ) 

#define IGcadUtility_GetAngle(This,Point,Prompt,Angle)	\
    ( (This)->lpVtbl -> GetAngle(This,Point,Prompt,Angle) ) 

#define IGcadUtility_AngleFromXAxis(This,StartPoint,EndPoint,Angle)	\
    ( (This)->lpVtbl -> AngleFromXAxis(This,StartPoint,EndPoint,Angle) ) 

#define IGcadUtility_GetCorner(This,Point,Prompt,corner)	\
    ( (This)->lpVtbl -> GetCorner(This,Point,Prompt,corner) ) 

#define IGcadUtility_GetDistance(This,Point,Prompt,dist)	\
    ( (This)->lpVtbl -> GetDistance(This,Point,Prompt,dist) ) 

#define IGcadUtility_GetOrientation(This,Point,Prompt,Angle)	\
    ( (This)->lpVtbl -> GetOrientation(This,Point,Prompt,Angle) ) 

#define IGcadUtility_GetPoint(This,Point,Prompt,inputPoint)	\
    ( (This)->lpVtbl -> GetPoint(This,Point,Prompt,inputPoint) ) 

#define IGcadUtility_PolarPoint(This,Point,Angle,Distance,inputPoint)	\
    ( (This)->lpVtbl -> PolarPoint(This,Point,Angle,Distance,inputPoint) ) 

#define IGcadUtility_CreateTypedArray(This,varArr,Type,inArgs)	\
    ( (This)->lpVtbl -> CreateTypedArray(This,varArr,Type,inArgs) ) 

#define IGcadUtility_GetEntity(This,Object,PickedPoint,Prompt)	\
    ( (This)->lpVtbl -> GetEntity(This,Object,PickedPoint,Prompt) ) 

#define IGcadUtility_Prompt(This,Message)	\
    ( (This)->lpVtbl -> Prompt(This,Message) ) 

#define IGcadUtility_GetSubEntity(This,Object,PickedPoint,transMatrix,ContextData,Prompt)	\
    ( (This)->lpVtbl -> GetSubEntity(This,Object,PickedPoint,transMatrix,ContextData,Prompt) ) 

#define IGcadUtility_IsURL(This,URL,IsValidURL)	\
    ( (This)->lpVtbl -> IsURL(This,URL,IsValidURL) ) 

#define IGcadUtility_GetRemoteFile(This,URL,LocalFile,IgnoreCache)	\
    ( (This)->lpVtbl -> GetRemoteFile(This,URL,LocalFile,IgnoreCache) ) 

#define IGcadUtility_PutRemoteFile(This,URL,LocalFile)	\
    ( (This)->lpVtbl -> PutRemoteFile(This,URL,LocalFile) ) 

#define IGcadUtility_IsRemoteFile(This,LocalFile,URL,IsDownloadedFile)	\
    ( (This)->lpVtbl -> IsRemoteFile(This,LocalFile,URL,IsDownloadedFile) ) 

#define IGcadUtility_LaunchBrowserDialog(This,SelectedURL,DialogTitle,OpenButtonCaption,StartPageURL,RegistryRootKey,OpenButtonAlwaysEnabled,success)	\
    ( (This)->lpVtbl -> LaunchBrowserDialog(This,SelectedURL,DialogTitle,OpenButtonCaption,StartPageURL,RegistryRootKey,OpenButtonAlwaysEnabled,success) ) 

#define IGcadUtility_SendModelessOperationStart(This,Context)	\
    ( (This)->lpVtbl -> SendModelessOperationStart(This,Context) ) 

#define IGcadUtility_SendModelessOperationEnded(This,Context)	\
    ( (This)->lpVtbl -> SendModelessOperationEnded(This,Context) ) 

#define IGcadUtility_GetSubEntity32(This,Object,PickedPoint,transMatrix,ContextData,Prompt)	\
    ( (This)->lpVtbl -> GetSubEntity32(This,Object,PickedPoint,transMatrix,ContextData,Prompt) ) 

#define IGcadUtility_ObjectId32ToObjectIdString(This,ObjectID32,ObjectIdString)	\
    ( (This)->lpVtbl -> ObjectId32ToObjectIdString(This,ObjectID32,ObjectIdString) ) 

#define IGcadUtility_GetObjectIdString(This,Object,bHex,ObjectIdString)	\
    ( (This)->lpVtbl -> GetObjectIdString(This,Object,bHex,ObjectIdString) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadUtility_INTERFACE_DEFINED__ */


#ifndef __IGcadDocument_INTERFACE_DEFINED__
#define __IGcadDocument_INTERFACE_DEFINED__

/* interface IGcadDocument */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9368AF30-60A3-47E3-A743-60D4C21FB580")
    IGcadDocument : public IGcadDatabase
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Plot( 
            /* [retval][out] */ IGcadPlot **pPlot) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLayer( 
            /* [retval][out] */ IGcadLayer **pActLayer) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLayer( 
            /* [in] */ IGcadLayer *pActLayer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLinetype( 
            /* [retval][out] */ IGcadLineType **pActLinetype) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLinetype( 
            /* [in] */ IGcadLineType *pActLinetype) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveDimStyle( 
            /* [retval][out] */ IGcadDimStyle **pActDimStyle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveDimStyle( 
            /* [in] */ IGcadDimStyle *pActDimStyle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveTextStyle( 
            /* [retval][out] */ IGcadTextStyle **pActTextStyle) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveTextStyle( 
            /* [in] */ IGcadTextStyle *pActTextStyle) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveUCS( 
            /* [retval][out] */ IGcadUCS **pActUCS) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveUCS( 
            /* [in] */ IGcadUCS *pActUCS) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveViewport( 
            /* [retval][out] */ IGcadViewport **pActView) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveViewport( 
            /* [in] */ IGcadViewport *pActView) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActivePViewport( 
            /* [retval][out] */ IGcadPViewport **pActView) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActivePViewport( 
            /* [in] */ IGcadPViewport *pActView) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveSpace( 
            /* [retval][out] */ GcActiveSpace *ActSpace) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveSpace( 
            /* [in] */ GcActiveSpace ActSpace) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SelectionSets( 
            /* [retval][out] */ IGcadSelectionSets **pSelSets) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveSelectionSet( 
            /* [retval][out] */ IGcadSelectionSet **pSelSet) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullName( 
            /* [retval][out] */ BSTR *FullName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Path( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectSnapMode( 
            /* [retval][out] */ VARIANT_BOOL *fSnapMode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ObjectSnapMode( 
            /* [in] */ VARIANT_BOOL fSnapMode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *bReadOnly) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Saved( 
            /* [retval][out] */ VARIANT_BOOL *bSaved) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MSpace( 
            /* [retval][out] */ VARIANT_BOOL *Mode) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MSpace( 
            /* [in] */ VARIANT_BOOL Mode) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Utility( 
            /* [retval][out] */ IGcadUtility **pUtil) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ BSTR FullName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IGcadDocument **pDocObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AuditInfo( 
            /* [in] */ VARIANT_BOOL FixErr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT InsertionPoint,
            /* [in] */ double ScaleFactor,
            /* [retval][out] */ IDispatch **pObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Extension,
            /* [in] */ IGcadSelectionSet *SelectionSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE New( 
            /* [in] */ BSTR TemplateFileName,
            /* [retval][out] */ IGcadDocument **pDocObj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR FullFileName,
            /* [optional][in] */ VARIANT SaveAsType,
            /* [optional][in] */ VARIANT vSecurityParams) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Wblock( 
            /* [in] */ BSTR FileName,
            /* [in] */ IGcadSelectionSet *SelectionSet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PurgeAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariable( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariable( 
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadShapeFile( 
            /* [in] */ BSTR FullName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Regen( 
            /* [in] */ GcRegenType WhichViewports) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickfirstSelectionSet( 
            /* [retval][out] */ IGcadSelectionSet **pSelSet) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pvbActive) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [optional][in] */ VARIANT SaveChanges,
            /* [optional][in] */ VARIANT FileName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WindowState( 
            /* [in] */ GcWindowState pWinState) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowState( 
            /* [retval][out] */ GcWindowState *pWinState) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Width( 
            /* [in] */ int pWidth) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *pWidth) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Height( 
            /* [in] */ int pHeight) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *pHeight) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveLayout( 
            /* [in] */ IGcadLayout *pLayout) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveLayout( 
            /* [retval][out] */ IGcadLayout **pLayout) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendCommand( 
            /* [in] */ BSTR Command) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *HWND) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WindowTitle( 
            /* [retval][out] */ BSTR *Title) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Database( 
            /* [retval][out] */ IGcadDatabase **pDatabase) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartUndoMark( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndUndoMark( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveMaterial( 
            /* [retval][out] */ IGcadMaterial **pActMaterial) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveMaterial( 
            /* [in] */ IGcadMaterial *pActMaterial) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE InitDoc( 
            /* [in] */ DWORD *pDoc) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE BindDatabase( 
            /* [in] */ DWORD *pDb) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HWND32( 
            /* [retval][out] */ long *HWND) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadDocument * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadDocument * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadDocument * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadDocument * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadDocument * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadDocument * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadDocument * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ModelSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadModelSpace **pMSpace);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PaperSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadPaperSpace **pPSpace);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Blocks )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadBlocks **pBlocks);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyObjects )( 
            IGcadDocument * This,
            /* [in] */ VARIANT Objects,
            /* [optional][in] */ VARIANT Owner,
            /* [optional][out][in] */ VARIANT *IdPairs,
            /* [retval][out] */ VARIANT *pNewObjects);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadGroups **pGroups);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DimStyles )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadDimStyles **pDimStyles);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layers )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLayers **pLayers);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Linetypes )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLineTypes **pLinetypes);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Dictionaries )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadDictionaries **pDictionaries);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RegisteredApplications )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadRegisteredApplications **pRegApps);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextStyles )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadTextStyles **pTextStyles);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UserCoordinateSystems )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadUCSs **pUCSs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Views )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadViews **pViews);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Viewports )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadViewports **pViewports);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ElevationModelSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ double *Elevation);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ElevationModelSpace )( 
            IGcadDocument * This,
            /* [in] */ double Elevation);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ElevationPaperSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ double *Elevation);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ElevationPaperSpace )( 
            IGcadDocument * This,
            /* [in] */ double Elevation);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Limits )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT *Limits);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Limits )( 
            IGcadDocument * This,
            /* [in] */ VARIANT Limits);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HandleToObject )( 
            IGcadDocument * This,
            /* [in] */ BSTR Handle,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ObjectIdToObject )( 
            IGcadDocument * This,
            /* [in] */ LONG_PTR ObjectID,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Layouts )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLayouts **pLayouts);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotConfigurations )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadPlotConfigurations **pPlotConfigs);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Preferences )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadDatabasePreferences **pPref);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FileDependencies )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadFileDependencies **pFDM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SummaryInfo )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadSummaryInfo **pSummaryInfo);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SectionManager )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadSectionManager **pSecMgr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Materials )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadMaterials **pMaterials);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ObjectIdToObject32 )( 
            IGcadDocument * This,
            /* [in] */ long ObjectID,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Plot )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadPlot **pPlot);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayer )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLayer **pActLayer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLayer )( 
            IGcadDocument * This,
            /* [in] */ IGcadLayer *pActLayer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLinetype )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLineType **pActLinetype);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLinetype )( 
            IGcadDocument * This,
            /* [in] */ IGcadLineType *pActLinetype);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveDimStyle )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadDimStyle **pActDimStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveDimStyle )( 
            IGcadDocument * This,
            /* [in] */ IGcadDimStyle *pActDimStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveTextStyle )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadTextStyle **pActTextStyle);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveTextStyle )( 
            IGcadDocument * This,
            /* [in] */ IGcadTextStyle *pActTextStyle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveUCS )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadUCS **pActUCS);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveUCS )( 
            IGcadDocument * This,
            /* [in] */ IGcadUCS *pActUCS);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveViewport )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadViewport **pActView);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveViewport )( 
            IGcadDocument * This,
            /* [in] */ IGcadViewport *pActView);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActivePViewport )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadPViewport **pActView);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActivePViewport )( 
            IGcadDocument * This,
            /* [in] */ IGcadPViewport *pActView);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ GcActiveSpace *ActSpace);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveSpace )( 
            IGcadDocument * This,
            /* [in] */ GcActiveSpace ActSpace);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SelectionSets )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadSelectionSets **pSelSets);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveSelectionSet )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadSelectionSet **pSelSet);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullName )( 
            IGcadDocument * This,
            /* [retval][out] */ BSTR *FullName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadDocument * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            IGcadDocument * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectSnapMode )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *fSnapMode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectSnapMode )( 
            IGcadDocument * This,
            /* [in] */ VARIANT_BOOL fSnapMode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *bReadOnly);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Saved )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *bSaved);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MSpace )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *Mode);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MSpace )( 
            IGcadDocument * This,
            /* [in] */ VARIANT_BOOL Mode);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Utility )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadUtility **pUtil);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IGcadDocument * This,
            /* [in] */ BSTR FullName,
            /* [optional][in] */ VARIANT Password,
            /* [retval][out] */ IGcadDocument **pDocObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AuditInfo )( 
            IGcadDocument * This,
            /* [in] */ VARIANT_BOOL FixErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IGcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ VARIANT InsertionPoint,
            /* [in] */ double ScaleFactor,
            /* [retval][out] */ IDispatch **pObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IGcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ BSTR Extension,
            /* [in] */ IGcadSelectionSet *SelectionSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *New )( 
            IGcadDocument * This,
            /* [in] */ BSTR TemplateFileName,
            /* [retval][out] */ IGcadDocument **pDocObj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IGcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IGcadDocument * This,
            /* [in] */ BSTR FullFileName,
            /* [optional][in] */ VARIANT SaveAsType,
            /* [optional][in] */ VARIANT vSecurityParams);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Wblock )( 
            IGcadDocument * This,
            /* [in] */ BSTR FileName,
            /* [in] */ IGcadSelectionSet *SelectionSet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PurgeAll )( 
            IGcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariable )( 
            IGcadDocument * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ VARIANT *Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVariable )( 
            IGcadDocument * This,
            /* [in] */ BSTR Name,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadShapeFile )( 
            IGcadDocument * This,
            /* [in] */ BSTR FullName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Regen )( 
            IGcadDocument * This,
            /* [in] */ GcRegenType WhichViewports);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickfirstSelectionSet )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadSelectionSet **pSelSet);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IGcadDocument * This,
            /* [retval][out] */ VARIANT_BOOL *pvbActive);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            IGcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IGcadDocument * This,
            /* [optional][in] */ VARIANT SaveChanges,
            /* [optional][in] */ VARIANT FileName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WindowState )( 
            IGcadDocument * This,
            /* [in] */ GcWindowState pWinState);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowState )( 
            IGcadDocument * This,
            /* [retval][out] */ GcWindowState *pWinState);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Width )( 
            IGcadDocument * This,
            /* [in] */ int pWidth);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IGcadDocument * This,
            /* [retval][out] */ int *pWidth);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Height )( 
            IGcadDocument * This,
            /* [in] */ int pHeight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IGcadDocument * This,
            /* [retval][out] */ int *pHeight);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveLayout )( 
            IGcadDocument * This,
            /* [in] */ IGcadLayout *pLayout);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveLayout )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadLayout **pLayout);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendCommand )( 
            IGcadDocument * This,
            /* [in] */ BSTR Command);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IGcadDocument * This,
            /* [retval][out] */ LONG_PTR *HWND);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WindowTitle )( 
            IGcadDocument * This,
            /* [retval][out] */ BSTR *Title);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartUndoMark )( 
            IGcadDocument * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndUndoMark )( 
            IGcadDocument * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveMaterial )( 
            IGcadDocument * This,
            /* [retval][out] */ IGcadMaterial **pActMaterial);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveMaterial )( 
            IGcadDocument * This,
            /* [in] */ IGcadMaterial *pActMaterial);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *InitDoc )( 
            IGcadDocument * This,
            /* [in] */ DWORD *pDoc);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *BindDatabase )( 
            IGcadDocument * This,
            /* [in] */ DWORD *pDb);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HWND32 )( 
            IGcadDocument * This,
            /* [retval][out] */ long *HWND);
        
        END_INTERFACE
    } IGcadDocumentVtbl;

    interface IGcadDocument
    {
        CONST_VTBL struct IGcadDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadDocument_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadDocument_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadDocument_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadDocument_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadDocument_get_ModelSpace(This,pMSpace)	\
    ( (This)->lpVtbl -> get_ModelSpace(This,pMSpace) ) 

#define IGcadDocument_get_PaperSpace(This,pPSpace)	\
    ( (This)->lpVtbl -> get_PaperSpace(This,pPSpace) ) 

#define IGcadDocument_get_Blocks(This,pBlocks)	\
    ( (This)->lpVtbl -> get_Blocks(This,pBlocks) ) 

#define IGcadDocument_CopyObjects(This,Objects,Owner,IdPairs,pNewObjects)	\
    ( (This)->lpVtbl -> CopyObjects(This,Objects,Owner,IdPairs,pNewObjects) ) 

#define IGcadDocument_get_Groups(This,pGroups)	\
    ( (This)->lpVtbl -> get_Groups(This,pGroups) ) 

#define IGcadDocument_get_DimStyles(This,pDimStyles)	\
    ( (This)->lpVtbl -> get_DimStyles(This,pDimStyles) ) 

#define IGcadDocument_get_Layers(This,pLayers)	\
    ( (This)->lpVtbl -> get_Layers(This,pLayers) ) 

#define IGcadDocument_get_Linetypes(This,pLinetypes)	\
    ( (This)->lpVtbl -> get_Linetypes(This,pLinetypes) ) 

#define IGcadDocument_get_Dictionaries(This,pDictionaries)	\
    ( (This)->lpVtbl -> get_Dictionaries(This,pDictionaries) ) 

#define IGcadDocument_get_RegisteredApplications(This,pRegApps)	\
    ( (This)->lpVtbl -> get_RegisteredApplications(This,pRegApps) ) 

#define IGcadDocument_get_TextStyles(This,pTextStyles)	\
    ( (This)->lpVtbl -> get_TextStyles(This,pTextStyles) ) 

#define IGcadDocument_get_UserCoordinateSystems(This,pUCSs)	\
    ( (This)->lpVtbl -> get_UserCoordinateSystems(This,pUCSs) ) 

#define IGcadDocument_get_Views(This,pViews)	\
    ( (This)->lpVtbl -> get_Views(This,pViews) ) 

#define IGcadDocument_get_Viewports(This,pViewports)	\
    ( (This)->lpVtbl -> get_Viewports(This,pViewports) ) 

#define IGcadDocument_get_ElevationModelSpace(This,Elevation)	\
    ( (This)->lpVtbl -> get_ElevationModelSpace(This,Elevation) ) 

#define IGcadDocument_put_ElevationModelSpace(This,Elevation)	\
    ( (This)->lpVtbl -> put_ElevationModelSpace(This,Elevation) ) 

#define IGcadDocument_get_ElevationPaperSpace(This,Elevation)	\
    ( (This)->lpVtbl -> get_ElevationPaperSpace(This,Elevation) ) 

#define IGcadDocument_put_ElevationPaperSpace(This,Elevation)	\
    ( (This)->lpVtbl -> put_ElevationPaperSpace(This,Elevation) ) 

#define IGcadDocument_get_Limits(This,Limits)	\
    ( (This)->lpVtbl -> get_Limits(This,Limits) ) 

#define IGcadDocument_put_Limits(This,Limits)	\
    ( (This)->lpVtbl -> put_Limits(This,Limits) ) 

#define IGcadDocument_HandleToObject(This,Handle,pObj)	\
    ( (This)->lpVtbl -> HandleToObject(This,Handle,pObj) ) 

#define IGcadDocument_ObjectIdToObject(This,ObjectID,pObj)	\
    ( (This)->lpVtbl -> ObjectIdToObject(This,ObjectID,pObj) ) 

#define IGcadDocument_get_Layouts(This,pLayouts)	\
    ( (This)->lpVtbl -> get_Layouts(This,pLayouts) ) 

#define IGcadDocument_get_PlotConfigurations(This,pPlotConfigs)	\
    ( (This)->lpVtbl -> get_PlotConfigurations(This,pPlotConfigs) ) 

#define IGcadDocument_get_Preferences(This,pPref)	\
    ( (This)->lpVtbl -> get_Preferences(This,pPref) ) 

#define IGcadDocument_get_FileDependencies(This,pFDM)	\
    ( (This)->lpVtbl -> get_FileDependencies(This,pFDM) ) 

#define IGcadDocument_get_SummaryInfo(This,pSummaryInfo)	\
    ( (This)->lpVtbl -> get_SummaryInfo(This,pSummaryInfo) ) 

#define IGcadDocument_get_SectionManager(This,pSecMgr)	\
    ( (This)->lpVtbl -> get_SectionManager(This,pSecMgr) ) 

#define IGcadDocument_get_Materials(This,pMaterials)	\
    ( (This)->lpVtbl -> get_Materials(This,pMaterials) ) 

#define IGcadDocument_ObjectIdToObject32(This,ObjectID,pObj)	\
    ( (This)->lpVtbl -> ObjectIdToObject32(This,ObjectID,pObj) ) 


#define IGcadDocument_get_Plot(This,pPlot)	\
    ( (This)->lpVtbl -> get_Plot(This,pPlot) ) 

#define IGcadDocument_get_ActiveLayer(This,pActLayer)	\
    ( (This)->lpVtbl -> get_ActiveLayer(This,pActLayer) ) 

#define IGcadDocument_put_ActiveLayer(This,pActLayer)	\
    ( (This)->lpVtbl -> put_ActiveLayer(This,pActLayer) ) 

#define IGcadDocument_get_ActiveLinetype(This,pActLinetype)	\
    ( (This)->lpVtbl -> get_ActiveLinetype(This,pActLinetype) ) 

#define IGcadDocument_put_ActiveLinetype(This,pActLinetype)	\
    ( (This)->lpVtbl -> put_ActiveLinetype(This,pActLinetype) ) 

#define IGcadDocument_get_ActiveDimStyle(This,pActDimStyle)	\
    ( (This)->lpVtbl -> get_ActiveDimStyle(This,pActDimStyle) ) 

#define IGcadDocument_put_ActiveDimStyle(This,pActDimStyle)	\
    ( (This)->lpVtbl -> put_ActiveDimStyle(This,pActDimStyle) ) 

#define IGcadDocument_get_ActiveTextStyle(This,pActTextStyle)	\
    ( (This)->lpVtbl -> get_ActiveTextStyle(This,pActTextStyle) ) 

#define IGcadDocument_put_ActiveTextStyle(This,pActTextStyle)	\
    ( (This)->lpVtbl -> put_ActiveTextStyle(This,pActTextStyle) ) 

#define IGcadDocument_get_ActiveUCS(This,pActUCS)	\
    ( (This)->lpVtbl -> get_ActiveUCS(This,pActUCS) ) 

#define IGcadDocument_put_ActiveUCS(This,pActUCS)	\
    ( (This)->lpVtbl -> put_ActiveUCS(This,pActUCS) ) 

#define IGcadDocument_get_ActiveViewport(This,pActView)	\
    ( (This)->lpVtbl -> get_ActiveViewport(This,pActView) ) 

#define IGcadDocument_put_ActiveViewport(This,pActView)	\
    ( (This)->lpVtbl -> put_ActiveViewport(This,pActView) ) 

#define IGcadDocument_get_ActivePViewport(This,pActView)	\
    ( (This)->lpVtbl -> get_ActivePViewport(This,pActView) ) 

#define IGcadDocument_put_ActivePViewport(This,pActView)	\
    ( (This)->lpVtbl -> put_ActivePViewport(This,pActView) ) 

#define IGcadDocument_get_ActiveSpace(This,ActSpace)	\
    ( (This)->lpVtbl -> get_ActiveSpace(This,ActSpace) ) 

#define IGcadDocument_put_ActiveSpace(This,ActSpace)	\
    ( (This)->lpVtbl -> put_ActiveSpace(This,ActSpace) ) 

#define IGcadDocument_get_SelectionSets(This,pSelSets)	\
    ( (This)->lpVtbl -> get_SelectionSets(This,pSelSets) ) 

#define IGcadDocument_get_ActiveSelectionSet(This,pSelSet)	\
    ( (This)->lpVtbl -> get_ActiveSelectionSet(This,pSelSet) ) 

#define IGcadDocument_get_FullName(This,FullName)	\
    ( (This)->lpVtbl -> get_FullName(This,FullName) ) 

#define IGcadDocument_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IGcadDocument_get_Path(This,Path)	\
    ( (This)->lpVtbl -> get_Path(This,Path) ) 

#define IGcadDocument_get_ObjectSnapMode(This,fSnapMode)	\
    ( (This)->lpVtbl -> get_ObjectSnapMode(This,fSnapMode) ) 

#define IGcadDocument_put_ObjectSnapMode(This,fSnapMode)	\
    ( (This)->lpVtbl -> put_ObjectSnapMode(This,fSnapMode) ) 

#define IGcadDocument_get_ReadOnly(This,bReadOnly)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,bReadOnly) ) 

#define IGcadDocument_get_Saved(This,bSaved)	\
    ( (This)->lpVtbl -> get_Saved(This,bSaved) ) 

#define IGcadDocument_get_MSpace(This,Mode)	\
    ( (This)->lpVtbl -> get_MSpace(This,Mode) ) 

#define IGcadDocument_put_MSpace(This,Mode)	\
    ( (This)->lpVtbl -> put_MSpace(This,Mode) ) 

#define IGcadDocument_get_Utility(This,pUtil)	\
    ( (This)->lpVtbl -> get_Utility(This,pUtil) ) 

#define IGcadDocument_Open(This,FullName,Password,pDocObj)	\
    ( (This)->lpVtbl -> Open(This,FullName,Password,pDocObj) ) 

#define IGcadDocument_AuditInfo(This,FixErr)	\
    ( (This)->lpVtbl -> AuditInfo(This,FixErr) ) 

#define IGcadDocument_Import(This,FileName,InsertionPoint,ScaleFactor,pObj)	\
    ( (This)->lpVtbl -> Import(This,FileName,InsertionPoint,ScaleFactor,pObj) ) 

#define IGcadDocument_Export(This,FileName,Extension,SelectionSet)	\
    ( (This)->lpVtbl -> Export(This,FileName,Extension,SelectionSet) ) 

#define IGcadDocument_New(This,TemplateFileName,pDocObj)	\
    ( (This)->lpVtbl -> New(This,TemplateFileName,pDocObj) ) 

#define IGcadDocument_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IGcadDocument_SaveAs(This,FullFileName,SaveAsType,vSecurityParams)	\
    ( (This)->lpVtbl -> SaveAs(This,FullFileName,SaveAsType,vSecurityParams) ) 

#define IGcadDocument_Wblock(This,FileName,SelectionSet)	\
    ( (This)->lpVtbl -> Wblock(This,FileName,SelectionSet) ) 

#define IGcadDocument_PurgeAll(This)	\
    ( (This)->lpVtbl -> PurgeAll(This) ) 

#define IGcadDocument_GetVariable(This,Name,Value)	\
    ( (This)->lpVtbl -> GetVariable(This,Name,Value) ) 

#define IGcadDocument_SetVariable(This,Name,Value)	\
    ( (This)->lpVtbl -> SetVariable(This,Name,Value) ) 

#define IGcadDocument_LoadShapeFile(This,FullName)	\
    ( (This)->lpVtbl -> LoadShapeFile(This,FullName) ) 

#define IGcadDocument_Regen(This,WhichViewports)	\
    ( (This)->lpVtbl -> Regen(This,WhichViewports) ) 

#define IGcadDocument_get_PickfirstSelectionSet(This,pSelSet)	\
    ( (This)->lpVtbl -> get_PickfirstSelectionSet(This,pSelSet) ) 

#define IGcadDocument_get_Active(This,pvbActive)	\
    ( (This)->lpVtbl -> get_Active(This,pvbActive) ) 

#define IGcadDocument_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define IGcadDocument_Close(This,SaveChanges,FileName)	\
    ( (This)->lpVtbl -> Close(This,SaveChanges,FileName) ) 

#define IGcadDocument_put_WindowState(This,pWinState)	\
    ( (This)->lpVtbl -> put_WindowState(This,pWinState) ) 

#define IGcadDocument_get_WindowState(This,pWinState)	\
    ( (This)->lpVtbl -> get_WindowState(This,pWinState) ) 

#define IGcadDocument_put_Width(This,pWidth)	\
    ( (This)->lpVtbl -> put_Width(This,pWidth) ) 

#define IGcadDocument_get_Width(This,pWidth)	\
    ( (This)->lpVtbl -> get_Width(This,pWidth) ) 

#define IGcadDocument_put_Height(This,pHeight)	\
    ( (This)->lpVtbl -> put_Height(This,pHeight) ) 

#define IGcadDocument_get_Height(This,pHeight)	\
    ( (This)->lpVtbl -> get_Height(This,pHeight) ) 

#define IGcadDocument_put_ActiveLayout(This,pLayout)	\
    ( (This)->lpVtbl -> put_ActiveLayout(This,pLayout) ) 

#define IGcadDocument_get_ActiveLayout(This,pLayout)	\
    ( (This)->lpVtbl -> get_ActiveLayout(This,pLayout) ) 

#define IGcadDocument_SendCommand(This,Command)	\
    ( (This)->lpVtbl -> SendCommand(This,Command) ) 

#define IGcadDocument_get_HWND(This,HWND)	\
    ( (This)->lpVtbl -> get_HWND(This,HWND) ) 

#define IGcadDocument_get_WindowTitle(This,Title)	\
    ( (This)->lpVtbl -> get_WindowTitle(This,Title) ) 

#define IGcadDocument_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadDocument_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadDocument_StartUndoMark(This)	\
    ( (This)->lpVtbl -> StartUndoMark(This) ) 

#define IGcadDocument_EndUndoMark(This)	\
    ( (This)->lpVtbl -> EndUndoMark(This) ) 

#define IGcadDocument_get_ActiveMaterial(This,pActMaterial)	\
    ( (This)->lpVtbl -> get_ActiveMaterial(This,pActMaterial) ) 

#define IGcadDocument_put_ActiveMaterial(This,pActMaterial)	\
    ( (This)->lpVtbl -> put_ActiveMaterial(This,pActMaterial) ) 

#define IGcadDocument_InitDoc(This,pDoc)	\
    ( (This)->lpVtbl -> InitDoc(This,pDoc) ) 

#define IGcadDocument_BindDatabase(This,pDb)	\
    ( (This)->lpVtbl -> BindDatabase(This,pDb) ) 

#define IGcadDocument_get_HWND32(This,HWND)	\
    ( (This)->lpVtbl -> get_HWND32(This,HWND) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadDocument_INTERFACE_DEFINED__ */


#ifndef __IGcadDynamicBlockReferenceProperty_INTERFACE_DEFINED__
#define __IGcadDynamicBlockReferenceProperty_INTERFACE_DEFINED__

/* interface IGcadDynamicBlockReferenceProperty */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadDynamicBlockReferenceProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("017EAE27-EA30-4151-8272-BA072063C218")
    IGcadDynamicBlockReferenceProperty : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PropertyName( 
            /* [retval][out] */ BSTR *PropertyName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *ReadOnly) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Show( 
            /* [retval][out] */ VARIANT_BOOL *Show) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *Description) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AllowedValues( 
            /* [retval][out] */ VARIANT *AllowedValues) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *Value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UnitsType( 
            /* [retval][out] */ GcDynamicBlockReferencePropertyUnitsType *Units) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadDynamicBlockReferencePropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadDynamicBlockReferenceProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadDynamicBlockReferenceProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PropertyName )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ BSTR *PropertyName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ReadOnly )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ VARIANT_BOOL *ReadOnly);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Show )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ VARIANT_BOOL *Show);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ BSTR *Description);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AllowedValues )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ VARIANT *AllowedValues);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ VARIANT *Value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UnitsType )( 
            IGcadDynamicBlockReferenceProperty * This,
            /* [retval][out] */ GcDynamicBlockReferencePropertyUnitsType *Units);
        
        END_INTERFACE
    } IGcadDynamicBlockReferencePropertyVtbl;

    interface IGcadDynamicBlockReferenceProperty
    {
        CONST_VTBL struct IGcadDynamicBlockReferencePropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadDynamicBlockReferenceProperty_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadDynamicBlockReferenceProperty_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadDynamicBlockReferenceProperty_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadDynamicBlockReferenceProperty_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadDynamicBlockReferenceProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadDynamicBlockReferenceProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadDynamicBlockReferenceProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadDynamicBlockReferenceProperty_get_PropertyName(This,PropertyName)	\
    ( (This)->lpVtbl -> get_PropertyName(This,PropertyName) ) 

#define IGcadDynamicBlockReferenceProperty_get_ReadOnly(This,ReadOnly)	\
    ( (This)->lpVtbl -> get_ReadOnly(This,ReadOnly) ) 

#define IGcadDynamicBlockReferenceProperty_get_Show(This,Show)	\
    ( (This)->lpVtbl -> get_Show(This,Show) ) 

#define IGcadDynamicBlockReferenceProperty_get_Description(This,Description)	\
    ( (This)->lpVtbl -> get_Description(This,Description) ) 

#define IGcadDynamicBlockReferenceProperty_get_AllowedValues(This,AllowedValues)	\
    ( (This)->lpVtbl -> get_AllowedValues(This,AllowedValues) ) 

#define IGcadDynamicBlockReferenceProperty_get_Value(This,Value)	\
    ( (This)->lpVtbl -> get_Value(This,Value) ) 

#define IGcadDynamicBlockReferenceProperty_put_Value(This,Value)	\
    ( (This)->lpVtbl -> put_Value(This,Value) ) 

#define IGcadDynamicBlockReferenceProperty_get_UnitsType(This,Units)	\
    ( (This)->lpVtbl -> get_UnitsType(This,Units) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadDynamicBlockReferenceProperty_INTERFACE_DEFINED__ */


#ifndef __IGcadSortentsTable_INTERFACE_DEFINED__
#define __IGcadSortentsTable_INTERFACE_DEFINED__

/* interface IGcadSortentsTable */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadSortentsTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEDB84CD-55C2-4F73-B534-7F06EBF8919F")
    IGcadSortentsTable : public IGcadObject
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToBottom( 
            /* [in] */ VARIANT Objects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToTop( 
            /* [in] */ VARIANT Objects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveBelow( 
            /* [in] */ VARIANT Objects,
            /* [in] */ IGcadEntity *Target) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveAbove( 
            /* [in] */ VARIANT Objects,
            /* [in] */ IGcadEntity *Target) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapOrder( 
            /* [in] */ IGcadEntity *Object1,
            /* [in] */ IGcadEntity *Object2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Block( 
            /* [retval][out] */ IGcadBlock **pBlock) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFullDrawOrder( 
            /* [out] */ VARIANT *Objects,
            /* [in] */ VARIANT_BOOL honorSortentsSysvar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRelativeDrawOrder( 
            /* [out] */ VARIANT *Objects,
            /* [in] */ VARIANT_BOOL honorSortentsSysvar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRelativeDrawOrder( 
            /* [in] */ VARIANT Objects) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSortentsTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSortentsTable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSortentsTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSortentsTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSortentsTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSortentsTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSortentsTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSortentsTable * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadSortentsTable * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadSortentsTable * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadSortentsTable * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToBottom )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT Objects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToTop )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT Objects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveBelow )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT Objects,
            /* [in] */ IGcadEntity *Target);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveAbove )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT Objects,
            /* [in] */ IGcadEntity *Target);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapOrder )( 
            IGcadSortentsTable * This,
            /* [in] */ IGcadEntity *Object1,
            /* [in] */ IGcadEntity *Object2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Block )( 
            IGcadSortentsTable * This,
            /* [retval][out] */ IGcadBlock **pBlock);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFullDrawOrder )( 
            IGcadSortentsTable * This,
            /* [out] */ VARIANT *Objects,
            /* [in] */ VARIANT_BOOL honorSortentsSysvar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRelativeDrawOrder )( 
            IGcadSortentsTable * This,
            /* [out] */ VARIANT *Objects,
            /* [in] */ VARIANT_BOOL honorSortentsSysvar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRelativeDrawOrder )( 
            IGcadSortentsTable * This,
            /* [in] */ VARIANT Objects);
        
        END_INTERFACE
    } IGcadSortentsTableVtbl;

    interface IGcadSortentsTable
    {
        CONST_VTBL struct IGcadSortentsTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSortentsTable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSortentsTable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSortentsTable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSortentsTable_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSortentsTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSortentsTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSortentsTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSortentsTable_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadSortentsTable_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadSortentsTable_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadSortentsTable_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadSortentsTable_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadSortentsTable_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadSortentsTable_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadSortentsTable_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadSortentsTable_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadSortentsTable_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadSortentsTable_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadSortentsTable_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadSortentsTable_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadSortentsTable_MoveToBottom(This,Objects)	\
    ( (This)->lpVtbl -> MoveToBottom(This,Objects) ) 

#define IGcadSortentsTable_MoveToTop(This,Objects)	\
    ( (This)->lpVtbl -> MoveToTop(This,Objects) ) 

#define IGcadSortentsTable_MoveBelow(This,Objects,Target)	\
    ( (This)->lpVtbl -> MoveBelow(This,Objects,Target) ) 

#define IGcadSortentsTable_MoveAbove(This,Objects,Target)	\
    ( (This)->lpVtbl -> MoveAbove(This,Objects,Target) ) 

#define IGcadSortentsTable_SwapOrder(This,Object1,Object2)	\
    ( (This)->lpVtbl -> SwapOrder(This,Object1,Object2) ) 

#define IGcadSortentsTable_Block(This,pBlock)	\
    ( (This)->lpVtbl -> Block(This,pBlock) ) 

#define IGcadSortentsTable_GetFullDrawOrder(This,Objects,honorSortentsSysvar)	\
    ( (This)->lpVtbl -> GetFullDrawOrder(This,Objects,honorSortentsSysvar) ) 

#define IGcadSortentsTable_GetRelativeDrawOrder(This,Objects,honorSortentsSysvar)	\
    ( (This)->lpVtbl -> GetRelativeDrawOrder(This,Objects,honorSortentsSysvar) ) 

#define IGcadSortentsTable_SetRelativeDrawOrder(This,Objects)	\
    ( (This)->lpVtbl -> SetRelativeDrawOrder(This,Objects) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSortentsTable_INTERFACE_DEFINED__ */


#ifndef __IGcadIdPair_INTERFACE_DEFINED__
#define __IGcadIdPair_INTERFACE_DEFINED__

/* interface IGcadIdPair */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadIdPair;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1D3AF325-66DF-4CF6-B19F-1DCF053D75F9")
    IGcadIdPair : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsCloned( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsOwnerXlated( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IsPrimary( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_key( 
            /* [retval][out] */ LONG_PTR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ LONG_PTR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IDispatch **ApplicationObject) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Key32( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value32( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadIdPairVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadIdPair * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadIdPair * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadIdPair * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadIdPair * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadIdPair * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadIdPair * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadIdPair * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsCloned )( 
            IGcadIdPair * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsOwnerXlated )( 
            IGcadIdPair * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsPrimary )( 
            IGcadIdPair * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_key )( 
            IGcadIdPair * This,
            /* [retval][out] */ LONG_PTR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IGcadIdPair * This,
            /* [retval][out] */ LONG_PTR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadIdPair * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Key32 )( 
            IGcadIdPair * This,
            /* [retval][out] */ long *pVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value32 )( 
            IGcadIdPair * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IGcadIdPairVtbl;

    interface IGcadIdPair
    {
        CONST_VTBL struct IGcadIdPairVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadIdPair_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadIdPair_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadIdPair_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadIdPair_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadIdPair_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadIdPair_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadIdPair_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadIdPair_get_IsCloned(This,pVal)	\
    ( (This)->lpVtbl -> get_IsCloned(This,pVal) ) 

#define IGcadIdPair_get_IsOwnerXlated(This,pVal)	\
    ( (This)->lpVtbl -> get_IsOwnerXlated(This,pVal) ) 

#define IGcadIdPair_get_IsPrimary(This,pVal)	\
    ( (This)->lpVtbl -> get_IsPrimary(This,pVal) ) 

#define IGcadIdPair_get_key(This,pVal)	\
    ( (This)->lpVtbl -> get_key(This,pVal) ) 

#define IGcadIdPair_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IGcadIdPair_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadIdPair_get_Key32(This,pVal)	\
    ( (This)->lpVtbl -> get_Key32(This,pVal) ) 

#define IGcadIdPair_get_Value32(This,pVal)	\
    ( (This)->lpVtbl -> get_Value32(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadIdPair_INTERFACE_DEFINED__ */


#ifndef __IGcadTableStyle_INTERFACE_DEFINED__
#define __IGcadTableStyle_INTERFACE_DEFINED__

/* interface IGcadTableStyle */
/* [unique][oleautomation][dual][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadTableStyle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4EC5CAC3-22E8-4B42-BBA8-77271650DEA4")
    IGcadTableStyle : public IGcadObject
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrValue) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrValue) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *bstr) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BitFlags( 
            /* [retval][out] */ long *bitFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BitFlags( 
            /* [in] */ long bitFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FlowDirection( 
            /* [retval][out] */ GcTableDirection *pFlow) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FlowDirection( 
            /* [in] */ GcTableDirection pFlow) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HorzCellMargin( 
            /* [retval][out] */ double *dHorzCellMargin) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HorzCellMargin( 
            /* [in] */ double dHorzCellMargin) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_VertCellMargin( 
            /* [retval][out] */ double *dVertCellMargin) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_VertCellMargin( 
            /* [in] */ double dVertCellMargin) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TitleSuppressed( 
            /* [retval][out] */ VARIANT_BOOL *bValue) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TitleSuppressed( 
            /* [in] */ VARIANT_BOOL bValue) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HeaderSuppressed( 
            /* [retval][out] */ VARIANT_BOOL *bValue) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HeaderSuppressed( 
            /* [in] */ VARIANT_BOOL bValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTextStyle( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTextStyle( 
            /* [in] */ int rowTypes,
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTextHeight( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ double *pTextHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTextHeight( 
            /* [in] */ int rowTypes,
            /* [in] */ double TextHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAlignment( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ GcCellAlignment *pCellAlignment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAlignment( 
            /* [in] */ int rowTypes,
            /* [in] */ GcCellAlignment cellAlignment) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetColor( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetColor( 
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBackgroundColor( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBackgroundColor( 
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBackgroundColorNone( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ VARIANT_BOOL *bValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBackgroundColorNone( 
            /* [in] */ int rowTypes,
            /* [in] */ VARIANT_BOOL *bValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGridLineWeight( 
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGridLineWeight( 
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ GCAD_LWEIGHT Lineweight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGridColor( 
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGridColor( 
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGridVisibility( 
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ VARIANT_BOOL *bValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetGridVisibility( 
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ VARIANT_BOOL bValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDataType( 
            /* [in] */ GcRowType rowType,
            /* [out] */ GcValueDataType *pDataType,
            /* [out] */ GcValueUnitType *pUnitType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDataType( 
            /* [in] */ int rowTypes,
            /* [in] */ GcValueDataType nDataType,
            /* [in] */ GcValueUnitType nUnitType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFormat( 
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFormat( 
            /* [in] */ int rowTypes,
            /* [in] */ BSTR val) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTextStyleId32( 
            /* [in] */ BSTR bstrCellStyle,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetTextStyleId32( 
            /* [in] */ BSTR bstrCellStyle,
            /* [in] */ long val) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TemplateId32( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_TemplateId32( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetTemplateId32( 
            /* [in] */ long val,
            GcMergeCellStyleOption option) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadTableStyleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadTableStyle * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadTableStyle * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadTableStyle * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadTableStyle * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadTableStyle * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadTableStyle * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadTableStyle * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Handle )( 
            IGcadTableStyle * This,
            /* [retval][out] */ BSTR *Handle);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectName )( 
            IGcadTableStyle * This,
            /* [retval][out] */ BSTR *ObjectName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXData )( 
            IGcadTableStyle * This,
            /* [in] */ BSTR AppName,
            /* [out] */ VARIANT *XDataType,
            /* [out] */ VARIANT *XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXData )( 
            IGcadTableStyle * This,
            /* [in] */ VARIANT XDataType,
            /* [in] */ VARIANT XDataValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadTableStyle * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectID )( 
            IGcadTableStyle * This,
            /* [retval][out] */ LONG_PTR *ObjectID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadTableStyle * This,
            /* [retval][out] */ IDispatch **ApplicationObject);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IGcadTableStyle * This,
            /* [retval][out] */ IGcadDatabase **pDatabase);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HasExtensionDictionary )( 
            IGcadTableStyle * This,
            /* [retval][out] */ VARIANT_BOOL *bHasDictionary);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtensionDictionary )( 
            IGcadTableStyle * This,
            /* [retval][out] */ IGcadDictionary **pExtDictionary);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OwnerID )( 
            IGcadTableStyle * This,
            /* [retval][out] */ LONG_PTR *OwnerID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Document )( 
            IGcadTableStyle * This,
            /* [retval][out] */ IDispatch **pDocument);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Erase )( 
            IGcadTableStyle * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadTableStyle * This,
            /* [retval][out] */ BSTR *bstrValue);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadTableStyle * This,
            /* [in] */ BSTR bstrValue);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IGcadTableStyle * This,
            /* [retval][out] */ BSTR *bstr);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IGcadTableStyle * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BitFlags )( 
            IGcadTableStyle * This,
            /* [retval][out] */ long *bitFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BitFlags )( 
            IGcadTableStyle * This,
            /* [in] */ long bitFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FlowDirection )( 
            IGcadTableStyle * This,
            /* [retval][out] */ GcTableDirection *pFlow);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FlowDirection )( 
            IGcadTableStyle * This,
            /* [in] */ GcTableDirection pFlow);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HorzCellMargin )( 
            IGcadTableStyle * This,
            /* [retval][out] */ double *dHorzCellMargin);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HorzCellMargin )( 
            IGcadTableStyle * This,
            /* [in] */ double dHorzCellMargin);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_VertCellMargin )( 
            IGcadTableStyle * This,
            /* [retval][out] */ double *dVertCellMargin);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_VertCellMargin )( 
            IGcadTableStyle * This,
            /* [in] */ double dVertCellMargin);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TitleSuppressed )( 
            IGcadTableStyle * This,
            /* [retval][out] */ VARIANT_BOOL *bValue);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TitleSuppressed )( 
            IGcadTableStyle * This,
            /* [in] */ VARIANT_BOOL bValue);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderSuppressed )( 
            IGcadTableStyle * This,
            /* [retval][out] */ VARIANT_BOOL *bValue);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderSuppressed )( 
            IGcadTableStyle * This,
            /* [in] */ VARIANT_BOOL bValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTextStyle )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTextStyle )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTextHeight )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ double *pTextHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTextHeight )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ double TextHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAlignment )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ GcCellAlignment *pCellAlignment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAlignment )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ GcCellAlignment cellAlignment);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetColor )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetColor )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBackgroundColor )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBackgroundColor )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBackgroundColorNone )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ VARIANT_BOOL *bValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBackgroundColorNone )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ VARIANT_BOOL *bValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGridLineWeight )( 
            IGcadTableStyle * This,
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ GCAD_LWEIGHT *Lineweight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGridLineWeight )( 
            IGcadTableStyle * This,
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ GCAD_LWEIGHT Lineweight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGridColor )( 
            IGcadTableStyle * This,
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ IGcadGcCmColor **pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGridColor )( 
            IGcadTableStyle * This,
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ IGcadGcCmColor *pColor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGridVisibility )( 
            IGcadTableStyle * This,
            /* [in] */ GcGridLineType gridLineType,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ VARIANT_BOOL *bValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetGridVisibility )( 
            IGcadTableStyle * This,
            /* [in] */ int gridLineTypes,
            /* [in] */ int rowTypes,
            /* [in] */ VARIANT_BOOL bValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDataType )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [out] */ GcValueDataType *pDataType,
            /* [out] */ GcValueUnitType *pUnitType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDataType )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ GcValueDataType nDataType,
            /* [in] */ GcValueUnitType nUnitType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFormat )( 
            IGcadTableStyle * This,
            /* [in] */ GcRowType rowType,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFormat )( 
            IGcadTableStyle * This,
            /* [in] */ int rowTypes,
            /* [in] */ BSTR val);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTextStyleId32 )( 
            IGcadTableStyle * This,
            /* [in] */ BSTR bstrCellStyle,
            /* [retval][out] */ long *pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetTextStyleId32 )( 
            IGcadTableStyle * This,
            /* [in] */ BSTR bstrCellStyle,
            /* [in] */ long val);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TemplateId32 )( 
            IGcadTableStyle * This,
            /* [retval][out] */ long *pVal);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TemplateId32 )( 
            IGcadTableStyle * This,
            /* [in] */ long pVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetTemplateId32 )( 
            IGcadTableStyle * This,
            /* [in] */ long val,
            GcMergeCellStyleOption option);
        
        END_INTERFACE
    } IGcadTableStyleVtbl;

    interface IGcadTableStyle
    {
        CONST_VTBL struct IGcadTableStyleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadTableStyle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadTableStyle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadTableStyle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadTableStyle_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadTableStyle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadTableStyle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadTableStyle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadTableStyle_get_Handle(This,Handle)	\
    ( (This)->lpVtbl -> get_Handle(This,Handle) ) 

#define IGcadTableStyle_get_ObjectName(This,ObjectName)	\
    ( (This)->lpVtbl -> get_ObjectName(This,ObjectName) ) 

#define IGcadTableStyle_GetXData(This,AppName,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> GetXData(This,AppName,XDataType,XDataValue) ) 

#define IGcadTableStyle_SetXData(This,XDataType,XDataValue)	\
    ( (This)->lpVtbl -> SetXData(This,XDataType,XDataValue) ) 

#define IGcadTableStyle_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadTableStyle_get_ObjectID(This,ObjectID)	\
    ( (This)->lpVtbl -> get_ObjectID(This,ObjectID) ) 

#define IGcadTableStyle_get_Application(This,ApplicationObject)	\
    ( (This)->lpVtbl -> get_Application(This,ApplicationObject) ) 

#define IGcadTableStyle_get_Database(This,pDatabase)	\
    ( (This)->lpVtbl -> get_Database(This,pDatabase) ) 

#define IGcadTableStyle_get_HasExtensionDictionary(This,bHasDictionary)	\
    ( (This)->lpVtbl -> get_HasExtensionDictionary(This,bHasDictionary) ) 

#define IGcadTableStyle_GetExtensionDictionary(This,pExtDictionary)	\
    ( (This)->lpVtbl -> GetExtensionDictionary(This,pExtDictionary) ) 

#define IGcadTableStyle_get_OwnerID(This,OwnerID)	\
    ( (This)->lpVtbl -> get_OwnerID(This,OwnerID) ) 

#define IGcadTableStyle_get_Document(This,pDocument)	\
    ( (This)->lpVtbl -> get_Document(This,pDocument) ) 

#define IGcadTableStyle_Erase(This)	\
    ( (This)->lpVtbl -> Erase(This) ) 


#define IGcadTableStyle_get_Name(This,bstrValue)	\
    ( (This)->lpVtbl -> get_Name(This,bstrValue) ) 

#define IGcadTableStyle_put_Name(This,bstrValue)	\
    ( (This)->lpVtbl -> put_Name(This,bstrValue) ) 

#define IGcadTableStyle_get_Description(This,bstr)	\
    ( (This)->lpVtbl -> get_Description(This,bstr) ) 

#define IGcadTableStyle_put_Description(This,bstr)	\
    ( (This)->lpVtbl -> put_Description(This,bstr) ) 

#define IGcadTableStyle_get_BitFlags(This,bitFlag)	\
    ( (This)->lpVtbl -> get_BitFlags(This,bitFlag) ) 

#define IGcadTableStyle_put_BitFlags(This,bitFlag)	\
    ( (This)->lpVtbl -> put_BitFlags(This,bitFlag) ) 

#define IGcadTableStyle_get_FlowDirection(This,pFlow)	\
    ( (This)->lpVtbl -> get_FlowDirection(This,pFlow) ) 

#define IGcadTableStyle_put_FlowDirection(This,pFlow)	\
    ( (This)->lpVtbl -> put_FlowDirection(This,pFlow) ) 

#define IGcadTableStyle_get_HorzCellMargin(This,dHorzCellMargin)	\
    ( (This)->lpVtbl -> get_HorzCellMargin(This,dHorzCellMargin) ) 

#define IGcadTableStyle_put_HorzCellMargin(This,dHorzCellMargin)	\
    ( (This)->lpVtbl -> put_HorzCellMargin(This,dHorzCellMargin) ) 

#define IGcadTableStyle_get_VertCellMargin(This,dVertCellMargin)	\
    ( (This)->lpVtbl -> get_VertCellMargin(This,dVertCellMargin) ) 

#define IGcadTableStyle_put_VertCellMargin(This,dVertCellMargin)	\
    ( (This)->lpVtbl -> put_VertCellMargin(This,dVertCellMargin) ) 

#define IGcadTableStyle_get_TitleSuppressed(This,bValue)	\
    ( (This)->lpVtbl -> get_TitleSuppressed(This,bValue) ) 

#define IGcadTableStyle_put_TitleSuppressed(This,bValue)	\
    ( (This)->lpVtbl -> put_TitleSuppressed(This,bValue) ) 

#define IGcadTableStyle_get_HeaderSuppressed(This,bValue)	\
    ( (This)->lpVtbl -> get_HeaderSuppressed(This,bValue) ) 

#define IGcadTableStyle_put_HeaderSuppressed(This,bValue)	\
    ( (This)->lpVtbl -> put_HeaderSuppressed(This,bValue) ) 

#define IGcadTableStyle_GetTextStyle(This,rowType,bstrName)	\
    ( (This)->lpVtbl -> GetTextStyle(This,rowType,bstrName) ) 

#define IGcadTableStyle_SetTextStyle(This,rowTypes,bstrName)	\
    ( (This)->lpVtbl -> SetTextStyle(This,rowTypes,bstrName) ) 

#define IGcadTableStyle_GetTextHeight(This,rowType,pTextHeight)	\
    ( (This)->lpVtbl -> GetTextHeight(This,rowType,pTextHeight) ) 

#define IGcadTableStyle_SetTextHeight(This,rowTypes,TextHeight)	\
    ( (This)->lpVtbl -> SetTextHeight(This,rowTypes,TextHeight) ) 

#define IGcadTableStyle_GetAlignment(This,rowType,pCellAlignment)	\
    ( (This)->lpVtbl -> GetAlignment(This,rowType,pCellAlignment) ) 

#define IGcadTableStyle_SetAlignment(This,rowTypes,cellAlignment)	\
    ( (This)->lpVtbl -> SetAlignment(This,rowTypes,cellAlignment) ) 

#define IGcadTableStyle_GetColor(This,rowType,pColor)	\
    ( (This)->lpVtbl -> GetColor(This,rowType,pColor) ) 

#define IGcadTableStyle_SetColor(This,rowTypes,pColor)	\
    ( (This)->lpVtbl -> SetColor(This,rowTypes,pColor) ) 

#define IGcadTableStyle_GetBackgroundColor(This,rowType,pColor)	\
    ( (This)->lpVtbl -> GetBackgroundColor(This,rowType,pColor) ) 

#define IGcadTableStyle_SetBackgroundColor(This,rowTypes,pColor)	\
    ( (This)->lpVtbl -> SetBackgroundColor(This,rowTypes,pColor) ) 

#define IGcadTableStyle_GetBackgroundColorNone(This,rowType,bValue)	\
    ( (This)->lpVtbl -> GetBackgroundColorNone(This,rowType,bValue) ) 

#define IGcadTableStyle_SetBackgroundColorNone(This,rowTypes,bValue)	\
    ( (This)->lpVtbl -> SetBackgroundColorNone(This,rowTypes,bValue) ) 

#define IGcadTableStyle_GetGridLineWeight(This,gridLineType,rowType,Lineweight)	\
    ( (This)->lpVtbl -> GetGridLineWeight(This,gridLineType,rowType,Lineweight) ) 

#define IGcadTableStyle_SetGridLineWeight(This,gridLineTypes,rowTypes,Lineweight)	\
    ( (This)->lpVtbl -> SetGridLineWeight(This,gridLineTypes,rowTypes,Lineweight) ) 

#define IGcadTableStyle_GetGridColor(This,gridLineType,rowType,pColor)	\
    ( (This)->lpVtbl -> GetGridColor(This,gridLineType,rowType,pColor) ) 

#define IGcadTableStyle_SetGridColor(This,gridLineTypes,rowTypes,pColor)	\
    ( (This)->lpVtbl -> SetGridColor(This,gridLineTypes,rowTypes,pColor) ) 

#define IGcadTableStyle_GetGridVisibility(This,gridLineType,rowType,bValue)	\
    ( (This)->lpVtbl -> GetGridVisibility(This,gridLineType,rowType,bValue) ) 

#define IGcadTableStyle_SetGridVisibility(This,gridLineTypes,rowTypes,bValue)	\
    ( (This)->lpVtbl -> SetGridVisibility(This,gridLineTypes,rowTypes,bValue) ) 

#define IGcadTableStyle_GetDataType(This,rowType,pDataType,pUnitType)	\
    ( (This)->lpVtbl -> GetDataType(This,rowType,pDataType,pUnitType) ) 

#define IGcadTableStyle_SetDataType(This,rowTypes,nDataType,nUnitType)	\
    ( (This)->lpVtbl -> SetDataType(This,rowTypes,nDataType,nUnitType) ) 

#define IGcadTableStyle_GetFormat(This,rowType,pVal)	\
    ( (This)->lpVtbl -> GetFormat(This,rowType,pVal) ) 

#define IGcadTableStyle_SetFormat(This,rowTypes,val)	\
    ( (This)->lpVtbl -> SetFormat(This,rowTypes,val) ) 

#define IGcadTableStyle_GetTextStyleId32(This,bstrCellStyle,pVal)	\
    ( (This)->lpVtbl -> GetTextStyleId32(This,bstrCellStyle,pVal) ) 

#define IGcadTableStyle_SetTextStyleId32(This,bstrCellStyle,val)	\
    ( (This)->lpVtbl -> SetTextStyleId32(This,bstrCellStyle,val) ) 

#define IGcadTableStyle_get_TemplateId32(This,pVal)	\
    ( (This)->lpVtbl -> get_TemplateId32(This,pVal) ) 

#define IGcadTableStyle_put_TemplateId32(This,pVal)	\
    ( (This)->lpVtbl -> put_TemplateId32(This,pVal) ) 

#define IGcadTableStyle_SetTemplateId32(This,val,option)	\
    ( (This)->lpVtbl -> SetTemplateId32(This,val,option) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadTableStyle_INTERFACE_DEFINED__ */


#ifndef __IGcadShadowDisplay_INTERFACE_DEFINED__
#define __IGcadShadowDisplay_INTERFACE_DEFINED__

/* interface IGcadShadowDisplay */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IGcadShadowDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0552FF7C-E7C5-4890-984F-FD499B4B566F")
    IGcadShadowDisplay : public IUnknown
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShadowDisplay( 
            /* [retval][out] */ GcShadowDisplayType *ShadowDisplay) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShadowDisplay( 
            /* [in] */ GcShadowDisplayType ShadowDisplay) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableShadowDisplay( 
            /* [retval][out] */ BOOL *ShadowDisplay) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadShadowDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadShadowDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadShadowDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadShadowDisplay * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShadowDisplay )( 
            IGcadShadowDisplay * This,
            /* [retval][out] */ GcShadowDisplayType *ShadowDisplay);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShadowDisplay )( 
            IGcadShadowDisplay * This,
            /* [in] */ GcShadowDisplayType ShadowDisplay);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableShadowDisplay )( 
            IGcadShadowDisplay * This,
            /* [retval][out] */ BOOL *ShadowDisplay);
        
        END_INTERFACE
    } IGcadShadowDisplayVtbl;

    interface IGcadShadowDisplay
    {
        CONST_VTBL struct IGcadShadowDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadShadowDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadShadowDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadShadowDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadShadowDisplay_get_ShadowDisplay(This,ShadowDisplay)	\
    ( (This)->lpVtbl -> get_ShadowDisplay(This,ShadowDisplay) ) 

#define IGcadShadowDisplay_put_ShadowDisplay(This,ShadowDisplay)	\
    ( (This)->lpVtbl -> put_ShadowDisplay(This,ShadowDisplay) ) 

#define IGcadShadowDisplay_get_EnableShadowDisplay(This,ShadowDisplay)	\
    ( (This)->lpVtbl -> get_EnableShadowDisplay(This,ShadowDisplay) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadShadowDisplay_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesProfiles_INTERFACE_DEFINED__
#define __IGcadPreferencesProfiles_INTERFACE_DEFINED__

/* interface IGcadPreferencesProfiles */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesProfiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("807758BB-F12D-4275-A52F-6A2CFCAD9A21")
    IGcadPreferencesProfiles : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveProfile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveProfile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportProfile( 
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile,
            /* [in] */ VARIANT_BOOL IncludePathInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExportProfile( 
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteProfile( 
            /* [in] */ BSTR ProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetProfile( 
            /* [in] */ BSTR Profile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RenameProfile( 
            /* [in] */ BSTR origProfileName,
            /* [in] */ BSTR newProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyProfile( 
            /* [in] */ BSTR oldProfileName,
            /* [in] */ BSTR newProfileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllProfileNames( 
            /* [out] */ VARIANT *pNames) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesProfilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesProfiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesProfiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesProfiles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesProfiles * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesProfiles * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveProfile )( 
            IGcadPreferencesProfiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile,
            /* [in] */ VARIANT_BOOL IncludePathInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExportProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName,
            /* [in] */ BSTR RegFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR ProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR Profile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RenameProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR origProfileName,
            /* [in] */ BSTR newProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyProfile )( 
            IGcadPreferencesProfiles * This,
            /* [in] */ BSTR oldProfileName,
            /* [in] */ BSTR newProfileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllProfileNames )( 
            IGcadPreferencesProfiles * This,
            /* [out] */ VARIANT *pNames);
        
        END_INTERFACE
    } IGcadPreferencesProfilesVtbl;

    interface IGcadPreferencesProfiles
    {
        CONST_VTBL struct IGcadPreferencesProfilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesProfiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesProfiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesProfiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesProfiles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesProfiles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesProfiles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesProfiles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesProfiles_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesProfiles_put_ActiveProfile(This,Path)	\
    ( (This)->lpVtbl -> put_ActiveProfile(This,Path) ) 

#define IGcadPreferencesProfiles_get_ActiveProfile(This,Path)	\
    ( (This)->lpVtbl -> get_ActiveProfile(This,Path) ) 

#define IGcadPreferencesProfiles_ImportProfile(This,ProfileName,RegFile,IncludePathInfo)	\
    ( (This)->lpVtbl -> ImportProfile(This,ProfileName,RegFile,IncludePathInfo) ) 

#define IGcadPreferencesProfiles_ExportProfile(This,ProfileName,RegFile)	\
    ( (This)->lpVtbl -> ExportProfile(This,ProfileName,RegFile) ) 

#define IGcadPreferencesProfiles_DeleteProfile(This,ProfileName)	\
    ( (This)->lpVtbl -> DeleteProfile(This,ProfileName) ) 

#define IGcadPreferencesProfiles_ResetProfile(This,Profile)	\
    ( (This)->lpVtbl -> ResetProfile(This,Profile) ) 

#define IGcadPreferencesProfiles_RenameProfile(This,origProfileName,newProfileName)	\
    ( (This)->lpVtbl -> RenameProfile(This,origProfileName,newProfileName) ) 

#define IGcadPreferencesProfiles_CopyProfile(This,oldProfileName,newProfileName)	\
    ( (This)->lpVtbl -> CopyProfile(This,oldProfileName,newProfileName) ) 

#define IGcadPreferencesProfiles_GetAllProfileNames(This,pNames)	\
    ( (This)->lpVtbl -> GetAllProfileNames(This,pNames) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesProfiles_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferences_INTERFACE_DEFINED__
#define __IGcadPreferences_INTERFACE_DEFINED__

/* interface IGcadPreferences */
/* [unique][oleautomation][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadPreferences;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("253889D2-ABBB-4DB6-AB75-00DCACCB59A5")
    IGcadPreferences : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Files( 
            /* [retval][out] */ IGcadPreferencesFiles **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Display( 
            /* [retval][out] */ IGcadPreferencesDisplay **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OpenSave( 
            /* [retval][out] */ IGcadPreferencesOpenSave **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Output( 
            /* [retval][out] */ IGcadPreferencesOutput **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_System( 
            /* [retval][out] */ IGcadPreferencesSystem **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [retval][out] */ IGcadPreferencesUser **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Drafting( 
            /* [retval][out] */ IGcadPreferencesDrafting **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ IGcadPreferencesSelection **pObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Profiles( 
            /* [retval][out] */ IGcadPreferencesProfiles **pObj) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferences * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferences * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferences * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferences * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferences * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferences * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferences * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Files )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesFiles **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Display )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesDisplay **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OpenSave )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesOpenSave **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Output )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesOutput **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_System )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesSystem **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_User )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesUser **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Drafting )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesDrafting **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesSelection **pObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Profiles )( 
            IGcadPreferences * This,
            /* [retval][out] */ IGcadPreferencesProfiles **pObj);
        
        END_INTERFACE
    } IGcadPreferencesVtbl;

    interface IGcadPreferences
    {
        CONST_VTBL struct IGcadPreferencesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferences_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferences_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferences_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferences_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferences_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferences_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferences_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferences_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferences_get_Files(This,pObj)	\
    ( (This)->lpVtbl -> get_Files(This,pObj) ) 

#define IGcadPreferences_get_Display(This,pObj)	\
    ( (This)->lpVtbl -> get_Display(This,pObj) ) 

#define IGcadPreferences_get_OpenSave(This,pObj)	\
    ( (This)->lpVtbl -> get_OpenSave(This,pObj) ) 

#define IGcadPreferences_get_Output(This,pObj)	\
    ( (This)->lpVtbl -> get_Output(This,pObj) ) 

#define IGcadPreferences_get_System(This,pObj)	\
    ( (This)->lpVtbl -> get_System(This,pObj) ) 

#define IGcadPreferences_get_User(This,pObj)	\
    ( (This)->lpVtbl -> get_User(This,pObj) ) 

#define IGcadPreferences_get_Drafting(This,pObj)	\
    ( (This)->lpVtbl -> get_Drafting(This,pObj) ) 

#define IGcadPreferences_get_Selection(This,pObj)	\
    ( (This)->lpVtbl -> get_Selection(This,pObj) ) 

#define IGcadPreferences_get_Profiles(This,pObj)	\
    ( (This)->lpVtbl -> get_Profiles(This,pObj) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferences_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesDrafting_INTERFACE_DEFINED__
#define __IGcadPreferencesDrafting_INTERFACE_DEFINED__

/* interface IGcadPreferencesDrafting */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesDrafting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4A0A141-99BD-44B8-9A4F-5B813BE85A68")
    IGcadPreferencesDrafting : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarker( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarker( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMagnet( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMagnet( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapAperture( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapAperture( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapApertureSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapApertureSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarkerColor( 
            /* [in] */ GcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarkerColor( 
            /* [retval][out] */ GcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSnapMarkerSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSnapMarkerSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PolarTrackingVector( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PolarTrackingVector( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FullScreenTrackingVector( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullScreenTrackingVector( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoTrackTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoTrackTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AlignmentPointAcquisition( 
            /* [in] */ GcAlignmentPointAcquisition Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AlignmentPointAcquisition( 
            /* [retval][out] */ GcAlignmentPointAcquisition *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesDraftingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesDrafting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesDrafting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesDrafting * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesDrafting * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarker )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarker )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMagnet )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMagnet )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapTooltip )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapTooltip )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapAperture )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapAperture )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapApertureSize )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapApertureSize )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarkerColor )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ GcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarkerColor )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ GcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSnapMarkerSize )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSnapMarkerSize )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PolarTrackingVector )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PolarTrackingVector )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FullScreenTrackingVector )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullScreenTrackingVector )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoTrackTooltip )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoTrackTooltip )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AlignmentPointAcquisition )( 
            IGcadPreferencesDrafting * This,
            /* [in] */ GcAlignmentPointAcquisition Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AlignmentPointAcquisition )( 
            IGcadPreferencesDrafting * This,
            /* [retval][out] */ GcAlignmentPointAcquisition *Path);
        
        END_INTERFACE
    } IGcadPreferencesDraftingVtbl;

    interface IGcadPreferencesDrafting
    {
        CONST_VTBL struct IGcadPreferencesDraftingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesDrafting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesDrafting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesDrafting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesDrafting_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesDrafting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesDrafting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesDrafting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesDrafting_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesDrafting_put_AutoSnapMarker(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarker(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapMarker(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarker(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapMagnet(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMagnet(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapMagnet(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMagnet(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapTooltip(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapTooltip(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapAperture(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapAperture(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapAperture(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapAperture(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapApertureSize(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapApertureSize(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapApertureSize(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapApertureSize(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapMarkerColor(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarkerColor(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapMarkerColor(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarkerColor(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoSnapMarkerSize(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSnapMarkerSize(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoSnapMarkerSize(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSnapMarkerSize(This,Path) ) 

#define IGcadPreferencesDrafting_put_PolarTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> put_PolarTrackingVector(This,Path) ) 

#define IGcadPreferencesDrafting_get_PolarTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> get_PolarTrackingVector(This,Path) ) 

#define IGcadPreferencesDrafting_put_FullScreenTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> put_FullScreenTrackingVector(This,Path) ) 

#define IGcadPreferencesDrafting_get_FullScreenTrackingVector(This,Path)	\
    ( (This)->lpVtbl -> get_FullScreenTrackingVector(This,Path) ) 

#define IGcadPreferencesDrafting_put_AutoTrackTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_AutoTrackTooltip(This,Path) ) 

#define IGcadPreferencesDrafting_get_AutoTrackTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_AutoTrackTooltip(This,Path) ) 

#define IGcadPreferencesDrafting_put_AlignmentPointAcquisition(This,Path)	\
    ( (This)->lpVtbl -> put_AlignmentPointAcquisition(This,Path) ) 

#define IGcadPreferencesDrafting_get_AlignmentPointAcquisition(This,Path)	\
    ( (This)->lpVtbl -> get_AlignmentPointAcquisition(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesDrafting_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesDisplay_INTERFACE_DEFINED__
#define __IGcadPreferencesDisplay_INTERFACE_DEFINED__

/* interface IGcadPreferencesDisplay */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFA91E4C-5304-45CC-AA56-F57F39D7FCCD")
    IGcadPreferencesDisplay : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayMargins( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayMargins( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayPaper( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayPaper( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutDisplayPaperShadow( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutDisplayPaperShadow( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutShowPlotSetup( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutShowPlotSetup( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutCreateViewport( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutCreateViewport( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayScrollBars( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayScrollBars( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayScreenMenu( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayScreenMenu( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CursorSize( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CursorSize( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DockedVisibleLines( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DockedVisibleLines( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowRasterImage( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowRasterImage( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GraphicsWinModelBackgrndColor( 
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GraphicsWinModelBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *color) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ModelCrosshairColor( 
            /* [in] */ OLE_COLOR crossHairColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ModelCrosshairColor( 
            /* [retval][out] */ OLE_COLOR *crossHairColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GraphicsWinLayoutBackgrndColor( 
            /* [in] */ OLE_COLOR color) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GraphicsWinLayoutBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *color) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextWinBackgrndColor( 
            /* [in] */ OLE_COLOR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextWinBackgrndColor( 
            /* [retval][out] */ OLE_COLOR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextWinTextColor( 
            /* [in] */ OLE_COLOR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextWinTextColor( 
            /* [retval][out] */ OLE_COLOR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LayoutCrosshairColor( 
            /* [in] */ OLE_COLOR crossHairColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LayoutCrosshairColor( 
            /* [retval][out] */ OLE_COLOR *crossHairColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoTrackingVecColor( 
            /* [in] */ OLE_COLOR AutoTrackingVecColor) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoTrackingVecColor( 
            /* [retval][out] */ OLE_COLOR *AutoTrackingVecColor) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFont( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFont( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFontStyle( 
            /* [in] */ GcTextFontStyle Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFontStyle( 
            /* [retval][out] */ GcTextFontStyle *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextFontSize( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextFontSize( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HistoryLines( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HistoryLines( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxAutoCADWindow( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxAutoCADWindow( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayLayoutTabs( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayLayoutTabs( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ImageFrameHighlight( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ImageFrameHighlight( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TrueColorImages( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TrueColorImages( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_XRefFadeIntensity( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_XRefFadeIntensity( 
            /* [retval][out] */ long *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesDisplay * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayMargins )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayMargins )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayPaper )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayPaper )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutDisplayPaperShadow )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutDisplayPaperShadow )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutShowPlotSetup )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutShowPlotSetup )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutCreateViewport )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutCreateViewport )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScrollBars )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScrollBars )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayScreenMenu )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayScreenMenu )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CursorSize )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CursorSize )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DockedVisibleLines )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DockedVisibleLines )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowRasterImage )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowRasterImage )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GraphicsWinModelBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GraphicsWinModelBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *color);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ModelCrosshairColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR crossHairColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ModelCrosshairColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *crossHairColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GraphicsWinLayoutBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR color);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GraphicsWinLayoutBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *color);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextWinBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextWinBackgrndColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextWinTextColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextWinTextColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LayoutCrosshairColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR crossHairColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LayoutCrosshairColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *crossHairColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoTrackingVecColor )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ OLE_COLOR AutoTrackingVecColor);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoTrackingVecColor )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ OLE_COLOR *AutoTrackingVecColor);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFont )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFont )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFontStyle )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ GcTextFontStyle Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFontStyle )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ GcTextFontStyle *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextFontSize )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextFontSize )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HistoryLines )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HistoryLines )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MaxAutoCADWindow )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MaxAutoCADWindow )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayLayoutTabs )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayLayoutTabs )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ImageFrameHighlight )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ImageFrameHighlight )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TrueColorImages )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TrueColorImages )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_XRefFadeIntensity )( 
            IGcadPreferencesDisplay * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_XRefFadeIntensity )( 
            IGcadPreferencesDisplay * This,
            /* [retval][out] */ long *Path);
        
        END_INTERFACE
    } IGcadPreferencesDisplayVtbl;

    interface IGcadPreferencesDisplay
    {
        CONST_VTBL struct IGcadPreferencesDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesDisplay_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesDisplay_put_LayoutDisplayMargins(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayMargins(This,Path) ) 

#define IGcadPreferencesDisplay_get_LayoutDisplayMargins(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayMargins(This,Path) ) 

#define IGcadPreferencesDisplay_put_LayoutDisplayPaper(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayPaper(This,Path) ) 

#define IGcadPreferencesDisplay_get_LayoutDisplayPaper(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayPaper(This,Path) ) 

#define IGcadPreferencesDisplay_put_LayoutDisplayPaperShadow(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutDisplayPaperShadow(This,Path) ) 

#define IGcadPreferencesDisplay_get_LayoutDisplayPaperShadow(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutDisplayPaperShadow(This,Path) ) 

#define IGcadPreferencesDisplay_put_LayoutShowPlotSetup(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutShowPlotSetup(This,Path) ) 

#define IGcadPreferencesDisplay_get_LayoutShowPlotSetup(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutShowPlotSetup(This,Path) ) 

#define IGcadPreferencesDisplay_put_LayoutCreateViewport(This,Path)	\
    ( (This)->lpVtbl -> put_LayoutCreateViewport(This,Path) ) 

#define IGcadPreferencesDisplay_get_LayoutCreateViewport(This,Path)	\
    ( (This)->lpVtbl -> get_LayoutCreateViewport(This,Path) ) 

#define IGcadPreferencesDisplay_put_DisplayScrollBars(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayScrollBars(This,Path) ) 

#define IGcadPreferencesDisplay_get_DisplayScrollBars(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayScrollBars(This,Path) ) 

#define IGcadPreferencesDisplay_put_DisplayScreenMenu(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayScreenMenu(This,Path) ) 

#define IGcadPreferencesDisplay_get_DisplayScreenMenu(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayScreenMenu(This,Path) ) 

#define IGcadPreferencesDisplay_put_CursorSize(This,Path)	\
    ( (This)->lpVtbl -> put_CursorSize(This,Path) ) 

#define IGcadPreferencesDisplay_get_CursorSize(This,Path)	\
    ( (This)->lpVtbl -> get_CursorSize(This,Path) ) 

#define IGcadPreferencesDisplay_put_DockedVisibleLines(This,Path)	\
    ( (This)->lpVtbl -> put_DockedVisibleLines(This,Path) ) 

#define IGcadPreferencesDisplay_get_DockedVisibleLines(This,Path)	\
    ( (This)->lpVtbl -> get_DockedVisibleLines(This,Path) ) 

#define IGcadPreferencesDisplay_put_ShowRasterImage(This,Path)	\
    ( (This)->lpVtbl -> put_ShowRasterImage(This,Path) ) 

#define IGcadPreferencesDisplay_get_ShowRasterImage(This,Path)	\
    ( (This)->lpVtbl -> get_ShowRasterImage(This,Path) ) 

#define IGcadPreferencesDisplay_put_GraphicsWinModelBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> put_GraphicsWinModelBackgrndColor(This,color) ) 

#define IGcadPreferencesDisplay_get_GraphicsWinModelBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> get_GraphicsWinModelBackgrndColor(This,color) ) 

#define IGcadPreferencesDisplay_put_ModelCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> put_ModelCrosshairColor(This,crossHairColor) ) 

#define IGcadPreferencesDisplay_get_ModelCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> get_ModelCrosshairColor(This,crossHairColor) ) 

#define IGcadPreferencesDisplay_put_GraphicsWinLayoutBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> put_GraphicsWinLayoutBackgrndColor(This,color) ) 

#define IGcadPreferencesDisplay_get_GraphicsWinLayoutBackgrndColor(This,color)	\
    ( (This)->lpVtbl -> get_GraphicsWinLayoutBackgrndColor(This,color) ) 

#define IGcadPreferencesDisplay_put_TextWinBackgrndColor(This,Path)	\
    ( (This)->lpVtbl -> put_TextWinBackgrndColor(This,Path) ) 

#define IGcadPreferencesDisplay_get_TextWinBackgrndColor(This,Path)	\
    ( (This)->lpVtbl -> get_TextWinBackgrndColor(This,Path) ) 

#define IGcadPreferencesDisplay_put_TextWinTextColor(This,Path)	\
    ( (This)->lpVtbl -> put_TextWinTextColor(This,Path) ) 

#define IGcadPreferencesDisplay_get_TextWinTextColor(This,Path)	\
    ( (This)->lpVtbl -> get_TextWinTextColor(This,Path) ) 

#define IGcadPreferencesDisplay_put_LayoutCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> put_LayoutCrosshairColor(This,crossHairColor) ) 

#define IGcadPreferencesDisplay_get_LayoutCrosshairColor(This,crossHairColor)	\
    ( (This)->lpVtbl -> get_LayoutCrosshairColor(This,crossHairColor) ) 

#define IGcadPreferencesDisplay_put_AutoTrackingVecColor(This,AutoTrackingVecColor)	\
    ( (This)->lpVtbl -> put_AutoTrackingVecColor(This,AutoTrackingVecColor) ) 

#define IGcadPreferencesDisplay_get_AutoTrackingVecColor(This,AutoTrackingVecColor)	\
    ( (This)->lpVtbl -> get_AutoTrackingVecColor(This,AutoTrackingVecColor) ) 

#define IGcadPreferencesDisplay_put_TextFont(This,Path)	\
    ( (This)->lpVtbl -> put_TextFont(This,Path) ) 

#define IGcadPreferencesDisplay_get_TextFont(This,Path)	\
    ( (This)->lpVtbl -> get_TextFont(This,Path) ) 

#define IGcadPreferencesDisplay_put_TextFontStyle(This,Path)	\
    ( (This)->lpVtbl -> put_TextFontStyle(This,Path) ) 

#define IGcadPreferencesDisplay_get_TextFontStyle(This,Path)	\
    ( (This)->lpVtbl -> get_TextFontStyle(This,Path) ) 

#define IGcadPreferencesDisplay_put_TextFontSize(This,Path)	\
    ( (This)->lpVtbl -> put_TextFontSize(This,Path) ) 

#define IGcadPreferencesDisplay_get_TextFontSize(This,Path)	\
    ( (This)->lpVtbl -> get_TextFontSize(This,Path) ) 

#define IGcadPreferencesDisplay_put_HistoryLines(This,Path)	\
    ( (This)->lpVtbl -> put_HistoryLines(This,Path) ) 

#define IGcadPreferencesDisplay_get_HistoryLines(This,Path)	\
    ( (This)->lpVtbl -> get_HistoryLines(This,Path) ) 

#define IGcadPreferencesDisplay_put_MaxAutoCADWindow(This,Path)	\
    ( (This)->lpVtbl -> put_MaxAutoCADWindow(This,Path) ) 

#define IGcadPreferencesDisplay_get_MaxAutoCADWindow(This,Path)	\
    ( (This)->lpVtbl -> get_MaxAutoCADWindow(This,Path) ) 

#define IGcadPreferencesDisplay_put_DisplayLayoutTabs(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayLayoutTabs(This,Path) ) 

#define IGcadPreferencesDisplay_get_DisplayLayoutTabs(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayLayoutTabs(This,Path) ) 

#define IGcadPreferencesDisplay_put_ImageFrameHighlight(This,Path)	\
    ( (This)->lpVtbl -> put_ImageFrameHighlight(This,Path) ) 

#define IGcadPreferencesDisplay_get_ImageFrameHighlight(This,Path)	\
    ( (This)->lpVtbl -> get_ImageFrameHighlight(This,Path) ) 

#define IGcadPreferencesDisplay_put_TrueColorImages(This,Path)	\
    ( (This)->lpVtbl -> put_TrueColorImages(This,Path) ) 

#define IGcadPreferencesDisplay_get_TrueColorImages(This,Path)	\
    ( (This)->lpVtbl -> get_TrueColorImages(This,Path) ) 

#define IGcadPreferencesDisplay_put_XRefFadeIntensity(This,Path)	\
    ( (This)->lpVtbl -> put_XRefFadeIntensity(This,Path) ) 

#define IGcadPreferencesDisplay_get_XRefFadeIntensity(This,Path)	\
    ( (This)->lpVtbl -> get_XRefFadeIntensity(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesDisplay_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesFiles_INTERFACE_DEFINED__
#define __IGcadPreferencesFiles_INTERFACE_DEFINED__

/* interface IGcadPreferencesFiles */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39B8DED6-4AAA-4E2F-9EAF-4BBD930EFCED")
    IGcadPreferencesFiles : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SupportPath( 
            /* [in] */ BSTR orient) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SupportPath( 
            /* [retval][out] */ BSTR *orient) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DriversPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DriversPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MenuFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnterpriseMenuFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnterpriseMenuFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CustomIconPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CustomIconPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultInternetURL( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultInternetURL( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ConfigFile( 
            /* [retval][out] */ BSTR *ConfigFile) = 0;
        
        virtual /* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_LicenseServer( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextEditor( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextEditor( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_MainDictionary( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MainDictionary( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CustomDictionary( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CustomDictionary( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AltFontFile( 
            /* [in] */ BSTR fontFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AltFontFile( 
            /* [retval][out] */ BSTR *fontFile) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FontFileMap( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FontFileMap( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintSpoolExecutable( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintSpoolExecutable( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PostScriptPrologFile( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PostScriptPrologFile( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrintSpoolerPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrintSpoolerPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSavePath( 
            /* [in] */ BSTR AutoSavePath) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSavePath( 
            /* [retval][out] */ BSTR *AutoSavePath) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TemplateDwgPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TemplateDwgPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LogFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LogFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempXrefPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempXrefPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TextureMapPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TextureMapPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AltTabletMenuFile( 
            /* [in] */ BSTR MenuFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AltTabletMenuFile( 
            /* [retval][out] */ BSTR *MenuFile) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetProjectFilePath( 
            /* [in] */ BSTR ProjectName,
            /* [in] */ BSTR ProjectFilePath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjectFilePath( 
            /* [in] */ BSTR ProjectName,
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterConfigPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterConfigPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterDescPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterDescPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterStyleSheetPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterStyleSheetPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WorkspacePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WorkspacePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][hidden][propput][id] */ HRESULT STDMETHODCALLTYPE put_ObjectARXPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][hidden][propget][id] */ HRESULT STDMETHODCALLTYPE get_ObjectARXPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ColorBookPath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ColorBookPath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ToolPalettePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ToolPalettePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_QNewTemplateFile( 
            /* [in] */ BSTR templateFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_QNewTemplateFile( 
            /* [retval][out] */ BSTR *templateFile) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PlotLogFilePath( 
            /* [in] */ BSTR templateFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotLogFilePath( 
            /* [retval][out] */ BSTR *templateFile) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PageSetupOverridesTemplateFile( 
            /* [in] */ BSTR templateFile) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PageSetupOverridesTemplateFile( 
            /* [retval][out] */ BSTR *templateFile) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesFiles * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesFiles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesFiles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesFiles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesFiles * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SupportPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR orient);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SupportPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *orient);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DriversPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DriversPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MenuFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnterpriseMenuFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnterpriseMenuFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CustomIconPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CustomIconPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFilePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultInternetURL )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultInternetURL )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *ConfigFile);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LicenseServer )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextEditor )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextEditor )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_MainDictionary )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MainDictionary )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CustomDictionary )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CustomDictionary )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AltFontFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR fontFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AltFontFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *fontFile);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FontFileMap )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FontFileMap )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintSpoolExecutable )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintSpoolExecutable )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PostScriptPrologFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PostScriptPrologFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrintSpoolerPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrintSpoolerPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSavePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR AutoSavePath);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSavePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *AutoSavePath);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TemplateDwgPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TemplateDwgPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LogFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LogFilePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempFilePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempXrefPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempXrefPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TextureMapPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TextureMapPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AltTabletMenuFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR MenuFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AltTabletMenuFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *MenuFile);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetProjectFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR ProjectName,
            /* [in] */ BSTR ProjectFilePath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjectFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR ProjectName,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterConfigPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterConfigPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterDescPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterDescPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterStyleSheetPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterStyleSheetPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_WorkspacePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WorkspacePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][hidden][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ObjectARXPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][hidden][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectARXPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ColorBookPath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ColorBookPath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ToolPalettePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ToolPalettePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_QNewTemplateFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR templateFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_QNewTemplateFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *templateFile);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotLogFilePath )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR templateFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotLogFilePath )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *templateFile);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PageSetupOverridesTemplateFile )( 
            IGcadPreferencesFiles * This,
            /* [in] */ BSTR templateFile);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PageSetupOverridesTemplateFile )( 
            IGcadPreferencesFiles * This,
            /* [retval][out] */ BSTR *templateFile);
        
        END_INTERFACE
    } IGcadPreferencesFilesVtbl;

    interface IGcadPreferencesFiles
    {
        CONST_VTBL struct IGcadPreferencesFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesFiles_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesFiles_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesFiles_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesFiles_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesFiles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesFiles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesFiles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesFiles_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesFiles_put_SupportPath(This,orient)	\
    ( (This)->lpVtbl -> put_SupportPath(This,orient) ) 

#define IGcadPreferencesFiles_get_SupportPath(This,orient)	\
    ( (This)->lpVtbl -> get_SupportPath(This,orient) ) 

#define IGcadPreferencesFiles_put_DriversPath(This,Path)	\
    ( (This)->lpVtbl -> put_DriversPath(This,Path) ) 

#define IGcadPreferencesFiles_get_DriversPath(This,Path)	\
    ( (This)->lpVtbl -> get_DriversPath(This,Path) ) 

#define IGcadPreferencesFiles_put_MenuFile(This,Path)	\
    ( (This)->lpVtbl -> put_MenuFile(This,Path) ) 

#define IGcadPreferencesFiles_get_MenuFile(This,Path)	\
    ( (This)->lpVtbl -> get_MenuFile(This,Path) ) 

#define IGcadPreferencesFiles_put_EnterpriseMenuFile(This,Path)	\
    ( (This)->lpVtbl -> put_EnterpriseMenuFile(This,Path) ) 

#define IGcadPreferencesFiles_get_EnterpriseMenuFile(This,Path)	\
    ( (This)->lpVtbl -> get_EnterpriseMenuFile(This,Path) ) 

#define IGcadPreferencesFiles_put_CustomIconPath(This,Path)	\
    ( (This)->lpVtbl -> put_CustomIconPath(This,Path) ) 

#define IGcadPreferencesFiles_get_CustomIconPath(This,Path)	\
    ( (This)->lpVtbl -> get_CustomIconPath(This,Path) ) 

#define IGcadPreferencesFiles_put_HelpFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_HelpFilePath(This,Path) ) 

#define IGcadPreferencesFiles_get_HelpFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_HelpFilePath(This,Path) ) 

#define IGcadPreferencesFiles_put_DefaultInternetURL(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultInternetURL(This,Path) ) 

#define IGcadPreferencesFiles_get_DefaultInternetURL(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultInternetURL(This,Path) ) 

#define IGcadPreferencesFiles_get_ConfigFile(This,ConfigFile)	\
    ( (This)->lpVtbl -> get_ConfigFile(This,ConfigFile) ) 

#define IGcadPreferencesFiles_get_LicenseServer(This,Path)	\
    ( (This)->lpVtbl -> get_LicenseServer(This,Path) ) 

#define IGcadPreferencesFiles_put_TextEditor(This,Path)	\
    ( (This)->lpVtbl -> put_TextEditor(This,Path) ) 

#define IGcadPreferencesFiles_get_TextEditor(This,Path)	\
    ( (This)->lpVtbl -> get_TextEditor(This,Path) ) 

#define IGcadPreferencesFiles_put_MainDictionary(This,Path)	\
    ( (This)->lpVtbl -> put_MainDictionary(This,Path) ) 

#define IGcadPreferencesFiles_get_MainDictionary(This,Path)	\
    ( (This)->lpVtbl -> get_MainDictionary(This,Path) ) 

#define IGcadPreferencesFiles_put_CustomDictionary(This,Path)	\
    ( (This)->lpVtbl -> put_CustomDictionary(This,Path) ) 

#define IGcadPreferencesFiles_get_CustomDictionary(This,Path)	\
    ( (This)->lpVtbl -> get_CustomDictionary(This,Path) ) 

#define IGcadPreferencesFiles_put_AltFontFile(This,fontFile)	\
    ( (This)->lpVtbl -> put_AltFontFile(This,fontFile) ) 

#define IGcadPreferencesFiles_get_AltFontFile(This,fontFile)	\
    ( (This)->lpVtbl -> get_AltFontFile(This,fontFile) ) 

#define IGcadPreferencesFiles_put_FontFileMap(This,Path)	\
    ( (This)->lpVtbl -> put_FontFileMap(This,Path) ) 

#define IGcadPreferencesFiles_get_FontFileMap(This,Path)	\
    ( (This)->lpVtbl -> get_FontFileMap(This,Path) ) 

#define IGcadPreferencesFiles_put_PrintFile(This,Path)	\
    ( (This)->lpVtbl -> put_PrintFile(This,Path) ) 

#define IGcadPreferencesFiles_get_PrintFile(This,Path)	\
    ( (This)->lpVtbl -> get_PrintFile(This,Path) ) 

#define IGcadPreferencesFiles_put_PrintSpoolExecutable(This,Path)	\
    ( (This)->lpVtbl -> put_PrintSpoolExecutable(This,Path) ) 

#define IGcadPreferencesFiles_get_PrintSpoolExecutable(This,Path)	\
    ( (This)->lpVtbl -> get_PrintSpoolExecutable(This,Path) ) 

#define IGcadPreferencesFiles_put_PostScriptPrologFile(This,Path)	\
    ( (This)->lpVtbl -> put_PostScriptPrologFile(This,Path) ) 

#define IGcadPreferencesFiles_get_PostScriptPrologFile(This,Path)	\
    ( (This)->lpVtbl -> get_PostScriptPrologFile(This,Path) ) 

#define IGcadPreferencesFiles_put_PrintSpoolerPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrintSpoolerPath(This,Path) ) 

#define IGcadPreferencesFiles_get_PrintSpoolerPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrintSpoolerPath(This,Path) ) 

#define IGcadPreferencesFiles_put_AutoSavePath(This,AutoSavePath)	\
    ( (This)->lpVtbl -> put_AutoSavePath(This,AutoSavePath) ) 

#define IGcadPreferencesFiles_get_AutoSavePath(This,AutoSavePath)	\
    ( (This)->lpVtbl -> get_AutoSavePath(This,AutoSavePath) ) 

#define IGcadPreferencesFiles_put_TemplateDwgPath(This,Path)	\
    ( (This)->lpVtbl -> put_TemplateDwgPath(This,Path) ) 

#define IGcadPreferencesFiles_get_TemplateDwgPath(This,Path)	\
    ( (This)->lpVtbl -> get_TemplateDwgPath(This,Path) ) 

#define IGcadPreferencesFiles_put_LogFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_LogFilePath(This,Path) ) 

#define IGcadPreferencesFiles_get_LogFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_LogFilePath(This,Path) ) 

#define IGcadPreferencesFiles_put_TempFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_TempFilePath(This,Path) ) 

#define IGcadPreferencesFiles_get_TempFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_TempFilePath(This,Path) ) 

#define IGcadPreferencesFiles_put_TempXrefPath(This,Path)	\
    ( (This)->lpVtbl -> put_TempXrefPath(This,Path) ) 

#define IGcadPreferencesFiles_get_TempXrefPath(This,Path)	\
    ( (This)->lpVtbl -> get_TempXrefPath(This,Path) ) 

#define IGcadPreferencesFiles_put_TextureMapPath(This,Path)	\
    ( (This)->lpVtbl -> put_TextureMapPath(This,Path) ) 

#define IGcadPreferencesFiles_get_TextureMapPath(This,Path)	\
    ( (This)->lpVtbl -> get_TextureMapPath(This,Path) ) 

#define IGcadPreferencesFiles_put_AltTabletMenuFile(This,MenuFile)	\
    ( (This)->lpVtbl -> put_AltTabletMenuFile(This,MenuFile) ) 

#define IGcadPreferencesFiles_get_AltTabletMenuFile(This,MenuFile)	\
    ( (This)->lpVtbl -> get_AltTabletMenuFile(This,MenuFile) ) 

#define IGcadPreferencesFiles_SetProjectFilePath(This,ProjectName,ProjectFilePath)	\
    ( (This)->lpVtbl -> SetProjectFilePath(This,ProjectName,ProjectFilePath) ) 

#define IGcadPreferencesFiles_GetProjectFilePath(This,ProjectName,Path)	\
    ( (This)->lpVtbl -> GetProjectFilePath(This,ProjectName,Path) ) 

#define IGcadPreferencesFiles_put_PrinterConfigPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterConfigPath(This,Path) ) 

#define IGcadPreferencesFiles_get_PrinterConfigPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterConfigPath(This,Path) ) 

#define IGcadPreferencesFiles_put_PrinterDescPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterDescPath(This,Path) ) 

#define IGcadPreferencesFiles_get_PrinterDescPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterDescPath(This,Path) ) 

#define IGcadPreferencesFiles_put_PrinterStyleSheetPath(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterStyleSheetPath(This,Path) ) 

#define IGcadPreferencesFiles_get_PrinterStyleSheetPath(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterStyleSheetPath(This,Path) ) 

#define IGcadPreferencesFiles_put_WorkspacePath(This,Path)	\
    ( (This)->lpVtbl -> put_WorkspacePath(This,Path) ) 

#define IGcadPreferencesFiles_get_WorkspacePath(This,Path)	\
    ( (This)->lpVtbl -> get_WorkspacePath(This,Path) ) 

#define IGcadPreferencesFiles_put_ObjectARXPath(This,Path)	\
    ( (This)->lpVtbl -> put_ObjectARXPath(This,Path) ) 

#define IGcadPreferencesFiles_get_ObjectARXPath(This,Path)	\
    ( (This)->lpVtbl -> get_ObjectARXPath(This,Path) ) 

#define IGcadPreferencesFiles_put_ColorBookPath(This,Path)	\
    ( (This)->lpVtbl -> put_ColorBookPath(This,Path) ) 

#define IGcadPreferencesFiles_get_ColorBookPath(This,Path)	\
    ( (This)->lpVtbl -> get_ColorBookPath(This,Path) ) 

#define IGcadPreferencesFiles_put_ToolPalettePath(This,Path)	\
    ( (This)->lpVtbl -> put_ToolPalettePath(This,Path) ) 

#define IGcadPreferencesFiles_get_ToolPalettePath(This,Path)	\
    ( (This)->lpVtbl -> get_ToolPalettePath(This,Path) ) 

#define IGcadPreferencesFiles_put_QNewTemplateFile(This,templateFile)	\
    ( (This)->lpVtbl -> put_QNewTemplateFile(This,templateFile) ) 

#define IGcadPreferencesFiles_get_QNewTemplateFile(This,templateFile)	\
    ( (This)->lpVtbl -> get_QNewTemplateFile(This,templateFile) ) 

#define IGcadPreferencesFiles_put_PlotLogFilePath(This,templateFile)	\
    ( (This)->lpVtbl -> put_PlotLogFilePath(This,templateFile) ) 

#define IGcadPreferencesFiles_get_PlotLogFilePath(This,templateFile)	\
    ( (This)->lpVtbl -> get_PlotLogFilePath(This,templateFile) ) 

#define IGcadPreferencesFiles_put_PageSetupOverridesTemplateFile(This,templateFile)	\
    ( (This)->lpVtbl -> put_PageSetupOverridesTemplateFile(This,templateFile) ) 

#define IGcadPreferencesFiles_get_PageSetupOverridesTemplateFile(This,templateFile)	\
    ( (This)->lpVtbl -> get_PageSetupOverridesTemplateFile(This,templateFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesFiles_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesOpenSave_INTERFACE_DEFINED__
#define __IGcadPreferencesOpenSave_INTERFACE_DEFINED__

/* interface IGcadPreferencesOpenSave */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesOpenSave;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("97311A0B-4C28-4D80-8397-40FB3403AEF0")
    IGcadPreferencesOpenSave : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SavePreviewThumbnail( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SavePreviewThumbnail( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_IncrementalSavePercent( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_IncrementalSavePercent( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoSaveInterval( 
            /* [in] */ int Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoSaveInterval( 
            /* [retval][out] */ int *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CreateBackup( 
            /* [in] */ VARIANT_BOOL CreateBackup) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CreateBackup( 
            /* [retval][out] */ VARIANT_BOOL *CreateBackup) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FullCRCValidation( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FullCRCValidation( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LogFileOn( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LogFileOn( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TempFileExtension( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TempFileExtension( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_XrefDemandLoad( 
            /* [in] */ GcXRefDemandLoad Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_XrefDemandLoad( 
            /* [retval][out] */ GcXRefDemandLoad *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DemandLoadARXApp( 
            /* [in] */ GcGRXDemandLoad Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DemandLoadARXApp( 
            /* [retval][out] */ GcGRXDemandLoad *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProxyImage( 
            /* [in] */ GcProxyImage Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProxyImage( 
            /* [retval][out] */ GcProxyImage *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowProxyDialogBox( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowProxyDialogBox( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutoAudit( 
            /* [in] */ VARIANT_BOOL bAudit) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutoAudit( 
            /* [retval][out] */ VARIANT_BOOL *bAudit) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SaveAsType( 
            /* [in] */ GcSaveAsType Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SaveAsType( 
            /* [retval][out] */ GcSaveAsType *Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MRUNumber( 
            /* [retval][out] */ long *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesOpenSaveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesOpenSave * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesOpenSave * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesOpenSave * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesOpenSave * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SavePreviewThumbnail )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SavePreviewThumbnail )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalSavePercent )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalSavePercent )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSaveInterval )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ int Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSaveInterval )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ int *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CreateBackup )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL CreateBackup);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CreateBackup )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *CreateBackup);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FullCRCValidation )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FullCRCValidation )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LogFileOn )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LogFileOn )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TempFileExtension )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TempFileExtension )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_XrefDemandLoad )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ GcXRefDemandLoad Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_XrefDemandLoad )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ GcXRefDemandLoad *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DemandLoadARXApp )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ GcGRXDemandLoad Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DemandLoadARXApp )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ GcGRXDemandLoad *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProxyImage )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ GcProxyImage Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProxyImage )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ GcProxyImage *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowProxyDialogBox )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowProxyDialogBox )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutoAudit )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ VARIANT_BOOL bAudit);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutoAudit )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ VARIANT_BOOL *bAudit);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SaveAsType )( 
            IGcadPreferencesOpenSave * This,
            /* [in] */ GcSaveAsType Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SaveAsType )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ GcSaveAsType *Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MRUNumber )( 
            IGcadPreferencesOpenSave * This,
            /* [retval][out] */ long *Path);
        
        END_INTERFACE
    } IGcadPreferencesOpenSaveVtbl;

    interface IGcadPreferencesOpenSave
    {
        CONST_VTBL struct IGcadPreferencesOpenSaveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesOpenSave_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesOpenSave_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesOpenSave_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesOpenSave_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesOpenSave_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesOpenSave_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesOpenSave_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesOpenSave_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesOpenSave_put_SavePreviewThumbnail(This,Path)	\
    ( (This)->lpVtbl -> put_SavePreviewThumbnail(This,Path) ) 

#define IGcadPreferencesOpenSave_get_SavePreviewThumbnail(This,Path)	\
    ( (This)->lpVtbl -> get_SavePreviewThumbnail(This,Path) ) 

#define IGcadPreferencesOpenSave_put_IncrementalSavePercent(This,Path)	\
    ( (This)->lpVtbl -> put_IncrementalSavePercent(This,Path) ) 

#define IGcadPreferencesOpenSave_get_IncrementalSavePercent(This,Path)	\
    ( (This)->lpVtbl -> get_IncrementalSavePercent(This,Path) ) 

#define IGcadPreferencesOpenSave_put_AutoSaveInterval(This,Path)	\
    ( (This)->lpVtbl -> put_AutoSaveInterval(This,Path) ) 

#define IGcadPreferencesOpenSave_get_AutoSaveInterval(This,Path)	\
    ( (This)->lpVtbl -> get_AutoSaveInterval(This,Path) ) 

#define IGcadPreferencesOpenSave_put_CreateBackup(This,CreateBackup)	\
    ( (This)->lpVtbl -> put_CreateBackup(This,CreateBackup) ) 

#define IGcadPreferencesOpenSave_get_CreateBackup(This,CreateBackup)	\
    ( (This)->lpVtbl -> get_CreateBackup(This,CreateBackup) ) 

#define IGcadPreferencesOpenSave_put_FullCRCValidation(This,Path)	\
    ( (This)->lpVtbl -> put_FullCRCValidation(This,Path) ) 

#define IGcadPreferencesOpenSave_get_FullCRCValidation(This,Path)	\
    ( (This)->lpVtbl -> get_FullCRCValidation(This,Path) ) 

#define IGcadPreferencesOpenSave_put_LogFileOn(This,Path)	\
    ( (This)->lpVtbl -> put_LogFileOn(This,Path) ) 

#define IGcadPreferencesOpenSave_get_LogFileOn(This,Path)	\
    ( (This)->lpVtbl -> get_LogFileOn(This,Path) ) 

#define IGcadPreferencesOpenSave_put_TempFileExtension(This,Path)	\
    ( (This)->lpVtbl -> put_TempFileExtension(This,Path) ) 

#define IGcadPreferencesOpenSave_get_TempFileExtension(This,Path)	\
    ( (This)->lpVtbl -> get_TempFileExtension(This,Path) ) 

#define IGcadPreferencesOpenSave_put_XrefDemandLoad(This,Path)	\
    ( (This)->lpVtbl -> put_XrefDemandLoad(This,Path) ) 

#define IGcadPreferencesOpenSave_get_XrefDemandLoad(This,Path)	\
    ( (This)->lpVtbl -> get_XrefDemandLoad(This,Path) ) 

#define IGcadPreferencesOpenSave_put_DemandLoadARXApp(This,Path)	\
    ( (This)->lpVtbl -> put_DemandLoadARXApp(This,Path) ) 

#define IGcadPreferencesOpenSave_get_DemandLoadARXApp(This,Path)	\
    ( (This)->lpVtbl -> get_DemandLoadARXApp(This,Path) ) 

#define IGcadPreferencesOpenSave_put_ProxyImage(This,Path)	\
    ( (This)->lpVtbl -> put_ProxyImage(This,Path) ) 

#define IGcadPreferencesOpenSave_get_ProxyImage(This,Path)	\
    ( (This)->lpVtbl -> get_ProxyImage(This,Path) ) 

#define IGcadPreferencesOpenSave_put_ShowProxyDialogBox(This,Path)	\
    ( (This)->lpVtbl -> put_ShowProxyDialogBox(This,Path) ) 

#define IGcadPreferencesOpenSave_get_ShowProxyDialogBox(This,Path)	\
    ( (This)->lpVtbl -> get_ShowProxyDialogBox(This,Path) ) 

#define IGcadPreferencesOpenSave_put_AutoAudit(This,bAudit)	\
    ( (This)->lpVtbl -> put_AutoAudit(This,bAudit) ) 

#define IGcadPreferencesOpenSave_get_AutoAudit(This,bAudit)	\
    ( (This)->lpVtbl -> get_AutoAudit(This,bAudit) ) 

#define IGcadPreferencesOpenSave_put_SaveAsType(This,Path)	\
    ( (This)->lpVtbl -> put_SaveAsType(This,Path) ) 

#define IGcadPreferencesOpenSave_get_SaveAsType(This,Path)	\
    ( (This)->lpVtbl -> get_SaveAsType(This,Path) ) 

#define IGcadPreferencesOpenSave_get_MRUNumber(This,Path)	\
    ( (This)->lpVtbl -> get_MRUNumber(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesOpenSave_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesOutput_INTERFACE_DEFINED__
#define __IGcadPreferencesOutput_INTERFACE_DEFINED__

/* interface IGcadPreferencesOutput */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesOutput;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA0A2ECE-5E7C-46EF-ACCA-F2528C0C2566")
    IGcadPreferencesOutput : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultOutputDevice( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultOutputDevice( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterSpoolAlert( 
            /* [in] */ GcPrinterSpoolAlert Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterSpoolAlert( 
            /* [retval][out] */ GcPrinterSpoolAlert *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PrinterPaperSizeAlert( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PrinterPaperSizeAlert( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PlotLegacy( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotLegacy( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_OLEQuality( 
            /* [in] */ GcOleQuality Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OLEQuality( 
            /* [retval][out] */ GcOleQuality *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_UseLastPlotSettings( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_UseLastPlotSettings( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PlotPolicy( 
            /* [in] */ GcPlotPolicy Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PlotPolicy( 
            /* [retval][out] */ GcPlotPolicy *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleTable( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleTable( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleForObjects( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleForObjects( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotStyleForLayer( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotStyleForLayer( 
            /* [retval][out] */ BSTR *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ContinuousPlotLog( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ContinuousPlotLog( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AutomaticPlotLog( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AutomaticPlotLog( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DefaultPlotToFilePath( 
            /* [in] */ BSTR Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DefaultPlotToFilePath( 
            /* [retval][out] */ BSTR *Path) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesOutputVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesOutput * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesOutput * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesOutput * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesOutput * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesOutput * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesOutput * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesOutput * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultOutputDevice )( 
            IGcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultOutputDevice )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterSpoolAlert )( 
            IGcadPreferencesOutput * This,
            /* [in] */ GcPrinterSpoolAlert Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterSpoolAlert )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ GcPrinterSpoolAlert *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PrinterPaperSizeAlert )( 
            IGcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PrinterPaperSizeAlert )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotLegacy )( 
            IGcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotLegacy )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_OLEQuality )( 
            IGcadPreferencesOutput * This,
            /* [in] */ GcOleQuality Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OLEQuality )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ GcOleQuality *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_UseLastPlotSettings )( 
            IGcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UseLastPlotSettings )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PlotPolicy )( 
            IGcadPreferencesOutput * This,
            /* [in] */ GcPlotPolicy Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PlotPolicy )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ GcPlotPolicy *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleTable )( 
            IGcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleTable )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleForObjects )( 
            IGcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleForObjects )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotStyleForLayer )( 
            IGcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotStyleForLayer )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ContinuousPlotLog )( 
            IGcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ContinuousPlotLog )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_AutomaticPlotLog )( 
            IGcadPreferencesOutput * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AutomaticPlotLog )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultPlotToFilePath )( 
            IGcadPreferencesOutput * This,
            /* [in] */ BSTR Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultPlotToFilePath )( 
            IGcadPreferencesOutput * This,
            /* [retval][out] */ BSTR *Path);
        
        END_INTERFACE
    } IGcadPreferencesOutputVtbl;

    interface IGcadPreferencesOutput
    {
        CONST_VTBL struct IGcadPreferencesOutputVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesOutput_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesOutput_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesOutput_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesOutput_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesOutput_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesOutput_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesOutput_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesOutput_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesOutput_put_DefaultOutputDevice(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultOutputDevice(This,Path) ) 

#define IGcadPreferencesOutput_get_DefaultOutputDevice(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultOutputDevice(This,Path) ) 

#define IGcadPreferencesOutput_put_PrinterSpoolAlert(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterSpoolAlert(This,Path) ) 

#define IGcadPreferencesOutput_get_PrinterSpoolAlert(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterSpoolAlert(This,Path) ) 

#define IGcadPreferencesOutput_put_PrinterPaperSizeAlert(This,Path)	\
    ( (This)->lpVtbl -> put_PrinterPaperSizeAlert(This,Path) ) 

#define IGcadPreferencesOutput_get_PrinterPaperSizeAlert(This,Path)	\
    ( (This)->lpVtbl -> get_PrinterPaperSizeAlert(This,Path) ) 

#define IGcadPreferencesOutput_put_PlotLegacy(This,Path)	\
    ( (This)->lpVtbl -> put_PlotLegacy(This,Path) ) 

#define IGcadPreferencesOutput_get_PlotLegacy(This,Path)	\
    ( (This)->lpVtbl -> get_PlotLegacy(This,Path) ) 

#define IGcadPreferencesOutput_put_OLEQuality(This,Path)	\
    ( (This)->lpVtbl -> put_OLEQuality(This,Path) ) 

#define IGcadPreferencesOutput_get_OLEQuality(This,Path)	\
    ( (This)->lpVtbl -> get_OLEQuality(This,Path) ) 

#define IGcadPreferencesOutput_put_UseLastPlotSettings(This,Path)	\
    ( (This)->lpVtbl -> put_UseLastPlotSettings(This,Path) ) 

#define IGcadPreferencesOutput_get_UseLastPlotSettings(This,Path)	\
    ( (This)->lpVtbl -> get_UseLastPlotSettings(This,Path) ) 

#define IGcadPreferencesOutput_put_PlotPolicy(This,Path)	\
    ( (This)->lpVtbl -> put_PlotPolicy(This,Path) ) 

#define IGcadPreferencesOutput_get_PlotPolicy(This,Path)	\
    ( (This)->lpVtbl -> get_PlotPolicy(This,Path) ) 

#define IGcadPreferencesOutput_put_DefaultPlotStyleTable(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleTable(This,Path) ) 

#define IGcadPreferencesOutput_get_DefaultPlotStyleTable(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleTable(This,Path) ) 

#define IGcadPreferencesOutput_put_DefaultPlotStyleForObjects(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleForObjects(This,Path) ) 

#define IGcadPreferencesOutput_get_DefaultPlotStyleForObjects(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleForObjects(This,Path) ) 

#define IGcadPreferencesOutput_put_DefaultPlotStyleForLayer(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotStyleForLayer(This,Path) ) 

#define IGcadPreferencesOutput_get_DefaultPlotStyleForLayer(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotStyleForLayer(This,Path) ) 

#define IGcadPreferencesOutput_put_ContinuousPlotLog(This,Path)	\
    ( (This)->lpVtbl -> put_ContinuousPlotLog(This,Path) ) 

#define IGcadPreferencesOutput_get_ContinuousPlotLog(This,Path)	\
    ( (This)->lpVtbl -> get_ContinuousPlotLog(This,Path) ) 

#define IGcadPreferencesOutput_put_AutomaticPlotLog(This,Path)	\
    ( (This)->lpVtbl -> put_AutomaticPlotLog(This,Path) ) 

#define IGcadPreferencesOutput_get_AutomaticPlotLog(This,Path)	\
    ( (This)->lpVtbl -> get_AutomaticPlotLog(This,Path) ) 

#define IGcadPreferencesOutput_put_DefaultPlotToFilePath(This,Path)	\
    ( (This)->lpVtbl -> put_DefaultPlotToFilePath(This,Path) ) 

#define IGcadPreferencesOutput_get_DefaultPlotToFilePath(This,Path)	\
    ( (This)->lpVtbl -> get_DefaultPlotToFilePath(This,Path) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesOutput_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesSystem_INTERFACE_DEFINED__
#define __IGcadPreferencesSystem_INTERFACE_DEFINED__

/* interface IGcadPreferencesSystem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51B2EDFB-066F-40E2-A298-D3DA4355BAE7")
    IGcadPreferencesSystem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SingleDocumentMode( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SingleDocumentMode( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayOLEScale( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayOLEScale( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_StoreSQLIndex( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_StoreSQLIndex( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TablesReadOnly( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TablesReadOnly( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EnableStartupDialog( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EnableStartupDialog( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BeepOnError( 
            /* [in] */ VARIANT_BOOL BeepOnError) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BeepOnError( 
            /* [retval][out] */ VARIANT_BOOL *BeepOnError) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowWarningMessages( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowWarningMessages( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LoadGcadLspInAllDocuments( 
            /* [in] */ VARIANT_BOOL pALID) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LoadGcadLspInAllDocuments( 
            /* [retval][out] */ VARIANT_BOOL *pALID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesSystem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesSystem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesSystem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesSystem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesSystem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesSystem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SingleDocumentMode )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SingleDocumentMode )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayOLEScale )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayOLEScale )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_StoreSQLIndex )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StoreSQLIndex )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TablesReadOnly )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TablesReadOnly )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EnableStartupDialog )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EnableStartupDialog )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_BeepOnError )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL BeepOnError);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_BeepOnError )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *BeepOnError);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShowWarningMessages )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShowWarningMessages )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LoadGcadLspInAllDocuments )( 
            IGcadPreferencesSystem * This,
            /* [in] */ VARIANT_BOOL pALID);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LoadGcadLspInAllDocuments )( 
            IGcadPreferencesSystem * This,
            /* [retval][out] */ VARIANT_BOOL *pALID);
        
        END_INTERFACE
    } IGcadPreferencesSystemVtbl;

    interface IGcadPreferencesSystem
    {
        CONST_VTBL struct IGcadPreferencesSystemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesSystem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesSystem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesSystem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesSystem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesSystem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesSystem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesSystem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesSystem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesSystem_put_SingleDocumentMode(This,Path)	\
    ( (This)->lpVtbl -> put_SingleDocumentMode(This,Path) ) 

#define IGcadPreferencesSystem_get_SingleDocumentMode(This,Path)	\
    ( (This)->lpVtbl -> get_SingleDocumentMode(This,Path) ) 

#define IGcadPreferencesSystem_put_DisplayOLEScale(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayOLEScale(This,Path) ) 

#define IGcadPreferencesSystem_get_DisplayOLEScale(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayOLEScale(This,Path) ) 

#define IGcadPreferencesSystem_put_StoreSQLIndex(This,Path)	\
    ( (This)->lpVtbl -> put_StoreSQLIndex(This,Path) ) 

#define IGcadPreferencesSystem_get_StoreSQLIndex(This,Path)	\
    ( (This)->lpVtbl -> get_StoreSQLIndex(This,Path) ) 

#define IGcadPreferencesSystem_put_TablesReadOnly(This,Path)	\
    ( (This)->lpVtbl -> put_TablesReadOnly(This,Path) ) 

#define IGcadPreferencesSystem_get_TablesReadOnly(This,Path)	\
    ( (This)->lpVtbl -> get_TablesReadOnly(This,Path) ) 

#define IGcadPreferencesSystem_put_EnableStartupDialog(This,Path)	\
    ( (This)->lpVtbl -> put_EnableStartupDialog(This,Path) ) 

#define IGcadPreferencesSystem_get_EnableStartupDialog(This,Path)	\
    ( (This)->lpVtbl -> get_EnableStartupDialog(This,Path) ) 

#define IGcadPreferencesSystem_put_BeepOnError(This,BeepOnError)	\
    ( (This)->lpVtbl -> put_BeepOnError(This,BeepOnError) ) 

#define IGcadPreferencesSystem_get_BeepOnError(This,BeepOnError)	\
    ( (This)->lpVtbl -> get_BeepOnError(This,BeepOnError) ) 

#define IGcadPreferencesSystem_put_ShowWarningMessages(This,Path)	\
    ( (This)->lpVtbl -> put_ShowWarningMessages(This,Path) ) 

#define IGcadPreferencesSystem_get_ShowWarningMessages(This,Path)	\
    ( (This)->lpVtbl -> get_ShowWarningMessages(This,Path) ) 

#define IGcadPreferencesSystem_put_LoadGcadLspInAllDocuments(This,pALID)	\
    ( (This)->lpVtbl -> put_LoadGcadLspInAllDocuments(This,pALID) ) 

#define IGcadPreferencesSystem_get_LoadGcadLspInAllDocuments(This,pALID)	\
    ( (This)->lpVtbl -> get_LoadGcadLspInAllDocuments(This,pALID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesSystem_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesUser_INTERFACE_DEFINED__
#define __IGcadPreferencesUser_INTERFACE_DEFINED__

/* interface IGcadPreferencesUser */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AC90CA06-AABE-40DB-BE6B-D4C18C5BF232")
    IGcadPreferencesUser : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyboardAccelerator( 
            /* [in] */ GcKeyboardAccelerator Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyboardAccelerator( 
            /* [retval][out] */ GcKeyboardAccelerator *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyboardPriority( 
            /* [in] */ GcKeyboardPriority Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyboardPriority( 
            /* [retval][out] */ GcKeyboardPriority *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HyperlinkDisplayCursor( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HyperlinkDisplayCursor( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HyperlinkDisplayTooltip( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HyperlinkDisplayTooltip( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ADCInsertUnitsDefaultSource( 
            /* [in] */ GcInsertUnits pIU) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ADCInsertUnitsDefaultSource( 
            /* [retval][out] */ GcInsertUnits *pIU) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ADCInsertUnitsDefaultTarget( 
            /* [in] */ GcInsertUnits pSUunits) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ADCInsertUnitsDefaultTarget( 
            /* [retval][out] */ GcInsertUnits *pSUunits) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ShortCutMenuDisplay( 
            /* [in] */ VARIANT_BOOL pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortCutMenuDisplay( 
            /* [retval][out] */ VARIANT_BOOL *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMDefaultMode( 
            /* [in] */ GcDrawingAreaSCMDefault pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMDefaultMode( 
            /* [retval][out] */ GcDrawingAreaSCMDefault *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMEditMode( 
            /* [in] */ GcDrawingAreaSCMEdit pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMEditMode( 
            /* [retval][out] */ GcDrawingAreaSCMEdit *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMCommandMode( 
            /* [in] */ GcDrawingAreaSCMCommand pSCM) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMCommandMode( 
            /* [retval][out] */ GcDrawingAreaSCMCommand *pSCM) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMTimeMode( 
            /* [in] */ VARIANT_BOOL time) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMTimeMode( 
            /* [retval][out] */ VARIANT_BOOL *time) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SCMTimeValue( 
            /* [in] */ int time) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SCMTimeValue( 
            /* [retval][out] */ int *time) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesUser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesUser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesUser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesUser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesUser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesUser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesUser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyboardAccelerator )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcKeyboardAccelerator Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyboardAccelerator )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcKeyboardAccelerator *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyboardPriority )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcKeyboardPriority Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyboardPriority )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcKeyboardPriority *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HyperlinkDisplayCursor )( 
            IGcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HyperlinkDisplayCursor )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HyperlinkDisplayTooltip )( 
            IGcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HyperlinkDisplayTooltip )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ADCInsertUnitsDefaultSource )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcInsertUnits pIU);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ADCInsertUnitsDefaultSource )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcInsertUnits *pIU);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ADCInsertUnitsDefaultTarget )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcInsertUnits pSUunits);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ADCInsertUnitsDefaultTarget )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcInsertUnits *pSUunits);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ShortCutMenuDisplay )( 
            IGcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortCutMenuDisplay )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMDefaultMode )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcDrawingAreaSCMDefault pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMDefaultMode )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcDrawingAreaSCMDefault *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMEditMode )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcDrawingAreaSCMEdit pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMEditMode )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcDrawingAreaSCMEdit *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMCommandMode )( 
            IGcadPreferencesUser * This,
            /* [in] */ GcDrawingAreaSCMCommand pSCM);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMCommandMode )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ GcDrawingAreaSCMCommand *pSCM);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMTimeMode )( 
            IGcadPreferencesUser * This,
            /* [in] */ VARIANT_BOOL time);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMTimeMode )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ VARIANT_BOOL *time);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SCMTimeValue )( 
            IGcadPreferencesUser * This,
            /* [in] */ int time);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SCMTimeValue )( 
            IGcadPreferencesUser * This,
            /* [retval][out] */ int *time);
        
        END_INTERFACE
    } IGcadPreferencesUserVtbl;

    interface IGcadPreferencesUser
    {
        CONST_VTBL struct IGcadPreferencesUserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesUser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesUser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesUser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesUser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesUser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesUser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesUser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesUser_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesUser_put_KeyboardAccelerator(This,Path)	\
    ( (This)->lpVtbl -> put_KeyboardAccelerator(This,Path) ) 

#define IGcadPreferencesUser_get_KeyboardAccelerator(This,Path)	\
    ( (This)->lpVtbl -> get_KeyboardAccelerator(This,Path) ) 

#define IGcadPreferencesUser_put_KeyboardPriority(This,Path)	\
    ( (This)->lpVtbl -> put_KeyboardPriority(This,Path) ) 

#define IGcadPreferencesUser_get_KeyboardPriority(This,Path)	\
    ( (This)->lpVtbl -> get_KeyboardPriority(This,Path) ) 

#define IGcadPreferencesUser_put_HyperlinkDisplayCursor(This,Path)	\
    ( (This)->lpVtbl -> put_HyperlinkDisplayCursor(This,Path) ) 

#define IGcadPreferencesUser_get_HyperlinkDisplayCursor(This,Path)	\
    ( (This)->lpVtbl -> get_HyperlinkDisplayCursor(This,Path) ) 

#define IGcadPreferencesUser_put_HyperlinkDisplayTooltip(This,Path)	\
    ( (This)->lpVtbl -> put_HyperlinkDisplayTooltip(This,Path) ) 

#define IGcadPreferencesUser_get_HyperlinkDisplayTooltip(This,Path)	\
    ( (This)->lpVtbl -> get_HyperlinkDisplayTooltip(This,Path) ) 

#define IGcadPreferencesUser_put_ADCInsertUnitsDefaultSource(This,pIU)	\
    ( (This)->lpVtbl -> put_ADCInsertUnitsDefaultSource(This,pIU) ) 

#define IGcadPreferencesUser_get_ADCInsertUnitsDefaultSource(This,pIU)	\
    ( (This)->lpVtbl -> get_ADCInsertUnitsDefaultSource(This,pIU) ) 

#define IGcadPreferencesUser_put_ADCInsertUnitsDefaultTarget(This,pSUunits)	\
    ( (This)->lpVtbl -> put_ADCInsertUnitsDefaultTarget(This,pSUunits) ) 

#define IGcadPreferencesUser_get_ADCInsertUnitsDefaultTarget(This,pSUunits)	\
    ( (This)->lpVtbl -> get_ADCInsertUnitsDefaultTarget(This,pSUunits) ) 

#define IGcadPreferencesUser_put_ShortCutMenuDisplay(This,pSCM)	\
    ( (This)->lpVtbl -> put_ShortCutMenuDisplay(This,pSCM) ) 

#define IGcadPreferencesUser_get_ShortCutMenuDisplay(This,pSCM)	\
    ( (This)->lpVtbl -> get_ShortCutMenuDisplay(This,pSCM) ) 

#define IGcadPreferencesUser_put_SCMDefaultMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMDefaultMode(This,pSCM) ) 

#define IGcadPreferencesUser_get_SCMDefaultMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMDefaultMode(This,pSCM) ) 

#define IGcadPreferencesUser_put_SCMEditMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMEditMode(This,pSCM) ) 

#define IGcadPreferencesUser_get_SCMEditMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMEditMode(This,pSCM) ) 

#define IGcadPreferencesUser_put_SCMCommandMode(This,pSCM)	\
    ( (This)->lpVtbl -> put_SCMCommandMode(This,pSCM) ) 

#define IGcadPreferencesUser_get_SCMCommandMode(This,pSCM)	\
    ( (This)->lpVtbl -> get_SCMCommandMode(This,pSCM) ) 

#define IGcadPreferencesUser_put_SCMTimeMode(This,time)	\
    ( (This)->lpVtbl -> put_SCMTimeMode(This,time) ) 

#define IGcadPreferencesUser_get_SCMTimeMode(This,time)	\
    ( (This)->lpVtbl -> get_SCMTimeMode(This,time) ) 

#define IGcadPreferencesUser_put_SCMTimeValue(This,time)	\
    ( (This)->lpVtbl -> put_SCMTimeValue(This,time) ) 

#define IGcadPreferencesUser_get_SCMTimeValue(This,time)	\
    ( (This)->lpVtbl -> get_SCMTimeValue(This,time) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesUser_INTERFACE_DEFINED__ */


#ifndef __IGcadPreferencesSelection_INTERFACE_DEFINED__
#define __IGcadPreferencesSelection_INTERFACE_DEFINED__

/* interface IGcadPreferencesSelection */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPreferencesSelection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CDCD600E-0299-4127-89C6-3C8FA33F7EBC")
    IGcadPreferencesSelection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickFirst( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickFirst( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickAdd( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickAdd( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickDrag( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickDrag( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickAuto( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickAuto( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickBoxSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickBoxSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayGrips( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayGrips( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DisplayGripsWithinBlocks( 
            /* [in] */ VARIANT_BOOL Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DisplayGripsWithinBlocks( 
            /* [retval][out] */ VARIANT_BOOL *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripColorSelected( 
            /* [in] */ GcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripColorSelected( 
            /* [retval][out] */ GcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripColorUnselected( 
            /* [in] */ GcColor Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripColorUnselected( 
            /* [retval][out] */ GcColor *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_GripSize( 
            /* [in] */ long Path) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_GripSize( 
            /* [retval][out] */ long *Path) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_PickGroup( 
            /* [in] */ VARIANT_BOOL pick) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PickGroup( 
            /* [retval][out] */ VARIANT_BOOL *pick) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPreferencesSelectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPreferencesSelection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPreferencesSelection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPreferencesSelection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPreferencesSelection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPreferencesSelection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPreferencesSelection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPreferencesSelection * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickFirst )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickFirst )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickAdd )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickAdd )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickDrag )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickDrag )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickAuto )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickAuto )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickBoxSize )( 
            IGcadPreferencesSelection * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickBoxSize )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayGrips )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayGrips )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_DisplayGripsWithinBlocks )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DisplayGripsWithinBlocks )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripColorSelected )( 
            IGcadPreferencesSelection * This,
            /* [in] */ GcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripColorSelected )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ GcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripColorUnselected )( 
            IGcadPreferencesSelection * This,
            /* [in] */ GcColor Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripColorUnselected )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ GcColor *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_GripSize )( 
            IGcadPreferencesSelection * This,
            /* [in] */ long Path);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_GripSize )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ long *Path);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PickGroup )( 
            IGcadPreferencesSelection * This,
            /* [in] */ VARIANT_BOOL pick);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PickGroup )( 
            IGcadPreferencesSelection * This,
            /* [retval][out] */ VARIANT_BOOL *pick);
        
        END_INTERFACE
    } IGcadPreferencesSelectionVtbl;

    interface IGcadPreferencesSelection
    {
        CONST_VTBL struct IGcadPreferencesSelectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPreferencesSelection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPreferencesSelection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPreferencesSelection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPreferencesSelection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPreferencesSelection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPreferencesSelection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPreferencesSelection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPreferencesSelection_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPreferencesSelection_put_PickFirst(This,Path)	\
    ( (This)->lpVtbl -> put_PickFirst(This,Path) ) 

#define IGcadPreferencesSelection_get_PickFirst(This,Path)	\
    ( (This)->lpVtbl -> get_PickFirst(This,Path) ) 

#define IGcadPreferencesSelection_put_PickAdd(This,Path)	\
    ( (This)->lpVtbl -> put_PickAdd(This,Path) ) 

#define IGcadPreferencesSelection_get_PickAdd(This,Path)	\
    ( (This)->lpVtbl -> get_PickAdd(This,Path) ) 

#define IGcadPreferencesSelection_put_PickDrag(This,Path)	\
    ( (This)->lpVtbl -> put_PickDrag(This,Path) ) 

#define IGcadPreferencesSelection_get_PickDrag(This,Path)	\
    ( (This)->lpVtbl -> get_PickDrag(This,Path) ) 

#define IGcadPreferencesSelection_put_PickAuto(This,Path)	\
    ( (This)->lpVtbl -> put_PickAuto(This,Path) ) 

#define IGcadPreferencesSelection_get_PickAuto(This,Path)	\
    ( (This)->lpVtbl -> get_PickAuto(This,Path) ) 

#define IGcadPreferencesSelection_put_PickBoxSize(This,Path)	\
    ( (This)->lpVtbl -> put_PickBoxSize(This,Path) ) 

#define IGcadPreferencesSelection_get_PickBoxSize(This,Path)	\
    ( (This)->lpVtbl -> get_PickBoxSize(This,Path) ) 

#define IGcadPreferencesSelection_put_DisplayGrips(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayGrips(This,Path) ) 

#define IGcadPreferencesSelection_get_DisplayGrips(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayGrips(This,Path) ) 

#define IGcadPreferencesSelection_put_DisplayGripsWithinBlocks(This,Path)	\
    ( (This)->lpVtbl -> put_DisplayGripsWithinBlocks(This,Path) ) 

#define IGcadPreferencesSelection_get_DisplayGripsWithinBlocks(This,Path)	\
    ( (This)->lpVtbl -> get_DisplayGripsWithinBlocks(This,Path) ) 

#define IGcadPreferencesSelection_put_GripColorSelected(This,Path)	\
    ( (This)->lpVtbl -> put_GripColorSelected(This,Path) ) 

#define IGcadPreferencesSelection_get_GripColorSelected(This,Path)	\
    ( (This)->lpVtbl -> get_GripColorSelected(This,Path) ) 

#define IGcadPreferencesSelection_put_GripColorUnselected(This,Path)	\
    ( (This)->lpVtbl -> put_GripColorUnselected(This,Path) ) 

#define IGcadPreferencesSelection_get_GripColorUnselected(This,Path)	\
    ( (This)->lpVtbl -> get_GripColorUnselected(This,Path) ) 

#define IGcadPreferencesSelection_put_GripSize(This,Path)	\
    ( (This)->lpVtbl -> put_GripSize(This,Path) ) 

#define IGcadPreferencesSelection_get_GripSize(This,Path)	\
    ( (This)->lpVtbl -> get_GripSize(This,Path) ) 

#define IGcadPreferencesSelection_put_PickGroup(This,pick)	\
    ( (This)->lpVtbl -> put_PickGroup(This,pick) ) 

#define IGcadPreferencesSelection_get_PickGroup(This,pick)	\
    ( (This)->lpVtbl -> get_PickGroup(This,pick) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPreferencesSelection_INTERFACE_DEFINED__ */


#ifndef __IGcadMenuGroup_INTERFACE_DEFINED__
#define __IGcadMenuGroup_INTERFACE_DEFINED__

/* interface IGcadMenuGroup */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadMenuGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72D027F2-CD79-4135-AE60-74FD0F8F595B")
    IGcadMenuGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadMenuGroups **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ GcMenuGroupType *menuType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_MenuFileName( 
            /* [retval][out] */ BSTR *Name) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Menus( 
            /* [retval][out] */ IGcadPopupMenus **pMenus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Toolbars( 
            /* [retval][out] */ IGcadToolbars **pToolbars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ GcMenuFileType MenuFileType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            /* [in] */ BSTR MenuFileName,
            /* [in] */ GcMenuFileType MenuFileType) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadMenuGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadMenuGroup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadMenuGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadMenuGroup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadMenuGroup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadMenuGroup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadMenuGroup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadMenuGroup * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ IGcadMenuGroups **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ GcMenuGroupType *menuType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MenuFileName )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ BSTR *Name);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Menus )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ IGcadPopupMenus **pMenus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Toolbars )( 
            IGcadMenuGroup * This,
            /* [retval][out] */ IGcadToolbars **pToolbars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unload )( 
            IGcadMenuGroup * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IGcadMenuGroup * This,
            /* [in] */ GcMenuFileType MenuFileType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IGcadMenuGroup * This,
            /* [in] */ BSTR MenuFileName,
            /* [in] */ GcMenuFileType MenuFileType);
        
        END_INTERFACE
    } IGcadMenuGroupVtbl;

    interface IGcadMenuGroup
    {
        CONST_VTBL struct IGcadMenuGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadMenuGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadMenuGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadMenuGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadMenuGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadMenuGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadMenuGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadMenuGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadMenuGroup_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadMenuGroup_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadMenuGroup_get_Name(This,Name)	\
    ( (This)->lpVtbl -> get_Name(This,Name) ) 

#define IGcadMenuGroup_get_Type(This,menuType)	\
    ( (This)->lpVtbl -> get_Type(This,menuType) ) 

#define IGcadMenuGroup_get_MenuFileName(This,Name)	\
    ( (This)->lpVtbl -> get_MenuFileName(This,Name) ) 

#define IGcadMenuGroup_get_Menus(This,pMenus)	\
    ( (This)->lpVtbl -> get_Menus(This,pMenus) ) 

#define IGcadMenuGroup_get_Toolbars(This,pToolbars)	\
    ( (This)->lpVtbl -> get_Toolbars(This,pToolbars) ) 

#define IGcadMenuGroup_Unload(This)	\
    ( (This)->lpVtbl -> Unload(This) ) 

#define IGcadMenuGroup_Save(This,MenuFileType)	\
    ( (This)->lpVtbl -> Save(This,MenuFileType) ) 

#define IGcadMenuGroup_SaveAs(This,MenuFileName,MenuFileType)	\
    ( (This)->lpVtbl -> SaveAs(This,MenuFileName,MenuFileType) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadMenuGroup_INTERFACE_DEFINED__ */


#ifndef __IGcadPopupMenus_INTERFACE_DEFINED__
#define __IGcadPopupMenus_INTERFACE_DEFINED__

/* interface IGcadPopupMenus */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPopupMenus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4B67342A-4DF3-450B-8E12-CF0A8B16DBC0")
    IGcadPopupMenus : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenu **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadMenuGroup **pParent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR MenuName,
            /* [retval][out] */ IGcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertMenuInMenuBar( 
            /* [in] */ BSTR MenuName,
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveMenuFromMenuBar( 
            /* [in] */ VARIANT Index) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPopupMenusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPopupMenus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPopupMenus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPopupMenus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPopupMenus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPopupMenus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPopupMenus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPopupMenus * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadPopupMenus * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenu **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadPopupMenus * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadPopupMenus * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPopupMenus * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadPopupMenus * This,
            /* [retval][out] */ IGcadMenuGroup **pParent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IGcadPopupMenus * This,
            /* [in] */ BSTR MenuName,
            /* [retval][out] */ IGcadPopupMenu **pMenu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertMenuInMenuBar )( 
            IGcadPopupMenus * This,
            /* [in] */ BSTR MenuName,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveMenuFromMenuBar )( 
            IGcadPopupMenus * This,
            /* [in] */ VARIANT Index);
        
        END_INTERFACE
    } IGcadPopupMenusVtbl;

    interface IGcadPopupMenus
    {
        CONST_VTBL struct IGcadPopupMenusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPopupMenus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPopupMenus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPopupMenus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPopupMenus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPopupMenus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPopupMenus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPopupMenus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPopupMenus_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadPopupMenus_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadPopupMenus_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadPopupMenus_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPopupMenus_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadPopupMenus_Add(This,MenuName,pMenu)	\
    ( (This)->lpVtbl -> Add(This,MenuName,pMenu) ) 

#define IGcadPopupMenus_InsertMenuInMenuBar(This,MenuName,Index)	\
    ( (This)->lpVtbl -> InsertMenuInMenuBar(This,MenuName,Index) ) 

#define IGcadPopupMenus_RemoveMenuFromMenuBar(This,Index)	\
    ( (This)->lpVtbl -> RemoveMenuFromMenuBar(This,Index) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPopupMenus_INTERFACE_DEFINED__ */


#ifndef __IGcadPopupMenu_INTERFACE_DEFINED__
#define __IGcadPopupMenu_INTERFACE_DEFINED__

/* interface IGcadPopupMenu */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPopupMenu;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("551A5349-4463-40E2-822C-D3A632409117")
    IGcadPopupMenu : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenuItem **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_NameNoMnemonic( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ShortcutMenu( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_OnMenuBar( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMenuItem( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [in] */ BSTR Macro,
            /* [retval][out] */ IGcadPopupMenuItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSubMenu( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [retval][out] */ IGcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSeparator( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenuItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertInMenuBar( 
            /* [in] */ VARIANT Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveFromMenuBar( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPopupMenuVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPopupMenu * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPopupMenu * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPopupMenu * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPopupMenu * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPopupMenu * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPopupMenu * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPopupMenu * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenuItem **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ IDispatch **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadPopupMenu * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_NameNoMnemonic )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ShortcutMenu )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_OnMenuBar )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMenuItem )( 
            IGcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [in] */ BSTR Macro,
            /* [retval][out] */ IGcadPopupMenuItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSubMenu )( 
            IGcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Label,
            /* [retval][out] */ IGcadPopupMenu **pMenu);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSeparator )( 
            IGcadPopupMenu * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenuItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertInMenuBar )( 
            IGcadPopupMenu * This,
            /* [in] */ VARIANT Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveFromMenuBar )( 
            IGcadPopupMenu * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IGcadPopupMenu * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        END_INTERFACE
    } IGcadPopupMenuVtbl;

    interface IGcadPopupMenu
    {
        CONST_VTBL struct IGcadPopupMenuVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPopupMenu_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPopupMenu_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPopupMenu_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPopupMenu_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPopupMenu_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPopupMenu_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPopupMenu_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPopupMenu_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadPopupMenu_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadPopupMenu_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadPopupMenu_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPopupMenu_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadPopupMenu_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IGcadPopupMenu_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IGcadPopupMenu_get_NameNoMnemonic(This,bstrName)	\
    ( (This)->lpVtbl -> get_NameNoMnemonic(This,bstrName) ) 

#define IGcadPopupMenu_get_ShortcutMenu(This,bFlag)	\
    ( (This)->lpVtbl -> get_ShortcutMenu(This,bFlag) ) 

#define IGcadPopupMenu_get_OnMenuBar(This,bFlag)	\
    ( (This)->lpVtbl -> get_OnMenuBar(This,bFlag) ) 

#define IGcadPopupMenu_AddMenuItem(This,Index,Label,Macro,pItem)	\
    ( (This)->lpVtbl -> AddMenuItem(This,Index,Label,Macro,pItem) ) 

#define IGcadPopupMenu_AddSubMenu(This,Index,Label,pMenu)	\
    ( (This)->lpVtbl -> AddSubMenu(This,Index,Label,pMenu) ) 

#define IGcadPopupMenu_AddSeparator(This,Index,pItem)	\
    ( (This)->lpVtbl -> AddSeparator(This,Index,pItem) ) 

#define IGcadPopupMenu_InsertInMenuBar(This,Index)	\
    ( (This)->lpVtbl -> InsertInMenuBar(This,Index) ) 

#define IGcadPopupMenu_RemoveFromMenuBar(This)	\
    ( (This)->lpVtbl -> RemoveFromMenuBar(This) ) 

#define IGcadPopupMenu_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPopupMenu_INTERFACE_DEFINED__ */


#ifndef __IGcadPopupMenuItem_INTERFACE_DEFINED__
#define __IGcadPopupMenuItem_INTERFACE_DEFINED__

/* interface IGcadPopupMenuItem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadPopupMenuItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E00012D-0862-428C-B675-A88781D31934")
    IGcadPopupMenuItem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadPopupMenu **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Label( 
            /* [retval][out] */ BSTR *bstrLabel) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Label( 
            /* [in] */ BSTR bstrLabel) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TagString( 
            /* [in] */ BSTR bstrTag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Enable( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Enable( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Check( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Check( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ GcMenuItemType *itemType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SubMenu( 
            /* [retval][out] */ IGcadPopupMenu **pMenu) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Macro( 
            /* [retval][out] */ BSTR *bstrMacro) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Macro( 
            /* [in] */ BSTR bstrMacro) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nIndex) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *bstrCaption) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EndSubMenuLevel( 
            /* [retval][out] */ int *Level) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EndSubMenuLevel( 
            /* [in] */ int Level) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadPopupMenuItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadPopupMenuItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadPopupMenuItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadPopupMenuItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadPopupMenuItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadPopupMenuItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadPopupMenuItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadPopupMenuItem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ IGcadPopupMenu **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Label )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrLabel);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Label )( 
            IGcadPopupMenuItem * This,
            /* [in] */ BSTR bstrLabel);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TagString )( 
            IGcadPopupMenuItem * This,
            /* [in] */ BSTR bstrTag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Enable )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Enable )( 
            IGcadPopupMenuItem * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Check )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Check )( 
            IGcadPopupMenuItem * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ GcMenuItemType *itemType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SubMenu )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ IGcadPopupMenu **pMenu);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Macro )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrMacro);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Macro )( 
            IGcadPopupMenuItem * This,
            /* [in] */ BSTR bstrMacro);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ int *nIndex);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrCaption);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IGcadPopupMenuItem * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadPopupMenuItem * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndSubMenuLevel )( 
            IGcadPopupMenuItem * This,
            /* [retval][out] */ int *Level);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_EndSubMenuLevel )( 
            IGcadPopupMenuItem * This,
            /* [in] */ int Level);
        
        END_INTERFACE
    } IGcadPopupMenuItemVtbl;

    interface IGcadPopupMenuItem
    {
        CONST_VTBL struct IGcadPopupMenuItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadPopupMenuItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadPopupMenuItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadPopupMenuItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadPopupMenuItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadPopupMenuItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadPopupMenuItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadPopupMenuItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadPopupMenuItem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadPopupMenuItem_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadPopupMenuItem_get_Label(This,bstrLabel)	\
    ( (This)->lpVtbl -> get_Label(This,bstrLabel) ) 

#define IGcadPopupMenuItem_put_Label(This,bstrLabel)	\
    ( (This)->lpVtbl -> put_Label(This,bstrLabel) ) 

#define IGcadPopupMenuItem_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#define IGcadPopupMenuItem_put_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> put_TagString(This,bstrTag) ) 

#define IGcadPopupMenuItem_get_Enable(This,bFlag)	\
    ( (This)->lpVtbl -> get_Enable(This,bFlag) ) 

#define IGcadPopupMenuItem_put_Enable(This,bFlag)	\
    ( (This)->lpVtbl -> put_Enable(This,bFlag) ) 

#define IGcadPopupMenuItem_get_Check(This,bFlag)	\
    ( (This)->lpVtbl -> get_Check(This,bFlag) ) 

#define IGcadPopupMenuItem_put_Check(This,bFlag)	\
    ( (This)->lpVtbl -> put_Check(This,bFlag) ) 

#define IGcadPopupMenuItem_get_Type(This,itemType)	\
    ( (This)->lpVtbl -> get_Type(This,itemType) ) 

#define IGcadPopupMenuItem_get_SubMenu(This,pMenu)	\
    ( (This)->lpVtbl -> get_SubMenu(This,pMenu) ) 

#define IGcadPopupMenuItem_get_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> get_Macro(This,bstrMacro) ) 

#define IGcadPopupMenuItem_put_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> put_Macro(This,bstrMacro) ) 

#define IGcadPopupMenuItem_get_Index(This,nIndex)	\
    ( (This)->lpVtbl -> get_Index(This,nIndex) ) 

#define IGcadPopupMenuItem_get_Caption(This,bstrCaption)	\
    ( (This)->lpVtbl -> get_Caption(This,bstrCaption) ) 

#define IGcadPopupMenuItem_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IGcadPopupMenuItem_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IGcadPopupMenuItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadPopupMenuItem_get_EndSubMenuLevel(This,Level)	\
    ( (This)->lpVtbl -> get_EndSubMenuLevel(This,Level) ) 

#define IGcadPopupMenuItem_put_EndSubMenuLevel(This,Level)	\
    ( (This)->lpVtbl -> put_EndSubMenuLevel(This,Level) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadPopupMenuItem_INTERFACE_DEFINED__ */


#ifndef __IGcadToolbars_INTERFACE_DEFINED__
#define __IGcadToolbars_INTERFACE_DEFINED__

/* interface IGcadToolbars */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadToolbars;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8095E3AB-7AB4-4915-A35A-11491F1B45D6")
    IGcadToolbars : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbar **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadMenuGroup **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LargeButtons( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_LargeButtons( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR ToolbarName,
            /* [retval][out] */ IGcadToolbar **pTlbar) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadToolbarsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadToolbars * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadToolbars * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadToolbars * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadToolbars * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadToolbars * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadToolbars * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadToolbars * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadToolbars * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbar **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadToolbars * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadToolbars * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadToolbars * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadToolbars * This,
            /* [retval][out] */ IGcadMenuGroup **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LargeButtons )( 
            IGcadToolbars * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LargeButtons )( 
            IGcadToolbars * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IGcadToolbars * This,
            /* [in] */ BSTR ToolbarName,
            /* [retval][out] */ IGcadToolbar **pTlbar);
        
        END_INTERFACE
    } IGcadToolbarsVtbl;

    interface IGcadToolbars
    {
        CONST_VTBL struct IGcadToolbarsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadToolbars_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadToolbars_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadToolbars_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadToolbars_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadToolbars_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadToolbars_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadToolbars_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadToolbars_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadToolbars_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadToolbars_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadToolbars_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadToolbars_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadToolbars_get_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> get_LargeButtons(This,bFlag) ) 

#define IGcadToolbars_put_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> put_LargeButtons(This,bFlag) ) 

#define IGcadToolbars_Add(This,ToolbarName,pTlbar)	\
    ( (This)->lpVtbl -> Add(This,ToolbarName,pTlbar) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadToolbars_INTERFACE_DEFINED__ */


#ifndef __IGcadToolbar_INTERFACE_DEFINED__
#define __IGcadToolbar_INTERFACE_DEFINED__

/* interface IGcadToolbar */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadToolbar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EDE9142E-0923-4657-90F7-EB55FC56C99A")
    IGcadToolbar : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbarItem **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IDispatch **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ VARIANT_BOOL bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DockStatus( 
            /* [retval][out] */ GcToolbarDockStatus *nStatus) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_LargeButtons( 
            /* [retval][out] */ VARIANT_BOOL *bFlag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_left( 
            /* [retval][out] */ int *nLeft) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_left( 
            /* [in] */ int nLeft) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_top( 
            /* [retval][out] */ int *nTop) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_top( 
            /* [in] */ int nTop) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ int *nWidth) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ int *nHeight) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FloatingRows( 
            /* [retval][out] */ int *nRows) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FloatingRows( 
            /* [in] */ int nRows) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddToolbarButton( 
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR HelpString,
            /* [in] */ BSTR Macro,
            /* [optional][in] */ VARIANT FlyoutButton,
            /* [retval][out] */ IGcadToolbarItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSeparator( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbarItem **pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Dock( 
            /* [in] */ GcToolbarDockStatus Side) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Float( 
            /* [in] */ int top,
            /* [in] */ int left,
            /* [in] */ int NumberFloatRows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadToolbarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadToolbar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadToolbar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadToolbar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadToolbar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadToolbar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadToolbar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadToolbar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbarItem **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadToolbar * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadToolbar * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadToolbar * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadToolbar * This,
            /* [retval][out] */ IDispatch **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadToolbar * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadToolbar * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IGcadToolbar * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IGcadToolbar * This,
            /* [in] */ VARIANT_BOOL bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DockStatus )( 
            IGcadToolbar * This,
            /* [retval][out] */ GcToolbarDockStatus *nStatus);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LargeButtons )( 
            IGcadToolbar * This,
            /* [retval][out] */ VARIANT_BOOL *bFlag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_left )( 
            IGcadToolbar * This,
            /* [retval][out] */ int *nLeft);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_left )( 
            IGcadToolbar * This,
            /* [in] */ int nLeft);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_top )( 
            IGcadToolbar * This,
            /* [retval][out] */ int *nTop);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_top )( 
            IGcadToolbar * This,
            /* [in] */ int nTop);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IGcadToolbar * This,
            /* [retval][out] */ int *nWidth);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IGcadToolbar * This,
            /* [retval][out] */ int *nHeight);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_FloatingRows )( 
            IGcadToolbar * This,
            /* [retval][out] */ int *nRows);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_FloatingRows )( 
            IGcadToolbar * This,
            /* [in] */ int nRows);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IGcadToolbar * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IGcadToolbar * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddToolbarButton )( 
            IGcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [in] */ BSTR Name,
            /* [in] */ BSTR HelpString,
            /* [in] */ BSTR Macro,
            /* [optional][in] */ VARIANT FlyoutButton,
            /* [retval][out] */ IGcadToolbarItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddSeparator )( 
            IGcadToolbar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadToolbarItem **pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Dock )( 
            IGcadToolbar * This,
            /* [in] */ GcToolbarDockStatus Side);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Float )( 
            IGcadToolbar * This,
            /* [in] */ int top,
            /* [in] */ int left,
            /* [in] */ int NumberFloatRows);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadToolbar * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IGcadToolbar * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        END_INTERFACE
    } IGcadToolbarVtbl;

    interface IGcadToolbar
    {
        CONST_VTBL struct IGcadToolbarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadToolbar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadToolbar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadToolbar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadToolbar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadToolbar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadToolbar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadToolbar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadToolbar_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadToolbar_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadToolbar_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadToolbar_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadToolbar_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadToolbar_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IGcadToolbar_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IGcadToolbar_get_Visible(This,bFlag)	\
    ( (This)->lpVtbl -> get_Visible(This,bFlag) ) 

#define IGcadToolbar_put_Visible(This,bFlag)	\
    ( (This)->lpVtbl -> put_Visible(This,bFlag) ) 

#define IGcadToolbar_get_DockStatus(This,nStatus)	\
    ( (This)->lpVtbl -> get_DockStatus(This,nStatus) ) 

#define IGcadToolbar_get_LargeButtons(This,bFlag)	\
    ( (This)->lpVtbl -> get_LargeButtons(This,bFlag) ) 

#define IGcadToolbar_get_left(This,nLeft)	\
    ( (This)->lpVtbl -> get_left(This,nLeft) ) 

#define IGcadToolbar_put_left(This,nLeft)	\
    ( (This)->lpVtbl -> put_left(This,nLeft) ) 

#define IGcadToolbar_get_top(This,nTop)	\
    ( (This)->lpVtbl -> get_top(This,nTop) ) 

#define IGcadToolbar_put_top(This,nTop)	\
    ( (This)->lpVtbl -> put_top(This,nTop) ) 

#define IGcadToolbar_get_Width(This,nWidth)	\
    ( (This)->lpVtbl -> get_Width(This,nWidth) ) 

#define IGcadToolbar_get_Height(This,nHeight)	\
    ( (This)->lpVtbl -> get_Height(This,nHeight) ) 

#define IGcadToolbar_get_FloatingRows(This,nRows)	\
    ( (This)->lpVtbl -> get_FloatingRows(This,nRows) ) 

#define IGcadToolbar_put_FloatingRows(This,nRows)	\
    ( (This)->lpVtbl -> put_FloatingRows(This,nRows) ) 

#define IGcadToolbar_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IGcadToolbar_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IGcadToolbar_AddToolbarButton(This,Index,Name,HelpString,Macro,FlyoutButton,pItem)	\
    ( (This)->lpVtbl -> AddToolbarButton(This,Index,Name,HelpString,Macro,FlyoutButton,pItem) ) 

#define IGcadToolbar_AddSeparator(This,Index,pItem)	\
    ( (This)->lpVtbl -> AddSeparator(This,Index,pItem) ) 

#define IGcadToolbar_Dock(This,Side)	\
    ( (This)->lpVtbl -> Dock(This,Side) ) 

#define IGcadToolbar_Float(This,top,left,NumberFloatRows)	\
    ( (This)->lpVtbl -> Float(This,top,left,NumberFloatRows) ) 

#define IGcadToolbar_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadToolbar_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadToolbar_INTERFACE_DEFINED__ */


#ifndef __IGcadToolbarItem_INTERFACE_DEFINED__
#define __IGcadToolbarItem_INTERFACE_DEFINED__

/* interface IGcadToolbarItem */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadToolbarItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72E4902E-AA1A-4F5D-8995-B06088CF363C")
    IGcadToolbarItem : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadToolbar **pParent) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *bstrName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TagString( 
            /* [retval][out] */ BSTR *bstrTag) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TagString( 
            /* [in] */ BSTR bstrTag) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ GcToolbarItemType *itemType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Flyout( 
            /* [retval][out] */ IGcadToolbar **pTlbar) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Macro( 
            /* [retval][out] */ BSTR *bstrMacro) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Macro( 
            /* [in] */ BSTR bstrMacro) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Index( 
            /* [retval][out] */ int *nIndex) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_HelpString( 
            /* [retval][out] */ BSTR *bstrHelp) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_HelpString( 
            /* [in] */ BSTR bstrHelp) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBitmaps( 
            /* [out] */ BSTR *SmallIconName,
            /* [out] */ BSTR *LargeIconName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBitmaps( 
            /* [in] */ BSTR SmallIconName,
            /* [in] */ BSTR LargeIconName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AttachToolbarToFlyout( 
            /* [in] */ BSTR MenuGroupName,
            /* [in] */ BSTR ToolbarName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_CommandDisplayName( 
            /* [retval][out] */ BSTR *bstrCmdDisName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_CommandDisplayName( 
            /* [in] */ BSTR bstrCmdDisName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadToolbarItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadToolbarItem * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadToolbarItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadToolbarItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadToolbarItem * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadToolbarItem * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadToolbarItem * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadToolbarItem * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ IGcadToolbar **pParent);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR bstrName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TagString )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrTag);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TagString )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR bstrTag);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ GcToolbarItemType *itemType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Flyout )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ IGcadToolbar **pTlbar);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Macro )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrMacro);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Macro )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR bstrMacro);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Index )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ int *nIndex);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_HelpString )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrHelp);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_HelpString )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR bstrHelp);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBitmaps )( 
            IGcadToolbarItem * This,
            /* [out] */ BSTR *SmallIconName,
            /* [out] */ BSTR *LargeIconName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBitmaps )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR SmallIconName,
            /* [in] */ BSTR LargeIconName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AttachToolbarToFlyout )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR MenuGroupName,
            /* [in] */ BSTR ToolbarName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadToolbarItem * This);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CommandDisplayName )( 
            IGcadToolbarItem * This,
            /* [retval][out] */ BSTR *bstrCmdDisName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CommandDisplayName )( 
            IGcadToolbarItem * This,
            /* [in] */ BSTR bstrCmdDisName);
        
        END_INTERFACE
    } IGcadToolbarItemVtbl;

    interface IGcadToolbarItem
    {
        CONST_VTBL struct IGcadToolbarItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadToolbarItem_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadToolbarItem_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadToolbarItem_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadToolbarItem_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadToolbarItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadToolbarItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadToolbarItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadToolbarItem_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadToolbarItem_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#define IGcadToolbarItem_get_Name(This,bstrName)	\
    ( (This)->lpVtbl -> get_Name(This,bstrName) ) 

#define IGcadToolbarItem_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define IGcadToolbarItem_get_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> get_TagString(This,bstrTag) ) 

#define IGcadToolbarItem_put_TagString(This,bstrTag)	\
    ( (This)->lpVtbl -> put_TagString(This,bstrTag) ) 

#define IGcadToolbarItem_get_Type(This,itemType)	\
    ( (This)->lpVtbl -> get_Type(This,itemType) ) 

#define IGcadToolbarItem_get_Flyout(This,pTlbar)	\
    ( (This)->lpVtbl -> get_Flyout(This,pTlbar) ) 

#define IGcadToolbarItem_get_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> get_Macro(This,bstrMacro) ) 

#define IGcadToolbarItem_put_Macro(This,bstrMacro)	\
    ( (This)->lpVtbl -> put_Macro(This,bstrMacro) ) 

#define IGcadToolbarItem_get_Index(This,nIndex)	\
    ( (This)->lpVtbl -> get_Index(This,nIndex) ) 

#define IGcadToolbarItem_get_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> get_HelpString(This,bstrHelp) ) 

#define IGcadToolbarItem_put_HelpString(This,bstrHelp)	\
    ( (This)->lpVtbl -> put_HelpString(This,bstrHelp) ) 

#define IGcadToolbarItem_GetBitmaps(This,SmallIconName,LargeIconName)	\
    ( (This)->lpVtbl -> GetBitmaps(This,SmallIconName,LargeIconName) ) 

#define IGcadToolbarItem_SetBitmaps(This,SmallIconName,LargeIconName)	\
    ( (This)->lpVtbl -> SetBitmaps(This,SmallIconName,LargeIconName) ) 

#define IGcadToolbarItem_AttachToolbarToFlyout(This,MenuGroupName,ToolbarName)	\
    ( (This)->lpVtbl -> AttachToolbarToFlyout(This,MenuGroupName,ToolbarName) ) 

#define IGcadToolbarItem_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IGcadToolbarItem_get_CommandDisplayName(This,bstrCmdDisName)	\
    ( (This)->lpVtbl -> get_CommandDisplayName(This,bstrCmdDisName) ) 

#define IGcadToolbarItem_put_CommandDisplayName(This,bstrCmdDisName)	\
    ( (This)->lpVtbl -> put_CommandDisplayName(This,bstrCmdDisName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadToolbarItem_INTERFACE_DEFINED__ */


#ifndef __IGcadMenuBar_INTERFACE_DEFINED__
#define __IGcadMenuBar_INTERFACE_DEFINED__

/* interface IGcadMenuBar */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadMenuBar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87925C1E-ADEA-48BD-8BF1-239F9A116A81")
    IGcadMenuBar : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenu **pItem) = 0;
        
        virtual /* [hidden][restricted][propget][id] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **pEnumVariant) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *Count) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Application( 
            /* [retval][out] */ IGcadApplication **pAppObj) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ IGcadApplication **pParent) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadMenuBarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadMenuBar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadMenuBar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadMenuBar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadMenuBar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadMenuBar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadMenuBar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadMenuBar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IGcadMenuBar * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ IGcadPopupMenu **pItem);
        
        /* [hidden][restricted][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IGcadMenuBar * This,
            /* [retval][out] */ IUnknown **pEnumVariant);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IGcadMenuBar * This,
            /* [retval][out] */ long *Count);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Application )( 
            IGcadMenuBar * This,
            /* [retval][out] */ IGcadApplication **pAppObj);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            IGcadMenuBar * This,
            /* [retval][out] */ IGcadApplication **pParent);
        
        END_INTERFACE
    } IGcadMenuBarVtbl;

    interface IGcadMenuBar
    {
        CONST_VTBL struct IGcadMenuBarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadMenuBar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadMenuBar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadMenuBar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadMenuBar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadMenuBar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadMenuBar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadMenuBar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadMenuBar_Item(This,Index,pItem)	\
    ( (This)->lpVtbl -> Item(This,Index,pItem) ) 

#define IGcadMenuBar_get__NewEnum(This,pEnumVariant)	\
    ( (This)->lpVtbl -> get__NewEnum(This,pEnumVariant) ) 

#define IGcadMenuBar_get_Count(This,Count)	\
    ( (This)->lpVtbl -> get_Count(This,Count) ) 

#define IGcadMenuBar_get_Application(This,pAppObj)	\
    ( (This)->lpVtbl -> get_Application(This,pAppObj) ) 

#define IGcadMenuBar_get_Parent(This,pParent)	\
    ( (This)->lpVtbl -> get_Parent(This,pParent) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadMenuBar_INTERFACE_DEFINED__ */


#ifndef __IGcadSecurityParams_INTERFACE_DEFINED__
#define __IGcadSecurityParams_INTERFACE_DEFINED__

/* interface IGcadSecurityParams */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadSecurityParams;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("876889C6-F5DB-46F9-97AE-70DEFDF0DE9C")
    IGcadSecurityParams : public IDispatch
    {
    public:
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Action( 
            /* [in] */ long pOperations) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Action( 
            /* [retval][out] */ long *pOperations) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR pSecret) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pSecret) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProviderType( 
            /* [in] */ long pProvType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProviderType( 
            /* [retval][out] */ long *pProvType) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ProviderName( 
            /* [in] */ BSTR pProvName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ProviderName( 
            /* [retval][out] */ BSTR *pProvName) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Algorithm( 
            /* [in] */ long pAlgId) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Algorithm( 
            /* [retval][out] */ long *pAlgId) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_KeyLength( 
            /* [in] */ long pKeyLen) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_KeyLength( 
            /* [retval][out] */ long *pKeyLen) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR pCertSubject) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pCertSubject) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Issuer( 
            /* [in] */ BSTR pCertIssuer) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Issuer( 
            /* [retval][out] */ BSTR *pCertIssuer) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SerialNumber( 
            /* [in] */ BSTR pSerialNum) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SerialNumber( 
            /* [retval][out] */ BSTR *pSerialNum) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Comment( 
            /* [in] */ BSTR pText) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Comment( 
            /* [retval][out] */ BSTR *pText) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_TimeServer( 
            /* [in] */ BSTR pTimeServerName) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TimeServer( 
            /* [retval][out] */ BSTR *pTimeServerName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadSecurityParamsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadSecurityParams * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadSecurityParams * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadSecurityParams * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadSecurityParams * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadSecurityParams * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadSecurityParams * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadSecurityParams * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Action )( 
            IGcadSecurityParams * This,
            /* [in] */ long pOperations);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Action )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ long *pOperations);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pSecret);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pSecret);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProviderType )( 
            IGcadSecurityParams * This,
            /* [in] */ long pProvType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderType )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ long *pProvType);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_ProviderName )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pProvName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ProviderName )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pProvName);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Algorithm )( 
            IGcadSecurityParams * This,
            /* [in] */ long pAlgId);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Algorithm )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ long *pAlgId);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_KeyLength )( 
            IGcadSecurityParams * This,
            /* [in] */ long pKeyLen);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_KeyLength )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ long *pKeyLen);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pCertSubject);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pCertSubject);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Issuer )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pCertIssuer);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Issuer )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pCertIssuer);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SerialNumber )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pSerialNum);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SerialNumber )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pSerialNum);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Comment )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pText);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Comment )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pText);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_TimeServer )( 
            IGcadSecurityParams * This,
            /* [in] */ BSTR pTimeServerName);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TimeServer )( 
            IGcadSecurityParams * This,
            /* [retval][out] */ BSTR *pTimeServerName);
        
        END_INTERFACE
    } IGcadSecurityParamsVtbl;

    interface IGcadSecurityParams
    {
        CONST_VTBL struct IGcadSecurityParamsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadSecurityParams_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadSecurityParams_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadSecurityParams_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadSecurityParams_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadSecurityParams_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadSecurityParams_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadSecurityParams_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadSecurityParams_put_Action(This,pOperations)	\
    ( (This)->lpVtbl -> put_Action(This,pOperations) ) 

#define IGcadSecurityParams_get_Action(This,pOperations)	\
    ( (This)->lpVtbl -> get_Action(This,pOperations) ) 

#define IGcadSecurityParams_put_Password(This,pSecret)	\
    ( (This)->lpVtbl -> put_Password(This,pSecret) ) 

#define IGcadSecurityParams_get_Password(This,pSecret)	\
    ( (This)->lpVtbl -> get_Password(This,pSecret) ) 

#define IGcadSecurityParams_put_ProviderType(This,pProvType)	\
    ( (This)->lpVtbl -> put_ProviderType(This,pProvType) ) 

#define IGcadSecurityParams_get_ProviderType(This,pProvType)	\
    ( (This)->lpVtbl -> get_ProviderType(This,pProvType) ) 

#define IGcadSecurityParams_put_ProviderName(This,pProvName)	\
    ( (This)->lpVtbl -> put_ProviderName(This,pProvName) ) 

#define IGcadSecurityParams_get_ProviderName(This,pProvName)	\
    ( (This)->lpVtbl -> get_ProviderName(This,pProvName) ) 

#define IGcadSecurityParams_put_Algorithm(This,pAlgId)	\
    ( (This)->lpVtbl -> put_Algorithm(This,pAlgId) ) 

#define IGcadSecurityParams_get_Algorithm(This,pAlgId)	\
    ( (This)->lpVtbl -> get_Algorithm(This,pAlgId) ) 

#define IGcadSecurityParams_put_KeyLength(This,pKeyLen)	\
    ( (This)->lpVtbl -> put_KeyLength(This,pKeyLen) ) 

#define IGcadSecurityParams_get_KeyLength(This,pKeyLen)	\
    ( (This)->lpVtbl -> get_KeyLength(This,pKeyLen) ) 

#define IGcadSecurityParams_put_Subject(This,pCertSubject)	\
    ( (This)->lpVtbl -> put_Subject(This,pCertSubject) ) 

#define IGcadSecurityParams_get_Subject(This,pCertSubject)	\
    ( (This)->lpVtbl -> get_Subject(This,pCertSubject) ) 

#define IGcadSecurityParams_put_Issuer(This,pCertIssuer)	\
    ( (This)->lpVtbl -> put_Issuer(This,pCertIssuer) ) 

#define IGcadSecurityParams_get_Issuer(This,pCertIssuer)	\
    ( (This)->lpVtbl -> get_Issuer(This,pCertIssuer) ) 

#define IGcadSecurityParams_put_SerialNumber(This,pSerialNum)	\
    ( (This)->lpVtbl -> put_SerialNumber(This,pSerialNum) ) 

#define IGcadSecurityParams_get_SerialNumber(This,pSerialNum)	\
    ( (This)->lpVtbl -> get_SerialNumber(This,pSerialNum) ) 

#define IGcadSecurityParams_put_Comment(This,pText)	\
    ( (This)->lpVtbl -> put_Comment(This,pText) ) 

#define IGcadSecurityParams_get_Comment(This,pText)	\
    ( (This)->lpVtbl -> get_Comment(This,pText) ) 

#define IGcadSecurityParams_put_TimeServer(This,pTimeServerName)	\
    ( (This)->lpVtbl -> put_TimeServer(This,pTimeServerName) ) 

#define IGcadSecurityParams_get_TimeServer(This,pTimeServerName)	\
    ( (This)->lpVtbl -> get_TimeServer(This,pTimeServerName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadSecurityParams_INTERFACE_DEFINED__ */


#ifndef __IGcadScriptJet_INTERFACE_DEFINED__
#define __IGcadScriptJet_INTERFACE_DEFINED__

/* interface IGcadScriptJet */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IGcadScriptJet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BBD85F2-FBE1-414E-8A89-76379B9E2E4B")
    IGcadScriptJet : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParseScriptText_E( 
            /* [in] */ BSTR pstrCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Create( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddNamedItem( 
            /* [in] */ BSTR pstrCode,
            /* [defaultvalue][in] */ DWORD dwFlags = 6) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddVariant( 
            /* [in] */ BSTR varName,
            /* [in] */ VARIANT var) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariant( 
            /* [in] */ BSTR varName,
            /* [retval][out] */ VARIANT *value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadScriptJetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadScriptJet * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadScriptJet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadScriptJet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadScriptJet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadScriptJet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadScriptJet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadScriptJet * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParseScriptText_E )( 
            IGcadScriptJet * This,
            /* [in] */ BSTR pstrCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Create )( 
            IGcadScriptJet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            IGcadScriptJet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IGcadScriptJet * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddNamedItem )( 
            IGcadScriptJet * This,
            /* [in] */ BSTR pstrCode,
            /* [defaultvalue][in] */ DWORD dwFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddVariant )( 
            IGcadScriptJet * This,
            /* [in] */ BSTR varName,
            /* [in] */ VARIANT var);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariant )( 
            IGcadScriptJet * This,
            /* [in] */ BSTR varName,
            /* [retval][out] */ VARIANT *value);
        
        END_INTERFACE
    } IGcadScriptJetVtbl;

    interface IGcadScriptJet
    {
        CONST_VTBL struct IGcadScriptJetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadScriptJet_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadScriptJet_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadScriptJet_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadScriptJet_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadScriptJet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadScriptJet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadScriptJet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadScriptJet_ParseScriptText_E(This,pstrCode)	\
    ( (This)->lpVtbl -> ParseScriptText_E(This,pstrCode) ) 

#define IGcadScriptJet_Create(This)	\
    ( (This)->lpVtbl -> Create(This) ) 

#define IGcadScriptJet_Run(This)	\
    ( (This)->lpVtbl -> Run(This) ) 

#define IGcadScriptJet_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IGcadScriptJet_AddNamedItem(This,pstrCode,dwFlags)	\
    ( (This)->lpVtbl -> AddNamedItem(This,pstrCode,dwFlags) ) 

#define IGcadScriptJet_AddVariant(This,varName,var)	\
    ( (This)->lpVtbl -> AddVariant(This,varName,var) ) 

#define IGcadScriptJet_GetVariant(This,varName,value)	\
    ( (This)->lpVtbl -> GetVariant(This,varName,value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadScriptJet_INTERFACE_DEFINED__ */


#ifndef __IGcadLayerStateManager_INTERFACE_DEFINED__
#define __IGcadLayerStateManager_INTERFACE_DEFINED__

/* interface IGcadLayerStateManager */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IGcadLayerStateManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DAD7AF45-FA46-4052-BA56-F209379367B8")
    IGcadLayerStateManager : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDatabase( 
            /* [in] */ IGcadDatabase *iHostDb) = 0;
        
        virtual /* [helpcontext][helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Mask( 
            /* [in] */ BSTR bsName,
            /* [in] */ GcLayerStateMask eMask) = 0;
        
        virtual /* [helpcontext][helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Mask( 
            /* [in] */ BSTR bsName,
            /* [retval][out] */ GcLayerStateMask *eMask) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR bsName,
            /* [in] */ GcLayerStateMask eMask) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Restore( 
            /* [in] */ BSTR bsName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ BSTR bsName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsNewName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Import( 
            /* [in] */ BSTR bsFilename) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Export( 
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsFilename) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IGcadLayerStateManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IGcadLayerStateManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IGcadLayerStateManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IGcadLayerStateManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IGcadLayerStateManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IGcadLayerStateManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IGcadLayerStateManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IGcadLayerStateManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDatabase )( 
            IGcadLayerStateManager * This,
            /* [in] */ IGcadDatabase *iHostDb);
        
        /* [helpcontext][helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Mask )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ GcLayerStateMask eMask);
        
        /* [helpcontext][helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Mask )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [retval][out] */ GcLayerStateMask *eMask);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ GcLayerStateMask eMask);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rename )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsNewName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Import )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsFilename);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Export )( 
            IGcadLayerStateManager * This,
            /* [in] */ BSTR bsName,
            /* [in] */ BSTR bsFilename);
        
        END_INTERFACE
    } IGcadLayerStateManagerVtbl;

    interface IGcadLayerStateManager
    {
        CONST_VTBL struct IGcadLayerStateManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGcadLayerStateManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IGcadLayerStateManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IGcadLayerStateManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IGcadLayerStateManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IGcadLayerStateManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IGcadLayerStateManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IGcadLayerStateManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IGcadLayerStateManager_SetDatabase(This,iHostDb)	\
    ( (This)->lpVtbl -> SetDatabase(This,iHostDb) ) 

#define IGcadLayerStateManager_put_Mask(This,bsName,eMask)	\
    ( (This)->lpVtbl -> put_Mask(This,bsName,eMask) ) 

#define IGcadLayerStateManager_get_Mask(This,bsName,eMask)	\
    ( (This)->lpVtbl -> get_Mask(This,bsName,eMask) ) 

#define IGcadLayerStateManager_Save(This,bsName,eMask)	\
    ( (This)->lpVtbl -> Save(This,bsName,eMask) ) 

#define IGcadLayerStateManager_Restore(This,bsName)	\
    ( (This)->lpVtbl -> Restore(This,bsName) ) 

#define IGcadLayerStateManager_Delete(This,bsName)	\
    ( (This)->lpVtbl -> Delete(This,bsName) ) 

#define IGcadLayerStateManager_Rename(This,bsName,bsNewName)	\
    ( (This)->lpVtbl -> Rename(This,bsName,bsNewName) ) 

#define IGcadLayerStateManager_Import(This,bsFilename)	\
    ( (This)->lpVtbl -> Import(This,bsFilename) ) 

#define IGcadLayerStateManager_Export(This,bsName,bsFilename)	\
    ( (This)->lpVtbl -> Export(This,bsName,bsFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IGcadLayerStateManager_INTERFACE_DEFINED__ */



#ifndef __GcadVbaLib_LIBRARY_DEFINED__
#define __GcadVbaLib_LIBRARY_DEFINED__

/* library GcadVbaLib */
/* [helpstring][lcid][version][uuid] */ 

typedef /* [public][uuid] */  DECLSPEC_UUID("F4720841-0C0A-4094-B6C5-1135246B9633") BSTR GCAD_LAYER;

typedef /* [public][uuid] */  DECLSPEC_UUID("8B949E30-584A-4092-B585-BA23EE40D3D1") VARIANT GCAD_POINT;

typedef /* [public][uuid] */  DECLSPEC_UUID("97FE5D87-C612-4ED3-B31C-D62DD9B45EDF") long GCAD_NULL;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C2A3FC9C-D039-4C18-86C0-7130802CAEDF") 
enum GcGradientPatternType
    {
        gcPreDefinedGradient	= 0,
        acPreDefinedGradient	= 0,
        gcUserDefinedGradient	= 1,
        acUserDefinedGradient	= 1
    } 	GcGradientPatternType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("296CC8D3-6126-4950-AC75-7EAB07523FAD") 
enum GcadSecurityParamsType
    {
        GCADSECURITYPARAMS_ENCRYPT_DATA	= 1,
        GCADSECURITYPARAMS_ENCRYPT_PROPS	= 2,
        GCADSECURITYPARAMS_SIGN_DATA	= 16,
        GCADSECURITYPARAMS_ADD_TIMESTAMP	= 32,
        ACADSECURITYPARAMS_ENCRYPT_DATA	= 1,
        ACADSECURITYPARAMS_ENCRYPT_PROPS	= 2,
        ACADSECURITYPARAMS_SIGN_DATA	= 16,
        ACADSECURITYPARAMS_ADD_TIMESTAMP	= 32
    } 	GcadSecurityParamsType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("61FA8767-660D-4EA1-97C2-0B7D71CD3B86") 
enum GcadSecurityParamsConstants
    {
        GCADSECURITYPARAMS_ALGID_RC4	= 26625,
        ACADSECURITYPARAMS_ALGID_RC4	= 26625
    } 	GcadSecurityParamsConstants;


EXTERN_C const IID LIBID_GcadVbaLib;

#ifndef ___DGcadApplicationEvents_DISPINTERFACE_DEFINED__
#define ___DGcadApplicationEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DGcadApplicationEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DGcadApplicationEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("330F7B9E-C93C-403D-807C-D92CB9698637")
    _DGcadApplicationEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DGcadApplicationEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DGcadApplicationEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DGcadApplicationEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DGcadApplicationEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DGcadApplicationEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DGcadApplicationEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DGcadApplicationEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DGcadApplicationEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DGcadApplicationEventsVtbl;

    interface _DGcadApplicationEvents
    {
        CONST_VTBL struct _DGcadApplicationEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DGcadApplicationEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DGcadApplicationEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DGcadApplicationEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DGcadApplicationEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DGcadApplicationEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DGcadApplicationEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DGcadApplicationEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DGcadApplicationEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GcadApplication;

#ifdef __cplusplus

class DECLSPEC_UUID("1E517BAA-11BE-4655-9B62-1A7D53772938")
GcadApplication;
#endif

EXTERN_C const CLSID CLSID_GcadMenuGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("79855627-10CA-4054-BB8C-00946292669D")
GcadMenuGroups;
#endif

EXTERN_C const CLSID CLSID_GcadMenuBar;

#ifdef __cplusplus

class DECLSPEC_UUID("573373A3-EDBE-4369-AF1F-3292EE13538C")
GcadMenuBar;
#endif

EXTERN_C const CLSID CLSID_GcadDocuments;

#ifdef __cplusplus

class DECLSPEC_UUID("99EF8026-26E1-43C1-92EE-F5041E7DBE8C")
GcadDocuments;
#endif

EXTERN_C const CLSID CLSID_GcadDatabase;

#ifdef __cplusplus

class DECLSPEC_UUID("5E90323E-2CCF-4AE9-9B6F-6603AB611048")
GcadDatabase;
#endif

EXTERN_C const CLSID CLSID_GcadModelSpace;

#ifdef __cplusplus

class DECLSPEC_UUID("35DF9E00-7285-40A9-BD63-D714AA0CA70F")
GcadModelSpace;
#endif

EXTERN_C const CLSID CLSID_GcadPaperSpace;

#ifdef __cplusplus

class DECLSPEC_UUID("BF0FD147-A1EA-416E-911B-9EF794738AFA")
GcadPaperSpace;
#endif

EXTERN_C const CLSID CLSID_GcadBlocks;

#ifdef __cplusplus

class DECLSPEC_UUID("25F41555-CB62-4FB5-AF5A-FD50D5B99809")
GcadBlocks;
#endif

EXTERN_C const CLSID CLSID_GcadGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("255F2619-FB9D-4176-BE91-D2C122537155")
GcadGroups;
#endif

EXTERN_C const CLSID CLSID_GcadDimStyles;

#ifdef __cplusplus

class DECLSPEC_UUID("187BD9EB-18F0-40A0-BEA1-4B53AE20A161")
GcadDimStyles;
#endif

EXTERN_C const CLSID CLSID_GcadLayers;

#ifdef __cplusplus

class DECLSPEC_UUID("60E6BD18-62F7-4B1A-B701-CEF35537CB59")
GcadLayers;
#endif

EXTERN_C const CLSID CLSID_GcadLineTypes;

#ifdef __cplusplus

class DECLSPEC_UUID("09C7B1A6-D60E-43DA-B8DA-445C72D2A022")
GcadLineTypes;
#endif

EXTERN_C const CLSID CLSID_GcadDictionaries;

#ifdef __cplusplus

class DECLSPEC_UUID("07244103-C9ED-4EF9-BDD4-5062C58A34D4")
GcadDictionaries;
#endif

EXTERN_C const CLSID CLSID_GcadRegisteredApplication;

#ifdef __cplusplus

class DECLSPEC_UUID("CF8BF2DA-8602-41B7-8906-3C67F07994FB")
GcadRegisteredApplication;
#endif

EXTERN_C const CLSID CLSID_GcadRegisteredApplications;

#ifdef __cplusplus

class DECLSPEC_UUID("216D566A-A968-4E87-A8B3-9B5EB06BB19D")
GcadRegisteredApplications;
#endif

EXTERN_C const CLSID CLSID_GcadTextStyles;

#ifdef __cplusplus

class DECLSPEC_UUID("F194C083-83FC-4F35-A76F-F4C577C0689A")
GcadTextStyles;
#endif

EXTERN_C const CLSID CLSID_GcadUCSs;

#ifdef __cplusplus

class DECLSPEC_UUID("1146DF77-46C8-4F31-AB6A-8815AEE71EB7")
GcadUCSs;
#endif

EXTERN_C const CLSID CLSID_GcadViews;

#ifdef __cplusplus

class DECLSPEC_UUID("0165E8DC-3E0B-4102-9C66-DC0228911048")
GcadViews;
#endif

EXTERN_C const CLSID CLSID_GcadViewports;

#ifdef __cplusplus

class DECLSPEC_UUID("FD6D9F4B-1812-4B43-8836-1BCEC2E28F65")
GcadViewports;
#endif

EXTERN_C const CLSID CLSID_GcadLayouts;

#ifdef __cplusplus

class DECLSPEC_UUID("C6B60202-2BEA-4ED1-9A9F-7CF91E5A295D")
GcadLayouts;
#endif

EXTERN_C const CLSID CLSID_GcadPlotConfigurations;

#ifdef __cplusplus

class DECLSPEC_UUID("0EEABD18-B6F5-4E1E-887D-0384A20CD8E9")
GcadPlotConfigurations;
#endif

EXTERN_C const CLSID CLSID_GcadDatabasePreferences;

#ifdef __cplusplus

class DECLSPEC_UUID("E3AC406B-D118-44DB-AC19-AA594DD65C8A")
GcadDatabasePreferences;
#endif

EXTERN_C const CLSID CLSID_GcadFileDependencies;

#ifdef __cplusplus

class DECLSPEC_UUID("B1406301-FAFE-4332-B481-6DE6B109B206")
GcadFileDependencies;
#endif

EXTERN_C const CLSID CLSID_GcadSummaryInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("BBC325BA-407B-4755-B4D1-7A3E30581BD3")
GcadSummaryInfo;
#endif

EXTERN_C const CLSID CLSID_GcadSectionManager;

#ifdef __cplusplus

class DECLSPEC_UUID("D1F1BB22-D947-40C8-90D8-B9DC99591EF7")
GcadSectionManager;
#endif

EXTERN_C const CLSID CLSID_GcadMaterials;

#ifdef __cplusplus

class DECLSPEC_UUID("C4E55BE8-77A9-4A8A-81DE-2CC03D13FF48")
GcadMaterials;
#endif

EXTERN_C const CLSID CLSID_GcadGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("28EA8439-1EEF-4632-812B-3A8515F93530")
GcadGroup;
#endif

EXTERN_C const CLSID CLSID_GcadPlot;

#ifdef __cplusplus

class DECLSPEC_UUID("DF79DE83-2A11-43DB-AE4C-1FE95E57F574")
GcadPlot;
#endif

EXTERN_C const CLSID CLSID_GcadLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("C358F0A6-CF01-4B79-BC20-3744A6CE61CE")
GcadLayer;
#endif

EXTERN_C const CLSID CLSID_GcadLineType;

#ifdef __cplusplus

class DECLSPEC_UUID("44E0D10E-F951-4B01-BDC0-21256D036952")
GcadLineType;
#endif

EXTERN_C const CLSID CLSID_GcadDimStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("67211CB3-E07C-4585-B521-CD8F5840BD8D")
GcadDimStyle;
#endif

EXTERN_C const CLSID CLSID_GcadMLeaderStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("C3819487-144A-4471-B95E-712E3CC64BEC")
GcadMLeaderStyle;
#endif

EXTERN_C const CLSID CLSID_GcadTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("59F48386-168C-4320-8B3D-77E8556EF9E1")
GcadTextStyle;
#endif

EXTERN_C const CLSID CLSID_GcadUCS;

#ifdef __cplusplus

class DECLSPEC_UUID("D4E3C6C4-7DAE-4D80-A98C-148C3CD66E32")
GcadUCS;
#endif

EXTERN_C const CLSID CLSID_GcadViewport;

#ifdef __cplusplus

class DECLSPEC_UUID("415EAAB8-7D05-4935-A6DF-25DA98FC8FB2")
GcadViewport;
#endif

EXTERN_C const CLSID CLSID_GcadPViewport;

#ifdef __cplusplus

class DECLSPEC_UUID("BEAF55E0-0A37-499C-B48B-DBC93CF6E29B")
GcadPViewport;
#endif

EXTERN_C const CLSID CLSID_GcadUtility;

#ifdef __cplusplus

class DECLSPEC_UUID("9F1290F0-C25D-429E-901E-42CBE63A9836")
GcadUtility;
#endif

EXTERN_C const CLSID CLSID_GcadMaterial;

#ifdef __cplusplus

class DECLSPEC_UUID("F55DC97F-4A3C-49E9-873C-B1F3B6F4F8D6")
GcadMaterial;
#endif

EXTERN_C const CLSID CLSID_GcadLayout;

#ifdef __cplusplus

class DECLSPEC_UUID("12664C95-EEAD-4337-A88A-971953571812")
GcadLayout;
#endif

#ifndef ___DGcadDocumentEvents_DISPINTERFACE_DEFINED__
#define ___DGcadDocumentEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DGcadDocumentEvents */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DGcadDocumentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2ABEE42C-D570-4DE3-874F-353204A47B63")
    _DGcadDocumentEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DGcadDocumentEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DGcadDocumentEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DGcadDocumentEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DGcadDocumentEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DGcadDocumentEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DGcadDocumentEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DGcadDocumentEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DGcadDocumentEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DGcadDocumentEventsVtbl;

    interface _DGcadDocumentEvents
    {
        CONST_VTBL struct _DGcadDocumentEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DGcadDocumentEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DGcadDocumentEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DGcadDocumentEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DGcadDocumentEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DGcadDocumentEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DGcadDocumentEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DGcadDocumentEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DGcadDocumentEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GcadDocument;

#ifdef __cplusplus

class DECLSPEC_UUID("E6866304-52C2-42C5-9718-101C0C28042F")
GcadDocument;
#endif

EXTERN_C const CLSID CLSID_GcadObject;

#ifdef __cplusplus

class DECLSPEC_UUID("4F1D3AB3-AAC7-4F57-BA5C-B6D5410FE1D7")
GcadObject;
#endif

EXTERN_C const CLSID CLSID_GcadEntity;

#ifdef __cplusplus

class DECLSPEC_UUID("3737DD60-3DB3-45AA-A592-49640E47A4CB")
GcadEntity;
#endif

EXTERN_C const CLSID CLSID_GcadAcCmColor;

#ifdef __cplusplus

class DECLSPEC_UUID("2ABAB021-6644-4155-9DF6-0EF342610C69")
GcadAcCmColor;
#endif

EXTERN_C const CLSID CLSID_GcadHyperlinks;

#ifdef __cplusplus

class DECLSPEC_UUID("D1131D16-F4F4-4F50-8AEB-A6ECA83141C0")
GcadHyperlinks;
#endif

EXTERN_C const CLSID CLSID_GcadLine;

#ifdef __cplusplus

class DECLSPEC_UUID("6ACCA2E1-E804-4519-B95F-235867C214AC")
GcadLine;
#endif

EXTERN_C const CLSID CLSID_GcadPlotConfiguration;

#ifdef __cplusplus

class DECLSPEC_UUID("211BF34C-5307-4666-B82D-0719CACA809C")
GcadPlotConfiguration;
#endif

EXTERN_C const CLSID CLSID_GcadBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("60C11D4D-6F51-4A16-88CE-305C5BBC84F1")
GcadBlock;
#endif

EXTERN_C const CLSID CLSID_GcadState;

#ifdef __cplusplus

class DECLSPEC_UUID("6208CB09-68D9-4D82-A4BB-43003DB56AFA")
GcadState;
#endif

EXTERN_C const CLSID CLSID_GcadSelectionSet;

#ifdef __cplusplus

class DECLSPEC_UUID("81A17A41-793D-4BF0-A902-E1B622D175B5")
GcadSelectionSet;
#endif

EXTERN_C const CLSID CLSID_GcadSelectionSets;

#ifdef __cplusplus

class DECLSPEC_UUID("EA8022D8-0E43-473D-8646-BB1292EACE19")
GcadSelectionSets;
#endif

EXTERN_C const CLSID CLSID_GcadPreferences;

#ifdef __cplusplus

class DECLSPEC_UUID("57FB46D7-D66B-4EEA-969A-5D778BA7B79F")
GcadPreferences;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesDrafting;

#ifdef __cplusplus

class DECLSPEC_UUID("AA668926-0FCF-4677-A97F-AD7920AB2C58")
GcadPreferencesDrafting;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("865D8226-319C-4784-B160-5D45FE038BF8")
GcadPreferencesDisplay;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesFiles;

#ifdef __cplusplus

class DECLSPEC_UUID("6CE93067-926C-4A41-BFC4-EA0A02C9F7E7")
GcadPreferencesFiles;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesOpenSave;

#ifdef __cplusplus

class DECLSPEC_UUID("7DBA4518-9AA4-416E-A3D6-45E80A02E979")
GcadPreferencesOpenSave;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesOutput;

#ifdef __cplusplus

class DECLSPEC_UUID("62EE39DA-DF13-42B1-861F-487026489C27")
GcadPreferencesOutput;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesProfiles;

#ifdef __cplusplus

class DECLSPEC_UUID("38CDCF3E-F321-43F6-B355-6CBE197BD33A")
GcadPreferencesProfiles;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesSelection;

#ifdef __cplusplus

class DECLSPEC_UUID("1615B81F-2474-4AC3-A6F7-885F0DC5D62F")
GcadPreferencesSelection;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesSystem;

#ifdef __cplusplus

class DECLSPEC_UUID("C19DA545-A773-422D-818F-61E60340C184")
GcadPreferencesSystem;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesUser;

#ifdef __cplusplus

class DECLSPEC_UUID("2DF90FE8-4354-4AB3-ABA9-04B9831F94BF")
GcadPreferencesUser;
#endif

EXTERN_C const CLSID CLSID_GcadMenuGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("521C919B-AC49-4F28-A908-D4BD172C92E6")
GcadMenuGroup;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenus;

#ifdef __cplusplus

class DECLSPEC_UUID("63F5DDA7-C143-42AD-94E8-763C8E770537")
GcadPopupMenus;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenu;

#ifdef __cplusplus

class DECLSPEC_UUID("8774869F-546D-4CE5-9703-CFA67AEEBF26")
GcadPopupMenu;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenuItem;

#ifdef __cplusplus

class DECLSPEC_UUID("70408B41-584A-4C9C-B31B-F36FF8073798")
GcadPopupMenuItem;
#endif

EXTERN_C const CLSID CLSID_GcadMText;

#ifdef __cplusplus

class DECLSPEC_UUID("9F58700D-4910-4463-AEEB-2406161B0490")
GcadMText;
#endif

EXTERN_C const CLSID CLSID_GcadBlockReference;

#ifdef __cplusplus

class DECLSPEC_UUID("DA38CF1F-C119-4FE7-A5F9-AEC5E0C22709")
GcadBlockReference;
#endif

EXTERN_C const CLSID CLSID_GcadCircle;

#ifdef __cplusplus

class DECLSPEC_UUID("C858EE7D-1B1F-4F2E-A61F-3F4AA8C6C1BA")
GcadCircle;
#endif

EXTERN_C const CLSID CLSID_GcadShadowDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("0F994C78-5B0F-4A2C-B63A-DB74B93B5537")
GcadShadowDisplay;
#endif

EXTERN_C const CLSID CLSID_GcadHyperlink;

#ifdef __cplusplus

class DECLSPEC_UUID("B4F3F703-2BC5-4074-BD6E-24E5830BBD0A")
GcadHyperlink;
#endif

EXTERN_C const CLSID CLSID_GcadDynamicBlockReferenceProperty;

#ifdef __cplusplus

class DECLSPEC_UUID("114CCE6C-FDBF-4DAD-9157-7078B5664B95")
GcadDynamicBlockReferenceProperty;
#endif

EXTERN_C const CLSID CLSID_GcadXRecord;

#ifdef __cplusplus

class DECLSPEC_UUID("1E499AED-C7C7-4EE1-8FA6-AB1119B7268E")
GcadXRecord;
#endif

EXTERN_C const CLSID CLSID_GcadSectionSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("5246A240-92AB-460B-820D-365247D9B47F")
GcadSectionSettings;
#endif

EXTERN_C const CLSID CLSID_GcadRasterImage;

#ifdef __cplusplus

class DECLSPEC_UUID("FB5AA334-CBF1-41D1-B9E3-98F2ACB2EB83")
GcadRasterImage;
#endif

EXTERN_C const CLSID CLSID_Gcad3DFace;

#ifdef __cplusplus

class DECLSPEC_UUID("457AD5FC-1656-4606-AB8A-EF7F0215B238")
Gcad3DFace;
#endif

EXTERN_C const CLSID CLSID_Gcad3DPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("7D7FD20A-AC1D-46BC-8C49-8EBB286F681E")
Gcad3DPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadRegion;

#ifdef __cplusplus

class DECLSPEC_UUID("A83EBA25-CCF0-45CE-A7C2-FEABE0D3AF59")
GcadRegion;
#endif

EXTERN_C const CLSID CLSID_Gcad3DSolid;

#ifdef __cplusplus

class DECLSPEC_UUID("C998B595-8233-4859-A51A-492A25E9EB67")
Gcad3DSolid;
#endif

EXTERN_C const CLSID CLSID_GcadArc;

#ifdef __cplusplus

class DECLSPEC_UUID("7E99A93E-D084-43FF-9311-D24A452FF851")
GcadArc;
#endif

EXTERN_C const CLSID CLSID_GcadAttribute;

#ifdef __cplusplus

class DECLSPEC_UUID("3BE70A3D-E2C4-42A6-989C-2F1E08C338D4")
GcadAttribute;
#endif

EXTERN_C const CLSID CLSID_GcadAttributeReference;

#ifdef __cplusplus

class DECLSPEC_UUID("326662C0-F9F3-4A5B-BFE5-2431F4AEF3D8")
GcadAttributeReference;
#endif

EXTERN_C const CLSID CLSID_GcadEllipse;

#ifdef __cplusplus

class DECLSPEC_UUID("7F11EDC5-9468-4C9D-8749-5720C123C13F")
GcadEllipse;
#endif

EXTERN_C const CLSID CLSID_GcadHatch;

#ifdef __cplusplus

class DECLSPEC_UUID("EF74767C-CCF5-4725-935C-39E7BDB8D3B8")
GcadHatch;
#endif

EXTERN_C const CLSID CLSID_GcadLeader;

#ifdef __cplusplus

class DECLSPEC_UUID("1B4D2B5E-8406-4167-B42C-09D8136BAE47")
GcadLeader;
#endif

EXTERN_C const CLSID CLSID_GcadLWPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("508C6E95-0B42-4E0B-9A4A-75CF28263857")
GcadLWPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadPoint;

#ifdef __cplusplus

class DECLSPEC_UUID("5759A970-9028-4C5C-805B-AFE6D6169382")
GcadPoint;
#endif

EXTERN_C const CLSID CLSID_GcadPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("DD0ACEEC-B19B-4EC4-A5C8-C85BBE6402B2")
GcadPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadPolygonMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("7BAA52E2-CBFA-406B-83AB-7D0F939026D4")
GcadPolygonMesh;
#endif

EXTERN_C const CLSID CLSID_GcadRay;

#ifdef __cplusplus

class DECLSPEC_UUID("D44D6709-6C13-4C52-A360-A2943C33EEE8")
GcadRay;
#endif

EXTERN_C const CLSID CLSID_GcadShape;

#ifdef __cplusplus

class DECLSPEC_UUID("4EFE4629-C549-4346-9E5A-06F0AE788ED0")
GcadShape;
#endif

EXTERN_C const CLSID CLSID_GcadSolid;

#ifdef __cplusplus

class DECLSPEC_UUID("7EB18444-4D79-4CA8-8743-0498B64C4D01")
GcadSolid;
#endif

EXTERN_C const CLSID CLSID_GcadSpline;

#ifdef __cplusplus

class DECLSPEC_UUID("F2293592-5908-4F24-9B5D-759CDA971FC2")
GcadSpline;
#endif

EXTERN_C const CLSID CLSID_GcadText;

#ifdef __cplusplus

class DECLSPEC_UUID("12226789-EEA7-4BE8-9FD7-33513C744E3B")
GcadText;
#endif

EXTERN_C const CLSID CLSID_GcadTolerance;

#ifdef __cplusplus

class DECLSPEC_UUID("092962C2-F320-44E1-8857-C8AFE3885555")
GcadTolerance;
#endif

EXTERN_C const CLSID CLSID_GcadTrace;

#ifdef __cplusplus

class DECLSPEC_UUID("D7B6AF1E-5F8B-453C-A26E-828A2BD820CC")
GcadTrace;
#endif

EXTERN_C const CLSID CLSID_GcadXline;

#ifdef __cplusplus

class DECLSPEC_UUID("70371E06-28C5-423C-8912-78A9A6E342CB")
GcadXline;
#endif

EXTERN_C const CLSID CLSID_GcadMInsertBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("5B817FD8-0DDF-4283-B794-86434740C658")
GcadMInsertBlock;
#endif

EXTERN_C const CLSID CLSID_GcadPolyfaceMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("A9879069-87D2-4F15-94B4-92531900783C")
GcadPolyfaceMesh;
#endif

EXTERN_C const CLSID CLSID_GcadMLine;

#ifdef __cplusplus

class DECLSPEC_UUID("CC35F7B8-1AE8-4C31-9F3D-484A44EAC286")
GcadMLine;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayPath;

#ifdef __cplusplus

class DECLSPEC_UUID("3745EF1D-3D36-4500-8034-7526342623D3")
GcadAssocArrayPath;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayPolar;

#ifdef __cplusplus

class DECLSPEC_UUID("AC93B51F-F467-4928-B094-03EA43B3A681")
GcadAssocArrayPolar;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayRectangular;

#ifdef __cplusplus

class DECLSPEC_UUID("48E1D6AC-00B6-41DF-9A4F-26F4F47A8EE6")
GcadAssocArrayRectangular;
#endif

EXTERN_C const CLSID CLSID_GcadExternalReference;

#ifdef __cplusplus

class DECLSPEC_UUID("78F3EF1F-22D5-4BC8-A186-3CF45759F2DD")
GcadExternalReference;
#endif

EXTERN_C const CLSID CLSID_GcadTable;

#ifdef __cplusplus

class DECLSPEC_UUID("92B86261-DA20-4A60-9982-05863C6D9EBE")
GcadTable;
#endif

EXTERN_C const CLSID CLSID_GcadTableCell;

#ifdef __cplusplus

class DECLSPEC_UUID("6336B61B-EFBF-4325-94FE-59D403CB0C76")
GcadTableCell;
#endif

EXTERN_C const CLSID CLSID_GcadDimension;

#ifdef __cplusplus

class DECLSPEC_UUID("5D0A1B18-A59B-402A-B66B-2E10E2BDAE65")
GcadDimension;
#endif

EXTERN_C const CLSID CLSID_GcadDimAligned;

#ifdef __cplusplus

class DECLSPEC_UUID("31463489-3D64-4BC7-85B1-0A1C6F0B2ABA")
GcadDimAligned;
#endif

EXTERN_C const CLSID CLSID_GcadDimAngular;

#ifdef __cplusplus

class DECLSPEC_UUID("8CBE37D9-7079-437A-A384-635D4A74A8D3")
GcadDimAngular;
#endif

EXTERN_C const CLSID CLSID_GcadDimDiametric;

#ifdef __cplusplus

class DECLSPEC_UUID("A4E8085A-25F0-420B-A480-30ABAEF225C8")
GcadDimDiametric;
#endif

EXTERN_C const CLSID CLSID_GcadDimOrdinate;

#ifdef __cplusplus

class DECLSPEC_UUID("A6F7E215-803A-414A-A81D-6299DED292E4")
GcadDimOrdinate;
#endif

EXTERN_C const CLSID CLSID_GcadDimRadial;

#ifdef __cplusplus

class DECLSPEC_UUID("04A200E7-033D-4ECC-A9B1-806148A24763")
GcadDimRadial;
#endif

EXTERN_C const CLSID CLSID_GcadDimRotated;

#ifdef __cplusplus

class DECLSPEC_UUID("4D49A4C2-C908-4523-9E62-89B08B19CB1C")
GcadDimRotated;
#endif

EXTERN_C const CLSID CLSID_GcadDim3PointAngular;

#ifdef __cplusplus

class DECLSPEC_UUID("348090AB-ECF8-4259-BFA3-45C7A91E30F6")
GcadDim3PointAngular;
#endif

EXTERN_C const CLSID CLSID_GcadDimArcLength;

#ifdef __cplusplus

class DECLSPEC_UUID("2C817A8B-0B7D-4DE6-914A-B3A79F0665E4")
GcadDimArcLength;
#endif

EXTERN_C const CLSID CLSID_GcadDimRadialLarge;

#ifdef __cplusplus

class DECLSPEC_UUID("599C859E-76AB-4A00-8A81-2A71506A3824")
GcadDimRadialLarge;
#endif

EXTERN_C const CLSID CLSID_GcadDictionary;

#ifdef __cplusplus

class DECLSPEC_UUID("F7A4E90A-DB70-4175-833C-E9F927851832")
GcadDictionary;
#endif

EXTERN_C const CLSID CLSID_GcadView;

#ifdef __cplusplus

class DECLSPEC_UUID("A2F794C5-9ED5-49B6-A45B-1FB659497505")
GcadView;
#endif

EXTERN_C const CLSID CLSID_GcadToolbars;

#ifdef __cplusplus

class DECLSPEC_UUID("30523308-F09B-4C74-A819-9AD14A4A943E")
GcadToolbars;
#endif

EXTERN_C const CLSID CLSID_GcadToolbar;

#ifdef __cplusplus

class DECLSPEC_UUID("D6EE440D-BCFF-443C-960D-4F1DAC6D94F6")
GcadToolbar;
#endif

EXTERN_C const CLSID CLSID_GcadToolbarItem;

#ifdef __cplusplus

class DECLSPEC_UUID("D2806DE9-1AFE-42DF-87AC-B0A855F9B891")
GcadToolbarItem;
#endif

EXTERN_C const CLSID CLSID_GcadSecurityParams;

#ifdef __cplusplus

class DECLSPEC_UUID("5706A6D3-0EED-4984-B6BD-DFE60367F7CB")
GcadSecurityParams;
#endif

#ifndef ___IGcadScriptJetEvents_DISPINTERFACE_DEFINED__
#define ___IGcadScriptJetEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IGcadScriptJetEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IGcadScriptJetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1BAA42A6-463E-492D-BB53-0D4028148443")
    _IGcadScriptJetEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IGcadScriptJetEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IGcadScriptJetEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IGcadScriptJetEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IGcadScriptJetEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IGcadScriptJetEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IGcadScriptJetEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IGcadScriptJetEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IGcadScriptJetEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IGcadScriptJetEventsVtbl;

    interface _IGcadScriptJetEvents
    {
        CONST_VTBL struct _IGcadScriptJetEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IGcadScriptJetEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IGcadScriptJetEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IGcadScriptJetEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IGcadScriptJetEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IGcadScriptJetEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IGcadScriptJetEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IGcadScriptJetEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IGcadScriptJetEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GcadScriptJet;

#ifdef __cplusplus

class DECLSPEC_UUID("098976AB-EB69-4330-92C8-C8AC73822785")
GcadScriptJet;
#endif

EXTERN_C const CLSID CLSID_GcadFileDependency;

#ifdef __cplusplus

class DECLSPEC_UUID("0E92853F-5027-4A90-999C-118BC73FA6BA")
GcadFileDependency;
#endif

EXTERN_C const CLSID CLSID_GcadMLeader;

#ifdef __cplusplus

class DECLSPEC_UUID("E6494613-3893-47A5-B0E7-B6AD41ADA6F4")
GcadMLeader;
#endif

EXTERN_C const CLSID CLSID_GcadOle;

#ifdef __cplusplus

class DECLSPEC_UUID("ABA71980-3AA9-40F5-81A7-735886F6F6FD")
GcadOle;
#endif

EXTERN_C const CLSID CLSID_GcadSubDMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("73EBC89D-6A5A-4ED8-BC4D-2995DC879649")
GcadSubDMesh;
#endif

EXTERN_C const CLSID CLSID_GcadHelix;

#ifdef __cplusplus

class DECLSPEC_UUID("E817F271-E3BF-44E9-A481-C860D9D8CD13")
GcadHelix;
#endif

EXTERN_C const CLSID CLSID_GcadSection;

#ifdef __cplusplus

class DECLSPEC_UUID("DCB0E3B7-B4A4-4D92-A3E8-C27BCAECBE8F")
GcadSection;
#endif

EXTERN_C const CLSID CLSID_GcadDgnUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("7A486F98-18BC-424E-9D37-CD975EC3667F")
GcadDgnUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadPdfUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("8DF57FE7-CEDA-4730-9F54-C308ED442495")
GcadPdfUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadDwfUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("B8E04FA2-2C8E-4EAE-873C-9ECC978E1628")
GcadDwfUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("25D868BF-4CFD-4CB4-BC30-1A43AAF5F3E1")
GcadSurface;
#endif

EXTERN_C const CLSID CLSID_GcadExtrudedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("3865F4CA-2245-4517-9550-0FA5E5FC28F8")
GcadExtrudedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadLoftedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("3A949249-A2A7-412A-92FF-94D134EB3198")
GcadLoftedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadPlaneSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("938953B2-646A-428C-895E-203B73B1B05A")
GcadPlaneSurface;
#endif

EXTERN_C const CLSID CLSID_GcadRevolvedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("CA2C91D1-2D7B-4195-A66C-CFB788EFEB14")
GcadRevolvedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadSweptSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("6997E39D-299C-45CC-95BC-A677AC0D1A62")
GcadSweptSurface;
#endif

EXTERN_C const CLSID CLSID_GcadCamera;

#ifdef __cplusplus

class DECLSPEC_UUID("0C8A268F-2F40-4D78-8582-E900CD39AAB7")
GcadCamera;
#endif

EXTERN_C const CLSID CLSID_GcadLight;

#ifdef __cplusplus

class DECLSPEC_UUID("1441A79B-2C78-4568-8F3F-1D068ACFC6CD")
GcadLight;
#endif

EXTERN_C const CLSID CLSID_GcadIdPair;

#ifdef __cplusplus

class DECLSPEC_UUID("CDF39880-2237-4180-A675-1601037F78ED")
GcadIdPair;
#endif

EXTERN_C const CLSID CLSID_GcadLayerStateManager;

#ifdef __cplusplus

class DECLSPEC_UUID("7E1EAAEA-9C9A-45B7-B4B9-FDF3642CB5EC")
GcadLayerStateManager;
#endif

EXTERN_C const CLSID CLSID_GcadSortentsTable;

#ifdef __cplusplus

class DECLSPEC_UUID("79C8B818-C544-46EE-BDCF-613095E6DA50")
GcadSortentsTable;
#endif

EXTERN_C const CLSID CLSID_GcadTableStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("31B9FEC5-563C-464B-B180-5B5E4B530EDD")
GcadTableStyle;
#endif

EXTERN_C const CLSID CLSID_GcadArcAlignedText;

#ifdef __cplusplus

class DECLSPEC_UUID("BA03B2BE-41B3-40E6-A493-7F46CCD7CC05")
GcadArcAlignedText;
#endif

EXTERN_C const CLSID CLSID_GcadNurbSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("3C7846DC-43D5-44CD-B954-F941A0F85DE9")
GcadNurbSurface;
#endif

EXTERN_C const CLSID CLSID_GcadPointCloudEx;

#ifdef __cplusplus

class DECLSPEC_UUID("028BA451-EBBA-4529-8521-DBFB95EB745C")
GcadPointCloudEx;
#endif

EXTERN_C const CLSID CLSID_GcPePropertyEditorColor;

#ifdef __cplusplus

class DECLSPEC_UUID("11E6CDE7-1304-488C-8790-3F7AAC891BF2")
GcPePropertyEditorColor;
#endif
#endif /* __GcadVbaLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize64(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal64(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal64(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree64(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


