#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "gemat3d.h"
#include "geassign.h"
#include "adscodes.h"

void initApp();
void unloadApp();

void DragMoveEntitys();
void DragRotateEntitys();
void DragScaleEntitys();

void initApp()
{ 
	acedRegCmds->addCommand(_T("DRAGENTITIES_COMMANDS"), _T("DragMoveEntitys"), _T("DragMoveEntitys"), ACRX_CMD_MODAL, DragMoveEntitys);
	acedRegCmds->addCommand(_T("DRAGENTITIES_COMMANDS"), _T("DragRotateEntitys"), _T("DragRotateEntitys"), ACRX_CMD_MODAL, DragRotateEntitys);
	acedRegCmds->addCommand(_T("DRAGENTITIES_COMMANDS"), _T("DragScaleEntitys"), _T("DragScaleEntitys"), ACRX_CMD_MODAL, DragScaleEntitys);
}

void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("DRAGENTITIES_COMMANDS"));
}

static ads_point s_pt; // Global point

void ident_init(ads_matrix matrix)
{
	for (int i = 0; i <= 3; i++)
		for (int j = 0; j <= 3; j++)
		{
			if (i == j)
				matrix[i][j] = 1.0;
			else
				matrix[i][j] = 0.0;
		}
}

int scn_move(ads_point ptMove, ads_matrix mt)
{
	ident_init(mt);
	AcGeMatrix3d mat;
	AcGeVector3d offset = asPnt3d(ptMove) - asPnt3d(s_pt);
	if (offset.length() > 0)
	{
		mat.setToTranslation(offset);
		mt[0][0] = mat.entry[0][0];
		mt[0][1] = mat.entry[0][1];
		mt[0][2] = mat.entry[0][2];
		mt[0][3] = mat.entry[0][3];

		mt[1][0] = mat.entry[1][0];
		mt[1][1] = mat.entry[1][1];
		mt[1][2] = mat.entry[1][2];
		mt[1][3] = mat.entry[1][3];

		mt[2][0] = mat.entry[2][0];
		mt[2][1] = mat.entry[2][1];
		mt[2][2] = mat.entry[2][2];
		mt[2][3] = mat.entry[2][3];

		mt[3][0] = mat.entry[3][0];
		mt[3][1] = mat.entry[3][1];
		mt[3][2] = mat.entry[3][2];
		mt[3][3] = mat.entry[3][3];
		return RTNORM;
	}
	return RTNONE;
}

int scn_scale(ads_point ptMove, ads_matrix mt)
{
	ident_init(mt);
	double curDist = asPnt3d(ptMove).distanceTo(AcGePoint3d(0, 0, 0));
	double baseDist = asPnt3d(s_pt).distanceTo(AcGePoint3d(0, 0, 0));
	if (fabs(baseDist) < 1e-12)
	{
		baseDist = 1.0;
	}
	double scaleAll = curDist / baseDist;

	mt[0][0] = mt[1][1] = scaleAll; // x, y

	return RTNORM;
}

int scn_rotate(ads_point ptMove, ads_matrix mt)
{
	ident_init(mt);
	// Rotate around the z-axis
	AcGePoint3d pt(0, 0, 0);

	mt[0][0] = cos(acutAngle(asDblArray(pt), ptMove));
	mt[0][1] = -sin(acutAngle(asDblArray(pt), ptMove));
	mt[1][0] = sin(acutAngle(asDblArray(pt), ptMove));
	mt[1][1] = cos(acutAngle(asDblArray(pt), ptMove));

	return RTNORM;
}

// Pan entities
void DragMoveEntitys()
{
	ads_name ss;
	int nRet = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (nRet != RTNORM)
	{
		return;
	}
	AcDbObjectIdArray objIds;
	if (nRet == RTNORM)
	{
		int length;
		acedSSLength(ss, &length);
		for (int i = 0; i < length; i++)
		{
			ads_name ent;
			acedSSName(ss, i, ent);
			AcDbObjectId objId;
			acdbGetObjectId(objId, ent);

			objIds.append(objId);
		}
	}

	ads_point ptbase;
	nRet = acedGetPoint(NULL, _T("\nSpecify the base point: "), ptbase);
	if (nRet != RTNORM)
	{
		acedSSFree(ss);
		return;
	}
	ads_point_set(ptbase, s_pt);

	ads_point position;
	nRet = acedDragGen(ss, _T("\nSpecify the position: "), 0, scn_move, position);
	if (RTNORM == nRet)
	{
		AcGeMatrix3d mat;
		AcGeVector3d offset = asPnt3d(position) - asPnt3d(s_pt);
		mat.setToTranslation(offset);
		acedXformSS(ss, mat.entry);
	}

	acedSSFree(ss);
}

// Zoom entities
void DragScaleEntitys()
{
	ads_name ss;
	int nRet = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (nRet != RTNORM)
	{
		return;
	}
	AcDbObjectIdArray objIds;
	if (nRet == RTNORM)
	{
		int length;
		acedSSLength(ss, &length);
		for (int i = 0; i < length; i++)
		{
			ads_name ent;
			acedSSName(ss, i, ent);
			AcDbObjectId objId;
			acdbGetObjectId(objId, ent);

			objIds.append(objId);
		}
	}

	ads_point ptbase;
	nRet = acedGetPoint(NULL, _T("\nSpecify the base point: "), ptbase);
	if (nRet != RTNORM)
	{
		acedSSFree(ss);
		return;
	}
	ads_point_set(ptbase, s_pt);

	ads_point position;
	nRet = acedDragGen(ss, _T("\nSpecify the position: "), 0, scn_scale, position);
	if (RTNORM == nRet)
	{
		AcGeMatrix3d mat;
		double curDist = asPnt3d(position).distanceTo(AcGePoint3d(0, 0, 0));
		double baseDist = asPnt3d(s_pt).distanceTo(AcGePoint3d(0, 0, 0));
		if (fabs(baseDist) < 1e-12) 
		{
			baseDist = 1.0;
		}
		double scaleAll = curDist / baseDist;
		mat.setToScaling(scaleAll);
		acedXformSS(ss, mat.entry);
	}
	acedSSFree(ss);
}

// Rotate entities
void DragRotateEntitys()
{
	ads_name ss;
	int nRet = acedSSGet(NULL, NULL, NULL, NULL, ss);
	if (nRet != RTNORM)
	{
		return;
	}
	AcDbObjectIdArray objIds;
	if (nRet == RTNORM)
	{
		int length;
		acedSSLength(ss, &length);
		for (int i = 0; i < length; i++)
		{
			ads_name ent;
			acedSSName(ss, i, ent);
			AcDbObjectId objId;
			acdbGetObjectId(objId, ent);

			objIds.append(objId);
		}
	}

	ads_point position;
	nRet = acedDragGen(ss, _T("\nSpecify the position: "), 0, scn_rotate, position);
	if (RTNORM == nRet)
	{
		AcGeMatrix3d mat;
		AcGeVector3d offset = asPnt3d(position) - AcGePoint3d(0, 0, 0);
		double angle = offset.angleTo(AcGeVector3d(1, 0, 0));
		mat.setToRotation(angle, AcGeVector3d(0, 0, 1));
		acedXformSS(ss, mat.entry);
	}
	acedSSFree(ss);
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


