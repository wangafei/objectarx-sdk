/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////




#ifndef __DBRASTERIMAGEDEF_H
#define __DBRASTERIMAGEDEF_H

#include "TD_PackPush.h"

// Forward declarations
//

class OdDbDictionary;
class IGcReadStream;

#include "DbObjectReactor.h"
#include "DbObject.h"
#include "Gi/Gi.h"
#include "Gi/GiRasterWrappers.h" // to prevent branching (todo - replace by GiRasterImage.h)
#include "Ge/GeVector2d.h"
#include "RxObjectImpl.h"

/** Description:
    This virtual base class defines Raster Image Definition objects in an OdDbDatabase instance.
    
    Library:
    TD_Db

    Remarks:
    Raster Image Definitions (OdDbRasterImageDef objects) work with Raster Image (OdDbRasterImage) entities) 
    in much the same way that Block Table Records (OdDbBlockTableRecord objects) work with Block References
    (OdDbBlockReference entities).

    {group:OdDb_Classes}
*/
class RasterImageDefImp;
class OdGiBitmap;
class IeImg;
class OdGiSentScanLines;
class OdGiRequestScanLines;


enum ClassVersion
{
  kVersion1 = 0,    // S039 Oct 21, 1996
  kVersion2 = 1,    // S052 Jan 16, 1996
  kVersion3 = 2     // S061 Mar 21, 1997
};

class TOOLKIT_EXPORT OdDbRasterImageDef : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRasterImageDef);

  enum Units 
  {
    kNone           = 0,
    kMillimeter     = 1,
    kCentimeter     = 2,
    kMeter          = 3,
    kKilometer      = 4,
    kInch           = 5,
    kFoot           = 6,
    kYard           = 7,
    kMile           = 8,
    kMicroinches    = 9,
    kMils           = 10,
    kAngstroms      = 11,
    kNanometers     = 12,
    kMicrons        = 13,
    kDecimeters     = 14,
    kDekameters     = 15,
    kHectometers    = 16,
    kGigameters     = 17,
    kAstronomical   = 18,
    kLightYears     = 19,
    kParsecs        = 20
  };

  static ClassVersion classVersion();

  OdDbRasterImageDef();
  virtual  ~OdDbRasterImageDef();
  
  OdResult subErase(
    OdBool erasing);
  virtual OdResult subHandOverTo (
    OdDbObject* pNewObject);
  OdResult subClose();

  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  OdResult dxfOutFields( 
    OdDbDxfFiler* pFiler) const;

  /** Description:
    Sets the *name* of the source file containing the raster *image* for this Raster Image Definition object (DXF 1).
    
    Arguments:
    pathName (I) Path *name*.
  */
  virtual OdResult setSourceFileName(const OdChar* pPathName);

  /** Description:
    Returns the name of the source file containing the raster *image* for this Raster Image Definition object (DXF 1).
    
    Remarks:
    This function calls searchForActivePath() to determine the active path.
    
    Note:
    This RasterImageDef object must be open for reading.
  */
  virtual const OdChar* sourceFileName() const;

	virtual const OdChar *activeFileName() const;
	virtual OdResult setActiveFileName(const OdChar* pPathName);
	virtual const OdChar *searchForActivePath();
	virtual OdResult applyPartialUndo(OdDbDwgFiler* pUndoFiler, OdRxClass* pClassObj);
  /** Description:
    Loads the source *image* file for this Raster Image Definition object.
    
    Arguments:
    modifyDatabase (I) If and only if true, undo recording will be done for this object.

    Remarks:
    This function calls searchForActivePath() to determine the active path.
    
    If the *image* file is currently loaded, the file will not be read.
    
    "Lazy loading" implies that the *image* file will not be loaded until it is required.
    
  */
  virtual OdResult load(bool modifyDatabase = false);
  virtual OdGiImageOrg organization() const;

  /** Description:
    Unloads the *image* for this Raster Image Definition object. 
    
    Arguments:
    modifyDatabase (I) If and only if true, undo recording will be done for this object.

    Remarks:

    Note:
    This RasterImageDef object must be open for writing.

  */
  virtual OdResult unload(
    OdBool modifyDatabase = true);

  /** Description:
    Returns true if and only if the *image* file for this Raster Image Definition object is loaded (DXF 280).
  */
  virtual OdBool isLoaded() const;

  /** Description:
    Returns the XY pixel *size* of the *image* for this Raster Image Definition (DXF 10).
  */
  virtual OdGeVector2d size() const;


  /** Description:
    Returns the default physical pixel *size*, in mm/pixel, of the *image* for this Raster Image Definition object (DXF 10).
    
    Note:
    If the *image* has no default pixel *size*, 
    this function returns 1.0/(image width in pixels) for XY resolutions.
  */
  virtual OdGeVector2d resolutionMMPerPixel() const;

  /** Description:
    Sets the default physical pixel *size*, in mm/pixel, of the *image* for this Raster Image Definition object (DXF 10).
    
    Note:
    Loading the actual image file resets this value if the *image* has default pixel *size*.
  */
  virtual OdResult setResolutionMMPerPixel(const OdGeVector2d&);


  /** Description:
      TBC.
  */
  int entityCount(OdBool* pbLocked = 0) const;
  void updateEntities() const;
  
 

  /** Description:
    Returns the resolution units for the *image* for this Raster Image Definition object (DXF 281).
  */
  virtual Units resolutionUnits() const;

  /** Description:
    Sets the resolution units for the *image* for this Raster Image Definition object (DXF 281).

    Note:
    Loading the actual image file resets this value.
  */
  virtual void setResolutionUnits(OdDbRasterImageDef::Units);

  /** Description:
    Returns the OdGiRasterImage object associated with this RasterImageDef object 
  */
  virtual OdGiRasterImagePtr image(bool load = true);

  /** Description:
    Creates an *image* from the specified OdGiRasterImage object.
    Arguments:
    pImage (I) Pointer to the RasterImage object.
    modifyDatabase (I) If and only if true, marks the associated OdDbDatabase instance as *modified*.
    
    Remarks:
    isLoaded() returns false if pImage is NULL. Otherwise, it is returns true..
  */
  virtual void setImage(OdGiRasterImage* pImage, OdBool modifyDatabase = kTrue);

  /** Description:
    Creates an *image* dictionary, if one is not already present, in the specified OdDbDatabase instance.

    Arguments:
    pDb (I) Pointer to the *database*.
    
    Remarks:
    Returns the Object ID of the *image* dictionary.
  */
  static OdDbObjectId createImageDictionary(OdDbDatabase* pDb);

  static OdResult createImageDictionary(OdDbDatabase* pDb, OdDbObjectId& dictId);
  /** Description:
    Returns the Object ID of the *image* dictionary in the specified OdDbDatabase instance.
    Arguments:
    pDb (I) Pointer to the *database*.  
  */
  static OdDbObjectId imageDictionary(OdDbDatabase* pDb);

  enum 
  { 
    kMaxSuggestNameSize = 2049 
  };

  /** Description:
    Massages the original *image* filename of this RasterImageDef object to produce an new
    *image* name suitable for an *image* dictionary.
    Arguments:
    pImageDictionary (I) Pointer to the *image* dictionary.
    newImageName (O) Receives the new *image* name. 
  */
  static OdString suggestName(const OdDbDictionary* pImageDictionary, OdString newImageName);

  //   comment this out for a while
  static OdResult suggestName(OdDbDictionary* pImageDictionary, const OdChar* pNewImagePathName, OdChar* newImageName);

  static OdResult suggestName(
    OdDbDictionary* pImageDictionary, 
    const OdChar* pNewImagePathName, 
    OdChar* newImageName,
    size_t nSize);

  virtual int colorDepth() const;
  OdGiSentScanLines* makeScanLines(
    const OdGiRequestScanLines* pReq,
    const OdGeMatrix2d& pixToScreen,
    OdGePoint2dArray* pActiveClipBndy = 0, // Data will be modified!
    OdBool draftQuality = false,
    OdBool isTransparent = false,
    const double brightness = 50.0,
    const double contrast = 50.0,
    const double fade = 0.0
    ) const;
