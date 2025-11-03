#ifndef ZACPLPRECISIONENTRY_H
#define ZACPLPRECISIONENTRY_H

#pragma once

#include "zAcPl.h"
#include "zAcPlObject.h"

class ZcPlPrecisionEntry  : public ZcPlObject
{
    ZCPL_DECLARE_MEMBERS(ZcPlPrecisionEntry)
public:
    ZCPL_PORT ZcPlPrecisionEntry();

    ZCPL_PORT virtual ~ZcPlPrecisionEntry();

    ZCPL_PORT ZcPlPrecisionEntry(const ZcPlPrecisionEntry & src);

    ZCPL_PORT ZcPlPrecisionEntry& operator= (const ZcPlPrecisionEntry &src);

    ZCPL_PORT const ZTCHAR *     title() const;
    ZCPL_PORT void              setTitle(const ZTCHAR * pTitle);

    ZCPL_PORT const ZTCHAR *     description() const;
    ZCPL_PORT void              setDescription(const ZTCHAR * pDescription);

    ZCPL_PORT const ZTCHAR *     unitType() const;
    ZCPL_PORT void              setUnitType(const ZTCHAR * pUnitType);

    ZCPL_PORT const ZTCHAR *     unitScale() const;
    ZCPL_PORT void              setUnitScale(const ZTCHAR * pUnitScale);

    ZCPL_PORT const double      desiredPrecision() const;
    ZCPL_PORT void              setDesiredPrecision(double dDesiredPrecision);

    ZCPL_PORT const int         gradientResolution() const;
    ZCPL_PORT void              setGradientResolution(int nGradientResolution);

    ZCPL_PORT const int         colorResolution() const;
    ZCPL_PORT void              setColorResolution(int nColorResolution);

    ZCPL_PORT const int         monoResolution() const;
    ZCPL_PORT void              setMonoResolution(int nMonoResolution);
};

#endif
