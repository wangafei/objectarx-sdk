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




#ifndef _OD_AUDITINFO_INCLUDED_
#define _OD_AUDITINFO_INCLUDED_

#include "TD_PackPush.h"

#include "DbRootExport.h"
#include "OdString.h"
#include "CmColor.h"
#include "RxObject.h"
#include "DbHandle.h"
class OdAuditInfoImpl;
//class OdRxObject;

#define ODDB_AUDIT_RETURN(pAuditInfo, baseEs, localEs, boilDownLocalStatus)        \
  return (baseEs != eOk)                ?  \
             baseEs                     :  \
             (eOk == localEs)           ?  \
                 eOk                    :  \
                 boilDownLocalStatus    ?  \
                (pAuditInfo->fixErrors()?  \
                    eFixedAllErrors     :  \
                    eLeftErrorsUnfixed) :  \
                                localEs;

/** Description:
  This class tracks audit information during a *database* audit.

  Library:
  TD_Db

  {group:OdDb_Classes}
*/
class DBROOT_EXPORT OdAuditInfo
{
public:
  enum AuditPass 
  {
    PASS1 = 1,
    PASS2 = 2
  };

  enum PrintDest
  {
    kSilent  = 0, // None.
    kCmdLine = 1, // Command line.
    kFile    = 2, // File.
    kBoth    = 3  // Both command line and file.
  };
  struct MsgInfo
  {
    OdString strName;
    OdString strValue;
    OdString strValidation;
    OdString strDefaultValue;
    bool     bIsError;
  };

  OdAuditInfo();

  virtual ~OdAuditInfo();

  /** Description:
    Returns true if and only if errors are to be fixed during the
    audit that uses this AuditInfo object.
  */
  bool fixErrors() const;

  /** Description:
    Controls the fixing of errors are to be fixed during the
    audit that uses this AuditInfo object.

    Arguments:
    fixErrors (I) Fix errors.
  */
  void setFixErrors(
    bool fixErrors);

  /** Description:
    Returns the number of errors reported to this AuditInfo object.
  */
  int numErrors() const;

  /** Description:
    Returns the number of errors reported as fixed to this AuditInfo object.
  */
  int numFixes() const;

  /** Description:
    Increments the *count* of errors reported to this AuditInfo object.
    Arguments:
    increment (I) Increment.
  */
  void errorsFound(
    int count);

  /** Description:
    Increments the *count* of errors reported as fixed to this AuditInfo object.
    Arguments:
    increment (I) Increment.
  */
  void errorsFixed(
    int count);

  // The audit pass number: 1 = pass 1, 2 = pass 2.
  AuditPass auditPass(void) const;

  /** Description:
    Notification function called to print error information.
    Remarks:
    Prints log information about an error detected or fixed during an audit.

    Arguments:
    name(I) Type of erroneous data found.
    value (I) Value of the bad data.
    validation (I) Reason the data were bad.
    defaultValue (I) Default *value* to which the were set.

    Note:
    As implemented, this functions does nothing.
  */
  virtual void printError(
    const OdChar * name, 
    const OdChar * value, 
    const OdChar * validation = OD_T(""), 
    const OdChar * defaultValue = OD_T(""));

  /**
    Arguments:
    pObject (I) Pointer to the object which generated the error.

    Remarks:
    pObject->isA()->name() is used to generate the *name*.
  */
  virtual void printError(
    const OdRxObject* pObject,
    const OdChar * value, 
    const OdChar * validation = OD_T(""), 
    const OdChar * defaultValue = OD_T(""));

  /** Description:
    Notification function called to print log information.

    Arguments:
    logInfo (I) Log information.
  */
  virtual void printInfo (
    const OdString& logInfo);

  /** Description:
    Allows fixed objects to specify a regen is required.
  */
  void requestRegen();

  /** Description:
    Resets the number of errors reported to this AuditInfo object.
  */
  void resetNumEntities();

  /** Description:
    Increments by one the number of errors reported as processed to this AuditInfo object.
  */
  void incNumEntities();

  /** Description:
    Returns the number of entities reported as processed to this AuditInfo object.
  */
  int numEntities();

  /** Description:
    Returns the last error information that is intended for printing.
  */
  virtual const MsgInfo& getLastInfo();

  /** Description:
    Sets the last error information that is intended for printing.
    Arguments:
    lastInfo (I) Last error information.
  */
  virtual void setLastInfo(
    MsgInfo &lastInfo);

  /*  If the current count of entities being maintained in the instance
      of OdAuditInfo is a multiple of 100, and msg is not NULL,
      then this function will print the string pointed to by msg
      followed by the current entity count out to the audit log file.
  */
  void printNumEntities(const OdChar* msg);

  /** Description:
    Sets the destination for log printing.
    Arguments:
    printDest (I) Print destination.

    Remarks:
    printDest must be one of the following:

    @table
    Name        Value  Description
    kSilent     0      None.
    kCmdLine    1      Command line.
    kFile       2      File.
    kBoth       3      Both command line and file.
  */
  void setPrintDest(
    PrintDest printDest);

  /** Description:
    Returns the destination for log printing.

    Remarks:
    getPrintDest() returns one of the following:

    @table
    Name        Value  Description
    kSilent     0      None.
    kCmdLine    1      Command line.
    kFile       2      File.
    kBoth       3      Both command line and file.
  */
  PrintDest  getPrintDest();

  //arx 2008
  OdResult fetchObject(OdDbStub*  originalObjId,
    OdDbStub*& newObjId,
    OdRxClass*    pObjClass,
    bool          uneraseIfPossible = false,
    bool          createIfNotFound = true,
    bool          externalDbOk = false);

  //arx 2008
  OdResult registerObject(OdDbHandle handle,
    bool        objIsValid,
    OdRxClass*  pObjClass);

  //arx 2008
  OdResult updateObject(OdDbHandle   handle,
    bool         setFileObjIsValid,
    bool         setNewObjIsValid,
    bool         setFileObjClass,
    bool         setNewObjClass,
    bool         setNewObjId,
    bool         fileObjIsValid,
    bool         newObjIsValid,
    OdRxClass*   pFileObjClass,
    OdRxClass*   pNewObjClass,
    OdDbStub* newObjId);

private:
  OdAuditInfoImpl* m_pImpl;
};

#include "TD_PackPop.h"

#endif // _OD_AUDITINFO_INCLUDED_

