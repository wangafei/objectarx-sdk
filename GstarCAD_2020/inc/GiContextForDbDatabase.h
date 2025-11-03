/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef _ODGI_CONTEXTFORDBDATABASE_INCLUDED_
#define _ODGI_CONTEXTFORDBDATABASE_INCLUDED_

#include "GiDefaultContext.h"
#include "DbExport.h"
#include "OdPlatform.h"
#include "StaticRxObject.h"
#include "DbDatabase.h"
#include "DbDatabaseReactor.h"
#include "Ps/PlotStyles.h"
#include "Gi/GiSubEntityTraitsData.h"
#include "Gi/GiLinetyper.h"

#include "TD_PackPush.h"

struct OdGsClientViewInfo;



/** Description:
    This class defines the operations and properties that are used in the
    Teigha vectorization of an OdDbDatabase.

    Library: TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdGiContextForDbDatabase : public OdGiDefaultContext
{
private:
  enum
  {
    kPlotGeneration                  = 1,
    kUseGsModel                      = 2,
    kOdGiZeroTextNormals             = 4,
    kDisableLayoutHelperLinkReactors = 8,
    kTTFPolyDraw                     = 16,
    kTrackDbDestroy                  = 32,
    kIgnoreTTFHeight                 = 64,
    kForceDisplaySilhouettes         = 128,
    kLastFlag                        = kForceDisplaySilhouettes
  };

  OdUInt32              m_fflags;

  class TOOLKIT_EXPORT DatabaseHolder : public OdStaticRxObject<OdDbDatabaseReactor>
  {
  public:
    DatabaseHolder();
    ~DatabaseHolder();

    OdDbDatabase* m_pDb;

    void setDatabase( bool bWasTrackDbDestroy, OdDbDatabase* pDb, bool bTrackDbDestroy );

    void goodbye(const OdDbDatabase* pDb);
  }
  m_DbHolder;

protected:
  ODCOLORREF            m_paletteBackground;
  OdPsPlotStyleTablePtr m_pPlotStyleTable;

  OdGiContextForDbDatabase();

public:

  ODRX_DECLARE_MEMBERS(OdGiContextForDbDatabase);

  ~OdGiContextForDbDatabase();

  // OdGiContext overridden functions

  virtual OdDbDatabase* database() const;
  virtual OdGiDrawablePtr openDrawable(OdDbStub* drawableId);
  virtual OdUInt32 numberOfIsolines() const;
  virtual double commonLinetypeScale() const;
  virtual OdDb::LineWeight defaultLineWeight() const;
  virtual bool quickTextMode() const;
  virtual OdUInt32 textQuality() const;
  virtual ImageQuality imageQuality() const;
  virtual OdUInt32 fadingIntensityPercentage() const;
  virtual bool ttfPolyDraw() const;
  virtual OdUInt32 displaySilhouettes() const;

  /** Description:
    Sets the *database* to be vectorized.

    Arguments:
    pDb (I) Pointer to the *database*.
    bTrackDbDestroy (I) if to the *database* is not NULL then
    this parameter specifies if implementation should track database lifetime
    (by adding reactor to the *database* and processing OdDbDatabaseReactor::goodbye() event)
    and to clear pointer to the *database* if it will be destroyed. If you sure that lifetime of this object
    is shorter then lifetime of the *database* you may set this parameter to false
    to turn off unnecessary database lifetime tracking.
  */
  void setDatabase( OdDbDatabase* pDb, bool bTrackDbDestroy = true );

  /** Description:
    Returns the *database* that is currently being vectorized.
  */
  OdDbDatabase* getDatabase() const;

  /** Description:
    Returns the OdGsClientViewInfo for the specified viewport.
    Arguments:
    vpId (I) Object ID of the viewport.
    viewInfo (O) Receives the client view info.
  */
  virtual void fillGsClientViewInfo(const OdDbObjectId& vpId, OdGsClientViewInfo& viewInfo);

  /** Description:
  Returns the OdDbStub for the specified handle id.
  Arguments:
  objectId (I) Object ID of the object.
  Returns the pointer to OdDbStub.
  */
  virtual OdDbStub* getStubByID( OdUInt64 objectId ) const;

  virtual void getDefaultTextStyle(OdGiTextStyle& textStyle);

  unsigned int circleZoomPercent(OdDbStub* viewportId) const;

  /** Description:
    Returns true if and only the GsModel flag of this Context Object is set..
  */
  bool useGsModel() const;

  /** Description:
    Controls the GsModel flag of this Context Object.
    Arguments:
    enable (I) Controls the Gs Model.
  */
  void enableGsModel(bool enable);

  /** Description:
    Returns true if and only the PlotGeneration flag of this Context Object is set.
  */
  OdBool isPlotGeneration() const;

  /** Description:
    Controls the PlotGeneration flag of this Context Object.
    Arguments:
    plotGeneration (I) Controls plot generation.
  */
  void setPlotGeneration(bool plotGeneration);

  /** Description:
    Returns true if and only the kOdGiZeroTextNormals flag of this Context Object is set.
  */
  virtual bool isZeroTextNormals() const;

  /** Description:
    Controls the ZeroTextNormals flag of this Context Object.
    Arguments:
    bZeroTextNormals (I) Controls text normals generation.
  */
  void setZeroTextNormals(bool bZeroTextNormals);

  /** Description:
    Returns true if and only the kDisableLayoutHelperLinkReactors flag of this Context Object is set.
  */
  bool isLayoutHelperLinkRectorsDisabled() const;

  /** Description:
    Controls the kDisableLayoutHelperLinkReactors flag of this Context Object.
    Arguments:
    bDisableLinkReactors (I) Controls layout link reactors flag.
  */
  void disableLayoutHelperLinkRectors(bool bDisableLinkReactors);

  /** Description:
    Enables TrueType text contours info output.
    Arguments:
    bPolyDraw (I) Controls kTTFPolyDraw flag of this Context Object.
  */
  void setTtfPolyDrawMode(bool bPolyDraw);

  /** \details
    Returns current state of display silhouettes forcing mode.
  */
  bool isForceDisplaySilhouettesEnabled() const;

  /** \details
    Sets current state of display silhouettes forcing mode.
    \param bOn [in]  Enable or disable display silhouettes forcing.
  */
  void setForceDisplaySilhouettes(bool bOn);

  bool fillTtf() const;

  void setIgnoreTTFHeight(bool bIgnore);
  bool isIgnoreTTFHeight() const;

  /** Description:
    Returns the palette background color for this Context object.
  */
  ODCOLORREF paletteBackground() const { return m_paletteBackground; }
  /** Description:
    Sets the palette background color for this Context object.
    Arguments:
    paletteBackground (I) Palette background.
  */
  void setPaletteBackground(ODCOLORREF paletteBackground) { m_paletteBackground = paletteBackground; }

  /** Description:
    Loads the specified plot style table for this Context object.
    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
  */
  void loadPlotStyleTable(OdStreamBuf* pStreamBuf);
  
  /** Description:
    Returns the plot style type for this Context object.
  */
  virtual PStyleType plotStyleType() const;

  /** Description:
    Returns the plot style data for the specified pen number or object Id.
    Arguments:
    penNumber (I) Pen number.
    psNameId (I) Object id of the plot style name.
    plotStyleData (O) Receives the plot style data.
  */
  virtual void plotStyle(int penNumber, OdPsPlotStyleData& plotStyleData) const;

  virtual void plotStyle(OdDbStub* psNameId, OdPsPlotStyleData& plotStyleData) const;

  enum SolidHatchAsPolygonMode
  {
    kHatchTriangulation, //no polygons (default rendering)
    kHatchPolygon, //polygons only
    kHatchBoth, //triangulation and polygons
    kHatchPolygonSLoop
  };
  /** Description:
  Returns SolidHatchAsPolygonMode set for this Context Object.
  */
  SolidHatchAsPolygonMode hatchAsPolygon() const;

  /** Description:
  Controls SolidHatchAsPolygonMode of this Context Object.
  Arguments:
  bOn (I) Controls hatch as polygon generation.
  */
  void setHatchAsPolygon(SolidHatchAsPolygonMode mode);

  void releasePlotStyleTable();

  /** \details
    Returns an interface for access section geometry functionality.
  */
  virtual OdGiSectionGeometryManagerPtr getSectionGeometryManager();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiContextForDbDatabase object pointers.
*/
typedef OdSmartPtr<OdGiContextForDbDatabase> OdGiContextForDbDatabasePtr;


#include "TD_PackPop.h"

#endif //_ODGI_CONTEXTFORDBDATABASE_INCLUDED_
