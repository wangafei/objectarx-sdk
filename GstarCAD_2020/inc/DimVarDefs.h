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



#ifndef BLKVAR_DEF
#define BLKVAR_DEF  VAR_DEF
#endif

#ifndef ANNOVAR_DEF
#define ANNOVAR_DEF  VAR_DEF
#endif

#ifndef ODTDB_LINEWEIGHT
#define ODTDB_LINEWEIGHT OdDb::LineWeight /* {Secret} */
#define DOUNDEF_ODTDB_LINEWEIGHT
#endif

#ifndef ODTDIST
#define ODTDIST  double /* {Secret} */
#define DOUNDEF_ODTDIST
#endif

#ifndef ODTORIENT
#define ODTORIENT  double /* {Secret} */
#define DOUNDEF_ODTORIENT
#endif

#ifndef ODTUNITLESS
#define ODTUNITLESS  double /* {Secret} */
#define DOUNDEF_ODTUNITLESS
#endif

#ifndef ODTDECSEP
#define ODTDECSEP  OdInt16 /* {Secret} */
#define DOUNDEF_ODTDECSEP
#endif

#ifndef ODTARROWBLK
#define ODTARROWBLK  OdDbHardPointerId /* {Secret} */
#define DOUNDEF_ODTARROWBLK
#endif

#ifndef ODTTEXTSTYLEID
#define ODTTEXTSTYLEID  OdDbHardPointerId /* {Secret} */
#define DOUNDEF_ODTTEXTSTYLEID
#endif


#ifndef ODTLINETYPEID
#define ODTLINETYPEID  OdDbHardPointerId /* {Secret} */
#define DOUNDEF_ODTLINETYPEID
#endif

#ifndef ODCMCOLORACI
#define ODCMCOLORACI OdCmColor
#define DOUNDEF_ODCMCOLORACI
#endif

#ifndef VAR_DEF_STRING
#define VAR_DEF_STRING VAR_DEF
#endif
/************************************************
 *
 * Dimension variables definitions
 */

//Gcad(NOTICE)
//arx里面OdInt16部分都是使用的int,这里暂时不改

//          Type              Name    DXF     Default value         Metric Def Value      Reserve1   Reserve2

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMADEC specifies the number of decimal places in angular dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              adec,   179,    (0),                  (0),              ADEC,        ValidateRange(0,8))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALT controls the display of alternate measurements in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled"
      "\n    true     Enabled"
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 alt,    170,    (false),              (false),                 ALT,        ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTD specifies the number of decimal places in alternate measurements in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt16,             altd,   171,    (2),                  (3),                  ALTD,        ValidateRange(0,8))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTF specifies the distance multiplier for alternate measurements in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(double,               altf,   143,    (25.4),               (0.03937007874016),               ALTF,        ValidateRange(DBL_MIN, DBL_MAX))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTRND specifies the rounding of alternate measurements in dimensions."
      "\n"
      "\n    If DIMALTRND == 0.0, no rounding is performed."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              altrnd, 148,    (0.0),                (0.0),              ALTRND,        ValidateRange(0,DBL_MAX))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTTD specifies the number of decimal places in tolerance values in alternate measurements in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              alttd,  274,    (2),                  (3),              ALTTD,        ValidateRange(0,8))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTTZ controls zero suppression in tolerance values in alternate measurements in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Suppress zero feet and exactly zero inches."
      "\n    1        Include zero feet and exactly zero inches."
      "\n    2        Include zero feet and suppress exactly zero inches."
      "\n    3        Suppress zero feet and include exactly zero inches."
      "\n    4        Suppress leading decimal zeros."
      "\n    8        Suppress trailing decimal zeros.
      "\n    12       Suppress leading and trailing decimal zeros.
      "\n"
      "\n    Values 0-3 affect only feet-and-inch dimensions, and may be combined with values 4-12."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt8,              alttz,  286,    (0),                  (0),                  ALTTZ,        ValidateRange(0,15))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTU controls the formatting for alternate units in dimensions."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    1         Scientific"
      "\n    2         Decimal"
      "\n    3         Engineering"
      "\n    4         Architectural (stacked)"
      "\n    5         Fractional (stacked)"
      "\n    6         Architectural"
      "\n    7         Fractional"
      "\n    8         Microsoft Windows Desktop"
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              altu,   273,    (2),                  (2),              ALTU,        ValidateRange(1,8))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMALTZ controls zero suppression in alternate measurements in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Suppress zero feet and exactly zero inches."
      "\n    1        Include zero feet and exactly zero inches."
      "\n    2        Include zero feet and suppress exactly zero inches."
      "\n    3        Suppress zero feet and include exactly zero inches."
      "\n    4        Suppress leading decimal zeros."
      "\n    8        Suppress trailing decimal zeros."
      "\n    12       Suppress leading and trailing decimal zeros."
      "\n"
      "\n    Values 0-3 affect only feet-and-inch dimensions, and may be combined with values 4-12."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt8,              altz,   285,    (0),                  (0),              ALTZ,        ValidateRange(0,15))

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMAPOST specifies a prefix and/or suffix for alternate measurement text in dimensions."
      "\n"
      "\n    DIMAPOST is in the form /prefix/<>/suffix/. "
      "\n"
      "\n    The '<>' in DIMAPOST is replaced by the alternate measurement text."
    </remarks>
  </properties>
