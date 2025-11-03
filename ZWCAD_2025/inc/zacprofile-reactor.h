#pragma once
#include "zAdAChar.h"
#include "zaccoredefs.h"

class ZCCORE_PORT ZcApProfileManagerReactor
{
public:
    virtual void currentProfileWillChange(const ZTCHAR *newProfile);
    virtual void currentProfileChanged(const ZTCHAR *newProfile);
    virtual void currentProfileWillBeReset(const ZTCHAR *currentProfile);
    virtual void currentProfileReset(const ZTCHAR *currentProfile);
    virtual void currentProfileWillBeSaved(const ZTCHAR *currentProfile);
    virtual void currentProfileSaved(const ZTCHAR *currentProfile);
    virtual void profileWillReset(const ZTCHAR *profileName);
    virtual void profileReset(const ZTCHAR *profileName);
    virtual void profileWillBeSaved(const ZTCHAR *profileName);
    virtual void profileSaved(const ZTCHAR *profileName);
    virtual ~ZcApProfileManagerReactor() {}
};
