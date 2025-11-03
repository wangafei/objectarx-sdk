#include "stdafx.h"
#include "PropertiesOverrule.h"
#include "dbents.h"

void CPropertiesOverrule::list(const AcDbEntity * pSubject)
{
	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\n CPropertiesOverrule list begin----"));
		AcDbPropertiesOverrule::list(pSubject);
		acutPrintf(_T("\n CPropertiesOverrule list end----"));
	}
	else
	{
		AcDbPropertiesOverrule::list(pSubject);
	}
}

Zcad::ErrorStatus CPropertiesOverrule::getClassID(const AcDbObject * pSubject, CLSID * pClsid)
{
	return AcDbPropertiesOverrule::getClassID(pSubject, pClsid);
}

bool CPropertiesOverrule::isApplicable(const AcRxObject * pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc());
}