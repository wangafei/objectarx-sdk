#pragma once

#include "dbmain.h"
#include "dbentityoverrule.h"

class CPropertiesOverrule : public AcDbPropertiesOverrule
{
public:
	virtual void list(const AcDbEntity* pSubject);
	virtual Acad::ErrorStatus getClassID(const AcDbObject* pSubject, CLSID* pClsid);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
protected:
private:
};
