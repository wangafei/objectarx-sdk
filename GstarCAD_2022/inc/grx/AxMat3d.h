#pragma once

#ifndef GCADAXEXP
#ifdef GVBADLL
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif
#endif

class GCADAXEXP GcAxMatrix3d : public AcGeMatrix3d
{
public:
    /*
    Default constructor. 
    */
    GcAxMatrix3d(void);

    /*
    safeArrayPt Input SAFEARRAY pointer containing matrix data 
    Constructs 3d matrix with data in safeArrayPt. The SAFEARRAY is two dimensional and composed of sixteen doubles.
    */
    GcAxMatrix3d(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    var Input VARIANT reference containing matrix data 
    Constructs a 3d matrix with data in var.
    */
    GcAxMatrix3d(const VARIANT& var) throw(HRESULT);

    /*
    var Input VARIANT pointer containing matrix data 
    Constructs a 3d matrix with data in var.
    */
    GcAxMatrix3d(const VARIANT* var) throw(HRESULT);

    /*
    var Input ads_point[4] containing matrix data 
    Constructs a 3d matrix with data in var.
    */
    GcAxMatrix3d(ads_matrix sdspoint);

    /*
    safeArrayPt Input SAFEARRAY pointer containing matrix data 
    Copies 3d matrix with data in safeArrayPt. The SAFEARRAY is two dimensional and composed of sixteen doubles.
    */
    GcAxMatrix3d &operator =(const SAFEARRAY* safeArrayPt) throw(HRESULT);

    /*
    var Input VARIANT reference containing matrix data 
    Copies a 3d matrix with data in var.
    */
    GcAxMatrix3d &operator =(const VARIANT& var) throw(HRESULT);

    /*
    var Input VARIANT pointer containing matrix data 
    Copies a 3d matrix with data in var.
    */
    GcAxMatrix3d &operator =(const VARIANT* var) throw(HRESULT);

    VARIANT SetVariant(VARIANT *var);
    VARIANT SetVariant(VARIANT &var);
};
