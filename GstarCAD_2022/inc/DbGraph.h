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




#ifndef _ODDBGRAPH_H_INCLUDED_
#define _ODDBGRAPH_H_INCLUDED_

#include "TD_PackPush.h"

#include "OdaDefs.h"
#include "RxObject.h"
#include "OdArray.h"

class OdDbGraph;
class OdDbGraphNode;

/** Description:
    This template class is a specialization of the OdArray class for OdDbGraphNode object pointers.
*/
typedef OdArray<OdDbGraphNode*, OdMemoryAllocator<OdDbGraphNode*> > OdDbGraphNodeArray;

/** Description:
    This class implements generic node objects for generic graphs.
    
    Remarks:
    A graph consists of a collection of nodes bi-directionally linked by directional edges.
    
    An edge connected to a *node* is represented as a pointer or reference to the *node* at the other
    end of the edge.
 
    References are classified as either incoming or outgoing. Every incoming reference has
    a corresponding outgoing reference and vice versa.

    Each GraphNode object can have any number of references associated with it, enabling the
    implementation of any graph structure.

    See also:
    
    o  OdDbGraph
    o  OdDbGraphStack
    o  OdDbXrefGraph
    o  OdDbXrefGraphNode
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGraphNode : public OdRxObject
{
  friend class OdDbGraph;

public:
  ODRX_DECLARE_MEMBERS(OdDbGraphNode);

  // Gcad(Modify)
  OdDbGraphNode(void* pData = NULL) : m_pData(pData), m_flags(0), m_pOwner(0) {}

  virtual ~OdDbGraphNode();
  
  enum Flags
  {
    kNone         = 0x00, // None.
    kVisited      = 0x01, // Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    kOutsideRefed = 0x02, // Used internally by Xref detach.
    kSelected     = 0x04, // User selection. Set by getOutgoing.
    kInList       = 0x08, // Is *in* list. Set by getOutgoing.
    kListAll      = 0x0E, // Used to *clear* kSelected, kInList, and kOutsideRefed.
    kFirstLevel   = 0x10, // The *node* is connected to the root *node*. Read Only.
    kUnresTree    = 0x20, // The tree is unresolved.
    kAll          = 0x2F  // Used to *clear* all but kFirstLevel.
  };
  
  /** Description:
    Returns the *data* associated with this GraphNode object.
  */
  void* data() const { return m_pData; }

  /** Description:
    Sets the *data* associated with this GraphNode object.
    
    Remarks:
    pData (I) Pointer to the *data*.
  */
  void setData(
    void* pData) { m_pData = pData; }
  
  /** Description:
    Return the number of outgoing references associated with this GraphNode object.
  */
  int numOut() const { return m_outgoing.size(); }
  
  /** Description:
    Return the number of incoming references associated with this GraphNode object.
  */
  int numIn() const { return m_incoming.size(); } 
   
  /** Description:
    Returns the specified incoming reference of this GraphNode object.
    
    Arguments:
    refIndex (I) Reference index. 
    
    Remarks:
    Returns a null pointer if and only if the index is not valid.
  */
  OdDbGraphNode* in(
    int refIndex) const { return m_incoming.at(refIndex); }

  /** Description:
    Returns the specified outgoing reference of this GraphNode object.
    
    Arguments:
    refIndex (I) Reference index. 
    Remarks:
    Returns a null pointer if and only if the index is not valid.
  */
  OdDbGraphNode* out(
    int refIndex) const { return m_outgoing.at(refIndex); }
  
  /** Description:
    Creates an outgoing reference, *in* this GraphNode object, to the specified GraphNode object.  
    
    Arguments:
    pTo (I) Pointer to the outgoing GraphNode.

    Remarks:
    Creates an incoming reference to this GraphNode object *in* *pTo.
    
    Throws:
    OdError(eInvalidOwnerObject) if the specified GraphNode object are not *in* the same Graph object as this
    GraphNode object.
    
    See also:
    OdDbGraph::addEdge

    Gcad(Modify): void->OdResult
  */
  OdResult addRefTo(
    OdDbGraphNode* pTo);
  
  /** Description:
    Removes the outgoing reference, *in* this GraphNode object, to the specified GraphNode object.  
    
    Arguments:
    pTo (I) Pointer to the outgoing GraphNode.

    Remarks:
    Removes the incoming reference to this GraphNode object *in* the outgoing GraphNode object.
    
    The specified GraphNode object must be part of the same graph as this GraphNode object.

    Gcad(Modify): void->OdResult
  */
  OdResult removeRefTo(
    OdDbGraphNode* pNode);

  /** Description:
    Removes all references *in* and to this GraphNode object.  
    
    Remarks:
    Always called by ~OdDbGraphNode().

    Gcad(Modify): void->OdResult
  */
  OdResult disconnectAll();
  
  /** Description:
    Returns the Graph object to which this GraphNode object is attached.
  */
  OdDbGraph* owner() const { return m_pOwner; }
  
  /** Description:
    Returns true if and only if the all the specified set flag bits are set *in* this GraphNode object.
    
    Arguments:
    flags (I) Flag bits.
    
    Remarks:
    flags must be a combination of one or more of the following:
    
    @table
    Name              Value    Description
    kNone             0x00     None.
    kVisited          0x01     Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    kOutsideRefed     0x02     Used internally by Xref detach.
    kSelected         0x04     User selection. Set by getOutgoing.
    kInList           0x08     Is *in* list. Set by getOutgoing.
    kListAll          0x0E     Used to *clear* kSelected, kInList, kOutsideRefed.
    kFirstLevel       0x10     The *node* is connected to the root *node*. Read Only.
    kUnresTree        0x20     The tree is unresolved.
    kAll              0x2F     Used to *clear* all but kFirstLevel.
  */
  bool isMarkedAs(
    OdUInt8 flags) const { return ((m_flags & flags)==flags); }
  
  /** Description:
    Sets the specified set flag bits *in* this GraphNode object.
    
    Arguments:
    flags (I) Flag bits.
    
    Remarks:
    flags must be a combination of one or more of the following:
    
    @table
    Name              Value    Description
    kNone             0x00     None.
    kVisited          0x01     Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    kOutsideRefed     0x02     Used internally by Xref detach.
    kSelected         0x04     User selection. Set by getOutgoing.
    kInList           0x08     Is *in* list. Set by getOutgoing.
    kListAll          0x0E     Used to *clear* kSelected, kInList, kOutsideRefed.
    kFirstLevel       0x10     The *node* is connected to the root *node*. Read Only.
    kUnresTree        0x20     The tree is unresolved.
    kAll              0x2F     Used to *clear* all but kFirstLevel.

    Gcad(Modify): void->OdResult
  */
  OdResult markAs(
    OdUInt8 flags)
  {
    if(!GETBIT(flags, kFirstLevel))
    {
      m_flags |= flags;
      return Oda::eOk;
    }
    else
    {
      return Oda::eInvalidInput;
    }
  }

  /** Description:
    Clears the specified set flag bits *in* this GraphNode object.
    
    Arguments:
    flags (I) Flag bits.
    
    Remarks:
    flags must be a combination of one or more of the following:
    
    @table
    Name              Value    Description
    kNone             0x00     None.
    kVisited          0x01     Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    kOutsideRefed     0x02     Used internally by Xref detach.
    kSelected         0x04     User selection. Set by getOutgoing.
    kInList           0x08     Is *in* list. Set by getOutgoing.
    kListAll          0x0E     Used to *clear* kSelected, kInList, kOutsideRefed.
    kFirstLevel       0x10     The *node* is connected to the root *node*. Read Only.
    kUnresTree        0x20     The tree is unresolved.
    kAll              0x2F     Used to *clear* all but kFirstLevel.

    Gcad(Modify): void->OdResult
  */
  OdResult clear(
    OdUInt8 flags)
  {
    if(!GETBIT(flags, kFirstLevel))
    {
      m_flags &= (~flags);
      return Oda::eOk;
    }
    else
    {
      return Oda::eInvalidInput;
    }
  }
    
  /** Description:
    Marks this GraphNode object and all nested outgoing GraphNode objects with the specified flags.
    
    Arguments:
    flags (I) Flag bits.
    pNodeArray (I) Pointer to a GraphNode array.  

    Remarks:
    If pNodeArray is specified, this function appends this GraphNode object and all 
    nested outgoing GraphNode objects, to the specified array. While tranversing a branch,
    if any GraphNode object already has the flag bits set, the branch is no longer followed.

    The user must *clear* the *flags* with OdDbGraph::clearAll() or OdDbGraphNode::clear() when done with them.
    
    flags must be a combination of one or more of the following:
    
    @table
    Name              Value    Description
    kNone             0x00     None.
    kVisited          0x01     Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    kOutsideRefed     0x02     Used internally by Xref detach.
    kSelected         0x04     User selection. Set by getOutgoing.
    kInList           0x08     Is *in* list. Set by getOutgoing.
    kListAll          0x0E     Used to *clear* kSelected, kInList, kOutsideRefed.
    kFirstLevel       0x10     The *node* is connected to the root *node*. Read Only.
    kUnresTree        0x20     The tree is unresolved.
    kAll              0x2F     Used to *clear* all but kFirstLevel.
    
    Note:
    This function is not implemented, and will generate a link error if you reference it.

    Gcad(Modify): void->OdResult
  */
  OdResult markTree(
    OdUInt8 flags, 
    OdDbGraphNodeArray* pNodeArray = 0);
  
  // Circularity detection methods
  
  /** Description:
    Returns the number of outgoing cyclical references associated with this GraphNode object.
    
    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  int numCycleOut() const { return m_cycleOut.size(); }

  /** Description:
    Returns the number of incoming cyclical references associated with this GraphNode object.
    
    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  int numCycleIn() const { return m_cycleIn.size(); }
  
  /** Description:
    Returns the specified incoming cyclical reference of this GraphNode object.
    
    Arguments:
    refIndex (I) Reference index. 

    Remarks:
    Returns a null pointer if and only if the index is not valid.

    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  OdDbGraphNode* cycleIn(
    int refIndex) const { return m_cycleIn[refIndex]; }

  /** Description:
    Returns the specified outgoing cyclical reference of this GraphNode object.
    
    Arguments:
    refIndex (I) Reference index. 

    Remarks:
    Returns a null pointer if and only if the index is not valid.

    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  OdDbGraphNode* cycleOut(
    int refIndex) const  { return m_cycleOut[refIndex]; }
  
  /** Description:
    Returns the next outgoing cyclical reference of this GraphNode object.
    
    Remarks:
    This function returns cycleOut(0).

    Remarks:
    Returns a null pointer if cycleOut(0) == 0.

    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  OdDbGraphNode* nextCycleNode() const { return cycleOut(0); }
  
  /** Description:
    Returns true if and only if this GraphNode object is part of a cyclical reference.

    Note:
    This function returns valid results only if OdDbGraph::findCycles() has been called
    with no intervening changes to the graph.
  */
  bool isCycleNode() const { return (numCycleOut() != 0 || numCycleIn() != 0); }

  // Gcad(Add): setEdgeGrowthRate
  void setEdgeGrowthRate(int outEdgeRate, int inEdgeRate)
  {
    m_outgoing.setGrowLength(outEdgeRate);
    m_incoming.setGrowLength(inEdgeRate);
  }
  
