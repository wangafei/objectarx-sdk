/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_RXOBJECT_H
#define GD_RXOBJECT_H 1

#include "gcbasedefs.h"
#include "gsoft.h"
#include "rxdefs.h"
#include "rxboiler.h"
#include "gcadstrc.h"
#include "gcdbport.h"
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

class GCBASE_PORT GSOFT_NO_VTABLE GcRxObject
{
public:
  static const wchar_t* className() { return L"GcRxObject"; }
  virtual ~GcRxObject();

  static GcRxClass*         desc();
  static GcRxObject *       cast(const GcRxObject * inPtr)
  {
    return const_cast<GcRxObject *>(inPtr);
  }

  inline bool               isKindOf(const GcRxClass * gClass) const;
  GcRxObject*               queryX(const GcRxClass* protocolClass) const;
  GcRxObject*               x(const GcRxClass* protocolClass) const;
  virtual GcRxClass*        isA() const;
  virtual GcRxObject*       clone() const;
  virtual Gcad::ErrorStatus copyFrom(const GcRxObject* other);
  virtual bool              isEqualTo(const GcRxObject * other) const;
  virtual GcRx::Ordering    comparedTo(const GcRxObject * other) const;

protected:
  friend class              GcRxQueryXOverrule;
  virtual GcRxObject*       subQueryX(const GcRxClass* protocolClass) const;

  GcRxObject();
};

inline GcRxObject::~GcRxObject()
{
}

#pragma pack (pop)

#include "rxclass.h"

#define GCRX_PE_PTR(RxObj,PEClass) PEClass::cast(RxObj-> \
                                            queryX(PEClass::desc()))

#define GCRX_X_CALL(RxObj,PEClass) PEClass::cast(RxObj->x(PEClass::desc()))

#include "rxdict.h"

#endif
