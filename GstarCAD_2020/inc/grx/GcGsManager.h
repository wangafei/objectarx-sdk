#pragma once
#include "gcadstd.h"

class GcDbViewportTableRecord;
class GcGiDrawable;
class GcGsClassFactory;
class GcGsView;
class GcGsModel;
class GcGsDevice;
class IGcadDrawingSurface;

//////////////////////////////////////////////////////////////////////////
// 

class GcGsManager
{
public:
          GcGsManager(void)   { }
  virtual ~GcGsManager(void)  { }

  //////////////////////////////////////////////////////////////////////////
  // 以下7个函数内部不调用，做为兼容ARX接口存在
  virtual OdGsModel *         createCADModel    (void)                          = 0;
  virtual OdGsView *          createCADViewport (OdDbViewportTableRecord * vp)  = 0;
  virtual OdGsView *          createCADView     (OdGiDrawable * drawable)       = 0;
  virtual OdGsDevice *        createCADDevice   (HWND hWnd)                     = 0;
  virtual OdGsDevice *        createCADOffScreenDevice()                        = 0;

  virtual void                destroyCADModel   (OdGsModel  * model)            = 0;
  virtual void                destroyCADView    (OdGsView   * view)             = 0;
  virtual void                destroyCADDevice  (OdGsDevice * device)           = 0;

public:
  virtual GcGsClassFactory *  getGSClassFactory (void)                          = 0;
  virtual OdGsModel        *  getDBModel        (void)                          = 0;
  virtual OdGsDevice       *  getGUIDevice      (void)                          = 0;

  virtual IGcadDrawingSurface* getDrawingSurface(void) { return NULL; }
};


