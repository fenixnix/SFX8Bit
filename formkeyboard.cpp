#include "formkeyboard.h"
#include "ui_formkeyboard.h"
#include <QPushButton>
#include <QDebug>

FormKeyboard::FormKeyboard(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::FormKeyboard)
{
  ui->setupUi(this);
  music.SetMode("China");
  InitKey();
}

FormKeyboard::~FormKeyboard()
{
  delete ui;
}

void FormKeyboard::OnClickKey()
{
  QPushButton* btn = (QPushButton*)sender();
  int v = btn->toolTip().toInt();
  music.Play(v);
}

void FormKeyboard::InitKey()
{
  int cnt = music.GetModeNoteCount();
  for(int i = -cnt;i<cnt*2;i++){
      QPushButton* btn = new QPushButton();
      btn->setToolTip(QString::number(i));
      QObject::connect(btn,&QPushButton::pressed,this,&FormKeyboard::OnClickKey);
      ui->horizontalLayout_Keyboard->addWidget(btn);
      btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    }
}

void FormKeyboard::on_btnBass_clicked()
{
    Drum.Bass();
}

void FormKeyboard::on_btnSide_clicked()
{
    Drum.SideDrum();
}

void FormKeyboard::on_btnHighHat_clicked()
{
    Drum.HighHat();
}

void FormKeyboard::on_btnTomtom_clicked()
{
    Drum.Tomtom();
}
