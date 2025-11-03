/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GcDMMEPlotProperties_h
#define GcDMMEPlotProperties_h

#include "gcdmmeplotproperty.h"
#include "gcdmmutils.h"

class GcDMMEPlotProperties
{
public:
  GcDMMEPlotProperties()
    : m_id(NULL)
  {

  }

  GcDMMEPlotProperties(const GcDMMEPlotProperties &src)
    : m_id(NULL)
  {
    *this = src;
  }

  ~GcDMMEPlotProperties()
  {
    m_properties.removeAll();
    m_refs.removeAll();
    if (NULL != m_id)
      delete m_id;
  }

  void AddProperty(const GcDMMEPlotProperty * property)
  {
    if (NULL == property)
      return;
    m_properties.append(*property);
  }

  void AddProperty(wchar_t * name, wchar_t *value)
  {
    GcDMMEPlotProperty newProp(name, value);
    m_properties.append(newProp);
  }

  const GcDMMEPlotPropertyVec& GetProperties() const
  {
    return m_properties;
  }

  const GcDMMEPlotProperty * GetProperty(unsigned long index) const
  {
    if (m_properties.length() <= (int)index)
      return NULL;
    return &m_properties[index];
  }

  void SetId(const wchar_t * id)
  {
    if (NULL != m_id)
      delete m_id;
    if (NULL != id) {
      size_t nSize = ::wcslen(id) + 1;
      m_id = new wchar_t[nSize];
      errno_t err = ::wcscpy_s(m_id, nSize, id);
      assert(err == 0);
    }
    else
      m_id = NULL;
  }

  const wchar_t * GetId() const
  {
    return m_id;
  }

  void SetRefs(const GcDMMStringVec& refs)
  {
    m_refs.removeAll();
    for (int i = 0; i < refs.length(); i++)
      m_refs.append(refs.at(i));
  }

  const GcDMMStringVec * GetRefs() const
  {
    return &m_refs;
  }

  GcDMMEPlotProperties& operator= (const GcDMMEPlotProperties &src)
  {
    if (this == &src)
      return *this;

    m_properties.removeAll();
    for (int i = 0; i < src.m_properties.length(); i++)
      m_properties.append(src.m_properties.at(i));
    SetId(src.m_id);
    SetRefs(src.m_refs);
    return *this;
  }

private:
  GcDMMEPlotPropertyVec m_properties;
  wchar_t * m_id;
  GcDMMStringVec m_refs;
};

#endif 