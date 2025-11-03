#pragma once

#include "MyCurveEnt.h"
#include "dbjig.h"

class CMyJig : public AcEdJig
{
public:
	CMyJig();
	~CMyJig();

	bool doIt(const AcGePoint3d &ptCenter, int num);
	AcDbEntity* entity() const;
	AcEdJig::DragStatus sampler();
	Adesk::Boolean update();

private:
	CMyCurve* m_pEnt;
	AcGePoint3d m_ptCenter;
	AcGePoint3d m_ptCur;
};