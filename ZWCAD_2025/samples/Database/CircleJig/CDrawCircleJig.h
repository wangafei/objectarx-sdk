#pragma once
#include "stdafx.h"
#include "dbjig.h"
#include "dbents.h"

class CDrawCircleJig : public AcEdJig
{
public:
	CDrawCircleJig(const AcGeVector3d &normal);
	virtual ~CDrawCircleJig();

	void doIt();

	virtual AcEdJig::DragStatus sampler();

	virtual Adesk::Boolean update();

	virtual AcDbEntity* entity() const;
private:
	AcDbCircle* m_pCircle;
	AcGePoint3d m_centerPoint;
	AcGeVector3d m_normal;
	double m_dRadius;
	int m_iPromptCount;
};