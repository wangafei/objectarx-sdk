/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GcGiStyleAttributes_H_Defined__
#define __GcGiStyleAttributes_H_Defined__

#include "GcGiLineAttributes.h"
#include "dbid.h"
#include "dbcolor.h"

class GSOFT_NO_VTABLE GcGiStyleAttributes
{
public:

  enum AttributeFlags {
    kNothing = 0x00,
    kColor = 0x01,
    kLine = 0x02,
    kLineType = 0x04,
    kPlotStyle = 0x08,
    kEverything = 0x0F
  };

  GcGiStyleAttributes() { }
  GcGiStyleAttributes(const GcGiStyleAttributes& source);
  virtual ~GcGiStyleAttributes() { }

  GcCmEntityColor& getColorAttribute();
  const GcCmEntityColor& getColorAttribute() const;
  void setColorAttribute(const GcCmEntityColor& color);

  GcDbObjectId linetypeObjectId() const;
  void setLinetypeObjectId(const GcDbObjectId& newId);

  GcDbObjectId plotStyleNameId() const;
  void setPlotStyleName(const GcDbObjectId& newId);

  virtual GcGiLineAttributes* getLineAttribute() = 0;
  virtual const GcGiLineAttributes* getLineAttribute() const = 0;
  virtual void setLineAttribute(const GcGiLineAttributes* pLineAttributes) = 0;

  virtual void EnsureColorVisibility(GcCmEntityColor& color) = 0;

protected:
  GcCmEntityColor m_colorAttribute;
  GcDbObjectId    m_idLinetype;
  GcDbObjectId    m_idPlotstyle;
};

inline
GcGiStyleAttributes::GcGiStyleAttributes(
  const GcGiStyleAttributes& source)
{
  m_colorAttribute = source.getColorAttribute();
  m_idLinetype = source.linetypeObjectId();
  m_idPlotstyle = source.plotStyleNameId();
}

inline
GcCmEntityColor&
GcGiStyleAttributes::getColorAttribute()
{
  return m_colorAttribute;
}

inline
const GcCmEntityColor&
GcGiStyleAttributes::getColorAttribute() const
{
  return m_colorAttribute;
}

inline
void
GcGiStyleAttributes::setColorAttribute(
  const GcCmEntityColor& color)
{
  m_colorAttribute = color;
}

inline
GcDbObjectId
GcGiStyleAttributes::linetypeObjectId() const
{
  return m_idLinetype;
}

inline
void
GcGiStyleAttributes::setLinetypeObjectId(const GcDbObjectId& newId)
{
  m_idLinetype = newId;
}

inline
GcDbObjectId
GcGiStyleAttributes::plotStyleNameId() const
{
  return m_idPlotstyle;
}

inline
void
GcGiStyleAttributes::setPlotStyleName(const GcDbObjectId& newId)
{
  m_idPlotstyle = newId;
}

#endif 