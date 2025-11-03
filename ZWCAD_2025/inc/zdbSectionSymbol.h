
#pragma once

#include "zdbViewSymbol.h"

#pragma pack (push, 8)


#ifndef ZCSYNERGY_PORT
#define ZCSYNERGY_PORT _declspec(dllexport)
#endif


class ZCSYNERGY_PORT ZcDbSectionSymbol : public ZcDbViewSymbol
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbSectionSymbol);

	ZcDbSectionSymbol();

    int               sectionPointsCount() const;
    void              getSectionPoints(ZcGePoint3dArray &pts) const;
    Zcad::ErrorStatus getSectionPointAt(int idx, ZcGePoint3d& pt) const;
    Zcad::ErrorStatus getBulgeAt(int idx, double& bulge) const;
    Zcad::ErrorStatus getLabelNameAt(int idx, ZcString& sName) const;
    Zcad::ErrorStatus getLabelOffsetAt(int idx, ZcGeVector3d& offset) const;
    void              getLabelOffsets(ZcGeVector3dArray& offsets) const;
    bool              isViewDirectionLeft() const;
    bool              isHalfSection () const;

    
    Zcad::ErrorStatus setSectionPoints(const ZcGePoint3dArray& pts);
    Zcad::ErrorStatus setSectionPoints(const ZcGePoint3dArray& pts, const ZcGeDoubleArray& bulges);
    Zcad::ErrorStatus addSectionPoint(const ZcGePoint3d& pt, double bulge = 0);
    Zcad::ErrorStatus removeSectionPointAt(int idx);
    Zcad::ErrorStatus setSectionPointAt(int idx, const ZcGePoint3d& pt, double bulge = 0);
    void              clearSectionPoints();
    Zcad::ErrorStatus setLabelNameAt(int idx, const ZTCHAR* pName);
    Zcad::ErrorStatus setLabelNames(const ZcArray<ZcString>& names);
    Zcad::ErrorStatus setLabelOffsetAt(int idx, const ZcGeVector3d& offset);
    Zcad::ErrorStatus setLabelOffsets(const ZcGeVector3dArray& offsets);
    void              resetLabelOffsets(bool allOffsets = true);
    void              setViewDirectionLeft(bool bLeft);
    void              setIsHalfSection (bool bHalfSection);
    bool              flipDirection ();
};

#pragma pack (pop)
