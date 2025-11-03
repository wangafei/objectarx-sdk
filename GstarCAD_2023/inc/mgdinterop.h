/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include <vcclr.h>
#include <gcroot.h>

class GcGeVector2d;
class GcGeVector3d;
class GcGeMatrix2d;
class GcGeMatrix3d;
class GcGePoint2d;
class GcGePoint3d;
class GcGeScale2d;
class GcGeScale3d;
class GcGeTol;
class GcDbObjectId;
class GcDbExtents;


namespace GrxCAD
{
  namespace Runtime
  {
#ifdef __cplusplus_cli
    ref class DisposableWrapper;
#else
    public __gc __abstract class DisposableWrapper;
#endif
  }
}

#ifdef __cplusplus_cli
#define GC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::operator System::IntPtr(x)).ToPointer())
#define GC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::operator GCHandle(System::IntPtr(x)))
#define GC_NULLPTR nullptr
#define GC_GCNEW gcnew
#define GC_WCHAR_PINNED_GCPTR pin_ptr<const wchar_t>
typedef GrxCAD::Runtime::DisposableWrapper^ DisposableWrapper_GcPtr;
typedef System::Type^ Type_GcPtr;
typedef System::String^ String_GcPtr;
#else
#define GC_GCHANDLE_TO_VOIDPTR(x) ((GCHandle::op_Explicit(x)).ToPointer())
#define GC_VOIDPTR_TO_GCHANDLE(x) (GCHandle::op_Explicit(x))
#define GC_NULLPTR 0
#define GC_GCNEW new
#define GC_WCHAR_PINNED_GCPTR const wchar_t __pin*
typedef GrxCAD::Runtime::DisposableWrapper* DisposableWrapper_GcPtr;
typedef System::Type* Type_GcPtr;
typedef System::String* String_GcPtr;
#endif

class GcMgObjectFactoryBase : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcMgObjectFactoryBase);
  virtual gcroot<DisposableWrapper_GcPtr> createRCW(GcRxObject* unmanagedPointer, bool autoDelete) = 0;
  virtual bool isManaged()
  {
    return false;
  }
  ~GcMgObjectFactoryBase() {}
  virtual gcroot<Type_GcPtr> getType() = 0;

};

template <typename RCW, typename ImpObj>
class GcMgObjectFactory : public GcMgObjectFactoryBase
{
public:
  gcroot<DisposableWrapper_GcPtr> createRCW(GcRxObject* unmanagedPointer, bool autoDelete)
  {
    gcroot<DisposableWrapper_GcPtr> temp = GC_GCNEW RCW(System::IntPtr(static_cast<ImpObj*>(unmanagedPointer)), autoDelete);
    return temp;
  }
  GcMgObjectFactory()
  {
    ImpObj::desc()->addX(GcMgObjectFactoryBase::desc(), this);
  }
  ~GcMgObjectFactory()
  {
    ImpObj::desc()->delX(GcMgObjectFactoryBase::desc());
  }
  gcroot<Type_GcPtr> getType() override
  {
#ifdef __cplusplus_cli
    return RCW::typeid;
#else
    return __typeof(RCW);
#endif
  }
};

class StringToWchar
{
  typedef System::Runtime::InteropServices::GCHandle GCHandle;

  const wchar_t* m_ptr;
  void* m_pinner;

public:

