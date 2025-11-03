/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef _ODDB_OBJECTCONTEXTCOLLECTION_H_INCLUDED_
#define _ODDB_OBJECTCONTEXTCOLLECTION_H_INCLUDED_

#include "DbObjectContext.h"
#include "TD_PackPush.h"

class OdDbObjectContextCollectionIterator;
typedef OdSmartPtr<OdDbObjectContextCollectionIterator> OdDbObjectContextCollectionIteratorPtr;

/** Description:
    This class represents a collection of objects that have context items defined.

    Remarks:
    Implement this interface and register it with OdDbObjectContextContextManager
	for each database that supports context items. A context collection can be made
	current, locked, or unlocked.
        
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT ODRX_ABSTRACT OdDbObjectContextCollection : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbObjectContextCollection);

   /** Description:
    Returns the name of the context collection.
  
	Remarks:
	The context collection name is used by the context manager to identify the 
	collection and the context items that it contains.
   */  
  virtual OdString name() const = 0;

   /** Description:
    Returns a pointer to the current context of the context collection.
  
    Arguments:
	pRequestingObject (I) Optional pointer to the object for which you want
	the current context.
 
	Remarks:
	If no current context exists, Null is returned.
  */
  virtual OdDbObjectContext* currentContext(
    const OdDbObject* pRequestingObject) const = 0;

  // Gcad(Add)
  OdDbObjectContextPtr currentContext(ODSYSDEF,
    const OdDbObject* pRequestingObject) const;

  /** Description:
    Sets the current context of the context collection.
  
    Arguments:
	pContext (I) Pointer to the context for which a uniqueIdentifier is defined
	to make current for the context collection.
   */ 
  virtual OdResult setCurrentContext(
    const OdDbObjectContext* pContext) = 0;

   /** Description:
    Copies a context and adds the copy to the context collection.
  
    Arguments:
	pContext (I) Pointer to the context for which a uniqueIdentifier is defined
	to copy and add to the context collection.
 
	Remarks:
	The new context is assigned a new uniqueIdentifier.
	Returns eOk if successful, or an appropriate error code if not.
   */
  virtual OdResult addContext(
    const OdDbObjectContext* pContext) = 0;

   /** Description:
    Removes a context from the context collection.
  
    Arguments:
	contextName (I) Name of the context to delete from the context
	collection.
 
	Remarks:
	To remove the current context from a collection, first make a different
	context current, then delete the desired context.
	Returns eOk if successful, or an appropriate error code if not.
   */
  virtual OdResult removeContext(
    const OdString& contextName) = 0;

   /** Description:
    Internal use only.
   */  
  virtual OdResult lockContext(
    const OdDbObjectContext* pContext) = 0;
 
   /** Description:
    Internal use only.
   */  
  virtual OdResult unlockContext() = 0;

   /** Description:
    Internal use only.
   */  
  virtual bool locked() const = 0;

   /** Description:
    Returns a pointer to a copy of a named context in the collection.
  
    Arguments:
	contextName (I) Name of the context.
 
	Remarks:
	If no context exists with the specified name, Null is returned.
  */
  virtual OdDbObjectContext* getContext(
    const OdString& contextName) const = 0;

  // Gcad(Add)
  virtual OdDbObjectContextPtr getContext(ODSYSDEF,
    const OdString& contextName) const;

  /** Description:
    Returns whether a named context exists in the collection.
  
    Arguments:
	contextName (I) Name of the context.
 
	Remarks:
	Returns True if the named context exists in the collection, 
	or returns Null if itbdoes not exist.
   */
  virtual bool hasContext(
    const OdString& contextName) const = 0;

   /** Description:
    Returns an Iterator to the contexts in the collection.
  */
  virtual OdDbObjectContextCollectionIterator* newIterator() const = 0;

  // Gcad(Add)
  OdDbObjectContextCollectionIteratorPtr newIterator(ODSYSDEF) const;
};


////////////////////////////////////////////////////////////////////////
// class OdDbObjectContextCollectionIterator
////////////////////////////////////////////////////////////////////////

/** Description:
    This class implements Iterators for objects that have context items defined and
	stored in a context collection (using the OdDbObjectContextCollections class).

    Remarks:
    If an application supports context collections, you must implement this class. You
	can get an Iterator using OdDbObjectContextCollection::newIterator().
        
    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT ODRX_ABSTRACT OdDbObjectContextCollectionIterator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbObjectContextCollectionIterator);

   /** Description:
    Moves the Iterator to the start of the collection.
 
	Remarks:
	Returns eOk if successful, or an appropriate error code if not.
   */
  virtual OdResult start() = 0;

   /** Description:
    Moves the Iterator to the next context of the collection.
 
	Remarks:
	Returns True if successful, or returns False if the Iterator is
	at the end of the collection.
   */
  virtual bool next() = 0;

   /** Description:
    Returns whether the Iterator is at the end of the collection.
 
	Remarks:
	Returns True if the Iterator is at the end of the collection, or
	returns False if it is not.
   */
  virtual bool done() const = 0;

   /** Description:
    Returns a copy of the context located at the current position of the
	Iterator.
   */
  virtual OdResult getContext(OdDbObjectContext*& pObjectContext) const = 0;
  // Gcad(Add)
  virtual OdDbObjectContextPtr getContext() const;
};

#include "TD_PackPop.h"

#endif // _ODDB_OBJECTCONTEXTCOLLECTION_H_INCLUDED_
