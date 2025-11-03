/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2016, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2016 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////


#ifndef _OdDbSection_h_Included_
#define _OdDbSection_h_Included_

#include "DbEntity.h"
#include "SmartPtr.h"
#include "DbHatch.h"
#include "TD_PackPush.h"
#include "ModelerGeometry.h"

class OdDbSectionSettings;
typedef OdSmartPtr<OdDbSectionSettings> OdDbSectionSettingsPtr;

class OdDbSection;
typedef OdSmartPtr<OdDbSection> OdDbSectionPtr;

/** \details

    <group OdDb_Classes>
*/
class TOOLKIT_EXPORT OdDbSection : public OdDbEntity
{
public:
  enum State
  {
    kPlane              = 0x01,
    kBoundary           = 0x02,
    kVolume             = 0x04
  };

  enum SubItem
  {
    kNone               = 0x00,
    kSectionLine        = 0x01,
    kSectionLineTop     = 0x02,
    kSectionLineBottom  = 0x04,
    kBackLine           = 0x08,
    kBackLineTop        = 0x10,
    kBackLineBottom     = 0x20,
    kVerticalLineTop    = 0x40,
    kVerticalLineBottom = 0x80
  };

  enum Height
  {
    kHeightAboveSectionLine = 0x1,
    kHeightBelowSectionLine = 0x2
  };

public:
  ODDB_DECLARE_MEMBERS(OdDbSection);

  OdDbSection();
  OdDbSection(const OdGePoint3dArray& pts,
	  const OdGeVector3d& verticalDir);
  OdDbSection(const OdGePoint3dArray& pts,
	  const OdGeVector3d& verticalDir, const OdGeVector3d& vecViewingDir);
  ~OdDbSection(void);
  static OdDbSectionPtr createObject(const OdGePoint3dArray& pts,
    const OdGeVector3d& verticalDir);
  static OdDbSectionPtr createObject(const OdGePoint3dArray& pts,
    const OdGeVector3d& verticalDir, const OdGeVector3d& vecViewingDir);

  OdDbSection::State state() const;
  OdResult setState(OdDbSection::State nState);

  const OdChar * getName() const;
  OdResult getName(OdString& sName) const;
  OdResult getName (OdChar*& pszName) const;
  
  OdResult setName(const OdChar * pszName);

  OdGeVector3d viewingDirection () const;
  OdResult setViewingDirection(const OdGeVector3d& dir);

  OdGeVector3d verticalDirection() const;
  OdResult setVerticalDirection(const OdGeVector3d& dir);

  OdGeVector3d normal() const;
  OdResult plane(OdGeVector3d& uAxis, OdGeVector3d& vAxis) const;

  int indicatorTransparency() const;
  OdResult setIndicatorTransparency(int nTransparency);

  OdCmColor indicatorFillColor  () const;
  OdResult setIndicatorFillColor(const OdCmColor& color);

  int numVertices() const;
  OdResult getVertex(int nIndex, 
    OdGePoint3d& pt) const;
  OdResult setVertex(int nIndex, 
    const OdGePoint3d& pt);
  OdResult addVertex(int nInsertAt, 
    const OdGePoint3d& pt);
  OdResult removeVertex(int nIndex);
  OdResult  getVertices(OdGePoint3dArray& pts) const;
  OdResult  setVertices(const OdGePoint3dArray& pts);

  double height(OdDbSection::Height nHeightType) const;
  OdResult setHeight(OdDbSection::Height nHeightType, double fHeight);

  bool  hitTest(const OdGePoint3d& ptHit, int* pSegmentIndex, OdGePoint3d* ptOnSegment, OdDbSection::SubItem* pSubItem) const;
  OdResult createJog   (const OdGePoint3d& ptOnSection);
  bool hasJogs() const;

  OdDbObjectId getSettings() const;
  OdDbSectionSettingsPtr getSettings(OdDb::OpenMode mode) const;
  OdResult getSettings (OdDbSectionSettings*& pSettings,OdDb::OpenMode mode) const;

  bool isLiveSectionEnabled() const;
  OdResult enableLiveSection(bool bEnable);

  bool isSlice() const;
  OdResult setIsSlice( bool bIsSlice );

  double thicknesDepth() const;
  OdResult setThicknesDepth( double depth );

  double sectionPlaneOffset() const;
  OdResult setSectionPlaneOffset( double offset );

public:
  // Base class overrides
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
	
  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
  virtual OdResult subClose();
  
  virtual OdResult subTransformBy(const OdGeMatrix3d& xform);

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;

