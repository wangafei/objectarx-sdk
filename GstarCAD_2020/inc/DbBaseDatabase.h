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




#ifndef _ODDB_BASEDATABASE_INCLUDED_
#define _ODDB_BASEDATABASE_INCLUDED_


#include "RxObject.h"
#include "DbRootExport.h"
#include "OdFont.h"
#include "GiDefaultContext.h"
#include "Gs/Gs.h"
#include "Gi/GiLinetype.h"
#include "DbDate.h" // dgn dwf export
#include "OdUnitsFormatter.h"
#include "StringArray.h"

class OdDbBaseHostAppServices;
class OdGiAnnoScaleSet;

typedef OdRxObject OdDbBaseDatabase;

/** Description:

    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseViewTableIteratorPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseViewTableIteratorPE);

  virtual void start(const OdRxObject*,
    bool atBeginning = true, 
    bool skipErased = true) = 0;

  virtual bool done(const OdRxObject*) const = 0;

  virtual OdDbStub* item(const OdRxObject*) const = 0;

  virtual void step(const OdRxObject*,
    bool forward = true, 
    bool skipErased = true) = 0;

  virtual bool seek(const OdRxObject*,
    OdDbStub* objectId) = 0;
};
typedef OdSmartPtr<OdDbBaseViewTableIteratorPE> OdDbBaseViewTableIteratorPEPtr;

/** Description:
    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseViewTableRecordPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseViewTableRecordPE);
  virtual OdGePoint3d getTarget(const OdRxObject* Rec) = 0;
};
typedef OdSmartPtr<OdDbBaseViewTableRecordPE> OdDbBaseViewTableRecordPEPtr;

/** Description:
    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseViewTablePE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseViewTablePE); 
  virtual OdDbBaseViewTableRecordPEPtr getRecordByName(const OdRxObject* Tab, OdString name) = 0;
};
typedef OdSmartPtr<OdDbBaseViewTablePE> OdDbBaseViewTablePEPtr;

/** Description:
    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseViewportTableRecordPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseViewportTableRecordPE); 
  virtual OdGePoint3d getTarget(const OdRxObject* Rec) = 0;
};
typedef OdSmartPtr<OdDbBaseViewportTableRecordPE> OdDbBaseViewportTableRecordPEPtr;

/** Description:
    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes}
*/
class DBROOT_EXPORT OdDbBaseViewportTablePE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseViewportTablePE); 
  virtual OdDbBaseViewportTableRecordPEPtr getActiveViewport(const OdRxObject* Tab) = 0;
};
typedef OdSmartPtr<OdDbBaseViewportTablePE> OdDbBaseViewportTablePEPtr;

