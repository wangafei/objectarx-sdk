/* 声明示例
#define OD_SYSVAR_DEF_R(RName, DDName, type) \
        type RName() const;
#define OD_SYSVAR_DEF_W(WName, DDName, type) \
        OdResult WName(type);
*/
/* 实现示例
#define OD_SYSVAR_DEF_R(RName, DDName, type) \
        type OdDbDatabase::RName() const \
        { return OD_SYSVAR_HOOK_GET(get##DDName()); }
#define OD_SYSVAR_DEF_W(WName, DDName, type) \
        OdResult OdDbDatabase::WName(type val) \
        { OD_TRY() set##DDName(OD_SYSVAR_HOOK_SET(val)); OD_CATCH() }
*/


#if !defined(OD_SYSVAR_DEF_R) || !defined(OD_SYSVAR_DEF_W)
#error "OD_SYSVAR_DEF_R and OD_SYSVAR_DEF_W NOT defined"
#endif

#ifndef OD_SYSVAR_DEF_RW
#define OD_SYSVAR_DEF_RW(RName, WName, DDName, type) \
        OD_SYSVAR_DEF_R(RName, DDName, type) \
        OD_SYSVAR_DEF_W(WName, DDName, type)
#endif

#define OD_SYSVAR_HOOK_GET(x) (x)
#define OD_SYSVAR_HOOK_SET(x) (x)


// ***DRAWING SYSTEM VARS***

OD_SYSVAR_DEF_RW(dimaso, setDimaso, DIMASO, bool)
OD_SYSVAR_DEF_RW(dimsho, setDimsho, DIMSHO, bool)
OD_SYSVAR_DEF_RW(plinegen, setPlinegen, PLINEGEN, bool)
OD_SYSVAR_DEF_RW(orthomode, setOrthomode, ORTHOMODE, bool)
OD_SYSVAR_DEF_RW(regenmode, setRegenmode, REGENMODE, bool)
OD_SYSVAR_DEF_RW(fillmode, setFillmode, FILLMODE, bool)
OD_SYSVAR_DEF_RW(qtextmode, setQtextmode, QTEXTMODE, bool)
OD_SYSVAR_DEF_RW(psltscale, setPsltscale, PSLTSCALE, bool)
OD_SYSVAR_DEF_RW(limcheck, setLimcheck, LIMCHECK, bool)

#undef OD_SYSVAR_HOOK_SET
#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) ((x) != 0)
#define OD_SYSVAR_HOOK_SET(x) ((x) ? 1 : 0)
// OdInt16 <-> bool
OD_SYSVAR_DEF_RW(saveproxygraphics, setSaveproxygraphics, PROXYGRAPHICS, bool)
#undef OD_SYSVAR_HOOK_SET
#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (x)
#define OD_SYSVAR_HOOK_SET(x) (x)

OD_SYSVAR_DEF_RW(dispSilh, setDispSilh, DISPSILH, bool)
OD_SYSVAR_DEF_RW(plineEllipse, setPlineEllipse, PELLIPSE, bool)
OD_SYSVAR_DEF_RW(skpoly, setSkpoly, SKPOLY, bool)
OD_SYSVAR_DEF_RW(angdir, setAngdir, ANGDIR, bool)
OD_SYSVAR_DEF_RW(splframe, setSplframe, SPLFRAME, bool)
OD_SYSVAR_DEF_RW(mirrtext, setMirrtext, MIRRTEXT, bool)
OD_SYSVAR_DEF_RW(worldview, setWorldview, WORLDVIEW, bool)
OD_SYSVAR_DEF_RW(tilemode, setTilemode, TILEMODE, bool)
OD_SYSVAR_DEF_RW(plimcheck, setPlimcheck, PLIMCHECK, bool)
OD_SYSVAR_DEF_RW(visretain, setVisretain, VISRETAIN, bool)

