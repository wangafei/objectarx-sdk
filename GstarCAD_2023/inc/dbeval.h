/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "dbents.h"
#include "GcString.h"
#include "gdscodes.h"
#include "gdsdef.h"

#pragma pack(push, 8)

class GcDbEvalGraph;
class GcDbEvalEdgeInfo;
class GcDbEvalExpr;
class GcDbEvalConnectable;
class GcDbEvalContext;
class GcDbEvalContextPair;
class GcDbEvalContextIterator;
class GcDbEvalVariant;
class GcDbImpEvalContext;
class GcDbImpEvalContextIterator;
class GcRxValue;
class GcRxValueType;


typedef Gsoft::UInt32 GcDbEvalNodeId;

typedef GcArray<GcDbEvalNodeId>             GcDbEvalNodeIdArray;
typedef GcArray<GcDbEvalEdgeInfo*>          GcDbEvalEdgeInfoArray;
typedef GcArray<GcDbEvalExpr*>              GcDbEvalExprPtrArray;
typedef GcArray<GcDbEvalVariant,
  GcArrayObjectCopyReallocator<GcDbEvalVariant> >   GcDbEvalVariantArray;


class GCDB_PORT GcDbEvalVariant : public resbuf, public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbEvalVariant);
  GcDbEvalVariant();
  GcDbEvalVariant(const GcDbEvalVariant& other);
  GcDbEvalVariant(GcDbEvalVariant&& other);
  GcDbEvalVariant(const GcDbEvalVariant* pOther);
  ~GcDbEvalVariant();
  GcDbEvalVariant(double       dVal);
  GcDbEvalVariant(short        iVal);
  GcDbEvalVariant(const GCHAR*  szVal);
  GcDbEvalVariant(Gsoft::Int32         lVal);
  GcDbEvalVariant(const GcDbObjectId& id);
  GcDbEvalVariant(const GcGePoint2d&  pt);
  GcDbEvalVariant(const GcGePoint3d&  pt);
  GcDbEvalVariant(const resbuf& rb);

  GcDbEvalVariant& operator=(const resbuf& rb);
  GcDbEvalVariant& operator=(double      dVal);
  GcDbEvalVariant& operator=(short       iVal);
  GcDbEvalVariant& operator=(Gsoft::Int32  lVal);
  GcDbEvalVariant& operator=(const GCHAR* szVal);
  GcDbEvalVariant& operator=(const GcDbEvalVariant& other);
  GcDbEvalVariant& operator=(GcDbEvalVariant&& other);
  GcDbEvalVariant& operator=(const GcDbObjectId& id);
  GcDbEvalVariant& operator=(const GcGePoint2d&  pt);
  GcDbEvalVariant& operator=(const GcGePoint3d&  pt);

  void clear();
  Gcad::ErrorStatus copyFrom(const GcRxObject* pOther) override;

  bool operator < (const GcDbEvalVariant& val) const;
  bool operator > (const GcDbEvalVariant& val) const;
  bool operator <= (const GcDbEvalVariant& val) const;
  bool operator >= (const GcDbEvalVariant& val) const;
  bool operator == (const GcDbEvalVariant& val) const;
  bool operator != (const GcDbEvalVariant& val) const;

  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler);
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler);
  GcDb::DwgDataType getType() const;

  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, double value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, short value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, Gsoft::Int32 value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, const GcString& value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, const wchar_t * value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, GcDbObjectId value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, const GcGePoint3d& value);
  Gcad::ErrorStatus setValue(GcDb::DxfCode groupcode, const GcGePoint2d& value);

  Gcad::ErrorStatus getValue(double& value) const;
  Gcad::ErrorStatus getValue(short& value) const;
  Gcad::ErrorStatus getValue(Gsoft::Int32& value) const;
  Gcad::ErrorStatus getValue(GcString& value) const;
  Gcad::ErrorStatus getValue(GcDbObjectId& value, GcDbDatabase *pDb = NULL) const;
  Gcad::ErrorStatus getValue(GcGePoint3d& value) const;
  Gcad::ErrorStatus getValue(GcGePoint2d& value) const;

  Gcad::ErrorStatus toGcRxValue(const GcRxValueType& type, GcRxValue& value) const;
  Gcad::ErrorStatus fromGcRxValue(const GcRxValue& value);

