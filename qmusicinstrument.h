#ifndef QMUSICINSTRUMENT_H
#define QMUSICINSTRUMENT_H

#include "qaudioplayer.h"
#include "nmuse.h"
#include "wavcontour.h"

class QMusicInstrument
{
public:
  QMusicInstrument();
  void Play(int index);
  void PlayChip();

  void Bass();
  void SideDrum();
  void Tomtom();
  void HighHat();

  void SetMode(QString mode);
  int GetModeNoteCount();

//private:

  NMuse music;
  WavContour contour;
  NChipTune chipTune;
  QAudioPlayer player;

};

#endif // QMUSICINSTRUMENT_H
