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

#ifndef _DbEvalGraph_h_Included_
#define _DbEvalGraph_h_Included_

#include "SmartPtr.h"
#include "DbObject.h"
#include "ResBuf.h"
#include "DbEvalVariant.h"

#include "TD_PackPush.h"

// Forward class declarations

class  OdDbEvalGraph;
class  OdDbEvalEdgeInfo;
class  OdDbEvalExpr;
class  OdDbEvalConnectable;
class  OdDbEvalContext;
class  OdDbEvalContextPair;
class  OdDbEvalContextIterator;
class  OdResBuf;
class  OdDbImpEvalContext;
class  OdDbImpEvalContextIterator;
class  OdDbEvalIdMap;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEvalGraph object pointers.
*/
typedef OdSmartPtr<OdDbEvalGraph> OdDbEvalGraphPtr;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEvalContextIterator object pointers.
*/
typedef OdSmartPtr<OdDbEvalContextIterator> OdDbEvalContextIteratorPtr;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEvalExpr object pointers.
*/
typedef OdSmartPtr<OdDbEvalExpr> OdDbEvalExprPtr;

typedef unsigned long OdDbEvalNodeId;

/** Description:
    This template class is a specialization of the OdArray class for OdDbEvalNodeId objects.
*/
typedef OdArray<OdDbEvalNodeId, OdMemoryAllocator<OdDbEvalNodeId> > OdDbEvalNodeIdArray;
/** Description:
    This template class is a specialization of the OdArray class for OdDbEvalEdgeInfo objects.
*/
typedef OdArray<OdDbEvalEdgeInfo> OdDbEvalEdgeInfoArray;
/** Description:
    This template class is a specialization of the OdArray class for OdDbEvalExprPtr object SmartPointers.
*/
typedef OdArray<OdDbEvalExprPtr> OdDbEvalExprPtrArray;
/** Description:
    This template class is a specialization of the OdArray class for OdResBufPtr object SmartPointers.
*/
typedef OdArray<OdResBufPtr> OdResBufArray;
/** Description:
    This template class is a specialization of the OdArray class for OdString object.
*/
typedef OdArray<OdString> OdStringArray;

#include "OdPlatformSettings.h"

#ifdef DYNBLOCKS_DLL_EXPORTS
#define DYNBLOCKS_EXPORT        OD_TOOLKIT_EXPORT
#define DYNBLOCKS_EXPORT_STATIC OD_STATIC_EXPORT
#else                           
#define DYNBLOCKS_EXPORT        OD_TOOLKIT_IMPORT
#define DYNBLOCKS_EXPORT_STATIC OD_STATIC_IMPORT
#endif
/** Description:
    This class implements the behavior of dynamic blocks with a network of interrelated
    elements.

    Remarks:
    Each element (OdDbEvalExpr object) depends on zero or more other elements. The
    dependencies are represented as edges to dependent nodes from the nodes
    on which they depend.

    In response to OdDbEvalGraph::evaluate(), this class traverses the graph and invokes
    OdDbEvalExpr::evaluate() for each of the elements in the graph in the proper order.

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContext
    o  OdDbEvalContextIterator
    o  OdDbEvalContextPair
    o  OdDbEvalEdgeInfo
    o  OdDbEvalExpr
*/
class DYNBLOCKS_EXPORT OdDbEvalGraph : public OdDbObject
{
public:

  enum NodeId {
    kNullNodeId = 0
  };

  ODDB_DECLARE_MEMBERS(OdDbEvalGraph);

  OdDbEvalGraph();
  virtual ~OdDbEvalGraph();

  /* Management */

  /** Description:
    Returns true if and only there is a graph with the specified *key* on the specified object or *database*.
    Arguments:
    pObj (I) Pointer to the object.
    key (I) Graph *key*.
  */
  static bool hasGraph(const OdDbObject* pObj,
    const OdChar* key);

  /** Description:
    Returns the Graph object with the specified *key* on the specified object or *database*.
    Arguments:
    pObj (I) Pointer to the object.
    key (I) Graph *key*.
    openMode (I) Mode in which to open the Graph object.
  */
  static OdDbEvalGraphPtr getGraph(const OdDbObject* pObj,
    const OdString& pKey,
    const OdDb::OpenMode openMode = OdDb::kForRead );

