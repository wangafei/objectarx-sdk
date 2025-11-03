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




#ifndef   _ODEDITORIMPL_H_INCLUDED_
#define   _ODEDITORIMPL_H_INCLUDED_

#include "TD_PackPush.h"

#include "Editor.h"

/** Description:

    {group:OdRx_Classes} 
*/

#define RXEVENT_FIRE(method, inparams, params) \
inline void fire_##method inparams \
{ \
  TD_AUTOLOCK( m_mutex ); \
  OdArray<OdRxEventReactor*> reactors = m_reactors; \
  for (OdSize i = 0; i < reactors.size(); ++i) \
  { \
    if (m_reactors.contains(reactors[i]))\
      reactors[i]->method params; \
  } \
}

#define EDEVENT_FIRE(method, inparams, params) \
inline void fire_##method inparams \
{ \
  TD_AUTOLOCK( m_mutex ); \
  OdArray<OdRxEventReactor*> reactors = m_reactors; \
  for (OdSize i = 0; i < reactors.size(); ++i) \
  { \
    if (m_reactors.contains(reactors[i]))\
    {\
      OdEditorReactorPtr pReactor = OdEditorReactor::ODSYSCALL1(cast , reactors[i]); \
      if (pReactor.get()) pReactor->method params; \
    }\
  } \
}

#define EDEVENT_FIRE2(method, inparams, params) \
  inline void fire_##method inparams \
{ \
  TD_AUTOLOCK( m_mutex ); \
  OdArray<OdRxEventReactor*> reactors = m_reactors; \
  for (OdSize i = 0; i < reactors.size(); ++i) \
  { \
  if (m_reactors.contains(reactors[i]))\
    {\
    OdEditorReactor2* pReactor = OdEditorReactor2::cast(reactors[i]); \
    if (pReactor) pReactor->method params; \
    }\
  } \
}


#define EDEVENT_FIREEX(method, inparams, params) \
  inline void fire_##method inparams \
{ \
  TD_AUTOLOCK( m_mutex ); \
  OdArray<OdRxEventReactor*> reactors = m_reactors; \
  for (OdSize i = 0; i < reactors.size(); ++i) \
  { \
  if (m_reactors.contains(reactors[i]))\
    {\
    OdEditorReactorEx* pReactor = OdEditorReactorEx::cast(reactors[i]); \
    if (pReactor) pReactor->method params; \
    }\
  } \
}
/** Description:
    This class defines the events that trigger OdRxEventReactor instances. 
    Library: TD_Db
    {group:OdRx_Classes} 
*/
class TOOLKIT_EXPORT OdRxEventImpl : public OdEditor
{
protected:
  OdArray<OdRxEventReactor*> m_reactors;
  OdMutex m_mutex;
public:
  OdRxEventImpl() {}
  ODRX_DECLARE_MEMBERS(OdRxEventImpl);
  
  void addReactor(OdRxEventReactor* pReactor);
  void removeReactor(OdRxEventReactor* pReactor);

