/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gs.h" 

class GcDbViewportTableRecord;
class GcGiDrawable;
class GcGsGraphicsKernel;
class GcGsKernelDescriptor;
class GcGsView;
class GcGsModel;
class GcGsDevice;
class GcGsConfig;
struct GcGsClientViewInfo;
class GcDbDatabase;

#ifndef DRAWBRIDGE_API
#define DRAWBRIDGE_API 
#endif 

class GcGsManager
{
public:
  GcGsManager(void) { }
  virtual             ~GcGsManager(void) { }

  virtual GcGsModel*  createGscadModel(GcGsGraphicsKernel &kernel) = 0;
  virtual GcGsView*   createGscadViewport(GcGsGraphicsKernel &kernel, GcDbViewportTableRecord *pVTR) = 0;
  virtual GcGsView*   createGscadView(GcGsGraphicsKernel &kernel, GcGiDrawable *pDrawable) = 0;
  virtual GcGsDevice* createGscadDevice(GcGsGraphicsKernel &kernel, GcGsWindowingSystemID id) = 0;
  virtual GcGsDevice* createGscadOffScreenDevice(GcGsGraphicsKernel &kernel) = 0;

  virtual void        destroyGscadModel(GcGsModel  *pModel) = 0;
  virtual void        destroyGscadView(GcGsView   *pView) = 0;
  virtual void        destroyGscadDevice(GcGsDevice *pDevice) = 0;
  virtual GcGsView*   createViewport(GcGsDevice* pDevice, GcDbViewportTableRecord *pVTR) = 0;
  virtual GcGsView*   createView(GcGsDevice* pDevice) = 0;
  virtual void        destroyView(GcGsView*, GcDbViewportTableRecord* pVTR = nullptr) = 0;

  virtual GcGsModel*  getDBModel(GcGsGraphicsKernel &kernel) = 0;
  virtual GcGsDevice* getGUIDevice(GcGsGraphicsKernel &kernel) = 0;

  virtual void        setGsModel(const GcDbDatabase* pDb, GcGsModel* pModel) = 0;
  virtual GcGsModel*  gsModel(const GcDbDatabase* pDb) const = 0;

  virtual void        setGsHighlightModel(const GcDbDatabase* pDb, GcGsModel* pModel) = 0;
  virtual GcGsModel*  gsHighlightModel(const GcDbDatabase* pDb) const = 0;

  virtual GcGsDevice* getOffScreenDevice(GcGsGraphicsKernel &kernel) = 0;
  virtual GcGsView*   getOffScreenView(GcGsGraphicsKernel &kernel, GcGsClientViewInfo &clientViewInfo) = 0;

  virtual bool        hasGsModel(const GcDbDatabase* pDb) const = 0;
  virtual bool        invalidateGsModel(const GcDbDatabase* pDb) = 0;

  static DRAWBRIDGE_API GcGsGraphicsKernel*  acquireGraphicsKernel(const GcGsKernelDescriptor &descriptor);
  static DRAWBRIDGE_API void                  releaseGraphicsKernel(GcGsGraphicsKernel *pKernel);

  static DRAWBRIDGE_API GcGsConfig*           getConfig(void);
};