#ifndef CHART_H
#define CHART_H

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
#include <QtCharts/QChart>

//User
#include <vchart/chartview.h>

class QGestureEvent;

QT_CHARTS_USE_NAMESPACE

//![1]
class Chart : public QChart
//![1]
{
public:
    explicit Chart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    ~Chart();


    struct VParameter{
        int axisX_TickCount = 11;
        qreal axisX_Range_Max = 100;
        qreal axisX_Range_Min = 0;
        int axisY_TickCount = 11;
        qreal axisY_Range_Max = 2;
        qreal axisY_Range_Min = 0;
        int timerScan = 100;
    };
    enum VScanType{
        scanScroll,
        scanCompact
    };

    //..........................................
    QValueAxis      *chartAxisX=nullptr;
    QValueAxis      *chartAxisY=nullptr;

    //Properties of charts
    inline VParameter Parameter() const{
        return m_chartParameter;
    }
    inline void setParameter(VParameter p){
        m_chartParameter = p;
        chartAxisX->setRange(p.axisX_Range_Min,p.axisX_Range_Max);
        chartAxisY->setRange(p.axisY_Range_Min,p.axisY_Range_Max);
    }
    inline int SampleMax() const{
        return m_sampleMax;
    }
    inline void setSampleMax(int max){
        m_sampleMax = max;
    }
    inline int ScanType() const{
        return m_scanType;
    }
    inline void setScanType(VScanType type){
        m_scanType = type;
    }


    //Properties of Lines on charts
    inline QVector<double> vector(int lines) const{
        QVector<double>data;
        for(int i=0;i<m_spline[lines-1]->points().count();i++){
            data.append(m_spline[lines-1]->points().at(i).y());
        }
        return data;
    }
    inline int LinesIndex() const{          //return max of lines on chart
        return m_linesIndex;
    }
    inline void setLinesIndex(int index){   //set max of lines on chart
        m_linesIndex = index;
    }
    inline int LinesIndexMax() const{          //return max of lines on chart
        return m_linesIndexMax;
    }
    inline void setLinesIndexMax(int index){   //set max of lines on chart
        m_linesIndexMax = index;
    }
    inline int Lines() const{       //return number of lines on chart
        return m_lines;
    }
    inline void setSplines(QSplineSeries* line, int i){
        removeSeries(m_spline[i-1]);
        m_spline[i-1] = line;
        QPen _pen;
        _pen.setWidth(3);
        _pen.setColor(listColor[(i-1)%listColor.count()]);
        m_spline[i-1]->setPen(_pen);
        addSeries(m_spline[i-1]);
    }




    void setLinesIndexNext();
    void Init();
    void Init(VParameter parameter,int lines, QWidget *widget);
    void Graph(double val);
    void Graph(double val,int lines);
    void Graph(double val,int lines,VScanType scan);
    void Clear();

protected:
    bool sceneEvent(QEvent *event);

private:
    bool gestureEvent(QGestureEvent *event);

private:
    QList<QColor> listColor = {Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray};
    ChartView       *m_chartView=nullptr;


    QList<QSplineSeries*> m_spline;
    QWidget *m_widget=nullptr;

    VScanType m_scanType = VScanType::scanScroll;

    int m_lines=0;
    int m_linesIndexMax=1;
    int m_linesIndex=1;
    int m_chartTimerInterval = 100;
    int m_chartTimerScan = 100;
    int m_sampleMax = 36000; //Run 1h with 10 samples/second
    VParameter      m_chartParameter;

    void chartClear();
    void chartInit(VParameter parameter,QWidget *widget);
    void chartInits(VParameter parameter,QWidget *widget);
    void graphScroll(double val,int lines);
    void graphCompact(double val,int lines);

};


#endif // CHART_H
