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
#define DRAWBRIDGE_API /*__declspec(dllimport)*/
#endif
class ZcGsManager
{
public:
	ZcGsManager(void) { }
    virtual ~ZcGsManager(void) { }

	virtual ZcGsModel* createZWCADModel(ZcGsGraphicsKernel &kernel) = 0;
	virtual ZcGsView* createZWCADViewport(ZcGsGraphicsKernel &kernel, ZcDbViewportTableRecord *pVTR) = 0;
	virtual ZcGsView* createZWCADView(ZcGsGraphicsKernel &kernel, ZcGiDrawable *pDrawable) = 0;
	virtual ZcGsDevice* createZWCADDevice(ZcGsGraphicsKernel &kernel, ZcGsWindowingSystemID id) = 0;
	virtual ZcGsDevice* createZWCADOffScreenDevice(ZcGsGraphicsKernel &kernel) = 0;

	virtual ZcGsGraphicsKernel* getGSClassFactory(void) = 0;
    virtual void destroyZWCADModel(ZcGsModel  * pModel) = 0;
	virtual void destroyZWCADView(ZcGsView* pView) = 0;
    virtual void destroyZWCADDevice(ZcGsDevice * pDevice) = 0;
    virtual ZcGsView* createViewport(ZcGsDevice* pDevice, ZcDbViewportTableRecord *pVTR) = 0;
    virtual ZcGsView* createView(ZcGsDevice* pDevice) = 0;
    virtual void destroyView(ZcGsView*, ZcDbViewportTableRecord* pVTR = nullptr) = 0;
    virtual ZcGsModel*  getDBModel(ZcGsGraphicsKernel &kernel) = 0;
    virtual ZcGsDevice* getGUIDevice(ZcGsGraphicsKernel &kernel) = 0;
	[[deprecated("Use ZcGsManager2::setGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel)")]]
    virtual void setGsModel(const ZcDbDatabase* pDb, ZcGsModel* pModel) = 0;
	[[deprecated("Use ZcGsManager2::gsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb)")]]
    virtual ZcGsModel* gsModel(const ZcDbDatabase* pDb) const = 0;
	[[deprecated("Use ZcGsManager2::setGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel)")]]
    virtual void setGsHighlightModel(const ZcDbDatabase* pDb, ZcGsModel* pModel) = 0;
	[[deprecated("Use ZcGsManager2::gsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb)")]]
    virtual ZcGsModel* gsHighlightModel(const ZcDbDatabase* pDb) const = 0;
    virtual ZcGsDevice* getOffScreenDevice(ZcGsGraphicsKernel &kernel) = 0;
    virtual ZcGsView* getOffScreenView(ZcGsGraphicsKernel &kernel, ZcGsClientViewInfo &clientViewInfo) = 0;
	[[deprecated("Use ZcGsManager2::hasGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb)")]]
    virtual bool hasGsModel(const ZcDbDatabase* pDb) const = 0;
    virtual bool invalidateGsModel(const ZcDbDatabase* pDb) = 0;

	static DRAWBRIDGE_API ZcGsGraphicsKernel* acquireGraphicsKernel(const ZcGsKernelDescriptor &descriptor);

	static DRAWBRIDGE_API void releaseGraphicsKernel(ZcGsGraphicsKernel *pKernel);

	static DRAWBRIDGE_API ZcGsConfig* getConfig(void);
};

class ZcGsManager2 : public ZcGsManager
{
public:
	virtual void setGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel) = 0;

	virtual ZcGsModel* gsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb) const = 0;

	virtual void setGsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb, ZcGsModel* pModel) = 0;

	virtual ZcGsModel* gsHighlightModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb) const = 0;

	virtual bool hasGsModel(ZcGsGraphicsKernel* pKernel, const ZcDbDatabase* pDb) const = 0;

	virtual bool activeGraphicsKernels(ZcArray<ZcGsGraphicsKernel*>& result) const = 0;

	virtual bool activeModels(ZcArray<ZcGsModel*>& result) const = 0;

	virtual bool activeModels(const ZcDbDatabase* pDb, ZcArray<ZcGsModel*>& result) const = 0;
};