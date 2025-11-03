#pragma once
#include "adsdef.h"
#include "acmem.h"
#include "AdAChar.h"
#include "../grx/gcedgds.h"
#include "../grx/gcdbgds.h"
#include "../grx/gcedgdsTodo.h"

#define AdInt32 HcInt32
#define HcInt32 OdInt32

#define acrx_abort  gcedAbort

#define acedGetAppName  gds_getappname
#define	gds_getappname  gcedGetAppName

#define acedUpdate  gds_update

#define adsw_acadMainWnd  gds_getmainhwnd
#define adsw_hwndAcad	    gdsw_hwndGcad

#define adsw_acadDocWnd   gds_getviewhwnd

#define acedCommand  gds_command
#define	gds_command  gcedCommand

#define acedCmd  gds_cmd
#define	gds_cmd  gcedCmd

#define acedRegFunc  gds_regfunc
#define	gds_regfunc  gcedRegFunc

#define acedUsrBrk  gds_usrbrk
#define	gds_usrbrk  gcedUsrBrk

#define acedDefun  gds_defun
#define	gds_defun  gcedDefun

#define acedSetFunHelp  gds_setfunhelp
#define	gds_setfunhelp  gcedSetFunHelp

#define acedUndef  gds_undef
#define	gds_undef  gcedUndef

#define acedGetFunCode  gds_getfuncode
#define	gds_getfuncode  gcedGetFunCode

#define acedGetArgs  gds_getargs
#define	gds_getargs  gcedGetArgs

#define acedRetList  gds_retlist
#define	gds_retlist  gcedRetList

#define acedRetVal  gds_retval
#define	gds_retval  gcedRetVal

#define acedRetPoint  gds_retpoint
#define	gds_retpoint  gcedRetPoint

#define acedRetStr  gds_retstr
#define	gds_retstr  gcedRetStr

#define acedRetName  gds_retname
#define	gds_retname  gcedRetName

#define acedRetInt  gds_retint
#define	gds_retint  gcedRetInt

#define acedRetReal  gds_retreal
#define	gds_retreal  gcedRetReal

#define acedRetT  gds_rett
#define	gds_rett  gcedRetT

#define acedRetNil  gds_retnil
#define	gds_retnil  gcedRetNil

#define acedRetVoid  gds_retvoid
#define	gds_retvoid  gcedRetVoid

#define acedEntSel  gds_entsel
#define	gds_entsel  gcedEntSel

#define acedNEntSel  gds_nentsel
#define	gds_nentsel  gcedNEntSel

#define acedNEntSelP  gds_nentselp
#define	gds_nentselp  gcedNEntSelP

#define acedSSGet  gds_ssget
#define	gds_ssget  gcedSSGet

#define acedSSGetFirst  gds_ssgetfirst
#define	gds_ssgetfirst  gcedSSGetFirst

#define acedSSSetFirst  gds_sssetfirst
#define	gds_sssetfirst  gcedSSSetFirst

#define acedSSFree  gds_ssfree
#define	gds_ssfree  gcedSSFree

#define acedSSLength  gds_sslength
#define	gds_sslength  gcedSSLength

#define acedSSAdd  gds_ssadd
#define	gds_ssadd  gcedSSAdd

#define acedSSDel  gds_ssdel
#define	gds_ssdel  gcedSSDel

#define acedSSMemb  gds_ssmemb
#define	gds_ssmemb  gcedSSMemb

#define acedSSName  gds_ssname
#define	gds_ssname  gcedSSName

#define acedSSNameX  gds_ssnamex
#define	gds_ssnamex  gcedSSNameX

#define acedSSGetKwordCallbackPtr  gcedSSGetKwordCallbackPtr

#define acedSSSetKwordCallbackPtr  gcedSSSetKwordCallbackPtr

#define acedSSGetOtherCallbackPtr  gcedSSGetOtherCallbackPtr

#define acedSSSetOtherCallbackPtr  gcedSSSetOtherCallbackPtr

#define acedTrans  gds_trans
#define	gds_trans  gcedTrans

#define acedSetVar  gds_setvar
#define	gds_setvar  gcedSetVar

#define acedInitGet  gds_initget
#define	gds_initget  gcedInitGet

#define acedGetSym  gds_getsym
#define	gds_getsym  gcedGetSym

#define acedPutSym  gds_putsym
#define	gds_putsym  gcedPutSym

#define acedHelp  gds_help
#define	gds_help  gcedHelp

#define acedHelpForExternal  gds_helpforexternal
#define gds_helpforexternal  gcedHelpForExternal

#define acedFNSplit  gds_fnsplit
#define	gds_fnsplit  gcedFNSplit

#define acedArxLoaded  gds_arxloaded
#define	gds_arxloaded  gcedArxLoaded

#define acedArxLoad  gds_arxload
#define	gds_arxload  gcedArxLoad

#define acedArxUnload  gds_arxunload
#define	gds_arxunload  gcedArxUnload

#define acedInvoke  gds_invoke
#define	gds_invoke  gcedInvoke

#define acedGetVar  gds_getvar
#define	gds_getvar  gcedGetVar

#define acedFindFile  gds_findfile
#define	gds_findfile  gcedFindFile

#define acedGetEnv  gds_agetenv
#define	gds_agetenv  gcedGetEnv

#define acedSetEnv  gds_asetenv
#define	gds_asetenv  gcedSetEnv

#define acedGetCfg  gds_getcfg
#define	gds_getcfg  gcedGetCfg

#define acedSetCfg  gds_asetcfg
#define	gds_asetcfg  gcedSetCfg

#define acedGetString  gds_getstring
#define	gds_getstring  gcedGetString

