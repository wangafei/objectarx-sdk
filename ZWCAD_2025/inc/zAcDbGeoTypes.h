#ifndef __ZGEOTYPE_H
#define __ZGEOTYPE_H

#pragma pack (push, 8)

enum ZcGeoMapType
{

	kNoMap = 0,
	

	kAerial = 1,
	

	kRoad = 2,

	kHybrid = 3
};

enum ZcGeoMapResolution
{

	kCoarse = -1,

	kOptimal = 0,
	

	kFine = 1,

	kFiner = 2
};

#pragma pack (pop)
#endif
