#ifndef VCHART_ZOOM_H
#define VCHART_ZOOM_H

#include <QWidget>


//chart
#include <esensor/echarts.h>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QGridLayout>
#include <QValueAxis>
#include <vdevice/vdevice.h>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class Vchart_Zoom;
}

class Vchart_Zoom : public QWidget
{
    Q_OBJECT


    /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
    Q_SIGNALS:
    void setChartParameter(int sampleTime);


   private slots:
        void on_chartTimer();
        /////////////////////////////////////////////////////////////////////////////////////////////////Function for Chart Graphic...
   private:
            ECharts *m_echart = nullptr;
            QTimer  *m_chartTimer=nullptr;
            VDevice m_device;
            int m_axisX_TickCount = 11;
            qreal m_axisX_Range = 100;
            int m_axisY_TickCount = 11;
            qreal m_axisY_Range_Max = 2;
            qreal m_axisY_Range_Min = 0;

            int m_chartTimerInterval = 100;
            int m_chartTimerScan = 100;

            qreal m_forceValue =0;
            qreal m_axtX_Index = 0;

            void chartInit();
            void chartGraph(double val);
            void chartClear();

            void setTrackLine(EChartGesture::ETrackLine track);


public:
    explicit Vchart_Zoom(QWidget *parent = nullptr);
    ~Vchart_Zoom();

    void setDevice(VDevice dev);
    void vchartInit(double y_min,double y_max,double x_max,int interval);
    void vchartGraph(double val,QString units);

protected:
    void closeEvent(QCloseEvent *event);

private slots:
        void on_pushButton_Cancel_clicked();

        void on_pushButton_SaveData_clicked();

        void on_pushButton_OpenData_clicked();

        void on_pushButton_Stop_clicked();

        void on_pushButton_SetSampleTime_clicked();

        void on_pushButton_SetConfigChart_clicked();

        void on_pushButton_ClearChart_clicked();

        void on_radioButton_Accumulation_toggled(bool checked);

        void on_pushButton_TrackLine_Default_clicked();

        void on_pushButton_TrackLine_Tooltip_clicked();

        void on_pushButton_TrackLine_Yax_clicked();

private:
    Ui::Vchart_Zoom *ui;

    void setOpenFile(bool status);
    bool    m_isOpenFile = false;
    double  m_GET_SAMPLE_MAX = std::numeric_limits<double>::min();
    double  m_GET_SAMPLE_MIN = std::numeric_limits<double>::max();
    double  m_GET_SAMPLE_SUM = 0;
    int     m_GET_SAMPLE_COUNT = 0;

};

#endif // FORM_H
