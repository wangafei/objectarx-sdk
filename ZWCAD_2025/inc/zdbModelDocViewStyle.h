

#ifndef __ZDBMODELDOCVIEWSTYLE_H__
#define __ZDBMODELDOCVIEWSTYLE_H__

#pragma once
#include "zacdbport.h"
#include "zdbmain.h"
#include "zdbmtext.h"
#include "zAcString.h"

class ZcDbImpModelDocViewStyle;

class ZCDBCORE2D_PORT ZcDbModelDocViewStyle : public ZcDbObject
{
public:
	ZcDbModelDocViewStyle(); 
    ZCDB_DECLARE_MEMBERS(ZcDbModelDocViewStyle);

    enum AttachmentPoint {
        kAboveView    = 0,
        kBelowView    = 1,
    };

    enum TextAlignment {
        kTextAlignmentLeft   = 0,
        kTextAlignmentCenter = 1,
        kTextAlignmentRight  = 2,
    };

	virtual ~ZcDbModelDocViewStyle();

    virtual Zcad::ErrorStatus getName(ZTCHAR*& pszName) const final;

    virtual Zcad::ErrorStatus getName(ZcString& strName) const;

    virtual Zcad::ErrorStatus setName(const ZTCHAR * pszName);

    virtual const ZTCHAR* description(void) const;

    virtual void getDescription(ZcString& strDescription) const;

    virtual Zcad::ErrorStatus setDescription(const ZTCHAR * pszDescription);

    
    void setDatabaseDefaults(ZcDbDatabase* pDb);
 
    Zcad::ErrorStatus postViewStyleToDb (ZcDbDatabase* pDb, const ZTCHAR* styleName, ZcDbObjectId &viewStyleId);
 
    bool              isModifiedForRecompute() const;

    ZcString          defaultViewName(int index) const;

    bool              isViewNameValid(const ZTCHAR* pName) const;

    static ZcGePoint3d calculateViewLabelPosition  (ZcGeVector2d &offsetVector,
                                                    ZcDbMText::AttachmentPoint &textAlignment,
                                                    ZcDbModelDocViewStyle::AttachmentPoint attachment,
                                                    double offset,
                                                    const ZcGePoint3d &minPt,
                                                    const ZcGePoint3d &maxPt);
 
    static ZcGeVector2d setViewLabelPosition   (ZcDbMText *pMText,
                                                ZcDbModelDocViewStyle::AttachmentPoint attachment,
                                                double offset,
                                                const ZcGePoint3d &minPt,
                                                const ZcGePoint3d &maxPt);

    static ZcGeVector2d updateViewLabelPosition(ZcDbMText *pMText,
                                                ZcDbModelDocViewStyle::AttachmentPoint &attachment,
                                                const ZcGePoint3d &minPt,
                                                const ZcGePoint3d &maxPt);

protected:
    
    
    virtual Zcad::ErrorStatus subDeepClone(ZcDbObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;
    virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;

private:
    friend class ZcDbImpModelDocViewStyle;
};

inline Zcad::ErrorStatus ZcDbModelDocViewStyle::getName(ZTCHAR*& pName) const
{
    return ::zcutGetZcStringConvertToZTChar(this, &ZcDbModelDocViewStyle::getName, pName);
}

#endif 

