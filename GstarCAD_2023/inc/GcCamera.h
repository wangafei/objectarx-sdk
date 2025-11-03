/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcdb.h"
#include "dbmain.h"
#include "dbents.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef CAMERADLLIMPEXP
#undef CAMERADLLIMPEXP
#endif
#ifdef GCCAMERA_EXPORTS
#define CAMERADLLIMPEXP __declspec( dllexport )
#else
#define CAMERADLLIMPEXP 
#endif

class GcDbImpCamera;

class GCDB_PORT GcDbCamera : public GcDbEntity
{
public:
  GcDbCamera();
  ~GcDbCamera();
  GCDB_DECLARE_MEMBERS(GcDbCamera);

  GcDbObjectId      view() const;
  Gcad::ErrorStatus	setView(const GcDbObjectId viewId);

  Gcad::ErrorStatus subErase(Gsoft::Boolean erasing) override;
  Gcad::ErrorStatus subOpen(GcDb::OpenMode openMode) override;
  Gcad::ErrorStatus subClose() override;

  Gcad::ErrorStatus	dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus	dwgOutFields(GcDbDwgFiler* filer) const override;

  Gcad::ErrorStatus	dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus	dxfOutFields(GcDbDxfFiler* filer) const override;

protected:
  Gsoft::Boolean    subWorldDraw(GcGiWorldDraw*	mode) override;
  void              subViewportDraw(GcGiViewportDraw* mode) override;
  Gsoft::UInt32     subSetAttributes(GcGiDrawableTraits* pTraits) override;
  void              subList() const override;
  Gcad::ErrorStatus subGetGripPoints(GcDbGripDataPtrArray& grips,
                                     const double curViewUnitSize,
                                     const int gripSize,
                                     const GcGeVector3d& curViewDir,
                                     const int bitflags) const override;

  Gcad::ErrorStatus subMoveGripPointsAt(const GcDbVoidPtrArray& gripAppData,
                                        const GcGeVector3d& offset,
                                        const int bitflags) override;
  Gcad::ErrorStatus subGetStretchPoints(GcGePoint3dArray&  stretchPoints)const override;
  Gcad::ErrorStatus subMoveStretchPointsAt(const GcDbIntArray& indices,
                                           const GcGeVector3d& offset) override;
  Gcad::ErrorStatus subTransformBy(const GcGeMatrix3d& xform)  override;
  Gcad::ErrorStatus subDeepClone(GcDbObject* pOwnerObject,
                                 GcDbObject*& pClonedObject,
                                 GcDbIdMapping& idMap,
                                 Gsoft::Boolean isPrimary = Gsoft::kTrue) const override;
  Gcad::ErrorStatus subWblockClone(GcRxObject* pOwnerObject,
                                   GcDbObject*& pClonedObject,
                                   GcDbIdMapping& idMap,
                                   Gsoft::Boolean isPrimary = Gsoft::kTrue) const override;
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
  Gcad::ErrorStatus subHighlight(const GcDbFullSubentPath& subId = kNullSubent,
                                 const Gsoft::Boolean highlightAll = Gsoft::kFalse) const override;
  Gcad::ErrorStatus subUnhighlight(const GcDbFullSubentPath& subId = kNullSubent,
                                   const Gsoft::Boolean highlightAll = Gsoft::kFalse) const override;
  Gcad::ErrorStatus subGetGeomExtents(GcDbExtents& extents) const override;

private:
  friend class GcDbImpCamera;

  Gsoft::UInt32     baseSetAttributes(GcGiDrawableTraits* pTraits);
  Gcad::ErrorStatus baseGetStretchPoints(GcGePoint3dArray&  stretchPoints) const;
  Gcad::ErrorStatus baseMoveStretchPointsAt(const GcDbIntArray & indices, const GcGeVector3d& offset);
  Gcad::ErrorStatus baseDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
                                  GcDbIdMapping& idMap, Gsoft::Boolean isPrimary) const;
  Gcad::ErrorStatus baseWblockClone(GcRxObject* pOwnerObject, GcDbObject*& pClonedObject,
                                    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary) const;
  Gcad::ErrorStatus baseHighlight(const GcDbFullSubentPath& subId,
                                  const Gsoft::Boolean highlightAll) const;
  Gcad::ErrorStatus baseUnhighlight(const GcDbFullSubentPath& subId,
                                    const Gsoft::Boolean highlightAll) const;

  GcDbImpCamera* pImp;
};

#pragma pack (pop)