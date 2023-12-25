#include "echarts.h"


QT_CHARTS_USE_NAMESPACE

ECharts::ECharts(QGraphicsItem *parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    // Seems that QGraphicsView (QChartView) does not grab gestures.
    // They can only be grabbed here in the QGraphicsWidget (QChart).
    grabGesture(Qt::PanGesture);
    grabGesture(Qt::PinchGesture);
}

ECharts::~ECharts()
{

}

void ECharts::setAxisX(qreal min, qreal max)
{
m_chartParameter.axisX_Range_Min=min;
m_chartParameter.axisX_Range_Max=max;
chartAxisX->setRange(m_chartParameter.axisX_Range_Min,m_chartParameter.axisX_Range_Max);
}

void ECharts::setAxisX_Max(qreal max)
{
    m_chartParameter.axisX_Range_Max=max;
    chartAxisX->setRange(m_chartParameter.axisX_Range_Min,m_chartParameter.axisX_Range_Max);
}

void ECharts::setAxisY(qreal min, qreal max)
{
    m_chartParameter.axisY_Range_Min=min;
    m_chartParameter.axisY_Range_Max=max;
    chartAxisY->setRange(m_chartParameter.axisY_Range_Min,m_chartParameter.axisY_Range_Max);
}

void ECharts::setAxisY_Max(qreal max)
{
    m_chartParameter.axisY_Range_Max=max;
    chartAxisY->setRange(m_chartParameter.axisY_Range_Min,m_chartParameter.axisY_Range_Max);
}

void ECharts::setSplines(QSplineSeries *line, int i)
{
    if(!m_spline[i-1])return;
    if(m_chartGesture)
        {
      //  disconnect(m_spline[i-1], &QSplineSeries::clicked, m_chartGesture, &EChartGesture::keepCallout);
        disconnect(m_spline[i-1], &QSplineSeries::hovered, m_chartGesture, &EChartGesture::tooltip);
        }
    removeSeries(m_spline[i-1]);
    m_spline[i-1] = line;
    QPen _pen;
    _pen.setWidth(3);
    _pen.setColor(listColor[(i-1)%listColor.count()]);
    m_spline[i-1]->setPen(_pen);
    addSeries(m_spline[i-1]);
    if(chartAxisX)m_spline[i-1]->attachAxis(chartAxisX);
    if(chartAxisY)m_spline[i-1]->attachAxis(chartAxisY);
    if(m_chartGesture)
        {
      //  connect(m_spline[i-1], &QSplineSeries::clicked, m_chartGesture, &EChartGesture::keepCallout);
        connect(m_spline[i-1], &QSplineSeries::hovered, m_chartGesture, &EChartGesture::tooltip);
        }
}

QPointF ECharts::getPositionMouse()
{
    QPointF p(0,0);
    if(m_chartGesture)return m_chartGesture->getPositionMouse();
    else return p;
}

QPointF ECharts::getValueMouse(int line)
{
    if(line<1||line>12)return QPointF(0,0);;
    if(m_spline[line-1]){
        auto const scenePos = mapToScene(QPoint(static_cast<int>(m_chartGesture->getWidgetPos().x()), static_cast<int>(m_chartGesture->getWidgetPos().y())));
        auto const chartItemPos = this->mapFromScene(scenePos);
        return this->mapToValue(chartItemPos,m_spline[line-1]);
    }
    else return QPointF(0,0);
}

////////////////////////////////////////////////////////////////////Function for VChart

void ECharts::setLinesIndexNext()
{
m_linesIndex++;
if(m_linesIndex>m_spline.count()||m_linesIndex>m_linesIndexMax)m_linesIndex=1;
m_spline[m_linesIndex-1]->clear();
}

void ECharts::setPrecisionXY(int x, int y)
{
    if(m_chartGesture)m_chartGesture->setPrecisionXY(x,y);
}

void ECharts::setTrackLine(EChartGesture::ETrackLine track)
{
    if(m_chartGesture)m_chartGesture->setTrackLine(track);
}

void ECharts::init()
{
    this->chartInit(m_chartParameter,m_widget);
}


void ECharts::init(Parameter parameter,int lines, QWidget *widget)
{
    m_chartParameter = parameter;
    m_spline.clear();
    m_lines = lines;
    for(int i=0;i<lines;i++){
        m_spline.append(new QSplineSeries());
    }
    m_splineHelp = new QSplineSeries();
    m_widget = widget;
    this->chartInit(m_chartParameter,m_widget);
}

void ECharts::init(ECharts::Parameter parameter, QSplineSeries *lines, QWidget *widget)
{
    m_chartParameter = parameter;
    m_spline.clear();
    m_lines = 1;
    m_spline.append(lines);
    m_splineHelp = new QSplineSeries();
    m_widget = widget;
    this->chartInit(m_chartParameter,m_widget);
}

