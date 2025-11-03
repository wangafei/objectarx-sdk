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




#ifndef OD_DBDIMASSOC_H
#define OD_DBDIMASSOC_H

#include "TD_PackPush.h"

#include "DbSubentId.h"
#include "DbHandle.h"


/** Description:
    This class uniquely defines Xref subentities within an OdDbDatabase instance.  

    Remarks:
    Each OdDbXrefFullSubentPath object consists of a OdDbSubentId object,
    an ordered array of Object IDs, and an ordered array of entity handles. 
    The SubentId consists the index and subentType
    of the object. The array of Object IDs, and the array of handles, define the path to the 
    subentity from the outermost entity (in PaperSpace or ModelSpace) 
    to the entity containing the subentity.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbXrefFullSubentPath : public OdDbFullSubentPath
{
public:
  /** Description:
    Returns a reference to the embedded OdHandleArray object in this XrefFullSubentPath object.
    
    Arguments:
    objectIds (O) Receives the array reference.
  */
  OdHandleArray& xrefObjHandles();
  const OdHandleArray& xrefObjHandles()const;

  /** 
    Description:
    Reads the .dwg file format data of this object from the specified file.
       
    Arguments:   
    pFiler (I) Pointer to the filer from which the data are to be read.
  */
  void dwgIn(OdDbDwgFiler* pFiler);

  /** 
    Description:
    Writes the .dwg file format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
    
  */
  void dwgOut(OdDbDwgFiler* pFiler) const;

  /** 
    Description:
    Writes the DXF format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
    groupCodeOffset (I) Group code offset.
  */
  void dxfOut(OdDbDxfFiler* pFiler, OdInt groupCodeOffset = 0) const;

  OdDbXrefFullSubentPath& operator =(const OdDbFullSubentPath& fullSubentPath)
  {
    //m_XrefObjHandles.clear();
    OdDbBaseFullSubentPath::operator=(fullSubentPath);
    return *this;
  }
private:
  OdHandleArray m_XrefObjHandles;
};

class OdDbOsnapPointRef;
class OdDbViewport;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbOsnapPointRef object pointers.
*/
typedef OdSmartPtr<OdDbOsnapPointRef> OdDbOsnapPointRefPtr;
//typedef OdArray<OdDbFullSubentPath> OdDbFullSubentPathArray;

typedef OdArray<OdDbHandle, OdObjectsAllocator<OdDbHandle> >
    OdDbHandleArrayPtRef;