//  OdString searchForActivePath();
  //This function is currently unimplemented, but may appear in a future release. It returns eNotImplemented. 
  OdResult embed();
  OdBool isEmbedded() const;
  virtual const OdChar* fileType() const;
  void setUndoStoreSize(unsigned int maxImages = 10);
  unsigned int undoStoreSize() const;
  OdBool imageModified() const;
  void setImageModified(OdBool modified);
  virtual IGcReadStream* getReadStream();
  void loadThumbnail(OdUInt16& maxWidth, OdUInt16& maxHeight,
    OdUInt8* pPalette = 0, int nPaletteEntries = 0);
  void unloadThumbnail();
  void* createThumbnailBitmap(BITMAPINFO*& pBitmapInfo,
    OdUInt8 brightness = 50, OdUInt8 contrast = 50, OdUInt8 fade = 0);
 // IeFileDesc* fileDescCopy() const;
  void getScanLines(OdGiBitmap& bitmap,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0) const;
  void openImage(IeImg*& pImage);
  void closeImage();
//  static Oda::ClassVersion classVersion();
  RasterImageDefImp* ptrImp() const;
  RasterImageDefImp* setPtrImp(RasterImageDefImp* pImp);

  OdResult            forceImageFileClosed(OdBool modifyDatabase);
private:
  RasterImageDefImp* mpImp;
//     static Oda::ClassVersion mVersion;
 // */
};




