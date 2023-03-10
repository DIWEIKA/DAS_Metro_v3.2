#ifndef FALLMAP_H
#define FALLMAP_H

/**
1. fallmap��������
2. Find & Select Max Data of all DemoData
3. �ж�������λ���ж���Ѱ��Ӧ��ʱ�����Ƿ��쳣�ж�
4. fallmap��ʾԤ���������ݴ���JSON
5. fault detection: ������ϣ��г�����
*/

#include <QObject>
#include <QThread>
#include "demowave.h"
#include "fault_detection.h"

#define Nf1 60 //fallmap xaxis length
#define BASE 0.1 //region find upper limit (rad)
#define LIMIT 10 //fault detection upper limit (rad)


class demowave;
class Fault_detection;

class fallmap : public QThread
{
    Q_OBJECT
public:
     fallmap(demowave* _demowave, int _fallmapFlashTime);
    ~fallmap();
    float** reverse(float** _array);
    vector<vector<float>>& GetFallmapDataVec(){return FallmapDataVec;}
    float GetMaxAmplitudeAll() const {return max_amplitude_all;}
    int GetPresentRegion() const {return present_region;}
    int GetIsFault() const {return IsFault;}
    QJsonObject& GetFallmapObj() {return fallmap_obj;}
    void SelectMax(vector<float>& max_data, vector<int>& max_data_index, int len);
    void Judgement(const vector<float>& max_data, const vector<int>& max_data_index);
    void PreProcess();
    QJsonObject& GetJudgementObj() {return judgement_obj;}
    vector<float>& GetStrainData() {return strain_data;}
    void Load_Fallmap(vector<float>& max_data);
    void Find_Present_Region(const vector<float>& max_data);
    void Fault_Detection(const int present_region, const vector<float>& max_data);
    void Find_Range();

private:

    demowave* m_demowave;
    int peakNum;
    int fallmapFlashTime;
    QJsonObject fallmap_obj;
    QJsonObject judgement_obj;
    float max_amplitude_all = 0.0; //���в������ź�����ǿֵ
    int present_region = 1; //��ǰ�ź���ǿ�Ĳ�����
    int IsFault = 0; //��ǰ�����Ŷ�Ӧ�Ĳ���״̬�Ƿ�����
    int lenoTime; //1s���ݳ���
    vector<float> strain_data; //��ǰ������Ӧ��Ӧ��ʱ��������
    Fault_detection* m_fault_detection;
    int temp_region = 1;

    //Save fallmap data
    vector<vector<float>> FallmapDataVec;
    vector<float> FallmapData1;
    vector<float> FallmapData2;
    vector<float> FallmapData3;
    vector<float> FallmapData4;
    vector<float> FallmapData5;
    vector<float> FallmapData6;
    vector<float> FallmapData7;
    vector<float> FallmapData8;
    vector<float> FallmapData9;
    vector<float> FallmapData10;
    vector<float> FallmapData11;
    vector<float> FallmapData12;
    vector<float> FallmapData13;
    vector<float> FallmapData14;
    vector<float> FallmapData15;
    vector<float> FallmapData16;
    vector<float> FallmapData17;
    vector<float> FallmapData18;
    vector<float> FallmapData19;
    vector<float> FallmapData20;
    vector<float> FallmapData21;
    vector<float> FallmapData22;
    vector<float> FallmapData23;
    vector<float> FallmapData24;
    vector<float> FallmapData25;
    vector<float> FallmapData26;
    vector<float> FallmapData27;
    vector<float> FallmapData28;
    vector<float> FallmapData29;
    vector<float> FallmapData30;
    vector<float> FallmapData31;
    vector<float> FallmapData32;
    vector<float> FallmapData33;
    vector<float> FallmapData34;
    vector<float> FallmapData35;
    vector<float> FallmapData36;
    vector<float> FallmapData37;
    vector<float> FallmapData38;
    vector<float> FallmapData39;
    vector<float> FallmapData40;
    vector<float> FallmapData41;
    vector<float> FallmapData42;
    vector<float> FallmapData43;
    vector<float> FallmapData44;
    vector<float> FallmapData45;
    vector<float> FallmapData46;
    vector<float> FallmapData47;
    vector<float> FallmapData48;
    vector<float> FallmapData49;
    vector<float> FallmapData50;
    vector<float> FallmapData51;
    vector<float> FallmapData52;
    vector<float> FallmapData53;
    vector<float> FallmapData54;
    vector<float> FallmapData55;
    vector<float> FallmapData56;
    vector<float> FallmapData57;
    vector<float> FallmapData58;
    vector<float> FallmapData59;
    vector<float> FallmapData60;


protected:
    void run();

signals:

};

#endif // FALLMAP_H
