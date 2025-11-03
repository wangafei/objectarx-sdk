//
//
//  ssgetfilter.h - Header file for GcEdSelectionSetService and GcEdSSGetFilter
//


#ifndef _SSGETFILTER_H
#define _SSGETFILTER_H

#include "gcadstd.h"
#include "gcedinpt.h"

class GcApDocument;
class GcEdSelectionSetService
{
public:

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

typedef GcArray<GcDbIntArray, OdObjectsAllocator<GcDbIntArray> > 
  GcDbArrayIntArray;

class GcEdSSGetFilter: public GcEdInputContextReactor
{
public:

  virtual void
    ssgetAddFilter(
    int ssgetFlags,
    GcEdSelectionSetService &service,
    const GcDbObjectIdArray& selectionSet,
    const GcDbObjectIdArray& subSelectionSet)
  {  }

  virtual void
    ssgetRemoveFilter(
    int ssgetFlags,
    GcEdSelectionSetService &service,
    const GcDbObjectIdArray& selectionSet,
    const GcDbObjectIdArray& subSelectionSet,
    GcDbIntArray& removeIndexes,
    GcDbArrayIntArray& removeSubentIndexes)
  {  }

  virtual void
    ssgetAddFailed(
    int ssgetFlags,
    int ssgetMode,
    GcEdSelectionSetService &service,
    const GcDbObjectIdArray& selectionSet,
    resbuf *rbPoints)
  {  }

  virtual void
    ssgetRemoveFailed(
    int ssgetFlags,
    int ssgetMode,
    GcEdSelectionSetService &service,
    const GcDbObjectIdArray& selectionSet,
    resbuf *rbPoints,
    GcDbIntArray& removeIndexes,
    GcDbArrayIntArray& removeSubentIndexes)
  {  }

  virtual void
    endSSGet(
    Gcad::PromptStatus returnStatus,
    int ssgetFlags,
    GcEdSelectionSetService &service,
    const GcDbObjectIdArray& selectionSet)
  {  }

  virtual void
    endEntsel(
    Gcad::PromptStatus       returnStatus,
    const GcDbObjectId&      pickedEntity,
    const GcGePoint3d&       pickedPoint,
    GcEdSelectionSetService& service)
  { } 

};


Gcad::ErrorStatus GCED_DLL_DECL addSSgetFilterInputContextReactor(
                        GcApDocument *pDoc, GcEdSSGetFilter *pFilter);

Gcad::ErrorStatus GCED_DLL_DECL removeSSgetFilterInputContextReactor(
                        GcApDocument *pDoc, GcEdSSGetFilter *pFilter);

Gcad::ErrorStatus GCED_DLL_DECL setAllowDuplicateSelection(
                        GcApDocument *pDoc, Hccad::Boolean flag);

bool      GCED_DLL_DECL        duplicateSelectionsAllowed(GcApDocument *pDoc);


namespace GcEdSSGet {

enum GcEdSSGetFlags {
    kNormal         =  0,
    kPickPoints     =  1,
    kDuplicates     =  2,
    kNestedEntities =  4,
    kSubEntities    =  8,
    kSinglePick     = 16,
    kPickfirstSet   = 32,
    kPreviousSet    = 64,
    kSubSelection   = 128,
    kUndo           = 256,
    kFailedPickAuto = 512,
    kCommandPreview = 1024,
    kAllViewports   = 2048,
    kForBoxPick     = 4096
};

enum GcEdSSGetModes {
    kWin = 1,   //  (Window spec)
    kCross,     //  (Crossing spec)
    kBox,       //  (Box spec)
    kLast,      //  (Last)
    kEntity,    //  (Explicit entity name)
    kAll,       //  (Select all)
    kFence,     //  (Fence Selection)
    kCPoly,     //  (Crossing Poly)
    kWPoly,     //  (Window Poly)
    kPick,      //  (Single pick)
    kEvery,     //  (every entity on single pick)
    kXten,      //  (ssget "X")
    kGroup,     //  (selection set from "group" specification)
    kPrevious,  //  (previous selectionset)
    kMultiple,  //  (Multiple keyword)
};

};

#pragma warning(push)
#pragma warning(disable:4265)//disable missing virtual destructor warning
class GcEdSSGetFilter2 : public GcEdSSGetFilter
{
public:

  virtual void
    ssgetRolloverFilter(
    const GcDbFullSubentPath &subEntityPath, 
    GcDbFullSubentPath &highlightPath)
  {  }
};
#pragma warning(pop) // C4265


Gcad::ErrorStatus GCED_DLL_DECL addSSgetFilterInputContextReactor(
                        GcApDocument *pDoc, GcEdSSGetFilter2 *pFilter);

Gcad::ErrorStatus GCED_DLL_DECL removeSSgetFilterInputContextReactor(
                        GcApDocument *pDoc, GcEdSSGetFilter2 *pFilter);


class GcEdSSGetFilter3 : public GcEdSSGetFilter
{
public:

  virtual void
    ssgetRolloverFilter(
    const GcDbFullSubentPath &subEntityPath, 
    GcDbFullSubentPathArray &highlightPaths)
  {  }
};

Gcad::ErrorStatus GCED_DLL_DECL addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter3 *pFilter);
Gcad::ErrorStatus GCED_DLL_DECL removeSSgetFilterInputContextReactor(
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
  { }

  virtual void beginSSGetCustomKeywordCallback(const GCHAR* pKeyword) {};
  virtual void endSSGetCustomKeywordCallback(const GCHAR* pKeyword) {};

};

Gcad::ErrorStatus GCED_DLL_DECL addSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter4 *pFilter);
Gcad::ErrorStatus GCED_DLL_DECL removeSSgetFilterInputContextReactor(
  GcApDocument *pDoc, GcEdSSGetFilter4 *pFilter);

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
    Hccad::GsMarker                gsMark, 
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

Gcad::ErrorStatus GCED_DLL_DECL addSSgetFilterInputContextReactor(
  GcApDocument             *pDoc, 
  GcEdSSGetSubSelectFilter *pFilter);

Gcad::ErrorStatus GCED_DLL_DECL removeSSgetFilterInputContextReactor(
  GcApDocument             *pDoc, 
  GcEdSSGetSubSelectFilter *pFilter);

#endif  // _SSGETFILTER_H

