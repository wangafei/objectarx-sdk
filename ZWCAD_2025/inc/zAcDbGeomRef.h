#pragma once
#include "zAcDbAssocGlobal.h"
#include "zgemat3d.h"
#include "zAcDbCompoundObjectId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbGeomRef : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbGeomRef);

    virtual ~ZcDbGeomRef() {}

    virtual void reset() = 0;

    virtual bool isValid() const = 0;

    virtual bool isEmpty() const = 0;

    virtual ZcDbEntity* createEntity() const = 0;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() = 0;
};

class ZCDBCORE2D_PORT ZcDbSubentRef : public ZcDbGeomRef
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSubentRef);

    ZcDbSubentRef() {}

    explicit ZcDbSubentRef(const ZcDbCompoundObjectId&, const ZcDbSubentId& = kNullSubentId);

    ZcDbSubentRef& operator =(const ZcDbSubentRef&);
    bool operator ==(const ZcDbSubentRef&) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isEmpty() const override { return mEntityId.isEmpty(); }

    virtual const ZcDbCompoundObjectId& entity() const;

    virtual ZcDbSubentId subentId() const;

    virtual ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override { return Zcad::eOk; }

protected:

    void setEntity(const ZcDbCompoundObjectId& entityId) { mEntityId = entityId; }

    void setSubent(const ZcDbSubentId& subentId) { mSubentId = subentId; }

    void setFromSubentPath(const ZcDbFullSubentPath&);

private:
    ZcDbCompoundObjectId mEntityId;
    ZcDbSubentId         mSubentId;
};

class ZCDBCORE2D_PORT ZcDbFaceRef : public ZcDbSubentRef
{
#ifdef __GNUC__
private:
    typedef ZcDbSubentRef __super;
#endif
public:
    ZCRX_DECLARE_MEMBERS(ZcDbFaceRef);

    ZcDbFaceRef();
    ZcDbFaceRef(const ZcDbFaceRef&);
    virtual ~ZcDbFaceRef();

    explicit ZcDbFaceRef(const ZcDbCompoundObjectId&, const ZcDbSubentId& = kNullSubentId, class BODY* = NULL);

    ZcDbFaceRef& operator =(const ZcDbFaceRef&);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override { return __super::isEmpty() && mpZsmBody == NULL; }

    class BODY* zsmBody() const { return mpZsmBody; }

    virtual ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override { return Zcad::eOk; }

private:
    class BODY* mpZsmBody;
};

class ZCDBCORE2D_PORT ZcDbEdgeRef : public ZcDbSubentRef
{
#ifdef __GNUC__
    typedef ZcDbSubentRef __super;
#endif
public:
    ZCRX_DECLARE_MEMBERS(ZcDbEdgeRef);

    ZcDbEdgeRef();
    ZcDbEdgeRef(const ZcDbEdgeRef&);
    virtual ~ZcDbEdgeRef();

    explicit ZcDbEdgeRef(const ZcDbCompoundObjectId&,
                         const ZcDbSubentId& edgeSubentId = kNullSubentId,
                         const ZcDbSubentId& faceSubentId = kNullSubentId,
                         const ZcGeCurve3d* pCurve        = NULL);

    explicit ZcDbEdgeRef(const ZcDbFullSubentPath&);

    explicit ZcDbEdgeRef(const ZcDbEntity* pEntity);

    explicit ZcDbEdgeRef(const ZcGeCurve3d* pGeCurve);

    ZcDbEdgeRef& operator =(const ZcDbEdgeRef&);
    bool operator ==(const ZcDbEdgeRef&) const;

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override { return __super::isEmpty() && mpCurve == NULL; }

    void setFaceSubentity(const ZcDbSubentId& faceSubentId);

    ZcDbSubentId faceSubentId() const { return mFaceSubentId; }

    const ZcGeCurve3d* curve() const { return mpCurve; }

    virtual Zcad::ErrorStatus evaluateCurve(ZcGeCurve3d*&) const;

    virtual ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override;

private:

    void setCurve(const ZcGeCurve3d* pCurve);

    ZcDbSubentId mFaceSubentId;
    ZcGeCurve3d* mpCurve;
};

class ZCDBCORE2D_PORT ZcDbVertexRef : public ZcDbSubentRef
{
#ifdef __GNUC__
private:
    typedef ZcDbSubentRef __super;
#endif
public:
    ZCRX_DECLARE_MEMBERS(ZcDbVertexRef);

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

    ZcDbVertexRef();
    ZcDbVertexRef(const ZcDbVertexRef&);
    virtual ~ZcDbVertexRef();

    explicit ZcDbVertexRef(const ZcDbCompoundObjectId&, const ZcDbSubentId& = kNullSubentId, const ZcGePoint3d& = ZcGePoint3d::kOrigin);

    explicit ZcDbVertexRef(const ZcDbFullSubentPath&);

