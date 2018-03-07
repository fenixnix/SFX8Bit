#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PickUp_CoinBtn_clicked();

    void on_Laser_ShootBtn_clicked();

    void on_ExplosionBtn_clicked();

    void on_PowerUpBtn_clicked();

    void on_Hit_HurtBtn_clicked();

    void on_JumpBtn_clicked();

    void on_Blip_SelectBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
