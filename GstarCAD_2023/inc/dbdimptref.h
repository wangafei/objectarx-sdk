/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DIMREFPT_H
#define GD_DIMREFPT_H

typedef GcArray<GcDbFullSubentPath, GcArrayObjectCopyReallocator<GcDbFullSubentPath> >
GcDbFullSubentPathArray;

typedef GcArray<GcDbHandle, GcArrayObjectCopyReallocator<GcDbHandle> >
GcDbHandleArrayPtRef;

class GCDB_PORT GcDbPointRef : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPointRef);

  enum OsnapType {
    kOsnapNone = 0,
    kOsnapEnd = 1,
    kOsnapMid = 2,
    kOsnapCen = 3,
    kOsnapNode = 4,
    kOsnapQuad = 5,
    kOsnapInt = 6,
    kOsnapIns = 7,
    kOsnapPerp = 8,
    kOsnapTan = 9,
    kOsnapNear = 10,
    kOsnapApint = 11,
    kOsnapStart = 13,
    kOsnapCentroid = 14
  };

  virtual GcDbPointRef& operator=(const GcDbPointRef& src);
  virtual Gcad::ErrorStatus evalPoint(GcGePoint3d& pnt_wcs) = 0;
  virtual Gcad::ErrorStatus getEntities(GcDbFullSubentPathArray& ents, bool getLastPtRef = true) const = 0;
  virtual bool              isGeomErased() const = 0;
  virtual bool              isXrefObj(GcDbObjectIdArray& ids1, GcDbObjectIdArray& ids2, bool isMainObj = true) const = 0;
  virtual Gcad::ErrorStatus updateXrefSubentPath() = 0;
  virtual Gcad::ErrorStatus updateSubentPath(GcDbIdMapping& idMap) = 0;

  virtual Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer, GcDbDatabase* pDb) const = 0;
  virtual Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer, GcDbDatabase* pDb) = 0;
  virtual Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer, GcDbDatabase* pDb) const = 0;
  virtual Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer, GcDbDatabase* pDb) = 0;

  virtual Gcad::ErrorStatus subErase(Gsoft::Boolean erasing)
  {
    GSOFT_UNREFED_PARAM(erasing);
    return Gcad::eOk;
  }
  virtual Gcad::ErrorStatus wblockClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping&,
    Gsoft::Boolean isPrimary = Gsoft::kTrue)
    const {
    GSOFT_UNREFED_PARAM(pOwnerObject);
    GSOFT_UNREFED_PARAM(pClonedObject);
    GSOFT_UNREFED_PARAM(isPrimary);

    return Gcad::eOk;
  }
  virtual Gcad::ErrorStatus deepClone(GcRxObject* pOwnerObject,
    GcDbObject*& pClonedObject,
    GcDbIdMapping&,
    Gsoft::Boolean isPrimary = Gsoft::kTrue)
    const {
    GSOFT_UNREFED_PARAM(pOwnerObject);
    GSOFT_UNREFED_PARAM(pClonedObject);
    GSOFT_UNREFED_PARAM(isPrimary);

    return Gcad::eOk;
  }
  virtual void              updateDueToMirror(bool inMirror = false) = 0;

  static Gcad::ErrorStatus  dwgInFields(GcDbDwgFiler* filer,
    GcDbDatabase* pDb,
    GcDbPointRef*& pPointRef);
  static Gcad::ErrorStatus  dwgOutFields(GcDbDwgFiler* filer,
    GcDbDatabase* pDb,
    const GcDbPointRef* pPointRef);
  static Gcad::ErrorStatus  dxfInFields(GcDbDxfFiler* filer,
    GcDbDatabase* pDb,
    GcDbPointRef*& pPointRef);
  static Gcad::ErrorStatus  dxfOutFields(GcDbDxfFiler* filer,
    GcDbDatabase* pDb,
    const GcDbPointRef* pPointRef);
  static GcDbEntity*        subentPtr(const GcDbFullSubentPath& objPath, bool& isCloned, bool& reverseArc, bool& isStandAloneArc);
  static bool               calcTransform(const GcDbObjectIdArray& ids, GcGeMatrix3d& A_Ecs2Wcs);
  static GcGeMatrix3d       wcsToDcsMatrix(const GcDbViewport* pVPort);
  static GcGeMatrix3d       mswcsToPswcs(const GcDbViewport* pVPort);
};

class GCDB_PORT GcDbOsnapPointRef : public GcDbPointRef
{
public:
  GCRX_DECLARE_MEMBERS(GcDbOsnapPointRef);

