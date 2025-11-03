

#ifndef   _ZXREFLOCK_H
#define   _ZXREFLOCK_H

#include "zrxnames.h"
#include "zdbidar.h"
#pragma pack (push, 8)

class ZcDbDatabase;
class ZcDbIdMapping;
class ZcDwgFileHandle;

class ZCDBCORE2D_PORT ZcEdXrefFileLock
{
public:
     ZcEdXrefFileLock();
    ~ZcEdXrefFileLock();

    Zcad::ErrorStatus lockFile(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus releaseFile(
                        int& retstatus,
                        bool bSkipSaveback = false,
                        bool bReload = true);

    Zcad::ErrorStatus consistencyCheck(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid,
                         ZcDbObjectIdArray& outofSyncBTRids);

    Zcad::ErrorStatus consistencyCheck(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus consistencyChecklocal(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    Zcad::ErrorStatus xloadctlType(
                         int& retstatus,
                         const ZcDbObjectId& selectedBTRid);

    int               getlockxloadctlType() const { return mXldctltype; }

    const ZcDbObjectIdArray& getoutofSyncIdArray() const { return mXBTRidArray; }

    Zcad::ErrorStatus reloadFile(
                         int& retstatus,
                         const ZcDbObjectIdArray& BTRids,
                         const int xldctltype = -1);

    Zcad::ErrorStatus reloadFile(
                         int& retstatus,
                         const int xldctltype = -1);

    void              setInternalTNmgmt(bool bTNmgmt);
    ZcDbObjectId      getLockBtrId() const { return mXBTRid; }

private:
    ZcDwgFileHandle*    mdwgfile;
    ZcDbDatabase*       mpXDB;
    ZcDbDatabase*       mpXDBlockFile;
    int                 mXldctltype;
    ZcDbObjectId        mXBTRid;
    ZcDbObjectIdArray   mXBTRidArray;
    bool                mbIntTNmgmt;
};


class ZCDBCORE2D_PORT ZcDbXrefFileLocker
{
public:

    explicit ZcDbXrefFileLocker(ZcDbDatabase* pXrefDatabase);

    virtual ~ZcDbXrefFileLocker(); 

    void release();

    Zcad::ErrorStatus status() const;

    void setSaveBackToXrefFile(bool yesNo);

    static bool isXrefDatabase(const ZcDbDatabase* pDatabase);

private: 

    void collectAllOpenedObjects(ZcDbObjectIdArray& openedObjectIds);

    bool hasOpenedObjects();

    void closeOpenedObjects (ZcDbObjectIdArray& openedObjectIds, ZcArray<ZcDb::OpenMode>& openModes, ZcArray<int>& openCounts);
    void reopenClosedObjects(const ZcDbObjectIdArray& openedObjectIds, const ZcArray<ZcDb::OpenMode>& openModes, const ZcArray<int>& openCounts);

private: 

    ZcDbDatabase*     mpXrefDatabase;
    ZcEdXrefFileLock  mXrefFileLock;
    Zcad::ErrorStatus mStatus;
    bool              mSaveBackToXrefFile;

    ZcDbXrefFileLocker();
    ZcDbXrefFileLocker(const ZcDbXrefFileLocker&);
    ZcDbXrefFileLocker& operator =(ZcDbXrefFileLocker&);
};


#pragma pack (pop)
#endif  
