/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCPLPLOTINFO_H
#define   _GCPLPLOTINFO_H

#include "GcPlObject.h"
#include "dbid.h"

class GcPlPlotConfig;
class GcRxObject;
class GcDbPlotSettings;
class GcString;

class GcPlPlotInfo : public GcPlObject
{
public:
  GCPL_PORT GcPlPlotInfo();
  GCPL_PORT ~GcPlPlotInfo();

  GCPL_DECLARE_MEMBERS(GcPlPlotInfo);

public:

  enum MergeStatus {
    kNoChanges = 0x00000000,
    kPlotCfgName = 0x00000001,
    kPlotPaperMargins = 0x00000002,
    kPlotPaperSize = 0x00000004,
    kCanonicalMediaName = 0x00000008,
    kPlotOrigin = 0x00000010,
    kPlotPaperUnits = 0x00000020,
    kPlotViewportBorders = 0x00000040,
    kPlotPlotStyles = 0x00000080,
    kShowPlotStyles = 0x00000100,
    kPlotRotation = 0x00000200,
    kPlotCentered = 0x00000400,
    kPlotHidden = 0x00000800,
    kShadePlot = 0x00001000,
    kShadePlotResLevel = 0x00002000,
    kShadePlotCustomDPI = 0x00004000,
    kPlotType = 0x00008000,
    kPlotWindowArea = 0x00010000,
    kPlotViewName = 0x00020000,
    kScale = 0x00040000,
    kCurrentStlyeSheet = 0x00080000,
    kScaleLineWeights = 0x00100000,
    kPrintLineWeights = 0x00200000,
    kDrawViewportsFirst = 0x00400000,
    kPlotTransparency = 0x00800000
  };

  GCPL_PORT Gcad::ErrorStatus copyFrom(const GcRxObject* pOther);

  GCPL_PORT void setLayout(GcDbObjectId& layoutId);
  GCPL_PORT GcDbObjectId layout() const;

  GCPL_PORT void setOverrideSettings(const GcDbPlotSettings* pOverrides);
  GCPL_PORT const GcDbPlotSettings* overrideSettings() const;

  GCPL_PORT void setDeviceOverride(const GcPlPlotConfig* pconf);
  GCPL_PORT const GcPlPlotConfig* deviceOverride() const;

  GCPL_PORT const GcDbPlotSettings* validatedSettings() const;
  GCPL_PORT Gcad::ErrorStatus setValidatedSettings(const GcDbPlotSettings* pValidatedSettings);

  GCPL_PORT const GcPlPlotConfig* validatedConfig() const;
  GCPL_PORT void setValidatedConfig(const GcPlPlotConfig* pConfig);

  GCPL_PORT bool isValidated() const;
  GCPL_PORT unsigned long mergeStatus() const;
  GCPL_PORT bool isCompatibleDocument(const GcPlPlotInfo* pOtherInfo) const;
  GCPL_PORT GcString& OrgFilePath();
};

#endif 