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




#if !defined(OdRxObjectImpl_INCLUDED_)
#define OdRxObjectImpl_INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "OdMutex.h"

/** Description:
    {filename:OdRxObjectImpl_Definition}
    {group:OdRx_Classes} 

    The template class provides the {hyperlink:standard implementation of the counting references|smart_pointers_definition_standard.html} 
    for instances of objects derived from the OdRxObject class.

    Library:
    TD_Db

    Samples:
    {hyperlink:Example of Counting References|smart_pointers_example_count_standard.html}

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 

    The OdStaticRxObject class
*/
template<class T, class TInterface = T>
class OdRxObjectImpl : public T
{
  /** Description:
      Allows to create OdRxObjectImpl<T> instances inside this class only.
  */
  OdRefCounter m_nRefCounter;

  /** Description:
      Assignment operator prohibited.
  */
  OdRxObjectImpl& operator = (const OdRxObjectImpl&);

protected:
  ODRX_HEAP_OPERATORS();

public:
  /** Description:
      Constructor sets the reference counter to one.
  */
  OdRxObjectImpl() 
  { 
    m_nRefCounter = 1; 
  }

  /** Description:
      Increments the reference counter.
  */
  void addRef()
  {
    ++m_nRefCounter;
  }

  /** Description:
      Decrements the reference counter, checks the reference counter, and destroys the instance 
      when the reference counter reaches zero.
  */
  void release()
  {
		ODA_ASSERT((m_nRefCounter > 0));
		if (!(--m_nRefCounter))
		{
      delete this;
		}
  }

  /** Description:
      Returns the number of references to an instance of this class.
  */
  long numRefs() const { return m_nRefCounter; }

  /** Description:
      It is the pseudo-constructor that creates an instance of this class  and returns the typified smart pointer to it.
  */

  static OdSmartPtr<TInterface> createObject()
  {
    return OdSmartPtr<TInterface>(static_cast<TInterface*>(new OdRxObjectImpl<T, TInterface>), kOdRxObjAttach);
  }
};


/** Description:
    Defines the pseudo-constructor for the specified class that is equivalent the pseudo-constructor of the wrapper class using the standard implementation.
*/
#define RXIMPL_CONSTR(ClassName) OdRxObjectImpl<ClassName>::createObject()

/** Description:
    Defines a pseudo-constructor for the specified class.
*/
#define ABSTRACTIMPL_CONSTR(CLASS) OdRxObjectImpl<CLASS##Impl>::createObject()

#include "TD_PackPop.h"

#endif // !defined(OdRxObjectImpl_INCLUDED_)

