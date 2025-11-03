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




#ifndef _RXDICTIONARY_INC_
#define _RXDICTIONARY_INC_


#include "RxObject.h"
#include "RxIterator.h"
#include "RxDefs.h"
#include "RxNames.h"

class OdString;

#include "TD_PackPush.h"

/** Description:
    This class implements Iterator objects that traverse entries in OdRxDictionary objects in an OdDbDatabase instance.
    
    Library: TD_Db
    
    Remarks:
    An OdRxDictionaryIterator maintains a "current position" within the entries
    of the associated dictionary, and can provide access to the key value and *object* at the
    current position.

    {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxDictionaryIterator : public OdRxIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdRxDictionaryIterator);

  /** Description:
      Returns the key of the dictionary entry currently referenced
      by this Iterator *object*.
  */
  OdString getKey() const
  {
	  return key();
  }
  virtual const OdChar* key() const = 0;
  virtual OdRxObject*  object() const
  {
    throw OdError(OdResult::eNotImplemented);
    return NULL;
  }

  /** Description:
      Returns the entry ID of the dictionary entry currently referenced
      by this Iterator object.
  */
  virtual OdUInt32 id() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxDictionaryIterator object pointers.
*/
typedef OdSmartPtr<OdRxDictionaryIterator> OdRxDictionaryIteratorPtr;


