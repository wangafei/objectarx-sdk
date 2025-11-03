#pragma once

#define gds_malloc	gcad_malloc
#define gds_free	gcad_free
#define gds__msize	gcad__msize
#define gds_realloc gcad_realloc
#define gds_calloc	gcad_calloc
#define gds_strdup	gcad__strdup
#define gds__strdup	gcad__strdup

#define gds_getfullinput	gcedGetFullInput
#define gds_getfullkword  gcedGetFullKword
#define gds_getfullstring gcedGetFullString
#define	gds_getappname	gcedGetAppName
#define	gds_update	gcedUpdate
#define	gds_command	gcedCommand
#define	gds_cmd	        gcedCmd
#define	gds_regfunc	gcedRegFunc
#define	gds_usrbrk	gcedUsrBrk
#define	gds_defun	gcedDefun
#define	gds_setfunhelp	gcedSetFunHelp
#define	gds_undef	gcedUndef
#define	gds_getfuncode	gcedGetFunCode
#define	gds_getargs	gcedGetArgs
#define	gds_retlist	gcedRetList
#define	gds_retval	gcedRetVal
#define	gds_retpoint	gcedRetPoint
#define	gds_retstr	gcedRetStr
#define	gds_retname	gcedRetName
#define	gds_retint	gcedRetInt
#define	gds_retreal	gcedRetReal
#define	gds_rett	gcedRetT
#define	gds_retnil	gcedRetNil
#define	gds_retvoid	gcedRetVoid
#define	gds_entsel	gcedEntSel
#define	gds_nentsel	gcedNEntSel
#define	gds_nentselp	gcedNEntSelP
#define	gds_ssget	gcedSSGet

#define	gds_ssgetfirst	gcedSSGetFirst
#define	gds_sssetfirst	gcedSSSetFirst

#define	gds_ssfree	gcedSSFree
#define	gds_sslength	gcedSSLength
#define	gds_ssadd	gcedSSAdd
#define	gds_ssdel	gcedSSDel
#define	gds_ssmemb	gcedSSMemb
#define	gds_ssname	gcedSSName
#define	gds_ssnamex	gcedSSNameX
#define	gds_ssGetKwordCallbackPtr	gcedSSGetKwordCallbackPtr
#define	gds_ssSetKwordCallbackPtr	gcedSSSetKwordCallbackPtr
#define	gds_ssGetOtherCallbackPtr	gcedSSGetOtherCallbackPtr
#define	gds_ssSetOtherCallbackPtr	gcedSSSetOtherCallbackPtr
#define	gds_setvar	gcedSetVar
#define	gds_initget	gcedInitGet
#define	gds_getsym	gcedGetSym
#define	gds_putsym	gcedPutSym
#define	gds_help	gcedHelp
#define	gds_fnsplit	gcedFNSplit
#define	gds_trans	gcedTrans
#define	gds_arxloaded	gcedArxLoaded
#define	gds_arxload	gcedArxLoad
#define	gds_arxunload	gcedArxUnload
#define	gds_invoke	gcedInvoke
#define	gds_getvar	gcedGetVar
#define	gds_findfile	gcedFindFile
#define	gds_agetenv	gcedGetEnv
#define	gds_asetenv	gcedSetEnv
#define	gds_getenv	gcedGetEnv
#define	gds_setenv	gcedSetEnv
#define	gds_agetcfg	gcedGetCfg
#define	gds_asetcfg	gcedSetCfg
#define	gds_getcfg	gcedGetCfg
#define	gds_setcfg	gcedSetCfg
#define	gds_getstring	gcedGetString
#define	gds_getstringb	gcedGetStringB
#define	gds_menucmd	gcedMenuCmd
#define	gds_prompt	gcedPrompt
#define	gds_alert	gcedAlert
#define	gds_getangle	gcedGetAngle
#define	gds_getcorner	gcedGetCorner
#define	gds_getdist	gcedGetDist
#define	gds_getorient	gcedGetOrient
#define	gds_getpoint	gcedGetPoint
#define	gds_getint	gcedGetInt
#define	gds_getkword	gcedGetKword
#define	gds_getreal	gcedGetReal
#define	gds_getinput	gcedGetInput
#define	gds_vports	gcedVports
#define	gds_textscr	gcedTextScr
#define	gds_graphscr	gcedGraphScr
#define	gds_textpage	gcedTextPage
#define	gds_redraw	gcedRedraw
#define	gds_osnap	gcedOsnap
#define	gds_grread	gcedGrRead
#define	gds_grtext	gcedGrText
#define	gds_grdraw	gcedGrDraw
#define	gds_grvecs	gcedGrVecs
#define	gds_xformss	gcedXformSS
#define	gds_draggen	gcedDragGen
#define	gds_setview	gcedSetView
#define	gds_getfiled	gcedGetFileD
#define gds_getfilenavdialog gcedGetFileNavDialog
#define	gds_textbox	gcedTextBox
#define	gds_tablet	gcedTablet
#define	gds_getcname	gcedGetCName


