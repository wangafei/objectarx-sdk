/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocEdgeActionParam.h"
#include "GcDbCompoundObjectId.h"
#pragma pack (push, 8)

class ENTITY;

class  GcDbSurfaceTrimInfo
{
public:
  enum TrimRelation {
    outside_tool,
    inside_tool,
  };

  DBCONSTRAINTS_PORT GcDbSurfaceTrimInfo();
  DBCONSTRAINTS_PORT virtual ~GcDbSurfaceTrimInfo();

  DBCONSTRAINTS_PORT void setTrimInfo(const GcDbCompoundObjectId& curveId, const GcGeVector3d & projVector, TrimRelation relation);
  DBCONSTRAINTS_PORT void setTrimInfo(ENTITY *pWireBody, const GcGeVector3d& projVector, TrimRelation relation);
  DBCONSTRAINTS_PORT void setTrimInfo(const GcDbCompoundObjectId &surfaceId, TrimRelation relation, const GcDbSubentId& subentId);
  DBCONSTRAINTS_PORT void setTrimInfo(ENTITY *pAsmBody, TrimRelation relation, const GcDbSubentId& subentId);

  DBCONSTRAINTS_PORT bool isCurve() const;

  DBCONSTRAINTS_PORT ENTITY *toolBody() const;
  DBCONSTRAINTS_PORT void setToolBody(ENTITY *pEntity);

  DBCONSTRAINTS_PORT GcDbCompoundObjectId toolBodyId() const;
  DBCONSTRAINTS_PORT void setToolBodyId(const GcDbCompoundObjectId &toolId);

  DBCONSTRAINTS_PORT TrimRelation relation() const;
  DBCONSTRAINTS_PORT void setRelation(TrimRelation relation);

  DBCONSTRAINTS_PORT GcGeVector3d projVector() const;
  DBCONSTRAINTS_PORT void setProjVector(const GcGeVector3d& projVector);

  DBCONSTRAINTS_PORT GcDbSubentId faceSubentId() const;
private:
  bool mbCurve;
  GcGeVector3d mProjVector;
  GcDbCompoundObjectId mToolBodyId;
  GcDbSubentId mToolFaceSubentId;
  mutable ENTITY *mToolBody;
  TrimRelation mRelation;
};

#pragma pack (pop)