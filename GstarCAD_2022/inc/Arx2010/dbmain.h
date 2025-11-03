#pragma once

#define addAcDbObject  addGcDbObject
#define addGcDbObject  addOdDbObject

#define getAcDbHandle  getGcDbHandle
#define getGcDbHandle  getOdDbHandle

#define AcDbServices  GcDbServices
#define GcDbServices  OdDbServices

#define acdbServices  gcdbServices
#define gcdbServices  oddbServices

#define acdbGroupCodeToType  gcdbGroupCodeToType
#define gcdbGroupCodeToType  oddbGroupCodeToType

#define acdbFreeResBufContents  gcdbFreeResBufContents

#define acdbIsPersistentReactor         gcdbIsPersistentReactor
#define acdbPersistentReactorObjectId   gcdbPersistentReactorObjectId
#define acdbDisplayPreviewFromDwg       gcdbDisplayPreviewFromDwg

#define acdbIsCustomObject  gcdbIsCustomObject

#define acdbOpenAcDbObject  gcdbOpenGcDbObject
#define gcdbOpenGcDbObject  oddbOpenOdDbObject

#define acdbOpenAcDbEntity  gcdbOpenGcDbEntity
#define gcdbOpenGcDbEntity  oddbOpenOdDbEntity

#define acdbOpenObject  gcdbOpenObject
#define gcdbOpenObject  oddbOpenObject

#define acdbResurrectMeNow  gcdbResurrectMeNow
#define gcdbResurrectMeNow  oddbResurrectMeNow

#define acdbGetAdsName  gcdbGetGdsName
#define gcdbGetGdsName  oddbGetAdsName

#define acdbGetObjectId  gcdbGetObjectId
#define gcdbGetObjectId  oddbGetObjectId

#define acdbSetReferenced  gcdbSetReferenced
#define gcdbSetReferenced  oddbSetReferenced

#define acdbValKey                          gcdbValKey
#define acdbActiveDatabaseArray             gcdbActiveDatabaseArray
#define acdbLoadMlineStyleFile              gcdbLoadMlineStyleFile
#define acdbLoadLineTypeFile                gcdbLoadLineTypeFile
#define acdbAlloc                           gcad_malloc
#define acdbRealloc                         gcad_realloc
#define acdbFree                            gcad_free
#define acdbValidateSetup                   gcdbValidateSetup
#define gcdbValidateSetup                   oddbValidateSetup
#define acdbCleanUp                         gcdbCleanUp
#define gcdbCleanUp                         oddbCleanUp
#define acdbOriginalXrefFullPathFor         gcdbOriginalXrefFullPathFor
#define acdbSetDefaultAcGiContext           gcdbSetDefaultGcGiContext
#define gcdbSetDefaultGcGiContext           oddbSetDefaultOdGiContext
#define acdbGetThumbnailBitmapFromDxfFile   gcdbGetThumbnailBitmapFromDxfFile
#define gcdbGetThumbnailBitmapFromDxfFile   oddbGetThumbnailBitmapFromDxfFile

#define AcDbDatabase  GcDbDatabase
#define GcDbDatabase  OdDbDatabase

#define acdbSaveAs2004    gcdbSaveAs2004
#define acdbSaveAs2000    gcdbSaveAs2000
#define acdbSaveAsR14     gcdbSaveAsR14
#define acdbDxfOutAs2004  gcdbDxfOutAs2004
#define acdbDxfOutAs2000  gcdbDxfOutAs2000
#define acdbDxfOutAsR12   gcdbDxfOutAsR12

#define AcDbObjectIterator  GcDbObjectIterator
#define GcDbObjectIterator  OdDbObjectIterator

#define AcDbObject  GcDbObject
#define GcDbObject  OdDbObject

#define AcDbXObject  GcDbXObject
#define GcDbXObject  OdDbXObject

#define AcCmComplexColor  GcCmComplexColor
#define GcCmComplexColor  OdCmComplexColor

#define AcCmColor  GcCmColor
#define GcCmColor  OdCmColor

#define accmGetColorFromACIName         gccmGetColorFromACIName
#define accmGetColorFromRGBName         gccmGetColorFromRGBName
#define accmGetColorFromColorBookName   gccmGetColorFromColorBookName
#define accmGetLocalizedColorNames      gccmGetLocalizedColorNames	

#define AcDbColor  GcDbColor
#define GcDbColor  OdDbColor

#define AcDbEntity  GcDbEntity
#define GcDbEntity  OdDbEntity

#define AcDbObjectReactor  GcDbObjectReactor
#define GcDbObjectReactor  OdDbObjectReactor

#define AcDbEntityReactor  GcDbEntityReactor
#define GcDbEntityReactor  OdDbEntityReactor

#define AcDbDatabaseReactor  GcDbDatabaseReactor
#define GcDbDatabaseReactor  OdDbDatabaseReactor

#define AcDbExtents  GcDbExtents
#define GcDbExtents  OdDbExtents

#define isAcDbObjectIdsInFlux isGcDbObjectIdsInFlux
#define isGcDbObjectIdsInFlux isOdDbObjectIdsInFlux

#define setAcDbObjectIdsInFlux setGcDbObjectIdsInFlux
#define setGcDbObjectIdsInFlux setOdDbObjectIdsInFlux

#define getAcDbObjectId  getGcDbObjectId
#define getGcDbObjectId  getOdDbObjectId

#define	AcDbDatabaseIterator GcDbDatabaseIterator
#define	GcDbDatabaseIterator OdDbDatabaseIterator

#define acdbTextFind gcdbTextFind

#define AC_SRCH_BLOCK      GC_SRCH_BLOCK
#define AC_SRCH_DIM_TEXT   GC_SRCH_DIM_TEXT
#define AC_SRCH_TEXT       GC_SRCH_TEXT
#define AC_SRCH_LINK_DESC  GC_SRCH_LINK_DESC
#define AC_SRCH_LINK_URL   GC_SRCH_LINK_URL
#define AC_SRCH_MATCH_CASE GC_SRCH_MATCH_CASE
#define AC_SRCH_WHOLE_WORD GC_SRCH_WHOLE_WORD
#define AC_SRCH_DEFAULT    GC_SRCH_DEFAULT

#include <stddef.h>
#include <share.h>
#include "gepnt3d.h"
#include "gevec3d.h"
#include "geline3d.h"
#include "AcHeapOpers.h"
#include "adesk.h"
#include "rxobject.h"
#include "rxdlinkr.h"
#include "rxiter.h"
#include "rxditer.h"
#include "rxsrvice.h"
#include "dbptrar.h"
#include "dbcolor.h"
#include "dbidar.h"
#include "drawable.h"
#include "dbsecurity.h"
#include "acdb.h"
#include "dbhandle.h"
#include "dbfiler.h"
#include "ads.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "dbsubeid.h"
#include "dbaudita.h"
#include "dbdimvar.h"
#include "../grx/dbmain.h"
#include "../grx/dbxutil.h"
#include "../DbIdOpen.h"
#include "../grx/gcmem.h"
#include "../grx/gcdbgds.h"
#include "../DbServices.h"
#include "../CmColor.h"