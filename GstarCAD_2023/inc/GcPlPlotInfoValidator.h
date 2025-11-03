/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCPLPLOTINFOVALIDATOR_H
#define   _GCPLPLOTINFOVALIDATOR_H

#include "GcPlObject.h"
#include "GcPlPlotInfo.h"

class GcPlPlotInfo;

#define DEFAULT_MEDIA_GROUP_WEIGHT 50
#define DEFAULT_SHEET_MEDIA_GROUP_WEIGHT 10
#define DEFAULT_MEDIA_BOUNDS_WEIGHT 100
#define DEFAULT_PRINTABLE_BOUNDS_WEIGHT 10
#define DEFAULT_DIMENSIONAL_WEIGHT 50
#define DEFAULT_SHEET_DIMENSIONAL_WEIGHT 10
#define DEFAULT_THRESHOLD 500

class GcPlPlotInfoValidator : public GcPlObject
{
public:
  GCPL_PORT GcPlPlotInfoValidator();
  GCPL_PORT ~GcPlPlotInfoValidator();

  GCPL_DECLARE_MEMBERS(GcPlPlotInfoValidator);

public:
  enum MatchingPolicy {
    kMatchDisabled = 1,
    kMatchEnabled,
    kMatchEnabledCustom,
    kMatchEnabledTmpCustom
  };

  enum eCustomSizeResult {
    ePossible = 0x0000,
    eMustCreatePC3 = 0x0001,
    eRotationRequired = 0x0002,
    ePC3DirReadOnly = 0x0004,
    ePMPDirReadOnly = 0x0008,
    ePMPDirMissing = 0x0010,
    eUnknownErrPMPDir = 0x0020,
    ePC3FileReadOnly = 0x0040,
    eSizeTooBig = 0x0080,
    eException = 0x0100,
    eUnknownErrPC3File = 0x0200,
    eUnknownErrPMPFile = 0x0400,
    ePMPFileReadOnly = 0x0800,
    eWidthAndHeightMustBePositive = 0x1000,
    eDeviceLoadFailed = 0x2000
  };


  GCPL_PORT virtual Gcad::ErrorStatus validate(GcPlPlotInfo& info);
  GCPL_PORT virtual unsigned long isCustomPossible(GcPlPlotInfo& info) const;

  GCPL_PORT void setMediaMatchingPolicy(MatchingPolicy policy);
  GCPL_PORT MatchingPolicy matchingPolicy() const;

  GCPL_PORT void setMediaGroupWeight(unsigned int weight = DEFAULT_MEDIA_GROUP_WEIGHT);
  GCPL_PORT unsigned int mediaGroupWeight() const;

  GCPL_PORT void setSheetMediaGroupWeight(unsigned int weight = DEFAULT_SHEET_MEDIA_GROUP_WEIGHT);
  GCPL_PORT unsigned int sheetMediaGroupWeight() const;

  GCPL_PORT void setMediaBoundsWeight(unsigned int weight = DEFAULT_MEDIA_BOUNDS_WEIGHT);
  GCPL_PORT unsigned int mediaBoundsWeight() const;

  GCPL_PORT void setPrintableBoundsWeight(unsigned int weight = DEFAULT_PRINTABLE_BOUNDS_WEIGHT);
  GCPL_PORT unsigned int printableBoundsWeight() const;

  GCPL_PORT void setDimensionalWeight(unsigned int weight = DEFAULT_DIMENSIONAL_WEIGHT);
  GCPL_PORT unsigned int dimensionalWeight() const;

  GCPL_PORT void setSheetDimensionalWeight(unsigned int weight = DEFAULT_SHEET_DIMENSIONAL_WEIGHT);
  GCPL_PORT unsigned int sheetDimensionalWeight() const;

  GCPL_PORT void setMediaMatchingThreshold(unsigned int threshold = DEFAULT_THRESHOLD);
  GCPL_PORT unsigned int mediaMatchingThreshold() const;

protected:
  unsigned int m_mediaBoundsWeight;
  unsigned int m_dimensionalWeight;
  unsigned int m_mediaGroupWeight;
  unsigned int m_printableBoundsWeight;
  unsigned int m_sheetDimensionalWeight;
  unsigned int m_sheetMediaGroupWeight;
  unsigned int m_matchingThreshold;

  MatchingPolicy m_matchingPolicy;
};
#endif 