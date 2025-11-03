/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcedinpt.h"  

class GcApDocument;

class GcEdSelectionSetService
{
public:
  virtual ~GcEdSelectionSetService() {}

  virtual Gcad::ErrorStatus ssNameX(
    bool bIsSubSelectionIndex,
    int index,
    resbuf*& result) = 0;

  virtual Gcad::ErrorStatus ssNameSubentityX(
    bool bIsSubSelectionIndex,
    int index,
    int subentityIndex,
    resbuf*& result) = 0;

  virtual Gcad::ErrorStatus ssNameSubentities(
    bool bIsSubSelectionIndex,
    int index,
    GcDbFullSubentPathArray& subEntities) = 0;

  virtual Gcad::ErrorStatus add(
    resbuf *ssnameXList,
    const GcDbFullSubentPath *pPath = NULL,
    const GcDbObjectId* pEntselSubent = NULL) = 0;

  virtual Gcad::ErrorStatus addSubentity(
    resbuf *ssnameXList,
    const GcDbFullSubentPath& subEntity) = 0;

  virtual Gcad::ErrorStatus remove(
    int index) = 0;

  virtual Gcad::ErrorStatus removeSubentity(
    int entityIndex,
    int subEntityIndex) = 0;

  virtual Gcad::ErrorStatus highlight(
    int subSelectionIndex,
    const GcDbFullSubentPath& path) = 0;

  virtual int subSelectionMode() = 0;

  virtual Gcad::ErrorStatus getSubSelectionPoints(
    GcGePoint3dArray& points) = 0;

  virtual Gcad::ErrorStatus add(
    const GcArray<resbuf *>& ssnameXList,
    const GcArray<GcDbFullSubentPath *> *pPath,
    bool bAddsAreUnique) = 0;

  virtual Gcad::ErrorStatus addSubentities(
    resbuf * ssnameXList,
    const GcArray<GcDbFullSubentPath>& subEntities,
    bool bAddsAreUnique) = 0;

  virtual Gcad::ErrorStatus remove(
    const GcArray<int>& indices) = 0;

  virtual Gcad::ErrorStatus removeSubentities(
    int entityIndex,
    const GcArray<int>& subEntityIndices) = 0;
};

typedef GcArray<GcDbIntArray, GcArrayObjectCopyReallocator<GcDbIntArray> >
GcDbArrayIntArray;

class GcEdSSGetFilter : public GcEdInputContextReactor
{
public:
  virtual void
    ssgetAddFilter(
      int ssgetFlags,
      GcEdSelectionSetService &service,
      const GcDbObjectIdArray& selectionSet,
      const GcDbObjectIdArray& subSelectionSet)
  {
    GSOFT_UNREFED_PARAM(ssgetFlags);
    GSOFT_UNREFED_PARAM(service);
    GSOFT_UNREFED_PARAM(selectionSet);
    GSOFT_UNREFED_PARAM(subSelectionSet);
  }

  virtual void
    ssgetRemoveFilter(
      int ssgetFlags,
      GcEdSelectionSetService &service,
      const GcDbObjectIdArray& selectionSet,
      const GcDbObjectIdArray& subSelectionSet,
      GcDbIntArray& removeIndexes,
      GcDbArrayIntArray& removeSubentIndexes)
  {
    GSOFT_UNREFED_PARAM(ssgetFlags);
    GSOFT_UNREFED_PARAM(service);
    GSOFT_UNREFED_PARAM(selectionSet);
    GSOFT_UNREFED_PARAM(subSelectionSet);
    GSOFT_UNREFED_PARAM(removeIndexes);
    GSOFT_UNREFED_PARAM(removeSubentIndexes);
  }

