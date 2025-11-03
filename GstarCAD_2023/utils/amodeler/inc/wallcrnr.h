/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_WALLCRNR_H
#define GMODELER_INC_WALLCRNR_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

DllImpExp Body createWallCornerBody(
  const Point2d& pt1,
  const Point2d& pt2,
  const Point2d& pt3,
  bool           materialToTheLeft,
  double         width1,
  double         width2,
  double         height,
  Color          matingFacesColor,
  Plane&         matingPlane1,
  Plane&         matingPlane2,
  bool&          wall1NeedsToBeSectioned,
  bool&          wall2NeedsToBeSectioned);

GMODELER_NAMESPACE_END
#endif
