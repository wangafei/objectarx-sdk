/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GcEdInplaceTextEditor_H
#define GcEdInplaceTextEditor_H

#include "dbtexteditor.h"
#include "gccoredefs.h"

class IPE_Editor;
class GcEdInplaceTextEditor;
class IGcEdInplaceTextEditorHost;
class GcEdInplaceTextEditorSettingsImp;
class GcEdInplaceTextEditorImp;

class GcEdInplaceTextEditorSettings
{
public:
  GCCORE_PORT GcEdInplaceTextEditorSettings();
  GCCORE_PORT ~GcEdInplaceTextEditorSettings();

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
  GCCORE_PORT int               editFlags() const;
  GCCORE_PORT Gcad::ErrorStatus setEditFlags(int flags);

  GCCORE_PORT EntityType        sourceEntityType() const;
  GCCORE_PORT Gcad::ErrorStatus setSourceEntityType(EntityType type);

  GCCORE_PORT bool              tabSupported() const;
  GCCORE_PORT Gcad::ErrorStatus setSupportTab(bool bTab);

  GCCORE_PORT bool              simpleMText() const;
  GCCORE_PORT Gcad::ErrorStatus setSimpleMText(bool bSimpleMText);

  GCCORE_PORT double            definedHeight() const;
  GCCORE_PORT Gcad::ErrorStatus setDefinedHeight(double height);
protected:
  GcEdInplaceTextEditorSettingsImp* m_pImp;
private:
  GcEdInplaceTextEditorSettings(const GcEdInplaceTextEditorSettings& editor);
  GcEdInplaceTextEditorSettings& operator=(const GcEdInplaceTextEditorSettings& editor);
};

class GcEdInplaceTextEditor : public GcDbTextEditor
{
public:
  GCCORE_PORT static GcEdInplaceTextEditor* current();
  GCCORE_PORT void setHost(IGcEdInplaceTextEditorHost* pHost);
  GCCORE_PORT static Gcad::ErrorStatus invoke(GcDbMText* pMtext, const GcEdInplaceTextEditorSettings* pSettings);
  GCCORE_PORT static Gcad::ErrorStatus invoke(GcDbText* pText, GcDbObjectIdArray* appendedEntities);

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

  GCCORE_PORT bool canUndo() const;
  GCCORE_PORT Gcad::ErrorStatus undo();

  GCCORE_PORT bool canRedo() const;
  GCCORE_PORT Gcad::ErrorStatus redo();

  GCCORE_PORT Gcad::ErrorStatus  addUndoMarker(TextUndoType type);

  GCCORE_PORT bool              canCut() const;
  GCCORE_PORT bool              canCopy() const;
  GCCORE_PORT bool              canPaste() const;

  GCCORE_PORT Gcad::ErrorStatus cut();
  GCCORE_PORT Gcad::ErrorStatus copy();
  GCCORE_PORT Gcad::ErrorStatus paste();
  GCCORE_PORT Gcad::ErrorStatus pasteWithoutFormats();

  GCCORE_PORT bool              undoRecordingDisabled();
  GCCORE_PORT Gcad::ErrorStatus setUndoRecordingDisable(bool disabled);

  GCCORE_PORT Gcad::ErrorStatus setAnnotative(bool bSet);
  GCCORE_PORT bool              annotative() const;

  GCCORE_PORT bool   isTableCell() const;
  GCCORE_PORT bool   isSimpleMtext() const;
  GCCORE_PORT bool   isText() const;

  GCCORE_PORT bool   isMultiAttribute() const;

  GCCORE_PORT bool   isParagraphSupported() const;

  GCCORE_PORT void   replaceAllMatchItems(int findFlags, const GcString& findStr, const GcString& replaceStr) const;
  GCCORE_PORT void   replaceCurrentMatchItem(int findFlags, const GcString& findStr, const GcString& replaceStr) const;
  GCCORE_PORT void   findMatchItem(int findFlags, const GcString& findStr) const;

  GCCORE_PORT void   setCanExitInplaceEditor(bool bCanExit);
  GCCORE_PORT bool   canExitInplaceEditor();

  GCCORE_PORT void   removeHightlight();
  GCCORE_PORT void   drawHighlight();

  GCCORE_PORT GcDbTextEditorParagraph::AlignmentType getAlignmentFromAttachment() const;

  GCCORE_PORT COLORREF layerColor() const;

  GCCORE_PORT bool     spellerEnabled() const;
  GCCORE_PORT void     toggleSpelling();

  GCCORE_PORT void     insertFile(const GcString& fileName);

  GCCORE_PORT bool     rulerSupported() const;
  GCCORE_PORT void   setRulerHidden(bool hideRuler);
  GCCORE_PORT bool   rulerHidden() const;

  GCCORE_PORT void   setOpaqueBackground(bool opaqueBackground);
  GCCORE_PORT bool   opaqueBackground();

  GCCORE_PORT bool   forcedOpaqueBackground();

  GCCORE_PORT bool   wysiwyg();
  GCCORE_PORT void   enableWysiwyg();

  GCCORE_PORT void  close(ExitStatus stat) override;

  GCCORE_PORT void   otherSymbol();

  GCCORE_PORT void   setToolbarHidden(bool bHideToolbar);
  GCCORE_PORT bool   toolbarHidden() const;

  GCCORE_PORT void   setToolbarOptionHidden(bool bHideOption);
  GCCORE_PORT bool   toolbarOptionHidden() const;

  GCCORE_PORT Gcad::ErrorStatus columnMenusInput(GcGePoint2d* menuPt, HWND parentHandle);
  GCCORE_PORT Gcad::ErrorStatus attachmentMenusInput(GcGePoint2d* menuPt, HWND parentHandle);
  GCCORE_PORT Gcad::ErrorStatus lineSpaceMenusInput(GcGePoint2d* menuPt, HWND parentHandle);
  GCCORE_PORT Gcad::ErrorStatus numberingMenusInput(GcGePoint2d* menuPt, HWND parentHandle);
  GCCORE_PORT Gcad::ErrorStatus symbolMenusInput(GcGePoint2d* menuPt, HWND parentHandle);
  GCCORE_PORT Gcad::ErrorStatus contextMenusInput(GcGePoint2d* menuPt, HWND parentHandle);

  GCCORE_PORT Gcad::ErrorStatus invokeParagraphDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeWipeoutDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeColumnsDialog(int iStaticColumnCount = 0);
  GCCORE_PORT Gcad::ErrorStatus invokeFindReplaceDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeImportTextDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeFieldDialog(GcDbField* pField = NULL);
  GCCORE_PORT Gcad::ErrorStatus invokeSpellSettingDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeSpellerDictionaryDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeHightlightColorDialog();
  GCCORE_PORT Gcad::ErrorStatus invokeHelpDialog();
  GSOFT_DEPRECATED GCCORE_PORT Gcad::ErrorStatus invokeNewFeatureWorkshop();
  GCCORE_PORT Gcad::ErrorStatus invokeStackPropertyDialog();
  GCCORE_PORT Gcad::ErrorStatus setStaticColumnsWithCount(int columnCount);
protected:
  GcEdInplaceTextEditor();
  ~GcEdInplaceTextEditor();
  GcEdInplaceTextEditor(const GcEdInplaceTextEditor&);
  GcEdInplaceTextEditor& operator=(const GcEdInplaceTextEditor&);

protected:
  friend class GcEdInplaceTextEditorImp;
  GcEdInplaceTextEditorImp* m_pEditorImp;
  IPE_Editor*               m_pIPEEditorImp;
};

#endif 