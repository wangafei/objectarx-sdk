

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Extensions\win\gcax\gcax.idl:
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


#ifndef __gcax_i_h__
#define __gcax_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

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


#ifndef __Gcad3dPloy_FWD_DEFINED__
#define __Gcad3dPloy_FWD_DEFINED__

#ifdef __cplusplus
typedef class Gcad3dPloy Gcad3dPloy;
#else
typedef struct Gcad3dPloy Gcad3dPloy;
#endif /* __cplusplus */

#endif 	/* __Gcad3dPloy_FWD_DEFINED__ */


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


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "GcadVbaApps.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __GcadVbaLib_LIBRARY_DEFINED__
#define __GcadVbaLib_LIBRARY_DEFINED__

/* library GcadVbaLib */
/* [helpstring][lcid][version][uuid] */ 

typedef /* [public][uuid] */  DECLSPEC_UUID("B139467B-4AE5-4FC6-8C18-71F1A9DE9DB3") BSTR GCAD_LAYER;

typedef /* [public][uuid] */  DECLSPEC_UUID("7DD0E5BE-5471-4850-8E5E-694C10CC9EAF") VARIANT GCAD_POINT;

typedef /* [public][uuid] */  DECLSPEC_UUID("C32F4DBA-E4A1-42DC-9BB3-3250383FC0D9") long GCAD_NULL;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("898CF636-FBE1-4835-BA0E-B4AA047B8451") 
enum GcGradientPatternType
    {
        gcPreDefinedGradient	= 0,
        acPreDefinedGradient	= 0,
        gcUserDefinedGradient	= 1,
        acUserDefinedGradient	= 1
    } 	GcGradientPatternType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C667652C-0063-464E-B2E8-6C3D95EE13E1") 
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

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D7B87B0E-E443-4EAB-822C-6F2517FE001A") 
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

    MIDL_INTERFACE("30C697A2-06F2-4053-B69F-1AA2386E0F7B")
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

class DECLSPEC_UUID("C181DC39-8DAB-4068-AE7D-B02B9FD44452")
GcadApplication;
#endif

EXTERN_C const CLSID CLSID_GcadMenuGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("154FDA15-3117-43C3-9156-29D04A5398A9")
GcadMenuGroups;
#endif

EXTERN_C const CLSID CLSID_GcadMenuBar;

#ifdef __cplusplus

class DECLSPEC_UUID("5B8EB7DC-9C9C-4B8D-9D51-0DF21B0308AA")
GcadMenuBar;
#endif

EXTERN_C const CLSID CLSID_GcadDocuments;

#ifdef __cplusplus

class DECLSPEC_UUID("1A2ABC48-193E-48D5-A683-EA1AB9400978")
GcadDocuments;
#endif

EXTERN_C const CLSID CLSID_GcadDatabase;

#ifdef __cplusplus

class DECLSPEC_UUID("705A9C9E-94EE-4D7D-9D27-F4F6CA0ACCF7")
GcadDatabase;
#endif

EXTERN_C const CLSID CLSID_GcadModelSpace;

#ifdef __cplusplus

class DECLSPEC_UUID("EF5178EC-3C8F-4215-948D-3DB768168A47")
GcadModelSpace;
#endif

EXTERN_C const CLSID CLSID_GcadPaperSpace;

#ifdef __cplusplus

class DECLSPEC_UUID("F26A8D81-439B-4115-BD6B-79D289319CD6")
GcadPaperSpace;
#endif

EXTERN_C const CLSID CLSID_GcadBlocks;

#ifdef __cplusplus

class DECLSPEC_UUID("0060A16E-7640-4879-8057-579D72781728")
GcadBlocks;
#endif

EXTERN_C const CLSID CLSID_GcadGroups;

#ifdef __cplusplus

class DECLSPEC_UUID("174BAF03-16C2-4762-B0B9-F04D81FF8FFC")
GcadGroups;
#endif

EXTERN_C const CLSID CLSID_GcadDimStyles;

#ifdef __cplusplus

class DECLSPEC_UUID("B895055E-FF1C-41CC-A720-9A5349B21FCC")
GcadDimStyles;
#endif

EXTERN_C const CLSID CLSID_GcadLayers;

#ifdef __cplusplus

