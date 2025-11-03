/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBXUTIL_H
#define GD_DBXUTIL_H 1

#include "gsoft.h"
#include "gcadstrc.h"
#include "gsoft.h"
#include "gdsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "gcutmem.h"
#include "gcgi.h"

#pragma pack (push, 8)

class GcGeMatrix3d;
class GcDbObject;
class GcDbOle2Frame;
class GcCmColor;
class GcDbViewport;
struct GcConstrainedGeometryDraggingInfo;
class GcDbTextStyleTableRecord;
class GcDbLinetypeTableRecord;

GCCORE_PORT bool    gcdbWcs2Ucs(gds_point p, gds_point q, bool vec);
GCCORE_PORT bool    gcdbWcs2Ecs(gds_point p, gds_point q, gds_point norm, bool vec);
GCCORE_PORT bool    gcdbUcs2Wcs(gds_point p, gds_point q, bool vec);
GCCORE_PORT bool    gcdbUcs2Ecs(gds_point p, gds_point q, gds_point norm, bool vec);
GCCORE_PORT bool    gcdbEcs2Wcs(gds_point p, gds_point q, gds_point norm, bool vec);
GCCORE_PORT bool    gcdbEcs2Ucs(gds_point p, gds_point q, gds_point norm, bool vec);

GCCORE_PORT GcGeVector3d     ucsXDir();
GCCORE_PORT GcGeVector3d     ucsYDir();
GCCORE_PORT void             ucsNormalVector(GcGeVector3d& ucsNormalVec);
GCCORE_PORT bool   isMSpaceActive(GcDbDatabase* pDb);

GCCORE_PORT GcDbObjectId      gcdbGetCurVportTableRecordId(GcDbDatabase* pDb);
GCCORE_PORT GcDbObjectId      gcdbGetCurVportId(GcDbDatabase* pDb);
GCCORE_PORT Gcad::ErrorStatus gcdbGetProxyInfo(GcDbObject *pObj, GCHAR*& dxfName,
  GCHAR*& className, GCHAR*& appName);
GCCORE_PORT bool    gcdbUcsMatrix(GcGeMatrix3d& mat, GcDbDatabase * pDb = nullptr);

GCDB_PORT Gcad::ErrorStatus gcdbGetExtnames(bool &value, GcDbDatabase *pDb);
GCDB_PORT Gcad::ErrorStatus gcdbSetExtnames(GcDbDatabase *pDb, bool value);

GCCORE_PORT const GCHAR* gcdbGetReservedString(GcDb::reservedStringEnumType reservedType,
  bool bGetLocalized = true);
GCCORE_PORT const GCHAR* gcdbXlateReservedString(const GCHAR* strSource,
  bool bGetLocalized = true);
GCCORE_PORT bool gcdbIsReservedString(const GCHAR* strString,
  GcDb::reservedStringEnumType reservedType);

GCCORE_PORT Gcad::ErrorStatus gcdbValidateDbConsistency(GcDbObject*     pHostObject,
  GcDbObjectId    objId,
  Gcad::ErrorStatus   es = Gcad::eOk);

GCCORE_PORT Gcad::ErrorStatus gcdbValidateDbConsistency(GcDbObject*     pHostObject,
  GcDbDatabase*   pDatabase,
  Gcad::ErrorStatus   es = Gcad::eOk);

GCCORE_PORT const GCHAR* gcdbGetMappedFontName(const GCHAR *fontName);

GCCORE_PORT Gcad::ErrorStatus gcdbQueueAnnotationEntitiesForRegen(GcDbDatabase* pDb);

GCCORE_PORT bool gcdbPSLayoutAnnoAllVisible(GcDbObjectId viewportEntityId);

GCCORE_PORT bool gcdbPSLayoutAnnoAllVisible(GcDbViewport* pVport);

GCCORE_PORT Gcad::ErrorStatus gcdbGetCurUserViewportId(GcDbDatabase* pDb, GcDbObjectId& vpId);

class GcDbDisableAnnoAutoScale
{
public:
  GcDbDisableAnnoAutoScale();
  ~GcDbDisableAnnoAutoScale();

private:
  short mSaveAnnoAutoScale;
  short mSaveAnnoAutoScaleLayout;
};

GCCORE_PORT Gcad::ErrorStatus gcdbGetUnitsConversion(GcDb::UnitsValue from,
  GcDb::UnitsValue to,
  double& conversionFactor);

GCCORE_PORT bool GSOFT_STDCALL gcdbDwkFileExists(const GCHAR *pszFileName);

GCCORE_PORT int GSOFT_STDCALL gcdbQueueForRegen(const GcDbObjectId *pIdArray,
  int nNumIds);

class GcDbCustomDynStyleReactor
{
public:
  GCCORE_PORT GcDbCustomDynStyleReactor();
  GCCORE_PORT virtual ~GcDbCustomDynStyleReactor();

