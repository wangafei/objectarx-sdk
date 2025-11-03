#pragma once
#include "dbentityoverrule.h"
class CMyLineOverrule : public AcGiDrawableOverrule
{
public:
	ACRX_DECLARE_MEMBERS(CMyLineOverrule);
	CMyLineOverrule();
	virtual ~CMyLineOverrule();

public:
	virtual Adesk::Boolean  worldDraw(AcGiDrawable* pSubject, AcGiWorldDraw * wd);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;

};

void AddDrawableOverrule();
void RemoveDrawableOverrule();
