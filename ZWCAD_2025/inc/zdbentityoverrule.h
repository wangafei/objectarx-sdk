

#pragma once

#include "zrxoverrule.h"

#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbPropertiesOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbPropertiesOverrule);

    ZcDbPropertiesOverrule();
    
    virtual void list(const ZcDbEntity* pSubject);

    virtual Zcad::ErrorStatus getClassID(const ZcDbObject* pSubject, CLSID* pClsid);
};

class ZCDBCORE2D_PORT ZcDbOsnapOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbOsnapOverrule);

    ZcDbOsnapOverrule();

    virtual Zcad::ErrorStatus getOsnapPoints(
                                const ZcDbEntity*   pSubject,
                                ZcDb::OsnapMode     osnapMode,
                                ZSoft::GsMarker     gsSelectionMark,
                                const ZcGePoint3d&  pickPoint,
                                const ZcGePoint3d&  lastPoint,
                                const ZcGeMatrix3d& viewXform,
                                ZcGePoint3dArray&   snapPoints,
                                ZcDbIntArray &   geomIds);

    virtual Zcad::ErrorStatus getOsnapPoints(
                                const ZcDbEntity*   pSubject,
                                ZcDb::OsnapMode     osnapMode,
                                ZSoft::GsMarker     gsSelectionMark,
                                const ZcGePoint3d&  pickPoint,
                                const ZcGePoint3d&  lastPoint,
                                const ZcGeMatrix3d& viewXform,
                                ZcGePoint3dArray&   snapPoints,
                                ZcDbIntArray &   geomIds,
                                const ZcGeMatrix3d& insertionMat);

    virtual bool isContentSnappable(const ZcDbEntity*   pSubject);
};

class ZCDBCORE2D_PORT ZcDbTransformOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbTransformOverrule);

    ZcDbTransformOverrule();

    virtual Zcad::ErrorStatus   transformBy(ZcDbEntity* pSubject, const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus   getTransformedCopy(const ZcDbEntity* pSubject, const ZcGeMatrix3d& xform,
                                                            ZcDbEntity*& pEnt);

    virtual Zcad::ErrorStatus   explode(const ZcDbEntity* pSubject, ZcDbVoidPtrArray& entitySet);

    virtual ZSoft::Boolean      cloneMeForDragging(ZcDbEntity* pSubject);

    virtual bool                hideMeForDragging(const ZcDbEntity* pSubject);
};

class ZCDBCORE2D_PORT ZcDbGripOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGripOverrule);

    ZcDbGripOverrule();

    virtual Zcad::ErrorStatus   getGripPoints(const ZcDbEntity* pSubject, 
                                ZcGePoint3dArray&  gripPoints,
                                ZcDbIntArray &     osnapModes,
                                ZcDbIntArray &  geomIds);

    virtual Zcad::ErrorStatus   moveGripPointsAt(ZcDbEntity* pSubject, 
                                    const ZcDbIntArray & indices,
                                    const ZcGeVector3d& offset);

    virtual Zcad::ErrorStatus   getGripPoints(const ZcDbEntity* pSubject,
                                                        ZcDbGripDataPtrArray& grips,
                                                        const double curViewUnitSize, 
                                                        const int gripSize, 
                                                        const ZcGeVector3d& curViewDir, 
                                                        const int bitflags);

    virtual Zcad::ErrorStatus   moveGripPointsAt(ZcDbEntity* pSubject,
                                            const ZcDbVoidPtrArray& gripAppData,
                                            const ZcGeVector3d& offset, 
                                            const int bitflags);

    virtual Zcad::ErrorStatus   getStretchPoints(const ZcDbEntity* pSubject,
                                                           ZcGePoint3dArray& stretchPoints);

    virtual Zcad::ErrorStatus   moveStretchPointsAt(ZcDbEntity* pSubject,
                                                              const ZcDbIntArray & indices,
                                                              const ZcGeVector3d& offset);

     virtual void gripStatus(ZcDbEntity* pSubject, const ZcDb::GripStat status);
};


