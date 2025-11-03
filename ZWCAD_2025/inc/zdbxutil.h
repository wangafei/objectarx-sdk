
#ifndef ZD_DBXUTIL_H
#define ZD_DBXUTIL_H 1

#include "zadesk.h"
#include "zacdb.h"
#include "zacadstrc.h"
#include "zadsdef.h"
#include "zdbidar.h"
#include "zdbid.h"
#include "zgegbl.h"
#include "zgetol.h"
#include "zacutmem.h"
#include "zacgi.h"
#include "zacdbport.h"

#pragma pack (push, 8)

class ZcGeCurve3d;
class ZcGeMatrix3d;
class ZcGePoint3d;
class ZcGeVector3d;
class ZcDbCurve;
class ZcDbObject;
class ZcDbOle2Frame;
class ZcCmColor;
class ZcDbViewport;
struct ZcConstrainedGeometryDraggingInfo;
class ZcDbTextStyleTableRecord;
class ZcDbLinetypeTableRecord;

bool    zcdbWcs2Ucs(zds_point p, zds_point q, bool vec);
bool    zcdbWcs2Ecs(zds_point p, zds_point q, zds_point norm, bool vec);
bool    zcdbUcs2Wcs(zds_point p, zds_point q, bool vec);
bool    zcdbUcs2Ecs(zds_point p, zds_point q, zds_point norm, bool vec);
bool    zcdbEcs2Wcs(zds_point p, zds_point q, zds_point norm, bool vec);
bool    zcdbEcs2Ucs(zds_point p, zds_point q, zds_point norm, bool vec);

ZcGeVector3d     ucsXDir();
ZcGeVector3d     ucsYDir();
void			 ucsNormalVector(ZcGeVector3d& ucsNormalVec);
ZCDBCORE2D_PORT bool   isMSpaceActive(ZcDbDatabase* pDb);
ZcDbObjectId      zcdbGetCurVportTableRecordId(ZcDbDatabase* pDb);
ZcDbObjectId      zcdbGetCurVportId(ZcDbDatabase* pDb);
Zcad::ErrorStatus zcdbGetProxyInfo(ZcDbObject *pObj, ZTCHAR*& dxfName,
                                   ZTCHAR*& className, ZTCHAR*& appName);
bool    zcdbUcsMatrix(ZcGeMatrix3d& mat, ZcDbDatabase * pDb = nullptr);

Zcad::ErrorStatus zcdbGetExtnames(bool &value, ZcDbDatabase *pDb);
Zcad::ErrorStatus zcdbSetExtnames(ZcDbDatabase *pDb, bool value);

const ZTCHAR* zcdbGetReservedString(ZcDb::reservedStringEnumType reservedType,
    bool bGetLocalized = true);
const ZTCHAR* zcdbXlateReservedString(const ZTCHAR* strSource,
    bool bGetLocalized = true);
bool zcdbIsReservedString(const ZTCHAR* strString,
    ZcDb::reservedStringEnumType reservedType);


Zcad::ErrorStatus zcdbValidateDbConsistency(ZcDbObject*     pHostObject,
                                            ZcDbObjectId    objId,
                                            Zcad::ErrorStatus   es = Zcad::eOk);

Zcad::ErrorStatus zcdbValidateDbConsistency(ZcDbObject*     pHostObject,
                                            ZcDbDatabase*   pDatabase,
                                            Zcad::ErrorStatus   es = Zcad::eOk);

ZCDBCORE2D_PORT const ZTCHAR* zcdbGetMappedFontName(const ZTCHAR *fontName);

Zcad::ErrorStatus zcdbQueueAnnotationEntitiesForRegen(ZcDbDatabase* pDb);


bool zcdbPSLayoutAnnoAllVisible(ZcDbObjectId viewportEntityId);
bool zcdbPSLayoutAnnoAllVisible(ZcDbViewport* pVport);

Zcad::ErrorStatus zcdbGetCurUserViewportId(ZcDbDatabase* pDb,  ZcDbObjectId& vpId);

class ZCDBCORE2D_PORT ZcDbDisableAnnoAutoScale
{
public:
    ZcDbDisableAnnoAutoScale ();
    ~ZcDbDisableAnnoAutoScale ();

private:
    short mSaveAnnoAutoScale;
    short mSaveAnnoAutoScaleLayout;
};
Zcad::ErrorStatus zcdbGetUnitsConversion (ZcDb::UnitsValue from,
                                          ZcDb::UnitsValue to,
                                          double& conversionFactor);

