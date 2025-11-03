/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxoverrule.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbPropertiesOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPropertiesOverrule);
  GcDbPropertiesOverrule();
  virtual void list(const GcDbEntity* pSubject);
  virtual Gcad::ErrorStatus getClassID(const GcDbObject* pSubject, CLSID* pClsid);
};

class GCDB_PORT GcDbOsnapOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbOsnapOverrule);
  GcDbOsnapOverrule();
  virtual Gcad::ErrorStatus getOsnapPoints(
    const GcDbEntity*   pSubject,
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds);
  virtual Gcad::ErrorStatus getOsnapPoints(
    const GcDbEntity*   pSubject,
    GcDb::OsnapMode     osnapMode,
    Gsoft::GsMarker     gsSelectionMark,
    const GcGePoint3d&  pickPoint,
    const GcGePoint3d&  lastPoint,
    const GcGeMatrix3d& viewXform,
    GcGePoint3dArray&   snapPoints,
    GcDbIntArray &   geomIds,
    const GcGeMatrix3d& insertionMat);
  virtual bool isContentSnappable(const GcDbEntity*   pSubject);
};

class GCDB_PORT GcDbTransformOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbTransformOverrule);
  GcDbTransformOverrule();
  virtual Gcad::ErrorStatus   transformBy(GcDbEntity* pSubject, const GcGeMatrix3d& xform);
  virtual Gcad::ErrorStatus   getTransformedCopy(const GcDbEntity* pSubject, const GcGeMatrix3d& xform, GcDbEntity*& pEnt);
  virtual Gcad::ErrorStatus   explode(const GcDbEntity* pSubject, GcDbVoidPtrArray& entitySet);
  virtual Gsoft::Boolean      cloneMeForDragging(GcDbEntity* pSubject);
  virtual bool                hideMeForDragging(const GcDbEntity* pSubject);
};

class GCDB_PORT GcDbGripOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGripOverrule);
  GcDbGripOverrule();
  virtual Gcad::ErrorStatus   getGripPoints(const GcDbEntity* pSubject,
    GcGePoint3dArray&  gripPoints,
    GcDbIntArray &     osnapModes,
    GcDbIntArray &  geomIds);
  virtual Gcad::ErrorStatus   moveGripPointsAt(GcDbEntity* pSubject,
    const GcDbIntArray & indices,
    const GcGeVector3d& offset);
  virtual Gcad::ErrorStatus   getGripPoints(const GcDbEntity* pSubject,
    GcDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const GcGeVector3d& curViewDir,
    const int bitflags);
  virtual Gcad::ErrorStatus   moveGripPointsAt(GcDbEntity* pSubject,
    const GcDbVoidPtrArray& gripAppData,
    const GcGeVector3d& offset,
    const int bitflags);
  virtual Gcad::ErrorStatus   getStretchPoints(const GcDbEntity* pSubject,
    GcGePoint3dArray& stretchPoints);
  virtual Gcad::ErrorStatus   moveStretchPointsAt(GcDbEntity* pSubject,
    const GcDbIntArray & indices,
    const GcGeVector3d& offset);
  virtual void gripStatus(GcDbEntity* pSubject, const GcDb::GripStat status);
};

