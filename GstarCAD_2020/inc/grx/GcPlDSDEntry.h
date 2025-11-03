#ifndef _GCPLDSDENTRY_H
#define _GCPLDSDENTRY_H

#include "GcPl.h"
#include "GcPlObject.h"

/////////////////////////////////////////////////////////////////////////////


class GcPlDSDEntry  : public GcPlObject
{
	GCPL_DECLARE_MEMBERS(GcPlDSDEntry);
public:

    enum SheetType {
        kSingleDWF  = 0,
        kMultiDWF = 1,
        kOriginalDevice = 2,
        kSingleDWFx = 3,
        kMultiDWFx = 4,
        kSinglePDF = 5,
        kMultiPDF = 6
    };

    enum SetupType {
        kOriginalPS = 0,
        kNPSSameDWG = 1,
        kNPSOtherDWG = 2,
        k3dDwf = 3,
        kOverridePS = 4,
    };

    GCPL_PORT GcPlDSDEntry();

    GCPL_PORT virtual ~GcPlDSDEntry();

    GCPL_PORT GcPlDSDEntry(const GcPlDSDEntry & src);

    GCPL_PORT GcPlDSDEntry& operator= (const GcPlDSDEntry &src);

    GCPL_PORT const GCHAR *      dwgName() const;
    GCPL_PORT void              setDwgName(const GCHAR * pName);

    GCPL_PORT const GCHAR *      layout() const;
    GCPL_PORT void              setLayout(const GCHAR * pLayoutName);
    
    GCPL_PORT const GCHAR *      title() const;
    GCPL_PORT void              setTitle(const GCHAR * pTitle);
    
    GCPL_PORT const GCHAR *      NPS() const;
    GCPL_PORT void              setNPS(const GCHAR * pNPSName);
    
    GCPL_PORT const GCHAR *      NPSSourceDWG() const;
    GCPL_PORT void              setNPSSourceDWG(const GCHAR * pNPWDWGName);

    GCPL_PORT bool               has3dDwfSetup() const;
    GCPL_PORT void              setHas3dDwfSetup(bool b3dDwfSetup);

    GCPL_PORT GcPlDSDEntry::SetupType setupType() const;
    GCPL_PORT void               setSetupType(GcPlDSDEntry::SetupType eType);
};

#endif // _GCPLDSDENTRY_H
