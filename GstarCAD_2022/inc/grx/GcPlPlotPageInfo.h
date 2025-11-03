#ifndef _GCPLPLOTPAGEINFO_H
#define _GCPLPLOTPAGEINFO_H


#include "gcplobject.h"

class GcPlPlotPageInfo : public GcPlObject
{
    GCPL_DECLARE_MEMBERS(GcPlPlotPageInfo);

public:
    GCPL_PORT GcPlPlotPageInfo();
    GCPL_PORT virtual ~GcPlPlotPageInfo();

    GCPL_PORT long entityCount() const;
    GCPL_PORT long rasterCount() const;
    GCPL_PORT long oleObjectCount() const;
    GCPL_PORT long gradientCount() const;
    GCPL_PORT long shadedViewportType() const;
};

#endif //_GCPLPLOTPAGEINFO_H