/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDIMASSOC_H
#define GD_DBDIMASSOC_H

#include "dbmain.h"

class GcDb2LineAngularDimension;
class GcDb3PointAngularDimension;
class GcDbAlignedDimension;
class GcDbArcDimension;
class GcDbDiametricDimension;
class GcDbLeader;
class GcDbMLeader;
class GcDbOrdinateDimension;
class GcDbPointRef;
class GcDbRadialDimension;
class GcDbRadialDimensionLarge;
class GcDbRotatedDimension;

class GCDB_PORT GcDbDimAssoc : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDimAssoc);

  enum { kMaxPointRefs = 4 };

  enum PointType {
    kXline1Point = 0,
    kXline2Point = 1,
    kOriginPoint = 0,
    kDefiningPoint = 1,
    kXline1Start = 0,
    kXline1End = 1,
    kXline2Start = 2,
    kXline2End = 3,
    kVertexPoint = 2,
    kChordPoint = 0,
    kCenterPoint = 1,
    kFarChordPoint = 1,
    kOverrideCenterPoint = 2,
    kAngLineStart = 2,
    kJogPoint = 3,
    kAngLineEnd = 3,
    kLeaderPoint = 0
  };

  enum AssocFlags {
    kFirstPointRef = 1,
    kSecondPointRef = 2,
    kThirdPointRef = 4,
    kFourthPointRef = 8
  };

  enum RotatedDimType {
    kUnknown = 0,
    kParallel = 1,
    kPerpendicular = 2
  };

  GcDbDimAssoc();
  ~GcDbDimAssoc();
  GcDbObjectId dimObjId() const;
  Gcad::ErrorStatus setDimObjId(const GcDbObjectId& dimId);
  Gcad::ErrorStatus setAssocFlag(int ptType, bool value);
  void setAssocFlag(int assocFlg);
  bool assocFlag(int ptType) const;
  int assocFlag(void);
  Gcad::ErrorStatus setPointRef(int ptType, GcDbPointRef* ptRef);
  const GcDbPointRef *pointRef(int ptType) const;
  Gcad::ErrorStatus setRotatedDimType(RotatedDimType dimType);
  RotatedDimType    rotatedDimType() const;
  Gcad::ErrorStatus addToPointRefReactor();
  Gcad::ErrorStatus addToDimensionReactor(bool isAdd = true);
  Gcad::ErrorStatus removePointRef(int ptType);
  Gcad::ErrorStatus updateDimension(bool update = true, bool skipReactors = false);
  Gcad::ErrorStatus removeAssociativity(bool force = true);
  bool              isTransSpatial() const;
  Gcad::ErrorStatus setTransSpatial(bool value);
  Gcad::ErrorStatus startCmdWatcher();
  Gcad::ErrorStatus startOopsWatcher(bool bAddAll = true);
  void              removeOopsWatcher(void);
  Gcad::ErrorStatus restoreAssocFromOopsWatcher(void);
  bool              hasOopsWatcher(void) const;
  Gcad::ErrorStatus post(GcDbObjectId dimId,
    GcDbObjectId& dimAssocId,
    bool isActive = true);
  Gcad::ErrorStatus getDimAssocGeomIds(GcDbObjectIdArray& geomIds) const;
  bool              isAllGeomErased() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const override;
  void modifiedGraphics(const GcDbEntity* pObj) override;

  Gcad::ErrorStatus swapReferences(const GcDbIdMapping& idMap) override;
  Gcad::ErrorStatus updateFillet(const GcDbObjectIdArray& ids);
  Gcad::ErrorStatus updateAssociativity(const GcDbObjectIdArray& ids);
  Gcad::ErrorStatus updateXrefSubentPath();
  Gcad::ErrorStatus updateSubentPath(GcDbIdMapping& idMap);
  void updateDueToMirror(bool wasInMirror);