class DECLSPEC_UUID("01908C97-BB14-4881-B9EA-684C0F16ECFA")
GcadLayers;
#endif

EXTERN_C const CLSID CLSID_GcadLineTypes;

#ifdef __cplusplus

class DECLSPEC_UUID("8E7C8CE0-3510-4D91-BDB7-55CFF429C523")
GcadLineTypes;
#endif

EXTERN_C const CLSID CLSID_GcadDictionaries;

#ifdef __cplusplus

class DECLSPEC_UUID("368DF756-E772-44C6-A1D6-70E27BFAC0E1")
GcadDictionaries;
#endif

EXTERN_C const CLSID CLSID_GcadRegisteredApplication;

#ifdef __cplusplus

class DECLSPEC_UUID("3BE37274-72BE-4D99-8696-69D0B71E66FE")
GcadRegisteredApplication;
#endif

EXTERN_C const CLSID CLSID_GcadRegisteredApplications;

#ifdef __cplusplus

class DECLSPEC_UUID("F73D9421-22C6-4A68-B770-FC7EFE0D0968")
GcadRegisteredApplications;
#endif

EXTERN_C const CLSID CLSID_GcadTextStyles;

#ifdef __cplusplus

class DECLSPEC_UUID("409B6F0A-928F-4A99-ABAC-ED8EEE2D0A61")
GcadTextStyles;
#endif

EXTERN_C const CLSID CLSID_GcadUCSs;

#ifdef __cplusplus

class DECLSPEC_UUID("B963F979-6E59-45F1-BF53-51E6F9E4CFE6")
GcadUCSs;
#endif

EXTERN_C const CLSID CLSID_GcadViews;

#ifdef __cplusplus

class DECLSPEC_UUID("B237C847-5542-44E7-BC2F-6FC5033F7A2C")
GcadViews;
#endif

EXTERN_C const CLSID CLSID_GcadViewports;

#ifdef __cplusplus

class DECLSPEC_UUID("41CC6533-DD51-4E9E-8518-DC74B128C99F")
GcadViewports;
#endif

EXTERN_C const CLSID CLSID_GcadLayouts;

#ifdef __cplusplus

class DECLSPEC_UUID("75515074-E16A-41EB-9359-F613F734E2E2")
GcadLayouts;
#endif

EXTERN_C const CLSID CLSID_GcadPlotConfigurations;

#ifdef __cplusplus

class DECLSPEC_UUID("DCCDBEDC-27E5-4F1A-BD8C-08BAE11D953C")
GcadPlotConfigurations;
#endif

EXTERN_C const CLSID CLSID_GcadDatabasePreferences;

#ifdef __cplusplus

class DECLSPEC_UUID("877A01AF-AF04-4B69-9BB6-18B065154FE3")
GcadDatabasePreferences;
#endif

EXTERN_C const CLSID CLSID_GcadFileDependencies;

#ifdef __cplusplus

class DECLSPEC_UUID("F70A8FDF-2DA9-4F79-B46A-ED56ECB2E761")
GcadFileDependencies;
#endif

EXTERN_C const CLSID CLSID_GcadSummaryInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("4C584ABF-1496-488D-AEF6-5CC01AAA80A8")
GcadSummaryInfo;
#endif

EXTERN_C const CLSID CLSID_GcadSectionManager;

#ifdef __cplusplus

class DECLSPEC_UUID("DDFA484D-2F8C-44D3-88AA-9B0C2F5D77D4")
GcadSectionManager;
#endif

EXTERN_C const CLSID CLSID_GcadMaterials;

#ifdef __cplusplus

class DECLSPEC_UUID("72D705AD-941E-4CA0-988E-3162569AA6BA")
GcadMaterials;
#endif

EXTERN_C const CLSID CLSID_GcadGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("A6AF6F55-5797-4DAE-8612-2E879E6E9EA2")
GcadGroup;
#endif

EXTERN_C const CLSID CLSID_GcadPlot;

#ifdef __cplusplus

class DECLSPEC_UUID("55FC1574-EBD5-4B0D-954C-63CBE5FD6C1B")
GcadPlot;
#endif

EXTERN_C const CLSID CLSID_GcadLayer;

#ifdef __cplusplus

