

#ifndef __ZXPNT2D_H_
#define __ZXPNT2D_H_

#include "zgept2dar.h"
#include "zgepnt2d.h"
#include "zgevec2d.h"
#pragma pack (push, 8)

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
	#define ZXAUTOEXP __declspec(dllexport)
#else
	#define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290) 

class ZXAUTOEXP ZcAxPoint2d : public ZcGePoint2d
{
public:
    
    ZcAxPoint2d();
    ZcAxPoint2d(double x, double y);
    ZcAxPoint2d(const ZcGePoint2d& pt);
    ZcAxPoint2d(const ZcGeVector2d& pt);
    ZcAxPoint2d(const VARIANT* var) noexcept(false);
   	ZcAxPoint2d(const VARIANT& var) noexcept(false);
   	ZcAxPoint2d(const SAFEARRAY* safeArrayPt) noexcept(false);

   	ZcAxPoint2d& operator=(const ZcGePoint2d& pt);
   	ZcAxPoint2d& operator=(const ZcGeVector2d& pt);
   	ZcAxPoint2d& operator=(const VARIANT* var) noexcept(false);
   	ZcAxPoint2d& operator=(const VARIANT& var) noexcept(false);
   	ZcAxPoint2d& operator=(const SAFEARRAY* safeArrayPt) noexcept(false);

    VARIANT* asVariantPtr() const noexcept(false);
    SAFEARRAY* asSafeArrayPtr() const noexcept(false);

    VARIANT& setVariant(VARIANT& var) const noexcept(false);
    VARIANT* setVariant(VARIANT* var) const noexcept(false);

private:
    ZcAxPoint2d& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);
};

#pragma warning(disable : 4275) 

class ZXAUTOEXP ZcAxPoint2dArray : public ZcGePoint2dArray
{
public:
    
   	ZcAxPoint2dArray& append(const ZcGePoint2d& pt);
   	ZcAxPoint2dArray& append(const VARIANT* var) noexcept(false);
   	ZcAxPoint2dArray& append(const VARIANT& var) noexcept(false);
   	ZcAxPoint2dArray& append(const SAFEARRAY* safeArrayPt) noexcept(false);

    SAFEARRAY* asSafeArrayPtr() const noexcept(false);

    VARIANT& setVariant(VARIANT& var) const noexcept(false);
    VARIANT* setVariant(VARIANT* var) const noexcept(false);

private:
    ZcAxPoint2dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);
};

#pragma pack (pop)
#endif
