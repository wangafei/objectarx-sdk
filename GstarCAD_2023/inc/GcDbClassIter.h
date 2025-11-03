/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbmain.h"

#pragma pack (push, 4)

class GSOFT_NO_VTABLE GcDbClassIterator
{
public:
  GCDB_PORT static GcDbClassIterator * newIterator();
  GCDB_PORT static void deleteIterator(GcDbClassIterator *pIter);

  enum {
    kAllClasses = 0x01,
    kCustomClasses = 0x02,
    kProxyClasses = 0x04
  };

  virtual Gcad::ErrorStatus start(GcDbDatabase *pDb, int nFlags) = 0;
  virtual bool next() = 0;
  virtual bool done() const = 0;
  virtual void detach() = 0;

  virtual const GCHAR *name() const = 0;
  virtual const GCHAR *appName() const = 0;
  virtual const GCHAR *dxfName() const = 0;

  virtual Gsoft::UInt32 numInstances() const = 0;
  virtual bool isProxy() const = 0;
  virtual bool isEntity() const = 0;

protected:
  GcDbClassIterator();
  virtual ~GcDbClassIterator();
};

#pragma pack (pop)
