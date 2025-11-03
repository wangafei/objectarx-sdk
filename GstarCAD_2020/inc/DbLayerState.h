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

#ifndef DBLAYERSTATEMANAGER_H
#define DBLAYERSTATEMANAGER_H

#include "TD_PackPush.h"

#include "OdArray.h"
#include "OdString.h"
#include <set>

/** Description:
  This class implements an interface for maniuplating LayerStates in multiple OdDbDatabase instances.
  
  Library: TD_Db
  {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbLayerState
{
public:
  enum Mask
  {
    kDefMask          = (int)0xFFFFFFFF,
    kNone             = 0x0000,
    kOn               = 0x0001,
    kFrozen           = 0x0002,
    kLocked           = 0x0004,
    kPlot             = 0x0008,
    kNewViewport      = 0x0010,
    kColor            = 0x0020,
    kLineType         = 0x0040,
    kLineWeight       = 0x0080,
    kPlotStyle        = 0x0100,
    kCurrentViewport  = 0x0200,
    kTransparency     = 0x0400,

    kAll              = kOn | kFrozen | kLocked | kPlot | kNewViewport |
                        kColor | kLineType | kLineWeight | kPlotStyle |
                        kCurrentViewport | kTransparency,

    kHidden           = 0x8000        
  };
  
  enum
  {
    kUndefDoNothing = 0x00,
    kUndefTurnOff   = 0x01,
    kUndefFreeze    = 0x02
  };

  /** Description:
    Returns the Object ID of the LayerStates dictionary for the specified *database*.
    Arguments:
    pDb (I) Pointer to the *database*.
    createIfNotFound (I) Controls the creation of the dictionary if it does not exist.
  */
  static OdDbObjectId dictionaryId(OdDbDatabase *pDb, bool createIfNotFound = false);
  
  /** Description:
    Returns true if and only if the specified *database*
    *has* a LayerState with the specified *name*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
  */
  static bool has(OdDbDatabase *pDb, const OdString &layerStateName);
  
  /** Description:
    Saves the current LayerState of the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
    layerStateMask (I) LayerState *mask*.
    viewportId (I) Viewport whose LayerState is to be saved.
    
    Remarks:
    layerStateMask determines which layer attributes are to be stored in the LayerState.  
    layerStateMask must be a combination of one or more of the following:
    
    @table
    Name                   Value        
    kNone                  0x0000       
    kOn                    0x0001       
    kFrozen                0x0002       
    kLocked                0x0004       
    kPlot                  0x0008       
    kNewViewport           0x0010       
    kColor                 0x0020       
    kLineType              0x0040       
    kLineWeight            0x0080       
    kPlotStyle             0x0100        
    kCurrentViewport       0x0200     
    kTransparency          0x0400
    kAll                   kOn | kFrozen | kLocked | kPlot | kNewViewport |
                           kColor | kLineType | kLineWeight | kPlotStyle |
                           kCurrentViewport | kTransparency       
    kHidden                0x8000        
    
  */
  static void save(OdDbDatabase *pDb, const OdString &layerStateName, int layerStateMask, const OdDbObjectId &viewportId = OdDbObjectId::kNull);

  /** Description:
    Restores the specified LayerState of the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
    layerStateMask (I) LayerState *mask*.
    viewportId (I) Viewport whose LayerState is to be saved.
    undefAction (I) Action for undefined layers.
    
    Remarks:
    undefAction specified the action for layers not defined in the LayerState.
    undefAction must be one of the following:
    
    @table
    Name               Value  
    kUndefDoNothing    0      
    kUndefTurnOff      1        
    kUndefFreeze       2
    
    layerStateMask determines which layer attributes are to be restored from the LayerState.  
    layerStateMask must be a combination of one or more of the following:
    
    @table
    Name                   Value        
    kDefMask               0xFFFFFFFF   
    kNone                  0x0000       
    kOn                    0x0001       
    kFrozen                0x0002       
    kLocked                0x0004       
    kPlot                  0x0008       
    kNewViewport           0x0010       
    kColor                 0x0020       
    kLineType              0x0040       
    kLineWeight            0x0080       
    kPlotStyle             0x0100        
    kCurrentViewport       0x0200        
    kTransparency          0x0400
    kAll                   kOn | kFrozen | kLocked | kPlot | kNewViewport |
                           kColor | kLineType | kLineWeight | kPlotStyle |
                           kCurrentViewport | kTransparency       
    kHidden                0x8000        
    
  */
  static void restore(OdDbDatabase *pDb, const OdString &layerStateName,
    int undefAction = kUndefDoNothing, const int layerStateMask = kDefMask, const OdDbObjectId& viewportId = OdDbObjectId::kNull);
  /** Description:
    Sets the LayerState *mask* for the specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
    layerStateMask (I) LayerState *mask*.
    
    Remarks:
    layerStateMask determines which layer attributes are to be restored from the LayerState.  
    layerStateMask must be a combination of one or more of the following:
    
    @table
    Name                   Value        
    kNone                  0x0000       
    kOn                    0x0001       
    kFrozen                0x0002       
    kLocked                0x0004       
    kPlot                  0x0008       
    kNewViewport           0x0010       
    kColor                 0x0020       
    kLineType              0x0040       
    kLineWeight            0x0080       
    kPlotStyle             0x0100        
    kCurrentViewport       0x0200        
    kTransparency          0x0400
    kAll                   kOn | kFrozen | kLocked | kPlot | kNewViewport |
                           kColor | kLineType | kLineWeight | kPlotStyle |
                           kCurrentViewport | kTransparency       
    kHidden                0x8000        
    
  */
  static void setMask(OdDbDatabase *pDb, const OdString &layerStateName, int layerStateMask);
  
  /** Description:
    Returns the LayerState *mask* for the specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
    
    Remarks:
    The layer state mask determines which layer attributes are to be restored from the LayerState.  

    mask() returns a combination of one or more of the following:
    
    @table
    Name                   Value        
    kNone                  0x0000       
    kOn                    0x0001       
    kFrozen                0x0002       
    kLocked                0x0004       
    kPlot                  0x0008       
    kNewViewport           0x0010       
    kColor                 0x0020       
    kLineType              0x0040       
    kLineWeight            0x0080       
    kPlotStyle             0x0100        
    kCurrentViewport       0x0200        
    kTransparency          0x0400
    kAll                   kOn | kFrozen | kLocked | kPlot | kNewViewport |
                           kColor | kLineType | kLineWeight | kPlotStyle |
                           kCurrentViewport | kTransparency       
    kHidden                0x8000        
    
  */
  static int  mask(OdDbDatabase *pDb, const OdString &layerStateName);

  /** Description:
    Removes the specified LayerState from the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
  */
  static void remove(OdDbDatabase *pDb, const OdString &layerStateName);
 
  /** Description:
    Renames the specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    oldName (I) Old name.
    newName (I) New name.
  */
  static void rename(OdDbDatabase *pDb, const OdString &oldName, const OdString &newName);

  enum ImportResult
  {
    kImported,
    kAlreadyExists
  };

  /** Description:
    Imports the LayerState from the specified file to the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.    
    Remarks:
    If the LayerState from the specified file already exists in the *database*,
    this function is ignored.  

    Returns one of the following:

    @table
    Name               Value  
    kImported          0      
    kAlreadyExists     1        
  */
  static ImportResult importData(OdDbDatabase *pDb, OdStreamBuf* pStreamBuf, OdString& sStateName); // Gcad(Modify)

  /** Description:
    Exports the LayerState from the specified *database* to the specified file.

    Arguments:
    pDb (I) Pointer to the *database*.
    pStreamBuf (I) Pointer to the StreamBuf object to which the data are to be written.
    layerStateName (I) LayerState name.
  */
  static void exportData(OdDbDatabase *pDb, const OdString &layerStateName, OdStreamBuf* pStreamBuf);
  
  /** Description:
    Sets the *description* of the specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
    description (I) Description.
  */    
  static void setDescription(OdDbDatabase *pDb, const OdString &layerStateName, const OdString &description);
  /** Description:
    Returns the *description* of the specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
  */    
  static OdString description(OdDbDatabase *pDb, const OdString &layerStateName);

  /** Description:
    Returns true if and only if there is viewport data associated with specified LayerState in the specified *database*.

    Arguments:
    pDb (I) Pointer to the *database*.
    layerStateName (I) LayerState name.
  */    
  static bool hasViewportData(OdDbDatabase *pDb, const OdString &layerStateName);
};