protected:
  void init();

private:
  void takeStateFrom(GcDbEvalVariant &other);
};

class GcDbEvalEdgeInfo;

class GcDbEvalIdMap
{
public:
  virtual GcDbEvalNodeId find(const GcDbEvalNodeId& key) = 0;
  virtual void kill() = 0;
};

class DYNBLOCKS_PORT GcDbEvalGraph : public GcDbObject
{
public:
  enum NodeId {
    kNullNodeId = 0
  };

  GCDB_DECLARE_MEMBERS(GcDbEvalGraph);
  GcDbEvalGraph();
  ~GcDbEvalGraph();

  static bool hasGraph(const GcDbObject*    pObj,
    const GCHAR*          pKey);
  static Gcad::ErrorStatus getGraph(const GcDbObject*    pObj,
    const GCHAR*          pKey,
    GcDbEvalGraph**      pGraph,
    const GcDb::OpenMode mode);
  static Gcad::ErrorStatus createGraph(GcDbObject* pObj, const GCHAR* pKey);
  static Gcad::ErrorStatus removeGraph(GcDbObject* pObj, const GCHAR* pKey);
  static bool hasGraph(GcDbDatabase*        pDb, const GCHAR*          pKey);

  static Gcad::ErrorStatus getGraph(GcDbDatabase*        pDb,
    const GCHAR*          pKey,
    GcDbEvalGraph**      pGraph,
    const GcDb::OpenMode mode);
  static Gcad::ErrorStatus createGraph(GcDbDatabase* pDb, const GCHAR*   pKey);
  static Gcad::ErrorStatus removeGraph(GcDbDatabase* pDb, const GCHAR*   pKey);
  static Gcad::ErrorStatus replaceGraph(GcDbObject* pObj,
    const GCHAR* pKey,
    GcDbObjectId grphId);
  virtual Gcad::ErrorStatus addNode(GcDbEvalExpr*   pNode,
    GcDbEvalNodeId& id);
  virtual Gcad::ErrorStatus removeNode(const GcDbEvalNodeId& id);
  virtual Gcad::ErrorStatus removeNode(GcDbEvalExpr* pNode);
  virtual Gcad::ErrorStatus getAllNodes(GcDbEvalNodeIdArray& nodes) const;
  virtual Gcad::ErrorStatus getNode(const GcDbEvalNodeId& nodeId,
    GcDb::OpenMode        mode,
    GcDbObject**        ppNode) const;
  virtual Gcad::ErrorStatus addEdge(const GcDbEvalNodeId& idFrom,
    const GcDbEvalNodeId& idTo);
  virtual Gcad::ErrorStatus addEdge(const GcDbEvalNodeId& idFrom,
    const GcDbEvalNodeId& idTo,
    bool  bInvertible);
  virtual Gcad::ErrorStatus removeEdge(const GcDbEvalNodeId& idFrom,
    const GcDbEvalNodeId& idTo);
  virtual Gcad::ErrorStatus getIncomingEdges(const GcDbEvalNodeId& nodeId,
    GcDbEvalEdgeInfoArray& edges) const;
  virtual Gcad::ErrorStatus getOutgoingEdges(const GcDbEvalNodeId& nodeId,
    GcDbEvalEdgeInfoArray& edges) const;
  virtual Gcad::ErrorStatus getEdgeInfo(const GcDbEvalNodeId& nodeFrom,
    const GcDbEvalNodeId& nodeTo, GcDbEvalEdgeInfo& einfo) const;
  virtual Gcad::ErrorStatus addGraph(GcDbEvalGraph* pGraphToAdd,
    GcDbEvalIdMap*& idMap);
  virtual Gcad::ErrorStatus evaluate() const;
  virtual Gcad::ErrorStatus evaluate(const GcDbEvalContext*     pContext) const;
  virtual Gcad::ErrorStatus evaluate(const GcDbEvalContext*     pContext,
    const GcDbEvalNodeIdArray* activatedNodes) const;
  virtual Gcad::ErrorStatus activate(const GcDbEvalNodeIdArray& activatedNodes) const;
  virtual Gcad::ErrorStatus activate(const GcDbEvalNodeIdArray& activatedNodes,
    GcDbEvalNodeIdArray*       pActiveSubgraph) const;
  virtual Gcad::ErrorStatus activate(const GcDbEvalNodeIdArray& activatedNodes,
    GcDbEvalNodeIdArray*       pActiveSubgraph,
    GcDbEvalNodeIdArray*       pCycleNodes) const;
  virtual Gcad::ErrorStatus getIsActive(const GcDbEvalNodeId& id,
    bool& bIsActive) const;