  StringToWchar(String_GcPtr str)
  {
    m_pinner = GC_GCHANDLE_TO_VOIDPTR(GCHandle::Alloc(str, System::Runtime::InteropServices::GCHandleType::Pinned));
    GC_WCHAR_PINNED_GCPTR tmp = PtrToStringChars(str);
    m_ptr = tmp;
  }
  ~StringToWchar()
  {
    GCHandle g = GC_VOIDPTR_TO_GCHANDLE(m_pinner);
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
  return GC_GCNEW System::String(value);
}

#undef GC_GCHANDLE_TO_VOIDPTR
#undef GC_VOIDPTR_TO_GCHANDLE
#undef GC_NULLPTR
#undef GC_GCNEW

#define StringToCIF StringToWchar
#define CIFToString WcharToString

#ifndef GCDBMGD

#define GETVECTOR3D(vec3d)  (*reinterpret_cast<GcGeVector3d*>(&(vec3d)))
#define GETVECTOR2D(vec2d)  (*reinterpret_cast<GcGeVector2d*>(&(vec2d)))
#define GETMATRIX3D(mat3d)  (*reinterpret_cast<GcGeMatrix3d*>(&(mat3d)))
#define GETMATRIX2D(mat2d)  (*reinterpret_cast<GcGeMatrix2d*>(&(mat2d)))
#define GETPOINT3D(point3d) (*reinterpret_cast<GcGePoint3d*>(&(point3d)))
#define GETPOINT2D(point2d) (*reinterpret_cast<GcGePoint2d*>(&(point2d)))
#define GETSCALE2D(scale2d) (*reinterpret_cast<GcGeScale2d*>(&(scale2d)))
#define GETSCALE3D(scale3d) (*reinterpret_cast<GcGeScale3d*>(&(scale3d)))
#define GETTOL(tol)         (*reinterpret_cast<GcGeTol*>(&(tol)))
#define GETOBJECTID(id)     (*reinterpret_cast<GcDbObjectId*>(&(id)))
#define GETEXTENTS3D(ext3d) (*reinterpret_cast<GcDbExtents*>(&(ext3d)))
#define GETSUBENTITYID(subentityId) (*reinterpret_cast<GcDbSubentId*>(&(subentityId)))

#ifdef GC_GEVEC3D_H
inline GrxCAD::Geometry::Vector3d ToVector3d(const GcGeVector3d& pt)
{
  GrxCAD::Geometry::Vector3d ret;
  GETVECTOR3D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GEVEC2D_H
inline GrxCAD::Geometry::Vector2d ToVector2d(const GcGeVector2d& pt)
{
  GrxCAD::Geometry::Vector2d ret;
  GETVECTOR2D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GEMAT2D_H
inline GrxCAD::Geometry::Matrix3d ToMatrix3d(const GcGeMatrix3d& pt)
{
  GrxCAD::Geometry::Matrix3d ret;
  GETMATRIX3D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GEMAT3D_H
inline GrxCAD::Geometry::Matrix2d ToMatrix2d(const GcGeMatrix2d& pt)
{
  GrxCAD::Geometry::Matrix2d ret;
  GETMATRIX2D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GEPNT3D_H
inline GrxCAD::Geometry::Point3d ToPoint3d(const GcGePoint3d& pt)
{
  GrxCAD::Geometry::Point3d ret;
  GETPOINT3D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GEPNT2D_H
inline GrxCAD::Geometry::Point2d ToPoint2d(const GcGePoint2d& pt)
{
  GrxCAD::Geometry::Point2d ret;
  GETPOINT2D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GESCL2D_H
inline GrxCAD::Geometry::Scale2d ToScale2d(const GcGeScale2d& pt)
{
  GrxCAD::Geometry::Scale2d ret;
  GETSCALE2D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GESCL3D_H
inline GrxCAD::Geometry::Scale3d ToScale3d(const GcGeScale3d& pt)
{
  GrxCAD::Geometry::Scale3d ret;
  GETSCALE3D(ret) = pt;
  return ret;
}
#endif

#ifdef GC_GETOL_H
inline GrxCAD::Geometry::Tolerance ToTolerance(const GcGeTol& pt)
{
  GrxCAD::Geometry::Tolerance ret;
  GETTOL(ret) = pt;
  return ret;
}
#endif

#ifdef _GD_DBID_H
inline GrxCAD::DatabaseServices::ObjectId ToObjectId(const GcDbObjectId& pt)
{
  GrxCAD::DatabaseServices::ObjectId ret;
  GETOBJECTID(ret) = pt;
  return ret;
}
#endif

#ifdef GD_DBMAIN_H
inline GrxCAD::DatabaseServices::Extents3d ToExtents3d(const GcDbExtents& pt)
{
  GrxCAD::DatabaseServices::Extents3d ret;
  GETEXTENTS3D(ret) = pt;
  return ret;
}
#endif

#endif
