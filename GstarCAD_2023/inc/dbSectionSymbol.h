/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbViewSymbol.h"

#pragma pack (push, 8)

#ifndef GCSYNERGY_PORT
#define GCSYNERGY_PORT
#endif

class GCSYNERGY_PORT GcDbSectionSymbol : public GcDbViewSymbol
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSectionSymbol);
  GcDbSectionSymbol();

  int               sectionPointsCount() const;
  void              getSectionPoints(GcGePoint3dArray &pts) const;
  Gcad::ErrorStatus getSectionPointAt(int idx, GcGePoint3d& pt) const;
  Gcad::ErrorStatus getBulgeAt(int idx, double& bulge) const;
  Gcad::ErrorStatus getLabelNameAt(int idx, GcString& sName) const;
  Gcad::ErrorStatus getLabelOffsetAt(int idx, GcGeVector3d& offset) const;
  void              getLabelOffsets(GcGeVector3dArray& offsets) const;
  bool              isViewDirectionLeft() const;
  bool              isHalfSection() const;

  Gcad::ErrorStatus setSectionPoints(const GcGePoint3dArray& pts);
  Gcad::ErrorStatus setSectionPoints(const GcGePoint3dArray& pts, const GcGeDoubleArray& bulges);
  Gcad::ErrorStatus addSectionPoint(const GcGePoint3d& pt, double bulge = 0);
  Gcad::ErrorStatus removeSectionPointAt(int idx);
  Gcad::ErrorStatus setSectionPointAt(int idx, const GcGePoint3d& pt, double bulge = 0);
  void              clearSectionPoints();
  Gcad::ErrorStatus setLabelNameAt(int idx, const GCHAR* pName);
  Gcad::ErrorStatus setLabelNames(const GcArray<GcString>& names);
  Gcad::ErrorStatus setLabelOffsetAt(int idx, const GcGeVector3d& offset);
  Gcad::ErrorStatus setLabelOffsets(const GcGeVector3dArray& offsets);
  void              resetLabelOffsets(bool allOffsets = true);
  void              setViewDirectionLeft(bool bLeft);
  void              setIsHalfSection(bool bHalfSection);
  bool              flipDirection();
};

#pragma pack (pop)