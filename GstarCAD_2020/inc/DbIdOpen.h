///////////////////////////////////////////////////////////////////////////////
// TODO
// 
// 本文件被包含在 "DbObjectId.h" 里面
//
///////////////////////////////////////////////////////////////////////////////


#ifndef _OD_OBJECTID_OPEN_H_INCLUDED_
#define _OD_OBJECTID_OPEN_H_INCLUDED_


#include "RxObject.h"
class OdDbObjectId;
class OdDbEntity;

template<class T_OBJECT> inline 
OdResult oddbOpenObject(T_OBJECT *& pObj, 
                        const OdDbObjectId& id, 
                        OdDb::OpenMode mode, 
                        bool openErased = false)
{
  pObj = 0;
  OdResult res = Oda::eNullObjectId;  
  if (id.isNull()) return res;

  try {     // 这里没有检查 NULL-ID, 通过异常进行获取错误
    OdDbObject* ptr = NULL;
    OdDbObjectPtr spObj;
    res = id.openObject(spObj, mode, openErased, true);
    if(res==Oda::eOk)
    {	
	  ptr = spObj.detach();
	  if(ptr->isKindOf(T_OBJECT::desc()))
	  {
		  pObj = (T_OBJECT*)ptr;
	  }
	  else
	  {
		  spObj.attach(ptr);
		  res = Oda::eNotThatKindOfClass;
	  }      
    }
  }
  catch(OdError& err) {
    res = err.code();
  }

  return res;
}

extern TOOLKIT_EXPORT
OdResult oddbOpenOdDbObject(OdDbObject*& pObj, OdDbObjectId id, OdDb::OpenMode mode, bool openErasedObject = false);

extern TOOLKIT_EXPORT
OdResult oddbOpenOdDbObject(OdDbObject*& pObj, OdDbObjectId id, OdDb::OpenMode mode, const OdRxClass *pClass, bool openErasedObject = false);

extern TOOLKIT_EXPORT
OdResult oddbOpenOdDbEntity(OdDbEntity*& pEnt, OdDbObjectId id, OdDb::OpenMode mode, bool openErasedEntity = false);

inline OdResult 
oddbOpenObject(OdDbObject *& pObj, OdDbObjectId id, OdDb::OpenMode mode)
{
	return ::oddbOpenOdDbObject(pObj, id, mode, false);
}

inline OdResult 
oddbOpenObject(OdDbEntity *& pEnt, OdDbObjectId id, OdDb::OpenMode mode)
{
	return ::oddbOpenOdDbEntity(pEnt, id, mode, false);
}

inline OdResult 
oddbOpenObject(OdDbObject *& pObj, OdDbObjectId id, OdDb::OpenMode mode,  bool openErased)
{
	return ::oddbOpenOdDbObject(pObj, id, mode, openErased);
}

inline OdResult 
oddbOpenObject(OdDbEntity *& pEnt, OdDbObjectId id, OdDb::OpenMode mode,  bool openErased)
{
	return ::oddbOpenOdDbEntity(pEnt, id, mode, openErased);
}

#endif // _OD_OBJECTID_OPEN_H_INCLUDED_