protected:
  Gcad::ErrorStatus   setPointRefReactor(int ptType,
    bool isAdd = true);
  Gcad::ErrorStatus   removeDimExtDict(void);
  bool                isPointBetweenRays(const GcGePoint3d& vertex,
    const GcGePoint3d& firstPt,
    const GcGePoint3d& secondPt,
    const GcGePoint3d& angPt,
    const GcGeVector3d& normal);
  Gcad::ErrorStatus   updateDimension(GcDbRotatedDimension* pRotDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbAlignedDimension* pAlnDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbRadialDimension* pRadDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbRadialDimensionLarge* pRadDimLarge,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbDiametricDimension* pDiaDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDb2LineAngularDimension* pA2Dim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDb3PointAngularDimension* pA3Dim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbOrdinateDimension* pOrdDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbArcDimension* pArcDim,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbLeader* pLeader,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimension(GcDbMLeader* pMLeader,
    GcGePoint3d* pNewPts,
    bool bUpdate = true);
  Gcad::ErrorStatus   updateDimLineAndTextLocation(GcDbRotatedDimension* pAlnDim,
    const GcGePoint3d* kpOldPts,
    const GcGePoint3d* kpNewPts);
  Gcad::ErrorStatus   updateDimLineAndTextLocation(GcDbAlignedDimension* pAlnDim,
    const GcGePoint3d* pOldPts,
    const GcGePoint3d* pNewPts);
  Gcad::ErrorStatus   updateDimLineAndTextLocation(GcDb2LineAngularDimension* pA2Dim,
    const GcGePoint3d* pOldPts,
    const GcGePoint3d* pNewPts);
  Gcad::ErrorStatus   updateDimLineAndTextLocation(GcDb3PointAngularDimension* pA3Dim,
    const GcGePoint3d* pOldPts,
    const GcGePoint3d* pNewPts);
  Gcad::ErrorStatus   updateDimLineAndTextLocation(GcDbArcDimension* pArcDim,
    const GcGePoint3d* kpOldPts,
    const GcGePoint3d* kpNewPts);
  Gcad::ErrorStatus   calculate3PointAngDimArcLocation(const GcGePoint3d* kpOldPts,
    const GcGePoint3d& kOldArcPt,
    const GcGePoint3d& kOldTextPt,
    const GcGePoint3d* kpNewPts,
    const GcGeVector3d& normal,
    GcGePoint3d& newArcPt,
    GcGePoint3d& newTextPt);
  Gcad::ErrorStatus   calculate2LineAngDimArcLocation(const GcGePoint3d* kpOldPts,
    const GcGePoint3d& kOldArcPt,
    const GcGePoint3d& kOldTextPt,
    const GcGePoint3d* kpNewPts,
    const GcGeVector3d& kNormal,
    GcGePoint3d& newArcPt,
    GcGePoint3d& newTextPt);
};

GCCORE_PORT
Gcad::ErrorStatus
gcdbPostDimAssoc(GcDbObjectId dimId, GcDbDimAssoc* pDimAssoc,
  GcDbObjectId& dimAssocId, bool isActive = true);

GCCORE_PORT
Gcad::ErrorStatus
gcdbUpdateDimension(GcDbObjectId dimId);

GCCORE_PORT
Gcad::ErrorStatus
gcdbUpdateAllDimensions(GcDbDatabase* pDb);

GCCORE_PORT
Gcad::ErrorStatus
gcdbGetDimAssocId(GcDbObjectId dimId, GcDbObjectId& dimAssocId);

GCCORE_PORT
Gcad::ErrorStatus
gcdbGetDimAssocIds(GcDbObjectId entId, GcDbObjectIdArray& dimAssocIds);

GCCORE_PORT
bool
gcdbIsTransSpatial(const GcDbFullSubentPath& idPath);

GCCORE_PORT Gcad::ErrorStatus
gcdbGetAssocAnnotationActionBody(const GcDbObjectId& idDim,
  GcDbObjectId& idActionBody
);

GCCORE_PORT Gcad::ErrorStatus
gcdbGetNonAssocAnnotations(GcDbDatabase* pDb, bool isPaperSpace, GcDbObjectId& blockId,
  GcDbObjectIdArray& annoIds, bool ignoreOffOrFrozenLayers = false);

GCCORE_PORT bool
gcdbIsEntityInBlockOrXref(const GcDbEntity* pEnt);

GCCORE_PORT bool
gcdbIsAnnoMonitorOn();

GCCORE_PORT bool
gcdbIsAssociativityAlertIconDisabled(GcDbEntity *pEnt);

GCCORE_PORT bool
gcdbDisableAssociativityAlertIcon(GcDbEntity *pEnt, bool disable);

GCCORE_PORT bool
gcdbIsAssociativeAnnotation(GcDbObject* pObj, bool* pIsPartialAssoc = NULL);

class GCCORE_PORT GcDbAnnoAlertDisabler
{
public:
  GcDbAnnoAlertDisabler(const GcDbObjectId& objId);
  ~GcDbAnnoAlertDisabler();
private:
  GcDbObjectId m_objId;
};

GCCORE_PORT bool
gcdbGetAssociativityOverride(GcDbEntity *pEnt, int& nValue);

GCCORE_PORT bool
gcdbSetAssociativityOverride(GcDbEntity *pEnt, int nValue);

#endif  