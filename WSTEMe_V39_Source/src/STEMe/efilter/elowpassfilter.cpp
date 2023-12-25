#include "elowpassfilter.h"
#define ERROR_CHECK (true)

#if ERROR_CHECK
#include <QDebug>
#endif

ELowPassFilter::ELowPassFilter():output(0),ePow(0){}

ELowPassFilter::ELowPassFilter(double iCutOffFrequency, double iDeltaTime):
    output(0),
    ePow(1-exp(-iDeltaTime * 2 * M_PI * iCutOffFrequency))
{
    #if ERROR_CHECK
    if (iDeltaTime <= 0){
        qDebug() << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
        ePow = 0;
    }
    if(iCutOffFrequency <= 0){
        qDebug() << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
        ePow = 0;
    }
    #endif
}

double ELowPassFilter::update(double input){
    return output += (input - output) * ePow;
}

double ELowPassFilter::update(double input, double deltaTime, double cutoffFrequency){
    reconfigureFilter(deltaTime, cutoffFrequency); //Changes ePow accordingly.
    return output += (input - output) * ePow;
}

double ELowPassFilter::update(double input, double deltaTime, double cutoffFrequency, ELowPassFilter::FilterType type)
{
this->setFilterType(type);
    return this->update(input,deltaTime,cutoffFrequency);
}

void ELowPassFilter::reconfigureFilter(double deltaTime, double cutoffFrequency){
    #if ERROR_CHECK
    if (deltaTime <= 0){
        qDebug() << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
        ePow = 0;
    }
    if(cutoffFrequency <= 0){
        qDebug() << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
        ePow = 0;
    }
    #endif
    switch (m_filterType) {
    case filter_lpf:ePow = 1-exp(-deltaTime * 2 * M_PI * cutoffFrequency);
        break;
    case filter_hpf:ePow = cutoffFrequency/(2 * M_PI *deltaTime);
        break;
    }
}

