/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __IMGDEF_H
#define __IMGDEF_H    1

#include "dbmain.h"
#include "gcgi.h"
#include "gept2dar.h"
#include "gemat2d.h"
#include "GdGChar.h"
#pragma pack (push, 8)

class  RasterImageDefImp;
class  GcDbImpRasterImageDefReactor;
typedef struct tagBITMAPINFO BITMAPINFO;

namespace Gtil
{
  class  Image;
  class  FileReadDescriptor;
};

enum ClassVersion
{
  kVersion1 = 0,
  kVersion2 = 1,
  kVersion3 = 2
};

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

class IGcReadStream;

class GCDB_PORT GcDbRasterImageDef : public GcDbObject
{
public:
  static ClassVersion         classVersion();

  GCRX_DECLARE_MEMBERS(GcDbRasterImageDef);
  GcDbRasterImageDef();
  ~GcDbRasterImageDef();

  RasterImageDefImp*  ptrImp() const;
  RasterImageDefImp*  setPtrImp(RasterImageDefImp* pImp);

  Gcad::ErrorStatus   subErase(Gsoft::Boolean erasing) override;
  Gcad::ErrorStatus   subClose() override;

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual GcGiSentScanLines*  makeScanLines(const GcGiRequestScanLines* pReq,
                                            const GcGeMatrix2d& pixToScreen,
                                            GcGePoint2dArray* pActiveClipBndy = 0,
                                            Gsoft::Boolean draftQuality = false,
                                            Gsoft::Boolean isTransparent = false,
                                            const double brightness = 50.0,
                                            const double contrast = 50.0,
                                            const double fade = 0.0) const;

  virtual Gcad::ErrorStatus   setSourceFileName(const GCHAR * pPathName);
  virtual Gcad::ErrorStatus   setActiveFileName(const GCHAR * pPathName);
  virtual const GCHAR *       searchForActivePath();

  virtual const GCHAR *       sourceFileName() const;
  virtual const GCHAR *       activeFileName() const;

  virtual Gcad::ErrorStatus   embed();
  virtual Gsoft::Boolean      isEmbedded() const;

  virtual Gcad::ErrorStatus   load();
  virtual Gcad::ErrorStatus   unload(Gsoft::Boolean modifyDatabase = true);
  virtual Gsoft::Boolean      isLoaded() const;

  virtual GcGeVector2d        size() const;

  virtual GcGiImageOrg        organization() const;
  virtual int                 colorDepth() const;

  virtual const GCHAR *       fileType() const;
  virtual int                 entityCount(Gsoft::Boolean* pbLocked = 0) const;
  virtual void                updateEntities() const;

  enum Units
  {
    kNone         = 0,
    kMillimeter   = 1,
    kCentimeter   = 2,
    kMeter        = 3,
    kKilometer    = 4,
    kInch         = 5,
    kFoot         = 6,
    kYard         = 7,
    kMile         = 8,
    kMicroinches  = 9,
    kMils         = 10,
    kAngstroms    = 11,
    kNanometers   = 12,
    kMicrons      = 13,
    kDecimeters   = 14,
    kDekameters   = 15,
    kHectometers  = 16,
    kGigameters   = 17,
    kAstronomical = 18,
    kLightYears   = 19,
    kParsecs      = 20
  };

  virtual Gcad::ErrorStatus   setResolutionMMPerPixel(const GcGeVector2d& resMMPerPixel);
  virtual GcGeVector2d        resolutionMMPerPixel() const;
  virtual void                setResolutionUnits(GcDbRasterImageDef::Units units);
  virtual Units               resolutionUnits() const;

  virtual Gcad::ErrorStatus   loadThumbnail(Gsoft::UInt16& maxWidth,
                                            Gsoft::UInt16& maxHeight,
                                            Gsoft::UInt8* pPalette = 0,
                                            int nPaletteEntries = 0);
  virtual Gcad::ErrorStatus   unloadThumbnail();
  virtual void*               createThumbnailBitmap(BITMAPINFO*& pBitmapInfo,
                                                    Gsoft::UInt8 brightness = 50,
                                                    Gsoft::UInt8 contrast = 50,
                                                    Gsoft::UInt8 fade = 0);

  virtual Gtil::Image* imageCopy(Gsoft::Boolean bForceImageLoad = true) const;
  virtual Gtil::FileReadDescriptor* fileDescCopy() const;

  virtual Gcad::ErrorStatus   openImage(Gtil::Image*& pImage);
  virtual Gcad::ErrorStatus   closeImage();
  virtual Gcad::ErrorStatus   setImage(const Gtil::Image* pImage,
                                       const Gtil::FileReadDescriptor* pFileDesc,
                                       Gsoft::Boolean modifyDatabase = true);