private:
  // These are currently not supported
  //
  OdDbGraphNode(const OdDbGraphNode&);
  OdDbGraphNode& operator = (const OdDbGraphNode&);

  void setFirstLevel (bool fl)
  { SETBIT(m_flags, kFirstLevel, fl); }

  OdResult setOwner(
    OdDbGraph* pGraph) 
  {
    if(m_pOwner)
    {
      ODA_FAIL();
      return Oda::eInvalidOwnerObject;
    }
    m_pOwner = pGraph;
    return Oda::eOk;
  }
  
  friend struct if_leaf_push_to;
  friend struct clear_cycles;
  friend void break_edge(OdDbGraphNode* , OdDbGraphNode* );
  
  void*               m_pData;
  OdUInt8             m_flags;
  OdDbGraphNodeArray  m_outgoing;
  OdDbGraphNodeArray  m_incoming;
  OdDbGraph*          m_pOwner;
  OdDbGraphNodeArray  m_cycleOut;
  OdDbGraphNodeArray  m_cycleIn;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class template for OdDbGraphNode object pointers.
*/
typedef OdSmartPtr<OdDbGraphNode> OdDbGraphNodePtr;

/** Description:
    This class implements stacks for OdDbGraphNode object pointers.
    Library: TD_Db

    {group:OdDb_Classes}
*/
class OdDbGraphStack
{
public:
  /**
    Arguments:
      initPhysicalLength (I) Initial Physical Length.
      initGrowLength (I) Initial Grow Length.


    Remarks:
    Physical Length is the maximum number of entries *in* this Stack object before it automatically grows.
    
    Grow Length is the number of entries by which the Physical Length will grow as required.
  */
  OdDbGraphStack(
    int initPhysicalLength = 0, 
    int initGrowLength = 8)
    : m_stack(initPhysicalLength, initGrowLength) {}

