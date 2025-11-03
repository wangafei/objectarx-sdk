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



#ifndef OD_AVESCENE_H
#define OD_AVESCENE_H

#include "../TD_PackPush.h"

#include "../Ve/AveDefs.h"
#include "../RxObject.h"
#include "../DbObjectId.h"
#include "../DbEntity.h"

class OdAveSceneImpl;
class OdAveScene;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdAveScene object pointers.
*/
typedef OdSmartPtr<OdAveScene> OdAveScenePtr;

/** Description:
    This class represents AVE Scene properties.

    Remarks:
    Each AVE Scenes consist of a *view* and zero or more *lights*.
    
    Library: TD_Ave
    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveScene : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdAveScene);

  /** Description:
    Creates a Scene object from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
    
    Remarks:
    The new Scene object is attached to the specified block reference.
     
    Returns a SmartPointer to the new Scene object.
  */
  static OdAveScenePtr getScene(const OdDbObjectId& blockRefId);
  /** Description:
    Returns the Scene *name* from the specified OdDbBlockReference.
    
    Arguments:
    blockRefId (I) Object ID of the block reference.
    name (O) Receives the Scene *name*.
  */
  static void getSceneName(const OdDbObjectId& blockRefId, OdString& name);

  /** Description:
    Saves the Scene properties to the OdDbBlockReference to which this Scene object is attached.

    Arguments:
    pDb (I) Pointer to the *database*.
      
    Remarks:
    If pDb is null, the *database* containing this Light object is used.
  */
  OdResult writeScene(OdDbDatabase* pDb = 0);

  /** Description:
    Returns the *name* of this Scene object.
  */
  OdString name() const;
  /** Description:
    Sets the *name* of this Scene object.
    Arguments:
    name (I) Name.
    Remarks:
    Names are truncated to 8 characters.
  */
  void setName(const OdString& name);

  /** Description:
    Returns the OdDbViewTableRecord associated with this Scene object.
  */
  OdDbObjectId view() const;
  /** Description:
    Sets the OdDbViewTableRecord associated with this Scene object.
    Arguments:
    viewId (I) Object ID of the View Table Record.
  */
  void setView(const OdDbObjectId& viewId);

  /** Description:
    Returns the array of *lights* associated with this Scene object.
    Arguments:
    blockRefIds (O) Receives the array of object IDs of the block references associated with the *lights*.
  */
  void lights(OdDbObjectIdArray& blockRefIds) const;
  /** Description:
    Sets the array of *lights* associated with this Scene object.
    Arguments:
    blockRefIds (I) Array of the object IDs of the block references associated with the *lights*.
  */
  void setLights(const OdDbObjectIdArray& blockRefIds);
  /** Description:
    Adds the specified light to the array of *lights* associated with this Scene object.
    Arguments:
    blockRefId (I) Object ID of the block reference associated with the light.
  */
  void addLight(const OdDbObjectId& blockRefId);

protected:
  OdAveScene();
  OdAveScene(OdAveSceneImpl* pImpl);
  
  OdAveSceneImpl* m_pImpl;
};

/** Description:
  Returns an Iterator object that can be 
  used to traverse the OdAveScene objects in the specified *database*.
  
  Arguments:
  pDb (I) Pointer to the *database*.
*/
AVE_EXPORT OdRxIteratorPtr oddbGetScenes(OdDbDatabase* pDb);

#include "../TD_PackPop.h"

#endif // OD_AVESCENE_H
