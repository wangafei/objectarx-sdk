
#pragma once
#include "zAcDbAssocSimplePersSubentId.h"
#pragma pack (push, 8)

class ZcDbCompoundObjectId;
class ZcDbIdMapping;

#ifndef ZSOFT_UNREFED_PARAM
#define ZSOFT_UNREFED_PARAM(P)  (P)
#endif

enum RigidSetType
{

  kNotRigidSet = 0,

  kScalableRigidSet,

  kNonScalableRigidSet
};

class ZCDBCORE2D_PORT ZcDbAssocPersSubentIdPE : public ZcRxObject
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocPersSubentIdPE);

    virtual ZcDbAssocPersSubentId* createNewPersSubent(ZcDbEntity*                 pEntity,
                                                       ZcDbDatabase*               pDatabase,
                                                       const ZcDbCompoundObjectId& ,
                                                       const ZcDbSubentId&         subentId)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);

        return new ZcDbAssocSimplePersSubentId(subentId);
    }

    virtual Zcad::ErrorStatus releasePersSubent(ZcDbEntity*                  pEntity,
                                                ZcDbDatabase*                pDatabase,
                                                const ZcDbAssocPersSubentId* pPerSubentId)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        ZSOFT_UNREFED_PARAM(pPerSubentId);
        return Zcad::eOk;
    }

    virtual Zcad::ErrorStatus transferPersSubentToAnotherEntity(
        ZcDbEntity*                  pToEntity,
        ZcDbDatabase*                pToDatabase,
        ZcDbEntity*                  pFromEntity,
        ZcDbDatabase*                pFromDatabase,
        const ZcDbAssocPersSubentId* pPersSubentId)
    {
        ZSOFT_UNREFED_PARAM(pToEntity);
        ZSOFT_UNREFED_PARAM(pToDatabase);
        ZSOFT_UNREFED_PARAM(pFromEntity);
        ZSOFT_UNREFED_PARAM(pFromDatabase);
        ZSOFT_UNREFED_PARAM(pPersSubentId);
        return Zcad::eOk;
    }

    virtual Zcad::ErrorStatus makePersSubentPurgeable(ZcDbEntity*                  pEntity,
                                                      ZcDbDatabase*                pDatabase,
                                                      const ZcDbAssocPersSubentId* pPerSubentId,
                                                      bool                         yesNo)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        ZSOFT_UNREFED_PARAM(yesNo);
        ZSOFT_UNREFED_PARAM(pPerSubentId);
        return Zcad::eOk;
    }

    virtual Zcad::ErrorStatus getTransientSubentIds(const ZcDbEntity*            pEntity,
                                                    ZcDbDatabase*                pDatabase,
                                                    const ZcDbAssocPersSubentId* pPersSubentId,
                                                    ZcArray<ZcDbSubentId>&       subents) const;

    virtual Zcad::ErrorStatus getAllSubentities(const ZcDbEntity*      pEntity,
                                                ZcDb::SubentType       subentType,
                                                ZcArray<ZcDbSubentId>& allSubentIds)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(subentType);
        ZSOFT_UNREFED_PARAM(allSubentIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getAllSubentities(const ZcDbEntity*      pEntity,
                                                const ZcRxClass*       pSubentClass,
                                                ZcArray<ZcDbSubentId>& allSubentIds)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pSubentClass);
        ZSOFT_UNREFED_PARAM(allSubentIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getEdgeVertexSubentities(const ZcDbEntity*      pEntity,
                                                       const ZcDbSubentId&    edgeSubentId,
                                                       ZcDbSubentId&          startVertexSubentId,
                                                       ZcDbSubentId&          endVertexSubentId,
                                                       ZcArray<ZcDbSubentId>& otherVertexSubentIds)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(edgeSubentId);
        ZSOFT_UNREFED_PARAM(startVertexSubentId);
        ZSOFT_UNREFED_PARAM(endVertexSubentId);
        ZSOFT_UNREFED_PARAM(otherVertexSubentIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getSplineEdgeVertexSubentities(const ZcDbEntity*      pEntity,
                                                             const ZcDbSubentId&    edgeSubentId,
                                                             ZcDbSubentId&          startVertexSubentId,
                                                             ZcDbSubentId&          endVertexSubentId,
                                                             ZcArray<ZcDbSubentId>& controlPointSubentIds,
                                                             ZcArray<ZcDbSubentId>& fitPointSubentIds)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(edgeSubentId);
        ZSOFT_UNREFED_PARAM(startVertexSubentId);
        ZSOFT_UNREFED_PARAM(endVertexSubentId);
        ZSOFT_UNREFED_PARAM(controlPointSubentIds);
        ZSOFT_UNREFED_PARAM(fitPointSubentIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getVertexSubentityGeometry(const ZcDbEntity*   pEntity,
                                                         const ZcDbSubentId& vertexSubentId,
                                                         ZcGePoint3d&        vertexPosition)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(vertexSubentId);
        ZSOFT_UNREFED_PARAM(vertexPosition);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getEdgeSubentityGeometry(const ZcDbEntity*   pEntity,
                                                       const ZcDbSubentId& edgeSubentId,
                                                       ZcGeCurve3d*&       pEdgeCurve)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(edgeSubentId);
        ZSOFT_UNREFED_PARAM(pEdgeCurve);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getFaceSubentityGeometry(const ZcDbEntity*   pEntity,
                                                       const ZcDbSubentId& faceSubentId,
                                                       ZcGeSurface*&       pFaceSurface)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(faceSubentId);
        ZSOFT_UNREFED_PARAM(pFaceSurface);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus setVertexSubentityGeometry(ZcDbEntity*         pEntity,
                                                         const ZcDbSubentId& vertexSubentId,
                                                         const ZcGePoint3d&  newVertexPosition)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(vertexSubentId);
        ZSOFT_UNREFED_PARAM(newVertexPosition);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus setEdgeSubentityGeometry(ZcDbEntity*         pEntity,
                                                       const ZcDbSubentId& edgeSubentId,
                                                       const ZcGeCurve3d*  pNewEdgeCurve)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(edgeSubentId);
        ZSOFT_UNREFED_PARAM(pNewEdgeCurve);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus setFaceSubentityGeometry(ZcDbEntity*         pEntity,
                                                       const ZcDbSubentId& faceSubentId,
                                                       const ZcGeSurface*  pNewFaceSurface)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(faceSubentId);
        ZSOFT_UNREFED_PARAM(pNewFaceSurface);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getSubentityGeometry(const ZcDbEntity*   pEntity,
                                                   const ZcDbSubentId& subentId,
                                                   ZcGeEntity3d*&      pSubentityGeometry);

    virtual Zcad::ErrorStatus setSubentityGeometry(ZcDbEntity*         pEntity,
                                                   const ZcDbSubentId& subentId,
                                                   const ZcGeEntity3d* pNewSubentityGeometry);

    virtual Zcad::ErrorStatus getFaceSilhouetteGeometry(ZcDbEntity*                  pEntity,
                                                        ZcRxObject*                  pContext,
                                                        const ZcDbSubentId&          faceSubentId,
                                                        const ZcGeMatrix3d*          pEntityTransform,
                                                        class ZcDbGeometryProjector* pGeometryProjector,
                                                        ZcArray<int>&                transientSilhIds,
                                                        ZcArray<ZcGeCurve3d*>&       silhCurves)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pContext);
        ZSOFT_UNREFED_PARAM(faceSubentId);
        ZSOFT_UNREFED_PARAM(pEntityTransform);
        ZSOFT_UNREFED_PARAM(pGeometryProjector);
        ZSOFT_UNREFED_PARAM(transientSilhIds);

        silhCurves.removeAll();
        return Zcad::eNotImplemented;
    }

    virtual ZcDbAssocPersSubentId* createNewPersFaceSilhouetteId(ZcDbEntity*                  pEntity,
                                                                 ZcDbDatabase*                pDatabase,
                                                                 ZcRxObject*                  pContext,
                                                                 const ZcDbCompoundObjectId&  ,
                                                                 const ZcDbSubentId&          faceSubentId,
                                                                 const ZcGeMatrix3d*          pEntityTransform,
                                                                 class ZcDbGeometryProjector* pGeometryProjector,
                                                                 int                          transientSilhId)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        ZSOFT_UNREFED_PARAM(pContext);
        ZSOFT_UNREFED_PARAM(faceSubentId);
        ZSOFT_UNREFED_PARAM(pEntityTransform);
        ZSOFT_UNREFED_PARAM(pGeometryProjector);
        ZSOFT_UNREFED_PARAM(transientSilhId);
        return NULL;
    }

    virtual Zcad::ErrorStatus getTransientFaceSilhouetteIds(ZcDbEntity*                  pEntity,
                                                            ZcDbDatabase*                pDatabase,
                                                            ZcRxObject*                  pContext,
                                                            const ZcDbSubentId&          faceSubentId,
                                                            const ZcGeMatrix3d*          pEntityTransform,
                                                            class ZcDbGeometryProjector* pGeometryProjector,
                                                            const ZcDbAssocPersSubentId* pPersSilhId,
                                                            ZcArray<int>&                transientSilhIds)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        ZSOFT_UNREFED_PARAM(pContext);
        ZSOFT_UNREFED_PARAM(faceSubentId);
        ZSOFT_UNREFED_PARAM(pEntityTransform);
        ZSOFT_UNREFED_PARAM(pGeometryProjector);
        ZSOFT_UNREFED_PARAM(pPersSilhId);

        transientSilhIds.removeAll();
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getSubentGeometryXform(const ZcDbEntity*        pEntity,
                                                     const ZcDbObjectIdArray& fullSubentPath,
                                                     ZcGeMatrix3d&            trans) const
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(fullSubentPath);
        ZSOFT_UNREFED_PARAM(trans);

        trans.setToIdentity();
        return Zcad::eOk;
    }

    virtual Zcad::ErrorStatus mirrorPersSubent(const ZcDbEntity*      pMirroredEntity,
                                               ZcDbDatabase*          pDatabase,
                                               ZcDbAssocPersSubentId* pPersSubentIdToMirror)
    {
        ZSOFT_UNREFED_PARAM(pMirroredEntity);
        ZSOFT_UNREFED_PARAM(pDatabase);
        ZSOFT_UNREFED_PARAM(pPersSubentIdToMirror);
        return Zcad::eOk;
    }

    virtual int getRigidSetState(const ZcDbEntity* pEntity)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        return kNotRigidSet;
    }

    virtual Zcad::ErrorStatus getRigidSetTransform(const ZcDbEntity* pEntity,
                                                   ZcGeMatrix3d&     trans)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(trans);
        return Zcad::eNotApplicable;
    }

    virtual Zcad::ErrorStatus setRigidSetTransform(ZcDbEntity*         pEntity,
                                                   const ZcGeMatrix3d& trans)
    {
        ZSOFT_UNREFED_PARAM(pEntity);
        ZSOFT_UNREFED_PARAM(trans);
        return Zcad::eNotApplicable;
    }
};

class ZCDBCORE2D_PORT ZcDbAssocPersSubentIdPE2 : public ZcDbAssocPersSubentIdPE
{
public:
	ZCRX_DECLARE_MEMBERS(ZcDbAssocPersSubentIdPE2);

    virtual Zcad::ErrorStatus getUnredirectedObject(const ZcDbSubentId&          redirectedSubentId,
                                                    const ZcDbCompoundObjectId&  redirectedCompoundObjectId,
                                                    ZcDbCompoundObjectId&        originalCompoundObjectId)
    {
        ZSOFT_UNREFED_PARAM(redirectedSubentId);
        ZSOFT_UNREFED_PARAM(redirectedCompoundObjectId);
        ZSOFT_UNREFED_PARAM(originalCompoundObjectId);
        return Zcad::eNotApplicable;
    }
};

#pragma pack (pop)

