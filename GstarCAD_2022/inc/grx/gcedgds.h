#pragma once

#include "gcadstd.h"
#include "gdsdef.h"
#include "gcmem.h"
#include "gchar.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack (push, 8)

GCED_DLL_DECL void gcedAbort (const GCHAR * format, ...);
int gds_update(int vport, gds_point p1, gds_point p2);

#if defined(_WINDOWS_)
GCED_DLL_DECL HWND gds_getmainhwnd();
#ifndef gdsw_hwndGcad
	#define gdsw_hwndGcad gds_getmainhwnd()
#endif
GCED_DLL_DECL HWND gds_getviewhwnd();
#endif

GCAP_DLL_DECL int gcedCommand (int rtype, ...);
GCAP_DLL_DECL int gcedCmd(const struct resbuf *rbp);

GCED_DLL_DECL int gcedRegFunc (int (*fhdl) (void), int fcode);

GCED_DLL_DECL int gcedUsrBrk(void);

GCED_DLL_DECL int gcedDefun (const GCHAR *sname, int funcno);
GCED_DLL_DECL int gcedUndef (const GCHAR *sname, int funcno);

GCED_DLL_DECL int gcedSetFunHelp (const GCHAR* pszFunctionName, const GCHAR* pszHelpfile,const GCHAR* pszTopic, int iCmd);
GCED_DLL_DECL int gcedFunHelp (const GCHAR* pszFunctionName);

GCED_DLL_DECL int gcedGetFunCode (void);
GCED_DLL_DECL struct resbuf *gcedGetArgs (void);

GCED_DLL_DECL int gcedRetList (const struct resbuf *rbuf);
GCED_DLL_DECL int gcedRetVal (const struct resbuf *rbuf);
GCED_DLL_DECL int gcedRetPoint (const gds_point pt);
GCED_DLL_DECL int gcedRetStr (const GCHAR *s);
GCED_DLL_DECL int gcedRetName (const gds_name aname, int type);
GCED_DLL_DECL int gcedRetInt (int ival);
GCED_DLL_DECL int gcedRetReal (gds_real rval);
GCED_DLL_DECL int gcedRetT (void);
GCED_DLL_DECL int gcedRetNil (void);
GCED_DLL_DECL int gcedRetVoid (void);

GCED_DLL_DECL int gcedEntSel (const GCHAR *str, gds_name entres,gds_point ptres);
GCED_DLL_DECL int gcedNEntSel(const GCHAR *str, gds_name entres,gds_point ptres, gds_point xformres[4],struct resbuf **refstkres);
GCED_DLL_DECL int gcedNEntSelP (const GCHAR *str,gds_name entres,gds_point ptres, int pickflag,gds_matrix xformres,struct resbuf **refstkres);
GCED_DLL_DECL int gcedSSGet (const GCHAR *str, const void *pt1, const void *pt2, const struct resbuf *filter,gds_name ss);
GCED_DLL_DECL int gcedSSGetFirst (struct resbuf** gset, struct resbuf** pset);
GCED_DLL_DECL int gcedSSSetFirst (const gds_name pset, const gds_name unused);

GCED_DLL_DECL int gcedNEntSelPEx(const GCHAR *str,gds_name entres,gds_point ptres, int pickflag,gds_matrix xformres,struct resbuf **refstkres, unsigned int uTransSpaceFlag, INT_PTR* gsmarker);

GCED_DLL_DECL int gcedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const GCHAR*));
GCED_DLL_DECL int gcedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const GCHAR*));
GCED_DLL_DECL int gcedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const GCHAR*));
GCED_DLL_DECL int gcedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const GCHAR*));
 
GCED_DLL_DECL int gcedTrans(const gds_point pt, const struct resbuf *from, const struct resbuf *to, int disp, gds_point result);

GCED_DLL_DECL int gcedSetVar (const GCHAR *sym, const struct resbuf *val);
GCED_DLL_DECL int gcedGetVar (const GCHAR *sym, struct resbuf *result);

GCED_DLL_DECL int gcedInitGet (int val, const GCHAR *kwl);

GCED_DLL_DECL int gcedGetSym (const GCHAR *sname, struct resbuf **value);
GCED_DLL_DECL int gcedPutSym (const GCHAR *sname, struct resbuf *value);

GCED_DLL_DECL int gcedHelp (const GCHAR* szFilename, const GCHAR* szTopic, int iCmd);

GCED_DLL_DECL int gcedFNSplit(const GCHAR *pathToSplit,
  GCHAR *prebuf, size_t nPreBufLen,
  GCHAR *namebuf, size_t nNameBufLen,
  GCHAR *extbuf, size_t nExtBufLen);

