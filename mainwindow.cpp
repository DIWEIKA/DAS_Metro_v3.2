#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,isDemo(false)
    ,isStart(false)
    ,isHEX(true)
    ,AcqMode(1)
    ,Freq(1*1000) //������
    ,demoFlashTime(300)//����ź� flashһ�ε�ʱ��
    ,pulseFlashTime(1000)//�����ź� flashһ�ε�ʱ��
    ,fallmapFlashTime(1000) //�ٲ�ͼflashһ�ε�ʱ��
    ,fallmapThreadTime(1000) //�ٲ�ͼThread runһ�ε�ʱ��
{

    ui->setupUi(this);

    setWindowTitle(QString("DAS_Metro"));

    //set HTML pages
    setHtmlPages();

    //read configuration file
    readConfigFile();

    udp_recv = new UDP_Recv(this);
    udp_recv->start();
    FlashTimer_Pulse = new QTimer();
    DemoTimer = new QTimer();
    FlashTimer_Demo = new QTimer();
    pulsewave_Widget2 = new pulsewave_widget2(udp_recv);
    demodu = new Demodulation(udp_recv,demoFlashTime,Freq,peakNum);
    MsgTimer = new QTimer();
    fallmapTimer = new QTimer();
    m_demodata_save = new DemoData_Save(demodu);
    DemoSaveTimer = new QTimer();
    m_demowave = new demowave(demodu);
    m_fallmap = new fallmap(m_demowave,demoFlashTime);
    demowave_Widget2 = new demowave_widget2(m_demowave, m_fallmap);
    FlashTimer_Fallmap = new QTimer();

    FlashTimer_Pulse->setTimerType(Qt::PreciseTimer);
    DemoTimer->setTimerType(Qt::PreciseTimer);
    FlashTimer_Demo->setTimerType(Qt::PreciseTimer);
    MsgTimer->setTimerType(Qt::PreciseTimer);
    fallmapTimer->setTimerType(Qt::PreciseTimer);
    DemoSaveTimer->setTimerType(Qt::PreciseTimer);
    FlashTimer_Fallmap->setTimerType(Qt::PreciseTimer);

    connect(webobj,&WebClass::send_mainwindow_btn_start,this,&MainWindow::on_pushButton_Start_clicked);
    connect(webobj,&WebClass::send_mainwindow_btn_stop,this,&MainWindow::on_pushButton_Stop_clicked);
    connect(webobj,&WebClass::send_mainwindow_ckbox_isDemo,this,&MainWindow::on_checkBox_Demo_clicked);
    connect(webobj,&WebClass::send_mainwindow_btn_display_pulse,this,&MainWindow::on_pushButton_Display_pulse_clicked);
    connect(webobj,&WebClass::send_mainwindow_btn_display_demo,this,&MainWindow::on_pushButton_Display_demo_clicked);
    connect(webobj,&WebClass::send_mainwindow_combobox_mode_indexchanged,this,&MainWindow::on_comboBox_Mode_currentIndexChangedSlot);
    connect(pulsewave_Widget2,&pulsewave_widget2::send_mainwindow_btn_pause,this,&MainWindow::PulseWave_pause_slot);
    connect(pulsewave_Widget2,&pulsewave_widget2::send_mainwindow_btn_restart,this,&MainWindow::PulseWave_restart_slot);

    connect(FlashTimer_Pulse,&QTimer::timeout,pulsewave_Widget2,&pulsewave_widget2::FlashWave);
    connect(FlashTimer_Demo,&QTimer::timeout,demowave_Widget2,&demowave_widget2::FlashDemoWave);
    connect(FlashTimer_Fallmap,&QTimer::timeout,demowave_Widget2,&demowave_widget2::FlashFallmap);
    connect(FlashTimer_Demo,&QTimer::timeout,this,&MainWindow::openDemowaveThread);
    connect(MsgTimer,&QTimer::timeout,this,&MainWindow::setLocalMsg);
    connect(fallmapTimer,&QTimer::timeout,this,&MainWindow::openFallmapThread);
    connect(DemoSaveTimer,&QTimer::timeout,this,&MainWindow::openDemoSaveThread);

    connect(udp_recv,&QThread::finished,this,&MainWindow::FinishUDP_RecvThread);
    connect(demodu,&QThread::finished,this,&MainWindow::FinishDemodulationThread);
    connect(m_fallmap,&QThread::finished,this,&MainWindow::FinishFallmap_Thread);
    connect(m_demodata_save,&QThread::finished,this,&MainWindow::FinishDemosave_Thread);
    connect(m_demowave,&QThread::finished,this,&MainWindow::FinishDemowave_Thread);

    cnt=1;
    MsgTimer->start(100);

}