ZCDBCORE2D_PORT bool ZSOFT_STDCALL zcdbDwkFileExists(const ZTCHAR *pszFileName);

int ZSOFT_STDCALL zcdbQueueForRegen(const ZcDbObjectId *pIdArray,
                                    int nNumIds);

class ZCDBCORE2D_PORT ZcDbCustomDynStyleReactor
{
public:
    ZcDbCustomDynStyleReactor();
    virtual ~ZcDbCustomDynStyleReactor();

    virtual ZcDbObjectId getCustomDynDimStyleId(ZcDbDatabase* pDb = nullptr);
    virtual ZcDbObjectId getCustomDynDimTextStyleId(ZcDbDatabase* pDb = nullptr);
    virtual ZcDbObjectId getCustomDynLineTypeId(ZcDbDatabase* pDb = nullptr);
    virtual ZcDbObjectId getCustomDynArrowTypeId(ZcDbDatabase* pDb = nullptr);
};

class ZCDBCORE2D_PORT ZcDbCustomDynStyleNotifier
{
public:
    ZcDbCustomDynStyleNotifier();
    ~ZcDbCustomDynStyleNotifier() = default;

    static ZcDbCustomDynStyleNotifier* instance();

    Zcad::ErrorStatus addReactor(ZcDbCustomDynStyleReactor* reactor);
    Zcad::ErrorStatus removeReactor(ZcDbCustomDynStyleReactor* reactor);

    ZcDbObjectId getCustomDynDimStyleId(ZcDbDatabase* pDb = nullptr);
    ZcDbObjectId getCustomDynDimTextStyleId(ZcDbDatabase* pDb = nullptr);
    ZcDbObjectId getCustomDynLineTypeId(ZcDbDatabase* pDb = nullptr);
    ZcDbObjectId getCustomDynArrowTypeId(ZcDbDatabase* pDb = nullptr);

private:
    ZcDbCustomDynStyleReactor* m_pReactor = nullptr;
};

ZCDBCORE2D_PORT ZcDbObjectId  zcdbGetDimStyleId(ZcDbDatabase* pDb, const ZTCHAR* styleName, const ZTCHAR* lockName);
ZCDBCORE2D_PORT ZcDbObjectId  zcdbGetDynDimStyleId( ZcDbDatabase* pDb = NULL );

Zcad::ErrorStatus
zcdbCreateViewByViewport( ZcDbDatabase *pDb,
                          ZcDbObjectId viewportId, 
                          const ZTCHAR* name,
                          const ZTCHAR* categoryName,
                          ZcDbObjectId labelBlockId,
                          ZcDbObjectId& view);

Zcad::ErrorStatus
zcdbOleHitTest(const ZcDbOle2Frame* pOleEnt,     
               const ZcGePoint3d&  wvpt, 
               const ZcGeVector3d& wvwdir);

Zcad::ErrorStatus
zcdbOleGetRotationMatrix(const ZcDbOle2Frame* pOleEnt,
                         ZcGeMatrix3d& rotMat);

Zcad::ErrorStatus
zcdbOleGetOriginalWidthHeight(const ZcDbOle2Frame* pOleEnt,
                              double& width, 
                              double& height);

Zcad::ErrorStatus
zcdbOleSetOriginalWidthHeight(const ZcDbOle2Frame* pOleEnt,
                              const double width, 
                              const double height);

Zcad::ErrorStatus
zcdbOleGetSelectedFontName(const ZcDbOle2Frame* pOleEnt,
                           ZTCHAR*& fontName);

Zcad::ErrorStatus
zcdbOleSetSelectedFontName(const ZcDbOle2Frame* pOleEnt,
                           const ZTCHAR* fontName);

Zcad::ErrorStatus
zcdbOleGetSelectedFontPointSize(const ZcDbOle2Frame* pOleEnt,
                                int& pointSize);

Zcad::ErrorStatus
zcdbOleSetSelectedFontPointSize(const ZcDbOle2Frame* pOleEnt,
                                const int pointSize);

Zcad::ErrorStatus
zcdbOleGetSelectedTextSizeInZcadUnits(const ZcDbOle2Frame* pOleEnt,
                                      double& sizeInZcadUnits);

