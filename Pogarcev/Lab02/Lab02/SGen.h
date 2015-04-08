﻿#ifndef SINGEN_H
#define SINGEN_H

#include "signalgenerator.h"

class SGen : public SignalGenerator
{
public:
    SGen();
    double GetSample();
    void SetFrequency(double iFrequency);
    void SetAmplitude(double iAmplitude);
    void SetOffset(double iOffset);
    void ResetPosition(void);
    void SetDiscretizationFrequency(int iDiscrFreq);

protected:
    double
        _Amplitude,
        _Frequency,
        _PhaseShift;
    int
        _Pos,
        _DiscrFreq;
};

#endif // SINGEN_H