*/
VAR_DEF_STRING(OdString,             apost,  4,      (OD_T("")),                 (OD_T("")),             APOST,        ValidateNone())
/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMASZ specifies the arrowhead size for dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              asz,    41,     (0.18),               (2.5),              ASZ,        ValidateRange(0,DBL_MAX))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMATFIT specifies how arrows and text are placed when they do not fit"
      " within the extension lines of dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Moves text and arrows outside extension lines."
      "\n    1        Moves arrows, then text, outside extension lines."
      "\n    2        Moves text, then arrows, outside extension lines."
      "\n    3        Moves text or arrows for best fit."
      
      When DIMTMOVE == 1, a leader is added to moved text.
    </remarks>
  </properties>
*/
ANNOVAR_DEF(OdInt16,              atfit,  289,    (3),                  (3),              ATFIT,        ValidateRange(0,3))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMAUNIT specifies the formatting for units in angular dimensions."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    0         Decimal Degrees"
      "\n    1         Degrees-Minutes-Seconds"
      "\n    2         Gradians"
      "\n    3         Radians"
      "\n    4         Surveyor's Units"
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              aunit,  275,    (0),                  (0),              AUNIT,        ValidateRange(0,4))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMAZIN controls zero suppression in angular dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Display leading and trailing decimal zeros."
      "\n    1        Suppress leading decimal zeros."
      "\n    2        Suppress trailing decimal zeros."
      "\n    3        Suppress leading and trailing decimal zeros."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              azin,   79,     (0),                  (0),              AZIN,        ValidateRange(0,3))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMBLK specifies the arrowhead block at the ends of dimension lines and leader lines."
      "\n"
      "\n    A null value specifies the default arrowhead is to be used."
    </remarks>
  </properties>
*/
BLKVAR_DEF(ODTARROWBLK,       blk,    342,    (OdDbObjectId::kNull),(OdDbObjectId::kNull),       BLK,        ValidateDimBlock())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMBLK1 specifies the first arrowhead block of dimension lines when DIMSAH == true."
      "\n"
      "\n    A null value specifies the default arrowhead is to be used."
    </remarks>
  </properties>
*/
BLKVAR_DEF(ODTARROWBLK,       blk1,   343,    (OdDbObjectId::kNull),(OdDbObjectId::kNull),       BLK1,        ValidateDimBlock())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMBLK2 specifies the second arrowhead block of dimension lines when DIMSAH == true."
      "\n"
      "\n    A null value specifies the default arrowhead is to be used."
    </remarks>
  </properties>
