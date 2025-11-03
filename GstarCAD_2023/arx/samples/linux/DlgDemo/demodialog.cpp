/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//

#include "demodialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>

#include "adsdef.h"
#include "acedads.h"
#include "acutads.h"
#include "adscodes.h"
#include "AcString.h"
#include "dbjig.h"
#include "dbents.h"

CGcQtDemoDialogWidget::CGcQtDemoDialogWidget(QWidget *pParent)
  : QDialog(pParent)
  , m_bReenterShow(false)
{
  onCreate();
}

CGcQtDemoDialogWidget::~CGcQtDemoDialogWidget()
{
}

int CGcQtDemoDialogWidget::doModal()
{
  int ret = this->exec();
  while (m_bReenterShow)
  {
    m_bReenterShow = false;
    ret = this->exec();
  }

  return ret;
}

void CGcQtDemoDialogWidget::onCreate()
{
  setWindowTitle(tr("DemoDialog"));

  QVBoxLayout *pMainLayout = new QVBoxLayout;
  setLayout(pMainLayout);

  {
    auto button = new QPushButton(u8"EditMode + acedgetpoint测试");
    pMainLayout->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SLOT(onClickEditMode_getpoint()));
  }

  {
    auto button = new QPushButton(u8"画线");
    pMainLayout->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(onClickEditMode_JIG()));
  }

  QDialogButtonBox *pButtonBox = new QDialogButtonBox();
  pButtonBox->addButton(u8"确定", QDialogButtonBox::YesRole);
  pButtonBox->addButton(u8"取消", QDialogButtonBox::NoRole);
  pMainLayout->addWidget(pButtonBox);
  connect(pButtonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void CGcQtDemoDialogWidget::beginEditorCommand()
{
  this->hide();
}

void CGcQtDemoDialogWidget::completeEditorCommand(bool restoreDialogs /*= true*/)
{
  if (restoreDialogs)
  {
    this->show();
    m_bReenterShow = true;
  }
  else
  {
    m_bReenterShow = false;
    this->close();
  }
}

void CGcQtDemoDialogWidget::onClickEditMode_getpoint()
{
  this->beginEditorCommand();
  ads_point pt = { 0 };
  if (RTNORM == acedGetPoint(NULL, L"\n选择一个点:", pt))
  {
    AcString strPoint;
    strPoint.format(L"\n (%f, %f, %f)", pt[0], pt[1], pt[2]);
    acutPrintf(strPoint.constPtr());
  }

  this->completeEditorCommand();
}



//增加，过点，且定向的得点过程的JIG对象
class GcTestLineJig : public AcEdJig
{
public:
  GcTestLineJig(AcGePoint3d from)
  {
    m_pLine = new AcDbLine;
    m_pLine->setStartPoint(from);
    m_pLine->setEndPoint(from);
  }

  virtual ~GcTestLineJig()
  {
    m_pLine = NULL;
  }

  virtual DragStatus	sampler()
  {
    double dDist = 0.0;
    AcGePoint3d pnt;
    AcEdJig::DragStatus ds = this->acquirePoint(pnt);
    if (ds == AcEdJig::kNormal)
    {
      dDist = pnt.distanceTo(m_lastSamplePt);
      if (dDist < 1e-3)
      {
        ds = AcEdJig::kNoChange;
      }
      else
      {
        m_lastSamplePt = pnt;
      }
      m_lastPt = pnt;
    }

    return ds;
  }

  virtual bool  update()
  {
    m_pLine->setEndPoint(m_lastSamplePt);
    return true;
  }

  virtual AcDbEntity* entity() const
  {
    return (AcDbEntity*)m_pLine;
  }

  GcGePoint3d point()const {
    return m_lastPt;
  }
private:
  AcDbLine*     m_pLine;      // 拖动的线段
  AcGePoint3d   m_ptBase;     // 通过点，同时也是线段的起点
  AcGePoint3d		m_lastSamplePt;
  AcGePoint3d		m_lastPt;
};

void CGcQtDemoDialogWidget::onClickEditMode_JIG()
{
  this->beginEditorCommand();
  ads_point pt = { 0 };
  if (RTNORM != acedGetPoint(NULL, L"\n指定起点:", pt))
    return;

  GcTestLineJig singleLineJig(AcGePoint3d(pt[0], pt[1], pt[2]));
  singleLineJig.setDispPrompt(L"\n指定终点：");
  int nRet = singleLineJig.drag();
  if (nRet == AcEdJig::kNormal)
  {
    singleLineJig.append();
    this->completeEditorCommand(true);
  }
  else
  {
    this->completeEditorCommand(false);
  }
}
