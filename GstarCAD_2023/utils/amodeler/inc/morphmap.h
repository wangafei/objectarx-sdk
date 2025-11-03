/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_MORPHMAP_H
#define GMODELER_INC_MORPHMAP_H

#include "global.h"
#include "darray.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp MorphingMap
{
public:
  MorphingMap() {}
  MorphingMap(const MorphingMap&);
  ~MorphingMap();

  MorphingMap& operator =(const MorphingMap&);

  void  add(int from, int to, int vis = 0);
  void  addAt(int index, int from, int to, int vis = 0);
  void  del(int index);
  void  get(int index, int& fromIndex, int& toIndex, int& visibility) const;

  int  length() const { return mArray.length(); }
  bool isNull() const { return mArray.length() == 0; }
  bool isIdentity() const;

  void setToExplicitIdentityMap(int numEdges);

  void createFromTwoPointLoops(const std::vector<Point2d>&, const std::vector<Point2d>&);

  void init();
  void print() const;

  void normalize(int numEdges0, int numEdges1);

  void remapIndices(const std::vector<int>& fromIndexMap, const std::vector<int>& toIndexMap);

  static const MorphingMap kNull;

  enum
  {
    kCrossEdgeIsApprox = 1,
    kBaseEdgeIsApprox = 2
  };

private:
  class MorphingMapElem
  {
  public:
    MorphingMapElem(int i, int j, int vis = 0) : fromIndex(i), toIndex(j), visibility(vis) {}

    int fromIndex;
    int toIndex;
    int visibility;
  };
  Darray mArray;
};

DllImpExp void makeIndexToEdgeMap(int                 prof0NumEdges,
                                  const Body&         prof1,
                                  const MorphingMap&  morphingMap,
                                  Darray&             indexToEdgeMap);

DllImpExp void splitMorphingMap(const Body&         prof0,
                                const Body&         prof1,
                                const MorphingMap&  morphingMap,
                                Body&               midProf,
                                MorphingMap&        midMorphingMap,
                                MorphingMap&        morphingMap0,
                                MorphingMap&        morphingMap1);

GMODELER_NAMESPACE_END
#endif
