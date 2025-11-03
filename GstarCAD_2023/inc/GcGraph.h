/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma pack (push, 8)

#include "GcGraphNode.h"
#include <map>

class GcImpGraph;
class GcDbObject;

typedef std::map<GcGraphNode::Id, GcGraphNode*> NodeIdToPtrMap;

class DBCONSTRAINTS_PORT GcGraph : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGraph);

  enum PartialUndoCode
  {
    kAddNodePartialUndoCode = 0,
    kRemoveNodePartialUndoCode,
    kModifyNodePartialUndoCode,
    kModifyNextNewNodeIdPartialUndoCode,
  };

  typedef NodeIdToPtrMap::iterator iterator;
  typedef NodeIdToPtrMap::const_iterator const_iterator;

  explicit GcGraph(bool bCreateImp = true);
  ~GcGraph();

  GcDbObject* owningObject() const;
  void setOwningObject(GcDbObject* pObj);

  virtual Gcad::ErrorStatus applyPartialUndo(GcDbDwgFiler* pUndoFiler,
    PartialUndoCode code,
    GcGraphNode::Id &nodeId);

  Gcad::ErrorStatus addGraphNode(GcGraphNode* pNewNode);
  Gcad::ErrorStatus addGraphNode(GcGraphNode* pNewNode, GcGraphNode::Id nodeId);
  Gcad::ErrorStatus removeGraphNode(GcGraphNode* pNode, bool bDelete = true);
  GcGraphNode* getGraphNodePtr(GcGraphNode::Id nodeId) const;
  Gcad::ErrorStatus moveAndMerge(const GcArray<GcGraphNode*> & nodesToMove);
  Gcad::ErrorStatus merge(const GcGraph &graph);
  Gcad::ErrorStatus getRelatedNodes(const GcArray<GcGraphNode *> &nodes, GcArray<GcGraphNode *> &relatedNodes) const;

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;
  size_t size() const;
  void clear(bool bDelete);

  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler *pFiler) const;
  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler *pFiler);
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler *pFiler) const;
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler *pFiler);
  virtual Gsoft::UInt32     graphId() const;
  virtual void              setGraphId(Gsoft::UInt32 id);

protected:
  GcImpGraph* mpImpGraph;

private:
  GcGraph(const GcGraph &graph);
  GcGraph &operator = (const GcGraph &graph);

  friend class GcGraphNode;
  friend class GcImpGraphNode;
  friend class GcImpGraph;
};

#pragma pack (pop)