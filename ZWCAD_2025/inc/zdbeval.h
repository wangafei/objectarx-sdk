
#pragma once

#include "zdbmain.h"
#include "zdbents.h"
#include "zAcString.h"
#include "zadscodes.h"
#include "zadsdef.h"

#pragma pack(push, 8)
class  ZcDbEvalGraph;
class  ZcDbEvalEdgeInfo;
class  ZcDbEvalExpr;
class  ZcDbEvalCoectable;
class  ZcDbEvalContext;
class  ZcDbEvalContextPair;
class  ZcDbEvalContextIterator;
class  ZcDbEvalVariant;
class  ZcDbImpEvalContext;
class  ZcDbImpEvalContextIterator;
class ZcRxValue;
class ZcRxValueType;


typedef ZSoft::UInt32 ZcDbEvalNodeId;
typedef ZcArray<ZcDbEvalNodeId>             ZcDbEvalNodeIdArray;
typedef ZcArray<ZcDbEvalEdgeInfo*>          ZcDbEvalEdgeInfoArray;
typedef ZcArray<ZcDbEvalExpr*>              ZcDbEvalExprPtrArray;
typedef ZcArray<ZcDbEvalVariant,
        ZcArrayObjectCopyReallocator<ZcDbEvalVariant> >   ZcDbEvalVariantArray;

class ZCDBCORE2D_PORT ZcDbEvalVariant : public resbuf, public ZcRxObject
{
public:

    ZCRX_DECLARE_MEMBERS(ZcDbEvalVariant);
    ZcDbEvalVariant ();
    ZcDbEvalVariant(const ZcDbEvalVariant& other);
	ZcDbEvalVariant(ZcDbEvalVariant&& other);		
    ZcDbEvalVariant (const ZcDbEvalVariant* pOther);
    ~ZcDbEvalVariant();
    ZcDbEvalVariant (double       dVal);
    ZcDbEvalVariant (short        iVal);
    ZcDbEvalVariant (const ZTCHAR*  szVal);
    ZcDbEvalVariant (ZSoft::Int32       lVal);
    ZcDbEvalVariant (const ZcDbObjectId& id);
    ZcDbEvalVariant (const ZcGePoint2d&  pt);
    ZcDbEvalVariant (const ZcGePoint3d&  pt);

	ZcDbEvalVariant(const resbuf& rb);	
	ZcDbEvalVariant& operator=(const resbuf& rb);	

    ZcDbEvalVariant& operator=(double      dVal);
    ZcDbEvalVariant& operator=(short       iVal);
    ZcDbEvalVariant& operator=(ZSoft::Int32 lVal);
    ZcDbEvalVariant& operator=(const ZTCHAR* szVal);
    ZcDbEvalVariant& operator=(const ZcDbEvalVariant& other);
	ZcDbEvalVariant& operator=(ZcDbEvalVariant&& other);	
    ZcDbEvalVariant& operator=(const ZcDbObjectId& id);
    ZcDbEvalVariant& operator=(const ZcGePoint2d&  pt);
    ZcDbEvalVariant& operator=(const ZcGePoint3d&  pt);
	
    void clear();
    virtual Zcad::ErrorStatus copyFrom(const ZcRxObject* pOther) override;

	
	bool operator < ( const ZcDbEvalVariant& val ) const;

	bool operator > ( const ZcDbEvalVariant& val ) const;

	bool operator <= ( const ZcDbEvalVariant& val ) const;

	bool operator >= ( const ZcDbEvalVariant& val ) const;

	bool operator == ( const ZcDbEvalVariant& val ) const;

	bool operator != ( const ZcDbEvalVariant& val ) const;


	Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
	Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);

	Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;
	Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);

	ZcDb::DwgDataType getType() const;

	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, double value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, short value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, ZSoft::Int32 value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, const ZcString& value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, const wchar_t * value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, ZcDbObjectId value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, const ZcGePoint3d& value);
	Zcad::ErrorStatus setValue(ZcDb::DxfCode groupcode, const ZcGePoint2d& value);

	Zcad::ErrorStatus getValue(double& value) const;
	Zcad::ErrorStatus getValue(short& value) const;
	Zcad::ErrorStatus getValue(ZSoft::Int32& value) const;
	Zcad::ErrorStatus getValue(ZcString& value) const;
	Zcad::ErrorStatus getValue(ZcDbObjectId& value, ZcDbDatabase *pDb = NULL) const;
	Zcad::ErrorStatus getValue(ZcGePoint3d& value) const;
	Zcad::ErrorStatus getValue(ZcGePoint2d& value) const;

	Zcad::ErrorStatus toZcRxValue(const ZcRxValueType& type, 
		ZcRxValue& value) const;

	Zcad::ErrorStatus fromZcRxValue(const ZcRxValue& value);
	
