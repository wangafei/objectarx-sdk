/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GXMAT3D_H_
#define __GXMAT3D_H_

#include "gemat3d.h"
#pragma pack (push, 8)

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

class AXAUTOEXP GcAxMatrix3d : public GcGeMatrix3d
{
public:
  GcAxMatrix3d();
  GcAxMatrix3d(const VARIANT* var) throw(HRESULT);
  GcAxMatrix3d(const VARIANT& var) throw(HRESULT);
  GcAxMatrix3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  GcAxMatrix3d& operator=(const VARIANT* var) throw(HRESULT);
  GcAxMatrix3d& operator=(const VARIANT& var) throw(HRESULT);
  GcAxMatrix3d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);
private:
  GcAxMatrix3d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif
