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




#ifndef _ODDBLAYOUTMANAGER_INCLUDED_
#define _ODDBLAYOUTMANAGER_INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "DbDatabase.h"
#include "DbLayout.h"

class OdDbLayoutManagerImpl;

/** Description:
    This class is the base class for custom classes that receive notification
    of OdDbLayout events.
    
    Remarks:
    The default implementations of all methods in this class do nothing but return.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayoutManagerReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLayoutManagerReactor);
  /** Description:
    Notification function called whenever a layout has been added to an OdDbDatabase.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of layout.
    
 	  Remarks:
	  This function is called after the operation.
  */  
  virtual void layoutCreated(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);
    
  /** Description:
    Notification function called whenever a layout is about to be removed from an OdDbDatabase.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of layout.
    
 	  Remarks:
	  This function is called before the operation.
  */
  virtual void layoutToBeRemoved(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);

  /** Description:
    Notification function called whenever a layout has been removed from an OdDbDatabase.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called before the operation.
  */
  virtual void layoutRemoved(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);
    
  /** Description:
    Notification function called whenever the removal of a layout has been terminated.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called before the operation.
  */
  virtual void abortLayoutRemoved(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);

  /** Description:
    Notification function called whenever a layout is about to be copied.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called before the operation.
  */
  virtual void layoutToBeCopied(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);
    
  /** Description:
    Notification function called whenever a layout has been copied.
    
    Arguments:
    oldLayoutName (I) Old layout name.
    oldLayoutId (I) Object ID of the old layout.
    newLayoutName (I) New layout name.
    newLayoutId (I) Object ID of the new layout.
    
 	  Remarks:
	  This function is after the operation.
  */
  virtual void layoutCopied(
    const OdChar* oldLayoutName, 
    const OdDbObjectId& oldLayoutId,
    const OdChar* newLayoutName, 
    const OdDbObjectId& newLayoutId);

  /** Description:
    Notification function called whenever the copying of a layout has been terminated.
    
    Arguments:
    layoutName (I) Layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called after the operation.
  */
  virtual void abortLayoutCopied(
    const OdChar* layoutName, 
    const OdDbObjectId& layoutId);

  /** Description:
    Notification function called whenever a layout is about to be renamed.
    
    Arguments:
    oldLayoutName (I) Old layout name.
    newLayoutName (I) New layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called before the operation.
  */
  virtual void layoutToBeRenamed(
    const OdChar* oldLayoutName,
    const OdChar* newLayoutName, 
    const OdDbObjectId& layoutId);

  /** Description:
    Notification function called whenever a layout has been renamed.
    
    Arguments:
    oldLayoutName (I) Old layout name.
    newLayoutName (I) New layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called after the operation.
  */
  virtual void layoutRenamed(
    const OdChar* oldLayoutName,
    const OdChar* newLayoutName, 
    const OdDbObjectId& layoutId);
    
  /** Description:
    Notification function called whenever the renaming of a layout has been terminated.
    
    Arguments:
    oldLayoutName (I) Old layout name.
    newLayoutName (I) New layout name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called after the operation.
  */
  virtual void abortLayoutRename(
    const OdChar* oldLayoutName,
    const OdChar* newLayoutName, 
    const OdDbObjectId& layoutId);
    
  /** Description:
    Notification function called whenever the active layout has changed.
    
    Arguments:
    newLayoutName (I) New layout name.
    newLayoutId (I) Object ID of the new layout.
    
 	  Remarks:
	  This function is called after the operation.
  */
  virtual void layoutSwitched(
    const OdChar* newLayoutName, 
    const OdDbObjectId& newLayoutId);
    
  /** Description:
    Notification function called whenever the plot style table associated with a layout has changed.
    
    Arguments:
    newTableName (I) New PlotStyleTable name.
    layoutId (I) Object ID of the layout.
    
 	  Remarks:
	  This function is called after the operation.
  */
  virtual void plotStyleTableChanged(
    const OdChar* newTableName, 
    const OdDbObjectId& layoutId);

  //Gcad(Add)
  virtual void layoutsReordered();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLayoutManagerReactor object pointers. 