class DECLSPEC_UUID("82E4F14D-7D2D-4EB3-8992-E1397B1B6C44")
GcadLayer;
#endif

EXTERN_C const CLSID CLSID_GcadLineType;

#ifdef __cplusplus

class DECLSPEC_UUID("6913C857-3464-41B1-AEDC-CD8A87606565")
GcadLineType;
#endif

EXTERN_C const CLSID CLSID_GcadDimStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("4B1B4B63-FD4D-4F4A-B266-B9C8968FED82")
GcadDimStyle;
#endif

EXTERN_C const CLSID CLSID_GcadMLeaderStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("053D8D6B-4827-4DCB-A702-9C33E4FB0648")
GcadMLeaderStyle;
#endif

EXTERN_C const CLSID CLSID_GcadTextStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("B91787D9-B592-489E-8D60-8F653CF2D28D")
GcadTextStyle;
#endif

EXTERN_C const CLSID CLSID_GcadUCS;

#ifdef __cplusplus

class DECLSPEC_UUID("23E81DA6-7E1A-4188-A664-66C3CEE30E20")
GcadUCS;
#endif

EXTERN_C const CLSID CLSID_GcadViewport;

#ifdef __cplusplus

class DECLSPEC_UUID("C08B5DFE-2C14-43A5-BBE0-A74A5771C7F6")
GcadViewport;
#endif

EXTERN_C const CLSID CLSID_GcadPViewport;

#ifdef __cplusplus

class DECLSPEC_UUID("A7720A7A-E203-4D3C-BCCE-C78C7FB65BCE")
GcadPViewport;
#endif

EXTERN_C const CLSID CLSID_GcadUtility;

#ifdef __cplusplus

class DECLSPEC_UUID("87E3574C-C9D3-45AA-A275-973E90EFE726")
GcadUtility;
#endif

EXTERN_C const CLSID CLSID_GcadMaterial;

#ifdef __cplusplus

class DECLSPEC_UUID("03D26D7B-5797-4936-8031-2E8C844F022A")
GcadMaterial;
#endif

EXTERN_C const CLSID CLSID_GcadLayout;

#ifdef __cplusplus

class DECLSPEC_UUID("0D3AE524-7DDB-4D1C-A674-13CF140EFFE2")
GcadLayout;
#endif

#ifndef ___DGcadDocumentEvents_DISPINTERFACE_DEFINED__
#define ___DGcadDocumentEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DGcadDocumentEvents */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__DGcadDocumentEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FE29E391-9524-46D3-93D2-C43F10075E3F")
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

class DECLSPEC_UUID("B345005B-C953-491C-8C6B-29DDF9175FFB")
GcadDocument;
#endif

EXTERN_C const CLSID CLSID_GcadObject;

#ifdef __cplusplus

class DECLSPEC_UUID("F99C87FC-B6E0-459D-A8B6-3ACA8F140E33")
GcadObject;
#endif

EXTERN_C const CLSID CLSID_GcadEntity;

#ifdef __cplusplus

class DECLSPEC_UUID("80A7ABB7-11FA-4083-B073-DC24C05B0BB4")
GcadEntity;
#endif

EXTERN_C const CLSID CLSID_GcadAcCmColor;

#ifdef __cplusplus

class DECLSPEC_UUID("6887168C-2CCE-485D-AABC-53C1B1B2CD35")
GcadAcCmColor;
#endif

EXTERN_C const CLSID CLSID_GcadHyperlinks;

#ifdef __cplusplus

class DECLSPEC_UUID("A697E6C1-5C5C-4B87-BC75-18CA4B5D716E")
GcadHyperlinks;
#endif

EXTERN_C const CLSID CLSID_GcadLine;

#ifdef __cplusplus

class DECLSPEC_UUID("AC38B0A0-ED8A-4095-8A6D-70F5DBA2C18E")
GcadLine;
#endif

EXTERN_C const CLSID CLSID_GcadPlotConfiguration;

#ifdef __cplusplus

class DECLSPEC_UUID("3195CBB5-FA21-434F-AE47-D65E92AB7625")
GcadPlotConfiguration;
#endif

EXTERN_C const CLSID CLSID_GcadBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("E64571ED-D865-4055-AD72-C7702E363635")
GcadBlock;
#endif

