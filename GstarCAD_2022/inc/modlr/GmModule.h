#ifndef _GmModeler_Module_INCLUDED_
#define _GmModeler_Module_INCLUDED_

#include "GmExport.h"
#include "../OdaCommon.h"
#include "../RxDynamicModule.h"

//class SPAParameters;

/** Description:
    Library: gcmodlr
*/
class MODLR_EXPORT GmModelerModule : public OdRxModule
{
  bool m_bLocalInit;
protected:
  void initApp();
  void uninitApp();

public:
  GmModelerModule();
  ~GmModelerModule();

//  virtual OdResult setSPAParameters(const SPAParameters &pParameters);
//  virtual void getSPAParameters(SPAParameters &pParameters);
};

typedef OdSmartPtr<GmModelerModule> GmModelerModulePtr;

#endif
