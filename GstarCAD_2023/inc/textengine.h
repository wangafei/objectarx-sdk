/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _TEXTENGINE_H
#define _TEXTENGINE_H 1

#include "gcgi.h"
#include "GdGChar.h"
#include "gsoft.h"

#pragma pack (push, 8)

typedef void(*PolylineCallback) (int, int const *, GcGePoint3d const *, void *);
typedef void(*UnicodeCallback) (GcFontHandle*, wchar_t const *, int, void *);

class GcGiTextEngine
{
public:
  GCCORE_PORT static GcGiTextEngine * create();
  virtual ~GcGiTextEngine() { ; }

  virtual void getExtents(GcGiTextStyle &    ts,
                          GCHAR const *      pStr,
                          int                nLength,
                          bool               bPenUp,
                          bool               bRaw,
                          GcGePoint2d &      extents) = 0;

  virtual void tessellate(GcGiTextStyle &    ts,
                          GCHAR const *      pStr,
                          int                nLength,
                          bool               bRaw,
                          double             deviation,
                          void *             pVoid,
                          PolylineCallback   pPolylineCallback) = 0;

  virtual void tessellate(GcGiTextStyle &    ts,
                          GCHAR const *      pString,
                          int                nLength,
                          bool               bRaw,
                          void *             pVoid,
                          UnicodeCallback    pUnicodeCallback,
                          PolylineCallback   pPolylineCallback) = 0;
};

#pragma pack (pop)
#endif
