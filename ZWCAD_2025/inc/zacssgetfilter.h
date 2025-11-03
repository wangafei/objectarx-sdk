

#ifndef _ZCSSGETFILTER_H
#define _ZCSSGETFILTER_H
#include "zacedinpt.h"
#include "zaccoredefs.h"

class ZcApDocument;

class ZcEdSelectionSetService
{
public:
    virtual ~ZcEdSelectionSetService() {}

    virtual Zcad::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
    	int index,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus ssNameSubentityX(
        bool bIsSubSelectionIndex,
        int index,
        int subentityIndex,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus ssNameSubentities(
        bool bIsSubSelectionIndex,
        int index,
        ZcDbFullSubentPathArray& subEntities) = 0;

    virtual Zcad::ErrorStatus add(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath *pPath = NULL,
        const ZcDbObjectId* pEntselSubent = NULL) = 0;

    virtual Zcad::ErrorStatus addSubentity(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath& subEntity) = 0;

    virtual Zcad::ErrorStatus remove(
        int index) = 0;

    virtual Zcad::ErrorStatus removeSubentity(
        int entityIndex,
        int subEntityIndex) = 0;

    virtual Zcad::ErrorStatus highlight(
    	int subSelectionIndex,
        const ZcDbFullSubentPath& path) = 0;

	virtual int subSelectionMode() = 0;

	virtual Zcad::ErrorStatus getSubSelectionPoints(ZcGePoint3dArray& points) = 0;

	virtual Zcad::ErrorStatus add(const ZcArray<resbuf*>& ssnameXList,	const ZcArray<ZcDbFullSubentPath *> *pPath,	bool bAddsAreUnique) = 0;

	virtual Zcad::ErrorStatus addSubentities(resbuf* ssnameXList, const ZcArray<ZcDbFullSubentPath>& subEntities, bool bAddsAreUnique) = 0;

	virtual Zcad::ErrorStatus remove(const ZcArray<int>& indices) = 0;

	virtual Zcad::ErrorStatus removeSubentities(int entityIndex, const ZcArray<int>& subEntityIndices) = 0;

    virtual int subSelectionSubMode() = 0;
};

typedef ZcArray<ZcDbIntArray, ZcArrayObjectCopyReallocator<ZcDbIntArray> >
    ZcDbArrayIntArray;

class ZCAD_PORT ZcEdSSGetFilter: public ZcEdInputContextReactor
{
public:
    virtual ~ZcEdSSGetFilter() {};
    virtual void
    ssgetAddFilter(
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    const ZcDbObjectIdArray& subSelectionSet)
    {
        ZSOFT_UNREFED_PARAM(ssgetFlags);
        ZSOFT_UNREFED_PARAM(service);
        ZSOFT_UNREFED_PARAM(selectionSet);
        ZSOFT_UNREFED_PARAM(subSelectionSet);
    }

    virtual void
    ssgetRemoveFilter(
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    const ZcDbObjectIdArray& subSelectionSet,
        ZcDbIntArray& removeIndexes,
        ZcDbArrayIntArray& removeSubentIndexes)
    {
        ZSOFT_UNREFED_PARAM(ssgetFlags);
        ZSOFT_UNREFED_PARAM(service);
        ZSOFT_UNREFED_PARAM(selectionSet);
        ZSOFT_UNREFED_PARAM(subSelectionSet);
        ZSOFT_UNREFED_PARAM(removeIndexes);
        ZSOFT_UNREFED_PARAM(removeSubentIndexes);}

    virtual void
    ssgetAddFailed(
	    int ssgetFlags,
	    int ssgetMode,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
        resbuf *rbPoints)
    {
        ZSOFT_UNREFED_PARAM(ssgetFlags);
        ZSOFT_UNREFED_PARAM(ssgetMode);
        ZSOFT_UNREFED_PARAM(service);
        ZSOFT_UNREFED_PARAM(selectionSet);
        ZSOFT_UNREFED_PARAM(rbPoints);
    }

    virtual void
    ssgetRemoveFailed(
	    int ssgetFlags,
	    int ssgetMode,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet,
	    resbuf *rbPoints,
        ZcDbIntArray& removeIndexes,
        ZcDbArrayIntArray& removeSubentIndexes)
    {
        ZSOFT_UNREFED_PARAM(ssgetFlags);
        ZSOFT_UNREFED_PARAM(ssgetMode);
        ZSOFT_UNREFED_PARAM(service);
        ZSOFT_UNREFED_PARAM(selectionSet);
        ZSOFT_UNREFED_PARAM(rbPoints);
        ZSOFT_UNREFED_PARAM(removeIndexes);
        ZSOFT_UNREFED_PARAM(removeSubentIndexes);
    }

    virtual void
    endSSGet(
	    Zcad::PromptStatus returnStatus,
	    int ssgetFlags,
	    ZcEdSelectionSetService &service,
	    const ZcDbObjectIdArray& selectionSet)
    {
        ZSOFT_UNREFED_PARAM(returnStatus);
        ZSOFT_UNREFED_PARAM(ssgetFlags);
        ZSOFT_UNREFED_PARAM(service);
        ZSOFT_UNREFED_PARAM(selectionSet);
    }

    virtual void
    endEntsel(
        Zcad::PromptStatus       returnStatus,
        const ZcDbObjectId&      pickedEntity,
        const ZcGePoint3d&       pickedPoint,
        ZcEdSelectionSetService& service)
    {
        ZSOFT_UNREFED_PARAM(returnStatus);
        ZSOFT_UNREFED_PARAM(pickedEntity);
        ZSOFT_UNREFED_PARAM(pickedPoint);
        ZSOFT_UNREFED_PARAM(service);
    }

