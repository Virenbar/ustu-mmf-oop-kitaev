#include "trapezioidwavegenerator.h"

TrapezioidWaveGenerator::TrapezioidWaveGenerator(){
    _DescrFreq = 1;      /// Частота дискретизации 1000 Гц
    _Frequency = 0.02;        /// Частота сигнала по-умолчанию 50 Гц
    _Amplitude = 1.0;         /// Амлитуда сигнала
    _Offset = 0.0;            /// Метод задания фазы
    SetRiseTime(0.3);     /// Время нарастания [c]
    SetFallTime(0.04);     /// Время спада [c]
    SetPeakTime(0.05);     /// Время пика [c]
    _Time = 10;
    _value = 0.0;
    _CurrentPhase = 0; /// изначальнно фаза в нуле
}

//public signalgenerator
double TrapezioidWaveGenerator::GetSample(){ ///метод получения последующего сэмпла от генератора

    switch (_CurrentPhase){
        case 0:
            _value = (-_Amplitude)*(1.0-_Time*_InverseRiseTime)+_Amplitude*(_Time*_InverseRiseTime);

        /*старый кусочег
        case 0: ///нарастание
            _value = (-_Amplitude)*(1.0-_Time*_InverseRiseTime)+_Amplitude*(_Time*_InverseRiseTime); /// формулка для кривой безье по двум точкам
            if(_Time > _RiseTime){
                _CurrentPhase = 1;
                _Time -= _RiseTime; 
            }
            return _value;
            break;

        case 1: ///верхний пик
            _value = _Amplitude;
            if(_Time > _PeakTime){
                _CurrentPhase = 2;
                _Time -= _PeakTime;
            }
            return _value;
            break;

        case 2: ///спад
            _value = _Amplitude*(1.0-_Time*_InverseFallTime)-_Amplitude*(_Time*_InverseFallTime);
            if(_Time>_FallTime){
                _CurrentPhase = 3;
                _Time -= _FallTime;
            }
            return _value;
            break;

        case 3: ///нижний пик
            default:
            _value = -_Amplitude;
            if(_Time>(1.0/_Frequency)-_RiseTime-_PeakTime-_FallTime){
                _CurrentPhase = 0;
                _Time -= (1.0/_Frequency)-_RiseTime-_PeakTime-_FallTime;
            }
            return _value;
            break;
            */
    }
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFrequency(double iFrequency){ /// метод задания частоты генерируемого сигнала
    if (iFrequency<=0) {
        return BadValue;
    }
    _Frequency = iFrequency;
    return Success;
}

void TrapezioidWaveGenerator::SetAmplitude(double iAmplitude){ /// метод задания амплитуды генерируемого сигнала
    _Amplitude = iAmplitude;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetOffset(double iOffset){ /// метод задания сдвига фазы относительно начала отсчёта по времени
    if (iOffset<0) {
        return BadValue;
    }
    _Offset = iOffset;
    return Success;
}

void TrapezioidWaveGenerator::ResetPosition(){ /// метод сброса текущего времени
}

SignalGenerator::Result TrapezioidWaveGenerator::SetDiscretizationFrequency(int iDescrFreq){ /// метод задания частоты дискретизации сигнала
    if (iDescrFreq<=0) {
        return BadValue;
    }
    _DescrFreq = iDescrFreq;
    return Success;
}

///public trapezioidwavegenerator
SignalGenerator::Result TrapezioidWaveGenerator::SetRiseTime(double iRiseTime){ /// Время нарастания сигнала (обратная величина)
    if (iRiseTime<=0) {
        return BadValue;
    }

    _RiseTime =  iRiseTime;
    _InverseRiseTime = 1.0/_FallTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetFallTime(double iFallTime){ /// Время спада сигнала (обратная величина)
    if (iFallTime<=0) {
        return BadValue;
    }

    _FallTime =  iFallTime;
    _InverseFallTime = 1.0/_FallTime;
    return Success;
}

SignalGenerator::Result TrapezioidWaveGenerator::SetPeakTime(double iPeakTime){ ///время на пике
    if (iPeakTime<=0) {
        return BadValue;
    }
    _PeakTime = iPeakTime;
    return Success;
}