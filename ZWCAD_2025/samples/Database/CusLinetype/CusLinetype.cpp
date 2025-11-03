#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>
#include "dbents.h"
#include "dbapserv.h"

void initApp();
void unloadApp();

void createLineTypeTest();
void applyCusLineTypeTest();

void initApp()
{ 
	// Please execute command "CreateLineTypeTest" before executing command "ApplyCusLineTypeTest" to make sure the linetype exists.
	acedRegCmds->addCommand(_T("CUSLINETYPE_COMMANDS"), _T("createLineTypeTest"), _T("createLineTypeTest"), ACRX_CMD_MODAL, createLineTypeTest);
	acedRegCmds->addCommand(_T("CUSLINETYPE_COMMANDS"), _T("applyCusLineTypeTest"), _T("applyCusLineTypeTest"), ACRX_CMD_MODAL, applyCusLineTypeTest);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup(_T("CUSLINETYPE_COMMANDS"));
}

void createLineTypeTest()
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDadabase = acdbHostApplicationServices()->workingDatabase();
	AcDbLinetypeTable* pLineTypeTable = NULL;
	if (Acad::eOk != pDadabase->getLinetypeTable(pLineTypeTable, AcDb::kForWrite))
		return;

	// CustomLinetype1
	if (!pLineTypeTable->has(_T("CustomLinetype1")))
	{
		AcDbLinetypeTableRecord *pLineTypeTableRec1 = new AcDbLinetypeTableRecord();
		pLineTypeTableRec1->setName(_T("CustomLinetype1"));
		es = pLineTypeTableRec1->setComments(_T("TextLineType"));  // description

		// Dash£ºsolidline(+)£¬space(-)£¬dot(0)
		pLineTypeTableRec1->setNumDashes(2);
		pLineTypeTableRec1->setDashLengthAt(0, 1);
		pLineTypeTableRec1->setDashLengthAt(1, -2.25);

		// Dash(1) set as text
		pLineTypeTableRec1->setShapeStyleAt(1, pDadabase->textstyle());
		pLineTypeTableRec1->setTextAt(1, _T("TextLineType"));                  // text content
		pLineTypeTableRec1->setShapeScaleAt(1, 0.25);                          // text scale
		pLineTypeTableRec1->setShapeOffsetAt(1, AcGeVector2d(-2.2, -0.125));   // Text offset, the default is the starting point of the next dash

		pLineTypeTableRec1->setPatternLength(3);       // DashLength

		es = pLineTypeTable->add(pLineTypeTableRec1);
		pLineTypeTableRec1->close();
	}

	// CustomLinetype2
	if (!pLineTypeTable->has(_T("CustomLinetype2")))
	{
		AcDbLinetypeTableRecord *pLineTypeTableRec2 = new AcDbLinetypeTableRecord();
		pLineTypeTableRec2->setName(_T("CustomLinetype2"));
		es = pLineTypeTableRec2->setComments(_T("PointLineType"));  // description

		// Dash£ºsolidline(+)£¬space(-)£¬dot(0)
		pLineTypeTableRec2->setNumDashes(4);
		pLineTypeTableRec2->setDashLengthAt(0, 0.5);
		pLineTypeTableRec2->setDashLengthAt(1, -0.25);
		pLineTypeTableRec2->setDashLengthAt(2, 0);
		pLineTypeTableRec2->setDashLengthAt(3, -0.25);

		pLineTypeTableRec2->setPatternLength(1);       // DashLength

		es = pLineTypeTable->add(pLineTypeTableRec2);
		pLineTypeTableRec2->close();
	}

	pLineTypeTable->close();
}

void applyCusLineTypeTest()
{
	Acad::ErrorStatus es;
	AcDbDatabase *pDatabase = acdbHostApplicationServices()->workingDatabase();
	AcDbBlockTable *pBlockTable = NULL;
	AcDbBlockTableRecord *pMSBlkRec = NULL;
	pDatabase->getBlockTable(pBlockTable, AcDb::kForRead);
	if (Acad::eOk != pBlockTable->getAt(ACDB_MODEL_SPACE, pMSBlkRec, AcDb::kForWrite))
		return;

	AcDbLine *pLine1 = new AcDbLine(AcGePoint3d(0, 100, 0), AcGePoint3d(100, 100, 0));
	pLine1->setLinetype(_T("CustomLinetype1"));
	pLine1->setLinetypeScale(10);  // Set the linetype scale
	pMSBlkRec->appendAcDbEntity(pLine1);
	pLine1->close();

	AcDbLine *pLine2 = new AcDbLine(AcGePoint3d(100, 100, 0), AcGePoint3d(200, 100, 0));
	pLine2->setLinetype(_T("CustomLinetype2"));
	pLine1->setLinetypeScale(10);
	pMSBlkRec->appendAcDbEntity(pLine2);
	pLine2->close();

	pMSBlkRec->close();
	pBlockTable->close();
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