MainWindow::~MainWindow()
{
    delete ui;
    delete webChannel;
    delete webobj;
    delete MsgTimer;
    delete udp_recv;
    delete FlashTimer_Pulse;
    delete DemoTimer;
    delete FlashTimer_Demo;
    delete fallmapTimer;
    delete pulsewave_Widget2;
    delete demodu;
    delete demowave_Widget2;
    delete m_fallmap;
    delete m_demodata_save;
    delete DemoSaveTimer;

    on_pushButton_Stop_clicked();
    FinishUDP_RecvThread();
    FinishDemodulationThread();
    FinishFallmap_Thread();
    FinishDemosave_Thread();
}

//������Ͻ�x��ťʱ��Ӧ
void MainWindow::closeEvent( QCloseEvent * event )
{
    qApp->quit();
//switch( QMessageBox::information( this, tr("exit tip"), tr("Do you really want exit?"), tr("Yes"), tr("No"), 0, 1 ) )
//   {
//     case 0:
//          event->accept();
//          break;
//     case 1:
//     default:
//         event->ignore();
//         break;
//   }
}

void MainWindow::setHtmlPages()
{
    m_mainwindow_widget = ui->mainwindow_widget;
    m_mainwindow_widget->setContextMenuPolicy(Qt::NoContextMenu);
    m_mainwindow_widget->load(QUrl::fromLocalFile(QString("C:/DAS_Metro/PAGE/tpl03/MainWindow.html")));

    webChannel = new QWebChannel;

    webobj = new WebClass();

    webChannel->registerObject("webobj", webobj);

    m_mainwindow_widget->page()->setWebChannel(webChannel);
}


void MainWindow::setLocalMsg()
{
    QJsonObject LocalMsg_obj;

    //��ȡ�����ļ������
    QString localHostName = QHostInfo:: localHostName();
    qDebug() <<"LocalHostName: "<<localHostName<<endl;

    QJsonArray HostName_arr;
    HostName_arr.push_back(QString("LocalHostName: "+localHostName));
    LocalMsg_obj.insert("HostName",HostName_arr);

    //��ȡ����IP
    QHostInfo info = QHostInfo::fromName(localHostName);
    QList<QHostAddress> strIpAddress  = info.addresses();
    QHostAddress IpAddress =  strIpAddress.back();
    qDebug() << "IpAddress: " << IpAddress<<endl;

    QJsonArray IpAddr_arr;
    IpAddr_arr.push_back(QString("IpAddress: "+IpAddress.toString()+" Port: 7000"));
    LocalMsg_obj.insert("IpAddr",IpAddr_arr);

    QJsonArray ModeI_arr;
    ModeI_arr.push_back(QString("Setting Acquisition Card Mode I !"));
    LocalMsg_obj.insert("ModeI",ModeI_arr);

    //����js��LocalMsg����
    QString LocalMsg_js = QString("LocalMsg(%1)").arg(QString(QJsonDocument(LocalMsg_obj).toJson()));

    m_mainwindow_widget->page()->runJavaScript(LocalMsg_js);

    if(cnt++>=3) MsgTimer->stop();

}

void MainWindow::FinishUDP_RecvThread()
{
    udp_recv->quit();
    udp_recv->wait();

}

void MainWindow::readConfigFile()
{
    QString filePath = QString("C:/DAS_Metro/peak.txt");
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the Configration file!"<<endl;
    }
    QByteArray configData = file.readAll(); //��ȡ��������
    char peakNumChar_3 = configData[3]; //peakNum�İ�λ����ڵ��ĸ�λ��
    char peakNumChar_4 = configData[4]; //peakNum��ʮλ����ڵ����λ��
    char peakNumChar_5 = configData[5]; //peakNum�ĸ�λ����ڵ�����λ��
    char peakNumChar_6 = configData[6]; //���з�


    //peakNum�Ǹ�λ��
    if(peakNumChar_4 == '\n'){
        bool ok;
        peakNum = QString(peakNumChar_3).toInt(&ok,16)*1;
    }
    //peakNum��ʮλ��
    else if(peakNumChar_5 == '\n'){
        bool ok;
        peakNum = QString(peakNumChar_3).toInt(&ok,16)*10 + QString(peakNumChar_4).toInt(&ok,16)*1;
    }
    //peakNum�ǰ�λ��
    else if(peakNumChar_6 == '\n'){
        bool ok;
        peakNum = QString(peakNumChar_3).toInt(&ok,16)*100 + QString(peakNumChar_4).toInt(&ok,16)*10 + QString(peakNumChar_5).toInt(&ok,16)*1;
    }
}