  static OdResult getGraph( const OdDbObject* pObj, 
    const OdChar* key,
    OdDbEvalGraph** pGraph, 
    const OdDb::OpenMode openMode );

  /** Description:
    Creates a graph with the specified *key* on the specified object or *database*.
    Arguments:
    pObj (I) Pointer to the object.
    key (I) Graph *key*.
    Remarks:
    Returns true if and only if successful.
  */
  static OdResult createGraph(OdDbObject* pObj,
    const OdChar* key);


  /** Description:
    Removes the graph with the specified *key* on the specified object or *database*.
    Arguments:
    pObj (I) Pointer to the object.
    key (I) Graph *key*.
    Remarks:
    Returns true if and only if there was a graph with the specified *key*.
  */
  static OdResult removeGraph(OdDbObject* pObj,
    const OdChar* pKey);

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  static bool hasGraph(OdDbDatabase* pDb,
    const OdChar* key);

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  static OdDbEvalGraphPtr getGraph(OdDbDatabase* pDb,
    const OdString& key,
    const OdDb::OpenMode openMode = OdDb::kForRead );

  static OdResult getGraph( OdDbDatabase* pDb, 
    const OdChar* key,
    OdDbEvalGraph** pGraph, 
    const OdDb::OpenMode mode );

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  static OdResult createGraph(OdDbDatabase* pDb,
    const OdChar* key);

  /**
    Arguments:
    pDb (I) Pointer to the *database*.
  */
  static OdResult removeGraph(OdDbDatabase* pDb,
    const OdChar* key);

  static OdResult replaceGraph(OdDbObject* pObj,
    const OdChar* key,
    OdDbObjectId grphId);

  /**  Description:
    Adds a node to this Graph object.
    Arguments:
    pNode (I) Pointer to the GsNode object.
    Remarks:
    Returns the node ID of the newly added node.

    Note:
    For *database* resident Graphs, the user is expected to close returned nodes
    when done for them. This includes the pNode argument.
  */
  // Gcad(Modify): virtual
  OdDbEvalNodeId addNode (OdDbEvalExpr* pNode);
  // Gcad(Add)
  virtual OdResult addNode (OdDbEvalExpr* pNode, OdDbEvalNodeId& id);

  /**  Description:
    Removes a node from this Graph object.
    Arguments:
    nodeId (I) Node ID.
    Remarks:
    Returns true if and only if the node existed.
  */
  virtual OdResult removeNode  (const OdDbEvalNodeId& nodeId);

  /**
    Arguments:
    pNode (I) Pointer to the GsNode object.

    Remarks:
    If pNode is specified, it is assumed the node is open for read or write.
  */
  virtual OdResult removeNode (OdDbEvalExpr* pNode);

  /** Description:
    Returns an array of the node IDs of all nodes in this Graph object.
    Arguments:
    allNodes (O) Receives an array of node IDs.
  */
  // Gcad(Modify): void->OdResult
  virtual OdResult getAllNodes (OdDbEvalNodeIdArray& allNodes) const;

  /** Description:
    Opens and returns a SmartPointer to the specified node in this Graph object.
    Arguments:
    nodeId (I) Node ID.
    openMode (I) Mode in which to open the Node object.
  */
  // Gcad(Modify): virtual
  OdDbEvalExprPtr getNode( const OdDbEvalNodeId& nodeId, OdDb::OpenMode openMode = OdDb::kForRead ) const;
  // Gcad(Add)
  virtual OdResult getNode (const OdDbEvalNodeId& nodeId,
    OdDb::OpenMode mode,
    OdDbObject** ppNode ) const;

  /** Description:
    Adds the specified edge to this Graph object.

    Arguments:
    idFrom (I) Node ID of the node at the start of the edge.
    idTo (I) Node ID of the node at the end of the edge.

    Remarks:
    Creates an outgoing reference to idTo in idFrom, and an incoming reference to idFrom in idTo.

    Throws:
    OdError(eInvalidOwnerObject) if the specified GraphNode objects are not in the same Graph object.
  */
  virtual OdResult addEdge(const OdDbEvalNodeId& idFrom,
    const OdDbEvalNodeId& idTo);

