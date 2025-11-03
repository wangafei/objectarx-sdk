/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GdGChar.h"

class GCCORE_PORT GcApProfileManagerReactor
{
public:
  virtual void currentProfileWillChange(const GCHAR *newProfile);
  virtual void currentProfileChanged(const GCHAR *newProfile);
  virtual void currentProfileWillBeReset(const GCHAR *currentProfile);
  virtual void currentProfileReset(const GCHAR *currentProfile);
  virtual void currentProfileWillBeSaved(const GCHAR *currentProfile);
  virtual void currentProfileSaved(const GCHAR *currentProfile);
  virtual void profileWillReset(const GCHAR *profileName);
  virtual void profileReset(const GCHAR *profileName);
  virtual void profileWillBeSaved(const GCHAR *profileName);
  virtual void profileSaved(const GCHAR *profileName);
  virtual ~GcApProfileManagerReactor() {}
};