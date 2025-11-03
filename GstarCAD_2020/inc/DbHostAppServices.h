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




#ifndef _ODDBHOSTAPPLICATIONSERVICES_INCLUDED_
#define _ODDBHOSTAPPLICATIONSERVICES_INCLUDED_


#include "TD_PackPush.h"

#include "SmartPtr.h"
#include "DbBaseHostAppServices.h"
#include "DbAppSystemVariables.h"
#include "DbLayoutManager.h"
#include "OdStreamBuf.h"
#include "DbDatabase.h"
#include "OdFont.h"
#include "OdBinaryData.h"
#include "DbSecurity.h"
#include "DbPlotSettingsValidator.h"
#include "OdCodePage.h"

class OdDbKey;
class OdDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;
class OdHatchPatternManager;
class OdDbPageController;
class OdDbGlobals;
class GcadInternalServices;
class COleClientItem;
class CArchive;
struct _EXCEPTION_POINTERS;

typedef OdResult(*SELECTFILEPROC)(short* userCancel,
  OdChar*& chosenPath,
  void* h,
  const int nFlags,
  const OdChar* prompt,
  const OdChar* dir,
  const OdChar* name,
  const OdChar* type,
  int* pnChoice,
  bool* pbReadOnly,
  const OdChar* pszWSTags,
  void* pReserved);

typedef OdResult(*REMAPPROC) (OdChar*& newName, const OdChar* filename, int context, void* pReserved);
typedef void(*MAPFILENOTIFYPROC) (const OdChar* filename, const OdChar* newName, int context, void* pReserved);
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPageController object pointers.
*/
typedef OdSmartPtr<OdDbPageController> OdDbPageControllerPtr;


