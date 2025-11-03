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



#ifndef _ODDBHYPERLINK_INCLUDED_
#define _ODDBHYPERLINK_INCLUDED_

#include "TD_PackPush.h"
#include "RxObject.h"
#include "DbObject.h"

/** Description:
    This class is the base class for Hyperlink objects.
    
    Library: TD_Db
    
    Remarks:
    OdDbHyperlink objects contain the following data:
    
    @table
    Name               Description 
    Hyperlink Name     A filename or URL.
    Sublocation        A named view, range of cells, etc.
    Description        A display *name* for the Hyperlink.
    
    
    See also:
    o  OdDbEntityHyperlinkPE
    o  OdDbHyperlink
    o  OdDbHyperlinkCollection

    {group:OdDb_Classes}
*/
class OdDbHyperlink
{
public:
  /** Description:
  Flags that can be set on the hyperlink object
  */
  enum HLinkFlags 
  {
    kUndefined = 0,
    kConvertDwgToDwf = 0x1
  };

  OdDbHyperlink() {}

  virtual ~OdDbHyperlink(){}
  

  /** Description:
    Returns the *name* associated with this Hyperlink object.
  */
  virtual const OdChar* name() const = 0;   

  /** Description:
    Sets the *name* associated with this Hyperlink object.
    
    Arguments:
    name (I) Name for this Hyperlink object.
  */
  virtual void setName(const OdChar* name) = 0; 
  
  /** Description:
    Returns the *description* associated with this Hyperlink object.
  */
  virtual const OdChar* description() const = 0;  

  /** Description:
    Sets the *description* associated with this Hyperlink object.
    
    Arguments:
    description (I) Description for this Hyperlink object.

    Remarks:
    "<Name> - <SubLocation>" will be returned by getDisplayString() if description is null.
  */
  virtual void setDescription(const OdChar* description) = 0;
  
  /** Description:
    Returns the sublocation associated with this Hyperlink object.
  */
  virtual const OdChar* subLocation() const = 0;  

  /** Description:
    Sets the sublocation associated with this Hyperlink object.
    
    Arguments:
    subLocation (I) Sublocation for this Hyperlink object.
  */
  virtual void setSubLocation(const OdChar* subLocation) = 0;
  
  /** Description:
    Returns the display string associated with this Hyperlink object.

    Remarks:
    Returns "<Name> - <SubLocation>" will be returned if description() is null.
  */
  virtual const OdChar* getDisplayString() const = 0;  
  
  /** Description:
    Returns true if and only if this Hyperlink object is associated with the outermost container.
  */
  virtual bool isOutermostContainer() const = 0;
  
  /** Description:
    Returns the nesting level of this Hyperlink object.
  */
  virtual const int getNestedLevel() const = 0;

  /** Description:
  Get flags that can be set on the hyperlink object
  */
  virtual const OdInt32 flags() const {return  OdDbHyperlink::kUndefined;}

  /** Description:
  Set flags that can be set on the hyperlink object
  */
  virtual void setFlags(const OdInt32 lFlags) {}

};

/** Description
    This class is a container object for OdDbHyperlink objects.
    
    See also:
    o  OdDbEntityHyperlinkPE
    o  OdDbHyperlink
    o  OdDbHyperlinkCollection

    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class OdDbHyperlinkCollection : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbHyperlinkCollection);

  OdDbHyperlinkCollection() {}

  virtual ~OdDbHyperlinkCollection(){}

  
  /** Description:
    Creates a HyperLink object, and adds it to the start of this HyperlinkCollection object.

    Arguments:
    name (I) Name for the Hyperlink object.
    description (I) Description for the Hyperlink object.
    subLocation (I) Sublocation for the Hyperlink object.
  */
  virtual void addHead(
    const OdChar* name, 
    const OdChar* description, 
    const OdChar* subLocation = NULL) = 0;

  /** Description:
    Creates a HyperLink object, and adds it to the end of this HyperlinkCollection object.

    Arguments:
    name (I) Name for the Hyperlink object.
    description (I) Description for the Hyperlink object.
    subLocation (I) Sublocation for the Hyperlink object.
  */
  virtual void addTail(
    const OdChar* name, 
    const OdChar* description, 
    const OdChar* subLocation = NULL) = 0;

  /** Description:
    Creates a HyperLink object, and inserts it into this HyperlinkCollection object at the specified *index*.

    Arguments:
    Arguments:
    name (I) Name for the Hyperlink object.
    description (I) Description for the Hyperlink object.
    subLocation (I) Sublocation for the Hyperlink object.
    hyperlinkIndex (I) Hyperlink *index*.
    
    Remarks:
    Objects at or after index are moved toward the tail.
  */
  virtual void addAt(
    const int hyperlinkIndex,
    const OdChar* name, 
    const OdChar* description, 
    const OdChar* subLocation = NULL) = 0;

  /** Description:
    Removes the first HyperLink object in this HyperlinkCollection object
  */
  virtual void removeHead() = 0;

  /** Description:
    Removes the last HyperLink object in this HyperlinkCollection object
  */
  virtual void removeTail() = 0;

  /** Description:
    Removes the HyperLink object at the specified location in this HyperlinkCollection object.

    Arguments:
    hyperlinkIndex (I) Hyperlink *index*.
  */
  virtual void removeAt(
    const int hyperlinkIndex) = 0;
  
  /** Description:
    Returns the number of HyperLink objects in this HyperlinkCollection object.
  */
  virtual int count() const = 0;
  
  /** Description:
    Returns the HyperLink object at the specified location in this HyperlinkCollection object.

    Arguments:
    hyperlinkIndex (I) Hyperlink *index*.
  */
  virtual OdDbHyperlink * item(
    const int hyperlinkIndex) const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbHyperlinkCollection object pointers.
