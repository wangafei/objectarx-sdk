

#ifndef _ZCGS_H
#define _ZCGS_H

#include "zadesk.h"
#include "zacdb.h"
#include "stdlib.h"
#include "zAdAChar.h"
#include "zacgitransient.h"
#include "zAcCoreDefs.h"
#include "zacgidefs.h"
#include "zgs.h"

#pragma pack (push, 8)

ZSoft::Boolean zcgsGetDisplayInfo           (int & drawingWidth,    
                                             int & drawingHeight,     
                                             int & aspectWidth,
                                             int & aspectHeight);

ZSoft::Boolean zcgsGetViewportInfo          (int   viewportNumber,
                                             int & left,    
                                             int & bottom,
                                             int & right,    
                                             int & top);    
class ZcDbDatabase;
class ZcGiDrawable;
class ZcGsScreenShot {      
    public:
    virtual ZSoft::Boolean getSize          (int & width,             
                                             int & height,
                                             int & depth) const = 0; 

    virtual ZSoft::Boolean getColorMap      (int             index,
                                             ZSoft::UInt8 & red,
                                             ZSoft::UInt8 & green,
                                             ZSoft::UInt8 & blue) const = 0;

    virtual void const * getScanline        (int offsetFromLeft,
                                             int offsetFromTop) const = 0;

#ifdef new
#define DISABLING_LEAK_CHECK
#undef new
#endif
    void * operator new (size_t size);

    void operator delete (void * p);   

#ifndef PRODUCTION
        void * operator new (size_t size, const char *, int) { return operator new(size); }
#if _MSC_VER >= 1200
        
        void operator delete (void * p, const char *, int) { delete p; }
#endif 
#endif 

#ifdef DISABLING_LEAK_CHECK
#define new DEBUG_NEW
#undef DISABLING_LEAK_CHECK
#endif

    ZcGsScreenShot();
    virtual ~ZcGsScreenShot () = 0;
};

#define ScreenShot ZcGsScreenShot

ZcGsScreenShot * zcgsGetScreenShot          (int          viewportNumber);

void zcgsSetViewportRenderFlag              (int          viewportNumber);

ZSoft::Boolean zcgsDisplayImage             (int          viewportNumber,
                                             ZSoft::Int32 originLeft,    
                                             ZSoft::Int32 originTop,    
                                             int          imageWidth,    
                                             int          imageHeight,    
                                             void const * imageData,        
                                             int          hasTransparency);

ZSoft::Boolean zcgsRemoveAnonymousGraphics  (int viewportNumber);

typedef void (*zcgsCustomUpdateMethod)      (void * pParm, int left, int right, int bottom, int top);
ZSoft::Boolean zcgsSetCustomUpdateMethod    (zcgsCustomUpdateMethod custom_update_method, void * pParm);

ZCCORE_PORT void zcgsRedrawShortTermGraphics (int minx, int miny, int maxx, int maxy);

struct ZcGs
{
    enum LinePattern      { eSolid                         = 0,
                            eDashed                        = 1,
                            eDotted                        = 2,
                            eDashDot                       = 3,
                            eShortDash                     = 4,
                            eMediumDash                    = 5,
                            eLongDash                      = 6,
                            eDoubleShortDash               = 7,
                            eDoubleMediumDash              = 8,
                            eDoubleLongDash                = 9,
                            eMediumLongDash                = 10,
                            eMediumDashShortDashShortDash  = 11,
                            eLongDashShortDash             = 12,
                            eLongDashDotDot                = 13,
                            eLongDashDot                   = 14,
                            eMediumDashDotShortDashDot     = 15,
                            eSparseDot                     = 16,
                            eDefaultLinePattern            = eDotted };
};

ZCCORE_PORT void               zcgsSetHighlightColor       (ZSoft::UInt16 colorIndex);
ZCCORE_PORT ZSoft::UInt16      zcgsGetHighlightColor       (void);
ZCCORE_PORT void               zcgsSetHighlightLinePattern (ZcGs::LinePattern pattern);
ZCCORE_PORT ZcGs::LinePattern  zcgsGetHighlightLinePattern (void);
ZCCORE_PORT void               zcgsSetHighlightLineWeight  (ZSoft::UInt16 weight);
ZCCORE_PORT ZSoft::UInt16      zcgsGetHighlightLineWeight  (void);
ZCCORE_PORT void               zcgsSetHighlightStyle       (ZcGiHighlightStyle style);
ZCCORE_PORT ZcGiHighlightStyle zcgsGetHighlightStyle       (void);