//////////////////////////////////////////////////////////////////////
// Gcad(Add) class OdDbLayerStateManager
class OdDbLayerStateManagerImpl;
class OdDbLayerStateManagerReactor;
typedef OdArray<OdString> OdStringArray;

class TOOLKIT_EXPORT OdDbLayerStateManager : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLayerStateManager);

  OdDbLayerStateManager();
  OdDbLayerStateManager(OdDbDatabase* pHostDb);
  virtual ~OdDbLayerStateManager();

  enum LayerStateMask
  {
    kNone           = 0x0000,
    kOn             = 0x0001,
    kFrozen         = 0x0002,
    kLocked         = 0x0004,
    kPlot           = 0x0008,
    kNewViewport    = 0x0010,
    kColor          = 0x0020,
    kLineType       = 0x0040,
    kLineWeight     = 0x0080,
    kPlotStyle      = 0x0100,
    kCurrentViewport = 0x0200,
    kTransparency   = 0x0400,
    kAll            = kOn | kFrozen | kLocked | kPlot | kNewViewport |
    kColor | kLineType | kLineWeight | kPlotStyle |
    kCurrentViewport | kTransparency,
    kStateIsHidden  = 0x8000,        
    kLastRestored   = 0x10000,        
    kDecomposition  = kAll | 0x20000
  };

  enum 
  {
	kUndefDoNothing = 0,
	kUndefTurnOff = 1,
	kUndefFreeze = 2,
	kRestoreAsOverrides = 4
  };

  OdDbDatabase* getDatabase() const;

  bool addReactor(OdDbLayerStateManagerReactor* pReactor);
  bool removeReactor(OdDbLayerStateManagerReactor* pReactor);

  // Service methods
  OdDbObjectId layerStatesDictionaryId(bool bCreateIfNotPresent=false);

  bool         hasLayerState(const OdChar* sName);
  OdResult     saveLayerState(const OdChar* sName, LayerStateMask mask);
  OdResult     saveLayerState(const OdChar* sName, LayerStateMask mask, const OdDbObjectId& idVp);
  OdResult     restoreLayerState(const OdChar* sName);
  OdResult     restoreLayerState(const OdChar* sName, const OdDbObjectId& idVp,
								 int nRestoreFlags = 0, const LayerStateMask* pClientMask = NULL);

  OdResult     setLayerStateMask(const OdChar* sName, LayerStateMask mask);
  OdResult     getLayerStateMask(const OdChar* sName, LayerStateMask& returnMask);
  
  OdResult     deleteLayerState(const OdChar* sName);
  OdResult     renameLayerState(const OdChar* sName, const OdChar* sNewName);

  OdResult     importLayerState(const OdChar* sFilename);
  OdResult     importLayerState(const OdChar* sFilename, OdString& sName);
  OdResult     exportLayerState(const OdChar* sNameToExport, const OdChar* sFilename);

  OdResult     setLayerStateDescription(const OdChar* sName, const OdChar* sDesc);
  OdResult     getLayerStateDescription(const OdChar* sName, OdChar*& sDesc);
  bool         layerStateHasViewportData(const OdChar* sName);
  OdResult     importLayerStateFromDb(const OdChar* pStateName, OdDbDatabase* pDb);
  OdResult     getLayerStateNames(OdStringArray& lsArray, bool bIncludeHidden = true, bool bIncludeXref = true);
  OdResult     getLastRestoredLayerState(OdString& sName, OdDbObjectId& restoredLSId);
  OdResult     getLayerStateLayers(OdStringArray& layerArray, const OdChar* sName, bool bInvert = false);
  bool         compareLayerStateToDb(const OdChar* sName, const OdDbObjectId& idVp);
  OdResult     addLayerStateLayers(const OdChar* sName, const OdDbObjectIdArray& layerIds);
  OdResult     removeLayerStateLayers(const OdChar* sName, const OdStringArray& layerNames);
  bool         isDependentLayerState(const OdChar* sName);

	void				setDatabase(OdDbDatabase* pHostDb);
