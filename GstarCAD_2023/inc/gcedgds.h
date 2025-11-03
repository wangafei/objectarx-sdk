/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcedgds_h
#define _gcedgds_h 1

#ifdef __cplusplus
#include "gsoft.h"
#endif

#include "gdsdef.h"
#include "gccoredefs.h"
#include "gcbasedefs.h"
#include "gcmem.h"
#include "GdGChar.h"

#pragma pack (push, 8)
#ifdef GdInt32
#undef GdInt32
#endif
#ifdef __cplusplus
#define GdInt32 Gsoft::Int32
#else
#define GdInt32 long
#endif

GCCORE_PORT const GCHAR *  gcedGetAppName();
GCCORE_PORT int            gcedUpdate(int vport, gds_point p1, gds_point p2);

#if defined(_WINDEF_) || defined(_GSOFT_MAC_)
#if (defined(_GSOFT_CROSS_PLATFORM_) && defined(GCCORE_FABRIC) && !defined(CRX_API)) || !defined(_GSOFT_CROSS_PLATFORM_)
GCAD_PORT HWND           gdsw_gcadMainWnd();
#ifndef gdsw_hwndGcad
#define gdsw_hwndGcad gdsw_gcadMainWnd()
#endif

GCAD_PORT  HWND gdsw_gcadDocWnd();
#endif
#endif  

#define gcedCommand MustSwitchTo_gcedCommandC_or_gcedCommandS - - !
#define gcedCmd MustSwitchTo_gcedCmdC_or_gcedCmdS - - !

GCCORE_PORT int            gcedRegFunc(int(*fhdl) (void), int fcode);

GCCORE_PORT int            gcedUsrBrk(void);

GCCORE_PORT int     gcedDefun(const GCHAR *pszName, int nFuncNum);
GCCORE_PORT int     gcedDefunEx(const GCHAR *pszGlobalName,
  const GCHAR *pszLocalName, int nFuncNum);

GCAD_PORT int            gcedSetFunHelp(const GCHAR* pszFunctionName,
  const GCHAR* pszHelpfile,
  const GCHAR* pszTopic, int iCmd);

GCCORE_PORT int            gcedUndef(const GCHAR *sname, int nFuncNum);

GCCORE_PORT int            gcedGetFunCode(void);
GCCORE_PORT struct resbuf *gcedGetArgs(void);

GCCORE_PORT int            gcedRetList(const struct resbuf *rbuf);
GCCORE_PORT int            gcedRetVal(const struct resbuf *rbuf);
GCCORE_PORT int            gcedRetPoint(const gds_point pt);
GCCORE_PORT int            gcedRetStr(const GCHAR *s);
GCCORE_PORT int            gcedRetName(const gds_name aname, int type);
GCCORE_PORT int            gcedRetInt(int ival);
GCCORE_PORT int            gcedRetReal(gds_real rval);
GCCORE_PORT int            gcedRetT(void);
GCCORE_PORT int            gcedRetNil(void);
GCCORE_PORT int            gcedRetVoid(void);

GCCORE_PORT int            gcedEntSel(const GCHAR *str, gds_name entres,
  gds_point ptres);
#ifdef __cplusplus
class GcSelectionPreview;
GCCORE_PORT int            gcedEntSel(const GCHAR *str, gds_name entres,
  gds_point ptres, GcSelectionPreview *pSelectionPreview);
#endif
GCCORE_PORT int            gcedNEntSel(const GCHAR *str, gds_name entres,
  gds_point ptres, gds_point xformres[4],
  struct resbuf **refstkres);
GCCORE_PORT int            gcedNEntSelP(const GCHAR *str, gds_name entres,
  gds_point ptres, int pickflag,
  gds_matrix xformres,
  struct resbuf **refstkres);
GCCORE_PORT int            gcedSSGet(const GCHAR *str, const void *pt1,
  const void *pt2, const struct resbuf *filter,
  gds_name ss);
#ifdef __cplusplus
GCCORE_PORT int            gcedSSGet(const GCHAR *str, const void *pt1,
  const void *pt2, const struct resbuf *filter,
  gds_name ss, GcSelectionPreview *pSelectionPreview);