  virtual bool equals(const GcDbEvalGraph* pOther) const;
  virtual bool isSubgraphOf(const GcDbEvalGraph* pOther) const;
  virtual Gcad::ErrorStatus postInDatabase(GcDbObjectId& objId, GcDbDatabase* pDb);
};

class GcDbEvalEdgeInfo
{
public:
  GcDbEvalEdgeInfo()
    : mFlags(0), mRefCount(0)
  {
    mIdFrom = GcDbEvalGraph::kNullNodeId;
    mIdTo = GcDbEvalGraph::kNullNodeId;
  }
  GcDbEvalEdgeInfo(GcDbEvalNodeId from,
    GcDbEvalNodeId to,
    Gsoft::Int32   flags,
    Gsoft::UInt32  count)
    : mIdFrom(from), mIdTo(to), mFlags(flags), mRefCount(count)
  {}

  GcDbEvalNodeId from() const;
  GcDbEvalNodeId to() const;
  Gsoft::UInt32 refCount() const;
  bool isInvertible() const;
  bool isSuppressed() const;
  bool operator == (const GcDbEvalEdgeInfo& other) const;

private:
  GcDbEvalNodeId mIdFrom;
  GcDbEvalNodeId mIdTo;
  Gsoft::Int32 mFlags;
  Gsoft::UInt32 mRefCount;
};

class DYNBLOCKS_PORT GcDbEvalExpr : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbEvalExpr);
  GcDbEvalExpr();
  ~GcDbEvalExpr();

  Gcad::ErrorStatus getGraph(GcDbEvalGraph** pGraph, GcDb::OpenMode  mode) const;
  GcDbEvalNodeId    nodeId() const;
  virtual void addedToGraph(GcDbEvalGraph*  pGraph);
  virtual void removedFromGraph(GcDbEvalGraph*  pGraph);
  virtual void adjacentNodeRemoved(const GcDbEvalNodeId& adjNodeId);
  virtual void adjacentEdgeRemoved(const GcDbEvalNodeId& adjEdgeNodeId);
  virtual void adjacentEdgeAdded(const GcDbEvalNodeId& fromId,
    const GcDbEvalNodeId& toId,
    bool bIsInvertible);
  virtual void movedFromGraph(GcDbEvalGraph* pFromGraph);
  virtual void movedIntoGraph(GcDbEvalGraph* pIntoGraph);
  virtual void remappedNodeIds(GcDbEvalIdMap& idMap);
  virtual void copiedIntoGraph(GcDbEvalGraph* pIntoGraph);
  virtual bool isActivatable();
  virtual void activated(GcDbEvalNodeIdArray& argumentActiveList);
  virtual void graphEvalStart(bool bNodeIsActive);
  virtual void graphEvalEnd(bool bNodeIsActive);
  virtual void graphEvalAbort(bool bNodeIsActive);
  virtual Gcad::ErrorStatus evaluate(const GcDbEvalContext* ctxt);
  virtual bool equals(const GcDbEvalExpr* pOther) const;
  GcDbEvalVariant value() const;
  virtual Gcad::ErrorStatus postInDatabase(GcDbObjectId& objId, GcDbDatabase* pDb);