  /**
    Arguments:
    invertible (I) True if and only if the edge is *invertible*.

    Remarks:
    An *invertible* edge can have its originating and terminating nodes swapped
    based on which of the nodes is activated.
  */
  virtual OdResult addEdge(const OdDbEvalNodeId& idFrom,
    const OdDbEvalNodeId& idTo,
    bool  invertible);


  /** Description:
    Removes the specified edge from this Graph object.

    Arguments:
    idFrom (I) Node ID of the node at the start of the edge.
    idTo (I) Node ID of the node at the end of the edge.

    Remarks:
    Creates an outgoing reference to idTo in idFrom, and an incoming reference to idFrom in idTo.

    Throws:
    OdError(eInvalidOwnerObject) if the specified GraphNode objects are not in the same Graph object.
  */
  virtual OdResult removeEdge(const OdDbEvalNodeId& idFrom,
    const OdDbEvalNodeId& idTo);

  /** Description:
    Returns an array of the incoming *edges* for the specified node of this Graph object.

    Arguments:
    nodeId (I) Node ID.
    edges (I) Receives an array of *edges*.
  */
  virtual OdResult getIncomingEdges(const OdDbEvalNodeId& nodeId,
    OdDbEvalEdgeInfoArray& edges) const;

  /** Description:
    Returns an array of the outgoing *edges* for the specified node of this Graph object.

    Arguments:
    nodeId (I) Node ID.
    edges (I) Receives an array of *edges*.
  */
  virtual OdResult getOutgoingEdges(const OdDbEvalNodeId& nodeId,
    OdDbEvalEdgeInfoArray& edges) const;


  /** Description:
    Returns the edge information for the specified edge of this Graph object.
    Arguments:
    idFrom (I) Node ID of the node at the start of the edge.
    idTo (I) Node ID of the node at the end of the edge.
    edgeInfo (O) Receives the edge information.
    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult getEdgeInfo(const OdDbEvalNodeId& idFrom,
    const OdDbEvalNodeId& idTo, OdDbEvalEdgeInfo& edgeInfo) const;


  /** Description:
    Moves the nodes and edges from the specified Graph object to this Graph object.
    Arguments:
    pGraphToAdd (I) Pointer to the Graph object to add.
  */
  virtual OdResult addGraph(OdDbEvalGraph* pGraphToAdd);

  virtual OdResult addGraph(OdDbEvalGraph* pGraphToAdd, 
    OdDbEvalIdMap*& idMap);

  /* Evaluation */

  /** Description:
    Evaluates this Graph object.

    Remarks:
    Evaluation is accomplished by traversing the activated nodes on the Graph,
    invoking OdDbEvalExpr::evaluate() on each of the visited nodes.

    Nodes may be activated with either the activate() method, or by
    supplying an activatedNodes argument.

    Note:
    Nodes not activated are deactivated.

    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult evaluate() const;

  /**
    Arguments:
    pContext (I) Pointer to the Context object for the evaluation.
  */
  virtual OdResult evaluate(
    const OdDbEvalContext* pContext) const;

  /**
    Arguments:
    pActivatedNodes (I) Pointer to an array of node IDs to activate.
  */
  virtual OdResult evaluate(
    const OdDbEvalContext* pContext,
    const OdDbEvalNodeIdArray* pActivateNodes) const;


  /** Description:
    Activates the specified nodes in this Graph object.

    Arguments:
    activatedNodes (I) Array of node IDs to activate.

    Note:
    Nodes not activated are deactivated.

    Remarks:
    Returns true if and only if the graph is non-cyclic.
  */
  virtual OdResult activate(
    const OdDbEvalNodeIdArray& activatedNodes) const;


  /**
    Arguments:
    pActiveSubgraph (I) Pointer to an array to receive the node IDs that would visited, given the activated nodes.
  */
  virtual OdResult activate(
    const OdDbEvalNodeIdArray& activatedNodes,
    OdDbEvalNodeIdArray* pActiveSubgraph) const;

