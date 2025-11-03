#pragma once

typedef unsigned __int64    GcDgnRefFileId;

struct GcDbDgnRefFileData {
  enum FileType {
    kDgnFile = 1,
    kDwgFile = 2,
    kImageFile = 3,
    kOtherFile = 4
  };
  FileType type;
  GcString savedPathAndName;
  GcString foundPathAndName;
  GcDgnRefFileId refId;
};

typedef GcArray<GcDbDgnRefFileData*>     GcDbRefFileDataPtrArray;
typedef GcArray<GcDgnRefFileId>          GcDbDgnRefFileIdArray;

GCDB_DLL_DECL Gcad::ErrorStatus
gcdbGetDgnFileReferences(const GCHAR* fileName, const GCHAR* pwd,
  GcDbRefFileDataPtrArray& files);

class GcDbDgnRefFileRepath
{
public:
  GcDbDgnRefFileRepath() {};
  Gcad::ErrorStatus setFile(const GcString& dgnPathAndFilename, const GCHAR* pwd);
  ~GcDbDgnRefFileRepath();
  Gcad::ErrorStatus getReferenceFilePaths(GcDbRefFileDataPtrArray& refFiles);
  Gcad::ErrorStatus rePath(const GcDbDgnRefFileIdArray& refFileIds,
    const GcStringArray& newRefFileNames);
};
