/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_IDGRAPH_H
#define GD_IDGRAPH_H 1

#include "graph.h"
#include "dbidmap.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbObjectIdGraphNode : public GcDbGraphNode
{
public:
  GcDbObjectIdGraphNode(const GcDbObjectId id);
  ~GcDbObjectIdGraphNode();

  GcDbObjectId        id() const;
private:
  GcDbObjectId        mId;
};

class GCDB_PORT GcDbObjectIdGraph : public GcDbGraph
{
public:
  GcDbObjectIdGraph();
  ~GcDbObjectIdGraph();

  Gcad::ErrorStatus       addNode(GcDbObjectIdGraphNode *);
  Gcad::ErrorStatus       delNode(GcDbObjectIdGraphNode *);
  GcDbObjectIdGraphNode*  findNode(const GcDbObjectId) const;
  GcDbObjectIdGraphNode*  idNode(int idx) const;
private:
  GcDbIdMapping       mIdNodeMap;
};

inline GcDbObjectId GcDbObjectIdGraphNode::id() const
{
  return mId;
}

inline GcDbObjectIdGraphNode* GcDbObjectIdGraph::idNode(int idx) const
{
  return (GcDbObjectIdGraphNode*)node(idx);
}

#pragma pack (pop)

#endif
