

#ifndef _zcedads_h
#define _zcedads_h 1

#ifdef __cplusplus
    #include "zAdesk.h"
#endif

#include "zadsdef.h"
#include "zaccoredefs.h"
#include "zacbasedefs.h"
#include "zacmem.h"
#include "zAdAChar.h"

#ifdef __cplusplus
#include "zacadstrc.h"
#include "zAcString.h"
#endif

#pragma pack (push, 8)

#ifdef ZdInt32
#undef ZdInt32
#endif
#ifdef __cplusplus
#define ZdInt32 ZSoft::Int32
#else
#define ZdInt32 long
#endif

const ZTCHAR*         zcedGetAppName ();
int            zcedUpdate(int vport, zds_point p1, zds_point p2);

#if defined(_WINDEF_) || defined(_ZSOFT_MAC_)

#if (defined(_ZSOFT_CROSS_PLATFORM_) && defined(ZCCORE_FABRIC) && !defined(CRX_API)) || !defined(_ZSOFT_CROSS_PLATFORM_)
ZCCORE_PORT HWND      zdsw_zcadMainWnd();
#ifndef zdsw_hwndZcad
#define zdsw_hwndZcad zdsw_zcadMainWnd()
#endif

ZCCORE_PORT HWND           zdsw_zcadDocWnd();
#endif
#endif  

#ifndef zcedCommand
#define zcedCommand zcedCommandS
#endif

#ifndef zcedCmd
#define zcedCmd zcedCmdS
#endif

int            zcedRegFunc (int (*fhdl) (void), int fcode);

int            zcedUsrBrk (void);

int            zcedDefun (const ZTCHAR *sname, int nFuncNum);

int			   zcedDefunEx(const ZTCHAR * pszGlobalName, const ZTCHAR * pszLocalName, int nFuncNum);

int            zcedSetFunHelp (const ZTCHAR* pszFunctionName,
                               const ZTCHAR* pszHelpfile,
                               const ZTCHAR* pszTopic, int iCmd);

int            zcedUndef (const ZTCHAR *sname, int nFuncNum);

int            zcedGetFunCode (void);
struct resbuf *zcedGetArgs (void);

int            zcedRetList (const struct resbuf *rbuf);
int            zcedRetVal (const struct resbuf *rbuf);
int            zcedRetPoint (const zds_point pt);
int            zcedRetStr (const ZTCHAR *s);
int            zcedRetName (const zds_name aname, int type);
int            zcedRetInt (int ival);
int            zcedRetReal (zds_real rval);
int            zcedRetT (void);
int            zcedRetNil (void);
int            zcedRetVoid (void);

int            zcedEntSel (const ZTCHAR *str, zds_name entres,
                             zds_point ptres);
#ifdef __cplusplus
class ZcSelectionPreview;
ZCCORE_PORT int zcedEntSel (const ZTCHAR *str, zds_name entres,
                             zds_point ptres, ZcSelectionPreview *pSelectionPreview);
#endif
int            zcedNEntSel (const ZTCHAR *str, zds_name entres,
                              zds_point ptres, zds_point xformres[4],
                              struct resbuf **refstkres);
int            zcedNEntSelP (const ZTCHAR *str, zds_name entres,
                              zds_point ptres, int pickflag,
                              zds_matrix xformres,
                              struct resbuf **refstkres);
int            zcedSSGet (const ZTCHAR *str, const void *pt1,
                            const void *pt2, const struct resbuf *filter,
                            zds_name ss);
#ifdef __cplusplus
ZCCORE_PORT int zcedSSGet (const ZTCHAR *str, const void *pt1,
                           const void *pt2, const struct resbuf *filter,
                           zds_name ss, ZcSelectionPreview *pSelectionPreview);
#endif
int            zcedSSGetFirst (struct resbuf** gset, struct resbuf** pset);
int            zcedSSSetFirst (const zds_name pset, const zds_name unused);
int            zcedSSFree (const zds_name sname);
#ifdef __cplusplus
int            zcedSSLength (const zds_name sname, ZSoft::Int32 *len);
#else
int            zcedSSLength (const zds_name sname, long *len);
#endif
int            zcedSSAdd (const zds_name ename, const zds_name sname,
                            zds_name result);
int            zcedSSDel (const zds_name ename, const zds_name ss);
int            zcedSSMemb (const zds_name ename, const zds_name ss);
int            zcedSSName (const zds_name ss, int i, zds_name entres);
int            zcedSSNameX (struct resbuf **rbpp, const zds_name ss,
                              int i); 
int            zcedSSNameXEx (struct resbuf **rbpp, const zds_name ss,
                              int i, unsigned int flags);
