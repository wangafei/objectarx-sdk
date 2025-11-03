/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcbasedefs.h"
#include "gsoft.h"
#include "gcadstrc.h"
#include "pimplapi.h"

class GcRxCategory : public GcRxMember
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxCategory, GCBASE_PORT);

  GCBASE_PORT GcRxCategory(const GCHAR* name, GcRxCategory* pOwner) throw();

  GCBASE_PORT Gcad::ErrorStatus    removeChild(GcRxCategory* pChildCategory);
  GCBASE_PORT GcRxCategory*        findDescendant(const GCHAR* name) const;
  GCBASE_PORT static GcRxCategory* rootCategory();
private:
  GCBASE_PORT ~GcRxCategory();
};

GCBASE_PORT Gcad::ErrorStatus gcdbGetLegacyCategoryId(const GcRxCategory* pCategory, int& legacyId);
GCBASE_PORT Gcad::ErrorStatus gcdbSetLegacyCategoryId(GcRxCategory* pCategory, int legacyId);
