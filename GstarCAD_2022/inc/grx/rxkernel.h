#pragma once
#include "gcadstd.h"
#include "rxsrvice.h"

#pragma pack (push, 8)

class GcRxClass;
class GcRxDictionary;

class  TOOLKIT_EXPORT GcRxKernel : public GcRxService
{
public:
  GCRX_DECLARE_MEMBERS(GcRxKernel);

  GcRxKernel();
  virtual ~GcRxKernel();

  virtual GcRxDictionary* newGcRxDictionary(Hccad::Boolean sorted = Hccad::kTrue, Hccad::Boolean ignoreCase = Hccad::kFalse) = 0;
  virtual GcRxDictionary* newGcRxDictionary(unsigned long length, Hccad::Boolean delObjects, Hccad::Boolean sorted = Hccad::kTrue,Hccad::Boolean ignoreCase = Hccad::kFalse) = 0;
  virtual GcRxDictionary* newGcRxDictionary(const GcRxClass * filter) = 0;
};

#define gcrxKernel GcRxKernel::cast(GcRxDictionary::cast(gcrxSysRegistry()->at(GCRX_SERVICE_DICTIONARY))->at(GCRX_KERNEL_SERVICES))

#pragma pack (pop)
