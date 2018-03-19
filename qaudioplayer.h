#ifndef QAUDIOPLAYER_H
#define QAUDIOPLAYER_H

#include <QAudioOutput>
#include <QBuffer>
#include <QString>
#include <QDebug>
#include <vector>
#include "nchiptune.h"

using namespace std;

class QAudioPlayer
{
public:
  QAudioPlayer();
  ~QAudioPlayer();

  QStringList GetAvailableDevices();
  void SetDevice(QString deviceID);
  void Import(QByteArray data);
  void ImportData(vector<float> rawData);
  void Save(QString fileName);
  static vector<float> Export(QByteArray data);

  void Play();
  void Play(QByteArray data);

  QAudioFormat Format;

private:
  bool CheckDevice();

  QAudioDeviceInfo deviceInfo;
  QBuffer* buffer;
  QByteArray dataBuffer;
  QAudioOutput* output;
};

#endif // QAUDIOPLAYER_H
