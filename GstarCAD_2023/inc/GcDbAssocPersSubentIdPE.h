/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocSimplePersSubentId.h"
#pragma pack (push, 8)

class GcDbCompoundObjectId;
class GcDbIdMapping;

#ifndef GSOFT_UNREFED_PARAM
#define GSOFT_UNREFED_PARAM(P)  (P)
#endif

enum RigidSetType
{
  kNotRigidSet = 0,
  kScalableRigidSet,
  kNonScalableRigidSet
};

class DBCONSTRAINTS_PORT GcDbAssocPersSubentIdPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPersSubentIdPE);

  virtual GcDbAssocPersSubentId* createNewPersSubent(GcDbEntity*                 pEntity,
    GcDbDatabase*               pDatabase,
    const GcDbCompoundObjectId&,
    const GcDbSubentId&         subentId)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    return new GcDbAssocSimplePersSubentId(subentId);
  }

  virtual Gcad::ErrorStatus releasePersSubent(GcDbEntity*                  pEntity,
    GcDbDatabase*                pDatabase,
    const GcDbAssocPersSubentId* pPerSubentId)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    GSOFT_UNREFED_PARAM(pPerSubentId);
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus transferPersSubentToAnotherEntity(
    GcDbEntity*                  pToEntity,
    GcDbDatabase*                pToDatabase,
    GcDbEntity*                  pFromEntity,
    GcDbDatabase*                pFromDatabase,
    const GcDbAssocPersSubentId* pPersSubentId)
  {
    GSOFT_UNREFED_PARAM(pToEntity);
    GSOFT_UNREFED_PARAM(pToDatabase);
    GSOFT_UNREFED_PARAM(pFromEntity);
    GSOFT_UNREFED_PARAM(pFromDatabase);
    GSOFT_UNREFED_PARAM(pPersSubentId);
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus makePersSubentPurgeable(GcDbEntity*                  pEntity,
    GcDbDatabase*                pDatabase,
    const GcDbAssocPersSubentId* pPerSubentId,
    bool                         yesNo)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    GSOFT_UNREFED_PARAM(yesNo);
    GSOFT_UNREFED_PARAM(pPerSubentId);
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus getTransientSubentIds(const GcDbEntity*            pEntity,
    GcDbDatabase*                pDatabase,
    const GcDbAssocPersSubentId* pPersSubentId,
    GcArray<GcDbSubentId>&       subents) const;

  virtual Gcad::ErrorStatus getAllSubentities(const GcDbEntity*      pEntity,
    GcDb::SubentType       subentType,
    GcArray<GcDbSubentId>& allSubentIds)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(subentType);
    GSOFT_UNREFED_PARAM(allSubentIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getAllSubentities(const GcDbEntity*      pEntity,
    const GcRxClass*       pSubentClass,
    GcArray<GcDbSubentId>& allSubentIds)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pSubentClass);
    GSOFT_UNREFED_PARAM(allSubentIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getEdgeVertexSubentities(const GcDbEntity*      pEntity,
    const GcDbSubentId&    edgeSubentId,
    GcDbSubentId&          startVertexSubentId,
    GcDbSubentId&          endVertexSubentId,
    GcArray<GcDbSubentId>& otherVertexSubentIds)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(edgeSubentId);
    GSOFT_UNREFED_PARAM(startVertexSubentId);
    GSOFT_UNREFED_PARAM(endVertexSubentId);
    GSOFT_UNREFED_PARAM(otherVertexSubentIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getSplineEdgeVertexSubentities(const GcDbEntity*      pEntity,
    const GcDbSubentId&    edgeSubentId,
    GcDbSubentId&          startVertexSubentId,
    GcDbSubentId&          endVertexSubentId,
    GcArray<GcDbSubentId>& controlPointSubentIds,
    GcArray<GcDbSubentId>& fitPointSubentIds)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(edgeSubentId);
    GSOFT_UNREFED_PARAM(startVertexSubentId);
    GSOFT_UNREFED_PARAM(endVertexSubentId);
    GSOFT_UNREFED_PARAM(controlPointSubentIds);
    GSOFT_UNREFED_PARAM(fitPointSubentIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getVertexSubentityGeometry(const GcDbEntity*   pEntity,
    const GcDbSubentId& vertexSubentId,
    GcGePoint3d&        vertexPosition)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(vertexSubentId);
    GSOFT_UNREFED_PARAM(vertexPosition);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getEdgeSubentityGeometry(const GcDbEntity*   pEntity,
    const GcDbSubentId& edgeSubentId,
    GcGeCurve3d*&       pEdgeCurve)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(edgeSubentId);
    GSOFT_UNREFED_PARAM(pEdgeCurve);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getFaceSubentityGeometry(const GcDbEntity*   pEntity,
    const GcDbSubentId& faceSubentId,
    GcGeSurface*&       pFaceSurface)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(faceSubentId);
    GSOFT_UNREFED_PARAM(pFaceSurface);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus setVertexSubentityGeometry(GcDbEntity*         pEntity,
    const GcDbSubentId& vertexSubentId,
    const GcGePoint3d&  newVertexPosition)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(vertexSubentId);
    GSOFT_UNREFED_PARAM(newVertexPosition);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus setEdgeSubentityGeometry(GcDbEntity*         pEntity,
    const GcDbSubentId& edgeSubentId,
    const GcGeCurve3d*  pNewEdgeCurve)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(edgeSubentId);
    GSOFT_UNREFED_PARAM(pNewEdgeCurve);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus setFaceSubentityGeometry(GcDbEntity*         pEntity,
    const GcDbSubentId& faceSubentId,
    const GcGeSurface*  pNewFaceSurface)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(faceSubentId);
    GSOFT_UNREFED_PARAM(pNewFaceSurface);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getSubentityGeometry(const GcDbEntity*   pEntity,
    const GcDbSubentId& subentId,
    GcGeEntity3d*&      pSubentityGeometry);

  virtual Gcad::ErrorStatus setSubentityGeometry(GcDbEntity*         pEntity,
    const GcDbSubentId& subentId,
    const GcGeEntity3d* pNewSubentityGeometry);

  virtual Gcad::ErrorStatus getFaceSilhouetteGeometry(GcDbEntity*                  pEntity,
    GcRxObject*                  pContext,
    const GcDbSubentId&          faceSubentId,
    const GcGeMatrix3d*          pEntityTransform,
    class GcDbGeometryProjector* pGeometryProjector,
    GcArray<int>&                transientSilhIds,
    GcArray<GcGeCurve3d*>&       silhCurves)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pContext);
    GSOFT_UNREFED_PARAM(faceSubentId);
    GSOFT_UNREFED_PARAM(pEntityTransform);
    GSOFT_UNREFED_PARAM(pGeometryProjector);
    GSOFT_UNREFED_PARAM(transientSilhIds);
    silhCurves.removeAll();
    return Gcad::eNotImplemented;
  }

  virtual GcDbAssocPersSubentId* createNewPersFaceSilhouetteId(GcDbEntity*                  pEntity,
    GcDbDatabase*                pDatabase,
    GcRxObject*                  pContext,
    const GcDbCompoundObjectId&,
    const GcDbSubentId&          faceSubentId,
    const GcGeMatrix3d*          pEntityTransform,
    class GcDbGeometryProjector* pGeometryProjector,
    int                          transientSilhId)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    GSOFT_UNREFED_PARAM(pContext);
    GSOFT_UNREFED_PARAM(faceSubentId);
    GSOFT_UNREFED_PARAM(pEntityTransform);
    GSOFT_UNREFED_PARAM(pGeometryProjector);
    GSOFT_UNREFED_PARAM(transientSilhId);
    return NULL;
  }

  virtual Gcad::ErrorStatus getTransientFaceSilhouetteIds(GcDbEntity*                  pEntity,
    GcDbDatabase*                pDatabase,
    GcRxObject*                  pContext,
    const GcDbSubentId&          faceSubentId,
    const GcGeMatrix3d*          pEntityTransform,
    class GcDbGeometryProjector* pGeometryProjector,
    const GcDbAssocPersSubentId* pPersSilhId,
    GcArray<int>&                transientSilhIds)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    GSOFT_UNREFED_PARAM(pContext);
    GSOFT_UNREFED_PARAM(faceSubentId);
    GSOFT_UNREFED_PARAM(pEntityTransform);
    GSOFT_UNREFED_PARAM(pGeometryProjector);
    GSOFT_UNREFED_PARAM(pPersSilhId);
    transientSilhIds.removeAll();
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getSubentGeometryXform(const GcDbEntity*        pEntity,
    const GcDbObjectIdArray& fullSubentPath,
    GcGeMatrix3d&            trans) const
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(fullSubentPath);
    GSOFT_UNREFED_PARAM(trans);
    trans.setToIdentity();
    return Gcad::eOk;
  }

  virtual Gcad::ErrorStatus mirrorPersSubent(const GcDbEntity*      pMirroredEntity,
    GcDbDatabase*          pDatabase,
    GcDbAssocPersSubentId* pPersSubentIdToMirror)
  {
    GSOFT_UNREFED_PARAM(pMirroredEntity);
    GSOFT_UNREFED_PARAM(pDatabase);
    GSOFT_UNREFED_PARAM(pPersSubentIdToMirror);
    return Gcad::eOk;
  }

  virtual int getRigidSetState(const GcDbEntity* pEntity)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    return kNotRigidSet;
  }

  virtual Gcad::ErrorStatus getRigidSetTransform(const GcDbEntity* pEntity,
    GcGeMatrix3d&     trans)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(trans);
    return Gcad::eNotApplicable;
  }

  virtual Gcad::ErrorStatus setRigidSetTransform(GcDbEntity*         pEntity,
    const GcGeMatrix3d& trans)
  {
    GSOFT_UNREFED_PARAM(pEntity);
    GSOFT_UNREFED_PARAM(trans);
    return Gcad::eNotApplicable;
  }
};

class DBCONSTRAINTS_PORT GcDbAssocPersSubentIdPE2 : public GcDbAssocPersSubentIdPE
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocPersSubentIdPE2);

  virtual Gcad::ErrorStatus getUnredirectedObject(const GcDbSubentId&          redirectedSubentId,
    const GcDbCompoundObjectId&  redirectedCompoundObjectId,
    GcDbCompoundObjectId&        originalCompoundObjectId)
  {
    GSOFT_UNREFED_PARAM(redirectedSubentId);
    GSOFT_UNREFED_PARAM(redirectedCompoundObjectId);
    GSOFT_UNREFED_PARAM(originalCompoundObjectId);
    return Gcad::eNotApplicable;
  }
};

#pragma pack (pop)