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




#ifndef __DBGSMANAGER_H_INCLUDED_
#define __DBGSMANAGER_H_INCLUDED_

class OdDbObjectId;
class OdGiContextForDbDatabase;

#include "Gs/Gs.h"


#include "TD_PackPush.h"

/** Description:
    Library: TD_Db
    {group:OdGs_Classes} 
*/
class TOOLKIT_EXPORT OdGsLayoutHelper : public OdGsDevice
{
public:
  ODRX_DECLARE_MEMBERS(OdGsLayoutHelper);
  /** Description:
    Returns the Layout object associated with this LayoutHelper object.
  */
  virtual OdDbObjectId layoutId() const = 0;
  /** Description:
    Returns the active GsView object of the Layout object associated with this LayoutHelper object.
  */
  virtual OdGsViewPtr activeView() const = 0;
  /** Description:
    Sets the active GsView object of the Layout object associated with this LayoutHelper object.
    Arguments:
    pView (I) Pointer to the GsView.
  */
  virtual void makeViewActive(OdGsView* pView) = 0;
  /** Description:
    Return the OdGsModel object associated with this layout helper.
  */
  virtual OdGsModel* gsModel() = 0;

  /** Description:
    Returns the underlying OdGsDevice object associated with this LayoutHelper object.
  */
  virtual OdGsDevicePtr underlyingDevice() const = 0;

  /** Description:
    Sets the active viewport
    Arguments:
    at (I) Pick point in device coordinates.
  */
  virtual bool setActiveViewport(const OdGePoint2d& screenPt) = 0;

  /** Description:
    Arguments:
    id (I) ObjectId of viewport which will be made active.
  */
  virtual bool setActiveViewport(const OdDbObjectId& id) = 0;

  virtual void sleep();
  virtual void wakeup();
};

typedef OdSmartPtr<OdGsLayoutHelper> OdGsLayoutHelperPtr;


/** Description:
    Library: TD_Db
    {group:OdGs_Classes} 
*/
class TOOLKIT_EXPORT OdGsPaperLayoutHelper : public OdGsLayoutHelper
{
public:
  ODRX_DECLARE_MEMBERS(OdGsPaperLayoutHelper);

  virtual OdGsViewPtr helperOverallView() const = 0;
  virtual OdGsViewPtr overallView() const = 0;
  virtual void makeViewOverall(OdGsView* pView) = 0;
  virtual void initGsView(OdGsView* pView, const OdDbViewport* pVp) = 0;

  virtual OdGsViewPtr addViewport(const OdDbViewport* pVp);
  virtual OdGsViewPtr insertViewport(int viewIndex, const OdDbViewport* pVp);

  static OdGsLayoutHelperPtr create(OdGsDevice* pDevice, const OdDbObjectId& layoutId);
};

typedef OdSmartPtr<OdGsPaperLayoutHelper> OdGsPaperLayoutHelperPtr;


/** Description:

    Library: TD_Db
    {group:OdGs_Classes} 
*/
class TOOLKIT_EXPORT OdGsModelLayoutHelper : public OdGsLayoutHelper
{
public:
  ODRX_DECLARE_MEMBERS(OdGsModelLayoutHelper);

  static OdGsLayoutHelperPtr create(OdGsDevice* pDevice, const OdDbObjectId& layoutId);
};

typedef OdSmartPtr<OdGsModelLayoutHelper> OdGsModelLayoutHelperPtr;


/** Description:

    {group:TD_Namespaces}
*/
namespace OdDbGsManager
{
  /** Description:
      Populates OdGsDevice-derived object with OdGsViews-derived objects.
      Returns OdGsDevice-derived wrapper that handles some OdGsDevice's calls.
  */
  TOOLKIT_EXPORT OdGsLayoutHelperPtr setupActiveLayoutViews(OdGsDevice* pDevice,
    OdGiContextForDbDatabase* pGiCtx);

  /** Description:
      Populates OdGsDevice-derived object with OdGsViews-derived objects.
      Returns OdGsDevice-derived wrapper that handles some OdGsDevice's calls.
  */
  TOOLKIT_EXPORT OdGsLayoutHelperPtr setupLayoutViews(OdDbObjectId layoutId, OdGsDevice* pDevice, 
    OdGiContextForDbDatabase* pGiCtx);
  TOOLKIT_EXPORT OdGsLayoutHelperPtr mc_setupModelViews(OdGsDevice* pDevice, OdGiContextForDbDatabase* pGiCtx,OdArray<OdDbObjectId>&vObjs);
  TOOLKIT_EXPORT OdGsLayoutHelperPtr mc_setupModelViews(OdGsDevice* pDevice, OdGiContextForDbDatabase* pGiCtx);
  TOOLKIT_EXPORT OdGsLayoutHelperPtr mc_setupPaperViews(OdGsDevice* pDevice, 
	  OdDbObjectId layoutId, 
	  OdGiContextForDbDatabase* pGiCtx);
  TOOLKIT_EXPORT OdGsLayoutHelperPtr mc_setupPaperViewViewport(OdGsDevice* pDevice, 
	  OdDbViewport * pVp, 
	  OdGiContextForDbDatabase* pGiCtx);

}

#include "TD_PackPop.h"

#endif // __DBGSMANAGER_H_INCLUDED_

