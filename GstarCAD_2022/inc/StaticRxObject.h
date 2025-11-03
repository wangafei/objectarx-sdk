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




// StaticRxObject.h
//
//////////////////////////////////////////////////////////////////////

#if !defined(ODSTATICRXOBJECT_INCLUDED_)
#define ODSTATICRXOBJECT_INCLUDED_

/** Description:
    {filename:OdStaticRxObject_Definition}
    {group:Other_Classes}

    This template class provides the {hyperlink:empty implementation of counting references|smart_pointers_definition_empty.html}  
    for instances of classes derived from the OdRxObject class.

    Library: 
    TD_Db

    Remarks:
    When you use this template class, the numRefs method is inherited from the OdRxObject class in the default definition.
    The numRefs method returns 1 by default.

    Samples:  
    {hyperlink:Example of Counting References|smart_pointers_example_count_empty.html}

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 

    The OdRxObjectImpl class
*/
template<class T>
class OdStaticRxObject : public T
{
public:
  /** Description:
    Simulates the incrementing of the reference counter non-changing it.
  */
  void addRef() { }
  /** Description:
    Simulates the decrementing of the reference counter non-changing it.
  */
  void release() { }
};

#endif // !defined(ODSTATICRXOBJECT_INCLUDED_)

