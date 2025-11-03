/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GXLOCK_H
#define _GXLOCK_H

#include "gcadstrc.h"
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)

#ifndef AXAUTOEXP
#ifdef AXAUTO_DLL
#define AXAUTOEXP __declspec(dllexport)
#else
#define AXAUTOEXP __declspec(dllimport)
#endif
#endif

class GcDbDatabase;
class GcDbObjectId;

class AXAUTOEXP GcAxDocLock
{
public:
  enum DocLockType
  {
    kNormal       = 0,
    kCurDocSwitch = 1
  };

  GcAxDocLock();
  GcAxDocLock(const GcDbObjectId& objectId, DocLockType = kNormal);
  GcAxDocLock(GcDbDatabase * pDatabase, DocLockType = kNormal);
  ~GcAxDocLock();

  Gcad::ErrorStatus lockStatus() const;

  void* document() const;
private:

  void lockDocument(GcDbDatabase* pDatabase, DocLockType lockType = kNormal);
  void initialize();

  Gcad::ErrorStatus   m_lockStatus;
  void*               m_pDocToUnlock;
  void*               m_pCurDocToRestore;
  bool                m_restoreActivation;
};

#pragma pack (pop)

#endif
