#include "fallmap_widget2.h"
#include "ui_fallmap_widget2.h"

fallmap_widget2::fallmap_widget2( Demodulation* demodulation, fallmap* _fallmap) :
     ui(new Ui::fallmap_widget2),
    demodu(demodulation),
    m_fallmap(_fallmap),
    peakNum(demodu->GetPeakNum())
{
    ui->setupUi(this);

    setHtmlPages();
}

fallmap_widget2::~fallmap_widget2()
{
    delete ui;
    delete demodu;
    delete m_fallmap;
    delete m_fallmap_widget;
    delete webChannel5;
    delete webobj5;
}

void fallmap_widget2::setHtmlPages()
{
    setWindowTitle(QString("Fall Map Display"));

    m_fallmap_widget = ui->fallmapView;
    m_fallmap_widget->setContextMenuPolicy(Qt::NoContextMenu);
    m_fallmap_widget->load(QUrl::fromLocalFile(QString("C:/DAS_Metro/PAGE/tpl03/DemoWaveDisplay2.0.html")));

    webChannel5 = new QWebChannel;

    webobj5 = new WebClass();

    webChannel5->registerObject("webobj5", webobj5);

    m_fallmap_widget->page()->setWebChannel(webChannel5);
}

void fallmap_widget2::FlashWave()
{
    qDebug() <<"Flash Fallmap Slot responsed !"<<endl;


}
