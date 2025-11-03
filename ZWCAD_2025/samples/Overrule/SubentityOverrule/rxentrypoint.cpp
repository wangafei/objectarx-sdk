#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "adscodes.h"
#include "dbapserv.h"
#include "migrtion.h"

#include "SubentityOverrule.h"

static CSubentityOverrule* s_g_subentityOverrule = nullptr;

Acad::ErrorStatus AppendToModalSpace(AcDbDatabase* db, AcDbEntity* ent, AcDbObjectId& oid)
{
	if (!db)
		return Acad::eNoDatabase;
	if (!ent)
		return Acad::eNullObjectPointer;

	Acad::ErrorStatus stats = Acad::eOk;
	AcDbBlockTable* pBlockTable = NULL;
	stats = db->getBlockTable(pBlockTable, AcDb::kForRead);
	if (pBlockTable)
	{
		AcDbBlockTableRecord* pBTR = NULL;
		stats = pBlockTable->getAt(ACDB_MODEL_SPACE, pBTR, AcDb::kForWrite);
		pBlockTable->close();
		pBlockTable = NULL;
		if (pBTR)
		{
			stats = pBTR->appendAcDbEntity(oid, ent);
			pBTR->close();
		}
	}
	return stats;
}

int getGsMarker(ads_name sset, int & gsmarker)
{
	int iRetValue = RTNORM;

	struct resbuf *pRb = nullptr;
	if (RTNORM != (iRetValue = acedSSNameX(&pRb, sset, 0)))
	{
		return iRetValue;
	}

	struct resbuf *pTarNode = pRb;
	int i = 1;
	for (; pTarNode && i < 4; i++)  // The fourth node corresponds to gsmarker
	{
		pTarNode = pTarNode->rbnext;
	}

	if (pTarNode && i == 4)
		gsmarker = pTarNode->resval.rint;
	else
		iRetValue = RTERROR;

	acutRelRb(pRb);

	return iRetValue;
}

void highlightEdge(const AcDbObjectId& objId, const int gsmarker)
{
	AcDbEntity *pEnt = nullptr;
	if (Acad::eOk != acdbOpenAcDbEntity(pEnt, objId, AcDb::kForRead))
		return;

	AcGePoint3d pickpnt;
	AcGeMatrix3d xform;
	int numIds = 0;
	AcDbFullSubentPath *subentIds = nullptr;
	pEnt->getSubentPathsAtGsMarker(AcDb::kEdgeSubentType, gsmarker, pickpnt, xform, numIds, subentIds);

	if (numIds > 0)
	{
		// Highlight the subenttity
		pEnt->highlight(subentIds[0]);

		TCHAR szData[128] = { 0 }; // space for acedGetString pauses below
		acedGetString(0, _T("\nPlease press <Space> or <Enter> to continue..."), szData);

		// Cancel the highlight state
		pEnt->unhighlight(subentIds[0]);

		// Copy a subentity
		// You can override AcDbSubentityOverrule::subentPtr to customize the return value
		AcDbEntity *pEntCpy = pEnt->subentPtr(subentIds[0]);  
		if (pEntCpy)
		{
			acutPrintf(_T("\nCopy SubEntity done!"));
			pEntCpy->setColorIndex(1);

			AcGeMatrix3d mat(AcGeMatrix3d::kIdentity);
			mat.setToTranslation(AcGeVector3d(0, 100, 0));
			pEntCpy->transformBy(mat);

			AcDbObjectId objId;
			AppendToModalSpace(acdbCurDwg(), pEntCpy, objId);
			pEntCpy->close();
		}
	}

	if (subentIds)
	{
		delete[]subentIds;
		subentIds = nullptr;
	}

	pEnt->close();
}

void removeSubentityOverrule()
{
	if (s_g_subentityOverrule)
	{
		AcRxOverrule::removeOverrule(AcDbPolyline::desc(), s_g_subentityOverrule);
		AcRxOverrule::setIsOverruling(false);

		delete s_g_subentityOverrule;
		s_g_subentityOverrule = nullptr;
	}
}

void addSubentityOverrule()
{
	removeSubentityOverrule();

	s_g_subentityOverrule = new CSubentityOverrule;
	AcRxOverrule::addOverrule(AcDbPolyline::desc(), s_g_subentityOverrule);
	AcRxOverrule::setIsOverruling(true);
}

// Highlight the sub-edge of entity
//
void highlihtSubEdge()
{
	ads_name sset;
	int iRetValue = RTNORM;
	AcDbObjectId objId;
	int gsmarker;

	if (RTNORM != (iRetValue = acedSSGet(_T(":S"), NULL, NULL, NULL, sset)))
	{
		acutPrintf(_T("\nSSGet error: %d"), iRetValue);
		return;
	}

	ads_name ename;
	acedSSName(sset, 0, ename);
	acdbGetObjectId(objId, ename);

	if (RTNORM == getGsMarker(sset, gsmarker))
	{
		acutPrintf(_T("\nGsMarker: %d"), gsmarker);
		highlightEdge(objId, gsmarker);
	}
	else
	{
		acutPrintf(_T("\nGetGsMarker failed!"));
	}

	acedSSFree(sset);
}

void initApp()
{ 
	// 1.Draw a polyline;
	// 2.Execute "HighlihtSubEdge" and select a sub-edge of polyline;
	// 3.Execute "AddSubentityOverrule" and repeat step 2
	acedRegCmds->addCommand(_T("SUBENTITYOVERRULE_COMMANDS"), _T("RemoveSubentityOverrule"), _T("RemoveSubentityOverrule"), ACRX_CMD_MODAL, removeSubentityOverrule);
	acedRegCmds->addCommand(_T("SUBENTITYOVERRULE_COMMANDS"), _T("AddSubentityOverrule"), _T("AddSubentityOverrule"), ACRX_CMD_MODAL, addSubentityOverrule);
	acedRegCmds->addCommand(_T("SUBENTITYOVERRULE_COMMANDS"), _T("HighlihtSubEdge"), _T("HighlihtSubEdge"), ACRX_CMD_MODAL, highlihtSubEdge);
}

void unloadApp()
{ 
	removeSubentityOverrule();
	acedRegCmds->removeGroup(_T("SUBENTITYOVERRULE_COMMANDS"));
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


