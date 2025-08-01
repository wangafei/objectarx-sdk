//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2017 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
// 
// Name:            DbSectionManager.h
//
// Description:     Header for AcDbSectionManager and 
//                  AcDbSectionManagerIterator classes.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "AdAChar.h"
#include "DbSection.h"


class AcDbSection;
class AcDbSectionManagerIterator;
class AcDbImpSectionManager;


//*************************************************************************
// AcDbSectionManager
//*************************************************************************

class AcDbSectionManager : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSectionManager);

    ACDB_PORT Acad::ErrorStatus getSection  (const ACHAR* pszName, 
                                             AcDbObjectId& id) const;
    ACDB_PORT Acad::ErrorStatus getSection  (const ACHAR* pszName, 
                                             AcDbSection*& pSecPlane, 
                                             AcDb::OpenMode mode) const;
    ACDB_PORT Acad::ErrorStatus getLiveSection(AcDbObjectId& id) const;
    ACDB_PORT Acad::ErrorStatus getLiveSection(AcDbSection*& pSecPlane,
                                             AcDb::OpenMode mode) const;
    ACDB_PORT int   numSections             (void) const;
    ACDB_PORT Acad::ErrorStatus newIterator (AcDbSectionManagerIterator*& pIterator) const;
    ACDB_PORT Acad::ErrorStatus getUniqueSectionName(const ACHAR* pszBaseName, 
                                             ACHAR*& pszUniqueName) const;

    // Base class overrides
    ACDB_PORT virtual Acad::ErrorStatus dwgInFields (AcDbDwgFiler* pFiler);
    ACDB_PORT virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
    ACDB_PORT virtual Acad::ErrorStatus dxfInFields (AcDbDxfFiler* pFiler);
    ACDB_PORT virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;

public:
    // TODO: These should be protected
    ACDB_PORT AcDbSectionManager(void);
    ACDB_PORT ~AcDbSectionManager(void);

protected:
    ACDB_PORT virtual Acad::ErrorStatus subGetClassID  (CLSID* pClsid) const;
};


//*************************************************************************
// AcDbSectionManagerIterator
//*************************************************************************

class AcDbSectionManagerIterator
{
public:
    ACDB_PORT virtual ~AcDbSectionManagerIterator(void);

    ACDB_PORT void  start                   (void);
    ACDB_PORT void  step                    (void);
    ACDB_PORT bool  done                    (void) const;

    ACDB_PORT AcDbObjectId      getSection  (void) const;
    ACDB_PORT Acad::ErrorStatus getSection  (AcDbSection*& pSecPlane, 
                                             AcDb::OpenMode openMode) const;

protected:
    ACDB_PORT AcDbSectionManagerIterator(AcDbSectionManager* pMgr);

protected:
    void            *   mpImpObj;

    friend class AcDbImpSectionManager;
};
