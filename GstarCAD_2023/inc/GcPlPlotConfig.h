/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTCONFIG_H
#define GCPLPLOTCONFIG_H

#include "GcPl.h"

#include "gcarray.h"
#include "gepnt2d.h"
#include "geblok2d.h"
#include "dblayout.h"

class HT_Plot_Config;
class HT_Media_Size;
class HT_Media_Description;

class GcPlPlotConfig : public GcPlObject
{
  GCPL_DECLARE_MEMBERS(GcPlPlotConfig)

public:
  enum PlotToFileCapability {
    kNoPlotToFile = 0,
    kPlotToFileAllowed = 1,
    kMustPlotToFile = 2
  };

public:
  GCPL_PORT ~GcPlPlotConfig();
  GCPL_PORT virtual Gcad::ErrorStatus copyFrom(const GcRxObject* pSrc);
  GCPL_PORT virtual void getDescriptionFields(GCHAR*& pDriverName,
    GCHAR*& pLocationName,
    GCHAR*& pComment,
    GCHAR*& pPortName,
    GCHAR*& pServerName,
    GCHAR*& pTagLine) const;
  GCPL_PORT virtual const GCHAR* deviceName() const;
  GCPL_PORT virtual const GCHAR* fullPath() const;
  GCPL_PORT virtual unsigned int maxDeviceDPI() const;
  GCPL_PORT virtual unsigned long deviceType() const;
  GCPL_PORT virtual void getCanonicalMediaNameList(GcArray<GCHAR*> &mediaList) const;
  GCPL_PORT virtual void getLocalMediaName(const GCHAR* pCanonicalMediaName,
    GCHAR* &pLocalMediaName) const;
  GCPL_PORT virtual void getMediaBounds(const GCHAR* pCanonicalMediaName,
    GcGePoint2d &pageSize,
    GcGeBoundBlock2d &printableArea) const;
  GCPL_PORT virtual void refreshMediaNameList();
  GCPL_PORT virtual bool isPlotToFile() const;
  GCPL_PORT virtual Gcad::ErrorStatus setPlotToFile(bool bPlotToFile);
  GCPL_PORT virtual Gcad::ErrorStatus getDefaultFileExtension(const GCHAR*& pDefaultExtension) const;
  GCPL_PORT virtual PlotToFileCapability plotToFileCapability() const;
  GCPL_PORT virtual bool saveToPC3(const GCHAR* pPC3Name);
  GCPL_PORT virtual HT_Plot_Config* plotConfig() const;
  GCPL_PORT virtual unsigned long isCustomPossible(double width, double height,
    bool bIsDimensional, bool bIsSheet, int dpi, const
    GCHAR * pPC3Dir) const;
  GCPL_PORT virtual bool matchMediaSize(double page_x, double page_y,
    double printable_w, double printable_h,
    GcDbLayout::PlotPaperUnits units,
    bool bIsSheet, int dpi,
    const GCHAR * pTargetCanonicalName,
    GCHAR *& pNearestSizeName,
    GCHAR *& pLocalizedName,
    double & scaleFactor);

  GCPL_PORT virtual Gcad::ErrorStatus makeCustomMediaFromSizeDesc(
    HT_Media_Size * pSize, HT_Media_Description * pDesc,
    bool bSameDriver, bool bSavePC3,
    const GCHAR * pSourceEntry, const GCHAR * pSourceName,
    GCHAR *& pCanonicalSizeName, GCHAR *& pLocalizedSizeName,
    GCHAR *& pPMPPath, GCHAR *& pPC3Path, int dpi, double & scaleFactor);

protected:
  friend class GcPlPlotConfigManagerImp;
  friend class GcPlPlotInfoImp;
  friend class GcPlPlotInfoValidatorImp;

  GcPlPlotConfig(HT_Plot_Config* pConfig, const GCHAR* pDevName,
    const GCHAR* pFullPath, unsigned long nDevType);
  GcPlPlotConfig(const GcPlPlotConfig* pOther);

private:
  GcPlPlotConfig();

};

#endif 