//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2017 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
//
// DESCRIPTION:
//
// This file contains the class AcGeLinearEnt3d - A mathematical entity
// used to represent a line in 3-space.

#ifndef AC_GELINE3D_H
#define AC_GELINE3D_H

#include "gelent3d.h"
#pragma pack (push, 8)

class AcGeLine2d;

class
GE_DLLEXPIMPORT
AcGeLine3d : public AcGeLinearEnt3d
{
public:
    AcGeLine3d();
    AcGeLine3d(const AcGeLine3d& line);
    AcGeLine3d(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    AcGeLine3d(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);

    // The x-axis, y-axis, and z-axis lines.
    //
    static const AcGeLine3d kXAxis;
    static const AcGeLine3d kYAxis;
    static const AcGeLine3d kZAxis;

    // Set methods.
    //
    AcGeLine3d& set(const AcGePoint3d& pnt, const AcGeVector3d& vec);
    AcGeLine3d& set(const AcGePoint3d& pnt1, const AcGePoint3d& pnt2);

    // Assignment operator.
    //
    AcGeLine3d& operator = (const AcGeLine3d& line);
};

#pragma pack (pop)
#endif