#endif
GCCORE_PORT int            gcedSSGetFirst(struct resbuf** gset, struct resbuf** pset);
GCCORE_PORT int            gcedSSSetFirst(const gds_name pset, const gds_name unused);
GCCORE_PORT int            gcedSSFree(const gds_name sname);
#ifdef __cplusplus
GCCORE_PORT int            gcedSSLength(const gds_name sname, Gsoft::Int32 *len);
#else
GCCORE_PORT int            gcedSSLength(const gds_name sname, long *len);
#endif
GCCORE_PORT int            gcedSSAdd(const gds_name ename, const gds_name sname,
  gds_name result);
GCCORE_PORT int            gcedSSDel(const gds_name ename, const gds_name ss);
GCCORE_PORT int            gcedSSMemb(const gds_name ename, const gds_name ss);
GCCORE_PORT int            gcedSSName(const gds_name ss, int i, gds_name entres);
GCCORE_PORT int            gcedSSNameX(struct resbuf **rbpp, const gds_name ss,
  int i);
GCCORE_PORT int            gcedSSNameXEx(struct resbuf **rbpp, const gds_name ss,
  int i, unsigned int flags);

GCCORE_PORT int            gcedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const GCHAR*));
GCCORE_PORT int            gcedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const GCHAR*));
GCCORE_PORT int            gcedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const GCHAR*));
GCCORE_PORT int            gcedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const GCHAR*));

GCCORE_PORT int            gcedTrans(const gds_point pt, const struct resbuf *from,
  const struct resbuf *to, int disp,
  gds_point result);

GCCORE_PORT int            gcedSetVar(const GCHAR *sym, const struct resbuf *val);
GCCORE_PORT int            gcedInitGet(int val, const GCHAR *kwl);

GCCORE_PORT int            gcedGetSym(const GCHAR *sname, struct resbuf **value);
GCCORE_PORT int            gcedPutSym(const GCHAR *sname, struct resbuf *value);

GCAD_PORT   int            gcedHelp(const GCHAR* szFilename, const GCHAR* szTopic, int iCmd);
GCCORE_PORT int            gcedHelpForExternal(const GCHAR *pszFunctionName);

GCCORE_PORT int            gcedFNSplit(const GCHAR *pathToSplit,
  GCHAR *prebuf, size_t nPreBufLen,
  GCHAR *namebuf, size_t nNameBufLen,
  GCHAR *extbuf, size_t nExtBufLen);

#define HELP_CONTENTS     0x0003L  
#define HELP_HELPONHELP   0x0004L  
#define HELP_PARTIALKEY   0x0105L  

GCCORE_PORT struct resbuf  *gcedGrxLoaded(void);
GCCORE_PORT int            gcedGrxLoad(const GCHAR *app);
GCCORE_PORT int            gcedGrxUnload(const GCHAR *app);

GCCORE_PORT int            gcedInvoke(const struct resbuf *args,
  struct resbuf **result);
GCCORE_PORT int            gcedGetVar(const GCHAR *sym, struct resbuf *result);
GCCORE_PORT int            gcedFindFile(const GCHAR *fname, GCHAR *result, size_t nBufLen);
GCCORE_PORT int            gcedFindTrustedFile(const GCHAR *fname, GCHAR *result, size_t nBufLen);

GCCORE_PORT int            gcedGetEnv(const GCHAR *sym, GCHAR  *var, size_t nBufLen);
GCCORE_PORT int            gcedSetEnv(const GCHAR *sym, const GCHAR *val);

GCCORE_PORT int            gcedGetCfg(const GCHAR *sym, GCHAR  *var, size_t len);
GCCORE_PORT int            gcedSetCfg(const GCHAR *sym, const GCHAR *val);

GCCORE_PORT int            gcedGetString(int cronly, const GCHAR *prompt,
  GCHAR *result, size_t bufsize);

GCCORE_PORT int            gcedMenuCmd(const GCHAR *str);
GCCORE_PORT int            gcedPrompt(const GCHAR *str);
GCAD_PORT   int            gcedAlert(const GCHAR *str);

GCCORE_PORT int            gcedGetAngle(const gds_point pt, const GCHAR *prompt,
  gds_real *result);
GCCORE_PORT int            gcedGetCorner(const gds_point pt, const GCHAR *prompt,
  gds_point result);
GCCORE_PORT int            gcedGetDist(const gds_point pt, const GCHAR *prompt,
  gds_real *result);
GCCORE_PORT int            gcedGetOrient(const gds_point pt, const GCHAR *prompt,
  gds_real *result);
GCCORE_PORT int            gcedGetPoint(const gds_point pt, const GCHAR *prompt,
  gds_point result);