class ZCDBCORE2D_PORT ZcDbSubentityOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSubentityOverrule);

    ZcDbSubentityOverrule();

    virtual Zcad::ErrorStatus addSubentPaths(ZcDbEntity* pSubject, const ZcDbFullSubentPathArray& newPaths);

    virtual Zcad::ErrorStatus deleteSubentPaths(ZcDbEntity* pSubject, const ZcDbFullSubentPathArray& paths);

    virtual Zcad::ErrorStatus transformSubentPathsBy(ZcDbEntity* pSubject,
                                            const ZcDbFullSubentPathArray& paths,
                                            const ZcGeMatrix3d&            xform);

    virtual Zcad::ErrorStatus getGripPointsAtSubentPath(
                                   const ZcDbEntity*              pSubject,
                                   const ZcDbFullSubentPath&      path,
                                   ZcDbGripDataPtrArray&          grips,
                                   const double                   curViewUnitSize,
                                   const int                      gripSize,
                                   const ZcGeVector3d&            curViewDir,
                                   const int                      bitflags);

    virtual Zcad::ErrorStatus moveGripPointsAtSubentPaths(
                                    ZcDbEntity*                    pSubject,
                                    const ZcDbFullSubentPathArray& paths,
                                    const ZcDbVoidPtrArray&        gripAppData,
                                    const ZcGeVector3d&            offset,
                                    const int                      bitflags);

    virtual  Zcad::ErrorStatus getSubentPathsAtGsMarker(
                                    const ZcDbEntity*      pSubject,
                                    ZcDb::SubentType       type,
                                    ZSoft::GsMarker        gsMark, 
                                    const ZcGePoint3d&     pickPoint,
                                    const ZcGeMatrix3d&    viewXform, 
                                    int&                   numPaths,
                                    ZcDbFullSubentPath*&   subentPaths, 
                                    int                    numInserts = 0,
                                    ZcDbObjectId*          entAndInsertStack = NULL);

    virtual  Zcad::ErrorStatus getGsMarkersAtSubentPath(
                                    const ZcDbEntity*         pSubject,
                                    const ZcDbFullSubentPath& subPath, 
                                    ZcArray<ZSoft::GsMarker>& gsMarkers);

    virtual ZcDbEntity* subentPtr(const ZcDbEntity* pSubject, const ZcDbFullSubentPath& id);

    virtual void        subentGripStatus(
                                        ZcDbEntity*               pSubject,
                                        const ZcDb::GripStat      status,
                                        const ZcDbFullSubentPath& subentity);

    virtual Zcad::ErrorStatus getCompoundObjectTransform(const ZcDbEntity* pSubject, ZcGeMatrix3d & xMat);

    virtual Zcad::ErrorStatus getSubentPathGeomExtents(const ZcDbEntity* pSubject,
                                    const ZcDbFullSubentPath& path, 
                                    ZcDbExtents&              extents);

    virtual Zcad::ErrorStatus getSubentClassId(const ZcDbEntity* pSubject,
                                    const ZcDbFullSubentPath& path,
                                    CLSID*                    clsId);
};

class ZCDBCORE2D_PORT ZcDbHighlightOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbHighlightOverrule);

    ZcDbHighlightOverrule();

    virtual Zcad::ErrorStatus highlight(
                                const ZcDbEntity*      pSubject,
                                const ZcDbFullSubentPath& subId = kNullSubent,
                                const ZSoft::Boolean highlightAll = false);

    virtual Zcad::ErrorStatus unhighlight(
                                    const ZcDbEntity*      pSubject,
                                    const ZcDbFullSubentPath& subId = kNullSubent, 
                                    const ZSoft::Boolean highlightAll = false);
};


class ZCDBCORE2D_PORT ZcDbHighlightStateOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbHighlightStateOverrule);

    ZcDbHighlightStateOverrule();

    virtual Zcad::ErrorStatus  pushHighlight(
                                    ZcDbEntity*               pSubject,
                                    const ZcDbFullSubentPath& subId,
                                    ZcGiHighlightStyle        highlightStyle);

    virtual Zcad::ErrorStatus  popHighlight(
                                    ZcDbEntity*               pSubject,
                                    const ZcDbFullSubentPath& subId);

    virtual ZcGiHighlightStyle highlightState(
                                    ZcDbEntity*               pSubject,
                                    const ZcDbFullSubentPath& subId);
};

class ZCDBCORE2D_PORT ZcDbVisibilityOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbVisibilityOverrule);

    ZcDbVisibilityOverrule();

    virtual ZcDb::Visibility visibility(const ZcDbEntity* pSubject);

    virtual Zcad::ErrorStatus setVisibility(ZcDbEntity* pSubject,
                                    ZcDb::Visibility newVal,
                                    ZSoft::Boolean doSubents = true);
};

class ZCDBCORE2D_PORT ZcDbGeometryOverrule : public ZcRxOverrule
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGeometryOverrule);

    ZcDbGeometryOverrule();

    virtual  Zcad::ErrorStatus intersectWith(
                                            const ZcDbEntity* pSubject,
                                            const ZcDbEntity* pEnt,
                                            ZcDb::Intersect intType, 
                                            ZcGePoint3dArray& points,
                                            ZSoft::GsMarker thisGsMarker = 0, 
                                            ZSoft::GsMarker otherGsMarker = 0);

    virtual  Zcad::ErrorStatus intersectWith(
                                            const ZcDbEntity* pSubject,
                                            const ZcDbEntity* pEnt,
                                            ZcDb::Intersect intType, 
                                            const ZcGePlane& projPlane,
                                            ZcGePoint3dArray& points, 
                                            ZSoft::GsMarker thisGsMarker = 0,
                                            ZSoft::GsMarker otherGsMarker = 0);

    virtual  Zcad::ErrorStatus getGeomExtents(const ZcDbEntity* pSubject, ZcDbExtents& extents);
};

#pragma pack (pop)
