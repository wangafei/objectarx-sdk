/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCHAPI_H
#define GCHAPI_H 1

#include "GdGChar.h"
#include "GcDbCore2dDefs.h"

#pragma pack (push, 8)


class GCBASE_PORT GcDbHyperlink
{
public:
  GcDbHyperlink() {};
  virtual ~GcDbHyperlink() {};

  enum HLinkFlags {
    kUndefined = 0,
    kConvertDwgToDwf = 0x1
  };

  virtual const GCHAR * name() const = 0;
  virtual void setName(const GCHAR * cName) = 0;

  virtual const GCHAR * description() const = 0;
  virtual void setDescription(const GCHAR * cDescription) = 0;

  virtual const GCHAR * subLocation() const = 0;
  virtual void setSubLocation(const GCHAR * cSubLocation) = 0;

  virtual const GCHAR * getDisplayString() const = 0;
  virtual bool isOutermostContainer() const = 0;
  virtual const int getNestedLevel() const = 0;

  virtual const Gsoft::Int32 flags() const;
  virtual void setFlags(const Gsoft::Int32 lFlags);
};

inline const Gsoft::Int32 GcDbHyperlink::flags() const
{
  return  GcDbHyperlink::kUndefined;
}

inline void GcDbHyperlink::setFlags(const Gsoft::Int32 lFlags)
{
  GSOFT_UNREFED_PARAM(lFlags);
}

class GcDbHyperlinkCollection
{
public:
  GcDbHyperlinkCollection() {};
  virtual ~GcDbHyperlinkCollection() {};

  virtual void addHead(const GCHAR * sName, const GCHAR * sDescription,
    const GCHAR * sSubLocation = NULL) = 0;
  virtual void addTail(const GCHAR * sName, const GCHAR * sDescription,
    const GCHAR * sSubLocation = NULL) = 0;
  virtual void addAt(const int nIndex, const GCHAR * sName,
    const GCHAR * sDescription,
    const GCHAR * sSubLocation = NULL) = 0;
  GCBASE_PORT void addAt(int index, const GcDbHyperlink* pHLink);

  virtual void removeHead() = 0;
  virtual void removeTail() = 0;
  virtual void removeAt(const int nIndex) = 0;

  virtual int count() const = 0;

  virtual GcDbHyperlink * item(const int nIndex) const = 0;
};

class GCBASE_PORT GcDbEntityHyperlinkPE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbEntityHyperlinkPE);

  virtual Gcad::ErrorStatus getHyperlinkCollection(GcDbObject * pObj,
    GcDbHyperlinkCollection *& pcHCL,
    bool bOneOnly = false,
    bool bIgnoreBlockDefinition = true) = 0;
  virtual Gcad::ErrorStatus getHyperlinkCollection(const GcArray<GcDbObjectId> *& idContainers,
    GcDbHyperlinkCollection *& pcHCL,
    bool bOneOnly = false,
    bool bIgnoreBlockDefinition = true) = 0;

  virtual Gcad::ErrorStatus setHyperlinkCollection(GcDbObject * pObj,
    GcDbHyperlinkCollection * pcHCL) = 0;

  virtual Gcad::ErrorStatus getHyperlinkCount(GcDbObject * pObj,
    unsigned int & nCount,
    bool bIgnoreBlockDefinition = true) = 0;
  virtual Gcad::ErrorStatus getHyperlinkCount(const GcArray<GcDbObjectId> *& idContainers,
    unsigned int & nCount,
    bool bIgnoreBlockDefinition = true) = 0;

  virtual Gcad::ErrorStatus hasHyperlink(GcDbObject * pObj,
    bool & bHasHyperlink,
    bool bIgnoreBlockDefinition = true) = 0;
  virtual Gcad::ErrorStatus hasHyperlink(const GcArray<GcDbObjectId> *& idContainers,
    bool & bHasHyperlink,
    bool bIgnoreBlockDefinition = true) = 0;
};

#define HAPI_SERVICE  GCRX_T("GcadHyperlinks")

#pragma pack (pop)
#endif 