
#pragma once

namespace Pimpl
{
    class ImpBase;
    
    template <typename Base, class ImpPart>
    class ApiPart : public Base
    {
    protected:
        ApiPart(ImpPart* pImp) throw()
        :m_pImp(pImp)
        {
        }
        
		~ApiPart() {};
    private:
        friend class ImpBase;
        ImpPart* m_pImp;
    };
    
    
    template <class ImpPart>
    class ApiPart<void, ImpPart>
    {
    protected:
        ApiPart(ImpPart* pImp) throw()
        :m_pImp(pImp)
        {
        }

		~ApiPart() {};
    private:
        friend class ImpBase;
        ImpPart* m_pImp;
    };
}
