/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "rxobject.h"
#include "GcHeapOpers.h"
#include "gcarray.h"
#include "dbfiler.h"

#pragma pack (push, 8)

class GcImpGraphNode;
class GcGraph;

class GcGraphNode : public GcRxObject,
  public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcGraphNode, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT ~GcGraphNode();

  typedef Gsoft::UInt32 Id;

  enum {
    kNullId = 0
  };

  DBCONSTRAINTS_PORT Id nodeId() const;
  DBCONSTRAINTS_PORT GcGraph* owningGraph() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus connectNode(GcGraphNode* pNode);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus disconnectNode(GcGraphNode* pNode);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus disconnectAllNodes();
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getAdjacentNodes(GcArray<GcGraphNode*>& adjacentNodes) const;
  DBCONSTRAINTS_PORT virtual void backup();
  DBCONSTRAINTS_PORT bool isAdjacentTo(GcGraphNode *pNode) const;

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus nodeToBeConnectedNotification(GcGraphNode *pNode);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus nodeToBeDisconnectedNotification(GcGraphNode* pNode);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus nodeToBeMovedNotification(GcGraph *pGraph, GcArray<GcGraphNode *> & otherNodesToMove);

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler*) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler*);
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler*) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler*);

protected:
  DBCONSTRAINTS_PORT explicit GcGraphNode(bool bCreateImp = true);
  GcImpGraphNode* mpImpGraphNode;

private:
  GcGraphNode(const GcGraphNode &node);
  GcGraphNode &operator = (const GcGraphNode &node);
  friend class GcGraph;
  friend class GcImpGraph;
};

#pragma pack (pop)