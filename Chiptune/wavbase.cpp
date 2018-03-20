#include "wavbase.h"
#include <stdexcept>

using namespace std;

#define rnd(n) (rand()%(n+1))

#define PI 3.14159265f

float WavBase::duty = 0.5f;

float frnd2(float range)
{
    return (float)rnd(10000)/10000*range;
}

static float noise_buffer[32];

WavBase::WavBase()
{

}

void WavBase::randomNoise()
{
  for(int i=0;i<32;i++)
      noise_buffer[i]=frnd2(2.0f)-1.0f;
}

float WavBase::wave(int type, float phase)
{
  float tmpSample = 0;
  switch(type)
  {
  case 0: // square
      if(phase<duty)
          tmpSample=0.5f;
      else
          tmpSample=-0.5f;
      break;
  case 1: // sawtooth
      tmpSample=1.0f-phase*2;
      break;
  case 2: // sine
      tmpSample=(float)sin(phase*2*PI);
      break;
  case 3: // noise
      int i = (int)(phase*(float)(32));
      if(i>31){
          i = 31;
        }
      tmpSample=noise_buffer[i];
      break;
  }
  return tmpSample;
}

void WavBase::DutyQuality()
{
  if(duty>0.5f)duty = 0.5f;
  if(duty<0.0f)duty =0.0f;
}
