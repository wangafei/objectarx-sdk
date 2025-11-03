
#ifndef ZGEOMENT_DBREGION_H
#define ZGEOMENT_DBREGION_H

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"

#pragma pack(push, 8)

class ZCDB_PORT ZcDbRegion: public  ZcDbEntity
{
public:
    ZcDbRegion();
    virtual ~ZcDbRegion();

    ZCDB_DECLARE_MEMBERS(ZcDbRegion);

    static
    Zcad::ErrorStatus createFromCurves(const ZcDbVoidPtrArray& curveSegments,
                                       ZcDbVoidPtrArray& regions);

    static
    Zcad::ErrorStatus createFromCurves(const ZcArray<ZcDbEntity*>& curveSegments, ZcArray<ZcDbRegion*>& regions);

    virtual Zcad::ErrorStatus getPerimeter(double&) const;
    virtual Zcad::ErrorStatus getArea(double& regionArea) const;

	virtual void*             ZSMBodyCopy(bool bDeepCopy = false) const; 
	virtual void const *      getLockedZSMBody();                        
	virtual void              unlockZSMBody();                           
	virtual void*             getLockedWritableZSMBody();                
	virtual void              commitWritableZSMBody();                   
	virtual Zcad::ErrorStatus setZSMBody(const void* modelerBody);       

    virtual Zcad::ErrorStatus getAreaProp(
                                 const ZcGePoint3d&  origin,
                                 const ZcGeVector3d& xAxis,
                                 const ZcGeVector3d& yAxis,
                                 double&             perimeter,
                                 double&             area,
                                 ZcGePoint2d&        centroid,
                                 double              momInertia[2],
                                 double&             prodInertia,
                                 double              prinMoments[2],
                                 ZcGeVector2d        prinAxes[2],
                                 double              radiiGyration[2],
                                 ZcGePoint2d&        extentsLow,
                                 ZcGePoint2d&        extentsHigh)const;

    virtual Zcad::ErrorStatus getPlane(ZcGePlane& regionPlane) const;

	virtual void	  dragStatus(const ZcDb::DragStat) override;

    virtual ZSoft::Boolean    isNull () const;
    virtual Zcad::ErrorStatus getNormal(ZcGeVector3d&) const;

    virtual ZcDbSubentId      internalSubentId      (void* ent) const;
    virtual void*             internalSubentPtr     (const ZcDbSubentId& id) const;

    virtual Zcad::ErrorStatus booleanOper(ZcDb::BoolOperType operation, ZcDbRegion* otherRegion);

    virtual ZSoft::UInt32 numChanges() const;

	virtual bool usesGraphicsCache();

    Zcad::ErrorStatus getPlane(ZcGePlane& plane, ZcDb::Planarity& type) const override;

protected:

    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif
