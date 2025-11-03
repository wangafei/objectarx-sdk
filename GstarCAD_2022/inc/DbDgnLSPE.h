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

#ifndef _OD_DB_DGNLS_PE_
#define _OD_DB_DGNLS_PE_

#include "DbLinetypeTableRecord.h"

struct OdGiDgLinetypeModifiers;
class OdGiSubEntityTraits;

/** Description:
    This class defines the interface for the Linetype Table Record Protocol Extension classes.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDgnLSPE : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdDbDgnLSPE);

    enum DgnLSSetupFlags
    {
      kDgnLSProcessed = 1
    };

    /**
      Description:
      Checks does Linetype Table Record contain attached DgnLS data.

      Arguments:
      pLTR (I) Pointer to the Linetype Table Record.
      Remarks:
      Returns true if Linetype Table Record have attached DgnLS data.
    */
    virtual bool hasDgnLSData(const OdDbLinetypeTableRecord *pLTR) const = 0;

    /**
      Description:
      Setup traits by DgnLS data.

      Arguments:
      pLTR (I) Pointer to the Linetype Table Record.
      nResFlags (O) setAttributes return flags.
      pTraits (I) Traits pointer which will be filled by DgnLS data.
      Remarks:
      Returns kDgnLSProcessed if DgnLS data completely processed. Returns 0 if standard processing is required.
    */
    virtual OdUInt32 setupDgnLSData(const OdDbLinetypeTableRecord *pLTR, OdUInt32 &nResFlags, OdGiDrawableTraits *pTraits) const = 0;

    /**
      Description:
      Prepare cache for DgnLS data.

      Arguments:
      pLTR (I) Pointer to the Linetype Table Record.
      pCache (O) Pointer to cache object which will be filled by DgnLS data.
      Remarks:
      Returns kDgnLSProcessed if DgnLS data completely processed. Returns 0 if standard processing is required.
    */
    virtual OdUInt32 prepareDgnLSCache(const OdDbLinetypeTableRecord *pLTR, OdRxObjectPtr &pCache) const = 0;

    /**
      Description:
      Setup traits from DgnLS cache.

      Arguments:
      pCache (I) Pointer to the DgnLS cache.
      nResFlags (O) setAttributes return flags.
      pTraits (I) Traits pointer which will be filled by DgnLS data.
      Remarks:
      Returns kDgnLSProcessed if DgnLS data completely processed. Returns 0 if standard processing is required.
    */
    virtual OdUInt32 setupDgnLSCache(const OdRxObject *pCache, OdUInt32 &nResFlags, OdGiDrawableTraits *pTraits) const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDgnLSPE object pointers.
*/
typedef OdSmartPtr<OdDbDgnLSPE> OdDbDgnLSPEPtr;

/** Description:
    This class defines the interface for the Entity Protocol Extension classes.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDgnLSModifiersPE : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdDbDgnLSModifiersPE);

    /**
      Description:
      Checks does Entity contain attached DgnLSModifiers data.

      Arguments:
      pEntity (I) Pointer to the Entity.
      Remarks:
      Returns true if Entity have attached DgnLSModifiers data.
    */
    virtual bool hasDgnLSModifiersXData(const OdDbEntity *pEntity) const = 0;

    /**
      Description:
      Read DgnLSModifiers data from the Entity.

      Arguments:
      pEntity (I) Pointer to the Entity.
      pModifiers (O) DgnLSModifiers read results.
      pScale (O) Optionally return linetype scale.
      Remarks:
      Returns true if DgnLSModifiers data reading process successfully completed.
    */
    virtual bool readDgnLSModifiersXData(const OdDbEntity *pEntity, OdGiDgLinetypeModifiers &pModifiers, double *pScale = NULL) const = 0;

    /**
      Description:
      Read and draw DgnLSModifiers data for the Entity.

      Arguments:
      pEntity (I) Pointer to the Entity.
      pTraits (O) Traits where to place DgnLSModifiers read results.
      Remarks:
      Returns true if DgnLSModifiers data reading process successfully completed.
    */
    virtual bool readDgnLSModifiersXData(const OdDbEntity *pEntity, OdGiSubEntityTraits *pTraits) const = 0;

    /**
      Description:
      Write DgnLSModifiers data into the Entity.

      Arguments:
      pEntity (I) Pointer to the Entity.
      pModifiers (I) DgnLSModifiers for write.
      pScale (I) Optional linetype scale.
      Remarks:
      Returns true if DgnLSModifiers data writing process successfully completed.
    */
    virtual bool writeDgnLSModifiersXData(OdDbEntity *pEntity, const OdGiDgLinetypeModifiers &pModifiers, const double *pScale = NULL) const = 0;

    /**
      Description:
      Remove DgnLSModifiers data from the Entity.

      Arguments:
      pEntity (I) Pointer to the Entity.
      Remarks:
      Returns true if DgnLSModifiers data removed from the Entity.
    */
    virtual bool removeDgnLSModifiersXData(OdDbEntity *pEntity) const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDgnLSModifiersPE object pointers.
*/
typedef OdSmartPtr<OdDbDgnLSModifiersPE> OdDbDgnLSModifiersPEPtr;

#endif //_OD_DB_DGNLS_PE_
