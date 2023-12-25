#include <QtMath>
#include "vchart/chart.h"
#include <QtWidgets/QGesture>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <vchart/chartview.h>

QT_CHARTS_USE_NAMESPACE

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    // Seems that QGraphicsView (QChartView) does not grab gestures.
    // They can only be grabbed here in the QGraphicsWidget (QChart).
    grabGesture(Qt::PanGesture);
    grabGesture(Qt::PinchGesture);
}

Chart::~Chart()
{

}


////////////////////////////////////////////////////////////////////Function for VChart

void Chart::setLinesIndexNext()
{
m_linesIndex++;
if(m_linesIndex>m_spline.count()||m_linesIndex>m_linesIndexMax)m_linesIndex=1;
m_spline[m_linesIndex-1]->clear();
}

void Chart::Init()
{
    this->chartInit(m_chartParameter,m_widget);
}


void Chart::Init(VParameter parameter,int lines, QWidget *widget)
{
    m_chartParameter = parameter;
    m_spline.clear();
    m_lines = lines;
    for(int i=0;i<lines;i++){
        m_spline.append(new QSplineSeries());
    }
    m_widget = widget;
    this->chartInit(m_chartParameter,m_widget);
}

void Chart::Graph(double val)
{
    this->Graph(val,m_linesIndex);
}

void Chart::Graph(double val, int lines)
{
    this->Graph(val,lines,m_scanType);
}

void Chart::chartInit(VParameter parameter,QWidget *widget)
{
    if(chartAxisX)delete chartAxisX;
    chartAxisX = new QValueAxis(this);
    if(chartAxisY)delete chartAxisY;
    chartAxisY = new QValueAxis(this);

    addAxis(chartAxisX,Qt::AlignBottom);
    addAxis(chartAxisY,Qt::AlignLeft);
    //Add pen for lines
    for(int i=0;i<m_spline.count();i++){
        QPen _pen;
        _pen.setWidth(3);
        _pen.setColor(listColor[i%listColor.count()]);
        m_spline[i]->setPen(_pen);
        //Add lines for chart
        addSeries(m_spline[i]);
        m_spline[i]->attachAxis(chartAxisX);
        m_spline[i]->attachAxis(chartAxisY);

    }
    chartAxisX->setTickCount(parameter.axisX_TickCount);
    chartAxisX->setRange(parameter.axisX_Range_Min, parameter.axisX_Range_Max);
    chartAxisX->setLabelsBrush(QColor("#b6b7b8"));
    chartAxisX->setLabelFormat("%u");

    chartAxisY->setTickCount(parameter.axisY_TickCount);
    chartAxisY->setRange(parameter.axisY_Range_Min, parameter.axisY_Range_Max);
    chartAxisY->setLabelFormat("%.1f");
    chartAxisY->setLabelsBrush(QColor("#b6b7b8"));
    legend()->hide();
    setBackgroundBrush(QColor("#0f1c23"));
    setBackgroundPen(QColor(Qt::cyan));

    if(m_chartView)delete m_chartView;
    m_chartView = new ChartView(this,widget);
    m_chartView->setGeometry(widget->geometry().x(),widget->geometry().y(),widget->width(),widget->height());
    //m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->show();
}


void Chart::Graph(double val, int lines, VScanType scan)
{
    if(lines==0||lines>m_spline.count())return;
    m_scanType = scan;
    //Calculator
    if(val>chartAxisY->max()-qFabs(val*0.1)){
        chartAxisY->setMax(val + qFabs(val*0.1));
    }
    if(val<chartAxisY->min()+qFabs(val*0.1)){
        chartAxisY->setMin(val - qFabs(val*0.1));
    }

    //Check SampleMax
    if(m_spline[lines-1]->count()>m_sampleMax)this->Clear();

    //Scan graph
    switch(scan){
    case scanScroll:this->graphScroll(val,lines);
        break;
    case scanCompact:this->graphCompact(val,lines);
        break;
    }
}

void Chart::Clear()
{
    this->chartClear();
}

void Chart::chartClear()
{
    chartAxisX->setRange(m_chartParameter.axisX_Range_Min,m_chartParameter.axisX_Range_Max);
    chartAxisY->setRange(m_chartParameter.axisY_Range_Min,m_chartParameter.axisY_Range_Max);
    chartAxisX->setTickCount(m_chartParameter.axisX_TickCount);
    chartAxisY->setTickCount(m_chartParameter.axisY_TickCount);
    for(int i=0;i<m_spline.count();i++){
        if(m_spline[i])m_spline[i]->clear();
    }
}

void Chart::graphScroll(double val,int lines)
{
    if(m_spline[lines-1]->count()<m_chartParameter.axisX_Range_Max){
        m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
    }
    else{
        m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
        scroll(m_spline[lines-1]->count()-chartAxisX->max(),0);
    }
}

void Chart::graphCompact(double val, int lines)
{
    if(m_spline[lines-1]->count()>chartAxisX->max())chartAxisX->setMax(m_spline[lines-1]->count());
    m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
}





////////////////////////////////////////////////////////////////////Event for gesture
//![1]
bool Chart::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent *>(event));
    return QChart::event(event);
}

bool Chart::gestureEvent(QGestureEvent *event)
{
    if (QGesture *gesture = event->gesture(Qt::PanGesture)) {
        QPanGesture *pan = static_cast<QPanGesture *>(gesture);
        QChart::scroll(-(pan->delta().x()), pan->delta().y());
    }

    if (QGesture *gesture = event->gesture(Qt::PinchGesture)) {
        QPinchGesture *pinch = static_cast<QPinchGesture *>(gesture);
        if (pinch->changeFlags() & QPinchGesture::ScaleFactorChanged)
            QChart::zoom(pinch->scaleFactor());
    }

    return true;
}
//![1]