  GCCORE_PORT virtual GcDbObjectId getCustomDynDimStyleId(GcDbDatabase* = nullptr);
  GCCORE_PORT virtual GcDbObjectId getCustomDynDimTextStyleId(GcDbDatabase* = nullptr);
  GCCORE_PORT virtual GcDbObjectId getCustomDynLineTypeId(GcDbDatabase* = nullptr);
  GCCORE_PORT virtual GcDbObjectId getCustomDynArrowTypeId(GcDbDatabase* = nullptr);
};

class GcDbCustomDynStyleNotifier
{
public:
  GCCORE_PORT GcDbCustomDynStyleNotifier();
  GCCORE_PORT ~GcDbCustomDynStyleNotifier() = default;

  GCCORE_PORT static GcDbCustomDynStyleNotifier* instance();

  GCCORE_PORT Gcad::ErrorStatus addReactor(GcDbCustomDynStyleReactor* reactor);
  GCCORE_PORT Gcad::ErrorStatus removeReactor(GcDbCustomDynStyleReactor* reactor);

  GCCORE_PORT GcDbObjectId getCustomDynDimStyleId(GcDbDatabase* pDb = nullptr);
  GCCORE_PORT GcDbObjectId getCustomDynDimTextStyleId(GcDbDatabase* pDb = nullptr);
  GCCORE_PORT GcDbObjectId getCustomDynLineTypeId(GcDbDatabase* pDb = nullptr);
  GCCORE_PORT GcDbObjectId getCustomDynArrowTypeId(GcDbDatabase* pDb = nullptr);

private:
  GcDbCustomDynStyleReactor* m_pReactor = nullptr;
};

GCCORE_PORT GcDbObjectId  gcdbGetDynDimStyleId(GcDbDatabase* pDb = NULL);

GCCORE_PORT Gcad::ErrorStatus
gcdbCreateViewByViewport(GcDbDatabase *pDb,
  GcDbObjectId viewportId,
  const GCHAR* name,
  const GCHAR* categoryName,
  GcDbObjectId labelBlockId,
  GcDbObjectId& view);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleHitTest(const GcDbOle2Frame* pOleEnt,
  const GcGePoint3d&  wvpt,
  const GcGeVector3d& wvwdir);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetRotationMatrix(const GcDbOle2Frame* pOleEnt,
  GcGeMatrix3d& rotMat);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetOriginalWidthHeight(const GcDbOle2Frame* pOleEnt,
  double& width,
  double& height);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetOriginalWidthHeight(const GcDbOle2Frame* pOleEnt,
  const double width,
  const double height);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetSelectedFontName(const GcDbOle2Frame* pOleEnt,
  GCHAR*& fontName);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetSelectedFontName(const GcDbOle2Frame* pOleEnt,
  const GCHAR* fontName);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  int& pointSize);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  const int pointSize);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  double& sizeInGcadUnits);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  const double sizeInGcadUnits);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetOriginalSelectedFontName(const GcDbOle2Frame* pOleEnt,
  GCHAR*& fontName);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetOriginalSelectedFontName(const GcDbOle2Frame* pOleEnt,
  const GCHAR* fontName);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetOriginalSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  int& pointSize);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetOriginalSelectedFontPointSize(const GcDbOle2Frame* pOleEnt,
  const int pointSize);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleGetOriginalSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  double& sizeInGcadUnits);

GCCORE_PORT Gcad::ErrorStatus
gcdbOleSetOriginalSelectedTextSizeInGcadUnits(const GcDbOle2Frame* pOleEnt,
  const double sizeInGcadUnits);

GCCORE_PORT bool
gcdbGetDimTextBackground(GcDbObject *pObj,
  int& bgFlag,
  GcCmColor& bgColor);