int            zcedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const ZTCHAR*));
int            zcedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const ZTCHAR*));
int            zcedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const ZTCHAR*));
int            zcedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const ZTCHAR*));

int            zcedTrans (const zds_point pt, const struct resbuf *from,
                            const struct resbuf *to, int disp,
                            zds_point result);

int            zcedSetVar (const ZTCHAR *sym, const struct resbuf *val);
int            zcedInitGet (int val, const ZTCHAR *kwl);

int            zcedGetSym (const ZTCHAR *sname, struct resbuf **value);
int            zcedPutSym (const ZTCHAR *sname, struct resbuf *value);

int            zcedHelp (const ZTCHAR* szFilename, const ZTCHAR* szTopic, int iCmd);
int            zcedHelpForExternal (const ZTCHAR *pszFunctionName);
int            zcedFNSplit (const ZTCHAR *pathToSplit, 
							ZTCHAR *prebuf, size_t nPreBufLen,
                            ZTCHAR *namebuf, size_t nNameBufLen,
							ZTCHAR *extbuf, size_t nExtBufLen);

#define HELP_CONTENTS     0x0003L  
#define HELP_HELPONHELP   0x0004L  
#define HELP_PARTIALKEY   0x0105L  

struct resbuf  *zcedZrxLoaded (void);
int            zcedZrxLoad (const ZTCHAR *app);
int            zcedZrxUnload (const ZTCHAR *app);

int            zcedInvoke (const struct resbuf *args,
                             struct resbuf **result);

int            zcedGetVar (const ZTCHAR *sym, struct resbuf *result);
int            zcedFindFile (const ZTCHAR *fname, ZTCHAR *result, size_t nBufLen);
int            zcedFindTrustedFile (const ZTCHAR *fname, ZTCHAR *result, size_t nBufLen);

int            zcedGetEnv (const ZTCHAR *sym, ZTCHAR  *var, size_t nBufLen);
int            zcedSetEnv (const ZTCHAR *sym, const ZTCHAR *val);

int            zcedGetCfg (const ZTCHAR *sym, ZTCHAR  *var, size_t len);
int            zcedSetCfg (const ZTCHAR *sym, const ZTCHAR *val);

int            zcedGetString (int cronly, const ZTCHAR *prompt, ZTCHAR *result, size_t bufsize);
int            zcedGetStringB (int cronly, const ZTCHAR *prompt,
                                    ZTCHAR *result, size_t bufsize);

int            zcedMenuCmd (const ZTCHAR *str);
int            zcedPrompt (const ZTCHAR *str);
int            zcedAlert (const ZTCHAR *str);

int            zcedGetAngle (const zds_point pt, const ZTCHAR *prompt,
                               zds_real *result);
int            zcedGetCorner (const zds_point pt, const ZTCHAR *prompt,
                                zds_point result);
int            zcedGetDist (const zds_point pt, const ZTCHAR *prompt,
                              zds_real *result);
int            zcedGetOrient (const zds_point pt, const ZTCHAR *prompt,
                                zds_real *result);
int            zcedGetPoint (const zds_point pt, const ZTCHAR *prompt,
                               zds_point result);
int            zcedGetInt (const ZTCHAR *prompt, int *result);
int            zcedGetKword (const ZTCHAR *prompt, ZTCHAR *result, size_t nBufLen);
int            zcedGetReal (const ZTCHAR *prompt, zds_real *result);
int            zcedGetInput (ZTCHAR *str, size_t nBufLen);
int            zcedVports (struct resbuf **vlist);

int            zcedTextScr (void);
int            zcedGraphScr (void);
int            zcedTextPage (void);

int            zcedRedraw (const zds_name ent, int mode);
int            zcedOsnap (const zds_point pt, const ZTCHAR *mode,
                            zds_point result);
int            zcedGrRead (int track, int *type, struct resbuf *result);
int            zcedGrText (int box, const ZTCHAR *text, int hl);
int            zcedGrDraw (const zds_point from, const zds_point to,
                             int color, int hl);
int            zcedGrVecs (const struct resbuf *vlist, zds_matrix mat);
int            zcedXformSS (const zds_name ssname,
                              zds_matrix genmat);
int            zcedDragGen (const zds_name ss, const ZTCHAR *pmt, int cursor,
                              int (*scnf) (zds_point pt, zds_matrix mt),
                              zds_point p);
int            zcedSetView (const struct resbuf *view, int vport);

int            zcedGetFileD (const ZTCHAR *title, const ZTCHAR *defawlt,
                               const ZTCHAR *ext, int flags,
                               struct resbuf *result);
