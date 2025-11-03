#pragma once

#include "dbxutil.h"

class                       GcDbOle2Frame;
struct                      GcConstrainedGeometryDraggingInfo;

GCDB_DLL_DECL Gcad::ErrorStatus gcdbValidateDbConsistency(GcDbObject* pHostObject,
  GcDbObjectId objId,
  Gcad::ErrorStatus es = Gcad::eOk);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbValidateDbConsistency(GcDbObject* pHostObject,
  GcDbDatabase* pDatabase,
  Gcad::ErrorStatus   es = Gcad::eOk);

class GcDbDisableAnnoAutoScale
{
public:
  GcDbDisableAnnoAutoScale();
  ~GcDbDisableAnnoAutoScale();
};

GCDB_DLL_DECL Gcad::ErrorStatus gcdbQueueAnnotationEntitiesForRegen(GcDbDatabase* pDb);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleHitTest(const GcDbOle2Frame* pOleEnt,
  const GcGePoint3d& wvpt,
  const GcGeVector3d& wvwdir);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetRotationMatrix(const GcDbOle2Frame* pOleEnt,
  GcGeMatrix3d& rotMat);

// Original width and height is used in
// calculating reset scale
GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetOriginalWidthHeight(const GcDbOle2Frame* pOleEnt,
  double& width,
  double& height);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetOriginalWidthHeight(const GcDbOle2Frame* pOleEnt,
  const double width,
  const double height);

// Selected font name, point size and size in Gcad units
// is to persist the selected font name from the 
// OLE Text Size dialog
GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetSelectedFontName(const GcDbOle2Frame* pOleEnt,
  GCHAR*& fontName);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetSelectedFontName(const GcDbOle2Frame* pOleEnt,
  const GCHAR* fontName);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  int& pointSize);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  const int pointSize);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  double& sizeInGcadUnits);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  const double sizeInGcadUnits);

// Originally selected font name, point size and size in Gcad units
// is to support Reset. 
GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetOriginalSelectedFontName(const GcDbOle2Frame* pOleEnt,
  GCHAR*& fontName);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetOriginalSelectedFontName(const GcDbOle2Frame* pOleEnt,
  const GCHAR* fontName);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetOriginalSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  int& pointSize);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetOriginalSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  const int pointSize);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleGetOriginalSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  double& sizeInGcadUnits);

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbOleSetOriginalSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  const double sizeInGcadUnits);

GCDB_DLL_DECL bool
gcdbGetDimTextBackground(GcDbObject *pObj,
  int& bgFlag,
  GcCmColor& bgColor);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimTextBackground(GcDbObject *pObj,
  int bgFlag,
  GcCmColor* pBgColor,
  bool autoClearOverride = true);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimExtensionLength(GcDbObject *pObj,
  double& fValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimExtensionLength(GcDbObject *pObj,
  double fValue,
  bool autoClearOverride = true);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetFixedLengthExtLineEnabled(GcDbObject *pObj,
  int& nValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetFixedLengthExtLineEnabled(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetArcLengthSymbolPlacement(GcDbObject *pObj,
  int& nValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetArcLengthSymbolPlacement(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

// Internal use only.                           
GCDB_DLL_DECL bool
gcdbGetDimLineLinetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimLineLinetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimExt1Linetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimExt1Linetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

// Internal use only.                        
GCDB_DLL_DECL bool
gcdbGetDimExt2Linetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimExt2Linetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

// Internal use only.                        
GCDB_DLL_DECL bool
gcdbGetLargeRadDimJogAngle(GcDbObject *pObj,
  double& fJogAngle);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetLargeRadDimJogAngle(GcDbObject *pObj,
  double fJogAngle,
  bool autoClearOverride = true);

// Internal use only.                                 
GCDB_DLL_DECL bool
gcdbGetDimFlipArrow(GcDbObject *pObj,
  int& nValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimFlipArrow(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

// Internal use only.                                 
GCDB_DLL_DECL bool
gcdbGetDimTextDirection(GcDbObject *pObj,
  int& nValue);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimTextDirection(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

// Internal use only.                     
GCDB_DLL_DECL bool
gcdbGetDimFlipArrowWhich(GcDbObject *pObj,
  int& nValue);

// Internal use only.                          
GCDB_DLL_DECL bool
gcdbSetDimFlipArrowWhich(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

// Spago "DIMJAG" feature extension.
// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimJogSymbolSize(GcDbObject *pObj,
  int& dimJagFlag,
  double& dimJagSize);
// Internal use only.
GCDB_DLL_DECL bool
gcdbSetDimJogSymbolSize(GcDbObject *pObj,
  int dimJagFlag,
  const double dimJagSize,
  bool autoClearOverride = true);

// Internal use only.
GCDB_DLL_DECL bool
gcdbGetDimJogSymbolPosition(GcDbObject *pObj,
  int& dimJagFlag,
  GcGePoint3d& pos);
// Internal use only.
GCDB_DLL_DECL bool
gcdbSetDimJogSymbolPosition(GcDbObject *pObj,
  int& dimJagFlag,
  const GcGePoint3d& pos,
  bool autoClearOverride = true);

// Spago "DIMRADIUS" arc extension.
// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetRadialExtensionAngles(GcDbObject *pObj,
  int& dimExtFlag,
  double& dimExtAng1,
  double& dimExtAng2);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetRadialExtensionAngles(GcDbObject *pObj,
  int dimExtFlag,
  double dimExtAng1,
  double dimExtAng2);

// Spago "DIMANGULAR" quadrant extension.
// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimAngExtOn(GcDbObject *pObj,
  int& dimExtFlag);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimAngExtOn(GcDbObject *pObj,
  int dimExtFlag);

// Spago Tolerance Dimension Alignment extension.
// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimTolAlign(GcDbObject *pObj,
  int& dimTolAlignFlag);

// Internal use only. 
GCDB_DLL_DECL bool
gcdbSetDimTolAlign(GcDbObject *pObj,
  int dimTolAlignFlag,
  bool autoClearOverride = true);

// Spago "DIMBREAK" feature extension.
// Internal use only. 
GCDB_DLL_DECL bool
gcdbGetDimBreakSize(GcDbObject *pObj,
  double& dimBreakSize);
// Internal use only.
GCDB_DLL_DECL bool
gcdbSetDimBreakSize(GcDbObject *pObj,
  double dimBreakSize,
  bool autoClearOverride = true);

// Returns true if this object is in a long transaction.
GCDB_DLL_DECL bool gcdbIsInLongTransaction(GcDbObjectId id);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbAddConstrainedGeometryDraggingInfo(
  const GcConstrainedGeometryDraggingInfo* pDraggingInfo);
