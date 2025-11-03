#pragma once

#pragma pack(push, 8)

class ZcGiDrawStreamImp;

typedef bool (*GraphicsUpdateProc)(const ZcArray<ZcGiDrawable*>& drawableArray);

class ZCDBCORE2D_PORT ZcGiDrawStream : public ZcGiDrawable
{
    friend class ZcGiDrawStreamImp;

public:
    ZCRX_DECLARE_MEMBERS(ZcGiDrawStream);

    static bool build(const ZcArray<ZcGiDrawStream*>& streamArray, GraphicsUpdateProc lpFunc);

    ZcGiDrawStream();
    ZcGiDrawStream(const ZcGiDrawable* pOwner);
   ~ZcGiDrawStream();

    ZcGiDrawable* getOwner() const;
    void setOwner(const ZcGiDrawable* pOwner);
    bool isValid() const;

    bool serializeOut(IZcWriteStream* pOutput) const;
    bool serializeIn(IZcReadStream* pInput, ZcDbDatabase* pDb = NULL);

    virtual ZSoft::Boolean isPersistent() const ZSOFT_OVERRIDE;
    virtual ZcDbObjectId id() const ZSOFT_OVERRIDE;
    virtual ZcGiDrawable::DrawableType drawableType() const ZSOFT_OVERRIDE;
    virtual bool bounds(ZcDbExtents& bounds) const ZSOFT_OVERRIDE;
    virtual void setDrawStream(ZcGiDrawStream* pStream) ZSOFT_OVERRIDE;
    virtual ZcGiDrawStream* drawStream() const ZSOFT_OVERRIDE;

protected:

    virtual ZSoft::UInt32 subSetAttributes(ZcGiDrawableTraits* pTraits) ZSOFT_OVERRIDE;
    virtual ZSoft::Boolean subWorldDraw(ZcGiWorldDraw* pWd) ZSOFT_OVERRIDE;
    virtual void subViewportDraw(ZcGiViewportDraw* pVd) ZSOFT_OVERRIDE;
    virtual ZSoft::UInt32 subViewportDrawLogicalFlags(ZcGiViewportDraw* pVd) ZSOFT_OVERRIDE;

protected:
    ZcGiDrawStreamImp* m_pImp;
};

#pragma pack(pop)