void MainWindow::FinishDemodulationThread()
{
    demodu->quit();
    demodu->wait();
}


void MainWindow::on_pushButton_Start_clicked()
{
    QJsonObject start_msg_obj;
    QJsonArray startMsg;
    startMsg.push_back(QString("Started ! \n"));
    start_msg_obj.insert("start",startMsg);
    QString Start_Msg_js = QString("Start_Msg(%1)").arg(QString(QJsonDocument(start_msg_obj).toJson()));
    m_mainwindow_widget->page()->runJavaScript(Start_Msg_js);

    isStart = true;

    if(!udp_recv->isRunning())
        udp_recv->start();

}

void MainWindow::on_pushButton_Stop_clicked()
{
    QJsonObject stop_msg_obj;
    QJsonArray stopMsg;
    stopMsg.push_back(QString("Stopped ! \n"));
    stop_msg_obj.insert("stop",stopMsg);
    QString Stop_Msg_js = QString("Stop_Msg(%1)").arg(QString(QJsonDocument(stop_msg_obj).toJson()));
    m_mainwindow_widget->page()->runJavaScript(Stop_Msg_js);

    isStart = false;
    isSave = false;
    isDemo = false;

    //clear CHdata
    udp_recv->quit();

    //clear DEMOdata
    demodu->GetDEMOdata_flash()->clear();

    if(DemoTimer->isActive()) DemoTimer->stop();
    if(FlashTimer_Pulse->isActive()) FlashTimer_Pulse->stop();
    if(FlashTimer_Demo->isActive()) FlashTimer_Demo->stop();

}

void MainWindow::on_pushButton_Clear_clicked()
{
//    ui->textEdit_Msg->clear();
}


void MainWindow::on_checkBox_Demo_clicked(bool _isDemo)
{
    isDemo = _isDemo;

    if(!DemoSaveTimer->isActive() && isDemo) DemoSaveTimer->start(60000); //����洢��ʱ

    if(!fallmapTimer->isActive() && isDemo) fallmapTimer->start(fallmapThreadTime); //fallmap�����ʱ

    if(DemoTimer->isActive() && (!isDemo)) DemoTimer->stop();

    demodu->start(); //��ʼ����߳�

}

void MainWindow::on_comboBox_Mode_currentIndexChangedSlot(int _AcqMode)
{
    AcqMode = _AcqMode;
    qDebug()<<"AcqMode = "<<_AcqMode<<endl;
}

void MainWindow::on_pushButton_Display_pulse_clicked()
{
    if(!FlashTimer_Pulse->isActive()) FlashTimer_Pulse->start(pulseFlashTime);

    pulsewave_Widget2->show();
}


void MainWindow::on_pushButton_Display_demo_clicked()
{
    if(!FlashTimer_Demo->isActive()) FlashTimer_Demo->start(demoFlashTime); //demowaveˢ�¼�ʱ

    if(!FlashTimer_Fallmap->isActive()) FlashTimer_Fallmap->start(fallmapFlashTime); //fallmapˢ�¼�ʱ

    demowave_Widget2->show();
}

void MainWindow::PulseWave_pause_slot()
{
    if(FlashTimer_Pulse->isActive()) FlashTimer_Pulse->stop();
}

void MainWindow::PulseWave_restart_slot()
{
    if(!FlashTimer_Pulse->isActive()) FlashTimer_Pulse->start(pulseFlashTime);
}

void MainWindow::openFallmapThread()
{
    if(!m_fallmap->isRunning())
        m_fallmap->start();
}

void MainWindow::FinishFallmap_Thread()
{
    m_fallmap->quit();
    m_fallmap->wait();
}

void MainWindow::openDemoSaveThread()
{
    if(!m_demodata_save->isRunning())
    m_demodata_save->start();

    QJsonObject demosave_msg_obj;
    QJsonArray demoSaveMsg;
    demoSaveMsg.push_back(m_demodata_save->SaveFileDemo());
    demosave_msg_obj.insert("demoSaveMsg",demoSaveMsg);
    QString DemoSave_Msg_js = QString("DemoSave_Msg(%1)").arg(QString(QJsonDocument(demosave_msg_obj).toJson()));
    m_mainwindow_widget->page()->runJavaScript(DemoSave_Msg_js);
}

void MainWindow::FinishDemosave_Thread()
{
    m_demodata_save->quit();
    m_demodata_save->wait();
}

void MainWindow::openDemowaveThread()
{
    if(!m_demowave->isRunning())
        m_demowave->start();
}

void MainWindow::FinishDemowave_Thread()
{
    m_demowave->quit();
    m_demowave->wait();
}


