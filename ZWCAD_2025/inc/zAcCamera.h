

#pragma once

#include "zacdb.h"
#include "zdbmain.h"
#include "zdbents.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef CAMERADLLIMPEXP
#undef CAMERADLLIMPEXP
#endif

#ifdef ZCCAMERA_EXPORTS
#define CAMERADLLIMPEXP __declspec( dllexport )
#else
#define CAMERADLLIMPEXP
#endif

class ZcDbImpCamera;

class CAMERADLLIMPEXP ZcDbCamera: public ZcDbEntity
{

public:
    ZcDbCamera ();
    virtual ~ZcDbCamera();
    ZCDB_DECLARE_MEMBERS(ZcDbCamera);
    ZcDbObjectId view() const;
    Zcad::ErrorStatus	setView(const ZcDbObjectId viewId);

	virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing);
	virtual Zcad::ErrorStatus   subOpen(ZcDb::OpenMode openMode);
	virtual Zcad::ErrorStatus   subClose();

	virtual Zcad::ErrorStatus	dwgInFields(ZcDbDwgFiler* filer);
	virtual Zcad::ErrorStatus	dwgOutFields(ZcDbDwgFiler* filer) const;

	virtual Zcad::ErrorStatus	dxfInFields(ZcDbDxfFiler* filer);
	virtual Zcad::ErrorStatus	dxfOutFields(ZcDbDxfFiler* filer) const;

protected:
	virtual ZSoft::Boolean subWorldDraw(ZcGiWorldDraw*	mode);
	virtual void subViewportDraw(ZcGiViewportDraw* mode);
	virtual ZSoft::UInt32 subSetAttributes(ZcGiDrawableTraits* pTraits);

	virtual void              subList() const;

    virtual Zcad::ErrorStatus subGetGripPoints(
        ZcDbGripDataPtrArray& grips,
		const double curViewUnitSize,
		const int gripSize,
		const ZcGeVector3d& curViewDir,
		const int bitflags) const;

	virtual Zcad::ErrorStatus subMoveGripPointsAt(
		const ZcDbVoidPtrArray& gripAppData,
		const ZcGeVector3d& offset,
		const int bitflags);

	virtual Zcad::ErrorStatus subGetStretchPoints(
		ZcGePoint3dArray&  stretchPoints)
		const;
	virtual Zcad::ErrorStatus subMoveStretchPointsAt(
		const ZcDbIntArray& indices,
		const ZcGeVector3d&     offset);
	virtual Zcad::ErrorStatus subTransformBy(const ZcGeMatrix3d& xform);

    virtual Zcad::ErrorStatus subDeepClone(
        ZcDbObject* pOwnerObject,
		ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,
		ZSoft::Boolean isPrimary
		= ZSoft::kTrue) const;

    virtual Zcad::ErrorStatus subWblockClone(
        ZcRxObject* pOwnerObject,
		ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,
		ZSoft::Boolean isPrimary
		= ZSoft::kTrue) const;
	
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const;

    virtual Zcad::ErrorStatus subHighlight(
        const ZcDbFullSubentPath& subId = kNullSubent,
        const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;

    virtual Zcad::ErrorStatus subUnhighlight(
        const ZcDbFullSubentPath& subId = kNullSubent,
        const ZSoft::Boolean highlightAll = ZSoft::kFalse) const;

	virtual Zcad::ErrorStatus subGetGeomExtents(ZcDbExtents& extents) const;
private:
    friend class ZcDbImpCamera;

	ZSoft::UInt32       baseSetAttributes(ZcGiDrawableTraits* pTraits);
	Zcad::ErrorStatus   baseGetStretchPoints(ZcGePoint3dArray&  stretchPoints) const;
	Zcad::ErrorStatus   baseMoveStretchPointsAt(const ZcDbIntArray & indices, const ZcGeVector3d& offset);
	Zcad::ErrorStatus   baseDeepClone(ZcDbObject* pOwner,ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap,ZSoft::Boolean isPrimary) const;
	Zcad::ErrorStatus   baseWblockClone(ZcRxObject* pOwnerObject, ZcDbObject*& pClonedObject,
		ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary) const;
	Zcad::ErrorStatus   baseHighlight(const ZcDbFullSubentPath& subId,
		const ZSoft::Boolean highlightAll) const;
	Zcad::ErrorStatus   baseUnhighlight(const ZcDbFullSubentPath& subId,
		const ZSoft::Boolean highlightAll) const;

    ZcDbImpCamera* pImp;
};

#pragma pack (pop)
