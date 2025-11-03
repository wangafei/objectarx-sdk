/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "adesk.h"
#include "acadapidef.h"
#include "gepnt2d.h"
#include "gepnt3d.h"
#include "AcHeapOpers.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbboiler.h"   
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "AcString.h"

#include "acdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "ads_db.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "acgidefs.h"
#include "acarray.h"

#include "../../inc/dbmain.h"

#define AcCmEntityColor GcCmEntityColor
#define AcCmColor GcCmColor
#define AcDbBlockBegin GcDbBlockBegin
#define AcDbBlockEnd GcDbBlockEnd
#define AcDbDatabase GcDbDatabase
#define AcDbDatabaseIterator GcDbDatabaseIterator
#define AcDbDatabaseReactor GcDbDatabaseReactor
#define AcDbEntity GcDbEntity
#define AcDbEntityReactor GcDbEntityReactor
#define AcDbImpDatabase GcDbImpDatabase
#define AcDbImpObject GcDbImpObject
#define AcDbObject GcDbObject
#define AcDbObjectReactor GcDbObjectReactor
#define AcDbSpaceIterator GcDbSpaceIterator
#define AcDbSystemInternals GcDbSystemInternals
#define AcDbXObject GcDbXObject
#define AcDbBlockReference GcDbBlockReference
#define AcDbSymbolTable GcDbSymbolTable
#define AcDbBlockTable GcDbBlockTable
#define AcDbBlockTableRecord GcDbBlockTableRecord
#define AcDbLayerTable GcDbLayerTable
#define AcDbTextStyleTable GcDbTextStyleTable
#define AcDbLinetypeTable GcDbLinetypeTable
#define AcDbAbstractViewTable GcDbAbstractViewTable
#define AcDbViewTable GcDbViewTable
#define AcDbUCSTable GcDbUCSTable
#define AcDbViewportTable GcDbViewportTable
#define AcDbRegAppTable GcDbRegAppTable
#define AcDbDimStyleTable GcDbDimStyleTable
#define AcDbDimStyleTableRecord GcDbDimStyleTableRecord
#define AcDbIdMapping GcDbIdMapping
#define AcDbDictionary GcDbDictionary
#define AcDbDictionaryWithDefault GcDbDictionaryWithDefault
#define AcDbMline GcDbMline
#define AcDbMlineStyle GcDbMlineStyle
#define AcDbCurve GcDbCurve
#define AcDbEllipse GcDbEllipse
#define AcDbSpline GcDbSpline
#define AcDbRegion GcDbRegion
#define AcDb3dSolid GcDb3dSolid
#define AcDbBody GcDbBody
#define AcDbDate GcDbDate
#define AcDbExtents GcDbExtents
#define AcDbAuditInfo GcDbAuditInfo
#define AcDbUndoController GcDbUndoController
#define AcDbTransactionManager GcDbTransactionManager
#define AcDbSpatialFilter GcDbSpatialFilter
#define AcDbLayerFilter GcDbLayerFilter
#define AcGeMatrix2d GcGeMatrix2d
#define AcGeVector3d GcGeVector3d
#define AcGsNode GcGsNode
#define AcGsModel GcGsModel
#define AcGiContext GcGiContext
#define AcDbObjectIdGraph GcDbObjectIdGraph
#define AcDbLayerStateManager GcDbLayerStateManager
#define AcDwgFileHandle GcDwgFileHandle
#define AcDbTableStyle GcDbTableStyle
#define AcFdFieldValue GcFdFieldValue
#define AcDbField GcDbField
#define AcDbSectionManager GcDbSectionManager
#define AcDbDataLinkManager GcDbDataLinkManager
#define AcGiMapper GcGiMapper
#define AcDbAnnotationScale GcDbAnnotationScale
#define IAcReadStream IGcReadStream
#define IAcWriteStream IGcWriteStream
#define acutNewString gcutNewString
#define Atil Gtil
#define AcDbGripDataPtrArray GcDbGripDataPtrArray
#define AcDbFullSubentPathArray GcDbFullSubentPathArray
#define acdbGroupCodeToType gcdbGroupCodeToType
#define acdbPersistentReactorObjectId gcdbPersistentReactorObjectId
#define acdbIsPersistentReactor gcdbIsPersistentReactor
#define acdbDisplayPreviewFromDwg gcdbDisplayPreviewFromDwg
#define acdbIsCustomObject gcdbIsCustomObject
#define acdbOpenObject gcdbOpenObject
#define acdbOpenAcDbObject gcdbOpenGcDbObject
#define acdbOpenAcDbEntity gcdbOpenGcDbEntity
#define acdbResurrectMeNow gcdbResurrectMeNow
#define acdbGetAdsName gcdbGetGdsName
#define acdbGetObjectId gcdbGetObjectId
#define acdbValKey gcdbValKey
#define acdbSetReferenced gcdbSetReferenced
#define acdbActiveDatabaseArray gcdbActiveDatabaseArray
#define acdbLoadMlineStyleFile gcdbLoadMlineStyleFile
#define acdbLoadLineTypeFile gcdbLoadLineTypeFile
#define acdbAlloc gcdbAlloc
#define acdbRealloc gcdbRealloc
#define acdbFree gcdbFree
#define acdbInitialize gcdbInitialize
#define acdbTerminate gcdbTerminate
#define acdbValidateSetup gcdbValidateSetup
#define acdbCleanUp gcdbCleanUp
#define acdbOriginalXrefFullPathFor gcdbOriginalXrefFullPathFor
#define acdbSetDefaultAcGiContext gcdbSetDefaultGcGiContext
#define acdbGetThumbnailBitmapFromDxfFile gcdbGetThumbnailBitmapFromDxfFile

