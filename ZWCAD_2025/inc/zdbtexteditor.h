
#pragma once

#include "zacadstrc.h"
#include "zdbmtext.h"
#include "zAcString.h"
#include "PAL/api/zcharset.h"

class TextEditor;
class TextEditorLocation;

class ZcDbTextEditor;

class ZcDbTextEditorColumn;
class ZcDbTextEditorParagraph;
class ZcDbTextEditorParagraphIterator;

class ZcDbImpTextEditorParagraph;
class ZcDbImpTextEditorParagraphIterator;
class ZcDbImpTextEditorColumn;

class ZcDbTextEditorParagraphTab;
class ZcDbImpTextEditorParagraphTab;

class ZcDbTextEditorStack;
class ZcDbImpTextEditorStack;

class ZcDbImpTextEditorSelectionBase;
class ZcDbImpTextEditorCursor;
class ZcDbImpTextEditorSelection;

class ZCDBCORE2D_PORT ZcDbTextEditorLocation
{
public:

    void release();

private:
    ~ZcDbTextEditorLocation();
    ZcDbTextEditorLocation();
    bool operator==(const ZcDbTextEditorLocation& other);

    friend class ZcDbTextEditor;
    friend class ZcDbTextEditorServices;
    friend class ZcDbTextEditorCursor;

    TextEditorLocation* m_pImp;
};

class ZcDbTextEditorSelectable
{
public:
    virtual ~ZcDbTextEditorSelectable() { };

    virtual ZcDbTextEditorLocation* startOfText() = 0;

    virtual ZcDbTextEditorLocation* endOfText() = 0;
};

class ZCDBCORE2D_PORT ZcDbTextEditorSelectionBase
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

    Zcad::ErrorStatus setLanguage(Charset charset);

    Charset               language() const;

    Zcad::ErrorStatus setFont(const ZcString& fontname, bool bTrueType);

    ZcString          font() const;

    bool              isTrueType() const;

    Zcad::ErrorStatus setHeight(double height);

    double            height() const;

    Zcad::ErrorStatus setColor(const ZcCmColor& color);

    ZcCmColor         color() const;

    Zcad::ErrorStatus toggleBold();

    bool              bold() const;

    Zcad::ErrorStatus toggleItalic();

    bool              italic() const;

    Zcad::ErrorStatus toggleUnderline();

    bool              underline() const;

    Zcad::ErrorStatus toggleOverline();

    bool              overline() const;

    Zcad::ErrorStatus toggleStrikethrough();

    bool              strikethrough() const;

    Zcad::ErrorStatus setObliqueAngle(double angle);

    double            obliqueAngle() const;

    Zcad::ErrorStatus setTrackingFactor(double factor);

    double            trackingFactor() const;

    Zcad::ErrorStatus setWidthScale(double scale);

    double            widthScale() const;

    Zcad::ErrorStatus setFlowAlign(FlowAlign flowAlign);

    FlowAlign         flowAlign() const;

    static double     minObliqueAngle();

    static double     maxObliqueAngle();

    static double     minTrackingFactor();

    static double     maxTrackingFactor();

    static double     minWidthScale();

    static double     maxWidthScale();

    Zcad::ErrorStatus insertSymbol(ZTCHAR wch, Charset charset);

    Zcad::ErrorStatus insertString(const ZcString& str);

    Zcad::ErrorStatus insertImportedText(InsertTextType insertType, void * pData);

    Zcad::ErrorStatus inputSpecialChar(ZSoft::UInt32 c);

    Zcad::ErrorStatus insertColumnBreak();

protected:
    ZcDbTextEditorSelectionBase();
    virtual ~ZcDbTextEditorSelectionBase();
    ZcDbTextEditorSelectionBase(const ZcDbTextEditorSelectionBase&);
     ZcDbTextEditorSelectionBase& operator=(const ZcDbTextEditorSelectionBase&);

    friend class ZcDbTextEditor;
    ZcDbImpTextEditorSelectionBase* m_pImp;
};

class ZCDBCORE2D_PORT ZcDbTextEditorSelection : public ZcDbTextEditorSelectionBase
{
public:

    bool languageSupported(Charset charset) const;

    bool fontSupported(const ZcString& fontname, bool bTrueType) const;

    bool canStack() const;

    Zcad::ErrorStatus stack();

    bool canUnStack() const;

    Zcad::ErrorStatus    unStack();

    bool     singleStackSelected() const;

    Zcad::ErrorStatus    getStack(ZcDbTextEditorStack& stack) const;

    Zcad::ErrorStatus    setStack(const ZcDbTextEditorStack& stack);