*/
BLKVAR_DEF(ODTARROWBLK,       blk2,   344,    (OdDbObjectId::kNull),(OdDbObjectId::kNull),       BLK2,        ValidateDimBlock())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMCEN controls the generation of arc and circle center marks and lines."
      "\n"
      "\n    The absolute value of DIMCEN specifies the size of the center mark, which half the length of the center mark,"
      "\n    which is also the length of the portion of a center line beyond the arc or circle, as well as" 
      "\n    the length of the gap between the center mark and line."
      "\n"
      "\n    The sign of DIMCEN controls the generation of center marks and center lines:"
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    < 0       Center marks and center lines"
      "\n    0         No center marks or center lines"
      "\n    > 0       Center marks"
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              cen,    141,    (0.09),               (2.5),              CEN,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMCLRD specifies the *color* of dimension lines, leader lines, frames, and arrowheads."
    </remarks>
  </properties>
*/
VAR_DEF(ODCMCOLORACI,            clrd,   176,(OdCmEntityColor::kByBlock),(OdCmEntityColor::kByBlock),            CLRD,ValidateAciColor())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMCLRE specifies the *color* of extension lines."
    </remarks>
  </properties>
*/
VAR_DEF(ODCMCOLORACI,            clre,   177,(OdCmEntityColor::kByBlock),(OdCmEntityColor::kByBlock),            CLRE,ValidateAciColor())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMCLRT specifies the *color* of dimension text."
    </remarks>
  </properties>
*/
VAR_DEF(ODCMCOLORACI,            clrt,   178,(OdCmEntityColor::kByBlock),(OdCmEntityColor::kByBlock),            CLRT,ValidateAciColor())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMDEC specifies the number of decimal places in primary units in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              dec,    271,    (4),                  (2),              DEC,        ValidateRange(0,8))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMDLE specifies the distance dimension lines extend beyond extension lines when"
      "\n    arrowheads are architectural, integral, oblique, tick, or none."
      "\n"
      <see_also>
      "\n    DIMTSZ"
      </see_also>
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              dle,    46,     (0.0),                (0.0),              DLE,        ValidateRange(0,DBL_MAX))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMDLI specifies distance between dimension lines for baseline dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              dli,    43,     (0.38),               (3.75),              DLI,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMDSEP specifies the decimal separator for dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDECSEP,            dsep,   278,    ('.'),                (','),                DSEP,        ValidateDecSep())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMEXE specifies the distance extension lines extend beyond dimension lines."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              exe,    44,     (0.18),               (1.25),              EXE,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMEXO specifies the distance extension are offset from their origin points."
      "\n"
      "\n    DIMEXO specifies a minimum value when fixed-length extension lines are used." 
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              exo,    42,     (0.0625),             (0.625),              EXO,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMFRAC specifies the fraction format when DIMLUNIT == 4 or 5."
      "\n"
      "\n    @table"
      "\n    Value        Description"
      "\n    0            Horizontal Stacked."
      "\n    1            Diagonal Stacked."
      "\n    2            Not Stacked."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              frac,   276,    (0),                  (0),              FRAC,        ValidateRange(0,2))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMGAP specifies the gap between dimension text and dimension lines."
      "\n"
      "\n    A negative value for DIMGAP draws a reference box round the dimension text."
      "\n"
      "\n    Text is placed inside a dimension line only if there will be two line segments"    
      "\n    each as long as abs(DIMGAP)."    
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              gap,    147,    (0.09),               (0.625),              GAP,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMJUST specifies the dimension text horizontal position."
      "\n"
      "\n    @table"
      "\n    Value        Description"
      "\n    0            Centered above the dimension line."
      "\n    1            By the first extension line."
      "\n    2            By the second extension line."
      "\n    3            Above the dimension line, parallel to the first extension line."
      "\n    4            Above the dimension line, parallel to the second extension line."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt16,             just,   280,    (0),                  (0),             JUST,        ValidateRange(0,4))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLDRBLK specifies the arrowhead block at the ends of leader lines."
      "\n"
      "\n    A null value specifies the default arrowhead is to be used."
    </remarks>
  </properties>