Zcad::ErrorStatus
zcdbOleSetSelectedTextSizeInZcadUnits(const ZcDbOle2Frame* pOleEnt,
                                      const double sizeInZcadUnits);

Zcad::ErrorStatus
zcdbOleGetOriginalSelectedFontName(const ZcDbOle2Frame* pOleEnt,
                                   ZTCHAR*& fontName);

Zcad::ErrorStatus
zcdbOleSetOriginalSelectedFontName(const ZcDbOle2Frame* pOleEnt,
                                   const ZTCHAR* fontName);

Zcad::ErrorStatus
zcdbOleGetOriginalSelectedFontPointSize(const ZcDbOle2Frame* pOleEnt,
                                        int& pointSize);

Zcad::ErrorStatus
zcdbOleSetOriginalSelectedFontPointSize(const ZcDbOle2Frame* pOleEnt,
                                        const int pointSize);

Zcad::ErrorStatus
zcdbOleGetOriginalSelectedTextSizeInZcadUnits(const ZcDbOle2Frame* pOleEnt,
                                              double& sizeInZcadUnits);

Zcad::ErrorStatus
zcdbOleSetOriginalSelectedTextSizeInZcadUnits(const ZcDbOle2Frame* pOleEnt,
                                              const double sizeInZcadUnits);

bool 
zcdbGetDimTextBackground(ZcDbObject *pObj, 
                         int& bgFlag, 
                         ZcCmColor& bgColor);

bool 
zcdbSetDimTextBackground(ZcDbObject *pObj, 
                         int bgFlag, 
                         ZcCmColor* pBgColor,
                         bool autoClearOverride = true);

bool 
zcdbGetDimExtensionLength(ZcDbObject *pObj, 
						  double& fValue);

bool 
zcdbSetDimExtensionLength(ZcDbObject *pObj, 
						  double fValue,
						  bool autoClearOverride = true);

bool 
zcdbGetFixedLengthExtLineEnabled(ZcDbObject *pObj,
								 int& nValue);

bool 
zcdbSetFixedLengthExtLineEnabled(ZcDbObject *pObj, 
								 int nValue, 
								 bool autoClearOverride=true);

bool 
zcdbGetArcLengthSymbolPlacement(ZcDbObject *pObj,
								int& nValue);

bool 
zcdbSetArcLengthSymbolPlacement(ZcDbObject *pObj, 
								int nValue,
								bool autoClearOverride = true);
                          
bool 
zcdbGetDimLineLinetype(ZcDbObject *pObj,
					   ZcDbObjectId& oidValue);

bool 
zcdbSetDimLineLinetype(ZcDbObject *pObj,
					   ZcDbObjectId oidValue,
					   bool autoClearOverride = true);

bool 
zcdbGetDimExt1Linetype(ZcDbObject *pObj,
					   ZcDbObjectId& oidValue);

bool 
zcdbSetDimExt1Linetype(ZcDbObject *pObj,
					   ZcDbObjectId oidValue,
					   bool autoClearOverride = true);

bool 
zcdbGetDimExt2Linetype(ZcDbObject *pObj,
					   ZcDbObjectId& oidValue);

bool 
zcdbSetDimExt2Linetype(ZcDbObject *pObj,
					   ZcDbObjectId oidValue,
					   bool autoClearOverride = true);

bool 
zcdbGetLargeRadDimJogAngle(ZcDbObject *pObj,
						   double& fJogAngle);

bool 
zcdbSetLargeRadDimJogAngle(ZcDbObject *pObj, 
						   double fJogAngle,
						   bool autoClearOverride = true);

bool 
zcdbGetDimFlipArrow(ZcDbObject *pObj,
					int& nValue);
 
bool 
zcdbSetDimFlipArrow(ZcDbObject *pObj, 
					int nValue,
					bool autoClearOverride = true);

bool 
zcdbGetDimTextDirection(ZcDbObject *pObj,
                    int& nValue);

bool 
zcdbSetDimTextDirection(ZcDbObject *pObj, 
                    int nValue,
                    bool autoClearOverride = true);

bool 
zcdbGetDimFlipArrowWhich(ZcDbObject *pObj,
						 int& nValue);

bool 
zcdbSetDimFlipArrowWhich(ZcDbObject *pObj, 
						 int nValue,
						 bool autoClearOverride = true);