    virtual void
    endNEntsel(
        Zcad::PromptStatus returnStatus,
        const ZcDbObjectId& pickedEntity,
        const ZcGePoint3d& pickedPoint,
        zds_point xformres[4],
        struct resbuf** refstkres,
        ZcEdSelectionSetService& service)
    {
        ZSOFT_UNREFED_PARAM(returnStatus);
        ZSOFT_UNREFED_PARAM(pickedEntity);
        ZSOFT_UNREFED_PARAM(pickedPoint);
        ZSOFT_UNREFED_PARAM(xformres);
        ZSOFT_UNREFED_PARAM(refstkres);
        ZSOFT_UNREFED_PARAM(service);
    }

    virtual void beginSSGetCustomKeywordCallback(const ZTCHAR*) {}
    virtual void endSSGetCustomKeywordCallback(const ZTCHAR*) {}

    virtual void
    ssgetRolloverFilter(
        const ZcDbFullSubentPath& subEntityPath,
        ZcDbFullSubentPath& highlightPath)
    {
        ZSOFT_UNREFED_PARAM(subEntityPath);
        ZSOFT_UNREFED_PARAM(highlightPath);
    }

    virtual void
    ssgetRolloverFilter(
        const ZcDbFullSubentPath& subEntityPath,
        ZcDbFullSubentPathArray& highlightPaths)
    {
        ZSOFT_UNREFED_PARAM(subEntityPath);
        ZSOFT_UNREFED_PARAM(highlightPaths);
    }

    virtual void ssgetPreviewFilter(
        const ZcDbFullSubentPathArray& subEntityPaths,
        ZcDbFullSubentPathArray& highlightPaths)
    {
        ZSOFT_UNREFED_PARAM(subEntityPaths);
        ZSOFT_UNREFED_PARAM(highlightPaths);
    }

    enum MethodGroups {
        kAddRemove = 1,
        kBeginEnd = 2,
        kRollover = 4,
        kMisc = 8,
        kAll = 15
    };
};

typedef ZcEdSSGetFilter ZcEdSSGetFilter2;
typedef ZcEdSSGetFilter ZcEdSSGetFilter3;
typedef ZcEdSSGetFilter ZcEdSSGetFilter4;

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter *pFilter,
                        int nMethodsOverridden = ZcEdSSGetFilter::MethodGroups::kAll);

Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
                        ZcApDocument *pDoc, ZcEdSSGetFilter *pFilter);

Zcad::ErrorStatus setAllowDuplicateSelection(
                        ZcApDocument *pDoc, bool flag);

bool duplicateSelectionsAllowed(ZcApDocument *pDoc);

namespace ZcEdSSGet {

enum ZcEdSSGetFlags {
    kNormal         =  0,
    kPickPoints     =  1,
    kDuplicates     =  2,
    kNestedEntities =  4,
    kSubEntities    =  8,
    kSinglePick     = 16,
    kPickfirstSet   = 32,
    kPreviousSet    =  64,
    kSubSelection   = 128,
	kUndo           = 256,
	kFailedPickAuto = 512,
	kCommandPreview = 1024,
	kAllViewports   = 2048,
	kForBoxPick     = 4096,
	kPreSelectionHilite = 8192
};

enum ZcEdSSGetModes {
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

class ZcEdSubSelectFilterService
{
public:

    virtual Zcad::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
        int index,
        resbuf*& result) = 0;

    virtual Zcad::ErrorStatus add(
        resbuf *ssnameXList,
        const ZcDbFullSubentPath& path) = 0;

    virtual Zcad::ErrorStatus remove(
        bool bIsSubSelectionIndex,
        int index) = 0;
};

class ZcEdSSGetSubSelectFilter : public ZcEdInputContextReactor
{
public:
    ZCAD_PORT virtual ~ZcEdSSGetSubSelectFilter() {};

    virtual Zcad::ErrorStatus
        getSubentPathsAtGsMarker(
            ZcDbEntity*                    pEnt,
            bool                           bAdding,
            const ZcDbFullSubentPathArray& selectedPaths,
            ZcDb::SubentType               type,
            ZSoft::GsMarker                gsMark,
            const ZcGePoint3d&             pickPoint,
            const ZcGeMatrix3d&            viewXForm,
            int&                           numPaths,
            ZcDbFullSubentPath*&           subentPaths,
            int                            numInserts,
            ZcDbObjectId*                  entAndInsertStack) = 0;

    virtual Zcad::ErrorStatus
        subSelectClassList(ZcArray<ZcRxClass*>& classes) = 0;

    virtual void
        ssgetAddFilter(
            int                            ssgetFlags,
            ZcEdSubSelectFilterService&    service,
            const ZcDbObjectId&            object,
            const ZcDbFullSubentPathArray& selectedPaths,
            const ZcDbFullSubentPathArray& addedPaths) = 0;

    virtual void
        ssgetRemoveFilter(
            int                            ssgetFlags,
            ZcEdSubSelectFilterService&    service,
            const ZcDbObjectId&            object,
            const ZcDbFullSubentPathArray& selectedPaths,
            const ZcDbFullSubentPathArray& removedPaths) = 0;
};

Zcad::ErrorStatus addSSgetFilterInputContextReactor(
                        ZcApDocument             *pDoc,
                        ZcEdSSGetSubSelectFilter *pFilter);

Zcad::ErrorStatus removeSSgetFilterInputContextReactor(
                        ZcApDocument             *pDoc,
                        ZcEdSSGetSubSelectFilter *pFilter);

#endif  

