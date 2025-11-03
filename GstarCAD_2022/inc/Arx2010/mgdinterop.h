#pragma once
#include <vcclr.h>
#include <gcroot.h>
///////////////////////////////////////////////////////////////////////////////
// Forward Declarations
//

// Unmanaged types
class AcGeVector2d;
class AcGeVector3d;
class AcGeMatrix2d;
class AcGeMatrix3d;
class AcGePoint2d;
class AcGePoint3d;
class AcGeScale2d;
class AcGeScale3d;
class AcGeTol;
class AcDbObjectId;
class AcDbExtents;

// Managed types
#if !defined Gscad
#define Gscad GrxCAD
#endif

using namespace System;

#define AcMgObjectFactoryBase   GcMgObjectFactoryBase
#define AcMgObjectFactory       GcMgObjectFactory

#include "../grx/mgdinterop.h"

#ifdef __cplusplus_cli
 #define AC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::operator System::IntPtr(x)).ToPointer())
 #define AC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::operator GCHandle(System::IntPtr(x)))
 #define AC_NULLPTR nullptr
 #define AC_GCNEW gcnew
 #define AC_WCHAR_PINNED_GCPTR pin_ptr<const wchar_t>
 typedef GrxCAD::Runtime::DisposableWrapper^ DisposableWrapper_GcPtr;
 typedef System::Type^ Type_GcPtr;
 typedef System::String^ String_GcPtr;
#else
 #define AC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::op_Explicit(x)).ToPointer())
 #define AC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::op_Explicit(x))
 #define AC_NULLPTR 0
 #define AC_GCNEW new
 #define AC_WCHAR_PINNED_GCPTR const wchar_t __pin*
 typedef GrxCAD::Runtime::DisposableWrapper* DisposableWrapper_GcPtr;
 typedef System::Type* Type_GcPtr;
 typedef System::String* String_GcPtr;
#endif

///////////////////////////////////////////////////////////////////////////////
// Data Marshalling
//

class StringToWchar
{
    typedef System::Runtime::InteropServices::GCHandle GCHandle;

    const wchar_t* m_ptr;
    void* m_pinner;
    
public:

    StringToWchar(String_GcPtr str)
    {
        //pin the string
        m_pinner = AC_GCHANDLE_TO_VOIDPTR(
            GCHandle::Alloc(str,System::Runtime::InteropServices::GCHandleType::Pinned)
            );
        AC_WCHAR_PINNED_GCPTR tmp = PtrToStringChars(str);
        m_ptr = tmp;
    }
    ~StringToWchar()
    {
   		GCHandle g = AC_VOIDPTR_TO_GCHANDLE(m_pinner);
      g.Free();
      m_pinner = 0;
    }
    operator const wchar_t*()
    {
        return m_ptr;
    }
}; 
inline String_GcPtr WcharToString(const wchar_t* value)
{
    return AC_GCNEW System::String(value);
}

#undef AC_GCHANDLE_TO_VOIDPTR
#undef AC_VOIDPTR_TO_GCHANDLE
#undef AC_NULLPTR
#undef AC_GCNEW


//these defines make legacy clients happy
#define StringToCIF StringToWchar
#define CIFToString WcharToString

#ifndef ACDBMGD

#define GETVECTOR3D(vec3d)  (*reinterpret_cast<AcGeVector3d*>(&(vec3d)))
#define GETVECTOR2D(vec2d)  (*reinterpret_cast<AcGeVector2d*>(&(vec2d)))
#define GETMATRIX3D(mat3d)  (*reinterpret_cast<AcGeMatrix3d*>(&(mat3d)))
#define GETMATRIX2D(mat2d)  (*reinterpret_cast<AcGeMatrix2d*>(&(mat2d)))
#define GETPOINT3D(point3d) (*reinterpret_cast<AcGePoint3d*>(&(point3d)))
#define GETPOINT2D(point2d) (*reinterpret_cast<AcGePoint2d*>(&(point2d)))
#define GETSCALE2D(scale2d) (*reinterpret_cast<AcGeScale2d*>(&(scale2d)))
#define GETSCALE3D(scale3d) (*reinterpret_cast<AcGeScale3d*>(&(scale3d)))
#define GETTOL(tol)         (*reinterpret_cast<AcGeTol*>(&(tol)))
#define GETOBJECTID(id)     (*reinterpret_cast<AcDbObjectId*>(&(id)))
#define GETEXTENTS3D(ext3d) (*reinterpret_cast<AcDbExtents*>(&(ext3d)))
#define GETSUBENTITYID(subentityId) (*reinterpret_cast<AcDbSubentId*>(&(subentityId)))