bool zcdbGetExemptCheckFlag(ZcDbObject *pObj, int& bitFlags);

bool zcdbSetExemptCheckFlag(ZcDbObject *pObj, int bitFlags);

bool
zcdbGetDimJogSymbolSize(ZcDbObject *pObj,
                        int& dimJagFlag,
                        double& dimJagSize);
bool
zcdbSetDimJogSymbolSize(ZcDbObject *pObj,
                        int dimJagFlag,
                        const double dimJagSize,
                        bool autoClearOverride = true);
bool
zcdbGetDimJogSymbolPosition(ZcDbObject *pObj,
                        int& dimJagFlag,
                        ZcGePoint3d& pos);
bool
zcdbSetDimJogSymbolPosition(ZcDbObject *pObj,
                        int& dimJagFlag,
                        const ZcGePoint3d& pos,
                        bool autoClearOverride = true);

bool
zcdbGetRadialExtensionAngles(ZcDbObject *pObj,
                             int& dimExtFlag,
                             double& dimExtAng1,
                             double& dimExtAng2);

bool
zcdbSetRadialExtensionAngles(ZcDbObject *pObj,
                             int dimExtFlag,
                             double dimExtAng1,
                             double dimExtAng2);

bool
zcdbGetDimAngExtOn(ZcDbObject *pObj,
                             int& dimExtFlag);

bool
zcdbSetDimAngExtOn(ZcDbObject *pObj,
                             int dimExtFlag);

bool
zcdbGetDimTolAlign(ZcDbObject *pObj,
                             int& dimTolAlignFlag);

bool
zcdbSetDimTolAlign(ZcDbObject *pObj,
                             int dimTolAlignFlag,
                             bool autoClearOverride = true);
bool
zcdbGetDimBreakSize(ZcDbObject *pObj,
                    double& dimBreakSize);
bool
zcdbSetDimBreakSize(ZcDbObject *pObj,
                    double dimBreakSize,
                    bool autoClearOverride = true);

ZcDbObjectId zcdbGetViewportVisualStyle();
Zcad::ErrorStatus zcdbSetViewportVisualStyle(ZcDbObjectId visualStyleId);

ZCDBCORE2D_PORT int
zcdbGetVisualStyleIndexById(ZcDbObjectId visualStyleId);	

ZCDBCORE2D_PORT int
zcdbGetVisualStyleIndexByName(const wchar_t * visualStyleName);	

ZCDBCORE2D_PORT Zcad::ErrorStatus
zcdbGetVisualStyleIdByIndex(ZcDbObjectId& visualStyleId, int visualStyleIndex);	

Zcad::ErrorStatus zcdbForceTextAdjust(const ZcDbObjectIdArray& objIds);

bool zcdbIsInLongTransaction(ZcDbObjectId id);

Zcad::ErrorStatus zcdbSwapBlockEntities(ZcDbBlockTableRecord* pBlock1, ZcDbBlockTableRecord* pBlock2); 


ZCDBCORE2D_PORT Zcad::ErrorStatus zcdbAddConstrainedGeometryDraggingInfo(
	const ZcConstrainedGeometryDraggingInfo* pDraggingInfo);

Zcad::ErrorStatus zcdbConvertZcDbCurveToGelibCurve(const ZcDbCurve* dbCurve,
	ZcGeCurve3d*& pGeCurve, const ZcGeTol& tol = ZcGeContext::gTol);

ZCDBCORE2D_PORT
Zcad::ErrorStatus zcdbConvertGelibCurveToZcDbCurve(const ZcGeCurve3d& geCurve,
	ZcDbCurve*& pDbCurve, ZcGeVector3d* normal = NULL, const ZcGeTol& tol = ZcGeContext::gTol);

Zcad::ErrorStatus zcdbAssignGelibCurveToZcDbCurve(const ZcGeCurve3d& geCurve,
	ZcDbCurve* pDbCurve, ZcGeVector3d* normal = NULL, const ZcGeTol& tol = ZcGeContext::gTol);

ZCDB_PORT bool zcdbIsEnabledTightExtents();

ZCDB_PORT void zcdbSetEnableTightExtents(bool bEnable);

bool regAppName(const wchar_t* pAppName, ZcDbDatabase* pDatabase);

#pragma pack (pop)
#endif 
