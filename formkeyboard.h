#ifndef FORMKEYBOARD_H
#define FORMKEYBOARD_H

#include <QWidget>
#include "qmusicinstrument.h"

namespace Ui {
  class FormKeyboard;
}

class FormKeyboard : public QWidget
{
  Q_OBJECT

public:
  explicit FormKeyboard(QWidget *parent = 0);
  ~FormKeyboard();

public slots:
  void OnClickKey();

private slots:
  void on_btnBass_clicked();

  void on_btnSide_clicked();

  void on_btnHighHat_clicked();

  void on_btnTomtom_clicked();

private:
  Ui::FormKeyboard *ui;
  QMusicInstrument music;
  QMusicInstrument Drum;
  void InitKey();
};

#endif // FORMKEYBOARD_H
