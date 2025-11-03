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

#ifndef ODDGNLS_DBLSINTERNALCOMPONENT_H
#define ODDGNLS_DBLSINTERNALCOMPONENT_H

#include "DbLSStrokePatternComponent.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Internal Component.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSInternalComponent : public OdDbLSStrokePatternComponent
{
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSInternalComponent);

    OdDbLSInternalComponent();

    /**
      Description:
      Returns hardware style for this internal component.

      Remarks:
      Typically it is similar with *lineCode*.
    */
    OdUInt32 hardwareStyle() const;
    /**
      Description:
      Sets hardware style for this internal component.

      Arguments:
      nStyle (I) New style to set.
    */
    void setHardwareStyle(OdUInt32 nStyle);

    /**
      Description:
      Returns true if hardware style is set.

      Remarks:
      Typically true for [1-7] line codes.
    */
    bool isHardwareStyle() const;
    /**
      Description:
      Sets flag which is incicate that hardware style is set for this internal component.

      Arguments:
      bSet (I) New flag to set.
    */
    void setIsHardwareStyle(bool bSet);

    /**
      Description:
      Returns Design line code for this internal component.

      Remarks:
      Internal components in Design file could be in [0-7] range.
    */
    OdUInt32 lineCode() const;
    /**
      Description:
      Sets Design line code for this internal component.

      Arguments:
      nCode (I) New code to set.
    */
    void setLineCode(OdUInt32 nCode);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSInternalComponent object pointers.
*/
typedef OdSmartPtr<OdDbLSInternalComponent> OdDbLSInternalComponentPtr;

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSINTERNALCOMPONENT_H
