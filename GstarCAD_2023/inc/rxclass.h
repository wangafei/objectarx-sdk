/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcbasedefs.h"
#include "rxobject.h"
#include "GdGChar.h"
#include "gcbasedefs.h" 
#pragma pack (push, 8)

class GcRxMemberCollection;
class GcRxAttributeCollection;
class GcRxSet;
class GcRxImpClass;
class GcRxMemberCollectionBuilder;
typedef void(*GcRxMemberCollectionConstructorPtr)(GcRxMemberCollectionBuilder&, void*);

class GCBASE_PORT GcRxClass : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxClass);

  GcRxObject* addX(GcRxClass*, GcRxObject*);
  GcRxObject* getX(const GcRxClass*);
  GcRxObject* delX(GcRxClass*);
  GcRxObject* queryX(const GcRxClass*);

  GcRxObject*  create();
  const GCHAR* appName() const;
  const GCHAR* dxfName() const;
  const GCHAR* name() const;
  void         getClassVersion(int& dwgVer, int& maintVer) const;
  int          proxyFlags() const;

  bool        isDerivedFrom(const GcRxClass*) const;
  static bool isDerivedFrom(const GcRxClass *pDerived, const GcRxClass* pBase);

  GcRxClass*     myParent() const;
  GcRx::Ordering comparedTo(const GcRxObject*) const override;

  AppNameChangeFuncPtr appNameCallbackPtr() const;

  const GcRxSet* descendants() const;
  GcRxMemberCollection* members() const;
  const GcRxAttributeCollection& attributes() const;
  GcRxAttributeCollection&       attributes();
protected:
  GcRxClass(const GCHAR* name, const GCHAR* parent, GcRxMemberCollectionConstructorPtr memberConstruct, void* userData);
  ~GcRxClass();
private:
  void isKindOf(void *);
  GcRxClass();
  friend class GcRxImpClass;
  GcRxImpClass* m_pImp;
  GcRxClass(const GcRxClass &) = delete;
  GcRxClass operator = (const GcRxClass &) = delete;
};

GCBASE_PORT GcRxClass* newGcRxClass(
  const GCHAR* className,
  const GCHAR* parentClassName,
  int          proxyFlags = 0,
  GcRxObject* (*pseudoConstructor)() = NULL,
  const GCHAR* dxfName = NULL,
  const GCHAR* appName = NULL);

GCBASE_PORT GcRxClass* newGcRxClass(
  const GCHAR* className,
  const GCHAR* parentClassName,
  int          dwgVer,
  int          maintVer,
  int          proxyFlags = 0,
  GcRxObject* (*pseudoConstructor)() = NULL,
  const GCHAR* dxfName = NULL,
  const GCHAR* appName = NULL,
  AppNameChangeFuncPtr func = NULL);

GCBASE_PORT GcRxClass* newGcRxClass(
  const GCHAR* className,
  const GCHAR* parentClassName,
  int          dwgVer,
  int          maintVer,
  int          proxyFlags,
  GcRxObject* (*pseudoConstructor)(),
  const GCHAR* dxfName,
  const GCHAR* appName,
  AppNameChangeFuncPtr func,
  GcRxMemberCollectionConstructorPtr makeMembers,
  void*        userData = NULL);

GCBASE_PORT void gcrxBuildClassHierarchy();

GCBASE_PORT void deleteGcRxClass(GcRxClass* pClassObj);

inline bool GcRxClass::isDerivedFrom(const GcRxClass* pOtherClass) const
{
  return GcRxClass::isDerivedFrom(this, pOtherClass);
}

inline bool GcRxObject::isKindOf(const GcRxClass* pOtherClass) const
{
  return GcRxClass::isDerivedFrom(this->isA(), pOtherClass);
}

typedef void(*RxInitFuncPtr)();
GCBASE_PORT GcRxClass* gcrxQueueClassForInitialization(GcRxClass** pgpDesc, RxInitFuncPtr rxInit);
#pragma pack (pop)
