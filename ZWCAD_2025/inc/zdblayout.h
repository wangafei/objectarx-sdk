

#ifndef ZD_DBLAYOUT_H
#define ZD_DBLAYOUT_H

#include "zdbmain.h"
#include "zdbdict.h"
#include "zAdAChar.h"
#include "zdbPlotSettings.h"

namespace Ztil 
{
	class Image; 
}

typedef struct tagBITMAPINFO BITMAPINFO;


#pragma pack(push, 8)

class ZCDBCORE2D_PORT ZcDbLayout: public ZcDbPlotSettings
{
public:
     ZCDB_DECLARE_MEMBERS(ZcDbLayout);

    ZcDbLayout();
    virtual ~ZcDbLayout     ();

    ZcDbObjectId      
    getBlockTableRecordId   () const;

    virtual Zcad::ErrorStatus 
    setBlockTableRecordId   (ZcDbObjectId BlockTableRecordId);

    virtual Zcad::ErrorStatus 
    addToLayoutDict         (ZcDbDatabase *towhichDb,
                             ZcDbObjectId BlockTableRecordId);

    Zcad::ErrorStatus 
    getLayoutName           (const ZTCHAR*& layoutName) const;

	Zcad::ErrorStatus getName(ZcString & sName) const;	

    Zcad::ErrorStatus 
    getLayoutName           (ZTCHAR*& layoutName) const;

    virtual Zcad::ErrorStatus setLayoutName           (const ZTCHAR* layoutName);

    int               
    getTabOrder             () const;

    virtual void              
    setTabOrder             (int newOrder);

    bool
    getTabSelected          () const;

    virtual void              
    setTabSelected          (ZSoft::Boolean tabSelected);

    ZcDbObjectIdArray 
    getViewportArray        () const;

    Zcad::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
    Zcad::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
	
	Zcad::ErrorStatus getPreviewImage(Ztil::Image*& pPreviewImage) const;	

	Zcad::ErrorStatus setPreviewImage (const Ztil::Image * pPreviewImage);	

    void
    getLimits (ZcGePoint2d& limMin, ZcGePoint2d& limMax) const;

	void
	getLimits (ZcDbExtents2d& extent) const;	

    void
    getExtents (ZcGePoint3d& extMin, ZcGePoint3d& extMax) const;

	void
	getExtents (ZcDbExtents& extent) const; 

    Zcad::ErrorStatus
    initialize(ZcDbObjectId* paperVportId = NULL);

    bool
    annoAllVisible() const;

    Zcad::ErrorStatus
    setAnnoAllVisible(bool newVal);
protected:
	virtual Zcad::ErrorStatus 
		subGetClassID              (CLSID* pClsid) const override;
};
inline Zcad::ErrorStatus ZcDbLayout::getLayoutName(ZTCHAR*& layoutName)const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbLayout::getName, layoutName);
}

#pragma pack(pop)

#endif
