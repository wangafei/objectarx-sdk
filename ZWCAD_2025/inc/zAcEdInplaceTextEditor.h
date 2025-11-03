#ifndef ZcEdInplaceTextEditor_H
#define ZcEdInplaceTextEditor_H

#include "zdbtexteditor.h"
#include "zAcCoreDefs.h"

class IPE_Editor;
class ZcEdInplaceTextEditor;
class IZcEdInplaceTextEditorHost;
class ZcEdInplaceTextEditorSettingsImp;
class ZcEdInplaceTextEditorImp;

class ZCCORE_PORT ZcEdInplaceTextEditorSettings
{
public:
    ZcEdInplaceTextEditorSettings();

    ~ZcEdInplaceTextEditorSettings();

    enum EntityType
    {

        kDefault,

        kTableCell,

        kMultiAttribute
    };

    enum EditFlags
    {

        kForceOpaqueBackground = 1 << 0,

        kSelectAll = 1 << 1,

        kCursorAtEnd = 1 << 2,
    };

public:
    int               editFlags() const;

    Zcad::ErrorStatus setEditFlags(int flags);

    EntityType        sourceEntityType() const;

    Zcad::ErrorStatus setSourceEntityType(EntityType type);

    bool              tabSupported() const;

    Zcad::ErrorStatus setSupportTab(bool bTab);

    bool              simpleMText() const;

    Zcad::ErrorStatus setSimpleMText(bool bSimpleMText);

    double            definedHeight() const;

    Zcad::ErrorStatus setDefinedHeight(double height);
protected:
    ZcEdInplaceTextEditorSettingsImp* m_pImp;
private:
    ZcEdInplaceTextEditorSettings(const ZcEdInplaceTextEditorSettings& editor);
    ZcEdInplaceTextEditorSettings& operator=(const ZcEdInplaceTextEditorSettings& editor);
};

class ZCCORE_PORT ZcEdInplaceTextEditor : public ZcDbTextEditor
{
public:
    static ZcEdInplaceTextEditor* current();

    void setHost(IZcEdInplaceTextEditorHost* pHost);

    static Zcad::ErrorStatus invoke(ZcDbMText* pMtext, const ZcEdInplaceTextEditorSettings* pSettings);

    static Zcad::ErrorStatus invoke(ZcDbText* pText, ZcDbObjectIdArray* appendedEntities);

public:
    enum TextUndoType {

        kUndoTyping = 1,

        kUndoBoldOn,

        kUndoBoldOff,

        kUndoItalicOn,

        kUndoItalicOff,

        kUndoUnderlineOn,

        kUndoUnderlineOff,

        kUndoOverlineOn,

        kUndoOverlineOff,

        kUndoFont,

        kUndoHeight,

        kUndoColor,

        kUndoObliqueAngle,

        kUndoWidthScale,

        kUndoTrackingFactor,

        kUndoLanguage,

        kUndoBackspace,

        kUndoDelete,

        kUndoPaste,

        kUndoCut,

        kUndoStack,

        kUndoUnstack,

        kUndoStackProperties,

        kUndoFieldInsert,

        kUndoFieldConvert,

        kUndoFieldUpdate,

        kUndoSymbolInsert,

        kUndoAutoField,

        kUndoAutoStack,

        kUndoAutoSymbol,

        kUndoAutoDTextEscape,

        kUndoAutoMifOrCif,

        kUndoAutoDimension,

        kUndoAutoDimBreak,

        kUndoAutoSpell,

        kUndoStyle,

        kUndoAttachment,

        kUndoChangeCase,

        kUndoImportText,

        kUndoCombineParagraphs,

        kUndoRemoveCharFormatting,

        kUndoRemoveParaFormatting,

        kUndoRemoveAllFormatting,

        kUndoReplaceAll,

        kUndoReplace,

        kUndoParagraphAttributes,

        kUndoSetDefinedWidth,

        kUndoSetDefinedHeight,

        kUndoCharAttributes,

        kUndoWipeout,

        kUndoDimensionInsert,

        kUndoDimBreakInsert,

        kUndoCustomConvert,

        kUndoDeleteAndMoveSelection,

        kUndoParagraphNumbering,

