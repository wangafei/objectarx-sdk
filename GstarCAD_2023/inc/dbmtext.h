/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBMTEXT_H
#define GD_DBMTEXT_H

#include "dbmain.h"

#pragma pack(push, 8)

struct GcDbMTextFragment
{
  GcGePoint3d  location;
  GcGeVector3d normal;
  GcGeVector3d direction;

  GcString msText;
  const GCHAR * text = nullptr;

  GcString msFont;
  const GCHAR * font = nullptr;

  GcString msBigFont;
  const GCHAR * bigfont = nullptr;

  GcGePoint2d  extents;
  double       capsHeight = 0.0;
  double       widthFactor = 0.0;
  double       obliqueAngle = 0.0;
  double       trackingFactor = 0.0;
  GcCmEntityColor color;

  unsigned stackTop : 1;
  unsigned stackBottom : 1;

  unsigned    underlined : 1;
  unsigned    overlined : 1;
  unsigned    strikethrough : 1;
  GcGePoint3d underPoints[2] = {};
  GcGePoint3d overPoints[2] = {};
  GcGePoint3d strikePoints[2] = {};

  GcString msFontName;
  const GCHAR *  fontname = nullptr;
  bool    bold = false;
  bool    italic = false;
};

typedef int(*GcDbMTextEnum)(GcDbMTextFragment *, void *);

class GcDbText;

