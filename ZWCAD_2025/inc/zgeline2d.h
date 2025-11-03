

#ifndef ZC_GELINE2D_H
#define ZC_GELINE2D_H

#include "zgelent2d.h"
#pragma pack (push, 8)

class
ZcGeLine2d : public ZcGeLinearEnt2d
{
public:
    GE_DLLEXPIMPORT ZcGeLine2d();
    GE_DLLEXPIMPORT ZcGeLine2d(const ZcGeLine2d& line);
    GE_DLLEXPIMPORT ZcGeLine2d(const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeLine2d(const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    GE_DLLDATAEXIMP static const ZcGeLine2d kXAxis;
    GE_DLLDATAEXIMP static const ZcGeLine2d kYAxis;

    GE_DLLEXPIMPORT ZcGeLine2d& set (const ZcGePoint2d& pnt, const ZcGeVector2d& vec);
    GE_DLLEXPIMPORT ZcGeLine2d& set (const ZcGePoint2d& pnt1, const ZcGePoint2d& pnt2);

    GE_DLLEXPIMPORT ZcGeLine2d& operator = (const ZcGeLine2d& line);
};

#pragma pack (pop)
#endif
