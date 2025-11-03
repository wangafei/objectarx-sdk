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



#ifndef QVAR_DEF_RO
#define DOUNDEF_QVAR_DEF_RO
#define QVAR_DEF_RO  QVAR_DEF /* {Secret} */
#endif

#ifndef QVAR_DEF_RO
#define DOUNDEF_QVAR_DEF_RO
#define QVAR_DEF_RO  QVAR_DEF /* {Secret} */
#endif


#ifndef ODTDIST
#define ODTDIST  double /* {Secret} */
#define DOUNDEF_ODTDIST
#endif

#ifndef ODTORIENT
#define ODTORIENT  double /* {Secret} */
#define DOUNDEF_ODTORIENT
#endif

#ifndef ODTANGLE
#define ODTANGLE double /* {Secret} */
#define DOUNDEF_ODTANGLE
#endif

#ifndef ODTLAYOUTID
#define ODTLAYOUTID  OdDbObjectId /* {Secret} */
#define DOUNDEF_ODTLAYOUTID
#endif

#ifndef ODTTEXTSTYLEID
#define ODTTEXTSTYLEID  OdDbObjectId /* {Secret} */
#define DOUNDEF_ODTTEXTSTYLEID
#endif

#ifndef ODTBOOL
#define ODTBOOL  bool /* {Secret} */
#define DOUNDEF_ODTBOOL
#endif

/*
#ifdef DATE
#define SAVED_DATE_DEFINITION
#undef DATE
#endif
*/

//         Type                   Name

QVAR_DEF_RO(ODTDIST,              BACKZ,            ValidateNone()    )
QVAR_DEF   (ODTLAYOUTID,          CTAB,             ValidateLayout()  )
QVAR_DEF   (OdString,             CPLOTSTYLE,       ValidateNone()    )
QVAR_DEF   (OdInt16,              CVPORT,           ValidateRange(0, 32767)    )
QVAR_DEF_RO(OdString,             DWGNAME,          ValidateNone()    )
QVAR_DEF_RO(OdString,             DWGPREFIX,        ValidateNone()    )
QVAR_DEF_RO(ODTBOOL,              DWGTITLED,        ValidateNone()    )
QVAR_DEF   (ODTDIST,              ELEVATION,        ValidateNone()    )
QVAR_DEF_RO(OdGePoint3d,          EXTMAX,           ValidateNone()    )
QVAR_DEF_RO(OdGePoint3d,          EXTMIN,           ValidateNone()    )
QVAR_DEF_RO(ODTDIST,              FRONTZ,           ValidateNone()    )
QVAR_DEF   (ODTBOOL,              GRIDMODE,         ValidateBOOL()    )
QVAR_DEF   (OdGePoint2d,          GRIDUNIT,         ValidateNone()    )
QVAR_DEF   (OdGePoint3d,          INSBASE,          ValidateNone()    )
QVAR_DEF_RO(ODTDIST,              LENSLENGTH,       ValidateNone()    )
QVAR_DEF   (ODTBOOL,              LIMCHECK,         ValidateBOOL()    )
QVAR_DEF   (OdGePoint2d,          LIMMAX,           ValidateNone()    )
QVAR_DEF   (OdGePoint2d,          LIMMIN,           ValidateNone()    )
QVAR_DEF   (ODTANGLE,             SNAPANG,          ValidateNone()    )
QVAR_DEF   (OdGePoint2d,          SNAPBASE,         ValidateNone()    )
QVAR_DEF   (OdInt16,              SNAPISOPAIR,      ValidateRange(0, 2)    )
QVAR_DEF   (ODTBOOL,              SNAPMODE,         ValidateBOOL()    )
QVAR_DEF   (ODTBOOL,              SNAPSTYL,         ValidateBOOL()    )
QVAR_DEF   (OdGePoint2d,          SNAPUNIT,         ValidateNone()    )
QVAR_DEF_RO(OdCodePageId,         SYSCODEPAGE,      ValidateNone()    )
QVAR_DEF_RO(OdGePoint3d,          TARGET,           ValidateNone()    )
QVAR_DEF   (ODTBOOL,              UCSFOLLOW,        ValidateBOOL()    )
QVAR_DEF   (OdInt16,              UCSICON,          ValidateNone()    )
QVAR_DEF   (ODTBOOL,              UCSVP,            ValidateBOOL()    )
QVAR_DEF_RO(ODTUCSNAME,           UCSNAME,          ValidateNone()    )
QVAR_DEF_RO(OdGePoint3d,          UCSORG,           ValidateNone()    )
QVAR_DEF_RO(OdGeVector3d,         UCSXDIR,          ValidateNone()    )
QVAR_DEF_RO(OdGeVector3d,         UCSYDIR,          ValidateNone()    )
QVAR_DEF_RO(OdGePoint3d,          VIEWCTR,          ValidateNone()    )
QVAR_DEF_RO(OdGeVector3d,         VIEWDIR,          ValidateNone()    )
QVAR_DEF_RO(OdInt16,              VIEWMODE,         ValidateNone()    )
QVAR_DEF_RO(ODTDIST,              VIEWSIZE,         ValidateNone()    )
QVAR_DEF_RO(ODTORIENT,            VIEWTWIST,        ValidateNone()    )
QVAR_DEF_RO(OdInt16,              WORLDUCS,         ValidateNone()    )
QVAR_DEF_RO(OdString,             LOGINNAME,        ValidateNone()    )
QVAR_DEF_RO(OdDbDate,             DATE,             ValidateNone()    )
QVAR_DEF_RO(double,               CANNOSCALEVALUE,  ValidateNone()    )
QVAR_DEF_RO(OdInt16,               DIMANNO,  ValidateNone()    )
QVAR_DEF(OdInt16,               ANNOALLVISIBLE,  ValidateRange(0,1)    )
/* TODO:
 CANNOSCALEVALUE
*/
QVAR_DEF   (OdInt16,              GRIDMAJOR,      ValidateRange(1,100) )
QVAR_DEF   (OdInt16,              GRIDDISPLAY,      ValidateRange(0,15) )

