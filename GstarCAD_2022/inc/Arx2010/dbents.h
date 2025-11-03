#pragma once

#define AcDbText                                   GcDbText
#define GcDbText                                   OdDbText
#define AcDbAttributeDefinition                    GcDbAttributeDefinition
#define GcDbAttributeDefinition                    OdDbAttributeDefinition
#define AcDbAttribute                              GcDbAttribute
#define GcDbAttribute                              OdDbAttribute
#define AcDbBlockReference                         GcDbBlockReference
#define GcDbBlockReference                         OdDbBlockReference
#define treatAsAcDbBlockRefForExplode              treatAsGcDbBlockRefForExplode
#define treatAsGcDbBlockRefForExplode              treatAsOdDbBlockRefForExplode
#define AcDbMInsertBlock                           GcDbMInsertBlock
#define GcDbMInsertBlock                           OdDbMInsertBlock
#define AcDbBlockBegin                             GcDbBlockBegin
#define GcDbBlockBegin                             OdDbBlockBegin
#define AcDbBlockEnd                               GcDbBlockEnd
#define GcDbBlockEnd                               OdDbBlockEnd
#define AcDbSequenceEnd                            GcDbSequenceEnd
#define GcDbSequenceEnd                            OdDbSequenceEnd
#define AcDbVertex                                 GcDbVertex
#define GcDbVertex                                 OdDbVertex
#define AcDb2dVertex                               GcDb2dVertex
#define GcDb2dVertex                               OdDb2dVertex
#define AcDb3dPolylineVertex                       GcDb3dPolylineVertex
#define GcDb3dPolylineVertex                       OdDb3dPolylineVertex
#define AcDbPolygonMeshVertex                      GcDbPolygonMeshVertex
#define GcDbPolygonMeshVertex                      OdDbPolygonMeshVertex
#define AcDbPolyFaceMeshVertex                     GcDbPolyFaceMeshVertex
#define GcDbPolyFaceMeshVertex                     OdDbPolyFaceMeshVertex
#define AcDbFaceRecord                             GcDbFaceRecord
#define GcDbFaceRecord                             OdDbFaceRecord
#define AcDb2dPolyline                             GcDb2dPolyline
#define GcDb2dPolyline                             OdDb2dPolyline
#define AcDb3dPolyline                             GcDb3dPolyline
#define GcDb3dPolyline                             OdDb3dPolyline
#define AcDbArc                                    GcDbArc
#define GcDbArc                                    OdDbArc
#define AcDbCircle                                 GcDbCircle
#define GcDbCircle                                 OdDbCircle
#define AcDbLine                                   GcDbLine
#define GcDbLine                                   OdDbLine
#define AcDbPoint                                  GcDbPoint
#define GcDbPoint                                  OdDbPoint
#define AcDbFace                                   GcDbFace
#define GcDbFace                                   OdDbFace
#define AcDbPolygonMesh                            GcDbPolygonMesh
#define GcDbPolygonMesh                            OdDbPolygonMesh
#define AcDbPolyFaceMesh                           GcDbPolyFaceMesh
#define GcDbPolyFaceMesh                           OdDbPolyFaceMesh
#define AcDbSolid                                  GcDbSolid
#define GcDbSolid                                  OdDbSolid
#define AcDbTrace                                  GcDbTrace
#define GcDbTrace                                  OdDbTrace
#define AcDbShape                                  GcDbShape
#define GcDbShape                                  OdDbShape
#define AcDbViewport                               GcDbViewport
#define GcDbViewport                               OdDbViewport

#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
#include "dbmtext.h"
#include "dbbackground.h"
#include "dbdim.h"
#include "gept2dar.h"
#include "gedblar.h"
#include "dbsymtb.h"
#include "gemat3d.h"
#include "acdbxref.h"
#include "acgi.h"
#include "acgiviewport.h"
#include "acgivisualstyle.h"

#include "../DbLine.h"
#include "../DbAttributeDefinition.h"
#include "../DbAttribute.h"
#include "../DbMInsertBlock.h"
#include "../Db3dPolylineVertex.h"
#include "../DbPolygonMeshVertex.h"
#include "../DbPolyFaceMeshVertex.h"
#include "../DbFaceRecord.h"
#include "../Db3dPolyline.h"
#include "../DbArc.h"
#include "../DbCircle.h"
#include "../DbPoint.h"
#include "../DbFace.h"
#include "../DbPolygonMesh.h"
#include "../DbPolyFaceMesh.h"
#include "../DbSolid.h"
#include "../DbTrace.h"
#include "../DbShape.h"
#include "../DbViewport.h"
#include "../DbSequenceEnd.h"
#include "../DbBlockEnd.h"
#include "../DbBlockBegin.h"