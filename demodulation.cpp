#include "demodulation.h"

//����udp_recv�µ�CHdata���ɽ��
Demodulation::Demodulation(UDP_Recv* udp_Recv, int DemoFlashTime, int freq, int peaknum):
    demoFlashTime(DemoFlashTime),
    Freq(freq),
    peakNum(peaknum),
    RealPh(new float[peakNum]()),
    PriorPh(new float[peakNum]()),
    K(new float[peakNum]()),
    PriorK(new float[peakNum]()),
    output(new float[peakNum]()),
    RealPhReg(new float[peakNum][FILTERODR]()),
    RealPhOut(new float[peakNum][FILTERODR]()),
    FilterReg(new float[peakNum][LPFILTERODR]),
    HPFilterCoeff(new float[54]()),
    LPFilterCoeff(new float[54]()),
    cnt(new unsigned long[peakNum]()),
    FirstRealPh(new float[peakNum]()),
    FirstIn_n(new int[peakNum]())
{
    udp_recv = udp_Recv;

    DEMOdata_flash = make_shared<CirQueue<float>>(peakNum*Freq*DemoFlashTime/1000*10000); //1s������ * 10000
    DEMOdata_save = make_shared<CirQueue<float>>(peakNum*Freq*60000/1000*10); //60s������ * 10

    readAtanTable(atanTable);

    ReadFilterCoeff(HPFilterCoeff,LPFilterCoeff);
}

Demodulation::~Demodulation()
{
    FreeMemory();
    delete udp_recv;
}

int Demodulation::ParseFrame()
{
    bool isHeadFream = 0;

    //�ж�ǰ16λ�Ƿ���6666666666666666���������������;
    //������ӵ�ǰλ�ÿ�ʼ����һ��6666666666666666��6666666666666666֮��ĳ��ȣ���һ����ֵ������ݵ�demo_CHdata��
    do{
        //                 if(udp_recv->CHdata1->isEmpty()) QThread::msleep(10);
        //                while(udp_recv->CHdata1->isEmpty()) QThread::msleep(10);
        if(udp_recv->GetCHdata1()->pop() == '6' ){
            //                    if(udp_recv->CHdata1->isEmpty())  QThread::msleep(10);
            if(udp_recv->GetCHdata1()->pop() == '6' ){
                //                       if(udp_recv->CHdata1->isEmpty())  QThread::msleep(10);
                if(udp_recv->GetCHdata1()->pop() == '6' ){
                    //                             if(udp_recv->CHdata1->isEmpty())  QThread::msleep(10);
                    if(udp_recv->GetCHdata1()->pop() == '6' ){

                        sizeoCHdata = peakNum*16; //����6666666666666666֮��ĳ���

                        demo_CHdata[0] = '6';
                        demo_CHdata[1] = '6';
                        demo_CHdata[2] = '6';
                        demo_CHdata[3] = '6';

                        //��16��ʼ���sizeoCHdata����
                        for( int j=4; j<sizeoCHdata; ++j){
                            if(udp_recv->GetCHdata1()->isEmpty())  QThread::msleep(5);
                            //unsigned char usCHdata = udp_recv->CHdata1->pop();
                            demo_CHdata[j] = udp_recv->GetCHdata1()->pop();
                        }

                        isHeadFream = 1;

                        // qDebug()<<"Found 6666666666666666!!"<<endl;

                    }
                }
            }

        }

    }while (isHeadFream==0) ;//isHeadFream == 0ʱѭ����ֱ��������0����ѭ��

    int sizeoDemodata = sizeoCHdata;

    for(int m = 0; m<sizeoDemodata; m+=4){
        bool ok;
        int number_DEC = QString(demo_CHdata[m]).toInt(&ok,16)*0
                + QString(demo_CHdata[m+1]).toInt(&ok,16)*256
                + QString(demo_CHdata[m+2]).toInt(&ok,16)*16
                +QString(demo_CHdata[m+3]).toInt(&ok,16)*1;
        if(number_DEC>2047)
            number_DEC = number_DEC-4096;
        int n = m/4/*-4*/;
        demo_CHdata_DEC_all[n] = number_DEC;
    }

    for(int k = 0; k<(sizeoDemodata/*-16*/)/4; k+=4){
        int p = k/4;
        demo_CHdata_DEC_1[p] = demo_CHdata_DEC_all[k];
        demo_CHdata_DEC_2[p] = demo_CHdata_DEC_all[k+1];
        demo_CHdata_DEC_3[p] = demo_CHdata_DEC_all[k+2];
        demo_CHdata_DEC_4[p] = demo_CHdata_DEC_all[k+3];
    }

    return sizeoDemodata;
}

float Demodulation::OpenFilter(int i, float* FirstRealPh)
{
//    return RealPh[i]; //�����˲�ǰ����

    Hpfilter(i, FirstRealPh); //���ø�ͨ�˲�����

    float HPRealPh = RealPhOut[i][2]; //��ͨ�˲����

//    return HPRealPh; //���ظ�ͨ�˲�������

    Lpfilter(i,HPRealPh);  //���õ�ͨ�˲�����

    return output[i]; //���ظ�ͨ����ͨ�˲�������
}

