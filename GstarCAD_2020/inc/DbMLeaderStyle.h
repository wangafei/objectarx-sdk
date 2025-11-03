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




#ifndef OD_DBMLEADERSTYLE_H
#define OD_DBMLEADERSTYLE_H

#include "TD_PackPush.h"

#include "DbObject.h"
#include "DbMText.h"

class OdGeScale3d;
class OdString;

/** Description:
    This class represents *MLeader* Style objects in an OdDbDatabase instance.
    
    Library:
    TD_Db

    OdDbMLeaderStyle objects are stored in the ACAD_MLEADERSTYLE dictionary 
    in the Named Object Dictionary of an OdDbDatabase.
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbMLeaderStyle: public OdDbObject
{
public:
  /** Description:
    Enumeration for the content type of an MLeader.
  */
  enum ContentType {
    /** Description:
      The MLeader has no content.
    */
    kNoneContent                = 0,

    /** Description:
      The MLeader has block content.
    */
    kBlockContent               = 1,

    /** Description:
      The MLeader has mtext content.
    */
    kMTextContent               = 2,

    /** Description:
      The MLeader has tolerance content.
    */
    kToleranceContent           = 3
  };

  /** Description:
    Enumeration for the draw order type of an MLeader.
  */
  enum DrawMLeaderOrderType {
    /** Description:
      MLeader content should be drawn first.
    */
    kDrawContentFirst           = 0,

    /** Description:
      MLeader leaderline should be drawn first.
    */
    kDrawLeaderFirst            = 1
  };

  /** Description:
    Enumeration for MLeader Line draw order type.
  */
  enum DrawLeaderOrderType {
    /** Description:
      MLeader leaderline head should be drawn first.
    */
    kDrawLeaderHeadFirst        = 0,

    /** Description:
      MLeader leaderline tail should be drawn first.
    */
    kDrawLeaderTailFirst        = 1
  };

  /** Description:
    Enumeration for the leader type of MLeader.
  */
  enum LeaderType {
    /** Description:
      Invisible leader.
    */
    kInVisibleLeader            = 0,

    /** Description:
      Straight line leader.
    */
    kStraightLeader             = 1,
    
    /** Description:
      Spline leader.
    */
    kSplineLeader               = 2
  };

  /** Description:
    Enumeration for the text attachment direction of MLeader text.
  */
  enum TextAttachmentDirection {
    /** Description:
      Horizontal.
    */
    kAttachmentHorizontal       = 0,
    /** Description:
      Vertical.
    */
    kAttachmentVertical         = 1
  };

  /** Description:
    Enumeration for the text attachment type of MLeader text.
  */
  enum TextAttachmentType {
    /** Description:
      Use the top of the top text line as the attachment point.
    */
    kAttachmentTopOfTop         = 0,

    /** Description:
      Use the middle of the top text line as the attachment point.
    */
    kAttachmentMiddleOfTop      = 1,

    /** Description:
      Use the middle of the text as the attachment point.
    */
    kAttachmentMiddle           = 2,

    /** Description:
      Use the middle of the bottom text line as the attachment point.
    */
    kAttachmentMiddleOfBottom   = 3,

    /** Description:
      Use the bottom of the bottom text line as the attachment point.
    */
    kAttachmentBottomOfBottom   = 4,

    /** Description:
      Use the bottom text line as the attachment point.
    */
    kAttachmentBottomLine       = 5,

    /** Description:
      Use the bottom of the top text line as the attachment point.
    */
    kAttachmentBottomOfTopLine  = 6,

    /** Description:
      Use the bottom of the top text line as the attachment point.
    */
    kAttachmentBottomOfTop      = 7,

    /** Description:
      Use the bottom of the top text line as the attachment point, and underline all content.
    */
    kAttachmentAllLine          = 8,

    /** Description:
      Use the center of the mtext as the attachment point for vertical attachment.
    */
    kAttachmentCenter           = 9,

    /** Description:
      Use the center of the mtext as the attachment point for vertical attachment, and overline/underline all content.
    */
    kAttachmentLinedCenter      = 10
  };

  /** Description:
    Enumeration for the text angle type of MLeader text.
  */
  enum TextAngleType {
    /** Description:
      Text angle is specified according to the angle of the last leader line segment.
    */
    kInsertAngle                = 0,

    /** Description:
      Text is unconditionally horizontal.
    */
    kHorizontalAngle            = 1,
        
    /** Description:
      Text angle is specified according to the angle of the last leader line segment, 
      and text is always oriented right side up to be readable.
    */
    kAlwaysRightReadingAngle    = 2
  };

  /** Description:
    Enumeration for MLeader text alignment type.
  */
  enum TextAlignmentType {
    /** Description:
      MLeader text is left justified.
    */
    kLeftAlignment              = 0,

    /** Description:
      MLeader text is center justified.
    */
    kCenterAlignment            = 1,

    /** Description:
      MLeader text is right justified.
    */
    kRightAlignment             = 2
  };

  /** Description:
    Enumeration for the block connection type of MLeader block content.
  */
  enum BlockConnectionType {
    /** Description:
      MLeader should connect to the extents of the block.
    */
    kConnectExtents             = 0,

    /** Description:
      MLeader should connect to the base point of the block.
    */
    kConnectBase                = 1
  };

  /** Description:
    Enumeration for the direction type of an MLeader.
  */
  enum LeaderDirectionType {
    /** Description:
      Unknown direction type.
    */
    kUnknownLeader              = 0,

    /** Description:
      Direction type of left.
    */
    kLeftLeader                 = 1,

    /** Description:
      Direction type of right.
    */
    kRightLeader                = 2,

    /** Description:
      Direction type of top.
    */
    kTopLeader                  = 3,

    /** Description:
      Direction type of bottom.
    */
    kBottomLeader               = 4
  };


  /** Description:
    Enumeration for the segment angle type of an MLeader.
  */
  enum SegmentAngleType {
    /** Description:
      Any.
    */
    kAny                        = 0, 

    /** Description:
      Angle of 15 degrees.
    */    
    k15                         = 1,

    /** Description:
      Angle of 30 degrees.
    */
    k30                         = 2,

    /** Description:
      Angle of 45 degrees.
    */
    k45                         = 3,

    /** Description:
      Angle of 60 degrees.
    */
    k60                         = 4,

    /** Description:
      Angle of 90 degrees.
    */
    k90                         = 6,

    /** Description:
      Angle of 180 degrees.
    */
    kHorz                       = 12
  };

