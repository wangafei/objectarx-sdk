/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GEOTYPE_H
#define __GEOTYPE_H

#pragma pack (push, 8)

enum GcGeoMapType
{
  kNoMap = 0,
  kAerial = 1,
  kRoad = 2,
  kHybrid = 3
};

enum GcGeoMapResolution
{
  kCoarse = -1,
  kOptimal = 0,
  kFine = 1,
  kFiner = 2
};

#pragma pack (pop)
#endif 