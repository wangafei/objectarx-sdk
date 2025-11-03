#ifndef _GCPLPLOTCONFIGMGR_H
#define _GCPLPLOTCONFIGMGR_H


#include "GcPl.h"
#include "GcArray.h"
#include "GcPlObject.h"
#include "GcPlPlotConfigInfo.h"
#include "GcPlPlotConfig.h"


class GcPlPlotConfig;
class HT_Thin_Plot_Config_Manager;
class HT_Error_Handler;

class GcPlPlotConfigManager
{

public:
	GcPlPlotConfigManager();

	virtual ~GcPlPlotConfigManager();

public:
	// Refresh Codes
	enum RefreshCode {
	    kAll,
        kRefreshDevicesList,
        kRefreshStyleList,
        kRefreshSystemDevicesList,
        kRefreshPC3DevicesList
	};
		    // Diffrent type of plot style tables
	enum StyTypes {
	    kUndefined      = 0,
	    kRegular        = 0x01,
	    kTranslation    = 0x02,
	    kColorDep       = 0x04,
	    kAllTypes       = 0x07
	};
		 		    // List of standard pc3 files that are installed by default
	enum StdConfigs {
		kNoneDevice,
		kDefaultWindowsSysPrinter,
		kDWF6ePlot,
		kDWFePlotOptForPlotting,
		kDWFePlotOptForViewing,
		kPublishToWebDWF,
		kPublishToWebJPG,
		kPublishToWebPNG,
		kDWFxePlot,
		kPublishToWebDWFx,
		kPDFePlot
	};
    // Returns the listof system printer, pc3 file installed on the current
    // system. Also includes the None device as the first element of the array
    virtual bool getDevicesList(GcArray<GcPlPlotConfigInfo, 
        GcArrayObjectCopyReallocator <GcPlPlotConfigInfo> > &deviceList);

    // Returns a list of plot style table based on the styType flag specified
    // currently installed on a system
    virtual bool getStyleList(GcArray<GCHAR *> &list, 
        long styType = kAllTypes); //VC8: Removed extra qualifier

    // Resets the local cache of the devices or plot style tables based on
    // the refreshCode specified
    virtual void refreshList(RefreshCode refreshCode = kAll);

    // Returns the current active plot config object in the Plot Config Manager
    // wrapped as a GcPlPlotConfig object
    virtual OdResult getCurrentConfig(GcPlPlotConfig*& pConfig);

    // Creates a plot config for the specified device, wraps it as a
    // GcPlPlotConfig object and returns it
	virtual OdResult setCurrentConfig(GcPlPlotConfig*& pConfig, 
		const GCHAR * pDeviceName);

    // Returns the localized name for the default pc3 files that are 
    // installed with AutoCAD
    virtual const GCHAR * getStdConfigName(StdConfigs stdConfig);

    // Returns a pointer to the current global thin plot config manager
    virtual HT_Thin_Plot_Config_Manager* thinPltCfgMgr(); //  (for internal use only)

    // Returns a pointer to the Plot Config Manager's error handler
    virtual HT_Error_Handler* errorHandler(); //  (for internal use only)

    // Returns a pointer the parent error handler (ACAD_Err_Handler)
    virtual HT_Error_Handler* acadErrorHandler(); //  (for internal use only)
};

GCPL_PORT GcPlPlotConfigManager* __stdcall gcplPlotConfigManagerPtr();
#define gcplPlotConfigManager gcplPlotConfigManagerPtr()

#endif // _GCPLPLOTCONFIGMGR_H


