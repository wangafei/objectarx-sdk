#pragma once

#define AcDbSubDMesh  GcDbSubDMesh
#define GcDbSubDMesh  OdDbSubDMesh

#define AcDbFaceterSettings  GcDbFaceterSettings
#define GcDbFaceterSettings  OdDbFaceterSettings

#define MeshFaceterSettings  OdDbFaceterSettings

#define acdbGetObjectMesh  gcdbGetObjectMesh
#define gcdbGetObjectMesh  oddbGetObjectMesh

#include "dbmain.h"
#include "../DbSubDMesh.h"