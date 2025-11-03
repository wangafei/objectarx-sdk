/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCEDSEL_H
#define _GCEDSEL_H

#include "gcarray.h"
#include "gcadstrc.h"   
#include "gcgitransient.h"
#pragma pack (push, 8)

class GcDbObjectId;
class GcDbSubentId;
class GcEdSelectedTransientImp;
class GcGsDCRect;

class GCCORE_PORT GcEdSolidSubentitySelector
{
public:
  GcEdSolidSubentitySelector();
  ~GcEdSolidSubentitySelector();

  Gcad::ErrorStatus selectFaces(GcDbObjectId& selectedSolidId,
    GcArray<GcDbSubentId *>& faceSet);
};

class GCCORE_PORT GcEdSelectedTransient
{
public:
  GcEdSelectedTransient();
  GcEdSelectedTransient(const GcEdSelectedTransient& source);
  GcEdSelectedTransient& operator=(const GcEdSelectedTransient& source);
  ~GcEdSelectedTransient();

  GcGiDrawable* parent();
  GcGiDrawable* drawable();
  Gsoft::GsMarker marker();
  GcGiTransientDrawingMode mode();
  int subDrawingMode();

protected:
  GcEdSelectedTransientImp* mImp;
  friend class GcEdTransientSelectionInternals;
};

GCCORE_PORT Gcad::ErrorStatus gcedSelectTransients(const GcGsDCRect& rect,
  int viewportNumber,
  GcArray<GcEdSelectedTransient>& result);

#pragma pack (pop)
#endif 