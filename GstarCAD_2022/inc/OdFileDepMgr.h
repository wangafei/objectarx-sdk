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


#ifndef _ODFILEDEPMGR_INCLUDED_
#define _ODFILEDEPMGR_INCLUDED_

#include "OdString.h"
#include "RxDictionary.h"

/** Description:
    This class represents entries in the DWG section of File Dependency List.
    Library: TD_Db
    {group:Other_Classes} 
*/
class TOOLKIT_EXPORT OdFileDependencyInfo : public OdRxObject
{
protected:
  OdFileDependencyInfo();

public:
  ODRX_DECLARE_MEMBERS(OdFileDependencyInfo);
  virtual OdResult copyFrom(
    const OdRxObject* pSource);
  OdString m_FullFileName;      // Full name of file.
  OdString m_FileName;          // Base name of file.
  OdString m_FoundPath;         // Path at which file was found.
  OdString m_FingerprintGuid;   // Fingerprint GUID.
  OdString m_VersionGuid;       // Version GUID.
  OdString m_Feature;           // Name of the application or *feature* that created this entry.
  bool m_bIsModified;           // Database was modified since last save.
  bool m_bAffectsGraphics;      // Entry affects the screen view.
  OdInt32 m_nIndex;             // Unique File Dependency List *index*.
  OdInt32 m_nTimeStamp;         // Seconds since 1/1/1980.
  OdInt32 m_nFileSize;          // Current File size.
  OdInt32 m_nReferenceCount;    // Current reference count for *database*.
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdFileDependencyInfo object pointers.
*/
typedef OdSmartPtr<OdFileDependencyInfo> OdFileDependencyInfoPtr;

/** Description:
    This class allows management of entries in the DWG section of the File Dependency List. 

    Library: TD_Db
    
    Remarks:
    Every OdDbDatabase instance has permanently associated with it an instance of the this class.
    {group:Other_Classes} 
*/
class TOOLKIT_EXPORT OdFileDependencyManager : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFileDependencyManager);

  OdFileDependencyManager() {};
  
  virtual ~OdFileDependencyManager() {};

  /** Description:
    Creates an entry in the DWG section of the File Dependency List.

    Arguments:
    feature (I) Name of the application or *feature* creating the entry.
    fullFileName (I) Full name of file for the entry.
    affectsGraphics (I) True if and only if the entry affects the screen view.
    noIncrement (I) If true, duplicate records are created instead of 
                    incrementing the reference count of the existing entry.
    
    Remarks:
    Returns the Unique File Dependency List ID for the new entry, or 0 if not successful.
  */
  virtual long createEntry(
    const OdChar* feature,
    const OdChar* fullFileName,
    const bool affectsGraphics = false,
    const bool noIncrement = false) = 0;


  /** Description:
    Returns the specified entry in the DWG section of the File Dependency List.
    
    Arguments:
    feature (I) Name of the application or *feature* that created the entry.
    fullFileName (I) Full name of file for the entry.
    fdlIndex (I) File Dependency List *index*.
    fileInfo (O) Receives the file dependency information
    useCachedInfo (I) True to use cached information, false to use updated information.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getEntry(
    const OdChar* feature,
    const OdChar* fullFileName,
    OdFileDependencyInfo*& fileInfo, 
    const bool useCachedInfo = false) = 0;

  virtual OdResult getEntry(
    const long fdlIndex,
    OdFileDependencyInfo*& fileInfo, 
    const bool useCachedInfo = false) = 0;

  /** Description:
    Updates the specified entry in the DWG section of the File Dependency List.
    
    Arguments:
    feature (I) Name of the application or *feature* that created the entry.
    fullFileName (I) Full name of file for the entry.
    index (I) File Dependency List *index*.

    Remarks:
    This function resets the mIsModified, mTimestamp, and mFileSize members of the entry.    
  */
  virtual OdResult updateEntry(
    const OdChar* feature,
    const OdChar* fullFileName) = 0;
  virtual OdResult updateEntry(
    const long index) = 0;

  /** Description:
    Erases the specified entry from the DWG section of the File Dependency List.
    
    Arguments:
    feature (I) Name of the application or *feature* that created the entry.
    fullFileName (I) Full name of file for the entry.
    fdlIndex (I) File Dependency List *index*.
    forceRemove (I) True to erases the entry regardless of its reference count.

    Remarks:
    If the reference count of the entry is 1, or forceRemove is true, the entry is erased. Otherwise,
    this function merely decrements the reference count.
  */
  virtual OdResult eraseEntry(
    const OdChar* feature,
    const OdChar* fullFileName,
    const bool forceRemove = false) = 0;
  virtual OdResult eraseEntry(
    const long fdlIndex,
    const bool forceRemove = false) = 0;

  /** Description:
    Returns the number of unique entries in the DWG section of the File Dependency List.
  */
  virtual long countEntries() = 0;

  /** Description:
    Initializes an iterator for the DWG section of the File Dependency List.
    
    Arguments:
    feature (I) Name of the application or *feature* creating the entry.
    modifiedOnly (I) True to return only modified entries.
    affectsGraphicsOnly (I) True to return only  entries that effect the screen view.
    walkXRefTree (I) True to traverse the File Dependency Lists of Xref'd drawings.    
    
    Remarks:
    If no arguments are specified, all entries in the local list will be traversed. 
    Specifying feature, modifiedOnly true, and/or affectsGraphicsOnly true will restrict the entries traversed.
  */
  virtual void iteratorInitialize(
    const OdChar* feature = NULL, 
    const bool modifiedOnly = false,
    const bool affectsGraphicsOnly = false,
    const bool walkXRefTree = false) = 0;

  /** Description:
    Returns the *index* of the next entry in the DWG section of the File Dependency List.
    
    Remarks:
    The returned value may be used in the getEntry() and eraseEntry() functions.
  */
  virtual long iteratorNext() = 0;

  // get feature list for saving

  /** Description:
    Returns the dictionary containing the *feature* list in the DWG section of the File Dependency List.
  */
  virtual void getFeatures(
    OdRxDictionaryPtr& features) = 0;
  
  /** Description:
    Removes the Xref entries added to the DWG section of the File Dependency List
    by iteratorInitialize.
  */
  virtual void clearXRefEntries() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdFileDependencyManager object pointers.
*/
typedef OdSmartPtr<OdFileDependencyManager> OdFileDependencyManagerPtr;

#endif