EXTERN_C const CLSID CLSID_GcadState;

#ifdef __cplusplus

class DECLSPEC_UUID("B0E25CB9-8EF7-4D86-9B32-1963C653549A")
GcadState;
#endif

EXTERN_C const CLSID CLSID_GcadSelectionSet;

#ifdef __cplusplus

class DECLSPEC_UUID("BAFCE6BD-696A-4E65-B704-5E0647595CB6")
GcadSelectionSet;
#endif

EXTERN_C const CLSID CLSID_GcadSelectionSets;

#ifdef __cplusplus

class DECLSPEC_UUID("99C3AC8B-5C3B-4472-8DB1-3C2DACF24B5A")
GcadSelectionSets;
#endif

EXTERN_C const CLSID CLSID_GcadPreferences;

#ifdef __cplusplus

class DECLSPEC_UUID("DDA39907-8BFA-4EBF-AE31-F333E8FF39F1")
GcadPreferences;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesDrafting;

#ifdef __cplusplus

class DECLSPEC_UUID("E00D7615-6680-47CD-ABE2-7CD557588463")
GcadPreferencesDrafting;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("38A25FF1-B4F3-4617-903A-4D592389DC51")
GcadPreferencesDisplay;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesFiles;

#ifdef __cplusplus

class DECLSPEC_UUID("F79C360F-446D-4430-8162-F3DC095F1911")
GcadPreferencesFiles;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesOpenSave;

#ifdef __cplusplus

class DECLSPEC_UUID("8E2B2271-F278-40BD-B4AE-11D20BA23C89")
GcadPreferencesOpenSave;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesOutput;

#ifdef __cplusplus

class DECLSPEC_UUID("088E0D47-E5DF-41CF-8E2F-67D83B955168")
GcadPreferencesOutput;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesProfiles;

#ifdef __cplusplus

class DECLSPEC_UUID("0E53AAA1-4A92-4A83-9D05-97D9E73F47EC")
GcadPreferencesProfiles;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesSelection;

#ifdef __cplusplus

class DECLSPEC_UUID("046B5F0A-5F92-40B0-BEC1-6E86E710A61D")
GcadPreferencesSelection;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesSystem;

#ifdef __cplusplus

class DECLSPEC_UUID("3276DC7B-8997-416D-A6F4-0F33DADAB54A")
GcadPreferencesSystem;
#endif

EXTERN_C const CLSID CLSID_GcadPreferencesUser;

#ifdef __cplusplus

class DECLSPEC_UUID("70209125-AFC3-4988-A2D9-19E7167C5D2C")
GcadPreferencesUser;
#endif

EXTERN_C const CLSID CLSID_GcadMenuGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("C4117295-FB99-40BA-A351-624A020E640E")
GcadMenuGroup;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenus;

#ifdef __cplusplus

class DECLSPEC_UUID("5114C677-C38F-4A07-B48B-349FB7BF08DE")
GcadPopupMenus;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenu;

#ifdef __cplusplus

class DECLSPEC_UUID("3C1321D7-7592-4D5A-90A5-7FF7FAC9C86D")
GcadPopupMenu;
#endif

EXTERN_C const CLSID CLSID_GcadPopupMenuItem;

#ifdef __cplusplus

class DECLSPEC_UUID("75460FC8-A4F5-473E-8B20-5A9C0080FDF1")
GcadPopupMenuItem;
#endif

EXTERN_C const CLSID CLSID_GcadMText;

#ifdef __cplusplus

class DECLSPEC_UUID("7BFC78B5-BFC6-403A-BD20-8E0E0BFE62A4")
GcadMText;
#endif

EXTERN_C const CLSID CLSID_GcadBlockReference;

#ifdef __cplusplus

class DECLSPEC_UUID("FB589558-3BF2-4C22-B29D-45533C222BA2")
GcadBlockReference;
#endif

EXTERN_C const CLSID CLSID_GcadCircle;

#ifdef __cplusplus

class DECLSPEC_UUID("5A49A8EB-CE2C-4952-B998-BDDEF7FAE37F")
GcadCircle;
#endif

EXTERN_C const CLSID CLSID_Gcad3dPloy;

#ifdef __cplusplus

class DECLSPEC_UUID("2B2AD04D-DE0B-4D7A-8933-E9C7C6C94A10")
Gcad3dPloy;
#endif