int            zcedGetFileNavDialog (const ZTCHAR *title, const ZTCHAR *defawlt,
                             const ZTCHAR *ext, const ZTCHAR *dlgname, int flags,
                             struct resbuf **result);

int            zcedTextBox (const struct resbuf *args,
                              zds_point pt1, zds_point pt2);

int            zcedTablet  (const struct resbuf *args,
                              struct resbuf **result);

int            zcedGetCName (const ZTCHAR *cmd, ZTCHAR **result);

int           zcedEatCommandThroat(void);
int            zcdbEntDel (const zds_name ent);
struct resbuf *zcdbEntGetX (const zds_name ent, const struct resbuf *args);
struct resbuf *zcdbEntGet (const zds_name ent);
int            zcdbEntLast (zds_name result);
int            zcdbEntNext (const zds_name ent, zds_name result);
int            zcdbEntUpd (const zds_name ent);
int            zcdbEntMod (const struct resbuf *ent);
int            zcdbEntMake (const struct resbuf *ent);
int            zcdbEntMakeX (const struct resbuf *entm, zds_name result);
int            zcdbRegApp (const ZTCHAR *appname);
struct resbuf *zcdbTblNext (const ZTCHAR *tblname, int rewind);
struct resbuf *zcdbTblSearch (const ZTCHAR *tblname, const ZTCHAR *sym,
                              int setnext);
int	           zcdbNamedObjDict (zds_name result);
struct resbuf *zcdbDictSearch (const zds_name dict, const ZTCHAR* sym,
                               int setnext);
struct resbuf *zcdbDictNext (const zds_name dict, int rewind);
int            zcdbDictRename (const zds_name dictname, const ZTCHAR* oldsym,
                               const ZTCHAR* newsym);
int            zcdbDictRemove (const zds_name dictname, const ZTCHAR* symname);
int            zcdbDictAdd (const zds_name dictname, const ZTCHAR* symname,
                            const zds_name newobj);

int            zcdbTblObjName (const ZTCHAR *tblname, const ZTCHAR *sym,
                               zds_name result);

int            zcdbAngToS (zds_real v, int unit, int prec, ZTCHAR *str, size_t nBufLen);
int            zcdbRawAngToS (zds_real v, int unit, int prec, ZTCHAR *str, size_t nBufLen);
int            zcdbRToS (zds_real val, int unit, int prec, ZTCHAR *str, size_t nBufLen);
int            zcdbAngToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbRawAngToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbDisToF (const ZTCHAR *str, int unit, zds_real *v);
int            zcdbInters (const zds_point from1, const zds_point to1,
                             const zds_point from2, const zds_point to2,
                             int teston, zds_point result);
int            zcdbSNValid (const ZTCHAR *tbstr, int pipetest);
int			   zds_queueexpr(const ZTCHAR* pchString);

void		   zcedRegen();


#ifdef __cplusplus

ZCCORE_PORT int zcedGetString (int cronly, const ZTCHAR *prompt, ZcString &sResult);
ZCCORE_PORT int zcedGetKword (const ZTCHAR *prompt, ZcString & sResult);
ZCCORE_PORT int zcedGetInput (ZcString &sOut);
ZCCORE_PORT int zcdbAngToS(double val, ZcString &sOut, int unit = -1, int prec = -1);
ZCCORE_PORT int zcdbRawAngToS(double val, ZcString &sOut, int unit = -1, int prec = -1);
ZCCORE_PORT int zcdbRToS(double val, ZcString &sOut, int unit = -1, int prec = -1);
ZCCORE_PORT int zcedFindFile(const ZTCHAR *fname, ZcString &sResult);
ZCCORE_PORT int zcedFindTrustedFile(const ZTCHAR *fname, ZcString &sResult);
ZCCORE_PORT int zcedGetCName(const ZTCHAR *cmd, ZcString &sOut);
ZCCORE_PORT int zcedGetEnv(const ZTCHAR *sym, ZcString &sResult);
ZCCORE_PORT int zcedGetInt(const ZTCHAR *prompt, int &nResult);
ZCCORE_PORT int zcedGetInt(const ZTCHAR *prompt, int &nResult, int nMin, int nMax);

Zcad::ErrorStatus zcutNewString(const ZTCHAR* pInput, ZTCHAR*& pOutput);
inline int zcedGetFullInput(ZTCHAR *&pStr)
{
    ZcString sOut;
    const int nRet = ::zcedGetInput(sOut);
    ::zcutNewString(sOut.constPtr(), pStr);
    return nRet;
}