    void paragraph(ZcArray<ZcDbTextEditorParagraph*>& paragraphs);

    Zcad::ErrorStatus combineParagraphs();

    Zcad::ErrorStatus removeCharacterFormatting();

    Zcad::ErrorStatus removeParagraphFormatting();

    Zcad::ErrorStatus removeAllFormatting();

    bool canChangeCase() const;

    bool changeToUppercase();

    bool changeToLowercase();

    Zcad::ErrorStatus getSelectionText(ZcString& txt) const;

    bool     singleFieldSelected() const;

    ZcDbField* field() const;

    Zcad::ErrorStatus  updateField();

    Zcad::ErrorStatus  convertToPlainText();

    Zcad::ErrorStatus getLocations(ZcDbTextEditorLocation*& pStartLocation, ZcDbTextEditorLocation*& pEndLocation) const;

protected:
    ZcDbTextEditorSelection(const TextEditor* pImp);
    ~ZcDbTextEditorSelection();
    ZcDbTextEditorSelection(const ZcDbTextEditorSelection&);
    ZcDbTextEditorSelection& operator=(const ZcDbTextEditorSelection&);

    ZcDbImpTextEditorSelection* m_pImpSelection;
    friend class TextEditor;
};

class ZCDBCORE2D_PORT ZcDbTextEditorCursor : public ZcDbTextEditorSelectionBase
{
public:

    ZcDbTextEditorParagraph* paragraph();

    ZcDbTextEditorColumn*    column();

    Zcad::ErrorStatus        setLocation(const ZcDbTextEditorLocation& location);

    ZcDbTextEditorLocation* location() const;

protected:
    ZcDbTextEditorCursor(const TextEditor* pImp);
    ~ZcDbTextEditorCursor();
    ZcDbTextEditorCursor(const ZcDbTextEditorCursor&);
    ZcDbTextEditorCursor& operator=(const ZcDbTextEditorCursor&);

    ZcDbImpTextEditorCursor* m_pImpCursor;
    friend class TextEditor;
};

class ZCDBCORE2D_PORT ZcDbTextEditorParagraphTab
{
public:

    enum ParagraphTabType
    {
        kLeftTab,
        kCenterTab,
        kRightTab,
        kDecimalTab,
    };

     ZcDbTextEditorParagraphTab();

    ~ZcDbTextEditorParagraphTab();

    ZcDbTextEditorParagraphTab(const ZcDbTextEditorParagraphTab&);

    ZcDbTextEditorParagraphTab& operator=(const ZcDbTextEditorParagraphTab&);

    double            offset() const;

    Zcad::ErrorStatus setOffset(double offdist);

    ParagraphTabType  type() const;

    Zcad::ErrorStatus setType(ParagraphTabType type);

    wchar_t             decimalChar() const;

    Zcad::ErrorStatus setDecimalChar(wchar_t decchar);

private:
    ZcDbImpTextEditorParagraphTab* m_pImp;
};

class ZCDBCORE2D_PORT ZcDbTextEditorParagraph : public ZcDbTextEditorSelectable
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

    enum LineSpacingStyle{
        kLineSpacingDefault,
        kLineSpacingExactly,
        kLineSpacingAtLeast,
        kLineSpacingMultiple,
    };

    enum NumberingType{
        kOff = 0,
        kBullet,
        kNumber,
        kLetterLower,
        kLetterUpper,
        kNumberWide,
        kLetterLowerWide,
        kLetterUpperWide,
    };

    Zcad::ErrorStatus setAlignment(AlignmentType AlignmentType);

    AlignmentType alignment() const;

    Zcad::ErrorStatus setFirstIndent(double firstIndent);

    double firstIndent() const;

    Zcad::ErrorStatus setLeftIndent(double leftIndent);

    double leftIndent() const;

    Zcad::ErrorStatus setRightIndent(double rightIndent);

    double rightIndent() const;

    Zcad::ErrorStatus setLineSpacingStyle(LineSpacingStyle lineSpacingStyle);

    LineSpacingStyle  lineSpacingStyle() const;

    Zcad::ErrorStatus setLineSpacingFactor(double lineSpacingFactor);

    double            lineSpacingFactor() const;

    Zcad::ErrorStatus setSpaceBefore(double spaceBefore);

    double            spaceBefore() const;

    Zcad::ErrorStatus setSpaceAfter(double spaceAfter);

    double            spaceAfter() const;

    Zcad::ErrorStatus setNumberingType(NumberingType type);

    NumberingType     numberingType() const;

    Zcad::ErrorStatus restartNumbering();

    Zcad::ErrorStatus continueNumbering();

    int               tabsCount() const;

    Zcad::ErrorStatus addTab(const ZcDbTextEditorParagraphTab& tab);

    Zcad::ErrorStatus removeTab(const ZcDbTextEditorParagraphTab& tab);

    Zcad::ErrorStatus getTab(int i, ZcDbTextEditorParagraphTab& tab);

    virtual ZcDbTextEditorLocation* startOfText() ZSOFT_OVERRIDE;

    virtual ZcDbTextEditorLocation* endOfText() ZSOFT_OVERRIDE;

    double     minLineSpacingFactor() const;

    double     maxLineSpacingFactor() const;

    double     minSpaceValue() const;

    double     maxSpaceValue() const;

    void             release();

