#ifndef _DBTEXTEDITORSERVICES_H_
#define _DBTEXTEDITORSERVICES_H_

class GcDbTextEditorCharAttributes
{
public:
  enum FlowAlign
  {
    kFlowBase = 0,
    kFlowCenter,
    kFlowTop
  };

  virtual GcDbTextEditorCharAttributes* cloneAttribute() = 0;

  virtual void setFont(const OdChar* font, bool bShx) = 0;
  virtual const OdString& font() const = 0;

  virtual void setCharset(int charSet) = 0;
  virtual int charset() const = 0;

  virtual void setPitchAndFamily(int pitchAndFamily) = 0;
  virtual int pitchAndFamily() const = 0;

  virtual bool isShx() const = 0;

  virtual void setBigFont(const OdChar* font) = 0;
  virtual const OdString& bigFont() const = 0;

  virtual bool isBigFont() const = 0;

  virtual void setTextHeight(double textHeight) = 0;
  virtual double textHeight() const = 0;

  virtual void setBold(bool b) = 0;
  virtual bool bold() const = 0;

  virtual void setItalic(bool i) = 0;
  virtual bool italic() const = 0;

  virtual void setStrikeOut(bool s) = 0;
  virtual bool strikeOut() const = 0;
  
  virtual void setUnderlined(bool ul) = 0;
  virtual bool underlined() const = 0;

  virtual void setOverlined(bool ol) = 0;
  virtual bool overlined() const = 0;

  virtual void setColor(const OdCmEntityColor& cr) = 0;
  virtual const OdCmEntityColor& color() const = 0;

  virtual void setOblique(double dOblique) = 0;
  virtual double oblique() const = 0;

  virtual void setTrackingFactor(double dFactor) = 0;
  virtual double trackingFactor() const = 0;

  virtual void setWidthScale(double dScale) = 0;
  virtual double widthScale() const = 0;

  virtual void setAlignment(FlowAlign align) = 0;
  virtual FlowAlign alignment() const = 0;
};

class GcDbTextEditorStack
{
public:
  virtual void setTop(const OdString& top) = 0;
  virtual const OdChar* top() const = 0;

  virtual void setBottom(const OdString& bottom) = 0;
  virtual const OdChar* bottom() const = 0;

  virtual void setScale(double scale) = 0;
  virtual double scale() const = 0;

  virtual void setDecimalChar(OdChar decimalChar) = 0;
  virtual OdChar decimalChar() const = 0;
};

class GcDbTextEditorFragment
{
public:
  enum FragmentType
  {
    kNormal,                                    // 普通字符
    kStack,                                     // 堆叠
    kField,                                     // 字段
    kMainField,                                 // 字段拆分后的主字段
    kSubField,                                  // 字段拆分后的子字段
    kDimension,                                 // 标注
  };

  virtual void setFragment(const OdString& content) = 0;
  virtual GcDbTextEditorStack* setStack() = 0;
  virtual void setFieldType(FragmentType type) = 0;
  virtual void setAttribute(GcDbTextEditorCharAttributes* pAttribute) = 0;
  virtual void setWordBegin(bool bBegin) = 0;
  virtual void setExtend(double left, double width, double height) = 0;
  virtual double left() const = 0;
  virtual double width() const = 0;
  virtual double height() const = 0;
};

class GcDbTextEditorLine
{
public:
  virtual GcDbTextEditorFragment* appendFragment() = 0;

  virtual void setExtend(double left, double top, double width, double height) = 0;
  virtual void setCursor(double top, double height) = 0;
  //base是基线的位置，maxY是base到行的顶点的距离
  virtual void setBase(double base, double maxY) = 0;
  virtual double top() const = 0;
  virtual double height() const = 0;
};

class GcDbTextEditorParagraph
{
public:
  enum AlignmentType
  {
    kAlignmentDefault = 0,
    kAlignmentLeft,
    kAlignmentCenter,
    kAlignmentRight,
    kAlignmentJustify,
    kAlignmentDistribute
  };

  enum LineSpacingStyle
  {
    kLineSpacingDefault,
    kLineSpacingExactly,
    kLineSpacingAtLeast,
    kLineSpacingMultiple,
  };