#define HELP_CONTENTS     0x0003L
#define HELP_HELPONHELP   0x0004L
#define HELP_PARTIALKEY   0x0105L

GCED_DLL_DECL struct resbuf  *gcedArxLoaded (void);
GCED_DLL_DECL int gcedArxLoad (const GCHAR *app);
GCED_DLL_DECL int gcedArxUnload (const GCHAR *app);
GCED_DLL_DECL int gcedInvoke (const struct resbuf *args,struct resbuf **result);

GCED_DLL_DECL int gcedFindFile (const GCHAR *fname, GCHAR *result, size_t nBufLen);

GCED_DLL_DECL int gcedGetEnv (const GCHAR *sym, GCHAR  *var, size_t nBufLen);
GCED_DLL_DECL int gcedSetEnv (const GCHAR *sym, const GCHAR *val);

GCED_DLL_DECL int gcedGetCfg(const GCHAR *sym, GCHAR* val, int len);
GCED_DLL_DECL int gcedSetCfg(const GCHAR *sym, const GCHAR *val);

GCED_DLL_DECL int gcedGetString (int cronly, const GCHAR *prompt, GCHAR *result, size_t bufsize);

GCED_DLL_DECL int gcedMenuCmd (const GCHAR *str);
GCED_DLL_DECL int gcedPrompt (const GCHAR *str);

GCAD_DLL_DECL int gcedAlert (const GCHAR *str);

GCED_DLL_DECL int gcedSSFree	(const gds_name sname);
#ifdef __cplusplus
GCED_DLL_DECL int gcedSSLength  (const gds_name sname, Hccad::Int32 *len);
#else
GCED_DLL_DECL int gcedSSLength	(const gds_name sname, long *len);
#endif
GCED_DLL_DECL int gcedSSAdd	(const gds_name ename, const gds_name sname,gds_name result);
GCED_DLL_DECL int gcedSSDel	(const gds_name ename, const gds_name ss);
GCED_DLL_DECL int gcedSSMemb	(const gds_name ename, const gds_name ss);
GCED_DLL_DECL int gcedSSName	(const gds_name ss, long i, gds_name entres);
GCED_DLL_DECL int gcedSSNameX	(struct resbuf **rbpp, const gds_name ss, const long i);

GCED_DLL_DECL int gcedGetAngle (const gds_point pt, const GCHAR *prompt, gds_real *result);
GCED_DLL_DECL int gcedGetCorner(const gds_point pt, const GCHAR *prompt, gds_point result);
GCED_DLL_DECL int gcedGetDist  (const gds_point pt, const GCHAR *prompt, gds_real *result);
GCED_DLL_DECL int gcedGetOrient(const gds_point pt, const GCHAR *prompt, gds_real *result);
GCED_DLL_DECL int gcedGetPoint (const gds_point pt, const GCHAR *prompt, gds_point result);
GCED_DLL_DECL int gcedGetInt (const GCHAR *prompt, int *result);
GCED_DLL_DECL int gcedGetKword (const GCHAR *prompt, GCHAR *result, size_t nBufLen);
GCED_DLL_DECL int gcedGetReal (const GCHAR *prompt, gds_real *result);
GCED_DLL_DECL int gcedGetInput(GCHAR *str, size_t nBufLen);
GCED_DLL_DECL int gcedVports (struct resbuf **vlist);

GCED_DLL_DECL int gcedNumberOfViewports();

GCAD_DLL_DECL int gcedTextScr (void);
GCAD_DLL_DECL int gcedGraphScr(void);
GCAD_DLL_DECL int gcedTextPage(void);

GCED_DLL_DECL int gcedRedraw (const gds_name ent, int mode);
GCED_DLL_DECL int gcedOsnap  (const gds_point pt, const GCHAR *mode, gds_point result);
GCED_DLL_DECL int gcedGrRead (int track, int *type, struct resbuf *result);
GCED_DLL_DECL int gcedGrText (int box, const GCHAR *text, int hl);
GCED_DLL_DECL int gcedGrDraw (const gds_point from, const gds_point to, int color, int hl);
GCED_DLL_DECL int gcedGrVecs (const struct resbuf *vlist, gds_matrix mat);
GCED_DLL_DECL int gcedXformSS(const gds_name ssname, gds_matrix genmat);
GCED_DLL_DECL int gcedDragGen(const gds_name ss, const GCHAR *pmt, int cursor, int (*scnf) (gds_point pt, gds_matrix mt), gds_point p);
GCED_DLL_DECL int gcedSetView (const struct resbuf *view, int vport);

GCED_DLL_DECL void gds_regen();

