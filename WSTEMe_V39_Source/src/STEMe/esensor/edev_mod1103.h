#ifndef EDEV_MOD1103_H
#define EDEV_MOD1103_H

#include <esensor/esensor_base.h>
#include <esensor/esensors.h>
#include <vroot/vdevicecalibration.h>
#include <esensor/echarts.h>
#include <echart/echartlines.h>

class EDev_Mod1103 : public ESensor_Base
{
    //////////////////////////////////////////////////////////////////////////Charts///////////////////////////
public:
    enum TypeLine{
        typeSpline,
        typeLine
    };

    inline ECharts::Parameter chartParameter(){return m_echart->parameter();}
    inline EChartLines::Parameter chartLineParameter(){return m_echartLine->parameter();}
    void setChartParameter(ECharts::Parameter p);
    void setChartParameter(EChartLines::Parameter p);
    inline void setChartTimeScan(int time){m_chartTimerScan = time;}
    void setScanType(ECharts::ScanType type);
    void setScanType(EChartLines::ScanType type);
    void replaceListLineColor(int index,QColor rgb){m_listColor.replace(index,rgb);}
    void setLineHelp(int line){m_echart->updateLineHelp(line);}
    inline ECharts* chart(){return m_echart;}
    inline EChartLines* chartLines(){return m_echartLine;}
    //position
    //QPointF getChartPositionMouse(){return m_echart->getPositionMouse();}
    QPointF getChartValueMouse(int line);
    void setColorTextAxis_X(QColor color);
    void setColorTextAxis_Y(QColor color);

        void chartInit(QWidget *widget,TypeLine type);
        void graph(QPointF vals,int line);
        void setTypeLine(TypeLine type){m_typeLine = type;}
        void setSpline(QSplineSeries *series,int line);
        void setSpline(QLineSeries *series,int line);
        void chartClear();
        void setTrackLine(EChartGesture::ETrackLine track);
        void setPrecisionXY(int x, int y);

private:
        ECharts *m_echart = nullptr;
        EChartLines *m_echartLine = nullptr;
       // ECharts::Parameter m_parameter;
        QWidget *m_chartWidget=nullptr;
        QList<QColor> m_listColor = {Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray,Qt::red,Qt::green,Qt::white,Qt::blue,Qt::cyan,Qt::magenta,Qt::yellow,Qt::gray};

        TypeLine m_typeLine = TypeLine::typeLine;
        //Chart parameter
        int m_axisX_TickCount = 11;
        qreal m_axisX_Range = 1;
        int m_axisY_TickCount = 6;
        qreal m_axisY_Range_Max = 0.001;
        qreal m_axisY_Range_Min = 0;
        int m_chartTimerInterval = 100;
        int m_chartTimerScan = 100;

        //////////////////////////////////////////////////////////////////////////Device///////////////////////////

public:
    EDev_Mod1103();
    virtual ~EDev_Mod1103();

    enum DeviceREG_Tables{
        dREG_ID				= 0x00,//ID = 0x00,0x01,0x02 of 16-bit reg
        dREG_ADDRESS 		= 0x03,
        dREG_BAUDRATE 		= 0x04,

        dREG_CAR_Command	= 0x05,	//msb:number of slave, lsb:command
        //For CAR-01
        dREG_CAR01_PIN		= 0x06,
        dREG_CAR01_ADD		= 0x07,//0x08,0x09
        dREG_CAR01_CALS_X	= 0x0A,//0x0B
        dREG_CAR01_CALF_X	= 0x0C,//0x0D
        dREG_CAR01_TS		= 0x0E,
        dREG_CAR01_CS		= 0x0F,
        dREG_CAR01_INDEX	= 0x10,
        dREG_CAR01_D		= 0x11,//0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,
        dREG_CAR01_T		= 0x25,//0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38

        //For CAR-02
        dREG_CAR02_PIN		= 0x39,
        dREG_CAR02_ADD		= 0x3A,//0x3B,0x3C
        dREG_CAR02_CALS_X	= 0x3D,//0x3E
        dREG_CAR02_CALF_X	= 0x3F,//0x40
        dREG_CAR02_TS		= 0x41,
        dREG_CAR02_CS		= 0x42,
        dREG_CAR02_INDEX	= 0x43,
        dREG_CAR02_D		= 0x44,//0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57
        dREG_CAR02_T		= 0x58,//0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6A,0x6B

