//
#ifndef   _GCPLPLOTINFO_H
#define   _GCPLPLOTINFO_H

#include "GcPl.h"
#include "GcPlObject.h"


class GcPlPlotConfig;
class GcRxObject;
class GcDbPlotSettings;

class GcPlPlotInfo : public GcPlObject
{
public:
	GCPL_DECLARE_MEMBERS(GcPlPlotInfo);

    GCPL_PORT GcPlPlotInfo();
    GCPL_PORT virtual ~GcPlPlotInfo();
	
public:

    enum MergeStatus {
        kNoChanges              = 0x00000000,
        kPlotCfgName            = 0x00000001,
        kPlotPaperMargins       = 0x00000002,
        kPlotPaperSize          = 0x00000004,
        kCanonicalMediaName     = 0x00000008,
        kPlotOrigin             = 0x00000010,
        kPlotPaperUnits         = 0x00000020,
        kPlotViewportBorders    = 0x00000040,
        kPlotPlotStyles         = 0x00000080,
        kShowPlotStyles         = 0x00000100,
        kPlotRotation           = 0x00000200,
        kPlotCentered           = 0x00000400,
        kPlotHidden             = 0x00000800,
        kShadePlot              = 0x00001000,
        kShadePlotResLevel      = 0x00002000,
        kShadePlotCustomDPI     = 0x00004000,
        kPlotType               = 0x00008000,
        kPlotWindowArea         = 0x00010000,
        kPlotViewName           = 0x00020000,
        kScale                  = 0x00040000,
        kCurrentStlyeSheet      = 0x00080000,
        kScaleLineWeights       = 0x00100000,
        kPrintLineWeights       = 0x00200000,
        kDrawViewportsFirst     = 0x00400000
    };

    GCPL_PORT OdResult copyFrom(const GcRxObject* pOther);

    // Layout to be plotted. Required. 
    GCPL_PORT void setLayout(GcDbObjectId& layoutId);

    // Layout to be plotted.  
    GCPL_PORT GcDbObjectId layout() const;

    // GcDbPlotSettings containing the settings to use for the plot. 
    // Optional, passing NULL removes any existing overrides. 
    // If not provided the object uses the layout settings. 
    GCPL_PORT void setOverrideSettings(const GcDbPlotSettings* pOverrides);

    // The current GcDbPlotSettings containing the overrides.
    GCPL_PORT const GcDbPlotSettings* overrideSettings() const;

    // Provides an GcPlPlotConfig (or PC3/Device name) to use instead of the
    // config/device specified in the layout or override.  Optional, passing
    // NULL removes any existing overrides. 
    GCPL_PORT void setDeviceOverride(const GcPlPlotConfig* pconf);

    // The "merged" GcDbPlotSettings object, created by merging the source
    // layout with the overrides and device override. 
    GCPL_PORT const GcDbPlotSettings* validatedSettings() const;

    // Sets the validated GcDbPlotSettings. 
    GCPL_PORT OdResult setValidatedSettings(const GcDbPlotSettings* pValidatedSettings);

    // The GcPlPlotConfig for the validated settings
    GCPL_PORT const GcPlPlotConfig* validatedConfig() const;

    // Sets the validated config
    GCPL_PORT void setValidatedConfig(const GcPlPlotConfig* pConfig);

    // The GcPlPlotConfig object (or PC3/Device name) 
    // that will override the output device set in the layout. 
    GCPL_PORT const GcPlPlotConfig* deviceOverride() const;

    // Returns a bool indicating whether the current overrides have been merged 
    // with the layout settings. 
    GCPL_PORT bool isValidated() const;

    // Gets the "changed" bits on the info object to indicate the what
    // properties of the source layout changed as a result of applying the plot
    // settings and device overrides.  
    GCPL_PORT unsigned long mergeStatus() const;

    // Could this object be sufficiently similar to another plot info,
    // satisfying the requirements of multi-page documents
    // (Same device name, media size, orientation, etc.)
    GCPL_PORT bool isCompatibleDocument(const GcPlPlotInfo* pOtherInfo) const;
};

#endif // _GCPLPLOTINFO_H
