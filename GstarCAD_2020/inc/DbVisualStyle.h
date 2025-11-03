/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef OD_DBVISUALSTYLE_H
#define OD_DBVISUALSTYLE_H

#include "TD_PackPush.h"

#include "DbObject.h"
#include "Gi/GiVisualStyle.h"

/** Description: 
  
    {group:TD_Namespaces}
*/
namespace OdDb
{
  // Legacy (shademode) styles
  const wchar_t kszVSFlat[]                 = L"Flat";
  const wchar_t kszVSFlatWithEdges[]        = L"FlatWithEdges";
  const wchar_t kszVSGouraud[]              = L"Gouraud";
  const wchar_t kszVSGouraudWithEdges[]     = L"GouraudWithEdges";

  // Visual Styles
  const wchar_t kszVS2DWireframe[]   = L"2dWireframe";
  const wchar_t kszVS3DWireframe[]   = L"Wireframe"; // Was "3dWireframe" before (#11263)
  const wchar_t kszVSBasic[]         = L"Basic";
  const wchar_t kszVSHidden[]        = L"Hidden";    // Was "3D Hidden" before   (#11263)
  const wchar_t kszVSRealistic[]     = L"Realistic";
  const wchar_t kszVSConceptual[]    = L"Conceptual";
  const wchar_t kszVSCustom[]        = L"Custom";
  const wchar_t kszVSShadesOfGray[]  = L"Shades of Gray";
  const wchar_t kszVSSketchy[]       = L"Sketchy";
  const wchar_t kszVSXRay[]          = L"X-Ray";

  // AirMax Visual Styles
  const wchar_t kszVSShadedWithEdges[]      = L"Shaded with edges";
  const wchar_t kszVSShaded[]               = L"Shaded";

  // Highlight Visual Styles (internal use only)
  const wchar_t kszVSDim[]           = L"Dim";
  const wchar_t kszVSBrighten[]      = L"Brighten";
  const wchar_t kszVSThicken[]       = L"Thicken";
  const wchar_t kszVSTransparent[]   = L"Transparent";
  const wchar_t kszVSLinePattern[]   = L"Linepattern";
  const wchar_t kszVSFacePattern[]   = L"Facepattern";
  const wchar_t kszVSColorChange[]   = L"ColorChange";

  // Edge Style Override Visual Styles (internal use only)
  const wchar_t kszVSJitterOff[]     = L"JitterOff";
  const wchar_t kszVSOverhangOff[]   = L"OverhangOff";
  const wchar_t kszVSEdgeColorOff[]  = L"EdgeColorOff";
}

/** Description:
    This class represents visual style in an OdDbDatabase instance.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbVisualStyle : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbVisualStyle);

  OdDbVisualStyle();

  virtual ~OdDbVisualStyle();
  OdResult setDescription(const OdString& pDescription);
  const OdString& description () const;

  OdResult setType(OdGiVisualStyle::Type type);
  OdGiVisualStyle::Type type() const;

  void setFaceStyle(const OdGiFaceStyle& faceStyle);
  const OdGiFaceStyle& faceStyle() const;

  void setEdgeStyle(const OdGiEdgeStyle& edgeStyle);
  const OdGiEdgeStyle& edgeStyle() const;

  OdResult setDisplayStyle(const OdGiDisplayStyle& displayStyle);
  const OdGiDisplayStyle& displayStyle() const;

  virtual bool isInternalUseOnly() const;
  virtual void setInternalUseOnly(bool bInternalUseOnly);

  virtual OdResult copyTo(OdGiVisualStyle * pDest) const;
  virtual OdResult copyFrom(const OdGiVisualStyle * pSrc);

  static OdGiFaceStylePtr createFaceStyle();
  static OdGiEdgeStylePtr createEdgeStyle();
  static OdGiDisplayStylePtr createDisplayStyle();

  OdResult setTrait(OdGiVisualStyleProperties::Property prop, const OdGiVariant *pVal,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, OdInt32 nVal,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, bool bVal,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, double dVal,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, double red, double green, double blue,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, const OdCmColor *pColor,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);
  OdResult setTrait(OdGiVisualStyleProperties::Property prop, const OdString &strVal,
                OdGiVisualStyleOperations::Operation op = OdGiVisualStyleOperations::kSet);

  OdGiVariantPtr trait(OdGiVisualStyleProperties::Property prop, OdGiVisualStyleOperations::Operation *pOp = NULL) const;

  OdResult setTraitFlag(OdGiVisualStyleProperties::Property flagProp, OdUInt32 flagVal, bool bEnable = true);
  bool traitFlag(OdGiVisualStyleProperties::Property flagProp, OdUInt32 flagVal) const;

  void name(OdString &value) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdGiDrawable* drawable();

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

public:
  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*&  replaceObj,
    OdDbObjectId& replaceId,
    OdBool&       exchangeXData);

  virtual void setGsNode(OdGsNode* pNode);

  virtual OdGsNode* gsNode(void) const;

private:
  void rdOperation(OdDbDxfFiler *pFiler, int index);
  void rdVer3PropsChain(OdDbDxfFiler *pFiler);
  void wrVer3PropsChain(OdDbDxfFiler *pFiler) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbVisualStyle object pointers.
*/
typedef OdSmartPtr<OdDbVisualStyle> OdDbVisualStylePtr;
void TOOLKIT_EXPORT oddbConfigureVisualStyles(OdDbDatabase* pDb);

#include "TD_PackPop.h"

#endif // OD_DBVISUALSTYLE_H
