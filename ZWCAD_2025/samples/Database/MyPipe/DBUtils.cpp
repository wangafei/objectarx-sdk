#pragma once
#include "stdafx.h"
#include "DBUtils.h"
#include "dbobjptr.h"
#include "dbapserv.h"
#include "adscodes.h"

Acad::ErrorStatus GetSysVar(LPCTSTR name, int& value)
{
	resbuf rb;
	if (acedGetVar(name, &rb) == RTNORM)
	{
		ASSERT(rb.restype == RTSHORT);
		value = rb.resval.rint;
		return Acad::eOk;
	}

	return Acad::eInvalidInput;
}

Acad::ErrorStatus AddToCurrentSpace(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb/* = NULL*/)
{
	if (pDb == NULL)
		pDb = acdbHostApplicationServices()->workingDatabase();

	AcDbBlockTableRecordPointer pBTR(pDb->currentSpaceId(), AcDb::kForWrite);
	EOK_RETURN(pBTR.openStatus());

	return pBTR->appendAcDbEntity(objId, newEnt);
}

Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb/* = NULL*/)
{
	EOK_RETURN(AddToCurrentSpace(newEnt, objId, pDb));

	return newEnt->close();
}

Acad::ErrorStatus AddToModelSpace(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb/* = NULL*/)
{
	if (pDb == NULL)
		pDb = acdbHostApplicationServices()->workingDatabase();

	AcDbBlockTableRecordPointer pBTR(ACDB_MODEL_SPACE, pDb, AcDb::kForWrite);
	EOK_RETURN(pBTR.openStatus());

	return pBTR->appendAcDbEntity(objId, newEnt);
}

Acad::ErrorStatus AddToModelSpaceAndClose(AcDbEntity* newEnt, AcDbObjectId& objId, AcDbDatabase* pDb/* = NULL*/)
{
	EOK_RETURN(AddToModelSpace(newEnt, objId, pDb));

	return newEnt->close();
}	