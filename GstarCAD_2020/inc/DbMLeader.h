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

#ifndef OD_MLEADER_H
#define OD_MLEADER_H

#include "TD_PackPush.h"
#include "DbMLeaderStyle.h"
#include "DbEntity.h"
#include "DbSubentId.h"
#include "DbAttribute.h"
#include "IntArray.h"

#define MAX_LEADER_NUMBER     5000
#define MAX_LEADERLINE_NUMBER 5000

class OdDbAttribute;
class OdDbMLeaderObjectContextData;

/** Description:
    This class is the main class used for the multiple leader (MLeader) objects. 
        
    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbMLeader : public OdDbEntity
{
public:
  /** Description:
    Enumeration for MLeader move type.
  */
  enum MoveType {
    /** Description:
      All MLeader points should be moved.
    */
    kMoveAllPoints,

    /** Description:
      All MLeader points should be moved, except the arrowhead points of the leader line.
    */
    kMoveAllExceptArrowHeaderPoints,

    /** Description:
      MLeader content points and dog-leg points should be moved.
    */
    kMoveContentAndDoglegPoints
  };

  /** Description:
    Enumeration for MLeader GS mark type.
  */
  enum gsMarkType {
    /** Description:
      No GS mark.
    */
    kNone               = 0,

    /** Description:
      GS mark of arrow.
    */
    kArrowMark          = 1,

    /** Description:
      GS mark of leader line.
    */
    kLeaderLineMark     = kArrowMark  + MAX_LEADERLINE_NUMBER,

    /** Description:
      GS mark of dog-leg.
    */
    kDoglegMark         = kLeaderLineMark + MAX_LEADERLINE_NUMBER,

    /** Description:
      GS mark of MText content.
    */
    kMTextMark          = kDoglegMark + MAX_LEADER_NUMBER,

    /** Description:
      GS mark of MText underline content (includes text frame if present).
    */
    kMTextUnderLineMark = kMTextMark + 1,

    /** Description:
      GS mark of tolerance content.
    */
    kToleranceMark      = kMTextUnderLineMark + 1,

    /** Description:
      GS mark of block content.
    */
    kBlockMark          = kToleranceMark + 1,

    /** Description:
      GS mark of block attribute content.
    */
    kBlockAttribute     = kBlockMark + 1
  };

  /** Description:
      Enumeration for MLeader properties which can be overridden.
  */
  enum PropertyOverrideType {
    /** Description:
      Leader line type.
    */
    kLeaderLineType         = 0,

    /** Description:
      Leader line color.
    */
    kLeaderLineColor        = 1,

    /** Description:
      Leader line type ID.
    */
    kLeaderLineTypeId       = 2,

    /** Description:
      Leader line weight.
    */
    kLeaderLineWeight       = 3,

    /** Description:
      Enable landing.
    */
    kEnableLanding          = 4,

    /** Description:
      Landing gap.
    */
    kLandingGap             = 5,

    /** Description:
      Enable dog-leg.
    */
    kEnableDogleg           = 6,

    /** Description:
      Dog-leg length.
    */
    kDoglegLength           = 7,

    /** Description:
      Arrow symbol ID.
    */
    kArrowSymbolId          = 8,

    /** Description:
      Arrow symbol size.
    */
    kArrowSize              = 9,

    /** Description:
      MLeader content type.
    */
    kContentType            = 10,

    /** Description:
      Text style ID (of MText).
    */
    kTextStyleId            = 11,

    /** Description:
      Text left attachment type (of MText).
    */
    kTextLeftAttachmentType = 12,

    /** Description:
      Text angle type (of MText).
    */
    kTextAngleType          = 13,

    /** Description:
      Text alignment type (of MText).
    */
    kTextAlignmentType      = 14,

    /** Description:
      Text color (of MText).
    */
    kTextColor              = 15,

    /** Description:
      Text height (of MText).
    */
    kTextHeight             = 16,

    /** Description:
      Enable text frame.
    */
    kEnableFrameText        = 17,

    /** Description:
      Enable use of default MText (from MLeaderStyle).
    */
    kDefaultMText           = 18,

    /** Description:
      Block content block ID.
    */
    kBlockId                = 19,

    /** Description:
      Block content color.
    */
    kBlockColor             = 20,

    /** Description:
      Block content scale.
    */
    kBlockScale             = 21,

    /** Description:
      Block content rotation.
    */
    kBlockRotation          = 22,

    /** Description:
      Block content connection type.
    */
    kBlockConnectionType    = 23,

    /** Description:
      MLeader scale.
    */
    kScale                  = 24,

    /** Description:
      Text right attachment type (of MText).
    */
    kTextRightAttachmentType = 25,

    /** Description:
      Text switch alignment type (of MText).
    */
    kTextSwitchAlignmentType = 26,

    /** Description:
      Text attachment direction (of MText).
    */
    kTextAttachmentDirection = 27,

    /** Description:
      Text top attachment type (of MText).
    */
    kTextTopAttachmentType   = 28,

    /** Description:
      Text bottom attachment type (of MText).
    */
    kTextBottomAttachmentType = 29,

    /** Description:
      Extend leader line to text.
    */
    kExtendLeaderToText      = 30,

    /** Description:
      Size of bit set.
    */
    kSize = kExtendLeaderToText + 1
  };

