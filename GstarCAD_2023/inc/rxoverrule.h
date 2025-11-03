/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _RXOVERRULE_H
#define _RXOVERRULE_H

#include "gcbasedefs.h"
#include "rxobject.h"
#include "gcarray.h"

#pragma pack (push, 8)

class GcRxOverruleIteratorBase;

class GSOFT_NO_VTABLE GCBASE_PORT GcRxOverruleBase : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcRxOverruleBase);
private:
  mutable GcRxOverruleIteratorBase* m_pIter;
  friend class GcRxOverruleInternals;
};

#pragma warning( push )
#pragma warning( disable : 4275 )
class GCBASE_PORT GcRxOverrule : public GcRxOverruleBase
{
public:
  GCRX_DECLARE_MEMBERS(GcRxOverrule);
  ~GcRxOverrule();

  virtual bool isApplicable(const GcRxObject* pOverruledSubject) const = 0;

  static Gcad::ErrorStatus addOverrule(GcRxClass* pClass, GcRxOverrule* pOverrule, bool bAddAtLast = false);
  static Gcad::ErrorStatus removeOverrule(GcRxClass* pClass, GcRxOverrule* pOverrule);

  static void setIsOverruling(bool bIsOverruling);
  static bool isOverruling(void);
  static bool hasOverrule(const GcRxObject* pSubject, GcRxClass* pOverruleClass);
};

class GCBASE_PORT GcRxQueryXOverrule : public GcRxOverrule
{
public:
  GCRX_DECLARE_MEMBERS(GcRxQueryXOverrule);
  GcRxQueryXOverrule();

  virtual GcRxObject* queryX(const GcRxObject* pSubject, const GcRxClass* protocolClass) const;
};
#pragma warning( pop )

#pragma pack (pop)
#endif
