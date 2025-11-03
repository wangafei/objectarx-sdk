#pragma once

//{{Struct && Union && Typedef
#define ads_real       gds_real
#define ads_point      gds_point
#define ads_matrix     gds_matrix
#define ads_name       gds_name
#define ads_pointp     gds_pointp
#define ads_namep      gds_namep
#define ads_resbuf     gds_resbuf
#define	ads_binary     gds_binary
#define	ads_u_val      gds_u_val
#define	ads_hdlg       gds_hdlg
#define	ads_htile      gds_htile
#define	ads_callback_packet gds_callback_packet
//}}

//{{Function
//Ed
#define acrx_abort     gcedAbort
#define acedGetAppName gcedGetAppName
#define acedUpdate     gcedUpdate
#define adsw_acadMainWnd   gds_getmainhwnd
#define adsw_acadDocWnd    gds_getviewhwnd
#define adsw_hwndAcad  gdsw_hwndGcad
#define acedCommand    gcedCommand
#define acedCmd        gcedCmd
#define acedRegFunc    gcedRegFunc
#define acedUsrBrk     gcedUsrBrk
#define acedDefun      gcedDefun
#define acedSetFunHelp gcedSetFunHelp
#define acedUndef      gcedUndef
#define acedGetFunCode gcedGetFunCode
#define acedGetArgs    gcedGetArgs
#define acedGetAcadWinApp  gcedGetGcadWinApp
#define acedRetList    gcedRetList
#define acedRetVal     gcedRetVal
#define acedRetPoint   gcedRetPoint
#define acedRetStr     gcedRetStr
#define acedRetName    gcedRetName
#define acedRetInt     gcedRetInt
#define acedRetReal    gcedRetReal
#define acedRetT       gcedRetT
#define acedRetNil     gcedRetNil
#define acedRetVoid    gcedRetVoid

#define acedEntSel     gcedEntSel
#define acedNEntSel    gcedNEntSel
#define acedNEntSelP   gcedNEntSelP
#define acedSSGet      gcedSSGet
#define acedSSGetFirst gcedSSGetFirst
#define acedSSSetFirst gcedSSSetFirst
#define acedSSFree     gcedSSFree
#define acedSSLength   gcedSSLength
#define acedSSAdd      gcedSSAdd
#define acedSSDel      gcedSSDel
#define acedSSMemb     gcedSSMemb
#define acedSSName     gcedSSName
#define acedSSNameX    gcedSSNameX
#define acedSSGetKwordCallbackPtr	gcedSSGetKwordCallbackPtr
#define acedSSSetKwordCallbackPtr	gcedSSSetKwordCallbackPtr
#define acedSSGetOtherCallbackPtr	gcedSSGetOtherCallbackPtr
#define acedSSSetOtherCallbackPtr	gcedSSSetOtherCallbackPtr

#define acedNEntSelPEx gcedNEntSelPEx

#define acedTrans     gcedTrans

#define acedGetVar    gcedGetVar
#define acedSetVar    gcedSetVar
#define acedGetCfg    gcedGetCfg
#define acedSetCfg    gcedSetCfg
#define acedGetEnv    gcedGetEnv
#define acedSetEnv    gcedSetEnv

#define acedInitGet   gcedInitGet
#define acedGetAngle  gcedGetAngle
#define acedGetCorner gcedGetCorner
#define acedGetDist   gcedGetDist
#define acedGetOrient gcedGetOrient
#define acedGetPoint  gcedGetPoint
#define acedGetInt    gcedGetInt
#define acedGetKword  gcedGetKword
#define acedGetReal   gcedGetReal
#define acedGetInput  gcedGetInput
#define acedGetString gcedGetString
#define acedGetStringB    gcedGetStringB
#define acedVports    gcedVports
#define acedGetFullInput  gcedGetFullInput
#define acedGetFullKword  gcedGetFullKword
#define acedGetFullString gcedGetFullString
#define acedSSNameXEx gcedSSNameXEx

#define acedTextScr   gcedTextScr
#define acedTextPage  gcedTextPage
#define acedGraphScr  gcedGraphScr
#define acedRedraw    gcedRedraw
#define acedOsnap     gcedOsnap
#define acedGrRead    gcedGrRead
#define acedGrText    gcedGrText
#define acedGrDraw    gcedGrDraw
#define acedGrVecs    gcedGrVecs
#define acedXformSS   gcedXformSS
#define acedDragGen   gcedDragGen
#define acedTextBox   gcedTextBox
#define acedTablet    gcedTablet
#define acedSetView   gcedSetView

#define ads_regen     gds_regen

#define acedGetCName  gcedGetCName
#define acedGetSym    gcedGetSym
#define acedPutSym    gcedPutSym

#define acedHelp      gcedHelp
#define acedArxLoaded gcedArxLoaded
#define acedArxLoad   gcedArxLoad
#define acedArxUnload gcedArxUnload
#define acedInvoke    gcedInvoke
#define acedFindFile  gcedFindFile
#define acedFNSplit   gcedFNSplit

#define acedIsDragging    gcedIsDragging

#define ads_init      gds_init
#define ads_abort     gds_abort
#define ads_exit      gds_exit
#define ads_link      gds_link

