#pragma once

#include "../OdaCommon.h"
#include "../DbObjectId.h"
#include "../Gi/Gi.h"
#include "../Gi/GiViewportDraw.h"
#include "../Gi/GiWorldDraw.h"
#include "../Ge/GeCircArc3d.h"
#include "../Ge/GeLineSeg3d.h"

class OdGiLinetypeEngine : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiLinetypeEngine);

  OdGiLinetypeEngine();
  virtual ~OdGiLinetypeEngine();

  // Tessellate the polyline with linetype applied, through world draw
  virtual OdResult tessellate(
    bool                 bIsArc,
    bool                 bIsCircle,
    const OdUInt32       nPoints,
    const OdGePoint3d  * pVertexList,
    OdGiWorldDraw *      pWorldDraw,
    const OdDbObjectId   linetypeId,
    double               linetypeScale,
    const OdGeVector3d * pNormal);

  // Tessellate the polyline with linetype applied, through viewport draw
  virtual OdResult tessellate(
    bool                 bIsArc,
    bool                 bIsCircle,
    const OdUInt32       nPoints,
    const OdGePoint3d  * pVertexList,
    OdGiViewportDraw *   pViewportDraw,
    const OdDbObjectId   linetypeId,
    double               linetypeScale,
    const OdGeVector3d * pNormal);

  virtual OdResult tessellate(
    const OdGeCircArc3d& arcSeg,
    const OdGeMatrix3d&  ecsMat,
    double               startWidth,
    double               endWidth,
    OdGiCommonDraw *     pDraw,
    const OdDbObjectId   linetypeId,
    double               linetypeScale,
    double               thick);

  virtual OdResult tessellate(
    const OdGeLineSeg3d& lineSeg,
    const OdGeMatrix3d&  ecsMat,
    double               startWidth,
    double               endWidth,
    OdGiCommonDraw *     pDraw,
    const OdDbObjectId   linetypeId,
    double               linetypeScale);

};


