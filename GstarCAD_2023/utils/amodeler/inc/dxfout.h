/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_DXFOUT_H
#define GMODELER_INC_DXFOUT_H

#include "callback.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp OutputToDxfFileCallback : public OutputPolylineCallback,
  public OutputTriangleCallback
{
public:
  OutputToDxfFileCallback(const wchar_t* dxfFileName);
  ~OutputToDxfFileCallback();

  virtual void outputPolyline(Edge*             edgeArray[],
                              const Point3d     pointArray[],
                              const double      bulgeArray[],
                              int               numPoints,
                              bool              isClosed,
                              bool              isVisible);
  virtual void outputArc(Edge*          edge,
                         const Point3d& center,
                         double         radius,
                         double         startAngle,
                         double         endAngle,
                         bool           isVisible);
  virtual void outputTriangle(Edge* edgeArray[], int arrayLength);
  virtual void outputTriStrip(Edge* edgeArray[], int arrayLength, bool firstTriangleIsCcw);

private:
  FILE* mpFile;
  void g(int code, const char*    value) const;
  void g(int code, int            value) const;
  void g(int code, double         value) const;
  void g(int code, const Point2d& value) const;
  void g(int code, const Point3d& value) const;
};

DllImpExp extern void printTriangle(Edge* edgeArray[], int numSides);

GMODELER_NAMESPACE_END
#endif