/** Description:
    This class is the base class for platform specific operations within Teigha.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbHostAppServices : public OdDbBaseHostAppServices
{
public:
  ODRX_DECLARE_MEMBERS(OdDbHostAppServices);

  OdDbHostAppServices(int createGlobals = 1);
  virtual ~OdDbHostAppServices();

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
    4.  The directories listed in the "ACAD" environment variable.
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
    OdDbBaseHostAppServices::FindFileHint hint = kDefault);

  virtual OdResult findFile(
    OdChar* pcFullPathOut, int nBufferLength,
    const OdChar* pcFilename, 
    OdDbDatabase * pDb = NULL,
    OdDbBaseHostAppServices::FindFileHint hint = kDefault);

  virtual OdResult getRemoteFile(
    const OdChar * pszURL, 
    OdChar * pszLocalFile, 
    OdBool bIgnoreCache = kFalse) const;

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
  virtual OdResult getRoamableRootFolder(const OdChar*& folder);

  virtual OdResult getLocalRootFolder(const OdChar*& folder);

  virtual OdResult selectFile(short* userCancel,
    OdChar*& chosenPath,
    void* h,
    const int nFlags,
    const OdChar* prompt,
    const OdChar* dir,
    const OdChar* name,
    const OdChar* type,
    int* pnChoice,
    bool* pbReadOnly,
    const OdChar* pszWSTags,
    void* pReserved);

  virtual OdResult registerSelectFileCallback(const OdChar* appName,
    SELECTFILEPROC proc,
    bool unRegister = false,
    bool asPrimary = false);

  virtual const OdChar* primaryClientForSelectFileCallback()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdResult getRegisteredSelectFileClients(OdArray<const OdChar*>& clients);

  virtual OdResult mapFile(OdChar*& newName,
    const OdChar* filename,
    int context,
    void* pReserved);

  virtual OdResult registerMapFileCallback(const OdChar* appName,
    REMAPPROC proc,
    bool unRegister = false,
    bool asPrimary = false);

  virtual const OdChar* primaryClientForMapFileCallback()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual bool setMapFlag(bool setIt)
  {
    throw OdError(OdResult::eNotImplemented);
  }
  virtual OdResult getRegisteredFileMapClients(OdArray<const OdChar*>& clients);

  virtual OdResult registerMapFileNotification(const OdChar* appName,
    MAPFILENOTIFYPROC,
    bool unRegister = false);

  virtual void fatalError(const OdChar* format, ...)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void reportUnhandledArxException(const _EXCEPTION_POINTERS* pExcPtrs,
    const OdChar* pAppName)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void displayChar(OdChar c) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void displayString(const OdChar* string, int count) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void enableMessageDisplay(OdBool)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void releaseProgressMeter(
    OdDbHostAppProgressMeter* pProgressMeter);

  /** Description:
    Returns the static OdRxClass *description* object associated with the *database*.

    Remarks:
    Returns OdDbDatabase::desc();
  */
  virtual OdRxClass* databaseClass() const;

  /** Description:
    Creates an instance of an OdDbDatabase object.

    Arguments:
    createDefault (I) If and only if true, the newly created *database*
            will be populated with the default set of objects (all tables, ModelSpace and PaperSpace blocks
            etc.)
    measurement (I) Units of *measurement* for creating the *database*.

    Remarks:
    Returns the newly created *database*.

    This HostAppServices object will be associated with the newly created *database*.

    measurement must be one of the following:

    @table
    Name              Value   Description
    OdDb::kEnglish    0       English
    OdDb::kMetric     1       Metric

   */
  virtual OdDbDatabasePtr createDatabase(
    bool createDefault = true,
    OdDb::MeasurementValue measurement = OdDb::kEnglish) const;

  /** Description:
    Loads the contents of the specified StreamBuf or DWG/DXF file into the
    *database* with which this HostAppServices object is associated.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
    partialLoad (I) Controls the *partial* loading of .dwg files.
    password (I) Password for file.
    allowCPConversion (I) If and only if true, allows code page conversion.

    Remarks:
    Returns a SmartPointer to the *database* containing the contents of the file.
  */
  virtual OdDbDatabasePtr readFile(
    OdStreamBuf* pStreamBuf,
    bool allowCPConversion = false,
    bool partialLoad = false,
    const OdPassword& password = OdPassword());

  /** Description:
    Performs a recover operation on the specified StreamBuf file.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.
    password (I) Password for file.


    Remarks:
    The specified AuditInfo object controls the *audit*, and receives the *audit* status.

    When overriding this function for a custom class, first call OdDbObject::audit(pAuditInfo)
    to validate the *audit* operation.
  */
  virtual OdDbDatabasePtr recoverFile(
    OdStreamBuf* pStreamBuf,
    OdDbAuditInfo *pAuditInfo = 0,
    const OdPassword& password = OdPassword());

  /** Description:
    Arguments:
    filename (I) Path of the DWG/DXF file to read.
    shareMode (I) Sharing mode to use when opening the file.

    Remarks:
    shareMode must be one of the following:

    @table
    Name                         Value       Description
    Oda::kShareDenyReadWrite     0x10        deny read/write mode
    Oda::kShareDenyWrite         0x20        deny write mode
    Oda::kShareDenyRead          0x30        deny read mode
    Oda::kShareDenyNo            0x40        deny none mode
  */
  virtual OdDbDatabasePtr readFile(
    const OdString& filename,
    bool allowCPConversion = false,
    bool partialLoad = false,
    Oda::FileShareMode shareMode = Oda::kShareDenyNo,
    const OdPassword& password = OdPassword())
  {
    Oda::FileAccessMode nDesiredAccess = Oda::kFileRead;
    return readFile(odSystemServices()->createFile(filename, nDesiredAccess, shareMode),
      allowCPConversion, partialLoad, password);
  }

  virtual OdDbDatabasePtr recoverFile(
    const OdString& filename,
    Oda::FileShareMode shareMode = Oda::kShareDenyNo,
    OdDbAuditInfo *pAuditInfo = 0,
    const OdPassword& password = OdPassword())
  {
    Oda::FileAccessMode nDesiredAccess = Oda::kFileRead;
    return recoverFile(odSystemServices()->createFile(filename, nDesiredAccess, shareMode),pAuditInfo, password);
  }

  /** Description:
    Returns a pointer to a  string  for displaying  the color name.

    Arguments:
    pszColor (I) The color name. Possible input is "ByLayer", "ByBlock", "Red" etc.

    Remarks:
    The pointer may be temporary and should not be stored for later use.

    Note:
    The default implementation of this function returns the input color name.
  */
  void setWorkingProgressMeter(OdDbHostApplicationProgressMeter* pNewMeter)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual ClipBoundaryArray* newClipBoundaryArray()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual const OdChar * colorNameForDisplay(const OdChar* pszColorName);

  /** Description:
    Returns the *name* of the client *program*.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getLibName()
  */
  virtual const OdChar * program();

  /** Description:
    Returns the *name* of the client *product*.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns program().
  */
  virtual const OdChar * product();
  
  void setDefaultUndoController(OdDbUndoController* pUndoCtrl)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  void setWorkingTransactionManager(OdDbTransactionManager* pTM)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdDbGlobals* createWorkingGlobals()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  OdDbGlobals* workingGlobals() const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  void setWorkingGlobals(OdDbGlobals* pGlobals) 
  {
    throw OdError(OdResult::eNotImplemented);
  }

  void setWorkingAppSysvars(OdDbAppSystemVariables* pSysvars)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual bool supportsMultiRedo() const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  enum ModelerFlavor { kModelerFull = 0, kModelerRegionsOnly = 1, kModelerObjectsOnly = 2 };

  virtual ModelerFlavor getModelerFlavor() const 
  {
    throw OdError(OdResult::eNotImplemented);
  }

  void setSystemCodePage(OdCodePageId)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual GcadInternalServices* gcadInternalServices()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  /** Description:
    Returns the *name* of the client company.

    Remarks:
    This function is typically used for populating "About" information.

    Note:
    The default implementation of this function returns oddbGetLibraryInfo()->getCompanyName().
  */
  virtual const OdChar * companyName();

  // Determine whether a given string ('pszURL') is a valid URL.
  //
  virtual OdBool isURL(const OdChar * pszURL) const;

  // 'isRemoteFile()' is the inverse of 'isURL()'--it provides a mapping
  // from a local file to the corresponding URL that the file was down-
  // loaded from. The URL, if any, is returned via 'pszURL.'
  //
  virtual OdBool isRemoteFile(const OdChar * pszLocalFile,
                              OdChar * pszURL) const;

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
    const OdString& message) { odSystemServices()->warning(message); };

  virtual void warning(
    OdWarning warningOb) { warning(getErrorDescription(warningOb)); }

  virtual void warning(
    OdWarning warningOb,
    OdDbObjectId objectId);

  virtual void warning(
    const OdError& err)  { warning(err.description()); }


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
    Returns true if and only if Teigha is to do full-time CRC checking on *database* filing operations.

    Remarks:
    The default implementation of this function always returns false.
    Override this function to return true or false as desired to control this checking.
  */
  virtual bool doFullCRCCheck();

  /** Description:
    Returns an alternate UndoController object for Teigha.

    Remarks:
    The default implementation of this function always returns a null SmartPointer.

    Each database requires at most 2 undo controllers (for undo and redo).
  */
  virtual OdDbUndoControllerPtr newUndoController();
  virtual OdUInt32 getUndoControlData(int nIndex);
  /** Description:
    Print the audit report for the specified AuditInfo object.

    Arguments:
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.
    strLine (I) The string to print.
    printDest (I) Print destination.

    Remarks:
    The default implementation of this function does nothing but return.
   */
  virtual OdBool launchBrowserDialog(OdChar* pszSelectedURL,
    const OdChar* pszDialogTitle,
    const OdChar* pszOpenButtonCaption,
    const OdChar* pszStartURL,
    const OdChar* pszRegistryRootKey = 0,
    OdBool bOpenButtonAlwaysEnabled = false) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdResult putRemoteFile(const OdChar* pszURL,
    const OdChar* pszLocalFile) const;

  virtual OdResult getNewOleClientItem(COleClientItem*& pItem);

  virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
    OdLongPtr hdc,
    long left, long top, long right, long bottom)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdResult serializeOleItem(COleClientItem* pItem, CArchive*);

  virtual void terminateScript()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdBool getSubstituteFont(OdChar** pFileName,
    OdChar* prompt,
    int type, int fontAlt)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void alert(const OdChar* string) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void auditPrintReport(OdDbAuditInfo * pAuditInfo,
    const OdChar* line,
    int both) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void getDefaultPlotCfgInfo(OdChar* plotDeviceName, OdChar* plotStyleName)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual OdResult signingComplete(OdResult es,
    const OdChar* msg,
    bool* result);

  enum PasswordOptions { kPasswordOptionDefault = 0, kPasswordOptionUpperCase = 1, kPasswordOptionIsExternalReference = 2 };

  virtual bool getPassword(const OdChar* dwgName,
    PasswordOptions options,
    wchar_t* password,
    const size_t bufSize)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual bool loadApp(const OdChar* appName,
    OdaApp::LoadReasons why,
    bool printit,
    bool asCmd)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual short getKeyState(int nVirtKey) const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void usedPasswordFromCacheMsg(const OdChar* dwgName)
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void missingCryptoProviderMsg()
  {
    throw OdError(OdResult::eNotImplemented);
  }

  OdPwdCache* getPasswordCache() const
  {
    throw OdError(OdResult::eNotImplemented);
  }

  virtual void auditPrintReport(
    OdAuditInfo* pAuditInfo,
    const OdString& strLine,
    int printDest) const;

  /** Description:
    Returns the PlotSettingsValidator object associated with HostAppServices object.

    Remarks:
    If no PlotSettingsValidator object is associated with this HostAppServices object, one is created and
    associated with it.
  */
  virtual OdDbPlotSettingsValidator* plotSettingsValidator();

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

