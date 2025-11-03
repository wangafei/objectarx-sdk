/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcadstrc.h"
#include "dbmtext.h"
#include "GcString.h"
#include "PAL/api/charset.h"

class TextEditor;
class TextEditorLocation;

class GcDbTextEditor;

class GcDbTextEditorColumn;
class GcDbTextEditorParagraph;
class GcDbTextEditorParagraphIterator;

class GcDbImpTextEditorParagraph;
class GcDbImpTextEditorParagraphIterator;
class GcDbImpTextEditorColumn;

class GcDbTextEditorParagraphTab;
class GcDbImpTextEditorParagraphTab;

class GcDbTextEditorStack;
class GcDbImpTextEditorStack;

class GcDbImpTextEditorSelectionBase;
class GcDbImpTextEditorCursor;
class GcDbImpTextEditorSelection;

class GcDbTextEditorLocation
{
public:
  GCDB_PORT void release();

private:
  ~GcDbTextEditorLocation();
  GcDbTextEditorLocation();
  bool operator==(const GcDbTextEditorLocation& other);

  friend class GcDbTextEditor;
  friend class GcDbTextEditorServices;
  friend class GcDbTextEditorCursor;

  TextEditorLocation* m_pImp;
};

class GcDbTextEditorSelectable
{
public:
  virtual ~GcDbTextEditorSelectable() { };

  virtual GcDbTextEditorLocation* startOfText() = 0;
  virtual GcDbTextEditorLocation* endOfText() = 0;
};

class GcDbTextEditorSelectionBase
{
public:
  enum FlowAlign
  {
    kFlowBase,
    kFlowCenter,
    kFlowTop
  };

  enum InsertTextType {
    kUnicodeMTextFormat,
    kMTextFormat,
    kRichTextFormat,
    kUnicodeDTextFormat,
    kDTextFormat,
    kUnicodeTextFormat,
    kMultibyteTextFormat
  };

  GCCORE_PORT Gcad::ErrorStatus setLanguage(Charset charset);
  GCCORE_PORT Charset               language() const;

  GCCORE_PORT Gcad::ErrorStatus setFont(const GcString& fontname, bool bTrueType);
  GCCORE_PORT GcString          font() const;

  GCCORE_PORT bool              isTrueType() const;

  GCCORE_PORT Gcad::ErrorStatus setHeight(double height);
  GCCORE_PORT double            height() const;

  GCCORE_PORT Gcad::ErrorStatus setColor(const GcCmColor& color);
  GCCORE_PORT GcCmColor         color() const;

  GCCORE_PORT Gcad::ErrorStatus toggleBold();
  GCCORE_PORT bool              bold() const;

  GCCORE_PORT Gcad::ErrorStatus toggleItalic();
  GCCORE_PORT bool              italic() const;

  GCCORE_PORT Gcad::ErrorStatus toggleUnderline();
  GCCORE_PORT bool              underline() const;

  GCCORE_PORT Gcad::ErrorStatus toggleOverline();
  GCCORE_PORT bool              overline() const;

  GCCORE_PORT Gcad::ErrorStatus toggleStrikethrough();
  GCCORE_PORT bool              strikethrough() const;

  GCCORE_PORT Gcad::ErrorStatus setObliqueAngle(double angle);
  GCCORE_PORT double            obliqueAngle() const;

  GCCORE_PORT Gcad::ErrorStatus setTrackingFactor(double factor);
  GCCORE_PORT double            trackingFactor() const;

  GCCORE_PORT Gcad::ErrorStatus setWidthScale(double scale);
  GCCORE_PORT double            widthScale() const;

  GCCORE_PORT Gcad::ErrorStatus setFlowAlign(FlowAlign flowAlign);
  GCCORE_PORT FlowAlign         flowAlign() const;

