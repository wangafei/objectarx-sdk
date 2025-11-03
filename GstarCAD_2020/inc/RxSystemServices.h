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


#ifndef _ODRXSYSTEMSERVICES_INCLUDED_
#define _ODRXSYSTEMSERVICES_INCLUDED_

#include <stdarg.h>

#include "RxObject.h"
#include "OdStreamBuf.h"
#include "OdCodePage.h"

class OdTimeStamp;
class OdRxModule;
class OdRxDictionary;
typedef OdSmartPtr<OdRxDictionary> OdRxDictionaryPtr;

#include "TD_PackPush.h"

#define _SH_DENYRW      0x10    /* deny read/write mode */
#define _SH_DENYWR      0x20    /* deny write mode */
#define _SH_DENYRD      0x30    /* deny read mode */
#define _SH_DENYNO      0x40    /* deny none mode */
/** Description:

    {group:TD_Namespaces}
*/
namespace Oda
{
  ///////////////// FILE SYSTEM SERVICES //////////////////


  enum FileAccessMode   // Access
  {
    kFileRead     = (long)
                    0x80000000,   // Read access. Use kFileRead | kFileWrite for read/write access.
    kFileWrite    = 0x40000000,   // Write access. Use kFileRead | kFileWrite for read/write access.
    kFileTmp      = 0x20000000,   // hint to use FILE_ATTRIBUTE_TEMPORARY  for 'FlagsAndAttributes'
    kFileDelete   = 0x10000000,   // hint to use FILE_FLAG_DELETE_ON_CLOSE for 'FlagsAndAttributes'
    kNoFlushWhenClosed = 0x08000000       //do NOT call FlushFileBuffers when closing file (tremendously accelerates writing small files)
  };

  enum FileShareMode
  {
    kShareDenyReadWrite = _SH_DENYRW,//0x10, // deny read/write mode
    kShareDenyWrite     = _SH_DENYWR,//0x20, // deny write mode
    kShareDenyRead      = _SH_DENYRD,//0x30, // deny read mode
    kShareDenyNo        = _SH_DENYNO//0x40  // deny none mode
  };


  enum FileCreationDisposition
  {
    kCreateNew        = 1,  // Creates a new file; fails if the specified file already exists.
    kCreateAlways     = 2,  // Creates a new file; overwrites any existing file.
    kOpenExisting     = 3,  // Opens the file; fails if the file does not exist.
    kOpenAlways       = 4,  // Opens the file; creates the file if it does not exist.
    kTruncateExisting = 5   // Truncates the file; fails if the file does not exist. The file must be open at least kFileWrite.
  };
}

/** Description:
    This class implements OdError objects with access to the Result codes and filenames
    of the objects related to the errors.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_FileException : public OdError
{
public:
  /** Arguments:
    code (I) Result *code*.
    filename (I) Filename.
  */
  OdError_FileException(OdResult code, const OdString& filename);
  /** Description:
    Returns the *filename* of this Error object.
  */
  OdString getFileName() const;
};

/** Description:
    This class implements FileException object with a Result *code* of eFileNotFound,
    and the *filename* of the object related to the error.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_FileNotFound : public OdError_FileException
{
public:
  /** Arguments:
    filename (I) Filename.
  */
  OdError_FileNotFound(const OdString& filename);
};

/** Description:
    This class implements FileException object with a Result *code* of eFileException,
    and the *filename* of the object related to the error.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_CantOpenFile : public OdError_FileException
{
public:
  /** Arguments:
    filename (I) Filename.
  */
  OdError_CantOpenFile(const OdString& filename);
};

/** Description:
    This class implements FileException object with a Result *code* of eFileWriteError,
    and the *filename* of the object related to the error.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_FileWriteError : public OdError_FileException
{
public:
  /** Arguments:
    filename (I) Filename.
  */
  OdError_FileWriteError(const OdString& filename);
};

/** Description:
    This class implements OdError objects with Result codes of eInvalidIndex.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_InvalidIndex : public OdError
{
public:
  OdError_InvalidIndex();
};

/** Description:
    This class implements OdError objects with Result codes of eInvalidKey.
    
    Library: TD_Root
    {group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError_InvalidKey: public OdError
{
public:
  OdError_InvalidKey();
};


/** Description:
    This class is the base class for classes that provide platform-dependent file operations for
    Teigha.
    
    Library: TD_Root
    
    {group:OdRx_Classes}
*/
class FIRSTDLL_EXPORT OdRxSystemServices : public OdRxObject
{
public:
  ///////////////// FILE SYSTEM SERVICES //////////////////

  /** Description:
    Creates and/or opens the specified file.
    Arguments:
    filename (I) Filename.
    accessMode (I) Access mode.
    shareMode (I) Share mode.
    creationDisposition (I) Creation disposition.
    
    Remarks:
    Returns a SmartPointer to an OdStreamBuf object for the file. 
    
    accessMode must be a combination of one or more of the following:
    
    @table
    Name                Value          Description
    Oda::kFileRead      0x80000000     Read access.
    Oda::kFileWrite     0x40000000     Write access.
    
    shareMode must be one of the following:
    
    @table
    Name                         Value       Description
    Oda::kShareDenyReadWrite     0x10        deny read/write mode
    Oda::kShareDenyWrite         0x20        deny write mode
    Oda::kShareDenyRead          0x30        deny read mode
    Oda::kShareDenyNo            0x40        deny none mode

    Creation disposition must be one of the following:
    
    @table
    Name                         Value     Description
    Oda::kCreateNew              1         Creates a new file; fails if the specified file already exists.
    Oda::kCreateAlways           2         Creates a new file; overwrites any existing file.
    Oda::kOpenExisting           3         Opens the file; fails if the file does not exist.
    Oda::kOpenAlways             4         Opens the file; creates the file if it does not exist.
    Oda::kTruncateExisting       5         Truncates the file; fails if the file does not exist. The file must be open at least Oda::kFileWrite.
  */
  virtual OdStreamBufPtr createFile(
    const OdString& filename,                    
    Oda::FileAccessMode accessMode = Oda::kFileRead,
    Oda::FileShareMode  shareMode = Oda::kShareDenyNo,                          
    Oda::FileCreationDisposition creationDisposition = Oda::kOpenExisting) = 0;

