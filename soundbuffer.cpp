#include "soundbuffer.h"

SoundBuffer::SoundBuffer()
{

}

void SoundBuffer::Start()
{
  open(QIODevice::ReadOnly);
}

void SoundBuffer::Stop()
{
  m_pos = 0;
  close();
}

qint64 SoundBuffer::readData(char *data, qint64 len)
{
  qint64 total = 0;
//  if(m_pos>1){
//      return 0;
//    }
  if (!buffer.isEmpty()) {
      while (len - total > 0) {
          const qint64 chunk = qMin((buffer.size() - m_pos), len - total);
          memcpy(data + total, buffer.constData() + m_pos, chunk);
          m_pos = (m_pos + chunk) % buffer.size();
          total += chunk;
      }
  }
  return total;
}

qint64 SoundBuffer::writeData(const char *data, qint64 len)
{
  Q_UNUSED(data);
  Q_UNUSED(len);
  return 0;
}

qint64 SoundBuffer::bytesAvailable() const
{
    return buffer.size() + QIODevice::bytesAvailable();
}

void SoundBuffer::SetData(QByteArray data)
{
    buffer = data;
}

#include <qmath.h>
#include <qendian.h>
void SoundBuffer::generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate)
{
  const int channelBytes = format.sampleSize() / 8;
  const int sampleBytes = format.channelCount() * channelBytes;

  qint64 length = (format.sampleRate() * format.channelCount() * (format.sampleSize() / 8))
                      * durationUs / 100000;

  Q_ASSERT(length % sampleBytes == 0);
  Q_UNUSED(sampleBytes) // suppress warning in release builds

  buffer.resize(length);
  unsigned char *ptr = reinterpret_cast<unsigned char *>(buffer.data());
  int sampleIndex = 0;

  while (length) {
      const qreal x = qSin(2 * 3.14 * sampleRate * qreal(sampleIndex % format.sampleRate()) / format.sampleRate());
      for (int i=0; i<format.channelCount(); ++i) {
          if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::UnSignedInt) {
              const quint8 value = static_cast<quint8>((1.0 + x) / 2 * 255);
              *reinterpret_cast<quint8*>(ptr) = value;
          } else if (format.sampleSize() == 8 && format.sampleType() == QAudioFormat::SignedInt) {
              const qint8 value = static_cast<qint8>(x * 127);
              *reinterpret_cast<quint8*>(ptr) = value;
          } else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::UnSignedInt) {
              quint16 value = static_cast<quint16>((1.0 + x) / 2 * 65535);
              if (format.byteOrder() == QAudioFormat::LittleEndian)
                  qToLittleEndian<quint16>(value, ptr);
              else
                  qToBigEndian<quint16>(value, ptr);
          } else if (format.sampleSize() == 16 && format.sampleType() == QAudioFormat::SignedInt) {
              qint16 value = static_cast<qint16>(x * 32767);
              if (format.byteOrder() == QAudioFormat::LittleEndian)
                  qToLittleEndian<qint16>(value, ptr);
              else
                  qToBigEndian<qint16>(value, ptr);
          }

          ptr += channelBytes;
          length -= channelBytes;
      }
      ++sampleIndex;
  }
}