  virtual void
    ssgetAddFailed(
      int ssgetFlags,
      int ssgetMode,
      GcEdSelectionSetService &service,
      const GcDbObjectIdArray& selectionSet,
      resbuf *rbPoints)
  {
    GSOFT_UNREFED_PARAM(ssgetFlags);
    GSOFT_UNREFED_PARAM(ssgetMode);
    GSOFT_UNREFED_PARAM(service);
    GSOFT_UNREFED_PARAM(selectionSet);
    GSOFT_UNREFED_PARAM(rbPoints);
  }

  virtual void
    ssgetRemoveFailed(
      int ssgetFlags,
      int ssgetMode,
      GcEdSelectionSetService &service,
      const GcDbObjectIdArray& selectionSet,
      resbuf *rbPoints,
      GcDbIntArray& removeIndexes,
      GcDbArrayIntArray& removeSubentIndexes)
  {
    GSOFT_UNREFED_PARAM(ssgetFlags);
    GSOFT_UNREFED_PARAM(ssgetMode);
    GSOFT_UNREFED_PARAM(service);
    GSOFT_UNREFED_PARAM(selectionSet);
    GSOFT_UNREFED_PARAM(rbPoints);
    GSOFT_UNREFED_PARAM(removeIndexes);
    GSOFT_UNREFED_PARAM(removeSubentIndexes);
  }

  virtual void
    endSSGet(
      Gcad::PromptStatus returnStatus,
      int ssgetFlags,
      GcEdSelectionSetService &service,
      const GcDbObjectIdArray& selectionSet)
  {
    GSOFT_UNREFED_PARAM(returnStatus);
    GSOFT_UNREFED_PARAM(ssgetFlags);
    GSOFT_UNREFED_PARAM(service);
    GSOFT_UNREFED_PARAM(selectionSet);
  }

  virtual void
    endEntsel(
      Gcad::PromptStatus       returnStatus,
      const GcDbObjectId&      pickedEntity,
      const GcGePoint3d&       pickedPoint,
      GcEdSelectionSetService& service)
  {
    GSOFT_UNREFED_PARAM(returnStatus);
    GSOFT_UNREFED_PARAM(pickedEntity);
    GSOFT_UNREFED_PARAM(pickedPoint);
    GSOFT_UNREFED_PARAM(service);
  }
};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter *pFilter);

Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter *pFilter);

Gcad::ErrorStatus GCCORE_PORT setAllowDuplicateSelection(
  GcApDocument *pDoc, unsigned char flag);

bool      GCCORE_PORT        duplicateSelectionsAllowed(GcApDocument *pDoc);

namespace GcEdSSGet {

  enum GcEdSSGetFlags {
    kNormal = 0,
    kPickPoints = 1,
    kDuplicates = 2,
    kNestedEntities = 4,
    kSubEntities = 8,
    kSinglePick = 16,
    kPickfirstSet = 32,
    kPreviousSet = 64,
    kSubSelection = 128,
    kUndo = 256,
    kFailedPickAuto = 512,
    kCommandPreview = 1024,
    kAllViewports = 2048,
    kForBoxPick = 4096,
    kPreSelectionHilite = 8192
  };

  enum GcEdSSGetModes {
    kUnknown = 0,
    kWin,
    kCross,
    kBox,
    kLast,
    kEntity,
    kAll,
    kFence,
    kCPoly,
    kWPoly,
    kPick,
    kEvery,
    kXten,
    kGroup,
    kPrevious,
    kMultiple,
  };

};

class GcEdSSGetFilter2 : public GcEdSSGetFilter
{
public:
  virtual void
    ssgetRolloverFilter(
      const GcDbFullSubentPath &subEntityPath,
      GcDbFullSubentPath &highlightPath)
  {
    GSOFT_UNREFED_PARAM(subEntityPath);
    GSOFT_UNREFED_PARAM(highlightPath);
  }
};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter2 *pFilter);
Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter2 *pFilter);

