#ifndef GcDMMEPlotProperties_h
#define GcDMMEPlotProperties_h

#include "GcDMMEPlotProperty.h"
#include "GcDMMUtils.h"

/////////////////////////////////////////////////////////////////////
// class GcDMMEPlotProperties
/////////////////////////////////////////////////////////////////////

/// <summary>
/// This class is a lighweight proxy for the DWF EPlotProperties class which is
/// used by the DMM (DWF Metadata Manager) API to allow clients to
/// associate entity properties with DWF geometry without linking to
/// the DWF toolkit. This class contains the data but not the behavior
/// of the corresponding DWF toolkit object. 
/// </summary>
///
/// <remarks>
/// Note that all strings are Unicode. XML encoding will be done by the
/// DMM when the proxy object is converted to the corresponding DWF
/// toolkit object.
/// </remarks>
///
class GcDMMEPlotProperties
{
public:

    /// <summary>
    /// Default constructor
    /// </summary>
    ///
    /// <remarks>
    /// Constructs an empty GcDMMEPlotProperties object.
    /// </remarks>
    ///
    GcDMMEPlotProperties()
        : m_id(NULL)
    {

    }

    /// <summary>
    /// Copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object to be copied
    /// </param>
    ///
    GcDMMEPlotProperties(const GcDMMEPlotProperties &src)
        : m_id(NULL)
    { 
        *this = src;
    }

    /// <summary>
    /// Destructor
    /// </summary>
    ///
    ~GcDMMEPlotProperties()
    {
        m_properties.removeAll();
        m_refs.removeAll();
        if (NULL != m_id)
            delete m_id;
    }


    /// <summary>
    /// Adds a new GcDMMEPlotProperty object to the internal vector of 
    /// properties
    /// </summary>
    ///
    /// <param name="property">
    /// the property to be added to this Properties list
    /// </param>
    ///
    void AddProperty(const GcDMMEPlotProperty * property)
    {
        if (NULL == property)
            return;
        m_properties.append(*property);
    }

    /// <summary>
    /// Creates and adds a new GcDMMEPlotProperty object to the internal 
    /// vector of properties.
    /// </summary>
    ///
    /// <param name="name">
    /// the new property's name
    /// </param>
    ///
    /// <param name="value">
    /// the new property's value
    /// </param>
    ///
    void AddProperty(wchar_t * name, wchar_t *value)
    {
        GcDMMEPlotProperty newProp(name, value);
        m_properties.append(newProp);
    }

    /// <summary>
    /// accessor for the internal vector of GcDMMEPlotProperty objects
    /// contained by this object
    /// </summary>
    ///
    /// <returns>
    /// Returns a const reference to the internal Vector of 
    /// GcDMMEPlotProperty objects contained by this object
    /// </returns>
    const GcDMMEPlotPropertyVec& GetProperties() const
    {
        return m_properties;
    }

    /// <summary>
    /// accessor for individual properties in the internal vector of
    /// GcDMMEPlotProperties contained in this object
    /// </summary>
    ///
    /// <param name="index">
    /// the zero based index of the desired property
    /// </param>
    ///
    /// <returns>
    /// Returns a const pointer to the EPlotProperty object at the given 
    /// 0-based index.
    /// </returns>
    ///
    /// <remarks>
    /// warning - May overflow the internal Vector array.  Clients should 
    /// check GetProperties().size() before calling this method.
    /// </remarks>
    /// 
    const GcDMMEPlotProperty * GetProperty(unsigned long index) const
    {
        if (m_properties.length() <= (int)index)
            return NULL;
        return &m_properties[index];
    }


    /// <summary>
    /// mutator for the Id attribute of this object
    /// </summary>
    ///
    /// <param name="id">
    /// the Unicode unique identifier the client assigns to this object.
    /// </param>
    ///
    /// <remarks>
    /// The unique identifier for this EPlotProperties element (can be 
    /// a name, a GUID, etc.). It is preferred for this string to be
    /// prefixed with the client application name to distinguish its
    /// properties from those of other clients
    /// The EPlotProperties element, when used in an ObjectDefinition resource,
    /// can be referenced by other "child" EPlotProperties elements, thereby 
    /// creating an efficient hierarchy of properties.
    /// WARNING - these Ids are processed in a space delimited list. Your
    /// properties will not behave as expected if the Id contains spaces.
    /// </remarks>
    void GcDMMEPlotProperties::SetId(const wchar_t * id)
    {
        if (NULL != m_id)
            delete m_id;
        if (NULL != id) {
            size_t nSize = ::wcslen(id) + 1;
            m_id = new wchar_t[nSize];
            errno_t err =::wcscpy_s(m_id, nSize, id);
            assert(err == 0);
        } else
            m_id = NULL;
    }

    /// <summary>
    /// accessor for the Id attribute.
    /// </summary>
    /// 
    /// <returns>
    /// returns a const pointer to the Unicode string which is the unique
    /// identifier assigned by the client to this object.
    /// </returns>
    ///
    /// <remarks>
    /// Returns the unique identifier for this GcDMMEPlotProperties element.
    /// </remarks> 
    const wchar_t * GetId() const
    {
        return m_id;
    }

    /// <summary>
    /// Sets the vector of the unique identifiers of the EPlotProperties 
    /// objects referenced (inherited) by this object.
    /// </summary>
    ///
    /// <param name="refs">
    /// a const reference to a vector of Unicode string identifications
    /// of additional GcDMMEPlotProperties objects
    /// </param>
    ///
    /// <remarks>
    /// The properties in the referenced EPlotProperties objects should be 
    /// considered part of this EPlotProperties instance as if they were 
    /// contained directly by this instance.
    /// </remarks>
    void GcDMMEPlotProperties::SetRefs(const GcDMMStringVec& refs)
    {
        m_refs.removeAll();
        for (int i = 0; i < refs.length(); i++)
            m_refs.append(refs.at(i));
    }

    /// <summary>
    /// accessor for the vector of Unicode string identifications of 
    /// referenced GcDMMEPlotProperties objects
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the vector of Unicode string identifications of 
    /// referenced GcDMMEPlotProperties objects
    /// </returns>
    const GcDMMStringVec * GcDMMEPlotProperties::GetRefs() const
    {
        return &m_refs;
    }


    /// <summary>
    /// operator= also used by copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object whose values will be copied to this object
    /// </param>
    ///
    /// <returns>
    /// returns this object
    /// </returns>
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
    wchar_t * m_id; /**<  Unique identifier for this object. */
    GcDMMStringVec m_refs; /**< Contains a list of EPlotProperties ID's.*/
};

#endif // GcDMMEPlotProperties_h