#define acutGetAcStringConvertToAChar gcutGetGcStringConvertToGChar
#define acutAcStringToAChar gcutGcStringToGChar

#define acdbSaveAs2004 gcdbSaveAs2004
#define acdbSaveAs2000 gcdbSaveAs2000
#define acdbSaveAsR14 gcdbSaveAsR14
#define acdbDxfOutAs2004 gcdbDxfOutAs2004
#define acdbDxfOutAs2000 gcdbDxfOutAs2000
#define acdbDxfOutAsR12 gcdbDxfOutAsR12

#define AcDbObjectIterator GcDbObjectIterator
#define AcCmComplexColor GcCmComplexColor
#define AcCmHSB GcCmHSB

#define accmGetColorFromACIName             gccmGetColorFromACIName
#define accmGetColorFromRGBName             gccmGetColorFromRGBName
#define accmGetFromHSBName                  gccmGetFromHSBName
#define accmGetColorFromColorBookName       gccmGetColorFromColorBookName
#define accmGetLocalizedColorNames gccmGetLocalizedColorNames

#define AcDbColor GcDbColor
#define AcDbExtents2d GcDbExtents2d

#define AC_SRCH_BLOCK        GC_SRCH_BLOCK     
#define AC_SRCH_DIM_TEXT     GC_SRCH_DIM_TEXT  
#define AC_SRCH_TEXT         GC_SRCH_TEXT      
#define AC_SRCH_LINK_DESC    GC_SRCH_LINK_DESC 
#define AC_SRCH_LINK_URL     GC_SRCH_LINK_URL  
#define AC_SRCH_MATCH_CASE   GC_SRCH_MATCH_CASE
#define AC_SRCH_WHOLE_WORD   GC_SRCH_WHOLE_WORD
#define AC_SRCH_DEFAULT      GC_SRCH_DEFAULT  

#define acdbTextFind gcdbTextFind
#define AcDbObjectContextManager GcDbObjectContextManager
#define	addAcDbObject 	addGcDbObject
#define acdbFreeResBufContents            gcdbFreeResBufContents
#define	getAcDbHandle 	getGcDbHandle
#define	getAcDbObjectId 	getGcDbObjectId
#define dwgFileWasSavedByAutodeskSoftware dwgFileWasSavedByGssoftSoftware
#define setAcDbObjectIdsInFlux setGcDbObjectIdsInFlux
#define isAcDbObjectIdsInFlux isGcDbObjectIdsInFlux