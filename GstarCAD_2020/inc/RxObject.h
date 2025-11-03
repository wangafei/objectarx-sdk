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




#ifndef _ODRXOBJECT_INCLUDED_
#define _ODRXOBJECT_INCLUDED_ /** { Secret } *// 

#include "TD_PackPush.h"
#include "RootExport.h"
#include "OdHeap.h"
#include "OdArrayPreDef.h"
#include "OdString.h"

class OdRxClass;
class OdRxObject;
class OdRxModule;

/** Description:
    Suppresses the incrementing of the reference counter.
    
    Remarks:
    The option is used for creating of smart pointers that refer to the classes derived from OdRxObject.
    The option can be specified as an argument for the constructor of the OdSmartPtr class or OdRxObjectPtr class.

    See Also:
    {hyperlink:Implementing Smart Pointers|smart_pointers_definition.html} 
*/
enum OdRxObjMod { kOdRxObjAttach };


/** Description:
    Declares the RunTime Type Identification functions required by OdRxObject objects.
    
    Remarks:
    Any class derived from OdRxObject should include this macro in its class declarations,
    passing its own name.
*/
#define ODRX_DECLARE_MEMBERS(ClassName)\
public:                                                                                              \
                                                                                                     \
  /** Description: Casts the specified pointer to an ClassName SmartPointer. **/                      \
  static OdSmartPtr<ClassName> cast(ODSYSDEF , const OdRxObject* pObj)                                          \
  {                                                                                                  \
    if (pObj)                                                                                        \
      return OdSmartPtr<ClassName>(((ClassName*)pObj->queryX(ClassName::desc())), kOdRxObjAttach);   \
    return (ClassName*)0;                                                                            \
  }                                                                                                  \
  static ClassName * cast (const OdRxObject* pObj)\
  {\
  OD_TRY_N()\
    OdSmartPtr<ClassName> objPtr = ODSYSCALL1(cast , pObj);\
    return objPtr.get();\
  OD_CATCH_N()\
	return NULL;\
  }\
                                                                                                     \
  static OdRxClass* g_pDesc;                                                                         \
                                                                                                     \
  /** Description: Returns the static OdRxClass description object associated with this object. **/  \
  /** Note: This function is for use only when the class type of this object is known.          **/  \
  /** If the class type of this object is unknown, use instead isA().                           **/  \
  static OdRxClass* desc();                                                                   \
                                                                                                     \
  /** Description: Returns the OdRxClass description instance associated with this object.      **/  \
  /** Note: This function is for use only when the class type of this object is unknown.        **/  \
  /** If the class type of this object is known, use instead desc().                            **/  \
  virtual OdRxClass* isA() const;                                                                    \
                                                                                                     \
  /** Description: Returns the Protocol Extension object for this object.        **/                 \
  /** Remarks: Return null if there is no Protocol Extension object is found.    **/                 \
  virtual OdRxObject* queryX(const OdRxClass* protocolClass) const;                                  \
                                                                                                     \
  /** Description: Creates a new instance of this object type.                   **/                 \
  /** Remarks: Returns a SmartPointer to the new instance.                       **/                 \
  static OdRxObjectPtr pseudoConstructor();                                                          \
                                                                                                     \
  /** Description: Creates a new instance of this object type.                   **/                 \
  /** Remarks: Returns a SmartPointer to the new instance.                       **/                 \
   static OdSmartPtr<ClassName> createObject()                                                       \
  { if (!desc()) throw OdError(eNotInitializedYet); return desc()->ODSYSCALL0(create); }                       \
                                                                                                     \
  /** Description: Registers ClassName with Teigha.                           **/                 \
  static void rxInit();                                                                              \
                                                                                                     \
  /* Description: Unregisters ClassName with Teigha.                          **/                 \
  static void rxUninit()
  
/** Description:
    Defines the empty constructor and casts a null pointer for the specified class.
*/
#define EMPTY_CONSTR(ClassName)(ClassName*)0