        kUndoCursorAttributes,

        kUndoColumns,

        kUndoAnnoState,

        kUndoDimensionTweak,

        kUndoDimensionSymbol,

        kUndoDimensionTemplate,
    };

    bool canUndo() const;

    Zcad::ErrorStatus undo();

    bool canRedo() const;

    Zcad::ErrorStatus redo();

    Zcad::ErrorStatus  addUndoMarker(TextUndoType type);

    bool              canCut() const;

    bool              canCopy() const;

    bool              canPaste() const;

    Zcad::ErrorStatus cut();

    Zcad::ErrorStatus copy();

    Zcad::ErrorStatus paste();

    Zcad::ErrorStatus pasteWithoutFormats();

    bool              undoRecordingDisabled();

    Zcad::ErrorStatus setUndoRecordingDisable(bool disabled);

    Zcad::ErrorStatus setAnnotative(bool bSet);

    bool              annotative() const;

    bool   isTableCell() const;

    bool   isSimpleMtext() const;

    bool   isText() const;

    bool   isMultiAttribute() const;

    bool   isParagraphSupported() const;

    void   replaceAllMatchItems(int findFlags, const ZcString& findStr, const ZcString& replaceStr) const;

    void   replaceCurrentMatchItem(int findFlags, const ZcString& findStr, const ZcString& replaceStr) const;

    void   findMatchItem(int findFlags, const ZcString& findStr) const;

    void   setCanExitInplaceEditor(bool bCanExit);

    bool   canExitInplaceEditor();

    void   removeHightlight();

    void   drawHighlight();

    ZcDbTextEditorParagraph::AlignmentType getAlignmentFromAttachment() const;

    COLORREF layerColor() const;

    bool     spellerEnabled() const;

    void     toggleSpelling();

    void     insertFile(const ZcString& fileName);

    bool     rulerSupported() const;

    void   setRulerHidden(bool hideRuler);

    bool   rulerHidden() const;

    void   setOpaqueBackground(bool opaqueBackground);

    bool   opaqueBackground();

    bool   forcedOpaqueBackground();

    bool   wysiwyg();

    void   enableWysiwyg();

    virtual void  close(ExitStatus stat);

    void   otherSymbol();

    void   setToolbarHidden(bool bHideToolbar);

    bool   toolbarHidden() const;

    void   setToolbarOptionHidden(bool bHideOption);

    bool   toolbarOptionHidden() const;

    Zcad::ErrorStatus columnMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus attachmentMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus lineSpaceMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus numberingMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus symbolMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus contextMenusInput(ZcGePoint2d* menuPt, HWND parentHandle);

    Zcad::ErrorStatus invokeParagraphDialog();

    Zcad::ErrorStatus invokeWipeoutDialog();

    Zcad::ErrorStatus invokeColumnsDialog(int iStaticColumnCount = 0);

    Zcad::ErrorStatus invokeFindReplaceDialog();

    Zcad::ErrorStatus invokeImportTextDialog();

    Zcad::ErrorStatus invokeFieldDialog(ZcDbField* pField = NULL);

    Zcad::ErrorStatus invokeSpellSettingDialog();

    Zcad::ErrorStatus invokeSpellerDictionaryDialog();

    Zcad::ErrorStatus invokeHightlightColorDialog();

    Zcad::ErrorStatus invokeHelpDialog();

    ZSOFT_DEPRECATED Zcad::ErrorStatus invokeNewFeatureWorkshop();

    Zcad::ErrorStatus invokeStackPropertyDialog();

    Zcad::ErrorStatus setStaticColumnsWithCount(int columnCount);

    Zcad::ErrorStatus setTextLayer(const ZcString& layername);
protected:
    ZcEdInplaceTextEditor();
    ~ZcEdInplaceTextEditor();
    ZcEdInplaceTextEditor(const ZcEdInplaceTextEditor&);
    ZcEdInplaceTextEditor& operator=(const ZcEdInplaceTextEditor&);

protected:
   friend class ZcEdInplaceTextEditorImp;
   ZcEdInplaceTextEditorImp* m_pEditorImp;
   IPE_Editor*               m_pIPEEditorImp;
};

#endif
