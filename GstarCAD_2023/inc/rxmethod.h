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
#include "rxmember.h"

class GcRxValue;
class GcRxMethodImp;
class GcRxMethodIteratorImp;

class GcRxMethod : public GcRxMember
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxMethod, GCBASE_PORT);
  GCBASE_PORT Gcad::ErrorStatus invoke(GcRxObject* pO, GcRxValue& param) const;
  GCBASE_PORT Gcad::ErrorStatus isExecutable(const GcRxObject* pO, const GcRxValue& param) const;

protected:
  GCBASE_PORT ~GcRxMethod();
  GCBASE_PORT GcRxMethod(const GCHAR* name, const GcRxValueType& type);

  virtual Gcad::ErrorStatus subInvoke(GcRxObject* pO, GcRxValue& param) const;
  virtual Gcad::ErrorStatus subIsExecutable(const GcRxObject* pO, const GcRxValue& param) const;

protected:
  friend class GcRxMethodImp;
  GCBASE_PORT GcRxMethod(GcRxMethodImp*);
};
