#pragma once

#include "gcadstd.h"
#include "gcdb.h"
#include "gdsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "gcutmem.h"
#include "windows.h"
#include "gcgi.h"
#include "geassign.h"
#include "dbcurve.h"

#pragma pack (push, 8)

class GcGeMatrix3d;
class GcDbObject;
class GcDbViewport;

GCDB_DLL_DECL bool gcdbUcsMatrix(GcGeMatrix3d& mat, GcDbDatabase * pDb = NULL);
GCDB_DLL_DECL bool gcdbWcs2Ucs(gds_point p, gds_point q, bool vec);
GCDB_DLL_DECL bool gcdbWcs2Ecs(gds_point p, gds_point q, gds_point norm, bool vec);
GCDB_DLL_DECL bool gcdbUcs2Wcs(gds_point p, gds_point q, bool vec);
GCDB_DLL_DECL bool gcdbUcs2Ecs(gds_point p, gds_point q, gds_point norm, bool vec);
GCDB_DLL_DECL bool gcdbEcs2Wcs(gds_point p, gds_point q, gds_point norm, bool vec);
GCDB_DLL_DECL bool gcdbEcs2Ucs(gds_point p, gds_point q, gds_point norm, bool vec);

GCDB_DLL_DECL GcGeVector3d     ucsXDir();
GCDB_DLL_DECL GcGeVector3d     ucsYDir();
GCDB_DLL_DECL void             ucsNormalVector(GcGeVector3d& ucsNormalVec);

GCDB_DLL_DECL GcDbObjectId gcdbGetCurVportTableRecordId(GcDbDatabase* pDb);
GCDB_DLL_DECL GcDbObjectId gcdbGetCurVportId(OdDbDatabase* pDb);
GCDB_DLL_DECL Gcad::ErrorStatus  gcdbGetProxyInfo(OdDbObject *pObj, GCHAR*& dxfName, GCHAR*& className, GCHAR*& appName);

GCDB_DLL_DECL const GCHAR* gcdbGetReservedString(GcDb::reservedStringEnumType reservedType, bool bGetLocalized = true);
GCDB_DLL_DECL const GCHAR* gcdbXlateReservedString(const GCHAR* strSource, bool bGetLocalized = true);
GCDB_DLL_DECL bool gcdbIsReservedString(const GCHAR* strString, GcDb::reservedStringEnumType reservedType);

bool HCCAD_STDCALL gcdbDwkFileExists(const GCHAR *pszFileName);
GCDB_DLL_DECL int  HCCAD_STDCALL gcdbQueueForRegen(const GcDbObjectId *pIdArray, int nNumIds);

GcDbObjectId  gcdbGetDynDimStyleId( OdDbDatabase* pDb = NULL );

GCDB_DLL_DECL bool gcdbGetPreviewBitmapFromDwg(const GCHAR* pszDwgfilename, HBITMAP* pPreviewBmp, HPALETTE* pRetPal);
GCDB_DLL_DECL bool gcdbDisplayPreviewFromDwg(const GCHAR * pszDwgfilename,void* pPreviewWnd,const Hccad::UInt32* pBgColor = NULL);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbGetCurUserViewportId(OdDbDatabase* pDb,  GcDbObjectId& vpId);

// gcdbGetUnitsConversion
//
// Obtains the double value that represents the differnce in scale between two
// GcDb::UnitsValue enumerations. The returned conversion factor provides the
// multiplier needed to convert units measured in "from" units to the units
// measured in "to" units. 
// 
//   toValue = conversionFactor * fromValue
//
// (For example, if the "to" units are millimeters and the "from" units are
// inches the conversion factor is 25.4).
//   
// Returns eOk if succesful. Returns eInvalidInput if either of the UnitsValue
// enums are invalid.

GCDB_DLL_DECL Gcad::ErrorStatus gcdbGetUnitsConversion (GcDb::UnitsValue from,
                                          GcDb::UnitsValue to,
                                          double& conversionFactor);

/// <summary>
/// Map the font that will be used given a font name.
/// </summary>
/// <param name="fontName">Input font name.</param>
/// <returns>A mapped(substitute) font name or NULL if there is no substitution.
/// </returns>
GCDB_DLL_DECL const GCHAR* gcdbGetMappedFontName(const GCHAR *fontName);

GCDB_DLL_DECL bool gcdbPSLayoutAnnoAllVisible(GcDbObjectId viewportEntityId);

GCDB_DLL_DECL bool gcdbPSLayoutAnnoAllVisible(GcDbViewport* pVport);


// gcdbForceTextAdjust()
// Forces the text to be adjusted in all text objects in the objectid array.
// objIds: input array of GcDbObjectId objects whose text will be adjusted.
//         Supported objects are GcDbText, GcDbBlockReference and GcDbBlockTableRecord.
GCDB_DLL_DECL Gcad::ErrorStatus gcdbForceTextAdjust(const GcDbObjectIdArray& objIds);

// get/set a flag for dimstyle, linetype and layer object to exempt from
// CAD STANDARD check.
// pObj: pointer to AcDbObject
// bitFlags = 0x00:   No Exemption  
// bitFlags = 0x01:   Exempt from CAD Standard check
// 
GCDB_DLL_DECL bool gcdbGetExemptCheckFlag(GcDbObject *pObj, int& bitFlags);

GCDB_DLL_DECL bool gcdbSetExemptCheckFlag(GcDbObject *pObj, int bitFlags);

// Visual Style from viewport
GCDB_DLL_DECL GcDbObjectId gcdbGetViewportVisualStyle();
GCDB_DLL_DECL Gcad::ErrorStatus gcdbSetViewportVisualStyle(GcDbObjectId visualStyleId);

GCDB_DLL_DECL bool gcdbIsCustomObject(const GcDbObjectId& id);

GCDB_DLL_DECL void gcdbConvertHslToRgb(const GcGeVector3d& hsl, GcGeVector3d& rgb);
GCDB_DLL_DECL void gcdbConvertRgbToHsl(const GcGeVector3d& rgb, GcGeVector3d& hsl);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbCreateViewByViewport(
    GcDbDatabase * pDb, 
    GcDbObjectId viewportId, 
    const GCHAR* name, 
    const GCHAR* categoryName, 
    GcDbObjectId labelBlockId, 
    GcDbObjectId& view
);


GCDB_DLL_DECL Gcad::ErrorStatus gcdbConvertGcDbCurveToGelibCurve(const GcDbCurve* dbCurve,
  GcGeCurve3d*& pGeCurve, const GcGeTol& tol = GcGeContext::gTol);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbConvertGelibCurveToGcDbCurve(const GcGeCurve3d& geCurve,
  GcDbCurve*& pDbCurve, GcGeVector3d* normal = NULL, const GcGeTol& tol = GcGeContext::gTol);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbAssignGelibCurveToGcDbCurve(const GcGeCurve3d& geCurve,
  GcDbCurve* pDbCurve, GcGeVector3d* normal = NULL, const GcGeTol& tol = GcGeContext::gTol);

#pragma pack (pop)