QVAR_DEF   (ODTBOOL,              PERSPECTIVE,      ValidateNone()    )
QVAR_DEF   (OdInt16,              DIMUNIT,          ValidateNone()    )

//-----------------------------------------
// Variables added in AC 2010 
//-----------------------------------------

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    IMAGEFRAME Controls whether image frames are displayed and plotted"
      "\n"
      "\n    @table"
      "\n    Value   Description"
      "\n    0       Invisible"
      "\n    1       Is displayed and plotted"
      "\n    2       Is displayed but not plotted"
    </remarks>
  </properties>
*/
QVAR_DEF   (OdInt16,              IMAGEFRAME,       ValidateNone()    )
QVAR_DEF   (OdInt16,              FRAME,            ValidateNone()    )
QVAR_DEF   (OdInt16,              PDFFRAME,         ValidateNone()    )
QVAR_DEF   (OdInt16,              XCLIPFRAME,       ValidateNone()    )
QVAR_DEF   (OdInt8,               DWFFRAME,         ValidateNone()    )
QVAR_DEF   (OdInt8,               DGNFRAME,         ValidateNone()    )
QVAR_DEF   (OdInt8,               OLEFRAME,         ValidateNone()    )
QVAR_DEF   (OdInt16,              WIPEOUTFRAME,        ValidateNone()    )

QVAR_DEF   (ODTTEXTSTYLEID,       TEXTSTYLE,        ValidateTextStyle())
QVAR_DEF   (double,               TEXTSIZE,         ValidateNone()    )
QVAR_DEF_RO(OdDbDate,             CDATE,            ValidateNone()    )
QVAR_DEF_RO(ODTBOOL,              FULLOPEN,         ValidateBOOL()    )
QVAR_DEF   (OdInt16,              ZOOMPERCENT,      ValidateRange(1,20000) )
QVAR_DEF   (double, EXPVALUE,     ValidateNone())
QVAR_DEF   (double, EXPWHITEBALANCE, ValidateNone())
QVAR_DEF   (OdInt16, DEFAULTLIGHTING, ValidateRange(0, 1))
QVAR_DEF   (OdInt16, DEFAULTLIGHTINGTYPE, ValidateRange(0, 1))
QVAR_DEF   (OdInt16, SUNSTATUS, ValidateRange(0, 1))


