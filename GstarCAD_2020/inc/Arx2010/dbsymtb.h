#pragma once

#define AcDbSymbolTable  GcDbSymbolTable
#define GcDbSymbolTable  OdDbSymbolTable

#define AcDbBlockTable  GcDbBlockTable
#define GcDbBlockTable  OdDbBlockTable

#define AcDbLayerTable  GcDbLayerTable
#define GcDbLayerTable  OdDbLayerTable

#define AcDbTextStyleTable  GcDbTextStyleTable
#define GcDbTextStyleTable  OdDbTextStyleTable

#define AcDbLinetypeTable  GcDbLinetypeTable
#define GcDbLinetypeTable  OdDbLinetypeTable

#define AcDbAbstractViewTable  GcDbAbstractViewTable
#define GcDbAbstractViewTable  OdDbAbstractViewTable

#define AcDbViewTable  GcDbViewTable
#define GcDbViewTable  OdDbViewTable

#define AcDbUCSTable  GcDbUCSTable
#define GcDbUCSTable  OdDbUCSTable

#define AcDbViewportTable  GcDbViewportTable
#define GcDbViewportTable  OdDbViewportTable

#define AcDbRegAppTable  GcDbRegAppTable
#define GcDbRegAppTable  OdDbRegAppTable

#define AcDbDimStyleTable  GcDbDimStyleTable
#define GcDbDimStyleTable  OdDbDimStyleTable

#define AcDbSymbolTableIterator  GcDbSymbolTableIterator
#define GcDbSymbolTableIterator  OdDbSymbolTableIterator

#define AcDbBlockTableIterator  GcDbBlockTableIterator
#define GcDbBlockTableIterator  OdDbBlockTableIterator

#define AcDbLayerTableIterator  GcDbLayerTableIterator
#define GcDbLayerTableIterator  OdDbLayerTableIterator

#define AcDbTextStyleTableIterator  GcDbTextStyleTableIterator
#define GcDbTextStyleTableIterator  OdDbTextStyleTableIterator

#define AcDbLinetypeTableIterator  GcDbLinetypeTableIterator
#define GcDbLinetypeTableIterator  OdDbLinetypeTableIterator

#define AcDbAbstractViewTableIterator  GcDbAbstractViewTableIterator
#define GcDbAbstractViewTableIterator  OdDbAbstractViewTableIterator

#define AcDbViewTableIterator  GcDbViewTableIterator
#define GcDbViewTableIterator  OdDbViewTableIterator

#define AcDbUCSTableIterator  GcDbUCSTableIterator
#define GcDbUCSTableIterator  OdDbUCSTableIterator

#define AcDbViewportTableIterator  GcDbViewportTableIterator
#define GcDbViewportTableIterator  OdDbViewportTableIterator

#define AcDbRegAppTableIterator  GcDbRegAppTableIterator
#define GcDbRegAppTableIterator  OdDbRegAppTableIterator

#define AcDbDimStyleTableIterator  GcDbDimStyleTableIterator
#define GcDbDimStyleTableIterator  OdDbDimStyleTableIterator

#define AcDbSymbolTableRecord  GcDbSymbolTableRecord
#define GcDbSymbolTableRecord  OdDbSymbolTableRecord

#define AcDbBlockTableRecordIterator  GcDbBlockTableRecordIterator
#define GcDbBlockTableRecordIterator  OdDbBlockTableRecordIterator

#define AcDbBlockReferenceIdIterator  GcDbBlockReferenceIdIterator
#define GcDbBlockReferenceIdIterator  OdDbBlockReferenceIdIterator

#define AcDbBlockTableRecord  GcDbBlockTableRecord
#define GcDbBlockTableRecord  OdDbBlockTableRecord

#define AcDbLayerTableRecord  GcDbLayerTableRecord
#define GcDbLayerTableRecord  OdDbLayerTableRecord

#define AcDbTextStyleTableRecord  GcDbTextStyleTableRecord
#define GcDbTextStyleTableRecord  OdDbTextStyleTableRecord

#define AcDbLinetypeTableRecord  GcDbLinetypeTableRecord
#define GcDbLinetypeTableRecord  OdDbLinetypeTableRecord

#define AcDbAbstractViewTableRecord  GcDbAbstractViewTableRecord
#define GcDbAbstractViewTableRecord  OdDbAbstractViewTableRecord

#define AcDbViewTableRecord  GcDbViewTableRecord
#define GcDbViewTableRecord  OdDbViewTableRecord

#define AcDbUCSTableRecord  GcDbUCSTableRecord
#define GcDbUCSTableRecord  OdDbUCSTableRecord

#define AcDbViewportTableRecord  GcDbViewportTableRecord
#define GcDbViewportTableRecord  OdDbViewportTableRecord

#define AcDbRegAppTableRecord  GcDbRegAppTableRecord
#define GcDbRegAppTableRecord  OdDbRegAppTableRecord

#define AcDbDimStyleTableRecord  GcDbDimStyleTableRecord
#define GcDbDimStyleTableRecord  OdDbDimStyleTableRecord  

#define appendAcDbEntity  appendGcDbEntity
#define appendGcDbEntity  appendOdDbEntity

#include "dbmain.h"
#include "dbdict.h"
#include "dbdate.h"
#include "dbbackground.h"
#include "gevec2d.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"
#include "../Tables.h"
#include "../DbLinetypeTable.h"
#include "../DbLinetypeTableRecord.h"
#include "../DbLayerTableRecord.h"
#include "../DbAbstractViewTableRecord.h"
#include "../DbAbstractViewTable.h"