/** Description:
    This class implements dictionaries of OdRxObject objects.
    
    Remarks:
    
    o  Each instance of OdRxbDictionary is a single container object, in which
       entries are searched, added, modified, and deleted.  
  
    o  Each OdRxDictionary entry associates a unique *name* (key) string or 32-Bit ID with a unique OdDbObject.
    
    o  Anonymous names are signified by specifying a name starting with an asterisk; e.g., *U. 
       A unique *name* (also starting with an asterisk) will be constructed for the entry.

    o  Entry names honor the rules of Symbol names
    
        o  Names may be any length.
        
        o  Names are case-insensitve
        
        o  Names may not contain any of the following characters
    
                      | * \ : ; < > ? " , equals

    See Also:
    OdRxDictionaryIterator
    
    Library: TD_Db
    
    {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxDictionary : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRxDictionary);
  
  /** Description:
    Allocates storage for the specified number of entries in this Dictionary object.
    Arguments:
    minSize (I) Minimum number of entries. 
  */
  virtual void reserve(
    OdUInt32 minSize);

  /** Description:
    Returns the OdRxObject associated with the specified *name* (key) 
    or entry ID in this Dictionary object.

    Arguments:
    name (I) Entry *name*.
    id (I) Entry ID.

    Remarks:
    Returns a null SmartPointer if the specified entry could found.
  */

  OdRxObjectPtr getAt(const OdChar* key) const;
  OdRxObjectPtr getAt(OdUInt32 id) const;

  virtual OdRxObject *at(const OdChar* key) const = 0;
  virtual OdRxObject *at(OdUInt32 id) const = 0;

  virtual OdBool atKeyAndIdPut(const OdChar* newKey, OdUInt32 id, OdRxObject* pObject) = 0;

  /** Description:
    Puts the specified object pointer into this Dictionary object.
    
    Arguments:
    key (I) Entry *name*.
    id (I) Entry ID.
    pObject (I) Pointer to the object.
    pRetId (I) Pointer to an OdUInt32 to receive the Entry ID of the entry.
    
    Remarks:
    Returns a SmartPointer to the object at this entry prior to the call.
    
    Note:
    key and pObject must not be NULL, and id > 0.
  */
  OdRxObjectPtr putAt(
    const OdString& key, 
    OdRxObject* pObject, 
    OdUInt32* pRetId = 0)
  {
	  OdRxObject *pObj;
	  if (pRetId !=0)
	  {
		  pObj= atPut(key , pObject , *pRetId);
	  }
	  else
	  {
		  pObj= atPut(key , pObject);
	  }

	  OdRxObjectPtr pRes;
	  if (pObj != NULL)
	  {
		  pRes.attach(pObj);
	  }
	  return pRes;
  }

  OdRxObjectPtr putAt(
    OdUInt32 id, 
    OdRxObject* pObject)
  {
	  OdRxObject *pObj = atPut(id , pObject);
	  OdRxObjectPtr pRes;
	  if (pObj != NULL)
	  {
		  pRes.attach(pObj);
	  }
	  return pRes;
  }

  virtual OdRxObject* atPut(
    const OdChar * key, 
    OdRxObject* pObject) = 0;
  virtual OdRxObject* atPut(
    const OdChar* key, 
    OdRxObject* pObject, 
    OdUInt32& RetId) = 0;
  virtual OdRxObject* atPut(
    OdUInt32 id, 
    OdRxObject* pObject) = 0;
  
  /** Description:
    Sets the *key* associated with the specified entry ID for this Dictionary object.
    
    Arguments:
    id (I) Entry ID.
    newKey (I) New *key*.
    
    Remarks:
    Returns true if and only if successful.    
  */
  
  //没有地方调用,直接修改
  virtual OdBool resetKey(
	  OdUInt32 id,
	  const OdChar* newKey) = 0;
  virtual OdBool resetKey(
	  const OdChar* oldKey,
	  const OdChar* newKey) = 0;

  /** Description:
    Removes the specified entry from this Dictionary object.
    
    Arguments:
    key (I) Entry *name*.
    id (I) Entry ID.
    
    Remarks:
    Returns a SmartPointer to the object referenced by the entry.
  */

  //原函数改为非虚,添加与ARX兼容的函数
  OdRxObjectPtr remove(ODSYSDEF, const OdString& key);
  OdRxObjectPtr remove(ODSYSDEF, OdUInt32 id);

  virtual OdRxObject *remove(OdUInt32 id) = 0;
  virtual OdRxObject *remove(const OdChar* key) = 0;


  /** Description:
    Returns true if and only if this Dictionary object *has* an entry with the specified *name* (key) or entry ID.

    Arguments:
    name (I) Entry *name*.
    id (I) Entry ID.
  */
  bool has(ODSYSDEF, const OdString& name) const
  {
	  return has(name);
  }
  virtual OdBool has(const OdChar* name) const = 0;
  virtual OdBool has(
    OdUInt32 id) const = 0;


  /** Description:
    Returns the entry ID of the specified object in this Dictionary object.

    Arguments:
    key (I) Entry *name*.
    
    Remarks:
    Returns an empty string if id is not in this Dictionary object.
  */
  OdUInt32 idAt(ODSYSDEF, const OdString& key) const
  {
	  return idAt(key);
  }
  virtual OdUInt32 idAt(const OdChar* key) const = 0;

  /** Description:
    Returns the entry *name* (key) of the specified object in this Dictionary object.

    Arguments:
    id (I) Entry ID.
    
    Remarks:
    Returns an empty string if id is not in this Dictionary object.
  */
   virtual OdString keyAt(
    OdUInt32 id) const = 0;

  /** Description:
    Returns the number of entries in this Dictionary object.
  */
  virtual OdUInt32 numEntries() const = 0;
  virtual OdBool deletesObjects() const
  {
    throw OdError(OdResult::eNotImplemented);
    return kFalse;
  }

  /** Description:
    Returns a new interator that can be used to traverse the entries in this Dictionary object.

    Arguments:
    iterType (I) Type of iterator.

    Remarks:
    The iterator type can be one of the following:

    @table
    Name                      Description
    OdRx::kDictCollated       Traverses the entries in the order they were added to the dictionary.
    OdRx::kDictSorted         Traverses the entries in alphabetical order by key value.
  */
  OdRxDictionaryIteratorPtr newIterator(ODSYSDEF, OdRx::DictIterType iterType = OdRx::kDictCollated)
  {
    OdRxDictionaryIteratorPtr pRes;
#ifdef ODARXDEF
	  OdRxDictionaryIterator *pObj = newIterator(iterType);	  
	  if (pObj != NULL)
	  {
		  pRes.attach(pObj);
	  }
#endif
	  return pRes;
  }
#ifdef ODARXDEF
  virtual OdRxDictionaryIterator* newIterator(OdRx::DictIterType iterType = OdRx::kDictCollated) = 0;
#endif
  /** Description: 
    Returns true if and only if keys for this Dictionary object are case-sensitive.
    
  */
  virtual OdBool isCaseSensitive() const = 0;
  virtual OdBool isSorted() const
  {
    throw OdError(OdResult::eNotImplemented);
    return kFalse;
  }
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdRxDictionary object pointers.
*/
typedef OdSmartPtr<OdRxDictionary> OdRxDictionaryPtr;

FIRSTDLL_EXPORT OdRxDictionary* odrxSysRegistry();

FIRSTDLL_EXPORT OdRxDictionaryPtr odrxClassDictionary();

FIRSTDLL_EXPORT OdRxDictionaryPtr odrxServiceDictionary();

FIRSTDLL_EXPORT OdRxDictionaryPtr odrxCreateRxDictionary();

FIRSTDLL_EXPORT OdRxDictionaryPtr odrxCreateSyncRxDictionary();


#include "TD_PackPop.h"

#endif // _RXDICTIONARY_INC_

