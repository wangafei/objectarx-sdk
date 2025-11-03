/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBPLOTSETTINGS_H
#define GD_DBPLOTSETTINGS_H

#include "dbmain.h"
#include "dbdict.h"
#include "GcDbCore2dDefs.h"

class IGcReadStream;

#pragma pack(push, 8)

class GCDB_PORT GcDbPlotSettings : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbPlotSettings);
  GcDbPlotSettings();
  GcDbPlotSettings(bool ModelType);
  ~GcDbPlotSettings();

  using GcDbObject::copyFrom;

  Gcad::ErrorStatus copyFrom(GcDbPlotSettings *fromPlotSettings);

  enum PlotPaperUnits {
    kInches,
    kMillimeters,
    kPixels
  };

  enum PlotRotation {
    k0degrees,
    k90degrees,
    k180degrees,
    k270degrees
  };

  enum PlotType {
    kDisplay,
    kExtents,
    kLimits,
    kView,
    kWindow,
    kLayout
  };

  enum StdScaleType {
    kScaleToFit,
    k1_128in_1ft,
    k1_64in_1ft,
    k1_32in_1ft,
    k1_16in_1ft,
    k3_32in_1ft,
    k1_8in_1ft,
    k3_16in_1ft,
    k1_4in_1ft,
    k3_8in_1ft,
    k1_2in_1ft,
    k3_4in_1ft,
    k1in_1ft,
    k3in_1ft,
    k6in_1ft,
    k1ft_1ft,
    k1_1,
    k1_2,
    k1_4,
    k1_5,
    k1_8,
    k1_10,
    k1_16,
    k1_20,
    k1_30,
    k1_40,
    k1_50,
    k1_100,
    k2_1,
    k4_1,
    k8_1,
    k10_1,
    k100_1,
    k1000_1,
    k1and1_2in_1ft
  };

  enum ShadePlotType {
    kAsDisplayed = 0,
    kWireframe = 1,
    kHidden = 2,
    kRendered = 3,
    kVisualStyle = 4,
    kRenderPreset = 5
  };

  enum ShadePlotResLevel {
    kDraft,
    kPreview,
    kNormal,
    kPresentation,
    kMaximum,
    kCustom
  };

  Gcad::ErrorStatus addToPlotSettingsDict(GcDbDatabase *towhichDb);
  Gcad::ErrorStatus getPlotSettingsName(const GCHAR *& plotSettingsName) const;
  Gcad::ErrorStatus getPlotSettingsName(GCHAR *& plotSettingsName) const;
  Gcad::ErrorStatus setPlotSettingsName(const GCHAR * plotSettingsName);
  Gcad::ErrorStatus getPlotCfgName(const GCHAR *& plotCfgName) const;
  Gcad::ErrorStatus getPlotPaperMargins(double& printableXmin,
    double& printableYmin,
    double& printableXmax,
    double& printableYmax) const;
  Gcad::ErrorStatus getPlotPaperSize(double& paperWidth, double& paperHeight) const;
  Gcad::ErrorStatus getPlotPaperSize(GcGePoint2d& paperSize) const;

  Gcad::ErrorStatus getCanonicalMediaName(const GCHAR *& mediaName) const;
  Gcad::ErrorStatus getCanonicalMediaName(GcString& mediaName) const;

  Gcad::ErrorStatus getPlotOrigin(double& x, double& y) const;
  Gcad::ErrorStatus getPlotOrigin(GcGePoint2d& origin) const;
  GcDbPlotSettings::PlotPaperUnits plotPaperUnits() const;

  Gsoft::Boolean plotViewportBorders() const;
  void setPlotViewportBorders(Gsoft::Boolean plotViewportBorders);

  Gsoft::Boolean plotTransparency() const;
  void setPlotTransparency(Gsoft::Boolean plotTransparency);

  Gsoft::Boolean plotPlotStyles() const;
  void setPlotPlotStyles(Gsoft::Boolean plotPlotStyles);

  Gsoft::Boolean showPlotStyles() const;
  void setShowPlotStyles(Gsoft::Boolean showPlotStyles);

  GcDbPlotSettings::PlotRotation plotRotation() const;
  Gsoft::Boolean plotCentered() const;

  Gsoft::Boolean plotHidden() const;
  void setPlotHidden(Gsoft::Boolean plotHidden);

  GcDbPlotSettings::ShadePlotType shadePlot() const;
  Gcad::ErrorStatus setShadePlot(GcDbPlotSettings::ShadePlotType shadePlot);

  GcDbPlotSettings::ShadePlotResLevel shadePlotResLevel() const;
  Gcad::ErrorStatus setShadePlotResLevel(GcDbPlotSettings::ShadePlotResLevel resLevel);
  Gsoft::Int16 shadePlotCustomDPI() const;
  Gcad::ErrorStatus setShadePlotCustomDPI(Gsoft::Int16 val);
  GcDbPlotSettings::PlotType plotType() const;
  Gcad::ErrorStatus getPlotWindowArea(double& xmin,
    double& ymin,
    double& xmax,
    double& ymax) const;
  Gcad::ErrorStatus getPlotViewName(const GCHAR *& viewName) const;
  Gsoft::Boolean useStandardScale() const;
  Gcad::ErrorStatus getCustomPrintScale(double& numerator, double& denominator) const;
  Gcad::ErrorStatus getCurrentStyleSheet(const GCHAR *& styleSheetName) const;
  IGcReadStream* getStyleSheetReadStream();

  GcDbPlotSettings::StdScaleType stdScaleType() const;
  Gcad::ErrorStatus getStdScale(double& scale) const;

  Gsoft::Boolean scaleLineweights() const;
  void setScaleLineweights(Gsoft::Boolean scaleLineweights);

  Gsoft::Boolean printLineweights() const;
  void setPrintLineweights(Gsoft::Boolean printLineweights);

  Gsoft::Boolean drawViewportsFirst() const;
  void setDrawViewportsFirst(Gsoft::Boolean drawViewportsFirst);

  Gsoft::Boolean modelType() const;
  GcDbObjectId shadePlotId() const;
  Gcad::ErrorStatus setShadePlot(GcDbPlotSettings::ShadePlotType type, GcDbObjectId shadePlotId);
  bool plotWireframe() const;
  bool plotAsRaster() const;

protected:
  virtual Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif