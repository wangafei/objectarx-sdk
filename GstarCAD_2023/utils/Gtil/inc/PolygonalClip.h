/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef POLYGONALCLIP_H
#define POLYGONALCLIP_H

#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef POINT2D_H
#include "Point2d.h"
#endif
#ifndef SPANPROVIDERINTERFACE_H
#include "SpanProviderInterface.h"
#endif
#ifndef GTILFILTERSVERSION_H
#include "AtilFiltersVersion.h"
#endif

namespace GtilFilters
{
  class PolyList;
  class Edge;

  class GTIL_EXPORT PolygonalClip : public SpanProviderInterface
  {
  public:
    enum Operation
    {
      kClipCrop,
      kWindow
    };

  public:
    PolygonalClip(int nPoints, const Gtil::Point2d* cpaPolygon, Operation op);
    ~PolygonalClip();

    Operation operation() const;

    virtual SpanProviderInterface* clone() const;

    virtual void begin();

    virtual Mode mode();

    virtual void end();

    virtual bool nextRow();

    virtual int numRows();

    virtual bool getNextSpan(int& nStart, int& nCount);

    virtual int numSpans();

    virtual const Gtil::BoundingBox& bounds() const;

    GtilFiltersVersion version;

  private:
    void preUpdateActiveEdgeTable(int nCurrentY);
    void postUpdateActiveEdgeTable();
    int roundAndClipToInt(const double& dValue) const;

    int mnPoints;
    Gtil::Point2d* mpPolygon;

    int mnRows;
    int mnOnRow;
    int mnSpans;

    PolyList** mapEdgeBucketSortList;
    PolyList* mpActiveEdgeSortList;
    Edge* mpCurEdge;

    Gtil::BoundingBox mBounds;
    Operation mOp;

    bool mbValidRegion;
  };
}

#endif
