#ifndef _DB_DATABASE_QUERY_H__INCLUDED_
#define _DB_DATABASE_QUERY_H__INCLUDED_

#include "RxObject.h"


class OdDbStub;
class OdDbDatabase;

class OdDatabaseQuery
{
public:
  enum DbQueryType {
    lineTypeByLayer,
    lineTypeByBlock,
    lineTypeContinuous
  };

  virtual OdDbStub* query(OdDbDatabase* p, OdDatabaseQuery::DbQueryType t) const = 0;
};

class TOOLKIT_EXPORT OdDbDatabaseQuery : public OdRxObject, public OdDatabaseQuery
{
public:
  OdDbDatabaseQuery();
  virtual ~OdDbDatabaseQuery ();

  ODRX_DECLARE_MEMBERS(OdDbDatabaseQuery);

  virtual OdDbStub* query(OdDbDatabase* p, OdDatabaseQuery::DbQueryType t) const;

};

#endif //_DB_DATABASE_QUERY_H__INCLUDED_