/** Description 
    Defines the pseudo-constructor for the specified class that creates a new instance, creates a smart pointer to it,
    does not increment its reference counter, and returns a smart pointer to the instance.
    
    Remarks: 
    The reference counter of a new instance is set to a default value.
*/                                          
#define NEWOBJ_CONSTR(ClassName) OdSmartPtr<ClassName>(new ClassName, kOdRxObjAttach)

/** Description:
    Defines Runtime Type Identification functions for OdRxObject objects.
*/
#define ODRX_DEFINE_RTTI_MEMBERS(ClassName,ParentClass)                                              \
                                                                                                     \
OdRxClass* ClassName::g_pDesc = 0;                                                                   \
OdRxClass* ClassName::desc(){ return g_pDesc; }                                                      \
OdRxClass* ClassName::isA() const { return g_pDesc; }                                                \
                                                                                                     \
OdRxObject* ClassName::queryX(const OdRxClass* pClass) const                                         \
{ return ::odQueryXImpl<ClassName,ParentClass >(this, pClass); }

#define ODRX_DEFINE_RTTI_MEMBERS_TEMPLARG(ClassName,ParentClass)                                     \
                                                                                                     \
OdRxClass* ClassName::g_pDesc = 0;                                                                   \
template<> OdRxClass* ClassName::desc(){ return g_pDesc; }                                           \
template<> OdRxClass* ClassName::isA() const { return g_pDesc; }                                     \
                                                                                                     \
OdRxObject* ClassName::queryX(const OdRxClass* pClass) const                                         \
{ return ::odQueryXImpl<ClassName,ParentClass >(this, pClass); }
/*
  Description:
  Defines initialization functions for OdObjecobjects.
*/
#define ODRX_DEFINE_INIT_MEMBERS(ClassName,ParentClass,pseudoConsFn, DwgVer,MaintVer,nProxyFlags,szDWGClassName,szDxfName,szAppName) \
                                                                                                     \
/* Registers this class with Teigha.                                         */                   \
void ClassName::rxInit()                                                                             \
{                                                                                                    \
  if (!ClassName::g_pDesc) {                                                                          \
     if(ParentClass::desc() == NULL) ParentClass::rxInit();                                           \
    ClassName::g_pDesc = ::newOdRxClass(szDWGClassName,ParentClass::desc(),                          \
    pseudoConsFn,DwgVer,MaintVer,nProxyFlags,szDxfName,szAppName);                                   \
    if(ClassName::g_pDesc)ClassName::g_pDesc->setRef(&ClassName::g_pDesc);                           \
  }                                                                                                  \
}                                                                                                    \
                                                                                                     \
/* Unregisters this class with Teigha.                                       */                   \
void ClassName::rxUninit()                                                                           \
{                                                                                                    \
  if (ClassName::g_pDesc) {                                                                          \
    ::deleteOdRxClassDefault(ClassName::g_pDesc);                                                    \
    ClassName::g_pDesc = 0;                                                                          \
  }                                                                                                  \
}


/** Description:
    Defines a Pseudoconstructor for ClassName.
*/
#define ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,DOCREATE)                                            \
                                                                                                     \
OdRxObjectPtr ClassName::pseudoConstructor() { return OdRxObjectPtr(DOCREATE(ClassName)); }

/** Description:
    Defines Runtime Type Identification and initialization functions for OdRxObject objects.
*/
#define ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,pseudoConsFn,DwgVer,MaintVer,nProxyFlags,szDWGClassName,szDxfName,szAppName) \
                                                                                                     \
ODRX_DEFINE_RTTI_MEMBERS(ClassName,ParentClass)                                                      \
                                                                                                     \
ODRX_DEFINE_INIT_MEMBERS(ClassName,ParentClass,pseudoConsFn,                                         \
    DwgVer,MaintVer,nProxyFlags, szDWGClassName,szDxfName,szAppName)
    

#define ODRX_DEFINE_MEMBERS2_TEMPLARG(ClassName,ParentClass,pseudoConsFn,DwgVer,MaintVer,nProxyFlags,szDWGClassName,szDxfName,szAppName) \
                                                                                                     \
ODRX_DEFINE_RTTI_MEMBERS_TEMPLARG(ClassName,ParentClass)                                                      \
                                                                                                     \
