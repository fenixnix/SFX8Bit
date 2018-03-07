#ifndef QAUDIOPLAYER_H
#define QAUDIOPLAYER_H

#include <QAudioOutput>
#include <QBuffer>
#include <QString>
#include <QDebug>
#include <vector>
#include "nchiptune.h"
#include "nmusic.h"

using namespace std;

class QAudioPlayer
{
public:
  QAudioPlayer();
  ~QAudioPlayer();

  QStringList GetAvailableDevices();
  void SetDevice(QString deviceID);

  void ImportData(vector<float> rawData);

  void Play();

  void TestPlay();

  QAudioFormat Format;

private:
  bool CheckDevice();

  QAudioOutput* output;
  QAudioDeviceInfo deviceInfo;

  NMusic music;
  NChipTune chipTune;
  QBuffer* buffer;
  QByteArray dataBuffer;
};

#endif // QAUDIOPLAYER_H
