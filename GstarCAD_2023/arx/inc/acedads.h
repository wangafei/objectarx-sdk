/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "acadapidef.h"
#include "../../inc/gcedgds.h"
#ifdef __cplusplus
#include "adesk.h"
#endif

#include "adsdef.h"
#include "accoredefs.h"
#include "acbasedefs.h"
#include "acmem.h"
#include "AdAChar.h"

#define acedGetAppName gcedGetAppName
#define acedUpdate gcedUpdate
#define adsw_acadMainWnd gdsw_gcadMainWnd
#define adsw_acadDocWnd gdsw_gcadDocWnd
#define acedRegFunc gcedRegFunc
#define acedUsrBrk gcedUsrBrk
#define acedDefun gcedDefun
#define acedDefunEx gcedDefunEx
#define acedSetFunHelp gcedSetFunHelp
#define acedUndef gcedUndef
#define acedGetFunCode gcedGetFunCode
#define acedGetArgs gcedGetArgs
#define acedRetList gcedRetList
#define acedRetVal gcedRetVal
#define acedRetPoint gcedRetPoint
#define acedRetStr gcedRetStr
#define acedRetName gcedRetName
#define acedRetInt gcedRetInt
#define acedRetReal gcedRetReal 
#define acedRetT gcedRetT
#define acedRetNil gcedRetNil
#define acedRetVoid gcedRetVoid
#define acedEntSel gcedEntSel
#define acedNEntSelP gcedNEntSelP
#define acedNEntSel gcedNEntSel
#define acedSSGet gcedSSGet
#define acedSSGetFirst gcedSSGetFirst
#define acedSSSetFirst gcedSSSetFirst
#define acedSSFree gcedSSFree
#define acedSSLength gcedSSLength
#define acedSSAdd gcedSSAdd
#define acedSSDel gcedSSDel
#define acedSSMemb gcedSSMemb
#define acedSSName gcedSSName
#define acedSSNameX gcedSSNameX
#define acedSSNameXEx gcedSSNameXEx
#define acedSSGetKwordCallbackPtr gcedSSGetKwordCallbackPtr
#define acedSSSetKwordCallbackPtr gcedSSSetKwordCallbackPtr
#define acedSSGetOtherCallbackPtr gcedSSGetOtherCallbackPtr
#define acedSSSetOtherCallbackPtr gcedSSSetOtherCallbackPtr
#define acedTrans gcedTrans
#define acedSetVar gcedSetVar
#define acedInitGet gcedInitGet
#define acedGetSym gcedGetSym
#define acedPutSym gcedPutSym
#define acedHelp gcedHelp
#define acedHelpForExternal gcedHelpForExternal
#define acedFNSplit gcedFNSplit
#define acedArxLoaded gcedGrxLoaded
#define acedArxLoad gcedGrxLoad
#define acedArxUnload gcedGrxUnload
#define acedInvoke gcedInvoke
#define acedGetVar gcedGetVar
#define acedFindFile gcedFindFile
#define acedFindTrustedFile gcedFindTrustedFile
#define acedGetEnv gcedGetEnv
#define acedGetCfg gcedGetCfg
#define acedSetCfg gcedSetCfg
#define acedGetString gcedGetString
#define acedMenuCmd gcedMenuCmd
#define acedPrompt gcedPrompt
#define acedAlert gcedAlert
#define acedGetAngle gcedGetAngle
#define acedGetCorner gcedGetCorner
#define acedGetDist gcedGetDist
#define acedGetPoint gcedGetPoint
#define acedGetOrient gcedGetOrient
#define acedGetInt gcedGetInt
#define acedGetKword gcedGetKword
#define acedGetReal gcedGetReal
#define acedGetInput gcedGetInput
#define acedVports gcedVports
#define acedTextScr gcedTextScr
#define acedGraphScr gcedGraphScr
#define acedTextPage gcedTextPage
#define acedRedraw gcedRedraw
#define acedOsnap gcedOsnap
#define acedGrRead gcedGrRead
#define acedGrText gcedGrText
#define acedGrDraw gcedGrDraw
#define acedGrVecs gcedGrVecs
#define acedXformSS gcedXformSS
#define acedDragGen gcedDragGen
#define acedSetView gcedSetView
#define acedGetFileD gcedGetFileD
#define acedGetFileNavDialog gcedGetFileNavDialog
#define acedTextBox gcedTextBox
#define acedTablet gcedTablet
#define acedGetCName gcedGetCName
#define acedEatCommandThroat gcedEatCommandThroat
#define acdbEntDel gcdbEntDel
#define acdbEntGetX gcdbEntGetX
#define acdbEntGet gcdbEntGet
#define acdbEntLast gcdbEntLast
#define acdbEntNext gcdbEntNext
#define acdbEntUpd gcdbEntUpd
#define acdbEntMod gcdbEntMod
#define acdbEntMake gcdbEntMake
#define acdbEntMakeX gcdbEntMakeX
#define acdbRegApp gcdbRegApp
#define acdbTblNext gcdbTblNext
#define acdbTblSearch gcdbTblSearch
#define acdbNamedObjDict gcdbNamedObjDict
#define acdbDictSearch gcdbDictSearch
#define acdbDictNext gcdbDictNext
#define acdbDictRename gcdbDictRename
#define acdbDictRemove gcdbDictRemove
#define acdbDictAdd gcdbDictAdd
#define acdbTblObjName gcdbTblObjName
#define acdbAngToS gcdbAngToS
#define acdbRawAngToS gcdbRawAngToS
#define acdbRToS gcdbRToS
#define acdbAngToF gcdbAngToF
#define acdbRawAngToF gcdbRawAngToF
#define acdbDisToF gcdbDisToF
#define acdbInters gcdbInters
#define acdbSNValid gcdbSNValid
#define ads_queueexpr gds_queueexpr
#define acedGetString gcedGetString
#define acedGetKword gcedGetKword
#define acedGetInput gcedGetInput
#define acutNewString gcutNewString
#define acedGetFullInput gcedGetFullInput
#define acedGetFullKword gcedGetFullKword
#define acedGetFullString gcedGetFullString
#define AcEdCommandRejector GcEdCommandRejector
#define acedRegisterCommandRejector gcedRegisterCommandRejector
#define acedUnRegisterCommandRejector gcedUnRegisterCommandRejector
#define acedSetEnv    gcedSetEnv
#define adsw_hwndAcad  gdsw_hwndGcad
#define AcSelectionPreview GcSelectionPreview
#define AdInt32 GdInt32