inline int zcedGetFullKword(const ZTCHAR * pString, ZTCHAR *&pStr)
{
    ZcString sOut;
    const int nRet = ::zcedGetKword(pString, sOut);
    ::zcutNewString(sOut.constPtr(), pStr);
    return nRet;
}

inline int zcedGetFullString(int cronly, const ZTCHAR *pString, ZTCHAR *&pResult)
{
    ZcString sResult;
    const int nRet = ::zcedGetString(cronly, pString, sResult);
    ::zcutNewString(sResult.constPtr(), pResult);
    return nRet;
}

template<size_t nBufLen> inline int zcedGetEnv(const wchar_t* pszName, wchar_t (&buf)[nBufLen])
{
	return ::zcedGetEnv(pszName, buf, nBufLen);
}

template<size_t nBufLen> inline int zcedGetInput(wchar_t (&buf)[nBufLen])
{
	return ::zcedGetInput(buf, nBufLen);
}

template<size_t nBufLen> inline int zcedGetString(int cronly, const wchar_t* prompt,
                                wchar_t (&buf)[nBufLen])
{
	return ::zcedGetString(cronly, prompt, buf, nBufLen);
}

template<size_t nBufLen> inline int zcedFindFile(const wchar_t* pszName, wchar_t (&buf)[nBufLen])
{
	return ::zcedFindFile(pszName, buf, nBufLen);
}

template<size_t nBufLen> inline int zcedFindTrustedFile(const wchar_t *pszName,
    wchar_t(&buf)[nBufLen])
{
    return ::zcedFindTrustedFile(pszName, buf, nBufLen);
}

template<size_t nBufLen> inline int zcedGetKword(const wchar_t* pszPrompt, wchar_t (&buf)[nBufLen])
{
	return ::zcedGetKword(pszPrompt, buf, nBufLen);
}

template<size_t nPreBufLen, size_t nNameBufLen, size_t nExtBufLen> inline int
    zcedFNSplit(const wchar_t* pathToSplit,
    wchar_t (&prebuf) [nPreBufLen],
    wchar_t (&namebuf)[nNameBufLen],
    wchar_t (&extbuf) [nExtBufLen])
{
	return ::zcedFNSplit(pathToSplit, prebuf, nPreBufLen, namebuf, nNameBufLen,	extbuf, nExtBufLen);
}

template<size_t nNameBufLen> inline 
int zcedFNSplit(const wchar_t* pathToSplit, size_t nPre, wchar_t (&namebuf)[nNameBufLen], size_t nExt)
{
	return ::zcedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, nullptr, nExt);
}

template<size_t nExtBufLen> inline 
int zcedFNSplit(const ZTCHAR*pathToSplit, size_t nPre, size_t nName, wchar_t (&extbuf)[nExtBufLen])
{
	return ::zcedFNSplit(pathToSplit, nullptr, nPre, nullptr, nName, extbuf, nExtBufLen);
}

template<size_t nNameBufLen, size_t nExtBufLen> 
inline int zcedFNSplit(const ZTCHAR* pathToSplit, size_t nPre, wchar_t (&namebuf)[nNameBufLen], wchar_t(&extbuf)[nExtBufLen])
{
	return ::zcedFNSplit(pathToSplit, nullptr, nPre, namebuf, nNameBufLen, extbuf, nExtBufLen);
}

template<size_t nPreBufLen> 
inline int zcedFNSplit(const wchar_t*pathToSplit, wchar_t(& prebuf)[nPreBufLen], size_t nName, size_t nExt)
{
	return ::zcedFNSplit(pathToSplit, prebuf, nPreBufLen, nullptr, nName, nullptr, nExt);
}

template<size_t nBufLen> 
inline int zcdbAngToS(zds_real v, int unit, int prec, wchar_t(& buf)[nBufLen])
{
	return ::zcdbAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen> 
inline int zcdbRawAngToS(zds_real v, int unit, int prec, wchar_t(& buf)[nBufLen])
{
	return ::zcdbRawAngToS(v, unit, prec, buf, nBufLen);
}

template<size_t nBufLen> 
inline int zcdbRToS(zds_real v, int unit, int prec, wchar_t(& buf)[nBufLen])
{
	return ::zcdbRToS(v, unit, prec, buf, nBufLen);
}

class ZcEdCommandRejector
{
public:
    virtual bool reject(const ZTCHAR* globalCmdName, const ZTCHAR* localCmdName) = 0;
};

ZCCORE_PORT void zcedRegisterCommandRejector(ZcEdCommandRejector* pRejector);
ZCCORE_PORT void zcedUnRegisterCommandRejector(ZcEdCommandRejector* pRejector);

#endif  

#pragma pack (pop)

#endif  
