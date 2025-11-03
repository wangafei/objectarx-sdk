/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_GRAPH_H
#define GD_GRAPH_H 1

#include "dbmain.h"

#pragma pack (push, 8)

class GcDbGraph;

class GCDB_PORT GcDbGraphNode : public GcHeapOperators
{
  friend class GcDbGraph;

public:
  GcDbGraphNode(void* pData = NULL);
  virtual ~GcDbGraphNode();

  enum Flags
  {
    kNone         = 0x00,
    kVisited      = 0x01,
    kOutsideRefed = 0x02,
    kSelected     = 0x04,
    kInList       = 0x08,
    kListAll      = 0x0E,
    kFirstLevel   = 0x10,
    kUnresTree    = 0x20,
    kAll          = 0x2F
  };

  void*               data() const;
  void                setData(void*);

  int                 numOut() const;
  int                 numIn() const;

  GcDbGraphNode*      in(int) const;
  GcDbGraphNode*      out(int) const;

  Gcad::ErrorStatus   addRefTo(GcDbGraphNode*);
  Gcad::ErrorStatus   removeRefTo(GcDbGraphNode*);
  Gcad::ErrorStatus   disconnectAll();

  GcDbGraph*          owner() const;

  bool                isMarkedAs(Gsoft::UInt8 flags) const;
  Gcad::ErrorStatus   markAs(Gsoft::UInt8 flags);
  Gcad::ErrorStatus   clear(Gsoft::UInt8 flags);

  Gcad::ErrorStatus   markTree(Gsoft::UInt8 flags, GcDbVoidPtrArray* = NULL);

  int                 numCycleOut() const;
  int                 numCycleIn() const;

  GcDbGraphNode*      cycleIn(int) const;
  GcDbGraphNode*      cycleOut(int) const;

  GcDbGraphNode*      nextCycleNode() const;
  bool                isCycleNode() const;

  void                setEdgeGrowthRate(int outEdgeRate, int inEdgeRate);

private:
  GcDbGraphNode(const GcDbGraphNode&);
  GcDbGraphNode&      operator =      (const GcDbGraphNode&);

  GcDbVoidPtrArray    mOutgoing;
  GcDbVoidPtrArray    mIncoming;
  void*               mpData;
  void                setFirstLevel(Gsoft::Boolean);
  Gsoft::UInt8        mFlags;

  Gcad::ErrorStatus   setOwner(GcDbGraph*);
  Gcad::ErrorStatus   resetCycles();
  Gcad::ErrorStatus   removeCycleRefTo(GcDbGraphNode*);
  Gcad::ErrorStatus   clearCycles();

  GcDbGraph*          mpOwner;
  GcDbVoidPtrArray*   mpCycleOut;
  GcDbVoidPtrArray*   mpCycleIn;
};

class GCDB_PORT GcDbGraph : public GcHeapOperators
{
  friend class GcDbGraphNode;

public:
  GcDbGraph(GcDbGraphNode* pRoot = NULL);
  virtual ~GcDbGraph();

  GcDbGraphNode*      node(int index) const;
  GcDbGraphNode*      rootNode() const;

  int                 numNodes() const;
  bool                isEmpty() const;

  Gcad::ErrorStatus   addNode(GcDbGraphNode*);
  Gcad::ErrorStatus   addEdge(GcDbGraphNode* pFrom, GcDbGraphNode* pTo);

  Gcad::ErrorStatus   delNode(GcDbGraphNode*);

  void                reset();
  void                clearAll(Gsoft::UInt8 flags);

  void                getOutgoing(GcDbVoidPtrArray&);

  virtual Gsoft::Boolean findCycles(GcDbGraphNode* pStart = NULL);
  Gcad::ErrorStatus   breakCycleEdge(GcDbGraphNode* pFrom, GcDbGraphNode* pTo);

  void                setNodeGrowthRate(int rate);
protected:
  Gcad::ErrorStatus   clearAllCycles();
private:
  GcDbGraph(const GcDbGraph&);
  GcDbGraph&          operator =      (const GcDbGraph&);

  GcDbVoidPtrArray    mNodes;
  GcDbVoidPtrArray*   mpCycleNodes;

  void                setDirty();
  bool                mDirty;
};

class GCDB_PORT GcDbGraphStack : public GcHeapOperators
{
public:
  GcDbGraphStack(int initPhysicalLength = 0, int initGrowLength = 8);
  ~GcDbGraphStack();

  Gcad::ErrorStatus   push(GcDbGraphNode*);
  GcDbGraphNode*      pop();
  GcDbGraphNode*      top() const;
  bool                isEmpty() const;
private:
  GcDbVoidPtrArray    mStack;
};

inline void* GcDbGraphNode::data() const
{
  return mpData;
}
inline void  GcDbGraphNode::setData(void* pData)
{
  mpData = pData;
}

inline int GcDbGraphNode::numOut() const
{
  return mOutgoing.length();
}
inline int GcDbGraphNode::numIn() const
{
  return mIncoming.length();
}

inline GcDbGraphNode* GcDbGraphNode::in(int idx) const
{
  return (GcDbGraphNode*)mIncoming.at(idx);
}
inline GcDbGraphNode* GcDbGraphNode::out(int idx) const
{
  return (GcDbGraphNode*)mOutgoing.at(idx);
}

inline bool GcDbGraphNode::isMarkedAs(Gsoft::UInt8 flag) const
{
  return (this->mFlags & flag) != 0;
}

inline GcDbGraph*        GcDbGraphNode::owner() const
{
  return mpOwner;
}
inline Gcad::ErrorStatus GcDbGraphNode::setOwner(GcDbGraph* pOwn)
{
  assert(!mpOwner);
  if (mpOwner)
    return Gcad::eInvalidOwnerObject;
  mpOwner = pOwn;
  return Gcad::eOk;
}

inline int GcDbGraphNode::numCycleOut() const
{
  return mpCycleOut == NULL ? 0 : mpCycleOut->length();
}
inline int GcDbGraphNode::numCycleIn() const
{
  return mpCycleIn == NULL ? 0 : mpCycleIn->length();
}

inline GcDbGraphNode* GcDbGraphNode::cycleOut(int idx) const
{
  return (GcDbGraphNode*)(mpCycleOut == NULL ? NULL : mpCycleOut->at(idx));
}
inline GcDbGraphNode* GcDbGraphNode::cycleIn(int idx) const
{
  return (GcDbGraphNode*)(mpCycleIn == NULL ? NULL : mpCycleIn->at(idx));
}

inline GcDbGraphNode* GcDbGraphNode::nextCycleNode() const
{
  assert(mpCycleOut != NULL); return cycleOut(0);
}
inline bool GcDbGraphNode::isCycleNode() const
{
  return mpCycleIn != NULL || mpCycleOut != NULL;
}

inline int GcDbGraph::numNodes() const
{
  return mNodes.length();
}
inline GcDbGraphNode* GcDbGraph::node(int idx) const
{
  return (GcDbGraphNode*)mNodes.at(idx);
}

inline GcDbGraphNode* GcDbGraph::rootNode() const
{
  return (numNodes() > 0) ? node(0) : NULL;
}

inline bool GcDbGraph::isEmpty() const
{
  return numNodes() == 0;
}

inline void GcDbGraph::setDirty()
{
  mDirty = true;
}

inline bool GcDbGraphStack::isEmpty() const
{
  return mStack.isEmpty();
}

inline GcDbGraphNode* GcDbGraphStack::top() const
{
  return isEmpty() ? NULL : (GcDbGraphNode*)mStack.last();
}

#pragma pack (pop)

#endif
