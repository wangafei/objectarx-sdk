

#ifndef ZD_DBMLINE_H
#define ZD_DBMLINE_H

#include "zdbmain.h"
#include "zgevptar.h"

#pragma pack(push, 8)

struct Mline
{
    typedef ZSoft::Int8 MlineJustification;
    enum {
        kTop        = 0,
        kZero       = 1,
        kBottom     = 2
    };
    enum {
        kOpen         = 0,
        kClosed       = 1,
        kMerged       = 2
    };
};

class ZcGePlane;

class ZCDBCORE2D_PORT ZcDbMline: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbMline);
    ZcDbMline();
    virtual ~ZcDbMline();

    Zcad::ErrorStatus setStyle(const ZcDbObjectId &newStyleId);
    ZcDbObjectId      style() const;

    Zcad::ErrorStatus setJustification(Mline::MlineJustification newJust);
    Mline::MlineJustification justification() const;

    Zcad::ErrorStatus setScale(double newScale);
    double            scale() const;

    ZcGeVector3d      normal            () const;
    Zcad::ErrorStatus setNormal(const ZcGeVector3d & newNormal);

    Zcad::ErrorStatus appendSeg(const ZcGePoint3d& newVertex);
    Zcad::ErrorStatus removeLastSeg(ZcGePoint3d& lastVertex);

    Zcad::ErrorStatus moveVertexAt(int index, const ZcGePoint3d& newPosition);

    Zcad::ErrorStatus setClosedMline(bool closed);
    bool              closedMline() const;

    void              setSupressStartCaps(bool supressIt);
    bool              supressStartCaps() const;
    void              setSupressEndCaps(bool supressIt);
    bool              supressEndCaps() const;

    int               numVertices() const;
    int               element(const ZcGePoint3d & pt) const;
    ZcGePoint3d       vertexAt(int index) const;

    ZcGeVector3d      axisAt(int index) const;
    ZcGeVector3d      miterAt(int index) const;
    Zcad::ErrorStatus getParametersAt(int index,
                                      ZcGeVoidPointerArray& params) const;
    Zcad::ErrorStatus setParametersAt(int index,
                                            ZcGeVoidPointerArray& params);

    Zcad::ErrorStatus getClosestPointTo(
                         const ZcGePoint3d& givenPoint,
                         ZcGePoint3d& pointOnCurve,
                         bool extend,
                         bool excludeCaps = false) const;
    Zcad::ErrorStatus getClosestPointTo(
                         const ZcGePoint3d& givenPoint,
                         const ZcGeVector3d& normal,
                         ZcGePoint3d& pointOnCurve,
                         bool extend,
                         bool excludeCaps = false) const;

    void              getPlane(ZcGePlane&) const;

protected:
    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;	
};

#pragma pack(pop)

#endif
