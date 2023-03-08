#ifndef DEMODATA_SAVE_H
#define DEMODATA_SAVE_H

#include <QThread>
#include <mainwindow.h>

class Demodulation;

class DemoData_Save : public QThread
{
    Q_OBJECT
public:
    DemoData_Save(Demodulation* demodulation);
    ~DemoData_Save();
    QString& SaveFileDemo() {return saveFileDemo;}

private:
    Demodulation* m_demodulation;

    QDateTime dateTime; //��ǰϵͳʱ��
    QString saveFileDemo;
    ofstream outfileDemo;
    int peakNum;
    int freq;

signals:

protected:
    void run();

};

#endif // DEMODATA_SAVE_H
