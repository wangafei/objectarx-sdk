#pragma once

class GcEdXrefFileLock
{
public:
  GcEdXrefFileLock();
  ~GcEdXrefFileLock();


  Gcad::ErrorStatus lockFile( int& retstatus, 
    const GcDbObjectId& selectedBTRid);

  Gcad::ErrorStatus releaseFile( int& retstatus, 
    bool bSkipSaveback = false,
    bool bReload = true);

  Gcad::ErrorStatus consistencyCheck( int& retstatus, 
    const GcDbObjectId& selectedBTRid,
    GcDbObjectIdArray& outofSyncBTRids);

  Gcad::ErrorStatus consistencyCheck( int& retstatus, 
    const GcDbObjectId& selectedBTRid);

  Gcad::ErrorStatus consistencyChecklocal( int& retstatus, 
    const GcDbObjectId& selectedBTRid);

  Gcad::ErrorStatus xloadctlType( int& retstatus,
    const GcDbObjectId& selectedBTRid);

  int getlockxloadctlType() const;

  const GcDbObjectIdArray& getoutofSyncIdArray() const;

  Gcad::ErrorStatus reloadFile(int& retstatus,
    const GcDbObjectIdArray& BTRids,
    const int xldctltype = -1);

  Gcad::ErrorStatus reloadFile(int& retstatus,
    const int xldctltype = -1);

  void              setInternalTNmgmt(bool bTNmgmt);
  GcDbObjectId      getLockBtrId();
};