GCCORE_PORT bool
gcdbSetDimTextBackground(GcDbObject *pObj,
  int bgFlag,
  GcCmColor* pBgColor,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimExtensionLength(GcDbObject *pObj,
  double& fValue);

GCCORE_PORT bool
gcdbSetDimExtensionLength(GcDbObject *pObj,
  double fValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetFixedLengthExtLineEnabled(GcDbObject *pObj,
  int& nValue);

GCCORE_PORT bool
gcdbSetFixedLengthExtLineEnabled(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetArcLengthSymbolPlacement(GcDbObject *pObj,
  int& nValue);

GCCORE_PORT bool
gcdbSetArcLengthSymbolPlacement(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimLineLinetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

GCCORE_PORT bool
gcdbSetDimLineLinetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimExt1Linetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

GCCORE_PORT bool
gcdbSetDimExt1Linetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimExt2Linetype(GcDbObject *pObj,
  GcDbObjectId& oidValue);

GCCORE_PORT bool
gcdbSetDimExt2Linetype(GcDbObject *pObj,
  GcDbObjectId oidValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetLargeRadDimJogAngle(GcDbObject *pObj,
  double& fJogAngle);

GCCORE_PORT bool
gcdbSetLargeRadDimJogAngle(GcDbObject *pObj,
  double fJogAngle,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimFlipArrow(GcDbObject *pObj,
  int& nValue);

GCCORE_PORT bool
gcdbSetDimFlipArrow(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimTextDirection(GcDbObject *pObj,
  int& nValue);

GCCORE_PORT bool
gcdbSetDimTextDirection(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimFlipArrowWhich(GcDbObject *pObj,
  int& nValue);

GCCORE_PORT bool
gcdbSetDimFlipArrowWhich(GcDbObject *pObj,
  int nValue,
  bool autoClearOverride = true);

GCCORE_PORT bool gcdbGetExemptCheckFlag(GcDbObject *pObj, int& bitFlags);

GCCORE_PORT bool gcdbSetExemptCheckFlag(GcDbObject *pObj, int bitFlags);

GCCORE_PORT bool
gcdbGetDimJogSymbolSize(GcDbObject *pObj,
  int& dimJagFlag,
  double& dimJagSize);
GCCORE_PORT bool
gcdbSetDimJogSymbolSize(GcDbObject *pObj,
  int dimJagFlag,
  const double dimJagSize,
  bool autoClearOverride = true);
GCCORE_PORT bool
gcdbGetDimJogSymbolPosition(GcDbObject *pObj,
  int& dimJagFlag,
  GcGePoint3d& pos);
GCCORE_PORT bool
gcdbSetDimJogSymbolPosition(GcDbObject *pObj,
  int& dimJagFlag,
  const GcGePoint3d& pos,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetRadialExtensionAngles(GcDbObject *pObj,
  int& dimExtFlag,
  double& dimExtAng1,
  double& dimExtAng2);

GCCORE_PORT bool
gcdbSetRadialExtensionAngles(GcDbObject *pObj,
  int dimExtFlag,
  double dimExtAng1,
  double dimExtAng2);

GCCORE_PORT bool
gcdbGetDimAngExtOn(GcDbObject *pObj,
  int& dimExtFlag);

GCCORE_PORT bool
gcdbSetDimAngExtOn(GcDbObject *pObj,
  int dimExtFlag);

GCCORE_PORT bool
gcdbGetDimTolAlign(GcDbObject *pObj,
  int& dimTolAlignFlag);

GCCORE_PORT bool
gcdbSetDimTolAlign(GcDbObject *pObj,
  int dimTolAlignFlag,
  bool autoClearOverride = true);

GCCORE_PORT bool
gcdbGetDimBreakSize(GcDbObject *pObj,
  double& dimBreakSize);
GCCORE_PORT bool
gcdbSetDimBreakSize(GcDbObject *pObj,
  double dimBreakSize,
  bool autoClearOverride = true);

GCCORE_PORT GcDbObjectId gcdbGetViewportVisualStyle();
GCCORE_PORT Gcad::ErrorStatus gcdbSetViewportVisualStyle(GcDbObjectId visualStyleId);

GCCORE_PORT int
gcdbGetVisualStyleIndexById(GcDbObjectId visualStyleId);
GCCORE_PORT int
gcdbGetVisualStyleIndexByName(const wchar_t * visualStyleName);
GCCORE_PORT Gcad::ErrorStatus
gcdbGetVisualStyleIdByIndex(GcDbObjectId& visualStyleId, int visualStyleIndex);

GCCORE_PORT Gcad::ErrorStatus gcdbForceTextAdjust(const GcDbObjectIdArray& objIds);

GCCORE_PORT bool gcdbIsInLongTransaction(GcDbObjectId id);

GCCORE_PORT Gcad::ErrorStatus gcdbAddConstrainedGeometryDraggingInfo(
  const GcConstrainedGeometryDraggingInfo* pDraggingInfo);

GCCORE_PORT Gcad::ErrorStatus gcdbConvertGcDbCurveToGelibCurve(const GcDbCurve* dbCurve,
  GcGeCurve3d*& pGeCurve, const GcGeTol& tol = GcGeContext::gTol);

GCCORE_PORT
Gcad::ErrorStatus gcdbConvertGelibCurveToGcDbCurve(const GcGeCurve3d& geCurve,
  GcDbCurve*& pDbCurve, GcGeVector3d* normal = NULL, const GcGeTol& tol = GcGeContext::gTol);

GCCORE_PORT Gcad::ErrorStatus gcdbAssignGelibCurveToGcDbCurve(const GcGeCurve3d& geCurve,
  GcDbCurve* pDbCurve, GcGeVector3d* normal = NULL, const GcGeTol& tol = GcGeContext::gTol);

#pragma pack (pop)
#endif 