void ECharts::init(ECharts::Parameter parameter, QList<QSplineSeries*> lines, QWidget *widget)
{
    m_chartParameter = parameter;
    m_spline.clear();
    m_lines = lines.count();
    m_spline = lines;
    m_splineHelp = new QSplineSeries();
    m_widget = widget;
    this->chartInit(m_chartParameter,m_widget);
}



void ECharts::chartInit(Parameter parameter,QWidget *widget)
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
    QPen _hpen;
    _hpen.setWidth(1);
    _hpen.setColor(Qt::white);
    m_splineHelp->setPen(_hpen);
    addSeries(m_splineHelp);
    m_splineHelp ->attachAxis(chartAxisX);
    m_splineHelp ->attachAxis(chartAxisY);


    chartAxisX->setTickCount(parameter.axisX_TickCount);
    chartAxisX->setRange(parameter.axisX_Range_Min, parameter.axisX_Range_Max);
    //chartAxisX->setLabelsBrush(QColor("#b6b7b8"));
    chartAxisX->setTitleText(m_axisXName);
    chartAxisX->setTitleBrush(QColor("#FFFFFF"));
    chartAxisX->setLabelsBrush(m_textAxis_X);
    switch (m_axisXFormat) {
    case 0:chartAxisY->setLabelFormat("%.0f");
        break;
    case 1:chartAxisX->setLabelFormat("%.1f");
        break;
    case 2:chartAxisX->setLabelFormat("%.2f");
        break;
    case 3:chartAxisX->setLabelFormat("%.3f");
        break;
    }
    chartAxisX->setGridLineVisible(false);

    chartAxisY->setTickCount(parameter.axisY_TickCount);
    chartAxisY->setRange(parameter.axisY_Range_Min, parameter.axisY_Range_Max);
    chartAxisY->setTitleText(m_axisYName);
    chartAxisY->setTitleBrush(QColor("#FFFFFF"));
    switch (m_axisYFormat) {
    case 0:chartAxisY->setLabelFormat("%.0f");
        break;
    case 1:chartAxisY->setLabelFormat("%.1f");
        break;
    case 2:chartAxisY->setLabelFormat("%.2f");
        break;
    case 3:chartAxisY->setLabelFormat("%.3f");
        break;
    }
    //chartAxisY->setLabelsBrush(QColor("#b6b7b8"));
    chartAxisY->setLabelsBrush(m_textAxis_Y);
    QPen _gridPen;
    _gridPen.setWidth(1);
    _gridPen.setColor(Qt::gray);
    chartAxisY->setGridLinePen(_gridPen);
    legend()->hide();
    setBackgroundBrush(QColor("#0f1c23"));
    setBackgroundPen(QColor(Qt::cyan));
    setAnimationOptions(AnimationOption::NoAnimation);
    chartAxisX->setLabelsAngle(-90);
    m_widget = widget;
    if(!m_chartGesture)m_chartGesture = new EChartGesture(this,widget);
    m_chartGesture->setGeometry(0,0,widget->width(),widget->height());

    //m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartGesture->show();
    for(int i=0;i<m_spline.count();i++){
      //  connect(m_spline[i], &QSplineSeries::clicked, m_chartGesture, &EChartGesture::keepCallout);
        connect(m_spline[i], &QSplineSeries::hovered, m_chartGesture, &EChartGesture::tooltip);
    }
}

void ECharts::graph(double val)
{
    this->graph(val,m_linesIndex);
}

void ECharts::graph(double val, int lines)
{
    this->graph(val,lines,m_scanType);
}

void ECharts::graph(double val, int lines, ScanType scan)
{
    if(lines==0||lines>m_spline.count())return;
    m_scanType = scan;
    //Calculator
    if(val>chartAxisY->max()-qFabs(val*0.3)){
        chartAxisY->setMax(val + qFabs(val*0.3));
    }
    if(val<chartAxisY->min()+qFabs(val*0.3)){
        chartAxisY->setMin(val - qFabs(val*0.3));
    }
    //Check SampleMax
    if(m_spline[lines-1]->count()>m_sampleMax)this->clear();
    //Scan graph
    switch(scan){
    case scanScroll:this->graphScroll(val,lines);
        //this->graphScroll();
        break;
    case scanCompact:this->graphCompact(val,lines);
        //this->graphCompact();
        break;
    }
}

void ECharts::graph(QPointF val)
{
    this->graph(val,m_linesIndex);
}

void ECharts::graph(QPointF val, int lines)
{
    this->graph(val,lines,m_scanType);
}

void ECharts::graph(QPointF val, int lines, ECharts::ScanType scan)
{
    if(lines==0||lines>m_spline.count())return;
    m_scanType = scan;
    //Calculator
    if(val.y()>chartAxisY->max()-qFabs(val.y()*0.3)){
        chartAxisY->setMax(val.y() + qFabs(val.y()*0.3));
    }
    if(val.y()<chartAxisY->min()+qFabs(val.y()*0.3)){
        chartAxisY->setMin(val.y() - qFabs(val.y()*0.3));
    }
    //Scan graph
    switch(scan){
    case scanScroll:this->graphScroll(val,lines);
        //this->graphScroll();
        break;
    case scanCompact:this->graphCompact(val,lines);
        //this->graphCompact();
        break;
    }
}

