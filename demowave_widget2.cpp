#include "demowave_widget2.h"
#include "ui_demowave_widget2.h"

demowave_widget2::demowave_widget2(demowave* _demowave, fallmap* _fallmap):
    ui(new Ui::demowave_widget2),
    m_demowave(_demowave),
    m_fallmap(_fallmap),
    RegionIndex(0)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->setupUi(this);

    setHtmlPages();
}

demowave_widget2::~demowave_widget2()
{
    delete ui;
    delete m_demowave_widget;
    delete webChannel4;
    delete webobj4;
}

void demowave_widget2::setHtmlPages()
{
    setWindowTitle(QString("Demodulation Wave Display"));

    m_demowave_widget = ui->demowave_widget;
    m_demowave_widget->setContextMenuPolicy(Qt::NoContextMenu);
    m_demowave_widget->load(QUrl::fromLocalFile(QString("C:/DAS_Metro/PAGE/tpl03/DemoWaveDisplay4.0.html")));

    webChannel4 = new QWebChannel;

    webobj4 = new WebClass();

    webChannel4->registerObject("webobj4", webobj4);

    m_demowave_widget->page()->setWebChannel(webChannel4);
}

//Ë¢ÐÂ²¨ÐÎÏÔÊ¾
void demowave_widget2::FlashDemoWave()
{
//    qDebug() <<"Flash Demodulation Wave Slot responsed !"<<endl;

    //demowave display
//    QString demo_wave_js = QString("demo_wave(%1)").arg(QString(QJsonDocument(m_demowave->GetDemoWaveObj()).toJson()));
//    m_demowave_widget->page()->runJavaScript(demo_wave_js);

}

void demowave_widget2::FlashFallmap()
{
//    qDebug() <<"Flash Fallmap Slot responsed !"<<endl;

    //fallmap display
    QString fallmap_js = QString("fallmap_flash(%1)").arg(QString(QJsonDocument(m_fallmap->GetFallmapObj()).toJson()));
    m_demowave_widget->page()->runJavaScript(fallmap_js);

    //judgement display
    QString judgement_js = QString("judgement_flash(%1)").arg(QString(QJsonDocument(m_fallmap->GetJudgementObj()).toJson()));
    m_demowave_widget->page()->runJavaScript(judgement_js);
}




