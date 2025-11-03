/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocGlobal.h" 
#include "gemat3d.h"
#include "GcDbCompoundObjectId.h"
#pragma pack (push, 8)

class GCDB_PORT GcDbGeomRef : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGeomRef);

  ~GcDbGeomRef() {}

  virtual void reset() = 0;
  virtual bool isValid() const = 0;
  virtual bool isEmpty() const = 0;
  virtual GcDbEntity* createEntity() const = 0;
  virtual Gcad::ErrorStatus evaluateAndCacheGeometry() = 0;
};

class GCDB_PORT GcDbSubentRef : public GcDbGeomRef
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSubentRef);

  GcDbSubentRef() {}
  explicit GcDbSubentRef(const GcDbCompoundObjectId&, const GcDbSubentId& = kNullSubentId);

  GcDbSubentRef& operator =(const GcDbSubentRef&);
  bool operator ==(const GcDbSubentRef&) const;

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;
  void reset() override;
  bool isEmpty() const override { return mEntityId.isEmpty(); }
  virtual const GcDbCompoundObjectId& entity() const;
  virtual GcDbSubentId subentId() const;
  GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override { return Gcad::eOk; }

protected:
  void setEntity(const GcDbCompoundObjectId& entityId) { mEntityId = entityId; }
  void setSubent(const GcDbSubentId& subentId) { mSubentId = subentId; }
  void setFromSubentPath(const GcDbFullSubentPath&);

private:
  GcDbCompoundObjectId mEntityId;
  GcDbSubentId         mSubentId;
};

class GCDB_PORT GcDbFaceRef : public GcDbSubentRef
{
#ifdef __GNUC__
private:
  typedef GcDbSubentRef __super;
#endif
public:
  GCRX_DECLARE_MEMBERS(GcDbFaceRef);

  GcDbFaceRef();
  GcDbFaceRef(const GcDbFaceRef&);
  ~GcDbFaceRef();

  explicit GcDbFaceRef(const GcDbCompoundObjectId&, const GcDbSubentId& = kNullSubentId, class BODY* = NULL);

  GcDbFaceRef& operator =(const GcDbFaceRef&);

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  bool isEmpty() const override { return __super::isEmpty() && mpAsmBody == NULL; }
  class BODY* asmBody() const { return mpAsmBody; }
  GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override { return Gcad::eOk; }

private:
  class BODY* mpAsmBody;
};

class GCDB_PORT GcDbEdgeRef : public GcDbSubentRef
{
#ifdef __GNUC__
  typedef GcDbSubentRef __super;
#endif
public:
  GCRX_DECLARE_MEMBERS(GcDbEdgeRef);

  GcDbEdgeRef();
  GcDbEdgeRef(const GcDbEdgeRef&);
  ~GcDbEdgeRef();

  explicit GcDbEdgeRef(const GcDbCompoundObjectId&,
    const GcDbSubentId& edgeSubentId = kNullSubentId,
    const GcDbSubentId& faceSubentId = kNullSubentId,
    const GcGeCurve3d* pCurve = NULL);
  explicit GcDbEdgeRef(const GcDbFullSubentPath&);
  explicit GcDbEdgeRef(const GcDbEntity* pEntity);
  explicit GcDbEdgeRef(const GcGeCurve3d* pGeCurve);

  GcDbEdgeRef& operator =(const GcDbEdgeRef&);
  bool operator ==(const GcDbEdgeRef&) const;

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  bool isEmpty() const override { return __super::isEmpty() && mpCurve == NULL; }
  void setFaceSubentity(const GcDbSubentId& faceSubentId);
  GcDbSubentId faceSubentId() const { return mFaceSubentId; }
  const GcGeCurve3d* curve() const { return mpCurve; }
  virtual Gcad::ErrorStatus evaluateCurve(GcGeCurve3d*&) const;
  GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
  void setCurve(const GcGeCurve3d* pCurve);
  GcDbSubentId mFaceSubentId;
  GcGeCurve3d* mpCurve;
};

class GCDB_PORT GcDbVertexRef : public GcDbSubentRef
{
#ifdef __GNUC__
private:
  typedef GcDbSubentRef __super;
#endif
public:
  GCRX_DECLARE_MEMBERS(GcDbVertexRef);

  enum ImpliedType
  {
    kExplicitVertex,
    kUnknownType,
    kEdgeStart,
    kEdgeEnd,
    kEdgeMid,
    kEdgeCenter,
    kEdgeSplineControlPoint,
    kEdgeSplineFitPoint,
  };

  GcDbVertexRef();
  GcDbVertexRef(const GcDbVertexRef&);
  ~GcDbVertexRef();

