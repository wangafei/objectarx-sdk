#pragma once
#include <vcclr.h>
#include <gcroot.h>

#if !defined Gscad
#define Gscad GrxCAD
#endif

namespace GrxCAD
{
  namespace Runtime
  {
    ref class DisposableWrapper;
  }
}

#ifdef  _GMDB_BUILD
#define GMDB_PORT __declspec(dllexport)
#else
#define GMDB_PORT __declspec(dllimport)
#endif

class GMDB_PORT OdMgObjectFactoryBase : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdMgObjectFactoryBase);

  virtual gcroot<Gscad::Runtime::DisposableWrapper^> createRCW(OdRxObject* unmanagedPointer, bool autoDelete) = 0;

  virtual bool isManaged()
  {
    return false;
  }
  virtual ~OdMgObjectFactoryBase(){}
};

template <typename RCW, typename ImpObj>
class OdMgObjectFactory : public OdStaticRxObject<OdMgObjectFactoryBase>
{
public:
  gcroot<Gscad::Runtime::DisposableWrapper^> createRCW(OdRxObject* unmanagedPointer, bool autoDelete)
  {
    return gcnew RCW(System::IntPtr(static_cast<ImpObj*>(unmanagedPointer)),autoDelete);
  }
  OdMgObjectFactory()
  {
    ImpObj::desc()->addX(OdMgObjectFactoryBase::desc(),this);
  }
  ~OdMgObjectFactory()
  {
    ImpObj::desc()->delX(OdMgObjectFactoryBase::desc());
  }
};