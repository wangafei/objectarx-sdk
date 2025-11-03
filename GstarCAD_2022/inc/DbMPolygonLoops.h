#ifndef _OD_DB_DBMPOLYGONEX_
#define _OD_DB_DBMPOLYGONEX_

class OdDbMpolygonLoops
{
public:
  OdDbMpolygonLoops(int lindex, int gindex = 0, int gcnt = 0);

  int mLoopIndex;
  bool mIsText;
  int mGripIndex;
  int mGripCount;
  OdGePoint2dArray mVertexPoints;
  OdGeDoubleArray mVertexBulges;
};

class OdDbMPolygonCrossing
{
public:
  OdDbMPolygonCrossing();
  ~OdDbMPolygonCrossing();

  int getLoopIndex() const;
  void setLoopIndex(int index);

  int getEdgeIndex() const;
  void setEdgeIndex(int index);

  OdGePoint2d getCrossingPoint() const;
  void setCrossingPoint(const OdGePoint2d& pt);

private:
  void* pImp;
};

class OdDbMPolygonNode
{
public:
  OdDbMPolygonNode();

public:
  OdDbMPolygonNode * mParent;
  OdArray<OdDbMPolygonNode*> mChildren;
  int mLoopIndex;
};

#endif