#define REGVAR_DEF(type, name, unused3, unused4, unused5)\
protected:\
  type  m_##name;\
public:\
  /** Description: Returns the ##NAME registry-resident system variable. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual type get##name() const;\
  \
  /** Description: Sets the ##NAME registry-resident system variable. \
    Arguments:  val (I) New value for ##NAME. ##RANGE \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual void set##name(type val);
#include "SysVarDefs.h"

  virtual OdUInt32 getMAXHATCHDENSITY() const;
  virtual void setMAXHATCHDENSITY(OdUInt32 val);
#undef REGVAR_DEF

  /** Description:
    Returns the instance of the application-wide system variables service. 
  */ 
  OdDbAppSystemVariables* workingAppSysvars() const;

  virtual OdString getAlternateFontName() const;

  /** Description:
    Returns the name of the font mapping file used by the getPreferableFont function.

    See Also:
    Font Handling

    Note:
    The default implementation of this function does nothing but return an empty string.
    It will be fully implemented in a future *release*.
  */
  virtual OdString getFontMapFileName() const;

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
    OdFontType fontType);

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
    OdFontType fontType);

  virtual void setAllowFontReplace(bool){};

  /** Description:
    Returns the PatternManager associated with this HostAppServices object.

    Remarks:
    If no PatternManager object is associated with this HostAppServices object, one is created and
    associated with it.
  */
  virtual OdHatchPatternManager* patternManager() = 0;

  /** Description:
    Notification function called whenever a drawing file requires a *password.*

    Arguments:
    dwgName (I) Drawing file requiring the *password*.
    isXref (I) True if and only if the drawing file is being opened as an Xref.
    password (O) Password.

    Remarks:
    Prompts the user for a *password* and returns said *password*.

    Returns false if the user cancels the *password* entry, or
    if there is no user.

    Note:
    The default implementation of this function does nothing but return false.
  */
  virtual bool getPassword(
    const OdString& dwgName,
    bool isXref,
    OdPassword& password);

  /** { Secret } */
  virtual OdPwdCachePtr getPasswordCache();

  /** Description:
    Returns an alternate PageController object for Teigha.

    Remarks:
    The paging type will be determined by the overridden OdDbPageController::pagingType
    function in the returned instance.

    A null SmartPointer indicates no paging of *database* objects is to be done.

    Note:
    The default implementation of this function always returns a null SmartPointer.
  */
  virtual OdDbPageControllerPtr newPageController();


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

  virtual OdDbLayoutManager* layoutManager() const;

  /** Description:
  Returns non-zero if the application copy is educational.
  */
  virtual OdUInt32 educationalPlotStamp() const;

  /** Description:
    Returns the OdDgHostAppServices object used for reading dgn files.
  */
  virtual OdDbBaseHostAppServices* getDgnHostAppServices() const;

  virtual OdDbKey* key() const = 0;

  void setWorkingDatabase(OdDbDatabase* pDatabase);

  OdDbDatabase* workingDatabase() const;

  int getSystemCodePage(){return 1;}

  virtual bool readyToDisplayMessages() { return false; }
  virtual bool cacheSymbolIndices() { return false; }
  virtual const OdChar * getRegistryProductRootKey() { return NULL; }
  virtual const OdChar* getUserRegistryProductRootKey() { return NULL; }
  virtual const OdChar* getMachineRegistryProductRootKey() { return NULL; }
  virtual int  getRegistryProductLCID() { return 1; }
  virtual void *defaultUndoController() { return (void*)NULL; }
  virtual OdDbTransactionManager* workingTransactionManager();
  virtual OdUInt32 getTempPath(int, OdChar *) { return 0; }

  virtual const OdChar * getColorBookLocation() const { return NULL; }

  virtual void flushGraphic() {}

  virtual OdString getNextNewLayoutName(OdDbDatabase*) {return OD_T("Layout");}

  // 输出字符串
  virtual void edPrompt(const OdChar*) { }

  virtual const OdChar* getEnv(const OdChar* var) { return NULL; }

  virtual OdBool userBreak(bool updCtrlsWhenEnteringIdle = true) const { updCtrlsWhenEnteringIdle;return kFalse; }

  virtual bool getAlternateSymbol(const OdString&, const OdString&, OdString&){return false;}

  virtual void readCustomUndo(OdDbDatabase*,OdDbDwgFiler*){}
  virtual bool getTTfFont(const OdString&, OdString&, bool&, bool&, int&, int&) const {return false;}

  virtual __int64 tickCount() { return 0; }

