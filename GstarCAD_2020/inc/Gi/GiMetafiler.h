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

#ifndef __OD_GI_METAFILER__
#define __OD_GI_METAFILER__

#include "../Gi/GiConveyorNode.h"
#include "../Gi/GiChunkAllocator.h"
#include "../Ge/GeDoubleArray.h"

class OdGiDeviation;

#include "../TD_PackPush.h"


/** Description:

    {group:OdGi_Classes} 
*/
class OdGiGeometryMetafile;
class ODGI_EXPORT OdGiGeometryMetafileRecord
{
public:
  ODGI_HEAP_OPERATORS();
  virtual ~OdGiGeometryMetafileRecord(){}
  virtual void play(OdGiConveyorGeometry* pGeom, OdGiConveyorContext* pCtx) const = 0;
  virtual bool appendTo(OdGiGeometryMetafile* pMf) { return false; }
};

class ODGI_EXPORT OdGiGeometryMetafile : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiGeometryMetafile);
  ODGI_HEAP_OPERATORS();
  
  virtual void clear() = 0;
  virtual void play(OdGiConveyorGeometry* pGeom, OdGiConveyorContext* pCtx) const = 0;
  virtual void saveTraits(const OdGiSubEntityTraitsData& entTraits) = 0;
  virtual void saveRecord(OdGiGeometryMetafileRecord* pRec) = 0;
};

typedef OdSmartPtr<OdGiGeometryMetafile> OdGiGeometryMetafilePtr;

/** Description:

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiMetafiler : public OdGiConveyorNode
{
public:
  ODRX_DECLARE_MEMBERS(OdGiMetafiler);
  
  virtual void setMetafile(OdGiGeometryMetafile* pMetafile) = 0;
  virtual OdGiGeometryMetafile* metafile() = 0;

  /**
    Sets max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGeDoubleArray& deviations) = 0;

  /**
    Sets deviation object to obtain max deviation for curve tesselation.
  */
  virtual void setDeviation(const OdGiDeviation* pDeviation) = 0;

  /**
    Sets the draw context object (to access to traits, etc).
  */
  virtual void setDrawContext(OdGiConveyorContext* pDrawCtx) = 0;

  enum CoordType
  {
    kUnknown = 0,
    kModel,
    kWorld,
    kEye,
    kDevice
  };

  /**
    Sets coordinates type for geometry stored by metafiler.
  */
  virtual void setCoordinatesType(CoordType ct) = 0;

  /**
    Returns coordinates type used by this metafiler object.
  */
  virtual CoordType coordinatesType() const = 0;

  /**
    Save traits into metafile. Optionally save ByBlock traits.
  */
  virtual bool saveTraits(const OdGiSubEntityTraitsData& entTraits, const OdGiSubEntityTraitsData *byBlockTraits = NULL) = 0;
  /**
    Save effective traits into metafile. Optionally save ByBlock traits.
  */
  virtual bool saveTraits(const OdGiSubEntityTraitsData *byBlockTraits) = 0;
  /**
    Save only effective traits into metafile.
  */
  virtual bool saveTraits() = 0;

  /**
    Flush all data to the metafile
  */
  virtual void flush(bool bForceTraits = true) = 0;

  /**
    Adds metafile record to the records list.
  */
  virtual void addRecord(OdGiGeometryMetafileRecord* pRec) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMetafiler object pointers.
*/
typedef OdSmartPtr<OdGiMetafiler> OdGiMetafilerPtr;

#include "../TD_PackPop.h"

#endif //#ifndef __OD_GI_METAFILER__
