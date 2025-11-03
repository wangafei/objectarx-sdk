#pragma once

#include "gcadstd.h"
#pragma pack (push, 8)
#include "gcdocman.h"

class GcDbDatabase;
class GcDbObjectId;

#ifndef GCADAXEXP
#ifdef GVBADLL
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif
#endif

class GCADAXEXP GcAxDocLock
{
public:

    enum DocLockType
    {
        kNormal         = 0,
        kCurDocSwitch   = 1
    };

    GcAxDocLock();
    ~GcAxDocLock();

    GcAxDocLock(const GcDbObjectId& objectId, DocLockType = kNormal);
    GcAxDocLock(GcDbDatabase * pDatabase, DocLockType = kNormal);
    Gcad::ErrorStatus lockStatus() const;

private:

    void lockDocument(GcDbDatabase* pDatabase, DocLockType lockType = kNormal);
    void initialize();

    Gcad::ErrorStatus   m_lockStatus;
    GcApDocument*       m_pDocToUnlock;
    GcApDocument*       m_pCurDocToRestore;
    bool                m_restoreActivation;
};

#pragma pack (pop)