#include "pch.h"
#include "CMyLineOverrule.h"

ACRX_NO_CONS_DEFINE_MEMBERS(CMyLineOverrule, AcGiDrawableOverrule)

CMyLineOverrule::CMyLineOverrule()
{
}


CMyLineOverrule::~CMyLineOverrule()
{
}

Adesk::Boolean CMyLineOverrule::worldDraw(AcGiDrawable * pSubject, AcGiWorldDraw * wd)
{
	AcDbLine* line = AcDbLine::cast(pSubject);
	if (line)
	{
		uint16_t color = wd->subEntityTraits().color();
		wd->subEntityTraits().setColor(35);
		const ACHAR* text = line->isA()->dxfName();
		wd->geometry().text(line->endPoint(), AcGeVector3d::kZAxis, AcGeVector3d::kXAxis, 10, 1, 0, text);
		wd->subEntityTraits().setColor(color);
	}
	return AcGiDrawableOverrule::worldDraw(pSubject, wd);
}

bool CMyLineOverrule::isApplicable(const AcRxObject * pOverruledSubject) const
{
	return true;
}


static CMyLineOverrule s_line_overrule;
void AddDrawableOverrule()
{
	AcRxOverrule::addOverrule(AcDbLine::desc(), &s_line_overrule, false);
}

void RemoveDrawableOverrule()
{
	AcRxOverrule::removeOverrule(AcDbLine::desc(), &s_line_overrule);
}