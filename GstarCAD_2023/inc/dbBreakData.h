/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"

#pragma pack (push, 8)

class GcDbBreakPointRef;

class GCDB_PORT GcDbBreakData : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbBreakData);

  GcDbBreakData();
  ~GcDbBreakData();

  GcDbObjectId dimObjId() const;
  Gcad::ErrorStatus setDimObjId(const GcDbObjectId& dimId);

  Gcad::ErrorStatus addBreakPointRef(GcDbBreakPointRef* ptRef);
  Gcad::ErrorStatus getBreakPointRef(int lineIndex, GcArray<GcDbBreakPointRef*>& ptRefs) const;
  Gcad::ErrorStatus getBreakPointRef(GcArray<GcDbBreakPointRef*>& ptRefs) const;
  Gcad::ErrorStatus deleteAllBreakPointRefs();
  Gcad::ErrorStatus removeAssociativity(bool force = true);
  Gcad::ErrorStatus postToDb(GcDbObjectId& breakObjId);
  Gcad::ErrorStatus eraseFromDb(void);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;

  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;

  void  modifiedGraphics(const GcDbEntity* pEnt) override;

  Gcad::ErrorStatus updateAssociativity(const GcDbObjectIdArray& ids, int cmdType);
};

class GCDB_PORT GcDbBreakPointRef : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbBreakPointRef);

  enum BreakPointType {
    kDynamic = 0,
    kStatic = 1,
    kStatic2Point = 2
  };

  GcDbBreakPointRef();
  ~GcDbBreakPointRef();

  GcDbBreakPointRef::BreakPointType pointType() const;
  Gcad::ErrorStatus setPointType(GcDbBreakPointRef::BreakPointType newVal);
  Gsoft::Int32 lineIndex() const;
  Gcad::ErrorStatus setLineIndex(Gsoft::Int32 index);
  GcGePoint3d breakPoint() const;
  Gcad::ErrorStatus setBreakPoint(const GcGePoint3d& pt);
  GcGePoint3d breakPoint2() const;
  Gcad::ErrorStatus setBreakPoint2(const GcGePoint3d& pt);
  Gcad::ErrorStatus getBreakPointId(GcDbFullSubentPath& idPath) const;
  Gcad::ErrorStatus setBreakPointId(const GcDbFullSubentPath& idPath);
  GcDbEntity *subentPtr() const;
  Gcad::ErrorStatus intersectWith(const GcDbEntity* pEnt,
    GcGePoint3dArray& points,
    GcGePoint3dArray& textBoxPts);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;

  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;
};

GCDB_PORT Gcad::ErrorStatus gcdbGetBreakSubentIndex(GcDbEntity* pEnt,
  const GcGePoint3d& pickPt,
  const GcGeVector3d& viewDir,
  int& subentIndex,
  GcGePoint3d& ptOnEnt,
  const GcGeTol& tol = GcGeContext::gTol);

#pragma pack (pop)