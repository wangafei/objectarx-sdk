
#ifndef AECMODELER_INC_WALLCRNR_H
#define AECMODELER_INC_WALLCRNR_H


#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN

DllImpExp ZwBody ZwCreateWallCornerBody(
                    const ZwPoint2d& pt1,
                    const ZwPoint2d& pt2,
                    const ZwPoint2d& pt3,
                    bool           materialToTheLeft,
                    double         width1,
                    double         width2,
                    double         height,
                    ZwColor          matingFacesColor,
                    ZwPlane&         matingPlane1,
                    ZwPlane&         matingPlane2,
                    bool&          wall1NeedsToBeSectioned,
                    bool&          wall2NeedsToBeSectioned);

AECMODELER_NAMESPACE_END
#endif

