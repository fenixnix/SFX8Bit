#include "nchiptune.h"

NChipTune::NChipTune()
{
    Format.setSampleRate(22500);
    Format.setChannelCount(1);
    Format.setSampleSize(8);
    Format.setSampleType(QAudioFormat::SignedInt);
    Format.setByteOrder(QAudioFormat::LittleEndian);
    Format.setCodec("audio/pcm");
}

void NChipTune::Start()
{
    open(QIODevice::ReadOnly);
}

void NChipTune::Stop()
{
    m_pos = 0;
    close();
}

qint64 NChipTune::readData(char *data, qint64 len)
{
    qint64 total = 0;
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

qint64 NChipTune::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);
    return 0;
}

qint64 NChipTune::bytesAvailable() const
{
    return buffer.size() + QIODevice::bytesAvailable();
}



void NChipTune::Pulse()
{
    Stop();
    buffer.clear();
    int T = Format.sampleRate()/Freq;
    int HiCnt = T*Duty;
    int LoCnt = T-HiCnt;
    int Amp = 127*Volume;
    int HiVal = Amp + 128;
    int LoVal = 128-Amp;

    buffer.append(QByteArray(HiCnt,(uchar)HiVal));
    buffer.append(QByteArray(LoCnt,(uchar)LoVal));
}

void NChipTune::Pulse(int freq)
{
    Freq = freq;
    Pulse();
}

void NChipTune::Triangle()
{
    Stop();
    buffer.clear();
    int T = Format.sampleRate()/Freq;
    int halfT = T/2;

    int Amp = 127*Volume;
    int DAmp = Amp*2;
    int HiVal = Amp + 128;
    int LoVal = 128-Amp;

    for(int i = 0;i<halfT;i++){
        int v = LoVal + i*DAmp/halfT;
        buffer.append((uchar)v);
    }
    for(int i = 0;i<halfT;i++){
        int v = HiVal - i*DAmp/halfT;
        buffer.append((uchar)v);
    }
}

void NChipTune::Triangle(int freq)
{
    Freq = freq;
    Triangle();
}

void NChipTune::Sine()
{
    Stop();
    buffer.clear();
    int T = Format.sampleRate()/Freq;

    int Amp = 127*Volume;

    for(int i = 0;i<T;i++){
        int v = 128 + Amp*sin(M_PI*2*i/T);
        buffer.append((uchar)v);
    }
}

void NChipTune::Sine(int freq)
{
    Freq =freq;
    Sine();
}

void NChipTune::Noise()
{
    Stop();
    buffer.clear();
    int T = Format.sampleRate()/Freq;
    int Amp = 127*Volume;
    int DAmp = Amp*2;
    int HiVal = Amp + 128;
    int LoVal = 128-Amp;

    for(int j = 0;j<Freq;j++){
        int v = LoVal + qrand()%DAmp;
        for(int i = 0;i<T;i++){
            buffer.append((uchar)v);
        }
    }
}

void NChipTune::Noise(int freq)
{
    Freq = freq;
    Noise();
}

QString NChipTune::Print()
{
    QString str;
    foreach (auto b, buffer) {
        str += b;
        qDebug()<<(uchar)b;
    }
    return str;
}
