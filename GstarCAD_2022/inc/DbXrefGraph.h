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




#ifndef _ODDBXREFGRAPH_H_INCLUDED_
#define _ODDBXREFGRAPH_H_INCLUDED_

#include "TD_PackPush.h"

#include "OdDb.h"
#include "DbGraph.h"
#include "DbObjectId.h"
#include "OdString.h"

/** Description: 
  
    {group:TD_Namespaces}
*/

class OdDbXrefGraphNode;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbXrefGraphNode object pointers.
*/
typedef OdSmartPtr<OdDbXrefGraphNode> OdDbXrefGraphNodePtr;

/** Description:
    This class is a derived class for representing an Xref *database*.

    Remarks:
    OdDbXrefGraph::getFrom() will populate an XrefGraph object with the Xref tree for a specified *database*.

    See also:
    
    o  OdDbGraph
    o  OdDbGraphStack
    o  OdDbXrefGraph
    o  OdDbXrefGraphNode

    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXrefGraphNode : public OdDbGraphNode
{
protected:
 // OdDbXrefGraphNode() : m_status(OdDb::kXrfNotAnXref) {}
public:

  ODRX_DECLARE_MEMBERS(OdDbXrefGraphNode);

  // Gcad(Add)
  OdDbXrefGraphNode(const OdChar* pName = NULL,
        const OdDbObjectId& btrId = OdDbObjectId::kNull,
        OdDbDatabase* pDb = NULL,
        OdDb::XrefStatus status = OdDb::kXrfResolved)
    : OdDbGraphNode(pDb)
    , m_sName()
    , m_blockId(btrId)
    , m_status(status)
    , m_pXData(0)
    , m_statusNotify(OdDb::kXrfNotifyNone) 
  { if(pName) m_sName = pName; }

  virtual ~OdDbXrefGraphNode();
  
  /** Description:
    Returns the *name* associated with this XrefGraphNode object.
  */
  const OdChar * name() const { return (const OdChar *)m_sName; }

  /** Description:
    Returns the Object ID of the BlockTableRecord associated with this XrefGraphNode object.
  */
  OdDbObjectId btrId() const { return m_blockId; }

  /** Description:
    Returns the *database* relevent to this XrefGraphNode object.
  */
  OdDbDatabase* database() const { return (OdDbDatabase*)data(); }
  
  /** Description:
    Sets the *name* associated with this XrefGraphNode object.
    
    Arguments:
    name (I) Name.
  */
  OdResult setName(
    const OdString& name) { m_sName = name; return Oda::eOk; }
  OdResult setName(
    const OdChar* name) { m_sName = name; return Oda::eOk; }
  /** Description:
    Sets the Object ID of the BlockTableRecord associated with this XrefGraphNode object.

    Arguments:
    blockId (I) Object ID of BlockTableRecord.
  */
  void setBtrId(
    const OdDbObjectId& blockId) { m_blockId = blockId; }
   
  /** Description:
    Sets the *database* relevent to this XrefGraphNode object.

    Arguments:
    pDb (I) Pointer to the *database*.
  */
  void setDatabase(
    OdDbDatabase* pDb) { setData(pDb); }
  
  /** Description:
    Returns true if and only if this XrefGraphNode represents an Xref that is not directly referenced
    by the host drawing.
  */
  bool isNested() const { return !isMarkedAs(kFirstLevel); }

  /** Description:
    Returns the status for this XrefGraphNode object.
    
    Remarks:
    xrefStatus() returns one of the following:

    @table
    Name                      Value   Description
    OdDb::kXrfNotAnXref       0       Not an Xref.
    OdDb::kXrfResolved        1       Resolved.
    OdDb::kXrfUnloaded        2       Unloaded.
    OdDb::kXrfUnreferenced    3       Unreferenced.
    OdDb::kXrfFileNotFound    4       File Not Found.
    OdDb::kXrfUnresolved      5       Unresolved.
      
  */  
  OdDb::XrefStatus xrefStatus() const { return m_status; }


  /** Description:
    Sets the status for this XrefGraphNode object.
    
    Remarks:
    xrefStatus must be one of the following:

    @table
    Name                      Value   Description
    OdDb::kXrfNotAnXref       0       Not an Xref.
    OdDb::kXrfResolved        1       Resolved.
    OdDb::kXrfUnloaded        2       Unloaded.
    OdDb::kXrfUnreferenced    3       Unreferenced.
    OdDb::kXrfFileNotFound    4       File Not Found.
    OdDb::kXrfUnresolved      5       Unresolved.
      
  */  
  void setXrefStatus(
    OdDb::XrefStatus xrefStatus) { m_status = xrefStatus; }

  // Gcad(Add)
  OdDb::XrefNotificationStatus xrefNotificationStatus() const { return m_statusNotify; }
  void setXrefNotificationStatus(
    OdDb::XrefNotificationStatus stat) { m_statusNotify = stat; }

  void* xData() { return m_pXData; }
  void  setxData(void *pXData) { m_pXData = pXData; }
  OdResult xrefReadSubstatus() const;
  