EXTERN_C const CLSID CLSID_GcadShadowDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("40CE58A3-58B4-4F6B-BA13-6DADC5C4609E")
GcadShadowDisplay;
#endif

EXTERN_C const CLSID CLSID_GcadHyperlink;

#ifdef __cplusplus

class DECLSPEC_UUID("407C6BCD-3F93-4C6A-AC60-A005565ED270")
GcadHyperlink;
#endif

EXTERN_C const CLSID CLSID_GcadDynamicBlockReferenceProperty;

#ifdef __cplusplus

class DECLSPEC_UUID("6F645C8C-C7F1-44D5-BCDD-3C0144120AC1")
GcadDynamicBlockReferenceProperty;
#endif

EXTERN_C const CLSID CLSID_GcadXRecord;

#ifdef __cplusplus

class DECLSPEC_UUID("41669BFA-0CC0-46CC-83EC-F99506DA5010")
GcadXRecord;
#endif

EXTERN_C const CLSID CLSID_GcadSectionSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("75CA6B7C-3647-4BAF-9DBB-A48C952B800E")
GcadSectionSettings;
#endif

EXTERN_C const CLSID CLSID_GcadRasterImage;

#ifdef __cplusplus

class DECLSPEC_UUID("06FE5F78-C011-4A72-BEA0-70F293299BB5")
GcadRasterImage;
#endif

EXTERN_C const CLSID CLSID_Gcad3DFace;

#ifdef __cplusplus

class DECLSPEC_UUID("540C4940-30E2-45DD-B9CA-65A4DF65EF91")
Gcad3DFace;
#endif

EXTERN_C const CLSID CLSID_Gcad3DPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("933449D2-160B-4F71-A6DC-D6E1B65278EF")
Gcad3DPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadRegion;

#ifdef __cplusplus

class DECLSPEC_UUID("327A6ABD-10F8-4A3C-93BE-BB312C3644F4")
GcadRegion;
#endif

EXTERN_C const CLSID CLSID_Gcad3DSolid;

#ifdef __cplusplus

class DECLSPEC_UUID("1A92693F-8FD9-40AE-B31B-267844F4EF10")
Gcad3DSolid;
#endif

EXTERN_C const CLSID CLSID_GcadArc;

#ifdef __cplusplus

class DECLSPEC_UUID("4100C09B-246A-4E44-AC2F-B718CCD86465")
GcadArc;
#endif

EXTERN_C const CLSID CLSID_GcadAttribute;

#ifdef __cplusplus

class DECLSPEC_UUID("2CAA2F65-5A9F-41EC-8505-0E81F77D6795")
GcadAttribute;
#endif

EXTERN_C const CLSID CLSID_GcadAttributeReference;

#ifdef __cplusplus

class DECLSPEC_UUID("54EBB895-4C1A-458A-B585-BA8C8E632EF0")
GcadAttributeReference;
#endif

EXTERN_C const CLSID CLSID_GcadEllipse;

#ifdef __cplusplus

class DECLSPEC_UUID("AC20E67A-9894-429E-89EB-57EFCD28BD44")
GcadEllipse;
#endif

EXTERN_C const CLSID CLSID_GcadHatch;

#ifdef __cplusplus

class DECLSPEC_UUID("C881E0D9-D25F-4B89-8665-DBEECF61D8FB")
GcadHatch;
#endif

EXTERN_C const CLSID CLSID_GcadLeader;

#ifdef __cplusplus

class DECLSPEC_UUID("4941D740-31C3-4090-A85C-EF6CEBF0ED97")
GcadLeader;
#endif

EXTERN_C const CLSID CLSID_GcadLWPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("D3C541A2-0449-4FC1-A275-F039A6043233")
GcadLWPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadPoint;

#ifdef __cplusplus

class DECLSPEC_UUID("0D300372-C6AB-4DBA-80A3-188CE765027C")
GcadPoint;
#endif

EXTERN_C const CLSID CLSID_GcadPolyline;

#ifdef __cplusplus

class DECLSPEC_UUID("9499DD79-B3F7-4A6F-9A75-28889352219C")
GcadPolyline;
#endif