#define	gds_xdroom	gcdbXdRoom
#define	gds_xdsize	gcdbXdSize

#ifdef __STDC__
#define gds_name_set(from, to)  (memcpy(to, from, sizeof(ads_name)))
#define gds_point_set(from,to)  (memcpy(to, from, sizeof(ads_point)))
#else
#define gds_name_set(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define gds_point_set(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif

//gds_names
#define gds_name_clear(name)    name[0] = name[1] = 0
#define gds_name_nil(name)      (name[0] == 0 && name[1] == 0)
#define gds_name_equal(name1, name2)  (name1[0]==name2[0] && name1[1]==name2[1])


#define	gds_entdel	gcdbEntDel
#define	gds_entgetx	gcdbEntGetX
#define	gds_entget	gcdbEntGet
#define	gds_entlast	gcdbEntLast
#define	gds_entnext	gcdbEntNext
#define	gds_entupd	gcdbEntUpd
#define	gds_entmod	gcdbEntMod
#define	gds_entmake	gcdbEntMake
#define	gds_entmakex	gcdbEntMakeX
#define	gds_tblnext	gcdbTblNext
#define	gds_tblsearch	gcdbTblSearch
#define	gds_namedobjdict	gcdbNamedObjDict
#define	gds_dictsearch	gcdbDictSearch
#define	gds_dictnext	gcdbDictNext
#define	gds_dictrename	gcdbDictRename
#define	gds_dictremove	gcdbDictRemove
#define	gds_dictadd	gcdbDictAdd
#define	gds_tblobjname	gcdbTblObjName
#define	gds_handent	gcdbHandEnt
#define	gds_inters	gcdbInters
#define	gds_snvalid	gcdbSNValid
#define	gds_xstrsave	gcdbXStrSave
#define	gds_xstrcase	gcdbXStrCase
#define	gds_regapp	gcdbRegApp
#define	gds_fail	gcdbFail
#define	gds_angtos	gcdbAngToS
#define	gds_rtos	gcdbRToS
#define	gds_angtof	gcdbAngToF
#define	gds_distof	gcdbDisToF
#define gds_regappx(appname, xsave12)   gcdbRegApp(appname)

#define	gds_printf	gcutPrintf
#define	gds_cvunit	gcutCvUnit
#define	gds_wcmatch	gcutWcMatch
#define	gds_angle	gcutAngle
#define	gds_distance	gcutDistance
#define	gds_polar	gcutPolar
#define	gds_isalpha	gcutIsAlpha
#define	gds_isupper	gcutIsUpper
#define	gds_islower	gcutIsLower
#define	gds_isdigit	gcutIsDigit
#define	gds_isxdigit	gcutIsXDigit
#define	gds_isspace	gcutIsSpace
#define	gds_ispunct	gcutIsPunct
#define	gds_isalnum	gcutIsAlNum
#define	gds_isprint	gcutIsPrint
#define	gds_isgraph	gcutIsGraph
#define	gds_iscntrl	gcutIsCntrl
#define	gds_toupper	gcutToUpper
#define	gds_tolower	gcutToLower
#define	gds_newrb	gcutNewRb
#define	gds_relrb	gcutRelRb
#define	gds_buildlist	gcutBuildList
