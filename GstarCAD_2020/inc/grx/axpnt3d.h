#pragma once

#ifndef GCADAXEXP
#ifdef GVBADLL
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif
#endif


class GCADAXEXP GcAxPoint3d : public GcGePoint3d
{
public:

    GcAxPoint3d();
    /*
    safeArrayPt Input SAFEARRAY pointer containing x,y,z coordinates 
    Constructs a 3d point with coordinates from safeArrayPt. The SAFEARRAY is one dimensional and composed of three doubles
    */
    GcAxPoint3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    x Input x coordinate 
    y Input y coordinate 
    z Input z coordinate 
    Constructs 3d point with coordinates x, y, and z.
    */

    GcAxPoint3d(double x, double y, double z);

    /*
    pt Input GcGePoint3d containing x,y,z coordinates 
    Constructs a 3d point with coordinates from pt.
    */
    GcAxPoint3d(const GcGePoint3d& pt);

    /*
    pt Input GcGeVector3d containing x,y,z coordinates 
    Constructs a 3d point with coordinates from pt.
    */
    GcAxPoint3d(const GcGeVector3d& pt);

    /*
    var Input VARIANT pointer containing x,y,z coordinates 
    Constructs a 3d point with coordinates from var. The VARIANT should contain a SAFEARRAY of three doubles.
    */
    GcAxPoint3d(const VARIANT* var) throw(HRESULT);

    /*
    var Input VARIANT reference containing x,y,z coordinates 
    Constructs a 3d point with coordinates from var. The VARIANT should contain a SAFEARRAY of three doubles.
    */
    GcAxPoint3d(const VARIANT& var) throw(HRESULT);

    /*
    var Output VARIANT reference to contain x, y, and z coordinates 
    Populates the VARIANT passed in with the X, Y, and Z coordinates. The data is represented in the VARIANT as a one-dimensional SAFEARRAY of three doubles.
    */
    VARIANT &setVariant(VARIANT& var) const throw(HRESULT);

    /*
    var Output VARIANT pointer to contain x, y, and z coordinates 
    Populates the VARIANT passed in with the X, Y, and Z coordinates. The data is represented in the VARIANT as a one-dimensional SAFEARRAY of three doubles.
    */
    VARIANT *setVariant(VARIANT* var) const throw(HRESULT);

    /*
    pt Input GcGeVector3d containing x, y, and z coordinates 
    Copies the 3d point with coordinates in pt.
    */
    GcAxPoint3d &operator = (const GcGeVector3d& pt);

    /*
    var Input VARIANT pointer containing x, y, and z coordinates 
    Copies the 3d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of three doubles.
    */
    GcAxPoint3d &operator = (const VARIANT* var) throw(HRESULT);

    /*
    var Input VARIANT reference containing x, y, and z coordinates 
    Copies the 3d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of three doubles.
    */
    GcAxPoint3d &operator = (const VARIANT& var) throw(HRESULT);

    /*
    safeArrayPt Input SAFEARRAY pointer containing x, y, and z coordinates 
    Copies the 3d point with coordinates in safeArrayPt. The SAFEARRAY is one dimensional and composed of three doubles.
    */
    GcAxPoint3d &operator = (const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    pt Input GcGePoint3d containing x, y, and z coordinates 
    Copies the 3d point with coordinates from pt.
    */
    GcAxPoint3d &operator = (const GcGePoint3d& pt);

    /*
    Returns a pointer to a one-dimensional SAFEARRAY of three doubles that contains the X, Y, and Z coordinates of the point. The SAFEARRAY pointer returned must be freed using SafeArrayDestroy().
    */
    SAFEARRAY *asSafeArrayPtr() const throw(HRESULT);

    /*
    Returns a VARIANT pointer containing a one-dimensional SAFEARRAY of three doubles that contains the X, Y, and Z coordinates of the point. The contents of the VARIANT returned must be freed using VariantClear() and the pointer deleted.
    */
    VARIANT *asVariantPtr() const throw(HRESULT);

};

class GCADAXEXP GcAxPoint3dArray : public GcGePoint3dArray
{
public:
    /*
    var Output VARIANT reference to contain the x, y, and z coordinates of each point 
    Populates the VARIANT passed in with the X, Y, and Z coordinates of each point. The data is represented in the VARIANT as a one dimensional SAFEARRAY of 3 * X doubles where X is the number of points in the array.
    */
    VARIANT *setVariant(VARIANT* var) const throw(HRESULT);

    /*
    var Output VARIANT reference to contain the x, y, and z coordinates of each point 
    Populates the VARIANT passed in with the X, Y, and Z coordinates of each point. The data is represented in the VARIANT as a one dimensional SAFEARRAY of 3 * X doubles where X is the number of points in the array.
    */
    VARIANT &setVariant(VARIANT& var) const throw(HRESULT);

    /*
    safeArrayPt Input SAFEARRAY pointer containing x, y, and z coordinates 
    This function appends the data in var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint3dArray &append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    var Input VARIANT reference containing x, y, and z coordinates 
    This function appends the data in var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint3dArray &append(const VARIANT& var) throw(HRESULT);

    /*
    var Input VARIANT pointer containing x, y, and z coordinates 
    This function appends the data in var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint3dArray &append(const VARIANT* var) throw(HRESULT);

    /*
    pt Input GcGePoint3d reference value 
    This function appends pt to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint3dArray &append(const GcGePoint3d& pt);

    /*
    Returns a pointer to a one dimensional SAFEARRAY of 3 * X doubles (where X is the number of points in the array) that contains the X, Y, and Z coordinates of each point. The SAFEARRAY returned must be freed using SafeArrayDestroy().
    */
    SAFEARRAY *asSafeArrayPtr() const throw(HRESULT);

};
