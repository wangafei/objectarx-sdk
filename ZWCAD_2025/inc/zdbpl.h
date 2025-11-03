
#pragma once
#ifndef ZD_DBPL_H
#define ZD_DBPL_H 1

#include "zdbmain.h"
#include "zdbcurve.h"

#include "zgelnsg2d.h"
#include "zgelnsg3d.h"
#include "zgearc2d.h"
#include "zgearc3d.h"
#include "zgept2dar.h"
#include "zdbboiler.h"

#pragma pack(push, 8)

class ZcDb2dPolyline;

class ZCDBCORE2D_PORT ZcDbPolyline : public ZcDbCurve
{

public:
                      ZcDbPolyline();
                      ZcDbPolyline(unsigned int num_verts);
    virtual          ~ZcDbPolyline();

    ZCDB_DECLARE_MEMBERS(ZcDbPolyline);

    virtual Zcad::ErrorStatus convertFrom(ZcDbEntity*& pPline, 
                                  ZSoft::Boolean transferId = ZSoft::kTrue);
    Zcad::ErrorStatus convertTo(ZcDb2dPolyline*&  pPline,
                                ZSoft::Boolean transferId = ZSoft::kTrue) const;

    Zcad::ErrorStatus getPointAt(unsigned int, ZcGePoint3d& pt) const;

    enum SegType {
        kLine,
        kArc,
        kCoincident,
        kPoint,
        kEmpty
    };

    SegType           segType           (unsigned int index) const;

    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg2d& ln) const;
    Zcad::ErrorStatus getLineSegAt      (unsigned int index,
                                         ZcGeLineSeg3d& ln) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc2d& arc) const;
    Zcad::ErrorStatus getArcSegAt       (unsigned int index,
                                         ZcGeCircArc3d& arc) const;
    virtual ZSoft::Boolean onSegAt      (unsigned int index, const ZcGePoint2d& pt2d,
                                         double& param) const;

    virtual void              setClosed       (ZSoft::Boolean);
    void		              setPlinegen     (ZSoft::Boolean);
    virtual void			  setElevation    (double);
	virtual	Zcad::ErrorStatus setThickness    (double);
	virtual	Zcad::ErrorStatus setConstantWidth(double);
	virtual	Zcad::ErrorStatus setNormal       (const ZcGeVector3d&);

    ZSoft::Boolean    isOnlyLines     ()                        const;
    ZSoft::Boolean    hasPlinegen     ()                        const;
    double            elevation       ()                        const;
    double            thickness       ()                        const;
    Zcad::ErrorStatus getConstantWidth(double&)                 const;
    ZcGeVector3d      normal          ()                        const;

    virtual Zcad::ErrorStatus addVertexAt     (unsigned int index,
                                       const ZcGePoint2d& pt,
                                       double bulge = 0.,
                                       double startWidth = -1.,
                                       double endWidth = -1.,
                                       ZSoft::Int32 vertexIdentifier = 0);

    virtual Zcad::ErrorStatus removeVertexAt  (unsigned int index);

    unsigned int      numVerts        ()                        const;

    Zcad::ErrorStatus getPointAt        (unsigned int index,
                                       ZcGePoint2d& pt)         const;
    Zcad::ErrorStatus getBulgeAt      (unsigned int index,
                                       double&      bulge)      const;
    Zcad::ErrorStatus getVertexIdentifierAt(unsigned int index,
                                            ZSoft::Int32& vertexIdentifier) const;
    Zcad::ErrorStatus getWidthsAt     (unsigned int index,
                                       double&      startWidth,
                                       double&      endWidth)   const;

   virtual Zcad::ErrorStatus setPointAt(unsigned int index,
                                       const ZcGePoint2d& pt);
   virtual Zcad::ErrorStatus setBulgeAt(unsigned int index,
                                       double       bulge);
   virtual Zcad::ErrorStatus setVertexIdentifierAt (unsigned int index, ZSoft::Int32 suggestedValue);
   virtual Zcad::ErrorStatus setWidthsAt     (unsigned int index,
                                       double       startWidth,
                                       double       endWidth);

    Zcad::ErrorStatus minimizeMemory  ();
    Zcad::ErrorStatus maximizeMemory  ();

    virtual void              reset           (ZSoft::Boolean reuse,
                                       unsigned int numVerts);

    ZSoft::Boolean     hasBulges       ()        const;
    ZSoft::Boolean     hasVertexIdentifiers()    const;
    ZSoft::Boolean     hasWidth        ()        const;
	
	 Zcad::ErrorStatus makeClosedIfStartAndEndVertexCoincide(double distTol);

	DBCURVE_METHODS

    virtual void              getEcs(ZcGeMatrix3d& retVal) const override;

    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* filer,
                                               ZcRxClass*    classobj) override;
    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;

    virtual void              saveAs(ZcGiWorldDraw* mode,
                                     ZcDb::SaveType st) override;

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline ZSoft::Boolean ZcDbPolyline::isPlanar() const
{
    return ZSoft::kTrue;
}

inline Zcad::ErrorStatus ZcDbPolyline::getStartParam(double& startParam) const
{
    startParam = 0.;
    return Zcad::eOk;
}

inline Zcad::ErrorStatus ZcDbPolyline::getSpline(ZcDbSpline*& spline) const
{
    ZSOFT_UNREFED_PARAM(spline);
    return Zcad::eNotApplicable;
}

#pragma pack(pop)

#endif 
