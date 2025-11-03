/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2018, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2018 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////



#ifndef _INC_DDBRENTITY_3F819553013C_INCLUDED
#define _INC_DDBRENTITY_3F819553013C_INCLUDED


#include "../OdaCommon.h"
#include "../RxObject.h"
#include "../Br/BrExport.h"
#include "../Br/BrEnums.h"
#include "../Br/BrProps.h"

#include "../TD_PackPush.h"
#include "../SharedPtr.h"
#include "../DbSubentId.h"
#include "../Ge/Ge.h"

class OdBrBrep;
class OdBrHit;
class OdGePoint3d;
class OdGeLinearEnt3d;
class OdGeBoundBlock3d;
class OdBrBrepData;

/** \details
  This class is the interface base class for BREP topology objects.

  Corresponding C++ library: TD_Br

  <group OdBr_Classes>
*/
class ODBR_TOOLKIT_EXPORT OdBrEntity : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdBrEntity);
  /** \details
    Destructor for objects of the OdBrEntity class.
  */
  virtual ~OdBrEntity();

  /** \details
    Returns true if and only if there is no ACIS model associated with this
    entity object.

    \returns
    True if there is no ACIS model associated with this entity object; false
    otherwise.
  */
  bool isNull() const;

  /** \details
    Returns true if and only if the specified entity object is equivalent to
    this entity object.

    \param pOtherEntity [in]  Pointer to any OdBrEntity object.

    \returns
    True if the specified entity object is equivalent to this entity object;
    false otherwise.

    \remarks
    Two OdBrEntity objects are equivalent if and only if they are non-NULL, and
    have the same subentity path.
  */
  OdBool isEqualTo(const OdRxObject* pOtherEntity) const;

  /** \details
    Returns the owner of this entity object.
    
    \param brep [out] Owner of this entity object.

    \returns
    True if successful; false otherwise.
  */
  OdBrErrorStatus getBrep(OdBrBrep& brep) const;

  /** \details
    Validates the element.
  */
  bool checkEntity() const;

  OdBrErrorStatus   set(const OdDbFullSubentPath& path);
  OdBrErrorStatus   get(OdDbFullSubentPath& path) const;

  OdBrErrorStatus   setSubentPath   (OdDbFullSubentPath& subpath);
  OdBrErrorStatus   getSubentPath   (OdDbFullSubentPath& subPath) const;

  /** \details
  Returns the FullSubentPath of this Entity object.
  see OdDbBody::setSubentPath also.
  */
  OdBrErrorStatus getSubentPath(OdDbBaseFullSubentPath& subPath) const;

  // for internal usage only. OdDbBody::setSubentPath should be used instead.
  OdBrErrorStatus setSubentPath(OdBrBrep &brep, OdDbBaseFullSubentPath& subpath);

  OdBrErrorStatus getPointContainment(const OdGePoint3d&      point,
                                      OdGe::PointContainment& containment,
                                      OdBrEntity*&            brEntContainer ) const;

  OdBrErrorStatus getLineContainment( const OdGeLinearEnt3d& line,
                                      const OdUInt32&        iNumHitsWanted,
                                      OdUInt32&              iNumHitsFound,
                                      OdBrHit*&              brHit ) const;


  // Geometric properties
  OdBr::ErrorStatus	getMassProps	(OdBrMassProps& massProps,
    const double&  density     = *(double*)NULL,
    const double&  tolRequired = *(double*)NULL,
    double&        tolAchieved = *(double*)NULL) const;

  OdBr::ErrorStatus	getVolume		(double&       volume,
    const double& tolRequired = *(double*)NULL,
    double&       tolAchieved = *(double*)NULL) const;

  OdBr::ErrorStatus	getSurfaceArea	(double&       area,
    const double& tolRequired = *(double*)NULL,
    double&       tolAchieved = *(double*)NULL) const;

  OdBr::ErrorStatus	getPerimeterLength(double&       length,
    const double& tolRequired = *(double*)NULL,
    double&       tolAchieved = *(double*)NULL) const;


  void* getEntity() const;
  OdBrErrorStatus setEntity(void* pData, OdDbFullSubentPath& subPath = *(OdDbFullSubentPath*)NULL);

  /** \details
    Calculates the entity geometric bounds.

    \param block [out] Model space bounding box as OdGeBoundBlock3d.

    \returns
    * odbrNotImplementedYet &mdash; if the method is not implemented for the current modeler.
    * odbrUninitialisedObject &mdash; if the object is uninitialized.
    * odbrInvalidInput &mdash; if the calculation was unsuccessful.
    * odbrOK &mdash; if the calculation was successful.
  */
  OdBrErrorStatus getBoundBlock(OdGeBoundBlock3d& block) const;

  // Validation
  OdBrErrorStatus setValidationLevel(const BrValidationLevel& level = *(BrValidationLevel*)NULL);
  OdBrErrorStatus getValidationLevel(BrValidationLevel& level) const;

  //BrEntityFlags
  OdUInt32 getFlags() const;

  OdBrErrorStatus getGsMarker(OdGsMarker& marker) const;

  bool brepChanged() const;

  OdBrErrorStatus set(OdBrBrepData* data);
  OdBrErrorStatus get(OdBrBrepData*& data) const;
/*
  // Geometric properties
  OdBrErrorStatus getMassProps(OdBrMassProps& massProps,
    const double& dDensity     = *(double*)NULL,
    const double& dTolRequired = *(double*)NULL,
    double&       dTolAchieved = *(double*)NULL) const;
  OdBrErrorStatus getVolume(double& dVolume,
    const double& dTolRequired = *(double*)NULL,
    double&       dTolAchieved = *(double*)NULL) const;
  OdBrErrorStatus getSurfaceArea(double& dArea,
    const double& dTolRequired = *(double*)NULL,
    double&       dTolAchieved = *(double*)NULL) const;
  OdBrErrorStatus getPerimeterLength(double& dLength,
    const double& dTolRequired = *(double*)NULL,
    double&       dTolAchieved = *(double*)NULL) const;
*/
  //DOM-IGNORE-BEGIN
  ODBR_TOOLKIT_EXPORT_STATIC static double dUnspecified;

protected:
  void *m_pImp;
  OdSharedPtr<OdDbStubPtrArray> m_pFSubentPath;
  bool m_bIsValidate; //The enum has only 2 values.

  OdBrEntity();
  OdBrEntity(const OdBrEntity& src);
  OdBrEntity& operator =(const OdBrEntity& src);

  friend class OdBrEntityInternals;
};

#include "../TD_PackPop.h"

#endif /* _INC_DDBRENTITY_3F819553013C_INCLUDED */

