

#ifndef _ZCEDSEL_H
#define _ZCEDSEL_H

#include "zacarray.h"
#include "zacadstrc.h"
#include "zacgitransient.h"
#include "zaccoredefs.h"

#pragma pack (push, 8)

class ZcDbObjectId;
class ZcDbSubentId;
class ZcEdSelectedTransientImp;
class ZcGsDCRect;
class ZCCORE_PORT ZcEdSolidSubentitySelector
{
public:
    ZcEdSolidSubentitySelector();
    ~ZcEdSolidSubentitySelector();

    Zcad::ErrorStatus selectFaces(ZcDbObjectId& selectedSolidId, 
        ZcArray<ZcDbSubentId *>& faceSet);
};

class ZCCORE_PORT ZcEdSelectedTransient
{
public:
    ZcEdSelectedTransient();
    ZcEdSelectedTransient(const ZcEdSelectedTransient& source);
    ZcEdSelectedTransient& operator=(const ZcEdSelectedTransient& source);
    ~ZcEdSelectedTransient();

    ZcGiDrawable* parent();
    ZcGiDrawable* drawable();
    ZSoft::GsMarker marker();
    ZcGiTransientDrawingMode mode();
    int subDrawingMode();

protected:
    ZcEdSelectedTransientImp* mImp;
    friend class ZcEdTransientSelectionInternals;
};

Zcad::ErrorStatus zcedSelectTransients(const ZcGsDCRect& rect,
                                       int viewportNumber,
                                       ZcArray<ZcEdSelectedTransient>& result);
#pragma pack (pop)
#endif 