OD_SYSVAR_DEF_RW(treedepth, setTreedepth, TREEDEPTH, OdInt16)
OD_SYSVAR_DEF_RW(lunits, setLunits, LUNITS, OdInt16)
OD_SYSVAR_DEF_RW(luprec, setLuprec, LUPREC, OdInt16)
OD_SYSVAR_DEF_RW(aunits, setAunits, AUNITS, OdInt16)
OD_SYSVAR_DEF_RW(auprec, setAuprec, AUPREC, OdInt16)
OD_SYSVAR_DEF_RW(attmode, setAttmode, ATTMODE, OdInt16)
OD_SYSVAR_DEF_RW(pdmode, setPdmode, PDMODE, OdInt16)
OD_SYSVAR_DEF_RW(useri1, setUseri1, USERI1, OdInt16)
OD_SYSVAR_DEF_RW(useri2, setUseri2, USERI2, OdInt16)
OD_SYSVAR_DEF_RW(useri3, setUseri3, USERI3, OdInt16)
OD_SYSVAR_DEF_RW(useri4, setUseri4, USERI4, OdInt16)
OD_SYSVAR_DEF_RW(useri5, setUseri5, USERI5, OdInt16)
OD_SYSVAR_DEF_RW(splinesegs, setSplinesegs, SPLINESEGS, OdInt16)
OD_SYSVAR_DEF_RW(surfu, setSurfu, SURFU, OdInt16)
OD_SYSVAR_DEF_RW(surfv, setSurfv, SURFV, OdInt16)
OD_SYSVAR_DEF_RW(surftype, setSurftype, SURFTYPE, OdInt16)
OD_SYSVAR_DEF_RW(surftab1, setSurftab1, SURFTAB1, OdInt16)
OD_SYSVAR_DEF_RW(surftab2, setSurftab2, SURFTAB2, OdInt16)
OD_SYSVAR_DEF_RW(splinetype, setSplinetype, SPLINETYPE, OdInt16)
OD_SYSVAR_DEF_RW(shadedge, setShadedge, SHADEDGE, OdInt16)
OD_SYSVAR_DEF_RW(shadedif, setShadedif, SHADEDIF, OdInt16)
OD_SYSVAR_DEF_RW(measurement, setMeasurement, MEASUREMENT, OdDb::MeasurementValue)
OD_SYSVAR_DEF_RW(unitmode, setUnitmode, UNITMODE, OdInt16)
OD_SYSVAR_DEF_RW(maxactvp, setMaxactvp, MAXACTVP, OdInt16)
OD_SYSVAR_DEF_RW(isolines, setIsolines, ISOLINES, OdInt16)

OD_SYSVAR_DEF_RW(ltscale, setLtscale, LTSCALE, double)
OD_SYSVAR_DEF_RW(textsize, setTextsize, TEXTSIZE, double)
OD_SYSVAR_DEF_RW(tracewid, setTracewid, TRACEWID, double)
OD_SYSVAR_DEF_RW(sketchinc, setSketchinc, SKETCHINC, double)
OD_SYSVAR_DEF_RW(filletrad, setFilletrad, FILLETRAD, double)
OD_SYSVAR_DEF_RW(thickness, setThickness, THICKNESS, double)

OD_SYSVAR_DEF_RW(celweight, setCelweight, CELWEIGHT, OdDb::LineWeight)
OD_SYSVAR_DEF_RW(endCaps, setEndCaps, ENDCAPS, OdDb::EndCaps)
OD_SYSVAR_DEF_RW(joinStyle, setJoinStyle, JOINSTYLE, OdDb::JoinStyle)
OD_SYSVAR_DEF_RW(lineWeightDisplay, setLineWeightDisplay, LWDISPLAY, bool)
OD_SYSVAR_DEF_RW(xrefEditEnabled, setXrefEditEnabled, XEDIT, bool)
OD_SYSVAR_DEF_RW(oleStartUp, setOleStartUp, OLESTARTUP, bool)

