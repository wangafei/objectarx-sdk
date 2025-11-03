/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/dbsymtb.h"
#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbBackground.h"
#include "gevec2d.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"
#include "AcDbCore2dDefs.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"

#define	Acad 	Gcad
#define	AcDb 	GcDb
#define ACHAR	GCHAR
#define	Adesk 	Gsoft
#define Atil Gtil
#define Autodesk  Gssoft
#define AutoCAD Gscad
#define	AcString 	GcString
#define	AcCmColor 	GcCmColor
#define	AcDbEntity 	GcDbEntity
#define	AcDbObjectId 	GcDbObjectId
#define	AcDbDwgFiler 	GcDbDwgFiler
#define	AcDbDxfFiler 	GcDbDxfFiler
#define	AcGePoint3d 	GcGePoint3d
#define	AcDbBlockEnd 	GcDbBlockEnd
#define	AcDbDatabase 	GcDbDatabase
#define	AcCmEntityColor 	GcCmEntityColor
#define	AcGiDrawable 	GcGiDrawable
#define	AcDbObject 	GcDbObject
#define	AcCmTransparency 	GcCmTransparency
#define	AcDbDwgVersion 	GcDbDwgVersion
#define	AcDbBlockBegin 	GcDbBlockBegin
#define	appendAcDbEntity 	appendGcDbEntity
#define	AcDbObjectIdArray 	GcDbObjectIdArray
#define	AcDbSortentsTable 	GcDbSortentsTable
#define	AcDbSymbolTableRecord 	GcDbSymbolTableRecord
#define	AcDbBlockTableRecord 	GcDbBlockTableRecord
#define	AcDbLayerTableRecord 	GcDbLayerTableRecord
#define	AcDbTextStyleTableRecord 	GcDbTextStyleTableRecord
#define	AcDbLinetypeTableRecord 	GcDbLinetypeTableRecord
#define	AcDbAbstractViewTableRecord 	GcDbAbstractViewTableRecord
#define	AcDbBlockTableRecordIterator 	GcDbBlockTableRecordIterator
#define	AcDbBlockReferenceIdIterator 	GcDbBlockReferenceIdIterator
#define	AcGeVector2d 	GcGeVector2d
#define	AcGePoint2d 	GcGePoint2d
#define	AcGeVector3d 	GcGeVector3d
#define  AcGiViewportTraits GcGiViewportTraits
#define	AcDbViewTableRecord 	GcDbViewTableRecord
#define  AcGiToneOperatorParameters GcGiToneOperatorParameters
#define AcDbAnnotationScale GcDbAnnotationScale
#define	AcDbUCSTableRecord 	GcDbUCSTableRecord
#define	AcDbViewportTableRecord 	GcDbViewportTableRecord
#define	AcGsView 	GcGsView
#define	AcDbRegAppTableRecord 	GcDbRegAppTableRecord
#define	AcDbDimStyleTableRecord 	GcDbDimStyleTableRecord
#define	AcDbSymbolTable 	GcDbSymbolTable
#define	AcDbSymbolTableIterator 	GcDbSymbolTableIterator
#define	AcDbBlockTable 	GcDbBlockTable
#define	AcDbBlockTableIterator 	GcDbBlockTableIterator
#define	AcDbLayerTable 	GcDbLayerTable
#define	AcDbLayerTableIterator 	GcDbLayerTableIterator
#define	AcDbTextStyleTable 	GcDbTextStyleTable
#define	AcDbTextStyleTableIterator 	GcDbTextStyleTableIterator
#define	AcDbLinetypeTable 	GcDbLinetypeTable
#define	AcDbLinetypeTableIterator 	GcDbLinetypeTableIterator
#define	AcDbAbstractViewTable 	GcDbAbstractViewTable
#define	AcDbAbstractViewTableIterator 	GcDbAbstractViewTableIterator
#define	AcDbViewTable 	GcDbViewTable
#define	AcDbViewTableIterator 	GcDbViewTableIterator
#define	AcDbUCSTable 	GcDbUCSTable
#define	AcDbUCSTableIterator 	GcDbUCSTableIterator
#define	AcDbViewportTable 	GcDbViewportTable
#define	AcDbViewportTableIterator 	GcDbViewportTableIterator
#define	AcDbRegAppTable 	GcDbRegAppTable
#define	AcDbRegAppTableIterator 	GcDbRegAppTableIterator
#define	AcDbDimStyleTable 	GcDbDimStyleTable
#define	AcDbDimStyleTableIterator 	GcDbDimStyleTableIterator
#define	AcDbBlockReference 	GcDbBlockReference
#define	ACDB_DECLARE_MEMBERS 	GCDB_DECLARE_MEMBERS
#define	ACRX_NO_CONS_DEFINE_MEMBERS 	GCRX_NO_CONS_DEFINE_MEMBERS