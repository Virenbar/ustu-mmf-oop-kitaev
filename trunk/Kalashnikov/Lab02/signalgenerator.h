#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

class SignalGenerator
{
public:
    SignalGenerator(){};
    virtual double GetSample(void) = 0; //метод получения последующего сэмпла от генератора
    virtual void SetFrequency(double iFrequency) = 0; // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude) = 0; // метод задания амплитуды генерируемого сигнала
    virtual void SetOffset(double iOffset) = 0; // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition(void) = 0; // метод сброса текущего времени
    virtual void SetDiscretizationFrequency(int iDescrFreq) = 0; // метод задания частоты дискретизации сигнала
};

#endif // SIGNALGENERATOR_H
