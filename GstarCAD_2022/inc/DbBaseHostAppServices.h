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




#ifndef _ODDB_BASEHOSTAPPSERVICES_INCLUDED_
#define _ODDB_BASEHOSTAPPSERVICES_INCLUDED_


#include "TD_PackPush.h"


#include "DbRootExport.h"
#include "DbBaseDatabase.h"
#include "DbHostAppProgressMeter.h"
#include "RxObject.h"
#include "SmartPtr.h"
#include "OdFont.h"
#include "DbAppSystemVariables.h"

class OdGsDevice;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGsDevice object pointers.
*/
typedef OdSmartPtr<OdGsDevice> OdGsDevicePtr;

class OdDbUndoController;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbUndoController object pointers.
*/
typedef OdSmartPtr<OdDbUndoController> OdDbUndoControllerPtr;

class OdAuditInfo;
class OdTtfDescriptor;

typedef unsigned long LCID;

class OdDbTransactionManager;

enum OdSDIValues
{
  kMDIEnabled             = 0,
  kSDIUserEnforced        = 1,
  kSDIAppEnforced         = 2,
  kSDIUserAndAppEnforced  = 3
};

enum ProdIdCode
{
  kProd_ACAD = 1, // Plain
  kProd_LT   = 2, // Lite
  kProd_OEM  = 3, // OEM
  kProd_OdDb = 4  // ..
};