    explicit ZcDbVertexRef(const ZcDbEntity*);

    explicit ZcDbVertexRef(const ZcGePoint3d&);

    explicit ZcDbVertexRef(ImpliedType, const ZcDbEdgeRef& edgeRef, int controlOrFitPointIndex = 0, const ZcGePoint3d& = ZcGePoint3d::kOrigin);

    ZcDbVertexRef& operator =(const ZcDbVertexRef&);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;

    virtual const ZcDbCompoundObjectId& entity() const override;

    virtual ZcDbSubentId subentId() const override;

    ImpliedType        impliedType()   const { return mImpliedType;    }
    const ZcDbGeomRef* referencedRef() const { return mpReferencedRef; }
    int                index()         const { return mIndex;          }

    ZcGePoint3d point() const;

    virtual Zcad::ErrorStatus evaluatePoint(ZcGePoint3d&) const;

    class ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override;

private:

    void setReferencedRef(const ZcDbGeomRef*);

    ImpliedType        mImpliedType;
    const ZcDbGeomRef* mpReferencedRef;
    int                mIndex;

    ZcGePoint3d  mPoint;
};

class ZCDBCORE2D_PORT ZcDbPathRef : public ZcDbGeomRef
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbPathRef);

    ZcDbPathRef();
    ZcDbPathRef(const ZcDbPathRef&);

    explicit ZcDbPathRef(const ZcArray<ZcDbEdgeRef>&);

   ZcDbPathRef(const ZcDbFullSubentPathArray& edgeSubentPathArr,
               const ZcDbFullSubentPathArray& faceSubentPathArr);

    virtual ~ZcDbPathRef();

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override;

    void setEdgeRefs(const ZcArray<ZcDbEdgeRef>& edges);

    Zcad::ErrorStatus getEntityArray(ZcArray<ZcDbEntity*>& entities, bool concatenate) const;

    const ZcArray<ZcDbEdgeRef>& edgeRefs() const { return mEdgeRefs; }

    bool isEqualTo(const ZcGeCurve3d*);

    bool isReferencePath();

    virtual ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override;

private:
    ZcArray<ZcDbEdgeRef> mEdgeRefs;
};

class ZCDBCORE2D_PORT ZcDbVectorRef : public ZcDbGeomRef
{
#ifdef __GNUC__
private:
    typedef ZcDbGeomRef __super;
#endif
public:
    ZCRX_DECLARE_MEMBERS(ZcDbVectorRef);

    explicit ZcDbVectorRef();

    explicit ZcDbVectorRef(const ZcDbVectorRef&);

    explicit ZcDbVectorRef(const ZcGeVector3d&);

    virtual ~ZcDbVectorRef();

    ZcDbVectorRef& operator = (const ZcDbVectorRef&);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override;

    const ZcGeVector3d vector() const { return mVector; }

    void set(const ZcGeVector3d&);

    virtual ZcDbEntity* createEntity() const override;

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override;

private:

    ZcGeVector3d mVector;
};

class ZCDBCORE2D_PORT ZcDbCoordSystemRef : public ZcDbGeomRef
{
#ifdef __GNUC__
    typedef ZcDbGeomRef __super;
#endif
public:
    ZCRX_DECLARE_MEMBERS(ZcDbCoordSystemRef);

    explicit ZcDbCoordSystemRef();

    explicit ZcDbCoordSystemRef(const ZcDbCoordSystemRef&);

    explicit ZcDbCoordSystemRef(const ZcGeMatrix3d&);

    explicit ZcDbCoordSystemRef(const ZcDbCompoundObjectId&, const ZcGeMatrix3d&);

    explicit ZcDbCoordSystemRef(const ZcArray<ZcDbSubentRef*>&);

    virtual ~ZcDbCoordSystemRef();

    ZcDbCoordSystemRef& operator = (const ZcDbCoordSystemRef&);

    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject*) override;

    virtual void reset() override;
    virtual bool isValid() const override;
    virtual bool isEmpty() const override;

    const ZcGeMatrix3d&            coordSystem() const { return mCoordSystem; }
    const ZcDbCompoundObjectId&    entityId   () const { return mEntityId;    }
    const ZcArray<ZcDbSubentRef*>& subentRefs () const { return mSubentRefs;  }

    void set(const ZcGeMatrix3d&);
    void set(const ZcDbCompoundObjectId&);
    void set(const ZcArray<ZcDbSubentRef*>&);

    virtual ZcDbEntity* createEntity() const override { return NULL; }

    virtual Zcad::ErrorStatus evaluateAndCacheGeometry() override;

private:

    ZcGeMatrix3d            mCoordSystem;
    ZcDbCompoundObjectId    mEntityId;
    ZcArray<ZcDbSubentRef*> mSubentRefs;
};

#pragma pack (pop)
