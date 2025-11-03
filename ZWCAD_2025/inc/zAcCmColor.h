
#pragma once

#include "zadesk.h"
#include "zdbcolor.h"
#include "zacutAcString.h"
#include "zacdb.h"

extern const wchar_t kszZwCAD_Color_Index[];
extern const wchar_t kszUNNAMED[];

class ZcDbDxfFiler;
class ZcDbAuditInfo;
class ZcDbDwgFiler;
class ZCDBCORE2D_PORT ZcCmColor : public ZcCmColorBase
{
public:
    ZcCmColor();
    ZcCmColor(const ZcCmColor&);
    ZcCmColor(const ZcCmColorBase&);
    ZcCmColor& operator=(const ZcCmColor& inputColor);
    ZcCmColor& operator=(const ZcCmColorBase& inputColor);
    ZcCmColor(const ZcCmEntityColor&);
    ZcCmColor& operator=(const ZcCmEntityColor& inputColor);
    ~ZcCmColor();

    bool operator ==(const ZcCmColor& color) const;
    bool operator !=(const ZcCmColor& color) const;
    bool operator ==(const ZcCmColorBase& color) const;
    bool operator !=(const ZcCmColorBase& color) const;

    Zcad::ErrorStatus getDescription(ZcString & desc) const;
    Zcad::ErrorStatus getDescription(ZTCHAR*& desc) const;
    Zcad::ErrorStatus getExplanation(ZcString & expl) const;
    Zcad::ErrorStatus getExplanation(ZTCHAR*& expl) const;
    ZcCmEntityColor::ColorMethod  colorMethod() const override;

    void setNone() override {
        mColor.setNone();
    }
    void setByBlock() override {
        mColor.setByBlock();
    }
    void setForeground() override {
        mColor.setForeground();
    }
    void setLayerOff() override {
        mColor.setLayerOff();
    }
    void setByLayer() override {
        mColor.setByLayer();
    }
    bool    isByColor() const override;
    bool    isByLayer() const override;
    bool    isByBlock() const override;
    bool    isByACI()   const override;
    bool    isByPen() const override;
    bool    isForeground()   const override;

    bool            isNone() const;

    Zcad::ErrorStatus setRGB(ZSoft::UInt8 red,
        ZSoft::UInt8 green,
        ZSoft::UInt8 blue) override;

    ZSoft::UInt8      red() const override;
    ZSoft::UInt8      green() const override;
    ZSoft::UInt8      blue() const override;

    Zcad::ErrorStatus   setCOLORREF(ZSoft::ColorRef cref) override;
    ZSoft::ColorRef     getCOLORREF() const override;

    Zcad::ErrorStatus   setRGB(ZSoft::RGBQuad rgbquad) override;
    ZSoft::RGBQuad      getRGB() const override;

    Zcad::ErrorStatus   setRGBM(ZSoft::UInt32 rgbmValue) override;
    ZSoft::UInt32       getRGBM() const override;

    ZSoft::UInt16     colorIndex() const override;
    Zcad::ErrorStatus setColorIndex(ZSoft::UInt16 colorIndex) override;
    ZSoft::UInt16     penIndex() const override;
    Zcad::ErrorStatus setPenIndex(ZSoft::UInt16 penIndex) override;

    Zcad::ErrorStatus setNames(const ZTCHAR* colorName,
        const ZTCHAR* bookName = nullptr) override;
    const ZTCHAR* colorName(void) const override;
    const ZTCHAR* bookName(void) const override;
    const ZTCHAR* colorNameForDisplay(void) override;
    bool              hasColorName(void) const override;
    bool              hasBookName(void) const override;

    ZcCmEntityColor           entityColor(void) const;
    int                       dictionaryKeyLength(void) const;

    Zcad::ErrorStatus       getDictionaryKey(ZcString& sKey) const;
    Zcad::ErrorStatus       getDictionaryKey(ZTCHAR* pKey, size_t nLen) const;
    Zcad::ErrorStatus       setNamesFromDictionaryKey(const ZTCHAR* pKey);

    Zcad::ErrorStatus dwgIn(ZcDbDwgFiler* pInputFiler);
    Zcad::ErrorStatus dwgOut(ZcDbDwgFiler* pOutputFiler) const;

    Zcad::ErrorStatus dxfIn(ZcDbDxfFiler* pFiler, int groupCodeOffset = 0);
    Zcad::ErrorStatus dxfOut(ZcDbDxfFiler* pFiler, int groupCodeOffset = 0) const;

    Zcad::ErrorStatus audit(ZcDbAuditInfo* pAuditInfo);

    Zcad::ErrorStatus serializeOut(void* pBuff, int* pBuflen,
        ZcDb::ZcDbDwgVersion ver = ZcDb::kDHL_CURRENT) const;

    Zcad::ErrorStatus serializeIn(const void* pBuff, int* pBuflen);

    static const ZSoft::UInt16 MaxColorIndex;

    Zcad::ErrorStatus dwgInAsTrueColor(ZcDbDwgFiler* pInputFiler);
    Zcad::ErrorStatus dwgOutAsTrueColor(ZcDbDwgFiler* pOutputFiler) const;

private:

    enum NameFlags {
        kNoNames = 0x00,
        kHasColorName = 0x01,
        kHasBookName = 0x02
    };

    static const ZSoft::UInt16 ComplexColorFlag;

    ZcCmEntityColor         mColor;
    ZcString                msColorName;
    ZcString                msBookName;
    ZSoft::UInt8            mNameFlags = 0;
#ifdef ZcCmColor_DEPRECATED_METHODS
public:
    [[deprecated("Prefer specific setMethod() calls to this generic call")]] Zcad::ErrorStatus setColorMethod(ZcCmEntityColor::ColorMethod eColorMethod) override;
    [[deprecated("Use getRGBM() or getRGB()")]] ZSoft::UInt32 color() const override;
    [[deprecated("Use setRGBM() or setRGB()")]] Zcad::ErrorStatus setColor(ZSoft::UInt32 color) override;
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setRed(ZSoft::UInt8 red) override;
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setGreen(ZSoft::UInt8 green) override;
    [[deprecated("Use setRGB()")]] Zcad::ErrorStatus setBlue(ZSoft::UInt8 blue) override;
#endif
};

