/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcarray.h"

typedef enum {
  kGcGiMain = 0,
  kGcGiSprite,
  kGcGiDirectShortTerm,
  kGcGiHighlight,
  kGcGiDirectTopmost,
  kGcGiContrast,
  kGcGiDrawingModeCount
} GcGiTransientDrawingMode;
class GcGiDrawable;

class GcGiTransientManager
{
public:
  virtual             ~GcGiTransientManager(void) { }

  virtual bool        addTransient(GcGiDrawable* pDrawable,
    GcGiTransientDrawingMode mode,
    int subDrawingMode,
    const GcArray<int>& viewportNumbers) = 0;
  virtual bool        eraseTransient(GcGiDrawable* pDrawable,
    const GcArray<int>& viewportNumbers) = 0;
  virtual bool        eraseTransients(GcGiTransientDrawingMode mode,
    int subDrawingMode,
    const GcArray<int>& viewportNumbers) = 0;

  virtual void        updateTransient(GcGiDrawable* pDrawable,
    const GcArray<int>& viewportNumbers) = 0;
  virtual bool        addChildTransient(GcGiDrawable * pDrawable,
    GcGiDrawable * pParentDrawable) = 0;
  virtual bool        eraseChildTransient(GcGiDrawable * pDrawable,
    GcGiDrawable * pParentDrawable) = 0;
  virtual void        updateChildTransient(GcGiDrawable * pDrawable,
    GcGiDrawable * pParentDrawable) = 0;

  virtual int         getFreeSubDrawingMode(GcGiTransientDrawingMode mode,
    int& subDrawingMode,
    const GcArray<int>& viewportNumbers) = 0;
};

GCGS_PORT GcGiTransientManager* gcgiGetTransientManager();
GCGS_PORT void gcgiSetTransientManager(GcGiTransientManager* transientManager);