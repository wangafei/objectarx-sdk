
#ifndef DB3DPROFILE_H_INCLUDE
#define DB3DPROFILE_H_INCLUDE

#include "DbSurface.h"
#include "DbGeomRef.h"

class OdDb3dProfileData;

#include "TD_PackPush.h"


class TOOLKIT_EXPORT OdDb3dProfile : public OdRxObject
{
public:

    ODRX_DECLARE_MEMBERS(OdDb3dProfile);

    OdDb3dProfile();

    OdDb3dProfile( OdDbEntity *pEntity );

    OdDb3dProfile( const OdDbFullSubentPath& faceSubentPath );

    OdDb3dProfile( const OdDbPathRef & pathRef);

    OdDb3dProfile( const OdDbVertexRef & vertexRef);

    OdDb3dProfile( const OdDb3dProfile& src );

    virtual ~OdDb3dProfile();

    virtual OdResult copyFrom ( const OdRxObject *src );

    OdDbEntity*  entity () const;

    OdResult getPathRef( OdDbPathRef &pathRef ) const;

    OdResult getVertexRef( OdDbVertexRef &vertexRef ) const;

    OdResult  convertProfile ( bool explodeMultiFaceRegions, bool convertSurfaceToEdges,
                                        bool nonPlanarOnly, bool outerLoopOnly,
                                        OdArray<OdDb3dProfile*>& convertedProfileArr ) const;

    static OdDb3dProfile* convertProfile(const OdArray<OdDbPathRef>&);
    
    OdResult set ( const OdDbPathRef &pathRef );

    OdResult set ( const OdDbVertexRef &vertexRef );

    OdResult set ( OdDbEntity *pEntity );

    bool  isClosed () const;

    bool  isPlanar () const;

    bool  isSubent () const;

    bool  isFace () const;

    bool  isEdge () const;

    bool  isValid () const;
    
    static OdResult mergeProfiles ( const OdArray<OdDb3dProfile*>& profileArr,
                                             bool mergeEdges, bool mergeCurves,
                                             OdArray<OdDb3dProfile*>& mergedProfileArr );
    
    OdDb3dProfile& operator = ( const OdDb3dProfile& src );

private:
    friend class OdDb3dProfileData;
    friend class OdDbLoftProfile;

    OdDb3dProfileData *mProfileData;
};


class TOOLKIT_EXPORT OdDbLoftProfile : public OdDb3dProfile
{
public:

    ODRX_DECLARE_MEMBERS(OdDbLoftProfile);

    OdDbLoftProfile ();

    OdDbLoftProfile ( OdDbEntity *pEntity );

    OdDbLoftProfile ( const OdDbPathRef & pathRef);

    OdDbLoftProfile ( const OdGePoint3d& pnt );

    OdDbLoftProfile ( const OdDbLoftProfile& src );

    virtual OdResult copyFrom ( const OdRxObject *src );
    
    OdInt16  continuity () const;

    void          setContinuity ( OdInt16 value );

    double        magnitude () const;

    void          setMagnitude ( double value );
    
    OdDbLoftProfile& operator = ( const OdDbLoftProfile& src );
    
    OdDbLoftProfile& operator = ( const OdDb3dProfile& src );
};

#include "TD_PackPop.h"
#endif // DB3DPROFILE_H_INCLUDE
