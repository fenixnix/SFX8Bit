#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSound>
#include <QFile>
#include <QAudioOutput>
#include <QBuffer>
#include "chiptune/Sfx8Bit.h"
#include "Device/qaudioplayer.h"
#include "Device/qmusicinstrument.h"

Sfx8Bit sfx;
vector<float> wavData;
QAudioPlayer player;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void Play(vector<float> rawData){
//    for(int i = 0;i<rawData.size();i++){
//        qDebug()<<rawData[i];
//      }
    player.ImportData(rawData);
    player.Play();
}

void Play(){
  sfx.SynthSample(wavData);
  Play(wavData);
  NWavWriter::Save("tmp.wav",wavData);
  //QSound::play("tmp.wav");
}

void MainWindow::on_PickUp_CoinBtn_clicked()
{
  sfx.PickUp_Coin();
  Play();
}

void MainWindow::on_Laser_ShootBtn_clicked()
{
  sfx.Laser_Shoot();
  Play();
}

void MainWindow::on_ExplosionBtn_clicked()
{
  sfx.Explosion();
  Play();
}

void MainWindow::on_PowerUpBtn_clicked()
{
  sfx.PowerUp();
  Play();
}

void MainWindow::on_Hit_HurtBtn_clicked()
{
  sfx.Hit_Hurt();
  Play();
}

void MainWindow::on_JumpBtn_clicked()
{
  sfx.Jump();
  Play();
}

void MainWindow::on_Blip_SelectBtn_clicked()
{
  sfx.Blip_Select();
  Play();
}

void MainWindow::on_actionKeyboard_triggered()
{
  keyboard.show();
}

void MainWindow::on_actionTune_Test_triggered()
{
    testDlg.exec();
}