protected:
    void init();
private:
	void takeStateFrom(ZcDbEvalVariant &other);		
};

class ZcDbEvalEdgeInfo;

class ZcDbEvalIdMap
{
public:
    virtual ZcDbEvalNodeId find(const ZcDbEvalNodeId& key) = 0;
    virtual void kill() = 0;
};

class ZCDBCORE2D_PORT ZcDbEvalGraph : public ZcDbObject
{
public:
    enum NodeId {
        kNullNodeId = 0
    };

    ZCDB_DECLARE_MEMBERS(ZcDbEvalGraph);
    ZcDbEvalGraph();
    virtual ~ZcDbEvalGraph();
    static bool hasGraph(const ZcDbObject*    pObj,
                         const ZTCHAR*          pKey);
    static Zcad::ErrorStatus getGraph(const ZcDbObject*    pObj,
                                      const ZTCHAR*          pKey,
                                      ZcDbEvalGraph**      pGraph,
                                      const ZcDb::OpenMode mode);
    static Zcad::ErrorStatus createGraph(ZcDbObject* pObj,
                                         const ZTCHAR* pKey);
    static Zcad::ErrorStatus removeGraph(ZcDbObject* pObj,
                                         const ZTCHAR* pKey);
    static bool hasGraph(ZcDbDatabase*        pDb,
                         const ZTCHAR*          pKey);
    static Zcad::ErrorStatus getGraph(ZcDbDatabase*        pDb,
                                      const ZTCHAR*          pKey,
                                      ZcDbEvalGraph**      pGraph,
                                      const ZcDb::OpenMode mode);
    static Zcad::ErrorStatus createGraph(ZcDbDatabase* pDb,
                                         const ZTCHAR*   pKey);
    static Zcad::ErrorStatus removeGraph(ZcDbDatabase* pDb,
                                         const ZTCHAR*   pKey);
    static Zcad::ErrorStatus replaceGraph(ZcDbObject* pObj,
                                         const ZTCHAR* pKey,
                                         ZcDbObjectId grphId);
    virtual Zcad::ErrorStatus addNode     (ZcDbEvalExpr*   pNode,
                                           ZcDbEvalNodeId& id);
    virtual Zcad::ErrorStatus removeNode  (const ZcDbEvalNodeId& id);
    virtual Zcad::ErrorStatus removeNode  (ZcDbEvalExpr* pNode);
    virtual Zcad::ErrorStatus getAllNodes (ZcDbEvalNodeIdArray& nodes) const;
    virtual Zcad::ErrorStatus getNode     (const ZcDbEvalNodeId& nodeId,
                                           ZcDb::OpenMode        mode,
                                           ZcDbObject**        ppNode) const;
    virtual Zcad::ErrorStatus addEdge(const ZcDbEvalNodeId& idFrom,
                                      const ZcDbEvalNodeId& idTo);
    virtual Zcad::ErrorStatus addEdge(const ZcDbEvalNodeId& idFrom,
                                      const ZcDbEvalNodeId& idTo,
                                      bool  bInvertible);
    virtual Zcad::ErrorStatus removeEdge(const ZcDbEvalNodeId& idFrom,
                                         const ZcDbEvalNodeId& idTo);
    virtual Zcad::ErrorStatus getIncomingEdges(const ZcDbEvalNodeId& nodeId,
                                      ZcDbEvalEdgeInfoArray& edges) const;
    virtual Zcad::ErrorStatus getOutgoingEdges(const ZcDbEvalNodeId& nodeId,
                                      ZcDbEvalEdgeInfoArray& edges) const;
    virtual Zcad::ErrorStatus getEdgeInfo(const ZcDbEvalNodeId& nodeFrom,
            const ZcDbEvalNodeId& nodeTo, ZcDbEvalEdgeInfo& einfo) const;
    virtual Zcad::ErrorStatus addGraph(ZcDbEvalGraph* pGraphToAdd,
                ZcDbEvalIdMap*& idMap);
    virtual Zcad::ErrorStatus evaluate() const;
    virtual Zcad::ErrorStatus evaluate(
            const ZcDbEvalContext*     pContext) const;
    virtual Zcad::ErrorStatus evaluate(
            const ZcDbEvalContext*     pContext,
            const ZcDbEvalNodeIdArray* activatedNodes) const;
    virtual Zcad::ErrorStatus activate(
            const ZcDbEvalNodeIdArray& activatedNodes) const;
    virtual Zcad::ErrorStatus activate(
            const ZcDbEvalNodeIdArray& activatedNodes,
            ZcDbEvalNodeIdArray*       pActiveSubgraph) const;
    virtual Zcad::ErrorStatus activate(
            const ZcDbEvalNodeIdArray& activatedNodes,
            ZcDbEvalNodeIdArray*       pActiveSubgraph,
            ZcDbEvalNodeIdArray*       pCycleNodes) const;
    virtual Zcad::ErrorStatus getIsActive(const ZcDbEvalNodeId& id,
            bool& bIsActive) const;
    virtual bool equals(const ZcDbEvalGraph* pOther) const;
    virtual bool isSubgraphOf(const ZcDbEvalGraph* pOther) const;
    virtual Zcad::ErrorStatus postInDatabase(ZcDbObjectId& objId, ZcDbDatabase* pDb);

};

