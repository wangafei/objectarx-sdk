

#pragma once

#ifndef ZDBBLENDOPTIONS_H
#define ZDBBLENDOPTIONS_H

#include "zacdb.h"

#pragma pack(push, 8)



class ZCDB_PORT ZcDbBlendOptions
{
public:

    ZcDbBlendOptions ();

    ~ZcDbBlendOptions ();

    enum DriveModeType {
        kDriveModeFirst  = 0,
        kDriveModeSecond = 1,
        kDriveModeBoth   = 2
    };

    ZcDbBlendOptions& operator = ( const ZcDbBlendOptions& src );

    bool  simplify () const;

    Zcad::ErrorStatus  setSimplify ( bool val );

    bool  solid () const;

    Zcad::ErrorStatus  setSolid ( bool val );

    unsigned int  quality () const;

    Zcad::ErrorStatus  setQuality ( unsigned int val );

    ZcGePoint3d*  coplanarPoint () const;

    Zcad::ErrorStatus  setCoplanarPoint ( const ZcGePoint3d* pPt );

    ZcGeVector3d*  coplanarDirection () const;

    Zcad::ErrorStatus  setCoplanarDirection ( const ZcGeVector3d* pDir );

    
    ZcDbBlendOptions::DriveModeType  driveMode () const;

    Zcad::ErrorStatus  setDriveMode( ZcDbBlendOptions::DriveModeType val );

private:
    void *mpImpBlendOptions;
    friend class ZcDbImpBlendOptions;
};

#pragma pack(pop)

#endif 
