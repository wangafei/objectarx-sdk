/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcdb.h"
#include "dbeval.h"
#include "GcDbAssocGlobal.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocValueProviderPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocValueProviderPE);

  virtual bool canGetValue(const GcDbObject* pObject, const GcString& valueName) {
    GSOFT_UNREFED_PARAM(pObject);
    GSOFT_UNREFED_PARAM(valueName);
    return true;
  }

  virtual bool canSetValue(const GcDbObject* pObject, const GcString& valueName) {
    GSOFT_UNREFED_PARAM(pObject);
    GSOFT_UNREFED_PARAM(valueName);
    return false;
  }

  virtual Gcad::ErrorStatus getValue(const GcDbObject* pObject,
    const GcString&   valueName,
    GcDbEvalVariant&  value) = 0;

  virtual Gcad::ErrorStatus setValue(GcDbObject*            pObject,
    const GcString&        valueName,
    const GcDbEvalVariant& newValue)
  {
    GSOFT_UNREFED_PARAM(pObject);
    GSOFT_UNREFED_PARAM(valueName);
    GSOFT_UNREFED_PARAM(newValue);
    return Gcad::eNotHandled;
  }

  static Gcad::ErrorStatus getObjectValue(const GcDbObjectId&, const GcString& valueName, GcDbEvalVariant& value);
  static Gcad::ErrorStatus setObjectValue(const GcDbObjectId&, const GcString& valueName, const GcDbEvalVariant& value);
};

#pragma pack (pop)