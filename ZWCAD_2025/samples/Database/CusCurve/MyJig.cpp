#include "stdafx.h"
#include "MyJig.h"

extern  Acad::ErrorStatus AddToModelSpace(AcDbEntity *pEnt);
extern double pi();

CMyJig::CMyJig() : AcEdJig()
{
	m_pEnt = NULL;
}

CMyJig::~CMyJig()
{
}

bool CMyJig::doIt(const AcGePoint3d &ptCenter, int num)
{
	m_ptCenter = ptCenter;
	m_pEnt = new CMyCurve(m_ptCenter, m_ptCenter, num);
	setDispPrompt(_T("Specify next point£º"));
	AcEdJig::DragStatus stat = drag();

	if (stat == kNormal)
	{
		AddToModelSpace(m_pEnt);
		m_pEnt->close();
		return true;
	}
	else
	{
		delete m_pEnt;
		return false;
	}
}

AcEdJig::DragStatus CMyJig::sampler()
{
	setUserInputControls((UserInputControls)(AcEdJig::kAccept3dCoordinates | AcEdJig::kNoNegativeResponseAccepted | AcEdJig::kNullResponseAccepted));
	static AcGePoint3d pt;
	DragStatus stat = acquirePoint(m_ptCur);
	if (pt != m_ptCur)
	{
		pt = m_ptCur;
	}
	else if (stat == AcEdJig::kNormal)
	{
		return AcEdJig::kNoChange;
	}
	return stat;
}

Adesk::Boolean CMyJig::update()
{
	m_pEnt->setEndPoint(m_ptCur);

	return Adesk::kTrue;
}

AcDbEntity *CMyJig::entity() const
{
	return m_pEnt;
}
