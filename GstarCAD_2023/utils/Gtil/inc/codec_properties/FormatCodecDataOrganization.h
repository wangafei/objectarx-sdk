/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#include "FormatCodecExclusivePropertySetInterface.h"
#endif

#ifndef FORMATCODECDATAORGANIZATION_H
#define FORMATCODECDATAORGANIZATION_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecDataOrganization : public FormatCodecPropertyInterface
  {
  public:
    enum Organization
    {
      kMonolithic,
      kTiled,
      kStripped
    };
    enum TileGeometry
    {
      kSquare,
      kRectangle
    };

  public:
    virtual ~FormatCodecDataOrganization();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual Organization getOrganization() const;
    virtual bool setOrganization(Organization organization);

    virtual bool getTileDimensions(int& nWidth, int& nHeight);
    virtual bool setTileDimensions(int nWidth, int nHeight);

    virtual bool getRowsPerStrip(int& nRowsPerStrip);
    virtual bool setRowsPerStrip(int nRowsPerStrip);

  protected:
    FormatCodecDataOrganization(Organization org);

    void setDefaultTileDimensions(int nWidth, int nHeight);
    void setDefaultRowsPerStrip(int nRowsPerStrip);

    int mnTileWidth;
    int mnDefaultTileWidth;
    int mnTileHeight;
    int mnDefaultTileHeight;
    int mnRowsPerStrip;
    int mnDefaultRowsPerStrip;

    Organization mOrgDefault;
    Organization mOrganization;
  };

}

#endif
