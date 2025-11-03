/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#if defined(GSFT_GCGEVECTOR2D_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCGEVECTOR2D_DEFINED
template<>
struct GcArrayItemCopierSelector<GcGeVector2d, false>
{
  typedef GcArrayMemCopyReallocator<GcGeVector2d> allocator;
};
#endif

#if defined(GSFT_GCGEVECTOR3D_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCGEVECTOR3D_DEFINED
template<>
struct GcArrayItemCopierSelector<GcGeVector3d, false>
{
  typedef GcArrayMemCopyReallocator<GcGeVector3d> allocator;
};
#endif

#if defined(GSFT_GCGEPOINT3D_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCGEPOINT3D_DEFINED
template<>
struct GcArrayItemCopierSelector<GcGePoint3d, false>
{
  typedef GcArrayMemCopyReallocator<GcGePoint3d> allocator;
};
#endif

#if defined(GSFT_GCGEPOINT2D_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCGEPOINT2D_DEFINED
template<>
struct GcArrayItemCopierSelector<GcGePoint2d, false>
{
  typedef GcArrayMemCopyReallocator<GcGePoint2d> allocator;
};
#endif

#if defined(GSFT_GCDBOBJECTID_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCDBOBJECTID_DEFINED
template<>
struct GcArrayItemCopierSelector<GcDbObjectId, false>
{
  typedef GcArrayMemCopyReallocator<GcDbObjectId> allocator;
};
#endif

#if defined(GSFT_GCCMENTITYCOLOR_DEFINED) && defined(GC_GCARRAY_H)
#undef GSFT_GCCMENTITYCOLOR_DEFINED
template<>
struct GcArrayItemCopierSelector<GcCmEntityColor, false>
{
  typedef GcArrayMemCopyReallocator<GcCmEntityColor> allocator;
};
#endif