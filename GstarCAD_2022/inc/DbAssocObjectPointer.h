#pragma once
#include "DbAssocAction.h"

template<class ODDB_CLASS> class OdDbAssocObjectPointer
{
public:

  OdDbAssocObjectPointer(OdDbAssocAction*               pActionBeingEvaluated,
    OdDbObjectId                   objectId,
    OdDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  OdDbAssocObjectPointer(const OdDbAssocActionBody*     pActionBodyBeingEvaluated,
    OdDbObjectId                   objectId,
    OdDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  OdDbAssocObjectPointer(const OdDbAssocDependency*     pDependencyBeingEvaluated,
    OdDbObjectId                   objectId,
    OdDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  OdDbAssocObjectPointer(const OdDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
    OdDbObjectId                   objectId,
    OdDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  OdDbAssocObjectPointer(OdDbAssocAction*               pActionBeingEvaluated,
    ODDB_CLASS*                    pObject);

  OdDbAssocObjectPointer(const OdDbAssocActionBody*     pActionBodyBeingEvaluated,
    ODDB_CLASS*                    pObject);

  ~OdDbAssocObjectPointer();

  OdResult openStatus() const;

  bool isSubstituteObject() const
  {
    throw OdError(eNotImplemented);
    return false;
  }

  const ODDB_CLASS* operator->() const
  {
    throw OdError(eNotImplemented);
    return NULL;
  }

  ODDB_CLASS* operator->()
  {
    throw OdError(eNotImplemented);
    return NULL;
  }

  operator const ODDB_CLASS*() const
  {
    throw OdError(eNotImplemented);
    return NULL;
  }

  operator ODDB_CLASS*()
  {
    throw OdError(eNotImplemented);
    return NULL; 
  }
};