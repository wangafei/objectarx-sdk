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




#ifndef _OD_DB_SHAPE_
#define _OD_DB_SHAPE_

#include "TD_PackPush.h"

#include "DbEntity.h"


/*
    This class represents Shape entities in an OdDbDatabase instance.
    
    Remarks:
    A Shape entity is a single character of an SHX font. It is specified by name() and/or shapeNumber() and styleId(). 
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbShape : public OdDbEntity
{
public:


  ODDB_DECLARE_MEMBERS(OdDbShape);

  OdDbShape();
  OdDbShape(const OdGePoint3d& position,
      double size,
      const  OdChar * name,
      double rotation    = 0,
      double widthFactor = 0);
  OdDbShape(const OdGePoint3d&  position,
      double size,
      double rotation    = 0,
      double widthFactor = 0);
  ~OdDbShape();
  
  /** Description:
    Returns the *position* of this entity (WCS equivalent of DXF 10).
  */
  OdGePoint3d position() const;
  
  /** Description:
    Sets the *position* of this entity (WCS equivalent of DXF 10).

    Arguments:
    position (I) Position.
  */
   OdResult setPosition(
    const OdGePoint3d& position);

  /** Description:
    Returns the *size* of this Shape entity (DXF 40).
  */
  double size() const;

  /** Description:
    Sets the *size* of this Shape entity (DXF 40).
    Arguments:
    size (I) Shape *size*.
  */
   OdResult setSize(
    double size);

  /** Description:
    Returns the *name* of this Shape entity (DXF 2).
    Remarks:
    The *name* is not part of a Shape entity, but is derived from shapeNumber() and styleId().
  */
  OdString name(ODSYSDEF) const;
  const OdString& nameConst() const;
#ifdef ODARXDEF
  OdChar*  name() const;
#endif
  /** Description:
    Sets the *name* of this Shape entity (DXF 2).
    
    Remarks:
    The *name* is not part of a Shape entity, but is derived from shapeNumber() and shapeIndex().
    It is more efficient to use setShapeNumber() and setStyleId() directly.
  */
  OdResult setName(
    const OdString& name);
  OdResult setName(const OdChar *name) { return setName(OdString(name));}

  /** Description:
    Returns the *rotation* angle of this Shape entity (DXF 50).
    Note:
    All angles are expressed in radians.
 */
  double rotation() const;
  
  /** Description:
    Sets the *rotation* angle of this Shape entity (DXF 50).
    Arguments:
    rotation (I) Rotation angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult setRotation(
    double rotation);

  /** Description:
    Returns the relative X scale factor (width factor) for this Shape entity (DXF 41).
  */
  double widthFactor() const;

  /** Description:
    Sets the relative X scale factor (width factor) for this Shape entity (DXF 41).
    
    Arguments:
    widthFactor (I) Width factor.
  */
  OdResult setWidthFactor(
    double widthFactor);

 /** Description:
    Returns the *oblique* angle of this Shape entity (DXF 51).

    Remarks:
    oblique() has a range of ?.48335 radians (?5?.
    
    Oblique angles are measured clockwise from the vertical.

    Note:
    All angles are expressed in radians.  
  */
  double oblique() const;
  
  /** Description:
    Sets the *oblique* angle of this Shape entity (DXF 51).
    Arguments:
    oblique (I) Oblique angle.
    
    Remarks:
    oblique() has a range of ?.48335 radians (?5?.
    
    Oblique angles are measured clockwise from the vertical.
     
    Note:
    All angles are expressed in radians.  
  */
  OdResult setOblique(
    double oblique);

  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;
  
  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  OdResult setThickness(
    double thickness);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  OdBool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  /** Description:
    Returns the shape number of this Shape entity.
    Remarks:
    A Shape entity is a single character of an SHX font. 
    This function returns the code of that character.  
  */
  OdInt16 shapeNumber() const;

  /** Description:
    Sets the shape number of this Shape entity.
    Remarks:
    A Shape entity is a single character of an SHX font. 
    This function sets the code of that character.
    Arguments:
    shapeNumber (I) Shape number.  
  */
  OdResult setShapeNumber(
    OdInt16 shapeNumber);

  /** Description:
    Returns the Object ID of the OdDbTextStyleTableRecord containing
    the SHX font file for this Shape entity.

    Remarks:
    A Shape entity is a single character of an SHX font. This function
    returns a reference to that font.
  */
  OdDbObjectId styleId() const;

  /** Description:
    Sets the Object ID of the OdDbTextStyleTableRecord containing
    the SHX font file for this Shape entity.

    Remarks:
    A Shape entity is a single character of an SHX font. This function
    sets a reference to that font.
    Arguments:
    styleId (I) Style Object ID.  
  */
  OdResult setStyleId(
    OdDbObjectId styleId);

  OdDbObjectId  shapeIndex() const 
  { return this->styleId(); }
  OdResult		setShapeIndex(OdDbObjectId id)
  { return this->setStyleId(id); }
  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbShape object pointers.
*/
typedef OdSmartPtr<OdDbShape> OdDbShapePtr;

#include "TD_PackPop.h"

#endif

