/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GXPNT3D_H_
#define __GXPNT3D_H_

#include "gept3dar.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#pragma pack (push, 8)

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290) 

class AXAUTOEXP GcAxPoint3d : public GcGePoint3d
{
public:
  GcAxPoint3d();
  GcAxPoint3d(double x, double y, double z);
  GcAxPoint3d(const GcGePoint3d& pt);
  GcAxPoint3d(const GcGeVector3d& pt);
  GcAxPoint3d(const VARIANT* var) throw(HRESULT);
  GcAxPoint3d(const VARIANT& var) throw(HRESULT);
  GcAxPoint3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  GcAxPoint3d& operator=(const GcGePoint3d& pt);
  GcAxPoint3d& operator=(const GcGeVector3d& pt);
  GcAxPoint3d& operator=(const VARIANT* var) throw(HRESULT);
  GcAxPoint3d& operator=(const VARIANT& var) throw(HRESULT);
  GcAxPoint3d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  VARIANT*   asVariantPtr() const throw(HRESULT);
  SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

  VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
  VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
  GcAxPoint3d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma warning(disable : 4275) 

class AXAUTOEXP GcAxPoint3dArray : public GcGePoint3dArray
{
public:
  GcAxPoint3dArray& append(const GcGePoint3d& pt);
  GcAxPoint3dArray& append(const VARIANT* var) throw(HRESULT);
  GcAxPoint3dArray& append(const VARIANT& var) throw(HRESULT);
  GcAxPoint3dArray& append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

  VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
  VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
  GcAxPoint3dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif
