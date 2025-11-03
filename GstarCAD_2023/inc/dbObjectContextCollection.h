/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_OBJECTCONTEXTCOLLECTION_H
#define GCDB_OBJECTCONTEXTCOLLECTION_H

#pragma once

#include "gcdb.h"
#include "dbmain.h"
#include "GcString.h"
#include "dbObjContext.h"

#pragma pack (push, 8)

class GcDbObjectContextCollectionIterator;

class GCDB_PORT GSOFT_NO_VTABLE GcDbObjectContextCollection : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectContextCollection);

  virtual GcString            name() const = 0;
  virtual GcDbObjectContext*  currentContext(const GcDbObject* pRequestingObject) const = 0;
  virtual Gcad::ErrorStatus   setCurrentContext(const GcDbObjectContext* pContext) = 0;
  virtual Gcad::ErrorStatus   addContext(const GcDbObjectContext* pContext) = 0;
  virtual Gcad::ErrorStatus   removeContext(const GcString& contextName) = 0;
  virtual Gcad::ErrorStatus   lockContext(const GcDbObjectContext* pContext) = 0;
  virtual Gcad::ErrorStatus   unlockContext() = 0;
  virtual bool                locked() const = 0;
  virtual GcDbObjectContext*  getContext(const GcString& contextName) const = 0;
  virtual bool                hasContext(const GcString& contextName) const = 0;
  virtual GcDbObjectContextCollectionIterator* newIterator() const = 0;
};

class GCDB_PORT GSOFT_NO_VTABLE GcDbObjectContextCollectionIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbObjectContextCollectionIterator);

  virtual Gcad::ErrorStatus start() = 0;
  virtual bool              next() = 0;
  virtual bool              done() const = 0;
  virtual Gcad::ErrorStatus getContext(GcDbObjectContext*& pObjectContext) const = 0;
};
#pragma pack (pop)

#endif