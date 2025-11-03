#pragma once

#ifndef GCADAXEXP
#ifdef GVBADLL
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif
#endif


class GCADAXEXP GcAxPoint2d : public GcGePoint2d
{
public:
    /*	
    safeArrayPt Input SAFEARRAY pointer containing x,y coordinates 
    Constructs 2d point with coordinates in safeArrayPt. The SAFEARRAY is one dimensional and composed of two doubles.
    */
    GcAxPoint2d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    x Input x coordinate 
    y Input y coordinate 
    Constructs 2d point with coordinates X and y.
    */
    GcAxPoint2d(double x, double y);

    /*
    pt Input GcGePoint2d containing x, y coordinates 
    Constructs 2d point with coordinates in pt.
    */
    GcAxPoint2d(const GcGePoint2d& pt);


    /*
    pt Input GcGeVector2d containing x, y coordinates 
    Constructs 2d point with coordinates in pt.
    */
    GcAxPoint2d(const GcGeVector2d& pt);

    /*
    var Input VARIANT pointer containing x, y coordinates 
    Constructs 2d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of two doubles.
    */
    GcAxPoint2d(const VARIANT* var) throw(HRESULT);

    /*
    var Input VARIANT reference containing x, y coordinates 
    Constructs 2d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of two doubles.
    */
    GcAxPoint2d(const VARIANT& var) throw(HRESULT);
    /*
    Default constructor. Creates a 2d point at the origin.
    */
    GcAxPoint2d();

    /*
    var Output VARIANT reference to contain x, y coordinates 

    Populates the VARIANT passed in with the X, Y coordinates. The data is represented in the VARIANT as a one dimensional SAFEARRAY of two doubles.

    */
    VARIANT &setVariant(VARIANT& var) const throw(HRESULT);

    /*	
    var Output VARIANT pointer to contain x,y coordinates 

    Populates the VARIANT passed in with the X, Y coordinates. The data is represented in the VARIANT as a one dimensional SAFEARRAY of two doubles.
    */
    VARIANT *setVariant(VARIANT* var) const throw(HRESULT);

    /*
    pt Input GcGeVector2d containing x, y coordinates 
    Copies 2d point with coordinates in pt.
    */
    GcAxPoint2d &operator = (const GcGeVector2d& pt);

    /*	
    var Input VARIANT pointer containing x, y coordinates 

    Copies 2d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of two doubles.
    */
    GcAxPoint2d &operator = (const VARIANT* var) throw(HRESULT);

    /*
    var Input VARIANT reference containing x, y coordinates 
    Copies 2d point with coordinates in var. The VARIANT is composed of a SAFEARRAY of two doubles.
    */
    GcAxPoint2d &operator = (const VARIANT& var) throw(HRESULT);

    /*	
    safeArrayPt Input SAFEARRAY pointer containing x, y coordinates 

    Copies 2d point with coordinates in safeArrayPt. The SAFEARRAY is one dimensional and composed of two doubles.

    */
    GcAxPoint2d &operator = (const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    pt Input GcGePoint2d containing x, y coordinates 

    Copies 2d point with coordinates in pt.
    */
    GcAxPoint2d &operator = (const GcGePoint2d& pt);

    /*	
    Returns a pointer to a one-dimensional SAFEARRAY of two doubles that contains the X and Y coordinates of the point. The SAFEARRAY returned must be freed.
    */
    SAFEARRAY *asSafeArrayPtr() const throw(HRESULT);

    /*	
    Returns a VARIANT pointer containing a one-dimensional SAFEARRAY of two doubles that contains the X and Y coordinates of the point. The variant must be freed.
    */
    VARIANT *asVariantPtr() const throw(HRESULT);

};

class GCADAXEXP GcAxPoint2dArray : public GcGePoint2dArray
{
public:
    /*
    var Output VARIANT reference to contain x, y coordinates of each point 
    Populates the VARIANT passed in with the X, Y coordinates of each point. The data is represented in the VARIANT as a one dimensional SAFEARRAY of 2 * X doubles where X is the number of points in the array.
    */
    VARIANT *setVariant(VARIANT* var) const throw(HRESULT);

    /*	
    var Output VARIANT reference to contain x, y coordinates of each point 
    Populates the VARIANT passed in with the X, Y coordinates of each point. The data is represented in the VARIANT as a one dimensional SAFEARRAY of 2 * X doubles where X is the number of points in the array.
    */
    VARIANT &setVariant(VARIANT& var) const throw(HRESULT);

    /*
    safeArrayPt Input SAFEARRAY pointer containing x, y coordinates 
    This function appends var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint2dArray &append(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    var Input VARIANT reference containing x, y coordinates 
    This function appends var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint2dArray &append(const VARIANT& var) throw(HRESULT);
    /*
    var Input VARIANT pointer containing x,y coordinates 
    This function appends var to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint2dArray &append(const VARIANT* var) throw(HRESULT);
    /*
    pt Input GcGePoint2d value 
    This function appends pt to the end of the array. The logical length will increase by one. If the physical length is not long enough, it will increase in size by the grow length (with the usual caveat about insufficient memory, as described in the Overview). This function returns the index of the new last element.
    */
    GcAxPoint2dArray &append(const GcGePoint2d& pt);

    /*
    Returns a pointer to a one-dimensional SAFEARRAY of 2 * X doubles (where X is the number of points in the array) that contains the X and Y coordinates of each point. The SAFEARRAY returned must be freed.
    */
    SAFEARRAY *asSafeArrayPtr() const throw(HRESULT);

};