#ifndef AC_GEVEC3D_H
#define AC_GEVEC3D_H OD_GEVEC3D_H
#endif
#ifndef AC_GEVEC2D_H
#define AC_GEVEC2D_H OD_GEVEC2D_H
#endif
#ifndef AC_GEMAT3D_H
#define AC_GEMAT3D_H OD_GE_MATRIX_3D_H
#endif
#ifndef AC_GEMAT2D_H
#define AC_GEMAT2D_H OD_GE_MATRIX_2D_H
#endif
#ifndef AC_GEPNT3D_H
#define AC_GEPNT3D_H OD_GEPNT3D_H
#endif
#ifndef AC_GEPNT2D_H
#define AC_GEPNT2D_H OD_GEPNT2D_H
#endif
#ifndef AC_GESCL2D_H
#define AC_GESCL2D_H OD_GESCL2D_H
#endif
#ifndef AC_GESCL3D_H
#define AC_GESCL3D_H OD_GESCL3D_H
#endif
#ifndef AC_GETOL_H
#define AC_GETOL_H OD_GETOL_H
#endif
#ifndef AD_DBID_H
#define AD_DBID_H _ODDBOBJECTID_INCLUDED_
#endif
#ifndef AD_DBEXTENTS_H
#define AD_DBEXTENTS_H _ODDBENTITY_INCLUDED_
#endif


#ifdef AC_GEVEC3D_H
inline GrxCAD::Geometry::Vector3d ToVector3d(const AcGeVector3d& pt)
{
    GrxCAD::Geometry::Vector3d ret;
    GETVECTOR3D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GEVEC2D_H
inline GrxCAD::Geometry::Vector2d ToVector2d(const AcGeVector2d& pt)
{
    GrxCAD::Geometry::Vector2d ret;
    GETVECTOR2D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GEMAT3D_H
inline GrxCAD::Geometry::Matrix3d ToMatrix3d(const AcGeMatrix3d& pt)
{
    GrxCAD::Geometry::Matrix3d ret;
    GETMATRIX3D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GEMAT2D_H
inline GrxCAD::Geometry::Matrix2d ToMatrix2d(const AcGeMatrix2d& pt)
{
    GrxCAD::Geometry::Matrix2d ret;
    GETMATRIX2D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GEPNT3D_H
inline GrxCAD::Geometry::Point3d ToPoint3d(const AcGePoint3d& pt)
{
    GrxCAD::Geometry::Point3d ret;
    GETPOINT3D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GEPNT2D_H
inline GrxCAD::Geometry::Point2d ToPoint2d(const AcGePoint2d& pt)
{
    GrxCAD::Geometry::Point2d ret;
    GETPOINT2D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GESCL2D_H
inline GrxCAD::Geometry::Scale2d ToScale2d(const AcGeScale2d& pt)
{
    GrxCAD::Geometry::Scale2d ret;
    GETSCALE2D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GESCL3D_H
inline GrxCAD::Geometry::Scale3d ToScale3d(const AcGeScale3d& pt)
{
    GrxCAD::Geometry::Scale3d ret;
    GETSCALE3D(ret) = pt;
    return ret;
}
#endif

#ifdef AC_GETOL_H
inline GrxCAD::Geometry::Tolerance ToTolerance(const AcGeTol& pt)
{
    GrxCAD::Geometry::Tolerance ret;
    GETTOL(ret) = pt;
    return ret;
}
#endif

#ifdef AD_DBID_H
inline GrxCAD::DatabaseServices::ObjectId ToObjectId(const AcDbObjectId& pt)
{
    GrxCAD::DatabaseServices::ObjectId ret;
    GETOBJECTID(ret) = pt;
    return ret;
}
#endif

#ifdef AD_DBEXTENTS_H
inline GrxCAD::DatabaseServices::Extents3d ToExtents3d(const AcDbExtents& pt)
{
    GrxCAD::DatabaseServices::Extents3d ret;
    GETEXTENTS3D(ret) = pt;
    return ret;
}
#endif

#endif // #ifndef ACDBMGD
