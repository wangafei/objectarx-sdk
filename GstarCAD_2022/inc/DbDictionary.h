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




#ifndef _ODDBDICTIONARY_INCLUDED_
#define _ODDBDICTIONARY_INCLUDED_

#include "TD_PackPush.h"

#include "RxIterator.h"
#include "RxDefs.h"
#include "DbObject.h"

class OdDbDictionaryImpl;
class OdDbObjectId;
class OdString;

/** Description:
    This class implements Iterator objects that traverse entries in OdDbDictionary objects in an OdDbDatabase instance.
    
    Library: TD_Db
    
    Remarks:
    An OdDbDictionaryIterator maintains a "current position" within the entries
    of the associated dictionary, and can provide access to the key value and *object* at the
    current position.

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDictionaryIterator : public OdRxIterator
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDictionaryIterator);

  virtual ~OdDbDictionaryIterator() {}

  /** Description:
      Returns the *name* (key) of the dictionary entry currently referenced
      by this Iterator *object*.
  */
  virtual const OdChar* name() const = 0; // Gcad(Modify)

  /** Description:
      Opens the dictionary entry currently referenced by this Iterator *object*.    

      Arguments:
      mode (I) Mode in which to open the *object*.

      Remarks:
      Returns a SmartPointer to the opened *object*.
  */
  OdDbObjectPtr getObject( // Gcad(Modify)
    OdDb::OpenMode openMode = OdDb::kForRead);

  virtual OdResult getObject(// Gcad(Add)
    OdDbObject*& pObject,
    OdDb::OpenMode openMode = OdDb::kForRead) = 0;

  /** Description:
      Returns the Object ID of the dictionary entry currently referenced by
      this Iterator *object*.
  */
  virtual OdDbObjectId objectId() const = 0;

  /** Description:
      Sets the current position of this Iterator to the dictionary entry containing the
      specified ObjectId.

      Arguments:
      objectId (I) Object ID of item to which the current position will be set.

      Remarks:
      Returns true if and only if the current position was set to the specified item.
  */
  virtual bool setPosition(
    OdDbObjectId objectId) = 0;

  /** Description:
      Opens the dictionary entry currently referenced by this Iterator object in OdDb::kForRead mode.

      Remarks:
      Returns a SmartPointer to the opened *object*.
  */
  /*/DD2ARX - xi hui - 2008-06-20 - AcRxIterator::object
  virtual OdRxObjectPtr object() const;
  /*/
  virtual OdRxObject* object() const;
  //*/

protected:
  
  OdDbDictionaryIterator() {}
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDictionaryIterator object pointers..
*/
typedef OdSmartPtr<OdDbDictionaryIterator> OdDbDictionaryIteratorPtr;