GCCORE_PORT int            gcedGetInt(const GCHAR *prompt, int *result);
GCCORE_PORT int            gcedGetKword(const GCHAR *prompt, GCHAR *result, size_t nBufLen);
GCCORE_PORT int            gcedGetReal(const GCHAR *prompt, gds_real *result);
GCCORE_PORT int            gcedGetInput(GCHAR *str, size_t nBufLen);
GCCORE_PORT int            gcedVports(struct resbuf **vlist);

GCAD_PORT   int            gcedTextScr(void);
GCAD_PORT   int            gcedGraphScr(void);
GCAD_PORT   int            gcedTextPage(void);

GCCORE_PORT int            gcedRedraw(const gds_name ent, int mode);
GCCORE_PORT int            gcedOsnap(const gds_point pt, const GCHAR *mode,
  gds_point result);
GCCORE_PORT int            gcedGrRead(int track, int *type, struct resbuf *result);
GCCORE_PORT int            gcedGrText(int box, const GCHAR *text, int hl);
GCCORE_PORT int            gcedGrDraw(const gds_point from, const gds_point to,
  int color, int hl);
GCCORE_PORT int            gcedGrVecs(const struct resbuf *vlist, gds_matrix mat);
GCCORE_PORT int            gcedXformSS(const gds_name ssname,
  gds_matrix genmat);
GCCORE_PORT int            gcedDragGen(const gds_name ss, const GCHAR *pmt, int cursor,
  int(*scnf) (gds_point pt, gds_matrix mt),
  gds_point p);
GCCORE_PORT int            gcedSetView(const struct resbuf *view, int vport);

GCAD_PORT   int            gcedGetFileD(const GCHAR *title, const GCHAR *defawlt,
  const GCHAR *ext, int flags,
  struct resbuf *result);
GCAD_PORT   int            gcedGetFileNavDialog(const GCHAR *title, const GCHAR *defawlt,
  const GCHAR *ext, const GCHAR *dlgname, int flags,
  struct resbuf **result);

GCCORE_PORT int            gcedTextBox(const struct resbuf *args,
  gds_point pt1, gds_point pt2);

GCCORE_PORT int            gcedTablet(const struct resbuf *args,
  struct resbuf **result);

GCCORE_PORT int            gcedGetCName(const GCHAR *cmd, GCHAR **result);

GCCORE_PORT int            gcedEatCommandThroat(void);

GCCORE_PORT int            gcdbEntDel(const gds_name ent);
GCCORE_PORT struct resbuf *gcdbEntGetX(const gds_name ent, const struct resbuf *args);
GCCORE_PORT struct resbuf *gcdbEntGet(const gds_name ent);
GCCORE_PORT int            gcdbEntLast(gds_name result);
GCCORE_PORT int            gcdbEntNext(const gds_name ent, gds_name result);
GCCORE_PORT int            gcdbEntUpd(const gds_name ent);
GCCORE_PORT int            gcdbEntMod(const struct resbuf *ent);
GCCORE_PORT int            gcdbEntMake(const struct resbuf *ent);
GCCORE_PORT int            gcdbEntMakeX(const struct resbuf *entm, gds_name result);

GCCORE_PORT int            gcdbRegApp(const GCHAR *appname);
GCCORE_PORT struct resbuf *gcdbTblNext(const GCHAR *tblname, int rewind);
GCCORE_PORT struct resbuf *gcdbTblSearch(const GCHAR *tblname, const GCHAR *sym,
  int setnext);
GCCORE_PORT int            gcdbNamedObjDict(gds_name result);
GCCORE_PORT struct resbuf *gcdbDictSearch(const gds_name dict, const GCHAR* sym,
  int setnext);
GCCORE_PORT struct resbuf *gcdbDictNext(const gds_name dict, int rewind);
GCCORE_PORT int            gcdbDictRename(const gds_name dictname, const GCHAR* oldsym,
  const GCHAR* newsym);
GCCORE_PORT int            gcdbDictRemove(const gds_name dictname, const GCHAR* symname);
GCCORE_PORT int            gcdbDictAdd(const gds_name dictname, const GCHAR* symname,
  const gds_name newobj);

GCCORE_PORT int            gcdbTblObjName(const GCHAR *tblname, const GCHAR *sym,
  gds_name result);