QVAR_DEF(OdInt16, VSBACKGROUNDS, ValidateNone())

/**
<title VSEDGECOLOR>
<toctitle VSEDGECOLOR>

<table>
<b>Type</b>            OdString
<b>Initial value</b>   "ByEntity"
<b>Read-Only</b>       No
<b>Saved In</b>        Database
<b>Versions</b>        2007+
</table>

The VSEDGECOLOR variable stores the tint of edges in the visual style for the current viewport.
TrueColor value is set as follows: "RGB:XXX,XXX,XXX", where XXX is the color component value in
the range 0 to 255. Value 0 defines a color ByBlock, value 256 defines a color ByLayer, value 257
defines a color ByEntity, values 1 to 255 define the ACI color.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGECOLOR");
OdString tint = pRb-\>getString();
odPrintConsoleString(L"nColor of edges = %s", tint);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtString, L"RGB:128,128,128");
pDb-\>setSysVar(L"VSEDGECOLOR", pRb);
</code>

<group TD_SysVars_G>
*/
//<dom_var_def>OdString VSEDGECOLOR;
QVAR_DEF(OdString, VSEDGECOLOR, ValidateNone())

/**
<title VSEDGEJITTER>
<toctitle VSEDGEJITTER>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   (?)
<b>Read-Only</b>       No
<b>Saved In</b>        Database
<b>Versions</b>        2010+
</table>

The VSEDGEJITTER variable switches the display of edges to be viewed with several linear streaks,
as if the edges were sketched using a pencil. The value defines the number of jitters which can be:

<table>
<b>Value</b>   <b>Description</b>
1              Low jitters
2              Medium jitters
3              High jitters
</table>

A negative value turns off the sketch effect, but the variable continues to store the number of jitters.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current
viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGEJITTER");
OdInt16 jitters = pRb-\>getInt16();
odPrintConsoleString(L"nJitters = %d", jitters);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSEDGEJITTER", pRb)
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSEDGEJITTER;
QVAR_DEF(OdInt16, VSEDGEJITTER, ValidateNone())

/**
<title VSEDGELEX>
<toctitle VSEDGELEX>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   (?)
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2011+
</table>

The VSEDGELEX variable allows edges to extend beyond their intersection for 3D entities.
The admissible range is 1 to 100 pixels. A negative value turns off the line extensions
effect, but the variable continues to store the previous setting.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGELEX");
OdInt16 effect = pRb-\>getInt16();
odPrintConsoleString(L"nLine extensions effect = %d", effect);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 10);
pDb-\>setSysVar(L"VSEDGELEX", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSEDGELEX;
QVAR_DEF(OdInt16, VSEDGELEX, ValidateNone())

/**
<title VSEDGEOVERHANG>
<toctitle VSEDGEOVERHANG>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   (?)
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSEDGEOVERHANG variable overhangs edges that extend beyond their intersections for 3D entities.
The value can be in the range 1 to 100 pixels. A negative value turns off the overhang effect,
but the variable continues to store the setting.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGEOVERHANG");
OdInt16 effect = pRb-\>getInt16();
odPrintConsoleString(L"nOverhang effect = %d", effect);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 10);
pDb-\>setSysVar(L"VSEDGEOVERHANG", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSEDGEOVERHANG;
QVAR_DEF(OdInt16, VSEDGEOVERHANG, ValidateNone())

/**
<title VSEDGES>
<toctitle VSEDGES>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSEDGES variable stores the type of edges which are used for displaying in the current viewport.
The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Edges are not displayed
1              Isolines of edges are displayed
2              Facet edges are displayed
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGES");
OdInt16 type = pRb-\>getInt16();
odPrintConsoleString(L"nEdge type = %d", type);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSEDGES", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSEDGES;
QVAR_DEF(OdInt16, VSEDGES, ValidateNone())

/**
<title VSEDGESMOOTH>
<toctitle VSEDGESMOOTH>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSEDGESMOOTH variable stores the angle at which edges are displayed in the current viewport.
The value can be in the range 0 to 180 degrees.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSEDGESMOOTH");
OdInt16 angle = pRb-\>getInt16();
odPrintConsoleString(L"nAngle = %d", angle);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 90);
pDb-\>setSysVar(L"VSEDGESMOOTH", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSEDGESMOOTH;
QVAR_DEF(OdInt16, VSEDGESMOOTH, ValidateNone())

/**
<title VSFACECOLORMODE>
<toctitle VSFACECOLORMODE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSFACECOLORMODE variable stores the mode that defines how to calculate the face color.
The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Normal mode ?face color is not used.
1              Monochrome mode ?uses the color from VSMONOCOLOR system variable to display all faces.
2              Tint mode ?uses the color from VSMONOCOLOR system variable to shade all faces by changing the tint and saturation of colors.
3              Desaturate mode ?softens the color of all faces by reducing its saturation (30 percent).
</table>

<b>Note: </b> An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSFACECOLORMODE");
OdInt16 mode = pRb-\>getInt16();
odPrintConsoleString(L"nFace color mode = %d", mode);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSFACECOLORMODE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSFACECOLORMODE;
QVAR_DEF(OdInt16, VSFACECOLORMODE, ValidateNone())

/**
<title VSFACEHIGHLIGHT>
<toctitle VSFACEHIGHLIGHT>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   (?0)
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSFACEHIGHLIGHT variable stores the reflex highlights of faces without materials to be displayed
in the current viewport. The value can be in the range &#8211;100 to 100. The higher the value, the
larger the highlight. The smaller the value, the smaller the highlight. If the VSMATERIALMODE
system variable is on, attached materials ignore the highlight.

<b>Note: </b> An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSFACEHIGHLIGHT");
OdInt16 highlight = pRb-\>getInt16();
odPrintConsoleString(L"nFace highlight = %d", highlight);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 60);
pDb-\>setSysVar(L"VSFACEHIGHLIGHT", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSFACEHIGHLIGHT;
QVAR_DEF(OdInt16, VSFACEHIGHLIGHT, ValidateNone())

/**
<title VSFACEOPACITY>
<toctitle VSFACEOPACITY>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   (?0)
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSFACEOPACITY variable switches the preset level of transparency for 3D entities.
The value can be in the range 0 to 100 percent. The value 100 is limpid, the value 0 is
opaque. A negative value stores the transparency but turns off the effect.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSFACEOPACITY");
OdInt16 transparency = pRb-\>getInt16();
odPrintConsoleString(L"nTransparency level = %d", transparency);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 50);
pDb-\>setSysVar(L"VSFACEOPACITY", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSFACEOPACITY;
QVAR_DEF(OdInt16, VSFACEOPACITY, ValidateNone())

/**
<title VSFACESTYLE>
<toctitle VSFACESTYLE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSFACESTYLE variable stores the face mode that defines how faces display in the current viewport.
The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Off ?style is not applied.
1              Real ?defines how the face would appear in the real world mode.
2              Gooch ?uses cool and warm colors instead of dark and light to display the faces which might be shadowed and difficult to review in the realistic mode.
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSFACESTYLE");
OdInt16 mode = pRb-\>getInt16();
odPrintConsoleString(L"nFace mode = %d", mode);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSFACESTYLE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSFACESTYLE;
QVAR_DEF(OdInt16, VSFACESTYLE, ValidateNone())

/**
<title VSHALOGAP>
<toctitle VSHALOGAP>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSHALOGAP variable stores the aureole gap in the visual style for the current viewport.
The value can be in the range 0 to 100.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSHALOGAP");
OdInt16 gap = pRb-\>getInt16();
odPrintConsoleString(L"nAureole gap = %d", gap);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 60);
pDb-\>setSysVar(L"VSHALOGAP", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSHALOGAP;
QVAR_DEF(OdInt16, VSHALOGAP, ValidateNone())

/**
<title VSINTERSECTIONCOLOR>
<toctitle VSINTERSECTIONCOLOR>

<table>
<b>Type</b>            OdString
<b>Initial value</b>   "7"
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSINTERSECTIONCOLOR variable stores the tint of intersection polylines in the visual style
for the current viewport when it is set to 2D Wireframe. Value 0 defines a color ByBlock,
value 256 defines a color ByLayer, value 257 defines a color ByEntity, values 1 to 255
define the ACI color.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSINTERSECTIONCOLOR");
OdString tint = pRb-\>getString();
odPrintConsoleString(L"nColor of intersection = %s", tint);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtString, L"128");
pDb-\>setSysVar(L"VSINTERSECTIONCOLOR", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdString VSINTERSECTIONCOLOR;
QVAR_DEF(OdString, VSINTERSECTIONCOLOR, ValidateNone())

/**
<title VSINTERSECTIONEDGES>
<toctitle VSINTERSECTIONEDGES>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSINTERSECTIONEDGES variable determines whether intersection edges are displayed in the visual style for the
current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Display off
1              Display on
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSINTERSECTIONEDGES");
OdInt16 status = pRb-\>getInt16();
odPrintConsoleString(L"nIntersection display status = %d", status);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSINTERSECTIONEDGES", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSINTERSECTIONEDGES;
QVAR_DEF(OdInt16, VSINTERSECTIONEDGES, ValidateNone())

/**
<title VSINTERSECTIONLTYPE>
<toctitle VSINTERSECTIONLTYPE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSINTERSECTIONLTYPE variable stores the linetype number defining the shape of intersection
lines in the visual style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
1              Solid line
2              Dashed line
3              Dotted line
4              Short dashed line
5              Medium dashed line
6              Long dashed line
7              Double short dashed line
8              Double medium dashed line
9              Double long dashed line
10             Medium long dashed line
11             Sparse dotted line
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSINTERSECTIONLTYPE");
OdInt16 linetype = pRb-\>getInt16();
odPrintConsoleString(L"nIntersection linetype = %d", linetype);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 5);
pDb-\>setSysVar(L"VSINTERSECTIONLTYPE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSINTERSECTIONLTYPE;
QVAR_DEF(OdInt16, VSINTERSECTIONLTYPE, ValidateNone())

/**
<title VSISOONTOP>
<toctitle VSISOONTOP>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSISOONTOP variable determines whether isolines are on top of shaded entities in the visual
style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Isolines off
1              Isolines on
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSISOONTOP");
OdInt16 status = pRb-\>getInt16();
odPrintConsoleString(L"nIsoline status = %d", status);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSISOONTOP", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSISOONTOP;
QVAR_DEF(OdInt16, VSISOONTOP, ValidateNone())

/**
<title VSLIGHTINGQUALITY>
<toctitle VSLIGHTINGQUALITY>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSLIGHTINGQUALITY variable stores the light quality mode in the visual style for the current
viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Faceted ?uses a single color for each face.
1              Smooth ?computes colors of faces as a gradient between the vertices.
2              Smoothest ?computes colors of faces for individual pixels using the per-pixel lighting setting.
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSLIGHTINGQUALITY");
OdInt16 mode = pRb-\>getInt16();
odPrintConsoleString(L"nLight quality mode = %d", mode);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 2);
pDb-\>setSysVar(L"VSLIGHTINGQUALITY", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSLIGHTINGQUALITY;
QVAR_DEF(OdInt16, VSLIGHTINGQUALITY, ValidateNone())

/**
<title VSMATERIALMODE>
<toctitle VSMATERIALMODE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSMATERIALMODE variable stores the material mode that defines how materials are to be
displayed in the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Materials are not displayed.
1              Textures are not displayed and materials are displayed.
2              Textures and materials are displayed.
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSMATERIALMODE");
OdInt16 mode = pRb-\>getInt16();
odPrintConsoleString(L"nMaterial mode = %d", mode);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSMATERIALMODE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSMATERIALMODE;
QVAR_DEF(OdInt16, VSMATERIALMODE, ValidateNone())

/**
<title VSMONOCOLOR>
<toctitle VSMONOCOLOR>

<table>
<b>Type</b>            OdString
<b>Initial value</b>   "RGB:255,255,255"
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSMONOCOLOR variable stores the monochrome tint of faces in the visual style for the current
viewport. TrueColor value is set as follows: "RGB:XXX,XXX,XXX", where XXX is the color component
value in the range 0 to 255.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSMONOCOLOR");
OdString tint = pRb-\>getString();
odPrintConsoleString(L"nMonochrome color = %s", tint);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtString, L"RGB:128,128,128");
pDb-\>setSysVar(L"VSMONOCOLOR", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdString VSMONOCOLOR;
QVAR_DEF(OdString, VSMONOCOLOR, ValidateNone())

/**
<title VSOBSCUREDCOLOR>
<toctitle VSOBSCUREDCOLOR>

<table>
<b>Type</b>            OdString
<b>Initial value</b>   "ByEntity"
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSOBSCUREDCOLOR variable stores the tint of obscured (hidden) lines in the visual style for the
current viewport. TrueColor value is set as follows: "RGB:XXX,XXX,XXX", where XXX is the color
component value in the range 0 to 255. Value 0 defines a color ByBlock, value 256 defines a
color ByLayer, value 257 defines a color ByEntity, values 1 to 255 define the ACI color.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOBSCUREDCOLOR");
OdString tint = pRb-\>getString();
odPrintConsoleString(L"nColor of obscured lines = %s", tint);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtString, L"RGB:128,128,128");
pDb-\>setSysVar(L"VSOBSCUREDCOLOR", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdString VSOBSCUREDCOLOR;
QVAR_DEF(OdString, VSOBSCUREDCOLOR, ValidateNone())

/**
<title VSOBSCUREDEDGES>
<toctitle VSOBSCUREDEDGES>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSOBSCUREDEDGES variable determines whether obscured (hidden) edges are displayed in the
visual style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Display off
1              Display on
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOBSCUREDEDGES");
OdInt16 status = pRb-\>getInt16();
odPrintConsoleString(L"nObscured edges display status = %d", status);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 0);
pDb-\>setSysVar(L"VSOBSCUREDEDGES", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSOBSCUREDEDGES;
QVAR_DEF(OdInt16, VSOBSCUREDEDGES, ValidateNone())

/**
<title VSOBSCUREDLTYPE>
<toctitle VSOBSCUREDLTYPE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   Depends on the visual style
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSOBSCUREDLTYPE variable stores the linetype number defining the shape of obscured (hidden)
lines in the visual style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
1              Solid line
2              Dashed line
3              Dotted line
4              \Short dashed line
5              Medium dashed line
6              \Long dashed line
7              Double short dashed line
8              Double medium dashed line
9              Double long dashed line
10             Medium long dashed line
11             Sparse dotted line
</table>

The current visual style defines the initial value:

<table>
<b>Value</b>   <b>Description</b>
1              2D Wireframe
1              Conceptual
2              Hidden
1              Shaded
2              Shaded with Edges
1              Shades of Gray
1              Sketchy
1              Wireframe
1              X-ray
1              Realistic
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOBSCUREDLTYPE");
OdInt16 linetype = pRb-\>getInt16();
odPrintConsoleString(L"nObscured linetype = %d", linetype);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 5);
pDb-\>setSysVar(L"VSOBSCUREDLTYPE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSOBSCUREDLTYPE;
QVAR_DEF(OdInt16, VSOBSCUREDLTYPE, ValidateNone())

/**
<title VSOCCLUDEDCOLOR>
<toctitle VSOCCLUDEDCOLOR>

<table>
<b>Type</b>            OdString
<b>Initial value</b>   "ByEntity"
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2011+
</table>

The VSOCCLUDEDCOLOR variable stores the tint of occluded (hidden) lines in the visual style for
the current viewport. TrueColor value is set as follows: "RGB:XXX,XXX,XXX", where XXX is the color
component value in the range 0 to 255. Value 0 defines a color ByBlock, value 256 defines
a color ByLayer, value 257 defines a color ByEntity, values 1 to 255 define the ACI color.

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOCCLUDEDCOLOR");
OdString tint = pRb-\>getString();
odPrintConsoleString(L"nColor of occluded lines = %s", tint);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtString, L"RGB:128,128,128");
pDb-\>setSysVar(L"VSOCCLUDEDCOLOR", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdString VSOCCLUDEDCOLOR;
QVAR_DEF(OdString, VSOCCLUDEDCOLOR, ValidateNone())

/**
<title VSOCCLUDEDEDGES>
<toctitle VSOCCLUDEDEDGES>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   1
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2011+
</table>

The VSOCCLUDEDEDGES variable determines whether occluded (hidden) edges are displayed in the visual
style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Display off
1              Display on
</table>

<b>Note: </b>An existing visual style is not changed when the system variable gets a new value.
Temporary visual style will be created as a clone of visual style assigned for current viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOCCLUDEDEDGES");
OdInt16 status = pRb-\>getInt16();
odPrintConsoleString(L"nOccluded edges display status = %d", status);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 0);
pDb-\>setSysVar(L"VSOCCLUDEDEDGES", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSOCCLUDEDEDGES;
QVAR_DEF(OdInt16, VSOCCLUDEDEDGES, ValidateNone())

/**
<title VSOCCLUDEDLTYPE>
<toctitle VSOCCLUDEDLTYPE>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   Depends on the visual style
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2011+
</table>

The VSOCCLUDEDLTYPE variable stores the linetype number
defining the shape of occluded (hidden) lines in the visual
style for the current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
1              Solid line
2              Dashed line
3              Dotted line
4              Short dashed line
5              Medium dashed line
6              Long dashed line
7              Double short dashed line
8              Double medium dashed line
9              Double long dashed line
10             Medium long dashed line
11             Sparse dotted line
</table>

The current visual style defines the initial value:

<table>
<b>Value</b>   <b>Description</b>
1              2D Wireframe
1              Conceptual
2              Hidden
1              Shaded
2              Shaded with Edges
1              Shades of Gray
1              Sketchy
1              Wireframe
1              X-ray
1              Realistic
</table>

<b>Note: </b>An existing visual style is not changed when the
system variable gets a new value. Temporary visual style will
be created as a clone of visual style assigned for current
viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSOCCLUDEDLTYPE");
OdInt16 linetype = pRb-\>getInt16();
odPrintConsoleString(L"nOccluded linetype = %d", linetype);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 5);
pDb-\>setSysVar(L"VSOCCLUDEDLTYPE", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSOCCLUDEDLTYPE;
QVAR_DEF(OdInt16, VSOCCLUDEDLTYPE, ValidateNone())

/**
<title VSSHADOWS>
<toctitle VSSHADOWS>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   0
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSSHADOWS variable stores the shadow mode that defines
whether a visual style displays shadows in the current
viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Shadows are not displayed
1              Ground shadows are only displayed
2              Full shadows are displayed
</table>

<b>Note: </b>An existing visual style is not changed when the
system variable gets a new value. Temporary visual style will
be created as a clone of visual style assigned for current
viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSSHADOWS");
OdInt16 mode = pRb-\>getInt16();
odPrintConsoleString(L"nShadow mode = %d", mode);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSSHADOWS", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSSHADOWS;
QVAR_DEF(OdInt16, VSSHADOWS, ValidateNone())

/**
<title VSSILHEDGES>
<toctitle VSSILHEDGES>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   Depends on the visual style
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSSILHEDGES variable determines whether silhouette edges
of 3D entities are displayed in the visual style for the
current viewport. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              Display off
1              Display on
</table>

The current visual style defines the initial value:

<table>
<b>Value</b>   <b>Description</b>
0              2D Wireframe
1              Conceptual
1              Hidden
0              Shaded
1              Shaded with Edges
1              Shades of Gray
1              Sketchy
0              Wireframe
0              X-ray
0              Realistic
</table>

<b>Note: </b>An existing visual style is not changed when the
system variable gets a new value. Temporary visual style will
be created as a clone of visual style assigned for current
viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSSILHEDGES");
OdInt16 status = pRb-\>getInt16();
odPrintConsoleString(L"nSilhouette edge display status = %d", status);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"VSSILHEDGES", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSSILHEDGES;
QVAR_DEF(OdInt16, VSSILHEDGES, ValidateNone())

/**
<title VSSILHWIDTH>
<toctitle VSSILHWIDTH>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   5
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2007+
</table>

The VSSILHWIDTH variable stores the width in pixels of
silhouette edges in the visual style for the current
viewport. The value can be in the range 0 to 25.

<b>Note: </b>An existing visual style is not changed when the
system variable gets a new value. Temporary visual style will
be created as a clone of visual style assigned for current
viewport.

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"VSSILHWIDTH");
OdInt16 width = pRb-\>getInt16();
odPrintConsoleString(L"nSilhouette width = %d", width);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 12);
pDb-\>setSysVar(L"VSSILHWIDTH", pRb);
</code>

<group TD_SysVars_V>
*/
//<dom_var_def>OdInt16 VSSILHWIDTH;
QVAR_DEF(OdInt16, VSSILHWIDTH, ValidateNone())

