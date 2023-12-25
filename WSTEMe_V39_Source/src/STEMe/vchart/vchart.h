#ifndef VCHART_H
#define VCHART_H

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
#include <vchart/chart.h>
#include <vchart/chartview.h>

QT_CHARTS_USE_NAMESPACE

class VChart
{

public: //Properties

    struct VParameter{
        int axisX_TickCount = 11;
        int axisX_Range = 100;
        int axisY_TickCount = 11;
        int axisY_Range_Max = 2;
        int axisY_Range_Min = 0;
        int timerScan = 100;
    };
    enum VScanType{
        scroll,
        compact
    };

    //Properties of Axis X on charts
    inline int AxisX_TickCount() const{
        return m_chartAxisX->tickCount();
    }
    inline void setAxisX_TickCount(int tick){
        m_chartAxisX->setTickCount(tick);
    }
    inline qreal AxisX_Min() const{
        return m_chartAxisX->min();
    }
    inline qreal AxisX_Max() const{
        return m_chartAxisX->max();
    }
    inline void setAxisX_Min(qreal min){
        m_chartAxisX->setMin(min);
    }
    inline void setAxisX_Max(qreal max){
        m_chartAxisX->setMax(max);
    }
    inline void setAxisX_Range(qreal min,qreal max){
        m_chartAxisX->setRange(min,max);
    }


    //Properties of Axis Y on charts
    inline int AxisY_TickCount() const{
        return m_chartAxisY->tickCount();
    }
    inline void setAxisY_TickCount(int tick){
        m_chartAxisY->setTickCount(tick);
    }

    inline qreal AxisY_Min() const{
        return m_chartAxisY->min();
    }
    inline qreal AxisY_Max() const{
        return m_chartAxisY->max();
    }
    inline void setAxisY_Min(qreal min){
        m_chartAxisY->setMin(min);
    }
    inline void setAxisY_Max(qreal max){
        m_chartAxisY->setMax(max);
    }
    inline void setAxisY_Range(qreal min,qreal max){
        m_chartAxisY->setRange(min,max);
    }


    //Properties of charts
    inline int SampleMax() const{
        return m_sampleMax;
    }
    inline void setSampleMax(int max){
        m_sampleMax = max;
    }
    inline int ScanType() const{
        return m_scanType;
    }
    inline void setScanType(VChart::VScanType type){
        m_scanType = type;
    }


    //Properties of Lines on charts
    inline QList<QPointF> points(int lines) const{
        return m_spline[lines-1]->points();
    }
    inline QVector<QPointF> pointsVector(int lines) const{
        return m_spline[lines-1]->pointsVector();
    }
    inline QVector<double> vector(int lines) const{
        QVector<double>data;
        for(int i=0;i<m_spline[lines-1]->points().count();i++){
            data.append(m_spline[lines-1]->points().at(i).y());
        }
        return data;
    }
    inline int LinesIndex() const{
        return m_linesIndex;
    }
    inline void setLinesIndex(int index){
        m_linesIndex = index;
    }
    inline int Lines() const{
        return m_lines;
    }
    inline void setSplines(QSplineSeries* line, int i){
        m_chart->removeSeries(m_spline[i-1]);
        m_spline[i-1] = line;
        QPen _pen;
        _pen.setWidth(3);
        _pen.setColor(listColor[(i-1)%listColor.count()]);
        m_spline[i-1]->setPen(_pen);
        m_chart->addSeries(m_spline[i-1]);
    }

public:
    VChart();

    //List color for lines
    QList<QColor> listColor = {Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray};


    void setLines(int lines);
    void setLinesIndexNext();
    void Init();
    void Init(VChart::VParameter chartParameter,int lines, QWidget *widget);
    void Graph(double val);
    void Graph(double val,int lines);
    void Graph(double val,int lines,VScanType scan);
    void Clear();

private:
    ChartView       *m_chartView=nullptr;
    Chart           *m_chart=nullptr;
    QValueAxis      *m_chartAxisX=nullptr;
    QValueAxis      *m_chartAxisY=nullptr;


    VParameter m_chartParameter;
    QList<QSplineSeries*> m_spline;
    QWidget *m_widget=nullptr;

    VScanType m_scanType = VScanType::scroll;

    int m_lines=0;
    int m_linesIndex=1;
    int m_chartTimerInterval = 100;
    int m_chartTimerScan = 100;
    int m_sampleMax = 36000; //Run 1h with 10 samples/second


    void chartClear();
    void chartInit(VChart::VParameter chartParameter,QWidget *widget);
    void chartInits(VChart::VParameter chartParameter,QWidget *widget);
    void graphScroll(double val,int lines);
    void graphCompact(double val,int lines);
};

#endif // VCHART_H
