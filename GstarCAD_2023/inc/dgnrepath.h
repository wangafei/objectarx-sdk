/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcString.h"
#include "gcadstrc.h"

typedef Gsoft::UInt64 GcDgnRefFileId;

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

typedef GcArray<GcDbDgnRefFileData*> GcDbRefFileDataPtrArray;
typedef GcArray<GcDgnRefFileId>     GcDbDgnRefFileIdArray;

GCCORE_PORT Gcad::ErrorStatus
gcdbGetDgnFileReferences(const GCHAR* fileName, const GCHAR* pwd,
                         GcDbRefFileDataPtrArray& files);

class GCCORE_PORT GcDbDgnRefFileRepath
{
public:
  GcDbDgnRefFileRepath() : m_fileHandle(NULL) {};
  Gcad::ErrorStatus setFile(const GcString& dgnPathAndFilename, const GCHAR* pwd);
  ~GcDbDgnRefFileRepath();
  Gcad::ErrorStatus getReferenceFilePaths(GcDbRefFileDataPtrArray& refFiles);
  Gcad::ErrorStatus rePath(const GcDbDgnRefFileIdArray& refFileIds,
                           const GcStringArray& newRefFileNames);

private:
  void* m_fileHandle;
};