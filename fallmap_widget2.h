#ifndef FALLMAP_WIDGET2_H
#define FALLMAP_WIDGET2_H

#include <mainwindow.h>
#include <QWidget>
#include "fallmap.h"

class Demodulation;
class WebClass;
class fallmap;

namespace Ui {
class fallmap_widget2;
}

using namespace std;

class fallmap_widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit fallmap_widget2(Demodulation* demodulation, fallmap* _fallmap);
    ~fallmap_widget2();

    void setHtmlPages();
    void FlashWave();

private:
    Ui::fallmap_widget2 *ui;
    Demodulation* demodu;
    fallmap* m_fallmap;
    QWebEngineView *m_fallmap_widget;
    QWebChannel *webChannel5;
    WebClass *webobj5;
    int peakNum;
};

#endif // FALLMAP_WIDGET2_H
