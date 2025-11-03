
#ifndef __ZCDBSECTIONVIEWSTYLE_H__
#define __ZCDBSECTIONVIEWSTYLE_H__

#pragma once
#include "zdbModelDocViewStyle.h"

#pragma pack (push, 8)


class ZCDBCORE2D_PORT ZcDbSectionViewStyle : public ZcDbModelDocViewStyle
{
public:

    enum IdentifierPosition {
        kEndCuttingPlane             = 0,
        kAboveDirectionArrowLine     = 1,
        kAboveDirectionArrowSymbol   = 2,
        kStartDirectionArrow         = 3,
        kEndDirectionArrow           = 4,
    };

    enum ArrowDirection {
        kTowardsCuttingPlane    = 0,
        kAwayFromCuttingPlane   = 1,
    };

    ZcDbSectionViewStyle();
    ~ZcDbSectionViewStyle();
    ZCDB_DECLARE_MEMBERS(ZcDbSectionViewStyle);

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);

	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;

	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);

	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;    ZcDbObjectId      identifierStyleId () const;

    Zcad::ErrorStatus setIdentifierStyleId (const ZcDbObjectId &objId);

    ZcCmColor         identifierColor () const;

    Zcad::ErrorStatus setIdentifierColor (const ZcCmColor& color);

    double            identifierHeight () const;

    Zcad::ErrorStatus setIdentifierHeight (double height);

    const ZTCHAR *     identifierExcludeCharacters () const;

    Zcad::ErrorStatus setIdentifierExcludeCharacters (const ZTCHAR* str);

    ZcDbObjectId      arrowStartSymbolId () const;

    Zcad::ErrorStatus setArrowStartSymbolId (const ZcDbObjectId &arrowSymbolId);

    ZcDbObjectId      arrowEndSymbolId () const;

    Zcad::ErrorStatus setArrowEndSymbolId (const ZcDbObjectId &arrowSymbolId);

    ZcCmColor         arrowSymbolColor () const;

    Zcad::ErrorStatus setArrowSymbolColor (const ZcCmColor& color);

    double            arrowSymbolSize () const;

    Zcad::ErrorStatus setArrowSymbolSize (double size);

    double            arrowSymbolExtensionLength () const;

    Zcad::ErrorStatus setArrowSymbolExtensionLength (double length);

    ZcDb::LineWeight  planeLineWeight () const;

    Zcad::ErrorStatus setPlaneLineWeight (ZcDb::LineWeight lineweight);

    ZcCmColor         planeLineColor () const;

    Zcad::ErrorStatus setPlaneLineColor (const ZcCmColor& color);

    ZcDbObjectId      planeLineTypeId () const;

    Zcad::ErrorStatus setPlaneLineTypeId (const ZcDbObjectId &objId);

    ZcCmColor         bendLineColor () const;

    Zcad::ErrorStatus setBendLineColor (const ZcCmColor& color);

    ZcDb::LineWeight  bendLineWeight () const;

    Zcad::ErrorStatus setBendLineWeight (ZcDb::LineWeight lineweight);

    ZcDbObjectId      bendLineTypeId () const;

    Zcad::ErrorStatus setBendLineTypeId (const ZcDbObjectId &objId);

    double            bendLineLength () const;

    Zcad::ErrorStatus setBendLineLength (double length);

    double            endLineLength () const;

    Zcad::ErrorStatus setEndLineLength (double length);

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

    const ZTCHAR *     hatchPattern () const;

    Zcad::ErrorStatus setHatchPattern (const ZTCHAR* pattern);

    ZcCmColor         hatchColor () const;

    Zcad::ErrorStatus setHatchColor (const ZcCmColor& color);

    ZcCmColor         hatchBackgroundColor () const;

    Zcad::ErrorStatus setHatchBackgroundColor (const ZcCmColor& color);

    double            hatchScale () const;

    Zcad::ErrorStatus setHatchScale (double scale);

    const ZcArray<double>& hatchAngles () const;

    Zcad::ErrorStatus setHatchAngles (const ZcArray<double>& angleArray);

    Zcad::ErrorStatus setHatchTransparency (const ZcCmTransparency& transparency);

    ZcCmTransparency  hatchTransparency () const;

    bool              isContinuousLabeling () const;
    Zcad::ErrorStatus setContinuousLabeling (bool bValue);

    bool              showArrowheads () const;
    Zcad::ErrorStatus setShowArrowheads (bool bValue);

    bool              showViewLabel () const;
    Zcad::ErrorStatus setShowViewLabel (bool bValue);

    bool              showAllPlaneLines () const;
    Zcad::ErrorStatus setShowAllPlaneLines (bool bValue);

    bool              showAllBendIndentifiers () const;
    Zcad::ErrorStatus setShowAllBendIndentifiers (bool bValue);

    bool              showEndAndBendLines () const;
    Zcad::ErrorStatus setShowEndAndBendLines (bool bValue);

    bool              showHatching () const;
    Zcad::ErrorStatus setShowHatching (bool bValue);

    static bool       validateIdentifierExcludeCharacters (const ZTCHAR* str);

    ZcDbSectionViewStyle::IdentifierPosition viewIdentifierPosition () const;

    Zcad::ErrorStatus setViewIdentifierPosition (ZcDbSectionViewStyle::IdentifierPosition type);

    double viewIdentifierOffset () const;

    Zcad::ErrorStatus setViewIdentifierOffset (double offset);

    ZcDbSectionViewStyle::ArrowDirection arrowPosition () const;

    Zcad::ErrorStatus setArrowPosition (ZcDbSectionViewStyle::ArrowDirection type);

    double            endLineOvershoot () const;

    Zcad::ErrorStatus setEndLineOvershoot (double length);

protected:
    
    virtual Zcad::ErrorStatus subDeepClone(ZcDbObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;
    virtual Zcad::ErrorStatus subWblockClone(ZcRxObject* pOwner, ZcDbObject*& pClonedObject,
        ZcDbIdMapping& idMap, ZSoft::Boolean isPrimary = true) const override;
};

#pragma pack (pop)

#endif 
