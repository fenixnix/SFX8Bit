#include "qaudioplayer.h"

QAudioPlayer::QAudioPlayer()
{
  buffer = NULL;
  Format.setSampleRate(22500);
  Format.setChannelCount(1);
  Format.setSampleSize(8);
  Format.setSampleType(QAudioFormat::SignedInt);
  Format.setByteOrder(QAudioFormat::LittleEndian);
  Format.setCodec("audio/pcm");
  deviceInfo = QAudioDeviceInfo::defaultOutputDevice();
  CheckDevice();
  buffer = new QBuffer(&dataBuffer);
  output = new QAudioOutput(deviceInfo,Format);
}

QAudioPlayer::~QAudioPlayer()
{
  buffer->close();
  output->stop();
  delete buffer;
  delete output;
}

QStringList QAudioPlayer::GetAvailableDevices()
{
  auto deviceList = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
  QStringList list;
  for(auto d : deviceList){
      list.append(d.deviceName());
    }
  return list;
}

void QAudioPlayer::SetDevice(QString deviceID)
{
  auto deviceList = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
  for(auto d : deviceList){
      if(d.deviceName() == deviceID){
          deviceInfo = d;
          CheckDevice();
          break;
        }
    }
  CheckDevice();
}

void QAudioPlayer::ImportData(vector<float> rawData)
{
  output->stop();
  dataBuffer.clear();
  for(auto d :rawData){
      dataBuffer.append((char)(d*127+128));
    }
  buffer->open(QIODevice::ReadOnly);
}

void QAudioPlayer::Play()
{
  output->start(buffer);
}

void QAudioPlayer::TestPlay()
{
  //chipTune.Pulse(880);
  chipTune.Pulse(music.Note(0));
  chipTune.Print();
  chipTune.Start();
  output->start(&chipTune);
}

bool QAudioPlayer::CheckDevice()
{
  if (!deviceInfo.isFormatSupported(Format)) {
      qWarning() << "Raw audio format not supported by backend, cannot play audio.";
      return false;
    }
  return true;
}

