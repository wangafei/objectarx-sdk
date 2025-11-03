#ifndef _GCEDSEL_H
#define _GCEDSEL_H

#include "gcarray.h"
#include "dbid.h"
#include "dbsubeid.h"
#include "gcgitransient.h"
#pragma pack (push, 8)

class GcEdSelectedTransientImp;
class GcGsDCRect;

class GCED_DLL_DECL GcEdSolidSubentitySelector
{
public:
    GcEdSolidSubentitySelector();
    GcEdSolidSubentitySelector(const GCHAR* pQuickPrompt);
    ~GcEdSolidSubentitySelector();

    Gcad::ErrorStatus selectFaces(GcDbObjectId& selectedSolidId, 
        GcArray<GcDbSubentId *>& faceSet);
};

class GCED_DLL_DECL GcEdSelectedTransient
{
public:
    GcEdSelectedTransient();
    GcEdSelectedTransient(const GcEdSelectedTransient& source);
    GcEdSelectedTransient& operator=(const GcEdSelectedTransient& source);
    ~GcEdSelectedTransient();

    GcGiDrawable* parent();
    GcGiDrawable* drawable();
    Hccad::GsMarker marker();
    GcGiTransientDrawingMode mode();
    int subDrawingMode();

protected:
    GcEdSelectedTransientImp* mImp;
    friend class GcEdTransientSelectionInternals;
};

//This function returns all transients that draw any geometry inside the pickbox. 
Gcad::ErrorStatus GCED_DLL_DECL gcedSelectTransients(const GcGsDCRect& rect,
                                       int viewportNumber,
                                       GcArray<GcEdSelectedTransient>& result);


#pragma pack (pop)
#endif // _GCEDSEL_H