class ZCDBCORE2D_PORT ZcDbEvalEdgeInfo
{
public:
    ZcDbEvalEdgeInfo()
        : mFlags(0), mRefCount(0)
    {
        mIdFrom = ZcDbEvalGraph::kNullNodeId;
        mIdTo = ZcDbEvalGraph::kNullNodeId;
    }
    ZcDbEvalEdgeInfo(ZcDbEvalNodeId from,
                     ZcDbEvalNodeId to,
                     ZSoft::Int32   flags,
                     ZSoft::UInt32  count)
        : mIdFrom(from), mIdTo(to), mFlags(flags), mRefCount(count)
        {}
    ZcDbEvalNodeId from () const;
    ZcDbEvalNodeId to   () const;
    ZSoft::UInt32 refCount() const;
    bool isInvertible () const;
    bool isSuppressed  () const;
    bool operator == (const ZcDbEvalEdgeInfo& other) const;

private:
    ZcDbEvalNodeId mIdFrom;
    ZcDbEvalNodeId mIdTo;
    ZSoft::Int32  mFlags;
    ZSoft::UInt32 mRefCount;
};

class ZCDBCORE2D_PORT ZcDbEvalExpr : public ZcDbObject
{

public:
    ZCDB_DECLARE_MEMBERS(ZcDbEvalExpr);
    ZcDbEvalExpr();
    virtual ~ZcDbEvalExpr();
    Zcad::ErrorStatus getGraph(ZcDbEvalGraph** pGraph,
                               ZcDb::OpenMode  mode) const;
    ZcDbEvalNodeId    nodeId() const;
    virtual void addedToGraph       (ZcDbEvalGraph*  pGraph);
    virtual void removedFromGraph   (ZcDbEvalGraph*  pGraph);
    virtual void adjacentNodeRemoved (const ZcDbEvalNodeId& adjNodeId);
    virtual void adjacentEdgeRemoved (const ZcDbEvalNodeId& adjEdgeNodeId);
    virtual void adjacentEdgeAdded (const ZcDbEvalNodeId& fromId,
            const ZcDbEvalNodeId& toId,
            bool bIsInvertible);
    virtual void movedFromGraph (ZcDbEvalGraph* pFromGraph);
    virtual void movedIntoGraph (ZcDbEvalGraph* pIntoGraph);
    virtual void remappedNodeIds (ZcDbEvalIdMap& idMap);
    virtual void copiedIntoGraph(ZcDbEvalGraph* pIntoGraph);
    virtual bool isActivatable  ();
    virtual void activated           (ZcDbEvalNodeIdArray& argumentActiveList);
    virtual void graphEvalStart      (bool bNodeIsActive);
    virtual void graphEvalEnd        (bool bNodeIsActive);
    virtual void graphEvalAbort      (bool bNodeIsActive);
    virtual Zcad::ErrorStatus evaluate(const ZcDbEvalContext* ctxt);
    virtual bool equals(const ZcDbEvalExpr* pOther) const;
    ZcDbEvalVariant value() const;
    virtual Zcad::ErrorStatus postInDatabase(ZcDbObjectId& objId, ZcDbDatabase* pDb);

protected:
    ZcDbEvalVariant m_lastValue;
    friend class ZcDbImpEvalExpr;
};