  ~OdDbGraphStack() {}

  /** Description:
    Pushes the specified GraphNode onto this Stack object.
    
    Arguments:
    pNode (I) Pointer to the node to be pushed.

    Gcad(Modify): void->OdResult
  */
  OdResult push(
    OdDbGraphNode* pNode) 
  {
    if(!pNode) return Oda::eNullObjectPointer;
    m_stack.push_back(pNode); 
    return Oda::eOk;
  }

  /** Description:
    Pops and returns the GraphNode at the *top* of this Stack object.
    
    Remarks:
    Returns a null pointer if this Stack object is empty.
  */
  OdDbGraphNode* pop()
  {
    if(!isEmpty())
    {
      OdDbGraphNode* pRes = top();
      m_stack.removeLast();
      return pRes;
    }
    return 0;
  }


  /** Description:
    Returns the OdDbGraphNode at the *top* of this Stack object.

    Remarks:
    Returns a null pointer if this Stack object is empty.
  */
  OdDbGraphNode* top() const { return isEmpty() ? 0 : m_stack.last(); }

  /** Description:
    Returns true if and only if this Stack object is empty.
  */
  bool isEmpty() const { return m_stack.empty(); }
private:
  OdDbGraphNodeArray  m_stack;
};

/** Description:
    This class implements generic graph objects.
    
    Remarks:
    A graph consists of a collection of nodes bi-directionally linked by directional edges.
    
    An edge connected to a *node* is represented as a pointer or reference to the *node* at the other
    end of the edge.
 
    References are classified as either incoming or outgoing. Every incoming reference has
    a corresponding outgoing reference and vice versa.

    Each GraphNode object can have any number of references associated with it, enabling the
    implementation of any graph structure.

    See also:
    
    o  OdDbGraphNode
    o  OdDbGraphStack
    o  OdDbXrefGraph
    o  OdDbXrefGraphNode
    
    Library: TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbGraph
{
  friend class OdDbGraphNode;

public:
  // Gcad(Modify)
  OdDbGraph(OdDbGraphNode* pRoot = NULL) : m_bDirty(false), m_nNonCycleNodes(0) { if(pRoot) addNode(pRoot); }

  virtual ~OdDbGraph();
  
  /** Description:
    Returns the specified GraphNode object of this Graph object.
    
    Arguments:
    nodeIndex (I) Node index. 
  */
  OdDbGraphNode* node(
    int nodeIndex) const { return m_nodes.at(nodeIndex); }
  
  /** Description:
    Returns the root (first) GraphNode object of this Graph object.
    
    Remarks:
    Returns a null pointer if isEmpty().
  */
  OdDbGraphNode* rootNode() const;
  
  /** Description:
    Returns the specified incoming reference of this Graph object.
    
    Arguments:
    refIndex (I) Reference index. 
  */
  int numNodes() const { return m_nodes.size(); }

  /** Description:
    Returns true if and only if this Graph object is empty.
  */
  bool isEmpty() const { return numNodes() == 0; }
  
  /** Description:
    Adds the specifed GraphNode object to this Graph object.
    
    Arguments:
    pNode (I) Pointer to the GraphNode object.
    
    remarks
    *pNode must be created with new(), and should not be deleted once added to this Graph object; 
    This Graph object will delete the GraphNode when it is no longer needed.
    
    Throws:
    OdError(eInvalidOwnerObject) if the specified GraphNode object already has an owner.

    Gcad(Modify): void->OdResult
  */  
  OdResult addNode(
    OdDbGraphNode* pNode);
  
  /** Description:
    Adds the specified edge to this Graph object.

    Arguments:
    pFrom (I) Pointer to the GraphNode at the start of the edge.
    pTo (I) Pointer to the GraphNode at the end of the edge.
    
    Remarks:
    Creates an outgoing reference to *pTo in *pFrom, and an incoming reference to *pFrom in *pTo. 
        
    Throws:
    OdError(eInvalidOwnerObject) if the specified GraphNode objects are not in the same Graph object.

    Gcad(Modify): void->OdResult
  */ 
  OdResult addEdge(
    OdDbGraphNode* pFrom, 
    OdDbGraphNode* pTo);
  
  /** Description:
    Removes the specified *node* from this GraphNode object, and all references to it. 

    Arguments:
    pNode (I) Pointer to the GraphNode object.

    Gcad(Modify): void->OdResult
  */  
  OdResult delNode(
    OdDbGraphNode* pNode);
  
  /** Description:
    Removes all nodes and cycle nodes from this Graph object.

    Remarks:
    Always called by ~OdDbGraph().  
  */
  void reset();

  /** Description:
    Clears the specified set flag bits in the GraphNode objects of this Graph object.
    
    Arguments:
    flags (I) Flag bits.
    
    Remarks:
    flags must be a combination of one or more of the following:
    
    @table
    Name                             Value    Description
    OdDbGraphNode::kNone             0x00     None.
    OdDbGraphNode::kVisited          0x01     Used internally by OdDbGraph::findCycles() and while traversing a graphs with cycles.
    OdDbGraphNode::kOutsideRefed     0x02     Used internally by Xref detach.
    OdDbGraphNode::kSelected         0x04     User selection. Set by getOutgoing.
    OdDbGraphNode::kInList           0x08     Is in list. Set by getOutgoing.
    OdDbGraphNode::kListAll          0x0E     Used to *clear* kSelected, kInList, kOutsideRefed.
    OdDbGraphNode::kFirstLevel       0x10     The *node* is connected to the root *node*. Read Only.
    OdDbGraphNode::kUnresTree        0x20     The tree is unresolved.
    OdDbGraphNode::kAll              0x2F     Used to *clear* all but kFirstLevel.

    OdDbGraphNode::kListAll and OdDbGraphNode::kAll are intended to be used with this function.
  */
  void clearAll(
    OdUInt8 flags);
  
  /** Description:
    Adds to the specified array, the nested *outgoing* GraphNode objects from the specified GraphNode objects.

    Arguments:
    outgoing (I/O) Array of GraphNode objects. 

    Remarks:
    The user must *clear* the kListAll flags with OdDbGraph::clearAll() or OdDbGraphNode::clear() when done with them.
  */
  void getOutgoing(
    OdDbGraphNodeArray& outgoing);
  
  /**Description:
    Finds the cyclical nodes for this Graph object.
    
    Arguments:
    pStart (I) Pointer to the starting *node* from which to search. Usually defaulted.

    Remarks:
    Returns true if and only if there are any cyclical GraphNodes.
    
    Note:
    This function must be called with no intervening changes to the graph, prior to querying cycle information.
  */
  virtual OdBool findCycles(
    OdDbGraphNode* pStart = 0);
  /** Remarks:
    Removes the specified edge, and updates the cyclical information for this Graph object.

    Arguments:
    pFrom (I) Pointer to the GraphNode at the start of the edge.
    pTo (I) Pointer to the GraphNode at the end of the edge.

    Gcad(Modify): void->OdResult
  */
  OdResult breakCycleEdge(
    OdDbGraphNode* pFrom, 
    OdDbGraphNode* pTo);

  // Gcad(Add): setNodeGrowthRate
  void setNodeGrowthRate(int rate) { m_nodes.setGrowLength(rate); }
  
protected:
  /** Description:
    Removes all cyclical information determined by findCycles.
    
    Note:
    This function does not remove cyclical edges, and is intended
    only for error cleanup.
    
    See also:
    breakCycleEdge

    Gcad(Modify): void->OdResult
  */
  OdResult clearAllCycles();
private:
  OdDbGraph(
    const OdDbGraph&);
  OdDbGraph& operator =(
    const OdDbGraph&);
  
  void removeLeaves(
    OdDbGraphStack& stack);
  void setDirty() { m_bDirty = true; }
  bool isDirty() const { return m_bDirty; }
  bool m_bDirty;
  OdSize m_nNonCycleNodes;
  OdDbGraphNodeArray m_nodes;
};

#include "TD_PackPop.h"

#endif // _ODDBGRAPH_H_INCLUDED_
