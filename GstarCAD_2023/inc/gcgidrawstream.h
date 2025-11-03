/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#pragma pack(push, 8)

class GcGiDrawStreamImp;

typedef bool(*GraphicsUpdateProc)(const GcArray<GcGiDrawable*>& drawableArray);

class GcGiDrawStream : public GcGiDrawable
{
  friend class GcGiDrawStreamImp;

public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcGiDrawStream, GCBASE_PORT);

  GCBASE_PORT static bool build(const GcArray<GcGiDrawStream*>& streamArray, GraphicsUpdateProc lpFunc);

  GCBASE_PORT GcGiDrawStream();
  GCBASE_PORT GcGiDrawStream(const GcGiDrawable* pOwner);
  GCBASE_PORT ~GcGiDrawStream();

  GCBASE_PORT GcGiDrawable* getOwner() const;
  GCBASE_PORT void setOwner(const GcGiDrawable* pOwner);

  GCBASE_PORT bool isValid() const;

  GCBASE_PORT bool serializeOut(IGcWriteStream* pOutput) const;
  GCBASE_PORT bool serializeIn(IGcReadStream* pInput, GcDbDatabase* pDb = NULL);

  GCBASE_PORT Gsoft::Boolean isPersistent() const override;
  GCBASE_PORT GcDbObjectId id() const override;
  GCBASE_PORT GcGiDrawable::DrawableType drawableType() const override;
  GCBASE_PORT bool bounds(GcDbExtents& bounds) const override;
  GCBASE_PORT void setDrawStream(GcGiDrawStream* pStream) override;
  GCBASE_PORT GcGiDrawStream* drawStream() const override;

protected:
  GCBASE_PORT Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;
  GCBASE_PORT Gsoft::Boolean subWorldDraw(GcGiWorldDraw* pWd) override;
  GCBASE_PORT void subViewportDraw(GcGiViewportDraw* pVd) override;
  GCBASE_PORT Gsoft::UInt32 subViewportDrawLogicalFlags(GcGiViewportDraw* pVd) override;

protected:
  GcGiDrawStreamImp* m_pImp;
};

#pragma pack(pop)