class ZCDBCORE2D_PORT ZcDbEvalConnectable : public ZcDbEvalExpr
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbEvalConnectable);
    virtual ~ZcDbEvalConnectable();
    virtual Zcad::ErrorStatus getConnectionNames (ZcStringArray& names) const;
    virtual bool              hasConnectionNamed (const ZcString& name) const;
    virtual Zcad::ErrorStatus getConnectionType  (
                                    const ZcString&        name,
                                    ZcDb::DwgDataType& type) const;
    virtual Zcad::ErrorStatus getConnectionValue (
                                    const ZcString&    name,
                                    ZcDbEvalVariant&    value) const;
    virtual Zcad::ErrorStatus setConnectionValue (
                                    const ZcString&       name,
                                    const ZcDbEvalVariant& value);
    virtual Zcad::ErrorStatus connectTo (
                                const ZcString&      thisConnection,
                                const ZcDbEvalNodeId sourceConnectableId,
                                const ZcString&      sourceConnectionName);
    virtual Zcad::ErrorStatus disconnectFrom (
                                const ZcString&      thisConnection,
                                const ZcDbEvalNodeId sourceConnectableId,
                                const ZcString&      sourceConnectionName);
    virtual bool connectionAllowed ( 
                            const ZcString&      thisConnection,
                            const ZcDbEvalNodeId sourceConnectableId,
                            const ZcString&      sourceConnectionName) const;
    virtual Zcad::ErrorStatus getConnectedObjects (
                                const ZcString&      thisConnection,
                                ZcDbEvalNodeIdArray& connectedObjects) const;
    virtual Zcad::ErrorStatus getConnectedNames (
                                const ZcString&      thisConnection,
                                const ZcDbEvalNodeId sourceConnectableId,
                                ZcStringArray&       sourceConnectionNames) const;
protected:
    ZcDbEvalConnectable();
};

class ZCDBCORE2D_PORT ZcDbEvalContext : public ZcRxObject, public ZcHeapOperators
{
public:
    ZcDbEvalContext();
    virtual ~ZcDbEvalContext();

    ZCRX_DECLARE_MEMBERS(ZcDbEvalContext);
    virtual void        insertAt (const ZcDbEvalContextPair& pair);
    virtual void        removeAt (const ZTCHAR*                szKey);
    virtual Zcad::ErrorStatus getAt (ZcDbEvalContextPair& pair) const;
    virtual ZcDbEvalContextIterator* newIterator() const;

private:
    ZcDbImpEvalContext* mpImp;
    friend class ZcDbImpEvalContextIterator;
};

class ZCDBCORE2D_PORT ZcDbEvalContextPair : public ZcHeapOperators
{
public:
    ZcDbEvalContextPair();
    ZcDbEvalContextPair(const ZTCHAR* szKey, void *pValue);
    virtual ~ZcDbEvalContextPair();
    void        setKey   (const ZTCHAR* szKey);
    const ZTCHAR* key      () const;
    void        setValue (void* pValue);
    void*       value    () const;

private:
    ZTCHAR* mKey;
    void* mValue;
};

class ZCDBCORE2D_PORT ZcDbEvalContextIterator : public ZcRxObject, public ZcHeapOperators
{
public:
    ZcDbEvalContextIterator();
    virtual ~ZcDbEvalContextIterator();

    ZCRX_DECLARE_MEMBERS(ZcDbEvalContextIterator);
    virtual void   start();
    virtual bool   next();
    virtual bool   done() const;
    virtual ZcDbEvalContextPair contextPair() const;

private:
    ZcDbEvalContextIterator(ZcDbEvalContext* pContext);
    ZcDbImpEvalContextIterator* mpImp;
    friend class ZcDbImpEvalContext;
};

#pragma pack(pop)
