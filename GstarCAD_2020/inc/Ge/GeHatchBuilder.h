#ifndef OD_GE_HATCHBUILDER_H
#define OD_GE_HATCHBUILDER_H

#include "GeExport.h"

#include "GeExtents2d.h"
#include "GeExtents3d.h"
#include "GePoint2dArray.h"
#include "GeKnotVector.h"
#include "GeVoidPointerArray.h"

#include <vector>
#include <set>


class OdGeHatchBuilderImpl;
class GeGraphLoop;

class OdGeHatchInterrupt
{
public:
  virtual int interruptCallback() = 0;
};

namespace GeHB
{
  typedef enum 
  {
    IN_FACE,
    OUTSIDE_FACE,
    ON_BOUNDARY,
    UNKNOWN
  }point_face_flag;

  typedef enum 
  {
    EXTERNAL,
    OUTERMOST,
    DEFAULT,
  }LOOP_TYPE;

  typedef enum 
  {
    EXACT_IN,
    CLOSEST_IN
  }LOOP_FIND_METHOD;
}

class GE_TOOLKIT_EXPORT OdGeHatchLoop 
{
  OdGeHatchLoop(OdGeHatchLoop& src);
  OdGeHatchLoop& operator=(const OdGeHatchLoop& color);
public:
  OdGeHatchLoop();
  OdGeHatchLoop(GeGraphLoop* pLoop);
  ~OdGeHatchLoop();

  int  pointLocation( const OdGePoint3d & pnt, double &distance );
  bool contains(OdGeHatchLoop* pLoop);
  const OdGeExtents3d& boundBlock() const;

  GeGraphLoop* mpLoop;
};

class GE_TOOLKIT_EXPORT OdGeHatchBuilder 
{
public:
  OdGeHatchBuilder();
  OdGeHatchBuilder( bool isTrimmedHatch, double gapTol = 1.0e-6, double pixelUnitLength = 1.0e-6);
  ~OdGeHatchBuilder();

  void addLine(const OdGePoint2d &rootPt, const OdGeVector2d &direction, void *id);
  void addRay(const OdGePoint2d &rootPt, const OdGeVector2d &direction, void *id);
  void addLineSeg(const OdGePoint2d &startPt, const OdGePoint2d &endPt, void* id);
  void addCirArc(const OdGePoint2d &statPt, const OdGePoint2d &midPt, const OdGePoint2d &endPt, void* id);
  void addCircle(const OdGePoint2d &center, const double radius, void* id);
  void addEllipArc(const OdGePoint2d &center, const OdGeVector2d &majorAxis, const OdGeVector2d &minorAxis, 
    const double majorRadius, const double minorRadius,  double startAngle, double endAngle, void* id);
  void addPolyline(const OdGePoint2dArray &pnts, const OdGeDoubleArray &bugles, void *id);
  void addNurb(int degree, bool rational, bool closed, bool periodic,
    const OdGePoint2dArray &pnts, const OdGeDoubleArray &weights, const OdGeKnotVector &knots, void *id);

  bool evaluateHatch();

  bool beginEvaluateHatch();
  bool addLoops(const std::vector<OdGeVoidPointerArray> &boundary, const std::vector<OdGeVoidPointerArray> &ids);
  bool endEvaluateHatch();

  void setInterruptCallback(OdGeHatchInterrupt* pInterrupt);

  bool isBadHatch() const;

  GeHB::point_face_flag getLoops(const OdGePoint2d &pnt, 
    std::vector<OdGeVoidPointerArray> &boundary, 
    std::vector<OdGeVoidPointerArray> &ids, 
    std::vector<GeHB::LOOP_TYPE> &boundarTypes,
    GeHB::LOOP_FIND_METHOD findMethod = GeHB::EXACT_IN);

  bool getLoops(std::vector<OdGeVoidPointerArray> &boundary, 
    std::vector<OdGeVoidPointerArray> &ids, 
    std::vector<GeHB::LOOP_TYPE> &boudaryTypes,
    std::vector<bool> &closedFlag);

  int faceSize() const;

  bool getSubFaces(int index, 
    std::vector<OdGeVoidPointerArray> &boundary, 
    std::vector<OdGeVoidPointerArray> &ids, 
    std::vector<GeHB::LOOP_TYPE> &boudaryTypes, 
    std::vector<bool> &closedFlag);

  GeHB::point_face_flag pointOnFace(const OdGePoint2d &pnt, 
    const OdGeVoidPointerArray &boundary);

  bool getLoopTypes(const std::vector<OdGeVoidPointerArray> &allLoops,
    std::vector<GeHB::LOOP_TYPE> &loopTypes);

  bool getGeoExtents(OdGeExtents2d &bBox) const;

  static OdGeHatchLoop* createLoopFromCurve2ds(const OdGeVoidPointerArray& curve2ds);

  static bool sortLoops(std::vector<OdGeHatchLoop*> &loopSet, 
    std::set<int>& externalIndex, 
    std::set<int>& innerIndex, 
    std::set<int>& defaultIndex);

private:
  OdGeHatchBuilderImpl *mImpl;
};

#endif
