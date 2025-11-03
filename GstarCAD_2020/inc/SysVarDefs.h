///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance").
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
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance.
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




//$ACADVER  AC1015
//short ACADMAINTVER     6


#ifndef RO_VAR_DEF
#define RO_VAR_DEF  VAR_DEF /* {Secret} */
#define DOUNDEF_RO_VAR_DEF
#endif

#ifndef RO_VAR_DEF_H
#define RO_VAR_DEF_H  RO_VAR_DEF /* {Secret} */
#define DOUNDEF_RO_VAR_DEF_H
#endif

#ifndef VAR_DEF_H
#define VAR_DEF_H  VAR_DEF /* {Secret} */
#define DOUNDEF_VAR_DEF_H
#endif

#ifndef DICR15VAR
#define DOUNDEF_DICR15VAR
#define DICR15VAR  VAR_DEF /* {Secret} */
#endif

#ifndef DICR21VAR
#define DOUNDEF_DICR21VAR
#define DICR21VAR  VAR_DEF /* {Secret} */
#define DOUNDEF_DICR21VAR_H
#define DICR21VAR_H VAR_DEF_H /* {Secret} */
#else
#define DOUNDEF_DICR21VAR_H
#define DICR21VAR_H DICR21VAR /* {Secret} */
#endif

#ifndef DICR24VAR
#define DOUNDEF_DICR24VAR
#define DICR24VAR  DICR21VAR /* {Secret} */
#define DOUNDEF_DICR24VAR_H
#define DICR24VAR_H DICR21VAR_H /* {Secret} */
#else
#define DOUNDEF_DICR24VAR_H
#define DICR24VAR_H DICR24VAR /* {Secret} */
#endif

#ifndef DICR27VAR
#define DOUNDEF_DICR27VAR
#define DICR27VAR DICR21VAR /* {Secret} */
#define DOUNDEF_DICR27VAR_H
#define DICR27VAR_H DICR21VAR_H /* {Secret} */
#else
#define DOUNDEF_DICR27VAR_H
#define DICR27VAR_H DICR27VAR /* {Secret} */
#endif

#ifndef ANNO_VAR_DEF
#define DOUNDEF_ANNO_VAR_DEF
#define ANNO_VAR_DEF DICR21VAR  /* {Secret} */
#endif

#ifndef VAR_DEF_2
#define DOUNDEF_VAR_DEF_2
#define VAR_DEF_2  VAR_DEF /* {Secret} */
#endif

#ifndef ODTBOOL
#define ODTBOOL                 bool                    /* {Secret} */
#endif

#ifndef ODTDIST
#define ODTDIST                 double                  /* {Secret} */
#endif

#ifndef ODTORIENT
#define ODTORIENT               double                  /* {Secret} */
#endif

#ifndef ODTUNITLESS4
#define ODTUNITLESS4            double                  /* {Secret} */
#endif

#ifndef ODTUNITLESS8
#define ODTUNITLESS8            double                  /* {Secret} */
#endif

#ifndef ODTDB_MEASUREMENTVALUE
#define ODTDB_MEASUREMENTVALUE  OdDb::MeasurementValue  /* {Secret} */
#endif

#ifndef ODTDB_LINEWEIGHT
#define ODTDB_LINEWEIGHT        OdDb::LineWeight        /* {Secret} */
#endif

#ifndef ODTDB_JOINSTYLE
#define ODTDB_JOINSTYLE         OdDb::JoinStyle         /* {Secret} */
#endif

#ifndef ODTDB_UNITSVALUE
#define ODTDB_UNITSVALUE        OdDb::UnitsValue        /* {Secret} */
#endif

#ifndef ODTDB_PROXYIMAGE
#define ODTDB_PROXYIMAGE        OdDb::ProxyImage        /* {Secret} */
#endif

#ifndef ODTDB_MEASUREMENTVALUE
#define ODTDB_MEASUREMENTVALUE  OdDb::MeasurementValue  /* {Secret} */
#endif

#ifndef ODTDB_ENDCAPS
#define ODTDB_ENDCAPS           OdDb::EndCaps           /* {Secret} */
#endif

#ifndef ODTDB_JOINSTYLE
#define ODTDB_JOINSTYLE         OdDb::JoinStyle         /* {Secret} */
#endif

#ifndef ODTDB_PLOTSTYLENAMETYPE
#define ODTDB_PLOTSTYLENAMETYPE OdDb::PlotStyleNameType /* {Secret} */
#endif

#ifndef ODDBOBJECTID
#define ODDBOBJECTID            OdDbObjectId            /* {Secret} */
#endif

#ifndef ODDBHARDPOINTERID
#define ODDBHARDPOINTERID       ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTTEXTSTYLEID
#define ODTTEXTSTYLEID          ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTLAYERID
#define ODTLAYERID              ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTLINETYPEID
#define ODTLINETYPEID           ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTDIMSTYLEID
#define ODTDIMSTYLEID           ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTUCSID
#define ODTUCSID                ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTMLSTYLEID
#define ODTMLSTYLEID            ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTDB_TIMEZONE
#define ODTDB_TIMEZONE          OdDb::TimeZone         /* {Secret} */
#endif

#ifndef ODTDB_SHADOWFLAGS
#define ODTDB_SHADOWFLAGS       OdGiSubEntityTraits::ShadowFlags      /* {Secret} */
#endif

#ifndef ODVISTYLEID
#define ODVISTYLEID             ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTMATERIALID
#define ODTMATERIALID           ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTDB_LOFTPARAMTYPE
#define ODTDB_LOFTPARAMTYPE     OdDb::LoftParamType      /* {Secret} */
#endif

#ifndef ODTDB_LOFTNORMALSTYPE
#define ODTDB_LOFTNORMALSTYPE   OdDb::LoftNormalsType      /* {Secret} */
#endif

#ifndef ODTTABLESTYLEID
#define ODTTABLESTYLEID         ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTMLEADERSTYLEID
#define ODTMLEADERSTYLEID       ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTVIEWDETAILSTYLEID
#define ODTVIEWDETAILSTYLEID    ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODTVIEWSECTIONSTYLEID
#define ODTVIEWSECTIONSTYLEID   ODDBOBJECTID            /* {Secret} */
#endif

#ifndef ODANNOSCALE
#define ODANNOSCALE             OdDbAnnotationScalePtr /* {Secret} */
#endif

#ifndef VAR_DEF
/* {Secret} */
#define VAR_DEF(a,b,c,d,r1,r2)
/* {Secret} */
#define DOUNDEF_VAR_DEF
#endif

//         Type                    Name          Default                         Metric default                    Reserve1                    Reserve2

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ANGBASE specifies the direction of angle 0 with respect to the UCS."
    </remarks>
    <notes>
      "\n   All angles are expressed in radians."
    </notes>
  </properties>