GCCORE_PORT int            gcdbAngToS(gds_real v, int unit, int prec, GCHAR *str, size_t nBufLen);
GCCORE_PORT int            gcdbRawAngToS(gds_real v, int unit, int prec, GCHAR *str, size_t nBufLen);
GCCORE_PORT int            gcdbRToS(gds_real val, int unit, int prec, GCHAR *str, size_t nBufLen);
GCCORE_PORT int            gcdbAngToF(const GCHAR *str, int unit, gds_real *v);
GCCORE_PORT int            gcdbRawAngToF(const GCHAR *str, int unit, gds_real *v);
GCCORE_PORT int            gcdbDisToF(const GCHAR *str, int unit, gds_real *v);
GCCORE_PORT int            gcdbInters(const gds_point from1, const gds_point to1,
  const gds_point from2, const gds_point to2,
  int teston, gds_point result);
GCCORE_PORT int            gcdbSNValid(const GCHAR *tbstr, int pipetest);

GCCORE_PORT int            gds_queueexpr(const GCHAR* expr);

#ifdef __cplusplus

#include "gcadstrc.h"   
#include "GcString.h"

GCCORE_PORT int gcedGetString(int cronly, const GCHAR *prompt, GcString &sResult);
GCCORE_PORT int gcedGetKword(const GCHAR *prompt, GcString & sResult);
GCCORE_PORT int gcedGetInput(GcString &sOut);

GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);

inline int gcedGetFullInput(GCHAR *&pStr)
{
  GcString sOut;
  const int nRet = ::gcedGetInput(sOut);
  ::gcutNewString(sOut.constPtr(), pStr);
  return nRet;
}

inline int gcedGetFullKword(const GCHAR * pString, GCHAR *&pStr)
{
  GcString sOut;
  const int nRet = ::gcedGetKword(pString, sOut);
  ::gcutNewString(sOut.constPtr(), pStr);
  return nRet;
}

inline int gcedGetFullString(int cronly, const GCHAR *pString, GCHAR *&pResult)
{
  GcString sResult;
  const int nRet = ::gcedGetString(cronly, pString, sResult);
  ::gcutNewString(sResult.constPtr(), pResult);
  return nRet;
}

template<size_t nBufLen> inline int gcedGetEnv(const wchar_t *pszName, wchar_t(&buf)[nBufLen])
{
  return ::gcedGetEnv(pszName, buf, nBufLen);
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

template<size_t nBufLen> inline int gcedFindFile(const wchar_t *pszName, wchar_t(&buf)[nBufLen])
{
  return ::gcedFindFile(pszName, buf, nBufLen);
}

template<size_t nBufLen> inline int gcedFindTrustedFile(const wchar_t *pszName,
  wchar_t(&buf)[nBufLen])
{
  return ::gcedFindTrustedFile(pszName, buf, nBufLen);
}

template<size_t nBufLen> inline int gcedGetKword(const wchar_t *pszPrompt, wchar_t(&buf)[nBufLen])
{
  return ::gcedGetKword(pszPrompt, buf, nBufLen);
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

template<size_t nNameBufLen, size_t nExtBufLen> inline int gcedFNSplit(
  const wchar_t *pathToSplit,
  size_t nPre,
  wchar_t(&namebuf)[nNameBufLen],
  wchar_t(&extbuf)[nExtBufLen])
{
  return ::gcedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, extbuf, nExtBufLen);
}

template<size_t nPreBufLen> inline int gcedFNSplit(const wchar_t *pathToSplit,
  wchar_t(&prebuf)[nPreBufLen],
  size_t nName,
  size_t nExt)
{
  return ::gcedFNSplit(pathToSplit, prebuf, nPreBufLen, nullptr, nName, nullptr, nExt);
}

template<size_t nBufLen> inline int gcdbAngToS(gds_real v, int unit, int prec,
  wchar_t(&buf)[nBufLen])
{
  return ::gcdbAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen> inline int gcdbRawAngToS(gds_real v, int unit, int prec,
  wchar_t(&buf)[nBufLen])
{
  return ::gcdbRawAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen> inline int gcdbRToS(gds_real v, int unit, int prec,
  wchar_t(&buf)[nBufLen])
{
  return ::gcdbRToS(v, unit, prec, buf, nBufLen);
}

class GcEdCommandRejector
{
public:
  virtual bool reject(const GCHAR* globalCmdName, const GCHAR* localCmdName) = 0;
};

GCCORE_PORT void gcedRegisterCommandRejector(GcEdCommandRejector* pRejector);
GCCORE_PORT void gcedUnRegisterCommandRejector(GcEdCommandRejector* pRejector);

#endif  

#pragma pack (pop)

#endif  