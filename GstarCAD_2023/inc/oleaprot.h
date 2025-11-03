/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef OLEAUTO_H
#define OLEAUTO_H
#include "gsoft.h"
#include "gcdbport.h"
#ifdef _GSOFT_WINDOWS_
#include "dbmain.h"
#pragma pack (push, 8)

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

class GSOFT_NO_VTABLE AXAUTOEXP GcAxOleLinkManager
{
public:
  virtual IUnknown*      GetIUnknown(GcDbObject* pObject) = 0;
  virtual Gsoft::Boolean SetIUnknown(GcDbObject* pObject, IUnknown* pUnknown) = 0;
  virtual IUnknown*      GetIUnknown(GcDbDatabase* pDatabase) = 0;
  virtual Gsoft::Boolean SetIUnknown(GcDbDatabase* pDatabase, IUnknown* pUnknown) = 0;

  virtual IDispatch*     GetDocIDispatch(GcDbDatabase* pDatabase) = 0;
  virtual Gsoft::Boolean SetDocIDispatch(GcDbDatabase* pDatabase, IDispatch* pDispatch) = 0;

  virtual IUnknown*      GetIUnknown(GcDbObject* pObject, const GcDbSubentId &id) = 0;
  virtual Gsoft::Boolean SetIUnknown(GcDbObject* pObject, const GcDbSubentId &id, IUnknown* pUnknown) = 0;
};

AXAUTOEXP GcAxOleLinkManager* GcAxGetOleLinkManager();

#pragma pack (pop)

#endif
#endif