  /**
    Arguments:
    pCycleNodes (I) Pointer to an array to receive the node IDs that would be cyclic, given the activated nodes.
  */
  virtual OdResult activate(
    const OdDbEvalNodeIdArray& activatedNodes,
    OdDbEvalNodeIdArray* pActiveSubgraph,
    OdDbEvalNodeIdArray* pCycleNodes) const;


  /** Description:
    Returns true if and only if the specified node in this Graph object is active.

    Arguments:
    nodeId (I) Node ID.
    isActive (I) True if and only if node is active.

    Note:
    The return value of this function is always true. The active state of the node is returned via isActive.
  */
  virtual OdResult getIsActive(const OdDbEvalNodeId& nodeId,
    bool& isActive) const;

  /** Description:
    Returns true if and only if the specified Graph object is equal to this one.

    Arguments:
    pOther (I) Pointer to the other Graph object.

    Remarks:
    Returns true if and only if

                this->subgraph(pOther) && pOther->subgraph(this)
  */
  virtual bool equals(const OdDbEvalGraph* pOther) const;


  /** Description:
    Returns true if and only if the specified Graph object is a subgraph of this one.

    Arguments:
    pOther (I) Pointer to the other Graph object.
  */
  virtual bool isSubgraphOf(const OdDbEvalGraph* pOther) const;

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler) ODRX_OVERRIDE;
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const ODRX_OVERRIDE;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler) ODRX_OVERRIDE;
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const ODRX_OVERRIDE;
  virtual OdResult applyPartialUndo(OdDbDwgFiler* pFiler, OdRxClass* pClassObj) ODRX_OVERRIDE;
  virtual OdResult copyFrom(const OdRxObject* p) ODRX_OVERRIDE;
  virtual OdResult postInDatabase(OdDbObjectId& objId, OdDbDatabase* pDb);
};


/** Description:
    This class holds the directed edge information between pairs of nodes in an OdDbEvalGraph instance.

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContext
    o  OdDbEvalContextIterator
    o  OdDbEvalContextPair
    o  OdDbEvalExpr
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalEdgeInfo
{
public:
  OdDbEvalEdgeInfo()
    : mFlags(0), mRefCount(0)
  {
    mIdFrom = OdDbEvalGraph::kNullNodeId;
    mIdTo = OdDbEvalGraph::kNullNodeId;
  }

  /**
    Arguments:
    fromId (I) Node Id of the "from" Node object sharing the edge.
    toId (I) Node Id of the "to" Node object sharing the edge.
    flags (I) For internal use only.
    count (I) Number of times this edge was added *to* the graph.
  */
  OdDbEvalEdgeInfo(OdDbEvalNodeId fromId,
    OdDbEvalNodeId toId,
    long           flags,
    unsigned long  count)
    : mIdFrom(fromId), mIdTo(toId), mFlags(flags), mRefCount(count)
  {}

  /** Description:
    Returns the Object ID of the originating node of this edge.
  */
  OdDbEvalNodeId from () const;

  /** Description:
    Returns the Object ID of the terminating node of this edge.
  */
  OdDbEvalNodeId to () const;
  /** Description:
    Returns the number of times this edge was added *to* the graph.
  */
  unsigned long refCount() const;

  /** Description:
    Returns true if and only if this edge is invertible.
    Remarks:
    An *invertible* edge can have its originating and terminating nodes swapped
    based on which of the nodes is activated.
  */
  bool isInvertible () const;
  /** Description:
    Returns true if and only if this edge is suppressed.
    Remarks:
    As suppressed edge is temporarily removed *from* the graph during activation or evaluation. This applies only to
    invertible pairs of edges.
  */
  bool isSuppressed  () const;

  bool operator == (const OdDbEvalEdgeInfo& other) const;

private:
  OdDbEvalNodeId mIdFrom;
  OdDbEvalNodeId mIdTo;
  long mFlags;
  unsigned long mRefCount;
};


