#include "stdafx.h"
#include "DBReactor.h"

ACRX_NO_CONS_DEFINE_MEMBERS(DBReactor, AcDbDatabaseReactor);

DBReactor::DBReactor()
{
}

DBReactor::~DBReactor()
{
}

void DBReactor::objectAppended(const ZcDbDatabase * dwg, const ZcDbObject * dbObj)
{
	acutPrintf(_T("\nobjectAppended"));
}

void DBReactor::objectUnAppended(const ZcDbDatabase * dwg, const ZcDbObject * dbObj)
{
	acutPrintf(_T("\nobjectUnAppended"));
}

void DBReactor::objectReAppended(const ZcDbDatabase * dwg, const ZcDbObject * dbObj)
{
	acutPrintf(_T("\nobjectReAppended"));
}

void DBReactor::objectOpenedForModify(const ZcDbDatabase * dwg, const ZcDbObject * dbObj)
{
	acutPrintf(_T("\nobjectOpenedForModify"));
}

void DBReactor::objectModified(const ZcDbDatabase * dwg, const ZcDbObject * dbObj)
{
	acutPrintf(_T("\nobjectModified"));
}

void DBReactor::objectErased(const ZcDbDatabase * dwg, const ZcDbObject * dbObj, ZSoft::Boolean bErased)
{
	acutPrintf(_T("\nobjectErased"));
}

void DBReactor::headerSysVarWillChange(const ZcDbDatabase * dwg, const ZTCHAR * name)
{
	acutPrintf(_T("\nheaderSysVarWillChange"));
}

void DBReactor::headerSysVarChanged(const ZcDbDatabase * dwg, const ZTCHAR * name, ZSoft::Boolean bSuccess)
{
	acutPrintf(_T("\nheaderSysVarChanged"));
}

void DBReactor::proxyResurrectionCompleted(const ZcDbDatabase * dwg, const ZTCHAR * appname, ZcDbObjectIdArray & objects)
{
	acutPrintf(_T("\nproxyResurrectionCompleted"));
}

void DBReactor::goodbye(const ZcDbDatabase * dwg)
{
	acutPrintf(_T("\ngoodbye"));
}
