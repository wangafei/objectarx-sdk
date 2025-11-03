/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _rxkernel_h
#define _rxkernel_h 1

#include "gccoredefs.h"
#include "rxsrvice.h"
#pragma pack (push, 8)

class GcRxClass;
class GcRxDictionary;

class GSOFT_NO_VTABLE GCCORE_PORT GcRxKernel : public GcRxService
{
public:
  GCRX_DECLARE_MEMBERS(GcRxKernel);
  GcRxKernel();
  ~GcRxKernel();

  virtual GcRxDictionary* newGcRxDictionary(Gsoft::Boolean sorted = Gsoft::kTrue,
                                            Gsoft::Boolean ignoreCase = Gsoft::kFalse) = 0;
  virtual GcRxDictionary* newGcRxDictionary(Gsoft::UInt32 length,
                                            Gsoft::Boolean delObjects,
                                            Gsoft::Boolean sorted = Gsoft::kTrue,
                                            Gsoft::Boolean ignoreCase = Gsoft::kFalse) = 0;
  virtual GcRxDictionary* newGcRxDictionary(const GcRxClass * filter) = 0;
};

#define gcrxKernel \
    GcRxKernel::cast(GcRxDictionary::cast(\
    gcrxSysRegistry()->at(GCRX_SERVICE_DICTIONARY))->at(GCRX_KERNEL_SERVICES))

#pragma pack (pop)
#endif
