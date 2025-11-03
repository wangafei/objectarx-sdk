#ifndef AECMODELER_INC_UTIL_H
#define AECMODELER_INC_UTIL_H


#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


DllImpExp void ZwAppendDxfExtension(const wchar_t inFileName[], wchar_t outFileName[]);


DllImpExp double  ZwArcToBulge   (const ZwPoint2d& p1, const ZwPoint2d& p2, const ZwPoint2d& pointOnArc, const ZwPoint2d& center);
DllImpExp void    ZwBulgeToCircle(const ZwPoint2d& p1, const ZwPoint2d& p2, double bulge, ZwPoint2d& center, double& radius);

DllImpExp void ZwGetAllConnectedEdgesSharingVertex(const ZwEdge* oneEdge, ZwDarray& allEdges);

DllImpExp bool    ZwProfilesOrdered(const ZwBody&, const ZwBody&);

DllImpExp ZwEdge*   ZwBreakEdge     (ZwBody&, const ZwPoint3d&);
DllImpExp ZwEdge*   ZwBreakEdge     (ZwBody&, const ZwPoint3d& p1, const ZwPoint3d& p2);

DllImpExp ZwVertex* ZwFindVertex    (const ZwBody&, const ZwPoint3d&);
DllImpExp ZwEdge*   ZwFindEdge      (const ZwBody&, const ZwPoint3d&, const ZwPoint3d&);
DllImpExp void    ZwFindFace      (const ZwBody&, const ZwPlane&, ZwDarray& facesFound);

DllImpExp void    ZwPrintFace     (ZwFace*  );
DllImpExp void    ZwPrintEdge     (ZwEdge*  );
DllImpExp void    ZwPrintVertex   (ZwVertex*);

DllImpExp void ZwExtremeVertices  (const ZwBody&, const ZwVector3d& dir, ZwVertex*& vMin, ZwVertex*& vMax);

AECMODELER_NAMESPACE_END
#endif