  GCCORE_PORT static double     minObliqueAngle();
  GCCORE_PORT static double     maxObliqueAngle();
  GCCORE_PORT static double     minTrackingFactor();
  GCCORE_PORT static double     maxTrackingFactor();
  GCCORE_PORT static double     minWidthScale();
  GCCORE_PORT static double     maxWidthScale();

  GCCORE_PORT Gcad::ErrorStatus insertSymbol(GCHAR wch, Charset charset);
  GCCORE_PORT Gcad::ErrorStatus insertString(const GcString& str);
  GCCORE_PORT Gcad::ErrorStatus insertImportedText(InsertTextType insertType, void * pData);
  GCCORE_PORT Gcad::ErrorStatus inputSpecialChar(Gsoft::UInt32 c);
  GCCORE_PORT Gcad::ErrorStatus insertColumnBreak();

protected:
  GcDbTextEditorSelectionBase();
  virtual ~GcDbTextEditorSelectionBase();
  GcDbTextEditorSelectionBase(const GcDbTextEditorSelectionBase&);
  GcDbTextEditorSelectionBase& operator=(const GcDbTextEditorSelectionBase&);

  friend class GcDbTextEditor;
  GcDbImpTextEditorSelectionBase* m_pImp;
};

class GcDbTextEditorSelection : public GcDbTextEditorSelectionBase
{
public:
  GCCORE_PORT bool languageSupported(Charset charset) const;
  GCCORE_PORT bool fontSupported(const GcString& fontname, bool bTrueType) const;

  GCCORE_PORT bool canStack() const;
  GCCORE_PORT Gcad::ErrorStatus stack();

  GCCORE_PORT bool canUnStack() const;
  GCCORE_PORT Gcad::ErrorStatus    unStack();

  GCCORE_PORT bool     singleStackSelected() const;

  GCCORE_PORT Gcad::ErrorStatus    getStack(GcDbTextEditorStack& stack) const;
  GCCORE_PORT Gcad::ErrorStatus    setStack(const GcDbTextEditorStack& stack);

  GCCORE_PORT void paragraph(GcArray<GcDbTextEditorParagraph*>& paragraphs);

  GCCORE_PORT Gcad::ErrorStatus combineParagraphs();
  GCCORE_PORT Gcad::ErrorStatus removeCharacterFormatting();
  GCCORE_PORT Gcad::ErrorStatus removeParagraphFormatting();
  GCCORE_PORT Gcad::ErrorStatus removeAllFormatting();

  GCCORE_PORT bool canChangeCase() const;
  GCCORE_PORT bool changeToUppercase();
  GCCORE_PORT bool changeToLowercase();

  GCCORE_PORT Gcad::ErrorStatus getSelectionText(GcString& txt) const;
  GCCORE_PORT bool     singleFieldSelected() const;
  GCCORE_PORT GcDbField* field() const;
  GCCORE_PORT Gcad::ErrorStatus  updateField();
  GCCORE_PORT Gcad::ErrorStatus  convertToPlainText();
protected:
  GCCORE_PORT GcDbTextEditorSelection(const TextEditor* pImp);
  GCCORE_PORT ~GcDbTextEditorSelection();
  GcDbTextEditorSelection(const GcDbTextEditorSelection&);
  GcDbTextEditorSelection& operator=(const GcDbTextEditorSelection&);

  GcDbImpTextEditorSelection* m_pImpSelection;
  friend class TextEditor;
};

class GcDbTextEditorCursor : public GcDbTextEditorSelectionBase
{
public:
  GCCORE_PORT GcDbTextEditorParagraph* paragraph();
  GCCORE_PORT GcDbTextEditorColumn*    column();
  GCCORE_PORT Gcad::ErrorStatus        setLocation(const GcDbTextEditorLocation& location);
  GCCORE_PORT GcDbTextEditorLocation* location() const;

protected:
  GCCORE_PORT GcDbTextEditorCursor(const TextEditor* pImp);
  GCCORE_PORT ~GcDbTextEditorCursor();
  GcDbTextEditorCursor(const GcDbTextEditorCursor&);
  GcDbTextEditorCursor& operator=(const GcDbTextEditorCursor&);

