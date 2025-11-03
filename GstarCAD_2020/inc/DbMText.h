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




#ifndef OD_DBMTEXT_H
#define OD_DBMTEXT_H

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "TextDefs.h"
#include "Ge/GePoint2d.h"
#include "Ge/GePoint3d.h"

class OdGeVector3d;
class OdGePoint2d;

/** Description:

    {group:TD_Namespaces}
*/

/** Description:
    This struct is used to describe a fragment of text created by explodeFragments().

    Remarks:
    Each fragment contains a text string and its attributes.
    Library: TD_Db
    {group:Structs}
*/
struct OdDbMTextFragment
{
  OdGePoint3d location;           // Insertion point.

  OdGeVector3d normal;			//
  OdGeVector3d direction;		//·½Ïò

  OdString text;                  // Text string.

  OdString font;                  // SHX Font.
  OdString bigfont;               // SHX Bigfont.

  OdGePoint2d extents;            // Extents in OCS.
  double capsHeight;              // Height.
  double widthFactor;             // Width factor.
  double obliqueAngle;            // Obliquing angle.
  double trackingFactor;          // Tracking factor.

  // OdUInt16 colorIndex;

  OdCmEntityColor color;          // Color.
  bool vertical;                  // Text is vertical.

  bool stackTop;                  // Text is top of stacked text.
  bool stackBottom;               // Text is bottom of stacked text.

  bool underlined;                // Text is underlined.
  bool overlined;                 // Text is overlined.
  bool strikethrough;

  OdGePoint3d underPoints[2];     // Underline endpoints.
  OdGePoint3d overPoints[2];      // Overline endpoints.
  OdGePoint3d strikePoints[2];

  //  true type font data

  OdString  fontname;             // TrueType font name, or empty string.
  int       charset;              // TrueType character set.
  bool      bold;                 // Text is bold.
  bool      italic;               // Text is italic.

  // 0 - no change 1 - change to original 2 - change to other

  int      changeStyle;           // 0 == No change; 1 == Change to original; 2 == Change to other
  bool     lineBreak;             // Text is followed by a line break.
  bool     newParagraph;          // Text fragment starts new paragraph.
};

/** Description:
    This struct is used by OdDbMText::getParagraphsIndent() to return indentation and tab data.
    Library: TD_Db
    {group:Structs}
*/
struct OdDbMTextIndent
{
  double  paragraphInd;  // Subsequent line indent.

  double  firstLineInd;  // First line indent.

  OdArray<double> tabs; // Tab settings.
};

typedef int(*OdDbMTextEnum)(
    OdDbMTextFragment *,
    void *);

typedef OdArray<OdDbMTextIndent> OdDbMTextIndents;

class OdDbText;

