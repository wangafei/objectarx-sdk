#ifndef _GCPLPRECISIONENTRY_H
#define _GCPLPRECISIONENTRY_H


#include "GcPl.h"
#include "GcPlObject.h"

/////////////////////////////////////////////////////////////////////////////
// AcPlPrecisionEntry

class GcPlPrecisionEntry  : public GcPlObject
{
	GCPL_DECLARE_MEMBERS(GcPlPrecisionEntry);
    
public:
    GCPL_PORT GcPlPrecisionEntry();

    GCPL_PORT virtual ~GcPlPrecisionEntry();

    GCPL_PORT GcPlPrecisionEntry(const GcPlPrecisionEntry & src);

    GCPL_PORT GcPlPrecisionEntry& operator= (const GcPlPrecisionEntry &src);

    GCPL_PORT const GCHAR *     title() const;
    GCPL_PORT void              setTitle(const GCHAR * pTitle);

    GCPL_PORT const GCHAR *     description() const;
    GCPL_PORT void              setDescription(const GCHAR * pDescription);

    GCPL_PORT const GCHAR *     unitType() const;
    GCPL_PORT void              setUnitType(const GCHAR * pUnitType);

    GCPL_PORT const GCHAR *     unitScale() const;
    GCPL_PORT void              setUnitScale(const GCHAR * pUnitScale);

    GCPL_PORT const double      desiredPrecision() const;
    GCPL_PORT void              setDesiredPrecision(double dDesiredPrecision);

    GCPL_PORT const int         gradientResolution() const;
    GCPL_PORT void              setGradientResolution(int nGradientResolution);

    GCPL_PORT const int         colorResolution() const;
    GCPL_PORT void              setColorResolution(int nColorResolution);

    GCPL_PORT const int         monoResolution() const;
    GCPL_PORT void              setMonoResolution(int nMonoResolution);
};

#endif // _GCPLPRECISIONENTRY_H
