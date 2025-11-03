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

// OdGiVariant type for generic procedural material.

#ifndef __ODGIVARIANT_H__
#define __ODGIVARIANT_H__

#include "../RootExport.h"
#include "GiExport.h"

#include "../CmColor.h"
#include "../RxVariant.h"
#include "../RxObject.h"

#include "../TD_PackPush.h"

/** Description:
    This class is used as the basis for the generic data storage used for procedural material definitions.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiVariant : public OdRxObject
{
  static void copyDataFrom(OdGiVariant &vTo, const OdGiVariant &vFrom);
  public:
    enum VariantType
    {
      kUndefined = 0,
      kBoolean,
      kInt,
      kDouble,
      kColor,
      kString,
      kTable
    };
  public:
    ODRX_DECLARE_MEMBERS(OdGiVariant);

    //Constructors
    OdGiVariant();
    OdGiVariant(const OdGiVariant &value);
    OdGiVariant(bool value);
    OdGiVariant(OdInt32 value);
    OdGiVariant(double value);
    OdGiVariant(const OdCmEntityColor &value);
    OdGiVariant(const OdString &value);
    OdGiVariant(const OdChar *value);

  //protected:
  //  OdGiVariant();
  public:
    // Set of object constructors
    static OdSmartPtr<OdGiVariant> createObject(const OdGiVariant &value);
    static OdSmartPtr<OdGiVariant> createObject(bool value);
    static OdSmartPtr<OdGiVariant> createObject(OdInt32 value);
    static OdSmartPtr<OdGiVariant> createObject(double value);
    static OdSmartPtr<OdGiVariant> createObject(const OdCmEntityColor &value);
    static OdSmartPtr<OdGiVariant> createObject(const OdString &value);
    static OdSmartPtr<OdGiVariant> createObject(const OdChar *value);

    ~OdGiVariant();

    bool operator ==(const OdGiVariant& value) const;

    OdGiVariant &operator =(const OdGiVariant& value);

    virtual OdResult copyFrom(const OdRxObject* pSource);

    VariantType type() const;

    void set(bool value);
    void set(OdInt32 value);
    void set(double value);
    void set(const OdCmEntityColor &value);
    void set(const OdChar *value);

    bool asBoolean() const;
    OdInt32 asInt() const;
    double asDouble() const;
    OdCmEntityColor asColor() const;
    OdString asString() const;
    const OdCmEntityColor& asEntityColor() const;
    // Table access
    bool getElem(const OdString &elem, OdGiVariant &value) const;
    const OdGiVariant *getElem(const OdString &elem) const;
    void setElem(const OdString &elem, const OdGiVariant &value);
    void deleteElem(const OdString &elem);
    OdInt32 getElemCount() const;
    bool getElemAt(OdInt32 nElem, OdString &elem, OdGiVariant &value) const;
    const OdGiVariant *getElemAt(OdInt32 nElem, OdString &elem) const;

    static bool isEquivalent(const OdGiVariant *v1, const OdGiVariant *v2);
  private:
    VariantType m_type;
    OdVariant m_variant;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiVariant object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiVariant> OdGiVariantPtr;

#include "../TD_PackPop.h"

#endif // __ODGIVARIANT_H__
