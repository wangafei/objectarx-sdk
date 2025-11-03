/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "rxdefs.h"
#include "gcadstrc.h"

#pragma pack (push, 8)

class GcRxProtocolReactor;
class GcRxProtocolReactorIterator;
class GcRxProtocolReactorList;
class GcRxProtocolReactorListIterator;
class GcRxProtocolReactorManager;
class GcRxProtocolReactorManagerFactory;

class GCBASE_PORT GSOFT_NO_VTABLE GcRxProtocolReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactor);
};

class GSOFT_NO_VTABLE GcRxProtocolReactorIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactorIterator);
  virtual GcRxClass* reactorClass() const = 0;

  virtual void start() = 0;
  virtual bool next() = 0;
  virtual bool done() const = 0;

  virtual GcRxProtocolReactor* object() const = 0;
};

class GSOFT_NO_VTABLE GcRxProtocolReactorList : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactorList);
  virtual GcRxClass* reactorClass() const = 0;

  virtual Gcad::ErrorStatus addReactor(GcRxProtocolReactor* pReactor) = 0;
  virtual void              removeReactor(GcRxProtocolReactor* pReactor) = 0;

  virtual GcRxProtocolReactorIterator* newIterator() const = 0;
};

class GSOFT_NO_VTABLE GcRxProtocolReactorListIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactorListIterator);

  virtual void start() = 0;
  virtual bool next() = 0;
  virtual bool done() const = 0;
  virtual GcRxProtocolReactorList* object() const = 0;
};

class GSOFT_NO_VTABLE GCBASE_PORT GcRxProtocolReactorManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactorManager);

  virtual GcRxProtocolReactorList*         createReactorList(GcRxClass* pReactorClass) = 0;
  virtual GcRxProtocolReactorListIterator* newIterator() const = 0;
};

class GSOFT_NO_VTABLE GCBASE_PORT GcRxProtocolReactorManagerFactory : public GcRxService
{
public:
  GCRX_DECLARE_MEMBERS(GcRxProtocolReactorManagerFactory);
  virtual GcRxProtocolReactorManager* createReactorManager(GcRxClass* pRxClass) const = 0;
};

#define gcrxProtocolReactors \
GcRxProtocolReactorManagerFactory::cast(gcrxServiceDictionary-> \
                                        at(GCRX_PROTOCOL_REACTOR_MANAGER))

#define GCRX_PROTOCOL_REACTOR_MANAGER_AT(gcrxClass) \
gcrxProtocolReactors->createReactorManager(gcrxClass)

#define GCRX_PROTOCOL_REACTOR_LIST_AT(gcrxClass, reactorClass) \
    GCRX_PROTOCOL_REACTOR_MANAGER_AT(gcrxClass)->createReactorList(reactorClass)

#pragma pack (pop)
