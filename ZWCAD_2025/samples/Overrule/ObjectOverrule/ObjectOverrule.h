#pragma once

#include "dbmain.h"
#include "dbobjectoverrule.h"

class CPolyLineOverrule : public AcDbObjectOverrule
{
public:
	CPolyLineOverrule(bool canCopy);
	virtual Acad::ErrorStatus open(AcDbObject* pSubject, AcDb::OpenMode mode);

	virtual Acad::ErrorStatus close(AcDbObject* pSubject);

	virtual Acad::ErrorStatus cancel(AcDbObject* pSubject);

	virtual Acad::ErrorStatus erase(AcDbObject* pSubject, Adesk::Boolean erasing);

	virtual Acad::ErrorStatus deepClone(const AcDbObject* pSubject,
		AcDbObject* pOwnerObject,
		AcDbObject*& pClonedObject,
		AcDbIdMapping& idMap,
		Adesk::Boolean isPrimary = true);

	virtual Acad::ErrorStatus wblockClone(const AcDbObject* pSubject,
		AcRxObject* pOwnerObject,
		AcDbObject*& pClonedObject,
		AcDbIdMapping& idMap,
		Adesk::Boolean isPrimary = true);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
protected:
private:
	bool m_bCanCopy;
};
