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




#ifndef   _ODED_H_INCLUDED_
#define   _ODED_H_INCLUDED_

#include "TD_PackPush.h"

#include "RxNames.h"
#include "RxEvent.h"
#include "OdArrayPreDef.h"
#include "DbObjectId.h"
#include "IdArrays.h"

#define ODED_EDITOR_OBJ OD_T("OdEditor")

class OdDbDatabase;

enum xrefSubcommandActivities
{    
    kStart = 0,
    kStartItem = 2,
    kEndItem = 3,
    kEnd = 4,
    kWillAbort = 5,
    kAborted = 6,
    kStartXBindBlock = 7,
    kStartXBindSymbol = 8
};

enum undoSubcommandActivities
{
    kNone = 0,
    kOne = 1,
    kAll = 2
};

/** Description:
    This class is the base class for custom classes that receive notification
    of OdEditor events.

    Note:
    The default implementations of all methods in this class do nothing but return.
    
    Library:
    TD_Db
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdEditorReactor : public OdRxEventReactor 
{ 
public:
  ODRX_DECLARE_MEMBERS(OdEditorReactor);
  OdEditorReactor() : mVeto(0) {}

  virtual void lispWillStart   (const OdChar* firstLine);
  virtual void lispEnded       ();
  virtual void lispCancelled   ();
  /** Description:
    Notification function called whenever a .dwg file is about to be opened.
    
    Arguments:
    filename (I) Name of the .dwg file.
    
    Remarks:
    This function is called before the operation.
    
    See Also:
    o  dwgFileOpened
    o  endDwgOpen
  */
  virtual void beginDwgOpen(
    OdChar * filename);
    
  /** Description:
    Notification function called whenever a .dwg file has been opened.
    
    Arguments:
    filename (I) Name of the .dwg file.
    
    Remarks:
    This function is called after the operation.
    
    See Also:
    o  beginDwgOpen
    o  dwgFileOpened
  */
  virtual void endDwgOpen(const OdChar* filename, OdDbDatabase* pDb);
    
  /** Description:
    Notification function called whenever an OdDbDatabase instance is about to be closed.
    
    Arguments:
    pDb (I) Pointer to the *database* being *closed*.
    
    Remarks:
    This function is called before the operation.
  */
  virtual void beginClose(
    OdDbDatabase* pDb);
  /**
    See Also:
    o  beginDwgOpen
    o  endDwgOpen
  */
  virtual void dwgFileOpened(
    OdDbDatabase* pDb, 
    OdChar * filename);
  
  
  /** Description:
    Notification function called whenever an Xref *database* is about 
    to be attached to a host *database*.
    
    Arguments:
    pToDb (I) Host *database*.
    pFromDb (I) Xref *database*.
    filename (I) Xref filename.
    
    Remarks:
    This function is called before the operation.
    
    Remarks:
    filename may not have a path or extension.
    
    See Also:
    o  abortAttach
    o  endAttach  
    o  otherAttach
  */
  virtual void beginAttach(
    OdDbDatabase* pToDb, 
    const OdChar* filename, 
    OdDbDatabase* pFromDb);
    
  /** Description:
    Notification function called whenever an Xref *database* has been attached to a host *database*.
    
    Arguments:
    pToDb (I) Host *database*.
    pFromDb (I) Xref *database*.
    
    Remarks:
    This function is called after the operation, and is sent just after
    beginDeepCloneXlation.
    
    See Also:
    o  abortAttach
    o  beginAttach
    o  endAttach  
  */
  virtual void otherAttach(
    OdDbDatabase* pToDb, 
    OdDbDatabase* pFromDb);
    
  /** Description:
    Notification function called whenever the attachment of an Xref *database* has failed.
    
    Arguments:
    pToDb (I) Host *database*.
    
    Remarks:
    This function is called after the operation.
        
    See Also:
    o  beginAttach
    o  endAttach  
    o  otherAttach
  */
  virtual void abortAttach(
    OdDbDatabase* pFromDb);
    
  /** Description:
    Notification function called whenever the attachment of an Xref *database* has succeeded.
    
    Arguments:
    pToDb (I) Host *database*.
    
    Remarks:
    This function is called after the operation.
        
    See Also:
    o  abortAttach
    o  beginAttach
    o  otherAttach
  */
  virtual void endAttach(
    OdDbDatabase* pToDb);
    
  /** Description:
    Notification function called whenever an Object ID in an Xref *database* has been
    modified to point at an associated object in a host *database*. 
    
    Arguments:
    oldId (I) Object Id in the Xref *database*.
    neId (I) Object Id in the host *database*.
    
    Remarks:
    This function is called after the operation.
    
    Redirection is used to implement VISRETAIN.
  */
  virtual void redirected(
    OdDbObjectId newId, 
    OdDbObjectId oldId);
    
  /** Description:
    Notification function called whenever an object in an Xref *database* has been comandeered.
    
    Arguments:
    pToDb (I) Host *database*.
    pFromDb (I) Xref *database*.
    objectId (I) Object ID of the comandeered object.
    
    Remarks:
    Rather than copy an Xref dependent object to the host *database*, the Object ID of the object
    is merely appended to the host *database* symbol table with the name of the Xref prepended to it.
    
    Thus, the block BAR in the xrefed *database* FOO, becomes FOO|BAR in the host *database*.
  */
  virtual void comandeered(
    OdDbDatabase* pToDb, 
    OdDbObjectId id, 
    OdDbDatabase* pFromDb);
    
  
  /** Description:
    Notification function called whenever an Xref *database* is about 
    to be reloaded to a host *database*, when the Xref drawing file is unchanged.
    
    Arguments:
    pToDb (I) Host *database*.
    pFromDb (I) Xref *database*.
    filename (I) Xref filename.
    
    Remarks:
    This function is called before the operation.
    
    Remarks:
    filename may not have a path or extension.
    
    See Also:
    o  abortRestore
    o  endRestore  
  */
  virtual void beginRestore(
    OdDbDatabase* pToDb, 
    const OdChar* filename, 
    OdDbDatabase* pFromDb);

  /** Description:
    Notification function called whenever the restore of an Xref *database* has failed.
    
    Arguments:
    pToDb (I) Host *database*.
    
    Remarks:
    This function is called after the operation.
        
    See Also:
    o  beginRestore
    o  endRestore  
  */
  virtual void abortRestore(
    OdDbDatabase* pToDb);
  /** Description:
    Notification function called whenever the restore of an Xref *database* has succeeded.
    
    Arguments:
    pToDb (I) Host *database*.
    
    Remarks:
    This function is called after the operation.
        
    See Also:
    o  abortRestore
    o  beginAttach
  */
  virtual void endRestore(
    OdDbDatabase* pToDb);
  
  /** Description:
    Notification function called during an Xref Bind operation.
    
    Arguments:
    activity (I) Bind *activity*.
    blockId (I) Object ID of the Xref.
    
    Remarks:
    This function will be called multiple times as an Xrefs are bound.
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Bind has started. blockId is undefined.
    kStartItem          2         The Bind of the Xref with the specified blockId has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Bind of the Xref with the specified blockId has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Bind has completed successfully. blockId is undefined.
    kAborted            6         The Bind has failed to complete for the Xref with the specified blockId. 
    kStartXBindBlock    7         Notification of an Xref-dependent block being bound.
    kStartXBindSymbol   8         Notification of all other Xref-dependent symbols.

    See also:
    o  xrefSubcommandAttachItem
    o  xrefSubcommandDetachItem 
    o  xrefSubcommandOverlayItem
    o  xrefSubcommandPathItem
    o  xrefSubcommandReloadItem
    o  xrefSubcommandUnloadItem
    
  */
  virtual void xrefSubcommandBindItem(
	OdDbDatabase* pHost,
    int activity, 
    OdDbObjectId blockId);
    
  /** Description:
    Notification function called during an Xref Attach operation.
    
    Arguments:
    activity (I) Attach *activity*.
    xrefPath (I) Xref path.
    
    Remarks:
    This function will called multiple times as an Xrefs are attached. 
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Attach has started. xrefPath is undefined.
    kStartItem          2         The Attach of the Xref with the specified path has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Attach of the Xref with the specified path has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Attach has completed successfully. xrefPath is undefined.
    kAborted            6         The Attach has failed to complete for the Xref with the specified filename. 
    
    Note:
    This function can be triggered by any action that results in the resolution of Xrefs. 
    This includes plot, IGES and DXF input, block redefinition, and Xref Reload operations.

    See also:
    o  xrefSubcommandBindItem
    o  xrefSubcommandDetachItem 
    o  xrefSubcommandOverlayItem
    o  xrefSubcommandPathItem
    o  xrefSubcommandReloadItem
    o  xrefSubcommandUnloadItem
  */
  virtual void xrefSubcommandAttachItem(
	OdDbDatabase* pHost,
    int activity, 
    const OdChar* xrefPath);

  /** Description:
    Notification function called during an Xref Overlay operation.
    
    Arguments:
    activity (I) Overlay *activity*.
    xrefPath (I) Xref path.
    
    Remarks:
    This function will called multiple times as an Xrefs are overlayed. 
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Overlay has started. xrefPath is undefined.
    kStartItem          2         The Overlay of the Xref with the specified path has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Overlay of the Xref with the specified path has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Overlay has completed successfully. xrefPath is undefined.
    kAborted            6         The Overlay has failed to complete for the Xref with the specified filename. 
    
    Note:
    This function can be triggered by any action that results in the resolution of Xrefs. 
    This includes plot, IGES and DXF input, block redefinition, and Xref Reload operations.

    See also:
    o  xrefSubcommandAttachItem
    o  xrefSubcommandBindItem
    o  xrefSubcommandDetachItem 
    o  xrefSubcommandPathItem
    o  xrefSubcommandReloadItem
    o  xrefSubcommandUnloadItem
  */
  virtual void xrefSubcommandOverlayItem(
	OdDbDatabase* pHost,
    int activity, 
    const OdChar* xrefPath);
    
  /** Description:
    Notification function called during an Xref Detach operation.
    
    Arguments:
    activity (I) Detach *activity*.
    blockId (I) Object ID of the Xref.
    
    Remarks:
    This function will be called multiple times as an Xrefs are detached.
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Detach has started. blockId is undefined.
    kStartItem          2         The Detach of the Xref with the specified blockId has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Detach of the Xref with the specified blockId has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Detach has completed successfully. blockId is undefined.
    kAborted            6         The Detach has failed to complete for the Xref with the specified blockId. 

    See also:
    o  xrefSubcommandAttachItem
    o  xrefSubcommandBindItem
    o  xrefSubcommandOverlayItem
    o  xrefSubcommandPathItem
    o  xrefSubcommandReloadItem
    o  xrefSubcommandUnloadItem
  */
  virtual void xrefSubcommandDetachItem(
	OdDbDatabase* pHost,
    int activity, 
    OdDbObjectId blockId);
    
  /** Description:
    Notification function called during an Xref Path operation.
    
    Arguments:
    activity (I) Path *activity*.
    newPath (I) New Xref path.
    blockId (I) Object ID of the Xref.
    
    Remarks:
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Path operation has started. blockId and newPath are undefined.
    kStartItem          2         The Path operation the Xref with the specified blockId has been started. 
    kEndItem            3         The Path of the Xref with the specified blockId has been successfully changed to newPath.  
    kEnd                4         The Path operation has completed successfully. blockId and newPath are undefined.
    kAborted            6         The Path has failed to complete for the Xref with the specified blockId. 

    See also:
    o  xrefSubcommandAttachItem
    o  xrefSubcommandBindItem
    o  xrefSubcommandDetachItem 
    o  xrefSubcommandOverlayItem
    o  xrefSubcommandReloadItem
    o  xrefSubcommandUnloadItem
  */
  virtual void xrefSubcommandPathItem(
	OdDbDatabase* pHost,
    int activity, OdDbObjectId blockId, 
    const OdChar* newPath);
    
  /** Description:
    Notification function called during an Xref Reload operation.
    
    Arguments:
    activity (I) Reload *activity*.
    blockId (I) Object ID of the Xref.
    
    Remarks:
    This function will be called multiple times as an Xrefs are reloaded.
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Reload has started. blockId is undefined.
    kStartItem          2         The Reload of the Xref with the specified blockId has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Reload of the Xref with the specified blockId has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Reload has completed successfully. blockId is undefined.
    kAborted            6         The Reload has failed to complete for the Xref with the specified blockId. 

    See also:
    o  xrefSubcommandAttachItem
    o  xrefSubcommandBindItem
    o  xrefSubcommandDetachItem 
    o  xrefSubcommandOverlayItem
    o  xrefSubcommandPathItem
    o  xrefSubcommandUnloadItem
  */
  virtual void xrefSubcommandReloadItem(
	OdDbDatabase* pHost,
    int activity, 
    OdDbObjectId blockId);
    
  /** Description:
    Notification function called during an Xref Unload operation.
    
    Arguments:
    activity (I) Reload *activity*.
    blockId (I) Object ID of the Xref.
    
    Remarks:
    This function will be called multiple times as an Xrefs are unloaded.
    
    activity must be one of the following:
    
    @table
    Name                Value     Description
    kStart              0         The Unload has started. blockId is undefined.
    kStartItem          2         The Unload of the Xref with the specified blockId has been started. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEndItem            3         The Unload of the Xref with the specified blockId has been successfully completed. 
                                  Notification will be made for the 
                                  original Xref and any dependent Xrefs.
    kEnd                4         The Unload has completed successfully. blockId is undefined.
    kAborted            6         The Unload has failed to complete for the Xref with the specified blockId. 
  */
  virtual void xrefSubcommandUnloadItem(
	OdDbDatabase* pHost,
    int activity, 
    OdDbObjectId blockId);
  
  /** Description:
    Notification function called during an Undo Auto operation.
    
    Arguments:
    activity (I) Auto *activity*.
    undoAuto (I) True if and only if Undo Auto mode is on.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kEnd                4         The Auto operation has completed successfully.

    See also:
    o  undoSubcommandBack
    o  undoSubcommandBegin
    o  undoSubcommandControl
    o  undoSubcommandEnd
    o  undoSubcommandMark
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandAuto(
    int activity, 
    bool undoAuto);
    
  /** Description:
    Notification function called during an Undo Control operation.
    
    Arguments:
    activity (I) Control *activity*.
    option (I) Undo *option*.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kEnd                4         The Control operation has completed successfully.

    option must be one of the following:
    
    @table
    Name    Value   Description
    kNone   0       Undo None 
    kOne    1       Undo One  
    kAll    2       Undo All 

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBack
    o  undoSubcommandBegin
    o  undoSubcommandEnd
    o  undoSubcommandMark
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandControl(
    int activity, 
    int option);
    
  /** Description:
    Notification function called during an Undo Begin or Undo Group operation.
    
    Arguments:
    activity (I) Begin *activity*.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kStart              0         The Undo Begin/Group has started.

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBack
    o  undoSubcommandControl
    o  undoSubcommandEnd
    o  undoSubcommandMark
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandBegin(
    int activity);
    
  /** Description:
    Notification function called during an Undo End or Undo Group operation.
    
    Arguments:
    activity (I) End *activity*.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kStart              0         The Undo End has started.

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBack
    o  undoSubcommandBegin
    o  undoSubcommandControl
    o  undoSubcommandMark
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandEnd(
    int activity);
    
  /** Description:
    Notification function called during an Undo Mark operation.
    
    Arguments:
    activity (I) Mark *activity*.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kStart              0         The Undo Mark has started.

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBack
    o  undoSubcommandBegin
    o  undoSubcommandControl
    o  undoSubcommandEnd
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandMark(
    int activity);
    
  /** Description:
    Notification function called during an Undo Back operation.
    
    Arguments:
    activity (I) Back *activity*.
        
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kStart              0         The Undo Back has started.

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBegin
    o  undoSubcommandControl
    o  undoSubcommandEnd
    o  undoSubcommandMark
    o  undoSubcommandNumber
  */
  virtual void undoSubcommandBack(
    int activity);
    
  /** Description:
    Notification function called during an Undo <number>operation.
    
    Arguments:
    activity (I) Number *activity*.
    numSteps (I) Number of steps to be undone.    
    Remarks:
    activity will always be:
    
    @table
    Name                Value     Description
    kStart              0         The Undo Back has started.

    See also:
    o  undoSubcommandAuto
    o  undoSubcommandBack
    o  undoSubcommandBegin
    o  undoSubcommandControl
    o  undoSubcommandEnd
    o  undoSubcommandMark
  */
  virtual void undoSubcommandNumber(
    int activity, 
    int numSteps);
  
  /** Description:
    Notification function called to indicate the 
    number of entities in the pickfirst selection set has been changed.
  */
  virtual void pickfirstModified();
  
  /** Description:
    Notification function called to indicate the current layout has changed.
    
    Arguments:
    newLayoutName (I) New layout name.  
  */
  virtual void layoutSwitched(
    const OdChar* newLayoutName);
  
  /** Description:
    Notification function called to indicate an MDI document frame window has been *moved* or resized.
    
    Arguments:
    hwndDocFrame (I) HWND of document frame.
    moved (I) True if *moved*, false if resized.
    
    See also:
    mainFrameMovedOrResized
  */
  virtual void docFrameMovedOrResized(
    OdLongPtr hwndDocFrame, 
    bool moved);

  /** Description:
    Notification function called to indicate the Editor main frame window has been *moved* or resized.
    
    Arguments:
    hwndMainFrame (I) HWND of the main frame.
    moved (I) True if *moved*, false if resized.
    See also:
    docFrameMovedOrResized
  */
  virtual void mainFrameMovedOrResized(
    OdLongPtr hwndMainFrame, 
    bool moved);
  
  /* Description:
    Notification function called to indicate the mouse button has been double-clicked
    in the graphics screen area.
    
    Arguments:
    clickPoint (I) WCS double-click point.
    
    See also:
    beginRightClick
  */
  virtual void beginDoubleClick(
    const OdGePoint3d& clickPoint);

  /* Description:
    Notification function called to indicate the mouse button has been right-clicked
    in the graphics area.
    
    Arguments:
    clickPoint (I) WCS right-click point.
    
    See also:
    beginDoubleClick
  */
  virtual void beginRightClick(
  const OdGePoint3d& clickPoint);
  
  /* Description:
    Notification function called to indicate the toolbar bitmap size is about to change.
    
    Arguments:
    largeBitmaps (I) True if and only if large bitmaps. 
    
	  Remarks:
	  This function is called before the operation.

    See also:
    toolbarBitmapSizeChanged
  */
  virtual void toolbarBitmapSizeWillChange(
    bool largeBitmaps);
    
  /* Description:
    Notification function called to indicate the toolbar bitmap size has changed.
    
    Arguments:
    largeBitmaps (I) True if and only if large bitmaps. 
    
	  Remarks:
	  This function is called after the operation.

    See also:
    toolbarBitmapSizeWillChange
  */
  virtual void toolbarBitmapSizeChanged(
    bool largeBitmaps);
  
  /** Description:
    Notification function called after objects are lazy during a partial open of a drawing.
    
    Arguments:
    objectIDs (I) Object IDs lazy loaded.
  */    
  virtual void objectsLazyLoaded(const OdDbObjectIdArray& objectIds);
  
  /** Description:
    Notification function called whenever the Editor is about to shut down.
    
    Remarks:
    Calling veto() will cancel the shutdown.    
  */
  virtual void beginQuit();
  
  /** Description:
    Notification function called whenever the Editor has failed to shut down.

    See also:
    o  beginQuit
    o  quitWillStart
  */
  virtual void quitAborted();

  /** Description:
    Notification function called whenever the Editor is about to shut down.

    Remarks:
    This function is called after beginQuit was not vetoed.
    
    See also:
    o  beginQuit
    o  quitAborted
  */
  virtual void quitWillStart();

  /** Description:
    Notification function called whenever a modeless operation is about to start.

    Arguments:
    contextString (I) Context string identifying the operation.
    See also:
    modelessOperationEnded
  */  
  virtual void modelessOperationWillStart(
    const OdChar* contextString);

  /** Description:
    Notification function called whenever a modeless operation has ended.

    Arguments:
    contextString (I) Context string identifying the operation.
    See also:
    modelessOperationWillStart
 */  
  virtual void modelessOperationEnded(const OdChar* contextString);
  virtual void cmdIUnkModified(const OdChar* strCommand);

  virtual void sysVarChanged        (const OdChar* varName, OdBool success);
  virtual void sysVarWillChange     (const OdChar* varName);
  
  virtual void preXrefLockFile(OdDbObjectId btrId);
  virtual void viewChanged();  

