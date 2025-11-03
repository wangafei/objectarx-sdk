/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifndef DBBLENDOPTIONS_H
#define DBBLENDOPTIONS_H

#include "gcdb.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbBlendOptions
{
public:
  GcDbBlendOptions();
  ~GcDbBlendOptions();

  enum DriveModeType {
    kDriveModeFirst = 0,
    kDriveModeSecond = 1,
    kDriveModeBoth = 2
  };

  GcDbBlendOptions& operator = (const GcDbBlendOptions& src);

  bool  simplify() const;
  Gcad::ErrorStatus  setSimplify(bool val);
  bool  solid() const;
  Gcad::ErrorStatus  setSolid(bool val);
  unsigned int  quality() const;
  Gcad::ErrorStatus  setQuality(unsigned int val);
  GcGePoint3d*  coplanarPoint() const;
  Gcad::ErrorStatus  setCoplanarPoint(const GcGePoint3d* pPt);
  GcGeVector3d*  coplanarDirection() const;
  Gcad::ErrorStatus  setCoplanarDirection(const GcGeVector3d* pDir);
  GcDbBlendOptions::DriveModeType  driveMode() const;
  Gcad::ErrorStatus  setDriveMode(GcDbBlendOptions::DriveModeType val);
private:
  void *mpImpBlendOptions;
  friend class GcDbImpBlendOptions;
};

#pragma pack(pop)

#endif 