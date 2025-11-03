
#pragma once

#include "zAcString.h"
#include "zacadstrc.h"
#include "zAcDbCore2dDefs.h"



typedef ZSoft::UInt64 ZcDgnRefFileId;

struct ZcDbDgnRefFileData {
    enum FileType{
        kDgnFile   = 1,
        kDwgFile   = 2,
        kImageFile = 3,
        kOtherFile = 4
    };
    FileType type;
    ZcString savedPathAndName;
    ZcString foundPathAndName;
    ZcDgnRefFileId refId;
};

typedef ZcArray<ZcDbDgnRefFileData*> ZcDbRefFileDataPtrArray;
typedef ZcArray<ZcDgnRefFileId>     ZcDbDgnRefFileIdArray;

Zcad::ErrorStatus
zcdbGetDgnFileReferences(const ZTCHAR* fileName, const ZTCHAR* pwd,
    ZcDbRefFileDataPtrArray& files);

class  ZCDBCORE2D_PORT ZcDbDgnRefFileRepath
{
public:
    ZcDbDgnRefFileRepath() : m_fileHandle(NULL)  {};
    Zcad::ErrorStatus setFile(const ZcString& dgnPathAndFilename, const ZTCHAR* pwd);
    ~ZcDbDgnRefFileRepath();
    Zcad::ErrorStatus getReferenceFilePaths(ZcDbRefFileDataPtrArray& refFiles);
    Zcad::ErrorStatus rePath(const ZcDbDgnRefFileIdArray& refFileIds,
        const ZcStringArray& newRefFileNames);

private:
    void* m_fileHandle;
};