protected:
  GcDbEvalVariant m_lastValue;
  friend class GcDbImpEvalExpr;
};

class DYNBLOCKS_PORT GcDbEvalConnectable : public GcDbEvalExpr
{
public:
  GCDB_DECLARE_MEMBERS(GcDbEvalConnectable);
  ~GcDbEvalConnectable();

  virtual Gcad::ErrorStatus getConnectionNames(GcStringArray& names) const;
  virtual bool              hasConnectionNamed(const GcString& name) const;
  virtual Gcad::ErrorStatus getConnectionType(
    const GcString&        name,
    GcDb::DwgDataType& type) const;
  virtual Gcad::ErrorStatus getConnectionValue(
    const GcString&    name,
    GcDbEvalVariant&    value) const;
  virtual Gcad::ErrorStatus setConnectionValue(
    const GcString&       name,
    const GcDbEvalVariant& value);
  virtual Gcad::ErrorStatus connectTo(
    const GcString&      thisConnection,
    const GcDbEvalNodeId sourceConnectableId,
    const GcString&      sourceConnectionName);
  virtual Gcad::ErrorStatus disconnectFrom(
    const GcString&      thisConnection,
    const GcDbEvalNodeId sourceConnectableId,
    const GcString&      sourceConnectionName);
  virtual bool connectionAllowed(
    const GcString&      thisConnection,
    const GcDbEvalNodeId sourceConnectableId,
    const GcString&      sourceConnectionName) const;
  virtual Gcad::ErrorStatus getConnectedObjects(const GcString&      thisConnection,
    GcDbEvalNodeIdArray& connectedObjects) const;
  virtual Gcad::ErrorStatus getConnectedNames(const GcString&      thisConnection,
    const GcDbEvalNodeId sourceConnectableId,
    GcStringArray&       sourceConnectionNames) const;
protected:
  GcDbEvalConnectable();
};

class DYNBLOCKS_PORT GcDbEvalContext : public GcRxObject, public GcHeapOperators
{
public:
  GcDbEvalContext();
  ~GcDbEvalContext();
  GCRX_DECLARE_MEMBERS(GcDbEvalContext);

  virtual void        insertAt(const GcDbEvalContextPair& pair);
  virtual void        removeAt(const GCHAR*                szKey);
  virtual Gcad::ErrorStatus getAt(GcDbEvalContextPair& pair) const;
  virtual GcDbEvalContextIterator* newIterator() const;

private:
  GcDbImpEvalContext* mpImp;
  friend class GcDbImpEvalContextIterator;
};

class DYNBLOCKS_PORT GcDbEvalContextPair : public GcHeapOperators
{
public:
  GcDbEvalContextPair();
  GcDbEvalContextPair(const GCHAR* szKey, void *pValue);
  virtual ~GcDbEvalContextPair();

  void        setKey(const GCHAR* szKey);
  const GCHAR* key() const;
  void        setValue(void* pValue);
  void*       value() const;

private:
  GCHAR* mKey;
  void* mValue;
};

class DYNBLOCKS_PORT GcDbEvalContextIterator : public GcRxObject, public GcHeapOperators
{
public:
  GcDbEvalContextIterator();
  ~GcDbEvalContextIterator();
  GCRX_DECLARE_MEMBERS(GcDbEvalContextIterator);

  virtual void   start();
  virtual bool   next();
  virtual bool   done() const;
  virtual GcDbEvalContextPair contextPair() const;

private:
  GcDbEvalContextIterator(GcDbEvalContext* pContext);
  GcDbImpEvalContextIterator* mpImp;
  friend class GcDbImpEvalContext;
};

#pragma pack(pop)