/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBPLOTSETVAL_H
#define GD_DBPLOTSETVAL_H

#include "GdGChar.h"

#pragma pack (push, 8)
template <class T, class R> class GcArray;
class GcDbPlotSettings;

typedef GcDbPlotSettings::PlotPaperUnits PlotPaperUnits;
typedef GcDbPlotSettings::PlotRotation   PlotRotation;
typedef GcDbPlotSettings::PlotType       PlotType;
typedef GcDbPlotSettings::StdScaleType   StdScaleType;

class GCDB_PORT GcDbPlotSettingsValidator {
public:
  virtual Gcad::ErrorStatus setPlotCfgName(GcDbPlotSettings* pPlotSet,
    const GCHAR * plotDeviceName,
    const GCHAR * mediaName = NULL) = 0;
  virtual Gcad::ErrorStatus setCanonicalMediaName(GcDbPlotSettings* pPlotSet,
    const GCHAR * mediaName) = 0;
  virtual Gcad::ErrorStatus setPlotOrigin(GcDbPlotSettings *pPlotSet,
    const double xCoordinate,
    const double yCoordinate) = 0;
  virtual Gcad::ErrorStatus setPlotPaperUnits(GcDbPlotSettings* pPlotSet, const PlotPaperUnits units) = 0;
  virtual Gcad::ErrorStatus setPlotRotation(GcDbPlotSettings* pPlotSet, const PlotRotation rotationType) = 0;
  virtual Gcad::ErrorStatus setPlotCentered(GcDbPlotSettings* pPlotSet, Gsoft::Boolean isCentered) = 0;
  virtual Gcad::ErrorStatus setPlotType(GcDbPlotSettings* pPlotSet,
    const PlotType plotAreaType) = 0;
  virtual Gcad::ErrorStatus setPlotWindowArea(GcDbPlotSettings* pPlotSet,
    const double xmin,
    const double ymin,
    const double xmax,
    const double ymax) = 0;
  virtual Gcad::ErrorStatus setPlotViewName(GcDbPlotSettings* pPlotSet,
    const GCHAR * viewName) = 0;
  virtual Gcad::ErrorStatus setUseStandardScale(GcDbPlotSettings* pPlotSet,
    Gsoft::Boolean useStandard) = 0;
  virtual Gcad::ErrorStatus setCustomPrintScale(GcDbPlotSettings* pPlotSet,
    const double numerator,
    const double denominator) = 0;
  virtual Gcad::ErrorStatus setCurrentStyleSheet(GcDbPlotSettings* pPlotSet, const GCHAR * styleSheetName) = 0;
  virtual Gcad::ErrorStatus setStdScaleType(GcDbPlotSettings* pPlotSet, const StdScaleType scaleType) = 0;
  virtual Gcad::ErrorStatus setStdScale(GcDbPlotSettings* pPlotSet, const double standardScale) = 0;
  virtual Gcad::ErrorStatus plotDeviceList(GcArray<const GCHAR *> & deviceList) = 0;
  virtual Gcad::ErrorStatus canonicalMediaNameList(GcDbPlotSettings* pPlotSet, GcArray<const GCHAR *> & mediaList) = 0;
  virtual Gcad::ErrorStatus getLocaleMediaName(GcDbPlotSettings *pPlotSet,
    const GCHAR *  canonicalName,
    const GCHAR *& localeName) = 0;
  virtual Gcad::ErrorStatus getLocaleMediaName(GcDbPlotSettings *pPlotSet,
    int index,
    const GCHAR *& localeName) = 0;
  virtual Gcad::ErrorStatus setClosestMediaName(GcDbPlotSettings* pPlotSet,
    const double paperWidth,
    const double paperHeight,
    const PlotPaperUnits units,
    Gsoft::Boolean matchPrintableArea) = 0;
  virtual Gcad::ErrorStatus plotStyleSheetList(GcArray<const GCHAR *> & styleList) = 0;

  virtual void refreshLists(GcDbPlotSettings* pPlotSet) = 0;
  virtual void setZoomToPaperOnUpdate(GcDbPlotSettings* pPlotSet, Gsoft::Boolean doZoom) = 0;
  virtual Gcad::ErrorStatus setDefaultPlotConfig(GcDbPlotSettings* pPlotSet) = 0;
};
#pragma pack (pop)
#endif 