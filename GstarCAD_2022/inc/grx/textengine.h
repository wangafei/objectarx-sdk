#pragma once

#include "../OdaCommon.h"
#include "../Gi/Gi.h"
#include "../Gi/GiTextStyle.h"

typedef void(*PolylineCallback) (int, int const *, OdGePoint3d const *, void *);
typedef void(*UnicodeCallback) (OdLongPtr, wchar_t const *, int, void *);

class OdGiTextEngine {

public:
  static   OdGiTextEngine * create();
  virtual ~OdGiTextEngine() {}


  // Returns the extents of the text string in unit coordinates.
  virtual void getExtents(
    OdGiTextStyle &    ts,
    OdChar const *      pStr,
    int                nLength,
    bool               bPenUp,
    bool               bRaw,
    OdGePoint2d &      extents) = 0;


  // Tessellates the shape text and sends the tessellated vectors as a
  // single poly polyline call for the entire text string. Again, this
  // is in unit coordinates. The code to tessellate truetype text needs
  // to be added to this routine sometime in the future.
  virtual void tessellate(
    OdGiTextStyle &    ts,
    OdChar const *      pStr,
    int                nLength,
    bool               bRaw,
    double             deviation,
    void *             pVoid,
    PolylineCallback   pPolylineCallback) = 0;

  // Processes any control codes that are embedded in the passed in
  // string (give examples?). The converted unicode is passed back
  // through a unicode callback function. In addition, any
  // overscores/underscores that might result from the processing of
  // control codes will be drawn through the polyline callback. The
  // vectors representing the overlines and underlines will be in unit
  // coordinates as well. Currently, this is implemented for truetype
  // text only. Needs to be updated for shape text as well.
  virtual void tessellate(
    OdGiTextStyle &    ts,
    OdChar const *      pString,
    int                nLength,
    bool               bRaw,
    void *             pVoid,
    UnicodeCallback    pUnicodeCallback,
    PolylineCallback   pPolylineCallback) = 0;
};


