#include "stdafx.h"
#include "ObjectOverrule.h"
#include "dbents.h"
#include "dbidmap.h"

CPolyLineOverrule::CPolyLineOverrule(bool canCopy)
{
	m_bCanCopy = canCopy;
}

Acad::ErrorStatus CPolyLineOverrule::open(AcDbObject * pSubject, AcDb::OpenMode mode)
{
	Acad::ErrorStatus es = Acad::eOk;

	if (isApplicable(pSubject))
	{
		AcDbPolyline* pLine = AcDbPolyline::cast(pSubject);
		if (pLine->isWriteEnabled())
		{
			pLine->setLineWeight(AcDb::kLnWt020);
		}
	}
	else
	{
		es = AcDbObjectOverrule::open(pSubject, mode);
	}

	return es;
}

Acad::ErrorStatus CPolyLineOverrule::close(AcDbObject * pSubject)
{
	return AcDbObjectOverrule::close(pSubject);
}

Acad::ErrorStatus CPolyLineOverrule::cancel(AcDbObject * pSubject)
{
	Acad::ErrorStatus es = Acad::eOk;

	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\n cancel polyline operation"));
	}
	else
	{
		es = AcDbObjectOverrule::cancel(pSubject);
	}

	return es;
}

Acad::ErrorStatus CPolyLineOverrule::erase(AcDbObject * pSubject, Adesk::Boolean erasing)
{
	return AcDbObjectOverrule::erase(pSubject, erasing);
}

Acad::ErrorStatus CPolyLineOverrule::deepClone(const AcDbObject * pSubject, AcDbObject * pOwnerObject, AcDbObject *& pClonedObject, AcDbIdMapping & idMap, Adesk::Boolean isPrimary)
{
	Acad::ErrorStatus es = Acad::eOk;
	if (isApplicable(pSubject))
	{
		es = AcDbObjectOverrule::deepClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
		if (pClonedObject && pClonedObject->isKindOf(AcDbPolyline::desc()))
		{
			AcDbPolyline* pLine = AcDbPolyline::cast(pClonedObject);
			pLine->setColorIndex(1);
		}
		return es;
	}
	return AcDbObjectOverrule::deepClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
}

Acad::ErrorStatus CPolyLineOverrule::wblockClone(const AcDbObject * pSubject, AcRxObject * pOwnerObject, AcDbObject *& pClonedObject, AcDbIdMapping & idMap, Adesk::Boolean isPrimary)
{
	if (!m_bCanCopy && isApplicable(pSubject))
	{
		acutPrintf(_T("\nwblockclone polyline operation!(forbid copy)"));
		return Acad::eOk;
	}
	return AcDbObjectOverrule::wblockClone(pSubject, pOwnerObject, pClonedObject, idMap, isPrimary);
}

bool CPolyLineOverrule::isApplicable(const ZcRxObject * pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbPolyline::desc());
}