  enum TabType
  {
    kLeftTab,
    kCenterTab,
    kRightTab,
    kFullstopTab,
    kCommaTab,
    kSpaceTab,
  };

  virtual void setAlignment(AlignmentType alignmentType) = 0;
  virtual void setFirstIndent(double firstIndent) = 0;
  virtual void setLeftIndent(double leftIndent) = 0;
  virtual void setRightIndent(double rightIndent) = 0;
  virtual void setLineSpacingStyle(LineSpacingStyle lineSpacingStyle) = 0;
  virtual void setLineSpacingFactor(double lineSpacingFactor) = 0;
  virtual void setSpaceBefore(double spaceBefore) = 0;
  virtual void setSpaceAfter(double spaceAfter) = 0;
  virtual bool addTab(double offdist, TabType type) = 0;
  virtual GcDbTextEditorLine* appendLine() = 0;
};

class GcDbTextEditorColumn
{
public:
  virtual void addLine(GcDbTextEditorLine* pLine) = 0;

  virtual const OdGePoint3d& actualTopLeft() const = 0;
  virtual double actualWidth() const = 0;
  virtual double actualHeight() const = 0;

  virtual const OdGePoint3d& topLeft() const = 0;
  virtual double width() const = 0;
  virtual double height() const = 0;
};

class GcDbTextEditorColumns
{
public:
  virtual int count() const = 0;
  virtual GcDbTextEditorColumn* getAt(int i) const = 0;
};

class GcDbTextEditorLocation
{
public:
  virtual void release() = 0;
  virtual GcDbTextEditorLine* curLine() const = 0;
  virtual GcDbTextEditorFragment* curFragment() const = 0;
  virtual GcDbTextEditorLocation* next() const = 0;
  virtual bool equal(GcDbTextEditorLocation* pOther) const = 0;
};

class GcDbTextEditorServices
{
public:
  // 排版开始
  virtual void formatStarted() = 0;
  // 排版结束
  virtual void formatFinished() = 0;
  // 开始画文字
  virtual void onBeforeDrawFragments(OdGiGeometry& geom, OdGiCommonDraw* pWd) = 0;

  // 获得文字块属性
  virtual GcDbTextEditorCharAttributes* baseAttribute() = 0;

  // 将pAttribute加入到service中
  // 如果已经存在一个相同的pAttribute，则删除pAttribute，并返回已存在的pAttribute
  virtual GcDbTextEditorCharAttributes* insertAttribute(GcDbTextEditorCharAttributes* pAttribute) = 0;

  virtual GcDbTextEditorParagraph* insertParagraph() = 0;

  virtual GcDbTextEditorColumn* insertColumn() = 0;

  virtual bool canDraw() const = 0;
  virtual bool isEditMText() const = 0;
};

class GcDbTextEditorSelectionBase
{
public:
  virtual bool insertString(const OdString& str) = 0;
};

class GcDbTextEditorCursor : public GcDbTextEditorSelectionBase
{
public:
  virtual void updateAttribute() = 0;
};

class GcDbTextEditor
{
public:
  enum TextFindFlags
  {
    kFindMatchCase = 1 << 0,
    kFindWholeWord = 1 << 1,
    kFindHalfFullForm = 1 << 2,
    kFindIgnoreAccent = 1 << 3,
    kFindUseWildcards = 1 << 4,
  };
  virtual OdDbMText* mtext() const = 0;
  virtual GcDbTextEditorLocation* startOfText() = 0;
  virtual GcDbTextEditorLocation* endOfText() = 0;
  virtual GcDbTextEditorColumns* textEditorColumns() = 0;
  virtual bool findText(const OdChar* text, int flags,
    GcDbTextEditorLocation*& pStart, GcDbTextEditorLocation*& pEnd) = 0;
  virtual GcDbTextEditorCursor* cursor() = 0;
  virtual bool clearSelection() = 0;
  virtual bool makeSelection(const GcDbTextEditorLocation* pStart,
    const GcDbTextEditorLocation* pEnd) = 0;
  virtual void redraw() = 0;
  virtual void close() = 0;
};

TOOLKIT_EXPORT void setTextEditorServices(OdDbMText* pMText, GcDbTextEditorServices* pServices);

#endif //_DBTEXTEDITORSERVICES_H_
