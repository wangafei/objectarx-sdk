#pragma once
#pragma pack (push, 8)

#include "zAcGraphNode.h"
#include <map>

class ZcImpGraph;
class ZcDbObject;

typedef std::map<ZcGraphNode::Id, ZcGraphNode*> NodeIdToPtrMap;

class ZCDBCORE2D_PORT ZcGraph : public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcGraph);

    enum PartialUndoCode
    {
        kAddNodePartialUndoCode = 0,

        kRemoveNodePartialUndoCode,

        kModifyNodePartialUndoCode,

        kModifyNextNewNodeIdPartialUndoCode,
    };

typedef NodeIdToPtrMap::iterator iterator;
typedef NodeIdToPtrMap::const_iterator const_iterator;

    explicit ZcGraph(bool bCreateImp = true);

    virtual ~ZcGraph();

    ZcDbObject* owningObject() const;

    void setOwningObject(ZcDbObject* pObj);

    virtual Zcad::ErrorStatus applyPartialUndo(ZcDbDwgFiler* pUndoFiler,
                                               PartialUndoCode code,
                                               ZcGraphNode::Id &nodeId);

    Zcad::ErrorStatus addGraphNode(ZcGraphNode* pNewNode);
    Zcad::ErrorStatus addGraphNode(ZcGraphNode* pNewNode, ZcGraphNode::Id nodeId);
    Zcad::ErrorStatus removeGraphNode(ZcGraphNode* pNode, bool bDelete = true);
    ZcGraphNode* getGraphNodePtr(ZcGraphNode::Id nodeId) const;

    Zcad::ErrorStatus moveAndMerge(const ZcArray<ZcGraphNode*> & nodesToMove);
    Zcad::ErrorStatus merge(const ZcGraph &graph);

    Zcad::ErrorStatus getRelatedNodes(const ZcArray<ZcGraphNode *> &nodes, ZcArray<ZcGraphNode *> &relatedNodes) const;

    iterator begin();

    const_iterator begin() const;

    iterator end();

    const_iterator end() const;

    size_t size() const;

    void clear(bool bDelete);

    virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler *pFiler) const;
    virtual Zcad::ErrorStatus dwgInFields (ZcDbDwgFiler *pFiler);
    virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler *pFiler) const;
    virtual Zcad::ErrorStatus dxfInFields (ZcDbDxfFiler *pFiler);

    virtual ZSoft::UInt32     graphId() const;

    virtual void              setGraphId(ZSoft::UInt32 id);

protected:

    ZcImpGraph* mpImpGraph;

private:

    ZcGraph(const ZcGraph &graph);

    ZcGraph &operator = (const ZcGraph &graph);

friend class ZcGraphNode;
friend class ZcImpGraphNode;
friend class ZcImpGraph;
};

#pragma pack (pop)