  //virtual OdResult subGetGeomExtents(OdGeExtents3d& extents) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  OdResult generateSectionGeometry (OdDbEntity*             pEnt,
                                    OdArray<OdDbEntityPtr>& intBoundaryEnts,
                                    OdArray<OdDbEntityPtr>& intFillEnts,
                                    OdArray<OdDbEntityPtr>& backgroundEnts,
                                    OdArray<OdDbEntityPtr>& foregroundEnts,
                                    OdArray<OdDbEntityPtr>& curveTangencyEnts) const;

  // INTERNAL USE ONLY
  OdResult generateSectionGeometry (OdDbEntity*             pEnt,
                                    OdArray<OdDbEntityPtr>& intBoundaryEnts,
                                    OdArray<OdDbEntityPtr>& intFillEnts,
                                    OdArray<OdDbEntityPtr>& backgroundEnts,
                                    OdArray<OdDbEntityPtr>& foregroundEnts,
                                    OdArray<OdDbEntityPtr>& curveTangencyEnts,
                                    bool                    bIsSetProperties) const;
  
  OdResult generateSectionGeometry (const OdArray<OdDbEntity*>& entset,
                                    OdArray<OdDbEntity*>& intBoundaryEnts,
                                    OdArray<OdDbEntity*>& intFillEnts,
                                    OdArray<OdDbEntity*>& backgroundEnts,
                                    OdArray<OdDbEntity*>& foregroundEnts,
                                    OdArray<OdDbEntity*>& curveTangencyEnts) const;


  double topPlane() const;
  OdResult  setTopPlane(double);

  double bottomPlane() const;
  OdResult setBottomPlane(double);
  
  double elevation() const;
  OdResult setElevation( double);
};


//*************************************************************************
// OdDbSectionSettings
//*************************************************************************

/** \details

    <group OdDb_Classes>
*/
class TOOLKIT_EXPORT OdDbSectionSettings : public OdDbObject
{
public:
  enum SectionType
  {
    kLiveSection                = 0x1,
    k2dSection                  = 0x2,
    k3dSection                  = 0x4 
  };

  enum Geometry
  {
    kIntersectionBoundary       = 0x1,
    kIntersectionFill           = 0x2,
    kBackgroundGeometry         = 0x4,
    kForegroundGeometry         = 0x8,
    kCurveTangencyLines         = 0x10 
  };

  enum Generation
  {
    kSourceAllObjects           = 0x1,
    kSourceSelectedObjects      = 0x2,

    kDestinationNewBlock        = 0x10,
    kDestinationReplaceBlock    = 0x20,
    kDestinationFile            = 0x40
  };

public:
  ODDB_DECLARE_MEMBERS(OdDbSectionSettings);

  OdDbSectionSettings();
  ~OdDbSectionSettings();

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  OdResult reset();
  OdResult reset(OdDbSectionSettings::SectionType nSecType);

  OdDbSectionSettings::SectionType currentSectionType() const;
  OdResult setCurrentSectionType(OdDbSectionSettings::SectionType nSecType);

  OdDbSectionSettings::Generation generationOptions(OdDbSectionSettings::SectionType nSecType) const;
  OdResult setGenerationOptions(OdDbSectionSettings::SectionType nSecType,
    OdDbSectionSettings::Generation nOptions);

  OdResult getSourceObjects(OdDbSectionSettings::SectionType nSecType,
    OdDbObjectIdArray& ids) const;
  OdResult setSourceObjects(OdDbSectionSettings::SectionType nSecType,
    const OdDbObjectIdArray& ids);

  OdDbObjectId destinationBlock(OdDbSectionSettings::SectionType nSecType) const;
  OdResult setDestinationBlock(OdDbSectionSettings::SectionType nSecType,
    const OdDbObjectId& id);

  const OdChar * destinationFile(OdDbSectionSettings::SectionType nSecType) const;
  OdResult setDestinationFile(OdDbSectionSettings::SectionType nSecType,
    const OdChar * pszFileName);

  bool  visibility(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setVisibility(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    bool bVisible);
  OdCmColor color(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  // Gcad(Modify): void->OdResult
  OdResult setColor(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    const OdCmColor& color);
  const OdChar * layer(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setLayer(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    const OdChar * pszLayer);
  const OdChar * linetype(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setLinetype (OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    const OdChar * pszLinetype);
  double linetypeScale(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setLinetypeScale(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    double fScale);
  const OdChar * plotStyleName(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setPlotStyleName(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    const OdChar * pszPlotStyleName);
  OdDb::LineWeight lineWeight(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setLineWeight(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    OdDb::LineWeight nLineWeight);
  int   faceTransparency(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setFaceTransparency(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    int nTransparency);
  int   edgeTransparency(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setEdgeTransparency(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    int nTransparency);
  bool  hatchVisibility(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setHatchVisibility(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    bool bVisible);
  void getHatchPattern(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    OdDbHatch::HatchPatternType& nPatternType, 
    OdString& pszPatternName) const;
  OdResult getHatchPattern(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    OdDbHatch::HatchPatternType& nPatternType, 
    const OdChar*& pszPatternName) const;
  OdResult setHatchPattern(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    OdDbHatch::HatchPatternType nPatternType, 
    const OdChar * pszPatternName);
  double hatchAngle(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setHatchAngle(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    double fAngle);
  double hatchSpacing(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setHatchSpacing(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    double fSpacing);
  double hatchScale(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setHatchScale(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    double fScale);
  bool  hiddenLine(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setHiddenLine(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    bool bHiddenLine);
  bool  divisionLines(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry) const;
  OdResult setDivisionLines(OdDbSectionSettings::SectionType nSecType, 
    OdDbSectionSettings::Geometry nGeometry, 
    bool bShow);
};


#include "TD_PackPop.h"

#endif //_OdDbSection_h_Included_
