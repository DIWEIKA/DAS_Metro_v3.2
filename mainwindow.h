#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QCloseEvent>
#include <QQueue>
#include "CirQueue.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QtNetwork>
#include <recvdata.h>
#include <QtDebug>
#include <vector>
#include <winsock2.h>
#include <windows.h>
#include "udp_recv.h"
#include "pulsewave_widget2.h"
#include "demowave_widget2.h"
#include "demodulation.h"
#include "fallmap.h"
#include "ui_mainwindow.h"
#include <QtWebEngineWidgets>
#include <QtWebChannel>
#include <webclass.h>
#include "demodata_save.h"
#include "demowave.h"

typedef unsigned char BYTE;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

 //ʹ��ǰ������
class UDP_Recv;
class pulsewave_widget2;
class demowave_widget2;
class Demodulation;
class webclass;
class fallmap;
class DemoData_Save;
class demowave;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setHtmlPages();
    void setLocalMsg();
    void readConfigFile();
    const int GetFreq() const {return Freq;};
    const int GetPeakNum() const {return peakNum;};
    bool GetIsStart() const {return isStart;};
    int GetAcqMode() const {return AcqMode;};

private:
    Ui::MainWindow *ui;

    QWebEngineView* m_mainwindow_widget;
    QWebChannel *webChannel;
    WebClass *webobj;

    bool isSave;
    bool isDemo;
    bool isStart;
    bool isHEX;
    int AcqMode;
    int Freq;
    int peakNum;
    int demoFlashTime;
    int pulseFlashTime;
    int fallmapFlashTime;
    int fallmapThreadTime;
//    double demoFlashFreq;
    double pulseFlashFreq;
    int cnt;

    QTimer* MsgTimer;
    UDP_Recv* udp_recv;
    QTimer* FlashTimer_Pulse; //�����ˢ�¶�ʱ��
    QTimer* DemoTimer; //��������̶߳�ʱ��
    QTimer* FlashTimer_Demo; // ���ˢ�¶�ʱ��
    QTimer* fallmapTimer; //�ٲ�ͼ�����̶߳�ʱ��
    QTimer* FlashTimer_Fallmap; //�ٲ�ͼˢ�¶�ʱ��
    pulsewave_widget2 *pulsewave_Widget2;
    Demodulation *demodu;
    demowave_widget2 *demowave_Widget2;
    fallmap* m_fallmap;
    DemoData_Save* m_demodata_save;
    QTimer* DemoSaveTimer; //������ݴ洢��ʱ��
    demowave* m_demowave; //������μ���

private slots:
    void FinishUDP_RecvThread();
    void FinishDemodulationThread();
    void on_pushButton_Start_clicked();
    void on_pushButton_Stop_clicked();
    void on_pushButton_Clear_clicked();
    void on_checkBox_Demo_clicked(bool _isDemo);
    void on_comboBox_Mode_currentIndexChangedSlot(int _AcqMode);
    void on_pushButton_Display_pulse_clicked();
    void on_pushButton_Display_demo_clicked();
    void PulseWave_pause_slot();
    void PulseWave_restart_slot();
    void openFallmapThread();
    void FinishFallmap_Thread();
    void openDemoSaveThread();
    void FinishDemosave_Thread();
    void openDemowaveThread();
    void FinishDemowave_Thread();

private:
    void closeEvent( QCloseEvent * event);

};
#endif // MAINWINDOW_H
