#ifndef _GCPLPLOTCONFIG_H
#define _GCPLPLOTCONFIG_H

#include "GcPl.h"
#include "GcPlObject.h"

#include "GcArray.h"
#include "gepnt2d.h"
#include "geblok2d.h"
#include "dblayout.h"

class HT_Plot_Config;
class HT_Media_Size;
class HT_Media_Description;

class  GcPlPlotConfig : public GcPlObject
{
    GCPL_DECLARE_MEMBERS(GcPlPlotConfig);

public:
    enum PlotToFileCapability {
        kNoPlotToFile       = 0,
        kPlotToFileAllowed  = 1,
        kMustPlotToFile     = 2
    };

public:
    GCPL_PORT virtual ~GcPlPlotConfig();

    GCPL_PORT virtual OdResult copyFrom(const GcRxObject* pSrc);
	
    // returns the description field information - driver name
    // location, comment, port name, server name and tag line
    GCPL_PORT virtual void getDescriptionFields(GCHAR*& pDriverName,
        GCHAR*& pLocationName,
        GCHAR*& pComment,
        GCHAR*& pPortName,
        GCHAR*& pServerName,
        GCHAR*& pTagLine) const;

    // returns the current device name from the current plot config
    GCPL_PORT virtual const GCHAR* deviceName() const;

    // returns the full path name if the current plot config is of a pc3 file
    // or the UNC name if it is a system printer
    GCPL_PORT virtual const GCHAR* fullPath() const;

    // returns the maximum DPI supported by the device
    GCPL_PORT virtual unsigned int maxDeviceDPI() const;

    // returns the deviceType for the current plot config device
    GCPL_PORT virtual unsigned long deviceType() const;

    // returns the canonical media name list for the current device
    GCPL_PORT virtual void getCanonicalMediaNameList(GcArray<GCHAR*> &mediaList) const;

    // given a canonical media name, returns its local media name
    GCPL_PORT virtual void getLocalMediaName(const GCHAR* pCanonicalMediaName, 
        GCHAR* &pLocalMediaName) const;

    // returns the media bounds (page size and printable bounds) for the 
    // canonical media name passed in
    GCPL_PORT virtual void getMediaBounds(const GCHAR* pCanonicalMediaName,
        GcGePoint2d &pageSize, 
        GcGeBoundBlock2d &printableArea) const;

    // resets the current cGched media name list
    GCPL_PORT virtual void refreshMediaNameList();

    // gets/sets the config's plot to file setting
    GCPL_PORT virtual bool isPlotToFile() const;
    GCPL_PORT virtual OdResult setPlotToFile(bool bPlotToFile);

    // returns the device's default file extension (if any)
    // including the leading '.'
    GCPL_PORT virtual OdResult getDefaultFileExtension(const GCHAR*& pDefaultExtension) const;

    // returns the device's plot-to-file capability
    GCPL_PORT virtual PlotToFileCapability plotToFileCapability() const;

    // saves the current configuration to the specified pc3 file
    // Note: This doesn't load the saved pc3 as current config.
    // Use the method getPlotConfig() and pass in saved pc3 file to 
    // get to the plot config
    GCPL_PORT virtual bool saveToPC3(const GCHAR* pPC3Name);

    // returns the current HT_Plot_Config object (for internal use only)
    GCPL_PORT virtual HT_Plot_Config* plotConfig() const;

    // internal use only
    GCPL_PORT virtual unsigned long isCustomPossible(double width, double height, 
        bool bIsDimensional, bool bIsSheet, int dpi, const
        GCHAR * pPC3Dir) const;

    // internal use only
    GCPL_PORT virtual bool matchMediaSize(double page_x, double page_y,
        double printable_w, double printable_h, 
        GcDbLayout::PlotPaperUnits units, 
        bool bIsSheet, int dpi, 
        const GCHAR * pTargetCanonicalName, 
        GCHAR *& pNearestSizeName, 
        GCHAR *& pLocalizedName,
        double & scaleFGctor);

    // internal use only
    GCPL_PORT virtual OdResult makeCustomMediaFromSizeDesc( 
        HT_Media_Size * pSize, HT_Media_Description * pDesc,
        bool bSameDriver, bool bSavePC3,
        const GCHAR * pSourceEntry, const GCHAR * pSourceName, 
        GCHAR *& pCanonicalSizeName, GCHAR *& pLocalizedSizeName, 
        GCHAR *& pPMPPath, GCHAR *& pPC3Path, int dpi, double & scaleFGctor);

protected:
    friend class GcPlPlotConfigManagerImp;
    /*friend class GcPlPlotInfoImp;
    friend class GcPlPlotInfoValidatorImp;*/
    GcPlPlotConfig(HT_Plot_Config* pConfig, const GCHAR* pDevName, 
        const GCHAR* pFullPath, unsigned long nDevType);

    GcPlPlotConfig(const GcPlPlotConfig* pOther);

private:
    GcPlPlotConfig();

};

#endif // _GCPLPLOTCONFIG_H


