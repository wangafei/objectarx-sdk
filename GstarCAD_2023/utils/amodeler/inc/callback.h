/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_CALLBACK_H
#define GMODELER_INC_CALLBACK_H

#include "global.h"
#include "color.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp OutputPolylineCallback
{
public:
  virtual ~OutputPolylineCallback() {}

  virtual void outputPolyline(Edge*          edgeArray[],
                              const Point3d  pointArray[],
                              const double   bulgeArray[],
                              int            numPoints,
                              bool           isClosed,
                              bool           isVisible) = NULL;
  virtual void outputArc(Edge*          edge,
                         const Point3d& center,
                         double         radius,
                         double         startAngle,
                         double         endAngle,
                         bool           isVisible) = NULL;
};

class DllImpExp OutputTriangleCallback
{
public:
  virtual ~OutputTriangleCallback() {}

  virtual void outputTriangle(Edge* edgeArray[], int arrayLength) = NULL;

  enum
  {
    kMaxTriStripLength = 200
  };

  virtual void outputTriStrip(Edge* edgeArray[],
                              int   arrayLength,
                              bool  firstTriangleIsCcw) = NULL;
};

class DllImpExp SaveRestoreCallback
{
public:
  virtual ~SaveRestoreCallback() {}

  virtual void saveBytes(const void* buffer, int requiredLength) = NULL;
  virtual void restoreBytes(void*    buffer, int requiredLength) = NULL;
};

class DllImpExp TopologyChangeCallback
{
public:
  virtual ~TopologyChangeCallback() {}

  virtual void entityCreated(Entity*) = NULL;
  virtual void entityDeleted(Entity*) = NULL;
  virtual void entitySplit(Entity* pOrig, Entity* pNew) = NULL;
  virtual void entityMerged(Entity* pSurviving, Entity* pDeleted) = NULL;
};

class DllImpExp SaveToSatCallback
{
public:
  virtual ~SaveToSatCallback() {}

  virtual void saveIndex(int) = NULL;
  virtual void saveIdent(const char*) = NULL;
  virtual void saveDouble(double) = NULL;
  virtual void saveInt(int) = NULL;
};

GMODELER_NAMESPACE_END
#endif
