#ifndef _DBDYNAMICBLOCKPURGEPREVENTER__INCLUDED_
#define _DBDYNAMICBLOCKPURGEPREVENTER__INCLUDED_

#include "DbBlockRepresentationData.h"

class TOOLKIT_EXPORT OdDbDynamicBlockPurgePreventer : public OdDbBlockRepresentationData
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDynamicBlockPurgePreventer);
  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  OdDbDynamicBlockPurgePreventer();
};

typedef OdSmartPtr<OdDbDynamicBlockPurgePreventer> OdDbDynamicBlockPurgePreventerPtr;

#endif // _DBDYNAMICBLOCKPURGEPREVENTER__INCLUDED_