/** Description:
    This class is the base Protocol Extension class for database classes.

    Library:
    TD_DbRoot
    {group:OdDbRoot_Classes} 
*/
class DBROOT_EXPORT OdDbBaseDatabasePE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseDatabasePE);

  /** Description:
      Returns the OdDbBaseHostAppServices object associated with this *database* object.
  */
  virtual OdDbBaseHostAppServices* appServices(OdDbBaseDatabase* pDb) const = 0;

  /** Description:
      Returns the *name* of the file associated with this *database* object.
  */
  virtual OdString getFilename(OdDbBaseDatabase* pDb) const = 0;

  virtual void startTransaction(OdDbBaseDatabase* pDb) = 0;
  virtual void abortTransaction(OdDbBaseDatabase* pDb) = 0;

  virtual OdGiDefaultContextPtr createGiContext(OdDbBaseDatabase* pDb) const = 0;

  virtual void putNamedViewInfo(OdDbBaseDatabase* pDb, OdDbStub* layoutId, OdStringArray& names, OdGePoint3dArray& points) = 0;
  /** Description:
  Creates a TextIterator object for the specified data.

  Arguments:
  textString (I) Text string to be parsed.
  length (I) Length of string in bytes.
  raw (I) If and only if true, character sequences in the form of %%c will be treated as raw text.
  codePageId (I) Object ID of the Code Page of the text.
  pTextStyle (I) Pointer to the TextStyle object associated with the specified text.

  Remarks:
  Returns a SmartPointer to the new OdDbTextIterator object.
  */
  virtual OdBaseTextIteratorPtr createTextIterator(OdDbBaseDatabase* db, const OdChar* textString, int length, bool raw, const OdGiTextStyle* pTextStyle) const = 0;
  
  // setup Gs views in the device, according to the active database layout data
  virtual OdGsDevicePtr setupActiveLayoutViews(OdGsDevice* pDevice, OdGiDefaultContext* pGiCtx) = 0;

  // setup next view in the device
  virtual OdGsDevicePtr setupLayoutView(OdGsDevice* /*pDevice*/, OdGiDefaultContext* /*pDgnContext*/, OdDbStub* /*objectId*/) = 0;
  
  // get next view according to the active layout
  virtual OdDbStub* getNextViewForActiveLayout(OdGiDefaultContext* /*pDgnContext*/, OdDbStub* /*objectId*/) = 0;
  
  // setup Gs device to display current layout using plot settings stored in it (paper rotation, scale etc.)
  // returns visible rectangle (measured in device units)
  virtual void applyLayoutSettings(OdGsDCRect& clipBox, OdGsDevice* pDevice, OdDbBaseDatabase* db) = 0;
  
  // setup Gs device to draw current layout zoomed to extents
  // warning: this function may throw exception, if overall viewport is not found
  // outputRect is desired printable area (in device units)
  virtual void zoomToExtents(const OdGsDCRect& outputRect, OdGsDevice* pDevice, OdDbBaseDatabase* db, bool exactExtents = false, OdDbStub* objectId = NULL) = 0;
  
  virtual void loadPlotstyleTableForActiveLayout(OdGiDefaultContext* pDwgContext, OdDbBaseDatabase* db) = 0;

  virtual OdRxIteratorPtr layers(OdDbBaseDatabase* db) const = 0;

  // Layout here is an abstraction that corresponds to "sheet" in sheet set manager, 
  //   "page" in PDF and DWF, "layout"+"block table record" in DWG
  virtual OdRxObjectPtr currentLayout(OdDbBaseDatabase* db) = 0;

  virtual void setCurrentLayout(OdDbBaseDatabase* db, const OdString& name) = 0;

  virtual OdRxIteratorPtr layouts(OdDbBaseDatabase* db) const = 0;

  virtual OdRxObjectPtr getLayout(OdDbBaseDatabase* db, const OdString& name) = 0;

  virtual OdRxObjectPtr findLayoutByViewport(OdDbBaseDatabase* db, OdDbStub* pViewportId) = 0;

  virtual OdDbStub* findLayoutNamed(OdDbBaseDatabase* db, const OdString& name) = 0; // dgn dwf export
  virtual OdRxObjectPtr getFirstLayout(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdTimeStamp getCreationTime(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdTimeStamp getUpdateTime(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdString getFingerPrintGuid(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdString getVersionGuid(OdDbBaseDatabase* db) = 0; // dgn dwf export
//  virtual OdDbBaseViewTableIteratorPEPtr getViewTableIterator(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual int getUnits(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdUnitsFormatter* baseFormatter(OdDbBaseDatabase* db) = 0; // dgn dwg common formatter base class
  //virtual OdDbBaseViewTablePEPtr getViewTable(OdDbBaseDatabase* db) = 0; // dgn dwf export
  virtual OdDbBaseViewportTablePEPtr getViewportTable(OdDbBaseDatabase* db) = 0; // dgn dwf export
  //virtual OdString getLayoutName(OdDbStub* elementId) = 0; // dgn dwf export
  //virtual OdDbBaseLayoutIteratorPEPtr newLayoutIteratorPE(OdDbBaseDatabasePE* db) = 0; // dgn dwf export
  virtual int getMeasurement(OdDbBaseDatabase* db) = 0;

  virtual bool getLineTypeById( OdDbBaseDatabase* db, OdDbStub* pLTypeId, OdGiLinetype& LType ) = 0;

  virtual bool getTextStyleById( OdDbBaseDatabase* db, OdDbStub* idStyle, OdGiTextStyle& shapeInfo ) = 0;   
  virtual OdRxObjectPtr createObjectById( OdDbStub* Id) = 0;
  virtual OdDbStub *getObject(OdDbBaseDatabase* db, OdUInt64 handle) = 0;
  virtual OdDbHandle getHandle(OdDbStub* id);
  virtual OdDbBaseDatabase* getDatabase(OdDbStub *id);
  virtual OdDbStub *getOwner(OdDbStub *id);

  virtual OdCodePageId getCodePage(OdDbBaseDatabase* db) = 0;

  virtual OdDbStub* getModelBlockId(OdDbBaseDatabase* pDb) = 0;
  virtual OdDbStub* getPaperBlockId(OdDbBaseDatabase* pDb) = 0;
  virtual OdDbStub* currentLayoutId(OdDbBaseDatabase* pDb) = 0;
  virtual OdDbStub* xrefBlockId(OdDbBaseDatabase* pDb) = 0;

  virtual void setMultiThreadedRender(OdDbBaseDatabase* pDb, bool bOn) = 0;

  virtual bool isAProxy(OdRxObject* pDrw) = 0;
  virtual OdRxObjectPtr openObject(OdDbStub* pId) = 0;
 // virtual bool getAnnoScaleSet(OdDbStub* drawableId, OdGiAnnoScaleSet& res) = 0;
  virtual OdDbStub *getCurrentLongTransation(const OdDbBaseDatabase *pDb) = 0;

  class DatabaseUnloadReactor
  {
    public:
      virtual ~DatabaseUnloadReactor() { }
      virtual void goodbye(const OdDbBaseDatabase* pDb) = 0;
  };
  virtual OdRxObjectPtr addDatabaseUnloadReactor(OdDbBaseDatabase* pDb, OdRxObject *pPrevReactor, DatabaseUnloadReactor *pReactorRedirect) = 0;
  virtual void removeDatabaseUnloadReactor(OdDbBaseDatabase* pDb, OdRxObject *pReactor) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBaseDatabasePE object pointers.
*/
typedef OdSmartPtr<OdDbBaseDatabasePE> OdDbBaseDatabasePEPtr;



/** Description:
  This class is the protocol extension to be used as a layer abstraction, 
  independent of the underlying database (OdDbDatabase or OdDgDatabase).

  Library:
  TD_DbRoot

  {group:OdDbRoot_Classes} 
*/
class DBROOT_EXPORT OdDbBaseLayerPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseLayerPE);
  virtual OdString name(const OdRxObject*) const = 0;
  /** Description:
    Returns true if and only if this Layer is off.
    
    Arguments:    
    obj (I) Layer object
  */
  virtual bool isOff(const OdRxObject* obj) const = 0;
  /** Description:
    Returns true if and only if this Layer is frozen.
    
    Arguments:    
    obj (I) Layer object
  */
  virtual bool isFrozen(const OdRxObject* obj) const = 0;
  /** Description:
    Sets the on / *off* status of this Layer

    Arguments:    
    obj (I) Layer object
    off (I) True for off, false for on.
  */
  virtual void setIsOff(OdRxObject* obj, bool off) const = 0;
  /** Description:
    Sets the *frozen* status of this Layer.

    Arguments:
    obj (I) Layer object
    frozen (I) True to freeze, false to thaw.
  */
  virtual void setIsFrozen(OdRxObject* obj, bool frozen) const = 0;

  /** Description:
  Return true if function set line type description of this Layer.

  Arguments:
  obj (I) Layer object
  LType (O) Description of layer line type.
  */
  virtual bool getLineTypeById( OdRxObject* obj, OdGiLinetype& LType ) const = 0;
};

typedef OdSmartPtr<OdDbBaseLayerPE> OdDbBaseLayerPEPtr;


/** Description:
  This class is the protocol extension to be used as a layout abstraction, 
  independent of the underlying database (OdDbDatabase or OdDgDatabase).

  Library:
  TD_DbRoot

  {group:OdDbRoot_Classes} 
*/
class DBROOT_EXPORT OdDbBaseLayoutPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbBaseLayoutPE);
  enum PlotRotation
  {
    k0degrees       = 0,   // No rotation
    k90degrees      = 1,   // 90?CCW
    k180degrees     = 2,   // Inverted
    k270degrees     = 3    // 90?CW
  };
  virtual OdString name(const OdRxObject*) = 0;
  virtual bool isModelLayout(const OdRxObject*) = 0;
  virtual bool printLineweights(const OdRxObject*) = 0;
  virtual bool showPlotStyles(const OdRxObject*) = 0;
  virtual OdString paperName(const OdRxObject*) = 0;
  virtual void getPaperSize(const OdRxObject*, double& paperWidth, double& paperHeight) const = 0;
  virtual PlotRotation plotRotation(const OdRxObject*) = 0;
  virtual double getTopMargin(const OdRxObject*) = 0;
  virtual double getRightMargin(const OdRxObject*) = 0;
  virtual double getBottomMargin(const OdRxObject*) = 0;
  virtual double getLeftMargin(const OdRxObject*) = 0;
  virtual OdDbStub* getId(const OdRxObject*) = 0;
  virtual bool isOverallVPortErased(const OdRxObject*) = 0;
  virtual OdResult getGeomExtents(const OdRxObject*,OdGeExtents3d& ext) = 0;

  // methods inherited by OdDbLayoutImpl class // dgn dwf export
  virtual bool useStandardScale(const OdRxObject*) = 0;
  virtual void getStdScale(const OdRxObject*, double& scale) = 0;
  virtual void getCustomPrintScale(const OdRxObject*, double& numerator, double& denominator) = 0;
  virtual int plotType(const OdRxObject*) = 0;
  virtual OdString getPlotViewName(const OdRxObject*) = 0;
  virtual void getPlotWindowArea(const OdRxObject*, double& xmin, double& ymin, double& xmax, double& ymax) = 0;
  virtual void getPlotOrigin(const OdRxObject*, double& x, double& y) = 0;
  virtual void getPlotPaperSize(const OdRxObject*, double& paperWidth, double& paperHeight) = 0;
  virtual int plotPaperUnits(const OdRxObject*) = 0;

  // for Gs
  virtual OdDbStub* getBlockId(const OdRxObject*) const = 0;
  virtual bool scalePSLinetypes(const OdRxObject*) const = 0;
  virtual bool getApproxExtents(const OdRxObject*, OdGePoint3d& extMin, OdGePoint3d& extMax) const = 0;
};

typedef OdSmartPtr<OdDbBaseLayoutPE> OdDbBaseLayoutPEPtr;

#endif // _ODDB_BASEDATABASE_INCLUDED_

