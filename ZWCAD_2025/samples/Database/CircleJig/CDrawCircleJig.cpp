#include "stdafx.h"
#include "CDrawCircleJig.h"

CDrawCircleJig::CDrawCircleJig(const AcGeVector3d & normal)
{
	m_centerPoint = AcGePoint3d(0,0,0);
	m_dRadius = 0.0;
	m_normal = normal;
	m_iPromptCount = 0;
}

CDrawCircleJig::~CDrawCircleJig()
{
}

void CDrawCircleJig::doIt()
{
	m_pCircle = new AcDbCircle(m_centerPoint, m_normal, m_dRadius);

	setDispPrompt(_T("Please enter the center£º"));
	AcEdJig::DragStatus stat = drag();

	m_iPromptCount = 1;
	setDispPrompt(_T("Please enter the radius£º"));
	stat = drag();

	if (stat == AcEdJig::kNormal)
	{
		append();
	}
	else
	{
		delete m_pCircle;
	}
}

AcEdJig::DragStatus CDrawCircleJig::sampler()
{
	AcEdJig::DragStatus stat;

	setUserInputControls((UserInputControls)(AcEdJig::kAccept3dCoordinates | AcEdJig::kNoNegativeResponseAccepted | AcEdJig::kNoZeroResponseAccepted));
	if (m_iPromptCount == 0)
	{
		AcGePoint3d inputPt;
		stat = acquirePoint(inputPt);
		if (stat == AcEdJig::kNormal)
		{
			if (inputPt.isEqualTo(m_centerPoint))
			{
				return AcEdJig::kNoChange;
			}
			m_centerPoint = inputPt;
		}
	}
	else if (m_iPromptCount == 1)
	{
		double inputradius = -1;
		stat = acquireDist(inputradius, m_centerPoint);

		if (stat == AcEdJig::kNormal)
		{
			if (inputradius == m_dRadius)
			{
				return AcEdJig::kNoChange;
			}
			m_dRadius = inputradius;
		}
	}

	return stat;
}

Adesk::Boolean CDrawCircleJig::update()
{
	switch (m_iPromptCount)
	{
	case 0:
		m_pCircle->setCenter(m_centerPoint);
		m_pCircle->setRadius(m_dRadius);
	case 1:
		m_pCircle->setRadius(m_dRadius);
	default:
		break;
	}
	return Adesk::kTrue;
}

AcDbEntity * CDrawCircleJig::entity() const
{
	return m_pCircle;
}
