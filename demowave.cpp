#include "demowave.h"

demowave::demowave(Demodulation* _demodulation) :
    m_demodulation(_demodulation),
    peakNum(m_demodulation->GetPeakNum()),
    freq(m_demodulation->GetFreq())
{
    memset(Demodata_1, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_2, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_3, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_4, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_5, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_6, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_7, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_8, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_9, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_10, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_11, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_12, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_13, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_14, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_15, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_16, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_17, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_18, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_19, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_20, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_21, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_22, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_23, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_24, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_25, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_26, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_27, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_28, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_29, 0, sizeof(float)*REGION_DATA_LENGTH);
    memset(Demodata_30, 0, sizeof(float)*REGION_DATA_LENGTH);



    DemodataArray[0]=Demodata_1;
    DemodataArray[1]=Demodata_2;
    DemodataArray[2]=Demodata_3;
    DemodataArray[3]=Demodata_4;
    DemodataArray[4]=Demodata_5;
    DemodataArray[5]=Demodata_6;
    DemodataArray[6]=Demodata_7;
    DemodataArray[7]=Demodata_8;
    DemodataArray[8]=Demodata_9;
    DemodataArray[9]=Demodata_10;
    DemodataArray[10]=Demodata_11;
    DemodataArray[11]=Demodata_12;
    DemodataArray[12]=Demodata_13;
    DemodataArray[13]=Demodata_14;
    DemodataArray[14]=Demodata_15;
    DemodataArray[15]=Demodata_16;
    DemodataArray[16]=Demodata_17;
    DemodataArray[17]=Demodata_18;
    DemodataArray[18]=Demodata_19;
    DemodataArray[19]=Demodata_20;
    DemodataArray[20]=Demodata_21;
    DemodataArray[21]=Demodata_22;
    DemodataArray[22]=Demodata_23;
    DemodataArray[23]=Demodata_24;
    DemodataArray[24]=Demodata_25;
    DemodataArray[25]=Demodata_26;
    DemodataArray[26]=Demodata_27;
    DemodataArray[27]=Demodata_28;
    DemodataArray[28]=Demodata_29;
    DemodataArray[29]=Demodata_30;
}

demowave::~demowave()
{
    delete[] DemodataArray;
}

void demowave::run()
{
    /*--------------时域波形显示预处理---------------*/
    int regionNum = peakNum;
    int sizeoDemoData = m_demodulation->GetDEMOdata_flash()->size();
    int one_dis_len = sizeoDemoData/regionNum;
    sizeoDemoData = one_dis_len * regionNum;

    for(int k = 0; k<sizeoDemoData; k+=regionNum){
        int p = k/regionNum;
        for(int q=0; q<regionNum;q++){
            //            if(demodu->DEMOdata_flash->isEmpty()) QThread::msleep(100);
            DemodataArray[q][p] = m_demodulation->GetDEMOdata_flash()->pop();
//                        DemodataArray[q][p] = 1.0*k; //test
        }
    }
    QJsonArray demo_wave_json, dis_len_json;

    regionIndex = 1; //test
    one_dis_len = 1000; //test
    for(int i = 0; i<one_dis_len; i++){
        demo_wave_json.push_back(DemodataArray[regionIndex][i]);
    }

    dis_len_json.push_back(one_dis_len);
    demo_wave_obj.insert("dis_len",dis_len_json);
    demo_wave_obj.insert("demo_wave",demo_wave_json);

}

