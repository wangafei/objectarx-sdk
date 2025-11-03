
#pragma once
#include "zAcDbCore2dDefs.h"
#include "zacadstrc.h"
#include "zAcString.h"
#include "zacarray.h"
#include "zrxobject.h"

class ZcRxVariableReactor;
class ZcRxImpVariable;
class ZcRxImpVariablesDirectory;
class ZcRxImpVariablesDictionary;
class ZcRxImpVariableChangingEventArgs;
struct resbuf;

class ZCBASE_PORT ZcRxVariable
{
public:

    enum StorageType
    {

        kStoragePerSession = 0,

        kStoragePerUser = 1,

        kStoragePerProfile = 2,

        kStoragePerDatabase = 3,

        kStoragePerViewport = 4
    };

    enum SecondaryType
    {

        kSecondaryTypeNone = 0,

        kSecondaryTypeBoolean = 1,

        kSecondaryTypeSymbolName = 2,

        kSecondaryTypeArea = 3,

        kSecondaryTypeDistance = 4,

        kSecondaryTypeAngle = 5,

        kSecondaryTypeUnitlessReal = 6,

        kSecondaryTypeLast = 6,
    };

    enum TypeFlags
    {

        kTypeFlagsNone = 0,

        kTypeFlagSpacesAllowed = 1,

        kTypeFlagDotMeansEmpty = 2,

        kTypeFlagNoUndo = 4,

        kTypeFlagsChatty = 8,

        kTypeDeprecated = 16,
    };

    struct Range
    {
        Range():lowerBound(0), upperBound(0) {}

        Range(int lb, int ub):lowerBound(lb), upperBound(ub) {}

        int lowerBound;

        int upperBound;
    };

    const ZTCHAR* name() const;

    short primaryType() const;

    ZcRxVariable::SecondaryType secondaryType() const;

    ZcRxVariable::StorageType storageType() const;

    short typeFlags() const;

    const Range* range() const;

    Zcad::ErrorStatus setValue(const resbuf& value, void* ownerId = NULL, ZcString* failReason=NULL, bool disableUndoRecording = false);

    Zcad::ErrorStatus getValue(resbuf& value) const;

    bool isReadOnly(ZcString* reason=NULL) const;

    Zcad::ErrorStatus setIsReadOnly(bool value, void* ownerId, const ZcString* reason=NULL);

    void addReactor(ZcRxVariableReactor* reactor);

    bool isLocked() const;

    void removeReactor(ZcRxVariableReactor* reactor);

    Zcad::ErrorStatus reset();

    ~ZcRxVariable();
 private:
    friend class ZcRxImpVariable;
    ZcRxVariable(ZcRxImpVariable*);
    ZcRxImpVariable* m_pImp;
};

class ZCBASE_PORT ZcRxVariablesDictionary
{
public:
    ~ZcRxVariablesDictionary();

    void addReactor(ZcRxVariableReactor* reactor);

    void removeReactor(ZcRxVariableReactor* reactor);

    const ZcArray<ZcString>& getAllNames() const;

    ZcRxVariable* getVariable(const ZTCHAR* name) const;

    static ZcRxVariablesDictionary* get();

    Zcad::ErrorStatus reset(ZcRxVariable::StorageType filter);

    static bool getBool(const ZTCHAR* name, bool def);

    static bool getBool(const ZcRxVariable* pVar, bool def);

    static Zcad::ErrorStatus setBool(const ZTCHAR* name, bool val);

    static Zcad::ErrorStatus setBool(ZcRxVariable*, bool val);

    static short getInt16(const ZTCHAR* name, short def);

    static short getInt16(const ZcRxVariable* pVar, short def);

    static Zcad::ErrorStatus setInt16(const ZTCHAR* name, short val);

    static Zcad::ErrorStatus setInt16(ZcRxVariable* pVar, short val);

    static double getDouble(const ZTCHAR* name, double def);

    static double getDouble(const ZcRxVariable* pVar, double def);

    static Zcad::ErrorStatus setDouble(const ZTCHAR* name, double val);

    static Zcad::ErrorStatus setDouble(ZcRxVariable* pVar, double val);

    static ZcString getString(const ZTCHAR* name);

    static ZcString getString(const ZcRxVariable* pVar);

    static Zcad::ErrorStatus setString(const ZTCHAR* name, const ZTCHAR* val);

    static Zcad::ErrorStatus setString(ZcRxVariable* pVar, const ZTCHAR* val);

private:
    friend class ZcRxImpVariablesDictionary;
    ZcRxVariablesDictionary(ZcRxImpVariablesDictionary*);
    ZcRxImpVariablesDictionary* m_pImp;
};

class ZCBASE_PORT ZcRxVariableChangedEventArgs
{
public:

    const resbuf& oldValue() const;

    const resbuf& newValue() const;

    friend class ZcRxImpVariableChangingEventArgs;
    ZcRxVariableChangedEventArgs(ZcRxImpVariableChangingEventArgs*);
protected:
    ZcRxImpVariableChangingEventArgs* m_pImp;
};

class ZCBASE_PORT ZcRxVariableChangingEventArgs : public ZcRxVariableChangedEventArgs
{
public:

    Zcad::ErrorStatus setNewValue(const resbuf& value, void* ownerId = NULL);

    void veto(const ZTCHAR* failReason);

    bool isResetting() const;
    ZcRxVariableChangingEventArgs(ZcRxImpVariableChangingEventArgs*);
};

class ZSOFT_NO_VTABLE ZcRxVariableReactor : public ZcRxObject
{
public:

    virtual void changing(const ZcRxVariable* sender, ZcRxVariableChangingEventArgs& args)
    {
        (sender); (args);
    }

    virtual void changed(const ZcRxVariable* sender, const ZcRxVariableChangedEventArgs& args)
    {
        (sender); (args);
    }
};