*/
typedef OdSmartPtr<OdDbLayoutManagerReactor> OdDbLayoutManagerReactorPtr;

/** Description:
    This class modifies and accesses Layout objects in an OdDbDatabase instance.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLayoutManager : public OdRxObject  
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLayoutManager);

  OdDbLayoutManager();
  virtual ~OdDbLayoutManager();

/*/Gcad(Add)
  virtual void setCurrentLayout(OdDbDatabase* pDb, const OdDbObjectId& layoutId);
  virtual OdString findActiveLayout(const OdDbDatabase* pDb, bool allowModel) const;
  virtual OdDbObjectId getActiveLayoutBTRId(const OdDbDatabase* pDb) const;
  virtual OdDbObjectId findLayoutNamed(const OdDbDatabase* pDb, const OdString& name) const;
  virtual void deleteLayout(OdDbDatabase* pDb, const OdString& delname);
  virtual OdDbObjectId createLayout(OdDbDatabase* pDb, const OdString& newname, OdDbObjectId* pBlockTableRecId = 0);
  virtual void renameLayout(OdDbDatabase* pDb, const OdString& oldname, const OdString& newname);
  virtual OdDbObjectId cloneLayout(const OdDbLayout* pLayout, const OdString& newname, int newTabOrder = 0);
  virtual OdDbObjectId getNonRectVPIdFromClipId(const OdDbObjectId& clipId) const;
  virtual bool isVpnumClipped(const OdDbDatabase* pDb, int index) const;
  virtual int countLayouts(const OdDbDatabase* pDb) const;
/*/
  virtual OdResult setCurrentLayout(const OdChar * newname,OdDbDatabase* pDb = NULL);
  virtual OdResult setCurrentLayoutId(OdDbObjectId layoutId);

  virtual const OdChar * findActiveLayout(bool allowModel,const OdDbDatabase* pDb = NULL);

  virtual OdDbObjectId getActiveLayoutBTRId(const OdDbDatabase* pDb = NULL);

  virtual OdDbLayout * findLayoutNamed(const OdChar * name, bool leaveRecordOpen = false,const OdDbDatabase* pDb = NULL);

  virtual OdResult copyLayout(const OdChar * copyname, const OdChar * newname, OdDbDatabase* pDb = NULL);

  virtual OdResult deleteLayout(const OdChar * delname, OdDbDatabase* pDb = NULL);

  virtual OdResult createLayout(const OdChar *newname,
							   OdDbObjectId& layoutId, 
							   OdDbObjectId& blockTableRecId, 
							   OdDbDatabase* pDatabase = NULL);

  virtual OdResult renameLayout(const OdChar * oldname, 
							   const OdChar * newname, OdDbDatabase* pDb = NULL);

  virtual OdResult cloneLayout(OdDbLayout* pLBTR, 
							   const OdChar * newname, 
							   int newTabOrder = 0,
                 OdDbDatabase* pDb = NULL);

  virtual OdDbObjectId  getNonRectVPIdFromClipId (OdDbObjectId clipId);

  virtual bool  isVpnumClipped(int index,const OdDbDatabase* pDb = NULL);

  virtual int   countLayouts(OdDbDatabase *useDb = NULL);
//*/

  virtual void addReactor(OdDbLayoutManagerReactor * newObj);
  virtual void removeReactor(OdDbLayoutManagerReactor * delObj);
private:
  friend class OdDbLayoutManagerImpl;
protected:
  OdDbLayoutManager(OdDbLayoutManagerImpl* pImpl);
  OdDbLayoutManagerImpl* m_pImpl;
};

typedef OdSmartPtr<OdDbLayoutManager> OdDbLayoutManagerPtr;

#include "TD_PackPop.h"

#endif //_ODDBLAYOUTMANAGER_INCLUDED_