#define acedGetStringB  gds_getstringb
#define	gds_getstringb  gcedGetStringB

#define acedMenuCmd  gds_menucmd
#define	gds_menucmd  gcedMenuCmd

#define acedPrompt  gds_prompt
#define	gds_prompt  gcedPrompt

#define acedAlert  gds_alert
#define	gds_alert  gcedAlert

#define acedGetAngle  gds_getangle
#define	gds_getangle  gcedGetAngle

#define acedGetCorner  gds_getcorner
#define	gds_getcorner  gcedGetCorner

#define acedGetDist  gds_getdist
#define	gds_getdist  gcedGetDist

#define acedGetOrient  gds_getorient
#define	gds_getorient  gcedGetOrient

#define acedGetPoint  gds_getpoint
#define	gds_getpoint  gcedGetPoint

#define acedGetInt  gds_getint
#define	gds_getint  gcedGetInt

#define acedGetKword  gds_getkword
#define	gds_getkword  gcedGetKword


#define acedGetReal  gds_getreal
#define	gds_getreal  gcedGetReal

#define acedGetInput  gds_getinput
#define	gds_getinput  gcedGetInput

#define acedVports  gds_vports
#define	gds_vports  gcedVports

#define acedTextScr  gds_textscr
#define	gds_textscr  gcedTextScr

#define acedGraphScr  gds_graphscr
#define	gds_graphscr  gcedGraphScr

#define acedTextPage  gds_textpage
#define	gds_textpage  gcedTextPage

#define acedRedraw  gds_redraw
#define	gds_redraw  gcedRedraw

#define acedOsnap  gds_osnap
#define	gds_osnap  gcedOsnap

#define acedGrRead  gds_grread
#define	gds_grread  gcedGrRead

#define acedGrText  gds_grtext
#define	gds_grtext  gcedGrText

#define acedGrDraw  gds_grdraw
#define	gds_grdraw  gcedGrDraw

#define acedGrVecs  gds_grvecs
#define	gds_grvecs  gcedGrVecs

#define acedXformSS  gds_xformss
#define	gds_xformss  gcedXformSS

#define acedDragGen  gds_draggen
#define	gds_draggen  gcedDragGen

#define acedSetView  gds_setview
#define	gds_setview  gcedSetView

#define acedGetFileD  gds_getfiled
#define	gds_getfiled  gcedGetFileD

#define acedGetFileNavDialog  gds_getfilenavdialog
#define gds_getfilenavdialog  gcedGetFileNavDialog

#define acedTextBox  gds_textbox
#define	gds_textbox  gcedTextBox

#define acedTablet  gds_tablet
#define	gds_tablet  gcedTablet

#define acedGetCName  gds_getcname
#define	gds_getcname  gcedGetCName

#define acedEatCommandThroat  gcedEatCommandThroat

#define acdbEntDel  gds_entdel
#define	gds_entdel  gcdbEntDel

#define acdbEntGetX  gds_entgetx
#define	gds_entgetx  gcdbEntGetX

#define acdbEntGet  gds_entget
#define	gds_entget  gcdbEntGet

#define acdbEntLast  gds_entlast
#define	gds_entlast  gcdbEntLast

#define acdbEntNext  gds_entnext
#define	gds_entnext  gcdbEntNext

#define acdbEntUpd  gds_entupd
#define	gds_entupd  gcdbEntUpd

#define acdbEntMod  gds_entmod
#define	gds_entmod  gcdbEntMod

#define acdbEntMake  gds_entmake
#define	gds_entmake  gcdbEntMake

#define acdbEntMakeX  gds_entmakex
#define	gds_entmakex  gcdbEntMakeX

#define acdbAngToS gds_angtos
#define gds_angtos gcdbAngToS

#define acdbRegApp  gds_regapp
#define	gds_regapp  gcdbRegApp

#define acdbTblNext  gds_tblnext
#define	gds_tblnext  gcdbTblNext

#define acdbTblSearch  gds_tblsearch
#define	gds_tblsearch  gcdbTblSearch

#define acdbNamedObjDict  gds_namedobjdict
#define	gds_namedobjdict  gcdbNamedObjDict

#define acdbDictSearch  gds_dictsearch
#define	gds_dictsearch  gcdbDictSearch

#define acdbDictNext  gds_dictnext
#define	gds_dictnext  gcdbDictNext

#define acdbDictRename  gds_dictrename
#define	gds_dictrename  gcdbDictRename

#define acdbDictRemove  gcdbDictRemove

#define acdbDictAdd  gds_dictadd
#define	gds_dictadd  gcdbDictAdd

#define acdbTblObjName  gds_tblobjname
#define	gds_tblobjname  gcdbTblObjName

#define acdbRawAngToS  gds_rawangtos
#define gds_rawangtos  gcdbRawAngToS

#define acdbRToS  gds_rtos
#define	gds_rtos  gcdbRToS

#define acdbAngToF  gds_angtof
#define	gds_angtof  gcdbAngToF

#define acdbRawAngToF  gcdbRawAngToF

#define acdbDisToF  gds_distof
#define	gds_distof  gcdbDisToF

#define acdbInters  gds_inters
#define	gds_inters  gcdbInters

#define acdbSNValid  gds_snvalid
#define	gds_snvalid  gcdbSNValid

#define ads_queueexpr  gds_queueexpr

#define acedGetFullInput  gds_getfullinput
#define gds_getfullinput  gcedGetFullInput

#define acedGetFullKword  gds_getfullkword
#define gds_getfullkword  gcedGetFullKword

#define acedGetFullString  gds_getfullstring
#define gds_getfullstring  gcedGetFullString

#define acedSSNameXEx  gcedSSNameXEx 