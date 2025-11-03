#pragma once
#include "acedinpt.h"

class ZwInputPointFilter : public AcEdInputPointFilter
{
public:
	virtual Acad::ErrorStatus processInputPoint(const AcEdInputPoint& input, AcEdInputPointFilterResult& output);
public:
	inline void enableChange(bool bChanged = false) { m_bPointChanged = bChanged; }
private:
	bool m_bPointChanged;
};