        //
        dREG_CAR01_F_INDEX	= 0x6C,
        dREG_CAR01_F		= 0x6D,//0x6E,0x6F,0x70,0x71,0x72
        dREG_CAR02_F_INDEX	= 0x73,
        dREG_CAR02_F		= 0x74,//0x75,0x76,0x77,0x78,0x79,

        dREG_TIME_SYSTEM	= 0x7A,
        dREG_CAR01_SPT		= 0x7B,
        dREG_CAR02_SPT		= 0x7C
    };
    enum PayloadDataMap{
    mapCommandType	= 0,		//0x03:readREG, 0x06: writeREG
    mapCAR_S		= 1,//2	Distance		int16_t
    mapCAR_D		= 3,//4	Speed			int16_t
    mapCAR_F		= 5,//6,7,8	Force (g)		int16_t
    mapCAR_T		= 9,//10,11,12 (miniSecond)
    mapPIN			= 13,//14	miniVolt
    mapAddress		= 15,//16-17-18
    mapCalib_Sc		= 19,//20,21,22	(step)
    mapCalib_Fc		= 23,//24,25,26 (24 bit adc)
    mapCAR_TS		= 27,// Time shutdown
    mapCAR_CS		= 28,// Counter shutdown
    mapCheckSum 	= 31,

    mapShutdown		= 0xAA,
    mapZeroCAR		= 0xBB,	//Zero Car
    mapZeroForce	= 0xCC,
    mapSetAdd		= 0xF0,
    mapCalibS		= 0xF1,
    mapCalibF		= 0xF2,
    mapTimeShutdown = 0xF3,
    mapErrorWrite	= 0xE1
    };
    enum ForceUnits{
        SSU_default,
        SSU_scaleWeight,             //For WHL0103
        SSU_scaleGram,
        SSU_scaleKiloGram,
        SSU_scaleForce,
    };
    enum SpeedUnits{
        SPU_default,
        SPU_mm_per_second,
        SPU_m_per_second,
        SPU_km_per_hour
    };
    enum AccelerationUnits{
        ACU_default,
        ACU_mm_per_s2,
        ACU_m_per_s2
    };
    enum DistanceUnits{
        DSU_default,
        DSU_millimetre,
        DSU_metre,
        DSU_kilometre
    };
    enum VoltageUnits{
        VTU_default,
        VTU_mVolt,
        VTU_Volt
    };
    enum TimeUnits{
        TMU_default,
        TMU_uSecond,
        TMU_mSecond,
        TMU_Second
    };
    struct CAR_S{
        double value=0;
        DistanceUnits unit=DistanceUnits::DSU_millimetre;
        int pre=0;//Do phan dai
    };
    struct CAR_T{
        double value=0;
        TimeUnits unit=TimeUnits::TMU_Second;
        int pre=3;//Do phan dai
    };
    struct CAR_V{
        double value=0;
        SpeedUnits unit=SpeedUnits::SPU_mm_per_second;
        int pre=1;//Do phan dai
    };
    struct CAR_A{
        double value=0;
        AccelerationUnits unit=AccelerationUnits::ACU_mm_per_s2;
        int pre=1;//Do phan dai
    };
    struct CAR_F{
        double value=0;
        ForceUnits unit=ForceUnits::SSU_scaleForce;
        int pre=3;//Do phan dai
    };
    struct CAR_PIN{
        double value=0;
        VoltageUnits unit=VoltageUnits::VTU_Volt;
        int pre=2;//Do phan dai
    };
    struct ECar{
        uint index=0;
        CAR_S s;
        CAR_T t;
        CAR_V v;
        CAR_A a;
        CAR_F f;
        CAR_PIN pin;
        QString add="";
        double sc=37;
        double fc=1;
        uint ts=0;
        uint cs=0;
        uint SPT=0;
        uint frame=0;
        uint timeSystem=0;
        bool connect = false;
    };
    struct EMfsData{
        QVector <ECar> car01;
        QVector <ECar> car02;
    };
    enum ESlave{
        CAR_01,
        CAR_02,
        CAR_ALL
    };

