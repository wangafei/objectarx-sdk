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


#ifndef _ODDBUNDOCONTROLLER_INCLUDED_
#define _ODDBUNDOCONTROLLER_INCLUDED_

#include "RxObject.h"
#include "RxIterator.h"
#include "DbRootExport.h"

class OdStreamBuf;

/** Description:
  {group:OdDb_Classes}
*/
class DBROOT_EXPORT ODRX_ABSTRACT OdDbUndoControllerRecord : public OdRxObject
{
protected:
  OdDbUndoControllerRecord();
public:
  ODRX_DECLARE_MEMBERS(OdDbUndoControllerRecord);

  virtual OdUInt32 options() const = 0;
  virtual OdString name() const = 0;
};

typedef OdSmartPtr<OdDbUndoControllerRecord> OdDbUndoControllerRecordPtr;

class OdDbDatabase;
/** Description:
    This class defines the interface for Undo Controller objects for OdDbDatabase instances.
    Remarks:
    The implementer manages resources for storing undo and redo information.
    {group:OdDb_Classes}
*/
class DBROOT_EXPORT ODRX_ABSTRACT OdDbUndoController : public OdRxObject
{
public:
  enum
  {
    kDefault    = 0,
    kBlockBegin = 1,
    kBlockEnd   = 2,
    kMarker     = 3
  };

  enum undoBoundary
  {
    kSubCommandBoundary = 0x0004,
    kSubCommandWall = 0x0800,
    kCommandBoundary = 0x0008,
  };

  enum undoControl
  {
    kNone = 0,
    kOne = 1,
    kAll = 2,
  };

  ODRX_DECLARE_MEMBERS(OdDbUndoController);
  /** Description:
    Saves undo information in some manner.
    Arguments:
    pStream (I) stream that contains single undo step data.
    nSize (I) size of undo information (starting from current stream position).
    Remarks:
    Implementer should save nSize bytes from specified stream.
  */
  virtual void pushData(OdStreamBuf* pStream, OdUInt32 nSize, 
                        OdUInt32 opt = kDefault, 
                        const OdString& recordName = OdString::kEmpty) = 0;

  /** Description:
    Returns true if undo information is stored inside this object
    and can be taken back via call popData.
  */

  virtual OdStreamBuf * getStreamBuf() = 0;

  virtual bool hasData() const = 0;

  /** Description:
    Gives back most recent single undo step data.
    Arguments:
    pStream (O) stream
    Remarks:
    Implementer should write back single undo step data
    saved in this object via the most recent call pushData into specified stream
    and then free internal resources used for storing undo step.
  */
  virtual OdUInt32 popData(OdStreamBuf* pStream, OdString& recordName) = 0;

  virtual OdRxIteratorPtr newRecordStackIterator() const = 0;

  virtual void clearData() = 0;

  virtual void setCurrentState(OdUInt32, const OdString&){}
  virtual OdUInt32 getCurrentState(OdString&) const{return 0;}

  //arx
  virtual OdResult  setAuto(bool onOrOff){return eNotImplemented;}
  virtual OdResult  beginGroup(){return eNotImplemented;}
  virtual OdResult  endGroup(){return eNotImplemented;}
  virtual OdResult  setMark(){return eNotImplemented;}
  virtual OdResult  goBackToMark(OdInt16 num = 1){return eNotImplemented;}
  virtual OdResult  undoCommand(int numCmds = 1){return eNotImplemented;}

  virtual OdInt16   getUndoMarkCount() const{return 0;}

  virtual OdResult  undoSubCommand(int numSubCmds = 1){return eNotImplemented;}

  virtual OdResult  writeBoundary(undoBoundary){return eNotImplemented;}
  virtual OdResult  setUndoRequiresRegen(){return eNotImplemented;}

  virtual OdResult  setControlFlag(undoControl flags){return eNotImplemented;}
  virtual undoControl        controlFlag() const{return kNone;}

  virtual void               disableUndoRecording(bool bDisable){}

  virtual bool FillFuncPtrs() { return true; }

  virtual void setDatabase(OdDbDatabase*){}
};

/** Description:
 This template class is a specialization of the OdSmartPtr class for OdDbUndoController object pointers.
*/
typedef OdSmartPtr<OdDbUndoController> OdDbUndoControllerPtr;


#endif // _ODDBUNDOCONTROLLER_INCLUDED_