OD_SYSVAR_DEF_RW(angbase, setAngbase, ANGBASE, double)
OD_SYSVAR_DEF_RW(pdsize, setPdsize, PDSIZE, double)
OD_SYSVAR_DEF_RW(plinewid, setPlinewid, PLINEWID, double)
OD_SYSVAR_DEF_RW(userr1, setUserr1, USERR1, double)
OD_SYSVAR_DEF_RW(userr2, setUserr2, USERR2, double)
OD_SYSVAR_DEF_RW(userr3, setUserr3, USERR3, double)
OD_SYSVAR_DEF_RW(userr4, setUserr4, USERR4, double)
OD_SYSVAR_DEF_RW(userr5, setUserr5, USERR5, double)
OD_SYSVAR_DEF_RW(chamfera, setChamfera, CHAMFERA, double)
OD_SYSVAR_DEF_RW(chamferb, setChamferb, CHAMFERB, double)
OD_SYSVAR_DEF_RW(chamferc, setChamferc, CHAMFERC, double)
OD_SYSVAR_DEF_RW(chamferd, setChamferd, CHAMFERD, double)
OD_SYSVAR_DEF_RW(facetres, setFacetres, FACETRES, double)

OD_SYSVAR_DEF_R(tdcreate, TDCREATE, OdDbDate)
OD_SYSVAR_DEF_R(tdupdate, TDUPDATE, OdDbDate)
OD_SYSVAR_DEF_R(tducreate, TDUCREATE, OdDbDate)
OD_SYSVAR_DEF_R(tduupdate, TDUUPDATE, OdDbDate)
OD_SYSVAR_DEF_R(tdindwg, TDINDWG, OdDbDate)
OD_SYSVAR_DEF_R(tdusrtimer, TDUSRTIMER, OdDbDate)

OD_SYSVAR_DEF_RW(cecolor, setCecolor, CECOLOR, OdCmColor)
OD_SYSVAR_DEF_RW(clayer, setClayer, CLAYER, OdDbObjectId)
OD_SYSVAR_DEF_RW(textstyle, setTextstyle, TEXTSTYLE, OdDbObjectId)
OD_SYSVAR_DEF_RW(celtype, setCeltype, CELTYPE, OdDbObjectId)
OD_SYSVAR_DEF_RW(dimstyle, setDimstyle, DIMSTYLE, OdDbObjectId)
OD_SYSVAR_DEF_RW(cmlstyleID, setCmlstyleID, CMLSTYLE, OdDbObjectId)
OD_SYSVAR_DEF_RW(cmljust, setCmljust, CMLJUST, OdInt16)
OD_SYSVAR_DEF_RW(cmlscale, setCmlscale, CMLSCALE, double)
OD_SYSVAR_DEF_RW(celtscale, setCeltscale, CELTSCALE, double)

OD_SYSVAR_DEF_RW(pinsbase, setPinsbase, PINSBASE, OdGePoint3d)
OD_SYSVAR_DEF_RW(pextmin, setPextmin, PEXTMIN, OdGePoint3d)
OD_SYSVAR_DEF_RW(pextmax, setPextmax, PEXTMAX, OdGePoint3d)
OD_SYSVAR_DEF_RW(plimmin, setPlimmin, PLIMMIN, OdGePoint2d)
OD_SYSVAR_DEF_RW(plimmax, setPlimmax, PLIMMAX, OdGePoint2d)
OD_SYSVAR_DEF_RW(pelevation, setPelevation, PELEVATION, double)
OD_SYSVAR_DEF_RW(pucsBase, setPucsBase, PUCSBASE, OdDbObjectId)

OD_SYSVAR_DEF_R(pucsorg, PUCSORG, OdGePoint3d)
OD_SYSVAR_DEF_R(pucsxdir, PUCSXDIR, OdGeVector3d)
OD_SYSVAR_DEF_R(pucsydir, PUCSYDIR, OdGeVector3d)
OD_SYSVAR_DEF_R(pucsname, PUCSNAME, OdDbObjectId)