private:
  friend class OdDbLayerStateManagerImpl;
  OdDbLayerStateManagerImpl* mpImpl;
};

// class OdDbLayerStateManagerImpl
class OdDbLayerStateManagerImpl
{
public:
  static OdDbLayerStateManagerImpl* getImpl(OdDbLayerStateManager* lsm){ return lsm->mpImpl; }

  OdDbDatabase* mpDatabase;
  OdArray<OdDbLayerStateManagerReactor*> maReactors;
  std::set<OdDbObjectId> m_xrefStateIds;

  friend void xrefLayerStates(OdDbIdMapping* pIdMap, const OdString& xrefName);
  friend void odDbCleanXrefLayerStates(OdDbDatabase* pHostDb, OdDbDatabase* pXrefDb, bool bRemoveFromIdMap, bool bRemoveFromMgrSet);
};

//////////////////////////////////////////////////////////////////////
// Gcad(Add) class OdDbLayerStateManagerReactor
class TOOLKIT_EXPORT OdDbLayerStateManagerReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbLayerStateManagerReactor);

  virtual void layerStateCreated(const OdChar* layerStateName,
								 const OdDbObjectId& layerStateId);
  virtual void layerStateCompareFailed(const OdChar * layerStateName,
									   const OdDbObjectId& layerStateId);

  virtual void layerStateToBeRestored(const OdChar* layerStateName,
									  const OdDbObjectId& layerStateId);
  virtual void layerStateRestored(const OdChar* layerStateName,
								  const OdDbObjectId& layerStateId);
  virtual void abortLayerStateRestore(const OdChar* layerStateName,
									  const OdDbObjectId& layerStateId);


  virtual void layerStateToBeDeleted(const OdChar* layerStateName,
									 const OdDbObjectId& layerStateId);
  virtual void layerStateDeleted(const OdChar* layerStateName);
  virtual void abortLayerStateDelete(const OdChar* layerStateName,
									 const OdDbObjectId& layerStateId);

  virtual void layerStateToBeRenamed(const OdChar* oldLayerStateName,
									 const OdChar* newLayerStateName);
  virtual void layerStateRenamed(const OdChar* oldLayerStateName,
								 const OdChar* newLayerStateName);
  virtual void abortLayerStateRename(const OdChar* oldLayerStateName,
									 const OdChar* newLayerStateName);
};

#include "TD_PackPop.h"

#endif //#ifndef DBLAYERSTATEMANAGER_H
