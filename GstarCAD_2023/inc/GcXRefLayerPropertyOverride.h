/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once


class  GcXRefLayerPropertyOverride
{
public:
  enum XRefLayerPropertyOverrideType
  {
    On = 0,
    Freeze = 1,
    Lock = 2,
    Plot = 3,
    Color = 4,
    Linetype = 5,
    Lineweight = 6,
    Transparency = 7,
    PlotStyle = 8,
    NewVPFreeze = 9,
    Description = 10
  };

  GCDB_PORT static bool hasXRefLayerOverride(const GcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
  GCDB_PORT static bool hasAnyXRefLayerOverrides(const GcDbObjectId& hostLayerId);
  GCDB_PORT static bool hasAnyXRefLayerOverrides(GcDbDatabase* pHostDb);
  GCDB_PORT static bool hasXRefLayerOverride(GcDbBlockReference* pRef);
  GCDB_PORT static Gcad::ErrorStatus addXRefLayerOverride(const GcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
  GCDB_PORT static Gcad::ErrorStatus removeXRefLayerOverride(const GcDbObjectId& hostLayerId, XRefLayerPropertyOverrideType property);
  GCDB_PORT static Gcad::ErrorStatus removeXRefLayerOverride(GcDbDatabase* pHostDb, XRefLayerPropertyOverrideType property);
  GCDB_PORT static Gcad::ErrorStatus removeXRefLayerOverrides(const GcDbObjectId& hostLayerId);
  GCDB_PORT static Gcad::ErrorStatus removeXRefLayerOverrides(GcDbDatabase* pHostDb);
  GCDB_PORT static void enableXRefLayerPropertyOverrideRecording();
  GCDB_PORT static void disableXRefLayerPropertyOverrideRecording();
  GCDB_PORT static bool isXRefLayerPropertyOverrideRecordingEnabled();
};
