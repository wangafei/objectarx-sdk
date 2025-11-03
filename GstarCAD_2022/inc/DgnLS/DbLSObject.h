/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2014, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2014 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef ODDGNLS_DBLSOBJECT_H
#define ODDGNLS_DBLSOBJECT_H

#include "DbObject.h"

#include "OdDgnLSExport.h"

#include "TD_PackPush.h"

/* DgnLS classes hierarchy:
   - OdDbLSObject
   ---- OdDbLSDefinition
   ---- OdDbLSComponent
   -------- OdDbLSCompoundComponent
   -------- OdDbLSPointComponent
   -------- OdDbLSStrokePatternComponent
   ------------ OdDbLSInternalComponent
   -------- OdDbLSSymbolComponent
*/

/** Description:
    Basic object for all DgnLS objects.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSObject : public OdDbObject
{
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSObject);

    /** Note:
      Teigha applications typically will not use this constructor, insofar as 
      this class is a base class.
    */
    OdDbLSObject();

    virtual OdResult dwgInFields(OdDbDwgFiler *pFiler);
    virtual OdResult dwgOutFields(OdDbDwgFiler *pFiler) const;
    virtual OdResult dxfInFields(OdDbDxfFiler *pFiler);
    virtual OdResult dxfOutFields(OdDbDxfFiler *pFiler) const;

#ifdef ODA_DIAGNOSTICS
    /**
      Description:
      Debug data output for entire objects hierarchy.
    */
    void trace() const;
#endif

    /**
      Description:
      Returns component unique identifier.

      Remarks:
      16 bytes of data.
    */
    virtual const OdUInt8 *componentUID() const = 0;

    /**
      Description:
      Sets component unique identifier.

      Arguments:
      pUID (I) Input unique identifier represented as 16 bytes of data.
    */
    void setComponentUID(const OdUInt8 *pUID);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSObject object pointers.
*/
typedef OdSmartPtr<OdDbLSObject> OdDbLSObjectPtr;

// Inlines section

inline void OdDbLSObject::setComponentUID(const OdUInt8 *pUID)
{
  assertWriteEnabled();
  OdUInt8 *pUIDOut = const_cast<OdUInt8*>(componentUID());
  for (int i = 0; i < 16; i++)
    pUIDOut[i] = pUID[i];
}

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSOBJECT_H
