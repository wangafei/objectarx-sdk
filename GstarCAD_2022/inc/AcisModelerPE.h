#ifndef AICS_ENTITY_MODELER_PE_DEFINED
#define AICS_ENTITY_MODELER_PE_DEFINED

#include "RxObject.h"

class OdDbRegion;

class TOOLKIT_EXPORT AcisModelerPE : public OdRxObject
{
public:
	ODRX_DECLARE_MEMBERS(AcisModelerPE);

	AcisModelerPE();
	virtual ~AcisModelerPE();

	// for all
	virtual OdResult getGeomExtents(const OdDbEntity* pEntity, OdGeExtents3d& extents) = 0;

	// for OdDbRegion
	virtual OdResult booleanOper(OdDbRegion* thisRegion, OdDb::BoolOperType operation, OdDbRegion* otherRegion) = 0;

	virtual OdResult getArea(const OdDbRegion* thisRegion, double& regionArea) = 0;

	virtual OdResult getPerimeter(const OdDbRegion* thisRegion, double& regionPerimeter) = 0;

	virtual OdResult getAreaProp(const OdDbRegion* thisRegion, 
		const OdGePoint3d& origin, const OdGeVector3d& xAxis, const OdGeVector3d& yAxis, 
		double& perimeter, double& area, OdGePoint2d& centroid,
		double momInertia[2], double& prodInertia,
		double prinMoments[2], OdGeVector2d prinAxes[2],
		double radiiGyration[2], OdGePoint2d& extentsLow,
		OdGePoint2d& extentsHigh ) = 0;

	// for OdDb3dSolid
	// TODO: ...

	static void init(AcisModelerPE* pExternal);
	static void uninit();

	static bool isInit();
};

#endif  //AICS_ENTITY_MODELER_PE_DEFINED