  RXEVENT_FIRE(unknownCommand,(const OdChar* cmdStr, OdDbVoidPtrArray *al),(cmdStr,al))
  RXEVENT_FIRE(commandWillStart,(const OdChar* cmdStr),(cmdStr))
  RXEVENT_FIRE(commandEnded,(const OdChar* cmdStr),(cmdStr))
  RXEVENT_FIRE(commandCancelled,(const OdChar* cmdStr),(cmdStr))
  RXEVENT_FIRE(commandFailed,(const OdChar* cmdStr),(cmdStr))
  // notifiers
  RXEVENT_FIRE(dwgFileOpened, (OdDbDatabase* db, OdChar * filename),(db, filename))
  RXEVENT_FIRE(initialDwgFileOpenComplete, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(databaseConstructed, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(databaseToBeDestroyed, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(beginSave, (OdDbDatabase* db, const OdChar * pIntendedName), (db, pIntendedName))
  RXEVENT_FIRE(saveComplete, (OdDbDatabase* db, const OdChar * pActualName), (db, pActualName))
  RXEVENT_FIRE(abortSave, (OdDbDatabase* db), (db))
  // DXF In/Out Events.
  RXEVENT_FIRE(beginDxfIn, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(abortDxfIn, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(dxfInComplete, (OdDbDatabase* db), (db))
  //
  RXEVENT_FIRE(beginDxfOut, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(abortDxfOut, (OdDbDatabase* db), (db))
  RXEVENT_FIRE(dxfOutComplete, (OdDbDatabase* db), (db))
  // Insert Events.
  RXEVENT_FIRE(beginInsert, (OdDbDatabase* pTo, const OdChar * pBlockName, OdDbDatabase* pFrom), (pTo, pBlockName, pFrom))
  RXEVENT_FIRE(beginInsert, (OdDbDatabase* pTo, const OdGeMatrix3d& xform, OdDbDatabase* pFrom), (pTo, xform, pFrom))
  RXEVENT_FIRE(otherInsert, (OdDbDatabase* pTo, OdDbIdMapping& idMap, OdDbDatabase* pFrom), (pTo, idMap, pFrom))
  RXEVENT_FIRE(abortInsert, (OdDbDatabase* pTo), (pTo))
  RXEVENT_FIRE(endInsert, (OdDbDatabase* pTo), (pTo))

  // Wblock Events.
  RXEVENT_FIRE(wblockNotice, (OdDbDatabase* pDb), (pDb))
  RXEVENT_FIRE(beginWblock, (OdDbDatabase* pTo, OdDbDatabase* pFrom, const OdGePoint3d *& insertionPoint), (pTo, pFrom, insertionPoint))
  RXEVENT_FIRE(beginWblock, (OdDbDatabase* pTo, OdDbDatabase* pFrom, OdDbObjectId blockId), (pTo, pFrom, blockId))
  RXEVENT_FIRE(beginWblock, (OdDbDatabase* pTo, OdDbDatabase* pFrom), (pTo, pFrom))
  RXEVENT_FIRE(otherWblock, (OdDbDatabase* pTo, OdDbIdMapping& m, OdDbDatabase* pFrom), (pTo, m, pFrom))
  RXEVENT_FIRE(abortWblock, (OdDbDatabase* pTo), (pTo))
  RXEVENT_FIRE(endWblock, (OdDbDatabase* pTo), (pTo))
  RXEVENT_FIRE(beginWblockObjects, (OdDbDatabase* pDb, OdDbIdMapping& m), (pDb, m))

  // Deep Clone Events.
  RXEVENT_FIRE(beginDeepClone, (OdDbDatabase* pTo, OdDbIdMapping& m), (pTo, m))
  RXEVENT_FIRE(beginDeepCloneXlation, (OdDbIdMapping& m, OdResult* pResult), (m, pResult))
  RXEVENT_FIRE(abortDeepClone, (OdDbIdMapping& m), (m))
  RXEVENT_FIRE(endDeepClone, (OdDbIdMapping& m), (m))

  // Partial Open Events.
  RXEVENT_FIRE(partialOpenNotice, (OdDbDatabase* pDb), (pDb))

  //
  // OdEditorReactor events.
  //
  // file events
  EDEVENT_FIRE(beginDwgOpen,(OdChar* filename),(filename))
  EDEVENT_FIRE(endDwgOpen,(const OdChar* filename, OdDbDatabase* pDb),(filename,pDb))
  EDEVENT_FIRE(beginClose,   (OdDbDatabase* pDb), (pDb))

  // xref events
  EDEVENT_FIRE(beginAttach, (OdDbDatabase* pToDb, const OdChar * filename, OdDbDatabase* pFromDb), (pToDb, filename, pFromDb))
  EDEVENT_FIRE(otherAttach,  (OdDbDatabase* pToDb, OdDbDatabase* pFromDb), (pToDb, pFromDb))
  EDEVENT_FIRE(abortAttach,  (OdDbDatabase* pFromDb), (pFromDb))
  EDEVENT_FIRE(endAttach,    (OdDbDatabase* pToDb), (pToDb))
  EDEVENT_FIRE(redirected,   (OdDbObjectId newId, OdDbObjectId oldId), (newId, oldId))
  EDEVENT_FIRE(comandeered,  (OdDbDatabase* pToDb, OdDbObjectId id, OdDbDatabase* pFromDb), (pToDb, id, pFromDb))
  EDEVENT_FIRE(beginRestore, (OdDbDatabase* pToDb, const OdString& filename, OdDbDatabase* pFromDb), (pToDb, filename, pFromDb))
  EDEVENT_FIRE(abortRestore, (OdDbDatabase* pToDb), (pToDb))
  EDEVENT_FIRE(endRestore,   (OdDbDatabase* pToDb), (pToDb))

  // xref subcommand events
  EDEVENT_FIRE(xrefSubcommandBindItem,    (OdDbDatabase* pHost, int activity, OdDbObjectId blockId), (pHost, activity, blockId))
  EDEVENT_FIRE(xrefSubcommandAttachItem,  (OdDbDatabase* pHost, int activity, const OdString& xrefPath), (pHost, activity, xrefPath))
  EDEVENT_FIRE(xrefSubcommandOverlayItem, (OdDbDatabase* pHost, int activity, const OdString& xrefPath), (pHost, activity, xrefPath))
  EDEVENT_FIRE(xrefSubcommandDetachItem,  (OdDbDatabase* pHost, int activity, OdDbObjectId blockId), (pHost, activity, blockId))
  EDEVENT_FIRE(xrefSubcommandPathItem,    (OdDbDatabase* pHost, int activity, OdDbObjectId blockId, const OdString& newPath), (pHost, activity, blockId, newPath))
  EDEVENT_FIRE(xrefSubcommandReloadItem,  (OdDbDatabase* pHost, int activity, OdDbObjectId blockId), (pHost, activity, blockId))
  EDEVENT_FIRE(xrefSubcommandUnloadItem,  (OdDbDatabase* pHost, int activity, OdDbObjectId blockId), (pHost, activity, blockId))

  // command undo events
  EDEVENT_FIRE(undoSubcommandAuto,   (int activity, bool state), (activity, state))
  EDEVENT_FIRE(undoSubcommandControl,(int activity, int option), (activity, option))
  EDEVENT_FIRE(undoSubcommandBegin,  (int activity), (activity))
  EDEVENT_FIRE(undoSubcommandEnd,    (int activity), (activity))
  EDEVENT_FIRE(undoSubcommandMark,   (int activity), (activity))
  EDEVENT_FIRE(undoSubcommandBack,   (int activity), (activity))
  EDEVENT_FIRE(undoSubcommandNumber, (int activity, int num), (activity, num))

  // pickfirst selection event
  EDEVENT_FIRE(pickfirstModified, (), ())
  EDEVENT_FIRE(lispWillStart,(const OdChar* firstLine),(firstLine))
  EDEVENT_FIRE(lispEnded,(),())
  EDEVENT_FIRE(lispCancelled,(),())

  // layout event
  EDEVENT_FIRE(layoutSwitched, (const OdChar* newLayoutName), (newLayoutName))

  // window events
  EDEVENT_FIRE(docFrameMovedOrResized, (OdLongPtr hwndDocFrame, bool moved), (hwndDocFrame, moved))
  EDEVENT_FIRE(mainFrameMovedOrResized, (OdLongPtr hwndMainFrame, bool moved), (hwndMainFrame, moved))

  // mouse events
  EDEVENT_FIRE(beginDoubleClick, (const OdGePoint3d& clickPoint), (clickPoint))
  EDEVENT_FIRE(beginRightClick, (const OdGePoint3d& clickPoint), (clickPoint))

  // toolbar events
  EDEVENT_FIRE(toolbarBitmapSizeWillChange, (bool largeBitmaps), (largeBitmaps))
  EDEVENT_FIRE(toolbarBitmapSizeChanged, (bool largeBitmaps), (largeBitmaps))

  // partial open events
  EDEVENT_FIRE(objectsLazyLoaded, (const OdDbObjectIdArray& objectIds), (objectIds))

  // quit events
  EDEVENT_FIRE(beginQuit,       (), ())
  EDEVENT_FIRE(quitAborted,     (), ())
  EDEVENT_FIRE(quitWillStart,   (), ())

  // modeless operation events
  EDEVENT_FIRE(modelessOperationWillStart, (const OdChar* contextString), (contextString))
  EDEVENT_FIRE(modelessOperationEnded, (const OdChar* contextString), (contextString))

  // SysVar events
  EDEVENT_FIRE( sysVarChanged, (const OdChar* varName,OdBool success),(varName,success))
  EDEVENT_FIRE( sysVarWillChange, (const OdChar* varName), (varName))\

  EDEVENT_FIRE( viewChanged, (), ())

  //OdEditorReactor2
  EDEVENT_FIRE2(beginDocClose,(OdDbDatabase* pDwg),(pDwg))
  EDEVENT_FIRE2(docCloseAborted,(OdDbDatabase* pDwg),(pDwg))
  EDEVENT_FIRE2(docCloseWillStart,(OdDbDatabase* pDwg),(pDwg))
  EDEVENT_FIRE2(layoutToBeSwitched,(const OdChar *oldLayoutName, const OdChar *newLayoutName),(oldLayoutName,newLayoutName))
  EDEVENT_FIRE2(dwgViewResized,(OdLongPtr hwndDwgView),(hwndDwgView))
  EDEVENT_FIREEX( customModeBegin, (), ()) 
  EDEVENT_FIREEX( customModeEnd, (), ())
};

typedef OdSmartPtr<OdRxEventImpl> OdRxEventImplPtr;

/** Description:
    This class defines the events that trigger OdRxEventReactor instances. 
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdEditorImpl : public OdRxEventImpl
{
public:
  OdEditorImpl() {}
  ODRX_DECLARE_MEMBERS(OdEditorImpl);

  void enableVeto(bool bEnable);
  bool vetoed();
};

typedef OdSmartPtr<OdEditorImpl> OdEditorImplPtr;

#include "TD_PackPop.h"

#endif // _ODEDITORIMPL_H_INCLUDED_