class GcEdSSGetFilter3 : public GcEdSSGetFilter
{
public:
  virtual void
    ssgetRolloverFilter(
      const GcDbFullSubentPath &subEntityPath,
      GcDbFullSubentPathArray &highlightPaths)
  {
    GSOFT_UNREFED_PARAM(subEntityPath);
    GSOFT_UNREFED_PARAM(highlightPaths);
  }
};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter3 *pFilter);
Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter3 *pFilter);

class GcEdSSGetFilter4 : public GcEdSSGetFilter
{
public:
  virtual void
    endNEntsel(
      Gcad::PromptStatus       returnStatus,
      const GcDbObjectId&      pickedEntity,
      const GcGePoint3d&       pickedPoint,
      gds_point                xformres[4],
      struct resbuf **         refstkres,
      GcEdSelectionSetService& service)
  {
    GSOFT_UNREFED_PARAM(returnStatus);
    GSOFT_UNREFED_PARAM(pickedEntity);
    GSOFT_UNREFED_PARAM(pickedPoint);
    GSOFT_UNREFED_PARAM(xformres);
    GSOFT_UNREFED_PARAM(refstkres);
    GSOFT_UNREFED_PARAM(service);
  }

  virtual void beginSSGetCustomKeywordCallback(const GCHAR*) {};
  virtual void endSSGetCustomKeywordCallback(const GCHAR*) {};

};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter4 *pFilter);
Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter4 *pFilter);

class GcEdSSGetFilter5 : public GcEdSSGetFilter
{
public:
  virtual void ssgetPreviewFilter(
    const GcDbFullSubentPathArray& subEntityPaths,
    GcDbFullSubentPathArray& highlightPaths)
  {
    GSOFT_UNREFED_PARAM(subEntityPaths);
    GSOFT_UNREFED_PARAM(highlightPaths);
  }
};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter5 *pFilter);
Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter5 *pFilter);

class GcEdSubSelectFilterService
{
public:

  virtual Gcad::ErrorStatus ssNameX(
    bool bIsSubSelectionIndex,
    int index,
    resbuf*& result) = 0;

  virtual Gcad::ErrorStatus add(
    resbuf *ssnameXList,
    const GcDbFullSubentPath& path) = 0;

  virtual Gcad::ErrorStatus remove(
    bool bIsSubSelectionIndex,
    int index) = 0;
};

class GcEdSSGetSubSelectFilter : public GcEdInputContextReactor
{
public:

  virtual Gcad::ErrorStatus
    getSubentPathsAtGsMarker(
      GcDbEntity*                    pEnt,
      bool                           bAdding,
      const GcDbFullSubentPathArray& selectedPaths,
      GcDb::SubentType               type,
      Gsoft::GsMarker                gsMark,
      const GcGePoint3d&             pickPoint,
      const GcGeMatrix3d&            viewXForm,
      int&                           numPaths,
      GcDbFullSubentPath*&           subentPaths,
      int                            numInserts,
      GcDbObjectId*                  entAndInsertStack) = 0;

  virtual Gcad::ErrorStatus
    subSelectClassList(GcArray<GcRxClass*>& classes) = 0;

  virtual void
    ssgetAddFilter(
      int                            ssgetFlags,
      GcEdSubSelectFilterService&    service,
      const GcDbObjectId&            object,
      const GcDbFullSubentPathArray& selectedPaths,
      const GcDbFullSubentPathArray& addedPaths) = 0;

  virtual void
    ssgetRemoveFilter(
      int                            ssgetFlags,
      GcEdSubSelectFilterService&    service,
      const GcDbObjectId&            object,
      const GcDbFullSubentPathArray& selectedPaths,
      const GcDbFullSubentPathArray& removedPaths) = 0;
};

Gcad::ErrorStatus GCCORE_PORT addSSgetFilterInputContextReactor(
  GcApDocument             *pDoc,
  GcEdSSGetSubSelectFilter *pFilter);

Gcad::ErrorStatus GCCORE_PORT removeSSgetFilterInputContextReactor(
  GcApDocument             *pDoc,
  GcEdSSGetSubSelectFilter *pFilter);