protected:
    OdResult veto();

private:
  OdUInt8 mVeto;

  friend class OdEditorImpl;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdEditorReactor object pointers.
*/
typedef OdSmartPtr<OdEditorReactor> OdEditorReactorPtr;


class TOOLKIT_EXPORT OdEditorReactor2 : public OdEditorReactor
{
public:
  ODRX_DECLARE_MEMBERS(OdEditorReactor2);

  virtual void beginDocClose(OdDbDatabase* pDwg) {}

  virtual void docCloseAborted(OdDbDatabase* pDwg) {}

  virtual void docCloseWillStart(OdDbDatabase* pDwg) {}

  virtual void layoutToBeSwitched (const OdChar *oldLayoutName, const OdChar *newLayoutName) {}

  virtual void dwgViewResized (OdLongPtr hwndDwgView) {}
};

class TOOLKIT_EXPORT OdEditorReactorEx : public OdEditorReactor2
{
public:
  ODRX_DECLARE_MEMBERS(OdEditorReactorEx);
  virtual void customModeBegin(){}
  virtual void customModeEnd(){}
};
/** Description:
    This class manages application level OdEditorReactor instances.
    
    Library: TD_Db
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdEditor : public OdRxEvent 
{ 
public:
  ODRX_DECLARE_MEMBERS(OdEditor);
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdEditor object pointers.
*/
typedef OdSmartPtr<OdEditor> OdEditorPtr;

TOOLKIT_EXPORT OdEditor* odedEditor();

#include "TD_PackPop.h"

#endif // _ODED_H_INCLUDED_