/** Description:
    This class is the base class for platform specific operations within Teigha.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT DBROOT_EXPORT OdDbBaseHostAppServices : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseHostAppServices);

  OdDbBaseHostAppServices();

  enum RemapFileContext
  {
    kDrawingOpen        = 0,
    kXrefResolution     = 1,
    kRasterResolution   = 2,
    kAfterXrefResolution
  };

  enum FindFileHint
  {
    kDefault              = 0,  // Any file.
    kFontFile             = 1,  // Can be either SHX or TTF file.
    kCompiledShapeFile    = 2,  // SHX file.
    kTrueTypeFontFile     = 3,  // TTF file.
    kEmbeddedImageFile    = 4,  // Image file (ISM).
    kXRefDrawing          = 5,  // Drawing template file (DWT).
    kPatternFile          = 6,  // Pattern file (PAT).
    kTXApplication        = 7,  // Teigha(R) Xtension file (TX).
    kFontMapFile          = 8,  // FontMap file (FMP).
    kUnderlayFile         = 9,  // Underlay file
    kTextureMapFile       = 10,
    kPlotStyleFile        = 11
  };
  
  enum GsBitmapDeviceFlags
  {
    kUseSoftwareHLR       = (1 << 0), // Enable use of SoftwareHLR on device
    kFor2dExportRender    = (1 << 1), // Device for shaded viewport export
    kFor2dExportRenderHLR = (1 << 2), // Device for HiddenLine viewport export
    kForThumbnail         = (1 << 3)  // Device for thumbnail image generation
  };
  /** Description:
    Returns the fully qualified path to the specified file.

    Arguments:
    filename (I) Name of the file to find.
    pDb (I) Pointer to the *database* *context*.
    hint (I) Hint that indicates the type of file that is required.

    Remarks:
    Returns an empty string if the file is not found.

    This function is called by Teigha when access is needed to a
    file, such as a font file, a template file, etc.

    pDb == 0 specifies that this file search is not related to a *database*.

    If pDb != 0, call pDb->getFilename() to determine the path to the DWG
    file associated with the *database*.

    The typical search order is as follows:

    1.  The filename itself.
    2.  The current directory.
    3.  The drawing directory (for shx font, image, and xref files).
    4.  The directories listed in the ACAD environment variable.
    5.  The Windows fonts directory (only for TTF fonts on Windows).

    hint must be one of the following:

    @table
    Name                    Value     Description Extension
    kDefault                0         Any file.                         any
    kFontFile               1         Can be either SHX or TTF file.    SHX or TTF
    kCompiledShapeFile      2         SHX file.                         SHX
    kTrueTypeFontFile       3         TTF file.                         TTF
    kEmbeddedImageFile      4         Image file.                       ISM
    kXRefDrawing            5         Drawing template file.            DWT
    kPatternFile            6         Pattern file (PAT)                PAT
    kTXApplication          7         Teigha(R) Xtension file.            TX
    kFontMapFile            8         FontMap file                      FMP
    kUnderlayFile           9         Underlay file
    kTextureMapFile        10

    Note:
    The client application can, in fact return any non-null string, so long as
    the application can handle that string in OdDbSystemServices::createFile.
  */
  virtual OdString findFile(
    const OdString& filename,
    OdDbBaseDatabase* pDb = 0,
    FindFileHint hint = kDefault) = 0;

  virtual OdResult findFile(
    OdChar* pcFullPathOut, int nBufferLength,
    const OdChar* pcFilename, 
    OdDbDatabase * pDb = NULL,
    FindFileHint hint = kDefault) = 0;

  /** Description:
    Returns an instance of an OdDbHostAppProgressMeter.
  */
  virtual OdDbHostAppProgressMeter* newProgressMeter();

  /** Description:
    Notification function called whenever Teigha no longer needs the specified
    ProgressMeter object.

    Arguments:
    pProgressMeter (I) Pointer to the ProgressMeter object no longer needed by Teigha.

    Note:
    The default implementation of this function does nothing but return.
  */
  virtual void releaseProgressMeter(
    OdDbHostAppProgressMeter* pProgressMeter);

  /** Description:
    Returns the *name* of the client *program*.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getLibName()
  */
  virtual const OdChar * program() = 0;

  /** Description:
    Returns the *name* of the client *product*.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns program().
  */
  virtual const OdChar * product() = 0;

  /** Description:
    Returns the *name* of the client company.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getCompanyName().
  */
  virtual const OdChar * companyName() = 0;

  /** Description:
    Returns the name of the client *product* code.

    Remarks:
    This function is typically used for populating "About" information.

    prodcode() returns one of the following:

    @table
    Name          Value   Description
    kProd_ACAD    1       Plain
    kProd_LT      2       Lite
    kProd_OEM     3       OEM
    kProd_OdDb    4       ..

    Note:
    The default implementation of this function returns kProd_OEM, and should not be overridden.
  */
  virtual ProdIdCode prodcode();

  /** Description:
    Returns the *release* major and minor version string of the client application.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getLibVersion().
  */
  virtual const OdChar * releaseMajorMinorString();

  /** Description:
    Returns the *release* major version of the client application.

    Note:
    The default implementation of this function returns TD_MAJOR_VERSION.
  */
  virtual int releaseMajorVersion();

  /** Description:
    Returns the *release* minor version of the client application.

    Note:
    The default implementation of this function returns TD_MINOR_VERSION.
  */
  virtual int releaseMinorVersion();

  /** Description:
    Returns the *release* version string of the client application.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getLibVersion().
  */
  virtual const OdChar * versionString();

  /** Description:
    Displays in some manner the specified *warning* *message*.

    Arguments:
    message (I) Warning *message*.
    warningOb (I) Warning object.
    objectId (I) Object ID of the object associated with the *warning*.

    Note:
    These functions call odSystemServices()->warning(message) to display the warning.
  */
  virtual void warning(
    const OdString& message);

  virtual void warning(
    OdWarning warningOb);

  //virtual void warning(
  //  OdWarning warningOb,
  //  OdDbObjectId objectId);

  /** Description:
    Returns the error *description* associated with the specified error code.
    Arguments:
    errorCode (I) Error code.

    Note:
    The default implementation of this function returns formatMessage(errorCode).
  */
  virtual OdString getErrorDescription(
    unsigned int errorCode);

  /** Description:
    Returns a formatted message corresponding to the specified error code(s).
    Arguments:
    errorCode (I) Error code.
   */
  virtual OdString formatMessage(
    unsigned int errorCode,...);
#ifdef ODA_FORMAT
  virtual OdString formatMessage(unsigned int errorCode, long i, const OdString& str) { return formatMessage(errorCode, i, (void*)str.c_str()); }
