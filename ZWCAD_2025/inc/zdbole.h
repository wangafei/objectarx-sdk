

#ifndef ZD_DBOLE_H
#define ZD_DBOLE_H

#include "zdbmain.h"
#include "zdbframe.h"
#include "zgepnt3d.h"

#pragma pack (push, 8)

class CRectangle3d
{
public:
    ZcGePoint3d upLeft;
    ZcGePoint3d upRight;
    ZcGePoint3d lowLeft;
    ZcGePoint3d lowRight;
};

bool ZCDB_PORT operator==(const CRectangle3d&l, const CRectangle3d&r);

class COleClientItem;

class ZCDB_PORT ZcDbOleFrame: public ZcDbFrame
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbOleFrame);

    ZcDbOleFrame();
    virtual ~ZcDbOleFrame();

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;

    virtual void* getOleObject(void) const;
    virtual void setOleObject(const void *pItem);

protected:
};

class ZCDB_PORT ZcDbOle2Frame: public ZcDbOleFrame
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbOle2Frame);
    ZcDbOle2Frame();
    virtual ~ZcDbOle2Frame();

    virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer) override;
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer) override;
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;

    virtual void                saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st) override;

    virtual void* getOleObject(void) const override;
    virtual void setOleObject(const void *pItem) override;

	
    void* getOleItemHost() const;
    COleClientItem* getOleClientItem(void) const;
    Zcad::ErrorStatus setOleClientItem(const COleClientItem* pItem);
	

    virtual void getLocation(ZcGePoint3d& point3d) const;

    void setLocation(const ZcGePoint3d& point3d);

    virtual void position(CRectangle3d& rect3d) const;

    virtual void setPosition(const CRectangle3d& rect3d);

    virtual void position(RECT& rect) const;

    virtual void setPosition(const RECT& rect);

    virtual void getUserType(ZTCHAR * pszName, int nNameSize) const;
    Zcad::ErrorStatus getUserType(ZcString &) const;
    virtual int getType(void) const;

    virtual bool getLinkName(ZTCHAR * pszName, int nNameSize) const;
    Zcad::ErrorStatus getLinkName(ZcString &) const;
    bool isLinked() const;
    virtual bool getLinkPath(ZTCHAR * pszPath, int nPathSize) const;
    Zcad::ErrorStatus getLinkPath(ZcString &) const;

    virtual ZSoft::UInt8 outputQuality() const;
    virtual void setOutputQuality(ZSoft::UInt8);

	ZSoft::Boolean autoOutputQuality() const;
	void setAutoOutputQuality(ZSoft::UInt8);

    double rotation() const;
    Zcad::ErrorStatus setRotation(const double rotation);

    double wcsWidth() const;
    Zcad::ErrorStatus setWcsWidth(const double wcsWidth);

    double wcsHeight() const;
    Zcad::ErrorStatus setWcsHeight(const double wcsHeight);

    double scaleWidth() const;
    Zcad::ErrorStatus setScaleWidth(const double scaleWidth);

    double scaleHeight() const;
    Zcad::ErrorStatus setScaleHeight(const double scaleHeight);

    ZSoft::Boolean lockAspect() const;
    Zcad::ErrorStatus setLockAspect(const ZSoft::Boolean bLockAspect);

protected:
	virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)

#endif  
