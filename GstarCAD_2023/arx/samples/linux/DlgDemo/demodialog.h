/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//

#ifndef DEMO_DIALOG_H
#define DEMO_DIALOG_H

#include <QDialog>


class CGcQtDemoDialogWidget : public QDialog
{
  Q_OBJECT

public:
  CGcQtDemoDialogWidget(QWidget *pParent);
  ~CGcQtDemoDialogWidget();

  int doModal();

public slots:
  void onClickEditMode_getpoint();
  void onClickEditMode_JIG();

private:
  void onCreate();
  void beginEditorCommand();
  void completeEditorCommand(bool restoreDialogs = true);

private:
  /*
  QT特别的:当对话框从EDITMODE返回后，可能存在需要重新显示的状况，
  原因是hide引起EventLoop标识了退出，但还没有执行退出过程，此时执行show,对话框的EventLoop还是会继续退出，
  导致程序对话框显示不出来,所以在exec()后还要检查对话框是否是要ReenterShow,如果是要再执行一次exec
  */
  bool m_bReenterShow;
};

#endif 
