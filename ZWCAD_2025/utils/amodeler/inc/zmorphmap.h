
#ifndef AECMODELER_INC_MORPHMAP_H
#define AECMODELER_INC_MORPHMAP_H


#include "zglobal.h"
#include "zdarray.h"


AECMODELER_NAMESPACE_BEGIN


class DllImpExp ZwMorphingMap
{
public:
    ZwMorphingMap() {}
    ZwMorphingMap(const ZwMorphingMap&);
    ~ZwMorphingMap();

    ZwMorphingMap& operator =(const ZwMorphingMap&);

    void  add  (int from, int to, int vis = 0);
    void  addAt(int index, int from, int to, int vis = 0);
    void  del  (int index);
    void  get  (int index, int& fromIndex, int& toIndex, int& visibility) const;

    int  length() const { return mArray.length(); }
    bool isNull() const { return mArray.length() == 0; }
    bool isIdentity() const;

    void setToExplicitIdentityMap(int numEdges);

    void createFromTwoPointLoops(const std::vector<ZwPoint2d>&, const std::vector<ZwPoint2d>&);

    void init();
    void print() const;

    void normalize(int numEdges0, int numEdges1);

    void remapIndices(const std::vector<int>& fromIndexMap, const std::vector<int>& toIndexMap);

    static const ZwMorphingMap kNull;

    enum { kCrossEdgeIsApprox = 1, kBaseEdgeIsApprox = 2 };

private:

    class MorphingMapElem
    {
    public:
        MorphingMapElem(int i, int j, int vis = 0) : fromIndex(i), toIndex(j), visibility(vis) {} 

        int fromIndex;
        int toIndex;
        int visibility;
    };

    ZwDarray mArray;
};



DllImpExp void makeIndexToEdgeMap(  int                 prof0NumEdges, 
                                    const ZwBody&         prof1, 
                                    const ZwMorphingMap&  morphingMap,
                                    ZwDarray&             indexToEdgeMap);

DllImpExp void splitMorphingMap(    const ZwBody&         prof0, 
                                    const ZwBody&         prof1, 
                                    const ZwMorphingMap&  morphingMap,
                                    ZwBody&               midProf,
                                    ZwMorphingMap&        midMorphingMap, 
                                    ZwMorphingMap&        morphingMap0, 
                                    ZwMorphingMap&        morphingMap1); 
AECMODELER_NAMESPACE_END
#endif

