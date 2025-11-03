

#ifndef ZDBFCF_H
#define ZDBFCF_H

#include "zdbmain.h"
#include "zAcDbCore2dDefs.h"	
#pragma pack(push, 8)

class ZCDBCORE2D_PORT ZcDbFcf: public  ZcDbEntity
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbFcf);
                              ZcDbFcf();
                              ZcDbFcf(const ZTCHAR *, const ZcGePoint3d&,
                              const ZcGeVector3d&, const ZcGeVector3d&);
    virtual ~ZcDbFcf();

    enum whichLine {kAll = -1};
    virtual void              setText          (const ZTCHAR *);
	virtual Zcad::ErrorStatus text(ZcString & sText, int lineNo = kAll) const;	
    virtual ZTCHAR *           text             (int lineNo = kAll) const final;
    virtual void              setLocation      (const ZcGePoint3d&);
    virtual ZcGePoint3d       location         () const;
    virtual void              setOrientation   (const ZcGeVector3d& norm,
                                                const ZcGeVector3d& dir);
    virtual ZcGeVector3d normal()    const;
    virtual ZcGeVector3d direction() const;
    
    virtual void getBoundingPoints(ZcGePoint3dArray&) const;
    virtual void getBoundingPline(ZcGePoint3dArray&)  const;
    
    virtual void              setDimensionStyle(ZcDbHardPointerId);
    virtual ZcDbHardPointerId dimensionStyle() const;
    
    Zcad::ErrorStatus   getDimstyleData(ZcDbDimStyleTableRecord*& pRecord) const;
    Zcad::ErrorStatus   setDimstyleData(ZcDbDimStyleTableRecord* pNewData);
    Zcad::ErrorStatus   setDimstyleData(ZcDbObjectId newDataId);

    virtual void        setDimVars();

    ZcCmColor      dimclrd () const;
    ZcCmColor      dimclrt () const;
    double         dimgap  () const;
    double         dimscale() const;
    ZcDbObjectId   dimtxsty() const;
    double         dimtxt  () const;

    Zcad::ErrorStatus setDimclrd (ZcCmColor&     val);
    Zcad::ErrorStatus setDimclrt (ZcCmColor&     val);
    Zcad::ErrorStatus setDimgap  (double         val);
    Zcad::ErrorStatus setDimscale(double         val);
    Zcad::ErrorStatus setDimtxsty(ZcDbObjectId   val);
    Zcad::ErrorStatus setDimtxt  (double         val);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;	
};

#pragma pack(pop)

#endif