class GCDB_PORT GcDbSubentityOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSubentityOverrule);
  GcDbSubentityOverrule();
  virtual Gcad::ErrorStatus addSubentPaths(GcDbEntity* pSubject, const GcDbFullSubentPathArray& newPaths);
  virtual Gcad::ErrorStatus deleteSubentPaths(GcDbEntity* pSubject, const GcDbFullSubentPathArray& paths);
  virtual Gcad::ErrorStatus transformSubentPathsBy(GcDbEntity* pSubject,
    const GcDbFullSubentPathArray& paths,
    const GcGeMatrix3d&            xform);
  virtual Gcad::ErrorStatus getGripPointsAtSubentPath(
    const GcDbEntity*              pSubject,
    const GcDbFullSubentPath&      path,
    GcDbGripDataPtrArray&          grips,
    const double                   curViewUnitSize,
    const int                      gripSize,
    const GcGeVector3d&            curViewDir,
    const int                      bitflags);
  virtual Gcad::ErrorStatus moveGripPointsAtSubentPaths(
    GcDbEntity*                    pSubject,
    const GcDbFullSubentPathArray& paths,
    const GcDbVoidPtrArray&        gripAppData,
    const GcGeVector3d&            offset,
    const int                      bitflags);
  virtual  Gcad::ErrorStatus getSubentPathsAtGsMarker(
    const GcDbEntity*      pSubject,
    GcDb::SubentType       type,
    Gsoft::GsMarker        gsMark,
    const GcGePoint3d&     pickPoint,
    const GcGeMatrix3d&    viewXform,
    int&                   numPaths,
    GcDbFullSubentPath*&   subentPaths,
    int                    numInserts = 0,
    GcDbObjectId*          entAndInsertStack = NULL);
  virtual  Gcad::ErrorStatus getGsMarkersAtSubentPath(
    const GcDbEntity*         pSubject,
    const GcDbFullSubentPath& subPath,
    GcArray<Gsoft::GsMarker>& gsMarkers);
  virtual GcDbEntity* subentPtr(const GcDbEntity* pSubject, const GcDbFullSubentPath& id);
  virtual void        subentGripStatus(
    GcDbEntity*               pSubject,
    const GcDb::GripStat      status,
    const GcDbFullSubentPath& subentity);
  virtual Gcad::ErrorStatus getCompoundObjectTransform(const GcDbEntity* pSubject, GcGeMatrix3d & xMat);
  virtual Gcad::ErrorStatus getSubentPathGeomExtents(const GcDbEntity* pSubject,
    const GcDbFullSubentPath& path,
    GcDbExtents&              extents);
  virtual Gcad::ErrorStatus getSubentClassId(const GcDbEntity* pSubject,
    const GcDbFullSubentPath& path,
    CLSID*                    clsId);
};

class GCDB_PORT GcDbHighlightOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbHighlightOverrule);
  GcDbHighlightOverrule();
  virtual Gcad::ErrorStatus highlight(
    const GcDbEntity*      pSubject,
    const GcDbFullSubentPath& subId = kNullSubent,
    const Gsoft::Boolean highlightAll = false);
  virtual Gcad::ErrorStatus unhighlight(
    const GcDbEntity*      pSubject,
    const GcDbFullSubentPath& subId = kNullSubent,
    const Gsoft::Boolean highlightAll = false);
};

class GcDbHighlightStateOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbHighlightStateOverrule);
  GcDbHighlightStateOverrule();
  virtual Gcad::ErrorStatus  pushHighlight(
    GcDbEntity*               pSubject,
    const GcDbFullSubentPath& subId,
    GcGiHighlightStyle        highlightStyle);
  virtual Gcad::ErrorStatus  popHighlight(
    GcDbEntity*               pSubject,
    const GcDbFullSubentPath& subId);
  virtual GcGiHighlightStyle highlightState(
    GcDbEntity*               pSubject,
    const GcDbFullSubentPath& subId);
};

class GCDB_PORT GcDbVisibilityOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbVisibilityOverrule);
  GcDbVisibilityOverrule();
  virtual GcDb::Visibility visibility(const GcDbEntity* pSubject);
  virtual Gcad::ErrorStatus setVisibility(GcDbEntity* pSubject,
    GcDb::Visibility newVal,
    Gsoft::Boolean doSubents = true);
};

class GCDB_PORT GcDbGeometryOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGeometryOverrule);
  GcDbGeometryOverrule();
  virtual  Gcad::ErrorStatus intersectWith(
    const GcDbEntity* pSubject,
    const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker = 0,
    Gsoft::GsMarker otherGsMarker = 0);
  virtual  Gcad::ErrorStatus intersectWith(
    const GcDbEntity* pSubject,
    const GcDbEntity* pEnt,
    GcDb::Intersect intType,
    const GcGePlane& projPlane,
    GcGePoint3dArray& points,
    Gsoft::GsMarker thisGsMarker = 0,
    Gsoft::GsMarker otherGsMarker = 0);
  virtual  Gcad::ErrorStatus getGeomExtents(const GcDbEntity* pSubject, GcDbExtents& extents);
};

#pragma pack (pop)