OD_SYSVAR_DEF_RW(insbase, setInsbase, INSBASE, OdGePoint3d)
OD_SYSVAR_DEF_RW(extmin, setExtmin, EXTMIN, OdGePoint3d)
OD_SYSVAR_DEF_RW(extmax, setExtmax, EXTMAX, OdGePoint3d)
OD_SYSVAR_DEF_RW(limmin, setLimmin, LIMMIN, OdGePoint2d)
OD_SYSVAR_DEF_RW(limmax, setLimmax, LIMMAX, OdGePoint2d)
OD_SYSVAR_DEF_RW(elevation, setElevation, ELEVATION, double)
OD_SYSVAR_DEF_RW(ucsBase, setUcsBase, UCSBASE, OdDbObjectId)

OD_SYSVAR_DEF_R(ucsorg, UCSORG, OdGePoint3d)
OD_SYSVAR_DEF_R(ucsxdir, UCSXDIR, OdGeVector3d)
OD_SYSVAR_DEF_R(ucsydir, UCSYDIR, OdGeVector3d)
OD_SYSVAR_DEF_R(ucsname, UCSNAME, OdDbObjectId)

#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdUInt16)(x)
// OdUInt16 <-> int
OD_SYSVAR_DEF_RW(tstackalign, setTStackalign, TSTACKALIGN, int)
// OdUInt16 <-> int
OD_SYSVAR_DEF_RW(tstacksize, setTStacksize, TSTACKSIZE, int)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (x)

OD_SYSVAR_DEF_RW(insunits, setInsunits, INSUNITS, OdDb::UnitsValue)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (OdUInt8)(x)
// OdInt16 <-> OdUInt8
OD_SYSVAR_DEF_RW(sortEnts, setSortEnts, SORTENTS, OdUInt8)
// OdInt16 <-> OdUInt8
OD_SYSVAR_DEF_RW(dimAssoc, setDimAssoc, DIMASSOC, OdUInt8)
// OdInt16 <-> OdUInt8
OD_SYSVAR_DEF_RW(haloGap, setHaloGap, HALOGAP, OdUInt8)
// OdInt16 <-> OdUInt8
OD_SYSVAR_DEF_RW(obscuredLineType, setObscuredLineType, OBSCUREDLTYPE, OdUInt8)
#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (x)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (OdUInt16)(x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdInt16)(x)

// OdInt16 <-> OdUInt16
OD_SYSVAR_DEF_RW(obscuredColor, setObscuredColor, OBSCUREDCOLOR, OdUInt16)
// OdInt16 <-> OdUInt16
OD_SYSVAR_DEF_RW(intersectColor, setIntersectColor, INTERSECTIONCOLOR, OdUInt16)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (x ? 1 : 0)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (x != 0)

// bool <-> OdUInt8
OD_SYSVAR_DEF_RW(hideText, setHideText, HIDETEXT, OdUInt8)
// bool <-> OdUInt8
OD_SYSVAR_DEF_RW(intersectDisplay, setIntersectDisplay, INTERSECTIONDISPLAY, OdUInt8)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (x)

OD_SYSVAR_DEF_R(plotStyleMode, PSTYLEMODE, bool)
OD_SYSVAR_DEF_RW(viewportScaleDefault, setViewportScaleDefault, PSVPSCALE, double)

