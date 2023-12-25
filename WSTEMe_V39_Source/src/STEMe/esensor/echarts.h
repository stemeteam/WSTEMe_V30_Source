#ifndef ECHARTS_H
#define ECHARTS_H
#include <QtMath>
#include <QtWidgets/QGesture>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QDebug>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
#include <QtCharts/QChart>

//User
#include <esensor/echartgesture.h>

class QGestureEvent;

QT_CHARTS_USE_NAMESPACE

//![1]
class ECharts : public QChart
//![1]
{
public:
    explicit ECharts(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    ~ECharts();


    struct Parameter{
        int axisX_TickCount = 6;
        qreal axisX_Range_Max = 100;
        qreal axisX_Range_Min = 0;
        int axisY_TickCount = 16;
        qreal axisY_Range_Max = 2;
        qreal axisY_Range_Min = 0;
        int timerScan = 100;
    };
    enum ScanType{
        scanScroll,
        scanCompact
    };

    //..........................................
    QValueAxis      *chartAxisX=nullptr;
    QValueAxis      *chartAxisY=nullptr;

    //Properties of charts
    inline Parameter parameter() const{
        return m_chartParameter;
    }
    inline void setParameter(Parameter p){
        m_chartParameter = p;
        chartAxisX->setRange(p.axisX_Range_Min,p.axisX_Range_Max);
        chartAxisY->setRange(p.axisY_Range_Min,p.axisY_Range_Max);
    }
    void setAxisX(qreal min,qreal max);
    void setAxisX_Max(qreal max);
    double axisX_Max(){return chartAxisX->max();}
    double axisX_Min(){return chartAxisX->min();}
    inline void setAxisY(qreal min,qreal max);
    inline void setAxisY_Max(qreal max);
    double axisY_Max(){return chartAxisY->max();}
    double axisY_Min(){return chartAxisY->min();}
    inline int sampleMax() const{
        return m_sampleMax;
    }
    inline void setSampleMax(int max){
        m_sampleMax = max;
    }
    inline int scanType() const{
        return m_scanType;
    }
    inline void setScanType(ScanType type){
        m_scanType = type;
    }

    //Properties of Lines on charts
    inline QVector<double> vector(int lines) const{
        QVector<double>data;
        for(int i=0;i<m_spline[lines-1]->count();i++){
            data.append(m_spline[lines-1]->at(i).y());
        }
        return data;
    }
    inline QVector<QPointF> lines(int line) const{
        QVector<QPointF> data;
        for(int i=0;i<m_spline[line-1]->count();i++){
            data.append(m_spline[line-1]->at(i));
        }
        return data;
    }

    inline int linesIndex() const{          //return max of lines on chart
        return m_linesIndex;
    }
    inline void setLinesIndex(int index){   //set max of lines on chart
        m_linesIndex = index;
    }
    inline int linesIndexMax() const{          //return max of lines on chart
        return m_linesIndexMax;
    }
    inline void setLinesIndexMax(int index){   //set max of lines on chart
        m_linesIndexMax = index;
    }
    inline int lines() const{       //return number of lines on chart
        return m_lines;
    }

    void setSplines(QSplineSeries* line, int i);

    //position
    QPointF getPositionMouse();
    QPointF getValueMouse(int line);

    //Color
    void replaceListLineColor(int index,QColor rgb){listColor.replace(index,rgb);}

    void setLinesIndexNext();
    void setPrecisionXY(int x, int y);
    void setTrackLine(EChartGesture::ETrackLine track);

    void setAxisXFormat(int f){m_axisXFormat = f;}
    void setAxisYFormat(int f){m_axisYFormat = f;}
    void setAxisXName(QString f){m_axisXName = f;}
    void setAxisYName(QString f){m_axisYName = f;}
    void setColorTextAxis_X(QColor color){m_textAxis_X=color;}
    void setColorTextAxis_Y(QColor color){m_textAxis_Y=color;}
    void init();
    void init(Parameter parameter,int lines, QWidget *widget);
    void init(Parameter parameter,QSplineSeries* lines , QWidget *widget);
    void init(Parameter parameter,QList<QSplineSeries*> lines , QWidget *widget);
    void graph(double val);
    void graph(double val,int lines);
    void graph(double val,int lines,ScanType scan);

    void graph(QPointF val);
    void graph(QPointF val,int lines);
    void graph(QPointF val,int lines,ScanType scan);

    void graph(QVector<QPointF> val);
    void graph(QVector<QPointF> val,int lines);
    void graph(QVector<QPointF> val,int lines,ScanType scan);
    void clear();

    //LineHelp
    void updateLineHelp(int x);

protected:
    bool sceneEvent(QEvent *event);

private:
    bool gestureEvent(QGestureEvent *event);

private:
    QList<QColor> listColor = {Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray,Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray};
    EChartGesture       *m_chartGesture=nullptr;


    QList<QSplineSeries*> m_spline;
    QSplineSeries *m_splineHelp;
    QWidget *m_widget=nullptr;


    ScanType m_scanType = ScanType::scanScroll;

    int m_lines=0;
    int m_linesIndexMax=1;
    int m_linesIndex=1;
    int m_chartTimerInterval = 100;
    int m_chartTimerScan = 100;
    int m_sampleMax = 36000; //Run 1h with 10 samples/second
    int m_axisXFormat=0;
    int m_axisYFormat=0;
    QString m_axisXName = "";
    QString m_axisYName = "";
    Parameter      m_chartParameter;
    QColor m_textAxis_X = QColor(0, 255, 0);
    QColor m_textAxis_Y = QColor(170, 255, 255);

    void chartClear();
    void chartInit(Parameter parameter,QWidget *widget);
    void chartInits(Parameter parameter,QWidget *widget);

    void graphScroll(double val,int lines);
    void graphCompact(double val,int lines);

    void graphScroll(QPointF val,int lines);
    void graphCompact(QPointF val,int lines);

    void graphScroll(QVector<QPointF> val,int lines);
    void graphCompact(QVector<QPointF> val,int lines);

};



#endif // ECHARTS_H