/** Description:
    This class represents single nodes in OdDbEvalGraph objects.

    Remarks:
    Each node reprsents an action or expression. The OdDbEvalGraph object calls each owned node's
    evaluate() method while traversing the graph within the OdDbEvalGraph::evaluate() method.

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContext
    o  OdDbEvalContextIterator
    o  OdDbEvalContextPair
    o  OdDbEvalEdgeInfo
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalExpr : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbEvalExpr);

  OdDbEvalExpr();
  virtual ~OdDbEvalExpr();

  /** Description:
    Opens the OdDbEvalGraph object that owns this Node object.

    Arguments:
    openMode (I) Mode in which to open the Graph object.

    Remarks:
    Returns a SmartPointer to the opened OdDbEvalGraph if successful, otherwise a null SmartPointer.
  */
  OdDbEvalGraphPtr getGraph( OdDb::OpenMode openMode = OdDb::kForRead ) const;

  OdResult getGraph(OdDbEvalGraph** pGraph, OdDb::OpenMode mode) const;

  /** Description:
    Returns the node ID of this Node object.

    Remarks:
    An unique ID is assigned when a Node object it added to a Graph.

    Returns OdDbGraph::kNullId if this Node object is not graph-resident.
  */
  OdDbEvalNodeId nodeId() const;

  /** Description:
    Notification function called whenever this Node object has been added to a Graph object.

    Arguments:
    pGraph (I) Pointer to the Graph object.

    Remarks:
    Called by OdDbEvalGraph::addNode().

    This function is called after the operation.
  */
  virtual void addedToGraph (OdDbEvalGraph* pGraph);

  /** Description:
    Notification function called whenever this Node object has been removed a Graph object.

    Arguments:
    pGraph (I) Pointer to the Graph object.

    Remarks:
    Called by OdDbEvalGraph::removeNode().

    This function is called after the operation.
  */
  virtual void removedFromGraph (OdDbEvalGraph* pGraph);


  /** Description:
    Notification function called whenever a Node object with a shared edge
    to this Node object has been removed a Graph object.

    Arguments:
    adjNodeId (I) Node Id of the adjacent Node object.

    Remarks:
    Called by OdDbEvalGraph::removeNode().

    This function is called after the operation.
  */
  virtual void adjacentNodeRemoved (const OdDbEvalNodeId& adjNodeId);


  /** Description:
    Notification function called whenever an edge of this Node object has been removed.

    Arguments:
    adjEdgeNodeId (I) Node Id of the Node object sharing the edge.

    Remarks:
    Called by OdDbEvalGraph::removeEdge().

    This function is called after the operation.
  */
  virtual void adjacentEdgeRemoved (const OdDbEvalNodeId& adjEdgeNodeId);


  /** Description:
    Notification function called whenever an edge has been added the Graph object.

    Arguments:
    fromId (I) Node Id of the "from" Node object sharing the edge.
    toId (I) Node Id of the "to" Node object sharing the edge.
    isInvertible (I) True if and only if the edge the edge is invertible.
    Remarks:
    Called by OdDbEvalGraph::addEdge().

    When the edge is invertible, this function is called twice.

    This function is called after the operation.
  */
  virtual void adjacentEdgeAdded (const OdDbEvalNodeId& fromId,
    const OdDbEvalNodeId& toId,
    bool isInvertible);


  /** Description:
    Notification function called whenever this Node object
    is about to be moved to another Graph object.

    Arguments:
    pFromGraph (I) Pointer to the Graph object from which this Node object will be moved.

    Remarks:
    Called by OdDbEvalGraph::addGraph().

    This function is called before the operation.
  */
  virtual void movedFromGraph (OdDbEvalGraph* pFromGraph);

  /** Description:
    Notification function called whenever this Node object
    has been moved to another Graph object.

    Arguments:
    pIntoGraph (I) Pointer to the Graph object into which this Node object was moved.

    Remarks:
    Called by OdDbEvalGraph::addGraph().

    This function is called after the operation.
  */
  virtual void movedIntoGraph (OdDbEvalGraph* pIntoGraph);


  virtual void remappedNodeIds (OdDbEvalIdMap& idMap);

  /** Description:
    Notification function called whenever a Node object
    has been *copied* to another Graph object.

    Arguments:
    pIntoGraph (I) Pointer to the Graph object into which a Node object was *copied*.

    Remarks:
    Called by OdDbEvalGraph::copyFrom().

    This function is called after the operation.
  */
  virtual void copiedIntoGraph(OdDbEvalGraph* pIntoGraph);

  /** Description:
    Returns true if and only if this Node object can be *activated*.

    Remarks:
    The default implementation of this function always returns true.
  */
  virtual bool isActivatable();

  /** Description:
    Notification function called whenever this Node object has been *activated*.

    Arguments:
    argumentActivateList (I) Array of node IDs being *activated*.

    Remarks:
    Called by OdDbEvalGraph::activate() or by OdDbEvalGraph::evaluate().

    When the edge is invertible, this function is called twice.

    This function is called after the operation.
  */
  virtual void activated           (OdDbEvalNodeIdArray& argumentActiveList);

  /** Description:
    Notification function called whenever the Graph object is about to be traversed.

    Arguments:
    nodeIsActive (I) True if and only if this Node object has been *activated*.

    Remarks:
    Called by OdDbEvalGraph::evaluate().

    This function is called before the operation.
  */
  virtual void graphEvalStart (bool nodeIsActive);


  /** Description:
    Notification function called whenever the Graph object has been traversed.

    Arguments:
    nodeIsActive (I) True if and only if this Node object has been *activated*.

    Remarks:
    Called by OdDbEvalGraph::evaluate().

    This function is called after the operation.
  */
  virtual void graphEvalEnd(bool nodeIsActive);

  /** Description:
    Notification function called whenever the Graph object travesal is been terminated.

    Arguments:
    nodeIsActive (I) True if and only if this Node object has been *activated*.

    Remarks:
    Called by OdDbEvalGraph::evaluate().

    This function is called after the operation.
  */
  virtual void graphEvalAbort(bool nodeIsActive);

  /** Description:
    Evaluates the expression represented by this Node object.
    Arguments:
    evalContext (I) Evaluation *context*.

    Remarks:
    Called by OdDbEvalGraph::evaluate().

    Returns true if and only if successful. Returning false terminates the Traversal.

    evalContext may be NULL.
  */
  virtual OdResult evaluate(const OdDbEvalContext* evalContext);

  /** Description
    Returns true if and only if the specified Node object is equal to this Node object.

    Arguments:
    pOther (I) Pointer to the other Node object.
    Note:
    The default implementation of this function does nothing but
    throw an eNotImplemented error.
  */
  virtual bool equals(const OdDbEvalExpr* pOther) const;

  /** Description:
    Returns the *value* of the evaluated expression of this Node object.
    Remarks:
    The *value* is updated with a call to OdDbEvalExpr::evaluate().
  */
  //OdResBufPtr value() const;
  OdDbEvalVariant value() const;

  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  virtual OdResult postInDatabase(OdDbObjectId& objId, OdDbDatabase*pDb);