ODRX_DEFINE_INIT_MEMBERS(ClassName,ParentClass,pseudoConsFn,                                         \
    DwgVer,MaintVer,nProxyFlags, szDWGClassName,szDxfName,szAppName)

#define ODRX_DEFINE_MEMBERS(ClassName,ParentClass,DOCREATE,DwgVer,MaintVer, nProxyFlags,szDWGClassName,szDxfName,szAppName)\
                                                                                                     \
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,ClassName::pseudoConstructor,                             \
  DwgVer,MaintVer,nProxyFlags,szDWGClassName,szDxfName,szAppName)                                    \
                                                                                                     \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,DOCREATE)

#define ODRX_DEFINE_MEMBERS_TEMPLARG(ClassName,ParentClass,DOCREATE,DwgVer,MaintVer, nProxyFlags,szDWGClassName,szDxfName,szAppName)\
                                                                                                     \
ODRX_DEFINE_MEMBERS2_TEMPLARG(ClassName,ParentClass,ClassName::pseudoConstructor,                             \
  DwgVer,MaintVer,nProxyFlags,szDWGClassName,szDxfName,szAppName)                                    \
                                                                                                     \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,DOCREATE)

#define ODRX_NO_CONS_DEFINE_MEMBERS_ALTNAME(ClassName,ParentClass,szClassName)                       \
                                                                                                     \
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,0,0,0,0,szClassName,OdString::kEmpty,OdString::kEmpty)                \
                                                                                                     \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,EMPTY_CONSTR)

#define ODRX_NO_CONS_DEFINE_MEMBERS_ALTNAME_TEMPLARG(ClassName,ParentClass,szClassName)                       \
                                                                                                     \
ODRX_DEFINE_MEMBERS2_TEMPLARG(ClassName,ParentClass,0,0,0,0,szClassName,OdString::kEmpty,OdString::kEmpty)                \
                                                                                                     \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,EMPTY_CONSTR)

#define ODRX_NO_CONS_DEFINE_MEMBERS(ClassName,ParentClass)                                           \
                                                                                                     \
