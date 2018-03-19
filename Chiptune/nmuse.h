#ifndef NMUSIC_H
#define NMUSIC_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class NMuse
{
public:
    NMuse();
    void Init(int base = 261.62557,int div = 12);
    void LoadModeFile(string fileName);
    vector<string> GetModes();

    int Pitch(int index);
    int TunePitch(int index);

    void SetMode(string modeName = "Ionian");

    int TuneCount();

private:
    int baseFreq = 440;
    float step = 1.0594630943592953;
    vector<int> datas;
    vector<int> tuneMode;
};

#endif // NMUSIC_H
