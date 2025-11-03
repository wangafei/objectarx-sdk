#pragma once

#include "zgs.h"

class ZcDbViewportTableRecord;
class ZcGiDrawable;
class ZcGsGraphicsKernel;
class ZcGsKernelDescriptor;
class ZcGsView;
class ZcGsModel;
class ZcGsDevice;
class ZcGsConfig;
struct ZcGsClientViewInfo;
class ZcDbDatabase;

#ifndef DRAWBRIDGE_API
#define DRAWBRIDGE_API __declspec(dllimport)
#endif
class ZcGsManager
{
public:
                                ZcGsManager             (void) { }
    virtual                    ~ZcGsManager             (void) { }

	virtual ZcGsModel*  createZWCADModel          (ZcGsGraphicsKernel &kernel)                                = 0;
	virtual ZcGsView*   createZWCADViewport       (ZcGsGraphicsKernel &kernel, ZcDbViewportTableRecord *pVTR) = 0;
	virtual ZcGsView*   createZWCADView           (ZcGsGraphicsKernel &kernel, ZcGiDrawable *pDrawable)       = 0;
	virtual ZcGsDevice* createZWCADDevice         (ZcGsGraphicsKernel &kernel, ZcGsWindowingSystemID id)      = 0;
	virtual ZcGsDevice* createZWCADOffScreenDevice(ZcGsGraphicsKernel &kernel)                                = 0;

	virtual ZcGsGraphicsKernel *  getGSClassFactory       (void)                          = 0;
    virtual void                destroyZWCADModel     (ZcGsModel  * model)            = 0;
    virtual void                destroyZWCADView      (ZcGsView   * view)             = 0;
    virtual void                destroyZWCADDevice    (ZcGsDevice * device)           = 0;
    virtual ZcGsView*   createViewport              (ZcGsDevice* pDevice, ZcDbViewportTableRecord *pVTR)        = 0;
    virtual ZcGsView*   createView                  (ZcGsDevice* pDevice)                                       = 0;
    virtual void        destroyView                 (ZcGsView*, ZcDbViewportTableRecord* pVTR = nullptr)        = 0;
    virtual ZcGsModel*  getDBModel                  (ZcGsGraphicsKernel &kernel)                                = 0;
    virtual ZcGsDevice* getGUIDevice                (ZcGsGraphicsKernel &kernel)                                = 0;
    virtual void        setGsModel                  (const ZcDbDatabase* pDb, ZcGsModel* pModel)                = 0;
    virtual ZcGsModel*  gsModel                     (const ZcDbDatabase* pDb) const                             = 0;
    virtual void        setGsHighlightModel         (const ZcDbDatabase* pDb, ZcGsModel* pModel)                = 0;
    virtual ZcGsModel*  gsHighlightModel            (const ZcDbDatabase* pDb) const                             = 0;
    virtual ZcGsDevice* getOffScreenDevice(ZcGsGraphicsKernel &kernel) = 0;
    virtual ZcGsView*   getOffScreenView(ZcGsGraphicsKernel &kernel, ZcGsClientViewInfo &clientViewInfo)        = 0;
    virtual bool        hasGsModel(const ZcDbDatabase* pDb) const                                               = 0;
    virtual bool        invalidateGsModel(const ZcDbDatabase* pDb)                                              = 0;

	DRAWBRIDGE_API  static ZcGsGraphicsKernel*  acquireGraphicsKernel(const ZcGsKernelDescriptor &descriptor);

	DRAWBRIDGE_API  static void                  releaseGraphicsKernel(ZcGsGraphicsKernel *pKernel);

	DRAWBRIDGE_API  static ZcGsConfig*           getConfig            (void);
};