ODRX_NO_CONS_DEFINE_MEMBERS_ALTNAME(ClassName,ParentClass,OD_T(#ClassName))

#define ODRX_NO_CONS_DEFINE_MEMBERS_TEMPLARG(ClassName,ParentClass)                                           \
                                                                                                     \
ODRX_NO_CONS_DEFINE_MEMBERS_ALTNAME_TEMPLARG(ClassName,ParentClass,OD_T(#ClassName))

#define ODRX_CONS_DEFINE_MEMBERS_ALTNAME(ClassName,ParentClass,szClassName,DOCREATE)                 \
                                                                                                     \
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,ClassName::pseudoConstructor,0,0,0,szClassName,OdString::kEmpty,OdString::kEmpty) \
                                                                                                     \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,DOCREATE)



#define ODRX_CONS_DEFINE_MEMBERS(ClassName,ParentClass,DOCREATE)                                     \
                                                                                                     \
ODRX_CONS_DEFINE_MEMBERS_ALTNAME(ClassName,ParentClass,OD_T(#ClassName),DOCREATE)

#define ODRX_CONS_DEFINE_MEMBERS2(ClassName,ParentClass,VerNo)										\
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,ClassName::pseudoConstructor,VerNo,0,0,OD_T(#ClassName),OdString::kEmpty,OdString::kEmpty) \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,NEWOBJ_CONSTR)


#define ODRX_DXF_DEFINE_MEMBERS(ClassName,ParentClass,DOCREATE,DwgVer,MaintVer, nProxyFlags,DxfName,AppName)    \
                                                                                                                \
ODRX_DEFINE_MEMBERS(ClassName,ParentClass,DOCREATE,                                                             \
    DwgVer,MaintVer,nProxyFlags,OD_T(#ClassName),OD_T(#DxfName),OD_T(#AppName))



#define ODRX_DXF_CONS_DEFINE_MEMBERS(ClassName,ParentClass,DwgVer,MaintVer,nProxyFlags,DxfName,AppName)    \
                                                                                                           \
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,ClassName::pseudoConstructor,                                   \
    DwgVer,MaintVer,nProxyFlags,OD_T(#ClassName),OD_T(#DxfName),OD_T(#AppName))                                              \
                                                                                                           \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,NEWOBJ_CONSTR)

#define MAKE_ACDBOPENOBJECT_FUNCTION(CLASSNAME)
/** Description:

    {group:TD_Namespaces}
*/
namespace OdRx
{
  enum Ordering
  {
    kLessThan     =-1, // This object < Specified Object
    kEqual        = 0, // This object == Specified Object
    kGreaterThan  = 1, // This object > Specified Object
    kNotOrderable = 2  // These objects cannot be ordered.
  };
}


/** Description:
    {filename:OdRxObjectPtr_Definition}
    {group:OdRx_Classes} 

    This class provides the non-typified implementation of smart pointers for instances of classes derived from the OdRxObject class.

    Library:
    TD_Db
    
    Remarks:
    SmartPointers relieve the programmer of having to determine when objects are no longer needed, or having to delete
    them at that time.

    Each object referenced by a SmartPointer (henceforth 'referenced object') 
    maintains a reference count; i.e., how many SmartPointers are referencing it.     
    When the reference counter reaches zero, the referenced object is deleted.

     Samples:
    {hyperlink:Example of Assigning Smart Pointers|smart_pointers_example_refexchange.html}

    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html} 

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 

    The OdSmartPtr class   
*/
class OdRxObjectPtr
{
  OdRxObject*             m_pObject;

  /** Description:
    Increments the reference counter of the referenced object.
  */
  inline void internalAddRef();

  /** Description:
    Assigns the pointer of the specifed object to the smart pointer.  
      
    Remarks:
    The reference counter of the specified object is incremented.

    If this SmartPointer is currently referencing another object, that object 
    is released prior to the assignment.  

    Arguments:
    pObject (I) Pointer to the specified object to be assigned.
  */
  void assign(
    const OdRxObject* pObject)
  {
    if (m_pObject != pObject)  // To prevent reference counter dec/inc which
    {                       // may cause object destruction or subClose
      release();
      m_pObject = (OdRxObject*)pObject;
      internalAddRef();
    }
  }

public:

  /** Description:
    Constructors for the non-typified smart pointer.

    Arguments:
    pSource (I) Pointer to the specified object to be assigned for the new SmartPointer object.

    Remarks:
    If pSourceis specified, the smart pointer is set to the address of the specified object. If pSource is not specified, the smart pointer is set to a NULL.
    
    Remarks:
    If OdRxObjMod is specified, the reference counter of the specified object 
    is *not* incremented. 
  */
  OdRxObjectPtr() : m_pObject(0) { }
  OdRxObjectPtr(
    const OdRxObject* pSource, 
    OdRxObjMod)
    : m_pObject(const_cast<OdRxObject*>(pSource))
  { }

  OdRxObjectPtr(
    const OdRxObject* pSource) : m_pObject((OdRxObject*)pSource) { internalAddRef(); }

  OdRxObjectPtr(
    const OdRxObjectPtr& pSource) : m_pObject((OdRxObject*)pSource.get()) { internalAddRef(); }

  /** Description:
    Assigns the pointer of the specifed object to the smart pointer without incrementing its reference counter.  
      
    Arguments:
    pObject (I) Pointer to the specified object to be assigned.

    Remarks:
    The reference count of the specified object is not incremented.

    If this SmartPointer is currently referencing another object, that object 
    is released prior to the assignment.

    Samples:
    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html} 
  */
  void attach(
    const OdRxObject* pObject) { release(); m_pObject = (OdRxObject*)pObject; }

  /** Description:
    Destructor for the non-typified smart pointer.

    Remarks:
    Decrements the reference counter of the referenced object. When the reference count reaches zero, the referenced object is deleted.
  */
  ~OdRxObjectPtr()
 { 
     release(); 
 }

  /** Description:
    Releases the smart pointer reference to the referenced object. 
    
    Remarks:
    Decrements the reference counter of the referenced object.  When the reference count reaches zero, 
    the referenced object is deleted. Smart pointer is set to a NULL.

    Samples:
    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html} 
  */
  inline void release();

  /** Description:
    Releases the smart pointer reference to the referenced object without decrementing of the reference counter. 
      
    Remarks:
    Returns the raw pointer to the referenced object. The reference counter is not modified 
    for the referenced object. Smart pointer is set to a NULL.

    Samples:
    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html}
  */
  OdRxObject* detach()
  {
    OdRxObject* res = m_pObject;
    m_pObject = 0;
    return res;
  }

  /**
    Remarks:
    The assignment operator increments the reference counter of the referenced object and saves its address in the smart pointer.
     If the smart pointer is currently referencing to another object, that assignment operator releases the referenced object prior 
     to the assignment.  

    Samples:
   {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html}
  */
  OdRxObjectPtr& operator = (
    const OdRxObjectPtr& source)
  { assign(source); return *this; }

  OdRxObjectPtr& operator = (
    const OdRxObject* source)
  { assign(source); return *this; }

  /** Description:
    Returns the raw pointer to the referenced object.

    Remarks:
    The smart pointer maintains its reference to the referenced object.
    The reference counter of the referenced object is not changed.
 
    Samples:
    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html} 
 */
  OdRxObject* get() { return m_pObject; }
  const OdRxObject* get() const { return m_pObject; }

  /** Description:
    Returns the raw pointer to the referenced object.
      
    Remarks:
    The reference counter of the referenced object is not changed.

    Samples:
    {hyperlink:Example of a Non-Typified Smart Pointer|smart_pointers_example_nontypified.html} 
  */
  OdRxObject* operator ->() { return m_pObject; }
  const OdRxObject* operator ->() const { return m_pObject; }

#ifdef ODA_GCC_2_95
  /** Description:
    Returns the raw pointer to the referenced object.
    
    Remarks:
    The class maintains the reference to the referenced object.
    The reference counter of the referenced object is not changed.

    This non-standard form is used to eliminate a large number of compiler
    warnings produced by GCC 2.95.X (GCC 3.X no longer produces these warnings).
  */
  operator OdRxObject*() const { return m_pObject; }
#else
  /** Description:
    Returns the raw pointer of the referenced object.
    
    Remarks:
    The reference counter of the referenced object is not changed.
  */
  operator OdRxObject*() { return m_pObject; }

  operator const OdRxObject*() const { return m_pObject; }
#endif

  bool operator==(
    const OdRxObject* pObject) const { return (m_pObject==pObject); }

  bool operator!=(
    const OdRxObject* pObject) const { return (m_pObject!=pObject); }

  /** Description:
    Returns true if and only if this smart pointer is a NULL.
  */
  bool isNull() const { return m_pObject == 0; }
  friend class OdRxClassProtocolExtImpl;
};


/** Description:
    {filename:OdRxObject_Definition}
    {group:OdRx_Classes} 

    This class is the base class for all OdRxObject objects that 
    require Runtime Type Identification.

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxObject
{
public:
  /** Description:
      Constructor for this class that assigns another Rx-object.
  */
  OdRxObject(const OdRxObject&);

  /** Description:
      Assignment operator prohibited.
  */
  OdRxObject& operator = (const OdRxObject&);

public:
  /** Description:
      Protects derived OdRxObject objects from direct use of new and delete. 
  */
  ODRX_HEAP_OPERATORS();

public:
  /** Description:
      Constructor for this class.
  */
  OdRxObject() { }

  /** Description:
      The virtual destructor for this class.
  */
  virtual ~OdRxObject();

  /** Description:
    Returns a pointer this object if this object can be converted to the specified class.

    Arguments:
    pClass (I) A pointer to the class to which this object is to be converted.
      
    Remarks:
    If the object cannot be converted, a null pointer is returned.
    The user must release() this object, if the returned pointer is not null.
  */
  virtual OdRxObject* queryX(
    const OdRxClass* pClass) const;

  /** Description:
    Returns a pointer this object if this object can be converted to the specified class,
    or throws an exception if it cannot.

    Arguments:
    pClass (I) A pointer to the class to which this object is to be converted.

    Throws:
    @table
    Exception             Cause
    eNotThatKindOfClass   Cannot convert to the specified class.
    eInvalidInput         pClass is null

  */
  virtual OdRxObject* x(
    const OdRxClass* pClass) const;

  /** Description:
    Casts the specified *pointer* to a SmartPointer and returns the SmartPointer object.

    Arguments:
    pointer (I) Pointer to be cast.
  */
  static OdRxObjectPtr cast(ODSYSDEF , 
    const OdRxObject* pointer)
  {
    OdRxObjectPtr pRes;
    if (pointer)
      pRes.attach(pointer->queryX(desc()));
    return pRes;
  }

  static OdRxObject * cast (const OdRxObject* pObj)
  {
	OD_TRY_N()

    OdRxObjectPtr objPtr = ODSYSCALL1(cast , pObj);
    return objPtr.get();
	
	OD_CATCH_N()

	return NULL;
  }
  /** Description: Returns the static OdRxClass description object associated with this object. **/
  /** Note: This function is for use only when the class type of this object is known.          **/
  /** If the class type of this object is unknown, use instead isA().                           **/
  static OdRxClass* desc();


  /** Description: Returns the OdRxClass description instance associated with this object.      **/  
  /** Note: This function is for use only when the class type of this object is unknown.        **/  
  /** If the class type of this object is known, use instead desc().                            **/  
  virtual OdRxClass* isA() const;

  /** Description:
    Declares the method incrementing the reference counter in objects derived from this class.

    Remarks:
    It is the pure virtual method that does not have an implementation. You must redefine it in the derived class.

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 
  */
  virtual void addRef() {};

  /** Description:
    Declares the method decrementing the reference counter in objects derived from this class.
    
    Remarks:
    It is the pure virtual method that does not have an implementation. You must redefine it in the derived class.

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 
  */
  virtual void release() {};

  /** Description:
      Returns the value of the reference counter, that is, the number of references to an instance of this class.

    Remarks:
    This method has the default implementation that returns 1. You shloud redefine it in the derived class.

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 
  */
  virtual long numRefs() const;


  virtual bool isLocked() const { return true;}
  virtual void lock(bool blLock){}
   /**
    Description:
    Returns true if and only if this object is an instance of the specified class or
    a subclass of the specified class.

    Arguments:
    pClass (I) Pointer to the class to test. 
  */
  bool isKindOf(
    const OdRxClass* pClass) const
  {
    OdRxObjectPtr pRes;
    pRes.attach(queryX(pClass));
    return (!pRes.isNull());
  }

  /** Description:
    Creates a *clone* of this object, and returns a pointer to the *clone*.
  */
  OdRxObjectPtr clone(ODSYSDEF) const;
#ifdef ODARXDEF
  virtual OdRxObject * clone() const;
#endif
  /*
    Description:
    Copies the contents of the specified object into this object.
    
    Arguments:
    pSource (I) Pointer to the source object.
    
    Note:
    The default implementation of this function does nothing but throw an eNotApplicable exception. 
    
    Throws:
    @table
    Exception    
    eNotApplicable
   
 */
  virtual OdResult copyFrom(
    const OdRxObject* pSource);

  /** Description:
    Compares another object to this one in a manner similar to strcmp(). 

    Arguments:
    pOther (I) Pointer the object to be compared.
    
    Remarks:
    comparedTo() returns one of the following:
    
    @table
    Name                           Value     Description.
    OdRx::kLessThan                -1        This object < Other Object
    OdRx::kLessThanEqual            0         This object == Other Object
    OdRx::kLessThanGreaterThan      1         This object > Other Object
    OdRx::kLessThanNotOrderable     2         This class is not orderable.
   
    Note:
    The default implementation of this function returns OdRx::kNotOrderable. 
  */
  virtual OdRx::Ordering comparedTo(
    const OdRxObject* pOther) const;

  /**
    Description:
    Returns true if and only if the specified object is equal to this one.

    Arguments:
    pOther (I) Pointer to the object to be compared.

  */
  virtual OdBool isEqualTo(
    const OdRxObject* pOther) const;

  static void rxInit() {}
};



void OdRxObjectPtr::internalAddRef()
{
  if(m_pObject) { m_pObject->addRef(); }
}
void OdRxObjectPtr::release()
{
  if (m_pObject)
  {
    m_pObject->release();
    m_pObject = NULL;
  }
}
#include "SmartPtr.h"

/** Description:
    Defines OdPseudoConstructorType as a function pointer type.
    
    Remarks:
    Functions pointed to by OdPseudoConstructorType 
    take no arguments and construct instances of
    classes derived from OdRxObject;
    hence the name PseudoConstructorType.
*/
typedef OdRxObjectPtr (*OdPseudoConstructorType)();

/** Description:
    Contains runtime information about OdRxObject or classes derived from it.  
    
    Remarks:
    A pointer to an OdRxClass instance can be obtained for an OdRxObject class by calling 
    the OdRxObject::desc() function.

    {group:OdRx_Classes} 
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxClass : public OdRxObject
{
protected:
  OdRxClass();
public:
  ODRX_DECLARE_MEMBERS(OdRxClass);
 
  /** Description:
    Creates the Protocol Extension for the specified OdRxClass.

    Arguments:
    pProtocolClass (I) Pointer to the Protocol Extension class.
    pProtocolObject (I) Pointer to the Protocol Extension Object.

    Remarks:
    Returns a SmartPointer to the Protocol Extension.

    Note:
    The default implementation of  this object does nothing but return a
    null pointer, and asserts in debug mode. It will be
    fully implemented in a future *release*.
  */
  OdRxObjectPtr addX(ODSYSDEF,
    OdRxClass* pProtocolClass, 
    OdRxObject* pProtocolObject);
 #ifdef ODARXDEF
  virtual OdRxObject* addX(OdRxClass* pProtocolClass, OdRxObject* pProtocolObject);
#endif
  /** Description:
    Returns the Protocol Extension for the specified
    Protocol extension class.

    Arguments:
    pProtocolClass (I) Pointer to the Protocol Extension class.

    Remarks:
    Returns a SmartPointer to the Protocol Extension.

    Note:
    The default implementation of this object does nothing but
    assert in debug mode, and return a null pointer.
    It will be fully implemented in a future *release*.
  */
//  OdRxObjectPtr getX(ODSYSDEF, const OdRxClass* pProtocolClass);
  virtual OdRxObject* getX(const OdRxClass* pProtocolClass);

  /** Description:
    Deletes the Protocol Extension for the specified Protocol Extension class.

    Remarks:
    Returns the Protocol Extension Object.

    Arguments:
    pProtocolClass (I) Pointer to the Protocol Extension class.

    Note:
    As currently implemented, this function does nothing but
    assert in debug mode, and return a null pointer.
    It will be fully implemented in a future *release*.
  */
  OdRxObjectPtr delX(ODSYSDEF, OdRxClass* pProtocolClass);
#ifdef ODARXDEF
  virtual OdRxObject* delX(OdRxClass* pProtocolClass);
#endif 
  /** Description:
    Creates a new instance of the C++ class represented by this OdRxClass.

    Remarks:
    Returns a SmartPointer to the newly created class.
  */
  OdRxObjectPtr create(ODSYSDEF) const;
  virtual OdRxObject* create() const = 0;

  /** Description:
    Returns the application *name* associated with this OdRxClass.
  */
  virtual const OdChar* appName() const = 0;

  /** Description:
    Returns the DXF *name* for this OdRxClass.  
  */
  virtual const OdChar* dxfName() const = 0;

  /** Description:
    Returns the *name* of the C++ class represented by this OdRxClass.
  */
  virtual const OdChar* name() const = 0;

  /** Description:
    Returns the .dwg file maintenance version for this OdRxClass.

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer to receive the maintenance release version.

    Remarks:
    The maintenance release version is returned if and only if pMaintReleaseVer != NULL. 
  */
  virtual void getClassVersion(
    int &dwgVer , int &maintVer) const = 0 ;

  /** Description:
    Returns the proxy flags for this OdRxClass.
  */
  virtual OdUInt32 proxyFlags() const = 0;
  
  /** Description:
    Returns true if and only if this object is an instance of the specified class or
    a subclass of the specified class.

    Arguments:
    pClass (I) Pointer to the class to test. 
  */
  virtual bool isDerivedFrom(
    const OdRxClass* pClass) const;

  /** Description:
    Returns the parent of this OdRxClass.
  */
  virtual OdRxClass* myParent() const = 0;

  /** Description:
    Returns the OdRxModule in which the class is resides.

    Note:
    The default implementation of this function returns a null pointer. 
  */
  virtual OdRxModule* module() const = 0;

  /**
    Description:
    Returns the PseudoConstructor of this OdRxClass.
  */
  virtual OdPseudoConstructorType constructor();

  /**
    Description:
    Sets the PseudoConstructor for this OdRxClass.

    Arguments:
    pseudoConstr (I) PseudoConstructor.
  */
  virtual void setConstructor(
    OdPseudoConstructorType psuedoConstr) = 0;

  virtual OdRxClass** getRef(){return NULL;}
  virtual void setRef(OdRxClass** ppClass){}

  virtual AppNameChangeFuncPtr appNameCallbackPtr() const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class template for OdRxClass object pointers.
*/
typedef OdSmartPtr<OdRxClass> OdRxClassPtr;

#define ODRX_PE_PTR(RxObj,PEClass) PEClass::cast(RxObj-> \
                                            queryX(PEClass::desc()))

// Deprecated: The ACRX_X_CALL macro will be removed in a future
// release.  Please use ACRX_PE_PTR() instead.
//
#define ODRX_X_CALL(RxObj,PEClass) PEClass::cast(RxObj->x(PEClass::desc()))

template <class Class, class Parent>
OdRxObject* odQueryXImpl(const Class* pThis, const OdRxClass* pClass)
{
  ODA_ASSERT(pClass!=0); // if you get here, most likely requested class is not registred

  OdRxClass* pDesc = Class::desc();

  if(!pDesc)
    return NULL;

  OdRxObject* pObj = 0;
  if(pClass == pDesc)
  {
    pObj = (OdRxObject*)pThis;
    pObj->addRef();
  }
  else
  {
    //pObj = Class::desc()->ODSYSCALL1(getX,pClass).detach();
    pObj = pDesc->getX(pClass);
  
    if(!pObj)	
      pObj = pThis->Parent::queryX(pClass);
    else
      pObj->addRef();
  }
  return pObj;
}

FIRSTDLL_EXPORT OdRxObjectPtr odrxCreateObject(
    const OdString& szClassName);

FIRSTDLL_EXPORT OdRxClass* newOdRxClass(
    const OdString& szClassName,
    OdRxClass* pBaseClass,
    OdPseudoConstructorType pConstr = 0,
    int DwgVer = 0,

    int MaintVer = 0,
    int nProxyFlags = 0,
    const OdString& szDxfName = OdString::kEmpty,
    const OdString& szAppName = OdString::kEmpty
  );

OdRxClass* newOdRxClass(
    const char* className,
    const char* parentClassName,
    int         proxyFlags = 0,
    OdRxObject* (*pseudoConstructor)() = NULL,
    const char* dxfName = NULL,
    const char* appName = NULL);

OdRxClass* newOdRxClass(
    const char* className,
    const char* parentClassName,
    int         dwgVer,
    int         maintVer,
    int         proxyFlags = 0,
    OdRxObject* (*pseudoConstructor)() = NULL,
    const char* dxfName = NULL,
    const char* appName = NULL,
    AppNameChangeFuncPtr func = NULL);

FIRSTDLL_EXPORT void deleteOdRxClassDefault(
  OdRxClass* pClass);

FIRSTDLL_EXPORT void deleteOdRxClass(
  OdRxClass* pClass);

FIRSTDLL_EXPORT void odrxBuildClassHierarchy();

/** Description:
    This template class is a specialization of the OdArray class template for OdRx object pointers.
*/
typedef OdArray<OdRxObjectPtr> OdRxObjectPtrArray;

#include "TD_PackPop.h"

#endif //_ODRXOBJECT_INCLUDED_

