/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbCore2dDefs.h"
#include "gcadstrc.h"
#include "GcString.h"
#include "gcarray.h"
#include "rxobject.h"

class GcRxVariableReactor;
class GcRxImpVariable;
class GcRxImpVariablesDirectory;
class GcRxImpVariablesDictionary;
class GcRxImpVariableChangingEventArgs;
struct resbuf;

class GCCORE_PORT GcRxVariable
{
public:
  enum StorageType
  {
    kStoragePerSession  = 0,
    kStoragePerUser     = 1,
    kStoragePerProfile  = 2,
    kStoragePerDatabase = 3,
    kStoragePerViewport = 4
  };
  enum SecondaryType
  {
    kSecondaryTypeNone         = 0,
    kSecondaryTypeBoolean      = 1,
    kSecondaryTypeSymbolName   = 2,
    kSecondaryTypeArea         = 3,
    kSecondaryTypeDistance     = 4,
    kSecondaryTypeAngle        = 5,
    kSecondaryTypeUnitlessReal = 6,
    kSecondaryTypeLast         = 6,
  };
  enum TypeFlags
  {
    kTypeFlagsNone         = 0,
    kTypeFlagSpacesAllowed = 1,
    kTypeFlagDotMeansEmpty = 2,
    kTypeFlagNoUndo        = 4,
    kTypeFlagsChatty       = 8,
    kTypeDeprecated        = 16,
  };
  struct Range
  {
    Range() :lowerBound(0), upperBound(0) {}
    Range(int lb, int ub) :lowerBound(lb), upperBound(ub) {}
    int lowerBound;
    int upperBound;
  };
  const GCHAR* name() const;
  short primaryType() const;
  GcRxVariable::SecondaryType secondaryType() const;
  GcRxVariable::StorageType   storageType() const;
  short typeFlags() const;
  const Range* range() const;

  Gcad::ErrorStatus setValue(const resbuf& value, void* ownerId = NULL, GcString* failReason = NULL);
  Gcad::ErrorStatus getValue(resbuf& value) const;

  bool                 isReadOnly(GcString* reason = NULL) const;
  Gcad::ErrorStatus setIsReadOnly(bool value, void* ownerId, const GcString* reason = NULL);

  void addReactor(GcRxVariableReactor* reactor);
  bool isLocked() const;
  void removeReactor(GcRxVariableReactor* reactor);
  Gcad::ErrorStatus reset();

  ~GcRxVariable();
private:
  friend class GcRxImpVariable;
  GcRxVariable(GcRxImpVariable*);
  GcRxImpVariable* m_pImp;
};

class GCCORE_PORT GcRxVariablesDictionary
{
public:
  ~GcRxVariablesDictionary();
  void addReactor(GcRxVariableReactor* reactor);
  void removeReactor(GcRxVariableReactor* reactor);
  const GcArray<GcString>& getAllNames() const;
  GcRxVariable* getVariable(const GCHAR* name) const;
  static GcRxVariablesDictionary* get();
  Gcad::ErrorStatus reset(GcRxVariable::StorageType filter);

  static bool getBool(const GCHAR* name, bool def);
  static bool getBool(const GcRxVariable* pVar, bool def);
  static Gcad::ErrorStatus setBool(const GCHAR* name, bool val);
  static Gcad::ErrorStatus setBool(GcRxVariable*, bool val);

  static short getInt16(const GCHAR* name, short def);
  static short getInt16(const GcRxVariable* pVar, short def);
  static Gcad::ErrorStatus setInt16(const GCHAR* name, short val);
  static Gcad::ErrorStatus setInt16(GcRxVariable* pVar, short val);

  static double getDouble(const GCHAR* name, double def);
  static double getDouble(const GcRxVariable* pVar, double def);
  static Gcad::ErrorStatus setDouble(const GCHAR* name, double val);
  static Gcad::ErrorStatus setDouble(GcRxVariable* pVar, double val);

  static GcString getString(const GCHAR* name);
  static GcString getString(const GcRxVariable* pVar);
  static Gcad::ErrorStatus setString(const GCHAR* name, const GCHAR* val);
  static Gcad::ErrorStatus setString(GcRxVariable* pVar, const GCHAR* val);

private:
  friend class GcRxImpVariablesDictionary;
  GcRxVariablesDictionary(GcRxImpVariablesDictionary*);
  GcRxImpVariablesDictionary* m_pImp;
};

class GCCORE_PORT GcRxVariableChangedEventArgs
{
public:
  const resbuf& oldValue() const;
  const resbuf& newValue() const;

  friend class GcRxImpVariableChangingEventArgs;
  GcRxVariableChangedEventArgs(GcRxImpVariableChangingEventArgs*);
protected:
  GcRxImpVariableChangingEventArgs* m_pImp;
};

class GCCORE_PORT GcRxVariableChangingEventArgs : public GcRxVariableChangedEventArgs
{
public:
  Gcad::ErrorStatus setNewValue(const resbuf& value, void* ownerId = NULL);
  void veto(const GCHAR* failReason);
  bool isResetting() const;
  GcRxVariableChangingEventArgs(GcRxImpVariableChangingEventArgs*);
};

class GSOFT_NO_VTABLE GcRxVariableReactor : public GcRxObject
{
public:
  virtual void changing(const GcRxVariable* sender, GcRxVariableChangingEventArgs& args)
  {
    (sender); (args);
  }
  virtual void changed(const GcRxVariable* sender, const GcRxVariableChangedEventArgs& args)
  {
    (sender); (args);
  }
};
