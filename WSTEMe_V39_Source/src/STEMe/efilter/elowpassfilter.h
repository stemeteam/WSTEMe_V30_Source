#ifndef ELOWPASSFILTER_H
#define ELOWPASSFILTER_H
#include <QtMath>
#include <QPointF>
#include <QtMath>

class ELowPassFilter
{
public:
    ELowPassFilter();
    ELowPassFilter(double iCutOffFrequency, double iDeltaTime);
    enum FilterType{
        filter_lpf,
        filter_hpf
    };
    //properties
    inline void setFilterType(FilterType type){m_filterType = type;}
    //functions
    double update(double input);
    double update(double input, double deltaTime, double cutoffFrequency);
    double update(double input, double deltaTime, double cutoffFrequency,FilterType type);
    //get and configure funtions
    double getOutput() const{return output;}
    void reconfigureFilter(double deltaTime, double cutoffFrequency);
    void setOutput(double out){output = out;}

private:
    double output;
    double ePow;
    FilterType m_filterType=filter_lpf;


};

#endif // ELOWPASSFILTER_H
