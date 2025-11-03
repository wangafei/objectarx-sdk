#ifndef __GCGS_H__INCLUDED__
#define __GCGS_H__INCLUDED__

#pragma once

#include "gcadstd.h"

#include "../Gs/Gs.h"
#include "../Gs/GsModel.h"

#include "gcdb.h" // for namespace GcDb
#include "gcgitransient.h" // GcGiTransientDrawingMode

#ifndef GS_TOOLKIT_EXPORT_EX
  #ifdef GCGS_EXPORTS
    #define GS_TOOLKIT_EXPORT_EX
  #else
    #define GS_TOOLKIT_EXPORT_EX GS_TOOLKIT_EXPORT
  #endif
#endif


class OdGiDrawable;
class OdGsView;
class OdGsModel;
class OdGePoint3d;
class OdGeVector3d;
class GcGsManager; 

class CView;


GS_TOOLKIT_EXPORT_EX 
OdBool gcgsGetDisplayInfo  (int & drawingWidth,    
                            int & drawingHeight,     
                            int & aspectWidth,
                            int & aspectHeight);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsGetViewportInfo (int   viewportNumber,
                            int & left,    
                            int & bottom,
                            int & right,    
                            int & top);    


// for gcgsGetScreenShot
class GcGsScreenShot 
{
public:
    virtual OdBool getSize (int & width,             
                            int & height,
                            int & depth) const = 0; 

    virtual OdBool getColorMap (int       index,
                                OdUInt8 & red,
                                OdUInt8 & green,
                                OdUInt8 & blue) const = 0;

    virtual void const * getScanline (int offsetFromLeft,
                                      int offsetFromTop) const = 0;

    GcGsScreenShot();
    virtual ~GcGsScreenShot () = 0;
};

// Compatibility definition
#define ScreenShot GcGsScreenShot

GS_TOOLKIT_EXPORT_EX 
GcGsScreenShot * gcgsGetScreenShot (int viewportNumber);

GS_TOOLKIT_EXPORT_EX 
void gcgsSetViewportRenderFlag (int viewportNumber);

GS_TOOLKIT_EXPORT_EX 
OdBool gcgsDisplayImage            (int          viewportNumber,
                                    long         originLeft,    
                                    long         originTop,    
                                    int          imageWidth,    
                                    int          imageHeight,    
                                    void const * imageData,        
                                    int          hasTransparency);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsRemoveAnonymousGraphics (int viewportNumber);


typedef void (*gcgsCustomUpdateMethod) (void * pParm, int left, int right, int bottom, int top);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsSetCustomUpdateMethod (gcgsCustomUpdateMethod custom_update_method, void * pParm);

GS_TOOLKIT_EXPORT_EX 
void gcgsRedrawShortTermGraphics (short minx, short miny, short maxx, short maxy);


namespace GcGs
{
    enum LinePattern { eSolid                         = 0,
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

GS_TOOLKIT_EXPORT_EX 
void gcgsSetHighlightColor (OdUInt16 colorIndex);

GS_TOOLKIT_EXPORT_EX 
OdUInt16 gcgsGetHighlightColor (void);

GS_TOOLKIT_EXPORT_EX 
void gcgsSetHighlightLinePattern (GcGs::LinePattern pattern);

GS_TOOLKIT_EXPORT_EX 
GcGs::LinePattern gcgsGetHighlightLinePattern (void);

GS_TOOLKIT_EXPORT_EX 
void gcgsSetHighlightLineWeight (OdUInt16 weight);

GS_TOOLKIT_EXPORT_EX 
OdUInt16 gcgsGetHighlightLineWeight (void);


GS_TOOLKIT_EXPORT_EX 
OdBool gcgsSetViewParameters (int viewportNumber, const GcGsView * pView,
                              bool bRegenRequired, bool bRescaleRequired,
                              bool bSyncRequired = false);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsGetViewParameters (int viewportNumber, GcGsView * pView);

GS_TOOLKIT_EXPORT_EX 
OdBool gcgsSetLensLength (int viewportNumber, const double & lensLength);

GS_TOOLKIT_EXPORT_EX 
OdBool gcgsGetLensLength (int viewportNumber, double & lensLength);

GS_TOOLKIT_EXPORT_EX 
void   gcgsWriteViewToUndoController (int viewportNumber);

GS_TOOLKIT_EXPORT_EX 
OdBool gcgsSetView2D (int viewportNumber);


GS_TOOLKIT_EXPORT_EX 
GcGsView *    gcgsGetGsView (int viewportNumber, bool bCreateIfNone);

GS_TOOLKIT_EXPORT_EX
GcGsManager * gcgsGetGsManager (CView * pView = NULL); 

GS_TOOLKIT_EXPORT_EX
GcGsModel *   gcgsGetGsModel (GcGiTransientDrawingMode mode,
                              int subDrawingMode,
                              int viewportNumber);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsGetOrthoViewParameters (int viewportNumber, 
                                   GcDb::OrthographicView view,
                                   GcGeVector3d * pViewDir,
                                   GcGeVector3d * pUpVector);


// for gcgsCreate2DViewLimitManager and gcgsDestroy2DViewLimitManager 
class  GcGs2DViewLimitManager 
{      
public:
    virtual               ~GcGs2DViewLimitManager (void) { }
    virtual bool          testView                (const GcGePoint3d & target,
                                                   double              dFieldHeight)  = 0;
};

GS_TOOLKIT_EXPORT_EX 
GcGs2DViewLimitManager * gcgsCreate2DViewLimitManager  (int viewportNumber);

GS_TOOLKIT_EXPORT_EX 
void   gcgsDestroy2DViewLimitManager (GcGs2DViewLimitManager * pLimitManager);

GS_TOOLKIT_EXPORT_EX 
OdBool gcgsDrawableModified (GcGiDrawable *pDrawable, 
                             GcGiDrawable *pParentDrawable);
GS_TOOLKIT_EXPORT_EX 
OdBool gcgsDrawableErased (GcGiDrawable *pDrawable, 
                           GcGiDrawable *pParentDrawable);

GS_TOOLKIT_EXPORT_EX 
HBITMAP gcgsGetViewImage (GcGsView *pGsView, int nWidth, int nHeight);

GS_TOOLKIT_EXPORT_EX 
void gcgsSetLineWeightDisplay(GcGsDevice *pDevice, bool bDisplay);

#endif //__GCGS_H__INCLUDED__

