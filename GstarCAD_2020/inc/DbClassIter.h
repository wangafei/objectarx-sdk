#pragma once
#include "DbDatabase.h"
class OdDbClassIterator
{
public:

  static OdDbClassIterator * newIterator()
  {
    throw OdError(eNotImplemented);
    return NULL;
  }

  static void deleteIterator(OdDbClassIterator *pIter)
  {
    throw OdError(eNotImplemented);
    return; 
  }

  enum
  {
    kAllClasses = 0x01,
    kCustomClasses = 0x02,
    kProxyClasses = 0x04
  };

  virtual OdResult start(OdDbDatabase *pDb, int nFlags) = 0;

  virtual bool next() = 0;

  virtual bool done() const = 0;

  virtual void detach() = 0;

  virtual const OdChar *name() const = 0;

  virtual const OdChar *appName() const = 0;

  virtual const OdChar *dxfName() const = 0;

  virtual OdUInt32 numInstances() const = 0;

  virtual bool isProxy() const = 0;

  virtual bool isEntity() const = 0;

protected:
  OdDbClassIterator() {}
  ~OdDbClassIterator() {}
};