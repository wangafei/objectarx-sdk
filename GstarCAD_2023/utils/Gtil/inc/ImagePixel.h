/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef IMAGEPIXEL_H
#define IMAGEPIXEL_H

#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef RGBCOLOR_H
#include "RgbColor.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif
#ifndef DATAMODEL_H
#include "DataModel.h"
#endif

namespace Gtil
{
  struct GTIL_EXPORT ImagePixel
  {
    union
    {
      Data8   data1;
      Data8   data8;
      Data16  data16;
      Data32  data32;
      Data64  data64;
      Data128 data128;
      Data8   bitonal;
      Data8   gray;
      Data8   index;
      Data32  rgba;
      float   gray32f;
    } value;

    DataModelAttributes::PixelType type;

    ImagePixel(DataModelAttributes::PixelType pixTpe = DataModelAttributes::kData1);

    const ImagePixel& setToZero();

    bool operator==(const ImagePixel& rhs) const;
    bool operator!=(const ImagePixel& rhs) const;
  };
}

#endif
