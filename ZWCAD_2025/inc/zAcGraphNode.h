#pragma once

#pragma pack (push, 8)

class ZcImpGraphNode;
class ZcGraph;

class ZCDBCORE2D_PORT ZcGraphNode : public ZcRxObject,
                              public ZcHeapOperators
{
public:
    ZCRX_DECLARE_MEMBERS(ZcGraphNode);

    virtual ~ZcGraphNode();

    typedef ZSoft::UInt32 Id;

    enum {
		kNullId = 0
	};
	

    Id nodeId() const;

    ZcGraph* owningGraph() const;
    Zcad::ErrorStatus connectNode (ZcGraphNode* pNode);
    Zcad::ErrorStatus disconnectNode(ZcGraphNode* pNode);
    Zcad::ErrorStatus disconnectAllNodes();
    Zcad::ErrorStatus getAdjacentNodes(ZcArray<ZcGraphNode*>& adjacentNodes) const;

    virtual void backup();

    bool isAdjacentTo(ZcGraphNode *pNode) const;

    virtual Zcad::ErrorStatus nodeToBeConnectedNotification(ZcGraphNode *pNode);
    virtual Zcad::ErrorStatus nodeToBeDisconnectedNotification(ZcGraphNode* pNode);
    virtual Zcad::ErrorStatus nodeToBeMovedNotification(ZcGraph *pGraph, ZcArray<ZcGraphNode *> & otherNodesToMove);
    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler*) const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler*);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler*) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler*);

protected:

    explicit ZcGraphNode(bool bCreateImp = true);

    ZcImpGraphNode* mpImpGraphNode;

private:

    ZcGraphNode(const ZcGraphNode &node);

    ZcGraphNode &operator = (const ZcGraphNode &node);

friend class ZcGraph;
friend class ZcImpGraph;
};

#pragma pack (pop)
