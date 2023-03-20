QT       += core gui network webenginewidgets webchannel
QT += core gui charts
QT+= widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#CONFIG += resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demodata_save.cpp \
    demodulation.cpp \
    demowave.cpp \
    demowave_widget2.cpp \
    fallmap.cpp \
    fault_detection.cpp \
    main.cpp \
    mainwindow.cpp \
    pulsewave_widget2.cpp \
    udp_recv.cpp \

HEADERS += \
    CirQueue.h \
    demodata_save.h \
    demodulation.h \
    demowave.h \
    demowave_widget2.h \
    fallmap.h \
    fault_detection.h \
    findpeaks.h \
    mainwindow.h \
    pulsewave_widget2.h \
    udp_recv.h \
    webclass.h \


FORMS += \
    demowave_widget2.ui \
    mainwindow.ui \
    pulsewave_widget2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


LIBS += -lws2_32

QTQUICK_COMPILER_SKIPPED_RESOURCES += xxxx.qrc