GCED_DLL_DECL int gcedGetFileD (const GCHAR *title, const GCHAR *defawlt, const GCHAR *ext, int flags, struct resbuf *result);
GCED_DLL_DECL int gcedGetFileNavDialog(const GCHAR *title, const GCHAR *defawlt, const GCHAR *ext, const GCHAR *dlgname, int flags,struct resbuf **result);

GCED_DLL_DECL int gcedTextBox (const struct resbuf *args,	gds_point pt1, gds_point pt2);
GCED_DLL_DECL int gcedTablet  (const struct resbuf *args,	struct resbuf **result);

GCED_DLL_DECL int gcedGetCName (const GCHAR *cmd, GCHAR **result);
GCED_DLL_DECL int gds_queueexpr(GCHAR* expr);

GCED_DLL_DECL const GCHAR* gcedGetAppName();

#pragma pack (pop)

#ifdef __cplusplus
}
#endif

#pragma pack (push, 8)
#ifdef __cplusplus
extern "C++" {
GCED_DLL_DECL int gcedGetFullInput(GCHAR *&pStr);
GCED_DLL_DECL int gcedGetFullKword(const GCHAR * pString, GCHAR *&pStr);
GCED_DLL_DECL int gcedGetFullString(int cronly, const GCHAR *pString,
                                 GCHAR *&pResult);

GCED_DLL_DECL int gcedSSNameXEx(struct resbuf **rbpp, const gds_name ss, const long i, unsigned int flags = 0);
}

class GcSelectionPreview;
GCED_DLL_DECL int gcedEntSel(const GCHAR *str, gds_name entres, gds_point ptres, GcSelectionPreview *pSelectionPreview);
GCED_DLL_DECL int gcedSSGet(const GCHAR *str, const void *pt1, const void *pt2, const struct resbuf *filter, gds_name ss, GcSelectionPreview *pSelectionPreview);

template<size_t nBufLen> inline int gcedFindFile(const wchar_t *pszName, wchar_t(&buf)[nBufLen])
{
  return ::gcedFindFile(pszName, buf, nBufLen);
}


template<size_t nBufLen> inline int gcedGetKword(const wchar_t *pszPrompt, wchar_t(&buf)[nBufLen])
{
  return ::gcedGetKword(pszPrompt, buf, nBufLen);
}

template<size_t nBufLen> inline int gcedGetInput(wchar_t(&buf)[nBufLen])
{
  return ::gcedGetInput(buf, nBufLen);
}

template<size_t nBufLen> inline int gcedGetString(int cronly, const wchar_t *prompt,
  wchar_t(&buf)[nBufLen])
{
  return ::gcedGetString(cronly, prompt, buf, nBufLen);
}

template<size_t nBufLen> inline int gcedGetEnv(const wchar_t *pszName, wchar_t(&buf)[nBufLen])
{
  return ::gcedGetEnv(pszName, buf, nBufLen);
}

template<size_t nPreBufLen, size_t nNameBufLen, size_t nExtBufLen> inline int
gcedFNSplit(const wchar_t *pathToSplit,
  wchar_t(&prebuf)[nPreBufLen],
  wchar_t(&namebuf)[nNameBufLen],
  wchar_t(&extbuf)[nExtBufLen])
{
  return ::gcedFNSplit(pathToSplit, prebuf, nPreBufLen, namebuf, nNameBufLen,
    extbuf, nExtBufLen);
}

template<size_t nNameBufLen> inline int gcedFNSplit(const wchar_t *pathToSplit,
  size_t nPre,
  wchar_t(&namebuf)[nNameBufLen],
  size_t nExt)
{
  return ::gcedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, nullptr, nExt);
}


template<size_t nExtBufLen> inline int gcedFNSplit(const wchar_t *pathToSplit,
  size_t nPre,
  size_t nName,
  wchar_t(&extbuf)[nExtBufLen])
{
  return ::gcedFNSplit(pathToSplit, nullptr, nPre, nullptr, nName, extbuf, nExtBufLen);
}

template<size_t nNameBufLen, size_t nExtBufLen> inline int acedFNSplit(
  const wchar_t *pathToSplit,
  size_t nPre,
  wchar_t(&namebuf)[nNameBufLen],
  wchar_t(&extbuf)[nExtBufLen])
{
  return ::acedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, extbuf, nExtBufLen);
}

template<size_t nPreBufLen> inline int acedFNSplit(const wchar_t *pathToSplit,
  wchar_t(&prebuf)[nPreBufLen],
  size_t nName,
  size_t nExt)
{
  return ::acedFNSplit(pathToSplit, prebuf, nPreBufLen, nullptr, nName, nullptr, nExt);
}



#endif

#pragma pack (pop)

