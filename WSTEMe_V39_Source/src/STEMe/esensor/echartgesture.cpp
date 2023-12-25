#include "echartgesture.h"
#include <QtDebug>

QT_CHARTS_USE_NAMESPACE

EChartGesture::EChartGesture(QChart *chart, QWidget *parent) :
    QChartView(chart, parent),
    m_isTouching(false)
{
        //setRubberBand(QChartView::RectangleRubberBand);
        setRubberBand(QChartView::NoRubberBand);
        setDragMode(QGraphicsView::NoDrag);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        this->setMouseTracking(true);

        m_tooltip = new ECallout(chart);
        m_tooltip->hide();
        m_crosshairs = new Crosshairs(chart);
}

void EChartGesture::setTrackLine(EChartGesture::ETrackLine track)
{
    m_etrackLine = track;
    if(m_tooltip)m_tooltip->hide();
    const auto callouts = m_callouts;
    for (ECallout *callout : callouts)
    callout->hide();
    m_callouts.clear();
    if(m_crosshairs)m_crosshairs->hide();
}

void EChartGesture::clearTrackLine()
{
    const auto _callouts = m_callouts;
    this->tooltip(QPointF(0,0),false);
    for (ECallout *call : _callouts)call->hide();
    m_callouts.clear();
}

void EChartGesture::keepCallout()
{
    if(m_etrackLine==ETrackLine::ETL_tooltip||m_etrackLine==ETrackLine::ETL_y_ax){
        m_callouts.append(m_tooltip);
            m_tooltip = new ECallout(chart());
            m_tooltip->hide();
    }
}

void EChartGesture::tooltip(QPointF point, bool state)
{
    if(m_etrackLine==ETrackLine::ETL_tooltip||m_etrackLine==ETrackLine::ETL_y_ax){
        if (state) {
            if(m_etrackLine==ETrackLine::ETL_tooltip)m_tooltip->setText(QString("X: %1 \nY: %2 ").arg(QString::number(point.x(),'f',m_pre_X)).arg(QString::number(point.y(),'f',m_pre_Y)));
            if(m_etrackLine==ETrackLine::ETL_y_ax)m_tooltip->setText(QString("(x,y) = (%1,%2) \na = %3 ").arg(QString::number(point.x(),'f',m_pre_X)).arg(QString::number(point.y(),'f',m_pre_Y)).arg(QString::number(point.y()/point.x(),'f',this->getMax(m_pre_X,m_pre_Y))));
            m_tooltip->setAnchor(point);
            m_tooltip->setZValue(11);
            m_tooltip->updateGeometry();
            m_tooltip->show();
        } else {
            m_tooltip->hide();
        }
    }
}

bool EChartGesture::viewportEvent(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
        // By default touch events are converted to mouse events. So
        // after this event we will get a mouse event also but we want
        // to handle touch events as gestures only. So we need this safeguard
        // to block mouse events that are actually generated from touch.
        m_isTouching = true;

        // Turn off animations when handling gestures they
        // will only slow us down.
        chart()->setAnimationOptions(QChart::NoAnimation);
    }
    return QChartView::viewportEvent(event);
}

void EChartGesture::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mousePressEvent(event);
  //  switch(event->mou
}

void EChartGesture::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;

    m_widgetPos = event->localPos();
    auto const scenePos = mapToScene(QPoint(static_cast<int>(m_widgetPos.x()), static_cast<int>(m_widgetPos.y())));
    auto const chartItemPos = chart()->mapFromScene(scenePos);
    m_positionMouse = chart()->mapToValue(chartItemPos);
    switch(m_etrackLine){
    case ETrackLine::ETL_default:
        m_crosshairs->updatePosition(event->pos(),m_pre_X,m_pre_Y);
        break;
    case ETrackLine::ETL_tooltip:
        //m_coordX->setText(QString("X: %1").arg(chart()->mapToValue(event->pos()).x()));
        //m_coordY->setText(QString("Y: %1").arg(chart()->mapToValue(event->pos()).y()));
        break;
    case ETrackLine::ETL_y_ax:
        break;
    }
    QChartView::mouseMoveEvent(event);
  //  QGraphicsView::mouseMoveEvent(event);
}

void EChartGesture::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);
    const auto _callouts = m_callouts;
    switch(event->button())
    {
    case Qt::MouseButton::MiddleButton:
        chart()->zoomReset();
        this->tooltip(QPointF(chart()->mapToValue(event->pos()).x(),chart()->mapToValue(event->pos()).y()),false);
        for (ECallout *call : _callouts)call->hide();
        m_callouts.clear();
        break;
    case Qt::MouseButton::LeftButton:
        this->keepCallout();
        break;
    case Qt::MouseButton::RightButton:
        this->tooltip(QPointF(chart()->mapToValue(event->pos()).x(),chart()->mapToValue(event->pos()).y()),false);
        if(_callouts.count()>0){
            _callouts.last()->hide();
            m_callouts.removeLast();
            }

        // chart()->zoomOut();
        break;
    }
    QChartView::mouseReleaseEvent(event);
}

//![1]
void EChartGesture::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
    case Qt::Key_Enter:
        chart()->zoomReset();
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
       // QGraphicsView::keyPressEvent(event);
        QChartView::keyPressEvent(event);
        break;
    }
}

void EChartGesture::wheelEvent(QWheelEvent *event)
{
        QPoint angle = event->angleDelta();
        if(angle.y()>0)chart()->zoomIn();
            else chart()->zoomOut();
        //chart()->scroll(angle.x(),angle.y()/12);
        this->tooltip(QPointF(chart()->mapToValue(event->pos()).x(),chart()->mapToValue(event->pos()).y()),false);
        event->accept();
}

void EChartGesture::resizeEvent(QResizeEvent *event)
{
    switch(m_etrackLine){
    case ETrackLine::ETL_default:
        break;
    case ETrackLine::ETL_tooltip:
        if (scene()) {
            scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
            const auto callouts = m_callouts;
            for (ECallout *callout : callouts)
            callout->updateGeometry();
            }
        break;
    case ETrackLine::ETL_y_ax:
        if (scene()) {
            scene()->setSceneRect(QRect(QPoint(0, 0), event->size()));
            const auto callouts = m_callouts;
            for (ECallout *callout : callouts)
            callout->updateGeometry();
            }
        break;
    }

        //QGraphicsView::resizeEvent(event);
    QChartView::resizeEvent(event);
}

int EChartGesture::getMax(int x, int y)
{
if(x>y)return x;
return y;
}