void Demodulation::run()
{
    while(1){

        /*------------1. Parse Frame---------------*/
        int sizeoDemodata = ParseFrame();

            for(int t = 0; t<(sizeoDemodata/*-16*/)/16; t++){
                Vi[t] = (float)(demo_CHdata_DEC_1[t] + demo_CHdata_DEC_2[t] - 2 * demo_CHdata_DEC_3[t]);
                Vq[t] = (float)(-sqrt(3) * (demo_CHdata_DEC_1[t] - demo_CHdata_DEC_2[t]));

                /*------------2. Demodulate Phase--------------*/
                Ph[t]=demoduPh(Vi[t],Vq[t]);

                /*---------------3. Unwrap Phase---------------*/
                Unwrap(Ph[t], t);

                /*------------4. Filter Phase ---------*/
                RealPh[t] = OpenFilter(t, FirstRealPh);

                /*------------5. Push Phase ---------*/
                DEMOdata_flash->push(RealPh[t]);
                DEMOdata_save->push(RealPh[t]);

//                qDebug()<<RealPh[t]<<endl;
            }

//            qDebug()<<"aa"<<endl;


    }//end while

}

//��ȡ������ֵ����ļ�
void Demodulation::readAtanTable(float *roundNum){
    QString tableFileName;
    tableFileName = QString("C:/DAS_Metro/atanTable.bin");
    QString path= tableFileName;
    qDebug()<<"atan table file path:"<<path.toStdString().c_str();
    FILE *tableFile=fopen(path.toStdString().c_str(),"rb");
    if(tableFile == NULL)
    {
        char logStr2[64];
        sprintf(logStr2,"Open %s Failed!\n",path.toStdString().c_str());

    }
    fread(roundNum,sizeof(float),201,tableFile);
    fclose(tableFile);
}

//�����������λ���
float Demodulation::demoduPh(float vi,float vq){
    float absVi=abs(vi);
    float absVq=abs(vq);
    float z=0,z0=0,dz=0,ph0=0,ph=0;
    int numZ0=0;

    if(absVi>=absVq){
        if(vi>0){//111 110
            z=-vq/vi;
            z0=(float) (round(z*100.0)/100.0);//0.01�����ķ�����ֵ
            numZ0=(int) (100+z0/0.01);//z0=-1:0.01:1,������Ϊ1��1��201
            dz=(z-z0)/(1+(z*z0));
            ph0=dz+atanTable[numZ0];//���
            ph=ph0;
        }
        else if(vi==0){
            ph=0;
        }
        else {//vi<0  101 100
            z=-vq/vi;
            z0=(float) (round(z*100.0)/100.0);//0.01�����ķ�����ֵ
            numZ0=(int) (100+z0/0.01);//z0=-1:0.01:1,������Ϊ1��1��201
            dz=(z-z0)/(1+(z*z0));
            ph0=dz+atanTable[numZ0];//���
            ph= ( ((-vq)>=0) ? 1: -1 ) *M_PI+ph0;
        }
    }
    else {//absVi<absVq
        if(vq<0){//-vq>0
            z=-vi/vq;
            z0=(float) (round(z*100.0)/100.0);//0.01�����ķ�����ֵ
            numZ0=(int) (100+z0/0.01);//z0=-1:0.01:1,������Ϊ1��1��201
            dz=(z-z0)/(1+(z*z0));
            ph0=dz+atanTable[numZ0];//���
            ph=0.5*M_PI-ph0;
        }
        else {//-vq<0
            z=-vi/vq;
            z0=(float) (round(z*100.0)/100.0);//0.01�����ķ�����ֵ
            numZ0=(int) (100+z0/0.01);//z0=-1:0.01:1,������Ϊ1��1��201
            dz=(z-z0)/(1+(z*z0));
            ph0=dz+atanTable[numZ0];//���
            ph=-0.5*M_PI-ph0;
        }
    }
    return ph;
}

//��λ�����
float Demodulation::Unwrap(float ph, int i)
{
    if((ph - PriorPh[i]) > M_PI)//PriorPh[i]ʱ��������һ������
        K[i] = PriorK[i] - 1;//PriorK��Kʱ��������һ������
    else if((ph - PriorPh[i]) < -M_PI)
        K[i] = PriorK[i] + 1;
    else
        K[i] = PriorK[i];

    RealPh[i] = (float)(ph + 2*K[i]*M_PI);
    PriorPh[i] = ph;
    PriorK[i] = K[i];

    if(FirstIn_n[i] == 0)
    {
        FirstRealPh[i] = RealPh[i];
        FirstIn_n[i] = 1;
    }

    RealPh[i] -= FirstRealPh[i];

    return RealPh[i]; //�����˲�ǰ����
}

void Demodulation::FreeMemory()
{
    delete[] RealPh;
    delete[] PriorPh;
    delete[] K;
    delete[] PriorK;
    delete[] HPFilterCoeff;
    //    delete[] LPFilterCoeff;
    delete[] FirstRealPh;
    delete[] FirstIn_n;
    delete[] RealPhReg;
    delete[] RealPhOut;
    //    delete[] FilterReg;
    delete[] cnt;
    delete[] demo_CHdatax;
}

