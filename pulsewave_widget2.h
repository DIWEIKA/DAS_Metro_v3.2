#ifndef PULSEWAVE_WIDGET2_H
#define PULSEWAVE_WIDGET2_H

#include <mainwindow.h>
#include <QWidget>
#include <QMainWindow>
#include <qmainwindow.h>
#include <QTimer>
#include <fstream>
#include <sstream>
#include <mainwindow.h>
#include "udp_recv.h"
#include <ctime>

#define READ_PULSE_LENGTH 1024*32 //��pack_HEX_Display���ȡ�����ݳ���
#define PULSEDATA_ALL_LENGTH 1024*8 //�ĸ�ͨ����ʮ���������ݳ���
#define PULSEDATA_LENGTH 1024*2 //һ��ͨ����ʮ����������
#define DISPLAY_LENGTH_PULSE 256*2 //չʾ��widget�ϵ����ݳ���
#define SaveNumber 65 //�洢�����ĸ���

namespace Ui {
class pulsewave_widget2;
}

using namespace std;

class UDP_Recv;
class WebClass;

class pulsewave_widget2 : public QWidget
{
    Q_OBJECT
public:
    pulsewave_widget2(UDP_Recv *udp_Recv);
    ~pulsewave_widget2();

    void setHtmlPages();
    void FlashWave();
    void FreeMemory();

private:
    Ui::pulsewave_widget2 *ui;

    QWebEngineView *m_pulsewave_widget;
    QWebChannel *webChannel2;
    WebClass *webobj2;

    UDP_Recv *udp_recv;
    int sizeoPulsedata ;
    int sizeoPulsedataDec;
    int sizeoDisplaydata;
    int ChannelIndex=0;
    char* PulsedataHEX;
    int Pulsedata_DEC_all_HEX[PULSEDATA_ALL_LENGTH*2] =  {0};
    int Pulsedata_DEC_1_HEX[PULSEDATA_LENGTH*2]= {0};
    int Pulsedata_DEC_2_HEX[PULSEDATA_LENGTH*2] =  {0};
    int Pulsedata_DEC_3_HEX[PULSEDATA_LENGTH*2] =  {0};
    int Pulsedata_DEC_4_HEX[PULSEDATA_LENGTH*2] =  {0};
    int Pulsedata_DEC_disp[PULSEDATA_LENGTH*2] = {0};

signals:
    void send_mainwindow_btn_pause();
    void send_mainwindow_btn_restart();

private slots:
    void PulseWave_pause_slot();
    void PulseWave_restart_slot();
};

#endif // PULSEWAVE_WIDGET2_H
