#ifndef VDYNAMICSPLINE_H
#define VDYNAMICSPLINE_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class VDynamicSpline:public QChart
{
        Q_OBJECT
public:
    VDynamicSpline(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    virtual ~VDynamicSpline();
    void chartAppend(double val);

private:
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};

#endif // VDYNAMICSPLINE_H