class GCDB_PORT GcDbMText : public  GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDbMText);
  GcDbMText();
  ~GcDbMText();

  GcGePoint3d     location() const;
  Gcad::ErrorStatus   setLocation(const GcGePoint3d&);

  GcGeVector3d    normal() const;
  Gcad::ErrorStatus   setNormal(const GcGeVector3d&);

  Gsoft::Boolean      isPlanar() const override { return Gsoft::kTrue; }
  Gcad::ErrorStatus getPlane(GcGePlane& plane, GcDb::Planarity& type) const override;

  GcGeVector3d    direction() const;
  Gcad::ErrorStatus   setDirection(const GcGeVector3d&);

  double      rotation() const;
  Gcad::ErrorStatus   setRotation(double);

  double      width() const;
  Gcad::ErrorStatus   setWidth(double);

  double      ascent() const;
  double      descent() const;

  GcDbObjectId        textStyle() const;
  Gcad::ErrorStatus   setTextStyle(GcDbObjectId);

  double      textHeight() const;
  Gcad::ErrorStatus   setTextHeight(double);

  enum AttachmentPoint {
    kTopLeft = 1,
    kTopCenter = 2,
    kTopRight = 3,
    kMiddleLeft = 4,
    kMiddleCenter = 5,
    kMiddleRight = 6,
    kBottomLeft = 7,
    kBottomCenter = 8,
    kBottomRight = 9,
    kBaseLeft = 10,
    kBaseCenter = 11,
    kBaseRight = 12,
    kBaseAlign = 13,
    kBottomAlign = 14,
    kMiddleAlign = 15,
    kTopAlign = 16,
    kBaseFit = 17,
    kBottomFit = 18,
    kMiddleFit = 19,
    kTopFit = 20,
    kBaseMid = 21,
    kBottomMid = 22,
    kMiddleMid = 23,
    kTopMid = 24,
  };
  AttachmentPoint attachment() const;
  Gcad::ErrorStatus   setAttachment(AttachmentPoint);
  Gcad::ErrorStatus   setAttachmentMovingLocation(AttachmentPoint);

  enum FlowDirection {
    kLtoR = 1,
    kRtoL = 2,
    kTtoB = 3,
    kBtoT = 4,
    kByStyle = 5
  };
  FlowDirection       flowDirection() const;
  Gcad::ErrorStatus   setFlowDirection(FlowDirection);

  Gcad::ErrorStatus contents(GcString & sContents) const;
  GCHAR*            contents() const;
  int               setContents(const GCHAR *);
  Gcad::ErrorStatus contentsRTF(GcString &sContentsRTF) const;
  GCHAR* contentsRTF() const;
  int setContentsRTF(const GCHAR* RTFString);

  Gcad::ErrorStatus text(GcString & sText) const;
  GCHAR*      text() const;

  double      actualHeight(GcGiWorldDraw *ctxt = NULL) const;
  double      actualWidth() const;
  int         correctSpelling();
  void        getBoundingPoints(GcGePoint3dArray&) const;
  void        explodeFragments(GcDbMTextEnum, void *, GcGiWorldDraw *ctxt = NULL) const;

  static const GCHAR* const nonBreakSpace();
  static const GCHAR* const overlineOn();
  static const GCHAR* const overlineOff();
  static const GCHAR* const underlineOn();
  static const GCHAR* const underlineOff();
  static const GCHAR* const colorChange();
  static const GCHAR* const fontChange();
  static const GCHAR* const heightChange();
  static const GCHAR* const widthChange();
  static const GCHAR* const obliqueChange();
  static const GCHAR* const trackChange();
  static const GCHAR* const lineBreak();
  static const GCHAR* const paragraphBreak();
  static const GCHAR* const stackStart();
  static const GCHAR* const alignChange();
  static const GCHAR* const blockBegin();
  static const GCHAR* const blockEnd();
  static const GCHAR* const strikethroughOn();
  static const GCHAR* const strikethroughOff();

  Gcad::ErrorStatus   setLineSpacingStyle(GcDb::LineSpacingStyle eStyle);
  GcDb::LineSpacingStyle lineSpacingStyle() const;

  Gcad::ErrorStatus   setLineSpacingFactor(double dFactor);
  double              lineSpacingFactor() const;
  void                getEcs(GcGeMatrix3d& retVal) const override;

  bool      showBorders() const;
  Gcad::ErrorStatus setShowBorders(bool enable);

  bool backgroundFillOn() const;
  Gcad::ErrorStatus setBackgroundFill(bool enable);
  Gcad::ErrorStatus getBackgroundFillColor(GcCmColor& color) const;
  Gcad::ErrorStatus setBackgroundFillColor(const GcCmColor& color);
  Gcad::ErrorStatus getBackgroundScaleFactor(double& scale) const;
  Gcad::ErrorStatus setBackgroundScaleFactor(const double scale);
  Gcad::ErrorStatus getBackgroundTransparency(GcCmTransparency& transp) const;
  Gcad::ErrorStatus setBackgroundTransparency(const GcCmTransparency& transp);

  bool useBackgroundColorOn() const;
  Gcad::ErrorStatus   setUseBackgroundColor(bool enable);
  Gcad::ErrorStatus   setField(const GCHAR* pszPropName, GcDbField* pField, GcDbObjectId& fieldId) override;
  Gcad::ErrorStatus   removeField(GcDbObjectId fieldId) override;
  Gcad::ErrorStatus   removeField(const GCHAR* pszPropName, GcDbObjectId& returnId) override;
  Gcad::ErrorStatus   removeField(const GCHAR* pszPropName) override;
  Gcad::ErrorStatus   convertFieldToText();

  enum ColumnType {
    kNoColumns,
    kStaticColumns,
    kDynamicColumns,
  };

  Gcad::ErrorStatus setDynamicColumns(double width, double gutter, bool auto_height);
  Gcad::ErrorStatus setStaticColumns(double width, double gutter, int count);
  Gcad::ErrorStatus getColumnType(ColumnType&) const;
  Gcad::ErrorStatus setColumnType(ColumnType);
  Gcad::ErrorStatus getColumnAutoHeight(bool&) const;
  Gcad::ErrorStatus setColumnAutoHeight(bool);
  Gcad::ErrorStatus getColumnCount(int&) const;
  Gcad::ErrorStatus setColumnCount(int);
  Gcad::ErrorStatus getColumnWidth(double&) const;
  Gcad::ErrorStatus setColumnWidth(double);
  Gcad::ErrorStatus getColumnGutterWidth(double&) const;
  Gcad::ErrorStatus setColumnGutterWidth(double);
  Gcad::ErrorStatus getColumnFlowReversed(bool&) const;
  Gcad::ErrorStatus setColumnFlowReversed(bool);
  Gcad::ErrorStatus getColumnHeight(int, double&) const;
  Gcad::ErrorStatus setColumnHeight(int, double);

  Gcad::ErrorStatus   setUseWordBreak(bool bEnable);
  bool useWordBreak() const;

  double      height() const;
  Gcad::ErrorStatus   setHeight(double);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline GCHAR * GcDbMText::contents() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbMText::contents);
}

inline GCHAR * GcDbMText::contentsRTF() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbMText::contentsRTF);
}

inline GCHAR * GcDbMText::text() const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbMText::text);
}

#pragma pack(pop)

#endif