*/
typedef OdSmartPtr<OdDbHyperlinkCollection> OdDbHyperlinkCollectionPtr;


/** Description
    This class is the Hyperlink Protocol Extension class.

    Remarks:
    This class provides access to the Hyperlink objects
    associated with OdDbDatabase objects.
    
    See also:
    o  OdDbEntityHyperlinkPE
    o  OdDbHyperlink
    o  OdDbHyperlinkCollection

    Library: TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbEntityHyperlinkPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbEntityHyperlinkPE);
  
  OdDbEntityHyperlinkPE(){}

  virtual ~OdDbEntityHyperlinkPE(){}

  
  /** Description:
    Creates a HyperlinkCollection object containing the Hyperlink objects
    associated with the specified objects.
    
    Arguments:
    pObject (I) Pointer to the object.
    objectIds (I) Array of Object IDs.
    oneOnly (I) If and only if true, returns only the first Hyperlink.  
    ignoreBlockDefinition (I) If and only if true, ignores the Hyperlink objects associated with
                              block definitions.
    Remarks:                              
    Returns the HyperlinkColection object.                          

    Note:
    As implemented, ignoreBlockDefinition is ignored.
    It will be fully implemented in a future *release*.
  */
  virtual OdResult getHyperlinkCollection(
    OdDbObject * pObject, 
	OdDbHyperlinkCollection* &pcHCL,
    bool oneOnly = false, 
    bool ignoreBlockDefinition = true) = 0;
  
  virtual OdResult getHyperlinkCollection(
    const OdArray<OdDbObjectId> *& objectIds,
	OdDbHyperlinkCollection* &pcHCL,
    bool oneOnly = false,                                               
    bool ignoreBlockDefinition = true) = 0;
  
  /** Description:
    Associates the specified HyperlinkCollection object with the specified object.
    
    Arguments:
    pObject (I) Pointer to the target object.
    pHCO (I) Pointer to the HyperlinkCollection object.
    
    Note: Hyperlink objects with null name, description, or sublocation will
    not be added to the object. 
  */
  virtual OdResult setHyperlinkCollection(
    OdDbObject * pObject, 
    OdDbHyperlinkCollection * pHCO) = 0;
  
  /** Description:
    Returns the number of Hyperlink objects associated with the specified objects.

    Arguments:
    pObject (I) Pointer to the object.
    objectIds (I) Array of Object IDs.
    ignoreBlockDefinition (I) If and only if true, ignores the Hyperlink objects associated with
                              block definitions.

    Note:
    As implemented, ignoreBlockDefinition is ignored.
    It will be fully implemented in a future *release*.
  */
  virtual OdResult getHyperlinkCount(
    OdDbObject * pObject, 
	unsigned int & nCount, 
    bool ignoreBlockDefinition = true) = 0;
  
  virtual OdResult getHyperlinkCount(
    const OdArray<OdDbObjectId> *& idContainers, 
	unsigned int & nCount, 
    bool ignoreBlockDefinition = true) = 0;
  
  /** Description:
    Returns true if and only if one or more of the specified objects has 
    Hyperlink objects associated with them.

    Arguments:
    pObject (I) Pointer to the object.
    objectIds (I) Array of Object IDs.
    ignoreBlockDefinition (I) If and only if true, ignores the Hyperlink objects associated with
                              block definition.

    Note:
    As implemented, ignoreBlockDefinition is ignored.
    It will be fully implemented in a future *release*.
  */
  virtual OdResult hasHyperlink(
    OdDbObject * pObject, 
	bool & bHasHyperlink,
    bool ignoreBlockDefinition = true) = 0;
  
  virtual OdResult hasHyperlink(
    const OdArray<OdDbObjectId> *& objectIds, 
	bool & bHasHyperlink,
    bool ignoreBlockDefinition = true) = 0;
  
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEntityHyperlinkPE object pointers.
*/
typedef OdSmartPtr<OdDbEntityHyperlinkPE> OdDbEntityHyperlinkPEPtr;

#include "TD_PackPop.h"
#endif // _ODDBHYPERLINK_INCLUDED_
