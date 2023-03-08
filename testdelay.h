#ifndef TESTDELAY_H
#define TESTDELAY_H

#include <QObject>

class TestDelay : public QObject
{
    Q_OBJECT
public:
    explicit TestDelay(QObject *parent = nullptr);

signals:

};

#endif // TESTDELAY_H