/** Description:
    This class implements *database* -resident object dictionaries.
    
    Remarks:
    
    o  Each instance of OdDbDictionary is a single container object, in which
       entries are searched, added, *modified*, and deleted.  
  
    o  Each OdDbDictionary entry associates a unique *name* (key) string with a unique OdDbObject.
    
    o  Anonymous names are signified by specifying a name starting with an asterisk; e.g., *U. 
       A unique *name* (also starting with an asterisk) will be constructed for the entry.

    o  Entry names honor the rules of Symbol names
    
        o  Names may be any length.
        
        o  Names are case-insensitve
        
        o  Names may not contain any of the following characters
    
                      | * \ : ; < > ? " , equals

    See Also:
    OdDbDictionaryIterator
    
    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDictionary : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDictionary);

  OdDbDictionary();

  /** Description:
    Returns the OdDbObject associated with the specified *name* (key) in this Dictionary object.

    Arguments:
    name (I) Entry *name*.
    mode (I) Mode in which to open the object.
    pStatus (O) Receives eOk if successful, or an appropriate error code if not.

    Remarks:
    Opens the associated OdDbObject in the specified mode.
    
    Returns a null SmartPointer or Object ID if the specified entry could not be opened.
  */
  OdDbObjectPtr getAt(
    const OdString& name, 
    OdDb::OpenMode mode) const;

  OdResult getAt(
    const OdChar * name,
    OdDbObject*& pObject,
    OdDb::OpenMode mode) const;

  OdDbObjectId getAt(
    const OdString& name, 
    OdResult* pStatus = 0) const;

  OdResult getAt(
    const OdChar* name, 
    OdDbObjectId& objectId) const;

  
  /** Description:
    Returns the entry *name* (key) of the specified object in this Dictionary object.

    Arguments:
    objectId (I) Object ID.
    
    Remarks:
    Returns an empty string if objectId is not in this Dictionary object.
  */
  OdString nameAt(
    const OdDbObjectId& objectId) const;

  OdResult nameAt( // Gcad(Add)
    OdDbObjectId objectId,
    OdChar*& name) const;

  OdResult nameAt( // Gcad(Add)
    OdDbObjectId objectId,
    OdString& name) const;

  /** Description:
    Returns true if and only if this Dictionary object *has* an entry with the specified *name* (key) or Object ID.

    Arguments:
    name (I) Entry *name*.
    objectId (I) Object ID.
  */
  bool has(ODSYSDEF, const OdString& name) const { return has(name);}
  bool has(const OdChar * name) const;
  bool has(OdDbObjectId objectId) const;

  /** Description:
    Returns the number of entries in this Dictionary object.
  */
  OdUInt32 numEntries() const;

  /** Description:
    Removes the entry with the specified *name* (key) or Object ID from this Dictionary object, and returns
    the Object ID of the removed entry.

    Arguments:
    name (I) Entry *name*.
    objectId (I) Object ID.
    
    Note:
    Only the dictionary entry is removed; the associated object remains in the *database* without an owner.

    The dictionary is removed as a persistent reactor on the associated object. 
  */
  OdDbObjectId remove( // Gcad(Internal)
    ODSYSDEF,
    const OdString& name);

  OdResult remove( // Gcad(Modify)
    OdDbObjectId objectId);
  
  OdResult remove(const OdChar* name);
  
  OdResult remove(const OdChar* name,OdDbObjectId& objectId);
  
  /** Description:
    Changes the *name* (key) of the specified entry in this Dictionary object.

    Arguments:
    oldName (I) Name of entry to change.
    newName (I) New *name* for the entry.

    Remarks:
    Returns true and only if the entry *name* was successfully changed.
  */
  bool setName(const OdChar* oldName,const OdChar* newName);

  
  /** Description:
    Sets the value for the specified entry in this Dictionary object.

    Remarks:
    Returns the Object ID of the newly added entry.
    
    If an entry the specified *name* exists in the dictionary, it is
    erased, and a new entry created.

    If an entry for this *name* does not exist in this dictionary, 
    a new entry is created. 

    Arguments:
    name (I) Name of entry to be changed.
    newValue (I) Database object to be added.
  */
  OdDbObjectId setAt(
    const OdString& name, 
    OdDbObject* newValue);

  OdResult setAt(
    const OdChar * name,
    OdDbObject* newValue,
    OdDbObjectId& retObjId);

  /** Description:
    Returns true if and only if this Dictionary object is the hard owner of its elements.
     
    Remarks:
    Hard ownership protects the elements from purge. Soft ownership does not. 
  */
  bool isTreatElementsAsHard() const;

  /** Description:
    Sets the hard ownership property for this Dictionary object.

    Arguments:
    hard (I) Controls ownership.

    Remarks:
    Hard ownership protects the elements from purge. Soft ownership does not. 
  */
  void setTreatElementsAsHard(
    bool doIt);

  /** Description:
    Returns a new interator that can be used to traverse the entries in this Dictionary object.

    Arguments:
    iterType (I) Type of Iterator.

    Remarks:
    The Iterator type can be one of the following:

    @table
    Name                      Description
    OdRx::kDictCollated       Traverses the entries in the order they were added to the dictionary.
    OdRx::kDictSorted         Traverses the entries in alphabetical order by key value.
  */
  OdDbDictionaryIteratorPtr newIterator( // Gcad(Internal)
    ODSYSDEF,
    OdRx::DictIterType iterType = OdRx::kDictCollated) const;

#ifdef ODARXDEF

  OdDbDictionaryIterator* newIterator(OdRx::DictIterType iterType/* = OdRx::kDictSorted*/) const;
  
  OdDbDictionaryIterator* newIterator() const;
#endif

  virtual OdResult subErase(OdBool pErasing = kTrue);

  enum 
  { 
    kMaxSuggestNameSize = 2049 
  };
  /** \details
    Returns a string suitable to be used as dictionary Key for this dictionary object.
    The string is unique for this dictionary object and is as close to file name as possible.

    \param strFilePath [in]  File path.
    \param nMaxLength [in]  Maximum length of name generated.
  */
  OdString suggestName(const OdString& strFilePath, const int nMaxLength = kMaxSuggestNameSize) const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  /** Description:
      Returns the merge *style* for this dictionary object.
  */
  virtual OdDb::DuplicateRecordCloning mergeStyle() const;

  /** Description:
      Sets the merge *style* for this dictionary object.
      
      Arguments:
      mergeStyle (I) Merge *style*.
  */
  virtual void setMergeStyle(
    OdDb::DuplicateRecordCloning mergeStyle);

  virtual void goodbye(
    const OdDbObject* pObject);

  virtual void erased(
    const OdDbObject* pObject, 
    OdBool erasing = kTrue);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult applyPartialUndo(
    OdDbDwgFiler* pFiler,
    OdRxClass* pClass);

  virtual OdResult subClose();

  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDictionary object pointers.
*/
typedef OdSmartPtr<OdDbDictionary> OdDbDictionaryPtr;

#include "TD_PackPop.h"

#endif

