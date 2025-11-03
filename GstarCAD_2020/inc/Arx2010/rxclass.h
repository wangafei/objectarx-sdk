#pragma once

#define AcRxClass                       GcRxClass
#define GcRxClass                       OdRxClass
#define acrxBuildClassHierarchy         gcrxBuildClassHierarchy
#define gcrxBuildClassHierarchy         odrxBuildClassHierarchy
#define deleteAcRxClass                 deleteGcRxClass
#define deleteGcRxClass                 deleteOdRxClass
#define newAcRxClass                    newGcRxClass
#define newGcRxClass                    newOdRxClass

#include "rxobject.h"
#include "AdAChar.h"
#include "../RxObject.h"