public:
  ODDB_DECLARE_MEMBERS(OdDbMLeader);

  OdDbMLeader();
  ~OdDbMLeader();

  virtual OdResult dwgInFields (OdDbDwgFiler* filer);

  virtual OdResult dwgOutFields(OdDbDwgFiler* filer) const;

  virtual OdResult dxfInFields (OdDbDxfFiler* filer);

  virtual OdResult dxfOutFields(OdDbDxfFiler* filer) const;

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);

  virtual void  subViewportDraw(OdGiViewportDraw* mode);

  virtual OdResult subTransformBy(const OdGeMatrix3d& xform);

  /** Description:
	Returns all subentity paths by graphic system marker.

	Arguments:
	type (I) The subentity type being queried. ( Only OdDb::kClassSubentType )
	gsMarker (I) The GS marker of the subentity being queried.
	pickPoint (I) The WCS point being queried. ( Not used )
	xrm (I) The WCS->DCS transformation matrix. ( Not used )
	subentPaths (0) The array of OdDbFullSubentPath objects.
	entAndInsertStack (I) The array of objectIds of the objects that are the nested containers of the subentity.
  */

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  /** Description:
	Returns all graphic system marker by subentity paths.

	Arguments:
	subPath (I) The OdDbFullSubentPath to the subentity.
	gsMarkers (I/O) The array of integer identifiers (GS markers).
  */

  virtual OdResult subGetGsMarkersAtSubentPath(
    const OdDbFullSubentPath& subPath, 
	OdGsMarkerArray& gsMarkers) const;

  /** Description:
	Deletes one or more subentities from an entity.

	Arguments:
	paths (I) The array of OdDbFullSubentPath objects.
  */

  virtual OdResult subDeleteSubentPaths(const OdDbFullSubentPathArray& paths);

  /** Description:
	Create an object by OdDbFullSubentPath to the subentity.

	Arguments:
	path (I) The OdDbFullSubentPath to the subentity.
  */

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;// Gcad(Modify)

  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;// Gcad(Modify)

  virtual OdResult subClose();// Gcad(Modify)

  virtual OdResult subErase(OdBool erasing);

  virtual void objectClosed(const OdDbObjectId dbObjId);

  virtual void modified(const OdDbObject* dbObj);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

#if 0
//////////////////////////////////////////////////////////////////////////////

  virtual OdResult getGripEntityUCS(
    const void* pGripAppData,
    OdGeVector3d& normalVec,
    OdGePoint3d& origin,
    OdGeVector3d& xAxis) const;

  virtual void  gripStatus(
    const OdDb::GripStat status);