  GcDbImpTextEditorCursor* m_pImpCursor;
  friend class TextEditor;
};

class GcDbTextEditorParagraphTab
{
public:
  enum ParagraphTabType
  {
    kLeftTab,
    kCenterTab,
    kRightTab,
    kDecimalTab,
  };

  GCCORE_PORT  GcDbTextEditorParagraphTab();
  GCCORE_PORT ~GcDbTextEditorParagraphTab();
  GCCORE_PORT GcDbTextEditorParagraphTab(const GcDbTextEditorParagraphTab&);
  GCCORE_PORT GcDbTextEditorParagraphTab& operator=(const GcDbTextEditorParagraphTab&);
  GCCORE_PORT double            offset() const;
  GCCORE_PORT Gcad::ErrorStatus setOffset(double offdist);

  GCCORE_PORT ParagraphTabType  type() const;
  GCCORE_PORT Gcad::ErrorStatus setType(ParagraphTabType type);

  GCCORE_PORT wchar_t             decimalChar() const;
  GCCORE_PORT Gcad::ErrorStatus setDecimalChar(wchar_t decchar);

private:
  GcDbImpTextEditorParagraphTab* m_pImp;
};

class GcDbTextEditorParagraph : public GcDbTextEditorSelectable
{
public:
  enum AlignmentType
  {
    kAlignmentDefault,
    kAlignmentLeft,
    kAlignmentCenter,
    kAlignmentRight,
    kAlignmentJustify,
    kAlignmentDistribute
  };

  enum LineSpacingStyle {
    kLineSpacingDefault,
    kLineSpacingExactly,
    kLineSpacingAtLeast,
    kLineSpacingMultiple,
  };

  enum NumberingType {
    kOff = 0,
    kBullet,
    kNumber,
    kLetterLower,
    kLetterUpper,
    kNumberWide,
    kLetterLowerWide,
    kLetterUpperWide,
  };

  GCCORE_PORT Gcad::ErrorStatus setAlignment(AlignmentType AlignmentType);
  GCCORE_PORT AlignmentType alignment() const;

  GCCORE_PORT Gcad::ErrorStatus setFirstIndent(double firstIndent);
  GCCORE_PORT double firstIndent() const;

  GCCORE_PORT Gcad::ErrorStatus setLeftIndent(double leftIndent);
  GCCORE_PORT double leftIndent() const;

  GCCORE_PORT Gcad::ErrorStatus setRightIndent(double rightIndent);
  GCCORE_PORT double rightIndent() const;

  GCCORE_PORT Gcad::ErrorStatus setLineSpacingStyle(LineSpacingStyle lineSpacingStyle);
  GCCORE_PORT LineSpacingStyle  lineSpacingStyle() const;

  GCCORE_PORT Gcad::ErrorStatus setLineSpacingFactor(double lineSpacingFactor);
  GCCORE_PORT double            lineSpacingFactor() const;

  GCCORE_PORT Gcad::ErrorStatus setSpaceBefore(double spaceBefore);
  GCCORE_PORT double            spaceBefore() const;

  GCCORE_PORT Gcad::ErrorStatus setSpaceAfter(double spaceAfter);
  GCCORE_PORT double            spaceAfter() const;

  GCCORE_PORT Gcad::ErrorStatus setNumberingType(NumberingType type);
  GCCORE_PORT NumberingType     numberingType() const;

  GCCORE_PORT Gcad::ErrorStatus restartNumbering();
  GCCORE_PORT Gcad::ErrorStatus continueNumbering();