#define acedMenuCmd   gcedMenuCmd
#define acedPrompt    gcedPrompt
#define acedAlert     gcedAlert

#define acedGetFileD  gcedGetFileD
#define acedGetFileNavDialog gcedGetFileNavDialog

//Db
#define	acdbAngToS    gcdbAngToS
#define acdbRToS      gcdbRToS
#define acdbAngToF    gcdbAngToF
#define acdbDisToF    gcdbDisToF
#define acdbInters    gcdbInters
#define acdbSNValid   gcdbSNValid

#define	acdbFail      gcdbFail
#define acdbXdRoom    gcdbXdRoom
#define acdbXdSize    gcdbXdSize
#define acdbHandEnt   gcdbHandEnt
#define acdbXStrSave  gcdbXStrSave	
#define acdbXStrCase  gcdbXStrCase
#define acdbNameSet   gds_name_set
#define acdbPointSet  gds_point_set
#define acdbNameClear gds_name_clear
#define acdbNameNil   gds_name_nil
#define acdbNameEqual gds_name_equal

#define acdbEntDel    gcdbEntDel
#define acdbEntGetX   gcdbEntGetX
#define acdbEntGet    gcdbEntGet
#define acdbEntLast   gcdbEntLast
#define acdbEntNext   gcdbEntNext
#define acdbEntUpd    gcdbEntUpd
#define acdbEntMod    gcdbEntMod
#define acdbEntMake   gcdbEntMake
#define acdbEntMakeX  gcdbEntMakeX
#define acdbRegApp    gcdbRegApp
#define acdbTblNext   gcdbTblNext
#define acdbTblSearch gcdbTblSearch
#define acdbTblObjName    gcdbTblObjName
#define acdbDictSearch    gcdbDictSearch 
#define acdbDictNext  gcdbDictNext
#define acdbDictRename    gcdbDictRename
#define acdbDictRemove    gcdbDictRemove
#define acdbDictAdd       gcdbDictAdd
#define acdbNamedObjDict  gcdbNamedObjDict

//Memory
#define acad_malloc   gcad_malloc
#define acad_free     gcad_free
#define acad_realloc  gcad_realloc
#define acad_calloc   gcad_calloc
#define acad__msize   gcad__msize
#define acad__strdup  gcad__strdup

//Util
#define	acad__assert  gcad__assert
#define	acutCvUnit    gcutCvUnit
#define	acutWcMatch   gcutWcMatch
#define acutWcMatchEx gcutWcMatchEx

#define	acutPrintf		gcutPrintf
#define	acutSPrintf		gcutSPrintf

#define	acutNewRb		gcutNewRb
#define	acutRelRb		gcutRelRb
#define	acutBuildList	gcutBuildList

#define	acutAngle		gcutAngle
#define	acutDistance	gcutDistance
#define	acutPolar		gcutPolar

#define	acutIsAlpha		gcutIsAlpha
#define	acutIsUpper		gcutIsUpper
#define	acutIsLower		gcutIsLower
#define	acutIsDigit		gcutIsDigit
#define	acutIsXDigit	gcutIsXDigit
#define	acutIsSpace		gcutIsSpace
#define	acutIsPunct		gcutIsPunct
#define	acutIsAlNum		gcutIsAlNum
#define	acutIsPrint		gcutIsPrint
#define	acutIsGraph		gcutIsGraph
#define	acutIsCntrl		gcutIsCntrl
#define	acutToUpper		gcutToUpper
#define	acutToLower		gcutToLower

#define ads_queueexpr gds_queueexpr

//acutil
#define acutSplitString     gcutSplitString
#define	acutTrimWhiteSpace  gcutTrimWhiteSpace
#define acutXStrLength      gcutXStrLength
#define acutXStrNormalize   gcutXStrNormalize
#define acutXStrUppercase   gcutXStrUppercase
//Dcl
#define ads_load_dialog   dlg_load_dialog
#define ads_unload_dialog dlg_unload_dialog
#define ads_new_dialog    dlg_new_dialog
#define ads_new_positioned_dialog  dlg_new_positioned_dialog
#define ads_start_dialog  dlg_start_dialog
#define ads_done_dialog   dlg_done_dialog
#define ads_done_positioned_dialog dlg_done_positioned_dialog
#define ads_term_dialog   dlg_term_dialog
#define ads_action_tile   dlg_action_tile
#define ads_set_tile      dlg_set_tile
#define ads_client_data_tile  dlg_client_data_tile
#define ads_get_tile      dlg_get_tile
#define ads_get_attr      dlg_get_attr
#define ads_get_attr_string   dlg_get_attr_string
#define ads_start_list    dlg_start_list
#define ads_add_list      dlg_add_list
#define ads_end_list      dlg_end_list
#define ads_get_list_string   dlg_get_list_string
#define ads_mode_tile     dlg_mode_tile
#define ads_dimensions_tile   dlg_dimensions_tile
#define ads_start_image   dlg_start_image
#define ads_vector_image  dlg_vector_image
#define ads_fill_image    dlg_fill_image
#define ads_slide_image   dlg_slide_image
#define ads_end_image     dlg_end_image
//}}