    enum ConditionProcess{
        CDP_default,
        CDP_init,
        CDP_start,
        CDP_startCheck,
        CDP_stop,
        CDP_stopCheck,
        CDP_end
    };
    enum CarCondition{
        CCD_default,
        CCD_S_Higher,
        CCD_S_Lower,
        CCD_V_Higher,
        CCD_V_Lower,
        CCD_A_Higher,
        CCD_A_Lower,
        CCD_F_Higher,
        CCD_F_Lower,
        CCD_T_Higher
    }m_CCD_carCondition_Stop = CCD_default,m_CCD_carCondition_Start = CCD_default;

    //CAR Command
    enum CAR_Command{
        CCMD_ZeroCAR,
        CCMD_ZeroForce,
        CCMD_Shutdown,
        CCMD_Calib_S,
        CCMD_Calib_F
    };

    enum CarMode{
        CMD_continous,
        CMD_condition
    }m_CMD_carMode = CMD_continous;

    struct ECarLines{
    QLineSeries *line_s = new QLineSeries();
    QLineSeries *line_d = new QLineSeries();
    QLineSeries *line_t = new QLineSeries();
    QLineSeries *line_v = new QLineSeries();
    QLineSeries *line_a = new QLineSeries();
    QLineSeries *line_f = new QLineSeries();
    QLineSeries *line_spt = new QLineSeries();
    double line_time=0;
    int line_index=0;
    double timeSystem=0;
    }m_ecarLines_01,m_ecarLines_02;

    struct ECarSPlines{
    QSplineSeries *line_s = new QSplineSeries();
    QSplineSeries *line_d = new QSplineSeries();
    QSplineSeries *line_t = new QSplineSeries();
    QSplineSeries *line_v = new QSplineSeries();
    QSplineSeries *line_a = new QSplineSeries();
    QSplineSeries *line_f = new QSplineSeries();
    QSplineSeries *line_spt = new QSplineSeries();
    double line_time=0;
    int line_index=0;
    double timeSystem=0;
    }m_ecarSPlines_01,m_ecarSPlines_02;
    //Macro===========================================
    static int getESlave(ESlave slave);
    static ESlave getESlave(int slave);
    static int getCarCondition(CarCondition condition);
    static CarCondition getCarCondition(int condition);
    static QString getCarConditionUnit(int condition,ECar car);
    static QString getCarConditionUnit(CarCondition condition,ECar car);
    static ECar getCar(ESlave slave,ECar car01,ECar car02);
    ECar getCar(ESlave slave);
    void setCar(ESlave slave,ECar car);

    //properties=================================
    //Units
    inline ForceUnits sensorUnit(ESlave slave);
    void setForceUnit(ESlave slave,ForceUnits unit);
    static QString forceUnit(ForceUnits unit);
    void setDistanceUnit(ESlave slave,DistanceUnits unit);
    static QString distanceUnit(DistanceUnits unit);
    void setSpeedUnit(ESlave slave,SpeedUnits unit);
    static QString speedUnit(SpeedUnits unit);
    void setAccelerationUnit(ESlave slave,AccelerationUnits unit);
    static QString accelerationUnit(AccelerationUnits unit);
    void setVoltageUnit(ESlave slave,VoltageUnits unit);
    static QString voltageUnit(VoltageUnits unit);
    void setTimeUnit(ESlave slave,TimeUnits unit);
    static QString timeUnit(TimeUnits unit);
    inline void setDistanceCheck(double d){m_Distance_Check=d;}

    void setMeasureVector(ESlave slave,bool vector);
    void setReverseSign(ESlave slave,bool sign);
    inline void setWheelDiameter(double d){m_carWheelDiameter = d;}

    //Function
    double sensorCar_DistanceCheck(){return m_Distance_Check;}
    void setDistanceCheck(){m_Distance_Check=0;}
    ECar sensorCar(ESlave slave);
    ECarLines lineCar(ESlave slave);
    ECarSPlines splineCar(ESlave slave);
    void setLineCar(ESlave slave,ECarLines lines,bool clear);
    void setLineCar(ESlave slave,ECarSPlines lines,bool clear);
    void setUpdateLine(bool update,CarMode mode);

