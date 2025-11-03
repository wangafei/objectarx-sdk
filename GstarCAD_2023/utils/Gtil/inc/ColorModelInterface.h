/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif

#ifndef COLORMODELINTERFACE_H
#define COLORMODELINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT ColorModelInterface
  {
  public:
    virtual ~ColorModelInterface();

    virtual bool canConvertTo(const ColorModelInterface* colorModel) const = 0;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* colorModel,
                                                       RowProviderInterface* pInput) const = 0;

    virtual bool canConvertFrom(const ColorModelInterface* colorModel) const = 0;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* colorModel,
                                                         RowProviderInterface* pInput) const = 0;
  };
}
#endif