protected:

  OdResBufPtr m_lastValue;
  friend class OdDbEvalExprImpl;
};


/** Description:
    This class implements a runtime inspection interface for OdDbEvalExpr objects.

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalContext
    o  OdDbEvalContextIterator
    o  OdDbEvalContextPair
    o  OdDbEvalEdgeInfo
    o  OdDbEvalExpr
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalConnectable : public OdDbEvalExpr
{
public:
  ODDB_DECLARE_MEMBERS(OdDbEvalConnectable);

  virtual ~OdDbEvalConnectable();

  /** Description:
    Returns an array of Connection names for this Connectable object.
    Arguments:
    connectionNames (O) Receives an array of Connection names.
  */
  virtual OdResult getConnectionNames (OdStringArray& connectionNames) const;

  /** Description:
    Returns true if and only if this Connectable object has a connection with the specified name.
    Arguments:
    connectionName (I) Connection name.
  */
  virtual bool hasConnectionNamed (const OdString& connectionName) const;


  /** Description:
    Returns the type of the specified connection for this Connectable object.
    Arguments:
    connectionName (I) Connection name.
    connectionType (O) Receives the connection type.
    Remarks:
    Returns true if and only if a connection with the specified name exists.
  */
  virtual OdResult getConnectionType  (
    const OdString& connectionName,
    OdDb::DwgDataType& type) const;


  /** Description:
    Returns the *value* of the specified connection for this Connectable object.
    Arguments:
    connectionName (I) Connection name.
    Remarks:
    Returns a NULL SmartPointer if a connection with the specified name does not exist.
  */
  virtual OdResBufPtr getConnectionValue( const OdString& connectionName) const;
  virtual OdResult getConnectionValue(const OdString& connectionName, OdDbEvalVariant& connectionValue) const;


  /** Description:
    Sets the *value* of the specified connection for this Connectable object.
    Arguments:
    connectionName (I) Connection name.
    pValue (I) Pointer to the *value*.
    Remarks:
    Returns true if and only if a connection with the specified name exists.
  */
  virtual OdResult setConnectionValue ( const OdString& connectionName, const OdDbEvalVariant& pValue);


  /** Description:
    Connects this Connectable object to the specified Connectable object.

    Remarks:
    Both objects must graph-resident.

    Arguments:
    thisConnectionName (I) Connection name on this object.
    sourceConnectableId (I) Object ID of the other Connectable object.
    sourceConnectionName (I) Connection name on the other Connectable object.
    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult connectTo (
    const OdString&      thisConnectionName,
    const OdDbEvalNodeId sourceConnectableId,
    const OdString&      sourceConnectionName);


  /** Description:
    Disconnects this Connectable object from the specified Connectable object.

    Remarks:
    Both objects must graph-resident.

    Arguments:
    thisConnectionName (I) Connection name on this object.
    sourceConnectableId (I) Object ID of the other Connectable object.
    sourceConnectionName (I) Connection name on the other Connectable object.
    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult disconnectFrom (
    const OdString&      thisConnectionName,
    const OdDbEvalNodeId sourceConnectableId,
    const OdString&      sourceConnectionName);

  /** Description:
    Returns true if and only if a connection is allowed from this Connectable object
    to the specified Connectable object.

    Remarks:
    Both objects must graph-resident.

    Arguments:
    thisConnectionName (I) Connection name on this object.
    sourceConnectableId (I) Object ID of the other Connectable object.
    sourceConnectionName (I) Connection name on the other Connectable object.
  */
  virtual bool connectionAllowed (
    const OdString&      thisConnectionName,
    const OdDbEvalNodeId sourceConnectableId,
    const OdString&      sourceConnectionName) const;


  /* Description:
    Returns an array of Connectable objects to which this Connectable object
    is connected.

    Arguments:
    thisConnectionName (I) Connection name on this object.
    connectedObjects (O) Receives an array of object IDs.
    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult getConnectedObjects (
    const OdString&      thisConnectionName,
    OdDbEvalNodeIdArray& connectedObjects) const;

  /** Description:
    Returns an array Connection names shared between this OdDbEvalConnectable object and another.

    Arguments:
    thisConnectionName (I) Connection name on this object.
    sourceConnectableId (I) ID of the other Connectable object.
    sourceConnectionNames (O) Receives an array of connection names.

    Remarks:
    Returns true if and only if successful.
  */
  virtual OdResult getConnectedNames (
    const OdString&      thisConnectionName,
    const OdDbEvalNodeId sourceConnectableId,
    OdStringArray&       sourceConnectionNames) const;
