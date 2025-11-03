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

#ifndef _OdGsLight_h_Included_
#define _OdGsLight_h_Included_

#include "../RxObject.h"

class OdGePoint3d;
class OdGeVector3d;

#include "../TD_PackPush.h"

/** Description:
    This class is the base class for Light objects in an OdGs framework.
    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class FIRSTDLL_EXPORT OdGsLight : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGsLight);

  enum LightType
  {
    kPointLight      = 0,
    kDistantLight    = 1,
    kSpotlight       = 2
  };

  enum LightAttenuation
  {
    kAttenNone            = 0,
    kAttenInverseLinear   = 1,
    kAttenInverseSquare   = 2
  };

  /** Description:
    Returns the *type* of this Light object.
    
    Remarks:
    type() returns one of the following:
    
    @table
    Name             Value
    kPointLight      0
    kDistantLight    1
    kSpotlight       2
  */
  virtual LightType type() const = 0;
  
  /** Description:
    Returns the WCS *position* of this Light object. 
  */
  virtual OdGePoint3d position() const = 0;

  /** Description:
    Returns the WCS *target* of this Light object. 
  */
  virtual OdGePoint3d target() const = 0;
  /** Description:
    Returns the WCS *direction* of this Light object. 
  */
  virtual OdGeVector3d direction() const = 0;
  /** Description:
    Returns the *color* of this Light object. 
  */
  virtual ODCOLORREF color() const = 0;
  /** Description:
    Returns the *intensity* of this Light object. 
  */
  virtual double intensity() const = 0;
  /** Description:
    Returns the *attenuation* of this Light object. 
    
    Remarks:
    attenuation() returns one of the following:
    
    @table
    Name                  Value      
    kAttenNone            0          
    kAttenInverseLinear   1
    kAttenInverseSquare   2
  */
  virtual LightAttenuation attenuation() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsLight object pointers.
*/
typedef OdSmartPtr<OdGsLight> OdGsLightPtr;

#include "../TD_PackPop.h"

#endif // _OdGsLight_h_Included_