EXTERN_C const CLSID CLSID_GcadPolygonMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("D259752E-42F9-4321-ADCE-7770703E28B0")
GcadPolygonMesh;
#endif

EXTERN_C const CLSID CLSID_GcadRay;

#ifdef __cplusplus

class DECLSPEC_UUID("E22711E4-63DF-48DF-9E11-0B1EBDDE26BA")
GcadRay;
#endif

EXTERN_C const CLSID CLSID_GcadShape;

#ifdef __cplusplus

class DECLSPEC_UUID("DCFCB726-AF7E-48DA-939E-5B4330F2E572")
GcadShape;
#endif

EXTERN_C const CLSID CLSID_GcadSolid;

#ifdef __cplusplus

class DECLSPEC_UUID("83C1DD5B-4218-4074-9D2D-92F0AE522824")
GcadSolid;
#endif

EXTERN_C const CLSID CLSID_GcadSpline;

#ifdef __cplusplus

class DECLSPEC_UUID("6838641E-F222-4A8C-A497-C6CB38120445")
GcadSpline;
#endif

EXTERN_C const CLSID CLSID_GcadText;

#ifdef __cplusplus

class DECLSPEC_UUID("CE5BFF15-9D57-438C-98A6-3F646C3D585A")
GcadText;
#endif

EXTERN_C const CLSID CLSID_GcadTolerance;

#ifdef __cplusplus

class DECLSPEC_UUID("2BDC02E3-3231-4582-8876-732B7485C2B9")
GcadTolerance;
#endif

EXTERN_C const CLSID CLSID_GcadTrace;

#ifdef __cplusplus

class DECLSPEC_UUID("DA3A26AD-16EC-4894-8A43-9779FB3570DC")
GcadTrace;
#endif

EXTERN_C const CLSID CLSID_GcadXline;

#ifdef __cplusplus

class DECLSPEC_UUID("BACD4C5E-1069-44B3-BB95-BD86A6D9ACC2")
GcadXline;
#endif

EXTERN_C const CLSID CLSID_GcadMInsertBlock;

#ifdef __cplusplus

class DECLSPEC_UUID("F8C88BF0-B99B-4B1E-B6C1-C0AA38C01DC6")
GcadMInsertBlock;
#endif

EXTERN_C const CLSID CLSID_GcadPolyfaceMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("0EAE7ED2-A01E-4CCA-A413-0CE2394E291E")
GcadPolyfaceMesh;
#endif

EXTERN_C const CLSID CLSID_GcadMLine;

#ifdef __cplusplus

class DECLSPEC_UUID("0B946B2A-A35A-45EF-8405-861DD8376861")
GcadMLine;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayPath;

#ifdef __cplusplus

class DECLSPEC_UUID("72B18191-4745-4B85-972C-F178785AB100")
GcadAssocArrayPath;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayPolar;

#ifdef __cplusplus

class DECLSPEC_UUID("8BF417C6-77CE-4122-ADD7-754B958C138D")
GcadAssocArrayPolar;
#endif

EXTERN_C const CLSID CLSID_GcadAssocArrayRectangular;

#ifdef __cplusplus

class DECLSPEC_UUID("392DE6F9-4163-44D9-B0E3-9BB55C40625D")
GcadAssocArrayRectangular;
#endif

EXTERN_C const CLSID CLSID_GcadExternalReference;

#ifdef __cplusplus

class DECLSPEC_UUID("69C5CF1E-58D1-46EC-B526-6A7572827DC0")
GcadExternalReference;
#endif

EXTERN_C const CLSID CLSID_GcadTable;

#ifdef __cplusplus

class DECLSPEC_UUID("15A2DEE0-D8E1-4364-AF7F-0A77202B992A")
GcadTable;
#endif

EXTERN_C const CLSID CLSID_GcadTableCell;

#ifdef __cplusplus

class DECLSPEC_UUID("6E4106EE-7291-4C8C-8567-72A07AE21EFF")
GcadTableCell;
#endif

EXTERN_C const CLSID CLSID_GcadDimension;

#ifdef __cplusplus

class DECLSPEC_UUID("804D21E7-6B3E-485E-9115-1441D8A8443B")
GcadDimension;
#endif

EXTERN_C const CLSID CLSID_GcadDimAligned;

#ifdef __cplusplus

