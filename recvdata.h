#ifndef RECVDATA_H
#define RECVDATA_H

#include <QMainWindow>
#include <QUdpSocket>
#include <QQueue>
#include "CirQueue.h"
#include <memory>
#include <QMutex>
#include <fstream>
#include <QtNetwork>
#include <sstream>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include "ui_mainwindow.h"
#include "mainwindow.h"

 typedef unsigned char BYTE;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow;
class DealMsg;
class  WriteToFiles;

class Recvdata : public QObject
{
public:
    Recvdata(QUdpSocket *socket, Ui::MainWindow *ui);
    ~Recvdata();

    void readDatagram();//��ȡudp��Ϣ
    void getDatafromByteToFloat();
    void changeFileNameOnce();//�������ɴ洢�ļ���

    void changeFileName(); //�ı���һ���ļ����ļ���
    void WriteToFilesWith3Channels();

    bool isTimeUpdate;
    void closeStream();

    Ui::MainWindow *UI;

    QUdpSocket *udpSocket;//udpSocket������
    qint64 lenoDatagram; //Datagram�ĳ���
    QStringList BufArray;
    qint64 lenoBufArray;
    qint64 LenoUDP = 8192*6000;  //CHdata�ĳ��� ���Ϊ9223372036854775807
    string saveFolder;//�洢Ŀ¼���ļ��У�
    QString saveFilename1; //CH1�洢�ļ���
    QString saveFilename2;
    QString saveFilename3;

    QString file1;
    QString file2;
    QString file3;

    ofstream outfile1;//CH1
    ofstream outfile2;
    ofstream outfile3;

    QDateTime dateTime; //��ǰϵͳʱ��
    QDateTime nextDateTime;
    bool hasNextFilename;
    QByteArray datagram; //����UDP������
    QString buf; //��Ž������ݵĻ�����
    QHostAddress clientAddr;
    quint16 clientPort;
    QMutex writeLock;
    QTimer* udpTimer; //��ʱ�� ������ʱ1����
    BYTE* bufPtr;
    shared_ptr<BYTE*> RECORD_BUF; //�������ݵ�Buffer
    shared_ptr<CirQueue<float>> CHdata; //���Channel���ݵ�����
    shared_ptr<CirQueue<unsigned char>> CHdata2; //����
    char usCHDATA;

    int PeakNum = 31;//��ֵ��

public slots:
    void dealMsg(); //slot func
    void TimeUpdate();

private slots:


private:

signals:
//    timeout();

};

#endif // RECVDATA_H