// ARX-07
OD_SYSVAR_DEF_RW(get3dDwfPrec, set3dDwfPrec, 3DDWFPREC, double)
OD_SYSVAR_DEF_RW(hpInherit, setHpInherit, HPINHERIT, bool)
OD_SYSVAR_DEF_RW(hpOrigin, setHpOrigin, HPORIGIN, OdGePoint2d)
OD_SYSVAR_DEF_RW(cameraHeight, setCameraHeight, CAMERAHEIGHT, double)
OD_SYSVAR_DEF_RW(lensLength, setLensLength, LENSLENGTH, double)
OD_SYSVAR_DEF_RW(cameraDisplay, setCameraDisplay, CAMERADISPLAY, bool)
OD_SYSVAR_DEF_RW(stepsPerSec, setStepsPerSec, STEPSPERSEC, double)
OD_SYSVAR_DEF_RW(stepSize, setStepSize, STEPSIZE, double)
OD_SYSVAR_DEF_RW(realWorldScale, setRealWorldScale, REALWORLDSCALE, bool)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (OdUInt8)(x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdInt8)(x)

// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(drawOrderCtl, setDrawOrderCtl, DRAWORDERCTL, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(solidHist, setSolidHist, SOLIDHIST, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(showHist, setShowHist, SHOWHIST, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(lightGlyphDisplay, setLightGlyphDisplay, LIGHTGLYPHDISPLAY, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(tileModeLightSynch, setTileModeLightSynch, TILEMODELIGHTSYNCH, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(dwfframe, setDwfframe, DWFFRAME, OdUInt8)
// OdInt8 <-> OdUInt8
OD_SYSVAR_DEF_RW(dgnframe, setDgnframe, DGNFRAME, OdUInt8)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (OdUInt16)(x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdDb::LoftParamType)(x)

// OdDb::LoftParamType <-> OdUInt16
OD_SYSVAR_DEF_RW(loftParam, setLoftParam, LOFTPARAM, OdUInt16)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (OdUInt8)(x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdDb::LoftNormalsType)(x)

// OdDb::LoftNormalsType <-> OdUInt8
OD_SYSVAR_DEF_RW(loftNormals, setLoftNormals, LOFTNORMALS, OdUInt8)

#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (OdGiSubEntityTraits::ShadowFlags)(x)

// OdDb::ShadowFlags <-> OdUInt8
OD_SYSVAR_DEF_RW(cshadow, setCshadow, CSHADOW, OdUInt8)

#undef OD_SYSVAR_HOOK_GET
#define OD_SYSVAR_HOOK_GET(x) (x)
#undef OD_SYSVAR_HOOK_SET
#define OD_SYSVAR_HOOK_SET(x) (x)

//OD_SYSVAR_DEF_RW(tablestyle, setTablestyle, CTABLESTYLE, OdDbObjectId)
OD_SYSVAR_DEF_RW(psolWidth, setPsolWidth, PSOLWIDTH, double)
OD_SYSVAR_DEF_RW(psolHeight, setPsolHeight, PSOLHEIGHT, double)

OD_SYSVAR_DEF_RW(loftAng1, setLoftAng1, LOFTANG1, double)
OD_SYSVAR_DEF_RW(loftAng2, setLoftAng2, LOFTANG2, double)
OD_SYSVAR_DEF_RW(loftMag1, setLoftMag1, LOFTMAG1, double)
OD_SYSVAR_DEF_RW(loftMag2, setLoftMag2, LOFTMAG2, double)

OD_SYSVAR_DEF_RW(latitude, setLatitude, LATITUDE, double)
OD_SYSVAR_DEF_RW(longitude, setLongitude, LONGITUDE, double)
OD_SYSVAR_DEF_RW(northDirection, setNorthDirection, NORTHDIRECTION, double)
OD_SYSVAR_DEF_RW(timeZone, setTimeZone, TIMEZONE, OdDb::TimeZone)

