

#pragma once

#include "zdbmain.h"

#pragma pack (push, 4)

class ZCDBCORE2D_PORT ZSOFT_NO_VTABLE ZcDbClassIterator
{
  public:
    static ZcDbClassIterator *  newIterator();
    static void deleteIterator(ZcDbClassIterator *pIter);
    enum { kAllClasses = 0x01,
           kCustomClasses   = 0x02,
           kProxyClasses    = 0x04 };
    virtual Zcad::ErrorStatus start(ZcDbDatabase *pDb, int nFlags) = 0;
    virtual bool next() = 0;
    virtual bool done() const = 0;
    virtual void detach() = 0;
    virtual const ZTCHAR *name() const = 0;
    virtual const ZTCHAR *appName() const = 0;
    virtual const ZTCHAR *dxfName() const = 0;
    virtual ZSoft::UInt32 numInstances() const = 0;
    virtual bool isProxy() const = 0;
    virtual bool isEntity() const = 0;
  protected:
	ZcDbClassIterator();
	virtual ~ZcDbClassIterator();
};

#pragma pack (pop)

