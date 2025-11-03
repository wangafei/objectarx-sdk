/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2018, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2018 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////


#ifndef __OD_GE_ENVELOP_UTILS__
#define __OD_GE_ENVELOP_UTILS__ /* {Secret} */

#include "Ge/GeCurve3d.h"
#include "Ge/GeNurbCurve3d.h"
#include "Ge/GePoint3d.h"
#include "Ge/GeVector3d.h"


namespace OdGeEnvelopUtils
{

  inline void determineLinePoints(const OdGeVector3d* dirs, OdUInt16 num, OdGePoint3d* pnts, double* dist,
    const OdGePoint3d AP[2])
  {
    for (OdUInt32 i = 0; i<num; ++i)
    {
      double d1 = AP[0].asVector().dotProduct(dirs[i]);
      double d2 = AP[1].asVector().dotProduct(dirs[i]);
      double d = odmax(d1, d2);
      if (d > dist[i])
      {
        dist[i] = d;
        pnts[i] = AP[d1 < d2];
      }
    }
  }

  inline void determineNurbPoints(const OdGeVector3d* dirs, OdUInt16 num, OdGePoint3d* pnts, double* dist,
    const OdGeNurbCurve3d* pCurve)
  {
    for (int f = 0; f<pCurve->numControlPoints(); ++f)
    {
      OdGePoint3d p = pCurve->controlPointAt(f);
      OdGeVector3d v = p.asVector();
      for (OdUInt32 i = 0; i<num; ++i)
      {
        double d = v.dotProduct(dirs[i]);
        if (d > dist[i])
        {
          dist[i] = d;
          pnts[i] = p;
        }
      }
    }
  }

  template<class TCurve>
  void determineEllipPoints(const OdGeVector3d* dirs, OdUInt16 num, OdGePoint3d* pnts, double* dist,
    const TCurve* pCurve)
  {
    OdGeExtents3d exts;
    pCurve->getGeomExtents(exts);

    OdGePoint3d AP[8];
    AP[3] = AP[2] = AP[1] = AP[0] = exts.minPoint();
    AP[7] = AP[6] = AP[5] = AP[4] = exts.maxPoint();

    AP[3].y = AP[1].y = AP[4].y;
    AP[3].x = AP[2].x = AP[4].x;

    AP[7].y = AP[5].y = AP[0].y;
    AP[7].x = AP[6].x = AP[0].x;

    for (int f = 0; f<8; ++f)
    {
      OdGeVector3d v = AP[f].asVector();
      for (OdUInt32 i = 0; i<num; ++i)
      {
        double d = v.dotProduct(dirs[i]);
        if (d > dist[i])
        {
          dist[i] = d;
          pnts[i] = AP[f];
        }
      }
    }
  }

  inline void determineApexPoints(const OdGeVector3d* dirs, OdUInt16 num, OdGePoint3d* pnts, double* dist,
    const OdGePoint3d& AP)
  {
    for (OdUInt32 i = 0; i<num; ++i)
    {
      double d = AP.asVector().dotProduct(dirs[i]);
      if (d > dist[i])
      {
        dist[i] = d;
        pnts[i] = AP;
      }
    }
  }

}

#endif // __OD_GE_ENVELOP_UTILS__