*/
VAR_DEF(   ODTORIENT,              ANGBASE,      (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ANGDIR controls the direction of positive angles with respect to the UCS.
      "\n"
      "\n    @table"
      "\n    Value       Positive Angles"
      "\n    false       Counterclockwise"
      "\n    true        Clockwise
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                ANGDIR,       (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INSBASE specifies the WCS insertion base point of model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            INSBASE,      (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXTMIN specifies the lower-left corner of the extents of model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            EXTMIN,       (1.E+20, 1.E+20, 1.E+20),       (1.E+20, 1.E+20, 1.E+20),         (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXTMAX specifies the upper-right corner of the extents of model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            EXTMAX,       (-1.E+20, -1.E+20, -1.E+20),    (-1.E+20, -1.E+20, -1.E+20),      (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LIMMIN specifies the lower-left corner of the grid limits for model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint2d,            LIMMIN,       (0.0, 0.0),                     (0.0, 0.0),                       (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LIMMAX specifies the upper-right corner of the grid limits for model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint2d,            LIMMAX,       (12.0, 9.0),                    (420.0, 297.0),                   (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ORTHOMODE controls the constraint of cursor movement to the perpendicular."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not constrained"
      "\n    true     Constrained"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                ORTHOMODE,    (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    REGENMODE controls automatic regeneration."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"

    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                REGENMODE,    (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FILLMODE controls the rendering of Hatches, 2D Solids, and wide Polylines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                FILLMODE,     (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    QTEXT controls the display of text.
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Text is displayed"
      "\n    true     Bounding box is displayed"

    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                QTEXTMODE,    (false),                        (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MIRRTEXT controls the mirroring of Text with the MIRROR command."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not mirrored"
      "\n    true     Mirrored"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                MIRRTEXT,     (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LTSCALE specifies the global linetype scale factor."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUNITLESS4,           LTSCALE,      (1.0),                          (1.0),                            (),                         ValidatePositiveNonZero())
/*** VARDOCS:
<properties>
    <remarks>
      "\n    ATTMODE controls the display of attributes."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        All attributes are invisible."
      "\n    1        Visible attributes are visible, and invisible, invisible."
      "\n    2        All attributes are visible."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                ATTMODE,      (1),                            (1),                              (),                         ValidateRange(0,2))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TEXTSIZE specifies the default size for new text entities in the current text style."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                TEXTSIZE,     (0.2),                          (2.5),                            (),                         ValidateGr(0.))


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TRACEWID is default width for new trace entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                TRACEWID,     (0.05),                         (1.0),                            (),                         ValidateEqGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TEXTSTYLE specifies the default style for new text entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTTEXTSTYLEID,         TEXTSTYLE,    (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateTextStyle())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CLAYER specifies the default layer for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTLAYERID,             CLAYER,       (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateLayer())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CELTYPE specifies the default linetype for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTLINETYPEID,          CELTYPE,      (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateLinetype())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CECOLOR specifies the default color for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   OdCmColor,              CECOLOR,      (OdCmEntityColor::kByLayer),    (OdCmEntityColor::kByLayer),      (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CELTSCALE specifies the default linetype scale for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUNITLESS4,           CELTSCALE,    (1.0),                          (1.0),                            (),                         ValidateGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CHAMFERA specifies the default first chamfer distance."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                CHAMFERA,     (0.0),                          (0.0),                           (),                         ValidateEqGr(0.))
/*** VARDOCS:
<properties>
  <remarks>
      "\n    CHAMFERB specifies the default second chamfer distance."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                CHAMFERB,     (0.0),                          (0.0),                           (),                         ValidateEqGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CHAMFERC specifies the default chamfer length."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                CHAMFERC,     (0.0),                          (0.0),                           (),                         ValidateEqGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CHAMFERD specifies the default chamfer angle."
    </remarks>
    <note>
      "\n    All angles are expressed in radians."
    </note>
  </properties>
*/
VAR_DEF(   ODTORIENT,              CHAMFERD,     (0.0),                          (0.0),                            (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DISPSILH controls the display of silhouette curve edges and meshes."
      "\n"
      "\n    @table"
      "\n    Value    Curve Edges       Meshes"
      "\n    false    Not displayed     Displayed"
      "\n    true     Displayed         Not displayed"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                DISPSILH,     (false),                        (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMSTYLE specifies the default dimension style for new entities."
    </remarks>
  </properties>
*/
RO_VAR_DEF(ODTDIMSTYLEID,          DIMSTYLE,     (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateDimStyle())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMASO controls the creation of dimension objects."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Creates exploded dimensions (lines, arrowheads, text as separate entities."
      "\n    true    Creates single dimension entity."
    </remarks>
    <notes>
      "\n    DIMASO is depreciated, but is included for compatibility purposes."
    </notes>
  </properties>
*/
VAR_DEF(   ODTBOOL,                   DIMASO,       (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMSHO controls the updating of associative dimension objects while dragging.
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Disabled"
      "\n    true    Enabled"
    </remarks>
    <notes>
      "\n    DIMSHO is depreciated, but is included for compatibility purposes."
    </notes>
  </properties>
*/
VAR_DEF(   bool,                   DIMSHO,       (true),                         (true),                           (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LUNITS controls the display of linear units."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    1         Scientific"
      "\n    2         Decimal"
      "\n    3         Engineering"
      "\n    4         Architectural"
      "\n    5         Fractional"
    </remarks>
    <notes>
      "\n    LUNITS does not control the formatting of dimension text."
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                LUNITS,       (2),                            (2),                              (),                         ValidateRange(1,5))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LUPREC specifies the number of decimal places in the display of linear units."
    </remarks>
    <notes>
      "\n    LUPREC does not control the formatting of dimension text."
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                LUPREC,       (4),                            (4),                              (),                         ValidateRange(0,8))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SKETCHINC specifies the recording increment for the SKETCH command."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                SKETCHINC,    (0.1),                          (1.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FILLETRAD specifies the default fillet radius."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                FILLETRAD,    (0.5),                          (10.0),                           (),                         ValidateEqGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    AUNITS controls the display of angular units."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    0         Degrees"
      "\n    1         Degrees-Minutes-Seconds"
      "\n    2         Gradians"
      "\n    3         Radians"
      "\n    4         Surveyor Units"
    </remarks>
    <notes>
      "\n    AUNITS does not control the formatting of dimension text."
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                AUNITS,       (0),                            (0),                              (),                         ValidateRange(0,4))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    AUPREC specifies the number of decimal places in the display of angular units."
    </remarks>
    <notes>
      "\n    AUPREC does not control the formatting of display of dimension text."
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                AUPREC,       (0),                            (0),                              (),                         ValidateRange(0,8))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MENUNAME returns the path and filename of the customization file."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdString,               MENUNAME,     (OD_T(".")),                          (OD_T(".")),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ELEVATION specifies the default elevation for new entities in model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTDIST,                ELEVATION,    (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PELEVATION specifies the default elevation for new entities in the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTDIST,                PELEVATION,   (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    THICKNESS specifies the default 3D thickness for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                THICKNESS,    (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LIMCHECK controls the specification of objects in model space by points outside the grid limits of"
      " model space.
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Points outside limits allowed"
      "\n    true      Points outside limits disallowed"
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTBOOL,                   LIMCHECK,     (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SKPOLY controls the generation of polylines during the SKETCH command."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Generates Lines."
      "\n    true    Generates Polylines."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                SKPOLY,       (false),                        (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TDUCREATE represents the time and date, in Universal Time, that the *database* was created."
    </remarks>
    <see_also>
      "\n    odDbSetTDUCREATE"
    </see_also>
  </properties>
*/
RO_VAR_DEF(OdDbDate,               TDUCREATE,    (OdDbDate::kInitZero),          (OdDbDate::kInitZero),            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TDUUPDATE represents the time and date, in Universal Time, that the *database* was last saved."
    </remarks>
    <see_also>
      "\n    odDbSetTDUUPDATE"
    </see_also>
  </properties>
*/
RO_VAR_DEF(OdDbDate,               TDUUPDATE,    (OdDbDate::kInitZero),          (OdDbDate::kInitZero),            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TDINDWG represents the total editing time of the database."
    </remarks>
    <see_also>
      "\n    odDbSetTDINDWG"
    </see_also>
  </properties>
*/
RO_VAR_DEF(OdDbDate,               TDINDWGSTART,      (OdDbDate::kInitZero),          (OdDbDate::kInitZero),            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TDUSRTIMER represents the user-elapsed timer."
    </remarks>
    <see_also>
      "\n    odDbSetTDUSRTIMER"
    <see_also>
  </properties>
*/
RO_VAR_DEF(OdDbDate,               TDUSRTIMERSTART,   (OdDbDate::kInitZero),          (OdDbDate::kInitZero),            (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    USRTIMER controls the user elapsed timer."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Disabled"
      "\n    true      Enabled"
    </remarks>
  </properties>
*/
//VAR_DEF_H( bool,                   USRTIMER,     (true),                         (true),                           (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PDMODE specifies the display of Point entities."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                PDMODE,       (0),                            (0),                              (),                         ValidatePDMODE())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PDSIZE specifies the display size of point entities."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    < 0       Fraction of viewport size in drawing units."
      "\n    0         5% of viewport size in drawing units."
      "\n    > 0       Size in drawing units."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                PDSIZE,       (0.0),                          (0.0),                            (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLINEWID specifies the default width for new Polyline entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDIST,                PLINEWID,     (0.0),                          (0.0),                            (),                         ValidatePositive())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SPLFRAME controls the display of control polygons for Splines and spline-fit Polylines."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Disabled"
      "\n    true      Enabled"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                SPLFRAME,     (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SPLINETYPE specifies the type of spline generated by the PEDIT/Spline command."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    5         Quadratic B-spline."
      "\n    6         Cubic B-spline."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SPLINETYPE,   (6),                            (6),                              (),                         ValidateRange(5,6))


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SPLINESEGS specifies the number of segments generated by the PEDIT/Spline command."
      "\n"
      "\n    Negative values produce arc segments, while positive values generate line segments."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SPLINESEGS,   (8),                            (8),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
      <remarks>
        "\n    SURFTAB1 specifies the number of tabulations generated in the M direction by the"
        " EDGESURF, REVSURF, RULESURF, and TABSURF commands."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SURFTAB1,     (6),                            (6),                              (),                         ValidateRange(2,32766))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SURFTAB2 specifies the number of tabulations generated in the N direction by the EDGESURF and REVSURF commands."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SURFTAB2,     (6),                            (6),                              (),                         ValidateRange(2,32766))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SURFTYPE specifies the type of surface fitting for the PEDIT/Smooth command."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    5         Quadratic B-spline surface."
      "\n    6         Cubic B-spline surface"
      "\n    8         Bezier surface."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SURFTYPE,     (6),                            (6),                              (),                         ValidateRange(5,8))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SURFU specifies the surface density in the M direction for the PEDIT/Smooth command."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SURFU,        (6),                            (6),                              (),                         ValidateRange(0,200))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SURFV specifies the surface density in the N direction for the PEDIT/Smooth command."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SURFV,        (6),                            (6),                              (),                         ValidateRange(0,200))

/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERI1 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                USERI1,       (0),                            (0),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERI2 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                USERI2,       (0),                            (0),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERI3 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                USERI3,       (0),                            (0),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERI4 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                USERI4,       (0),                            (0),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERI5 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                USERI5,       (0),                            (0),                              (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERR1 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   ODTDIST,                USERR1,       (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERR2 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   ODTDIST,                USERR2,       (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERR3 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   ODTDIST,                USERR3,       (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERR4 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   ODTDIST,                USERR4,       (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <notes>
      "\n    USERR5 is 'reserved for user applications.'"
    </notes>
  </properties>
*/
VAR_DEF(   ODTDIST,                USERR5,       (0.0),                          (0.0),                            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    WORLDVIEW controls the switching of the UCS to the WCS for the duration of the"
      "3DORBIT, DVIEW and VPOINT commands."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    UCS is unchanged."
      "\n    true     UCS switches to WCS."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                WORLDVIEW,    (true),                         (true),                           (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SHADEDGE specifies the rendering of faces and edges with the SHADE command."
      "\n"
      "\n    @table"
      "\n    Value    Faces           Edges"
      "\n    0        Shaded          Not highlighted"
      "\n    1        Shaded          Background color"
      "\n    2        Not filled      Object Color"
      "\n    3        Object color    Background Color"
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SHADEDGE,     (3),                            (3),                              (),                         ValidateRange(0,3))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SHADEDIF specifies the percentage of diffuse reflective light (vs. ambient light)"
      " when (SHADEDGE == 0) || (SHADEDGE == 1)."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                SHADEDIF,     (70),                           (70),                             (),                         ValidateRange(0,100))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TILEMODE controls the active tab."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     A Layout tab is active."
      "\n    true      The Model tab is active."
      </remarks>
    <notes>
      "\n    The last active Layout tab will be activated when TILEMODE is changed from true to false."
    </notes>
  </properties>
*/
VAR_DEF_2( ODTBOOL,                TILEMODE,     (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MAXACTVP specifies the maximum of active viewports in a layout."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                MAXACTVP,     (64),                           (64),                             (),                         ValidateRange(2,64))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PINSBASE specifies the WCS insertion base point of the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PINSBASE,     (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLIMCHECK controls the specification of objects in paper space by points outside the grid limits of"
      " the current paper space.
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Points outside limits allowed"
      "\n    true      Points outside limits disallowed"
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTBOOL,                PLIMCHECK,    (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PEXTMIN specifies the lower-left corner of the extents of the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PEXTMIN,      (1.E+20, 1.E+20, 1.E+20),       (1.E+20, 1.E+20, 1.E+20),         (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PEXTMAX specifies the upper-right corner of the extents of the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PEXTMAX,      (-1.E+20, -1.E+20, -1.E+20),    (-1.E+20, -1.E+20, -1.E+20),      (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLIMMIN specifies the lower-left corner of the grid limits for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint2d,            PLIMMIN,      (0.0, 0.0),                     (0.0, 0.0),                       (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLIMMAX specifies the upper-right corner of the grid limits for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint2d,            PLIMMAX,      (12.0, 9.0),                    (420.0, 297.0),                   (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSNAME specifies the current UCS for the current viewport of model space."
    </remarks>
  </properties>
*/
VAR_DEF_H( ODDBHARDPOINTERID,      UCSNAME,      (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateUcsRec())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSNAME specifies the current UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( ODDBHARDPOINTERID,      PUCSNAME,     (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateUcsRec())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UNITMODE specifies the unit display format for Architectural Units and Surveyor's Units."
      "\n"
      "\n    @table"
      "\n    Value    Architectural Units      Surveyor's Units"
      "\n    0        12'-5 1/4\"               N 48d0'0\" E"
      "\n    1        12'5-1/4\"                N48d0'0\"E"
      "\n"
      "\n    When UNITMODE = 1, the displayed units are in a format suitable for input."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                UNITMODE,     (0),                            (0),                              (),                         ValidateRange(0,1))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    VISRETAIN specifies the precedence of layer settings for externally referenced databases."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Settings are saved in the external reference."
      "\n    true     Settings are saved in the current *database*."
      "\n"
      "\n    Layer settings include color, linetype, lineweight, plot styles, on/off and freeze/thaw"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                VISRETAIN,    (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLINEGEN controls the generation of linetypes for Polylines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Each segment starts and ends in a dash."
      "\n    true     Linetype generation is continuous, ignoring the vertices."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                PLINEGEN,     (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PSLTSCALE controls the generation of linetypes for Polylines in paper space."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Dash lengths in model space are based on model space drawing units."
      "\n    true     Dash lengths in model space are based on paper space drawing units."
      "\n"
      "\n    When PSLTSCALE is true, linetypes in viewports will appear the same size as those in paper space."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                PSLTSCALE,    (true),                         (true),                           (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TREEDEPTH specifies depth of the spatial index."
      "\n"
      "\n"   Spatial indexing, along with layer indexing, is used to maximize performance"
      " of demand loading and entity selection."
      "\n"
      "\n    @table"
      "\n    Value         Description"
      "\n    < 0           2D indexing. An integer in the form -MMMPP specifies the depths for model space (MMM) and paper space (PP)"
      "\n    0             Disables spatial indexing."
      "\n    > 0           3D indexing. An integer in the form MMMPP specifies the depths for model space (MMM) and paper space (PP)."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                TREEDEPTH,    (3020),                         (3020),                           (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CMLSTYLE specifies the default style for new multiline entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTMLSTYLEID,           CMLSTYLE,     (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateMLStyle())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CMLJUST specifies the default justification for new multiline entities."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Top"
      "\n    1        Middle"
      "\n    2        Bottom"
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt16,                CMLJUST,      (0),                            (0),                              (),                         ValidateRange(0,2))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CMLSCALE specifies the default width scale for new multiline entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUNITLESS4,           CMLSCALE,     (1.0),                          (20.0),                           (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PROXYGRAPHICS controls the saving of proxy images with the *database*."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        No proxy images."
      "\n    1        Proxy images saved with *database*."
    </remarks>
    <notes>
      "\n    PROXYGRAPHICS is called SAVEIMAGES in R13."
    </notes>
  </properties>
*/
VAR_DEF(   OdInt16,                PROXYGRAPHICS,(1),                            (1),                              (),                         ValidateRange(0,1))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MEASUREMENT controls the use of metric vs. imperial linetype and hatch pattern files."
      "\n"
      "\n    @table"
      "\n    Name             Value    Registry Settings Used       Default Settings"
      "\n    OdDb::kEnglish   0        ANSILinetype & ANSIHatch     acad.lin & acad.pat"
      "\n    OdDb::kMetric    1        ISOLinetype & ISOHatch.      acadiso.lin & acadiso.pat"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDB_MEASUREMENTVALUE, MEASUREMENT,  (OdDb::kEnglish),               (OdDb::kMetric),                  (),                         ValidateRange(OdDb::kEnglish,OdDb::kMetric))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CELWEIGHT specifies the default lineweight for new entities."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDB_LINEWEIGHT,       CELWEIGHT,    (OdDb::kLnWtByLayer),           (OdDb::kLnWtByLayer),             (),                         ValidateLineWeight())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ENDCAPS specifies the lineweight endcaps for new entities."
      "\n"
      "\n    @table"
      "\n    Name                   Value   Description"
      "\n    OdDb::kEndCapNone      0       None"
      "\n    OdDb::kEndCapRound     1       Round"
      "\n    OdDb::kEndCapAngle     2       Angle"
      "\n    OdDb::kEndCapSquare    3       Square"
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTDB_ENDCAPS,          ENDCAPS,      (OdDb::kEndCapNone),            (OdDb::kEndCapNone),              (),                         ValidateRange(OdDb::kEndCapNone, OdDb::kEndCapSquare))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    JOINSTYLE specifies the lineweight join style for new entities."
      "\n"
      "\n    @table"
      "\n    Name                   Value   Description"
      "\n    OdDb::kJnStylNone      0       None"
      "\n    OdDb::kJnStylRound     1       Round"
      "\n    OdDb::kJnStylAngle     2       Angle"
      "\n    OdDb::kJnStylFlat      3       Flat"
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTDB_JOINSTYLE,        JOINSTYLE,    (OdDb::kJnStylNone),            (OdDb::kJnStylNone),              (),                         ValidateRange(OdDb::kJnStylNone,OdDb::kJnStylFlat))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LWDISPLAY controls the display of lineweights."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not displayed."
      "\n    true     Displayed."
    </remarks>
  </properties>
*/
VAR_DEF(   bool,                   LWDISPLAY,    (false),                        (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INSUNITS specifies the drawing units used in the automatic scaling of blocks,"
      " Xrefs, and images inserted into or attached to this *database*."
      "\n"
      "\n    @table"
      "\n    Name                       Value        Description"
      "\n    OdDb::kUnitsUndefined      0            Undefined"
      "\n    OdDb::kUnitsInches         1            Inches"
      "\n    OdDb::kUnitsFeet           2            Feet"
      "\n    OdDb::kUnitsMiles          3            Miles"
      "\n    OdDb::kUnitsMillimeters    4            Millimeters"
      "\n    OdDb::kUnitsCentimeters    5            Centimeters"
      "\n    OdDb::kUnitsMeters         6            Meters"
      "\n    OdDb::kUnitsKilometers     7            Kilometers"
      "\n    OdDb::kUnitsMicroinches    8            Microinches"
      "\n    OdDb::kUnitsMils           9            Mils"
      "\n    OdDb::kUnitsYards          10           Yards"
      "\n    OdDb::kUnitsAngstroms      11           Angstroms"
      "\n    OdDb::kUnitsNanometers     12           Nanometers"
      "\n    OdDb::kUnitsMicrons        13           Microns"
      "\n    OdDb::kUnitsDecimeters     14           Decimeters"
      "\n    OdDb::kUnitsDekameters     15           Dekameters"
      "\n    OdDb::kUnitsHectometers    16           Hectometers"
      "\n    OdDb::kUnitsGigameters     17           Gigameters"
      "\n    OdDb::kUnitsAstronomical   18           Astronomical"
      "\n    OdDb::kUnitsLightYears     19           LightYears"
      "\n    OdDb::kUnitsParsecs        20           Parsecs"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTDB_UNITSVALUE,       INSUNITS,     (OdDb::kUnitsInches),           (OdDb::kUnitsMillimeters),        (),                         ValidateRange(OdDb::kUnitsUndefined,OdDb::kUnitsMax))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TSTACKALIGN controls the alignment of stacked text."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Bottom"
      "\n    1       Center"
      "\n    2       Top"
    </remarks>
  </properties>
*/
VAR_DEF(   OdUInt16,               TSTACKALIGN,  (1),                            (1),                              (),                         ValidateRange(0,2))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TSTACKSIZE specifies the size of stacked text as a percentage of the current text height."
    </remarks>
  </properties>
*/
VAR_DEF(   OdUInt16,               TSTACKSIZE,   (70),                           (70),                             (),                         ValidateRange(25,125))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HYPERLINKBASE specifies the base path for relative hyperlinks in this *database*."
      "\n"
      "\n    If HYPERLINKBASE is an empty string, the *database* path is used."
    </remarks>
  </properties>
*/
VAR_DEF(   OdString,               HYPERLINKBASE,(OD_T("")),                           (OD_T("")),                             (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    STYLESHEET specifies the *name* of the style sheet for the active layout."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdString,               STYLESHEET,   (OD_T("")),                           (OD_T("")),                             (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    XEDIT controls if this *database*, when an Xref, can be edited in-place."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Not edited in-place."
      "\n    true    Edited in-place."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                XEDIT,        (true),                         (true),                           (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CEPSNTYPE specifies the plot style name type for new entities."
      "\n"
      "\n    @table"
      "\n    Name                                Value"
      "\n    OdDb::kPlotStyleNameByLayer         0"
      "\n    OdDb::kPlotStyleNameByBlock         1"
      "\n    OdDb::kPlotStyleNameIsDictDefault   2"
      "\n    OdDb::kPlotStyleNameById            3"
  </properties>
*/
VAR_DEF_H( ODTDB_PLOTSTYLENAMETYPE, CEPSNTYPE,    (OdDb::kPlotStyleNameByLayer),  (OdDb::kPlotStyleNameByLayer),    (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CEPSNID specifies the plot style for new entities when CEPSNTYPE == OdDb::kPlotStyleNameById"
  </properties>
*/
VAR_DEF_H( ODDBHARDPOINTERID,      CEPSNID,      (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidatePSName())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PSTYLEMODE specifies if this *database* is in a color-dependent or named plot style mode."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Named plot style mode."
      "\n    true    Color-dependent plot style mode."
    </remarks>
  </properties>
*/
RO_VAR_DEF(ODTBOOL,                PSTYLEMODE,   (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FINGERPRINTGUID uniquely identifies a *database*."
      "\n"
      "\n    FINGERPRINTGUID is set when the *database* is created."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdString,               FINGERPRINTGUID,(odInitFINGERPRINTGUID()),    (odInitFINGERPRINTGUID()),        (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    VERSIONGUID uniquely identifies a specific version of a *database*."
      "\n"
      "\n    VERSIONGUID is updated each time the *database* is saved.
    </remarks>
  </properties>
*/
VAR_DEF_H( OdString,               VERSIONGUID,  (odInitVERSIONGUID()),          (odInitVERSIONGUID()),            (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXTNAMES specifies if symbol tables follow the R14- or R2000+ naming conventions."
      "\n"
      "\n    @table"
      "\n    Value   Version    Length            Character Set"
      "\n    false   R14-       31 characters     [A-Z], [0-9], $, _, -"
      "\n    true    R2000+     255 characters    All except \, /, :, *, ?, \", <, >, |"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                EXTNAMES,     (true),                         (true),                           (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PSVPSCALE specifies the view scale (PS/MS) for new viewports."
      "\n"
      "\n    A scale of 0.0 specifies Scaled to Fit.
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUNITLESS8,           PSVPSCALE,    (0.0),                          (0.0),                            (),                         ValidateEqGr(0.))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    OLESTARTUP specifies if the OLE source applications load when plotting."
      " This may improve the plot quality."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Not loaded."
      "\n    true    Loaded."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                OLESTARTUP,   (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PELLIPSE specifies if polylines or ellipses are to be generated by the ELLIPSE command."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Ellipses."
      "\n    true    Polylines"
    </remarks>
  </properties>
*/
VAR_DEF(   ODTBOOL,                PELLIPSE,     (false),                        (false),                          (),                         ValidateBOOL())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ISOLINES specifies the number of isolines displayed per surface on 3D solids."
    </remarks>
  </properties>
*/
VAR_DEF(   OdUInt16,               ISOLINES,     (4),                            (4),                              (),                         ValidateRange(0,2047))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TEXTQLTY specifies the rendering quality of TrueType fonts while plotting."
    </remarks>
  </properties>
*/
VAR_DEF(   OdUInt16,               TEXTQLTY,     (50),                           (50),                             (),                         ValidateRange(0,100))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FACETRES specifies the quality of hidden, shaded, and rendered objects."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUNITLESS4,           FACETRES,     (.5),                           (.5),                             (),                         ValidateRange(0.01,10.0))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORG specifies the WCS origin of the current UCS for the current viewport in model space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGePoint3d,          UCSORG,       (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
// READ ONLY IN R2000

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSXDIR specifies the WCS x-direction of the current UCS for the current viewport in model space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGeVector3d,         UCSXDIR,      (1.0, 0.0, 0.0),                (1.0, 0.0, 0.0),                  (),                         ValidateNone())

 // READ ONLY IN R2000

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSYDIR specifies the WCS y-direction of the current UCS for the current viewport in model space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGeVector3d,         UCSYDIR,      (0.0, 1.0, 0.0),                (0.0, 1.0, 0.0),                  (),                         ValidateNone())

// READ ONLY IN R2000

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSBASE specifies the UCS that defines the"
      " orthographic UCS base for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUCSID,               PUCSBASE,     (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateUcsRec())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORG specifies the WCS origin of the current UCS of the current paper space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGePoint3d,          PUCSORG,      (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSXDIR specifies the WCS x-direction of the current UCS of the current paper space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGeVector3d,         PUCSXDIR,     (1.0, 0.0, 0.0),                (1.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSYDIR specifies the WCS y-direction of the current UCS of the current paper space."
    </remarks>
  </properties>
*/
RO_VAR_DEF_H(OdGeVector3d,         PUCSYDIR,     (0.0, 1.0, 0.0),                (0.0, 1.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORTHOVIEW specifies the orthographic UCS with respect to the base UCS for the current paper space."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Non-orthographic"
      "\n    1       Top"
      "\n    2       Bottom"
      "\n    3       Front"
      "\n    4       Back"
      "\n    5       Left"
      "\n    6       Right"
    </remarks>
  </properties>
*/
VAR_DEF_H( OdInt16,                PUCSORTHOVIEW,(0),                            (0),                              (),                         ValidateRange(0,6))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGTOP specifies the WCS origin of the top-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGTOP,   (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGBOTTOM specifies the WCS origin of the bottom-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGBOTTOM,(0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGLEFT specifies the WCS origin of the left-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGLEFT,  (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGRIGHT specifies the WCS origin of the right-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGRIGHT, (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGFRONT specifies the WCS origin of the front-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGFRONT, (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PUCSORGBACK specifies the WCS origin of the back-orthographic"
      " UCS with respect to the base UCS for the current paper space."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            PUCSORGBACK,  (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSBASE specifies the UCS that defines the orthographic UCS for model space."
    </remarks>
  </properties>
*/
VAR_DEF(   ODTUCSID,               UCSBASE,      (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                         ValidateUcsRec())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORTHOVIEW specifies the model space orthographic UCS with respect to the base UCS."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Non-orthographic"
      "\n    1       Top"
      "\n    2       Bottom"
      "\n    3       Front"
      "\n    4       Back"
      "\n    5       Left"
      "\n    6       Right"
    </remarks>
  </properties>
*/
VAR_DEF_H( OdInt16,                UCSORTHOVIEW, (0),                            (0),                              (),                         ValidateRange(0,6))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGTOP specifies the WCS origin of the model space top-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGTOP,    (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGBOTTOM specifies the WCS origin of the model space bottom-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGBOTTOM, (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGLEFT specifies the WCS origin of the model space left-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGLEFT,   (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGRIGHT specifies the WCS origin of the model space right-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGRIGHT,  (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGFRONT specifies the WCS origin of the model space front-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGFRONT,  (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSORGBACK specifies the WCS origin of the model space back-orthographic UCS with respect to the base model space UCS."
    </remarks>
  </properties>
*/
VAR_DEF_H( OdGePoint3d,            UCSORGBACK,   (0.0, 0.0, 0.0),                (0.0, 0.0, 0.0),                  (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DWGCODEPAGE specifies the system code page when the database was created."
      "\n"
      "\n    @table"
      "\n    Name            Value    Description"
      "\n    CP_UNDEFINED    0        undefined"
      "\n    CP_ASCII        1        ascii"
      "\n    CP_8859_1       2        iso8859-1"
      "\n    CP_8859_2       3        iso8859-2"
      "\n    CP_8859_3       4        iso8859-3"
      "\n    CP_8859_4       5        iso8859-4"
      "\n    CP_8859_5       6        iso8859-5"
      "\n    CP_8859_6       7        iso8859-6"
      "\n    CP_8859_7       8        iso8859-7"
      "\n    CP_8859_8       9        iso8859-8"
      "\n    CP_8859_9       10       iso8859-9"
      "\n    CP_DOS437       11       dos437"
      "\n    CP_DOS850       12       dos850"
      "\n    CP_DOS852       13       dos852"
      "\n    CP_DOS855       14       dos855"
      "\n    CP_DOS857       15       dos857"
      "\n    CP_DOS860       16       dos860"
      "\n    CP_DOS861       17       dos861"
      "\n    CP_DOS863       18       dos863"
      "\n    CP_DOS864       19       dos864"
      "\n    CP_DOS865       20       dos865"
      "\n    CP_DOS869       21       dos869"
      "\n    CP_DOS932       22       dos932"
      "\n    CP_MACINTOSH    23       mac-roman"
      "\n    CP_BIG5         24       big5"
      "\n    CP_KSC5601      25       ksc5601"
      "\n    CP_JOHAB        26       johab"
      "\n    CP_DOS866       27       dos866"
      "\n    CP_ANSI_1250    28       ansi 1250"
      "\n    CP_ANSI_1251    29       ansi 1251"
      "\n    CP_ANSI_1252    30       ansi 1252"
      "\n    CP_GB2312       31       gb2312"
      "\n    CP_ANSI_1253    32       ansi 1253"
      "\n    CP_ANSI_1254    33       ansi 1254"
      "\n    CP_ANSI_1255    34       ansi 1255"
      "\n    CP_ANSI_1256    35       ansi 1256"
      "\n    CP_ANSI_1257    36       ansi 1257"
      "\n    CP_ANSI_874     37       ansi 874"
      "\n    CP_ANSI_932     38       ansi 932"
      "\n    CP_ANSI_936     39       ansi 936"
      "\n    CP_ANSI_949     40       ansi 949"
      "\n    CP_ANSI_950     41       ansi 950"
      "\n    CP_ANSI_1361    42       ansi 1361"
      "\n    CP_ANSI_1200    43       ansi 1200"
      "\n    CP_ANSI_1258    44       ansi 1258"

    </remarks>
  </properties>
*/
RO_VAR_DEF(OdCodePageId,           DWGCODEPAGE,  (CP_ANSI_1252),                 (CP_ANSI_1252),                   (),                         ValidateNone())

//新增变量{{
DICR21VAR(   OdInt16,       MIRRHATCH,     (0),     (0),             (), ValidateRange(0,1))

VAR_DEF(	OdInt16,			  HANDLES,		 (1),			   (1),             (),ValidateRange(0,1))
//VAR_DEF(	OdInt16,			  DIMUNIT,		 (2),			   (2),             (),ValidateRange(1,8))

VAR_DEF(	OdGePoint3d,          GPSLASTPT,     (0.0, 0.0, 0.0),  (0.0, 0.0, 0.0), (),ValidateNone())
VAR_DEF(	OdInt16,			  AXISMODE,		 (0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  AXISUNIT,		 (0),			   (0),             (),ValidateRange(0,1))
//VAR_DEF(	OdInt16,			  CEPSNTYPE,	 (0),			   (0),				(),ValidateRange(0,3))
VAR_DEF(	OdInt16,			  COMPASS,		 (0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  CYCLECURR,	 (5),			   (5),             (),ValidateNone())
VAR_DEF(	OdInt16,			  CYCLEKEEP,	 (1),			   (1),             (),ValidateNone())
VAR_DEF(	OdInt16,			  FLATLAND,		 (0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  GPSMODE,		 (0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  GPSPAUSED,	 (1),			   (1),             (),ValidateRange(0,1))
VAR_DEF(	OdString,			  GPSPLAYED,      (OdString::kEmpty),(OdString::kEmpty), (),ValidateNone())
VAR_DEF(	OdInt16,			  SAVEIMAGES,		 (0),			   (0),             (),ValidateRange(0,2))

//未保存
VAR_DEF(	OdInt16,			  CMDECHO,       (1),              (1),             (),ValidateRange(0,1))
VAR_DEF(	OdGePoint3d,          LASTPOINT,     (0.0, 0.0, 0.0),  (0.0, 0.0, 0.0), (),ValidateNone())
VAR_DEF(	OdInt16,			  ERRNO,		 (0),              (0),             (),ValidateNone())
RO_VAR_DEF(	double,				  LASTANGLE,     (0),              (0),             (),ValidateNone())
VAR_DEF(	OdInt16,			  UCSICONPOS,    (0),              (0),             (),ValidateRange(0,3))
VAR_DEF(	OdInt16,			  EXPERT,		 (0),              (0),             (),ValidateRange(0,5))
RO_VAR_DEF(	OdInt16,			  DBMOD,         (0),              (0),             (),ValidateRange(0,63))
VAR_DEF(	OdInt16,			  FASTZOOM,      (1),              (1),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  AFLAGS,		 (16),             (16),             (),ValidateRange(0,63))
VAR_DEF(	double,				  TEXTANGLE,     (0),              (0),             (),ValidateNone())
VAR_DEF(	OdInt16,			  TABMODE,		 (0),              (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  ISLASTCMDPT,	 (0),              (0),             (),ValidateRange(0,1))
VAR_DEF(	OdGePoint3d,          LASTCMDPT,     (0.0, 0.0, 0.0),  (0.0, 0.0, 0.0), (),ValidateNone())
VAR_DEF(	OdInt16,			  ACISOUTVER,	 (70),             (70),             (),ValidateRange(15,120))
RO_VAR_DEF(OdString,			  SAVENAME,      (OdString::kEmpty),(OdString::kEmpty), (),ValidateNone())
VAR_DEF(	OdInt16,			  POLYSIDES,	 (4),			   (4),             (),ValidateRange(3,1024))
VAR_DEF(	OdInt16,			  FITTYPE,		 (2),			   (2),             (),ValidateRange(2,3))
VAR_DEF(	double,				  OFFSETDIST,     (-1.0),          (-1.0),          (),ValidateNone())
VAR_DEF(	OdInt16,			  LTSCLWBLK,	 (0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdString,			  SHPNAME,      (OdString::kEmpty),(OdString::kEmpty), (),ValidateNone())
VAR_DEF(	OdString,			  HPNAME,		(OD_T("ANSI31")),(OD_T("ANSI31")), (),ValidateNone())
VAR_DEF(	OdString,			  HPLAYER,		(OD_T(".")),(OD_T(".")), (),ValidateNone())
//VAR_DEF(	OdInt16,			  HPSTYLE,		(0),			   (0),             (),ValidateRange(0,2))
VAR_DEF(	double,				  HPSCALE,		(1.0),			  (1.0),			(),ValidatePositiveNonZero())
VAR_DEF(	double,				  HPANG,		(0),			   (0),             (),ValidateNone())
VAR_DEF(	double,				  HPSPACE,		(1.0),			  (1.0),			(),ValidatePositiveNonZero())
VAR_DEF(	OdInt16,			  HPDOUBLE,		(0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	double,				  VIEWASPECT,	(1.0),			  (1.0),			(),ValidateNone())
VAR_DEF(	OdInt16,			  CHAMMODE,		(0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  TEXTEVAL,		(0),			   (0),             (),ValidateRange(0,1))
VAR_DEF(  double,         TEXTROTATE, (0),         (0),             (),ValidateNone())
VAR_DEF(	double,				  CIRCLERAD,	(0),			   (0),         (),ValidatePositive())
VAR_DEF(	double,				  DONUTID,		(0.5),			   (0.5),         (),ValidateRange(0,1.e+15))
RO_VAR_DEF(	OdString,			  REFEDITNAME,  (OdString::kEmpty),(OdString::kEmpty), (),ValidateNone())
RO_VAR_DEF(OdInt16,       ARRAYEDITSTATE, (0),     (0),             (), ValidateRange(0,1))
VAR_DEF(	OdString,			  INSNAME,      (OdString::kEmpty),(OdString::kEmpty), (),ValidateNone())
VAR_DEF(	OdString,			  HANDSEEDS,     (OD_T("25")),(OD_T("25")), (),ValidateNone())
VAR_DEF(	double,				  DONUTOD,		(1),			   (1),         (),ValidateRange(1.e-6,1.e+15))
VAR_DEF(	OdInt16,			  DIASTAT,		(1),			   (1),             (),ValidateRange(0,1))
VAR_DEF(	OdInt16,			  DIMFIT,		(3),			   (3),             (),ValidateRange(0,5))
VAR_DEF(	OdInt16,			  MENUECHO,		(0),			   (0),             (),ValidateRange(0,15))
VAR_DEF(	double,				  LASTCMDANG,      (0),(0), (),ValidateNone())
RO_VAR_DEF(double,				  AREA,		 (0),(0),				 (),ValidateNone())
//VAR_DEF(	OdInt16,			  BINDTYPE,		(0),			   (0),             (),ValidateRange(0,1))
RO_VAR_DEF(double,				  DISTANCE,		 (0),(0),				 (),ValidateNone())
RO_VAR_DEF(double,				  PERIMETER,		 (0),(0),				 (),ValidateNone())
RO_VAR_DEF(OdInt16,         BLOCKEDITOR,	  (0),(0),			 (),ValidateRange(0,1))
VAR_DEF(ODDBHARDPOINTERID,  BEDITBLOCK,	      (OdDbObjectId::kNull),    (OdDbObjectId::kNull),            (), ValidateNone())
VAR_DEF(ODDBHARDPOINTERID,  BEDITANONYBLOCK,	(OdDbObjectId::kNull),    (OdDbObjectId::kNull),            (), ValidateNone())
VAR_DEF(OdInt16,			      BVMODE,	        (0),(0),			 (),ValidateRange(0,1))
RO_VAR_DEF(OdInt16,					UNDOCTL,	  (53),(53),					(),		  ValidateRange(0,63))
//VAR_DEF(OdInt16,					LAYEREVAL,	  (0),(0),					(),		  ValidateRange(0,2))
//VAR_DEF(OdInt16,					LAYERNOTIFY,	  (0),(0),					(),		  ValidateNone())
VAR_DEF(double,           TSPACEFAC,  (1),(),             (),ValidateRange(0.25,4.0))
VAR_DEF(OdCmColor,        GFCLR1,  (OdCmColor(OdCmEntityColor::kByACI,5)),(OdCmColor(OdCmEntityColor::kByACI,5)),             (),ValidateNone())
VAR_DEF(OdCmColor,        GFCLR2,  (OdCmColor(OdCmEntityColor::kByACI,2)),(OdCmColor(OdCmEntityColor::kByACI,2)),             (),ValidateNone())
VAR_DEF(OdInt16,			    GFCLRSTATE, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(double,           GFCLRLUM,   (1.0),(1.0),     (),ValidateRange(0.0,1.0))
VAR_DEF(OdInt16,			    GFNAME,      (1),			   (1),     (),ValidateRange(1,9))
VAR_DEF(OdInt16,			    GFSHIFT, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(ODTORIENT,		    GFANG, (0),  (0),			 (),ValidateNone())
VAR_DEF(OdInt16,			    HPBOUNDRETAIN, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(OdInt16,			    HPBOUND,		 (1),			   (1),     (),ValidateRange(0,1))
VAR_DEF(OdInt16,			    HPISLANDDETECTIONMODE,		 (1),			   (1),     (),ValidateRange(0,1))
VAR_DEF(OdInt16,			    HPISLANDDETECTION,		 (1),			   (1),     (),ValidateRange(0,2))
DICR21VAR(OdCmColor,      HPCOLOR,  (OdCmColor(OdCmEntityColor::kNone)),(OdCmColor(OdCmEntityColor::kNone)),             (),ValidateNone())
DICR21VAR(OdCmColor,      HPBACKGROUNDCOLOR,  (OdCmColor(OdCmEntityColor::kNone)),(OdCmColor(OdCmEntityColor::kNone)),             (),ValidateNone())
VAR_DEF(	OdString,			  HPTRANSPARENCY,		(OD_T("use current")),(OD_T("use current")), (),ValidateNone())
VAR_DEF(OdInt16,			    WMFBKGND, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(OdInt16,			    WMFFOREGND, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(OdInt16,			    HPANNOTATIVE, (0),  (0),			 (),ValidateRange(0,1))
VAR_DEF(ODTDIST,          FILLETRAD3D, (1.0),  (1.0),   (),ValidateEqGr(0.))
//新增变量}}
// New in Red Deer

DICR21VAR( ODTTABLESTYLEID,        CTABLESTYLE,         (OdDbObjectId::kNull),    (OdDbObjectId::kNull),            (),                         ValidateTableStyle())

// New in AC2008
DICR21VAR( ODTMLEADERSTYLEID,      CMLEADERSTYLE,       (OdDbObjectId::kNull),    (OdDbObjectId::kNull),            (),                         ValidateMLeaderStyle())

ANNO_VAR_DEF( ODANNOSCALE,         CANNOSCALE,          (ODANNOSCALE()),          (ODANNOSCALE()),                  (),                         ValidateNone())

DICR21VAR( ODTBOOL,                ANNOALLVISIBLE,      (true),                   (true),                           (),                         ValidateBOOL())

DICR21VAR( OdInt8,                 ANNOTATIVEDWG,       (0),                      (0),                              (),                         ValidateRange(0, 1))

DICR21VAR( ODTBOOL,                MSLTSCALE,           (true),                   (true),                           (),                         ValidateBOOL())


DICR21VAR( OdInt16,                LAYEREVAL,            (1),                     (1),                           (),                             ValidateRange(0,2))
DICR21VAR( OdInt16,                LAYERNOTIFY,          (15),                    (15),                           (),                            ValidateRange(-63,63))
DICR21VAR( OdInt16,                LIGHTINGUNITS,        (2),                     (2),                           (),                             ValidateRange(0,2))
DICR21VAR( OdInt16,                LIGHTSINBLOCKS,       (1),                     (1),                           (),                             ValidateRange(0,1)) // default changed in R24
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DBCSTATE controls the display of the dbConnect Manager,"
      " whether or not the dbConnect Manager is active."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Not displayed"
      "\n    1       Displayed"
    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               DBCSTATE,            (0),                     (0),                              (),                         ValidateRange(0,1))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INTERSECTIONCOLOR specifies the ACI color index of intersection polylines."
      "\n"
      "\n    Intersection polylines are displayed at the intersections of 3D surfaces"
      " if and only if INTERSECTIONDISPLAY == true.
      "\n"
      "\n    @table"
      "\n    Name              Value   Description"
      "\n    kACIbyBlock       0       ByBlock."
      "\n    kACIforeground    7       Foreground color."
      "\n    kACIbyLayer       256     ByLayer."
      "\n    kACIRed           1       Red."
      "\n    kACIYellow        2       Yellow."
      "\n    kACIGreen         3       Green."
      "\n    kACICyan          4       Cyan."
      "\n    kACIBlue          5       Blue."
      "\n    kACIMagenta       6       Magenta."
      "\n    ..                8-255   Defined by display device."
      "\n    kACInone          257     No color."

    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               INTERSECTIONCOLOR,   (257),                   (257),                            (),                         ValidateRange(0,257))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INTERSECTIONDISPLAY controls the display of intersection polylines."
      "\n"
      "\n    Intersection polylines are displayed at the intersections of 3D surfaces."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Not displayed"
      "\n    true      Displayed"
    </remarks>
  </properties>
*/
DICR15VAR(  bool,                  INTERSECTIONDISPLAY, (false),                 (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HALOGAP specifies the gap to be displayed where one 3D object hides another."
      "\n"
      "\n    HALOGAP is zoom independent, and is specified as a percentage of one drawing unit."
    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               HALOGAP,             (0),                     (0),                              (),                         ValidateRange(0,100))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    OBSCUREDCOLOR specifies the ACI color index of obscured lines."
      "\n"
      "\n    @table"
      "\n    Name              Value   Description"
      "\n    kACIbyBlock       0       ByBlock."
      "\n    kACIforeground    7       Foreground color."
      "\n    kACIbyLayer       256     ByLayer."
      "\n    kACIRed           1       Red."
      "\n    kACIYellow        2       Yellow."
      "\n    kACIGreen         3       Green."
      "\n    kACICyan          4       Cyan."
      "\n    kACIBlue          5       Blue."
      "\n    kACIMagenta       6       Magenta."
      "\n    ..                8-255   Defined by display device."
      "\n    kACInone          257     No color."
    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               OBSCUREDCOLOR,       (257),                   (257),                            (),                          ValidateRange(0,257))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    OBSCUREDLTYPE specifies the display and linetype of obscured lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Off"
      "\n    1        Solid"
      "\n    2        Dashed"
      "\n    3        Dotted"
      "\n    4        Short Dash"
      "\n    5        Medium Dash"
      "\n    6        Long Dash"
      "\n    7        Double Short Dash"
      "\n    8        Double Medium Dash"
      "\n    9        Double Long Dash"
      "\n    10       Medium Long Dash"
      "\n    11       Sparse Dot"
    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               OBSCUREDLTYPE,       (0),                     (0),                              (),                         ValidateRange(0,11))

// these was dictvardefs in old versions



/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INDEXCTL specifies the creation of layer and spatial indices in the *database*."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       None created."
      "\n    1       Layer index created."
      "\n    2       Spatial Index created."
      "\n    3       Both created."
    </remarks>
  </properties>
*/
DICR15VAR(  OdInt16,               INDEXCTL,            (0),                     (0),                              (),                         ValidateRange(0,3))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PROJECTNAME specifies the project name associated with the *database*."
    </remarks>
  </properties>
*/
DICR15VAR( OdString,               PROJECTNAME,         (OdString::kEmpty),      (OdString::kEmpty),               (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SORTENTS controls the object sort order."
      "\n"
      "\n"   SORTENTS will be a combination of the following:"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       No sorting"
      "\n    1       Object selection sorting"
      "\n    2       Object snap sorting"
      "\n    4       Clear all checkboxes"
      "\n    8       MSLIDE command sorting"
      "\n    16      REGEN command sorting"
      "\n    32      Plotting sorting"
      "\n    64      Clear all checkboxes"
    </remarks>
    <notes>
      "\n    The SORTENTS system variable has been depreciated."
    </notes>
    <see_also>
     "\n    DRAWORDERCTL"
    </see_also>
  </properties>
*/
DICR15VAR( OdInt16,                SORTENTS,            (127),                   (127),                            (),                         ValidateRange(0,127))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMASSOC controls the associativity of new dimension entities."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Creates exploded dimensions."
      "\n    1       Creates un-associative dimension entities."
      "\n    2       Creates associative dimension entities."
    </remarks>
  </properties>
*/
DICR15VAR( OdInt16,                DIMASSOC,            (2),                     (2),                              (),                         ValidateRange(0,2))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HIDETEXT controls the participation of Text and MText entities in HIDE commands."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Don't hide and are not hidden."
      "\n    true     Hide and are hidden"
    </remarks>
  </properties>
*/
DICR15VAR( bool,                   HIDETEXT,            (true),                  (true),                           (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DRAWORDERCTL controls the display update and inheritance of"
      " draworder when using certain editing commands."
      "\n"
      "\n    The following commands are affected by DRAWORDERCTL, BREAK, EXPLODE, FILLET, "
      " HATCH, HATCHEDIT, JOIN, OFFSET, PEDIT, and TRIM."
      "\n"
      "\n    With Draworder Inheritance on, entities created with these commands assume"
      " the draw order of the original objects."
      "\n"
      "\n    With Draworder Inheritance off,"
      " they assume the default draworder (top)."
      "\n"
      "\n   With Display update on, entities created with the aforementioned editing"
      " commands are displayed correctly according to their Draworder."
      "\n"
      "\n With Display Update"
      " off, they are displayed on top, until the next regeneration."
      "\n"
      "\n    @table"
      "\n    Value   Draworder Inheritance   Display Update"
      "\n    0       Off                     Off"
      "\n    1       Off                     On"
      "\n    2       On                      Off"
      "\n    3       On                      On"
    </remarks>
  </properties>
*/
DICR21VAR( OdInt8,                   DRAWORDERCTL,        (3),                     (3),                              (),                    ValidateRange(0,3))

// 2006 support

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HPINHERIT specifies the hatch origin when hatch properties"
      " are inherited with the HATCH and HATCHEDIT commands."
      "\n"
      "\n    @table"
      "\n    Value   Hatch Origin"
      "\n    false   From HPORIGIN"
      "\n    true    From Source"
    </remarks>
  </properties>
*/
DICR21VAR(   ODTBOOL,                HPINHERIT,           (false),                 (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HPORIGIN specifies the hatch origin for new hatch entities relative to the current UCS."
    </remarks>
  </properties>
*/
DICR21VAR(   OdGePoint2d,            HPORIGIN,            (OdGePoint2d::kOrigin),  (OdGePoint2d::kOrigin),           (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FIELDEVAL specifies when fields are updated. "
      "\n"
      "\n    FIELDEVAL will be a combination of one or more of the following values:"
      "\n"
      "\n    @table"
      "\n    Name                              Value    Description"
      "\n    OdDbField::kDisable               0        Disable evaluation of field."
      "\n    OdDbField::kOnOpen                0x01     Evaluate on *database* open."
      "\n    OdDbField::kOnSave                0x02     Evaluate on *database* save."
      "\n    OdDbField::kOnPlot                0x04     Evaluate on *database* plot."
      "\n    OdDbField::kOnEtransmit           0x08     Evaluate on *database* Etransmit."
      "\n    OdDbField::kOnRegen               0x10     Evaluate on *database* regen."
      "\n    OdDbField::kOnDemand              0x20     Evaluate on demand."
      "\n    OdDbField::kAutomatic             0x3F     Evaluate automatically."
    </remarks>
  </properties>
*/
DICR21VAR(   OdInt16,                FIELDEVAL,           (31),                     (31),                             (),                         ValidateRange(0,31))

DICR21VAR(   double,                 MSOLESCALE,          (1.0),                    (1.0),                            (),                         ValidateEqGr(0.))

DICR21VAR(   OdInt16,                UPDATETHUMBNAIL,     (15),                     (15),                             (),                         ValidateRange(0,31))

//-----------------------------------------
// Variables added in AC 2007
//-----------------------------------------

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SOLIDHIST controls the default Show History property setting for all solids."
      "\n"
      "\n    When enabled, a history of the solids comprising a composite solid is retained."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Disabled."
      "\n    1        Enabled."
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt8,                  SOLIDHIST,            (1),                    (1),                             (),                         ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SHOWHIST controls the History display for solids in a drawing."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Hides all history."
      "\n    1        Uses the individual solid Show History properties."
      "\n    2        Displays all history.
    </remarks>
  </properties>
*/
VAR_DEF(   OdInt8,                  SHOWHIST,            (1),                    (1),                             (),                         ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PSOLWIDTH specifies the default width for swept solids."
    </remarks>
  </properties>
*/
DICR15VAR( ODTDIST,                 PSOLWIDTH,         (0.25),                  (5.0),                             (),                         ValidateRange(DBL_MIN,DBL_MAX))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTPARAM controls the shape of lofted solids and surfaces."
      "\n"
      "\n    LOFTPARAM will be a combination of one or more of the following:"
      "\n"
      "\n    @table"
      "\n    Name                 Value       Description"
      "\n    kLoftNoParam         0x00        No parameters.
      "\n    kLoftNoTwist         0x01        No twist between cross sections."
      "\n    kLoftAlignDirection  0x02        Align directions of cross sections."
      "\n    kLoftSimplify        0x04        Create simple solids and surfaces."
      "\n    kLoftClose           0x08        Close between the starting and ending cross sections."
      "\n    kLoftDefault         0x07        kLoftNoTwist | kLoftAlignDirection | kLoftSimplify "
    </remarks>
  </properties>
*/
VAR_DEF(  ODTDB_LOFTPARAMTYPE,                LOFTPARAM,            (OdDb::kLoftDefault),                    (OdDb::kLoftDefault),     (),   ValidateRange(OdDb::kLoftNoParam,ODTDB_LOFTPARAMTYPE(OdDb::kLoftNoTwist|OdDb::kLoftAlignDirection|OdDb::kLoftSimplify|OdDb::kLoftClose)))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTNORMALS controls the normals of lofted objects as they pass through cross sections."
      "\n"
      "\n    It is ignored when a path or guide curve is specified."
      "\n"
      "\n    @table"
      "\n    Name                   Value    Description"
      "\n    kLoftRuled             0        Ruled surface."
      "\n    kLoftSmooth            1        Smooth surface."
      "\n    kLoftFirstNormal       2        Surface is normal to the first cross section."
      "\n    kLoftLastNormal        3        Surface is normal to the last cross section."
      "\n    kLoftEndsNormal        4        Surface is normal to the first and last cross sections."
      "\n    kLoftAllNormal         5        Surface is normal to all cross sections."
      "\n    kLoftUseDraftAngles    6        Surface uses draft angle and magnitude."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDB_LOFTNORMALSTYPE,             LOFTNORMALS,            (OdDb::kLoftSmooth),                    (OdDb::kLoftSmooth),     (),         ValidateRange(OdDb::kLoftRuled,OdDb::kLoftUseDraftAngles))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTANG1 specifies the draft angle through the first cross section in a loft operation."
      "\n"
      "\n    0 is measured in the plane of the curve, outward from the curve."
      "\n    Positive angles are measured toward the next cross section."
    </remarks>
  </properties>
*/
VAR_DEF(  ODTORIENT,                   LOFTANG1,           (OdaPI2),                   (OdaPI2),                             (),                         ValidateRange(0, Oda2PI))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTANG1 specifies the draft angle through the first cross section in a loft operation."
      "\n"
      "\n    0 is measured in the plane of the curve, outward from the curve."
      "\n    Positive angles are measured toward the next previous cross section."
    </remarks>
  </properties>
*/
VAR_DEF(  ODTORIENT,                   LOFTANG2,           (OdaPI2),                   (OdaPI2),                             (),                         ValidateRange(0, Oda2PI))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTMAG1 specifies the draft angle magnitude through the first cross section"
      "\n    of a lofted solid."
    </remarks>
  </properties>
*/
VAR_DEF(  ODTUNITLESS8,                LOFTMAG1,            (0.),                    (0.),                             (),                         ValidateRange(0.,1.e100))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOFTMAG2 specifies the draft angle magnitude through the first cross section"
      "\n    of a lofted solid."
    </remarks>
  </properties>
*/
VAR_DEF(  ODTUNITLESS8,                LOFTMAG2,            (0.),                    (0.),                             (),                         ValidateRange(0., 1.e100))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LATITUDE specifies the drawing model latitude in decimal degrees."
      "\n"
      "\n    The default is determined by the country code in the operating system."
    </remarks>
    <notes>
      "\n     All angles are expressed in degrees."
      "\n"
      "\n     North latitudes are positive."
    </notes>
  </properties>
*/
VAR_DEF(  ODTORIENT,                    LATITUDE,            (37.7950),               (37.7950),                             (),                         ValidateRange(-90., 90.))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LONGITUDE specifies the drawing model longitude in decimal degrees."
      "\n"
      "\n    The default is determined by the country code in the operating system."
    </remarks>
    <notes>
      "\n     All angles are expressed in degrees."
      "\n"
      "\n     West longitudes are positive"
    </notes>
  </properties>
*/
VAR_DEF(  ODTORIENT,                    LONGITUDE,           (-122.3940),             (-122.3940),                             (),                         ValidateRange(-180., 180.))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    NORTHDIRECTION specifies the angle of the Sun from North."
    </remarks>
    <notes>
      "\n     All angles are expressed in degrees."
      "\n"
      "\n     This angle is in the context of the WCS."
    </notes>
  </properties>
*/
VAR_DEF(  ODTORIENT,                    NORTHDIRECTION,       (0.),                    (0.),                             (),                          ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TIMEZONE sets the time zone for sun studies in the drawing."
      "\n"
      "\n"   TIMEZONE represents hours and minutes away from Greenwich Mean Time."
      "\n    Setting a geographic location sets TIMEZONE."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDB_TIMEZONE,             TIMEZONE, (OdDb::kPacific),      (OdDb::kPacific),                            (),                            ValidateRange(OdDb::kInternationalDateLine,OdDb::kTonga))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LIGHTGLYPHDISPLAY controls the display of light glyphs."
      "\n"
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not displayed."
      "\n    1        Displayed."
    </remarks>
  </properties>
*/
VAR_DEF(  OdInt8,          LIGHTGLYPHDISPLAY,            (1),                    (1),                             (),                              ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TILEMODELIGHTSYNCH controls the synchronization of lighting in all model space viewports."
      "\n"
      "\n    This system variable has no effect on layout viewports."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not synchronized."
      "\n    1        Synchronized"
    </remarks>
  </properties>
*/
VAR_DEF(  OdInt8,          TILEMODELIGHTSYNCH,            (1),                    (1),                             (),                              ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INTERFERECOLOR specifies the color of interference objects."
    </remarks>
  </properties>
*/
VAR_DEF(  OdCmColor,       INTERFERECOLOR, (OdCmEntityColor::kByLayer), (OdCmEntityColor::kByLayer),               (),                              ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INTERFEREOBJVS specifies the interference object visual style."
    </remarks>
  </properties>
*/
VAR_DEF( ODVISTYLEID,    INTERFEREOBJVS,       (OdDbObjectId::kNull),       (OdDbObjectId::kNull),              (),                               ValidateVisualStyle())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    INTERFEREVPVS specifies the interference checking visual style for the viewport."
    </remarks>
  </properties>
*/
VAR_DEF( ODVISTYLEID,       INTERFEREVPVS,  (OdDbObjectId::kNull),          (OdDbObjectId::kNull),              (),                                ValidateVisualStyle())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DRAGVS specifies the drag visual style."
    </remarks>
  </properties>
*/
VAR_DEF( ODVISTYLEID,               DRAGVS,  (OdDbObjectId::kNull),          (OdDbObjectId::kNull),              (),                                ValidateVisualStyle())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n     CSHADOW controls shadows for 3D objects."
      "\n"
      "\n    @table"
      "\n    Name                       Value    Description"
      "\n    kShadowsCastAndReceive     0x00     Shadows cast and received."
      "\n    kShadowsDoesNotReceive     0x01     Shadows cast, but not received."
      "\n    kShadowsDoesNotCast        0x02     Shadows received but not cast."
      "\n    kShadowsIgnore             0x03      Shadows neither cast nor received."
    </remarks>
    <notes>
      "\n     It order be displayed, shadows must be turned enabled in the visual style that is applied"
      "\n     to the viewport."
    </notes>
  </properties>
*/
VAR_DEF(ODTDB_SHADOWFLAGS,         CSHADOW,    (OdGiSubEntityTraits::kShadowsCastAndReceive), (OdGiSubEntityTraits::kShadowsCastAndReceive),    (),                                ValidateRange(OdGiSubEntityTraits::kShadowsCastAndReceive,OdGiSubEntityTraits::kShadowsIgnore))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SHADOWPLANELOCATION specifies the location, on the current Z-axis, of an invisible ground plane"
      "\n    used to display shadows."
      "\n"
      "\n    The shadow plane casts and receives shadows."
    </remarks>
  </properties>
*/
VAR_DEF(  ODTDIST,         SHADOWPLANELOCATION,           (0.),                    (0.),                             (),                               ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CAMERADISPLAY controls the display of camera glyphs."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not displayed."
      "\n    true     Displayed."
    </remarks>
  </properties>
*/

VAR_DEF( ODTBOOL,                CAMERADISPLAY,           (false),                 (false),                          (),                         ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LENSLENGTH specifies the length, in millimeters, of the lens used in perspective viewing."
    </remarks>
  </properties>
*/
VAR_DEF_H( ODTDIST,               LENSLENGTH,           (50.),                     (50.),                             (),                           ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CAMERAHEIGHT specifies the default height, in drawing units, for new camera objects."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDIST,               CAMERAHEIGHT,           (0.),                    (0.),                             (),                           ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    STEPSPERSEC specifies the number of steps taken per second "
      "\n    in walk or fly mode."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDIST,               STEPSPERSEC,           (2.),                    (2.),                             (),                           ValidateRange(1,30))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    STEPSIZE specifies the size of each step, in drawing units, in walk or fly mode."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDIST,               STEPSIZE,           (6.),                    (6.),                             (),                           ValidateRange(1e-6,1e+6))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    3DDWFPREC specifies the 3D DWF publishing precision."
    </remarks>
  </properties>
*/
VAR_DEF( ODTDIST,               3DDWFPREC,           (2.),                    (2.),                             (),                           ValidateRange(1,6))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PSOLHEIGHT specifies the default height, in drawing units,"
      "\n    used by the POLYSOLID command, for swept solid objects."
    </remarks>
  </properties>
*/
DICR15VAR( ODTDIST,             PSOLHEIGHT,          (4.),                    (80.),                            (),                     ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CMATERIAL specifies the material of new objects."
    </remarks>
  </properties>
*/
VAR_DEF( ODTMATERIALID,         CMATERIAL,      (OdDbObjectId::kNull),          (OdDbObjectId::kNull),            (),                     ValidateMaterial())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DWFFRAME controls the visibility and plotting of the DWF underlay frame."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not visible and not plotted."
      "\n    1        Visible and plotted."
      "\n    2        Visible but not plotted."
    </remarks>
  </properties>
*/
DICR21VAR_H(  OdInt8,          DWFFRAME,            (2),                    (2),                             (),                              ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DGNFRAME controls the visibility and plotting of the DGN frame."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not visible and not plotted."
      "\n    1        Visible and plotted."
      "\n    2        Visible but not plotted."
    </remarks>
  </properties>
*/
VAR_DEF_H(  OdInt8,          DGNFRAME,            (0),                    (0),                             (),                              ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    REALWORLDSCALE controls the rendering of materials with units set to real-world scale."
      "\n"
      "\n     @table"
      "\n     Value    Description"
      "\n     false    Not rendered."
      "\n     true     Rendered."
    </remarks>
  </properties>
*/
VAR_DEF( bool,          REALWORLDSCALE,            (true),                    (true),                             (),                              ValidateBOOL())

//-----------------------------------------
// Variables added in AC 2008
//-----------------------------------------
DICR21VAR( OdInt16,     DXEVAL,     (12),                     (12),                          (),                         ValidateRange(0,511))

//-----------------------------------------
// Variables added in AC 2009
//-----------------------------------------
DICR21VAR( OdInt16,        GEOLATLONGFORMAT,        (1),                     (1),                          (),                         ValidateRange(0,1))
DICR21VAR( OdInt16,        GEOMARKERVISIBILITY,     (1),                     (1),                          (),                         ValidateRange(0,1))

DICR21VAR( OdInt16,                PREVIEWTYPE,     (0),                     (0),                          (),                         ValidateRange(0,1))

//-----------------------------------------
// Variables added in AC 2010
//-----------------------------------------

// DIMTXTDIRECTION - defined in DimVarDefs.h

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXPORTMODELSPACE specifies what part of the drawing to export to a DWF, DWFx, or PDF file from Model space"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Display"
      "\n    1       Extents"
      "\n    2       Window"
    </remarks>
  </properties>
*/
DICR24VAR( OdInt16,    EXPORTMODELSPACE,             (0),                 (0),                          (),                         ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXPORTPAPERSPACE specifies what part of the drawing to export to a DWF, DWFx, or PDF file from paper space"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Current Layout"
      "\n    1       All Layouts"
    </remarks>
  </properties>
*/
DICR24VAR( OdInt16,    EXPORTPAPERSPACE,             (0),                 (0),                          (),                         ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    EXPORTPAGESETUP specifies whether to export to a DWF, DWFx, or PDF file with the current page setup"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Default"
      "\n    1       Override"
    </remarks>
  </properties>
*/
DICR24VAR( OdInt16,     EXPORTPAGESETUP,             (0),                 (0),                          (),                         ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FRAME controls the visibility of frames for external references, images and underlays. It overrides the individual IMAGEFRAME, DWFFRAME, PDFFRAME, DGNFRAME, and XCLIPFRAME settings"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Invisible"
      "\n    1       Is displayed and plotted"
      "\n    2       Is displayed but not plotted"
      "\n    3       The individual setting varies for different underlays, external references and images"
    </remarks>
  </properties>
*/
DICR24VAR_H( OdInt16,               FRAME,             (3),                 (3),                          (),                         ValidateRange(0,3))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PDFFRAME controls the visibility of PDF underlay frames."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Invisible"
      "\n    1       Is displayed and plotted"
      "\n    2       Is displayed but not plotted"
    </remarks>
  </properties>
*/
/* This variable was bool in previous version */
DICR24VAR_H( OdInt16,               PDFFRAME,          (1),                 (1),                          (),                         ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    XCLIPFRAME controls the visibility of Xref clip boundaries."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Invisible"
      "\n    1       Is displayed and plotted"
      "\n    2       Is displayed but not plotted"
    </remarks>
  </properties>
*/
/* This variable was bool (with initial value "false") in previous version */
DICR15VAR( OdInt16,               XCLIPFRAME,          (2),                 (2),                          (),                         ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MESHTYPE Controls the type of mesh that is created by REVSURF, TABSURF, RULESURF and EDGESURF"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Creates legacy polygon or polyface mesh when you use REVSURF, TABSURF, RULESURF, or EDGESURF"
      "\n    1       Creates full-featured mesh objects when you use REVSURF, TABSURF, RULESURF, or EDGESURF (recommended)"
    </remarks>
  </properties>
*/
DICR24VAR( OdInt16,               MESHTYPE,          (1),                 (1),                          (),                         ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SKYSTATUS Determines if the sky illumination is computed at render time"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Sky off"
      "\n    1       Sky background"
      "\n    2       Sky background and illumination"
    </remarks>
  </properties>
*/
DICR24VAR( OdInt16,               SKYSTATUS,         (0),                 (0),                          (),                         ValidateRange(0,2))


//-----------------------------------------
// Variables added in AC 2013
//-----------------------------------------
RO_VAR_DEF(OdInt64,          REQUIREDVERSIONS,       (0),                 (0),                           (),                         ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CETRANSPARENCY variable sets the transparency assigned to new entities"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    ByLayer Transparency value by layer."
      "\n    ByBlock Transparency value by block."
      "\n    0       No transparency."
      "\n    1-90    Transparency value is a percentage (max. 90%)."
    </remarks>
  </properties>
*/
DICR27VAR(OdCmTransparency, CETRANSPARENCY, ((const OdCmTransparency&) OdCmTransparency()), ((const OdCmTransparency&) OdCmTransparency()), (), ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CVIEWDETAILSTYLE variable sets the current detail view style."
      "\n"
      "\n    @table"
      "\n    Value      Description"
      "\n    Imperial24 Detail view style used for imperial drawings."
      "\n    Metric50   Detail view style used for metric drawings."
    </remarks>
  </properties>
*/
DICR27VAR(ODTVIEWDETAILSTYLEID, CVIEWDETAILSTYLE, (OdDbObjectId::kNull), (OdDbObjectId::kNull), (), ValidateViewDetailStyle())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    CVIEWSECTIONSTYLE variable sets the current section view style."
      "\n"
      "\n    @table"
      "\n    Value      Description"
      "\n    Imperial24 Section view style used for imperial drawings."
      "\n    Metric50   Section view style used for metric drawings."
    </remarks>
  </properties>
*/
DICR27VAR(ODTVIEWSECTIONSTYLEID, CVIEWSECTIONSTYLE, (OdDbObjectId::kNull), (OdDbObjectId::kNull), (), ValidateViewSectionStyle())

/**
  <title WIPEOUTFRAME>
  <toctitle WIPEOUTFRAME>
   
  <table>
   <b>Type</b>            OdInt16
   <b>Initial value</b>   1
   <b>Read-Only</b>       No
   <b>Saved In</b>        Database
   <b>Versions</b>        2013+
  </table>
   
  WIPEOUTFRAME controls the visibility of wipeout object frames.
   
  <table>
   <b>Value</b>   <b>Description</b>
   0              Invisible
   1              Is displayed and plotted
   2              Is displayed but not plotted
  </table>
   
  <table>
   <b>Access Methods</b>
   OdDbDatabase::getSysVar()
   OdDbDatabase::setSysVar()
   &nbsp;?
   OdDbDatabase::getWIPEOUTFRAME()
   OdDbDatabase::setWIPEOUTFRAME()
  </table>  

<group TD_SysVars_W>
  */
//<dom_var_def>OdInt16 WIPEOUTFRAME;
DICR27VAR( OdInt16,              WIPEOUTFRAME,          (1),                 (1),                          (),                         ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MLEADERSCALE controls the overall scale factor applied to multileaders."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0.0      "
      "\n    >0       "
    </remarks>
  </properties>
*/
DICR27VAR( double,               MLEADERSCALE,          (1.0),               (1.0),                        (),                         ValidatePositive())

DICR27VAR(OdInt16,               POINTCLOUDPOINTSIZE,   (2),                  (2),            (),             ValidateRange(1,10))
DICR27VAR( OdInt16,              POINTCLOUDCLIPFRAME,   (2),                  (2),                          (),                         ValidateRange(0,2))

#ifdef DOUNDEF_VAR_DEF
#undef VAR_DEF
#undef DOUNDEF_VAR_DEF
#endif

#ifdef DOUNDEF_RO_VAR_DEF
#undef RO_VAR_DEF
#undef DOUNDEF_RO_VAR_DEF
#endif

#ifdef DOUNDEF_VAR_DEF_H
#undef VAR_DEF_H
#undef DOUNDEF_VAR_DEF_H
#endif

#ifdef DOUNDEF_RO_VAR_DEF_H
#undef RO_VAR_DEF_H
#undef DOUNDEF_RO_VAR_DEF_H
#endif

#ifdef DOUNDEF_DICR15VAR
#undef DICR15VAR
#undef DOUNDEF_DICR15VAR
#endif

#ifdef DOUNDEF_DICR21VAR_H
#undef DICR21VAR_H
#undef DOUNDEF_DICR21VAR_H
#endif

#ifdef DOUNDEF_DICR21VAR
#undef DICR21VAR
#undef DOUNDEF_DICR21VAR
#endif

#ifdef DOUNDEF_DICR24VAR_H
#undef DICR24VAR_H
#undef DOUNDEF_DICR24VAR_H
#endif

#ifdef DOUNDEF_DICR24VAR
#undef DICR24VAR
#undef DOUNDEF_DICR24VAR
#endif

#ifdef DOUNDEF_DICR27VAR_H
#undef DICR27VAR_H
#undef DOUNDEF_DICR27VAR_H
#endif

#ifdef DOUNDEF_DICR27VAR
#undef DICR27VAR
#undef DOUNDEF_DICR27VAR
#endif

#ifdef DOUNDEF_VAR_DEF_2
#undef VAR_DEF_2
#undef DOUNDEF_VAR_DEF_2
#endif

#ifdef DOUNDEF_ANNO_VAR_DEF
#undef ANNO_VAR_DEF
#undef DOUNDEF_ANNO_VAR_DEF
#endif

#ifdef REGVAR_DEF

#define ODTDB_PROXYIMAGE OdDb::ProxyImage /* {Secret} */


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ATTREQ controls the requesting of attribute values during the INSERT command."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Attributes assume their defaults."
      "\n    true    Attributes are requested."
    </remarks>
    <see_also>
      "setATTDIA getATTDIA"
    </see_also>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             ATTREQ,         (true),               (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    ATTDIA specifies if attribute values are requested via a dialog box during the INSERT command."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Attributes are requested via the command prompt."
      "\n    true    Attributes are requested via a dialog box."
    </remarks>
    <notes>
      Attributes are requested if and only if ATTREQ = true;
    </notes>
    <see_also>
      "setATTREQ getATTREQ"
    </see_also>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             ATTDIA,         (true),              (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    BLIPMODE controls the display of marker blips."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Not displayed."
      "\n    true    Displayed."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             BLIPMODE,       (false),              (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DELOBJ controls the deletion of objects used to create solid objects and regions."
      "\n"
      "\n    Commands affected are REGION, EXTRUDE, and REVOLVE."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Objects are not deleted."
      "\n    true    Objects are deleted."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             DELOBJ,         (3),               (),       ValidateRange(-3, 3))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FILEDIA controls the display of file navigation dialog boxes."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    false   Command prompt input."
      "\n    true    Dialog boxes displayed."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             FILEDIA,        (true),               (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    COORDS controls the display of coordinate information in the status bar."
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Absolute coordinates updated when points are picked."
      "\n    1       Absolute coordinates updated continuously."
      "\n    2       Absolute coordinates updated continuously, with polar coordinates displayed when appropriate."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             COORDS,         (1),                  (),       ValidateRange(0,2))
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DRAGMODE controls the display of dragged objects. This includes both objects being moved from"
      "\n    place to place, as well as objects being created; e.g., Circles."
      "\n"
      "\n    @table"
      "\n    Value   Mode    Description"
      "\n    0       Off     Off"
      "\n    1       On      Displays dragged objects if and only if \"drag\" is entered at the command line while dragging."
      "\n    2       Auto    Always displays dragged objects"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             DRAGMODE,       (2),                  (),       ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    OSMODE specifies the running object snaps. OSMODE will be a combination of one or more of the following:"
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0x00     NONe"
      "\n    0x01     ENDpoint"
      "\n    0x02     MIDpoint"
      "\n    0x04     CENter"
      "\n    0x08     NODe"
      "\n    0x10     QUAdrant"
      "\n    0x20     INTersection"
      "\n    0x40     INSertion"
      "\n    0x80     PERpendicular"
      "\n    0x100    TANgent"
      "\n    0x200    NEArest"
      "\n    0x400    Clears all object snaps"
      "\n    0x800    APParent intersection"
      "\n    0x1000   EXTension"
      "\n    0x2000   PARallel"
      "\n    0x4000   Disable all"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             OSMODE,         (37),                 (),       ValidateRange(0,32767))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PICKFIRST controls noun-verb object selection."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             PICKFIRST,      (1),                  (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PICKBOX specifies the object selection target height, in pixels."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             PICKBOX,        (3),                  (),       ValidateRange(0,50))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PICKSTYLE controls group and associative hatch selection."
      "\n"
      "\n    @table"
      "\n    Value    Group      Associative Hatch"
      "\n    0        Disabled   Disabled"
      "\n    1        Enabled    Disabled"
      "\n    2        Disabled   Enabled"
      "\n    3        Enabled    Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             PICKSTYLE,      (1),                  (),       ValidateRange(0,3))

// Range (0.1 - 1.0) lineweight setting slider

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LWDISPSCALE emulates the lineweight setting slider."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTUNITLESS4,        LWDISPSCALE,    (0.55),               (),       ValidateRange(0.1, 1.))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LWDEFAULT specifies the default lineweight for new entities."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTDB_LINEWEIGHT,    LWDEFAULT,      (OdDb::kLnWt025),     (),       ValidateLineWeightDefault())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FONTALT specifies the filename of the font file to be used when the font specified"
      " by a text style cannot be found."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdString,            FONTALT,        (OD_T("simplex.shx")),      (),       ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLINETYPE controls polyline creation and conversion from OdDb2dPolyline to OdDbPolyline when a database file is opened."
      "\n"
      "\n    @table"
      "\n    Value    Conversions    New Polylines"
      "\n    0        Disabled       OdDb2dPolyline"
      "\n    1        Disabled       OdDbPolyline"
      "\n    2        Enabled        OdDbPolyline"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             PLINETYPE,      (2),                  (),       ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SAVEROUNDTRIP controls the saving of information in a *database* file"
      " to allow round-tripping of object types not supported in the save file format."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(bool,                SAVEROUNDTRIP,  (true),               (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PROXYSHOW controls the display of proxy graphics."
      "\n"
      "\n    @table"
      "\n    Name                      Value   Description"
      "\n    OdDb::kProxyNotShow       0       Proxy graphics are not displayed."
      "\n    OdDb::kProxyShow          1       Proxy graphics are displayed."
      "\n    OdDb::kProxyBoundingBox   2       Proxy bounding boxes are displayed."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTDB_PROXYIMAGE,    PROXYSHOW,      (OdDb::kProxyShow),   (),       ValidateRange(OdDb::kProxyNotShow, OdDb::kProxyBoundingBox))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    TEXTFILL controls the filling of TrueType fonts."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             TEXTFILL,       (true),               (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PREVIEW_WIDTH specifies the width in pixels of generated preview bitmap images."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdUInt32,            PREVIEW_WIDTH,  (180),                (),       ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PREVIEW_HEIGHT specifies the height in pixels of generated preview bitmap images."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdUInt32,            PREVIEW_HEIGHT, (85),                 (),       ValidateNone())

// New in Red Deer (2004)


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    "
    </remarks>
  </properties>GRIPHOVER specifies the ACI color index of unselected grips when the cursor hovers over them.
*/
REGVAR_DEF(OdInt16,             GRIPHOVER,      (11),                  (),       ValidateRange(1,255))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    GRIPOBJLIMIT specifies the number of selected objects beyond which grips are suppressed."
      " for a selection set."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPOBJLIMIT,   (100),                (),       ValidateRange(0,32767))


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    GRIPTIPS controls the display of grip tips for custom objects."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Disabled"
      "\n    1        Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPTIPS,       (1),                  (),       ValidateRange(0,1))


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    HPASSOC controls the associativity of new hatch patterns and gradient fills."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not associative"
      "\n    1        Associative"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             HPASSOC,        (1),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    LOGFILEMODE controls the output of the text window to a log file."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not written"
      "\n    1        Written"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             LOGFILEMODE,    (0),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    MAXHATCHDENSITY specifies the maximum number of lines in a Hatch entity."
    </remarks>
  </properties>
*/
//REGVAR_DEF(OdUInt32,            MAXHATCHDENSITY,(300000),            (),       ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    FIELDDISPLAY controls the display of field backgrounds in text."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        No background"
      "\n    1        Gray background"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             FIELDDISPLAY,   (1),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    R12SaveDeviation controls the deviation for saving ellipses and splines to R12."
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTDIST,             R12SaveDeviation,(0.),                (),       ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    R12SaveAccuracy controls the number of segments between spline control"
      "segments or on 90 elliptical arcs for saving ellipses and splines to R12."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             R12SaveAccuracy,(8),                  (),       ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    AcisSaveAsMode controls the exploding mode of ACIS entities (3DSolids, Bodies, Regions)
      " while saving to R12, saving to proxy's graphics metafile, exploding geometry."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Save meshes"
      "\n    1        Save edges only"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             AcisSaveAsMode,(0),                (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    AcisProxyMode controls saving to proxy's graphics metafile mode of ACIS entities (3DSolids, Bodies, Regions)."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Save meshes"
      "\n    1        Save edges only"
    </remarks>
  </properties>
*/

REGVAR_DEF(OdInt16,              AcisProxyMode,(1),              (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    UCSVIEW controls the saving of the current UCS with a named view."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Not saved"
      "\n    1        Saved"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             UCSVIEW,        (1),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    SAVEDWGCHECKSUM specifies if drawing files created by Teigha are recognized as "trusted" drawings (not implemented)
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Drawing is not considered "trusted"
      "\n    true     Drawing is treated as "trusted" (not implemented)
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             SAVEDWGCHECKSUM,(true),               (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    GRIPBLOCK Controls how grips are displayed on a block after you select it. If this option is selected, all grips are displayed for each object in the block. If this option is cleared, one grip is displayed at the insertion point of the block."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Assigns a grip only to the insertion point of the block"
      "\n    true     Assigns grips to objects within the block"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPBLOCK,      (0),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n   Controls the color of nonselected grips"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPCOLOR,      (150),                (),       ValidateRange(1,255))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n   Controls the color of custom grips for dynamic blocks"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPDYNCOLOR,   (140),                (),       ValidateRange(1,255))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n   Controls the color of custom grips for dynamic blocks"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPHOT,        (12),                  (),       ValidateRange(1,255))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n   Controls the use of selection set grips."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPS,          (2),                  (),       ValidateRange(0,2))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n   Sets the size of the grip box in pixels."
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             GRIPSIZE,       (5),                  (),       ValidateRange(1,255))

/*** VARDOCS:
  <properties>
    <remarks>
    "\n   Controls whether the drawing is saved with visual fidelity."
    "\n"
    "\n    @table"
    "\n    Value    Description"
    "\n    0        Saved without visual fidelity"
    "\n    1        Saved with visual fidelity"
    </remarks>
  </properties>
*/
REGVAR_DEF(OdInt16,             SAVEFIDELITY,   (1),                  (),       ValidateRange(0,1))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DWFOSNAP controls whether object snapping is active for geometry in DWF underlays
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             DWFOSNAP,      (1),                  (),       ValidateBOOL())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DGNOSNAP controls whether object snapping is active for geometry in DGN underlays
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             DGNOSNAP,      (1),                  (),       ValidateBOOL())

//-----------------------------------------
// Variables added in AC 2009
//-----------------------------------------

REGVAR_DEF(OdInt16,            THUMBSIZE,      (1),                  (),       ValidateRange(0,8))

REGVAR_DEF(OdInt16,         PUBLISHHATCH,      (1),                  (),       ValidateRange(0,1))

REGVAR_DEF(OdInt16,          OPENPARTIAL,      (1),                  (),       ValidateRange(0,1))

REGVAR_DEF(double,          DGNIMPORTMAX,    (0.0),                  (),       ValidateNone())

//-----------------------------------------
// Variables added in AC 2010
//-----------------------------------------

/*** VARDOCS:
<properties>
<remarks>
"\n    PDFOSNAP controls whether object snapping is active for geometry in PDF underlays
"\n"
"\n    @table"
"\n    Value    Description"
"\n    false    Disabled"
"\n    true     Enabled"
</remarks>
</properties>
*/
REGVAR_DEF(ODTBOOL,             PDFOSNAP,      (1),                  (),       ValidateBOOL())

REGVAR_DEF(OdInt16,             XFADECTL,     (70),                  (),       ValidateRange(0,90))


/*** VARDOCS:
  <properties>
    <remarks>
      "\n    PLINECACHE controls creation the cache of vertexes for OdDb2dPolyline when a database file is opened."
      "\n"
      "\n    @table"
      "\n    Value    Cache"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
REGVAR_DEF(ODTBOOL,             PLINECACHE,      (true),                  (),       ValidateBOOL())

//新增系统变量
REGVAR_DEF(OdInt16,             SAVETIME,	  (90),					(),       ValidateRange(0,600))
REGVAR_DEF(OdInt16,             OSOPTIONS,	(3),					(),       ValidateRange(0,7))
REGVAR_DEF(OdInt16,             AUTOSNAP,	  (63),					(),       ValidateRange(0,63))
REGVAR_DEF(OdInt16,             POLARMODE,	  (0),					(),       ValidateRange(0,15))
REGVAR_DEF(OdInt16,             APERTURE,	  (10),					(),       ValidateRange(1,50))
REGVAR_DEF( OdString,           FONTMAP,    (OD_T("gcad.fmp")),			(),       ValidateNone())
REGVAR_DEF(OdInt16,             TRACKPATH,	  (0),					(),       ValidateRange(0,5))
REGVAR_DEF(OdInt16,             AUDITCTL,	  (0),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             MAXSORT,	  (1000),				(),       ValidateRange(0,32767))
REGVAR_DEF(double,              HPGAPTOL,	  (0),					(),       ValidateRange(0,5000))
REGVAR_DEF(OdInt16,             WDEFAULT,	  (25),					(),       ValidateRange(0,211))
REGVAR_DEF(OdInt16,             PROJMODE,	  (1),					(),       ValidateRange(0,2))
REGVAR_DEF(OdInt16,             EDGEMODE,	  (0),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             TRIMMODE,	  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             PICKAUTO,	  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             STARTUP,	  (0),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             COPYMODE,	  (0),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             MEASUREINIT,  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             PSTYLEPOLICY,  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             LWUNITS,	   (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             APBOX,		   (0),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             HPORIGINMODE,  (0),					(),       ValidateRange(0,5))
REGVAR_DEF(OdInt16,             HPDRAWORDER,  (3),					(),       ValidateRange(0,4))
REGVAR_DEF(OdInt16,             TOOLTIPS,  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(OdInt16,             PICKDRAG,  (0),					(),       ValidateRange(0,2))
REGVAR_DEF( OdString,           SAVEFILEPATH,     (OD_T("")),			(),       ValidatePath())
REGVAR_DEF(OdInt16,             CURSORSIZE,  (5),					(),       ValidateRange(1,100))
REGVAR_DEF(OdInt16,             PICKADD,  (2),					(),       ValidateRange(0,2))
REGVAR_DEF( OdString,           SAVEFILE,     (OD_T(".sv$")),			(),       ValidateNone())
REGVAR_DEF(OdInt16,             ZOOMFACTOR,  (60),					(),       ValidateRange(3,100))
REGVAR_DEF( OdString,           MTEXTED,     (OD_T("Internal")),			(),       ValidateNone())
REGVAR_DEF(OdInt16,             RASTERPREVIEW,  (1),					(),       ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  PEDITACCEPT,	 (0),			         (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  UCSORTHO,		(1),			         (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			ACADLSPASDOC,	 (0),			         (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			BACKGROUNDPLOT,	 (2),			         (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			CMDDIA,			 (1),			         (),ValidateRange(0,1))
REGVAR_DEF(	OdString,			DCTCUST,		 (OdString::kEmpty), (),ValidateNone())
REGVAR_DEF(	OdString,			DCTMAIN,		 (OdString::kEmpty), (),ValidateNone())
REGVAR_DEF(	OdInt16,			DEMANDLOAD,		 (3),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			DRAGP1,			 (10),			     (),ValidateNone())
REGVAR_DEF(	OdInt16,			DRAGP2,			 (25),			     (),ValidateNone())
REGVAR_DEF(	OdInt16,			DWGCHECK,		 (1),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			IMAGEHLT,		 (0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			INSUNITSDEFSOURCE,		 (4),			     (),ValidateRange(0,20))
REGVAR_DEF(	OdInt16,			INSUNITSDEFTARGET,		 (4),			     (),ValidateRange(0,20))
REGVAR_DEF(	OdInt16,			ISAVEBAK,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			ISAVEPERCENT,			(50),			     (),ValidateRange(0,100))
REGVAR_DEF(	OdString,			LOGFILEPATH,		 (OdString::kEmpty), (),ValidatePath())
REGVAR_DEF(	OdInt16,			MBUTTONPAN,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			MENUCTL,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			MTEXTFIXED,				(2),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdString,			MTJIGSTRING,		 (OD_T("abc")), (),ValidateNone())
REGVAR_DEF(	OdInt16,			OFFSETGAPTYPE,				(0),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			OLEHIDE,				(0),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			OLEQUALITY,				(3),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			OSNAPCOORD,				(2),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			PALETTEOPAQUE,				(0),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			PAPERUPDATE,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			PLOTOFFSET,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			PLOTROTMODE,				(2),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			PLQUIET,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdString,			POLARADDANG,		 (OdString::kEmpty), (),ValidateNone())
REGVAR_DEF(	ODTORIENT,		POLARANG,				(OdaPI2),			     (),ValidateNone())
REGVAR_DEF(	double,				POLARDIST,				(0),			     (),ValidateNone())
REGVAR_DEF(	OdInt16,			PROXYNOTICE,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			PROXYWEBSEARCH,				(1),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			RASTERDPI,				(300),			     (),ValidateRange(100,32767))
REGVAR_DEF(	OdInt16,			REMEMBERFOLDERS,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			REPORTERROR,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			RTDISPLAY,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			SHORTCUTMENU,				(11),			     (),ValidateRange(0,31))
REGVAR_DEF(	OdInt16,			SNAPTYPE,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			STANDARDSVIOLATION,				(2),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			TRAYICONS,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			TRAYNOTIFY,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			TRAYTIMEOUT,				(0),			     (),ValidateRange(0,10))
REGVAR_DEF(	OdInt16,			UCSAXISANG,				(90),			     (),ValidateRange(5,180))
REGVAR_DEF(	OdInt16,			WHIPARC,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			WHIPTHREAD,				(2),			     (),ValidateRange(0,3))
REGVAR_DEF(	OdInt16,			XLOADCTL,				(1),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdString,			XLOADPATH,		 (OdString::kEmpty), (),ValidateNone())
REGVAR_DEF(	OdInt16,			XREFCTL,				(0),			     (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			XREFNOTIFY,				(2),			     (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			XREFTYPE,				(0),			     (),ValidateRange(0,1))

REGVAR_DEF(	OdInt16,			  DYNDIGRIP,	    (31),          (),ValidateRange(0,31))
REGVAR_DEF(	OdInt16,			  DYNDIVIS,	      (1),           (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			  DYNMODE,	      (3),           (),ValidateRange(-3,3))
REGVAR_DEF(	OdInt16,			  DYNPICOORDS,	  (0),					 (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  DYNPIFORMAT,	  (0),					 (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  DYNPIVIS,	      (1),					 (),ValidateRange(0,2))
REGVAR_DEF(	OdInt16,			  DYNPROMPT,	    (1),					 (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  DYNTOOLTIPS,	  (1),				   (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  SELECTIONAREA,	(1),					 (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  SHOWLAYERUSAGE,	(0),					 (),ValidateRange(0,1))
REGVAR_DEF(	OdInt16,			  LAYERFILTERALERT,	(2),					 (),ValidateRange(0,3))

REGVAR_DEF(OdInt16        ,3DCONVERSIONMODE     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,3DOSMODE     ,(11)    ,()    ,ValidateRange(0,256))
REGVAR_DEF(OdInt16        ,3DSELECTIONMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdString        ,ACTPATH     ,(OD_T(""))    ,()    ,ValidateNone())
REGVAR_DEF(OdString        ,ACTRECPATH     ,(OD_T(""))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,ACTUI     ,(6)    ,()    ,ValidateRange(0,7))
REGVAR_DEF(OdInt16        ,ANNOAUTOSCALE     ,(-4)    ,()    ,ValidateRange(-4,4))
REGVAR_DEF(OdInt16        ,APPLYGLOBALOPACITIES     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,ATTIPE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,ATTMULTI     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,AUTODWFPUBLISH     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,BACTIONBARMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdCmColor        ,BACTIONCOLOR     ,(OdCmColor(OdCmEntityColor::kByACI,7))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,BDEPENDENCYHIGHLIGHT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdCmColor        ,BGRIPOBJCOLOR     ,(OdCmColor(OdCmEntityColor::kByACI,141))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,BGRIPOBJSIZE     ,(8)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,BLOCKEDITLOCK     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdCmColor        ,BPARAMETERCOLOR     ,(OdCmColor(OdCmEntityColor::kByACI,170))    ,()    ,ValidateNone())
REGVAR_DEF(OdString        ,BPARAMETERFONT     ,(OD_T("Arial"))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,BPARAMETERSIZE     ,(12)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,BPTEXTHORIZONTAL     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,BTMARKDISPLAY     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CALCINPUT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CAPTURETHUMBNAILS     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,CBARTRANSPARENCY     ,(50)    ,()    ,ValidateRange(10,90))
REGVAR_DEF(OdInt16        ,CCONSTRAINTFORM     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CENTERMT     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CLASSICKEYS     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CMDINPUTHISTORYMAX     ,(20)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,CONSTRAINTBARDISPLAY     ,(3)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,CONSTRAINTBARMODE     ,(4095)    ,()    ,ValidateRange(0,4095))
REGVAR_DEF(OdInt16        ,CONSTRAINTINFER     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CONSTRAINTNAMEFORMAT     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,CONSTRAINTSOLVEMODE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CROSSINGAREACOLOR     ,(100)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,CULLINGOBJ     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,CULLINGOBJSELECTION     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,DATALINKNOTIFY     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,DBLCLKEDIT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdString        ,DEFLPLSTYLE     ,(OD_T("ByColor"))    ,()    ,ValidateNone())
REGVAR_DEF(OdString        ,DEFPLSTYLE     ,(OD_T("ByColor"))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,DIMCONSTRAINTICON     ,(0)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,DIVMESHBOXHEIGHT     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHBOXLENGTH     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHBOXWIDTH     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHCONEAXIS     ,(8)    ,()    ,ValidateRange(3,256))
REGVAR_DEF(OdInt16        ,DIVMESHCONEBASE     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHCONEHEIGHT     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHCYLAXIS     ,(8)    ,()    ,ValidateRange(3,256))
REGVAR_DEF(OdInt16        ,DIVMESHCYLBASE     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHCYLHEIGHT     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHPYRBASE     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHPYRHEIGHT     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHPYRLENGTH     ,(3)    ,()    ,ValidateRange(1,256))
REGVAR_DEF(OdInt16        ,DIVMESHSPHEREAXIS     ,(12)    ,()    ,ValidateRange(3,512))
REGVAR_DEF(OdInt16        ,DIVMESHSPHEREHEIGHT     ,(6)    ,()    ,ValidateRange(2,1024))
REGVAR_DEF(OdInt16        ,DIVMESHTORUSPATH     ,(8)    ,()    ,ValidateRange(3,512))
REGVAR_DEF(OdInt16        ,DIVMESHTORUSSECTION     ,(8)    ,()    ,ValidateRange(3,512))
REGVAR_DEF(OdInt16        ,DIVMESHWEDGEBASE     ,(3)    ,()    ,ValidateRange(1,64))
REGVAR_DEF(OdInt16        ,DIVMESHWEDGEHEIGHT     ,(3)    ,()    ,ValidateRange(1,64))
REGVAR_DEF(OdInt16        ,DIVMESHWEDGELENGTH     ,(4)    ,()    ,ValidateRange(1,64))
REGVAR_DEF(OdInt16        ,DIVMESHWEDGESLOPE     ,(3)    ,()    ,ValidateRange(1,64))
REGVAR_DEF(OdInt16        ,DIVMESHWEDGEWIDTH     ,(3)    ,()    ,ValidateRange(1,64))
REGVAR_DEF(OdInt16        ,DYNCONSTRAINTMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdString        ,ENTERPRISEMENU     ,(OD_T("."))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,ERHIGHLIGHT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,EXPORTEPLOTFORMAT     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(double        ,FACETERDEVNORMAL     ,(OdaToRadian(40))    ,()    ,ValidateRange(0,OdaPI))
REGVAR_DEF(double        ,FACETERDEVSURFACE     ,(0.001)    ,()    ,ValidatePositive())
REGVAR_DEF(double        ,FACETERGRIDRATIO     ,(0.0)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(double        ,FACETERMAXEDGELENGTH     ,(0.0)    ,()    ,ValidatePositive())
REGVAR_DEF(OdInt16        ,FACETERMAXGRID     ,(4096)    ,()    ,ValidateRange(0,4096))
REGVAR_DEF(OdInt16        ,FACETERMESHTYPE     ,(0)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,FACETERMINUGRID     ,(0)    ,()    ,ValidateRange(0,1023))
REGVAR_DEF(OdInt16        ,FACETERMINVGRID     ,(0)    ,()    ,ValidateRange(0,1023))
REGVAR_DEF(OdInt16        ,FACETERPRIMITIVEMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,FACETERSMOOTHLEV     ,(1)    ,()    ,ValidateRange(-4,4))
REGVAR_DEF(OdInt16        ,FULLPLOTPATH     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,GLOBALOPACITY     ,(100)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(OdInt16        ,GRIDSTYLE     ,(0)    ,()    ,ValidateRange(0,7))
REGVAR_DEF(OdInt16        ,GRIPCONTOUR     ,(251)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,GRIPMULTIFUNCTIONAL     ,(3)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,GRIPSUBOBJMODE     ,(1)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,GTAUTO     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,GTDEFAULT     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,GTLOCATION     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdString       ,HELPPREFIX     ,(OD_T(""))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,HPDLGMODE     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt32        ,HPMAXLINES     ,(300000)    ,()    ,ValidateRange(100,1000000))
REGVAR_DEF(OdInt32        ,HPMAXAREAS     ,(100)    ,()    ,ValidateRange(0,10000000))
REGVAR_DEF(OdInt32        ,HPOBJWARNING     ,(10000)    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,HPORIGINSTOREASDEFAULT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,HPQUICKPREVIEW     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,HPQUICKPREVTIMEOUT     ,(2)    ,()    ,ValidateRange(1,300))
REGVAR_DEF(OdInt16        ,HPSEPARATE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,HPLINETYPE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,IMPLIEDFACE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,INPUTHISTORYMODE     ,(15)    ,()    ,ValidateRange(0,15))
REGVAR_DEF(OdInt16        ,INTELLIGENTUPDATE     ,(20)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(OdInt16        ,LARGEOBJECTSUPPORT     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,LAYERDLGMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,LAYEREVALCTL     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,LAYLOCKFADECTL     ,(50)    ,()    ,ValidateRange(-90,90))
REGVAR_DEF(OdInt16        ,LAYOUTREGENCTL     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,LEGACYCTRLPICK     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,LOCKUI     ,(0)    ,()    ,ValidateRange(0,15))
REGVAR_DEF(OdInt16        ,MATBROWSERSTATE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdString       ,MATERIALSPATH     ,(OD_T(""))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,MENUBAR     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,MDITAB      ,(1)    ,()    ,ValidateRange(0,1))
//REGVAR_DEF(OdString        ,MENUNAME     ,(OD_T(""))    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,MTEXTTOOLBAR     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,NAVBARDISPLAY     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,NAVSWHEELMODE     ,(2)    ,()    ,ValidateRange(0,6))
REGVAR_DEF(OdInt16        ,NAVSWHEELOPACITYBIG     ,(50)    ,()    ,ValidateRange(25,90))
REGVAR_DEF(OdInt16        ,NAVSWHEELOPACITYMINI     ,(50)    ,()    ,ValidateRange(25,90))
REGVAR_DEF(OdInt16        ,NAVSWHEELSIZEBIG     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,NAVSWHEELSIZEMINI     ,(1)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,NAVVCUBELOCATION     ,(0)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,NAVVCUBEOPACITY     ,(50)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(OdInt16        ,NAVVCUBEORIENT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,NAVVCUBESIZE     ,(4)    ,()    ,ValidateRange(0,4))
REGVAR_DEF(OdInt16        ,OBJECTISOLATIONMODE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,OSNAPNODELEGACY     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PARAMETERCOPYMODE     ,(1)    ,()    ,ValidateRange(0,4))
REGVAR_DEF(OdInt16        ,PARAMETERSSTATUS     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(double         ,PERSPECTIVECLIP     ,(5.0)    ,()    ,ValidateRange(0.01,10.0))
REGVAR_DEF(OdInt16        ,PLINECONVERTMODE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PLOTTRANSPARENCYOVERRIDE     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,POINTCLOUDAUTOUPDATE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt32        ,POINTCLOUDLOCK     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PREVIEWEFFECT     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,PREVIEWFACEEFFECT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PREVIEWFILTER     ,(7)    ,()    ,ValidateRange(0,63))
REGVAR_DEF(OdInt16        ,PUBLISHALLSHEETS     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PUBLISHCOLLATE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,QPLOCATION     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,QPMODE     ,(-1)    ,()    ,ValidateRange(-2,2))
REGVAR_DEF(OdInt16        ,QVDRAWINGPIN     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,QVLAYOUTPIN     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,RASTERPERCENT     ,(20)    ,()    ,ValidateRange(1,100))
REGVAR_DEF(OdInt16        ,RASTERTHRESHOLD     ,(20)    ,()    ,ValidateRange(0,2000))
REGVAR_DEF(OdInt16        ,REBUILD2DCV     ,(6)    ,()    ,ValidateRange(2,32767))
REGVAR_DEF(OdInt16        ,REBUILD2DDEGREE     ,(3)    ,()    ,ValidateRange(1,11))
REGVAR_DEF(OdInt16        ,REBUILD2DOPTION     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,REBUILDDEGREEU     ,(3)    ,()    ,ValidateRange(2,11))
REGVAR_DEF(OdInt16        ,REBUILDDEGREEV     ,(3)    ,()    ,ValidateRange(2,11))
REGVAR_DEF(OdInt16        ,REBUILDOPTIONS     ,(1)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,REBUILDU     ,(6)    ,()    ,ValidateRange(2,32767))
REGVAR_DEF(OdInt16        ,REBUILDV     ,(6)    ,()    ,ValidateRange(2,32767))
REGVAR_DEF(OdInt16        ,RECOVERAUTO     ,(0)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,RECOVERYMODE     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,RENDERUSERLIGHTS     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,RIBBONCONTEXTSELECT     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,RIBBONCONTEXTSELLIM     ,(2500)    ,()    ,ValidateRange(0,32767))
REGVAR_DEF(OdInt16        ,RIBBONDOCKEDHEIGHT     ,(100)    ,()    ,ValidateRange(0,500))
REGVAR_DEF(OdInt16        ,RIBBONSELECTMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,ROLLOVEROPACITY     ,(100)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(OdInt16        ,ROLLOVERTIPS     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SCREENMENU     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SELECTIONANNODISPLAY     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SELECTIONAREAOPACITY     ,(25)    ,()    ,ValidateRange(0,100))
REGVAR_DEF(OdInt16        ,SELECTIONCYCLING     ,(2)    ,()    ,ValidateRange(-2,2))
REGVAR_DEF(OdInt16        ,SELECTIONPREVIEW     ,(3)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,SELECTSIMILARMODE     ,(130)    ,()    ,ValidateRange(0,255))
REGVAR_DEF(OdInt16        ,SETBYLAYERMODE     ,(255)    ,()    ,ValidateRange(0,255))
REGVAR_DEF(OdInt16        ,SHOWMOTIONPIN     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SHOWPALETTESTATE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SIGWARN     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SMOOTHMESHCONVERT     ,(0)    ,()    ,ValidateRange(0,7))
REGVAR_DEF(OdInt16        ,SMOOTHMESHGRID     ,(3)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt32        ,SMOOTHMESHMAXFACE     ,(1000000)    ,()    ,ValidateRange(1,16000000))
REGVAR_DEF(OdInt16        ,SMOOTHMESHMAXLEV     ,(4)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,SSLOCATE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SSMAUTOOPEN     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SSMPOLLTIME     ,(60)    ,()    ,ValidateRange(20,600))
REGVAR_DEF(OdInt16        ,SSMSHEETSTATUS     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,STATUSBAR     ,(1)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,SURFACEASSOCIATIVITYDRAG     ,(1)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,SURFACEAUTOTRIM     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,SPACESWITCH     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,TABLEINDICATOR     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,TABLETOOLBAR     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,TBCUSTOMIZE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,TEMPOVERRIDES     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,TEXTED     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,TEXTOUTPUTFILEFORMAT     ,(0)    ,()    ,ValidateRange(0,3))
REGVAR_DEF(OdInt16        ,TOOLTIPMERGE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,TRANSPARENCYDISPLAY     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt32        ,TREEMAX     ,(10000000)    ,()    ,ValidateNone())
REGVAR_DEF(OdInt16        ,TSPACETYPE     ,(1)    ,()    ,ValidateRange(1,2))
REGVAR_DEF(OdInt16        ,UCSDETECT     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,UOSNAP     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,VPLAYEROVERRIDESMODE     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,VPROTATEASSOC     ,(1)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,VTDURATION     ,(750)    ,()    ,ValidateRange(0,5000))
REGVAR_DEF(OdInt16        ,VTENABLE     ,(3)    ,()    ,ValidateRange(0,7))
REGVAR_DEF(OdInt16        ,VTFPS     ,(7)    ,()    ,ValidateRange(1,30))
REGVAR_DEF(OdInt16        ,WINDOWAREACOLOR     ,(150)    ,()    ,ValidateRange(1,255))
REGVAR_DEF(OdInt16        ,WSAUTOSAVE     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,XDWGFADECTL     ,(50)    ,()    ,ValidateRange(-90,90))
REGVAR_DEF(OdInt16        ,ZOOMWHEEL     ,(0)    ,()    ,ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,MTEXTCOLUMN,	  (0),					(),       ValidateRange(0,2))
REGVAR_DEF(OdInt16        ,QAFLAGS,				(0),			     (),ValidateRange(0,32767))
REGVAR_DEF(ODTBOOL        ,DxfTextAdjustAlignment,  (true),  (),       ValidateBOOL())
REGVAR_DEF(OdInt16        ,LAYOUTSETTINGS     ,(47)    ,()    ,ValidateRange(0,32767))
REGVAR_DEF(OdInt16        ,SDI,(0),			  (0),     ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,PSQUALITY,				(75),			     (),ValidateRange(-32768,32767))
REGVAR_DEF(OdInt16        ,BLKOPT,				(1),			     (),ValidateRange(0,1))
REGVAR_DEF(OdInt16        ,DTEXTED     ,(2)    ,()    ,ValidateRange(0,2))
REGVAR_DEF(OdInt16,   POINTCLOUDBOUNDARY,     (1),                  (),        ValidateRange(0,1))
REGVAR_DEF(OdUInt32,  POINTCLOUDPOINTMAX,     (1500000),            (),        ValidateNone())
REGVAR_DEF(OdInt32,        POINTCLOUDPOINTMAXLEGACY,      (1500000),            (),             ValidateRange(1500000,10000000))
REGVAR_DEF(OdInt16,        POINTCLOUDLOD,                      (10),            (),             ValidateRange(1,10))
REGVAR_DEF(OdInt16,   POINTCLOUDDENSITY,      (15),                 (),        ValidateRange(1,100))
REGVAR_DEF(OdInt16,   POINTCLOUDRTDENSITY,    (5),                  (),        ValidateRange(1,100))
REGVAR_DEF(bool,                AllowSavingEmptyAcisObjects,  (false),               (),       ValidateBOOL())

REGVAR_DEF(bool, EnableAcisAudit, (false), (), ValidateBOOL())

REGVAR_DEF(OdInt16, FRAMESELECTION, (1), (0), ValidateRange(0, 1))
REGVAR_DEF(OdInt16, SURFACEASSOCIATIVITY, (1), (), ValidateRange(0, 1))
REGVAR_DEF(OdInt16, SURFACEMODELINGMODE, (0), (), ValidateRange(0, 1))

//未保存
#ifndef SEGVAR_DEF
#define SEGVAR_DEF REGVAR_DEF
#endif

SEGVAR_DEF(OdInt16        ,EXPLMODE,  (1),        (1),         ValidateRange(0,1))
SEGVAR_DEF(OdString       ,MODEMACRO, (OD_T("")), (),          ValidateNone())
SEGVAR_DEF(OdInt16        ,LISPINIT,  (1),        (),          ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,OSNAPZ,		(0),			  (0),         ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,FACETRATIO,(0),			  (0),     ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,GLOBCHECK,(0),			  (0),     ValidateRange(0,3))
SEGVAR_DEF(OdInt16        ,HIDEPRECISION,(0),			  (0),     ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,NOMUTT,(0),			  (0),     ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,SOLIDCHECK,(1),			  (1),     ValidateRange(0,1))
SEGVAR_DEF(OdInt16        ,OSNAPHATCH,(0),			  (0),     ValidateRange(0,1))
SEGVAR_DEF(OdInt32        ,PHANDLE,(0),			  (0),     ValidateNone())
SEGVAR_DEF(OdInt16        ,HIGHLIGHT   ,(1)    ,()    ,ValidateRange(0,1))

#undef SEGVAR_DEF

#undef ODTDB_PROXYIMAGE

#endif //#ifdef REGVAR_DEF


#undef ODTBOOL
#undef ODTDIST
#undef ODTORIENT
#undef ODTUNITLESS4
#undef ODTUNITLESS8
#undef ODTDB_MEASUREMENTVALUE
#undef ODTDB_LINEWEIGHT
#undef ODTDB_JOINSTYLE
#undef ODTDB_UNITSVALUE
#undef ODTDB_PROXYIMAGE
#undef ODTDB_MEASUREMENTVALUE
#undef ODTTEXTSTYLEID
#undef ODTLAYERID
#undef ODTLINETYPEID
#undef ODTDIMSTYLEID
#undef ODTUCSID
#undef ODTMLSTYLEID
#undef ODTDB_ENDCAPS
#undef ODTDB_JOINSTYLE
#undef ODTDB_PLOTSTYLENAMETYPE
#undef ODTDB_TIMEZONE
#undef ODTMATERIALID
#undef ODVISTYLEID
#undef ODTTABLESTYLEID
#undef ODTMLEADERSTYLEID
#undef ODANNOSCALE


