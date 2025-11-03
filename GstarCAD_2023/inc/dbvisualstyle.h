/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "gcgi.h"

#pragma pack (push, 8)

const GCHAR kszVSFlat[] = GCRX_T("Flat");
const GCHAR kszVSFlatWithEdges[] = GCRX_T("FlatWithEdges");
const GCHAR kszVSGouraud[] = GCRX_T("Gouraud");
const GCHAR kszVSGouraudWithEdges[] = GCRX_T("GouraudWithEdges");

const GCHAR kszVS2DWireframe[] = GCRX_T("2dWireframe");
const GCHAR kszVS3DWireframe[] = GCRX_T("Wireframe");
const GCHAR kszVSBasic[] = GCRX_T("Basic");
const GCHAR kszVSHidden[] = GCRX_T("Hidden");
const GCHAR kszVSRealistic[] = GCRX_T("Realistic");
const GCHAR kszVSConceptual[] = GCRX_T("Conceptual");
const GCHAR kszVSCustom[] = GCRX_T("Custom");
const GCHAR kszVSShadesOfGray[] = GCRX_T("Shades of Gray");
const GCHAR kszVSSketchy[] = GCRX_T("Sketchy");
const GCHAR kszVSXRay[] = GCRX_T("X-Ray");

const GCHAR kszVSShadedWithEdges[] = GCRX_T("Shaded with edges");
const GCHAR kszVSShaded[] = GCRX_T("Shaded");

const GCHAR kszVSDim[] = GCRX_T("Dim");
const GCHAR kszVSBrighten[] = GCRX_T("Brighten");
const GCHAR kszVSThicken[] = GCRX_T("Thicken");
const GCHAR kszVSTransparent[] = GCRX_T("Transparent");
const GCHAR kszVSLinePattern[] = GCRX_T("Linepattern");
const GCHAR kszVSFacePattern[] = GCRX_T("Facepattern");
const GCHAR kszVSColorChange[] = GCRX_T("ColorChange");

const GCHAR kszVSJitterOff[] = GCRX_T("JitterOff");
const GCHAR kszVSOverhangOff[] = GCRX_T("OverhangOff");
const GCHAR kszVSEdgeColorOff[] = GCRX_T("EdgeColorOff");

class GCDB_PORT GcDbVisualStyle : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbVisualStyle);
  GcDbVisualStyle();
  ~GcDbVisualStyle();

  Gcad::ErrorStatus   setDescription(const GCHAR* pDescription);
  const GCHAR*        description(void) const;

  Gcad::ErrorStatus setType(GcGiVisualStyle::Type type);
  GcGiVisualStyle::Type type() const;

  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    const GcGiVariant *pVal,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    int nVal,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    bool bVal,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    double dVal,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    double red,
    double green,
    double blue,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  Gcad::ErrorStatus setTrait(GcGiVisualStyleProperties::Property prop,
    const GcCmColor *pColor,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);

  const GcGiVariant& trait(GcGiVisualStyleProperties::Property prop,
    GcGiVisualStyleOperations::Operation *pOp = NULL) const;

  Gcad::ErrorStatus setTraitFlag(GcGiVisualStyleProperties::Property flagProp,
    Gsoft::UInt32 flagVal,
    bool bEnable = true);
  bool traitFlag(GcGiVisualStyleProperties::Property flagProp, Gsoft::UInt32 flagVal) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  GcGiDrawable*     drawable(void) override;
  virtual bool      isInternalUseOnly() const;
  virtual void      setInternalUseOnly(bool bInternalUseOnly);

  virtual Gcad::ErrorStatus copyTo(GcGiVisualStyle * pDest) const;
  virtual Gcad::ErrorStatus copyFrom(const GcGiVisualStyle * pSrc);
  Gcad::ErrorStatus decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*&         replaceObj,
    GcDbObjectId&        replaceId,
    Gsoft::Boolean&      exchangeXData) override;
  Gcad::ErrorStatus name(GcString &value) const;

protected:
};

#pragma pack (pop)