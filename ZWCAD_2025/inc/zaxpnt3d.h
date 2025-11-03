

#ifndef __ZXPNT3D_H_
#define __ZXPNT3D_H_

#include "zgept3dar.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#pragma pack (push, 8)

#ifndef ZXAUTOEXP
#ifdef ZXAUTO_DLL
	#define ZXAUTOEXP __declspec(dllexport)
#else
	#define ZXAUTOEXP __declspec(dllimport)
#endif
#endif

#pragma warning(disable : 4290) 

class ZXAUTOEXP ZcAxPoint3d : public ZcGePoint3d
{
public:
    
    ZcAxPoint3d();
    ZcAxPoint3d(double x, double y, double z);
    ZcAxPoint3d(const ZcGePoint3d& pt);
    ZcAxPoint3d(const ZcGeVector3d& pt);
   	ZcAxPoint3d(const VARIANT* var) noexcept(false);
   	ZcAxPoint3d(const VARIANT& var) noexcept(false);
   	ZcAxPoint3d(const SAFEARRAY* safeArrayPt) noexcept(false);

   	ZcAxPoint3d& operator=(const ZcGePoint3d& pt);
   	ZcAxPoint3d& operator=(const ZcGeVector3d& pt);
   	ZcAxPoint3d& operator=(const VARIANT* var) noexcept(false);
   	ZcAxPoint3d& operator=(const VARIANT& var) noexcept(false);
   	ZcAxPoint3d& operator=(const SAFEARRAY* safeArrayPt) noexcept(false);

    VARIANT* asVariantPtr() const noexcept(false);
    SAFEARRAY* asSafeArrayPtr() const noexcept(false);

    VARIANT& setVariant(VARIANT& var) const noexcept(false);
    VARIANT* setVariant(VARIANT* var) const noexcept(false);

private:
    ZcAxPoint3d& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);
};

#pragma warning(disable : 4275) 

class ZXAUTOEXP ZcAxPoint3dArray : public ZcGePoint3dArray
{
public:
    
   	ZcAxPoint3dArray& append(const ZcGePoint3d& pt);
   	ZcAxPoint3dArray& append(const VARIANT* var) noexcept(false);
   	ZcAxPoint3dArray& append(const VARIANT& var) noexcept(false);
   	ZcAxPoint3dArray& append(const SAFEARRAY* safeArrayPt) noexcept(false);

    SAFEARRAY* asSafeArrayPtr() const noexcept(false);

    VARIANT& setVariant(VARIANT& var) const noexcept(false);
    VARIANT* setVariant(VARIANT* var) const noexcept(false);

private:
    ZcAxPoint3dArray& fromSafeArray(const SAFEARRAY* safeArrayPt) noexcept(false);
};

#pragma pack (pop)
#endif