//��ȡ����buttorworth��ͨ�˲�����*HPFcoeff ��ͨ�˲�����*LPFcoeff
void Demodulation::ReadFilterCoeff(float *HPFcoeff, float *LPFcoeff)
{
    //    QString fileName = QString::fromLocal8Bit(hpcutoff.data());
    //    QString fileName2 = QString::fromLocal8Bit(lpcutoff.data());

    //fileName = QString("ButtorWorthFilterCoefficient_")+QString::number((int)(frequency/1000))+QString("KHz_50Hz.bin");
    //fileName = QString("ChebysheyIIFilterCoefficient_Order8_4Section_")+QString::number((int)(frequency/1000))+QString("KHz_1Hz.bin");//1Hz�ĸ�ͨ�˲����ļ���ΪButtorWorthFilterCoefficient_Order8_1KHz_1Hz
    //fileName2 = QString("LPFilterCoefficient_")+QString::number((int)(frequency/1000))+QString("KHz_400Hz.bin");// 400Hz��ͨ�˲����ļ���LPFilterCoefficient_1KHz_400Hz.bin

    QString pat = QString("C:/DAS_Metro/ButtorWorthFilterCoefficient_1KHz_10Hz.bin"); //��ͨ�˲�
    QString pat2 = QString("C:/DAS_Metro/LPFilterCoefficient_1KHz_30Hz.bin"); //��ͨ�˲�

    //    qDebug()<<"Filter Coefficient path:"<<pat.toStdString().c_str()<<"  "<<pat2.toStdString().c_str();

    QFile pFile(pat);
    QFile pFile2(pat2);
    if(!pFile.exists())
    {
        char logStr[64];
        sprintf(logStr,"Open %s Failed!.",pat.toStdString().c_str());

        //        isWaveFiletr = false;
    }
    else
    {
        //        isWaveFiletr = true;
        ifstream inFile(pat.toStdString().data(), ifstream::binary);
        for(int i = 0 ; i < FILTERODR; i++)
        {
            inFile.read((char*)(HPFcoeff + i), sizeof(float));
            qDebug() << "coeff[" << i << "] = " << HPFcoeff[i] << endl;
        }
        inFile.close();
    }

    if(!pFile2.exists())
    {
        char logStr[64];
        sprintf(logStr,"Open %s Failed!.",pat2.toStdString().c_str());

        //        isWaveLpFilter = false;
    }
    else
    {
        //        isWaveLpFilter = true;
        ifstream inFile2(pat2.toStdString().data(), ifstream::binary);
        for(int i = 0 ; i < LPFILTERODR; i++)
        {
            inFile2.read((char*)(LPFcoeff + i), sizeof(float));
            qDebug() << "LPFcoeff[" << i << "] = " << LPFcoeff[i] << endl;
        }
        inFile2.close();
    }

}

//RealPhOut����˲�������
void Demodulation::Hpfilter(int i, float* FirstRealPh)
{
    RealPhReg[i][0]=RealPhReg[i][1];
    RealPhReg[i][1]=RealPhReg[i][2];
    RealPhReg[i][2] = RealPh[i]-FirstRealPh[i];

    cnt[i] ++;//�˲�ִ�м���
    if(cnt[i]>2){
        //���װ�����˹�˲���1 * outdata(i)=FilterCoeff(0) * data(i) + FilterCoeff(1) * data(i - 1) + FilterCoeff(2) * data(i-2) - FilterCoeff*outdata(i-1)-b2*outdata(i-2);
        RealPhOut[i][0]=RealPhOut[i][1];
        RealPhOut[i][1]=RealPhOut[i][2];
        //�˴��ĳ����Ѿ��ĳɺ������˲��ķ�����ͬ������Ժ����ɵ��˲���ϵ���ļ� ֻ��Ҫֱ��ճ��matlab��fdatools���ɵġ�
        RealPhOut[i][2] = HPFilterCoeff[0] * RealPhReg[i][2] + HPFilterCoeff[1] * RealPhReg[i][1] +
                HPFilterCoeff[2] * RealPhReg[i][0] - HPFilterCoeff[3] * RealPhOut[i][1] - HPFilterCoeff[4] * RealPhOut[i][0];
        cnt[i] = 3;
    }

}

void Demodulation::Lpfilter(int i, float res)
{
    FilterReg[i][0]=LPFilterCoeff[0]*(res-LPFilterCoeff[1]*FilterReg[i][1]-LPFilterCoeff[2]*FilterReg[i][2]-LPFilterCoeff[3]*FilterReg[i][3]-LPFilterCoeff[4]*FilterReg[i][4]);
    output[i] = LPFilterCoeff[5]*FilterReg[i][0]+LPFilterCoeff[6]*FilterReg[i][1]+LPFilterCoeff[7]*FilterReg[i][2]+LPFilterCoeff[8]*FilterReg[i][3]+LPFilterCoeff[9]*FilterReg[i][4];
    for(int n=4;n>=1;n--)
    {
        FilterReg[i][n]=FilterReg[i][n-1];
    }
}