protected:

  OdDbEvalConnectable();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbEvalConnectable object pointers.
*/
typedef OdSmartPtr<OdDbEvalConnectable> OdDbEvalConnectablePtr;

/** Description:
    This class represents application data used during the evaluation of an OdDbEvalGraph object.

    Remarks:
    The graph passes the OdDbEvalContext object passed to OdDbEvalGraph::evaluate() to each node
    in the graph traversed as a result of calling OdDbEvalExpr::evaluate().

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContextIterator
    o  OdDbEvalContextPair
    o  OdDbEvalEdgeInfo
    o  OdDbEvalExpr
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalContext : public OdRxObject
{
public:

  OdDbEvalContext();


  virtual ~OdDbEvalContext();

  ODRX_DECLARE_MEMBERS(OdDbEvalContext);


  /** Description:
    Inserts the specified ContextPair into this Context object.
    Arguments:
    pair (I) ContextPair to insert.
    Remarks:
    Replaces any ContextPair with the same *key*.
  */
  virtual void insertAt (const OdDbEvalContextPair& pair);


  /** Description:
    Removes the ContextPair with the specified *key* from this Context object.
    Arguments:
    key (I) Key of ContextPair to remove.
  */
  virtual void removeAt (const OdChar* key);


  /** Description:
    Returns the ContextPair with the specified *key* from this Context object.
    Arguments:
    pair (I/0) Specifies / receives the ContextPair.

    Remarks:
    pair is initialized with the *key* of the ContextPair to return. If the *key* exists in this Context object,
    its associated *value* replaces the *value* in the specified ContextPair.

    Returns true if and only if the pari exists.
  */
  virtual OdResult getAt (OdDbEvalContextPair& pair) const;


  /** Description:
    Returns an Iterator object that can be used to traverse this Context object.
  */
  OdDbEvalContextIteratorPtr newIterator(ODSYSDEF) const;