/**
<title NAVVCUBEDISPLAY>
<toctitle NAVVCUBEDISPLAY>

<table>
<b>Type</b>            OdInt16
<b>Initial value</b>   3
<b>Read-Only</b>       No
<b>Saved In</b>        Nondatabase, Quasi variable
<b>Versions</b>        2010+
</table>

The NAVVCUBEDISPLAY variable specifies whether the viewcube
tool should be displayed in the current paper or display
viewport (OdDbViewport or OdDbViewportTableRecord) depending
on the current visual style. The TILEMODE variable defines
whether the current viewport is paper or display. The
viewcube is a navigation tool which is displayed in 2D and 3D
visual styles and also allows switching between standard and
isometric views. The value can be:

<table>
<b>Value</b>   <b>Description</b>
0              2D and 3D visual styles do not display the viewcube
1              3D visual styles display the viewcube, 2D visual styles do not
2              2D visual styles display the viewcube, 3D visual styles do not
3              2D and 3D visual styles display the viewcube
</table>

<table>
<b>Access Methods</b>
OdDbDatabase::getSysVar()
OdDbDatabase::setSysVar()
</table>

Access methods provide access to the value for the current
viewport (OdDbViewport if a paper layout is active or
OdViewportTableRecord if model space is active). See also
OdDbAbstractViewportData::navvcubeddisplay() and
OdDbAbstractViewportData::setNavvcubeddisplay() methods.

For example, to get the value:
<code>
OdRusBufPtr pRb = pDb-\>getSysVar(L"NAVVCUBEDISPLAY");
OdInt16 view = pRb-\>getInt16();
odPrintConsoleString(L"nThe viewcube status = %d", view);
</code>
For example, to set the value:
<code>
OdRusBufPtr pRb = OdResBuf::newRb(OdResBuf::kRtInt16, 1);
pDb-\>setSysVar(L"NAVVCUBEDISPLAY", pRb);
</code>

<group TD_SysVars_N>
*/
//<dom_var_def>OdInt16 NAVVCUBEDISPLAY;
QVAR_DEF(OdInt16, NAVVCUBEDISPLAY, ValidateRange(0, 3))

#ifdef DOUNDEF_ODTDIST
#undef ODTDIST
#undef DOUNDEF_ODTDIST
#endif

#ifdef DOUNDEF_ODTORIENT
#undef ODTORIENT
#undef DOUNDEF_ODTORIENT
#endif

#ifdef DOUNDEF_ODTANGLE
#undef ODTANGLE
#undef DOUNDEF_ODTANGLE
#endif

#ifdef DOUNDEF_ODTLAYOUTID
#undef ODTLAYOUTID
#undef DOUNDEF_ODTLAYOUTID
#endif

#ifdef DOUNDEF_ODTTEXTSTYLEID
#undef ODTTEXTSTYLEID
#undef DOUNDEF_ODTTEXTSTYLEID
#endif

#ifdef DOUNDEF_QVAR_DEF_RO
#undef QVAR_DEF_RO
#undef DOUNDEF_QVAR_DEF_RO
#endif

#ifdef DOUNDEF_ODTBOOL
#undef ODTBOOL
#undef DOUNDEF_ODTBOOL
#endif
