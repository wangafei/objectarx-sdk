/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DBSWEEPOPTIONS_H
#define DBSWEEPOPTIONS_H

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"

#pragma pack(push, 8)

class GCDB_PORT GcDbSweepOptions
{
public:
  GcDbSweepOptions();
  GcDbSweepOptions(const GcDbSweepOptions& src);
  ~GcDbSweepOptions();

  GcDbSweepOptions& operator = (const GcDbSweepOptions& src);
  bool              operator == (const GcDbSweepOptions&) const;

  enum AlignOption {
    kNoAlignment,
    kAlignSweepEntityToPath,
    kTranslateSweepEntityToPath,
    kTranslatePathToSweepEntity
  };

  enum MiterOption {
    kDefaultMiter,
    kOldMiter,
    kNewMiter,
    kCrimpMiter,
    kBendMiter
  };

  double  draftAngle() const;
  void    setDraftAngle(double ang);
  double  startDraftDist() const;
  void    setStartDraftDist(double val);
  double  endDraftDist() const;
  void    setEndDraftDist(double val);
  double  twistAngle() const;
  void    setTwistAngle(double ang);
  double  scaleFactor() const;
  void    setScaleFactor(double val);
  double  alignAngle() const;
  void    setAlignAngle(double ang);

  GcDbSweepOptions::AlignOption  align() const;
  void  setAlign(GcDbSweepOptions::AlignOption val);

  GcDbSweepOptions::MiterOption  miterOption() const;
  void  setMiterOption(GcDbSweepOptions::MiterOption val);

  bool  alignStart() const;
  void  setAlignStart(bool val);

  GcGePoint3d  basePoint() const;
  void  setBasePoint(GcGePoint3d& pnt);

  bool  bank() const;
  void  setBank(bool val);

  bool  checkIntersections() const;
  void  setCheckIntersections(bool val);

  GcGeVector3d  twistRefVec() const;
  void  setTwistRefVec(const GcGeVector3d& vec);

  bool  getSweepEntityTransform(GcGeMatrix3d& mat);
  void  setSweepEntityTransform(GcGeMatrix3d& mat);
  Gcad::ErrorStatus  setSweepEntityTransform(GcArray<GcDbEntity*>& sweepEntities, bool displayErrorMessages = false);

  bool  getPathEntityTransform(GcGeMatrix3d& mat);
  void  setPathEntityTransform(GcGeMatrix3d& mat);
  Gcad::ErrorStatus  setPathEntityTransform(GcDbEntity *pPathEnt, bool displayErrorMessages = false);

  Gcad::ErrorStatus  checkSweepCurve(GcDbEntity *pSweepEnt,
    GcDb::Planarity& planarity, GcGePoint3d& pnt, GcGeVector3d& vec,
    bool& closed, double& approxArcLen, bool displayErrorMessages = false);
  Gcad::ErrorStatus  checkPathCurve(GcDbEntity *pPathEnt, bool displayErrorMessages = false);

private:
  void *mpImpSweepOptions;
  friend class GcDbImpSweepOptions;
};
#pragma pack(pop)

#endif 