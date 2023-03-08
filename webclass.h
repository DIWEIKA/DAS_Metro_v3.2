#ifndef WEBCLASS_H
#define WEBCLASS_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>

/*---html����Qt�˽�����---*/

class WebClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString content MEMBER m_content NOTIFY contentChanged) //content => m_content �����Կ���ҳ�����

public:
    explicit WebClass(/*QObject *parent = nullptr*/){}

    QString getContent(){return m_content;}

private:
    QString m_content;

signals:
    void contentChanged(QString nc);
    void send_mainwindow_btn_start();
    void send_mainwindow_btn_stop();
//    void send_mainwindow_ckbox_isSave(bool _isSave);
    void send_mainwindow_ckbox_isDemo(bool _isDemo);
    void send_mainwindow_btn_display_pulse();
    void send_mainwindow_btn_display_demo();
    void send_mainwindow_btn_display_fallmap();
    void send_pulsewave_widget_btn_pulsewave_pause();
    void send_pulsewave_widget_btn_pulsewave_restart();
    void send_mainwindow_combobox_mode_indexchanged(int _AcqMode);
    void send_demowidget_combobox_region_indexchanged(int _regionIndex);
    void send_fft_combobox_region_indexchanged(int _regionIndex);

public slots:
    //ҳ��˵���
    void js_btn_start_called(){
//        qDebug()<<"btn Start clicked!"<<endl;
        emit send_mainwindow_btn_start(); //��mainwindow�����ź�
    }

    void js_btn_stop_called(){
//        qDebug()<<"btn Stop clicked!"<<endl;
        emit send_mainwindow_btn_stop();
    }

//    void js_checkbox_isSave_called(){
//        QVariant v = m_content;
//        bool isSave = v.toBool();
//        emit send_mainwindow_ckbox_isSave(isSave);
//    }

    void js_checkbox_isDemo_called(){
        QVariant v = m_content;
        bool isDemo = v.toBool();
        emit send_mainwindow_ckbox_isDemo(isDemo);
    }

    void js_btn_display_pulse_called(){
        emit send_mainwindow_btn_display_pulse();
    }

    void js_btn_display_demo_called(){
        emit send_mainwindow_btn_display_demo();
    }

    void js_btn_display_fallmap_called(){
        emit send_mainwindow_btn_display_fallmap();
    }

    void js_btn_pause_called(){
        emit send_pulsewave_widget_btn_pulsewave_pause();
    }

    void js_btn_restart_called(){
        emit send_pulsewave_widget_btn_pulsewave_restart();
    }

    void js_combobox_mode_indexchanged(){
        QVariant v = m_content;
        int _AcqMode = v.toInt();
        qDebug()<<"_AcqMode = "<<_AcqMode<<endl;
        emit send_mainwindow_combobox_mode_indexchanged(_AcqMode);
    }

    void js_combobox_region_indexchanged(){
        QVariant v = m_content;
        int _regionIndex = v.toInt();
        qDebug()<<"_regionIndex = "<<_regionIndex<<endl;
        emit send_demowidget_combobox_region_indexchanged(_regionIndex);
        emit send_fft_combobox_region_indexchanged(_regionIndex);

    }

};

#endif // WEBCLASS_H
