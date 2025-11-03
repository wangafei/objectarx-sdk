#include "stdafx.h"
#include "HighlightOverrule.h"

Acad::ErrorStatus CHighlightOverrule::highlight(
	const AcDbEntity* pSubject,
	const AcDbFullSubentPath& subId/*= kNullSubent*/,
	const Adesk::Boolean highlightAll/*= false*/)
{
	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(AcDbLine::desc()))
		{
			acutPrintf(_T("\nAcDbLine highlight invalid..."));
			return Acad::eInvalidInput;
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle highlight..."));
		}
	}

	return AcDbHighlightOverrule::highlight(pSubject, subId, highlightAll);
}

Acad::ErrorStatus CHighlightOverrule::unhighlight(
	const AcDbEntity* pSubject,
	const AcDbFullSubentPath& subId /*= kNullSubent*/,
	const Adesk::Boolean highlightAll /*= false*/)
{
	if (isApplicable(pSubject))
	{
		if (pSubject->isKindOf(AcDbLine::desc()))
		{
			acutPrintf(_T("\nAcDbLine unhighlight..."));
		}
		else if (pSubject->isKindOf(AcDbCircle::desc()))
		{
			acutPrintf(_T("\nAcDbCircle unhighlight invalid..."));
			return Acad::eInvalidInput;
		}
	}

	return AcDbHighlightOverrule::unhighlight(pSubject, subId, highlightAll);
}

bool CHighlightOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc()) || pOverruledSubject->isKindOf(AcDbCircle::desc());
}