OD_SYSVAR_DEF_RW(interfereColor, setInterfereColor, INTERFERECOLOR, OdCmColor)
OD_SYSVAR_DEF_RW(interfereObjVisStyle, setInterfereObjVisStyle, INTERFEREOBJVS, OdDbObjectId)
OD_SYSVAR_DEF_RW(interfereVpVisStyle, setInterfereVpVisStyle, INTERFEREVPVS, OdDbObjectId)
OD_SYSVAR_DEF_RW(dragVisStyle, setDragVisStyle, DRAGVS, OdDbObjectId)
OD_SYSVAR_DEF_RW(shadowPlaneLocation, setShadowPlaneLocation, SHADOWPLANELOCATION, double)
OD_SYSVAR_DEF_RW(cmaterial, setCmaterial, CMATERIAL, OdDbObjectId)

// ARX-08
//OD_SYSVAR_DEF_RW(mleaderstyle, setMleaderstyle, CMLEADERSTYLE, OdDbObjectId)
OD_SYSVAR_DEF_RW(annoAllVisible, setAnnoAllVisible, ANNOALLVISIBLE, bool)
OD_SYSVAR_DEF_RW(msltscale, setMsltscale, MSLTSCALE, bool)

///////////////////////////////////////////////////////////////////////////////////////////
// 以下必须手动实现

//OD_SYSVAR_DEF_RW(cannoscale, Cannoscale, CANNOSCALE, OdDbAnnotationScale*)

//OD_SYSVAR_DEF_RW(handseed, Handseed, handseed, OdDbHandle)

//OD_SYSVAR_DEF_RW(cePlotStyleNameId, CePlotStyleNameId, CEPSNTYPE & CEPSNID, XXX)

//OD_SYSVAR_DEF_R(getMenu, MENUNAME, XXX)

//OD_SYSVAR_DEF_RW(getProjectName, ProjectName, PROJECTNAME, XXX)

//OD_SYSVAR_DEF_RW(getHyperlinkBase, HyperlinkBase, HYPERLINKBASE, XXX)

//OD_SYSVAR_DEF_RW(getStyleSheet, StyleSheet, STYLESHEET, XXX)

//OD_SYSVAR_DEF_RW(getFingerprintGuid, FingerprintGuid, FINGERPRINTGUID, XXX)

//OD_SYSVAR_DEF_RW(getVersionGuid, VersionGuid, VERSIONGUID, XXX)

// 比较特殊，通过全局函数实现的
// EXTNAMES <-> xxdbGetExtnames xxdbSetExtnames
//
// //[TODO]
// INDEXCTL
// XCLIPFRAME
// FIELDEVAL
// MSOLESCALE
// UPDATETHUMBNAIL
//
// --没有对应--
// (08) annotativeDwg lightingUnits lightsInBlocks dxeVal
// (DD) DWGCODEPAGE
//
// --没有保存--
// TEXTQLTY
// DBCSTATE
//

// DimVar
// OdResult getDimpost(char*& pOutput) const;
// OdResult getDimapost(char*& pOutput) const;
// OdResult getDimblk(char*& pOutput) const;
// OdResult getDimblk1(char*& pOutput) const;
// OdResult getDimblk2(char*& pOutput) const;


/*
    static bool isValidLineWeight(int weight);
    static OdDb::LineWeight getNearestLineWeight(int weight);

    OdResult getDimstyleData(OdDbDimStyleTableRecord*& pRec) const;
    OdResult getDimstyleChildData(const OdRxClass *pDimClass,
                                  OdDbDimStyleTableRecord*& pRec,
                                  OdDbObjectId &style) const;
    OdDbObjectId getDimstyleChildId(const OdRxClass *pDimClass,
                                    OdDbObjectId &parentStyle) const;
    OdDbObjectId getDimstyleParentId(OdDbObjectId &childStyle) const;
                                           
    OdResult setDimstyleData(OdDbDimStyleTableRecord* pRec);
    OdResult setDimstyleData(OdDbObjectId id);

    OdResult updateExt(bool doBestFit = FALSE);
*/

#undef OD_SYSVAR_HOOK_SET
#undef OD_SYSVAR_HOOK_GET
#undef OD_SYSVAR_DEF_RW

