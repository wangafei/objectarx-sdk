#ifndef __ACFDUTIL_H__
#define __ACFDUTIL_H__

#include "AdAChar.h"
#include "AcCell.h"
#include "adesk.h"

#include "../../inc/zAcFdUtil.h"

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef ACFD_API
#define ACFD_API		ZCFD_API
#endif //#ifndef ACFD_API

#ifndef ACFD_PORT
#define ACFD_PORT		ZCFD_PORT
#endif //#ifndef ACFD_PORT

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcCell
#define AcCell		ZcCell
#endif //#ifndef AcCell

#ifndef AcCellRangeArray
#define AcCellRangeArray		ZcCellRangeArray
#endif //#ifndef AcCellRangeArray

#ifndef AcDbEvalNodeId
#define AcDbEvalNodeId		ZcDbEvalNodeId
#endif //#ifndef AcDbEvalNodeId

#ifndef AcDbField
#define AcDbField		ZcDbField
#endif //#ifndef AcDbField

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcFdEval
#define AcFdEval		ZcFdEval
#endif //#ifndef AcFdEval

#ifndef AcFdExtractData
#define AcFdExtractData		ZcFdExtractData
#endif //#ifndef AcFdExtractData

#ifndef AcFdMakeFieldCode
#define AcFdMakeFieldCode		ZcFdMakeFieldCode
#endif //#ifndef AcFdMakeFieldCode

#ifndef IAcSmDatabase
#define IAcSmDatabase		IZcSmDatabase
#endif //#ifndef IAcSmDatabase

#ifndef IAcSmSheetSet
#define IAcSmSheetSet		IZcSmSheetSet
#endif //#ifndef IAcSmSheetSet

#ifndef AcHyperlink
#define AcHyperlink		ZcHyperlink
#endif //#ifndef AcHyperlink

#ifndef IAcSmComponent
#define IAcSmComponent		IZcSmComponent
#endif //#ifndef IAcSmComponent

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef acutNewString
#define acutNewString		zcutNewString
#endif //#ifndef acutNewString

#endif //#ifndef __ACFDUTIL_H__