private:
  OdString          m_sName;
  OdDbObjectId      m_blockId;
  OdDb::XrefStatus  m_status;
  // OdDbDatabase* uses base class data() member

  // Gcad(Add)
  OdDb::XrefNotificationStatus  m_statusNotify;
  void* m_pXData;
};


/** Description:
    This class is a derived class for representing the Xref tree of a *database*.
    
    Remarks:
    This class uses XrefGraphNode objects to represent an Xref *database* at each *node*.

    See also:
    
    o  OdDbGraph
    o  OdDbGraphStack
    o  OdDbXrefGraph
    o  OdDbXrefGraphNode

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXrefGraph : public OdDbGraph
{
  OdDbXrefGraph(const OdDbXrefGraph&);
  OdDbXrefGraph& operator =(const OdDbXrefGraph&);
public:
  // Gcad(Modify)
  OdDbXrefGraph(OdDbXrefGraphNode* pHostDwg = NULL) : OdDbGraph(pHostDwg) {}

  virtual ~OdDbXrefGraph();
  
  /** Description:
    Returns the XrefGraphNode object corresponding to the specified parameter.
    
    Arguments:
    name (I) Name.
    blockId (I) Object ID of BlockTableRecord.
    pDb (I) Pointer to the *database*.
    nodeIndex (I) Node index. 
    
    Remarks:
    Return a null pointer if the specified *node* is not found.
    
    Note:
    getFrom() will populate an XrefGraph object with the Xref tree of a specified *database*.
  */
  OdDbXrefGraphNode* xrefNode(
    const OdString& name) const;
  OdDbXrefGraphNode* xrefNode(
    OdDbObjectId blockId) const;
  OdDbXrefGraphNode* xrefNode(
    const OdDbDatabase* pDb) const;
  OdDbXrefGraphNode* xrefNode(
    int nodeIndex) const { return(OdDbXrefGraphNode*)node(nodeIndex); }
    
  /** Description:
    Returns the XrefGraphNode associated with the host drawing of this XrefGraph object.
    
    Remarks:
    Returns rootNode().
  */  
  OdDbXrefGraphNode* hostDwg() const { return(OdDbXrefGraphNode*)rootNode(); }  
  /** Description:
    Marks the unresolved Xrefs in this XrefGraph object, and their nested Xrefs, with the kUnresTree flag.
    
    Remarks:
    Not implemented, reserved.
    Returns true if and only if there are any unresolved Xrefs.
  */
  OdBool markUnresolvedTrees();
  
  virtual OdBool findCycles(OdDbGraphNode* pStart = NULL);
  
  // cycle detection
  
  // virtual bool findCycles(OdDbGraphNode* pStart = 0);

  /** Description:
    Populate the specified XrefGraph object with the Xref tree of the specified *database*.
    
    Arguments:
    pDb (I) Pointer to the *database*.
    xrefGraph (O) Receives the Xref tree. 
    includeGhosts (I) Ignored.

    Remarks:
    xrefGraph is *reset* at the start of this function.
  */
  static void getFrom(
    OdDbDatabase* pDb, 
    OdDbXrefGraph& xrefGraph, 
    bool includeGhosts = false);
};

#include "TD_PackPop.h"

#endif // _ODDBXREFGRAPH_H_INCLUDED_