*/
VAR_DEF(ODTARROWBLK,          ldrblk, 341,    (OdDbObjectId::kNull),(OdDbObjectId::kNull),          LDRBLK,        ValidateDimBlock())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLFAC specifies the distance multiplier for measurements in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(double,               lfac,   144,    (1.0),                (1.0),               LFAC,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLIM controls the display of dimension limits."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    false     Disabled."
      "\n    true      Enabled."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 lim,    72,     (false),              (false),                 LIM,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLUNIT specifies the formatting for units in non-angular dimensions."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    1         Scientific"
      "\n    2         Decimal"
      "\n    3         Engineering"
      "\n    4         Architectural (stacked)"
      "\n    5         Fractional (stacked)"
      "\n    6         Microsoft Windows Desktop"
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              lunit,  277,    (2),                  (2),              LUNIT,        ValidateRange(1,6))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLWD specifies the lineweight for dimension lines."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDB_LINEWEIGHT,     lwd,    371,    (OdDb::kLnWtByBlock), (OdDb::kLnWtByBlock),     LWD,        ValidateLineWeight())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLWE specifies the lineweight for extension lines."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDB_LINEWEIGHT,     lwe,    372,    (OdDb::kLnWtByBlock), (OdDb::kLnWtByBlock),     LWE,        ValidateLineWeight())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMPOST specifies a prefix and/or suffix for the measurement text in dimensions."
      "\n"
      "\n    DIMPOST is in the form /prefix/<>/suffix/. "
      "\n"
      "\n    The '<>' in DIMPOST is replaced by the measurement text."
    </remarks>
  </properties>
