#pragma once
#include "gcadstd.h"
#include "gcdb.h"
#include "gds.h"
#include "../DbDatabase.h"
#include "../DbAudit.h"

GCDB_DLL_DECL Gcad::ErrorStatus gcdbValKey(const gds_name lname);

inline Gcad::ErrorStatus gcdbSaveAs2004(GcDbDatabase* pDb,
                                        const GCHAR* fileName)
{
    return pDb->saveAs(fileName, false, GcDb::kDHL_1800);
}

inline Gcad::ErrorStatus gcdbSaveAs2000(GcDbDatabase* pDb,
                                        const GCHAR* fileName)
{
    return pDb->saveAs(fileName, false, GcDb::kDHL_1015);
}

inline Gcad::ErrorStatus gcdbSaveAsR14(GcDbDatabase* pDb,
                                       const GCHAR* fileName)
{
    return pDb->saveAs(fileName, false, GcDb::kDHL_1014);
}

inline Gcad::ErrorStatus gcdbDxfOutAs2004(GcDbDatabase* pDb,
                                          const GCHAR* fileName,
                                          const int precision = 16)
{
    return pDb->dxfOut(fileName, precision, GcDb::kDHL_1800);
}

inline Gcad::ErrorStatus gcdbDxfOutAs2000(GcDbDatabase* pDb,
                                          const GCHAR* fileName,
                                          const int precision = 16)
{
    return pDb->dxfOut(fileName, precision, GcDb::kDHL_1015);
}

inline Gcad::ErrorStatus gcdbDxfOutAsR12(GcDbDatabase* pDb,
                                         const GCHAR* fileName,
                                         const int precision = 16)
{
    return pDb->dxfOut(fileName, precision, GcDb::kDHL_1009);
}

GCDB_DLL_DECL const GCHAR* gcdbOriginalXrefFullPathFor(const GcDbDatabase*);

/////////////////////////////////////////////////////////////////////////
// Text Finder API.
#define GC_SRCH_BLOCK         0x01
#define GC_SRCH_DIM_TEXT      0x02
#define GC_SRCH_TEXT          0x04
#define GC_SRCH_LINK_DESC     0x08
#define GC_SRCH_LINK_URL      0x10
#define GC_SRCH_MATCH_CASE    0x20
#define GC_SRCH_WHOLE_WORD    0x40

#define GC_SRCH_DEFAULT       0x1F

GCDB_DLL_DECL bool gcdbTextFind(GcDbDatabase* pDatabase,
                                GcDbObjectIdArray& resultSet,
                                const GCHAR* findString,
                                const GCHAR* replaceString = NULL,
                                Hccad::UInt8 searchOptions = GC_SRCH_DEFAULT,
                                const GcDbObjectIdArray& selSet = 0);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbLoadMlineStyleFile(const GCHAR *sname, const GCHAR *fname);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbLoadLineTypeFile(const GCHAR *ltname,const GCHAR *fname,GcDbDatabase *pDb);

GCUT_DLL_DECL Gcad::ErrorStatus gccmGetColorFromACIName(GcCmColor& clr, const GCHAR *pInput);
GCUT_DLL_DECL Gcad::ErrorStatus gccmGetColorFromRGBName(GcCmColor& clr, const GCHAR *pInput);
GCED_DLL_DECL Gcad::ErrorStatus gccmGetColorFromColorBookName(GcCmColor& clr, const GCHAR *pBookName, const GCHAR *pColorName);

GCUT_DLL_DECL void gccmGetLocalizedColorNames( const GCHAR* colors[9] );