  /** Description:
    Returns true if and only if the specified file can be accessed in the specified mode.

    Arguments:
    filename (I) Filename.
    accessMode (I) Access mode.
    
    Remarks:
    accessMode must be a combination of one or more of the following:
    
    @table
    Name                Value          Description
    ..                  0              File exists.
    Oda::kFileRead      0x80000000     Read access.
    Oda::kFileWrite     0x40000000     Write access.

  */
  virtual bool accessFile(const OdString& filename, int accessMode) = 0;

  /** Description:
    Returns the creation time of the specified file.
    Arguments:
    filename (I) Filename.
    
    Remarks:
    On most platforms, this function will be implemented with the stat function (stat::st_ctime).
  */
  virtual OdInt64 getFileCTime(const OdString& filename) = 0;

  /** Description:
    Returns the modification time of the specified file.
    Arguments:
    filename (I) Filename.
    
    Remarks:
    On most platforms, this function will be implemented with the stat function (stat::st_mtime).
  */
  virtual OdInt64 getFileMTime(const OdString& filename) = 0;

  /** Description:
    Returns the size of the specified file.
    Arguments:
    filename (I) Filename.
    
    Remarks:
    On most platforms, this function will be implemented with the stat function (stat::st_size).
  */
  virtual OdInt64 getFileSize(const OdString& filename) = 0;

  /** Description:
    Returns the home directory of current user.
  */
  virtual OdString getHomeDir() = 0;

  /** Description:
    Returns a message string formatted using a vsprintf-style *format* string and argument list.
    Arguments:
    formatID (I) String resource identifier containing the format string. 
    argList (I) Argument list.   
  */
  virtual OdString formatMessage(unsigned int formatId, va_list* argList= 0) = 0;

  /** Description: 
    Assigns a value to this String object using a printf-style *format* string and arguments.
    Arguments:
    formatID (I) String resource identifier containing the format string. 
    Remarks:
    Returns a reference to this String Object.
  */
  virtual OdString formatMsg(unsigned int formatId, ...);

  /** Description:
    Returns the system code page.
  */
  virtual OdCodePageId systemCodePage() const = 0;
  
  /** Description:
    Returns a Globally Unique IDentifier (GUID) for this SystemServices object.
  */
  virtual OdString createGuid();

  /** Description:
    Loads the specified physical (platform-dependent) module.
    
    Remarks:
    Appends the appropriate version suffix onto the supplied module name.
    Returns the abstract (platform independent) module object,    
    which represents module functionality in Teigha.

    Arguments:
    moduleFileName (I) Module filename to load.
    silent (I) If true, no load status message will be printed.
  */
  virtual OdRxModule* loadModule(const OdString& moduleFileName, bool silent);

  /** Description:
    Unloads the specified physical (platform-dependent) module.

    Arguments:
    pModuleObj (I) Pointer to the module object to be unloaded.
  */
  virtual void unloadModule(OdRxModule* pModuleObj);

  /** Description:
    Returns the filename associated with the specified application name.

    Arguments:
    applicationName (I) TX application name.
  */
  virtual OdString findModule(const OdString& applicationName);

  /** Description:
    Displays in some manner the specified *warning* *message*.
    
    Arguments:
    message (I) Warning *message*.
  */
  virtual void warning(const OdString& message);

  /** Description:
    Loads the specified physical (platform-dependent) module.

    Remarks:
    Returns the abstract (platform independent) module object,    
    which represents module functionality in Teigha.

    Arguments:
    moduleFileName (I) Module filename to load.
    silent (I) If true, no load status message will be printed.
  */
  static OdRxModule* loadModuleLib(const OdString& moduleFileName, bool silent);

  /** Description:
  Inits\Uninits the modeler library (platform-dependent) module.

  Remarks:
  Should return eOk, if (un)initialization is implemented inside (un)initModelerLibrary.
  Or eNotImplemented if default module (un)initialization required.

  Note:
   Used for custom initialization\uninitialization of Spatial ACIS library.
  */
  virtual OdResult initModelerLibrary() = 0;
  virtual OdResult uninitModelerLibrary() = 0;
  /** \details
  Get environment variable value.
  */
  virtual OdResult getEnvVar(const OdString &varName, OdString &value);

  /** \details
  Set environment variable value.
  */
  virtual OdResult setEnvVar(const OdString &varName, const OdString &newValue);
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxSystemServices object pointers.
*/
typedef OdSmartPtr<OdRxSystemServices> OdRxSystemServicesPtr;

FIRSTDLL_EXPORT OdRxSystemServices* odrxSystemServices();

#include "TD_PackPop.h"

#endif // #ifndef _ODRXSYSTEMSERVICES_INCLUDED_
