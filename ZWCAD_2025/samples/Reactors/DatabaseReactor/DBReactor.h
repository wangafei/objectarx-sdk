#pragma once
#include "stdafx.h"
#include "dbmain.h"
class DBReactor : public AcDbDatabaseReactor
{
public:
	ACRX_DECLARE_MEMBERS(DBReactor);
	DBReactor();
	~DBReactor();

	virtual void objectAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);//when the object has been added to the database
	virtual void objectUnAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);//when the addition to the database has been cancelled by an Undo operation
	virtual void objectReAppended(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);//when the object is reappended by redo after unappended by undo
	virtual void objectOpenedForModify(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);//when opend by writing
	virtual void objectModified(const ZcDbDatabase* dwg, const ZcDbObject* dbObj);//when the object is modified
	virtual void objectErased(const ZcDbDatabase* dwg, const ZcDbObject* dbObj, ZSoft::Boolean bErased);//when the object is erased or unerased
	virtual void headerSysVarWillChange(const ZcDbDatabase* dwg, const ZTCHAR* name);//attempting to change system variables
	virtual void headerSysVarChanged(const ZcDbDatabase* dwg, const ZTCHAR* name, ZSoft::Boolean bSuccess);// the system variable has been changed
	virtual void proxyResurrectionCompleted(const ZcDbDatabase* dwg, const ZTCHAR* appname, ZcDbObjectIdArray& objects);//triggered when the proxy object revives
	virtual void goodbye(const ZcDbDatabase* dwg);//triggered when the DWG database is about to be deleted

protected:

private:

};