private:
    friend class ZcDbTextEditorParagraphIterator;
    friend class ZcDbTextEditorServices;
    ZcDbImpTextEditorParagraph* m_pImp; 

    ZcDbTextEditorParagraph() {}
    virtual ~ZcDbTextEditorParagraph();
    ZcDbTextEditorParagraph(const ZcDbTextEditorParagraph&);
    ZcDbTextEditorParagraph& operator=(const ZcDbTextEditorParagraph&);
};

class ZCDBCORE2D_PORT ZcDbTextEditorParagraphIterator
{
public:

    ZcDbTextEditorParagraphIterator(const ZcDbTextEditor& textEditor);

    ~ZcDbTextEditorParagraphIterator();

    bool done();

    ZcDbTextEditorParagraph* current();

    void next();
private:
    ZcDbImpTextEditorParagraphIterator* m_pImp;
};

class ZCDBCORE2D_PORT ZcDbTextEditorColumn : public ZcDbTextEditorSelectable
{
public:

    double height();

    Zcad::ErrorStatus setHeight(double height);

    void              release();

    virtual ZcDbTextEditorLocation* startOfText() override;

    virtual ZcDbTextEditorLocation* endOfText() override;
private:
    ZcDbImpTextEditorColumn* m_pImp;
    friend class ZcDbTextEditorServices;

    ZcDbTextEditorColumn();
    virtual ~ZcDbTextEditorColumn();
    ZcDbTextEditorColumn(const ZcDbTextEditorColumn&);
    ZcDbTextEditorColumn& operator=(const ZcDbTextEditorColumn&);
};

class ZCDBCORE2D_PORT ZcDbTextEditorColumns
{
public:

    static int maxCount();

    int count() const;

    Zcad::ErrorStatus setCount(int count);

    ZcDbTextEditorColumn* getAt(int i);

    Zcad::ErrorStatus setColumnType(ZcDbMText::ColumnType type);

    ZcDbMText::ColumnType columnType() const;

    Zcad::ErrorStatus setAutoHeight(bool bAutoHeight);

    bool autoHeight() const;

    Zcad::ErrorStatus setWidth(double value);

    double width() const;

    Zcad::ErrorStatus setGutter(double value);

    double gutter() const;

    Zcad::ErrorStatus setTotalWidth(double value);

    double totalWidth() const;

    bool   isFlowReversed() const;

    Zcad::ErrorStatus setIsFlowReversed(bool isFlowReversed);

private:
    friend class TextEditor;
    ZcDbTextEditorColumns();
    ~ZcDbTextEditorColumns();
    ZcDbTextEditorColumns(const ZcDbTextEditorColumns&);
    ZcDbTextEditorColumns& operator=(const ZcDbTextEditorColumns&);

    TextEditor* m_pImp;
};

class ZCDBCORE2D_PORT ZcDbTextEditorWipeout
{
public:

    static double     minBackgroundScaleFactor();

    static double     maxBackgroundScaleFactor();

    bool              enableBackgroundFill() const;

    Zcad::ErrorStatus setEnableBackgroundFill(bool bEnable);

    ZcCmColor         getBackgroundFillColor() const;

    Zcad::ErrorStatus setBackgroundFillColor(ZcCmColor color);

    bool              useBackgroundColor() const;

    Zcad::ErrorStatus setUseBackgroundColor(bool bUse);

    double            getBackgroundScaleFactor()const;

    Zcad::ErrorStatus setBackgroundScaleFactor(double factor);

private:
    ZcDbTextEditorWipeout();
    ~ZcDbTextEditorWipeout();
    ZcDbTextEditorWipeout(const ZcDbTextEditorWipeout&);
    ZcDbTextEditorWipeout& operator=(const ZcDbTextEditorWipeout&);

    TextEditor* m_pEditor;
    friend class TextEditor;
};

class ZCDBCORE2D_PORT ZcDbTextEditorStack
{
public:

    enum StackType
    {
        kHorizontalStack,
        kDiagonalStack,
        kToleranceStack,
        kDecimalStack,
    };

