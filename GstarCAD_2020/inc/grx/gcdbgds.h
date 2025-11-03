#pragma once

#include "gcadstd.h"
#include "gdsdef.h"
#include "gcmem.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "gevec2d.h"
#include "gevec3d.h"

inline const GcGeVector3d& gcdbAsVector(const gds_point pt)
{
  return *((const GcGeVector3d*)pt);
}

inline GcGeVector3d& gcdbAsVector(gds_point pt)
{
  return *((GcGeVector3d*)pt);
}

inline const GcGePoint3d& gcdbAsPoint(const gds_point pt)
{
  return *((const GcGePoint3d*)pt);
}

inline GcGePoint3d& gcdbAsPoint(gds_point pt)
{
  return *((GcGePoint3d*)pt);
}

inline const GcGePoint2d & gcdbAsPoint2d(const gds_point pt)
{
  return *((const GcGePoint2d*)pt);
}

inline GcGePoint2d& gcdbAsPoint2d(gds_point pt)
{
  return *((GcGePoint2d*)pt);
}

inline const GcGeVector2d& gcdbAsVector2d(const gds_point pt)
{
  return *((const GcGeVector2d*)pt);
}

inline GcGeVector2d& gcdbAsVector2d(gds_point pt)
{
  return *((GcGeVector2d*)pt);
}

#pragma pack (push, 8)

#ifdef __cplusplus
	extern "C" {
#endif

#define gcdbNameSet(from, to)		((to)[0]=(from)[0], (to)[1]=(from)[1])
#define gcdbPointSet(from, to)	((to)[0]=(from)[0], (to)[1]=(from)[1], (to)[2]=(from)[2])
#define gcdbPointClear(pnt)		  ((pnt)[0] = (pnt)[1] = (pnt)[2] = 0.0)
#define gcdbNameClear(name)			((name)[0] = (name)[1] = 0)
#define gcdbNameNil(name)			  ((name)[0] == 0 && (name)[1] == 0)
#define gcdbNameEqual(name1, name2)	((name1)[0]==(name2)[0] && (name1)[1]==(name2)[1])

GCED_DLL_DECL void gcdbFail (const GCHAR *str);
GCDB_DLL_DECL int gcdbXdRoom (const gds_name ent, long *result);
GCDB_DLL_DECL int gcdbXdSize (const struct resbuf *rb, long *result);
GCDB_DLL_DECL int gcdbHandEnt (const GCHAR *handle, gds_name entres);
GCDB_DLL_DECL GCHAR * gcdbXStrSave (GCHAR *pSource, GCHAR **pDest);
GCDB_DLL_DECL int gcdbXStrCase (GCHAR *str);

GCDB_DLL_DECL void gcdbFreeResBufContents(resbuf* pField);
GCDB_DLL_DECL int gcdbEntDel (const gds_name ent);
GCDB_DLL_DECL struct resbuf *gcdbEntGetX (const gds_name ent, const struct resbuf *args);
GCDB_DLL_DECL struct resbuf *gcdbEntGet (const gds_name ent);
GCDB_DLL_DECL int gcdbEntLast (gds_name result);
GCDB_DLL_DECL int gcdbEntNext (const gds_name ent, gds_name result);
GCDB_DLL_DECL int gcdbEntUpd  (const gds_name ent);
GCDB_DLL_DECL int gcdbEntMod (const struct resbuf *ent);
GCDB_DLL_DECL int gcdbEntMake (const struct resbuf *ent);
GCDB_DLL_DECL int gcdbEntMakeX (const struct resbuf *entm, gds_name result);
GCDB_DLL_DECL int gcdbRegApp (const GCHAR *appname);
GCDB_DLL_DECL struct resbuf *gcdbTblNext (const GCHAR *tblname, int rewind);
GCDB_DLL_DECL struct resbuf *gcdbTblSearch (const GCHAR *tblname, const GCHAR *sym, int setnext);
GCDB_DLL_DECL int	gcdbNamedObjDict (gds_name result);
GCDB_DLL_DECL struct resbuf *gcdbDictSearch (const gds_name dict, const GCHAR* sym, int setnext);
GCDB_DLL_DECL struct resbuf *gcdbDictNext (const gds_name dict, int rewind);
GCDB_DLL_DECL int gcdbDictRename (const gds_name dictname, const GCHAR* oldsym, const GCHAR* newsym);
GCDB_DLL_DECL int gcdbDictRemove (const gds_name dictname, const GCHAR* symname);
GCDB_DLL_DECL int gcdbDictAdd (const gds_name dictname, const GCHAR* symname, const gds_name newobj);

GCDB_DLL_DECL int	gcdbTblObjName (const GCHAR *tblname, const GCHAR *sym, gds_name result);

GCDB_DLL_DECL int gcdbAngToS(gds_real v, int unit, int prec, GCHAR *str, size_t nBufLen);
GCDB_DLL_DECL int gcdbRawAngToS(gds_real v, int unit, int prec, GCHAR *str, size_t nBufLen);
GCDB_DLL_DECL int gcdbRToS(gds_real val, int unit, int prec, GCHAR *str, size_t nBufLen);
GCDB_DLL_DECL int gcdbAngToF(const GCHAR *str, int unit, gds_real *v);
GCDB_DLL_DECL int gcdbRawAngToF(const GCHAR *str, int unit, gds_real *v);
GCDB_DLL_DECL int gcdbDisToF(const GCHAR *str, int unit, gds_real *v);
GCDB_DLL_DECL int gcdbInters (const gds_point from1, const gds_point to1, const gds_point from2, const gds_point to2, int teston, gds_point result);
GCDB_DLL_DECL int gcdbSNValid (const GCHAR *tbstr, int pipetest);

#ifdef __cplusplus
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
#endif

#pragma pack (pop)


