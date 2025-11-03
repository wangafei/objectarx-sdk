/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTCONFIGMGR_H
#define GCPLPLOTCONFIGMGR_H

#include "GdGChar.h"
#include "GcPl.h"
#include "gcarray.h"
#include "GcPlObject.h"

class GcPlPlotConfig;
class HT_Thin_Plot_Config_Manager;
class HT_Error_Handler;

enum DeviceType {
  kSystemPrinter = 0,
  kPC3File = 1,
  kOneOffConfig = 2,
  kUninitialized = -1
};

class GcPlPlotConfigInfo : public GcPlObject
{
public:
  GCPL_PORT GcPlPlotConfigInfo();
  GCPL_PORT GcPlPlotConfigInfo(const GCHAR * pDevName,
    const GCHAR * pFullPath,
    DeviceType devType);
  GCPL_PORT GcPlPlotConfigInfo(const GcPlPlotConfigInfo &copy);

  GCPL_PORT Gcad::ErrorStatus copyFrom(const GcRxObject* pSrc);
  GCPL_PORT const GcPlPlotConfigInfo& operator=(const GcPlPlotConfigInfo& src);
  GCPL_PORT ~GcPlPlotConfigInfo();
  GCPL_DECLARE_MEMBERS(GcPlPlotConfigInfo);

  GCPL_PORT const GCHAR * fullPath() const;
  GCPL_PORT void setFullPath(const GCHAR * pPath);

  GCPL_PORT const GCHAR * deviceName() const;
  GCPL_PORT void setDeviceName(const GCHAR * pDevName);

  GCPL_PORT DeviceType deviceType() const;
  GCPL_PORT void setDeviceType(DeviceType devType);

  GCPL_PORT const GCHAR * deviceId() const;
  GCPL_PORT void setDeviceId(const GCHAR * pDevId);
};

class GSOFT_NO_VTABLE GcPlPlotConfigManager
{
public:

  enum RefreshCode {
    kAll,
    kRefreshDevicesList,
    kRefreshStyleList,
    kRefreshSystemDevicesList,
    kRefreshPC3DevicesList
  };
  enum StyTypes {
    kUndefined = 0,
    kRegular = 0x01,
    kTranslation = 0x02,
    kColorDep = 0x04,
    kAllTypes = 0x07
  };
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
    kPDFePlot,
    kPDFePlotGeneralDocs,
    kPDFePlotHighQuality,
    kPDFePlotSmallerFile,
    kPDFePlotWebMobile,
    kSVFePlot
  };

  virtual bool getDevicesList(GcArray<GcPlPlotConfigInfo,
    GcArrayObjectCopyReallocator <GcPlPlotConfigInfo> > &deviceList);
  virtual bool getStyleList(GcArray<GCHAR *> &list,
    long styType = kAllTypes);
  virtual void refreshList(RefreshCode refreshCode = kAll);

  virtual Gcad::ErrorStatus getCurrentConfig(GcPlPlotConfig*& pConfig);
  virtual Gcad::ErrorStatus setCurrentConfig(GcPlPlotConfig*& pConfig,
    const GCHAR * pDeviceName);

  virtual const GCHAR * getStdConfigName(StdConfigs stdConfig);
  virtual HT_Thin_Plot_Config_Manager* thinPltCfgMgr();
  virtual HT_Error_Handler* errorHandler();
  virtual HT_Error_Handler* gcadErrorHandler();
};

GCPL_PORT GcPlPlotConfigManager* GSOFT_STDCALL gcplPlotConfigManagerPtr();
#define gcplPlotConfigManager gcplPlotConfigManagerPtr()

#endif 