class DECLSPEC_UUID("62DFE964-2F73-4353-A527-2B32DA15AE84")
GcadDimAligned;
#endif

EXTERN_C const CLSID CLSID_GcadDimAngular;

#ifdef __cplusplus

class DECLSPEC_UUID("0E414170-7CA2-4188-8EE1-118D3FC6D93D")
GcadDimAngular;
#endif

EXTERN_C const CLSID CLSID_GcadDimDiametric;

#ifdef __cplusplus

class DECLSPEC_UUID("FC381ECE-5C9A-485D-AA2E-1F07EAAE3833")
GcadDimDiametric;
#endif

EXTERN_C const CLSID CLSID_GcadDimOrdinate;

#ifdef __cplusplus

class DECLSPEC_UUID("247F41A8-F408-4B5A-993A-2545D0F64740")
GcadDimOrdinate;
#endif

EXTERN_C const CLSID CLSID_GcadDimRadial;

#ifdef __cplusplus

class DECLSPEC_UUID("C7B6ABC8-16DF-4DF9-AFF1-F0179748CB7E")
GcadDimRadial;
#endif

EXTERN_C const CLSID CLSID_GcadDimRotated;

#ifdef __cplusplus

class DECLSPEC_UUID("F43BBA23-7136-4E5C-8D4F-E39E52A10F46")
GcadDimRotated;
#endif

EXTERN_C const CLSID CLSID_GcadDim3PointAngular;

#ifdef __cplusplus

class DECLSPEC_UUID("957351FF-3236-4DC3-91C5-3900F6E2A298")
GcadDim3PointAngular;
#endif

EXTERN_C const CLSID CLSID_GcadDimArcLength;

#ifdef __cplusplus

class DECLSPEC_UUID("A534DB38-BBD0-49F0-9AB8-C132B345BA09")
GcadDimArcLength;
#endif

EXTERN_C const CLSID CLSID_GcadDimRadialLarge;

#ifdef __cplusplus

class DECLSPEC_UUID("B39B20BF-7FD7-4FBB-8A98-222AF83A1079")
GcadDimRadialLarge;
#endif

EXTERN_C const CLSID CLSID_GcadDictionary;

#ifdef __cplusplus

class DECLSPEC_UUID("5E6BE764-775E-4AC5-8B30-75C095599955")
GcadDictionary;
#endif

EXTERN_C const CLSID CLSID_GcadView;

#ifdef __cplusplus

class DECLSPEC_UUID("E88813D2-D59E-40C9-8363-FF5F0158EC37")
GcadView;
#endif

EXTERN_C const CLSID CLSID_GcadToolbars;

#ifdef __cplusplus

class DECLSPEC_UUID("0736E422-3E1B-4D58-8B21-331996BDC327")
GcadToolbars;
#endif

EXTERN_C const CLSID CLSID_GcadToolbar;

#ifdef __cplusplus

class DECLSPEC_UUID("A170D6AD-470B-4817-A784-8FAD9AB51551")
GcadToolbar;
#endif

EXTERN_C const CLSID CLSID_GcadToolbarItem;

#ifdef __cplusplus

class DECLSPEC_UUID("3BF7156F-CAA1-452D-9E73-58AF3CB38234")
GcadToolbarItem;
#endif

EXTERN_C const CLSID CLSID_GcadSecurityParams;

#ifdef __cplusplus

class DECLSPEC_UUID("9066F0E4-FBEA-40D2-BC1B-E5CF2EF810CD")
GcadSecurityParams;
#endif

#ifndef ___IGcadScriptJetEvents_DISPINTERFACE_DEFINED__
#define ___IGcadScriptJetEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IGcadScriptJetEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IGcadScriptJetEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5AA656F5-4CA7-4C7B-99FD-F81D4E5B10FE")
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

class DECLSPEC_UUID("8018A9C5-8A53-4301-9CAD-29C7A2D5BA0D")
GcadScriptJet;
#endif

EXTERN_C const CLSID CLSID_GcadFileDependency;

#ifdef __cplusplus

class DECLSPEC_UUID("A98C008A-CB3A-4C16-B191-73F9550B2ED3")
GcadFileDependency;
#endif

EXTERN_C const CLSID CLSID_GcadMLeader;

