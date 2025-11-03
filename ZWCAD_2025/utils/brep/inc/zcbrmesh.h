#ifndef ZC_BRMESH_H
#define ZC_BRMESH_H 1

#include "../../../inc/zadesk.h"
#include "../../../inc/zrxobject.h"
#include "../../../inc/zrxboiler.h"
#include "zcbrment.h"


// forward class declarations
class ZcBrMeshEntity;


class DllImpExp ZcBrMesh : public ZcBrMeshEntity
{
public:
    ZCRX_DECLARE_MEMBERS(ZcBrMesh);
    virtual ~ZcBrMesh();

protected:
    ZcBrMesh();
    ZcBrMesh(const ZcBrMesh&);
    ZcBrMesh&           operator =      (const ZcBrMesh&);
};


#endif

