#ifndef SIGNALMIXER_H
#define SIGNALMIXER_H

#include <vector>
#include <QWidget>

#include "signalgen.h"

class QDial;

class SignalMixer : public QWidget, public SignalGen
{
    Q_OBJECT
public:
    explicit SignalMixer(QWidget *iParent = 0);
    virtual double GetSample(void);                 // метод получения последующего сэмпла от генератора
    virtual void SetFrequency(double iFrequency){}  // метод задания частоты генерируемого сигнала
    virtual void SetAmplitude(double iAmplitude){}  // метод задания амплитуды генерируемого сигнала
    virtual void SetOffset(double iOffset){}        // метод задания сдвига фазы относительно начала отсчёта по времени
    virtual void ResetPosition();                   // метод сброса текущего времени
    virtual void SetDiscrFrequency(int iDescrFreq); // метод задания частоты дискретизации сигнала

    //Добавление источника
    bool AddSource(SignalGen *iSource);
    //Удаление источника
    bool RemoveSource(SignalGen *iSource);
    //Проверка на наличие источника
    bool CheckSource(SignalGen *iSource);

private:
    //Источники
    std::vector<SignalGen*> sources;
    QDial *masterDial;
    double masterAmp;
private slots:
    void DialValueChange(int value);

};

#endif // SIGNALMIXER_H