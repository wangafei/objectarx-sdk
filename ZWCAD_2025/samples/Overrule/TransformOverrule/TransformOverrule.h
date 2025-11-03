#pragma once

#include "dbmain.h"
#include "dbentityoverrule.h"

class CTransformOverrule : public AcDbTransformOverrule
{
public:
	virtual Acad::ErrorStatus transformBy(AcDbEntity* pSubject, const AcGeMatrix3d& xform);
	virtual Acad::ErrorStatus getTransformedCopy(const AcDbEntity* pSubject, const AcGeMatrix3d& xform, AcDbEntity*& pEnt);
	virtual Acad::ErrorStatus explode(const AcDbEntity* pSubject, AcDbVoidPtrArray& entitySet);
	virtual Adesk::Boolean cloneMeForDragging(AcDbEntity* pSubject);
	virtual bool hideMeForDragging(const AcDbEntity* pSubject);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
protected:
private:
};
