//解调波形运算线程

#ifndef DEMOWAVE_H
#define DEMOWAVE_H

#include <QObject>
#include <QThread>
#include "demodulation.h"
#include "fallmap.h"

#define REGION_DATA_LENGTH 10*1000*1
#define MAXREGION 30 //最大区域数

class Demodulation;

class demowave : public QThread
{
    Q_OBJECT
public:
    explicit demowave(Demodulation* _demodulation);
    ~demowave();
    float** GetDemodataArray() const  {return DemodataArray;}
    const int PeakNum() const {return peakNum;}
    const int Freq() const {return freq;}
    QJsonObject& GetDemoWaveObj() {return demo_wave_obj;}

    int regionIndex;

private:
    Demodulation* m_demodulation;
    int peakNum;
    int freq;

    int maxAmplitude;
    bool isNormal;

    //存放Demodata[]的数组(二维数组) 二维数组最大为20000*20000*4Bytes(总容量不能超过2GBytes)
    float **DemodataArray = new float*[MAXREGION];
    //静态数组
    float Demodata_1[REGION_DATA_LENGTH]; //region1
    float Demodata_2[REGION_DATA_LENGTH]; //region2
    float Demodata_3[REGION_DATA_LENGTH];
    float Demodata_4[REGION_DATA_LENGTH];
    float Demodata_5[REGION_DATA_LENGTH];
    float Demodata_6[REGION_DATA_LENGTH];
    float Demodata_7[REGION_DATA_LENGTH];
    float Demodata_8[REGION_DATA_LENGTH];
    float Demodata_9[REGION_DATA_LENGTH];
    float Demodata_10[REGION_DATA_LENGTH];
    float Demodata_11[REGION_DATA_LENGTH];
    float Demodata_12[REGION_DATA_LENGTH];
    float Demodata_13[REGION_DATA_LENGTH];
    float Demodata_14[REGION_DATA_LENGTH];
    float Demodata_15[REGION_DATA_LENGTH];
    float Demodata_16[REGION_DATA_LENGTH];
    float Demodata_17[REGION_DATA_LENGTH];
    float Demodata_18[REGION_DATA_LENGTH];
    float Demodata_19[REGION_DATA_LENGTH];
    float Demodata_20[REGION_DATA_LENGTH];
    float Demodata_21[REGION_DATA_LENGTH];
    float Demodata_22[REGION_DATA_LENGTH];
    float Demodata_23[REGION_DATA_LENGTH];
    float Demodata_24[REGION_DATA_LENGTH];
    float Demodata_25[REGION_DATA_LENGTH];
    float Demodata_26[REGION_DATA_LENGTH];
    float Demodata_27[REGION_DATA_LENGTH];
    float Demodata_28[REGION_DATA_LENGTH];
    float Demodata_29[REGION_DATA_LENGTH];
    float Demodata_30[REGION_DATA_LENGTH];

    QJsonObject demo_wave_obj;
    QJsonObject fallmap_obj;

protected:
    void run();

signals:

};

#endif // DEMOWAVE_H