#endif

  /** Description:
    Returns an alternate UndoController object for Teigha.

    Remarks:
    The default implementation of this function always returns a null SmartPointer.

    Each database requires at most 2 undo controllers (for undo and redo).
  */
  virtual OdDbUndoControllerPtr newUndoController();


  virtual GcAdMemoryAllocator * getMemoryAllocator(OdDbDatabase *pDb = NULL);

  /** Description:
    Print the audit report for the specified AuditInfo object.

    Arguments:
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.
    strLine (I) The string to print.
    printDest (I) Print destination.

    Remarks:
    The default implementation of this function does nothing but return.
   */
  virtual void auditPrintReport(
    OdAuditInfo* pAuditInfo,
    const OdString& strLine,
    int printDest) const;

  /** Description:
    Locates the TTF or TTC file containing the specified font *description*.

    Arguments:
    description (I) Font *description*.
    filename (O) Receives the name of the TrueType font file.

    Remarks:
    Returns true and the *filename* if and only if the font file was found.

    Note:
    The non-Windows builds of this function do nothing but return.
  */
  virtual bool ttfFileNameByDescriptor(
    const OdTtfDescriptor& description,
    OdString& filename) = 0;

  /** Description:
    Returns the instance of the application-wide system variables service. 
  */ 
  virtual OdDbAppSystemVariables* workingAppSysvars() const = 0;

  /** Description:
    Returns the font file to be used when a given font file is
    not found by Teigha.

    See Also:
    Font Handling
  */
  virtual OdString getAlternateFontName() const = 0;

  /** Description:
    Returns the name of the font mapping file used by the getPreferableFont function.

    See Also:
    Font Handling

    Note:
    The default implementation of this function does nothing but return an empty string.
    It will be fully implemented in a future *release*.
  */
  virtual OdString getFontMapFileName() const = 0;

  /** Description:
    Returns the preferable font *name* for the specified font *name* and type.


    Arguments:
    fontName (I) Font *name*.
    fontType (I) Font type.

    Remarks:
    This function is called as the first step in the process of resolving a font file.
    The default implementation tries to locate a font mapping file by calling
    getFontMapFileName, and substitutes the font *name* based on the contents of this
    file.

    fontType must be one of the following:

    @table
    Name                    Value    Description
    kFontTypeUnknown        0        Unknown.
    kFontTypeShx            1        SHX font.
    kFontTypeTrueType       2        TrueType font.
    kFontTypeShape          3        Shape file.
    kFontTypeBig            4        BigFont file.

    See Also:
    Font Handling
  */
  virtual OdString getPreferableFont(
    const OdString& fontName,
    OdFontType fontType) = 0;

  /** Description:
    Returns the font to be used when the specified font is not found.

    Arguments:
    fontName (I) Font *name*.
    fontType (I) Font type.

    Remarks:
    fontType must be one of the following:

    @table
    Name                    Value    Description
    kFontTypeUnknown        0        Unknown.
    kFontTypeShx            1        SHX font.
    kFontTypeTrueType       2        TrueType font.
    kFontTypeShape          3        Shape file.
    kFontTypeBig            4        BigFont file.

    The default implementation of this function calls getAlternateFontName for
    fonts that are not of type kFontTypeShape or kFontTypeBig. When they are,
    and empty string is returned.

    Client code could override this function to perform custom substitution
    for these types of fonts.

    See Also:
    Font Handling
  */
  virtual OdString getSubstituteFont(
    const OdString& fontName,
    OdFontType fontType) = 0;

  /** Description:
    Prompts the user for a filename, and returns their response.

    Arguments:
    flags (I) Dialog behavior.
    dialogCaption (I) Dialog caption.
    defExt (I) Default file extension without "."
    defFilename (I) Default filename.
    filter (I) Filter pattern.

    Remarks:
    flags must be one of the following:

    @table
    Name          Value   Description
    kGfpForOpen   0       For Open.
    kGfpForSave   1       For Save.

    This function is intended for the selection of filenames via dialog boxes,
    although other methods may be used.

    o  Returns "*canceled*" if the user cancels the request.
    o  Returns "*unsupported*" if the application does not support this user input.

    Note:
    The default implementation of this function does nothing but return "*unsupported*".
  */
  virtual OdString fileDialog(
    int flags,
    const OdString& dialogCaption = OdString::kEmpty,
    const OdString& defExt = OdString::kEmpty,
    const OdString& defFilename = OdString::kEmpty,
    const OdString& filter = OdString::kEmpty);

  /** Description:
    Returns a the gsBitmapDevice associated with this HostAppServices object.
  */
  virtual OdGsDevicePtr gsBitmapDevice() = 0;

  virtual void setWorkingDatabase(OdDbDatabase* pDatabase) = 0;

  virtual OdDbDatabase* workingDatabase() const = 0;

  virtual int getSystemCodePage() = 0;

  virtual bool readyToDisplayMessages() = 0;
  virtual bool cacheSymbolIndices() = 0;
  virtual const OdChar * getRegistryProductRootKey() = 0;
  virtual int  getRegistryProductLCID() = 0;
  virtual void *defaultUndoController() = 0;
  virtual OdDbTransactionManager* workingTransactionManager() = 0;
  virtual OdUInt32 getTempPath(int nsize, OdChar *tempPath) = 0;
};


#include "TD_PackPop.h"

#endif // _ODDB_BASEHOSTAPPSERVICES_INCLUDED_
