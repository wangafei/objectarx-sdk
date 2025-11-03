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

#ifndef ODDGNLS_DBLSDEFINITION_H
#define ODDGNLS_DBLSDEFINITION_H

#include "DbLSObject.h"

#include "TD_PackPush.h"

enum MSLSUnits
{
  kMSLSMasterUnits = 0, // Master Units
  kMSLSUORS        = 1, // Design UORs
  kMSLSDeviceUnits = 2  // Device Units
};

/** Description:
    Dgn Line Style Definition.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSDefinition : public OdDbLSObject
{
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSDefinition);

    OdDbLSDefinition();

    /**
      Description:
      Returns initial component for Line Style.
    */
    OdDbObjectId component() const;
    /**
      Description:
      Sets initial component for Line Style.

      Arguments:
      compId (I) Identifier of component.
    */
    void setComponent(const OdDbObjectId &compId);

    /**
      Description:
      Returns component unique identifier.

      Remarks:
      16 bytes of data.
    */
    const OdUInt8 *componentUID() const;

    /**
      Description:
      Returns true if Line Style marked as continuous.
    */
    bool isContinuous() const;
    /**
      Description:
      Marks Line Style as continuous.

      Arguments:
      bSet (I) New value to set.
    */
    void setIsContinuous(bool bSet);

    /**
      Description:
      Returns true if Line Style comes from RSC file, elsewhere it is embedded in Design file.
    */
    bool isElement() const;
    /**
      Description:
      Sets flag which indicate that this Line Style comes from RSC file.

      Arguments:
      bSet (I) New value to set.
    */
    void setIsElement(bool bSet);

    /**
      Description:
      Returns true if Line Style marked as physical.

      Remarks:
      If true, prevents the Global Line Style Scale and the Annotation Scale factors from being applied.
    */
    bool isPhysical() const;
    /**
      Description:
      Marks this Line Style as physical.

      Arguments:
      bSet (I) New value to set.
    */
    void setIsPhysical(bool bSet);

    /**
      Description:
      Returns true if Line Style marked to scale inside shared cells independently.
    */
    bool isSCScaleIndependent() const;
    /**
      Description:
      Sets shared cell scale independent flag to this Line Style.

      Arguments:
      bSet (I) New value to set.
    */
    void setIsSCScaleIndependent(bool bSet);

    /**
      Description:
      Returns true if Line Style marked as snappable.

      Remarks:
      If true, allows you to snap to the individual components of a line style.
      If false, allows you to snap to the underlying line of a line style.
    */
    bool isSnappable() const;
    /**
      Description:
      Sets snappable flag for this Line Style.

      Arguments:
      bSet (I) New value to set.
    */
    void setIsSnappable(bool bSet);

    /**
      Description:
      Returns name of this Line Style.
    */
    OdString name() const;
    /**
      Description:
      Sets name for this Line Style.

      Arguments:
      str (I) Name to set.
    */
    void setName(const OdString &str);

    /**
      Description:
      Returns the style number for this Line Style.
    */
    OdInt32 styleNumber() const;
    /**
      Description:
      Sets style number for this Line Style.

      Arguments:
      nStyle (I) Style number to set.
      Remarks:
      Typically it is null.
    */
    void setStyleNumber(OdInt32 nStyle);

    /**
      Description:
      Returns the Line Style scale stored in definition.

      Remarks:
      Typically it is null.
    */
    double unitDef() const;
    /**
      Description:
      Sets the Line Style scale stored in definition.

      Arguments:
      fUnit (I) New scale factor to set.
      Remarks:
      It will be used as multiplier for *unitScale* if will be set as non-zero.
    */
    void setUnitDef(double fUnit);

    /**
      Description:
      Returns unit scale for this Line Style.

      Remarks:
      Typically it is 1.0.
    */
    double unitScale() const;
    /**
      Description:
      Sets the unit scale factor for this Line Style.

      Arguments:
      fUnit (I) New scale factor to set.
    */
    void setUnitScale(double fUnit);

    /**
      Description:
      Returns type of units used for this Line Style.

      Remarks:
      Typically it is set to kMSLSMasterUnits.
    */
    MSLSUnits unitsType() const;
    /**
      Description:
      Sets type of units used for this Line Style.

      Arguments:
      type (I) New type to set.
    */
    void setUnitsType(MSLSUnits type);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSDefinition object pointers.
*/
typedef OdSmartPtr<OdDbLSDefinition> OdDbLSDefinitionPtr;

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSDEFINITION_H