public:
  ODDB_DECLARE_MEMBERS(OdDbMLeaderStyle);

  OdDbMLeaderStyle();

  void setDatabaseDefaults( OdDbDatabase* pDb );

  //Gcad(Add)
  virtual ~OdDbMLeaderStyle();

  /** Description:
    Returns the name of this OdDbMLeaderStyle.
  */
  virtual OdString name() const;
  virtual OdResult getName(OdChar*& pszName) const;
 
  /** Description:
    Sets the name of this OdDbMLeaderStyle.

    Arguments:
    name (I) Holds the name of OdDbMLeaderStyle.
  */
  /*/Gcad(Modify)
  virtual void   setName(
    const OdString& name);
  /*/
  virtual OdResult   setName(const OdChar* pszName);
  //*/
  /** Description:
    Returns the description of this OdDbMLeaderStyle.
  */
  /*/Gcad(Modify)
  virtual OdString  description(void) const;
  /*/
  virtual const OdChar*  description(void) const;
  //*/
  /** Description:
    Sets the description of this OdDbMLeaderStyle.

    Arguments:    
    description (I) OdDbMLeaderStyle description string.
  */
  /*/Gcad(Modify)
  virtual void   setDescription(
    const OdString& pszDescription);
  /*/
  virtual OdResult   setDescription(const OdChar* pszDescription);
  //*/
  /** Description: 
    Returns the set of bit flags this OdDbMLeaderStyle.
  */
  virtual OdUInt32       bitFlags() const;

  /** Description:
    Sets the bit flags for this OdDbMLeaderStyle.

    Arguments:
    flags (I) The bit flags for this OdDbMLeaderStyle.
  */
  virtual OdResult setBitFlags(
    OdUInt32 flags);

  /** Description:
    Sets the content type for this OdDbMLeaderStyle.

    Arguments:
    contentType (I) The content type.
  */
  OdResult setContentType(
    ContentType contentType);

  /** Description:
    Returns the content type for this OdDbMLeaderStyle.
  */
  ContentType contentType() const;

  /** Description:
    Sets the draw order for the content of OdDbMLeader objects using this OdDbMLeaderStyle.

    Argumets:
    drawMLeaderOrderType (I) Draw order type for MLeader content.
  */
  OdResult setDrawMLeaderOrderType(
    DrawMLeaderOrderType drawMLeaderOrderType);

  /** Description:
    Returns the draw order for the content of OdDbMLeader objects using this OdDbMLeaderStyle.
  */
  DrawMLeaderOrderType  drawMLeaderOrderType() const;

  /** Description:
    Sets the leader line draw order for OdDbMLeader objects using this OdDbMLeaderStyle.
  
    Arguments:
    drawLeaderOrderType (I) The Leader line draw order.
  */
  OdResult setDrawLeaderOrderType(
    DrawLeaderOrderType drawLeaderOrderType);

  /** Description:
    Returns the leader line draw order for OdDbMLeader objects using this OdDbMLeaderStyle.
  */
  DrawLeaderOrderType drawLeaderOrderType() const;

  /** Description:
    Sets the maximun number of segment points used for leader lines.

    Arguments:
    maxLeaderSegmentsPoints (I) The maximum number of segment points.

    Remarks:
    A value of 0 for maxLeaderSegmentsPoints indicates no limit.
  */
  OdResult setMaxLeaderSegmentsPoints(
    int maxLeaderSegmentsPoints);

  /** Description:
    Returns the maximun number of segment points used for leader lines.
  */
  int maxLeaderSegmentsPoints() const;

  /** Description:
    Sets the constraint angle for the first segment (used for creating OdDbMLeader objects).

    Arguments:
    angle (I) Constraint angle.

    Remarks:
    A value of kAny for "angle" indicates that no constraint is used.
  */
  OdResult setFirstSegmentAngleConstraint(
    SegmentAngleType angle);

  /** Description:
    Returns the constraint angle for the first segment (used for creating OdDbMLeader objects).

    Remarks:
    A return value of kAny indicates that no constraint is used.
  */
  SegmentAngleType  firstSegmentAngleConstraint() const;

  /** Description:
    Sets the constraint angle for the second segment (used for creating OdDbMLeader objects).

    Arguments:
    angle (I) Constraint angle.

    Remarks:
    A value of kAny for "angle" indicates that no constraint is used.
  */
  OdResult setSecondSegmentAngleConstraint(
    SegmentAngleType angle);

  /** Description:
    Sets the constraint angle for the second segment (used for creating OdDbMLeader objects).

    Remarks:
    A return value of kAny indicates that no constraint is used.
  */
  SegmentAngleType  secondSegmentAngleConstraint() const;

  /** Description:
    Sets the leader line type for this OdDbMLeaderStyle.

    Arguments:
    leaderLineType (I) The leader line type.
  */
  OdResult setLeaderLineType(
    LeaderType leaderLineType);

  /** Description:
    Returns the leader line type for this OdDbMLeaderStyle.
  */
  LeaderType  leaderLineType() const;

  /** Description:
    Set the leader line color for this OdDbMLeaderStyle.

    Arguments:
    leaderLineColor (I) The leader line color.
  */
  OdResult setLeaderLineColor(
    const OdCmColor& leaderLineColor);

  /** Description:
    Returns the leader line color for this OdDbMLeaderStyle.
  */
  OdCmColor leaderLineColor() const;

  /** Description:
    Sets the leader line linetype for this OdDbMLeaderStyle.

    Arguments:
    leaderLineTypeId (I) The linetype Id.
  */
  OdResult setLeaderLineTypeId(
    OdDbObjectId leaderLineTypeId);

  /** Description:
    Returns the leader line linetype for this OdDbMLeaderStyle.
  */
  OdDbObjectId  leaderLineTypeId() const;

  /** Description:
    Sets the leader line lineweight for this OdDbMLeaderStyle.

    Arguments:
    leaderLineWeight (I) The leader line lineweight.
  */
  OdResult setLeaderLineWeight(
    OdDb::LineWeight leaderLineWeight);

  /** Description:
    Returns the leader line lineweight for this OdDbMLeaderStyle.
  */
  OdDb::LineWeight  leaderLineWeight() const;

  /** Description:
    Sets the leader line landing for this OdDbMLeaderStyle.

    Arguments:
    enableLanding (I) The leader line landing.

    Remarks:
    If landing is disabled, landing gap is ignored.
  */
  OdResult setEnableLanding(
    bool enableLanding);

  /** Description:
    Returns leader line landing for this OdDbMLeaderStyle.
  */
  bool  enableLanding() const;

  /** Description:
    Sets the gap between the leader line tail and the MText associated with the OdDbMLeader.

    Arguments:
    landingGap (I) The gap between the leader line tail and the MText associated with the OdDbMLeader.
  */
  OdResult setLandingGap(
    double landingGap);

  /** Description:
    Returns the gap between the leader line tail and the MText associated with the OdDbMLeader.
  */
  double  landingGap() const;

  /** Description:
    Sets the "dog leg" flag for this OdDbMLeaderStyle, which controls dog leg leader lines.

    Arguments:
    enableDogleg (I) "Dog leg" flag.
  */
  OdResult setEnableDogleg(
    bool enableDogleg);

  /** Description:
    Returns the "dog leg" flag for this OdDbMLeaderStyle, which controls dog leg leader lines.
  */
  bool  enableDogleg() const;

  /** Description:
    Sets the "dog leg" leader line length for this OdDbMLeaderStyle.

    Arguments:
    doglegLength (I) The "dog leg" leader line length.
  */
  OdResult setDoglegLength(
    double doglegLength);

  /** Description:
    Returns the "dog leg" leader line length for this OdDbMLeaderStyle.
  */
  double  doglegLength() const;

  /** Description:
    Sets the arrow symbol for this OdDbMLeaderStyle by name.

    Arguments:
    name (I) Name of the arrow symbol.
  */
  OdResult setArrowSymbolId(
    const OdChar* name);

  /** Description:
    Sets the arrow symbol for this OdDbMLeaderStyle by OdDbObjectId.

    Arguments:
    arrowSymbolId (I) OdDbObjectId of the arrow symbol.
  */
  OdResult setArrowSymbolId(
    OdDbObjectId arrowSymbolId);

  /** Description:
    Returns the arrow symbol for this OdDbMLeaderStyle as an OdDbObjectId.
  */
  OdDbObjectId  arrowSymbolId() const;

  /** Description:
    Sets the arrow size for this OdDbMLeaderStyle.

    Arguments:
    arrowSize (I) The arrow size.
  */
  OdResult setArrowSize(
    double arrowSize);

  /** Description:
    Returns the arrow size for this OdDbMLeaderStyle.
  */
  double  arrowSize() const;

  /** Description:
    Sets the default text used in an associated MText balloon.

    Arguments:
    defaultMText (I) The default text used in an associated MText balloon.
  */
  OdResult setDefaultMText(
    const OdDbMText* defaultMText);

  /** Description:
    Sets the default text used in an associated MText balloon.

    Remarks:
    The returned MText object is cloned, and can be NULL if there is no default MText.
  */
  //Gcad(Modify)
  OdDbMText*  defaultMText() const;

  /** Description:
    Sets the text style for this OdDbMLeaderStyle by OdDbObjectId.

    Arguments:
    textStyleId (I) The text style.
  */
  OdResult setTextStyleId(
    OdDbObjectId textStyleId);

  /** Description:
    Returns the text style OdDbObjectId for this OdDbMLeaderStyle.
  */
  OdDbObjectId  textStyleId() const;

  /** Description:
    Sets the text attachment type for this OdDbMLeaderStyle.

    Arguments:
    textAttachmentType (I) The text attachment type.
    leaderDirection (I) The leader direction type.
  */
  OdResult setTextAttachmentType(
    TextAttachmentType textAttachmentType,
    LeaderDirectionType leaderDirection);

  /** Description:
    Returns the text attachment type for this OdDbMLeaderStyle.

    Arguments:
    leaderDirection (I) The leader direction type.

    Remarks:
    Returns the text attachment type.
  */
  TextAttachmentType  textAttachmentType(
    LeaderDirectionType leaderDirection) const;

  /** Description:
    Sets the text angle type for this OdDbMLeaderStyle.

    Arguments:
    textAngleType (I) The text angle type.
  */
  OdResult setTextAngleType(
    TextAngleType textAngleType);

  /** Description:
    Returns the text angle type for this OdDbMLeaderStyle.
  */
  TextAngleType textAngleType() const;

  /** Description:
    Sets the text alignment type for this OdDbMLeaderStyle.

    Arguments:
    textAlignmentType (I) The text alignment type.
  */
  OdResult setTextAlignmentType(
    TextAlignmentType textAlignmentType);

  /** Description:
    Returns the text alignment type for this OdDbMLeaderStyle.
  */
  TextAlignmentType textAlignmentType() const;

  /** Description:
    Sets the "always create left aligned text" property for this OdDbMLeaderStyle.

    Arguments:
    bAlwaysLeft (I) If true, text will be left aligned for newly created OdDbMLeader objects.
  */
  OdResult setTextAlignAlwaysLeft(
    bool bAlwaysLeft);

  /** Description:
    Returns the "always create left aligned text" property for this OdDbMLeaderStyle.
  */
  bool  textAlignAlwaysLeft() const;

  /** Description:
    Sets the text color for this OdDbMLeaderStyle.

    Arguments:
    textColor (I) The text color used for associated OdDbMText object.
  */
  OdResult setTextColor(
    const OdCmColor& textColor);

  /** Description:
    Returns the text color for this OdDbMLeaderStyle.
  */
  OdCmColor textColor() const;

  /** Description:
    Sets the text height for the associated OdDbMText object.
  
    Arguments:
    textHeight (I) The text height.
  */
  OdResult setTextHeight(
    double textHeight);

  /** Description:
    Returns the text height for the associated OdDbMText object.
  */
  double  textHeight() const;

  /** Description:
    Sets the display/hide property for the frame around associated text.
  
    Arguments:
    enableFrameText (I) True if a frame is to be displayed around associated text, false otherwise.
  */
  OdResult setEnableFrameText(
    bool enableFrameText);

  /** Description:
    Returns true if a frame is to be displayed around associated text, false otherwise.
  */
  bool  enableFrameText() const;

  /** Description:
    Sets the alignment space value for this OdDbMLeaderStyle.

    Arguments:
    alignSpace (I) The alignment space value.
  */
  OdResult setAlignSpace(
    double alignSpace);

  /** Description:
    Returns the alignment space value for this OdDbMLeaderStyle.
  */
  double  alignSpace() const;

  /** Description:
    Sets the block to be associated with this OdDbMLeaderStyle by name.

    Arguments:
    name (I) The name of the standard block.
  */
  OdResult setBlockId(
    const OdChar* name);

  /** Description:
    Sets the block to be associated with this OdDbMLeaderStyle by OdDbObjectId.

    Arguments:
    blockId (I) OdDbObjectId of the OdDbBlockTableRecord associated with this OdDbMLeaderStyle.
  */
  OdResult setBlockId(
    OdDbObjectId blockId);

  /** Description:
    Returns the OdDbObjectId of the block associated with this OdDbMLeaderStyle.
  */
  OdDbObjectId  blockId() const;

  /** Description:
    Sets the color for block content associated with this OdDbMLeaderStyle.

    Arguments:
    blockColor (I) The color for block content.
  */
  OdResult setBlockColor(
    const OdCmColor& blockColor);

  /** Description:
    Returns the color for block content associated with this OdDbMLeaderStyle.
  */
  OdCmColor blockColor() const;

  /** Description:
    Sets the scale for the block associated with this by OdDbMLeaderStyle.

    Arguments:
    scale (I) The block scale.
  */
  OdResult setBlockScale(
    const OdGeScale3d& scale);

  /** Description:
    Returns the scale for the block associated with this by OdDbMLeaderStyle.
  */
  OdGeScale3d blockScale() const;

  /** Description:
    Enables/disables usage of the scale value set by setBlockScale().

    Arguments:
    enableBlockScale (I) true if block scale is to be used, false otherwise.
  */
  OdResult setEnableBlockScale(
    bool enableBlockScale);

  /** Description:
    Returns true if block scale (set by setBlockScale) is to be used, false otherwise.
  */
  bool  enableBlockScale() const;

  /** Description:
    Sets the rotation value for the block referenced by this OdDbMLeaderStyle.

    Arguments:
    rotation (I) The rotation value.
  */
  OdResult setBlockRotation(
    double rotation);

  /** Description:
    Returns the rotation value for the block referenced by this OdDbMLeaderStyle.
  */
  double  blockRotation() const;

  /** Description:
    Enables/disables usage of the rotation value set by setBlockRotation().

    Arguments:
    enableBlockRotation (I) true if block rotation is to be used, false otherwise.

  */
  OdResult setEnableBlockRotation(
    bool enableBlockRotation);

  /** Description:
    Returns true if block rotation (set by setBlockRotation) is to be used, false otherwise.
  */
  bool  enableBlockRotation() const;

  /** Description:
    Sets the connection type for the associated block.

    Arguments:
    blockConnectionType (I) The connection type.
  */
  OdResult setBlockConnectionType(
    BlockConnectionType blockConnectionType);

  /** Description:
    Returns the connection type for the associated block.
  */
  BlockConnectionType blockConnectionType() const;

  /** Description:
    Sets the scale factor for this OdDbMLeaderStyle.

    Arguments:
    scale (I) Scale factor.
  */
  OdResult setScale(
    double scale);

  /** Description:
    Returns the scale factor for this OdDbMLeaderStyle.
  */
  double  scale() const;

  /** Description:
    Returns true if properties were modified, false otherwise.
  */
  bool  overwritePropChanged() const;

  /** Description:
    Add this OdDbMLeaderStyle to the specified OdDbDatabase object.
    
    Arguments:
    pDb (I) Pointer of the database which will receive the OdDbMLeaderStyle object.
    styleName (I) Name of the style.
    
    Remarks:
    Returns the OdDbObjectID of the newly added OdDbMLeaderStyle object.
  */
  //Gcad(Modify)
  OdResult postMLeaderStyleToDb(
    OdDbDatabase* pDb, 
    const OdChar* styleName,
	OdDbObjectId& mleaderStyleId);

  /** Description:
    Sets the annotative flag for this OdDbMLeaderStyle.

    Arguments:
    isAnnotative (I) The annotative status.
  */
  OdResult setAnnotative(
    bool isAnnotative);

  /** Description:
    Returns the annotative flag for this OdDbMLeaderStyle.
  */
  bool  annotative() const;

  /** Description:
    Sets the gap used in the process of breaking leader lines.

    Arguments:
    size (I) The gap used in the process of breaking leader lines.
  */
  OdResult setBreakSize (
    double size);

  /** Description:
    Returns the gap used in the process of breaking leader lines.
  */
  double  breakSize() const;

  /** Description:
    Sets the text attachment direction of MText.

    Arguments:
    direction (I) The text attachment direction of MText.
  */

  OdResult setTextAttachmentDirection(
    TextAttachmentDirection direction);

  /** Description:
    Returns the text attachment direction of MText.
  */
  TextAttachmentDirection textAttachmentDirection() const;

  /** Description:
    Sets horizontal mleader lines extend to text mode.

    Arguments:
    bSet (I) Extend to text mode status.
  */
  void setExtendLeaderToText(bool bSet);

  /** Description:
    Returns horizontal mleader lines extend to text mode.
  */
  bool extendLeaderToText() const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult subClose();

  OdResult subGetClassID(CLSID* pClsid) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMLeaderStyle object pointers.
*/
typedef OdSmartPtr<OdDbMLeaderStyle> OdDbMLeaderStylePtr;

#include "TD_PackPop.h"

#endif