#ifdef __cplusplus

class DECLSPEC_UUID("A5435E4D-0FC4-4F0D-93F4-B6F00C5EF24E")
GcadMLeader;
#endif

EXTERN_C const CLSID CLSID_GcadOle;

#ifdef __cplusplus

class DECLSPEC_UUID("012AFE9E-5AB2-4F89-9C91-4D99F87985B8")
GcadOle;
#endif

EXTERN_C const CLSID CLSID_GcadSubDMesh;

#ifdef __cplusplus

class DECLSPEC_UUID("E1F7FCA0-5B61-4CD4-8DCB-B637B39B0F59")
GcadSubDMesh;
#endif

EXTERN_C const CLSID CLSID_GcadHelix;

#ifdef __cplusplus

class DECLSPEC_UUID("397740BF-FFB1-415F-A8A9-8BBC39DFED5D")
GcadHelix;
#endif

EXTERN_C const CLSID CLSID_GcadSection;

#ifdef __cplusplus

class DECLSPEC_UUID("AE743E8C-3DA0-407A-88BF-5A4C3DBECA63")
GcadSection;
#endif

EXTERN_C const CLSID CLSID_GcadDgnUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("6B24FA82-C83F-4922-930D-55A2FB372501")
GcadDgnUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadPdfUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("9544466E-C90C-49C6-B810-B1307E7BB402")
GcadPdfUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadDwfUnderlay;

#ifdef __cplusplus

class DECLSPEC_UUID("D9B87F87-475F-45E1-BC22-D83989CDF8E3")
GcadDwfUnderlay;
#endif

EXTERN_C const CLSID CLSID_GcadSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("B5AA8C25-6EE6-4883-B25B-343FA6799C0F")
GcadSurface;
#endif

EXTERN_C const CLSID CLSID_GcadExtrudedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("F66E9A28-7960-4BD6-97D2-13BA0F8AF98F")
GcadExtrudedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadLoftedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("CB4E6D6E-4F2C-4146-A27F-C8E82DE1A895")
GcadLoftedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadPlaneSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("65EC3555-C5C0-4D80-B4DF-BA36B7A3F950")
GcadPlaneSurface;
#endif

EXTERN_C const CLSID CLSID_GcadRevolvedSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("430D3AA1-494D-4983-A548-BC8E39023555")
GcadRevolvedSurface;
#endif

EXTERN_C const CLSID CLSID_GcadSweptSurface;

#ifdef __cplusplus

class DECLSPEC_UUID("B3A56B64-EA4D-4B10-A81C-B6FE3F5C8098")
GcadSweptSurface;
#endif

EXTERN_C const CLSID CLSID_GcadCamera;

#ifdef __cplusplus

class DECLSPEC_UUID("01099138-2EA6-4914-B60E-89E9FFD157AC")
GcadCamera;
#endif

EXTERN_C const CLSID CLSID_GcadLight;

#ifdef __cplusplus

class DECLSPEC_UUID("513384A0-35FA-4577-850F-C5C242E6ED75")
GcadLight;
#endif

EXTERN_C const CLSID CLSID_GcadIdPair;

#ifdef __cplusplus

class DECLSPEC_UUID("41DD8771-F694-4759-B310-BC4A93920891")
GcadIdPair;
#endif

EXTERN_C const CLSID CLSID_GcadLayerStateManager;

#ifdef __cplusplus

class DECLSPEC_UUID("235B07A4-7105-4E06-BD02-A68D8B359C96")
GcadLayerStateManager;
#endif

EXTERN_C const CLSID CLSID_GcadSortentsTable;

#ifdef __cplusplus

class DECLSPEC_UUID("101EA186-809A-40A5-AC92-E37BEBCC3EC4")
GcadSortentsTable;
#endif

EXTERN_C const CLSID CLSID_GcadTableStyle;

#ifdef __cplusplus

class DECLSPEC_UUID("3CD99AAF-A07B-41D9-A66D-6417237343AD")
GcadTableStyle;
#endif

EXTERN_C const CLSID CLSID_GcadArcAlignedText;

#ifdef __cplusplus

class DECLSPEC_UUID("E40B5128-542C-495A-9255-73CF87527087")
GcadArcAlignedText;
#endif
#endif /* __GcadVbaLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