/** Description:
    This class defines a point reference between a dimension and
	its corresponding object.

    Library: TD_Db
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPointRef : public OdRxObject
{
public:
  enum OsnapType { 
    kOsnapNone         = 0,
    kOsnapEnd          = 1,
    kOsnapMid          = 2,
    kOsnapCen          = 3,
    kOsnapNode         = 4,
    kOsnapQuad         = 5, 
    kOsnapInt          = 6,
    kOsnapIns          = 7,
    kOsnapPerp         = 8,
    kOsnapTan          = 9,
    kOsnapNear         = 10,
    kOsnapApint        = 11,
    kOsnapStart        = 13
  };

  ODRX_DECLARE_MEMBERS(OdDbPointRef);

  virtual OdDbPointRef& operator=(const OdDbPointRef& src);

  virtual OdResult subErase(OdBool erasing) { return eOk; }

  virtual OdResult wblockClone(OdRxObject* pOwnerObject,
                               OdDbObject*& pClonedObject,
                               OdDbIdMapping& idMap,
                               OdBool isPrimary = kTrue)
                               const {return eOk;}

  virtual OdResult deepClone(OdRxObject* pOwnerObject,
                             OdDbObject*& pClonedObject,
                             OdDbIdMapping& idMap,
                             OdBool isPrimary = kTrue)
                             const {return eOk;}

  virtual OdResult evalPoint(OdGePoint3d& pnt_wcs) = 0; 
  virtual OdResult getEntities(OdDbFullSubentPathArray& ents, bool getLastPtRef = true) const = 0;
  virtual bool isGeomErased() const = 0;
  virtual bool isXrefObj(OdDbObjectIdArray& ids1, OdDbObjectIdArray& ids2, bool isMainObj = true) const = 0;
  virtual OdResult updateXrefSubentPath() = 0;
  virtual OdResult updateSubentPath(OdDbIdMapping& idMap) = 0;

  virtual void dwgOutFields(OdDbDwgFiler* filer) const = 0;
  virtual OdResult dwgOutFields(OdDbDwgFiler* filer, OdDbDatabase* pDb)const
  {
    dwgOutFields(filer);
    return eOk;
  }

  virtual void dwgInFields(OdDbDwgFiler* filer) = 0;
  virtual OdResult dwgInFields(OdDbDwgFiler* filer, OdDbDatabase* pDb)
  {
     dwgInFields(filer);
     return eOk;
  }  

  virtual void dxfOutFields(OdDbDxfFiler* filer) const = 0;
  virtual OdResult dxfOutFields(OdDbDxfFiler* filer, OdDbDatabase* pDb) const
  {
     dxfOutFields(filer);
     return eOk;
  }  

  virtual OdResult dxfInFields(OdDbDxfFiler* filer) = 0;
  virtual OdResult dxfInFields(OdDbDxfFiler* filer, OdDbDatabase* pDb)
  {
     dxfInFields(filer);
     return eOk;
  }
  virtual void updateDueToMirror(bool inMirror = false) = 0;

/** \details
  Calculates transformation combined from OdDbViewport's MS2PS and BlockReference transformations
*/
  static bool calcTransform(const OdDbObjectIdArray& ids, OdGeMatrix3d& A_Ecs2Wcs);

  /** \details
  Returns matrix to convert MS coordinates to PS for given OdDbViewport entity
  */
  static OdGeMatrix3d mswcsToPswcs(const OdDbViewport* pVPort);

  static OdResult  dwgInFields(OdDbDwgFiler* filer, OdDbDatabase* pDb, OdDbPointRef*& pPointRef);
  static OdResult  dwgOutFields(OdDbDwgFiler* filer, OdDbDatabase* pDb, const OdDbPointRef* pPointRef);
  static OdResult  dxfInFields(OdDbDxfFiler* filer, OdDbDatabase* pDb, OdDbPointRef*& pPointRef);
  static OdResult  dxfOutFields(OdDbDxfFiler* filer, OdDbDatabase* pDb, const OdDbPointRef* pPointRef);
  static OdDbEntity* subentPtr(const OdDbFullSubentPath& objPath, bool& isCloned, bool& reverseArc, bool& isStandAloneArc);
  static OdGeMatrix3d wcsToDcsMatrix(const OdDbViewport* pVPort);

};

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbOsnapPointRef : public OdDbPointRef
{
public:
  OdDbOsnapPointRef();
  virtual ~OdDbOsnapPointRef();

  OdDbOsnapPointRef(const OdGePoint3d& refPt);

  OdDbOsnapPointRef(OdDbPointRef::OsnapType osnapType, 
                    const OdDbFullSubentPath *objPath, 
                    const OdDbFullSubentPath *intObjPath = NULL,
                    const OdGePoint3d *refPt = NULL,
                    OdDbPointRef* lastPtRef = NULL);

  OdDbOsnapPointRef(const OdDbOsnapPointRef& src);

  virtual OdDbPointRef& operator= (const OdDbPointRef& src);

  OdDbOsnapPointRef& operator= (const OdDbOsnapPointRef& src);

  ODRX_DECLARE_MEMBERS(OdDbOsnapPointRef);

  /** Description:
    Returns the object snap mode for this OsnapPointRef object.
    Remarks:
    osnapMode() returns one of the following:
    
    @table
    Name                      Value   Description 
    OdDb::kOsModeEnd          1       Endpoint
    OdDb::kOsModeMid          2       Midpoint
    OdDb::kOsModeCen          3       Center
    OdDb::kOsModeNode         4       Node
    OdDb::kOsModeQuad         5       Quadrant
    OdDb::kOsModeIntersec     6       Intersection
    OdDb::kOsModeIns          7       Insertion point
    OdDb::kOsModePerp         8       Perpendicular
    OdDb::kOsModeTan          9       Tangent
    OdDb::kOsModeNear         10      Nearest
    OdDb::kOsModeApint        11      Apparent intersection
    OdDb::kOsModePar          12      Parallel
    OdDb::kOsModeStart        13      Unknown 
 
  */
  OdDbPointRef::OsnapType osnapType() const;
  /** Description:
    Sets the object snap mode for this OsnapPointRef object.
 
    Remarks:
    osnapMode must be one of the following:
    
    @table
    Name                      Value   Description 
    OdDb::kOsModeEnd          1       Endpoint
    OdDb::kOsModeMid          2       Midpoint
    OdDb::kOsModeCen          3       Center
    OdDb::kOsModeNode         4       Node
    OdDb::kOsModeQuad         5       Quadrant
    OdDb::kOsModeIntersec     6       Intersection
    OdDb::kOsModeIns          7       Insertion point
    OdDb::kOsModePerp         8       Perpendicular
    OdDb::kOsModeTan          9       Tangent
    OdDb::kOsModeNear         10      Nearest
    OdDb::kOsModeApint        11      Apparent intersection
    OdDb::kOsModePar          12      Parallel
    OdDb::kOsModeStart        13      Unknown 
  */
  OdResult setOsnapType(OdDbPointRef::OsnapType osnapMode);

  /** Description:
    Returns a reference to the OdDbXrefFullSubentPath of the main entity for the OsnapPointRef object. 
  */
  OdDbXrefFullSubentPath& mainEntity();
  /** Description:
    Returns a reference to the OdDbXrefFullSubentPath of the intersecting entity for the OsnapPointRef object. 
  */
  OdDbXrefFullSubentPath& intersectEntity();

  OdResult getIdPath(OdDbFullSubentPath& idPath) const;
  OdResult setIdPath(const OdDbFullSubentPath& idPath);

  OdResult getIntIdPath(OdDbFullSubentPath& intIdPath) const;
  OdResult setIntIdPath(const OdDbFullSubentPath& intIdPath);

  /** Description:
    Returns the near Osnap value for this OsnapPointRef object.
  */
  double nearPointParam() const;

  /** Description:
    Returns the near Osnap value for this OsnapPointRef object.
    Arguments:
    nearOsnap (I) Near Osnap value.
  */
  OdResult setNearPointParam(double nearOsnap);

  /** Description:
    Returns a reference to the Osnap point for this OsnapPointRef object.
  */
  OdGePoint3d point() const;
  OdResult setPoint(const OdGePoint3d& pt);

  /** Description:
    Returns the last OsnapPointRef for this OsnapPointRef object.
  */
  const OdDbOsnapPointRef* lastPointRef() const;
  OdDbOsnapPointRef* lastPointRef();

  /** Description:
    Sets the last OsnapPointRef for this OsnapPointRef object.
    Arguments:
    pOsnapPointRef (I) Pointer to the last OsnapPointRef object.
  */
  void setLastPointRef(OdDbOsnapPointRefPtr pOsnapPointRef);

  virtual bool isGeomErased() const;
  virtual bool isXrefObj(OdDbObjectIdArray& ids1, OdDbObjectIdArray& ids2, bool isMainObj = true) const;
  virtual OdResult updateXrefSubentPath();
  virtual OdResult updateSubentPath(OdDbIdMapping& idMap);
  virtual OdResult evalPoint(OdGePoint3d &pt);
  virtual OdResult getEntities(OdDbFullSubentPathArray& ents, bool getLastPtRef = true) const;
  
  virtual OdResult copyFrom(const OdRxObject* pSrc);
  
  virtual void updateDueToMirror(bool inMirror = false);

  OdResult getXrefHandles(OdHandleArray& xrefHandles) const;
  OdResult setXrefHandles(const OdHandleArray& xrefHandles);
  OdResult getXrefIntHandles(OdHandleArray& xrefHandles) const;
  OdResult setXrefIntHandles(const OdHandleArray& xrefHandles);

  /** 
    Description:
    Reads the .dwg file format data of this object from the specified file.
       
    Arguments:   
    pFiler (I) Pointer to the filer from which the data are to be read.
  */
  void dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgInFields(OdDbDwgFiler* filer, OdDbDatabase* pDb)
  {
    dwgInFields(filer);
    return eOk;
  }
  /** 
    Description:
    Writes the .dwg file format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
  */
  void dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dwgOutFields(OdDbDwgFiler* filer, OdDbDatabase* pDb) const
  {
     dwgOutFields(filer);
     return eOk;
  }  
  /** 
    Description:
    Writes the DXF format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
  */
  void dxfOutFields(OdDbDxfFiler* pFiler) const;
  virtual OdResult dxfOutFields(OdDbDxfFiler* filer,OdDbDatabase *pDb) const
  {
     dxfOutFields(filer);
     return eOk;
  }

  OdResult dxfInFields(OdDbDxfFiler* filer);
  virtual OdResult dxfInFields(OdDbDxfFiler* filer,OdDbDatabase *pDb)
  {
     dxfInFields(filer);
     return eOk;
  }

private:
  OdDbPointRef::OsnapType m_OsnapMode;
  OdDbXrefFullSubentPath m_MainEntity;
  OdDbXrefFullSubentPath m_IntersectEntity;
  double                 m_dNearOsnap;
  OdGePoint3d            m_OsnapPoint;
  OdDbOsnapPointRefPtr   m_pLastPointRef;
  bool                   m_bUpdateDueToMirror;
};

