/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef OFFSET_H
#include "Offset.h"
#endif

#ifndef SIZE_H
namespace Gtil { class Size; }
#endif

#ifndef POINT2D_H
namespace Gtil { class Point2d; }
#endif

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

namespace Gtil
{
  class GTIL_EXPORT BoundingBox
  {
  public:
    BoundingBox();
    BoundingBox(Offset origin, Size size);
    BoundingBox(Offset origin, Offset extent);
    BoundingBox(int nPoints, const Offset* aOffsets);
    ~BoundingBox();

    void set(Offset offset, Size size);
    void set(Offset origin, Offset extent);
    void set(int nPoints, const Offset* aOffsets);

    void expandToInclude(Offset offset);
    void expandToInclude(int nPoints, const Offset* aOffsets);

    void getExtents(Offset& origin, Offset& extent) const;

    Size size() const;

    Offset origin() const;

    bool inBounds(const Offset& offset) const;
    bool inBounds(int x, int y) const;

    Offset clipToBounds(const Offset& offset) const;

    bool contains(const BoundingBox& box) const;

    bool intersects(const BoundingBox& bbOther) const;

    bool getIntersection(const BoundingBox& bbOther, BoundingBox& bbIntersection) const;
    bool getIntersection(int nPoints, const Point2d* aPolygon, BoundingBox& bbIntersection) const;

    void getUnion(const BoundingBox& bbOther, BoundingBox& bbUnion) const;

  private:
    Offset mOrigin;
    Offset mExtent;
  };

}
#ifndef BOUNDINGBOX_INL
#include <BoundingBox.inl>
#endif

#endif
