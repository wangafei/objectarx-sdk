/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCGS_H
#define _GCGS_H

#include "gsoft.h"
#include "gcdb.h"
#include "stdlib.h"
#include "GdGChar.h"
#include "gcgitransient.h"
#include "gccoredefs.h"
#include "gcgidefs.h"

#pragma pack (push, 8)

GCGS_PORT Gsoft::Boolean gcgsGetDisplayInfo(int & drawingWidth,
  int & drawingHeight,
  int & aspectWidth,
  int & aspectHeight);

GCGS_PORT Gsoft::Boolean gcgsGetViewportInfo(int   viewportNumber,
  int & left,
  int & bottom,
  int & right,
  int & top);

class GcDbDatabase;
class GcGiDrawable;

class GcGsScreenShot {
public:
  virtual Gsoft::Boolean getSize(int & width,
    int & height,
    int & depth) const = 0;

  virtual Gsoft::Boolean getColorMap(int             index,
    Gsoft::UInt8 & red,
    Gsoft::UInt8 & green,
    Gsoft::UInt8 & blue) const = 0;

  virtual void const * getScanline(int offsetFromLeft,
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

  GcGsScreenShot();
  virtual ~GcGsScreenShot() = 0;
};

#define ScreenShot GcGsScreenShot

GCGS_PORT GcGsScreenShot * gcgsGetScreenShot(int          viewportNumber);

GCGS_PORT void gcgsSetViewportRenderFlag(int          viewportNumber);

GCGS_PORT Gsoft::Boolean gcgsDisplayImage(int          viewportNumber,
  Gsoft::Int32 originLeft,
  Gsoft::Int32 originTop,
  int          imageWidth,
  int          imageHeight,
  void const * imageData,
  int          hasTransparency);

GCGS_PORT Gsoft::Boolean gcgsRemoveAnonymousGraphics(int viewportNumber);

typedef void(*gcgsCustomUpdateMethod)      (void * pParm, int left, int right, int bottom, int top);
GCGS_PORT Gsoft::Boolean gcgsSetCustomUpdateMethod(gcgsCustomUpdateMethod custom_update_method, void * pParm);

GCGS_PORT void gcgsRedrawShortTermGraphics(int minx, int miny, int maxx, int maxy);

struct GcGs
{
  enum LinePattern {
    eSolid = 0,
    eDashed = 1,
    eDotted = 2,
    eDashDot = 3,
    eShortDash = 4,
    eMediumDash = 5,
    eLongDash = 6,
    eDoubleShortDash = 7,
    eDoubleMediumDash = 8,
    eDoubleLongDash = 9,
    eMediumLongDash = 10,
    eMediumDashShortDashShortDash = 11,
    eLongDashShortDash = 12,
    eLongDashDotDot = 13,
    eLongDashDot = 14,
    eMediumDashDotShortDashDot = 15,
    eSparseDot = 16,
    eDefaultLinePattern = eDotted
  };
};

GCGS_PORT void                gcgsSetHighlightColor(Gsoft::UInt16 colorIndex);
GCGS_PORT Gsoft::UInt16       gcgsGetHighlightColor(void);
GCGS_PORT void                gcgsSetHighlightLinePattern(GcGs::LinePattern pattern);
GCGS_PORT GcGs::LinePattern   gcgsGetHighlightLinePattern(void);
GCGS_PORT void                gcgsSetHighlightLineWeight(Gsoft::UInt16 weight);
GCGS_PORT Gsoft::UInt16       gcgsGetHighlightLineWeight(void);
GCGS_PORT void                gcgsSetHighlightStyle(GcGiHighlightStyle style);
GCGS_PORT GcGiHighlightStyle  gcgsGetHighlightStyle(void);

class GcGsView;
class GcGsModel;
class GcGsManager;

GCGS_PORT Gsoft::Boolean  gcgsSetViewParameters(int viewportNumber, const GcGsView * pView,
  bool bRegenRequired, bool bRescaleRequired,
  bool bSyncRequired = false);
GCGS_PORT Gsoft::Boolean  gcgsGetViewParameters(int viewportNumber, GcGsView * pView);
GCGS_PORT Gsoft::Boolean  gcgsSetLensLength(int viewportNumber, const double & lensLength);
GCGS_PORT Gsoft::Boolean  gcgsGetLensLength(int viewportNumber, double & lensLength);
GCGS_PORT void            gcgsWriteViewToUndoController(int viewportNumber);
GCGS_PORT Gsoft::Boolean  gcgsSetView2D(int viewportNumber);

GCGS_PORT GcGsView *gcgsGetCurrentGcGsView(int vpNum);
GCGS_PORT GcGsView *gcgsGetCurrent3dGcGsView(int vpNum);

GCGS_PORT GcGsView *gcgsObtainGcGsView(int vpNum, const class GcGsKernelDescriptor &);
GCGS_PORT GcGsModel *gcgsGetGsModel(GcGiTransientDrawingMode mode, int subDrawingMode, int viewportNumber);

class CView;

GCGS_PORT GcGsManager *gcgsGetGsManager(CView * pView = nullptr);
GCGS_PORT GcGsManager *gcgsGetCurrentGsManager();

class GcGePoint3d;
class GcGeVector3d;
GCGS_PORT Gsoft::Boolean  gcgsGetOrthoViewParameters(int viewportNumber,
  GcDb::OrthographicView view,
  GcGeVector3d * pViewDir,
  GcGeVector3d * pUpVector);

class GcGs2DViewLimitManager
{
public:
  virtual                ~GcGs2DViewLimitManager(void) { }
  virtual bool            testView(GcGePoint3d const & target,
    double              dFieldHeight) = 0;
};

GCGS_PORT GcGs2DViewLimitManager *    gcgsCreate2DViewLimitManager(int viewportNumber);
GCGS_PORT void                        gcgsDestroy2DViewLimitManager(GcGs2DViewLimitManager * pLimitManager);
GCGS_PORT Gsoft::Boolean              gcgsDrawableModified(GcGiDrawable *pDrawable,
  GcGiDrawable *pParentDrawable);
GCGS_PORT Gsoft::Boolean              gcgsDrawableErased(GcGiDrawable *pDrawable,
  GcGiDrawable *pParentDrawable);
GCGS_PORT Gsoft::Boolean  gcgsDrawableCached(GcGiDrawable *pDrawable);
GCGS_PORT GcGsModel*      gcgsGetGsModel(const GcDbDatabase* pDb);
GCGS_PORT GcGsModel*      gcgsGetGsHighlightModel(const GcDbDatabase* pDb);
GCGS_PORT void            gcgsSetGsModel(const GcDbDatabase* pDb, GcGsModel* pModel);
GCGS_PORT void            gcgsSetGsHighlightModel(const GcDbDatabase* pDb, GcGsModel* pModel);

#pragma pack (pop)
#endif 