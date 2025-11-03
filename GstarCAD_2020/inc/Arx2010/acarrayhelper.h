#pragma once

#if defined(ODDB_ODGEVECTOR2D_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODEVECTOR2D_DEFINED
template<>
struct AllocatorSelector<OdGeVector2d, false>
{
	typedef OdMemoryAllocator<OdGeVector2d> allocator;
};
#endif

#if defined(ODDB_ODGEVECTOR3D_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODGEVECTOR3D_DEFINED
template<>
struct AllocatorSelector<OdGeVector3d, false>
{
	typedef OdMemoryAllocator<OdGeVector3d> allocator;
};
#endif

#if defined(ODDB_ODEPOINT3D_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODGEPOINT3D_DEFINED
template<>
struct AllocatorSelector<OdGePoint3d, false>
{
	typedef OdMemoryAllocator<OdGePoint3d> allocator;
};
#endif

#if defined(ODDB_ODGEPOINT2D_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODGEPOINT2D_DEFINED
template<>
struct AllocatorSelector<OdGePoint2d, false>
{
	typedef OdMemoryAllocator<OdGePoint2d> allocator;
};
#endif

#if defined(ODDB_ODDBOBJECTID_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODDBOBJECTID_DEFINED
template<>
struct AllocatorSelector<OdDbObjectId, false>
{
	typedef OdMemoryAllocator<OdDbObjectId> allocator;
};
#endif

#if defined(ODDB_ODCMENTITYCOLOR_DEFINED) /*&& defined(OD_ODARRAY_H)*/
#undef ODDB_ODCMENTITYCOLOR_DEFINED
template<>
struct AllocatorSelector<OdCmEntityColor, false>
{
	typedef OdMemoryAllocator<OdCmEntityColor> allocator;
};
#endif