    ZcDbTextEditorStack();

    ~ZcDbTextEditorStack();

    ZcDbTextEditorStack(const ZcDbTextEditorStack&);

    ZcDbTextEditorStack& operator=(const ZcDbTextEditorStack&);

    StackType        type() const;

    Zcad::ErrorStatus setType(StackType type);

    ZcDbTextEditorSelectionBase::FlowAlign alignType() const;

    Zcad::ErrorStatus setAlignType(ZcDbTextEditorSelectionBase::FlowAlign align);

    ZcString top() const;

    Zcad::ErrorStatus setTop(const ZcString& top);

    ZcString           bottom() const;

    Zcad::ErrorStatus setBottom(const ZcString& bottom);

    double            scale() const;

    Zcad::ErrorStatus setScale(double scale);

    wchar_t             decimalChar() const;

    Zcad::ErrorStatus setDecimalChar(wchar_t decimalChar);

    static double       minStackScale();

    static double       maxStackScale();

private:
    ZcDbImpTextEditorStack*   m_pImpStack;
};

class ZCDBCORE2D_PORT ZcDbTextEditor : public ZcDbTextEditorSelectable
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

    static ZcDbTextEditor* createDbTextEditor(ZcDbMText* pMText);

    virtual void  close(ExitStatus stat);

    void   redraw();

    ZcDbTextEditorColumns* columns();

    ZcDbTextEditorWipeout* wipeout();

    ZcDbTextEditorParagraphIterator* newParagraphsIterator();

    virtual ZcDbTextEditorSelection* selection();

    virtual ZcDbTextEditorCursor*    cursor();

    Zcad::ErrorStatus clearSelection();

    Zcad::ErrorStatus makeSelection(const ZcDbTextEditorLocation* pStart,
        const ZcDbTextEditorLocation* pEnd);

    Zcad::ErrorStatus findText(const ZTCHAR* text, int flags,
        ZcDbTextEditorLocation*& pStart,
        ZcDbTextEditorLocation*& pEnd);

    Zcad::ErrorStatus setAttachment(ZcDbMText::AttachmentPoint attachment);

    ZcDbMText::AttachmentPoint attachment() const;

    Zcad::ErrorStatus setStyle(int index);

    Zcad::ErrorStatus setStyle(ZcDbObjectId styleId);

    int               getIndexFromStyleName(const ZcString& styleName);

    int               getStyleCount() const;

    ZcString           getStyleName(int index) const;

    ZcDbObjectId      style(int index) const;

    int               currentStyleIndex() const;

    bool              isAnnotativeStyle(int index) const;

    bool             isVerticalSHX() const;

    bool             isVerticalTTF() const;

    Zcad::ErrorStatus setDefinedWidth(double width);

    double            definedWidth() const;

    Zcad::ErrorStatus setDefinedHeight(double height);

    double            definedHeight() const;

    double            textHeight() const;

    Zcad::ErrorStatus setTextHeight(double textHeight);

    double            actualWidth() const;

    double            actualHeight() const;

    Zcad::ErrorStatus selectAll(); 

    Zcad::ErrorStatus setAutoCAPS(bool autoCAPS);

    bool              autoCAPS();

    Zcad::ErrorStatus setEnableNumbering(bool bEnable);

    bool              numberingEnabled() const;

    Zcad::ErrorStatus setAutolistEnabled(bool enabled);

    bool              autolistEnabled() const;

    Zcad::ErrorStatus setTabOnlyDelimiter(bool tabOnlyDelimiter);

    bool              tabOnlyDelimiter() const;

    int               getFontCount() const;

    ZcString          getFontName(int index) const;

    bool              isTrueTypeFont(int index) const;

    int               stackCount() const;

    double             defaultStackScale() const;

    Zcad::ErrorStatus    setDefaultStackScale(double scale);

    ZcDbTextEditorSelectionBase::FlowAlign defaultStackAlignment() const;

    Zcad::ErrorStatus    setDefaultStackAlignment(ZcDbTextEditorSelectionBase::FlowAlign alignment);

    virtual ZcDbTextEditorLocation* startOfText() override;

    virtual ZcDbTextEditorLocation* endOfText() override;

protected:
    ZcDbTextEditor():m_pImp(NULL) {};
    virtual ~ZcDbTextEditor();

    friend class ZcDbTextEditorLocation;
    friend class ZcDbTextEditorParagraphIterator;
    TextEditor* m_pImp;

private:
    ZcDbTextEditor(const ZcDbTextEditor& editor);
    ZcDbTextEditor& operator=(const ZcDbTextEditor& editor);
};