*/
VAR_DEF_STRING(OdString,             post,   3,      (OD_T("")),                 (OD_T("")),             POST,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMRND specifies the rounding of measurements text."
      "\n"
      "\n    If DIMRND == 0, no rounding is performed."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              rnd,    45,     (0.0),                (0.0),              RND,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSAH controls the generation of separate arrowheads for dimension lines."
      "\n"
      "\n    @table"
      "\n    Value    Arrowhead Blocks"
      "\n    false    DIMBLK"
      "\n    true     DIMBLK1 and DIMBLK2"
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 sah,    173,    (false),              (false),                 SAH,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSCALE is an scale factor applied to all dimension variables that"
      "\n    regulate sizes, offsets, and distances."
      "\n"
      "\n    DIMSCALE serves as an overall \"volume control\" for dimensions"
      "\n    and leaders."
      "\n"
      "\n    @table"
      "\n    Value        Description"
      "\n    0.0          A \"reasonable\" value is computed for model space viewports."
      "\n    > 0.0        If set to the inverse of the plot scale, plotted dimensions will"
      " be at the sizes specified by the other dimension variables."
    </remarks>
  </properties>
*/
VAR_DEF(double,               scale,  40,     (1.0),                (1.0),               SCALE,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSD1 controls the suppression of the first dimension line and arrowhead in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not suppressed"
      "\n    true     Suppressed"
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 sd1,    281,    (false),              (false),                 SD1,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSD2 controls the suppression of the second dimension line and arrowhead in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not suppressed"
      "\n    true     Suppressed."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 sd2,    282,    (false),              (false),                 SD2,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSE1 controls the suppression of the first extension line in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not suppressed"
      "\n    true     Suppressed."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 se1,    75,     (false),              (false),                 SE1,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSE2 controls the suppression of the second extension line in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not suppressed"
      "\n    true     Suppressed."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 se2,    76,     (false),              (false),                 SE2,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMSOXD controls the suppression of dimension lines outside the extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Not suppressed"
      "\n    true     Suppressed."
    </remarks>
  </properties>
*/
ANNOVAR_DEF(bool,                 soxd,   175,    (false),              (false),                 SOXD,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTAD specifies the dimension text vertical position."
      "\n"
      "\n    @table"
      "\n    Value        Description"
      "\n    0            Centered about the dimension line."
      "\n    1            Above the dimension line, unless DIMTIH==1 and the dimension line is not horizontal."
      "\n    2            Side of the dimension line farthest from the defining points."
      "\n    3            JIS standard."
      "\n    4            Text below the dimension line"
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              tad,    77,     (0),                  (1),              TAD,        ValidateRange(0,4))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTDEC specifies the number of decimal places in tolerance values for primary units in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              tdec,   272,    (4),                  (2),              TDEC,        ValidateRange(0,8))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTFAC specifies, as a factor of DIMTXT, the size of tolerance and fraction text in dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(double,               tfac,   146,    (1.0),                (1.0),                TFAC,        ValidatePositiveNonZero())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTIH controls the orientation of dimension text inside the extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Aligned with dimension line."
      "\n    true     Horizontal."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 tih,    73,     (true),               (false),              TIH,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTIX controls the placement of dimension text inside the extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Inside extension lines if there is room."
      "\n    true     Inside extension lines."
    </remarks>
  </properties>
*/
ANNOVAR_DEF(bool,             tix,    174,    (false),              (false),              TIX,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTM specifies the negative of the lower tolerance limit for dimensions."
    </remarks>
  </properties>
*/

VAR_DEF(ODTDIST,              tm,     48,     (0.0),                (0.0),                TM,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTMOVE specifies the movement rules for dimension text."
      "\n"
      "\n    @table"
      "\n    Value        Description"
      "\n    0            Moving dimension text moves the dimension line."
      "\n    1            Moving dimension text adds a leader."
      "\n    2            Moving dimension text does not add a leader."
    </remarks>
  </properties>
*/
ANNOVAR_DEF(OdInt16,          tmove,  279,    (0),                  (0),                  TMOVE,        ValidateRange(0,2))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTOFL controls the drawing of dimension lines between extension lines"
      "\n    when text is outside the dimension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled."
      "\n    true     Enabled."
    </remarks>
  </properties>
*/
ANNOVAR_DEF(bool,             tofl,   172,    (false),              (true),               TOFL,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTOH controls the orientation of dimension text outside the extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Aligned with dimension line."
      "\n    true     Horizontal."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 toh,    74,     (true),               (false),                 TOH,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTOL controls the generation of tolerance text in dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Disabled."
      "\n    true     Enabled."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 tol,    71,     (false),              (false),                 TOL,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTOLJ controls the vertical justification of tolerance values with respect to the nominal dimension text."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Bottom"
      "\n    1        Middle"
      "\n    2        Top"
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt8,              tolj,   283,    (1),                  (0),              TOLJ,        ValidateRange(0,2))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTP specifies the upper tolerance limit for dimensions."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              tp,     47,     (0.0),                (0.0),              TP,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTSZ specifies the size of architectural tics are "
      "\n    to be drawn instead of arrowheads for linear, radial, and diameter dimensions."
      "\n"
      "\n    DIMTSZ is the distance, parallel to the dimension line,"
      "\n    that the tics extends beyond the extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0.0      Arrowheads"
      "\n    > 0.0    Tics"
    </remarks>
    <see_also>
      "\n    DIMDLE"
    </see_also>
  </properties>
*/
VAR_DEF(ODTDIST,              tsz,    142,    (0.0),                (0.0),                TSZ,        ValidatePositive())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTVP specifies, as a factor of DIMTXT, the vertical distance of the middle"
      "\n    of the dimension text with respect to the dimension line."
    </remarks>
  </properties>
*/
VAR_DEF(double,               tvp,    145,    (0.0),                (0.0),                TVP,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTXSTY specifies the text style of the dimension text."
    </remarks>
  </properties>
*/
VAR_DEF(ODTTEXTSTYLEID,       txsty,  340,    (OdDbObjectId::kNull),(OdDbObjectId::kNull),TXSTY,        ValidateTextStyle())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTXT specifies the size of the dimension text."
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              txt,    140,    (0.18),               (2.5),                TXT,        ValidatePositiveNonZero())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTZIN controls zero suppression in tolerance values in linear dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Suppress zero feet and exactly zero inches."
      "\n    1        Include zero feet and exactly zero inches."
      "\n    2        Include zero feet and suppress exactly zero inches."
      "\n    3        Suppress zero feet and include exactly zero inches."
      "\n    4        Suppress leading decimal zeros."
      "\n    8        Suppress trailing decimal zeros.
      "\n    12       Suppress leading and trailing decimal zeros.
      "\n"
      "\n    Values 0-3 affect only feet-and-inch dimensions, and may be combined with values 4-12."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt8,              tzin,   284,    (0),                  (8),              TZIN,        ValidateRange(0,15))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMUPT controls the movement of user-positioned text when dimension lines are moved."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Moves only the dimension line."
      "\n    true     Moves the dimension line and the text."
    </remarks>
  </properties>
*/
VAR_DEF(bool,                 upt,    288,    (false),              (false),                 UPT,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMZIN controls zero suppression in linear dimensions."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    0        Suppress zero feet and exactly zero inches."
      "\n    1        Include zero feet and exactly zero inches."
      "\n    2        Include zero feet and suppress exactly zero inches."
      "\n    3        Suppress zero feet and include exactly zero inches."
      "\n    4        Suppress leading decimal zeros."
      "\n    8        Suppress trailing decimal zeros.
      "\n    12       Suppress leading and trailing decimal zeros.
      "\n"
      "\n    Values 0-3 affect only feet-and-inch dimensions, and may be combined with values 4-12."
    </remarks>
  </properties>
*/
VAR_DEF(OdUInt8,              zin,    78,     (0),                  (8),              ZIN,        ValidateRange(0,15))


//--------------------------------------------new in R21------------------------------------------------------

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMFXL specifies the fixed length of extension lines from"
      "\n    the dimension line towards the dimension origin."
      "\n"
      "\n    DIMFXL is ignored when DIMFXLON == false. 
    </remarks>
  </properties>
*/
VAR_DEF(ODTDIST,              fxl,    49,     (1),                  (1),              FXLEN,        ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMFXLON controls the generation of fixed-length extension lines."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    Variable length."
      "\n    true     Fixed length."
    </remarks>
      <see_also>
      "\n    DIMFXL"
      </see_also>
  </properties>
*/
VAR_DEF(bool,              fxlon,    290,     (false),                  (false),                  FXLENON,       ValidateBOOL())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMJOGANG specifies the jog angle of dimension lines in jogged radius dimensions."
    </remarks>
    <notes>
      "\n    All angles are expressed in radians."
    </notes>
  </properties>
*/
VAR_DEF(ODTORIENT,         jogang,    50,     (OdaPI4),                  (OdaPI4),         JOGANG,     ValidateRange(  5.0*OdaPI/180.0, OdaPI2))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTFILL specifies the background fill of dimension text."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    0         No fill."
      "\n    1         Drawing background color."
      "\n    2         Color specified by DIMTFILLCLR."
     </remarks>
     <see_also>
      "\n    DIMTFILLCLR"
     </see_also>
  </properties>
*/
VAR_DEF(OdInt16,              tfill,    69,     (0),                  (0),              TFILL,        ValidateRange(0, 2))


/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTFILLCLR specifies the background fill color for dimension text when DIMTFILL == 2."
     </remarks>
     <see_also>
      "\n    DIMTFILL"
     </see_also>
  </properties>
*/
VAR_DEF(ODCMCOLORACI,              tfillclr,    70,     (OdCmEntityColor::kByBlock),                  (OdCmEntityColor::kByBlock),              TFILLCLR,        ValidateAciColor())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMARCSYM specifies the placement of arc symbols in arc length dimensions."
      "\n"
      "\n    @table"
      "\n    Value     Description"
      "\n    0         Before the dimension text."
      "\n    1         Above the dimension text."
      "\n    2         Not displayed."
     </remarks>
  </properties>
*/
VAR_DEF(OdInt16,              arcsym,    90,     (0),                  (0),              ARCSYM,        ValidateRange(0, 2))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLTYPE specifies the linetype of dimension lines."
     </remarks>
  </properties>
*/
VAR_DEF(ODTLINETYPEID,              ltype,    345,     (OdDbObjectId::kNull),                  (OdDbObjectId::kNull),                  LTYPE,        ValidateLinetype(true))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLTEX1 specifies the linetype of first extension lines."
     </remarks>
  </properties>
*/
VAR_DEF(ODTLINETYPEID,              ltex1,    346,     (OdDbObjectId::kNull),                  (OdDbObjectId::kNull),                  LTEX1,        ValidateLinetype(true))

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMLTEX2 specifies the linetype of the second extension lines."
     </remarks>
  </properties>
*/
VAR_DEF(ODTLINETYPEID,              ltex2,    347,     (OdDbObjectId::kNull),                  (OdDbObjectId::kNull),                  LTEX2,        ValidateLinetype(true))

//--------------------------------------------new in R24------------------------------------------------------

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMTXTDIRECTION controls the text direction."
      "\n"
      "\n    @table"
      "\n    Value    Description"
      "\n    false    "
      "\n    true     "
    </remarks>
      <see_also>
      "\n    DIMTXTDIRECTION"
      </see_also>
  </properties>
*/
VAR_DEF(bool,         txtdirection,   294,          (false),                  (false),          TXTDIRECTION,  ValidateBOOL())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMMZF."
    </remarks>
  </properties>
*/
VAR_DEF(double,                mzf,   297,          (100.0),                  (100.0),          MZF,  ValidateNone())

/*** VARDOCS:
  <properties>
    <remarks>
      "\n    DIMMZS."
    </remarks>
  </properties>
*/
VAR_DEF_STRING(OdString,              mzs,   298,       (OD_T("")),               (OD_T("")),          MZS,  ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMALTMZF."
    </remarks>
  </properties>
*/
VAR_DEF(double,             altmzf,   295,          (100.0),                  (100.0),          ALTMZF,  ValidateNone())

/*** VARDOCS: 
  <properties>
    <remarks> 
      "\n    DIMALTMZS."
    </remarks>
  </properties>
*/
VAR_DEF_STRING(OdString,           altmzs,   296,       (OD_T("")),               (OD_T("")),          ALTMZS,  ValidateNone())


#ifdef DOUNDEF_ODTDB_LINEWEIGHT
#undef ODTDB_LINEWEIGHT
#undef DOUNDEF_ODTDB_LINEWEIGHT
#endif

#ifdef DOUNDEF_ODTDIST
#undef ODTDIST
#undef DOUNDEF_ODTDIST
#endif

#ifdef DOUNDEF_ODTUNITLESS
#undef ODTUNITLESS
#undef DOUNDEF_ODTUNITLESS
#endif

#ifdef DOUNDEF_ODTORIENT
#undef ODTORIENT
#undef DOUNDEF_ODTORIENT
#endif

#ifdef DOUNDEF_ODTDECSEP
#undef ODTDECSEP
#undef DOUNDEF_ODTDECSEP
#endif

#ifdef DOUNDEF_ODTARROWBLK
#undef ODTARROWBLK
#undef DOUNDEF_ODTARROWBLK
#endif

#ifdef DOUNDEF_ODTTEXTSTYLEID
#undef ODTTEXTSTYLEID
#undef DOUNDEF_ODTTEXTSTYLEID
#endif

#ifdef DOUNDEF_ODTLINETYPEID
#undef ODTLINETYPEID
#undef DOUNDEF_ODTLINETYPEID
#endif

#ifdef DOUNDEF_ODCMCOLORACI
#undef ODCMCOLORACI
#undef DOUNDEF_ODCMCOLORACI
#endif

#ifdef VAR_DEF_STRING
#undef VAR_DEF_STRING
#endif