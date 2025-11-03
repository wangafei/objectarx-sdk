
#pragma once
#include "zrxvar.h"
#include "zadscodes.h"


class ZcRxVariableCache : public ZcRxVariableReactor
{
    virtual void changed(const ZcRxVariable* sender, const ZcRxVariableChangedEventArgs& args) override
    {
        const auto& rb = args.newValue();
        memcpy(&m_cache, &rb, sizeof(rb));
        if (rb.restype == RTSTR)
        {
            Zcad::ErrorStatus es = zcutUpdString(rb.resval.rstring, m_cache.resval.rstring);
            ASSERT(Zcad::eOk == es);
        }
    }
    resbuf m_cache;
    ZcString m_name;
public:

    ZcRxVariableCache(const ZTCHAR* name)
        :m_name(name)
        , m_cache({ 0 })
    {
        m_cache.restype = RTNONE;
        auto var = ZcRxVariablesDictionary::get()->getVariable(name);
        
        if (var == nullptr)
            return;
        var->addReactor(this);
        Zcad::ErrorStatus es = var->getValue(m_cache);
        ASSERT(Zcad::eOk == es);
    }

    ~ZcRxVariableCache()
    {
        auto var = ZcRxVariablesDictionary::get()->getVariable(m_name.kwszPtr());
        if (var == nullptr)
            return;
        var->removeReactor(this);
    }

    bool getBool(bool def)
    {
        return !!getInt16(def ? 1 : 0);
    }

    short getInt16(short def)
    {
        ASSERT(m_cache.restype == RTSHORT || m_cache.restype == RTNONE);
        if (m_cache.restype != RTSHORT)
            return def;
        return m_cache.resval.rint;
    }

    double getDouble(double def)
    {
        ASSERT(m_cache.restype == RTREAL || m_cache.restype == RTNONE);
        if (m_cache.restype != RTREAL)
            return def;
        return m_cache.resval.rreal;
    }

    ZcString getString()
    {
        ZcString ret;
        ASSERT(m_cache.restype == RTSTR || m_cache.restype == RTNONE);
        if (m_cache.restype != RTSTR)
            return ret;
        return m_cache.resval.rstring;
    }
};