protected:
  OdDbDatabase*                 m_pWorkingDatabase;
  OdDbLayoutManagerPtr          m_pLayoutManager;
  OdDbPlotSettingsValidatorPtr  m_pValidator;
  OdPwdCachePtr                 m_pPwdCache;
};

/** Description:
    This class implements platform-dependent operations and progress metering.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
#ifndef PROTECTED_DLL_ENABLED
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbHostAppServices2 : public OdDbHostAppServices
#else
class ODRX_ABSTRACT OdDbHostAppServices2 : public OdDbHostAppServices
#endif
{
  virtual OdDbKey* key() const;
};

//为了避免频繁修改接口，这里增加一个类，可以扩展这个类，不影响OdDbHostAppServices接口修改
class TOOLKIT_EXPORT OdDbHostAppServicesEx
{
public:
  OdDbHostAppServicesEx(){}
  virtual ~OdDbHostAppServicesEx(){}

public:
  virtual void messageBox(const OdChar* str){}
  virtual const OdChar* localVisualStyleString(const OdChar* pName) const {return pName;}  
};

TOOLKIT_EXPORT OdDbHostAppServices* oddbHostApplicationServices(); 
inline OdDbDatabase* oddbWorkingDatabase() { return oddbHostApplicationServices()->workingDatabase(); }

TOOLKIT_EXPORT void odInitHostApp(OdDbHostAppServices* pApp);
TOOLKIT_EXPORT void odUninitHostApp();

TOOLKIT_EXPORT OdDbHostAppServicesEx* oddbHostApplicationServicesEx(); 
TOOLKIT_EXPORT void oddbSetHostApp(OdDbHostAppServicesEx* pApp);
//TOOLKIT_EXPORT const OdChar* odrxProductKey();

#include "TD_PackPop.h"

#endif /* _ODDBHOSTAPPLICATIONSERVICES_INCLUDED_ */