  GCCORE_PORT int               tabsCount() const;
  GCCORE_PORT Gcad::ErrorStatus addTab(const GcDbTextEditorParagraphTab& tab);
  GCCORE_PORT Gcad::ErrorStatus removeTab(const GcDbTextEditorParagraphTab& tab);
  GCCORE_PORT Gcad::ErrorStatus getTab(int i, GcDbTextEditorParagraphTab& tab);

  GCCORE_PORT GcDbTextEditorLocation* startOfText() override;
  GCCORE_PORT GcDbTextEditorLocation* endOfText() override;

  GCCORE_PORT double     minLineSpacingFactor() const;
  GCCORE_PORT double     maxLineSpacingFactor() const;

  GCCORE_PORT double     minSpaceValue() const;
  GCCORE_PORT double     maxSpaceValue() const;
  GCCORE_PORT void       release();

private:
  friend class GcDbTextEditorParagraphIterator;
  friend class GcDbTextEditorServices;
  GcDbImpTextEditorParagraph* m_pImp;

  GcDbTextEditorParagraph() {}
  ~GcDbTextEditorParagraph();
  GcDbTextEditorParagraph(const GcDbTextEditorParagraph&);
  GcDbTextEditorParagraph& operator=(const GcDbTextEditorParagraph&);
};

class GcDbTextEditorParagraphIterator
{
public:
  GCCORE_PORT GcDbTextEditorParagraphIterator(const GcDbTextEditor& textEditor);
  GCCORE_PORT ~GcDbTextEditorParagraphIterator();

  GCCORE_PORT bool done();
  GCCORE_PORT GcDbTextEditorParagraph* current();
  GCCORE_PORT void next();
private:
  GcDbImpTextEditorParagraphIterator* m_pImp;
};

class GcDbTextEditorColumn : public GcDbTextEditorSelectable
{
public:
  GCCORE_PORT double height();
  GCCORE_PORT Gcad::ErrorStatus setHeight(double height);
  GCCORE_PORT void              release();

  GCCORE_PORT GcDbTextEditorLocation* startOfText() override;
  GCCORE_PORT GcDbTextEditorLocation* endOfText() override;
private:
  GcDbImpTextEditorColumn* m_pImp;
  friend class GcDbTextEditorServices;

  GcDbTextEditorColumn();
  ~GcDbTextEditorColumn();
  GcDbTextEditorColumn(const GcDbTextEditorColumn&);
  GcDbTextEditorColumn& operator=(const GcDbTextEditorColumn&);
};

class GcDbTextEditorColumns
{
public:
  GCCORE_PORT static int maxCount();
  GCCORE_PORT int count() const;
  GCCORE_PORT Gcad::ErrorStatus setCount(int count);
  GCCORE_PORT GcDbTextEditorColumn* getAt(int i);

  GCCORE_PORT Gcad::ErrorStatus setColumnType(GcDbMText::ColumnType type);
  GCCORE_PORT GcDbMText::ColumnType columnType() const;

  GCCORE_PORT Gcad::ErrorStatus setAutoHeight(bool bAutoHeight);
  GCCORE_PORT bool autoHeight() const;

  GCCORE_PORT Gcad::ErrorStatus setWidth(double value);
  GCCORE_PORT double width() const;

  GCCORE_PORT Gcad::ErrorStatus setGutter(double value);
  GCCORE_PORT double gutter() const;

  GCCORE_PORT Gcad::ErrorStatus setTotalWidth(double value);
  GCCORE_PORT double totalWidth() const;

  GCCORE_PORT bool   isFlowReversed() const;
  GCCORE_PORT Gcad::ErrorStatus setIsFlowReversed(bool isFlowReversed);

private:
  friend class TextEditor;
  GcDbTextEditorColumns();
  ~GcDbTextEditorColumns();
  GcDbTextEditorColumns(const GcDbTextEditorColumns&);
  GcDbTextEditorColumns& operator=(const GcDbTextEditorColumns&);

  TextEditor* m_pImp;
};

