#ifndef NCHIPTUNE_H
#define NCHIPTUNE_H

#include <QIODevice>
#include <QAudioFormat>
#include <QDebug>
#include <qmath.h>

class NChipTune: public QIODevice
{
public:
    NChipTune();

    void Start();
    void Stop();

    qint64 readData(char *data, qint64 maxlen) override;
    qint64 writeData(const char *data, qint64 len) override;
    qint64 bytesAvailable() const override;

    void generateData(const QAudioFormat &format, qint64 durationUs, int sampleRate);

    void Pulse();//12.5% 25% 50%
    void Pulse(int freq);
    void Triangle();
    void Triangle(int freq);
    void Sine();
    void Sine(int freq);
    void Noise();
    void Noise(int freq);
    QString Print();

    float Duty = 0.5f;//0~0.5
    int Freq = 440;//200~10000
    float Volume = 0.6f;//0~1

    QAudioFormat Format;

private:

    QByteArray buffer;
    qint64 m_pos;
};

#endif // NCHIPTUNE_H
