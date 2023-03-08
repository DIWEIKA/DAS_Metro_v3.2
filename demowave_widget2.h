#ifndef DEMOWAVE_WIDGET2_H
#define DEMOWAVE_WIDGET2_H

#include <mainwindow.h>
#include <QWidget>
#include <QMainWindow>
#include <qmainwindow.h>
#include <QTimer>
#include <QThread>
#include "demowave.h"
#include "fallmap.h"


using namespace std;

namespace Ui {
class demowave_widget2;
}

class demowave;
class WebClass;
class fallmap;

class demowave_widget2: public QWidget
{
public:
    demowave_widget2(demowave* _demowave, fallmap* _fallmap);
    ~demowave_widget2();

    void setHtmlPages();
    const WebClass* GetWebClass() const {return webobj4;};


private:
    Ui::demowave_widget2 *ui;

    QWebEngineView *m_demowave_widget;
    QWebChannel *webChannel4;
    WebClass *webobj4;
    demowave* m_demowave;
    fallmap* m_fallmap;
    int RegionIndex;

public slots:
    void FlashDemoWave();
    void FlashFallmap();

private slots:

};

#endif // DEMOWAVE_WIDGET2_H
