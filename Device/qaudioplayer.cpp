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

void QAudioPlayer::Save(QString fileName)
{
  auto data = Export(dataBuffer);
  NWavWriter::Save(fileName.toStdString(),data);
}

vector<float> QAudioPlayer::Export(QByteArray data)
{
  vector<float> outDatas;
  for(char c :data){
      outDatas.push_back((float)c/127.0f);
    }
}

void QAudioPlayer::Import(QByteArray data)
{
  output->stop();
  dataBuffer.clear();
  dataBuffer.append(data);
  buffer->open(QIODevice::ReadOnly);
}

void QAudioPlayer::Play()
{
  output->start(buffer);
}

void QAudioPlayer::Play(QByteArray data)
{
  Import(data);
  Play();
}

bool QAudioPlayer::CheckDevice()
{
  if (!deviceInfo.isFormatSupported(Format)) {
      qWarning() << "Raw audio format not supported by backend, cannot play audio.";
      return false;
    }
  return true;
}

