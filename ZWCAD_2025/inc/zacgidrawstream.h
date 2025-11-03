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

    virtual ZSoft::Boolean isPersistent() const override;
    virtual ZcDbObjectId id() const override;
    virtual ZcGiDrawable::DrawableType drawableType() const override;
    virtual bool bounds(ZcDbExtents& bounds) const override;
    virtual void setDrawStream(ZcGiDrawStream* pStream) override;
    virtual ZcGiDrawStream* drawStream() const override;

protected:

    virtual ZSoft::UInt32 subSetAttributes(ZcGiDrawableTraits* pTraits) override;
    virtual ZSoft::Boolean subWorldDraw(ZcGiWorldDraw* pWd) override;
    virtual void subViewportDraw(ZcGiViewportDraw* pVd) override;
    virtual ZSoft::UInt32 subViewportDrawLogicalFlags(ZcGiViewportDraw* pVd) override;

protected:
    ZcGiDrawStreamImp* m_pImp;
};

#pragma pack(pop)
