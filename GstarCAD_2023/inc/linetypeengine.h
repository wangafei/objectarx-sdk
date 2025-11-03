/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcgi.h"
#pragma pack (push, 8)

class GcGiImpLinetypeEngine;

class GCCORE_PORT GcGiLinetypeEngine : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcGiLinetypeEngine);
  GcGiLinetypeEngine();
  ~GcGiLinetypeEngine();

  virtual Gcad::ErrorStatus tessellate(bool                 bIsArc,
                                       bool                 bIsCircle,
                                       const Gsoft::UInt32  nPoints,
                                       const GcGePoint3d  * pVertexList,
                                       GcGiWorldDraw *      pWorldDraw,
                                       const GcDbObjectId   linetypeId,
                                       double               linetypeScale,
                                       const GcGeVector3d * pNormal,
                                       bool                 plineGen = false);
  virtual Gcad::ErrorStatus tessellate(bool                 bIsArc,
                                       bool                 bIsCircle,
                                       const Gsoft::UInt32  nPoints,
                                       const GcGePoint3d  * pVertexList,
                                       GcGiViewportDraw *   pViewportDraw,
                                       const GcDbObjectId   linetypeId,
                                       double               linetypeScale,
                                       const GcGeVector3d * pNormal,
                                       bool                 plineGen = false);
  virtual Gcad::ErrorStatus tessellate(const GcGeCircArc3d& arcSeg,
                                       const GcGeMatrix3d&  ecsMat,
                                       double               startWidth,
                                       double               endWidth,
                                       GcGiCommonDraw *     pDraw,
                                       const GcDbObjectId   linetypeId,
                                       double               linetypeScale,
                                       double               thick);
  virtual Gcad::ErrorStatus tessellate(const GcGeLineSeg3d& lineSeg,
                                       const GcGeMatrix3d&  ecsMat,
                                       double               startWidth,
                                       double               endWidth,
                                       GcGiCommonDraw *     pDraw,
                                       const GcDbObjectId   linetypeId,
                                       double               linetypeScale);
private:
  GcGiImpLinetypeEngine * mpGcGiImpLinetypeEngine;
};

#pragma pack (pop)
