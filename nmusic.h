#ifndef NMUSIC_H
#define NMUSIC_H

#include <string>
#include <vector>

using namespace std;

class NMusic
{
public:
    NMusic();

    int tune(int degree);

    int NoteFreq(string note);
    int Note(int index);
    void Div(int base = 440,int div = 12);

private:
    int baseFreq = 440;
    float step = 1.0594630943592953;
    vector<int> datas;
};

#endif // NMUSIC_H
