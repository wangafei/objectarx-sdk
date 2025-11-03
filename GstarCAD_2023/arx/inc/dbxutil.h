/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/dbxutil.h"
#include "adesk.h"
#include "acadstrc.h"
#include "adsdef.h"
#include "dbidar.h"
#include "dbid.h"
#include "acutmem.h"
#include "acgi.h"

#define	Acad 	Gcad
#define	AcDb 	GcDb
#define ACHAR	GCHAR
#define	AcCmColor 	GcCmColor
#define ads_point      gds_point
#define	acdbWcs2Ucs 	gcdbWcs2Ucs
#define	acdbWcs2Ecs 	gcdbWcs2Ecs
#define	acdbUcs2Wcs 	gcdbUcs2Wcs
#define	acdbUcs2Ecs 	gcdbUcs2Ecs
#define	acdbEcs2Wcs 	gcdbEcs2Wcs
#define	acdbEcs2Ucs 	gcdbEcs2Ucs
#define	ADESK_STDCALL 	GSOFT_STDCALL
#define	AcGeVector3d 	GcGeVector3d
#define	AcDbDatabase 	GcDbDatabase
#define	AcDbObjectId 	GcDbObjectId
#define	AcDbObject 	GcDbObject
#define	AcGeMatrix3d 	GcGeMatrix3d
#define	acdbUcsMatrix 	gcdbUcsMatrix
#define	acdbGetExtnames 	gcdbGetExtnames
#define	acdbSetExtnames 	gcdbSetExtnames
#define	acdbGetProxyInfo 	gcdbGetProxyInfo
#define	acdbGetCurVportId 	gcdbGetCurVportId
#define	acdbGetReservedString 	gcdbGetReservedString
#define	acdbXlateReservedString 	gcdbXlateReservedString
#define	acdbIsReservedString 	gcdbIsReservedString
#define acdbValidateDbConsistency gcdbValidateDbConsistency
#define acdbGetMappedFontName gcdbGetMappedFontName
#define acdbGetUnitsConversion gcdbGetUnitsConversion
#define	acdbDwkFileExists 	gcdbDwkFileExists
#define	acdbQueueForRegen 	gcdbQueueForRegen
#define AcDbCustomDynStyleReactor GcDbCustomDynStyleReactor
#define AcDbCustomDynStyleNotifier GcDbCustomDynStyleNotifier
#define	acdbGetDynDimStyleId 	gcdbGetDynDimStyleId
#define acdbCreateViewByViewport gcdbCreateViewByViewport
#define acdbGetCurVportTableRecordId gcdbGetCurVportTableRecordId
#define acdbQueueAnnotationEntitiesForRegen gcdbQueueAnnotationEntitiesForRegen
#define	AcDbOle2Frame 	GcDbOle2Frame
#define	AcGePoint3d 	GcGePoint3d
#define acdbOleHitTest gcdbOleHitTest
#define acdbOleGetRotationMatrix gcdbOleGetRotationMatrix
#define acdbOleGetOriginalWidthHeight gcdbOleGetOriginalWidthHeight
#define acdbOleSetOriginalWidthHeight gcdbOleSetOriginalWidthHeight
#define acdbOleGetSelectedFontName gcdbOleGetSelectedFontName
#define acdbOleSetSelectedFontName gcdbOleSetSelectedFontName
#define acdbOleGetSelectedFontPointSize gcdbOleGetSelectedFontPointSize
#define acdbOleSetSelectedFontPointSize gcdbOleSetSelectedFontPointSize
#define acdbOleGetSelectedTextSizeInAcadUnits gcdbOleGetSelectedTextSizeInGcadUnits
#define acdbOleSetSelectedTextSizeInAcadUnits gcdbOleSetSelectedTextSizeInGcadUnits
#define acdbOleGetOriginalSelectedFontName gcdbOleGetOriginalSelectedFontName
#define acdbOleSetOriginalSelectedFontName gcdbOleSetOriginalSelectedFontName
#define acdbOleGetOriginalSelectedFontPointSize gcdbOleGetOriginalSelectedFontPointSize
#define acdbOleSetOriginalSelectedFontPointSize gcdbOleSetOriginalSelectedFontPointSize
#define acdbOleGetOriginalSelectedTextSizeInAcadUnits gcdbOleGetOriginalSelectedTextSizeInGcadUnits
#define acdbOleSetOriginalSelectedTextSizeInAcadUnits gcdbOleSetOriginalSelectedTextSizeInGcadUnits
#define acdbGetDimTextBackground gcdbGetDimTextBackground
#define acdbSetDimTextBackground gcdbSetDimTextBackground
#define acdbGetDimExtensionLength gcdbGetDimExtensionLength
#define acdbSetDimExtensionLength gcdbSetDimExtensionLength
#define acdbGetFixedLengthExtLineEnabled gcdbGetFixedLengthExtLineEnabled
#define acdbSetFixedLengthExtLineEnabled gcdbSetFixedLengthExtLineEnabled
#define acdbSetFixedLengthExtLineEnabled gcdbSetFixedLengthExtLineEnabled
#define acdbGetArcLengthSymbolPlacement gcdbGetArcLengthSymbolPlacement
#define acdbSetArcLengthSymbolPlacement gcdbSetArcLengthSymbolPlacement
#define acdbGetDimLineLinetype gcdbGetDimLineLinetype
#define acdbSetDimLineLinetype gcdbSetDimLineLinetype
#define acdbSetDimExt1Linetype gcdbSetDimExt1Linetype
#define acdbGetDimExt1Linetype gcdbGetDimExt1Linetype
#define acdbSetDimExt2Linetype gcdbSetDimExt2Linetype
#define acdbGetDimExt2Linetype gcdbGetDimExt2Linetype
#define acdbGetLargeRadDimJogAngle gcdbGetLargeRadDimJogAngle
#define acdbSetLargeRadDimJogAngle gcdbSetLargeRadDimJogAngle
#define acdbGetDimFlipArrow gcdbGetDimFlipArrow
#define acdbSetDimFlipArrow gcdbSetDimFlipArrow
#define acdbGetDimFlipArrowWhich gcdbGetDimFlipArrowWhich
#define acdbSetDimFlipArrowWhich gcdbSetDimFlipArrowWhich
#define acdbGetExemptCheckFlag gcdbGetExemptCheckFlag
#define acdbSetExemptCheckFlag gcdbSetExemptCheckFlag
#define acdbGetDimJogSymbolSize gcdbGetDimJogSymbolSize
#define acdbSetDimJogSymbolSize gcdbSetDimJogSymbolSize
#define acdbGetDimJogSymbolPosition gcdbGetDimJogSymbolPosition
#define acdbSetDimJogSymbolPosition gcdbSetDimJogSymbolPosition
#define acdbGetRadialExtensionAngles gcdbGetRadialExtensionAngles
#define acdbSetRadialExtensionAngles gcdbSetRadialExtensionAngles
#define acdbGetDimAngExtOn gcdbGetDimAngExtOn
#define acdbSetDimAngExtOn gcdbSetDimAngExtOn
#define acdbGetDimTolAlign gcdbGetDimTolAlign
#define acdbSetDimTolAlign gcdbSetDimTolAlign
#define acdbGetDimBreakSize gcdbGetDimBreakSize
#define acdbSetDimBreakSize gcdbSetDimBreakSize
#define acdbGetViewportVisualStyle gcdbGetViewportVisualStyle
#define acdbSetViewportVisualStyle gcdbSetViewportVisualStyle
#define AcDbDisableAnnoAutoScale GcDbDisableAnnoAutoScale
#define acdbForceTextAdjust gcdbForceTextAdjust
#define acdbGetCurUserViewportId gcdbGetCurUserViewportId
#define acdbGetVisualStyleIdByIndex gcdbGetVisualStyleIdByIndex
#define acdbGetVisualStyleIndexById gcdbGetVisualStyleIndexById
#define acdbGetVisualStyleIndexByName gcdbGetVisualStyleIndexByName
#define acdbIsInLongTransaction gcdbIsInLongTransaction
#define acdbPSLayoutAnnoAllVisible gcdbPSLayoutAnnoAllVisible
#define acdbAssignGelibCurveToAcDbCurve gcdbAssignGelibCurveToGcDbCurve
#define acdbConvertAcDbCurveToGelibCurve gcdbConvertGcDbCurveToGelibCurve
#define acdbConvertGelibCurveToAcDbCurve gcdbConvertGelibCurveToGcDbCurve
#define acdbAddConstrainedGeometryDraggingInfo gcdbAddConstrainedGeometryDraggingInfo