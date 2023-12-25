#ifndef ECHARTGESTURE_H
#define ECHARTGESTURE_H

#include <QtCharts/QChartView>
#include <QtWidgets/QRubberBand>
#include <QtGui/QMouseEvent>
#include <QtCharts/QSplineSeries>
#include <QWheelEvent>
#include <echart/ecallout.h>
#include <echart/crosshairs.h>

QT_CHARTS_USE_NAMESPACE

//![1]
class EChartGesture : public QChartView
//![1]
{
public:
    EChartGesture(QChart *chart, QWidget *parent = nullptr);

    struct EMouseEvent{
        QPointF value;
        QPointF position;
    };
    enum ETrackLine{
        ETL_default,
        ETL_tooltip,
        ETL_y_ax
    };

    //
    inline QPointF getWidgetPos(){return m_widgetPos;}
    inline QPointF getPositionMouse(){return m_positionMouse;}
    inline EMouseEvent emouseEvent(){return m_emouseEvent;}
    void setTrackLine(ETrackLine track);
    void setPrecisionXY(int x, int y){m_pre_X=x;m_pre_Y=y;}
    void clearTrackLine();
public slots:
    void keepCallout();
    void tooltip(QPointF point, bool state);
//![2]
protected:
    bool viewportEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);
    void resizeEvent(QResizeEvent *event);
//![2]

private:
    bool m_isTouching;
    QPointF m_positionMouse={0,0};
    QPointF m_widgetPos={0,0};
    int m_seriesIndex=0;
    EMouseEvent m_emouseEvent;
    ETrackLine m_etrackLine = ETL_default;
//For Ecallout
private:
    ECallout *m_tooltip=nullptr;
    QList<ECallout *> m_callouts;
    Crosshairs *m_crosshairs=nullptr;
    int m_pre_X=3,m_pre_Y=3;

    int getMax(int x,int y);
};


#endif // ECHARTGESTURE_H
