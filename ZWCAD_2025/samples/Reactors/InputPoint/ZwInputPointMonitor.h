#pragma once

#include "acedinpt.h"

class ZwInputPointMonitor : public AcEdInputPointMonitor
{
public:
	virtual Acad::ErrorStatus monitorInputPoint(const AcEdInputPoint& input, AcEdInputPointMonitorResult& output);
	virtual bool excludeFromOsnapCalculation(const AcArray<AcDbObjectId>& nestedEntity, INT_PTR gsSelectionMark);
};
