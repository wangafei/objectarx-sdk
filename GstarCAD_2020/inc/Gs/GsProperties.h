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


#ifndef _ODGSPROPERTIES_H_INCLUDED_
#define _ODGSPROPERTIES_H_INCLUDED_

#include "../OdaCommon.h"
#include "../RxObject.h"
#include "../Gi/GiDrawable.h"
#include "../Gi/GiCommonDraw.h"
#include "../Gs/GsExport.h"
#include "../CmColor.h"

class OdDbStub;

class OdGiRasterImage;

class OdGsBaseVectorizeView;

#include "../TD_PackPush.h"

/** Description:
    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class OdGsPropertiesDirectRenderOutput
{
  public:
    enum DirectRenderFlags
    {
      DirectRender_Point           = 1,
      DirectRender_LineFlat        = (1 << 1),
      DirectRender_LineGouraud     = (1 << 2),
      DirectRender_TriangleFlat    = (1 << 3),
      DirectRender_TriangleGouraud = (1 << 4),
      DirectRender_PolygoneFlat    = (1 << 5),
      DirectRender_PolygoneGouraud = (1 << 6),
      DirectRender_Image           = (1 << 7)
    };
    struct DirectRenderImageUV
    {
      double u, v;
    };
    struct DirectRenderImageParams
    {
      DirectRenderImageUV *uvCoords;
      const OdGiDrawable *pDrawable; // For images caching
    };
  public:
    virtual void directRenderOutputPoint(const OdGePoint3d &/*point*/,
                                         const OdCmEntityColor &/*color*/)
    {
    }
    virtual void directRenderOutputLineFlat(const OdGePoint3d &/*pt1*/, const OdGePoint3d &/*pt2*/,
                                            const OdCmEntityColor &/*color*/)
    {
    }
    virtual void directRenderOutputLineGouraud(const OdGePoint3d &/*pt1*/, const OdGePoint3d &/*pt2*/,
                                               const OdCmEntityColor &/*clr1*/, const OdCmEntityColor &/*clr2*/)
    {
    }
    virtual void directRenderOutputTriangleFlat(const OdGePoint3d &/*pt1*/, const OdGePoint3d &/*pt2*/, const OdGePoint3d &/*pt3*/,
                                                const OdCmEntityColor &/*color*/)
    {
    }
    virtual void directRenderOutputTriangleGouraud(const OdGePoint3d &/*pt1*/, const OdGePoint3d &/*pt2*/, const OdGePoint3d &/*pt3*/,
                                                   const OdCmEntityColor &/*clr1*/, const OdCmEntityColor &/*clr2*/, const OdCmEntityColor &/*clr3*/)
    {
    }
    virtual void directRenderOutputPolygoneFlat(OdUInt32 /*nPts*/, const OdGePoint3d * /*pPts*/,
                                                const OdCmEntityColor &/*color*/)
    {
    }
    virtual void directRenderOutputPolygoneGouraud(OdUInt32 /*nPts*/, const OdGePoint3d * /*pPts*/,
                                                   const OdCmEntityColor * /*pClrs*/)
    {
    }
    // Points order (0 is origin):
    //
    //  3------2
    //  |      |
    //  |  IM  |
    //  |      |
    //  0------1
    //
    virtual void directRenderOutputImage(const OdGePoint3d * /*pRect*/, const OdGiRasterImage * /*pImage*/,
                                         const OdGsPropertiesDirectRenderOutput::DirectRenderImageParams &/*driParams*/)
    {
    }

    virtual OdUInt32 directRenderOutputFlags() const = 0;
};

/** Description:
    Library: TD_Gs
    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsProperties : public OdRxObject
{
public:
  enum PropertiesType
  {
    kViewport          = 1,
    kBackground        = (1 << 1),
    kVisualStyle       = (1 << 2),
    kRenderEnvironment = (1 << 3),
    kRenderSettings    = (1 << 4),
    // Simple device
    kDeviceSimple      = 0,
    // Background-compatible device
    kDeviceBackground  = 3, // kViewport | kBackground
    // Normal vectorization device
    kDeviceNormal      = 7, // kViewport | kBackground | kVisualStyle
    // Rendering device
    kDeviceRender      = 0xFF, // kAll
    // Enable all properties
    kAll               = 0xFF
  };
protected:
  void *m_pUnderlyingDrawable;
  const OdGiDrawable *m_pInconsistentDrawable;
  OdGsBaseVectorizeView *m_pView;
  OdGiDrawablePtr (*m_pOpenDrawableFn)(OdDbStub* id);
  bool m_bDrawablePersistent;
  // For optimize
  OdGiDrawable::DrawableType m_dType;
public:
  ODRX_DECLARE_MEMBERS(OdGsProperties);

  OdGsProperties();

  void setOpenDrawableFn(OdGiDrawablePtr (*fn)(OdDbStub*));

  void setUnderlyingDrawable(const OdGiDrawable *pUnderlyingDrawable, OdGsBaseVectorizeView* view);
  OdGiDrawablePtr underlyingDrawable() const;
  bool isUnderlyingDrawableChanged(const OdGiDrawable *pUnderlyingDrawable) const;
  bool hasUnderlyingDrawable() const;

  bool isUnderlyingDrawablePersistent() const;
  OdDbStub* underlyingDrawableId() const;

  OdGiDrawable::DrawableType underlyingDrawableType() const;

  virtual PropertiesType propertiesType() const = 0;

  // Search down in hierarchy for appropriate properties
  virtual OdSmartPtr<OdGsProperties> propertiesForType(PropertiesType /*type*/) const;

  // Update attributes
  virtual void update(const OdGiDrawable* pUnderlyingDrawable, OdGsBaseVectorizeView* view, OdUInt32 incFlags = kAll) = 0;
  // Display attributed data
  virtual void display(OdGsBaseVectorizeView& view, OdGsPropertiesDirectRenderOutput *pdro = NULL, OdUInt32 incFlags = kAll) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsProperties object pointers.
*/
typedef OdSmartPtr<OdGsProperties> OdGsPropertiesPtr;

// Negative GETBIT
#ifndef GETBITNEG
#define GETBITNEG(flags, bit) (((flags) & (bit)) != (bit))
#endif

// NULL
#ifndef NULL
#define NULL 0
#endif

#include "../TD_PackPop.h"

#endif // _ODGSPROPERTIES_H_INCLUDED_