#ifdef ODARXDEF
  virtual OdDbEvalContextIterator* newIterator() const;
#endif

private:
  OdDbImpEvalContext* m_pImp;
  friend class OdDbImpEvalContextIterator;
};

/** Description:
    This class represents *key* - *value* pairs stored in an OdDbEvalContext object.

    Remarks:
    Values stored are void pointers. Neither OdDbEvalContext nor OdDbEvalContextPair
    manage the memory allocated to the values.

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContext
    o  OdDbEvalContextIterator
    o  OdDbEvalEdgeInfo
    o  OdDbEvalExpr
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalContextPair
{
public:

  OdDbEvalContextPair();

  /**
    Arguments:
    key (I) ContextPair *key*.
    value (I) ContextPair *value*.
  */
  OdDbEvalContextPair(const OdChar* key, void *value);

  virtual ~OdDbEvalContextPair();

  /** Description:
    Sets the *key* of this ContextPair object.
    Arguments:
    key (I) ContextPair *key*.
  */
  void setKey (const OdChar* key);

  /** Description:
    Returns the *key* of this ContextPair object.
    Arguments:
    key (I) ContextPair *key*.
  */
  const OdChar* key () const;

  /** Description:
    Sets the *value* of this ContextPair object.
    Arguments:
    value (I) ContextPair *value*.

    Remarks:
    It is up to the caller to allocate and free memory pointed to by value.
  */
  void setValue (void* value);

  /** Description:
    Returns the *value* of this ContextPair object.
    Arguments:
    value (I) ContextPair *value*.
  */
  void*       value    () const;

private:
  OdString mKey;
  void* mValue;
};


/** Description:
    This class implements iterators for OdDbEvalContextPair objects in an OdDbEvalContext instance.

    Remarks:
    Instances are returned by OdDbEvalContext::newIterator()

    Library: TD_DynBlocks
    {group:OdDb_Classes}

    See also:
    o  OdDbEvalConnectable
    o  OdDbEvalContext
    o  OdDbEvalContextPair
    o  OdDbEvalEdgeInfo
    o  OdDbEvalExpr
    o  OdDbEvalGraph
*/
class DYNBLOCKS_EXPORT OdDbEvalContextIterator : public OdRxObject
{
public:
  OdDbEvalContextIterator();

  virtual ~OdDbEvalContextIterator();

  ODRX_DECLARE_MEMBERS(OdDbEvalContextIterator);

  /** Description:
    Sets this Iterator object to reference the EvalContextPair that it would normally return first.

    Remarks:
    Allows multiple traversals of the Iterator list.
  */
  virtual void start();

  /** Description:
    Increments this Iterator object.
  */
  virtual bool   next();

  /** Description:
    Returns true if and only if the traversal by this Iterator *object* is complete.
  */
  virtual bool   done() const;

  /** Description:
    Returns the ContextPair pointed to by this Iterator Object.
  */
  virtual OdDbEvalContextPair contextPair() const;

private:
  OdDbImpEvalContextIterator* m_pImp;
  friend class OdDbImpEvalContext;
};

#include "TD_PackPop.h"

#endif