/** Description:
    This class represents paragraph (multi-line) text (MText) entities in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbMText : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMText);

  OdDbMText();

  ~OdDbMText();
	
  /** Description:
    Returns the insertion point of this MText entity (WCS equivalent of DXF 10).
  */
  OdGePoint3d location() const;

  /** Description:
    Sets the insertion point of this MText entity (WCS equivalent of DXF 10).

    Arguments:
    location (I) Insertion point.
  */
  OdResult setLocation(
    const OdGePoint3d& location);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;

  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  /** Description:
    Returns the WCS X-axis *direction* vector of this MText entity (DXF 11).

  */
  OdGeVector3d direction() const;

  /** Description:
    Sets the WCS X-axis *direction* vector of this MText entity (DXF 11).
    Arguments:
    direction (I) Direction vector.
    Remarks:
    Direction and *rotation* are equivalent, and only one need be set when creating (or modifying) an MText entity.
  */
  OdResult setDirection(
    const OdGeVector3d& direction);

  /** Description:
    Returns the *rotation* angle of this MText entity (DXF 50).
    Note:
    All angles are expressed in radians.
 */
  double rotation() const;

  /** Description:
    Sets the *rotation* angle of this MText entity (DXF 50).
    Arguments:
    rotation (I) Rotation angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult setRotation(
    double rotation);

  /** Description:
    Returns the word-wrap *width* of this MText entity (DXF 41).

    Remarks:
    Words exceeding this value will extend beyond this *width*.
  */
  double width() const;

  /** Description:
    Sets the word-wrap *width* of this MText entity (DXF 41).
    Arguments:
    width (I) Word-wrap *width*
    Remarks:
    Words exceeding this value will extend beyond the Specified *width*.
  */
  OdResult setWidth(
    double width);

  /** Description:
    Returns the Object ID of the text style of this MText entity (DXF 7).
  */
  OdDbObjectId textStyle() const;

  /** Description:
    Sets the Object ID of the text style of this MText entity (DXF 7).
    Arguments:
    textStyleId (I) Text style Object ID.
  */
  OdResult setTextStyle(
    OdDbObjectId textStyleId);

  /** Description:
    Returns the text *height* of this MText entity (DXF 40).
  */
  double textHeight() const;

  /** Description:
    Sets the text *height* of this MText entity (DXF 40).
    Arguments:
    height (I) Text *height*.
  */
  OdResult setTextHeight(
    double height);

  enum AttachmentPoint
  {
    kTopLeft        = 1,    // Top Left
    kTopCenter      = 2,    // Top Center
    kTopRight       = 3,    // Top Right
    kMiddleLeft     = 4,    // Middle Left
    kMiddleCenter   = 5,    // Middle Center
    kMiddleRight    = 6,    // Middle Right
    kBottomLeft     = 7,    // Bottom Left
    kBottomCenter   = 8,    // Bottom Center
    kBottomRight    = 9,    // Bottom Right
    kBaseLeft       = 10,   // Baseline Left /reserved for future use/
    kBaseCenter     = 11,   // Baseline Center /reserved for future use/
    kBaseRight      = 12,   // Baseline Right /reserved for future use/
    kBaseAlign      = 13,   // Baseline Aligned /reserved for future use/
    kBottomAlign    = 14,   // Bottom Aligned /reserved for future use/
    kMiddleAlign    = 15,   // Middle Aligned /reserved for future use/
    kTopAlign       = 16,   // Top Aligned /reserved for future use/
    kBaseFit        = 17,   // Baseline Fit /reserved for future use/
    kBottomFit      = 18,   // Bottom Fit /reserved for future use/
    kMiddleFit      = 19,   // Middle Fit /reserved for future use/
    kTopFit         = 20,   // Top Fit /reserved for future use/
    kBaseMid        = 21,   // Baseline Middled /reserved for future use/
    kBottomMid      = 22,   // Bottom Middled /reserved for future use/
    kMiddleMid      = 23,   // Middle Middled /reserved for future use/
    kTopMid         = 24    // Top Middled /reserved for future use/
  };

  /** Description:
    Returns the *type* of *attachment* point of this MText entity (DXF 71).

    Remarks:
    attachment() returns one of the following:

    @table
    Name            Value
    kTopLeft        1
    kTopCenter      2
    kTopRight       3
    kMiddleLeft     4
    kMiddleCenter   5
    kMiddleRight    6
    kBottomLeft     7
    kBottomCenter   8
    kBottomRight    9
  */
  AttachmentPoint attachment() const;

  /** Description:
    Sets the *type* of *attachment* point of this MText entity (DXF 71).
    Arguments:
    type (I) Type of *attachment* point.

    Remarks:
    attachment must be one of the following:

    @table
    Name            Value
    kTopLeft        1
    kTopCenter      2
    kTopRight       3
    kMiddleLeft     4
    kMiddleCenter   5
    kMiddleRight    6
    kBottomLeft     7
    kBottomCenter   8
    kBottomRight    9

    Note:
    setAttachment() keeps the location of this MText entity constant
    while changing the *attachment* type, thereby changing the extents of (moving) this MText entity.

    setAttachmentMovingLocation() moves the location of the MText entity
    while changing the *attachment* type, thereby maintaining the extents (not moving) this MText entity.

    See also:
    setAttachmentMovingLocation
  */
  OdResult setAttachment(
    AttachmentPoint type);

  enum FlowDirection
  {
    kLtoR     = 1,  // Left to Right
    kRtoL     = 2,  // Right to Left
    kTtoB     = 3,  // Top to Bottom
    kBtoT     = 4,  // Bottom to Top
    kByStyle  = 5   // By Style
  };

  /** Description:
    Returns the flow *direction* of this MText entity (DXF 72).

    Remarks:
    flowDirection() returns one of the following:

    @table
    Name        Value
    kLtoR       1
    kRtoL       2
    kTtoB       3
    kBtoT       4
    kByStyle    5
  */
  FlowDirection flowDirection() const;

  /** Description:
    Sets the flow *direction* of this MText entity (DXF 72).
    Arguments:
    flowDirection (I) Flow *direction*.
    Remarks:
    flowDirection() returns one of the following:

    @table
    Name        Value
    kLtoR       1
    kRtoL       2
    kTtoB       3
    kBtoT       4
    kByStyle    5
  */
  OdResult setFlowDirection(
    FlowDirection flowDirection);

  /** Description:
    Returns a copy of the character *contents* of this MText entity (DXF 1 & 3).
  */
  OdString contents(ODSYSDEF) const;

  /** Gcad(Add)
  */
