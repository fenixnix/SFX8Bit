#include "nmusic.h"
#include "qmath.h"

NMusic::NMusic()
{
    Div();
}

int NMusic::tune(int degree)
{
    baseFreq*pow(step,degree);
}

int NMusic::NoteFreq(string note)
{

}

int NMusic::Note(int index)
{
  int i = index%datas.size();
  int d = index/datas.size();
  return datas[i]*pow(2,d);
}

void NMusic::Div(int base, int div)
{
  baseFreq = base;
  step = pow(2.0f,1.0f/(float)div);
  datas.clear();
  for(int i = 0;i<div;i++){
      datas.push_back(baseFreq*pow(step,i));
    }
}
