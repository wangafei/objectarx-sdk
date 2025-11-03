/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef HLR_INC_HLR_H_
#define HLR_INC_HLR_H_

#ifdef GC_HLR_EXPORT_
#if defined(__linux__)
#define EXP_IMP __attribute__((__visibility__("default")))
#else
#define EXP_IMP _declspec(dllexport)
#endif
#else
#if defined(__linux__)
#define EXP_IMP
#else
#define EXP_IMP _declspec(dllimport)
#endif
#endif

#define GsoftHlrApiServiceName _T("GSOFT_HLR_API_SERVICES")
#define AsdkHlrApiServiceName GsoftHlrApiServiceName

enum GsoftHlrControl
{
  kProject = 0x0001,
  kShowAll = 0x0002,
  kEntity = 0x0004,
  kBlock = 0x0008,
  kSubentity = 0x0010,
  kHideTangents = 0x0020,
  kCleanup = 0x0040,
  kIsolines = 0x0080,
  kUnite = 0x0100,
  kReuse = 0x0200,
  kProgress = 0x0400,
  kHandlePoints = 0x0800,
  kProcessAll = 0x1000,
  kHonorInternals = 0x2000,
  kMeshSilhouettes = 0x4000,
  kSingleCacheVp = 0x8000,
  kNoScale = 0x10000
};

//-----------------------------------------------------------------------------
class EXP_IMP GsoftHlrData
{
public:
  enum Visibility
  {
    kVisible,
    kHidden,
    kOccluded,
    kInternallyHidden,
    kUndefined
  };

protected:
  GcDbEntity *mEntity;
  GcDbObjectIdArray mObjectIds;
  GcDbSubentId mSubentId;
  Visibility mVisibility;
  Visibility mHlrVisibility;
  GcDbEntity *mResultEntity;

public:
  GsoftHlrData() : mEntity(nullptr), mVisibility(kUndefined), mHlrVisibility(kUndefined), mResultEntity(NULL) {}
  virtual ~GsoftHlrData()
  {
    if (mResultEntity && mResultEntity->objectId() == GcDbObjectId::kNull)
    {
      delete mResultEntity;
      mResultEntity = nullptr;
    }
  }

  void setEntity(GcDbEntity *pEnt)
  {
    if (pEnt != NULL)
      mEntity = pEnt;
  }

  void setObjectIds(GcDbObjectIdArray id)
  {
    mObjectIds = id;
  }

  void setResultEntity(GcDbEntity *pResultEnt)
  {
    mResultEntity = pResultEnt;
  }

  void setVisibility(Visibility visibility)
  {
    mVisibility = visibility;
  }

  void setHlrVisibility(Visibility visibility)
  {
    mHlrVisibility = visibility;
  }

  void setSubentId(GcDbSubentId subentId)
  {
    mSubentId = subentId;
  }

  GcDbEntity *getEntity()
  {
    return mEntity;
  }

  GcDbObjectIdArray &getObjectIds()
  {
    return mObjectIds;
  }

  GcDbEntity *getResultEntity()
  {
    return mResultEntity;
  }

  Visibility getVisibility()
  {
    return mVisibility;
  }
  Visibility getHlrVisibility()
  {
    return mHlrVisibility;
  }

  GcDbSubentId getSubentId()
  {
    return mSubentId;
  }
};

class GsoftHlrEngine;

class EXP_IMP GsoftHlrCollector
{
protected:
  GcArray<GcDbEntity *> mEntities;
  bool mDeleteInDestructor;
  GcDbObjectIdArray mEntityIds;

public:
  GcArray<GsoftHlrData *> mOutputData;

public:
  GsoftHlrCollector() : mDeleteInDestructor(false) {}
  GsoftHlrCollector(GcDbObjectIdArray &ids);
  GsoftHlrCollector(GcArray<GcDbEntity *> &entities, bool deleteInDestructor = false);
  GsoftHlrCollector(GsoftHlrCollector &collector);

  virtual ~GsoftHlrCollector();

  bool getDeleteState()
  {
    return mDeleteInDestructor;
  }

  void setDeleteState(bool bFlag)
  {
    mDeleteInDestructor = bFlag;
  }

  GcArray<GcDbEntity *> &getInputEntities()
  {
    return mEntities;
  }

  GcDbObjectIdArray &getInputEntityIds()
  {
    return mEntityIds;
  }

  void addEntity(GcDbEntity *pEnt);
  void addEntities(GcArray<GcDbEntity *> &pEnts);
  void addEntity(GcDbObjectId id);
  void addEntities(GcDbObjectIdArray &ids);

  void removeEntity(GcDbEntity *pEnt);
  void removeEntities(GcArray<GcDbEntity *> &pEnts);
  void removeEntity(GcDbObjectId id);
  void removeEntities(GcDbObjectIdArray &ids);

  void clear();

protected:
  virtual int initialize(GcArray<GcDbEntity *> &collection);
  virtual void close(GcArray<GcDbEntity *> &collection);

  friend class GsoftHlrEngine;
};

typedef void (*_AbortCallbackFct)(bool *abort);
typedef void (*_ProgressCallbackFct)(int percent_completed);

class EXP_IMP GsoftHlrEngine
{
protected:
  GcDbViewport *mpViewport;
  int mnControl;
  _AbortCallbackFct mpAbortCallbackFct;
  _ProgressCallbackFct mpAcisConvertionProgressCallbackFct;
  _ProgressCallbackFct mpAhlProgressCallbackFct;
  _ProgressCallbackFct mpAcadConvertionProgressCallbackFct;

public:
  GsoftHlrEngine(int ctrl = kShowAll | kEntity | kBlock | kSubentity | kReuse);
  GsoftHlrEngine(GcDbObjectId id, int ctrl = kShowAll | kEntity | kBlock | kSubentity | kReuse);
  GsoftHlrEngine(GcDbViewport *pViewport, int ctrl = kShowAll | kEntity | kBlock | kSubentity | kReuse);
  GsoftHlrEngine(const GcGePoint3d &viewTarget, const GcGeVector3d &viewDirection, int ctrl = kShowAll | kEntity | kBlock | kSubentity | kReuse);

  virtual ~GsoftHlrEngine();

  Gcad::ErrorStatus run(GsoftHlrCollector &collector);

  void setAbortCallback(_AbortCallbackFct fct);

  void setAcisConversionProgressCallBack(_ProgressCallbackFct fct);
  void setAhlProgressCallBack(_ProgressCallbackFct fct);
  void setAcadConversionProgressCallBack(_ProgressCallbackFct fct);

  static void cleanHlrCache();
  static void cleanHlrCache(GcDbEntity *pEnt, GcDbViewport *pVp = NULL);
  static void cleanHlrCache(GcDbEntity *pEnt, GcGePoint3d viewTarget, GcGeVector3d viewDir);
};

extern "C" EXP_IMP void *createBodyFromTriangles(GcGePoint3dArray &pts, GcGeIntArray &indices);

#endif