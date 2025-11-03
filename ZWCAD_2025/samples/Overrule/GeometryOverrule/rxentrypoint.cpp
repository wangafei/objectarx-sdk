#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "GeometryOverrule.h"

static CGeometryOverrule* s_g_geometryOverrule = nullptr;
void removeGeometryOverrule()
{
	if (s_g_geometryOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbLine::desc(), s_g_geometryOverrule);
		AcRxOverrule::removeOverrule(AcDbCircle::desc(), s_g_geometryOverrule);
		AcRxOverrule::removeOverrule(AcDbPolyline::desc(), s_g_geometryOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_geometryOverrule;
		s_g_geometryOverrule = nullptr;
	}
}
void addGeometryOverrule()
{
	removeGeometryOverrule();

	s_g_geometryOverrule = new CGeometryOverrule;
	AcRxOverrule::addOverrule(AcDbLine::desc(), s_g_geometryOverrule);
	AcRxOverrule::addOverrule(AcDbCircle::desc(), s_g_geometryOverrule);
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_geometryOverrule);
	AcRxOverrule::setIsOverruling(true);
}

// Get extents fo Entity
void getGeoExtentsOfThisEntity()
{
	ads_name sname;
	ads_point ptRes;
	if (RTNORM == acedEntSel(_T("Select an entity:"), sname, ptRes))
	{
		AcDbObjectId id;
		acdbGetObjectId(id, sname);

		AcDbEntity *pEnt = nullptr;
		if (Acad::eOk == acdbOpenAcDbEntity(pEnt, id, AcDb::kForRead))
		{
			AcDbExtents ext;
			pEnt->getGeomExtents(ext);
			acutPrintf(_T("\next.minPoint(%g, %g, %g) ext.maxPoint(%g, %g, %g)"),
				ext.minPoint().x, ext.minPoint().y, ext.minPoint().z, ext.maxPoint().x, ext.maxPoint().y, ext.maxPoint().z);

			pEnt->close();
		}
	}
}

// Get the intersection of two entities
void getIntersectionOfTwoEntities()
{
	ads_name sname1, sname2;
	ads_point ptRes;
	if (RTNORM == acedEntSel(_T("Select first entity:\n"), sname1, ptRes) && 
		RTNORM == acedEntSel(_T("Select second entity:\n"), sname2, ptRes))
	{
		AcDbObjectId id1, id2;
		if (Acad::eOk == acdbGetObjectId(id1, sname1) && Acad::eOk == acdbGetObjectId(id2, sname2))
		{
			AcDbEntity* ent1 = nullptr, *ent2 = nullptr;
			Acad::ErrorStatus es;
			AcGePoint3dArray points;
			es = acdbOpenAcDbEntity(ent1, id1, AcDb::kForRead);
			es = acdbOpenAcDbEntity(ent2, id2, AcDb::kForRead);
			ent1->intersectWith(ent2, AcDb::kOnBothOperands, points);
			acutPrintf(_T("\n<intersectWith api>Points length: %d"), points.length());
			for (int i = 0; i < points.length(); i++)
			{
				acutPrintf(_T("\nptInsec[%d]: (%g, %g, %g)"), i, points[i].x, points[i].y, points[i].z);
			}
			ent1->close();
			ent2->close();
		}
	}
}
void initApp()
{ 
	acedRegCmds->addCommand(_T("GEOMETRYOVERRULE_COMMANDS"), _T("removeGeometryOverrule"), _T("removeGeometryOverrule"), ACRX_CMD_MODAL, removeGeometryOverrule);
	acedRegCmds->addCommand(_T("GEOMETRYOVERRULE_COMMANDS"), _T("addGeometryOverrule"), _T("addGeometryOverrule"), ACRX_CMD_MODAL, addGeometryOverrule);
	acedRegCmds->addCommand(_T("GEOMETRYOVERRULE_COMMANDS"), _T("getGeoExtentsOfThisEntity"), _T("getGeoExtentsOfThisEntity"), ACRX_CMD_MODAL, getGeoExtentsOfThisEntity);
	acedRegCmds->addCommand(_T("GEOMETRYOVERRULE_COMMANDS"), _T("getIntersectionOfTwoEntities"), _T("getIntersectionOfTwoEntities"), ACRX_CMD_MODAL, getIntersectionOfTwoEntities);
}

void unloadApp()
{ 
	removeGeometryOverrule();
	acedRegCmds->removeGroup(_T("GEOMETRYOVERRULE_COMMANDS"));
}

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}