void ECharts::graph(QVector<QPointF> val)
{
    this->graph(val,m_linesIndex);
}

void ECharts::graph(QVector<QPointF> val, int lines)
{
    this->graph(val,lines,m_scanType);
}

void ECharts::graph(QVector<QPointF> val, int lines, ECharts::ScanType scan)
{
    qreal _max=-99999999999,_min=999999999999;
    if(lines==0||lines>m_spline.count())return;
    m_scanType = scan;
    //Calculator
    foreach(QPointF c,val){
        if(c.y()>_max)_max=c.y();
        if(c.y()<_min)_min=c.y();
    }
    if(_max>chartAxisY->max()-qFabs(_max*0.3)){
        chartAxisY->setMax(_max + qFabs(_max*0.3));
    }
    if(_min<chartAxisY->min()+qFabs(_min*0.3)){
        chartAxisY->setMin(_min - qFabs(_min*0.3));
    }
    //Check SampleMax
    if(m_spline[lines-1]->count()>m_sampleMax)this->clear();
    //Scan graph
    switch(scan){
    case scanScroll:this->graphScroll(val,lines);
        //this->graphScroll();
        break;
    case scanCompact:this->graphCompact(val,lines);
        //this->graphCompact();
        break;
    }
}

void ECharts::clear()
{
    this->chartClear();
}

void ECharts::chartClear()
{
    chartAxisX->setRange(m_chartParameter.axisX_Range_Min,m_chartParameter.axisX_Range_Max);
    chartAxisY->setRange(m_chartParameter.axisY_Range_Min,m_chartParameter.axisY_Range_Max);
    chartAxisX->setTickCount(m_chartParameter.axisX_TickCount);
    chartAxisY->setTickCount(m_chartParameter.axisY_TickCount);
    for(int i=0;i<m_spline.count();i++){
        if(m_spline[i])m_spline[i]->clear();
    }
    m_chartGesture->clearTrackLine();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void ECharts::graphScroll(double val,int lines)
{
    if(m_spline[lines-1]->count()<m_chartParameter.axisX_Range_Max){
        m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
    }
    else{
        for(int i=0;i<m_spline[lines-1]->count()-1;i++){
            m_spline[lines-1]->replace(i,m_spline[lines-1]->at(i).x(),m_spline[lines-1]->at(i+1).y());
        }
        m_spline[lines-1]->replace(m_spline[lines-1]->count()-1,m_spline[lines-1]->at(m_spline[lines-1]->count()-1).x(),val);
    }
}

void ECharts::graphCompact(double val, int lines)
{
    if(m_spline[lines-1]->count()>chartAxisX->max())chartAxisX->setMax(m_spline[lines-1]->count());
    m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void ECharts::graphScroll(QPointF val, int lines)
{
    if(m_spline[lines-1]->at(m_spline[lines-1]->count()-1).x()<m_chartParameter.axisX_Range_Max){
        m_spline[lines-1]->append(val.x(),val.y());
    }
    else{
        for(int i=0;i<m_spline[lines-1]->count()-1;i++){
            m_spline[lines-1]->replace(i,m_spline[lines-1]->at(i).x(),m_spline[lines-1]->at(i+1).y());
        }
        m_spline[lines-1]->replace(m_spline[lines-1]->count()-1,m_spline[lines-1]->at(m_spline[lines-1]->count()-1).x(),val.y());
    }
}
void ECharts::graphCompact(QPointF val, int lines)
{
    m_spline[lines-1]->append(val.x(),val.y());
    if(m_spline[lines-1]->at(m_spline[lines-1]->count()-1).x()>chartAxisX->max())chartAxisX->setMax(m_spline[lines-1]->at(m_spline[lines-1]->count()-1).x());
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void ECharts::graphScroll(QVector<QPointF> val, int lines)
{
    for(int i=0;i<val.count();i++){
        m_spline[lines-1]->append(val.at(i).x(),val.at(i).y());
    }
}

void ECharts::graphCompact(QVector<QPointF> val, int lines)
{
    for(int i=0;i<val.count();i++){
        m_spline[lines-1]->append(val.at(i).x(),val.at(i).y());
    }
}

void ECharts::updateLineHelp(int x)
{
    if(m_splineHelp->count()==0){
        m_splineHelp->append(QVariant(x).toDouble(),0);
        m_splineHelp->append(QVariant(x).toDouble(),chartAxisY->max());
    }
    else{
        m_splineHelp->replace(0,QVariant(x).toDouble(),0);
        m_splineHelp->replace(1,QVariant(x).toDouble(),chartAxisY->max());
    }
}

////////////////////////////////////////////////////////////////////Event for gesture
//![1]
bool ECharts::sceneEvent(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
        return gestureEvent(static_cast<QGestureEvent *>(event));
    return QChart::event(event);
}


bool ECharts::gestureEvent(QGestureEvent *event)
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