    //Function
    void sensorUpdate();
    void writeSensorCommand(ESlave slave,CAR_Command cmd);
    void setZero_S();
    void setZero_F();
    //Data Poll
    uint dataPoll_uint16(uint d1,uint d2);
    double dataPoll_uint16(double d1,double d2);
    //Data Function
    uint getAbsMult(uint s1,uint s2);
    double getPrecision(double val,int pre);
    double dataCar_S(double s,DistanceUnits unit);
    double dataCar_S(double s,DistanceUnits unit,int pre);

    double dataCar_T(uint t1,uint t2);
    double dataCar_T(double t1,double t2);
    double dataCar_T(double t,TimeUnits unit);
    double dataCar_T(double t,TimeUnits unit,int pre);

    inline double dataCar_V(double s1,double s2,double t);
    double dataCar_V(double v,SpeedUnits unit);
    double dataCar_V(double v,SpeedUnits unit,int pre);

    inline double dataCar_A(double v1,double v2,double t);
    double dataCar_A(double a,AccelerationUnits unit);
    double dataCar_A(double a,AccelerationUnits unit,int pre);

    double dataCar_PIN(double v,VoltageUnits unit);
    double dataCar_PIN(double v,VoltageUnits unit,int pre);

    double dataCar_F(double f,ForceUnits unit);
    double dataCar_F(double f,ForceUnits unit,int pre);

    //double dataSystem_T(TimeUnits unit);

    QString getConditionText(CarCondition condition);

private slots:
        void on_PollTimer();

private:
    QTimer  *m_PollTimer=nullptr;

    //MFS car
    ECar m_ecar_01,m_ecar_02;
    ECar m_ecar01_Last,m_ecar02_Last;
    ECar m_ecar01_Line_Last,m_ecar02_Line_Last;
    int check_car01=0,check_car02=0;

    bool m_updateLine=false;
    double m_Distance_Check=0;
    double m_car01_timeConnect=0,m_car02_timeConnect=0;

    double m_car01_Acceleration=0,m_car02_Acceleration=0;
    double m_car01_AccelerationTime=0,m_car02_AccelerationTime=0;
    double m_car01_Speed=0,m_car02_Speed=0;
    double m_car01_SpeedSUM=0,m_car02_SpeedSUM=0;
    uint   m_car01_SpeedCNT=0,m_car02_SpeedCNT=0;
    double m_car01_SpeedTime=0,m_car02_SpeedTime=0;
    double m_car01_Force=0,m_car02_Force=0;
    //For Car
    double m_carWheelDiameter = 1;
    QList<bool> m_useMeasureVector = {false,false};
    QList<bool> m_useReverseSign = {false,false};
    //for set/get DataRaw
    EMfsData m_emfsData;
    int  DATA_RAW_MAXSIZE = 200;
    int m_CAR01_DATA_RAW_HEAD = 0,m_CAR01_DATA_RAW_TAIL = 0;
    int m_CAR02_DATA_RAW_HEAD = 0,m_CAR02_DATA_RAW_TAIL = 0;


    //Frame function private
    uint frame_Index(ESlave slave);
    uint frame_Force_Index(ESlave slave);
    double frame_S(ESlave slave,uint index);
    uint frame_t(ESlave slave,uint index);
    double frame_f(ESlave slave,uint index);
    double frame_pin(ESlave slave);
    QString frame_add(ESlave slave);
    double frame_sc(ESlave slave);
    double frame_fc(ESlave slave);
    uint frame_ts(ESlave slave);
    uint frame_cs(ESlave slave);
    uint frame_SPT(ESlave slave);
    uint frame_timeSystem();

    //update data for CAR
    ECar getDataRawBefore(ESlave slave);
    ECar getDataRawLast(ESlave slave,bool clear);
    ECar getDataRaw(ESlave slave, bool *ok);
    void setDataRaw(ESlave slave,ECar data);

    void frameUpdate(ESlave slave);
    void carDataUpdate(ESlave slave);
    //line
    void carLineUpdateCondition(ESlave slave);
    void carLineUpdateContinous(ESlave slave);
    //spLine
    void carSPlineUpdateCondition(ESlave slave);
    void carSPlineUpdateContinous(ESlave slave);
    //Check vector for data
    double checkVector(double val,ESlave slave);
    void carCheckConnect();
};

#endif // EDEV_MOD1103_H
