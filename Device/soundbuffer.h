#ifndef SOUNDBUFFER_H
#define SOUNDBUFFER_H

#include <QIODevice>
#include <QAudioFormat>

class SoundBuffer : public QIODevice
{
public:
  SoundBuffer();

  void Start();
  void Stop();

  qint64 readData(char *data, qint64 maxlen) override;
  qint64 writeData(const char *data, qint64 len) override;
  qint64 bytesAvailable() const override;

  void SetData(QByteArray data);
  void generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate);
private:


  QByteArray buffer;
  qint64 m_pos;
};

#endif // SOUNDBUFFER_H
