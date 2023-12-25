#include "vchart.h"
#include <QWidget>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QtMath>

//chart
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE


VChart::VChart()
{

}


void VChart::setLinesIndexNext()
{
m_linesIndex++;
if(m_linesIndex>m_spline.count())m_linesIndex=1;
m_spline[m_linesIndex-1]->clear();
}

void VChart::Init()
{
    this->chartInit(m_chartParameter,m_widget);
}



void VChart::setLines(int lines)
{
this->Init(m_chartParameter,lines,m_widget);
}

void VChart::Init(VChart::VParameter chartParameter,int lines, QWidget *widget)
{
    m_chartParameter = chartParameter;
    m_spline.clear();
    m_lines = lines;
    for(int i=0;i<lines;i++){
        m_spline.append(new QSplineSeries());
    }
    m_widget = widget;
    this->chartInit(chartParameter,m_widget);
}

void VChart::Graph(double val)
{
    this->Graph(val,m_linesIndex);
}

void VChart::Graph(double val, int lines)
{
    this->Graph(val,lines,m_scanType);
}

void VChart::chartInit(VChart::VParameter chartParameter,QWidget *widget)
{
    if(m_chart)delete m_chart;
    m_chart = new Chart();
    //m_chart.set

    if(m_chartAxisX)delete m_chartAxisX;
    m_chartAxisX = new QValueAxis(m_chart);
    if(m_chartAxisY)delete m_chartAxisY;
    m_chartAxisY = new QValueAxis(m_chart);

    m_chart->addAxis(m_chartAxisX,Qt::AlignBottom);
    m_chart->addAxis(m_chartAxisY,Qt::AlignLeft);
    //Add pen for lines
    for(int i=0;i<m_spline.count();i++){
        QPen _pen;
        _pen.setWidth(3);
        _pen.setColor(listColor[i%listColor.count()]);
        m_spline[i]->setPen(_pen);
        //Add lines for chart
        m_chart->addSeries(m_spline[i]);
        m_spline[i]->attachAxis(m_chartAxisX);
        m_spline[i]->attachAxis(m_chartAxisY);

    }

    m_chartAxisX->setTickCount(chartParameter.axisX_TickCount);
    m_chartAxisX->setRange(0, chartParameter.axisX_Range);
    m_chartAxisX->setLabelsBrush(QColor("#b6b7b8"));
    m_chartAxisX->setLabelFormat("%u");

    m_chartAxisY->setTickCount(chartParameter.axisY_TickCount);
    m_chartAxisY->setRange(chartParameter.axisY_Range_Min, chartParameter.axisY_Range_Max);
    m_chartAxisY->setLabelFormat("%.1f");
    m_chartAxisY->setLabelsBrush(QColor("#b6b7b8"));
    m_chart->legend()->hide();
    m_chart->setBackgroundBrush(QColor("#0f1c23"));
    m_chart->setBackgroundPen(QColor(Qt::cyan));

    if(m_chartView)delete m_chartView;
    m_chartView = new ChartView(m_chart,widget);
    m_chartView->setGeometry(widget->geometry().x(),widget->geometry().y(),widget->width(),widget->height());
    //m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->show();
}


void VChart::Graph(double val, int lines, VChart::VScanType scan)
{
    if(lines==0||lines>m_spline.count())return;
    m_scanType = scan;
    //Calculator
    if(val>m_chartAxisY->max()-qFabs(val*0.1)){
        m_chartAxisY->setMax(val + qFabs(val*0.1));
    }
    if(val<m_chartAxisY->min()+qFabs(val*0.1)){
        m_chartAxisY->setMin(val - qFabs(val*0.1));
    }

    //Check SampleMax
    if(m_spline[lines-1]->count()>m_sampleMax)this->Clear();

    //Scan graph
    switch(scan){
    case VChart::scroll:this->graphScroll(val,lines);
        break;
    case VChart::compact:this->graphCompact(val,lines);
        break;
    }
}

void VChart::Clear()
{
    this->chartClear();
}

void VChart::chartClear()
{
    m_chartAxisX->setRange(0,m_chartParameter.axisX_Range);
    m_chartAxisY->setRange(m_chartParameter.axisY_Range_Min,m_chartParameter.axisY_Range_Max);
    m_chartAxisX->setTickCount(m_chartParameter.axisX_TickCount);
    m_chartAxisY->setTickCount(m_chartParameter.axisY_TickCount);
    for(int i=0;i<m_spline.count();i++){
        if(m_spline[i])m_spline[i]->clear();
    }
}

void VChart::graphScroll(double val,int lines)
{
    if(m_spline[lines-1]->count()<m_chartParameter.axisX_Range){
        m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
    }
    else{
        m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
        m_chart->scroll(m_spline[lines-1]->count()-m_chartAxisX->max(),0);
    }
}

void VChart::graphCompact(double val, int lines)
{
    if(m_spline[lines-1]->count()>m_chartAxisX->max())m_chartAxisX->setMax(m_spline[lines-1]->count());
    m_spline[lines-1]->append(m_spline[lines-1]->count(),val);
}
