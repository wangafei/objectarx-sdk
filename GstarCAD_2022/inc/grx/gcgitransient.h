#pragma once

#ifndef ODGI_EXPORT_EX
  #ifdef GCGS_EXPORTS
    #define ODGI_EXPORT_EX
  #else
    #define ODGI_EXPORT_EX ODGI_EXPORT
  #endif
#endif

typedef enum{
    kGcGiMain = 0,
    kGcGiSprite,
    kGcGiDirectShortTerm,
    kGcGiHighlight,
    kGcGiDirectTopmost,
    kGcGiContrast,
    kGcGiDrawingModeCount
} GcGiTransientDrawingMode;

class GcGiTransientManager
{
public:
    virtual             ~GcGiTransientManager   (void) { }

    virtual bool        addTransient            (GcGiDrawable* pDrawable,
                                                 GcGiTransientDrawingMode mode,
                                                 int subDrawingMode,
                                                 const GcArray<int>& viewportNumbers)    = 0;

    virtual bool        eraseTransient          (GcGiDrawable* pDrawable,
                                                 const GcArray<int>& viewportNumbers)    = 0;

    virtual bool        eraseTransients         (GcGiTransientDrawingMode mode,
                                                 int subDrawingMode,
                                                 const GcArray<int>& viewportNumbers)    = 0;

    virtual void        updateTransient         (GcGiDrawable* pDrawable,
                                                 const GcArray<int>& viewportNumbers)    = 0;

    virtual bool        addChildTransient       (GcGiDrawable * pDrawable, 
                                                 GcGiDrawable * pParentDrawable)         = 0;

    virtual bool        eraseChildTransient     (GcGiDrawable * pDrawable, 
                                                 GcGiDrawable * pParentDrawable)         = 0;

    virtual void        updateChildTransient    (GcGiDrawable * pDrawable, 
                                                 GcGiDrawable * pParentDrawable)         = 0; 

    virtual int         getFreeSubDrawingMode   (GcGiTransientDrawingMode mode,
                                                 int& subDrawingMode,
                                                 const GcArray<int>& viewportNumbers)    = 0;
};

ODGI_EXPORT_EX GcGiTransientManager* gcgiGetTransientManager();
ODGI_EXPORT_EX void gcgiSetTransientManager(GcGiTransientManager* transientManager);