class GcDbTextEditorWipeout
{
public:
  GCCORE_PORT static double     minBackgroundScaleFactor();
  GCCORE_PORT static double     maxBackgroundScaleFactor();

  GCCORE_PORT bool              enableBackgroundFill() const;
  GCCORE_PORT Gcad::ErrorStatus setEnableBackgroundFill(bool bEnable);

  GCCORE_PORT GcCmColor         getBackgroundFillColor() const;
  GCCORE_PORT Gcad::ErrorStatus setBackgroundFillColor(GcCmColor color);

  GCCORE_PORT bool              useBackgroundColor() const;
  GCCORE_PORT Gcad::ErrorStatus setUseBackgroundColor(bool bUse);

  GCCORE_PORT double            getBackgroundScaleFactor()const;
  GCCORE_PORT Gcad::ErrorStatus setBackgroundScaleFactor(double factor);

private:
  GcDbTextEditorWipeout();
  ~GcDbTextEditorWipeout();
  GcDbTextEditorWipeout(const GcDbTextEditorWipeout&);
  GcDbTextEditorWipeout& operator=(const GcDbTextEditorWipeout&);

  TextEditor* m_pEditor;
  friend class TextEditor;
};

class GcDbTextEditorStack
{
public:
  enum StackType
  {
    kHorizontalStack,
    kDiagonalStack,
    kToleranceStack,
    kDecimalStack,
  };

  GCCORE_PORT GcDbTextEditorStack();
  GCCORE_PORT ~GcDbTextEditorStack();
  GCCORE_PORT GcDbTextEditorStack(const GcDbTextEditorStack&);
  GCCORE_PORT GcDbTextEditorStack& operator=(const GcDbTextEditorStack&);

  GCCORE_PORT StackType        type() const;
  GCCORE_PORT Gcad::ErrorStatus setType(StackType type);

  GCCORE_PORT GcDbTextEditorSelectionBase::FlowAlign alignType() const;
  GCCORE_PORT Gcad::ErrorStatus setAlignType(GcDbTextEditorSelectionBase::FlowAlign align);

  GCCORE_PORT GcString top() const;
  GCCORE_PORT Gcad::ErrorStatus setTop(const GcString& top);

  GCCORE_PORT GcString          bottom() const;
  GCCORE_PORT Gcad::ErrorStatus setBottom(const GcString& bottom);

  GCCORE_PORT double            scale() const;
  GCCORE_PORT Gcad::ErrorStatus setScale(double scale);

  GCCORE_PORT wchar_t             decimalChar() const;
  GCCORE_PORT Gcad::ErrorStatus   setDecimalChar(wchar_t decimalChar);

  GCCORE_PORT static double       minStackScale();
  GCCORE_PORT static double       maxStackScale();

private:
  GcDbImpTextEditorStack*   m_pImpStack;
};

class GcDbTextEditor : public GcDbTextEditorSelectable
{
public:
  enum TextFindFlags {
    kFindMatchCase = 1 << 0,
    kFindWholeWord = 1 << 1,
    kFindHalfFullForm = 1 << 2,
    kFindIgnoreAccent = 1 << 3,
    kFindUseWildcards = 1 << 4,
  };

  enum ExitStatus
  {
    kExitQuit = 0,
    kExitSave,
  };
  GCCORE_PORT static GcDbTextEditor* createDbTextEditor(GcDbMText* pMText);

  GCCORE_PORT virtual void  close(ExitStatus stat);
  GCCORE_PORT void   redraw();
  GCCORE_PORT GcDbTextEditorColumns* columns();
  GCCORE_PORT GcDbTextEditorWipeout* wipeout();

