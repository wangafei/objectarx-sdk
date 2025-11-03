/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GXPNT2D_H_
#define __GXPNT2D_H_

#include "gept2dar.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#pragma pack (push, 8)

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290)

class AXAUTOEXP GcAxPoint2d : public GcGePoint2d
{
public:
  GcAxPoint2d();
  GcAxPoint2d(double x, double y);
  GcAxPoint2d(const GcGePoint2d& pt);
  GcAxPoint2d(const GcGeVector2d& pt);
  GcAxPoint2d(const VARIANT* var) throw(HRESULT);
  GcAxPoint2d(const VARIANT& var) throw(HRESULT);
  GcAxPoint2d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  GcAxPoint2d& operator=(const GcGePoint2d& pt);
  GcAxPoint2d& operator=(const GcGeVector2d& pt);
  GcAxPoint2d& operator=(const VARIANT* var) throw(HRESULT);
  GcAxPoint2d& operator=(const VARIANT& var) throw(HRESULT);
  GcAxPoint2d& operator=(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  VARIANT*   asVariantPtr() const throw(HRESULT);
  SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

  VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
  VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
  GcAxPoint2d& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma warning(disable : 4275) 

class AXAUTOEXP GcAxPoint2dArray : public GcGePoint2dArray
{
public:
  GcAxPoint2dArray& append(const GcGePoint2d& pt);
  GcAxPoint2dArray& append(const VARIANT* var) throw(HRESULT);
  GcAxPoint2dArray& append(const VARIANT& var) throw(HRESULT);
  GcAxPoint2dArray& append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

  SAFEARRAY* asSafeArrayPtr() const throw(HRESULT);

  VARIANT& setVariant(VARIANT& var) const throw(HRESULT);
  VARIANT* setVariant(VARIANT* var) const throw(HRESULT);

private:
  GcAxPoint2dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) throw(HRESULT);
};

#pragma pack (pop)
#endif