  GcDbOsnapPointRef();
  GcDbOsnapPointRef(const GcGePoint3d& refPt);
  GcDbOsnapPointRef(GcDbPointRef::OsnapType osnapType,
    const GcDbFullSubentPath *objPath,
    const GcDbFullSubentPath *intObjPath = NULL,
    const GcGePoint3d *refPt = NULL,
    GcDbPointRef* lastPtRef = NULL);
  GcDbOsnapPointRef(const GcDbOsnapPointRef& src);
  ~GcDbOsnapPointRef();

  GcDbPointRef& operator= (const GcDbPointRef& src) override;
  GcDbOsnapPointRef& operator= (const GcDbOsnapPointRef& src);

  GcDbPointRef::OsnapType osnapType() const;
  Gcad::ErrorStatus  setOsnapType(GcDbPointRef::OsnapType osnType);
  Gcad::ErrorStatus  getIdPath(GcDbFullSubentPath& idPath) const;
  Gcad::ErrorStatus  setIdPath(const GcDbFullSubentPath& idPath);
  Gcad::ErrorStatus  getIntIdPath(GcDbFullSubentPath& intIdPath) const;
  Gcad::ErrorStatus  setIntIdPath(const GcDbFullSubentPath& intIdPath);
  Gcad::ErrorStatus  setLastPointRef(GcDbPointRef *ptRef);
  GcDbPointRef*      lastPointRef() const;
  Gcad::ErrorStatus  setPoint(const GcGePoint3d& pt);
  GcGePoint3d        point() const;
  double             nearPointParam() const;
  Gcad::ErrorStatus  setNearPointParam(double newVal);
  bool       isGeomErased() const override;
  bool       isXrefObj(GcDbObjectIdArray& ids1,
    GcDbObjectIdArray& ids2,
    bool isMainObj = true) const override;
  Gcad::ErrorStatus updateXrefSubentPath() override;
  Gcad::ErrorStatus updateSubentPath(GcDbIdMapping& idMap) override;
  Gcad::ErrorStatus evalPoint(GcGePoint3d &pt) override;
  Gcad::ErrorStatus getEntities(GcDbFullSubentPathArray& ents, bool getLastPtRef = true) const override;
  Gcad::ErrorStatus copyFrom(const GcRxObject* pSrc) override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer, GcDbDatabase* pDb) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer, GcDbDatabase* pDb) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer, GcDbDatabase *pDb) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer, GcDbDatabase *pDb) const override;
  void updateDueToMirror(bool inMirror = false) override;

  Gcad::ErrorStatus  getXrefHandles(GcDbHandleArrayPtRef& xrefHandles) const;
  Gcad::ErrorStatus  setXrefHandles(const GcDbHandleArrayPtRef& xrefHandles);
  Gcad::ErrorStatus  getXrefIntHandles(GcDbHandleArrayPtRef& xrefHandles) const;
  Gcad::ErrorStatus  setXrefIntHandles(const GcDbHandleArrayPtRef& xrefHandles);
  Gcad::ErrorStatus  evalPoint(GcDbPointRef::OsnapType ospType,
    const GcGePoint3d& lastPt,
    GcGePoint3d &pt);

protected:
  GcGePoint3d        nearPoint();
  double             findNearPointParam(const GcGePoint3d& pt) const;
  bool               getEllipseParams(double& sP, double& eP) const;
  bool               isTransSpatial(bool isMainObj = true) const;
  Gcad::ErrorStatus  evalPointGuts(GcDbPointRef::OsnapType ospType,
    const GcGePoint3d& pickPt,
    const GcGePoint3d& lastPt,
    GcGePoint3d &pt);
  Gcad::ErrorStatus  getIntPoints(const GcDbEntity* pEnt,
    const GcDbEntity* pIntEnt,
    GcDb::Intersect intType,
    GcGePoint3dArray& intPts,
    int gsMarker1 = 0,
    int gsMarker2 = 0) const;
  Gcad::ErrorStatus  updateSubentPathGuts(GcDbFullSubentPath& path, GcDbIdMapping&      idMap);

private:
  OsnapType          mOsnapType;
  GcDbFullSubentPath mObjPath;
  GcDbFullSubentPath mIntObjPath;
  double             mNearPointParam;
  GcGePoint3d        mPoint;
  GcDbPointRef*      mpLastPointRef;
  bool               mUpdateDueToMirror;

  GcDbHandleArrayPtRef    mHandleArray;
  GcDbHandleArrayPtRef    mIntHandleArray;
};

#endif 