class ZcGsView;
class ZcGsModel;
class ZcGsManager;
class ZcGsManager2;

ZSoft::Boolean  zcgsSetViewParameters         (int viewportNumber, const ZcGsView * pView,
                                               bool bRegenRequired, bool bRescaleRequired,
                                               bool bSyncRequired = false);
ZSoft::Boolean  zcgsGetViewParameters         (int viewportNumber, ZcGsView * pView);
ZSoft::Boolean  zcgsSetLensLength             (int viewportNumber, const double & lensLength);
ZSoft::Boolean  zcgsGetLensLength             (int viewportNumber, double & lensLength);
void            zcgsWriteViewToUndoController (int viewportNumber);
ZSoft::Boolean  zcgsSetView2D                 (int viewportNumber);

ZCCORE_PORT ZcGsView *zcgsGetCurrentZcGsView(int vpNum);
ZCCORE_PORT ZcGsView *zcgsGetCurrent3dZcGsView(int vpNum);

ZCCORE_PORT ZcGsView *zcgsObtainZcGsView(int vpNum, const class ZcGsKernelDescriptor &);
ZcGsModel *zcgsGetGsModel(ZcGiTransientDrawingMode mode, int subDrawingMode, int viewportNumber);

class CView;

ZcGsManager *   zcgsGetGsManager            (CView * pView = nullptr); 

ZCCORE_PORT ZcGsManager *zcgsGetCurrentGsManager();
ZCCORE_PORT ZcGsManager2 *zcgsGetCurrentGsManager2();

class ZcGePoint3d;
class ZcGeVector3d;
ZSoft::Boolean  zcgsGetOrthoViewParameters  (int viewportNumber, 
                                             ZcDb::OrthographicView view,
                                             ZcGeVector3d * pViewDir,
                                             ZcGeVector3d * pUpVector);


class ZcGs2DViewLimitManager 
{      
public:
    virtual                ~ZcGs2DViewLimitManager  (void) { }
    virtual bool            testView                (ZcGePoint3d const & target,
                                                     double              dFieldHeight)  = 0;
};

ZcGs2DViewLimitManager *    zcgsCreate2DViewLimitManager  (int viewportNumber);
void                        zcgsDestroy2DViewLimitManager (ZcGs2DViewLimitManager * pLimitManager);

ZSoft::Boolean              zcgsDrawableModified    (ZcGiDrawable *pDrawable,
                                                     ZcGiDrawable *pParentDrawable);

ZSoft::Boolean              zcgsDrawableErased      (ZcGiDrawable *pDrawable,
                                                     ZcGiDrawable *pParentDrawable);

class ZcGsGraphicsKernel;

[[deprecated("Use zcgsDrawableCached(ZcGsGraphicsKernel* pKernel, ZcGiDrawable* pDrawable)")]]
ZCCORE_PORT ZSoft::Boolean  zcgsDrawableCached      (ZcGiDrawable *pDrawable);

ZCCORE_PORT ZSoft::Boolean  zcgsDrawableCached(ZcGsGraphicsKernel* pKernel, ZcGiDrawable* pDrawable);

[[deprecated("Use zcgsGetGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb)")]]
ZCCORE_PORT ZcGsModel*      zcgsGetGsModel          (const ZcDbDatabase* pDb);

ZCCORE_PORT ZcGsModel* zcgsGetGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb);

[[deprecated("Use zcgsGetGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb)")]]
ZCCORE_PORT ZcGsModel*      zcgsGetGsHighlightModel (const ZcDbDatabase* pDb);

ZCCORE_PORT ZcGsModel* zcgsGetGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb);

[[deprecated("Use zcgsSetGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel)")]]
ZCCORE_PORT void            zcgsSetGsModel          (const ZcDbDatabase* pDb, ZcGsModel* pModel);

ZCCORE_PORT void zcgsSetGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel);

[[deprecated("Use zcgsSetGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel)")]]
ZCCORE_PORT void            zcgsSetGsHighlightModel (const ZcDbDatabase* pDb, ZcGsModel* pModel);

ZCCORE_PORT void zcgsSetGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel);

ZCCORE_PORT bool zcgsGetActiveGraphicsKernels(ZcArray<ZcGsGraphicsKernel*>& result);

ZCCORE_PORT bool zcgsGetActiveModels(ZcArray<ZcGsModel*>& result);

ZCCORE_PORT bool zcgsGetActiveModels(const ZcDbDatabase* pDb, ZcArray<ZcGsModel*>& result);

#pragma pack (pop)
#endif 
