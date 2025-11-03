

#pragma once
#ifndef ZDB3DPROFILE_H
#define ZDB3DPROFILE_H

#include "zdbsurf.h"
#include "zAcDbGeomRef.h"	

class ZcDb3dProfileData;

#pragma pack(push, 8)


class ZCDB_PORT ZcDb3dProfile : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDb3dProfile);
    ZcDb3dProfile ();
    ZcDb3dProfile ( ZcDbEntity *pEntity );
    ZcDb3dProfile ( const ZcDbFullSubentPath& faceSubentPath );
    ZcDb3dProfile ( const ZcDbPathRef & pathRef);
    ZcDb3dProfile ( const ZcDbVertexRef & vertexRef);
    ZcDb3dProfile ( const ZcDb3dProfile& src );
    virtual ~ZcDb3dProfile();
    virtual Zcad::ErrorStatus copyFrom ( const ZcRxObject *src ) override;
    ZcDbEntity*  entity () const;
    Zcad::ErrorStatus getPathRef( ZcDbPathRef &pathRef ) const;
    Zcad::ErrorStatus getVertexRef( ZcDbVertexRef &vertexRef ) const;

    Zcad::ErrorStatus  convertProfile ( bool explodeMultiFaceRegions, bool convertSurfaceToEdges,
                                        bool nonPlanarOnly, bool outerLoopOnly,
                                        ZcArray<ZcDb3dProfile*>& convertedProfileArr ) const;

    static ZcDb3dProfile* convertProfile(const ZcArray<ZcDbPathRef>&);

    Zcad::ErrorStatus set ( const ZcDbPathRef &pathRef );

    Zcad::ErrorStatus set ( const ZcDbVertexRef &vertexRef );

    Zcad::ErrorStatus set ( ZcDbEntity *pEntity );

    bool  isClosed () const;

    bool  isPlanar () const;

    bool  isSubent () const;

    bool  isFace () const;

    bool  isEdge () const;

    bool  isValid () const;

    static Zcad::ErrorStatus mergeProfiles ( const ZcArray<ZcDb3dProfile*>& profileArr,
                                             bool mergeEdges, bool mergeCurves,
                                             ZcArray<ZcDb3dProfile*>& mergedProfileArr );

    ZcDb3dProfile& operator = ( const ZcDb3dProfile& src );

private:
    friend class ZcDb3dProfileData;
    friend class ZcDbLoftProfile;

    ZcDb3dProfileData *mProfileData;
};


class ZCDB_PORT ZcDbLoftProfile : public ZcDb3dProfile
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbLoftProfile);
    ZcDbLoftProfile ();
    ZcDbLoftProfile ( ZcDbEntity *pEntity );
    ZcDbLoftProfile ( const ZcDbPathRef & pathRef);
    ZcDbLoftProfile ( const ZcGePoint3d& pnt );
    ZcDbLoftProfile ( const ZcDbLoftProfile& src );
    virtual Zcad::ErrorStatus copyFrom ( const ZcRxObject *src ) override;
    ZSoft::Int16  continuity () const;
    void          setContinuity ( ZSoft::Int16 value );
    double        magnitude () const;
    void          setMagnitude ( double value );
    ZcDbLoftProfile& operator = ( const ZcDbLoftProfile& src );
    ZcDbLoftProfile& operator = ( const ZcDb3dProfile& src );
};

#pragma pack(pop)
#endif 
