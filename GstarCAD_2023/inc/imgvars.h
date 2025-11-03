/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __IMGVARS_H
#define __IMGVARS_H

#include "dbmain.h"
#include "imgdef.h"

#pragma pack (push, 8)

class GcDbImpRasterVariables;

#pragma warning( disable : 4275 )

#ifdef ISMDLLACCESS
#undef ISMDLLACCESS
#endif
#ifdef ISMDLLACCESSDATA
#undef ISMDLLACCESSDATA
#endif
#ifdef ISM_OBJ 
#define ISMDLLACCESS __declspec(dllexport)
#define ISMDLLACCESSDATA
#else
#define ISMDLLACCESS 
#define ISMDLLACCESSDATA __declspec(dllimport)
#endif

class GCDB_PORT GcDbRasterVariables : public GcDbObject
{
public:
  static ClassVersion        classVersion();

  GCRX_DECLARE_MEMBERS(GcDbRasterVariables);

  enum FrameSettings
  {
    kImageFrameInvalid  = -1,
    kImageFrameOff      = 0,
    kImageFrameAbove    = 1,
    kImageFrameBelow    = 2,
    kImageFrameOnNoPlot = 3
  };
  enum ImageQuality
  {
    kImageQualityInvalid = -1,
    kImageQualityDraft   = 0,
    kImageQualityHigh    = 1
  };

  static GcDbRasterVariables* create();
  GcDbRasterVariables();
  ~GcDbRasterVariables();

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual FrameSettings       imageFrame() const;
  virtual Gcad::ErrorStatus   setImageFrame(FrameSettings value);
  virtual ImageQuality        imageQuality() const;
  virtual Gcad::ErrorStatus   setImageQuality(ImageQuality value);

  virtual GcDbRasterImageDef::Units userScale() const;
  virtual Gcad::ErrorStatus         setUserScale(GcDbRasterImageDef::Units units);

  static GcDbRasterVariables* openRasterVariables(GcDb::OpenMode mode, GcDbDatabase* pDatabase = 0);

private:
  void *operator new[](size_t) throw() { return 0; }
  void  operator delete[](void *) {};
  void *operator new[](size_t, const char *, int) throw() { return 0; }

  GcDbImpRasterVariables*     mpImp;
  static ClassVersion         mVersion;
};

inline ClassVersion GcDbRasterVariables::classVersion()
{
  return mVersion;
}

#pragma warning( default : 4275 )

#pragma pack (pop)
#endif
