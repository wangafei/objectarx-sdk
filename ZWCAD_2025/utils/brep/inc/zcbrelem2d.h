#ifndef ZC_BRELEM2D_H
#define ZC_BRELEM2D_H 1

#include "../../../inc/zadesk.h"
#include "../../../inc/zrxobject.h"
#include "../../../inc/zrxboiler.h"
#include "zcbrgbl.h"
#include "zcbrelem.h"


// forward class declarations
class ZcGeVector3d;
class ZcBrElement;
class ZcBrElement2dData;


class DllImpExp ZcBrElement2d : public ZcBrElement
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrElement2d);
    ZcBrElement2d();
    ZcBrElement2d(const ZcBrElement2d& src);
    ~ZcBrElement2d();
    
    // Assignment operator
    ZcBrElement2d&		operator =      (const ZcBrElement2d& src);

    // Queries & Initialisers
    ZcBr::ErrorStatus   set				(ZcBrElement2dData* data);
	ZcBr::ErrorStatus	get				(ZcBrElement2dData*& data) const;

    // Geometry (for stereolithography support)
    ZcBr::ErrorStatus   getNormal		(ZcGeVector3d& normal) const;
};


#endif