  virtual Gcad::ErrorStatus   setUndoStoreSize(unsigned int maxImages = 10);
  virtual unsigned int        undoStoreSize() const;

  virtual Gsoft::Boolean       imageModified() const;
  virtual Gcad::ErrorStatus    setImageModified(Gsoft::Boolean modified);

  virtual IGcReadStream*       getReadStream();

  Gcad::ErrorStatus            forceImageFileClosed(Gsoft::Boolean modifyDatabase);
  static Gcad::ErrorStatus     createImageDictionary(GcDbDatabase* pDb, GcDbObjectId& dictId);
  static GcDbObjectId          imageDictionary(GcDbDatabase* pDb);

  enum
  {
    kMaxSuggestNameSize = 2049
  };
  static Gcad::ErrorStatus     suggestName(GcDbDictionary* pImageDictionary,
                                           const GCHAR* pNewImagePathName,
                                           GCHAR* newImageName,
                                           size_t nSize);

private:
  RasterImageDefImp*          mpImp;
  static ClassVersion         mVersion;
};

inline RasterImageDefImp* GcDbRasterImageDef::ptrImp() const
{
  return mpImp;
}

inline RasterImageDefImp* GcDbRasterImageDef::setPtrImp(RasterImageDefImp* pImp)
{
  RasterImageDefImp* oldImp = mpImp;
  mpImp = pImp;
  return oldImp;
}

class GCDB_PORT GcDbRasterImageDefReactor : public GcDbObject
{
public:
  static ClassVersion         classVersion();

  GCRX_DECLARE_MEMBERS(GcDbRasterImageDefReactor);

  GcDbRasterImageDefReactor();
  ~GcDbRasterImageDefReactor();

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  void                erased(const GcDbObject* dbObj, Gsoft::Boolean pErasing = true) override;
  void                modified(const GcDbObject* dbObj) override;

  enum DeleteImageEvent
  {
    kUnload = 1,
    kErase = 2,
  };

  virtual Gsoft::Boolean      onDeleteImage(const GcDbRasterImageDef* pImageDef,
                                            const Gtil::Image* pImage,
                                            DeleteImageEvent event,
                                            Gsoft::Boolean cancelAllowed);

  static void                 setEnable(Gsoft::Boolean enable);

private:
  GcDbImpRasterImageDefReactor*   mpImp;
  static ClassVersion             mVersion;
};

class GCDB_PORT GcDbRasterImageDefTransReactor : public GcDbObjectReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRasterImageDefTransReactor);
  ~GcDbRasterImageDefTransReactor();
  virtual Gsoft::Boolean      onDeleteImage(const GcDbRasterImageDef* pImageDef,
                                            const Gtil::Image* pImage,
                                            GcDbRasterImageDefReactor::DeleteImageEvent event,
                                            Gsoft::Boolean cancelAllowed) = 0;
};

class GCDB_PORT GcDbRasterImageDefFileAccessReactor : public GcDbObjectReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcDbRasterImageDefFileAccessReactor);
  ~GcDbRasterImageDefFileAccessReactor();

  virtual void                onAttach(const GcDbRasterImageDef*,
                                       const GCHAR * pPath) = 0;
  virtual void                onDetach(const GcDbRasterImageDef*,
                                       const GCHAR * pPath) = 0;
  virtual Gsoft::Boolean      onOpen(const GcDbRasterImageDef*,
                                     const GCHAR * pPath,
                                     const GCHAR * pActivePath,
                                     Gsoft::Boolean& replacePath,
                                     GCHAR *& replacementPath) = 0;
  virtual Gsoft::Boolean      onPathChange(const GcDbRasterImageDef*,
                                           const GCHAR * pPath,
                                           const GCHAR * pActivePath,
                                           Gsoft::Boolean& replacePath,
                                           GCHAR *& replacementPath) = 0;
  virtual void                onClose(const GcDbRasterImageDef*,
                                      const GCHAR * pPath) = 0;
  virtual void                onDialog(GcDbRasterImageDef*,
                                       const GCHAR * pCaption,
                                       const GCHAR * pFileExtensions) = 0;
};

inline ClassVersion GcDbRasterImageDef::classVersion()
{
  return mVersion;
}

inline ClassVersion GcDbRasterImageDefReactor::classVersion()
{
  return mVersion;
}

#pragma warning( default : 4275 )

#pragma pack (pop)
#endif