/////////////////////////////////////////////////////////////////////////////////
#endif

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xform,
    OdDbEntity*& pEnt) const;


  /** Description:
    Sets the override status for the specified PropertyOverrideType.

    Arguments:
    propertyType (I) PropertyOverrideType which will be set.
    isOverride (I) true if an override for propertyType is to be set, false otherwise.
  */
  OdResult setOverride( // Gcad(Modify)
    PropertyOverrideType propertyType,
    bool isOverride = true);

  /** Description:
    Returns the override status for the specified PropertyOverrideType.

    Arguments:
    propertyType (I) PropertyOverrideType for which status is to be returned.

    Remarks:
    Returns true if an override has been set for the specified propertyType, false otherwise.
  */
  bool  isOverride(
    PropertyOverrideType propertyType) const;

  /** Description:
    Sets the MLeader scale, which affects arrowhead size and content scale.

    Arguments:
    scale (I) The scale value.

    Remarks:
    Returns eOk if successful.  Note that this function will set an override 
    for kScale PropertyOverrideType.
  */
  OdResult setScale(
    double scale);

  /** Description:
    Returns the MLeader scale, which affects arrowhead size and content scale.

  */
  double  scale() const;

  /** Description:
    Returns the specified attribute from the associated block content.

    Arguments:
    attdefId (I) ObjectID of an attribute definition.
    pAtt (O) Returned attribute object corresponding to attdefId.

    Remarks:
    If successful, returns eOk.
  */
  OdResult getBlockAttributeValue(
    OdDbObjectId attdefId,
    OdDbAttributePtr& pAtt) const;

  OdResult getBlockAttributeValue(
    const OdDbObjectId& attdefId,
    OdDbAttribute*& pAtt) const;

  OdResult getBlockAttributeValue(
    const OdDbObjectId& attdefId,
    OdChar*& value) const;

  /** Description:
    Sets the specified attribute within associated block content.

    Arguments:
    attdefId (I) ObjectID of attribute definition.
    pAtt (I) Attribute object pointer.

    Remarks:
    Returns eOk if successful.
  */
  OdResult setBlockAttributeValue(
    const OdDbObjectId& attdefId,
    const OdDbAttribute* pAtt);

  OdResult setBlockAttributeValue(
    const OdDbObjectId& attdefId,
    const OdChar* value);

  /** Description:
    Returns the WCS plane containing this MLeader object.
  */
  OdGePlane plane() const;

  /** Description:
    Sets the WCS plane containing this MLeader object.

    Arguments:
    plane (I) Place which will contain the MLeader.

    Remarks:
    Note that MLeader geometry will be updated appropriately to reflect the new location.
  */
  void  setPlane(
    const OdGePlane& plane);

  OdGeVector3d  normal() const;

  /** Description:
    Moves this MLeader object as specified by an input vector.

    vector (I) Vector which specifies the direction and distance of the move.
    moveType (I) Indicates how to move the MLeader.
    bAutoSwitchDogleg (I) If true, automatically switch leader lines after movoing the MLeader.

    Remarks:
    Returns eOk if successful.
  */
  OdResult moveMLeader(
    const OdGeVector3d& vector,
    MoveType moveType,
    bool bAutoSwitchDogleg = true);

  /** Description:
    Returns the the extents of the content for this MLeader.

    Arguments:
    extents (O) Receives the content extents.

    Remarks:
    Returns eOk if successful.
  */
  OdResult getContentGeomExtents(
    OdDbExtents& extents) const;

  int numLeaders() const;
  /** Description:

    Arguments:
    leaderIndexes (O) Returned indexes.
  */
  void getLeaderIndexes(
    OdArray<int>& leaderIndexes) const;

  /** Description:
    Causes a new cluster to be added to this MLeader object, and returns the index of the new cluster.

    Arguments:
    leaderIndex (O) Index of newly added cluster.

    Remarks:
    A leader cluster consists of a dog-leg and leader lines.
  */
  OdResult addLeader( //Gcad(Modify)
    int& leaderIndex);

  /** Description:
    Removes the leader cluster specified by the passed-in index.

    Arguments:
    leaderIndex (I) Index of the cluster to be removed.

    Remarks:
    A leader cluster consists of a dog-leg and leader lines.
  */
  OdResult removeLeader( //Gcad(Modify)
    int leaderIndex);

  int               numLeaderLines      () const;
  /** Description:

    Arguments:
    leaderIndexes (O) Receives the indexes of leader lines for this MLeader.

    Remarks:
    Returns eOk if successful.
  */
  OdResult getLeaderLineIndexes( //Gcad(Modify)
    OdArray<int>& leaderLineIndexes);

  /** Description:
    Adds a leader line to the leader cluster specified by the supplied index.

    Arguments:
    leaderIndex (I) Leader cluster index.
    leaderLineIndex (O) Receives the index of the newly added leader line.
  */
  OdResult addLeaderLine(
    int leaderIndex, 
    int& leaderLineIndex);

  /** Description:
    Adds a new leader line to this MLeader.  The first point of the new leader line is passed in.

    Arguments:
    point (I) Specifies the first point of the new leader line.
    leaderLineIndex (O) Receives the index of the newly added leader line.

    Remarks:
    Returns eOk if successful. 
  */
  OdResult addLeaderLine(
    const OdGePoint3d& point, 
    int& leaderLineIndex);

  /** Description:
    Removes the leader line specified by the passed-in index.

    Arguments:
    leaderLineIndex (I) Index of the leader line to remove.

    Remarks:
    Note that removal of all leader lines will cause the MLeader to be removed as well.
  */
  OdResult removeLeaderLine( //Gcad(Modify)
    int leaderLineIndex);

  /** Description:
    Inserts a new first vertex into the specified leader line.

    Arguments:
    leaderLineIndex (I) Index of the leader line to which the vertext will be added.
    point (I) The position of the vertex.
  */
  OdResult addFirstVertex(
    int leaderLineIndex, const OdGePoint3d& point);

  /** Description:
    Removes the first vertex from the specified leader line.

    Arguments:
    leaderLineIndex (I) Index of the leader line from which the first vertex will be removed.

    Reamrks:
    Returns eOk if successful.
  */
  OdResult removeFirstVertex(
    int leaderLineIndex);

  /** Description:
    Returns the first vertex from the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    point (O) Receives the first vertex.

    Remarks:
    Returns eOk if successful.
  */
  OdResult getFirstVertex(
    int leaderLineIndex, 
    OdGePoint3d& point) const;

  /** Description:
    Sets the first vertex of the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    point (I) New position for the first vertex.

    Remarks:
    Returns eOk if successful.  Note that this function only sets the values for an existing 
    first vertex, but does not create any new vertices.
  */
  OdResult setFirstVertex(
    int leaderLineIndex, 
    const OdGePoint3d& point);

  /** Description:
    Appends a new last vertex onto the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    point (I) The new vertex position.

    Remarks:
    Returns eOk if successful.
*/
  OdResult addLastVertex(
    int leaderLineIndex,
    const OdGePoint3d& point);

  /** Description:
    Removes the last vertex from the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.

    Remarks:
    Returns eOk if successful.
  */
  OdResult removeLastVertex(
    int leaderLineIndex);

  /** Description:
    Returns the last vertex from the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    point (O) Receives the last vertex from the specified leader line.

    Remarks:
    Returns eOk if successful.
  */
  OdResult getLastVertex(
    int leaderLineIndex,
    OdGePoint3d& point) const;

  /** Description:
    Sets the last vertex of the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    point (I) New last vertex for specified leader line.
    
    Remarks:
    Returns eOk if successful.
*/
  OdResult setLastVertex(
    int leaderLineIndex,
    const OdGePoint3d& point);

  /** Description:
    Returns the number of vertices in the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    num (O) Receives the number of vertices in the specified leader line.

    Remarks:
    Returns eOk if successful.
  */
  OdResult numVertices(
    int leaderLineIndex, 
    int& num) const;

  /** Description:
    Sets the position for a specified vertex in a specified leader line. 

    Arguments:
    leaderLineIndex (I) Leader line index.
    index (I) The index of the vertex to be set.
    point (I) New coordinate value for the specified vertex.

    Remarks:
    Returns eOk if successful.
  */
  OdResult setVertex(
    int leaderLineIndex,
    int index,
    const OdGePoint3d& point);

  /** Description:
    Returns the position of a specified vertex in a specified leader line. 

    Arguments:
    leaderLineIndex (I) Leader line index.
    index (I) The index of the vertex.
    point (O) Receives the position value for the specified vertex.
    
    Remarks:
    Returns eOk if successful.
  */
  OdResult getVertex( //Gcad(Modify)
    int leaderLineIndex,
    int index, OdGePoint3d& point) const;

  /** Description:
    Returns the index of the leader cluster which contains the specified leader line.

    Arguments:
    leaderLineIndex (I) Leader line index.
    leaderIndex (O) Receives the index of the lead line owner.
  */
  OdResult getLeaderIndex( //Gcad(Modify)
    int leaderLineIndex,
    int& leaderIndex) const; 

  /** Description:
    Returns the indexes of all leader lines for the specified leader.

    Arguments:
    leaderIndex (I) Leader index.
    leaderLineIndexes (O) Receives the indexes of the owned leader lines.
  */
  OdResult getLeaderLineIndexes( //Gcad(Modify)
    int leaderIndex,
    OdArray<int>& leaderLineIndexes) const;

  /** Description:
    Sets the dog-leg direction for the specified leader cluster.

    Arguments:
    leaderIndex (I) Leader index.
    vector (I) The new dog-leg direction.
  */
  OdResult setDoglegDirection( //Gcad(Modify)
    int leaderIndex,
    const OdGeVector3d& vector);

  /** Description:
    Returns the dog-leg direction for the specified leader cluster.

    Remarks:
    leaderIndex (I) Leader index.
    vector (O) Receives the dog-leg direction.
*/
  OdResult getDoglegDirection( //Gcad(Modify)
    int leaderIndex,
    OdGeVector3d& vector) const;

  /** Description:
    Sets the leader line type for this MLeader object.

    Arguments:
    leaderLineType (I) Leader line type. 

    Remarks:
    The kLeaderLineType PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setLeaderLineType( //Gcad(Modify)
    OdDbMLeaderStyle::LeaderType leaderLineType);

  /** Description:
    Returns the leader line type for this MLeader object.
  */
  OdDbMLeaderStyle::LeaderType  leaderLineType() const;

  /** Description:
    Sets the leader line color for this MLeader.

    Arguments:
    leaderLineColor (I) Leader line color.

    Remarks:
    The kLeaderLineColor PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setLeaderLineColor( //Gcad(Modify)
    const OdCmColor& leaderLineColor);

  /** Description:
    Returns the leader line color for this MLeader.
  */
  OdCmColor leaderLineColor() const;

  /** Description:
    Sets the leader line linetype for this MLeader by OdDbObjectId.

    Arguments:
    leaderLineTypeId (I) Leader line type ObjectId.

    Remarks:
    The kLeaderLineTypeId PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setLeaderLineTypeId( //Gcad(Modify)
    OdDbObjectId leaderLineTypeId);

  /** Description:
    Returns the leader line linetype for this MLeader by OdDbObjectId.
  */
  OdDbObjectId  leaderLineTypeId() const;

  /** Description:
    Sets the leader line weight for this MLeader.

    Arguments:
    leaderLineWeight (I) Leader line weight.

    Remarks:
    The kLeaderLineWeight PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setLeaderLineWeight( //Gcad(Modify)
    OdDb::LineWeight leaderLineWeight);

  /** Description:
    Returns the leader line weight for this MLeader.
  */
  OdDb::LineWeight  leaderLineWeight() const;

  /** Description:
    Sets the landing gap for this MLeader (gap between the leader tail and associated MText).

    Arguments:
    landingGap (I) Landing gap (gap between the leader tail and associated MText).

    Remarks:
    The kLandingGap PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setLandingGap( //Gcad(Modify)
    double landingGap);

  /** Description:
    Returns the landing gap for this MLeader (gap between the leader tail and associated MText).
  */
  double  landingGap() const;

  /** Description:
    Sets the enabled/disabled status for leader landing line.

    Arguments:
    enableLanding (I) Leader landing line enabled status.

    Remarks:
    The kEnableLanding PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setEnableLanding( //Gcad(Modify)
    bool enableLanding);

  /** Description:
    Returns the enabled/disabled status for leader landing line.
  */
  bool  enableLanding() const;

  /** Description:
    Sets the enabled/disabled status for dog-leg leader line.

    Arguments:
    enableDogleg (I) Leader dog-leg line enabled status.

    Remarks:
    The kEnableDogleg PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setEnableDogleg( //Gcad(Modify)
    bool enableDogleg);

  /** Description:
    Returns the enabled/disabled status for dog-leg leader line.
  */
  bool  enableDogleg() const;

  /** Description:
    Sets the length for the dog-leg of the specified leader cluster.

    Arguments:
    leaderIndex (I) Leader index.
    dDoglegLength (I) Dog-leg length.

    Remarks:
    The kDoglegLength PropertyOverrideType override will be set as a result of
    calling this function.
  */
  OdResult setDoglegLength( //Gcad(Modify)
    int leaderIndex,
    double dDoglegLength);

  /** Description:
    Returns the length for the dog-leg of the specified leader cluster.

    leaderIndex (I) Leader index.
  */
  OdResult doglegLength(int leaderIndex , double& doglegLength) const;

  //deprecated 
  OdResult    setDoglegLength        (double doglegLength);
  //deprecated 
  double      doglegLength           () const;

  /** Description:
    Sets the arrow symbol for this MLeader (by ObjectId).

    Arguments:
    arrowSymbolId (I) Arrow symbol ObjectId.

    Remarks:
    The kDoglegLength PropertyOverrideType override will be set as a result of
    calling this function.  If this value is not set, the default arrow symbol 
    will be used.
  */
  OdResult setArrowSymbolId( //Gcad(Modify)
    OdDbObjectId arrowSymbolId);

  /** Description:
    Returns the arrow symbol for this MLeader (by ObjectId).
  */
  OdDbObjectId  arrowSymbolId() const;

  /** Description:
    Sets the arrow size for this MLeader object.

    Arguments:
    arrowSize (I) Arrow size.

    Remarks:
    The kArrowSize PropertyOverrideType override will be set as a result of
    calling this function.  
  */
  OdResult setArrowSize( //Gcad(Modify)
    double arrowSize);

  /** Description:
    Returns the arrow size for this MLeader object.
  */
  double  arrowSize() const;

  /** Description:
    Sets the content type for this MLeader object.

    Arguments:
    contentType (I) Content type.

    Remarks:
    The kContentType PropertyOverrideType override will be set as a result of
    calling this function.  
  */
  OdResult setContentType( //Gcad(Modify)
    OdDbMLeaderStyle::ContentType contentType);

  /** Description:
    Returns the content type for this MLeader object.
  */
  OdDbMLeaderStyle::ContentType contentType() const;

  /** Description:
    Sets the textstyle used by MText content (by ObjectId).

    Arguments:
    textStyleId (I) OdDbTextStyle ObjectId.

    Remarks:
    The kTextStyleId PropertyOverrideType override will be set as a result of
    calling this function.  
  */
  OdResult setTextStyleId(
    OdDbObjectId textStyleId);

  /** Description:
    Return the textstyle used by MText content (by ObjectId).
  */
  OdDbObjectId  textStyleId() const;

  /** Description:
    Sets the text attachment type used by MText content.

    Arguments:
    textAttachmentType (I) Text attachment type.
    leaderDirection (I) Text leader direction type.

    Remarks:
    The kTextLeftAttachmentType/kTextRightAttachmentType PropertyOverrideType override 
    will be set as a result of calling this function.  
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setTextAttachmentType(
      OdDbMLeaderStyle::TextAttachmentType textAttachmentType,
      OdDbMLeaderStyle::LeaderDirectionType leaderDirection);

  /** Description:
    Returns the text attachment type used by MText content.

    Arguments:
    leaderDirection (I) Text leader direction type.
  */
  OdDbMLeaderStyle::TextAttachmentType  textAttachmentType(
      OdDbMLeaderStyle::LeaderDirectionType leaderDirection) const;

  /** Description:
    Sets the angle type for MText content, with respect to the last leader line segment.

    Arguments:
    textAngleType (I) Text text angle type.

    Remarks:
    The kTextAngleType PropertyOverrideType override will be set as a result 
    of calling this function.  
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setTextAngleType(
    OdDbMLeaderStyle::TextAngleType textAngleType);

  /** Description:
    Returns the angle type for MText content, with respect to the last leader line segment.
  */
  OdDbMLeaderStyle::TextAngleType textAngleType() const;

  /** Description:
    Sets the text alignment type for MText content.

    Arguents:
    textAlignmentType (I) Text alignment type.

    Remarks:
    The kTextAlignmentType PropertyOverrideType override will be set as a result 
    of calling this function.  
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setTextAlignmentType(
    OdDbMLeaderStyle::TextAlignmentType textAlignmentType);

  /** Description:
    Returns the text alignment type for MText content.
  */
  OdDbMLeaderStyle::TextAlignmentType textAlignmentType() const;

  /** Description:
    Sets the text color for MText content.

    Arguments:
    textColor (I) Text color.

    Remarks:
    The kTextColor PropertyOverrideType override will be set as a result 
    of calling this function.
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setTextColor(const OdCmColor& textColor);

  /** Description:
    Returns the text color for MText content.
  */
  OdCmColor textColor() const;

  /** Description:
    Sets the text height for MText content.

    Argumenys:
    textHeight (I) Text height.

    Remarks:
    The kTextHeight PropertyOverrideType override will be set as a result 
    of calling this function.
	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTextHeight(
    double textHeight);

  /** Description:
    Returns the text height for MText content.
  */
  double  textHeight() const;

  /** Description:
    Sets the text frame visibility for MText content.

    Arguments:
    enableFrameText (I) True to enable the text frame, false otherwise.

    Remarks:
    The kEnableFrameText PropertyOverrideType override will be set as a result 
    of calling this function.
  */
  OdResult setEnableFrameText(
    bool enableFrameText);

  /** Description:
    Returns the text frame visibility for MText content.
  */
  bool  enableFrameText() const;

  /** Description:
    Sets the MText object to be associated with this MLeader.

    Arguments:
    pMText (I) The MText object to associate with this MLeader (if NULL, 
      the default MText defined in the associated MLeaderStyle is used).

    Remarks:
    The kDefaultMText PropertyOverrideType override will be set as a result 
    of calling this function.  The supplied MText object can be DBR or non-DBR.
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setMText(
    const OdDbMText* pMText);

  /** Description:
    Returns the MText content associated with this MLeader.
  */
  OdDbMText*  mtext() const;

  /** Description:
    Sets the referenced block for this MLeader, by block ObjectId.

    Arguments:
    blockId (I) Block table record ObjectId.

    Remarks:
    The kBlockId PropertyOverrideType override will be set as a result 
    of calling this function.  
  */
  OdResult setBlockContentId(
    OdDbObjectId blockId);

  /** Description:
    Returns the referenced block for this MLeader, by block ObjectId.
  */
  OdDbObjectId  blockContentId() const;

  /** Description:
    Sets the color used for block content.

    Arguments:
    blockColor (I) Block color.

    Reamrks:
    The kBlockColor PropertyOverrideType override will be set as a result 
    of calling this function.  
	Gcad(Modify):returns:void->OdResult
*/
  OdResult setBlockColor(
    const OdCmColor& blockColor);

  /** Description:
    Returns the color used for block content.
  */
  OdCmColor blockColor() const;

  /** Description:
    Sets the scale used by the referenced block.

    Arguments:
    scale (I) Referenced block scale.

    Remarks:
    The kBlockScale PropertyOverrideType override will be set as a result 
    of calling this function.  
  */
  OdResult setBlockScale(
    const OdGeScale3d& scale);

  /** Description:
    Returns the scale used by the referenced block.
  */
  OdGeScale3d blockScale() const;

  /** Description:
    Sets the rotation used by the referenced block.

    Arguments:
    rotation (I) Referenced block rotation.

    Remarks:
    The kBlockRotation PropertyOverrideType override will be set as a result 
    of calling this function.  
  */
  OdResult setBlockRotation(
    double rotation);

  /** Description:
    Returns the rotation used by the referenced block.
  */
  double blockRotation() const;

  /** Description:
    Sets the block connection type for this MLeader, which specifies how the 
    referenced block is connected to the leader lines.

    Aeguments:
    blockConnectionType (I) Block connection type.

    Remarks:
    The kBlockConnectionType PropertyOverrideType override will be set as a result 
    of calling this function.  
  */
  OdResult setBlockConnectionType(
    OdDbMLeaderStyle::BlockConnectionType blockConnectionType);

  /** Description:
    Returns the block connection type for this MLeader, which specifies how the 
    referenced block is connected to the leader lines.
  */
  OdDbMLeaderStyle::BlockConnectionType blockConnectionType() const;

  /** Description:
    Sets the annotation scale enabled status for this MLeader.

    Arguments:
    enableAnnotationScale (I) true if annotation scale is to be enabled, false otherwise.
  */
  OdResult setEnableAnnotationScale(
    bool enableAnnotationScale);

  /** Description:
    Returns the annotation scale enabled status for this MLeader.
  */
  bool  enableAnnotationScale() const;

  /** Description:
    Sets the MLeaderStyle used for this MLeader, by ObjectId.

    Arguments:
    newStyleId (I) New MLeaderStyle.
  */
  OdResult setMLeaderStyle(
    OdDbObjectId newStyleId);

  /** Description:
    Returns the MLeaderStyle used for this MLeader, by ObjectId.
  */
  OdDbObjectId  MLeaderStyle();

  /** Description:
    Returns the property set for the MLeader, including override values.

    Arguments:
    mleaderStyle (O) Receives the properties of this MLeader.

    Remarks:
    Returns eOk if successful. 
  */
  OdResult getOverridedMLeaderStyle(
    OdDbMLeaderStyle& mleaderStyle);

  /** Description:
    Sets the context data manager for this MLeader object.

    Arguments:
    pContextDataManager (I) Pointer to a context data manager.

    Remarks:
    Returns eOk if successful.
  */
  OdResult setContextDataManager(
    void* pContextDataManager);

  /** Description:
    Returns the context data manager for this MLeader object.
  */
  void* getContextDataManager() const;

  /** Description:
    Sets the position for the block referenced by this MLeader.

    Arguments:
    position (I) Block position.
  */
  OdResult setBlockPosition(
    const OdGePoint3d& position);

  /** Description:
    Returns the position for the block referenced by this MLeader.

    Arguments:
    position (O) Receives the block position.
	Gcad(Modify):returns:void->OdResult
*/
  OdResult getBlockPosition(
    OdGePoint3d& position);

  /** Description:
    Sets the location for the MText content associated with this MLeader.

    Arguments:
    location (I) MLeader mtext location.
  */
  OdResult setTextLocation(
    const OdGePoint3d& location);

  /** Description:
    Returns the location for the MText content associated with this MLeader.
  
    Arguments:
    location (O) Receives the MText location.
  */
  OdResult getTextLocation(
    OdGePoint3d& location);

  /** Description:
    Sets the location for MLeader tolerance content.

    Arguments:
    location (I) MLeader tolerance content location

    Remarks:
    Returns eOk if successful.
  */
  OdResult setToleranceLocation(
    const OdGePoint3d& location);

  /** Description:
    Returns the location for MLeader tolerance content.

    Arguments:
    location (O) Receives the MLeader tolerance content location.

    Returns eOk if successful.
  */
  OdResult getToleranceLocation(
    OdGePoint3d& location) const;

  /** Description:
    Sets the arrow head symbol for a specified leader line, by ObjectId.

    Arguments:
    leaderLineIndex (I) Leader line index.
    arrowSymbolId (I) Arrow symbol ObjectId.

    Remarks:
    Returns eOk if successful.
  */
  OdResult setArrowSymbolId(
    int leaderLineIndex,
    OdDbObjectId arrowSymbolId);

  /** Description:
    Returns the arrow head symbol for a specified leader line, by ObjectId.

    Arguments:
    leaderLineIndex (I) Leader line index.
  */
  OdDbObjectId  arrowSymbolId(
    int leaderLineIndex) const;

  /** Description:
    Returns true if this MLeader has content, false otherwise.
  */
  bool  hasContent() const;

  /** Description:
    Returns the connection point of this MLeader, for the speciefied direction.

    Arguments:
    vect (I) The specified direction.
    point (O) Receives the connection point.
  */
  OdResult connectionPoint(
    const OdGeVector3d& vect,
    OdGePoint3d& point) const;

  /** Description:
  Returns the connection point of this MLeader, for the speciefied direction.

  Arguments:
  vect (I) The specified direction.
  point (O) Receives the connection point.
  direction  The text attachment direction of MText. (Horizontally by default).  
  */
  OdResult connectionPoint(
    const OdGeVector3d& vect,
    OdGePoint3d& point,
    OdDbMLeaderStyle::TextAttachmentDirection direction) const;

  /** Description:
    Recomputes the dimension break points.

    Remarks:
    Returns eOk if successful.
  */  
  OdResult recomputeBreakPoints();

  /** Description:
    Adds this MLeader object to the Model Space block of the specified database.

    Arguments:
    pDb (I) Database to which this MLeader object should be added.

    Remarks:
    Returns eOk if successful.
  */
  OdResult postMLeaderToDb(
    OdDbDatabase* pDb);

  // dim associativity support

  /** Description:
    Updates leader line positions.

    Remarks:
    Returns eOk if successful.
  */
  OdResult updateLeaderLinePosition();

  /** Description:
    Removes the specified leader line's geometry association.

    Arguments:
    leaderLineIndex (I) Leader line index.

    Remarks:
    Returns eOk if successful.
  */
  OdResult removeLeaderLineRefAssoc(
    int leaderLineIndex) const;

  /** Description:
    Updates this MLeaders's arrow head, landing gap, dog-leg length, and text height or block scale.

    Arguments:
    pContext (I) MLeader context data.

    Remarks:
    Returns eOk if successful.
  */
  OdResult updateContentScale(
    OdDbMLeaderObjectContextData* pContext);

  virtual OdBool isPlanar() const;
  virtual OdResult getPlane(OdGePlane& plane, OdDb::Planarity& planarity) const;

  /** Description:
    Sets the text attachment direction of MText.

    Arguments:
    direction (I) The text attachment direction of MText.
  */
  void setTextAttachmentDirection(
    OdDbMLeaderStyle::TextAttachmentDirection direction);

  /** Description:
    Returns the text attachment direction of MText.
  */
  OdDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;

  /** Description:
      Enumeration of the individual leader line properties which can be overridden.
  */
  enum LeaderLineOverrideType
  {
    /** Description:
      Leader line type (OdDbMLeaderStyle::LeaderType).
    */
    kOverrideLeaderType = 0,
    /** Description:
      Leader line color.
    */
    kOverrideLineColor,
    /** Description:
      Leader line linetype ID.
    */
    kOverrideLineTypeId,
    /** Description:
      Leader line weight.
    */
    kOverrideLineWeight,
    /** Description:
      Leader line arrow size.
    */
    kOverrideArrowSize,
    /** Description:
      Leader line arrow symbol.
    */
    kOverrideArrowSymbolId  
  };
  
  /** Description:
    Returns the override status for the specified line property.

    Arguments:
    leaderLineIndex (I) leader line index for which status is to be returned.
    value (I) property identifier

    Remarks:
    Returns true if an override has been set for the specified property, false otherwise.
    (Override is set in the set* functions listed below, which accept leader line index as a first argument)
  */
  bool isOverride(int leaderLineIndex, LeaderLineOverrideType value);

  void setLeaderLineType(
    int leaderLineIndex,
    OdDbMLeaderStyle::LeaderType leaderLineType);

  OdDbMLeaderStyle::LeaderType leaderLineType(
    int leaderLineIndex) const;

    OdResult getLeaderLineType(int leaderLineIndex,
                                        OdDbMLeaderStyle::LeaderType& leaderLineType) const;


  OdResult setLeaderLineColor(
    int leaderLineIndex,
    const OdCmColor& leaderLineColor);

  OdResult getLeaderLineColor(
    int leaderLineIndex,
    OdCmColor& leaderLineColor) const;

  OdCmColor leaderLineColor(
    int leaderLineIndex) const;

  OdResult setLeaderLineTypeId(
    int leaderLineIndex,
    OdDbObjectId leaderLineTypeId);

  OdResult getLeaderLineTypeId(
    int leaderLineIndex,
    OdDbObjectId& leaderLineTypeId) const;

  OdDbObjectId leaderLineTypeId(
    int leaderLineIndex) const;

  OdResult setLeaderLineWeight(
    int leaderLineIndex,
    OdDb::LineWeight leaderLineWeight);

  OdResult getLeaderLineWeight(
    int leaderLineIndex,
    OdDb::LineWeight& leaderLineWeight) const;

  OdResult getArrowSymbolId(
    int leaderLineIndex,
    OdDbObjectId& arrowSymbolId) const;

  OdDb::LineWeight leaderLineWeight(
    int leaderLineIndex) const;

  OdResult setArrowSize(
    int leaderLineIndex,
    double arrowSize);

  double arrowSize(
    int leaderLineIndex) const;

  OdResult getArrowSize(
    int leaderLineIndex,
    double& arrowSize) const;

  /** Description:
    Set extend to text mode.

    Arguments:
    bSet (I) New value for extend to text mode flag.
  */
  void setExtendLeaderToText(bool bSet);

  /** Description:
    Returns extend to text mode flag.
  */
  bool extendLeaderToText() const;

  OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual OdBool subCloneMeForDragging();

  void subSetDatabaseDefaults(OdDbDatabase *pDb);

  /** Gcad(Add) 
  */
  virtual OdResult subIntersectWith(const OdDbEntity* pEnt,
							OdDb::Intersect intType, OdGePoint3dArray& points,
							OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
							const OdGePlane& projPlane, OdGePoint3dArray& points,
							OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbMLeader object pointers.
*/
typedef OdSmartPtr<OdDbMLeader> OdDbMLeaderPtr;

#include "TD_PackPop.h"

#endif // OD_MLEADER_H

