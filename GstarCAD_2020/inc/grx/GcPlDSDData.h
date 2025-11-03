#ifndef _GCPLDSDDATA_H
#define _GCPLDSDDATA_H

#pragma once

#include "GcPl.h"
#include "GcPlObject.h"
#include "GcPlDSDEntry.h"
#include "GcPlPrecisionEntry.h"
#include "GcArray.h"
#include "GcString.h"

typedef GcArray<GcPlDSDEntry, GcArrayObjectCopyReallocator <GcPlDSDEntry> > GcPlDSDEntries;
typedef GcArray<GcPlPrecisionEntry, GcArrayObjectCopyReallocator <GcPlPrecisionEntry> > GcPlPrecisionEntries;

//3d dwf options for publishing  
struct GcPl3dDwfOptions {
    bool  bGroupByXrefHierarchy;
    bool  bPublishWithMaterials;
};
/////////////////////////////////////////////////////////////////////////////
// GcPlDSDData - holds the data for a batch plotting operation

class GcPlDSDData  : public GcPlObject
{
   GCPL_DECLARE_MEMBERS(GcPlDSDData);
        // Construction
public:

    GCPL_PORT GcPlDSDData();

    GCPL_PORT virtual ~GcPlDSDData();

    GCPL_PORT GcPlDSDData(const GcPlDSDData & src);

    GCPL_PORT GcPlDSDData& operator= (const GcPlDSDData &src);

    GCPL_PORT const GCHAR *      projectPath() const;
    GCPL_PORT void              setProjectPath(const GCHAR * pVal);

    GCPL_PORT const GCHAR *      destinationName() const;
    GCPL_PORT void              setDestinationName(const GCHAR * pVal);

    GCPL_PORT void              getDSDEntries(GcPlDSDEntries &val) const;
    GCPL_PORT void              setDSDEntries(const GcPlDSDEntries &val);

    GCPL_PORT void              getPrecisionEntries(GcPlPrecisionEntries &val) const;
    GCPL_PORT void              setPrecisionEntries(const GcPlPrecisionEntries &val);

    GCPL_PORT int               numberOfDSDEntries() const;
    GCPL_PORT GcPlDSDEntry&     DSDEntryAt(int idx);

    GCPL_PORT GcPlDSDEntry::SheetType sheetType() const;
    GCPL_PORT void                    setSheetType(GcPlDSDEntry::SheetType val);

    GCPL_PORT const GCHAR *     password() const;
    GCPL_PORT void              setPassword(const GCHAR * pVal);

    GCPL_PORT void              getUnrecognizedData(
        GcArray<GCHAR*> &sectionArray, 
        GcArray<GCHAR*> &dataArray) const;
    GCPL_PORT void              setUnrecognizedData(
        const GcArray<GCHAR*> &sectionArray, 
        const GcArray<GCHAR*> &dataArray);
    GCPL_PORT void              setUnrecognizedData(
        const GCHAR * pSectionName, 
        const GCHAR * pSectionData);

    GCPL_PORT void              setUnrecognizedData(
        const GcStringArray& sectionArray, 
        const GcStringArray& dataArray);
    GCPL_PORT void              getUnrecognizedData(
        GcStringArray& sectionArray, 
        GcStringArray& dataArray) const;


    GCPL_PORT unsigned int      majorVersion() const;
    GCPL_PORT void              setMajorVersion(unsigned int nmajorVersion);

    GCPL_PORT unsigned int      minorVersion() const;
    GCPL_PORT void              setMinorVersion(unsigned int nminorVersion);

    GCPL_PORT const GCHAR *     sheetSetName() const;
    GCPL_PORT void              setSheetSetName(const GCHAR * pSheetSetName);

    GCPL_PORT unsigned int      noOfCopies() const;
    GCPL_PORT void              setNoOfCopies(unsigned int copies);

    GCPL_PORT void              setIsSheetSet(bool bSheetSet);
    GCPL_PORT bool              isSheetSet() const;

    GCPL_PORT bool              isHomogeneous() const;
    GCPL_PORT void              setIsHomogeneous(bool bHomogeneous);

    GCPL_PORT bool              plotStampOn() const;
    GCPL_PORT void              setPlotStampOn(bool bOn);

    GCPL_PORT bool              viewFile() const;
    GCPL_PORT void              setViewFile(bool bViewFile);

    GCPL_PORT const GCHAR *     selectionSetName() const;
    GCPL_PORT void              setSelectionSetName(const GCHAR * pSelSetName);

    GCPL_PORT const GCHAR *     categoryName() const;
    GCPL_PORT void              setCategoryName(const GCHAR * pCategoryName);

    GCPL_PORT const GCHAR *     logFilePath() const;
    GCPL_PORT void              setLogFilePath(const GCHAR * pLogFilePath);

    GCPL_PORT const GcPl3dDwfOptions&   get3dDwfOptions() const;
    GCPL_PORT void              set3dDwfOptions(const GcPl3dDwfOptions &val);

    GCPL_PORT bool              readDSD(const GCHAR *pName);
    GCPL_PORT bool              writeDSD(const GCHAR *pName);

    // The following methods are for internal use only 
    GCPL_PORT bool              includeLayerInfo() const;
    GCPL_PORT void              setIncludeLayerInfo(bool bOn);

    GCPL_PORT bool              lineMerge() const;
    GCPL_PORT void              setLineMerge(bool bOn);

    GCPL_PORT const GCHAR *     currentPrecision() const;
    GCPL_PORT void              setCurrentPrecision(const GCHAR * pCurrentPrecision);

    GCPL_PORT bool              promptForDwfName() const;
    GCPL_PORT void              setPromptForDwfName(bool bPromptForDwfName);

    GCPL_PORT bool              pwdProtectPublishedDWF() const;
    GCPL_PORT void              setPwdProtectPublishedDWF(
        bool bPwdProtectPublishedDWF);

    GCPL_PORT bool              promptForPassword() const;
    GCPL_PORT void              setPromptForPassword(bool bPromptForPassword);
};

#endif // _GCPLDSDDATA_H