/** Description:
    This class implements Raster Image Definition Reactor objects in an OdDbDatabase instance.
    
    Library:
    TD_Db
    
    Remarks:
    Raster Image Definition Reactor (OdDbRasterImageDefReactor) objects are used 
    to notify Raster Image (OdDbRasterImage) objects 
    of changes to their associated Raster Image Definition (OdDbRasterImage) objects.
    
    Modifications of Image Definition objects redraw their dependent Raster Image entities. 
    Deletion of Image Definition objects delete their dependent Raster Image entities.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRasterImageDefReactor : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRasterImageDefReactor);
  
  static ClassVersion  classVersion();
  virtual ~OdDbRasterImageDefReactor();

  OdDbRasterImageDefReactor();

  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  void erased(
    const OdDbObject* pObject, 
    OdBool erasing = kTrue);

  void modified(
    const OdDbObject* pObject);

  enum DeleteImageEvent
  {
    kUnload = 1,
    kErase = 2
  };
  /** Description:
    Controls notifications of OdDbRasterImage object events.
    
    Arguments:
    enable (I) If and only if true, enables notifications.
  */
  static void setEnable(
    OdBool enable);

  /** Description:
    Notification function called whenever an OdDbRasterImageDef object is about to be unloaded or *erased*.
    
    Arguments:
    pImageDef (I) Pointer to the OdDbRasterImageDef object sending this notification.
    event (I) Event triggering the notification.
    cancelAllowed (I) True to *enable* user cancellation, false to *disable*.
    
    Remarks:
    Returns true if and only if not cancelled. 
    
    event must be one of the following:
    
    @table
    Name      Value
    kUnload   1
    kErase    2
    
    
    Note:
    Use imageModified() to determine if the Image Definition has been *modified*.
  */
  virtual OdBool onDeleteImage( 
    const OdDbRasterImageDef* pImageDef,
    IeImg* pImage,
    DeleteImageEvent event,
    OdBool cancelAllowed);

  /* comment this out for a while
     static Oda::ClassVersion classVersion();
private:

  OdDbRasterImageDefReactorImpl* mpImp;
     static Oda::ClassVersion mVersion;
  */
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbRasterImageDefReactor object pointers.
*/
typedef OdSmartPtr<OdDbRasterImageDefReactor> OdDbRasterImageDefReactorPtr;

/** Description:
    This class implements Raster Image Definition Transient Reactor objects in an OdDbDatabase instance.
    Library: TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRasterImageDefTransReactor : public OdDbObjectReactor
{
protected:
  OdDbRasterImageDefTransReactor() {}
public:
  ODRX_DECLARE_MEMBERS(OdDbRasterImageDefTransReactor);
  virtual  ~OdDbRasterImageDefTransReactor();

  /** Description:
    Notification function called whenever an OdDbRasterImageDef object is about to be unloaded or *erased*.
    
    Arguments:
    pImageDef (I) Pointer to the OdDbRasterImageDef object sending this notification.
    event (I) Event triggering the notification.
    cancelAllowed (I) True to *enable* user cancellation, false to *disable*.
    
    Remarks:
    Returns true if and only if not cancelled. 
    
    event must be one of the following:
    
    @table
    Name                                 Value
    OdDbRasterImageDefReactor::kUnload   1
    OdDbRasterImageDefReactor::kErase    2
  */
  virtual OdBool onDeleteImage( const OdDbRasterImageDef* pImageDef,
                              IeImg* pImage,
                              OdDbRasterImageDefReactor::DeleteImageEvent event,
                              OdBool cancelAllowed ) = 0;
};

/*   comment this for a while */


/** { Secret } */
class TOOLKIT_EXPORT OdDbRasterImageDefFileAccessReactor : public OdDbObjectReactor
{
protected:
  OdDbRasterImageDefFileAccessReactor() {}
public:
  ODRX_DECLARE_MEMBERS(OdDbRasterImageDefFileAccessReactor);

  virtual void onAttach(const OdDbRasterImageDef*, const OdChar* pPath) = 0;

  virtual void onDetach(const OdDbRasterImageDef*, const OdChar* pPath) = 0;

  virtual OdBool onOpen(const OdDbRasterImageDef*, const OdChar* pPath,
    const OdChar* pActivePath, OdBool& replacePath, OdChar*& replacementPath) = 0;

  virtual OdBool onPathChange(const OdDbRasterImageDef*,
    const OdChar* pPath, const OdChar* pActivePath,
    OdBool& replacePath, OdChar*& replacementPath) = 0;

  virtual void onClose(const OdDbRasterImageDef*, const OdChar* pPath) = 0;

  virtual void onDialog(OdDbRasterImageDef*,
    const OdChar* pCaption, const OdChar* pFileExtensions) = 0;
};
#if 0 

inline Oda::ClassVersion
OdDbRasterImageDef::classVersion()
{ return mVersion; }

inline Oda::ClassVersion
OdDbRasterImageDefReactor::classVersion()
{ return mVersion; }

#endif

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbRasterImageDef object pointers.
*/
typedef OdSmartPtr<OdDbRasterImageDef> OdDbRasterImageDefPtr;

#include "TD_PackPop.h"

#endif // __DBRASTERIMAGEDEF_H

