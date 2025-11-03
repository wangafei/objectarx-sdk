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

#ifndef _DBSCALE_INCLUDED_
#define _DBSCALE_INCLUDED_

#include "DbObject.h"

/** Description:
    This class is a database resident and represents an annotation scale.
  
    Remarks:
    OdDbScale objects are stored in the ACAD_SCALELIST dictionary.
	This class is intended for application developers only, not TX developers.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbScale : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbScale);
  OdDbScale();
  class OdString scaleName() const;
  double paperUnits() const;
  double drawingUnits() const;
  bool isTemporaryScale() const;
  /** Description:
    Returns the unit scale (paper units or drawing units equal to 1) for viewports 
	that have no annotation scale, for example, viewports from legacy files.
  */
  bool isUnitScale() const;
  double scale() const;

  void setScaleName(const OdString&);
  void setPaperUnits(double);
  void setDrawingUnits(double);
  void setIsTemporaryScale(bool);
  /** Description:
    Sets the unit scale (paper units or drawing units equal to 1) for viewports 
	that have no annotation scale, for example, viewports from legacy files.
  */
  void setIsUnitScale(bool);
  /** Description:
    For internal use only.
  */
  void getXRefMangledName(OdString, OdString&, OdDbDatabase *);
  /** Description:
    For internal use only.
  */
  static bool nameExists(const OdString&,OdString*,OdDbDatabase *);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual void appendToOwner(OdDbIdPair& idPair, OdDbObject* pOwnerObject, OdDbIdMapping& ownerIdMap);
};

typedef OdSmartPtr<OdDbScale> OdDbScalePtr;


#endif //_DBSCALE_INCLUDED_
