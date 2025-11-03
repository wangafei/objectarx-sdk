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




#ifndef OD_RTEXT_H
#define OD_RTEXT_H

#include "TD_PackPush.h"

#include "DbEntity.h"
class OdDbEntityImpl;

/** Description:
    This class represents Reactive text (RText) entities in an OdDbDatabase instance.
    Library: TD_Db
    
    Remarks:
    RText entities can display either the contents of an external text file or the evaluation of a DIESEL expression. 

    {group:Other_Classes}
*/
class TOOLKIT_EXPORT RText : public OdDbEntity
{
public:
  ODRX_DECLARE_MEMBERS(RText);
  
  /** Description:
    Returns the WCS *normal* to the plane of this *RText* entity.
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this *RText* entity.
    Arguments:
    normal (I) Normal.
  */
  void         setNormal(const OdGeVector3d &normal);

  /** Description:
    Returns the WCS insertion *point* of this *RText* entity.
  */
  OdGePoint3d getPoint() const;

  /** Description:
    Sets the WCS insertion *point* of this *RText* entity.

    Arguments:
    point (I) Insertion *point*.
  */
  void        setPoint(const OdGePoint3d &point);

  /** Description:
    Returns the rotation angle of this *RText* entity.
    Note:
    All angles are expressed in radians.
  */
  double getRotAngle() const;
  /** Description:
    Sets the rotation angle of this *RText* entity.
    Arguments:
    rotAngle (I) Rotation angle.
    Note:
    All angles are expressed in radians.
  */
  void   setRotAngle(double rotAngle);

  /** Description:
    Returns the *height* of this *RText* entity.
  */
  double getHeight() const;
  /** Description:
    Sets the *height* of this *RText* entity.
    Arguments:
    height (I) Height.
  */
  void   setHeight(double height);

  /** Description:
    Returns true if and only if the *RText* entity is to be treated an as DIESEL expression.
  */
  bool isStringExpression() const;
  /** Description:
    Controls the treatment of this *RText* entity as an DIESEL expression.
    Arguments:
    isExpression (I) Controls treatment as a DIESAL expression.
  */
  void setToExpression(bool isExpression);

  /** Description:
    Returns true if and only if MText inline sequences are evaluated for this *RText* entity.
  */
  bool enabledMTextSequences() const;
  /** Description:
    Controls the evaluation of MText inline sequences for this *RText* entity.
    Arguments:
    enable (I) Enables MText sequences.
  */
  void enableMTextSequences(bool enable);
  /** Description:
    Returns a copy of the string contents of this *RText* entity.
    Remarks:
    If !isStringExpression(), the string contents specify the name of the file to be displayed.
  */
  const OdChar * getStringContents() const;
  /** Description:
    Sets the string contents of this *RText* entity.
    Arguments:
    stringContents (I) String contents.
    Remarks:
    If !isStringExpression(), the string contents specify the name of the file to be displayed.
  */
  void     setStringContents(const OdChar *stringContents);

  /** Description:
    Returns the object ID of the TextStyle of this *RText* entity.
    
    Remarks:
    If 
  */
  OdDbObjectId textStyleId() const;
  /** Description:
    Returns the *name* of the TextStyle of this *RText* entity.
  */
  OdString textStyleName() const;
  /** Description:
    Sets the TextStyle of this *RText* entity.
    Arguments:
    textStyleId (I) Object ID of TextStyle.
    name (I) Name of TextStyle.
  */
  void setTextStyle(OdDbObjectId textStyleId);
  void setTextStyle(const OdChar * name);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;
  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;

  OdResult subClose();

  RText();
protected:
  RText(OdDbEntityImpl* pImpl);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for RText object pointers.
*/
typedef OdSmartPtr<RText> OdRTextPtr;

#include "TD_PackPop.h"

#endif  // OD_RTEXT_H

