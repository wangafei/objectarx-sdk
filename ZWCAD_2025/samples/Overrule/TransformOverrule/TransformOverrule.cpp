#include "stdafx.h"
#include "TransformOverrule.h"
#include "dbents.h"
#include "dbsol3d.h"

Acad::ErrorStatus CTransformOverrule::transformBy(AcDbEntity * pSubject, const AcGeMatrix3d & xform)
{
	acutPrintf(_T("\nCTransformOverrule::transformBy is called!"));
	if (isApplicable(pSubject))
	{
		AcGeMatrix3d new_xform;
		AcGeVector3d vec(0, 0, 0);
		new_xform.setToTranslation(vec);
		return AcDbTransformOverrule::transformBy(pSubject, new_xform);
	}
	return AcDbTransformOverrule::transformBy(pSubject, xform);
}

Acad::ErrorStatus CTransformOverrule::getTransformedCopy(const AcDbEntity * pSubject, const AcGeMatrix3d & xform, AcDbEntity *& pEnt)
{
	if (isApplicable(pSubject))
	{
		AcGeMatrix3d new_xform;
		AcGeVector3d vec(100, 100, 0);
		new_xform.setToTranslation(vec);
		return AcDbTransformOverrule::getTransformedCopy(pSubject, new_xform, pEnt);
	}
	return AcDbTransformOverrule::getTransformedCopy(pSubject, xform, pEnt);
}

Acad::ErrorStatus CTransformOverrule::explode(const AcDbEntity * pSubject, AcDbVoidPtrArray & entitySet)
{
	acutPrintf(_T("\nCTransformOverrule::explode is called!"));
	if (isApplicable(pSubject))
	{
		// When the EXPLODE command is applied to a polyline, a cylinder is created instead
		const AcDbPolyline* pLine = static_cast<const AcDbPolyline*>(pSubject);
		AcDb3dSolid* solid = new AcDb3dSolid();
		AcGePoint3d startpt, endpt;
		pLine->getEndPoint(endpt);
		pLine->getStartPoint(startpt);
		double len = startpt.distanceTo(endpt);
		solid->createFrustum(len, 10, 10, 10);

		AcGeMatrix3d xform;
		AcGeVector3d vec(1, -(endpt.x - startpt.x) / (endpt.y - startpt.y), 0);
		xform.setToRotation(3.14 / 2, vec);
		solid->transformBy(xform);

		vec.set((endpt.x + startpt.x) / 2, (endpt.y + startpt.y) / 2, 0);
		xform.setToTranslation(vec);
		solid->transformBy(xform);

		entitySet.append(solid);
		return Acad::eOk;
	}
	return AcDbTransformOverrule::explode(pSubject, entitySet);
}

Adesk::Boolean CTransformOverrule::cloneMeForDragging(AcDbEntity * pSubject)
{
	if (isApplicable(pSubject))
	{
		const AcDbPolyline* pLine = static_cast<const AcDbPolyline*>(pSubject);
		AcGePoint3d startpt, endpt;
		pLine->getEndPoint(endpt);
		pLine->getStartPoint(startpt);
		if (startpt.distanceTo(endpt) < 1000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return AcDbTransformOverrule::cloneMeForDragging(pSubject);
}

bool CTransformOverrule::hideMeForDragging(const AcDbEntity * pSubject)
{
	if (isApplicable(pSubject))
	{
		const AcDbPolyline* pLine = static_cast<const AcDbPolyline*>(pSubject);
		AcGePoint3d startpt, endpt;
		pLine->getEndPoint(endpt);
		pLine->getStartPoint(startpt);
		if (startpt.distanceTo(endpt) < 1000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return AcDbTransformOverrule::hideMeForDragging(pSubject);
}

bool CTransformOverrule::isApplicable(const AcRxObject * pOverruledSubject) const
{
	if (!pOverruledSubject->isKindOf(AcDbPolyline::desc()))
	{
		return false;
	}
	if (((AcDbPolyline*)pOverruledSubject)->xData() != NULL)
	{
		return false;
	}
	return true;
}