/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "GcGiEnvironment.h"
#include "dbcolor.h"
#include "GdGChar.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP 
#endif

const GCHAR GCDB_BACKGROUND_DICTIONARY[] = GCRX_T("ACAD_BACKGROUND");

Gcad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode, bool createIfNonExist);
Gcad::ErrorStatus SCENEDLLIMPEXP getBackgroundDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode);

class GcDbImpBackground;

class SCENEDLLIMPEXP GcDbBackground : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbBackground);
  ~GcDbBackground();
  GcGiDrawable*  drawable() override;

protected:
  GcDbBackground(GcDbImpBackground* pImp);
  GcDbImpBackground* imp() const;

private:
  friend class GcDbImpBackground;
  GcDbImpBackground* mpImp;
};

class SCENEDLLIMPEXP GcDbSolidBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSolidBackground);
  GcDbSolidBackground();
  ~GcDbSolidBackground();

  void            setColorSolid(const GcCmEntityColor & color);
  GcCmEntityColor colorSolid(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  GcGiDrawable::DrawableType    drawableType() const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpSolidBackground;
};

class SCENEDLLIMPEXP GcDbGradientBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGradientBackground);
  GcDbGradientBackground();
  ~GcDbGradientBackground();

  void            setColorTop(const GcCmEntityColor & color);
  GcCmEntityColor colorTop(void) const;
  void            setColorMiddle(const GcCmEntityColor & color);
  GcCmEntityColor colorMiddle(void) const;
  void            setColorBottom(const GcCmEntityColor & color);
  GcCmEntityColor colorBottom(void) const;
  void            setHorizon(double horizon);
  double          horizon(void) const;
  void            setHeight(double height);
  double          height(void) const;
  void            setRotation(double rotation);
  double          rotation(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  GcGiDrawable::DrawableType    drawableType() const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpGradientBackground;
};

class SCENEDLLIMPEXP GcDbImageBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbImageBackground);
  GcDbImageBackground();
  ~GcDbImageBackground();

  void            setImageFilename(const GCHAR* filename);
  const GCHAR *   imageFilename(void) const;
  void            setFitToScreen(bool bFitToScreen);
  bool            fitToScreen(void) const;
  void            setMaintainAspectRatio(bool bMaintainAspectRatio);
  bool            maintainAspectRatio(void) const;
  void            setUseTiling(bool bUseTiling);
  bool            useTiling(void) const;
  void            setXOffset(double xOffset);
  double          xOffset(void) const;
  void            setYOffset(double yOffset);
  double          yOffset(void) const;
  void            setXScale(double xScale);
  double          xScale(void) const;
  void            setYScale(double yScale);
  double          yScale(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  GcGiDrawable::DrawableType    drawableType() const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpImageBackground;
};

class SCENEDLLIMPEXP GcDbGroundPlaneBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGroundPlaneBackground);
  GcDbGroundPlaneBackground();
  ~GcDbGroundPlaneBackground();

  void            setColorSkyZenith(const GcCmEntityColor & color);
  GcCmEntityColor colorSkyZenith(void) const;
  void            setColorSkyHorizon(const GcCmEntityColor & color);
  GcCmEntityColor colorSkyHorizon(void) const;
  void            setColorUndergroundHorizon(const GcCmEntityColor & color);
  GcCmEntityColor colorUndergroundHorizon(void) const;
  void            setColorUndergroundAzimuth(const GcCmEntityColor & color);
  GcCmEntityColor colorUndergroundAzimuth(void) const;
  void            setColorGroundPlaneNear(const GcCmEntityColor & color);
  GcCmEntityColor colorGroundPlaneNear(void) const;
  void            setColorGroundPlaneFar(const GcCmEntityColor & color);
  GcCmEntityColor colorGroundPlaneFar(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  GcGiDrawable::DrawableType    drawableType() const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpGroundPlaneBackground;
};

class SCENEDLLIMPEXP GcDbSkyBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSkyBackground);
  GcDbSkyBackground();
  ~GcDbSkyBackground();

  Gcad::ErrorStatus         setSunId(GcDbObjectId sunId);
  GcDbObjectId              sunId(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;

  GcGiDrawable::DrawableType    drawableType() const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpSkyBackground;
};

class SCENEDLLIMPEXP GcDbIBLBackground : public GcDbBackground
{
public:
  GCRX_DECLARE_MEMBERS(GcDbIBLBackground);
  GcDbIBLBackground();
  ~GcDbIBLBackground();

  GcGiDrawable* drawable() override;

  virtual Gcad::ErrorStatus setEnable(const bool bEnable);
  virtual bool              enable(void) const;
  virtual Gcad::ErrorStatus setIBLImageName(const GcString& name);
  virtual GcString          IBLImageName(void) const;
  virtual Gcad::ErrorStatus setRotation(const double rotation);
  virtual double            rotation(void) const;
  virtual Gcad::ErrorStatus setDisplayImage(const bool bdisplay);
  virtual bool              displayImage(void) const;
  virtual Gcad::ErrorStatus setSecondaryBackground(const GcDbObjectId bg);
  virtual GcDbObjectId      secondaryBackground(void) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  GcGiDrawable::DrawableType    drawableType() const override;

  virtual bool operator==(const GcDbIBLBackground& environment);

protected:
  Gsoft::UInt32 subSetAttributes(GcGiDrawableTraits* pTraits) override;
};

#pragma pack (pop)