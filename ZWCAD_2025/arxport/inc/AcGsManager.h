
#ifndef __ACGSMANAGER_H__
#define __ACGSMANAGER_H__

#include "gs.h"

#include "../../inc/zAcGsManager.h"

#ifndef AcDbDatabase
#define AcDbDatabase	ZcDbDatabase
#endif //#ifndef AcDbDatabase   

#ifndef AcGsClassFactory
#define AcGsClassFactory	ZcGsClassFactory
#endif //#ifndef AcGsClassFactory   

#ifndef AcGsConfig
#define AcGsConfig		ZcGsConfig
#endif //#ifndef AcGsConfig

#ifndef AcGsKernelDescriptor
#define AcGsKernelDescriptor		ZcGsKernelDescriptor
#endif //#ifndef AcGsKernelDescriptor

#ifndef AcGsGraphicsKernel
#define AcGsGraphicsKernel		ZcGsGraphicsKernel
#endif //#ifndef AcGsGraphicsKernel

#ifndef AcGsWindowingSystemID
#define AcGsWindowingSystemID		ZcGsWindowingSystemID
#endif //#ifndef AcGsWindowingSystemID

#ifndef AcGsClientViewInfo 
#define AcGsClientViewInfo 	ZcGsClientViewInfo 
#endif //#ifndef AcGsClientViewInfo    

#ifndef AcDbViewportTableRecord
#define AcDbViewportTableRecord		ZcDbViewportTableRecord
#endif //#ifndef AcDbViewportTableRecord

#ifndef AcGiDrawable
#define AcGiDrawable		ZcGiDrawable
#endif //#ifndef AcGiDrawable

#ifndef AcGsDevice
#define AcGsDevice		ZcGsDevice
#endif //#ifndef AcGsDevice

#ifndef AcGsManager
#define AcGsManager		ZcGsManager
#endif //#ifndef AcGsManager

#ifndef AcGsModel
#define AcGsModel		ZcGsModel
#endif //#ifndef AcGsModel

#ifndef AcGsView
#define AcGsView		ZcGsView
#endif //#ifndef AcGsView

#ifndef createAutoCADDevice
#define createAutoCADDevice		createZWCADDevice
#endif //#ifndef createAutoCADDevice

#ifndef createAutoCADModel
#define createAutoCADModel		createZWCADModel
#endif //#ifndef createAutoCADModel

#ifndef createAutoCADOffScreenDevice
#define createAutoCADOffScreenDevice		createZWCADOffScreenDevice
#endif //#ifndef createAutoCADOffScreenDevice

#ifndef createAutoCADView
#define createAutoCADView		createZWCADView
#endif //#ifndef createAutoCADView

#ifndef createAutoCADViewport
#define createAutoCADViewport		createZWCADViewport
#endif //#ifndef createAutoCADViewport

#ifndef destroyAutoCADDevice
#define destroyAutoCADDevice		destroyZWCADDevice
#endif //#ifndef destroyAutoCADDevice

#ifndef destroyAutoCADModel
#define destroyAutoCADModel		destroyZWCADModel
#endif //#ifndef destroyAutoCADModel

#ifndef destroyAutoCADView
#define destroyAutoCADView		destroyZWCADView
#endif //#ifndef destroyAutoCADView

#ifndef AcGsManager2
#define AcGsManager2 ZcGsManager2
#endif //#ifndef AcGsManager2

#endif //#ifndef __ACGSMANAGER_H__
