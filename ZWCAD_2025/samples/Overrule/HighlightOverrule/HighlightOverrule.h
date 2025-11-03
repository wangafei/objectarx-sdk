#pragma once

#include "dbents.h"
#include "dbentityoverrule.h"

class CHighlightOverrule : public AcDbHighlightOverrule
{
public:
	virtual Acad::ErrorStatus highlight(
		const AcDbEntity* pSubject,
		const AcDbFullSubentPath& subId = kNullSubent,
		const Adesk::Boolean highlightAll = false);

	virtual Acad::ErrorStatus unhighlight(
		const AcDbEntity* pSubject,
		const AcDbFullSubentPath& subId = kNullSubent,
		const Adesk::Boolean highlightAll = false);

	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
};