/** Description:
    This class represents Associative Dimension objects in an OdDbDatabase instance.

    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDimAssoc : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDimAssoc);

  OdDbDimAssoc();
  
  virtual ~OdDbDimAssoc();
 
  enum { kMaxPointRefs = 4 };
  
  enum PointType 
  {
    kXline1Point          = 0,
    kXline2Point          = 1,
    kOriginPoint          = 0,
    kDefiningPoint        = 1,
    kXline1Start          = 0,
    kXline1End            = 1,
    kXline2Start          = 2,
    kXline2End            = 3,
    kVertexPoint          = 2,
    kChordPoint           = 0,
    kCenterPoint          = 1,
    kFarChordPoint        = 1,
    kOverrideCenterPoint  = 2,
    kAngLineStart         = 2,
    kJogPoint             = 3,
    kAngLineEnd           = 3,
    kLeaderPoint          = 0
  };

  enum RotatedDimType
  {
    kUnknown       = 0,
    kParallel      = 1,
    kPerpendicular = 2
  };

  enum AssocFlags 
  {
    kFirstPointRef     = (1<<0),
    kSecondPointRef    = (1<<1),
    kThirdPointRef     = (1<<2),
    kFourthPointRef    = (1<<3)
  };

  enum
  {
	kPointAmount = 4
  };
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  /** Description:
    Returns the Object ID of the Dimension entity associated with this Associative Dimension object (DXF 330).
  */
  OdDbObjectId dimObjId() const;

  /** Description:
    Sets the Object ID of the Dimension entity associated with this Associative Dimension object (DXF 330).
    Arguments:
    dimId (I) Dimension Object ID.
  */
  OdResult setDimObjId(const OdDbObjectId& dimId);

  /** Description:
    Returns the associativity flag of this Associative Dimension object (DXF 90).
  */
  OdInt32 assocFlag() const;

  /** Description:
    Returns the associativity flag of the specified Osnap Point Reference for this Associative Dimension object.
  */
  bool assocFlag(int pointIndex) const;

  void setAssocFlag(int assocFlag);
  // Sets the index of point reference being used and establishes or clears the association flag. 
  OdResult setAssocFlag(int pointIndex, bool flagValue);

  /** Description:
    Returns the specified Osnap Point Reference for this Associative Dimension object.
    
    Arguments:
    pointIndex (I) Point index. The value should be 0, 1, 2, 3 or from the PointType enum 
    
    Remarks:
    pointIndex must be one of the following:
   
  */
  OdDbOsnapPointRefPtr pointRef(int pointIndex) const;

  /** Description:
    Sets the specified Osnap Point Reference for this Associative Dimension object.
    
    Arguments:
    pointIndex (I) Point index. The value should be 0, 1, 2, 3 or from the PointType enum 
    pOsnapPointRef (I) SmartPointer to the Osnap Point Reference.
  */
  OdResult setPointRef(int pointIndex, OdDbOsnapPointRefPtr pOsnapPointRef);

  /** Description:
  Returns the rotated *dimension* type of this Associative Dimension object (DXF 71).

  Remarks:
  rotatedDimType() returns one of the following:

  @table
  Name              Value
  kParallel         1
  kPerpendicular    2
  */
  RotatedDimType rotatedDimType() const;

  /** Description:
  Sets the rotated *dimension* type of this Associative Dimension object (DXF 71).

  Remarks:
  rotatedDimType must be one of the following:

  @table
  Name              Value
  kParallel         1
  kPerpendicular    2
  */
  OdResult setRotatedDimType(RotatedDimType dimType);

  OdResult addToPointRefReactor();
  OdResult addToDimensionReactor(bool isAdd = true);

  OdResult removePointRef(int ptType);
  OdResult updateDimension(bool update = true, bool skipReactors = false);
  OdResult removeAssociativity(bool force = true);
  
  /** Description:
  Returns the trans-space flag of this Associative Dimension object (DXF 70).
  */
  bool isTransSpatial() const;
  /** Description:
  Sets the trans-space flag of this Associative Dimension object (DXF 70).
  Arguments:
  transSpace (O) Trans-space flag.
  */
  OdResult setTransSpatial(bool value);
  
  OdResult startCmdWatcher();
  
  OdResult startOopsWatcher(bool bAddAll = true);
  
  void removeOopsWatcher(void);
  
  OdResult restoreAssocFromOopsWatcher(void);
  
  bool hasOopsWatcher(void) const;

  virtual OdResult swapReferences (const OdDbIdMapping& idMap);
  OdResult updateFillet(const OdDbObjectIdArray& ids);
  OdResult updateAssociativity(const OdDbObjectIdArray& ids);
  OdResult updateXrefSubentPath();
  void updateDueToMirror(bool wasInMirror);
  
  OdResult post(OdDbObjectId dimId, OdDbObjectId& dimAssocId, bool isActive = true);
  OdResult getDimAssocGeomIds(OdDbObjectIdArray& geomIds) const;
  bool isAllGeomErased() const;

  void copied(const OdDbObject* pObj, const OdDbObject* pNewObj);
  void erased(const OdDbObject *pObj, OdBool erasing = kTrue);
  void openedForModify(const OdDbObject* pObject);
  
  /** Gcad(Modify): OdDbEntity
  */
  virtual void modifiedGraphics(const OdDbEntity* pEntity);
	
