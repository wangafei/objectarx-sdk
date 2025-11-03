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

#ifndef _ODDBSECURITY_INCLUDED_
#define _ODDBSECURITY_INCLUDED_

#include "RxObject.h"
#include "OdArray.h"
#include "DbExport.h"
#include "OdString.h"

enum
{
  SECURITYPARAMS_ENCRYPT_DATA     = 0x00000001,
  SECURITYPARAMS_ENCRYPT_PROPS    = 0x00000002,

  SECURITYPARAMS_SIGN_DATA        = 0x00000010,
  SECURITYPARAMS_ADD_TIMESTAMP    = 0x00000020,

  SECURITYPARAMS_ALGID_RC4        = 0x00006801
};

struct SecurityParams
{
    unsigned long   cbSize;
    unsigned long   ulFlags;        // see enum above for flag values

    // data relevant to password protection
    wchar_t*        wszPassword;
    unsigned long   ulProvType;
    wchar_t*        wszProvName;
    unsigned long   ulAlgId;        // SECURITYPARAMS_ALGID_RC4
    unsigned long   ulKeyLength;

    // data relevant to digital signatures
    wchar_t*        wszCertSubject;
    wchar_t*        wszCertIssuer;
    wchar_t*        wszCertSerialNum;
    wchar_t*        wszComment;
    wchar_t*        wszTimeServer;
};
typedef OdWString OdPassword;

/** Description:
    This class represents the security parameters used by OdCrypt classes.
    
    Library: TD_Db
    {group:Other_Classes}
*/
class OdSecurityParams
{
public:
  OdSecurityParams()
    : nFlags(0)
    , nProvType(0)
    , nAlgId (SECURITYPARAMS_ALGID_RC4)
    , nKeyLength(40)
  {}

  OdUInt32    nFlags;
  OdPassword  password;
  OdUInt32    nProvType;
  OdWString   provName;
  OdUInt32    nAlgId;
  OdUInt32    nKeyLength;

  OdWString   sCertSubject;
  OdWString   sCertIssuer;
  OdWString   sCertSerialNum;
  OdWString   sComment;
  OdWString   sTimeServer;

};

/** Description:
    This class defines the interface for the 
    encription/decription of byte data.
    
    Library: TD_Db
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdCrypt : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdCrypt);

  /** Description:
    Initializes this OdCrypt object with the specified security parameters.
    Arguments:
    securityParams (I) Security parameters. 
    Remarks:
    Returns true if and only if successful.
  */
  virtual bool initialize(const OdSecurityParams& securityParams) = 0;
  /** Description:
    Encrypts the specified *buffer*.
    
    Arguments:
    bufferSize (I) Number of bytes.
    buffer (I/O) Data to be encrypted.
    Remarks:
    Returns true if and only if successful.
  */
  virtual bool encryptData(OdUInt8* buffer, OdUInt32 bufferSize) = 0;

  /** Description:
    Decrypts the specified *buffer*.
    
    Arguments:
    bufferSize (I) Number of bytes.
    buffer (I/O) Data to be decrypted.
    Remarks:
    Returns true if and only if successful.
  */
  virtual bool decryptData(OdUInt8* buffer, OdUInt32 bufferSize) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdCrypt object pointers.
*/
typedef OdSmartPtr<OdCrypt> OdCryptPtr;

/** Description:
    This class implements Iterator objects that traverse entries in OdPwdCache objects.

    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdPwdIterator : public OdRxObject
{
public:
  /** Description:
    Returns true if and only if the traversal by this Iterator *object* is complete.
  */  
  virtual bool done() const = 0;
  /** Description:
    Sets this Iterator *object* to reference the entry following the current entry.
  */
  virtual void next() = 0;
  /** Description:
    Returns the Password object pointed to by this Iterator *object*. 

    Arguments:
    password (O) Receives the Password object.
  */
  virtual void get(OdPassword& password) const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdPwdIterator object pointers.
*/
typedef OdSmartPtr<OdPwdIterator> OdPwdIteratorPtr;

/** Description:
  This class implements and manages a Password Cache.
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdPwdCache : public OdRxObject
{
public:
  /** Description:
    Adds the specified Password object to this Cache object.

    Arguments:
    password (I) Password object.
  */
  virtual void add(const OdPassword& password) = 0;
  /** Description:
    Returns an Iterator object that can be 
    used to traverse the OdPassword objects in this Stack object.
  */
  virtual OdPwdIteratorPtr newIterator() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdPwdCache object pointers.
*/
typedef OdSmartPtr<OdPwdCache> OdPwdCachePtr;

#endif  // _ODDBSECURITY_INCLUDED_
