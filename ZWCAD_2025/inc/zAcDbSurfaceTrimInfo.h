#pragma once
#include "zAcDbAssocEdgeActionParam.h"
#include "zAcDbCompoundObjectId.h"
#pragma pack (push, 8)

class ENTITY;

class ZCDB_PORT ZcDbSurfaceTrimInfo
{
public:
    enum TrimRelation {

        outside_tool,

        inside_tool,
    };

    ZcDbSurfaceTrimInfo();

    virtual ~ZcDbSurfaceTrimInfo();

    void setTrimInfo( const ZcDbCompoundObjectId& curveId, const ZcGeVector3d & projVector, TrimRelation relation );

    void setTrimInfo( ENTITY *pWireBody, const ZcGeVector3d& projVector, TrimRelation relation);

    void setTrimInfo( const ZcDbCompoundObjectId &surfaceId, TrimRelation relation, const ZcDbSubentId& subentId);

    void setTrimInfo( ENTITY *pZsmBody, TrimRelation relation, const ZcDbSubentId& subentId );

    bool isCurve() const;

    ENTITY *toolBody() const;

    void setToolBody(ENTITY *pEntity);

    ZcDbCompoundObjectId toolBodyId() const;

    void setToolBodyId( const ZcDbCompoundObjectId &toolId );

    TrimRelation relation() const;

    void setRelation( TrimRelation relation );

    ZcGeVector3d projVector() const;

    void setProjVector(const ZcGeVector3d& projVector);

    ZcDbSubentId faceSubentId() const;
private:
    bool mbCurve;

    ZcGeVector3d mProjVector;

    ZcDbCompoundObjectId mToolBodyId;

    ZcDbSubentId mToolFaceSubentId;

    mutable ENTITY *mToolBody;

    TrimRelation mRelation;
};

#pragma pack (pop)