  GCCORE_PORT GcDbTextEditorParagraphIterator* newParagraphsIterator();
  GCCORE_PORT virtual GcDbTextEditorSelection* selection();
  GCCORE_PORT virtual GcDbTextEditorCursor*    cursor();
  GCCORE_PORT Gcad::ErrorStatus clearSelection();
  GCCORE_PORT Gcad::ErrorStatus makeSelection(const GcDbTextEditorLocation* pStart,
    const GcDbTextEditorLocation* pEnd);
  GCCORE_PORT Gcad::ErrorStatus findText(const GCHAR* text, int flags,
    GcDbTextEditorLocation*& pStart,
    GcDbTextEditorLocation*& pEnd);

  GCCORE_PORT Gcad::ErrorStatus setAttachment(GcDbMText::AttachmentPoint attachment);
  GCCORE_PORT GcDbMText::AttachmentPoint attachment() const;

  GCCORE_PORT Gcad::ErrorStatus setStyle(int index);
  GCCORE_PORT Gcad::ErrorStatus setStyle(GcDbObjectId styleId);
  GCCORE_PORT int               getIndexFromStyleName(const GcString& styleName);
  GCCORE_PORT int               getStyleCount() const;
  GCCORE_PORT GcString          getStyleName(int index) const;
  GCCORE_PORT GcDbObjectId      style(int index) const;
  GCCORE_PORT int               currentStyleIndex() const;
  GCCORE_PORT bool              isAnnotativeStyle(int index) const;
  GCCORE_PORT bool              isVerticalSHX() const;
  GCCORE_PORT bool              isVerticalTTF() const;

  GCCORE_PORT Gcad::ErrorStatus setDefinedWidth(double width);
  GCCORE_PORT double            definedWidth() const;

  GCCORE_PORT Gcad::ErrorStatus setDefinedHeight(double height);
  GCCORE_PORT double            definedHeight() const;

  GCCORE_PORT double            textHeight() const;
  GCCORE_PORT Gcad::ErrorStatus setTextHeight(double textHeight);

  GCCORE_PORT double            actualWidth() const;
  GCCORE_PORT double            actualHeight() const;
  GCCORE_PORT Gcad::ErrorStatus selectAll();

  GCCORE_PORT Gcad::ErrorStatus setAutoCAPS(bool autoCAPS);
  GCCORE_PORT bool              autoCAPS();

  GCCORE_PORT Gcad::ErrorStatus setEnableNumbering(bool bEnable);
  GCCORE_PORT bool              numberingEnabled() const;

  GCCORE_PORT Gcad::ErrorStatus setAutolistEnabled(bool enabled);
  GCCORE_PORT bool              autolistEnabled() const;

  GCCORE_PORT Gcad::ErrorStatus setTabOnlyDelimiter(bool tabOnlyDelimiter);
  GCCORE_PORT bool              tabOnlyDelimiter() const;

  GCCORE_PORT int               getFontCount() const;
  GCCORE_PORT GcString          getFontName(int index) const;
  GCCORE_PORT bool              isTrueTypeFont(int index) const;
  GCCORE_PORT int               stackCount() const;

  GCCORE_PORT double             defaultStackScale() const;
  GCCORE_PORT Gcad::ErrorStatus  setDefaultStackScale(double scale);

  GCCORE_PORT GcDbTextEditorSelectionBase::FlowAlign defaultStackAlignment() const;
  GCCORE_PORT Gcad::ErrorStatus    setDefaultStackAlignment(GcDbTextEditorSelectionBase::FlowAlign alignment);

  GCCORE_PORT GcDbTextEditorLocation* startOfText() override;
  GCCORE_PORT GcDbTextEditorLocation* endOfText() override;

protected:
  GCCORE_PORT GcDbTextEditor() :m_pImp(NULL) {};
  GCCORE_PORT ~GcDbTextEditor();

  friend class GcDbTextEditorLocation;
  friend class GcDbTextEditorParagraphIterator;
  TextEditor* m_pImp;

private:
  GcDbTextEditor(const GcDbTextEditor& editor);
  GcDbTextEditor& operator=(const GcDbTextEditor& editor);
};