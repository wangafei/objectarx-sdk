

#ifndef __ZDBDETAILVIEWSTYLE_H__
#define __ZDBDETAILVIEWSTYLE_H__

#pragma once
#include "zdbModelDocViewStyle.h"

class ZCDBCORE2D_PORT ZcDbDetailViewStyle : public ZcDbModelDocViewStyle
{
public:
	enum IdentifierPlacement {
		kOutsideBoundary=0,
        kOutsideBoundaryWithLeader,
        kOnBoundary,
        kOnBoundaryWithLeader,
	};

    enum ModelEdge {
        kSmooth = 0,
        kSmoothWithBorder,
        kSmoothWithConnectionLine,
        kJagged,
    };

    ZcDbDetailViewStyle();
    ~ZcDbDetailViewStyle();
    ZCDB_DECLARE_MEMBERS(ZcDbDetailViewStyle);


    ZcDbObjectId      identifierStyleId () const;

    Zcad::ErrorStatus setIdentifierStyleId (const ZcDbObjectId &objId);

    ZcCmColor         identifierColor () const;

    Zcad::ErrorStatus setIdentifierColor (const ZcCmColor& color);

    double            identifierHeight () const;
    
    Zcad::ErrorStatus setIdentifierHeight (double height);

    double identifierOffset () const;

    Zcad::ErrorStatus setIdentifierOffset (double offset);

    ZcDbDetailViewStyle::IdentifierPlacement identifierPlacement () const;

    Zcad::ErrorStatus setIdentifierPlacement (ZcDbDetailViewStyle::IdentifierPlacement placement);

    ZcDbObjectId      arrowSymbolId () const;

    Zcad::ErrorStatus setArrowSymbolId (const ZcDbObjectId &arrowSymbolId);
    
    ZcCmColor         arrowSymbolColor () const;

    Zcad::ErrorStatus setArrowSymbolColor (const ZcCmColor& color);

    double            arrowSymbolSize () const;

    Zcad::ErrorStatus setArrowSymbolSize (double size);
  
    bool              showArrows () const;
    Zcad::ErrorStatus setShowArrows (bool bValue);

    ZcDb::LineWeight  boundaryLineWeight () const;

    Zcad::ErrorStatus setBoundaryLineWeight (ZcDb::LineWeight lineweight);

    ZcCmColor         boundaryLineColor () const;

    Zcad::ErrorStatus setBoundaryLineColor (const ZcCmColor& color);

    ZcDbObjectId      boundaryLineTypeId () const;
   
    Zcad::ErrorStatus setBoundaryLineTypeId (const ZcDbObjectId &objId);

    ZcDb::LineWeight  connectionLineWeight () const;

    Zcad::ErrorStatus setConnectionLineWeight (ZcDb::LineWeight lineweight);

    ZcCmColor         connectionLineColor () const;

    Zcad::ErrorStatus setConnectionLineColor (const ZcCmColor& color);
    
    ZcDbObjectId      connectionLineTypeId () const;

    Zcad::ErrorStatus setConnectionLineTypeId (const ZcDbObjectId &objId);

    ZcDbObjectId      viewLabelTextStyleId () const;

    Zcad::ErrorStatus setViewLabelTextStyleId (const ZcDbObjectId &objId);

    ZcCmColor         viewLabelTextColor () const;

    Zcad::ErrorStatus setViewLabelTextColor (const ZcCmColor& color);

    double            viewLabelTextHeight () const;
    Zcad::ErrorStatus setViewLabelTextHeight (double height);

    double            viewLabelOffset () const;

    Zcad::ErrorStatus setViewLabelOffset (double offset);

    ZcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment () const;

    Zcad::ErrorStatus setViewLabelAttachment (ZcDbModelDocViewStyle::AttachmentPoint attachment);

    ZcDbModelDocViewStyle::TextAlignment viewLabelAlignment () const;

    Zcad::ErrorStatus setViewLabelAlignment (ZcDbModelDocViewStyle::TextAlignment alignment);

    const ZTCHAR *     viewLabelPattern () const;

    Zcad::ErrorStatus getViewLabelPattern (ZcString &pattern,
                                           ZcDbField *pField = NULL) const;

    Zcad::ErrorStatus setViewLabelPattern (const ZTCHAR* pattern,
                                           const ZcDbField *pField = NULL);

    bool              showViewLabel () const;
    Zcad::ErrorStatus setShowViewLabel (bool bValue);

    ZcDbDetailViewStyle::ModelEdge modelEdge () const;

    Zcad::ErrorStatus setModelEdge (ZcDbDetailViewStyle::ModelEdge placement);

    ZcDb::LineWeight  borderLineWeight () const;

    Zcad::ErrorStatus setBorderLineWeight (ZcDb::LineWeight lineweight);

    ZcCmColor         borderLineColor () const;

    Zcad::ErrorStatus setBorderLineColor (const ZcCmColor& color);

    ZcDbObjectId      borderLineTypeId () const;

    Zcad::ErrorStatus setBorderLineTypeId (const ZcDbObjectId &objId);

protected:
    
    virtual Zcad::ErrorStatus subDeepClone(ZcDbObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;
    virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;
};

#endif 
