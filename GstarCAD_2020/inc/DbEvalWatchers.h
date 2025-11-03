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


#ifndef _ODDB_EVALWATCHERS_H_
#define _ODDB_EVALWATCHERS_H_

#include "RxObject.h"
#include "RxModule.h"
#include "DbEntity.h"
#include "DbHatch.h"

/** Description:
    This class is the base Protocol Extension class for classes used for catching 
    evaluation requests from associated objects.

    Library:
    TD_Db

    Remarks:
    This class can be used for OdDbHatch, OdDbDimAssoc, OdDbLeader and OdDbDimension classes.

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbEvalWatcherPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbEvalWatcherPE);

  /** Description:
    Notification function called whenever an object receives a *modified* notification 
    from an associated object.

    Arguments:
    pObj (I) Pointer to the object that received the notification.
    pAssocObj (I) Pointer to the associated object.
    
    Remarks:
    This function is called whenever the associated object is being closed after being *modified*.

    The default implementation of this function does nothing.
    This function can be overridden in custom classes.
  */
  virtual void modified(OdDbObject* pObj, const OdDbObject* pAssocObj) = 0;
  virtual void openedForModify(OdDbObject* pObj, const OdDbObject* pAssocObj);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEvalWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbEvalWatcherPE> OdDbEvalWatcherPEPtr;


/** Description:
    This class is the Protocol Extension class for updating OdDbHatch objects.

    Library:
    TD_Db

    Remarks:
    This protocol extension is added to the OdDbHatch class by Teigha while initializing.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbHatchWatcherPE : public OdDbEvalWatcherPE
{
public:
  virtual void modified(OdDbObject* pObj, const OdDbObject* pAssocObj);

  /** Description
    Notification function called whenever an OdDbHatch object is *modified*.

    Arguments:
    pHatch (I) Pointer to the hatch object.
    
    Remarks:
    This function is called whenever the hatch object is being closed after being *modified*.

    Remarks:
    This protocol extension is added to the OdDbHatch class by Teigha during initialization.

    The default implementation of this function does nothing.
    This function can be overridden in custom classes.
  */
  virtual void modifiedItself(OdDbHatch* pHatch);

  /** Description:
    Updates the boundary of an OdDbHatch object.
    
    Arguments:
      pHatch (I) Pointer to the hatch object.
      assocObjIds (I) Array of *modified* associated OdDbEntity object IDs.
  */
  virtual void evaluate(OdDbHatch* pHatch, const OdDbObjectIdArray& assocObjIds);

  /** Description:
    Returns a loop from the specified OdDbEntity object IDs for the specified OdDbHatch entity.

    Arguments:
    pHatch (I) The OdDbHatch object.
    loopType (I/O) Type of loop being updated.
    objectIds (I) Array of OdDbEntity object IDs that comprise the loop.
    edges (I/O) Array of *edges* that comprise the loop.
  */
  virtual void getLoopFromIds(const OdDbHatch* pHatch, 
    OdUInt32& loopType, 
    OdDbObjectIdArray& objectIds, 
    EdgeArray& edges);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbHatchWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbHatchWatcherPE> OdDbHatchWatcherPEPtr;


/** Description:
    This class is the Protocol Extension class for updating OdDbLeader objects.

    Library:
    TD_Db

    Remarks:
    This protocol extension is added to the OdDbLeader class by Teigha while initializing.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbLeaderWatcherPE : public OdDbEvalWatcherPE
{
public:
  virtual void modified(OdDbObject* pObj, const OdDbObject* pAssocObj);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLeaderWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbLeaderWatcherPE> OdDbLeaderWatcherPEPtr;


/** Description:
    This class is the Protocol Extension class for updating OdDbDimension objects when their
    associated OdDbDimStyleTableRecord objects are *modified*.

    Library:
    TD_Db

    Remarks:
    This protocol extension is added to the OdDbDimension class by Teigha while initializing.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbDimensionWatcherPE : public OdDbEvalWatcherPE
{
public:
  virtual void modified(OdDbObject* pObj, const OdDbObject* pDimStyle);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimensionWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbDimensionWatcherPE> OdDbDimensionWatcherPEPtr;

/** Description:
    This class is the Protocol Extension class for updating OdDbFcf objects when their
    associated OdDbDimStyleTableRecord objects are *modified*.

    Library:
    TD_Db

    Remarks:
    This protocol extension is added to the OdDbFcf class by Teigha while initializing.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbFcfWatcherPE : public OdDbEvalWatcherPE
{
public:
  virtual void modified(OdDbObject* pObj, const OdDbObject* pDimStyle);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbFcfWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbFcfWatcherPE> OdDbDFcfWatcherPEPtr;

/** Description:
    This class is the base Protocol Extension class for updating OdDbDimAssoc objects when their
    associated objects are *copied* or *erased*.

    Library:
    TD_Db

    Remarks:
    This class can be used for OdDbDimAssoc class.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbDimAssocWatcherPE : public OdDbEvalWatcherPE
{
public:
    virtual void copied(OdDbObject *pObj, const OdDbObject *pAssocObj, const OdDbObject *pNewObj) = 0;
    virtual void erased(OdDbObject *pObj, const OdDbObject *pAssocObj, bool erasing = true) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimAssocWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbDimAssocWatcherPE> OdDbDimAssocWatcherPEPtr;

/** Description:
    This class is the Protocol Extension class for updating OdDbTable objects when their
    associated OdDbTableStyle objects are *modified*.

    Library:
    TD_Db

    Remarks:
    This protocol extension is added to the OdDbTable class by Teigha while initializing.
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbTableWatcherPE : public OdDbEvalWatcherPE
{
public:
  virtual void modified(OdDbObject* pObj, const OdDbObject* pDimStyle);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbTableWatcherPE object pointers.
*/
typedef OdSmartPtr<OdDbTableWatcherPE> OdDbTableWatcherPEPtr;

#endif // _ODDB_EVALWATCHERS_H_
