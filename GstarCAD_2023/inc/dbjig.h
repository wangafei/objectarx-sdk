/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _DBJIG_H_
#define   _DBJIG_H_ 1

#if defined(__cplusplus)
#include "gccoredefs.h"
#include "dbDimData.h"  
#pragma pack (push, 8)

class GcEdImpJig;
class GcDbEntity;
class GcEdImpDragStyle;
class GcGePoint3d;
class GcGiVisualStyle;
class GcEdDragStyle;
class GcEdJigInputHelper;

class GCCORE_PORT GcEdJig : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdJig);

  enum UserInputControls {
    kGovernedByOrthoMode = 0x000001,
    kNullResponseAccepted = 0x000002,
    kDontEchoCancelForCtrlC = 0x000004,
    kDontUpdateLastPoint = 0x000008,
    kNoDwgLimitsChecking = 0x000010,
    kNoZeroResponseAccepted = 0x000020,
    kNoNegativeResponseAccepted = 0x000040,
    kAccept3dCoordinates = 0x000080,
    kAcceptMouseUpAsPoint = 0x000100,
    kAnyBlankTerminatesInput = 0x000200,
    kInitialBlankTerminatesInput = 0x000400,
    kAcceptOtherInputString = 0x000800,
    kGovernedByUCSDetect = 0x001000,
    kNoZDirectionOrtho = 0x002000,
    kImpliedFaceForUCSChange = 0x004000,
    kUseBasePointElevation = 0x008000,
    kDisableDirectDistanceInput = 0x010000,
  };

  enum DragStatus {
    kModeless = -17,
    kNoChange = -6,
    kCancel = -4,
    kOther = -3,
    kNull = -1,
    kNormal = 0,
    kKW1,
    kKW2,
    kKW3,
    kKW4,
    kKW5,
    kKW6,
    kKW7,
    kKW8,
    kKW9
  };

  enum CursorType {
    kNoSpecialCursor = -1,
    kCrosshair = 0,
    kRectCursor,
    kRubberBand,
    kNotRotated,
    kTargetBox,
    kRotatedCrosshair,
    kCrosshairNoRotate,
    kInvisible,
    kEntitySelect,
    kParallelogram,
    kEntitySelectNoPersp,
    kPkfirstOrGrips,
    kCrosshairDashed

  };

  GcEdJig();
  ~GcEdJig();

  DragStatus drag();
  DragStatus drag(const GcEdDragStyle& style);
  virtual DragStatus sampler();
  virtual Gsoft::Boolean update();
  GcDbObjectId append();
  const GCHAR* keywordList();
  void         setKeywordList(const GCHAR*);
  const GCHAR* dispPrompt();
  void         setDispPrompt(const GCHAR*, ...);

  DragStatus acquireString(GcString &s);
  DragStatus acquireString(GCHAR(&str)[2049]);
  DragStatus acquireAngle(double &ang);
  DragStatus acquireAngle(double &ang, const GcGePoint3d& basePnt);
  DragStatus acquireDist(double &dist);
  DragStatus acquireDist(double &dist, const GcGePoint3d& basePnt);
  DragStatus acquirePoint(GcGePoint3d&);
  DragStatus acquirePoint(GcGePoint3d&, const GcGePoint3d&basePnt);

  GcEdJig::CursorType specialCursorType();
  void                setSpecialCursorType(CursorType);
  GcEdJig::UserInputControls userInputControls();
  void                       setUserInputControls(GcEdJig::UserInputControls);

  virtual GcDbEntity* entity() const;
  virtual GcDbDimDataPtrArray * dimData(const double dimScale);
  virtual Gcad::ErrorStatus setDimValue(const GcDbDimData* dimData, const double dimValue);
private:
  GcEdImpJig*  mpImpJig;
  friend class GcEdJigInputHelper;
};

class  GcEdDragStyle
{
public:
  enum StyleType
  {
    kNone = 0,
    kHide,
    kTransparent25,
    kTransparent75,
    kDeletedEffect,
    kHighlight,
    kNotSet,
    kOpacity
  };

  GCCORE_PORT GcEdDragStyle();
  GCCORE_PORT GcEdDragStyle(StyleType styleTypeForOriginal, StyleType styleTypeForDragged);
  GCCORE_PORT GcEdDragStyle(const GcEdDragStyle& dragStyle);
  GCCORE_PORT ~GcEdDragStyle();

  GCCORE_PORT StyleType             styleTypeForOriginal() const;
  GCCORE_PORT StyleType             styleTypeForDragged() const;
  GCCORE_PORT Gcad::ErrorStatus     setStyleTypeForOriginal(StyleType styleType);
  GCCORE_PORT Gcad::ErrorStatus     setStyleTypeForDragged(StyleType styleType);

  GCCORE_PORT GcEdDragStyle&  operator = (const GcEdDragStyle& src);
  GCCORE_PORT bool operator == (const GcEdDragStyle& other) const;
  GCCORE_PORT bool operator != (const GcEdDragStyle& other) const;

private:
  GcEdImpDragStyle  *mpOriginalDragStyle;
  GcEdImpDragStyle  *mpDraggedDragStyle;

  friend class GcEdImpDragStyle;
};

#pragma pack (pop)
#endif 
#endif