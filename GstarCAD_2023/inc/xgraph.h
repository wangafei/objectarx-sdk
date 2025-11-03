/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_XGRAPH_H
#define GD_XGRAPH_H 1

#include "graph.h"
#include "GdGChar.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbXrefGraphNode : public GcDbGraphNode
{
public:
  GcDbXrefGraphNode(const GCHAR *       pName = NULL,
                    const GcDbObjectId& btrId = GcDbObjectId::kNull,
                    GcDbDatabase*       pDb = NULL,
                    GcDb::XrefStatus    status = GcDb::kXrfResolved);
  ~GcDbXrefGraphNode();

  const GCHAR * name() const;
  GcDbObjectId  btrId() const;
  GcDbDatabase* database() const;

  Gcad::ErrorStatus setName(const GCHAR * pName);
  void setBtrId(const GcDbObjectId& id);
  void setDatabase(GcDbDatabase* pDb);

  bool isNested() const;

  GcDb::XrefStatus xrefStatus() const;
  void             setXrefStatus(GcDb::XrefStatus stat);

  GcDb::XrefNotificationStatus xrefNotificationStatus() const;
  void                         setXrefNotificationStatus(GcDb::XrefNotificationStatus stat);

  void*   xData() { return mpxdata; }
  void    setxData(void *pXData) { mpxdata = pXData; }

  Gcad::ErrorStatus xrefReadSubstatus() const;

private:
  void*   mpxdata;
  GCHAR * mpName;
  GcDbObjectId     mBtrId;
  GcDb::XrefStatus mStatus;
  GcDb::XrefNotificationStatus mNotifyStatus;
};

class GCDB_PORT GcDbXrefGraph : public GcDbGraph
{
public:
  GcDbXrefGraph(GcDbXrefGraphNode* pHostDwg = NULL);
  ~GcDbXrefGraph();

  GcDbXrefGraphNode* xrefNode(const GCHAR * pName) const;
  GcDbXrefGraphNode* xrefNode(GcDbObjectId btrId) const;
  GcDbXrefGraphNode* xrefNode(const GcDbDatabase* pDb) const;

  GcDbXrefGraphNode* xrefNode(int idx) const;
  GcDbXrefGraphNode* hostDwg() const;

  Gsoft::Boolean markUnresolvedTrees();

  virtual Gsoft::Boolean findCycles(GcDbGraphNode* pStart = NULL);
};

GCCORE_PORT Gcad::ErrorStatus gcedGetCurDwgXrefGraph(GcDbXrefGraph&, Gsoft::Boolean includeGhosts = Gsoft::kFalse);

inline const GCHAR * GcDbXrefGraphNode::name() const
{
  return mpName;
}
inline GcDbObjectId GcDbXrefGraphNode::btrId() const
{
  return mBtrId;
}
inline GcDbDatabase* GcDbXrefGraphNode::database() const
{
  return (GcDbDatabase*)data();
}

inline void GcDbXrefGraphNode::setBtrId(const GcDbObjectId& id)
{
  mBtrId = id;
}
inline void GcDbXrefGraphNode::setDatabase(GcDbDatabase* pDb)
{
  setData(pDb);
}

inline bool GcDbXrefGraphNode::isNested() const
{
  return !isMarkedAs(kFirstLevel);
}

inline GcDb::XrefStatus GcDbXrefGraphNode::xrefStatus() const
{
  return mStatus;
}
inline void GcDbXrefGraphNode::setXrefStatus(GcDb::XrefStatus stat)
{
  mStatus = stat;
}

inline GcDb::XrefNotificationStatus GcDbXrefGraphNode::xrefNotificationStatus() const
{
  return mNotifyStatus;
}
inline void GcDbXrefGraphNode::setXrefNotificationStatus(GcDb::XrefNotificationStatus stat)
{
  mNotifyStatus = stat;
}

inline GcDbXrefGraphNode* GcDbXrefGraph::xrefNode(int idx) const
{
  return (GcDbXrefGraphNode*)node(idx);
}

inline GcDbXrefGraphNode* GcDbXrefGraph::hostDwg() const
{
  return (GcDbXrefGraphNode*)rootNode();
}

#pragma pack (pop)
#endif