#ifdef ODARXDEF
  OdChar*  contents() const;
#endif
  OdChar*  text() const;

  const OdChar*  contentsConst() const;
  /** Description:
    Sets the character *contents* of this MText entity (DXF 1 & 3).
    Arguments:
    text (I) Character *contents*.
  */
  int setContents(const OdChar * text);
  
  /** Gcad(Add): TODO
  */
  int setContentsRTF(const OdChar * text);
  
  /** Gcad(Add)
  */
  int correctSpelling();

  /** Description:
    Returns the *width* of the bounding box of this MText entity.
    Note:
    This value will probably be different than that returned by OdDbMText::width().
  */
  double actualWidth() const;

  /** Description:
    Returns the non-break space string "\~".

    Remarks:
    May be used in place of "\~" to make code more understandable.
  */
  static const OdChar* const nonBreakSpace();

  /** Description:
    Returns the overline on string "\O".

    Remarks:
    May be used in place of "\O" to make code more understandable.
  */
  static const OdChar* const overlineOn();

  /** Description:
    Returns the overline off string "\o".

    Remarks:
    May be used in place of "\o" to make code more understandable.
  */
  static const OdChar* const overlineOff();

  /** Description:
    Returns the underline on string "\L".

    Remarks:
    May be used in place of "\L" to make code more understandable.
  */
  static const OdChar* const underlineOn();

  /** Description:
    Returns the underline off string "\l".

    Remarks:
    May be used in place of "\l" to make code more understandable.
  */
  static const OdChar* const underlineOff();

  /** Description:
    Returns the *color* change string "\C".

    Remarks:
    May be used in place of "\C" to make code more understandable.
  */
  static const OdChar* const colorChange();

  /** Description:
    Returns the font change string "\F".

    Remarks:
    May be used in place of "\F" to make code more understandable.
  */
  static const OdChar* const fontChange();

  /** Description:
    Returns the height change string "\H".

    Remarks:
    May be used in place of "\H" to make code more understandable.
  */
  static const OdChar* const heightChange();

  /** Description:
    Returns the *width* change string "\W".

    Remarks:
    May be used in place of "\W" to make code more understandable.
  */
  static const OdChar* const widthChange();

  /** Description:
    Returns the oblique angle change string "\Q".

    Remarks:
    May be used in place of "\Q" to make code more understandable.
  */
  static const OdChar* const obliqueChange();

  /** Description:
    Returns the track change string "\T".

    Remarks:
    May be used in place of "\T" to make code more understandable.
  */
  static const OdChar* const trackChange();

  /** Description:
    Returns the line break string "\p".

    Remarks:
    May be used in place of "\p" to make code more understandable.
  */
  static const OdChar* const lineBreak();

  /** Description:
    Returns the paragraph break string "\P".
    Remarks:
    May be used in place of "\P" to make code more understandable.
  */
  static const OdChar* const paragraphBreak();

  /** Description:
    Returns the stacked text start string "\S".
    Remarks:
    May be used in place of "\S" to make code more understandable.
  */
  static const OdChar* const stackStart();

  /** Description:
    Returns the alignment change string "\A".

    Remarks:
    May be used in place of "\A" to make code more understandable.
  */
  static const OdChar* const alignChange();

  /** Description:
    Returns the begin block string "{".

    Remarks:
    May be used in place of "{" to make code more understandable.
  */
  static const OdChar* const blockBegin();

  /** Description:
    Returns the end block string "}".

    Remarks:
    May be used in place of "}" to make code more understandable.
  */
  static const OdChar* const blockEnd();

  /** \details
    Returns the strike through on string "\K".

    \remarks
    May be used in place of "\K" to make code more understandable.
  */
  static const OdChar*  const strikethroughOn(); 

  /** \details
    Returns the strike through off string "\k".

    \remarks
    May be used in place of "\k" to make code more understandable.
  */
  static const OdChar*  const strikethroughOff();
  /** Description:
    Sets the linespacing style of this MText entity (DXF 73).

    Arguments:
    lineSpacingStyle (I) Linespacing style.
  */
  OdResult setLineSpacingStyle(
    OdDb::LineSpacingStyle lineSpacingStyle);

  /** Description:
    Returns the linespacing style of this MText entity (DXF 73).
  */
  OdDb::LineSpacingStyle lineSpacingStyle() const;

  /** Description:
    Sets the linespacing factor of this MText entity (DXF 44).
    Arguments:
    lineSpacingFactor (I) Linespacing Factor.
  */
  OdResult setLineSpacingFactor(
    double lineSpacingFactor);

  /** Description:
      Returns the linespacing factor of this MText entity (DXF 44).
  */
  double lineSpacingFactor() const;

  void getEcs(OdGeMatrix3d& retVal) const;

  /** Description:
    Returns the horizontal mode of this MText entity (used for DXF 71).

    Remarks:
    horizontalMode returns one of the following:

    @table
    Name                Value
    OdDb::kTextLeft      0
    OdDb::kTextCenter    1
    OdDb::kTextRight     2
    OdDb::kTextAlign     3
    OdDb::kTextMid       4
    OdDb::kTextFit       5

  */
  OdDb::TextHorzMode horizontalMode() const;

  /** Description:
    Sets the horizontal mode of this MText entity (used for DXF 71).
    Arguments:
    horizontalMode (I) Horizontal mode.

    Remarks:
    horizontalMode must be one of the following:

    @table
    Name                Value
    OdDb::kTextLeft      0
    OdDb::kTextCenter    1
    OdDb::kTextRight     2
    OdDb::kTextAlign     3
    OdDb::kTextMid       4
    OdDb::kTextFit       5
  */
  void setHorizontalMode(
    OdDb::TextHorzMode horizontalMode);

  /** Description:
    Returns the vertical mode of this MText entity (used for DXF 71).

    Remarks:
    verticalMode() returns one of the following:

    @table
    Name                  Value
    OdDb::kTextBase       0
    OdDb::kkTextBottom    1
    OdDb::kkTextVertMid   2
    OdDb::kkTextTop       3
  */
  OdDb::TextVertMode verticalMode() const;

  /** Description:
    Sets the vertical mode of this MText entity (used for DXF 71).

    Arguments:
    verticalMode (I) Vertical mode.

    Remarks:
    verticalMode must be one of the following:

    @table
    Name                  Value
    OdDb::kTextBottom     1
    OdDb::kTextVertMid    2
    OdDb::kTextTop        3
  */
  void setVerticalMode(
    OdDb::TextVertMode verticalMode);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm);

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  virtual OdResult explodeGeometry(
    OdDbVoidPtrArray& entitySet) const;

  OdResult subGetClassID(
    CLSID* pClsid) const;

  OdResult subClose();

  /** Description:
    Explodes this MText entity into a sequence of simple text fragments, passing each
    fragment to the specified function

    Arguments:
    fragmentFn (I) Function pointer to the fragment elaboration callback function.
    params (I) Void pointer to the fragmentFn callback function's second argument.
    ctxt (I) Drawing *context*.

    Remarks:
    The prototype of the fragment elaboration is as follows:

            int (*OdDbMtextEnum)(OdDbMTextFragment *fragment, void *param)

    If ctxt is null, the current OdGiWorldDraw object will be used.

    The elaboration function should return 1 to continue, or 0 to terminate the explosion.

    Each new line in this MText entity, and each change of text attributes, will start a new fragment.
  */
  void explodeFragments(
    OdDbMTextEnum fragmentFn,
    void *params,
    OdGiWorldDraw *ctxt = 0) const;

  /** Description:
    Returns the height of the bounding box of this MText entity.

    Arguments:
    ctxt (I) Drawing *context*.

    Remarks:
    If ctxt is null, the current OdGiWorldDraw object will be used.
  */
  double actualHeight(
    OdGiWorldDraw *ctxt = 0) const;

  /** Description:
    Returns the WCS bounding points of this MText entity.

    Arguments:
    boundingPoints (O) Receives the bounding points.

    Remarks:
    The points are returned as follows:

    @table
    Point                Corner
    boundingPoints[0]    Top left
    boundingPoints[1]    Top right
    boundingPoints[2]    Bottom left
    boundingPoints[3]    Bottom right
  */
  void getBoundingPoints(
    OdGePoint3dArray& boundingPoints) const;

  /** Description:
    Sets the *type* of *attachment* point of this MText entity (DXF 71).
    Arguments:
    attachment (I) Type of *attachment* point.

    Remarks:
    attachment must be one of the following:

    @table
    Name            Value
    kTopLeft        1
    kTopCenter      2
    kTopRight       3
    kMiddleLeft     4
    kMiddleCenter   5
    kMiddleRight    6
    kBottomLeft     7
    kBottomCenter   8
    kBottomRight    9

    Note:
    setAttachment() keeps the location of this MText entity constant
    while changing the *attachment* type, thereby changing the extents of (moving) this MText entity.

    setAttachmentMovingLocation() adjusts the location of the MText entity
    while changing the *attachment* type, so as to maintain the extents (not move) this MText entity.

    See also:
    setAttachment
  */
  OdResult setAttachmentMovingLocation(
    AttachmentPoint attachment);

  virtual OdResult subGetGeomExtents( // Gcad(Modify)
    OdDbExtents& extents) const;

  /** Description:
    Returns true if and only if background fill is on of this MText entity (DXF 90, bit 0x01).
  */
  bool backgroundFillOn() const;

  /** Description:
    Controls the background fill of this MText entity (DXF 90, bit 0x01).
    Arguments:
    enable (I) True to *enable* background fill, false to *disable*.
  */
  OdResult setBackgroundFill(
    bool enable);

  /** Description:
    Returns the background fill *color* of this MText entity (DXF 63 and optionally 421 & 431).
  */
  OdCmColor getBackgroundFillColor() const;

  /** Gcad(Add)(07)
  */
  OdResult getBackgroundFillColor(
    OdCmColor& color) const;

  /** Description:
    Sets the background fill *color* of this MText entity (DXF 63 and optionally 421 & 431).
    Arguments:
    color (I) Background fill *color*.
  */
  OdResult setBackgroundFillColor(
    const OdCmColor& color);

  /** Description:
    Returns the background scale factor of this MText entity (DXF 45).

    Remarks:
    The filled background area is extended by (ScaleFactor - 1) * TextHeight in all directions.
  */
  double getBackgroundScaleFactor() const;

  /** Gcad(Add)(07)
  */
  OdResult getBackgroundScaleFactor(
    double& scale) const;

  /** Description:
    Sets the background scale factor of this MText entity (DXF 45).

    Arguments:
    scaleFactor (I) Background scale factor. [1..5]

    Remarks:
    The filled background area is extended by (ScaleFactor - 1) * TextHeight in all directions.

  */
  OdResult setBackgroundScaleFactor(
    const double scaleFactor);

  /** Description:
    Returns the background *transparency* of this MText entity (DXF 441).
  */
  OdCmTransparency getBackgroundTransparency() const;

  /** Gcad(Add)(07)
  */
  OdResult getBackgroundTransparency(
    OdCmTransparency& transp) const;

  /** Description:
    Sets the background *transparency* of this MText entity (DXF 441).
    Arguments:
    transparency (I) Background *transparency*.
  */
  OdResult setBackgroundTransparency(
    const OdCmTransparency& transparency);

  /** Description:
    Returns true if and only if the screen background *color* is
    used as the background *color* of this MText entity (DXF 90, bit 0x02).
  */
  bool useBackgroundColorOn() const;

  /** Description:
    Controls the use of the screen background *color* as the background *color*
    of this MText entity (DXF 90, bit 0x02).

    Arguments:
    enable (I) True to use the screen background *color*, false to use
               the setBackgroundFillColor() *color*.
  */
  OdResult setUseBackgroundColor(
    bool enable);

  /** Description:
    Returns the paragraph indentation and tab data of this MText entity.
    Arguments:
    indents (O) Receives the indentation and tab data.
  */
  void getParagraphsIndent(
    OdDbMTextIndents& indents) const;

  using OdDbObject::setField;
  virtual OdResult setField(
    const OdChar* pFieldName, 
    OdDbField* pField,
    OdDbObjectId& fieldId);
  using OdDbObject::removeField;

  virtual OdResult removeField(
    OdDbObjectId fieldId);

  OdResult setUseWordBreak(bool bEnable);

  /**Description:
    Converts the fields in this MText entity to text, and removes the fields.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    The fields are not evaluated before conversion.
  */
  OdResult convertFieldToText();

  /** Note:
    This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
    the dimension style of this entity to the current style for the specified *database*.
  */
  void subSetDatabaseDefaults(OdDbDatabase *pDb);

  enum ColumnType {
    kNoColumns,
    kStaticColumns,
    kDynamicColumns
  };

  /** Gcad(Add)(08)
      Gcad(Modify)(08): returns:void->OdResult
  */
  OdResult setDynamicColumns(double width, double gutter, bool bAutoHeigh);
  OdResult setStaticColumns(double width, double gutter, int count);

  ColumnType getColumnType() const;
  OdResult getColumnType(ColumnType&) const;  // Gcad(Add)
  OdResult setColumnType(ColumnType colType);

  bool getColumnAutoHeight() const;
  OdResult getColumnAutoHeight(bool&) const;  // Gcad(Add)
  OdResult setColumnAutoHeight(bool bAutoHeigh);

  OdInt getColumnCount() const;
  OdResult getColumnCount(OdInt&) const;  // Gcad(Add)
  OdResult setColumnCount(OdInt numCol);

  double getColumnWidth() const;
  OdResult getColumnWidth(double&) const;  // Gcad(Add)
  OdResult setColumnWidth(double colWidth);

  double getColumnGutterWidth() const;
  OdResult getColumnGutterWidth(double&) const;  // Gcad(Add)
  OdResult setColumnGutterWidth(double colGutter);

  bool getColumnFlowReversed() const;
  OdResult getColumnFlowReversed(bool&) const;  // Gcad(Add)
  OdResult setColumnFlowReversed(bool bFlowRev);

  double getColumnHeight(OdInt col) const;
  OdResult getColumnHeight(OdInt col, double&) const;  // Gcad(Add)
  OdResult setColumnHeight(OdInt col, double colHeight);

  double refRectWidth() const; // Gcad(Add)
  OdResult setRefRectWidth(double dWidth); // Gcad(Add)

  double refRectHeight() const; // Gcad(Add)
  OdResult setRefRectHeight(double dHeight); // Gcad(Add)
  
  double height() const;
  void setHeight(double value);

  bool useWordBreak() const;

  virtual OdResult getPlane(OdGePlane& plane, OdDb::Planarity& planarity) const;

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdBool subCloneMeForDragging();

  double      ascent() const;
  double      descent() const;

  /** \details
    Sets the flag controlling mtext border's visibility.

    \param bEnable [in]  - True means borders will be visible and false means borders will be invisible.
  */
  OdResult setShowBorders(bool bEnable);

  /** Gets the flag controlling mtext border's visibility.  
  */
  bool showBorders();
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMText object pointers.
*/
typedef OdSmartPtr<OdDbMText> OdDbMTextPtr;

#include "TD_PackPop.h"

#endif

