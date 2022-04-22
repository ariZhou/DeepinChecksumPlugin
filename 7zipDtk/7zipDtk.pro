QT += core gui dtkwidget

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 7zipDtk
TEMPLATE = app

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    basehasher.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    ihasher.h \
    basehasher.h