protected:
  OdResult setPointRefReactor(int ptType, bool isAdd = true);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimAssoc object pointers.
*/
typedef OdSmartPtr<OdDbDimAssoc> OdDbDimAssocPtr;

//
// Inlines
//

inline
OdHandleArray& OdDbXrefFullSubentPath::xrefObjHandles()
{ 
  return m_XrefObjHandles; 
}

inline
const OdHandleArray& OdDbXrefFullSubentPath::xrefObjHandles() const
{ 
  return m_XrefObjHandles; 
}

inline
OdDbPointRef::OsnapType OdDbOsnapPointRef::osnapType() const
{
  return m_OsnapMode;
}

inline
OdResult OdDbOsnapPointRef::setOsnapType(OdDbPointRef::OsnapType osnapMode)
{
  m_OsnapMode = osnapMode;

  return eOk;
}

inline
OdDbXrefFullSubentPath& OdDbOsnapPointRef::mainEntity()
{
  return m_MainEntity;
}

inline
OdDbXrefFullSubentPath& OdDbOsnapPointRef::intersectEntity()
{
  return m_IntersectEntity;
}

inline
double OdDbOsnapPointRef::nearPointParam() const
{
  return m_dNearOsnap;
}

inline
OdResult OdDbOsnapPointRef::setNearPointParam(double nearOsnap)
{
  m_dNearOsnap = nearOsnap;
  return eOk;
}

inline
OdGePoint3d OdDbOsnapPointRef::point() const
{
  return m_OsnapPoint;
}
inline
OdResult OdDbOsnapPointRef::setPoint(const OdGePoint3d& pt)
{
  m_OsnapPoint = pt;
  return eOk;
}

inline
const OdDbOsnapPointRef* OdDbOsnapPointRef::lastPointRef() const
{
  return m_pLastPointRef;
}
inline
OdDbOsnapPointRef* OdDbOsnapPointRef::lastPointRef()
{
  return m_pLastPointRef;
}

inline
void OdDbOsnapPointRef::setLastPointRef(OdDbOsnapPointRefPtr pOsnapPointRef)
{
  m_pLastPointRef = pOsnapPointRef;
}

#include "TD_PackPop.h"

#endif // OD_DBDIMASSOC_H

