/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "rxvar.h"
#include "gdscodes.h"
#include "eoktest.h"

GCBASE_PORT Gcad::ErrorStatus gcutUpdString(const GCHAR* pString, GCHAR*& newString);

class GcRxVariableCache : public GcRxVariableReactor
{
  void changed(const GcRxVariable* sender, const GcRxVariableChangedEventArgs& args) override
  {
    const auto& rb = args.newValue();
    memcpy_s(&m_cache, sizeof(m_cache), &rb, sizeof(rb));
    if (rb.restype == RTSTR)
    {
      Gcad::ErrorStatus es = gcutUpdString(rb.resval.rstring, m_cache.resval.rstring);
      ASSERT(Gcad::eOk == es);
    }
  }
  bool reload(const GcRxVariable* source)
  {
    return eOkVerify(source->getValue(m_cache));
  }
  resbuf m_cache;
  GcString m_name;

public:
  GcRxVariableCache(const GCHAR* name)
    :m_name(name)
    , m_cache({ 0 })
  {
    m_cache.restype = RTNONE;
    auto var = GcRxVariablesDictionary::get()->getVariable(name);
    if (var == nullptr)
      return;
    var->addReactor(this);
    reload(var);
  }
  ~GcRxVariableCache()
  {
    auto var = GcRxVariablesDictionary::get()->getVariable(m_name.kwszPtr());
    if (var == nullptr)
      return;
    var->removeReactor(this);
  }

  bool     getBool(bool def)
  {
    return !!getInt16(def ? 1 : 0);
  }
  short    getInt16(short def)
  {
    ASSERT(m_cache.restype == RTSHORT || m_cache.restype == RTNONE);
    if (m_cache.restype != RTSHORT)
      return def;
    return m_cache.resval.rint;
  }
  double   getDouble(double def)
  {
    ASSERT(m_cache.restype == RTREAL || m_cache.restype == RTNONE);
    if (m_cache.restype != RTREAL)
      return def;
    return m_cache.resval.rreal;
  }
  GcString getString()
  {
    GcString ret;
    ASSERT(m_cache.restype == RTSTR || m_cache.restype == RTNONE);
    if (m_cache.restype != RTSTR)
      return ret;
    return m_cache.resval.rstring;
  }
  bool     reload()
  {
    auto var = GcRxVariablesDictionary::get()->getVariable(m_name.kwszPtr());
    if (var == nullptr)
      return false;
    return reload(var);
  }
};
