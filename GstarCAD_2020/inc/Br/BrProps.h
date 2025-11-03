#pragma once

#include "../TD_PackPush.h"

#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"

struct OdBrMassProps
{
	double			  mVolume; 
	double			  mMass; 
	OdGePoint3d		mCentroid;
	double			  mRadiiGyration[3];
	double			  mMomInertia[3];
	double			  mProdInertia[3];
	double			  mPrinMoments[3];
	OdGeVector3d	mPrinAxes[3];
};


#include "../TD_PackPop.h"

