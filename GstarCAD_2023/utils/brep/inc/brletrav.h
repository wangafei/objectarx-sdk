/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRLETRAV_H
#define GC_BRLETRAV_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brtrav.h"

class GcGeCurve2d;
class GcGeCurve3d;
class GcGeNurbCurve2d;
class GcGeNurbCurve3d;
class GcBrLoop;
class GcBrEdge;
class GcBrFaceLoopTraverser;
class GcBrEdgeLoopTraverser;

class GCBR_PORT GcBrLoopEdgeTraverser : public GcBrTraverser
{
public:
  GCRX_DECLARE_MEMBERS(GcBrLoopEdgeTraverser);
  GcBrLoopEdgeTraverser();
  GcBrLoopEdgeTraverser(const GcBrLoopEdgeTraverser& src);
  ~GcBrLoopEdgeTraverser();

  GcBrLoopEdgeTraverser& operator =   (const GcBrLoopEdgeTraverser& src);

  GcBr::ErrorStatus   setLoopAndEdge(GcBrEdgeLoopTraverser& edgeLoop);
  GcBr::ErrorStatus   setLoop(GcBrFaceLoopTraverser& loop);
  GcBr::ErrorStatus   getLoop(GcBrLoop& loop) const;
  GcBr::ErrorStatus   setEdge(GcBrEdge& edge);
  GcBr::ErrorStatus   getEdge(GcBrEdge& edge) const;

  GcBr::ErrorStatus   getEdgeOrientToLoop(Gsoft::Boolean& orient) const;
  GcBr::ErrorStatus   getParamCurve(GcGeCurve2d*& pcurve) const;
  GcBr::ErrorStatus   getOrientedCurve(GcGeCurve3d*& curve) const;
  GcBr::ErrorStatus   getParamCurveAsNurb(GcGeNurbCurve2d& nurb,
                                          const double&    fitTolRequired = *(double*)NULL,
                                          double&          fitTolAchieved = *(double*)NULL) const;
  GcBr::ErrorStatus   getOrientedCurveAsNurb(GcGeNurbCurve3d& nurb,
                                             const double&    fitTolRequired = *(double*)NULL,
                                             double&          fitTolAchieved = *(double*)NULL) const;

  GcBr::ErrorStatus   setLoopAndEdge(const GcBrEdgeLoopTraverser& edgeLoop);
  GcBr::ErrorStatus   setLoop(const GcBrFaceLoopTraverser& faceLoop);
  GcBr::ErrorStatus   setLoop(const GcBrLoop& loop);
  GcBr::ErrorStatus   setEdge(const GcBrEdge& edge);
};

#endif