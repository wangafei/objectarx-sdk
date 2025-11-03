
#ifndef _GCPLPLOTCONFIGINFO_H
#define _GCPLPLOTCONFIGINFO_H

#include "GcPl.h"
#include "gcplobject.h"


enum DeviceType {
	kSystemPrinter = 0,
	kPC3File = 1,
	kOneOffConfig = 2,      // for internal use only
	kUninitialized = -1
};

class GcPlPlotConfigInfo : public GcPlObject
{
	GCPL_DECLARE_MEMBERS(GcPlPlotConfigInfo);

public:
    GCPL_PORT GcPlPlotConfigInfo();
    GCPL_PORT GcPlPlotConfigInfo(const GCHAR * pDevName,
        const GCHAR * pFullPath, 
        DeviceType devType);
    // copy constructor
    GCPL_PORT GcPlPlotConfigInfo(const GcPlPlotConfigInfo &copy);

    // assignment operator calls this method to copy the contents from src
    GCPL_PORT OdResult copyFrom(const GcRxObject* pSrc);

    // assignment operator copies the device name, full path and device type
    // information
    GCPL_PORT const GcPlPlotConfigInfo& operator=(const GcPlPlotConfigInfo& src);

    // destructor
    GCPL_PORT virtual ~GcPlPlotConfigInfo();

    //GcPl_DECLARE_MEMBERS(GcPlPlotConfigInfo);

    // returns the full path for the pc3 file. In case of system printers
    // just returns the UNC name
    GCPL_PORT const GCHAR * fullPath() const;

    // call to set the full path for the pc3 file or just the UNC name for 
    // system printers
    GCPL_PORT void setFullPath(const GCHAR * pPath);

    // returns the pc3 filename+ext portion or UNC name for system printers
    GCPL_PORT const GCHAR * deviceName() const;

    // call to set the pc3 filename+ext portion or UNC name for system printers
    GCPL_PORT void setDeviceName(const GCHAR * pDevName);

    // returns the device type (kSystemPrinter, kPC3file)
    GCPL_PORT DeviceType deviceType() const;

    // call to set the device type (kSystemPrinter, kPC3file)
    GCPL_PORT void setDeviceType(DeviceType devType);
};

#endif //_GCPLPLOTCONFIGINFO_H
