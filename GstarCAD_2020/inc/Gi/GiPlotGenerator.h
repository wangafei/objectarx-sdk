/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef __OD_GI_PLOTGENERATOR__
#define __OD_GI_PLOTGENERATOR__

#include "Gi/GiConveyorNode.h"

#include "TD_PackPush.h"
#include "Ps/PlotStyles.h"
#include "Gs/GsExport.h"

/** Description:
    This class is the base class for custom classes that compute the extents of OdGiConveyorGeometry objects.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiPlotGenerator : public OdGiConveyorNode
{
public:
  ODRX_DECLARE_MEMBERS(OdGiPlotGenerator);

  /**
    Sets max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGeDoubleArray& deviations) = 0;

  /**
    Sets deviation object to obtain max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGiDeviation* pDeviation) = 0;

  /** Description:
    Sets the draw context associated with this object.
    Arguments:
    pDrawContext (I) Pointer to the draw context.
  */
  virtual void setDrawContext(OdGiConveyorContext* pDrawContext) = 0;

  virtual void enable(bool bEnable) = 0;

  virtual bool enabled() const = 0;

  virtual void dot_per_inch(double dpi) = 0;
  virtual double dot_per_inch() const = 0;

  void dot_per_mm(double dpmm);
  double dot_per_mm() const;

  virtual void setPlotStyle(const OdPsPlotStyleData& psd) = 0;
};

inline void
OdGiPlotGenerator::dot_per_mm(double dpmm)
{
  dot_per_inch(dpmm * 25.4);
}

inline double
OdGiPlotGenerator::dot_per_mm() const
{
  return dot_per_inch() / 25.4;
}


/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiExtAccum object pointers.
*/
typedef OdSmartPtr<OdGiPlotGenerator> OdGiPlotGeneratorPtr;

#include "TD_PackPop.h"

#endif //#ifndef __OD_GI_PLOTGENERATOR__