  explicit GcDbVertexRef(const GcDbCompoundObjectId&, const GcDbSubentId& = kNullSubentId, const GcGePoint3d& = GcGePoint3d::kOrigin);
  explicit GcDbVertexRef(const GcDbFullSubentPath&);
  explicit GcDbVertexRef(const GcDbEntity*);
  explicit GcDbVertexRef(const GcGePoint3d&);
  explicit GcDbVertexRef(ImpliedType, const GcDbEdgeRef& edgeRef, int controlOrFitPointIndex = 0, const GcGePoint3d& = GcGePoint3d::kOrigin);

  GcDbVertexRef& operator =(const GcDbVertexRef&);

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  const GcDbCompoundObjectId& entity() const override;
  GcDbSubentId subentId() const override;
  ImpliedType        impliedType()   const { return mImpliedType; }
  const GcDbGeomRef* referencedRef() const { return mpReferencedRef; }
  int                index()         const { return mIndex; }
  GcGePoint3d point() const;
  virtual Gcad::ErrorStatus evaluatePoint(GcGePoint3d&) const;
  class GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
  void setReferencedRef(const GcDbGeomRef*);

  ImpliedType        mImpliedType;
  const GcDbGeomRef* mpReferencedRef;
  int                mIndex;
  GcGePoint3d  mPoint;
};

class GCDB_PORT GcDbPathRef : public GcDbGeomRef
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPathRef);

  GcDbPathRef();
  GcDbPathRef(const GcDbPathRef&);
  explicit GcDbPathRef(const GcArray<GcDbEdgeRef>&);
  GcDbPathRef(const GcDbFullSubentPathArray& edgeSubentPathArr,
    const GcDbFullSubentPathArray& faceSubentPathArr);
  ~GcDbPathRef();

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  bool isEmpty() const override;
  void setEdgeRefs(const GcArray<GcDbEdgeRef>& edges);
  Gcad::ErrorStatus getEntityArray(GcArray<GcDbEntity*>& entities, bool concatenate) const;
  const GcArray<GcDbEdgeRef>& edgeRefs() const { return mEdgeRefs; }
  bool isEqualTo(const GcGeCurve3d*);
  bool isReferencePath();
  GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
  GcArray<GcDbEdgeRef> mEdgeRefs;
};

class GCDB_PORT GcDbVectorRef : public GcDbGeomRef
{
#ifdef __GNUC__
private:
  typedef GcDbGeomRef __super;
#endif
public:
  GCRX_DECLARE_MEMBERS(GcDbVectorRef);

  explicit GcDbVectorRef();
  explicit GcDbVectorRef(const GcDbVectorRef&);
  explicit GcDbVectorRef(const GcGeVector3d&);
  ~GcDbVectorRef();

  GcDbVectorRef& operator = (const GcDbVectorRef&);

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  bool isEmpty() const override;
  const GcGeVector3d vector() const { return mVector; }
  void set(const GcGeVector3d&);
  GcDbEntity* createEntity() const override;
  Gcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
  GcGeVector3d mVector;
};

class GCDB_PORT GcDbCoordSystemRef : public GcDbGeomRef
{
#ifdef __GNUC__
  typedef GcDbGeomRef __super;
#endif
public:
  GCRX_DECLARE_MEMBERS(GcDbCoordSystemRef);

  explicit GcDbCoordSystemRef();
  explicit GcDbCoordSystemRef(const GcDbCoordSystemRef&);
  explicit GcDbCoordSystemRef(const GcGeMatrix3d&);
  explicit GcDbCoordSystemRef(const GcDbCompoundObjectId&, const GcGeMatrix3d&);
  explicit GcDbCoordSystemRef(const GcArray<GcDbSubentRef*>&);
  ~GcDbCoordSystemRef();

  GcDbCoordSystemRef& operator = (const GcDbCoordSystemRef&);

  Gcad::ErrorStatus copyFrom(const GcRxObject*) override;

  void reset() override;
  bool isValid() const override;
  bool isEmpty() const override;
  const GcGeMatrix3d&            coordSystem() const { return mCoordSystem; }
  const GcDbCompoundObjectId&    entityId() const { return mEntityId; }
  const GcArray<GcDbSubentRef*>& subentRefs() const { return mSubentRefs; }

  void set(const GcGeMatrix3d&);
  void set(const GcDbCompoundObjectId&);
  void set(const GcArray<GcDbSubentRef*>&);

  GcDbEntity* createEntity() const override { return NULL; }
  Gcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
  GcGeMatrix3d            mCoordSystem;
  GcDbCompoundObjectId    mEntityId;
  GcArray<GcDbSubentRef*> mSubentRefs;
};

#pragma pack (pop)