
#ifndef __MGDINTEROP_H__
#define __MGDINTEROP_H__

#include <vcclr.h>
#include <gcroot.h>

#include "../../inc/zmgdinterop.h"

#ifndef ACDBMGD
#define ACDBMGD		ZCDBMGD
#endif //#ifndef ACDBMGD

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AC_GCHANDLE_TO_VOIDPTR
#define AC_GCHANDLE_TO_VOIDPTR		ZC_GCHANDLE_TO_VOIDPTR
#endif //#ifndef AC_GCHANDLE_TO_VOIDPTR

#ifndef AC_GCNEW
#define AC_GCNEW		ZC_GCNEW
#endif //#ifndef AC_GCNEW

#ifndef AC_NULLPTR
#define AC_NULLPTR		ZC_NULLPTR
#endif //#ifndef AC_NULLPTR

#ifndef AC_VOIDPTR_TO_GCHANDLE
#define AC_VOIDPTR_TO_GCHANDLE		ZC_VOIDPTR_TO_GCHANDLE
#endif //#ifndef AC_VOIDPTR_TO_GCHANDLE

#ifndef AC_WCHAR_PINNED_GCPTR
#define AC_WCHAR_PINNED_GCPTR		ZC_WCHAR_PINNED_GCPTR
#endif //#ifndef AC_WCHAR_PINNED_GCPTR

#ifndef AcDbExtents
#define AcDbExtents		ZcDbExtents
#endif //#ifndef AcDbExtents

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef AcGeMatrix2d
#define AcGeMatrix2d		ZcGeMatrix2d
#endif //#ifndef AcGeMatrix2d

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcGePoint2d
#define AcGePoint2d		ZcGePoint2d
#endif //#ifndef AcGePoint2d

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeScale2d
#define AcGeScale2d		ZcGeScale2d
#endif //#ifndef AcGeScale2d

#ifndef AcGeScale3d
#define AcGeScale3d		ZcGeScale3d
#endif //#ifndef AcGeScale3d

#ifndef AcGeTol
#define AcGeTol		ZcGeTol
#endif //#ifndef AcGeTol

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcMgObjectFactory
#define AcMgObjectFactory		ZcMgObjectFactory
#endif //#ifndef AcMgObjectFactory

#ifndef AcMgObjectFactoryBase
#define AcMgObjectFactoryBase		ZcMgObjectFactoryBase
#endif //#ifndef AcMgObjectFactoryBase

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef AutoCAD
#define AutoCAD		ZwCAD
#endif //#ifndef AutoCAD

#ifndef Autodesk
#define Autodesk		ZwSoft
#endif //#ifndef Autodesk

#ifndef ADESK_OVERRIDE
#define ADESK_OVERRIDE		ZSOFT_OVERRIDE
#endif //#ifndef ADESK_OVERRIDE

#ifndef AC_GEVEC3D_H
#define AC_GEVEC3D_H		ZC_GEVEC3D_H
#endif //#ifndef AC_GEVEC3D_H

#ifndef AC_GEVEC2D_H
#define AC_GEVEC2D_H		ZC_GEVEC2D_H
#endif //#ifndef AC_GEVEC2D_H

#ifndef AC_GEMAT2D_H
#define AC_GEMAT2D_H		ZC_GEMAT2D_H
#endif //#ifndef AC_GEMAT2D_H

#ifndef AC_GEMAT3D_H
#define AC_GEMAT3D_H		ZC_GEMAT3D_H
#endif //#ifndef AC_GEMAT3D_H

#ifndef AC_GEPNT3D_H
#define AC_GEPNT3D_H		ZC_GEPNT3D_H
#endif //#ifndef AC_GEPNT3D_H

#ifndef AC_GEPNT2D_H
#define AC_GEPNT2D_H		ZC_GEPNT2D_H
#endif //#ifndef AC_GEPNT2D_H

#ifndef AC_GESCL2D_H
#define AC_GESCL2D_H		ZC_GESCL2D_H
#endif //#ifndef AC_GESCL2D_H

#ifndef AC_GESCL3D_H
#define AC_GESCL3D_H		ZC_GESCL3D_H
#endif //#ifndef AC_GESCL3D_H

#ifndef AC_GETOL_H
#define AC_GETOL_H		ZC_GETOL_H
#endif //#ifndef AC_GETOL_H

#endif //#ifndef __MGDINTEROP_H__
